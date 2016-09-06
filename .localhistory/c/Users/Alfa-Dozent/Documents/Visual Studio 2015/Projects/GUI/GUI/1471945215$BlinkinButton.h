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

	BlinkinButton(int interval, System::Drawing::Color color1, System::Drawing::Color color2)
	{
		changeConfig(interval, color1, color2);
	}

	void changeConfig(int interval, System::Drawing::Color color1, System::Drawing::Color color2)
	{
		t = gcnew Timer();
		t->Interval = interval;
		t->Enabled = true;
		t->Tick += gcnew System::EventHandler(this, &BlinkinButton::OnTick);
		this->color1 = color1;
		this->color2 = color2;
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

	void OnMouseHover(System::EventArgs^ e) override
	{
		this->Location = Point(this->Location->X)
	}

	virtual ~BlinkinButton()
	{
		delete t;
	}

private:
	Timer^ t;
	System::Drawing::Color color1;
	System::Drawing::Color color2;
};

