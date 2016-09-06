#pragma once
#include "IDatabaseable.h"
#include "DatabaseManager.h"
#include "Rechnung.h"
#include "Produkt.h"
namespace GUI {
	public ref class Rechnungsposition : public IDatabaseable
	{
	public:

		int id;
		int position;
		Rechnung^ rechnung;
		System::DateTime^ datum;
		Produkt^ produkt;
		int menge;
		DatabaseManager^ databaseManager;


		Rechnungsposition()
		{
			rechnung = gcnew Rechnung;
			produkt = gcnew Produkt;
			databaseManager = gcnew DatabaseManager;
			databaseManager->serverName = "localhost";
			databaseManager->databaseName = "Firma";
			databaseManager->userName = "sa";
			databaseManager->password = "sa";
		}

		virtual ~Rechnungsposition()
		{
		}

		virtual bool load() {
			System::Data::SqlClient::SqlDataReader^ rechnungspositionenDataReader;
			try {
				databaseManager->connect();
				System::Globalization::CultureInfo^ cultureInfoUS = gcnew System::Globalization::CultureInfo("en-US");
				//Select * FROM Rechnungspositionen id=?
				System::String^ sqlSelectRechnungspositionenCommand =
					"SELECT * FROM Rechnungspositionen WHERE id=" + id;

				System::Data::SqlClient::SqlCommand^ selectRechnungspositionenCommand =
					gcnew System::Data::SqlClient::SqlCommand(sqlSelectRechnungspositionenCommand, databaseManager->getConnection());


				rechnungspositionenDataReader = selectRechnungspositionenCommand->ExecuteReader();
				rechnungspositionenDataReader->Read();
				this->id = System::Convert::ToInt32(rechnungspositionenDataReader["id"]);
				this->position = System::Convert::ToInt32(rechnungspositionenDataReader["position"]);
				this->datum = System::Convert::ToDateTime(rechnungspositionenDataReader["datum"]);

				this->rechnung = gcnew Rechnung;
				this->rechnung->id = System::Convert::ToInt32(rechnungspositionenDataReader["rechnungsid"]);
				this->rechnung->load();

				this->produkt = gcnew Produkt;
				this->produkt->id = System::Convert::ToInt32(rechnungspositionenDataReader["produktnummer"]);
				this->produkt->load();

				this->menge = System::Convert::ToInt32(rechnungspositionenDataReader["menge"]);
			}
			catch (System::Exception^ e) {
				logger->Fatal(e->Message);
				return false;
			}
			finally{
				rechnungspositionenDataReader->Close();
				databaseManager->disconnect();
			}
			return true;
		}

		virtual bool update() {
			try {
				databaseManager->connect();
				System::Globalization::CultureInfo^ cultureInfoUS = gcnew System::Globalization::CultureInfo("en-US");
				//DELETE FROM Rechnungspositionen WHERE id=?
				System::String^ sqlUpdateRechnungspositionenCommand =
					"UPDATE Rechnungspositionen SET " +
					"position=" + position + "," +
					"rechnungsid=" + this->rechnung->id + ", " +
					"datum='" + datum->ToString(cultureInfoUS) + "'" +
					"produktnummer=" + this->produkt->id + ", " +
					"menge='" + menge + "'" +
					" WHERE id=" + id;
				logger->Debug(sqlUpdateRechnungspositionenCommand);

				System::Data::SqlClient::SqlCommand^ updateKundeCommand =
					gcnew System::Data::SqlClient::SqlCommand(sqlUpdateRechnungspositionenCommand, databaseManager->getConnection());
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

		virtual int deleteMe() {
			databaseManager->connect();

			//DELETE FROM Rechnungspositionen WHERE id=?
			System::String^ sqlDeleteRechnungCommand =
				"DELETE FROM Rechnungspositionen WHERE id=" + id.ToString();

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

				System::String^ sqlInsertIntoRechnungspositionenCommand =
					"INSERT INTO Rechnungspositionen (position ,rechnungsid,produktnummer,menge,datum) VALUES("
					+ position + ","
					+ rechnung->id + ","
					+ produkt->id + ","
					+ menge + ",'"
					+ datum->ToString(cultureInfoUS) + "');";
				logger->Trace(sqlInsertIntoRechnungspositionenCommand);

				System::Data::SqlClient::SqlCommand^ insertIntoRechnungspositionenCommand =
					gcnew System::Data::SqlClient::SqlCommand(sqlInsertIntoRechnungspositionenCommand, databaseManager->getConnection());
				int betroffeneZeile = insertIntoRechnungspositionenCommand->ExecuteNonQuery();
				int lastInsertedRechnungspositionId = databaseManager->getLastInsertedIdSQLServer("Rechnungspositionen");
				databaseManager->disconnect();
				return lastInsertedRechnungspositionId;
			}
			catch (System::Exception^ e) {
				logger->Fatal(e->Message);
				return 0;
			}
		}

		System::Collections::ArrayList^ getIdsByRechnungsid(int rechnungsId) {
			databaseManager->connect();
			System::String^ sqlSelectRechnungsIdsCommand =
				"SELECT id FROM Rechnungspositionen WHERE rechnungsid=" + rechnungsId;
			logger->Debug(sqlSelectRechnungsIdsCommand);

			System::Collections::ArrayList^ ids = gcnew System::Collections::ArrayList;

			System::Data::SqlClient::SqlCommand^ selectRechnungspositionenIdsCommand =
				gcnew System::Data::SqlClient::SqlCommand(sqlSelectRechnungsIdsCommand, databaseManager->getConnection());


			System::Data::SqlClient::SqlDataReader^ idsDataReader = selectRechnungspositionenIdsCommand->ExecuteReader();
			while (idsDataReader->Read())
			{
				ids->Add((int)idsDataReader["id"]);
				logger->Trace("Added id:" + (int)idsDataReader["id"]);
			}
			databaseManager->disconnect();
			return ids;
		}

		System::Collections::ArrayList^ getRechnungspositionen() {
			System::Collections::ArrayList^ rechnungspositionen = gcnew System::Collections::ArrayList;
			for each(int rPId in getIdsByRechnungsid(this->id)) {
				Rechnungsposition^ eineRechnungsposition = gcnew Rechnungsposition;
				eineRechnungsposition->id = rPId;
				eineRechnungsposition->load();
				rechnungspositionen->Add(eineRechnungsposition);
			}
			return rechnungspositionen;
		}

		double getRechnungspositionenSumme() {
			double sum = 0;
			for each(Rechnungsposition^ rp in getRechnungspositionen()) {
				sum += rp->produkt->vkpreis * rp->menge;
			}
			return sum;
		}

		System::String^ ToString() override {
			return id.ToString() + "," + position + "," + rechnung->id + "," + produkt->id + "," + menge + "," + datum->ToString();
		}

	private:
		static NLog::Logger^ logger = NLog::LogManager::GetCurrentClassLogger();

	};
}