#pragma once
using namespace System::Windows::Forms;

public ref class Test
{
public:

	TextBox^ textBoxFromAnotherForm;

	Test(TextBox^ textBox)
	{
		textBoxFromAnotherForm = textBox;
	}

	void changeTextBoxText()
	{
		neTextbox->AppendText("From Test Class");
	}
};

