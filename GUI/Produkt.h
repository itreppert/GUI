#pragma once
#include "IDatabaseable.h"
#include "DatabaseManager.h"
namespace GUI {
	public ref class Produkt : public IDatabaseable
	{
	public:

		Produkt()
		{
			databaseManager = gcnew DatabaseManager;
		}

		virtual ~Produkt()
		{
		}

		static NLog::Logger^ logger = NLog::LogManager::GetCurrentClassLogger();
		int id;
		System::String^ name;
		System::String^ beschreibung;
		double ekpreis;
		double vkpreis;
		int lagerbestand;

		DatabaseManager^ databaseManager;

		System::Collections::ArrayList^ getIdArrayList() {
			databaseManager->connect();

			System::String^ sqlSelectProduktIdsCommand =
				"SELECT id FROM Produkte";

			System::Data::SqlClient::SqlCommand^ selectProduktCommand =
				gcnew System::Data::SqlClient::SqlCommand(sqlSelectProduktIdsCommand, databaseManager->getConnection());

			System::Data::SqlClient::SqlDataReader^ produktDataReader = selectProduktCommand->ExecuteReader();
			System::Collections::ArrayList^ idArrayList = gcnew System::Collections::ArrayList;

			while (produktDataReader->Read())
			{
				idArrayList->Add((int)produktDataReader["id"]);
			}
			produktDataReader->Close();
			databaseManager->disconnect();
			return idArrayList;
		}

		System::Windows::Forms::ListViewItem^ getAsListViewItem() {
			System::Windows::Forms::ListViewItem^  produktListViewItem = gcnew System::Windows::Forms::ListViewItem(
				gcnew array< System::String^  >(6)
			{
				id.ToString(), name, beschreibung,
					ekpreis.ToString(), vkpreis.ToString(), lagerbestand.ToString()
			}, -1);

			return produktListViewItem;
		}

		//array<System::String^> getAsDataGridViewRow() {
		//	System::Windows::Forms::DataGridViewRow^ dgvr = gcnew System::Windows::Forms::DataGridViewRow();
		//	System::Windows::Forms::DataGridViewCell^ dgvc = gcnew System::Windows::Forms::DataGridViewCell;
		//	dgvr->Cells->Add(gcnew System::Windows::Forms::DataGridViewCell( this->beschreibung);
		//	return 
		//}

		virtual bool update() {
			try {
				databaseManager->connect();
				System::Globalization::CultureInfo^ cultureInfoUS = gcnew System::Globalization::CultureInfo("en-US");
				//DELETE FROM Produkt WHERE id=?
				System::String^ sqlUpdateProduktCommand =
					"UPDATE Produkte SET name='" + name + "'," +
					"beschreibung='" + beschreibung + "', " +
					"ekpreis=" + ekpreis.ToString(cultureInfoUS) + ", " +
					"vkpreis=" + vkpreis.ToString(cultureInfoUS) + ", " +
					"lagerbestand=" + lagerbestand.ToString() +
					" WHERE id=" + id;

				System::Data::SqlClient::SqlCommand^ updateProduktCommand =
					gcnew System::Data::SqlClient::SqlCommand(sqlUpdateProduktCommand, databaseManager->getConnection());
				int betroffeneZeile = updateProduktCommand->ExecuteNonQuery();
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
			System::Data::SqlClient::SqlDataReader^ produktDataReader;
			try {
				databaseManager->connect();
				System::Globalization::CultureInfo^ cultureInfoUS = gcnew System::Globalization::CultureInfo("en-US");
				//Select * FROM Produkt id=?
				System::String^ sqlSelectProduktCommand =
					"SELECT * FROM Produkte WHERE id=" + id;

				System::Data::SqlClient::SqlCommand^ selectProduktCommand =
					gcnew System::Data::SqlClient::SqlCommand(sqlSelectProduktCommand, databaseManager->getConnection());


				produktDataReader = selectProduktCommand->ExecuteReader();
				produktDataReader->Read();

				this->name = (System::String^)produktDataReader["name"];
				this->beschreibung = (System::String^)produktDataReader["beschreibung"];
				this->ekpreis = double::Parse(((System::Decimal)produktDataReader["ekpreis"]).ToString(cultureInfoUS));
				this->vkpreis = double::Parse(((System::Decimal)produktDataReader["vkpreis"]).ToString(cultureInfoUS));
				this->lagerbestand = (int)produktDataReader["lagerbestand"];
			}
			catch (System::Exception^ e) {
				logger->Fatal(e->Message);
				return false;
			}
			finally{
				produktDataReader->Close();
				databaseManager->disconnect();
			}
			return true;
		}


		virtual int deleteMe() {
			databaseManager->connect();

			//DELETE FROM Produkt WHERE id=?
			System::String^ sqlDeleteProduktCommand =
				"DELETE FROM Produkte WHERE id=" + id.ToString();

			System::Data::SqlClient::SqlCommand^ deleteProduktCommand =
				gcnew System::Data::SqlClient::SqlCommand(sqlDeleteProduktCommand, databaseManager->getConnection());
			int betroffeneZeile = deleteProduktCommand->ExecuteNonQuery();

			databaseManager->disconnect();
			return betroffeneZeile;
		}

		virtual int insert() {
			try {
				databaseManager->connect();

				System::Globalization::CultureInfo^ cultureInfoDE = gcnew System::Globalization::CultureInfo("de-DE");

				//INSERT INTO Produkt (vorname,nachname,strasse,plz,ort,benutzername,umsatz) VALUES('Holger','Reppert','Blastreet','66111','Saarbridges','Blondie',20000);
				System::String^ sqlInsertIntoProduktCommand =
					"INSERT INTO Produkte (name, beschreibung, ekpreis, vkpreis, lagerbestand) VALUES('"
					+ name + "','"
					+ beschreibung + "',"
					+ ekpreis.ToString(cultureInfoDE) + ","
					+ vkpreis.ToString(cultureInfoDE) + ","
					+ lagerbestand + ")";
				logger->Trace(sqlInsertIntoProduktCommand);

				System::Data::SqlClient::SqlCommand^ insertIntoProduktCommand =
					gcnew System::Data::SqlClient::SqlCommand(sqlInsertIntoProduktCommand, databaseManager->getConnection());
				int betroffeneZeile = insertIntoProduktCommand->ExecuteNonQuery();
				int insertedProduktid = databaseManager->getLastInsertedIdSQLServer("Produkte");

				databaseManager->disconnect();

				return insertedProduktid;
			}
			catch (System::Exception^ e) {
				logger->Fatal(e->Message);
				return 0;
			}
		}

		System::String^ ToString() override
		{
			System::Globalization::CultureInfo^ cultureInfoDE = gcnew System::Globalization::CultureInfo("de-DE");
			System::String^ result = id.ToString() + "," + name + "," + beschreibung + "," + ekpreis.ToString(cultureInfoDE) + "," + ekpreis.ToString(cultureInfoDE) + "," + lagerbestand;
			return result;
		}

		static Produkt^ getProduktById(int id) {
			Produkt^ k = gcnew Produkt;
			k->id = id;
			k->load();
			return k;
		}
	};
}