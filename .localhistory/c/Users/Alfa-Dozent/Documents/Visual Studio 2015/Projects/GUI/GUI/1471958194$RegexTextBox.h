#pragma once
public ref class RegexTextBox :public System::Windows::Forms::TextBox
{
public:

	RegexTextBox()
	{
		this->regexExpression = "^([\\+][0-9]{1,3}[ \\.\\-])?([\\(]{1}[0-9]{1,6}[\\)])?([0-9 \\.\\-\\/]{3,20})((x|ext|extension)[ ]?[0-9]{1,4})?$";
		this->regexErrorColor = System::Drawing::Color::LightSalmon;
		this->TextBox::TextBox();
	}

	RegexTextBox(System::String^ regexExpression, System::Drawing::Color regexErrorColor)
	{
		this->regexErrorColor = regexErrorColor;
		this->regexExpression = regexExpression;
		this->TextBox::TextBox();
	}

	void reconfigure(System::String^ regexExpression, System::Drawing::Color regexErrorColor)
	{
		this->regexErrorColor = regexErrorColor;
		this->regexExpression = regexExpression;
	}

	void match()
	{
		System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex(this->regexExpression);
		if (regex->IsMatch(this->Text))
		{
			this->BackColor = System::Drawing::Color::White;
		}
		else
		{
			this->BackColor = regexErrorColor;
		}
	}



	void OnTextChanged(System::EventArgs^ e) override
	{
		match();
	}

	virtual ~RegexTextBox()
	{
	}
private:
	System::String^ regexExpression;
	System::Drawing::Color regexErrorColor;
};

