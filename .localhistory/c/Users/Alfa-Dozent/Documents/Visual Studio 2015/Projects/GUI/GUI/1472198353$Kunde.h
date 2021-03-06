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

	void addKundeNodeToKundeVerzeichnisXml(System::Xml::XmlDocument^ targetXmlDocument, System::String^ kundeType)
	{
		System::Xml::XmlDocument^ kundenVerzeichnisXMLDocument = gcnew System::Xml::XmlDocument();
		try
		{
			kundenVerzeichnisXMLDocument->Load("d:\\Kunden.xml");

			System::Xml::XmlNode^ targetNode =
				kundenVerzeichnisXMLDocument->SelectSingleNode("/Kundenverzeichnis/" + kundeType);
			System::Xml::XmlNode^ kundeNode =
				kundenVerzeichnisXMLDocument->CreateNode(System::Xml::XmlNodeType::Element, "Kunde", "");
			System::Xml::XmlAttribute^ idAttribute = kundenVerzeichnisXMLDocument->CreateAttribute("id");
			idAttribute->Value = id;
			kundeNode->Attributes->Append(idAttribute);
			System::Xml::XmlNode^ vornameNode =
				kundenVerzeichnisXMLDocument->CreateNode(System::Xml::XmlNodeType::Element, "vorname", "");
			vornameNode->InnerText = vorname;
			System::Xml::XmlNode^ nachnameNode =
				kundenVerzeichnisXMLDocument->CreateNode(System::Xml::XmlNodeType::Element, "nachname", "");
			nachnameNode->InnerText = nachname;
			System::Xml::XmlNode^ strasseNode =
				kundenVerzeichnisXMLDocument->CreateNode(System::Xml::XmlNodeType::Element, "strasse", "");
			strasseNode->InnerText = strasse;
			System::Xml::XmlNode^ plzNode =
				kundenVerzeichnisXMLDocument->CreateNode(System::Xml::XmlNodeType::Element, "plz", "");
			plzNode->InnerText = plz;
			System::Xml::XmlNode^ ortNode =
				kundenVerzeichnisXMLDocument->CreateNode(System::Xml::XmlNodeType::Element, "ort", "");
			ortNode->InnerText = ort;
			System::Xml::XmlNode^ umsatzNode =
				kundenVerzeichnisXMLDocument->CreateNode(System::Xml::XmlNodeType::Element, "umsatz", "");
			umsatzNode->InnerText = umsatz;
			System::Xml::XmlNode^ benutzernameNode =
				kundenVerzeichnisXMLDocument->CreateNode(System::Xml::XmlNodeType::Element, "benutzername", "");
			benutzernameNode->InnerText = benutzername;

			targetNode->AppendChild(kundeNode);
			kundeNode->AppendChild(vornameNode);
			kundeNode->AppendChild(nachnameNode);
			kundeNode->AppendChild(strasseNode);
			kundeNode->AppendChild(plzNode);
			kundeNode->AppendChild(ortNode);
			kundeNode->AppendChild(umsatzNode);
			kundeNode->AppendChild(benutzernameNode);

			kundenVerzeichnisXMLDocument->Save("d:\\Kunden.xml");
		}
		catch (Exception^ e)
		{
			logger->Fatal(e->Message);
		}
	}

};

