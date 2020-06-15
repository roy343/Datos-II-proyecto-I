 // The module 'vscode' contains the VS Code extensibility API
// Import the module and reference it with the alias vscode in your code below
const vscode = require('vscode');

// this method is called when your extension is activated
// your extension is activated the very first time the command is executed

/**
 * @param {vscode.ExtensionContext} context
 */
function activate(context) {

	//Avisa que la exetension se ejecuto con exito
	console.log('La extension esta siendo ejecutada');

	//
	let disposable = vscode.commands.registerCommand('memory-manager.helloWorld', function () {
		const editor = vscode.window.activeTextEditor;
		
		vscode.window.showInformationMessage('Memory Manager a sido ejecutado con exito');
		editor.edit((edit)=>{
			//edit.replace(editor.selection,"#include \"vs.h\"")
			edit.replace(editor.selection,"#include <iostream>")
		})
	});

	context.subscriptions.push(disposable);
}
exports.activate = activate;

//Este metodo se invoca cuando la extension se desactiva
function deactivate() {}

module.exports = {
	activate,
	deactivate
}
