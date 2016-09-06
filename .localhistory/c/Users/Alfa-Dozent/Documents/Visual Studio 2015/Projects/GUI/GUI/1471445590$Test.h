#pragma once
using namespace System::Windows::Forms;

public ref class Test
{
public:

	Test()
	{
	}

	void changeTextBoxText(TextBox^ neTextbox)
	{
		neTextbox->AppendText("From Test Class");
	}
};

