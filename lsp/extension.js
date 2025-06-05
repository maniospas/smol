const path = require('path');
const vscode = require('vscode');
const { LanguageClient, TransportKind } = require('vscode-languageclient/node');
let arrowDecoration = vscode.window.createTextEditorDecorationType({
  color: 'transparent', // hide the actual text, but keep space and cursor behavior
  //letterSpacing: '-1ch',
  after: {
    contentText: "―▶",
    color: "#58f",
    fontWeight: "bold",
    margin: "0 0 0 -2ch", // shift left to draw over original
  },
  rangeBehavior: vscode.DecorationRangeBehavior.ClosedClosed
});
let dashDecoration = vscode.window.createTextEditorDecorationType({
  color: 'transparent', // hide the actual text, but keep space and cursor behavior
  //letterSpacing: '-1ch',
  after: {
    contentText: "――",
    color: "#58f",
    fontWeight: "bold",
    margin: "0 0 0 -2ch", // shift left to draw over original
  },
  rangeBehavior: vscode.DecorationRangeBehavior.ClosedClosed
});
let dashDecoration2 = vscode.window.createTextEditorDecorationType({
  after: {
    contentText: " [end] ",
    color: "#5588ff99",
  },
  rangeBehavior: vscode.DecorationRangeBehavior.ClosedClosed
});

const fileDiagnostics = new Map();

let client = null;
async function activate(context) {
  // vscode.window.showInformationMessage("Starting smoλ language server.");
  const serverModule = path.join(__dirname, 'server.js');
  const serverOptions = {
    run: { module: serverModule, transport: TransportKind.stdio },
    debug: { module: serverModule, transport: TransportKind.stdio,options: {execArgv: ['--nolazy', '--inspect=6009']}}
  };
  const outputChannel = vscode.window.createOutputChannel('Smoλ language server');
  const clientOptions = { documentSelector: [{ scheme: 'file', language: 'smolambda' }], outputChannel};
  client = new LanguageClient(
    'smolambdaLanguageServer',
    'Smoλ language server',
    serverOptions,
    clientOptions);
  try {
    await client.start();
    vscode.window.showInformationMessage("Smoλ language server started.");
    vscode.window.onDidChangeWindowState(state => {
      if(state.focused) {
          const editor = vscode.window.activeTextEditor;
          if(editor) client.sendNotification('custom/windowFocused', {uri: editor.document.uri.toString(),text: editor.document.getText()});
      }
    });
    client.onNotification('server/error', (message) => {vscode.window.showErrorMessage(`Smoλ language server error: ${message}`);});
    client.onNotification("smolambda/decorations", ({ uri, arrows, dashes }) => {
      const editor = vscode.window.visibleTextEditors.find(e => e.document.uri.toString() === uri);
      if(!editor) return;
      const arrowRanges = (arrows || []).map(d => ({range: new vscode.Range(d.range.start.line, d.range.start.character,d.range.end.line, d.range.end.character)}));
      const dashRanges = (dashes || []).map(d => ({range: new vscode.Range(d.range.start.line, d.range.start.character,d.range.end.line, d.range.end.character)}));
      editor.setDecorations(dashDecoration, dashRanges);
      editor.setDecorations(arrowDecoration, arrowRanges);
      //editor.setDecorations(dashDecoration2, dashRanges);
    });


    client.onNotification("smolambda/htmlNotification", ({ uri, diagnostics }) => {fileDiagnostics.set(uri, diagnostics);});
  } 
  catch (err) {
    vscode.window.showErrorMessage(`Smoλ language server failed to start: ${err.message}`);
    outputChannel.appendLine(err.stack || err.toString());
  }
  context.subscriptions.push({ dispose: () => client?.stop() });
}


vscode.languages.registerHoverProvider("smolambda", {
  provideHover(document, position, token) {
    const line = position.line;
    const text = document.lineAt(line).text;
    const uri = document.uri.toString();
    const diagnostic = (fileDiagnostics.get(uri) || []).find(d => {
      const start = d.range.start;
      const end = d.range.end;
      return (
        (position.line > start.line || (position.line === start.line && position.character >= start.character)) &&
        (position.line < end.line || (position.line === end.line && position.character <= end.character))
      );
    });
    const markdown = new vscode.MarkdownString();
    markdown.appendCodeblock(text.trim(), "rust");
    if (diagnostic) markdown.appendMarkdown("\n\n---\n\n" + diagnostic.message);
    markdown.isTrusted = true;
    return new vscode.Hover(markdown);
  }
});


function deactivate() { return client?.stop();}
module.exports = {activate,deactivate};
