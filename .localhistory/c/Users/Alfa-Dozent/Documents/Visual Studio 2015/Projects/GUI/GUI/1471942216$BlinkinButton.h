#pragma once
ref class BlinkinButton :public System::Windows::Forms::Button
{
public:

	Timer^ t;
	System::Drawing::Color c1;
	System::Drawing::Color c2;


	BlinkinButton()
	{
		t = gcnew Timer();
		t->Interval = 1000;
		t->Enabled = true;
		t->Tick += gcnew System::EventHandler(this, &BlinkinButton::OnTick);
	}

	void OnTick(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->BackColor == System::Drawing::Color::LightSalmon)
		{
			this->BackColor = System::Drawing::Color::LightSeaGreen;
		}
		else
		{
			this->BackColor = System::Drawing::Color::LightSalmon;
		}
	}

	virtual ~BlinkinButton()
	{
	}
};

