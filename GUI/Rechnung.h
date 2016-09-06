#pragma once
#include "Kunde.h"
#include "DatabaseManager.h"
#include "IDatabaseable.h"

namespace GUI {

	public ref class Rechnung : public IDatabaseable
	{
	public:

		int id;
		System::String^ rechnungsnummer;
		Kunde^ kunde;
		System::DateTime^ datum;
		System::DateTime^ zahlungsziel;
		DatabaseManager^ databaseManager;

		Rechnung()
		{
			logger->Trace("ctor");
			kunde = gcnew Kunde;
			databaseManager = gcnew DatabaseManager;
			databaseManager->serverName = "localhost";
			databaseManager->databaseName = "Firma";
			databaseManager->userName = "sa";
			databaseManager->password = "sa";
		}

		virtual ~Rechnung()
		{
		}

		virtual bool load() {
			System::Data::SqlClient::SqlDataReader^ rechnungenDataReader;
			try {
				databaseManager->connect();
				System::Globalization::CultureInfo^ cultureInfoUS = gcnew System::Globalization::CultureInfo("en-US");
				//Select * FROM Rechnungen id=?
				System::String^ sqlSelectRechnungenCommand =
					"SELECT * FROM Rechnungen WHERE id=" + id;
				logger->Debug(sqlSelectRechnungenCommand);
				System::Data::SqlClient::SqlCommand^ selectRechnungenCommand =
					gcnew System::Data::SqlClient::SqlCommand(sqlSelectRechnungenCommand, databaseManager->getConnection());


				rechnungenDataReader = selectRechnungenCommand->ExecuteReader();
				rechnungenDataReader->Read();
				this->id = System::Convert::ToInt32(rechnungenDataReader["id"]);
				this->rechnungsnummer = (System::String^)rechnungenDataReader["rechnungsnummer"];
				this->datum = System::Convert::ToDateTime(rechnungenDataReader["datum"]);
				this->zahlungsziel = System::Convert::ToDateTime(rechnungenDataReader["zahlungsziel"]);
				this->kunde = gcnew Kunde;
				this->kunde->id = System::Convert::ToInt32(rechnungenDataReader["kundennummer"]);
				this->kunde->load();
				logger->Trace("Loaded Rechnung:" + this->ToString());
			}
			catch (System::Exception^ e) {
				logger->Fatal(e->Message);
				return false;
			}
			finally{
				rechnungenDataReader->Close();
				databaseManager->disconnect();
			}
			return true;
		}

		virtual bool update() {
			try {
				databaseManager->connect();
				System::Globalization::CultureInfo^ cultureInfoUS = gcnew System::Globalization::CultureInfo("en-US");
				//DELETE FROM Rechnungen WHERE id=?
				System::String^ sqlUpdateRechnungenCommand =
					"UPDATE Rechnungen SET rechnungsnummer='" + rechnungsnummer + "'," +
					"kundennummer=" + this->kunde->id + ", " +
					"datum='" + datum->ToString(cultureInfoUS) + "'" +
					"zahlungsziel='" + zahlungsziel->ToString(cultureInfoUS) + "'" +
					" WHERE id=" + id;
				logger->Debug(sqlUpdateRechnungenCommand);

				System::Data::SqlClient::SqlCommand^ updateRechnungCommand =
					gcnew System::Data::SqlClient::SqlCommand(sqlUpdateRechnungenCommand, databaseManager->getConnection());
				int betroffeneZeile = updateRechnungCommand->ExecuteNonQuery();
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

		virtual int deleteMe() {
			databaseManager->connect();

			//DELETE FROM Rechnungen WHERE id=?
			System::String^ sqlDeleteRechnungCommand =
				"DELETE FROM Rechnungen WHERE id=" + id.ToString();
			logger->Debug(sqlDeleteRechnungCommand);

			System::Data::SqlClient::SqlCommand^ deleteRechnungCommand =
				gcnew System::Data::SqlClient::SqlCommand(sqlDeleteRechnungCommand, databaseManager->getConnection());
			int betroffeneZeile = deleteRechnungCommand->ExecuteNonQuery();

			databaseManager->disconnect();
			return betroffeneZeile;
		}

		virtual int insert() {
			try {
				databaseManager->connect();

				System::Globalization::CultureInfo^ cultureInfoUS = gcnew System::Globalization::CultureInfo("de-DE");

				System::String^ sqlInsertIntoRechnungenCommand =
					"INSERT INTO Rechnungen (rechnungsnummer,kundennummer,zahlungsziel,datum) VALUES('"
					+ rechnungsnummer + "',"
					+ this->kunde->id + ",'"
					+ zahlungsziel->ToString(cultureInfoUS) + "','"
					+ datum->ToString(cultureInfoUS) + "');";
				logger->Trace(sqlInsertIntoRechnungenCommand);

				System::Data::SqlClient::SqlCommand^ insertIntoRechnungenCommand =
					gcnew System::Data::SqlClient::SqlCommand(sqlInsertIntoRechnungenCommand, databaseManager->getConnection());
				int betroffeneZeile = insertIntoRechnungenCommand->ExecuteNonQuery();
				int lastInsertedProduktId = databaseManager->getLastInsertedIdSQLServer("Rechnungen");
				databaseManager->disconnect();
				return lastInsertedProduktId;

			}
			catch (System::Exception^ e) {
				logger->Fatal(e->Message);
				return 0;
			}
		}

		System::Collections::ArrayList^ getIds() {
			databaseManager->connect();
			System::String^ sqlRechnungsidsCommand =
				"SELECT id FROM Rechnungen";
			logger->Debug(sqlRechnungsidsCommand);

			//Container for return
			System::Collections::ArrayList^ ids = gcnew System::Collections::ArrayList;

			System::Data::SqlClient::SqlCommand^ selectRechnungIdsCommand =
				gcnew System::Data::SqlClient::SqlCommand(sqlRechnungsidsCommand, databaseManager->getConnection());

			System::Data::SqlClient::SqlDataReader^ idsDataReader = selectRechnungIdsCommand->ExecuteReader();
			while (idsDataReader->Read())
			{
				ids->Add((int)idsDataReader["id"]);
				logger->Trace("Added id:" + (int)idsDataReader["id"]);
			}
			databaseManager->disconnect();
			return ids;
		}

		//System::Collections::ArrayList^ getRechnungspositionen() {
		//	Rechnungsposition^ rp = gcnew Rechnungsposition;
		//	rp->id = this->id;
		//	return rp->getRechnungspositionen();
		//}

		//double getRechnungspositionenSumme() {
		//	Rechnungsposition^ rp = gcnew Rechnungsposition;
		//	rp->id = this->id;
		//	return rp->getRechnungspositionenSumme();
		//}


		System::String^ ToString() override {
			return id.ToString() + "," + rechnungsnummer + "," + kunde->id + "," + datum->ToString() + "," + zahlungsziel->ToString();
		}

	private:
		static NLog::Logger^ logger = NLog::LogManager::GetCurrentClassLogger();
	};
}
