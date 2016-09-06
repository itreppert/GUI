#include "MainForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main()
{
	//Visuelle Einstellungen
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//Fenster wird gebaut
	GUI::MainForm^ myForm = gcnew GUI::MainForm;
	//Fenster wird gestartet
	Application::Run(myForm);
}