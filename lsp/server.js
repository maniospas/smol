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
const directives = require("./smol_directives");
const connection = createConnection(ProposedFeatures.all);
const documents = new TextDocuments(TextDocument);
const symbolTable = new Map();  // uri => {symbols, abouts, fileAbout}
const includeGraph = new Map(); // uri => Set<includedUri>
let workspaceRoot = "";
const fileDiagnostics = new Map(); // uri -> array of diagnostics

function sendErrorToClient(msg) {
  try { connection.sendNotification('server/error', msg); }
  catch (e) { console.error("Failed to send error to client:", e); }
}
process.on("uncaughtException", (err) => { sendErrorToClient("Uncaught Exception: " + err.message); console.error("Uncaught Exception:", err); });
process.on("unhandledRejection", (reason) => { sendErrorToClient("Unhandled Rejection: " + reason); console.error("Unhandled Rejection:", reason); });

function analyzeDocument(uri, text) {
  const lines = text.split(/\r?\n/);
  const symbols = [];
  const includes = new Set();
  const abouts = new Map();
  let fileAbout = null;
  for (let i = 0; i < lines.length; i++) {
    const line = lines[i];
    // function / service / union definitions
    const defMatch = line.match(/^\s*(def|service|union)\s+([A-Za-z_][A-Za-z0-9_]*)/);
    if (defMatch) symbols.push({ name: defMatch[2], line: i, kind: "function" });

    // @about
    if (line.trim().startsWith("@about")) {
      let collected = line;
      let j = i + 1;
      while (j < lines.length && /^\s*"/.test(lines[j])) {
        collected += " " + lines[j].trim();
        j++;
      }
      i = j - 1;
      const parts = [...collected.matchAll(/"((?:\\.|[^"\\])*)"/g)]
        .map(m => m[1].replace(/\\"/g, '"'));
      const nameMatch = collected.match(/^@about\s+([A-Za-z_][A-Za-z0-9_]*)/);
      if (nameMatch) abouts.set(nameMatch[1], parts.join(" "));
      else if (parts.length) fileAbout = parts.join(" ");
    }

    // includes
    const includeMatch = line.match(/@include\s+([\w.]+)/);
    if (includeMatch) {
      const includePath = includeMatch[1].replace(/\./g, "/") + ".s";
      const basePath = decodeURIComponent(uri.replace("file://", ""));
      const dir = path.dirname(basePath);
      let resolvedPath = path.resolve(dir, includePath);
      if (!fs.existsSync(resolvedPath)) resolvedPath = path.resolve(workspaceRoot, includePath);
      const includedUri = "file://" + resolvedPath;
      includes.add(includedUri);
      if (!symbolTable.has(includedUri) && fs.existsSync(resolvedPath)) {
        analyzeDocument(includedUri, fs.readFileSync(resolvedPath, "utf8"));
      }
    }
  }
  symbolTable.set(uri, { symbols, abouts, fileAbout });
  includeGraph.set(uri, includes);
}

documents.onDidOpen(e => { analyzeDocument(e.document.uri, e.document.getText()); });
documents.onDidChangeContent(e => { analyzeDocument(e.document.uri, e.document.getText()); });
connection.onInitialize((params) => {
  connection.console.log("Smoλ language server initialized.");
  const folders = params.workspaceFolders;
  if (folders && folders.length > 0) workspaceRoot = decodeURIComponent(folders[0].uri.replace("file://", ""));
  else if (params.rootUri) workspaceRoot = decodeURIComponent(params.rootUri.replace("file://", ""));
  else workspaceRoot = process.cwd();
  return {
    capabilities: {
      textDocumentSync: documents.syncKind,
      completionProvider: { triggerCharacters: [".", "@"] },
      semanticTokensProvider: {
        legend: {
          tokenTypes: [
            'keyword', 'type', 'variable', 'macro',
            'function', 'number', 'string', 'operator', 'comment'
          ],
          tokenModifiers: []
        },
        full: true
      },
      definitionProvider: true,
      hoverProvider: true
    }
  };
});

connection.onCompletion((params) => {
  const uri = params.textDocument.uri;
  const document = documents.get(uri);
  if (!document) return [];
  const pos = params.position;
  const lines = document.getText().split(/\r?\n/);

  // include / install
  {
    const lineText = lines[pos.line].slice(0, pos.character);
    const incMatch = lineText.match(/@(include|install)(?:\s+([\w./]*))?$/);
    if (incMatch) {
      let basePath = (incMatch[2] || "").replace(/\./g, "/");
      const currentFile = decodeURIComponent(uri.replace("file://", ""));
      const currentDir = path.dirname(currentFile);
      let resolvedDir = basePath === "" ? currentDir : path.resolve(currentDir, basePath);
      if (!fs.existsSync(resolvedDir)) resolvedDir = path.resolve(workspaceRoot, basePath || ".");
      if (!fs.existsSync(resolvedDir) || !fs.statSync(resolvedDir).isDirectory()) {
        resolvedDir = path.dirname(resolvedDir);
      }
      if (fs.existsSync(resolvedDir) && fs.statSync(resolvedDir).isDirectory()) {
        const entries = fs.readdirSync(resolvedDir);
        return entries.map(entry => {
          const entryPath = path.join(resolvedDir, entry);
          const isDir = fs.existsSync(entryPath) && fs.statSync(entryPath).isDirectory();
          return {
            label: isDir ? entry : entry.replace(/\.s$/, ""),
            kind: isDir ? CompletionItemKind.Folder : CompletionItemKind.File,
            detail: isDir ? "Directory" : "File"
          };
        });
      }
    }
  }

  // directives
  {
    const lineText = lines[pos.line];
    const regex = /@[A-Za-z_.]*/g;
    let match, found = null;
    while ((match = regex.exec(lineText)) !== null) {
      const start = match.index, end = start + match[0].length;
      if (pos.character >= start && pos.character <= end) { found = match[0]; break; }
    }
    if (found && !/^@(include|install)\b/.test(found)) {
      return Object.entries(directives).map(([name, description]) => ({
        label: name,
        kind: CompletionItemKind.Keyword,
        detail: description,
        insertText: name + " "
      }));
    }
  }

  // normal completions
  const collectedSymbols = new Map();
  function collect(u, visited = new Set()) {
    if (visited.has(u)) return;
    visited.add(u);
    const entry = symbolTable.get(u);
    if (!entry) return;
    entry.symbols.forEach(d => collectedSymbols.set(d.name, d));
    (includeGraph.get(u) || new Set()).forEach(included => collect(included, visited));
  }
  collect(uri);
  return [
    ...builtins.map(k => ({ label: k, kind: CompletionItemKind.Keyword })),
    ...keywords.map(k => ({ label: k, kind: CompletionItemKind.Keyword })),
    ...[...collectedSymbols.values()].map(sym => ({
      label: sym.name,
      kind: CompletionItemKind.Function,
      insertText: sym.name,
      detail: "Function",
    }))
  ];
});

connection.onHover((params) => {
  const uri = params.textDocument.uri;
  const doc = documents.get(uri);
  if (!doc) return null;
  const lines = doc.getText().split(/\r?\n/);
  const pos = params.position;
  const word = getWordAt(lines[pos.line], pos.character);
  if (!word) return null;

  let err_contents = "";
  const diags = fileDiagnostics.get(uri) || [];
  for (const d of diags) {
    const { start, end } = d.range;
    if (pos.line === start.line &&
        pos.character >= start.character &&
        pos.character <= end.character &&
        d.message) {
      err_contents += d.message + "\n";
    }
  }
  let contents = "";

  // @include / @install hover info
  function hoverIncludeLike(keyword) {
    const includeLine = lines[pos.line];
    const includeMatch = includeLine.match(new RegExp(`@${keyword}\\s+([\\w.]+)`));
    if (includeMatch) {
      const includeWordStart = includeLine.indexOf(includeMatch[1]);
      const includeWordEnd = includeWordStart + includeMatch[1].length;
      if (pos.character >= includeWordStart && pos.character <= includeWordEnd) {
        const includePath = includeMatch[1].replace(/\./g, "/") + ".s";
        const basePath = decodeURIComponent(uri.replace("file://", ""));
        const dir = path.dirname(basePath);
        let resolvedPath = path.resolve(dir, includePath);
        if (!fs.existsSync(resolvedPath)) resolvedPath = path.resolve(workspaceRoot, includePath);
        if (fs.existsSync(resolvedPath)) {
          if (contents) contents += "\n\n---\n\n";
          contents += `**@${keyword}** → \`${resolvedPath}\``;
        }
      }
    }
  }
  hoverIncludeLike("include");
  hoverIncludeLike("install");

  // keyword descriptions
  const keywordDocs = {
    "def": "**def** — defines an inlined function. Its returned value is a named tuple.",
    "return": "**return** — returns a value from the current code block.",
    "end": "**end** — ends the current block without returning.",
    "service": "**service** — defines a new *runtype* that runs as a co-routine service with safe execution, even on internal failures.",
    "union": "**union** — defines a symbol that expands definitions to several type alternatives.",
    "if": "**if** — decides what to execute next based on a condition.",
    "while": "**while** — repeats a code block based on a condition.",
    "with": "**with** — decides what to execute next based on whether its block of context can be compiled (if not, an alternative or no compilation takes place).",
    "else": "**else** — marks an alternative branch of code.",
    "elif": "**elif** — marks an alternative branch of code that is still checked for a condition. It is equivalent to <code>else->if</code>",
    "on": "**on** — declares a context variable, which may be prepended to all internal calls if they cannot be resolved otherwise.",
    "u64": "**u64** — unsigned 64-bit integer.",
    "i64": "**i64** — signed 64-bit integers.",
    "f64": "**f64** — 64-bit precision number.",
    "bool": "**bool** — a true/false value.",
    "cstr": "**cstr** — a constant c-style string enclosed in \"quotations\".",
    "ptr": "**ptr** — a pointer to a memory address. Manual pointer handling is inherently unsafe and usually requires the file to be set as <code>@unsafe</code>.",
    "char": "**char** — a single byte character. Aligned to 64 bits in buffers."
  };
  if (keywordDocs[word]) contents += keywordDocs[word];

  // Directives
  {
    const lineText = lines[pos.line];
    const regex = /@[A-Za-z_.]+/g;
    let match;
    while ((match = regex.exec(lineText)) !== null) {
      const start = match.index;
      const end = start + match[0].length;
      if (pos.character >= start && pos.character <= end) {
        const directiveName = match[0].slice(1);
        if (directives[directiveName]) {
          if (contents) contents += "\n\n---\n\n";
          contents += `**${match[0]}** — ${directives[directiveName]}`;
        }
        break;
      }
    }
  }

  // collect @about docs from current file + includes
  function collect(u, visited = new Set()) {
    if (visited.has(u)) return [];
    visited.add(u);
    const entry = symbolTable.get(u);
    if (!entry) return [];
    const results = [];
    if (entry.abouts.has(word)) {
      const filePath = decodeURIComponent(u.replace("file://", ""));
      const relPath = path.relative(workspaceRoot, filePath);
      results.push(`**${word}** — ${relPath}`);
      results.push(entry.abouts.get(word));
    }
    (includeGraph.get(u) || new Set()).forEach(inc => results.push(...collect(inc, visited)));
    return results;
  }
  const allContents = collect(uri);
  if (allContents.length) {
    if (contents) contents += "\n\n---\n\n";
    contents += allContents.join("\n\n---\n\n");
  }

  if (contents && err_contents) contents = "\n\n---\n\n" + contents;
  if (err_contents) contents = err_contents + contents;

  contents = contents
    .replace(/\\n/g, "\n")
    .replace(/<pre>/g, "\n```rust\n")
    .replace(/<\/pre>/g, "\n```\n")
    .replace(/<code>/g, "`")
    .replace(/<\/code>/g, "`");

  return contents
    ? { contents: { kind: "markdown", value: contents } }
    : null;
});

function getWordAt(line, character) {
  const regex = /\b[A-Za-z_][A-Za-z0-9_]*\b/g;
  let match;
  while ((match = regex.exec(line)) !== null) {
    if (character >= match.index && character <= match.index + match[0].length) {
      return match[0];
    }
  }
  return null;
}

connection.onDefinition((params) => {
  const uri = params.textDocument.uri;
  const document = documents.get(uri);
  if (!document) return null;
  const pos = params.position;
  const lines = document.getText().split(/\r?\n/);

  // @include definitions
  const includeLine = lines[pos.line];
  const includeMatch = includeLine.match(/@include\s+([\w.]+)/);
  if (includeMatch) {
    const wordStart = includeLine.indexOf(includeMatch[1]);
    const wordEnd = wordStart + includeMatch[1].length;
    if (pos.character >= wordStart && pos.character <= wordEnd) {
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
  }

  const word = getWordAt(lines[pos.line], pos.character);
  if (!word) return null;

  const searchOrder = [];
  function collect(uri, visited = new Set()) {
    if (visited.has(uri)) return;
    visited.add(uri);
    searchOrder.push(uri);
    (includeGraph.get(uri) || new Set()).forEach(included => collect(included, visited));
  }
  collect(uri);
  const foundLocations = [];
  for (const u of searchOrder) {
    const entry = symbolTable.get(u);
    if (!entry) continue;
    for (const { name, line } of entry.symbols) {
      if (name === word) {
        const filePath = decodeURIComponent(u.replace("file://", ""));
        if (!fs.existsSync(filePath)) continue;
        const fileLines = fs.readFileSync(filePath, "utf8").split(/\r?\n/);
        const defLineText = fileLines[line] || "";
        const start = defLineText.indexOf(name);
        if (start !== -1) {
          foundLocations.push(
            Location.create(u, Range.create(line, start, line, start + name.length))
          );
        }
      }
    }
  }
  return foundLocations.length ? foundLocations : null;
});

connection.languages.semanticTokens.on((params) => {
  const uri = params.textDocument.uri;
  const document = documents.get(uri);
  if (!document) return { data: [] };
  const builder = new SemanticTokensBuilder();
  const text = document.getText();
  const lines = text.split(/\r?\n/);

  // collect function names
  const declared = new Set();
  function collect(u, visited = new Set()) {
    if (visited.has(u)) return;
    visited.add(u);
    const entry = symbolTable.get(u);
    if (!entry) return;
    entry.symbols.forEach(sym => declared.add(sym.name));
    (includeGraph.get(u) || new Set()).forEach(inc => collect(inc, visited));
  }
  collect(uri);

  for (let line = 0; line < lines.length; line++) {
    const textLine = lines[line];
    let pos = 0;
    while (pos < textLine.length) {
      if (/\s/.test(textLine[pos])) { pos++; continue; }

      if (textLine.startsWith("//", pos)) {
        builder.push(line, pos, textLine.length - pos, 8, 0);
        break;
      }

      if (textLine[pos] === '"') {
        let end = pos + 1;
        while (end < textLine.length && textLine[end] !== '"') {
          if (textLine[end] === '\\' && end + 1 < textLine.length) end += 2;
          else end++;
        }
        end = Math.min(end + 1, textLine.length);
        builder.push(line, pos, end - pos, 6, 0);
        pos = end;
        continue;
      }

      // if (textLine.startsWith("return", pos)) {
      //   builder.push(line, pos, 6, 3, 0); pos += 6; continue;
      // }
      // if (textLine.startsWith("end", pos)) {
      //   builder.push(line, pos, 3, 3, 0); pos += 3; continue;
      // }
      if (textLine.startsWith("|", pos)) {
        builder.push(line, pos, 1, 3, 0); pos += 1; continue;
      }
      if (textLine[pos] === ':') {
        builder.push(line, pos, 1, 3, 0); pos += 1; continue;
      }

      // identifiers WITHOUT '.' inside
      const match = textLine.slice(pos).match(/^@?[A-Za-z_][A-Za-z0-9_]*/);
      if (match) {
        const word = match[0];
        if (word[0] === "@") builder.push(line, pos, word.length, 3, 0); // directive
        else if (keywords.includes(word)) builder.push(line, pos, word.length, 0, 0); // keyword
        else if (builtins.includes(word)) builder.push(line, pos, word.length, 1, 0); // function (Types is 1 instead of 4)
        else if (declared.has(word)) {
          // check if followed by '(' → function call
          let j = pos + word.length;
          while (j < textLine.length && /\s/.test(textLine[j])) j++;
          if (j < textLine.length && textLine[j] === "(")
            builder.push(line, pos, word.length, 1, 0); // function
          else builder.push(line, pos, word.length, 1, 0); // type
        } //else builder.push(line, pos, word.length, 2, 0); // function
        pos += word.length;
        continue;
      }

      // dot operator (split x.y.z)
      if (textLine[pos] === ".") {
        builder.push(line, pos, 1, 7, 0); // operator
        pos++;
        continue;
      }

      pos++;
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
  if (!compileState.has(uri)) compileState.set(uri, { running: false, rerunRequested: false, debounceTimer: null });
  const state = compileState.get(uri);
  if (state.debounceTimer) clearTimeout(state.debounceTimer);
  state.debounceTimer = setTimeout(() => {
    if (state.running) {
      state.rerunRequested = true;
      return;
    }
    state.running = true;
    state.debounceTimer = null;
    const tempFilePath = path.join(os.tmpdir(), `smol_${randomUUID()}.s`);
    fs.writeFileSync(tempFilePath, text, "utf8");
    const proc = spawn("./smol", [tempFilePath, "--task", "lsp"]);
    let stderr = "";
    proc.stderr.on("data", chunk => { stderr += chunk.toString(); });
    proc.on("close", () => {
      const lines = stderr.split(/\r?\n/);
      const diagnostics = [];
      const diagnostics_no_text = [];
      let messageLines = [];
      for (let i = 0; i < lines.length; i++) {
        const line = stripAnsi(lines[i]);
        if (line.startsWith("at")) {
          const locMatch = line.match(/^at\s+(.*)\s+line\s+(\d+)\s+col\s+(\d+)/);
          if (!locMatch) continue;
          const [, , lineStr, colStr] = locMatch;
          const lineNum = parseInt(lineStr, 10) - 1;
          const colNum = parseInt(colStr, 10) - 1;
          const caretLine = lines[i + 2] || "";
          const caretMatch = caretLine.match(/\^+/);
          const tokenLength = caretMatch ? caretMatch[0].length : 1;
          const message = messageLines.slice(1).join("\n\n") || "";
          diagnostics.push({
            severity: 1,
            range: { start: { line: lineNum, character: colNum }, end: { line: lineNum, character: colNum + tokenLength } },
            message: message,
            source: "smol"
          });
          diagnostics_no_text.push({
            severity: 1,
            range: { start: { line: lineNum, character: colNum }, end: { line: lineNum, character: colNum + tokenLength } },
            message: "ERROR - " + messageLines[0],
            source: "smol"
          });
          messageLines = [];
          i += 2;
        } else messageLines.push(line);
      }
      try { fs.unlinkSync(tempFilePath); }
      catch (e) { console.error("Failed to remove temp file:", tempFilePath); }
      connection.sendDiagnostics({ uri, diagnostics: diagnostics_no_text });
      fileDiagnostics.set(uri, diagnostics);
      if (state.rerunRequested) {
        state.rerunRequested = false;
        state.running = false;
        runCompilerAndSendDiagnostics(document);
      } else state.running = false;
    });
  }, 300);
  function stripAnsi(line) {
    if (!line) return '';
    return line
      .replace(/\x1b\[31m/g, '')
      .replace(/\x1b\[32m/g, '')
      .replace(/\x1b\[33m/g, '')
      .replace(/\x1b\[34m/g, '')
      .replace(/\x1b\[35m/g, '')
      .replace(/\x1b\[36m/g, '')
      .replace(/\x1b\[38m/g, '')
      .replace(/\x1b\[0m/g, '');
  }
}

connection.onNotification('custom/windowFocused', (params) => { analyzeDocument(params.uri, params.text); });
documents.onDidChangeContent(async (e) => { await runCompilerAndSendDiagnostics(e.document); });
documents.onDidSave(async (e) => { await runCompilerAndSendDiagnostics(e.document); });
documents.listen(connection);
connection.listen();
