const {
  createConnection,
  TextDocuments,
  ProposedFeatures,
  CompletionItemKind,
  Location,
  SemanticTokensBuilder,
  Range
} = require("vscode-languageserver/node");
const { TextDocument } = require("vscode-languageserver-textdocument");
const fs = require("fs");
const path = require("path");
const keywords = require("./smol_keywords");
const builtins = require("./smol_builtins");
const connection = createConnection(ProposedFeatures.all);
const documents = new TextDocuments(TextDocument);
const symbolTable = new Map();  // uri => [{name, line}]
const includeGraph = new Map(); // uri => Set<includedUri>

function sendErrorToClient(msg) {
  try { connection.sendNotification('server/error', msg);} 
  catch (e) {console.error("Failed to send error to client:", e);}
}
process.on("uncaughtException", (err) => {sendErrorToClient("Uncaught Exception: " + err.message); console.error("Uncaught Exception:", err);});
process.on("unhandledRejection", (reason) => { sendErrorToClient("Unhandled Rejection: " + reason); console.error("Unhandled Rejection:", reason);});

function analyzeDocument(uri, text) {
  const lines = text.split(/\r?\n/);
  const symbols = [];
  const includes = new Set();
  for(let i = 0; i < lines.length; i++) {
    const line = lines[i];
    const defMatch = line.match(/^\s*(smo|service|union)\s+([A-Za-z_][A-Za-z0-9_]*)/);
    if(defMatch) symbols.push({ name: defMatch[2], line: i });
    const includeMatch = line.match(/@include\s+([\w.]+)/);
    if(includeMatch) {
      const includePath = includeMatch[1].replace(/\./g, "/") + ".s";
      const basePath = decodeURIComponent(uri.replace("file://", ""));
      const dir = path.dirname(basePath);
      const resolvedPath = path.resolve(dir, includePath);
      const includedUri = "file://" + resolvedPath;
      includes.add(includedUri);
      if(!symbolTable.has(includedUri) && fs.existsSync(resolvedPath)) analyzeDocument(includedUri, fs.readFileSync(resolvedPath, "utf8"));
    }
  }
  symbolTable.set(uri, symbols);
  includeGraph.set(uri, includes);
}

documents.onDidOpen(e => {analyzeDocument(e.document.uri, e.document.getText());});
documents.onDidChangeContent(e => {analyzeDocument(e.document.uri, e.document.getText());});
connection.onInitialize(() => {
  connection.console.log("Smoλ language server initialized.");
  return {
    capabilities: {
      textDocumentSync: documents.syncKind,
      completionProvider: {
        triggerCharacters: [".", "|"]
      },
      semanticTokensProvider: {
        legend: {
          tokenTypes: ['keyword', 'function', 'variable', 'string', 'operator'],
          tokenModifiers: []
        },
        full: true
      },
      definitionProvider: true
    }
  };
});

connection.onCompletion((params) => {
  const uri = params.textDocument.uri;
  const symbols = new Set();
  function collect(uri, visited = new Set()) {
    if (visited.has(uri)) return;
    visited.add(uri);
    const defs = symbolTable.get(uri) || [];
    defs.forEach(d => symbols.add(d.name));
    const includes = includeGraph.get(uri) || new Set();
    includes.forEach(included => collect(included, visited));
  }
  collect(uri);
  return [
    ...keywords.map(k => ({
      label: k,
      kind: CompletionItemKind.Keyword
    })),
    ...[...symbols].map(s => ({
      label: s,
      kind: CompletionItemKind.Function
    }))
  ];
});

connection.onDefinition((params) => {
  const uri = params.textDocument.uri;
  const document = documents.get(uri);
  if (!document) return null;
  const pos = params.position;
  const lines = document.getText().split(/\r?\n/);
  function getWordAt(line, character) {
    const regex = /\b[A-Za-z_][A-Za-z0-9_]*\b/g;
    let match;
    while ((match = regex.exec(line)) !== null) {
      const start = match.index;
      const end = start + match[0].length;
      if (character >= start && character <= end) {
        return match[0];
      }
    }
    return null;
  }
  const word = getWordAt(lines[pos.line], pos.character);
  if(!word) return null;
  const searchOrder = [];

  function collect(uri, visited = new Set()) {
    if (visited.has(uri)) return;
    visited.add(uri);
    searchOrder.push(uri);
    const includes = includeGraph.get(uri) || new Set();
    includes.forEach(included => collect(included, visited));
  }
  collect(uri);

  const foundLocations = [];
  for (const u of searchOrder) {
    const defs = symbolTable.get(u) || [];
    for (const { name, line } of defs) {
      if (name === word) {
        let defLineText;
        if (u === uri) defLineText = lines[line];
        else {
          const filePath = decodeURIComponent(u.replace("file://", ""));
          if (!fs.existsSync(filePath)) continue;
          const fileLines = fs.readFileSync(filePath, "utf8").split(/\r?\n/);
          defLineText = fileLines[line] || "";
        }
        var start = defLineText.indexOf(name);
        while (start !== -1) {
          const end = start + name.length;
          foundLocations.push(Location.create(u, Range.create(line, start, line, end)));
          start = defLineText.indexOf(name, end+1);
        }
      }
    }
  }
  if(foundLocations.length) return foundLocations;

  const includeLine = lines[pos.line];
  const includeMatch = includeLine.match(/@include\s+([\w.]+)/);
  if (includeMatch) {
    const includePath = includeMatch[1].replace(/\./g, "/") + ".s";
    const basePath = decodeURIComponent(uri.replace("file://", ""));
    const dir = path.dirname(basePath);
    const resolvedPath = path.resolve(dir, includePath);
    if (fs.existsSync(resolvedPath)) {
      const includedUri = "file://" + resolvedPath;
      return Location.create(includedUri, Range.create(0, 0, 0, 0));
    }
  }

  return null;
});


connection.languages.semanticTokens.on((params) => {
  const uri = params.textDocument.uri;
  const document = documents.get(uri);
  if(!document) return { data: [] };
  const builder = new SemanticTokensBuilder();
  const text = document.getText();
  const lines = text.split(/\r?\n/);
  for (let line = 0; line < lines.length; line++) {
    const textLine = lines[line];
    let pos = 0;
    while(pos < textLine.length) {
      if(/\s/.test(textLine[pos])) {pos++;continue;}
      if (/\s/.test(textLine[pos])) {
        pos++;
        continue;
      }
      if (textLine.startsWith("->", pos) || textLine.startsWith("--", pos)) { builder.push(line, pos, 2, 4, 0);pos += 2; continue;}
      if (textLine[pos] === '|' || textLine[pos] === '=') {builder.push(line, pos, 1, 4, 0);pos += 1;continue;}
      const match = textLine.slice(pos).match(/^@?[A-Za-z_][A-Za-z0-9_]*/);
      if(match) {
        const word = match[0];
        if (keywords.includes(word)) builder.push(line, pos, word.length, 0, 0);
        else if (builtins.includes(word)) builder.push(line, pos, word.length, 1, 0);
        pos += word.length;
      } 
      else pos++;
    }
  }
  
  return builder.build();
});


documents.listen(connection);
connection.listen();
