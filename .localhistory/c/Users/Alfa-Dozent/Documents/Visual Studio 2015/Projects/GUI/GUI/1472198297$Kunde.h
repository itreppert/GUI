#pragma once
ref class Kunde
{
public:

	Kunde()
	{
	}

	virtual ~Kunde()
	{
	}

	int id;
	System::String^ vorname;
	System::String^ nachname;
	System::String^ strasse;
	System::String^ plz;
	System::String^ ort;
	double vorname;
	System::String^ benutzername;
};

