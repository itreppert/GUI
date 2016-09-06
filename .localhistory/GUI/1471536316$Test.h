#pragma once
#include "MainForm.h"
using namespace System::Windows::Forms;

public ref class Test
{
public:
	Test()
	{
	}

	void changeTextBoxText(GUI::MainForm^ form)
	{
		textBox->AppendText("From Test Class");
	}
};

