#pragma once
#include "DatabaseManager.h"
#include "IDatabaseable.h"
#include "IXmlable.h"
namespace GUI{

	public ref class Kunde : public IDatabaseable, public IXmlable
	{
	public:

		Kunde()
		{
			databaseManager = gcnew DatabaseManager;
			databaseManager->serverName = "localhost";
			databaseManager->databaseName = "Firma";
			databaseManager->userName = "sa";
			databaseManager->password = "sa";
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
		double umsatz;
		System::String^ benutzername;

		DatabaseManager^ databaseManager;

		System::Collections::ArrayList^ getIdArrayList() {
			databaseManager->connect();

			System::String^ sqlSelectKundenIdsCommand =
				"SELECT id FROM Kunden";

			System::Data::SqlClient::SqlCommand^ selectKundenCommand =
				gcnew System::Data::SqlClient::SqlCommand(sqlSelectKundenIdsCommand, databaseManager->getConnection());

			System::Data::SqlClient::SqlDataReader^ kundenDataReader = selectKundenCommand->ExecuteReader();
			System::Collections::ArrayList^ idArrayList = gcnew System::Collections::ArrayList;

			while (kundenDataReader->Read())
			{
				idArrayList->Add((int)kundenDataReader["id"]);
			}
			kundenDataReader->Close();
			databaseManager->disconnect();
			return idArrayList;
		}

		System::Windows::Forms::ListViewItem^ getAsListViewItem() {
			System::Windows::Forms::ListViewItem^  kundenListViewItem = gcnew System::Windows::Forms::ListViewItem(
				gcnew array< System::String^  >(8)
			{
				id.ToString(), vorname, nachname,
					strasse, plz, ort,
					umsatz.ToString(), benutzername
			}, -1);

			return kundenListViewItem;
		}

		virtual bool update() {
			try {
				databaseManager->connect();
				System::Globalization::CultureInfo^ cultureInfoUS = gcnew System::Globalization::CultureInfo("en-US");
				//DELETE FROM Kunden WHERE id=?
				System::String^ sqlUpdateKundenCommand =
					"UPDATE Kunden SET vorname='" + vorname + "'," +
					"nachname = '" + nachname + "', " +
					"strasse = '" + strasse + "', " +
					"plz = '" + plz + "', " +
					"ort = '" + ort + "', " +
					"benutzername = '" + benutzername + "', " +
					"umsatz=" + umsatz.ToString(cultureInfoUS) +
					" WHERE id=" + id;
				logger->Debug(sqlUpdateKundenCommand);

				System::Data::SqlClient::SqlCommand^ updateKundeCommand =
					gcnew System::Data::SqlClient::SqlCommand(sqlUpdateKundenCommand, databaseManager->getConnection());
				int betroffeneZeile = updateKundeCommand->ExecuteNonQuery();
			}
			catch (System::Exception^ e) {
				logger->Fatal(e->Message);
				return false;
			}
			finally{
				databaseManager->disconnect();
			}
			return true;
		}

		virtual bool load() {
			System::Data::SqlClient::SqlDataReader^ kundenDataReader;
			try {
				databaseManager->connect();
				System::Globalization::CultureInfo^ cultureInfoUS = gcnew System::Globalization::CultureInfo("en-US");
				//Select * FROM Kunden id=?
				System::String^ sqlSelectKundenCommand =
					"SELECT * FROM Kunden WHERE id=" + id;

				System::Data::SqlClient::SqlCommand^ selectKundenCommand =
					gcnew System::Data::SqlClient::SqlCommand(sqlSelectKundenCommand, databaseManager->getConnection());


				kundenDataReader = selectKundenCommand->ExecuteReader();
				kundenDataReader->Read();

				this->vorname = (System::String^)kundenDataReader["vorname"];
				this->nachname = (System::String^)kundenDataReader["nachname"];
				this->strasse = (System::String^)kundenDataReader["strasse"];
				this->plz = (System::String^)kundenDataReader["plz"];
				this->ort = (System::String^)kundenDataReader["ort"];
				this->benutzername = (System::String^)kundenDataReader["benutzername"];
				this->umsatz = double::Parse(((System::Decimal)kundenDataReader["umsatz"]).ToString(cultureInfoUS));

			}
			catch (System::Exception^ e) {
				logger->Fatal(e->Message);
				return false;
			}
			finally{
				kundenDataReader->Close();
				databaseManager->disconnect();
			}
			return true;
		}


		virtual int deleteMe() {
			databaseManager->connect();

			//DELETE FROM Kunden WHERE id=?
			System::String^ sqlDeleteKundeCommand =
				"DELETE FROM Kunden WHERE id=" + id.ToString();

			System::Data::SqlClient::SqlCommand^ deleteKundeCommand =
				gcnew System::Data::SqlClient::SqlCommand(sqlDeleteKundeCommand, databaseManager->getConnection());
			int betroffeneZeile = deleteKundeCommand->ExecuteNonQuery();

			databaseManager->disconnect();
			return betroffeneZeile;
		}

		virtual int insert() {
			try {
				databaseManager->connect();

				System::Globalization::CultureInfo^ cultureInfoUS = gcnew System::Globalization::CultureInfo("de-DE");

				//INSERT INTO Kunden (vorname,nachname,strasse,plz,ort,benutzername,umsatz) VALUES('Holger','Reppert','Blastreet','66111','Saarbridges','Blondie',20000);
				System::String^ sqlInsertIntoKundenCommand =
					"INSERT INTO Kunden (vorname,nachname,strasse,plz,ort,benutzername,umsatz) VALUES('"
					+ vorname + "','"
					+ nachname + "','"
					+ strasse + "','"
					+ plz + "','"
					+ ort + "','"
					+ benutzername + "',"
					+ umsatz.ToString(cultureInfoUS) + ");";
				logger->Trace(sqlInsertIntoKundenCommand);

				System::Data::SqlClient::SqlCommand^ insertIntoKundenCommand =
					gcnew System::Data::SqlClient::SqlCommand(sqlInsertIntoKundenCommand, databaseManager->getConnection());
				int betroffeneZeile = insertIntoKundenCommand->ExecuteNonQuery();
				int insertedKundenid = databaseManager->getLastInsertedIdSQLServer("Kunden");
				databaseManager->disconnect();
				return insertedKundenid;

			}
			catch (System::Exception^ e) {
				logger->Fatal(e->Message);
				return 0;
			}
		}

		virtual void getFromVerzeichnisXml(System::Xml::XmlDocument^ sourceXmlDocument)
		{
			try
			{
				System::Xml::XmlNode^ kundeNode =
					sourceXmlDocument->SelectSingleNode("//Kunde[@id='" + id.ToString() + "']");

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

		virtual void addToVerzeichnisXml(System::Xml::XmlDocument^ targetXmlDocument, System::String^ kundeType)
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
			}
			catch (System::Exception^ e)
			{
				logger->Fatal("Node not found : " + kundeType);
				logger->Fatal(e->Message);
			}
		}

		virtual bool deleteFromVerzeichnisXml(System::Xml::XmlDocument^ sourceXmlDocument)
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
			System::String^ category = this->getCategory(sourceXmlDocument);
			this->deleteFromVerzeichnisXml(sourceXmlDocument);
			this->addToVerzeichnisXml(sourceXmlDocument, category);
			//geupgedateten Kunden NEU in das Dokument schreiben
			//wohin ??? Normalkunde ? Geschaeftskunde ?
			//
			return true;
		}

		System::String^ getCategory(System::Xml::XmlDocument^ sourceXmlDocument)
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
				return "";
			}
		}

		static System::Xml::XmlDocument^ getEmptyVerzeichnisXmlDocument(System::String^ path)
		{
			System::Xml::XmlDocument^ newXmlDocument = gcnew System::Xml::XmlDocument;
			System::Xml::XmlDeclaration^ xmlDeclaration = newXmlDocument->CreateXmlDeclaration("1.0", nullptr, "yes");
			newXmlDocument->AppendChild(xmlDeclaration);

			System::Xml::XmlNode^ kundenverzeichnisNode =
				newXmlDocument->CreateNode(System::Xml::XmlNodeType::Element, "Kundenverzeichnis", "");
			newXmlDocument->AppendChild(kundenverzeichnisNode);

			System::Xml::XmlNode^ normalkundenNode =
				newXmlDocument->CreateNode(System::Xml::XmlNodeType::Element, "Normalkunden", "");
			kundenverzeichnisNode->AppendChild(normalkundenNode);

			System::Xml::XmlNode^ geschaeftskundenNode =
				newXmlDocument->CreateNode(System::Xml::XmlNodeType::Element, "Geschaeftskunden", "");
			kundenverzeichnisNode->AppendChild(geschaeftskundenNode);

			newXmlDocument->Save(path);
			return newXmlDocument;
		}

		static int getHighestId(System::String^ path)
		{
			try
			{
				System::Xml::XmlDocument^ xmlDocumentToSearch = gcnew System::Xml::XmlDocument;
				xmlDocumentToSearch->Load(path);

				System::Xml::XmlNodeList^ ids = xmlDocumentToSearch->SelectNodes("//Kunde/@id");
				int id = 0;
				int oneIdInt;
				for each(System::Xml::XmlNode^ oneId in ids)
				{
					oneIdInt = int::Parse(oneId->InnerText);
					if (oneIdInt > id)
					{
						id = oneIdInt;
					}
				}

				logger->Trace(oneIdInt);
				return oneIdInt;
			}
			catch (System::Exception^ e)
			{
				logger->Fatal(e->Message);
			}
		}

		static Kunde^ getById(int id) {
			Kunde^ k = gcnew Kunde;
			k->id = id;
			k->load();
			return k;
		}

		private:
			static NLog::Logger^ logger = NLog::LogManager::GetCurrentClassLogger();
	};

}