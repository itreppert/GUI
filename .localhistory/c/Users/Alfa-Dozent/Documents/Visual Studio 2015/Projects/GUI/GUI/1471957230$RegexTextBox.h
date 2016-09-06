#pragma once
public ref class RegexTextBox :public System::Windows::Forms::TextBox
{
public:
	System::String^ regexExpression;
	System::Drawing::Color regexErrorColor;
	RegexTextBox()
	{
	}

	virtual ~RegexTextBox()
	{
	}
};

