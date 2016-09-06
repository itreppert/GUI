#pragma once
public ref class RegexTextBox :public System::Windows::Forms::TextBox
{
public:
	System::String^ regexExpression;
	System::Drawing::Color regexErrorColor;
	RegexTextBox()
	{
	}

	RegexTextBox(System::String^ regexExpression, System::Drawing::Color regexErrorColor)
	{
		this->regexErrorColor = regexErrorColor;
		this->regexExpression = regexExpression;
	}

	virtual ~RegexTextBox()
	{
	}
};

