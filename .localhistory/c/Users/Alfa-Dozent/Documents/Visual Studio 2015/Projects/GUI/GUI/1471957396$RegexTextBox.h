#pragma once
public ref class RegexTextBox :public System::Windows::Forms::TextBox
{
public:
	System::String^ regexExpression;
	System::Drawing::Color regexErrorColor;
	RegexTextBox()
	{
		this->regexErrorColor = "^([\\+][0-9]{1,3}[ \\.\\-])?([\\(]{1}[0-9]{1,6}[\\)])?([0-9 \\.\\-\\/]{3,20})((x|ext|extension)[ ]?[0-9]{1,4})?$";
		this->regexExpression = regexExpression;
		this->TextBox::TextBox();
	}

	RegexTextBox(System::String^ regexExpression, System::Drawing::Color regexErrorColor)
	{
		this->regexErrorColor = regexErrorColor;
		this->regexExpression = regexExpression;
		this->TextBox::TextBox();
	}

	virtual ~RegexTextBox()
	{
	}
};

