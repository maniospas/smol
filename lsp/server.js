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
let workspaceRoot = "";

function sendErrorToClient(msg) {
  try { connection.sendNotification('server/error', msg);} 
  catch (e) {console.error("Failed to send error to client:", e);}
}
process.on("uncaughtException", (err) => {sendErrorToClient("Uncaught Exception: " + err.message); console.error("Uncaught Exception:", err);});
process.on("unhandledRejection", (reason) => { sendErrorToClient("Unhandled Rejection: " + reason); console.error("Unhandled Rejection:", reason);});

function analyzeDocument(uri, text) {
  const lines = text.split(/\r?\n/);
  const symbols = [];
  const decorations_arrow = [];
  const decorations_dash = [];
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
      let resolvedPath = path.resolve(dir, includePath);
      if (!fs.existsSync(resolvedPath)) resolvedPath = path.resolve(workspaceRoot, includePath);

      const includedUri = "file://" + resolvedPath;
      includes.add(includedUri);
      if(!symbolTable.has(includedUri) && fs.existsSync(resolvedPath)) analyzeDocument(includedUri, fs.readFileSync(resolvedPath, "utf8"));
    }
    const arrowOrDashRegex = /--|->/g;
    let match;
    const consumed = new Set();

    while ((match = arrowOrDashRegex.exec(line)) !== null) {
      const startIdx = match.index;

      // If already consumed, skip
      if (consumed.has(startIdx)) continue;

      if (match[0] === '--') {
        decorations_dash.push({
          range: {
            start: { line: i, character: startIdx },
            end: { line: i, character: startIdx + 2 }
          },
          text: "--"
        });
        consumed.add(startIdx);
        consumed.add(startIdx + 1);
      } else if (match[0] === '->') {
        decorations_arrow.push({
          range: {
            start: { line: i, character: startIdx },
            end: { line: i, character: startIdx + 2 }
          },
          text: "->"
        });
        consumed.add(startIdx);
        consumed.add(startIdx + 1);
      }
    }

  }
  symbolTable.set(uri, symbols);
  includeGraph.set(uri, includes);
  connection.sendNotification("smolambda/decorations", {uri, arrows: decorations_arrow, dashes: decorations_dash});
}

documents.onDidOpen(e => {analyzeDocument(e.document.uri, e.document.getText());});
documents.onDidChangeContent(e => {analyzeDocument(e.document.uri, e.document.getText());});
connection.onInitialize((params) => {
  connection.console.log("Smoλ language server initialized.");
  const folders = params.workspaceFolders;
  if(folders && folders.length > 0) workspaceRoot = decodeURIComponent(folders[0].uri.replace("file://", ""));
  else if(params.rootUri) workspaceRoot = decodeURIComponent(params.rootUri.replace("file://", ""));
  else workspaceRoot = process.cwd(); // Fallback to current working dir
  return {
    capabilities: {
      textDocumentSync: documents.syncKind,
      completionProvider: {
        triggerCharacters: [".", ":"]
      },
      semanticTokensProvider: {
        legend: {
          tokenTypes: ['keyword', 'type', 'variable', 'macro', 'function', 'number', 'string', 'operator', 'comment'],
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
    ...builtins.map(k => ({
      label: k,
      kind: CompletionItemKind.Keyword
    })),
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
    let resolvedPath = path.resolve(dir, includePath);
    if (!fs.existsSync(resolvedPath)) resolvedPath = path.resolve(workspaceRoot, includePath);
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
  for(let line = 0; line < lines.length; line++) {
    const textLine = lines[line];
    let pos = 0;
    while(pos < textLine.length) {
      if(/\s/.test(textLine[pos])) { pos++; continue; }
      if(textLine.startsWith("//", pos)) {
        const length = textLine.length - pos;
        builder.push(line, pos, length, 8, 0)
        break;
      }
      if(textLine[pos] === '"') {
        let end = pos + 1;
        while(end < textLine.length && textLine[end] !== '"') {
          if(textLine[end] === '\\' && end + 1 < textLine.length) end += 2; 
          else end++;
        }
        end = Math.min(end + 1, textLine.length); // include closing quote
        const length = end - pos;
        builder.push(line, pos, length, 6, 0);
        pos = end;
        continue;
      }
  
      //if(textLine.startsWith("->", pos) || textLine.startsWith("--", pos) || textLine.startsWith("-->", pos) || textLine.startsWith("->>", pos)) {builder.push(line, pos, 2, 3, 0);pos += 2;continue;}
      //if(textLine.startsWith("-->", pos) || textLine.startsWith("->>", pos)) {builder.push(line, pos, 2, 3, 0);pos += 2;continue;}
      if(textLine[pos] === ':') {builder.push(line, pos, 1, 3, 0);pos += 1;continue;}
      const match = textLine.slice(pos).match(/^@?[A-Za-z_][A-Za-z0-9_.]*/);
      if(match) {
        const word = match[0];
        if (word[0] === "@") builder.push(line, pos, word.length, 3, 0);
        else if (keywords.includes(word)) builder.push(line, pos, word.length, 0, 0);
        else if (builtins.includes(word)) builder.push(line, pos, word.length, 1, 0);
        pos += word.length;
      } 
      else pos++;
    }
  }
  
  
  return builder.build();
});

const compileState = new Map();
const os = require("os");
const { spawn } = require("child_process");
const { randomUUID } = require("crypto");

function runCompilerAndSendDiagnostics(document) {
  const uri = document.uri;
  const text = document.getText();
  if(!compileState.has(uri)) compileState.set(uri, { running: false, rerunRequested: false, debounceTimer: null });
  const state = compileState.get(uri);
  if(state.debounceTimer) clearTimeout(state.debounceTimer);
  state.debounceTimer = setTimeout(() => {
    if(state.running) {state.rerunRequested = true;return;}
    state.running = true;
    state.debounceTimer = null;
    const tempFilePath = path.join(os.tmpdir(), `smol_${randomUUID()}.s`);
    fs.writeFileSync(tempFilePath, text, "utf8");
    const proc = spawn("./smol", [tempFilePath, "--task", "lsp"]);
    let stderr = "";
    proc.stderr.on("data", chunk => {stderr += chunk.toString();});
    proc.on("close", () => {
      const lines = stderr.split(/\r?\n/);
      const diagnostics = [];
      const diagnostics_no_text = [];
      let messageLines = [];
      for(let i = 0; i < lines.length - 2; i++) {
        const line = lines[i].trim();
        if(line.startsWith("at")) {
          const locMatch = line.match(/^at\s+(.*)\s+line\s+(\d+)\s+col\s+(\d+)/);
          if (!locMatch) continue;
          const [, , lineStr, colStr] = locMatch;
          const lineNum = parseInt(lineStr, 10) - 1;
          const colNum = parseInt(colStr, 10) - 1;
          const caretLine = lines[i + 2] || "";
          const caretMatch = caretLine.match(/\^+/);
          const tokenLength = caretMatch ? caretMatch[0].length : 1;
          const message = messageLines.map(stripAnsi).join("\n") || "Unknown error";
          diagnostics.push({
            severity: 1,
            range: {
              start: { line: lineNum, character: colNum },
              end: { line: lineNum, character: colNum + tokenLength }
            },
            message,
            source: "smol"
          });
          diagnostics_no_text.push({
            severity: 1,
            range: {
              start: { line: lineNum, character: colNum },
              end: { line: lineNum, character: colNum + tokenLength }
            },
            message: "ERROR",
            source: "smol"
          });
          i += 2;
          messageLines = [];
        } 
        else messageLines.push(lines[i]);
      }
      try {fs.unlinkSync(tempFilePath);} 
      catch(e) {console.error("Failed to remove temp file:", tempFilePath);}
      connection.sendNotification("smolambda/htmlNotification", { uri, diagnostics });
      connection.sendDiagnostics({ uri, diagnostics: diagnostics_no_text });
      if(state.rerunRequested) {
        state.rerunRequested = false;
        state.running = false;
        runCompilerAndSendDiagnostics(document);
      }
      else state.running = false;
    });
  }, 300);
  function stripAnsi(line) {
    return line 
      .replace(/\x1b\[31m/g, '')
      .replace(/\x1b\[32m/g, '')
      .replace(/\x1b\[33m/g, '')
      .replace(/\x1b\[34m/g, '')
      .replace(/\x1b\[35m/g, '')
      .replace(/\x1b\[36m/g, '')
      .replace(/\x1b\[0m/g, '');
  }
}

connection.onNotification('custom/windowFocused', (params) => {analyzeDocument(params.uri, params.text);});
documents.onDidChangeContent(async (e) => {await runCompilerAndSendDiagnostics(e.document);});
documents.onDidSave(async (e) => {await runCompilerAndSendDiagnostics(e.document);});
documents.listen(connection);
connection.listen();
