#pragma once
ref class BlinkinButton :public System::Windows::Forms::Button
{
public:

	Timer^ t;

	BlinkinButton()
	{
		t = gcnew Timer();
	}

	virtual ~BlinkinButton()
	{
	}
};

