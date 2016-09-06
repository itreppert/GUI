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
		this->Button::Button();
	}

	BlinkinButton(int interval, System::Drawing::Color color1, System::Drawing::Color color2)
	{
		changeConfig(interval, color1, color2);
		this->Button::Button();
	}

	void changeConfig(int interval, System::Drawing::Color color1, System::Drawing::Color color2)
	{
		t = gcnew Timer();
		t->Interval = interval;
		t->Enabled = false;
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
		logger->Debug("I got hovered from myself !!!");
		this->Location = System::Drawing::Point(this->Location.X + 30, this->Location.Y);
		//"Forward MouseHoverEvent to the form"
		this->Button::OnMouseHover(e);
	}

	virtual ~BlinkinButton()
	{
		delete t;
	}

private:
	static NLog::Logger^ logger = NLog::LogManager::GetCurrentClassLogger();
	Timer^ t;
	System::Drawing::Color color1;
	System::Drawing::Color color2;
};

