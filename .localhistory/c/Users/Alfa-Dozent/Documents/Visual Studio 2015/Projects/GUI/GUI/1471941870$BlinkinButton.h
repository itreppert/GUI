#pragma once
ref class BlinkinButton :public System::Windows::Forms::Button
{
public:

	Timer^ t;

	BlinkinButton()
	{
		t = gcnew Timer();
		t->Interval = 1000;
	}

	virtual ~BlinkinButton()
	{
	}
};

