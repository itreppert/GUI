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
		textBoxFromAnotherForm->AppendText("From Test Class");
	}
};

