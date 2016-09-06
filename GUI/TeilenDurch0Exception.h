#pragma once
ref class TeilenDurch0Exception : public System::Exception
{
public:
	int zaehler;

	TeilenDurch0Exception()
	{
	}

	TeilenDurch0Exception(System::String^ message, int zaehler)
	{
		this->Exception::Exception(message);
		this->zaehler = zaehler;
	}

	virtual ~TeilenDurch0Exception()
	{
	}
};

