#pragma once
public ref class Kunde
{
public:

	Kunde()
	{
	}

	virtual ~Kunde()
	{
	}

	static NLog::Logger^ logger = NLog::LogManager::GetCurrentClassLogger();
	int id;
	System::String^ vorname;
	System::String^ nachname;
	System::String^ strasse;
	System::String^ plz;
	System::String^ ort;
	double umsatz;
	System::String^ benutzername;

	void getFromKundeVerzeichnisXml(System::Xml::XmlDocument^ sourceXmlDocument)
	{
		try
		{
			System::Xml::XmlNode^ kundeNode =
				sourceXmlDocument->SelectSingleNode("//Kunde[@id='" + id.ToString() + "']");

			this->id = id;

			System::Xml::XmlNode^ vornameNode = kundeNode->SelectSingleNode("vorname");
			this->vorname = vornameNode->InnerText;
			System::Xml::XmlNode^ nachnameNode = kundeNode->SelectSingleNode("nachname");
			this->nachname = nachnameNode->InnerText;
			System::Xml::XmlNode^ strasseNode = kundeNode->SelectSingleNode("strasse");
			this->strasse = strasseNode->InnerText;
			System::Xml::XmlNode^ plzNode = kundeNode->SelectSingleNode("plz");
			this->plz = plzNode->InnerText;
			System::Xml::XmlNode^ ortNode = kundeNode->SelectSingleNode("ort");
			this->ort = ortNode->InnerText;
			System::Xml::XmlNode^ umsatzNode = kundeNode->SelectSingleNode("umsatz");
			this->umsatz = double::Parse(umsatzNode->InnerText);
			System::Xml::XmlNode^ benutzernameNode = kundeNode->SelectSingleNode("benutzername");
			this->benutzername = benutzernameNode->InnerText;
		}
		catch (System::Exception^ e)
		{
			logger->Fatal(e->Message);
		}
	}

	void addToKundeVerzeichnisXml(System::Xml::XmlDocument^ targetXmlDocument, System::String^ kundeType)
	{
		try
		{
			System::Xml::XmlNode^ targetNode =
				targetXmlDocument->SelectSingleNode("/Kundenverzeichnis/" + kundeType);
			System::Xml::XmlNode^ kundeNode =
				targetXmlDocument->CreateNode(System::Xml::XmlNodeType::Element, "Kunde", "");
			System::Xml::XmlAttribute^ idAttribute = targetXmlDocument->CreateAttribute("id");
			idAttribute->Value = id.ToString();
			kundeNode->Attributes->Append(idAttribute);
			System::Xml::XmlNode^ vornameNode =
				targetXmlDocument->CreateNode(System::Xml::XmlNodeType::Element, "vorname", "");
			vornameNode->InnerText = vorname;
			System::Xml::XmlNode^ nachnameNode =
				targetXmlDocument->CreateNode(System::Xml::XmlNodeType::Element, "nachname", "");
			nachnameNode->InnerText = nachname;
			System::Xml::XmlNode^ strasseNode =
				targetXmlDocument->CreateNode(System::Xml::XmlNodeType::Element, "strasse", "");
			strasseNode->InnerText = strasse;
			System::Xml::XmlNode^ plzNode =
				targetXmlDocument->CreateNode(System::Xml::XmlNodeType::Element, "plz", "");
			plzNode->InnerText = plz;
			System::Xml::XmlNode^ ortNode =
				targetXmlDocument->CreateNode(System::Xml::XmlNodeType::Element, "ort", "");
			ortNode->InnerText = ort;
			System::Xml::XmlNode^ umsatzNode =
				targetXmlDocument->CreateNode(System::Xml::XmlNodeType::Element, "umsatz", "");
			umsatzNode->InnerText = umsatz.ToString("F2");
			System::Xml::XmlNode^ benutzernameNode =
				targetXmlDocument->CreateNode(System::Xml::XmlNodeType::Element, "benutzername", "");
			benutzernameNode->InnerText = benutzername;

			targetNode->AppendChild(kundeNode);
			kundeNode->AppendChild(vornameNode);
			kundeNode->AppendChild(nachnameNode);
			kundeNode->AppendChild(strasseNode);
			kundeNode->AppendChild(plzNode);
			kundeNode->AppendChild(ortNode);
			kundeNode->AppendChild(umsatzNode);
			kundeNode->AppendChild(benutzernameNode);

			targetXmlDocument->Save("d:\\Kunden.xml");
		}
		catch (System::Exception^ e)
		{
			logger->Fatal(e->Message);
		}
	}

	bool deleteKunde(System::Xml::XmlDocument^ sourceXmlDocument)
	{
		try
		{
			System::Xml::XmlNode^ kundeNode =
				sourceXmlDocument->SelectSingleNode("//Kunde[@id='" + id.ToString() + "']");
			kundeNode->ParentNode->RemoveChild(kundeNode);
			return true;
		}
		catch (System::Exception^ e)
		{
			logger->Fatal(e->Message);
			return false;
		}
	}

	System::String^ ToString() override
	{
		System::String^ result = id.ToString() + "," + vorname + "," + nachname + "," + strasse + "," + plz + "," + ort + "," + umsatz + "," + benutzername;
		return result;
	}

	bool updateKunde(System::Xml::XmlDocument^ sourceXmlDocument)
	{

		//Alten Kunden l�schen		//geupgedateten Kunden NEU in das Dokument schreiben		//wohin ??? Normalkunde ? Geschaeftskunde ?		//
	}

	System::String^ getKundeCategory(System::Xml::XmlDocument^ sourceXmlDocument)
	{
		try
		{
			System::Xml::XmlNode^ kundeNode =
				sourceXmlDocument->SelectSingleNode("//Kunde[@id='" + id.ToString() + "']");
			return kundeNode->ParentNode->Name;
		}
		catch (System::Exception^ e)
		{
			logger->Fatal(e->Message);
		}
	}
};

