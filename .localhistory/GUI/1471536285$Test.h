#pragma once
using namespace System::Windows::Forms;

public ref class Test
{
public:
	Test()
	{
	}

	void changeTextBoxText(GUI::MainForm)
	{
		textBox->AppendText("From Test Class");
	}
};

