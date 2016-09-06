#pragma once
using namespace System::Windows::Forms;

public ref class Test
{
public:
	Test()
	{
	}

	void changeTextBoxText(TextBox^ textBox)
	{
		textBox->AppendText("From Test Class");
	}
};

