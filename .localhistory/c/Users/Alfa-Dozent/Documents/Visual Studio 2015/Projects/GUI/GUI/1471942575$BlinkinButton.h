#pragma once
ref class BlinkinButton :public System::Windows::Forms::Button
{
public:



	BlinkinButton()
	{
		t = gcnew Timer();
		t->Interval = 1000;
		t->Enabled = true;
		t->Tick += gcnew System::EventHandler(this, &BlinkinButton::OnTick);
	}

	BlinkinButton()
	{
		t = gcnew Timer();
		t->Interval = 1000;
		t->Enabled = true;
		t->Tick += gcnew System::EventHandler(this, &BlinkinButton::OnTick);
	}


	void OnTick(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->BackColor == color1)
		{
			this->BackColor = color2;
		}
		else
		{
			this->BackColor = color1;
		}
	}

	virtual ~BlinkinButton()
	{
	}

private :
	Timer^ t;
	System::Drawing::Color color1;
	System::Drawing::Color color2;
};

