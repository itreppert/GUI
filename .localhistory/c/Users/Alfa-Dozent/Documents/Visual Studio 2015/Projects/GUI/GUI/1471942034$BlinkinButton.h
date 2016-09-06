#pragma once
ref class BlinkinButton :public System::Windows::Forms::Button
{
public:

	Timer^ t;

	BlinkinButton()
	{
		t = gcnew Timer();
		t->Interval = 1000;
		t->Enabled = true;
		t->Tick += gcnew System::EventHandler(this, &BlinkinButton::OnTick);
	}

	void OnTick(System::Object^ sender, EventArgs^ e)
	{
		this->BackColor = System::Drawing::Color::LightSalmon;
	}

	virtual ~BlinkinButton()
	{
	}
};

