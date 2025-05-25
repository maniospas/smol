const path = require('path');
const vscode = require('vscode');
const { LanguageClient, TransportKind } = require('vscode-languageclient/node');

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
    client.onNotification('server/error', (message) => {vscode.window.showErrorMessage(`Smoλ language server error: ${message}`);});
  } 
  catch (err) {
    vscode.window.showErrorMessage(`Smoλ language server failed to start: ${err.message}`);
    outputChannel.appendLine(err.stack || err.toString());
  }
  context.subscriptions.push({ dispose: () => client?.stop() });
}

function deactivate() { return client?.stop();}
module.exports = {activate,deactivate};
