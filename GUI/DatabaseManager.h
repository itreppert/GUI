#pragma once
public ref class DatabaseManager
{
public:
	System::String^ serverName = "localhost";
	System::String^ databaseName = "Firma";
	System::String^ userName = "sa";
	System::String^ password = "sa";

	bool heartBeatOk = false;
	System::Windows::Forms::Timer^ heartbeatTimer;


	void connect() {
		//"Database=Firma;Server=localhost;Trusted_Connection=False;User ID=sa;Password=sa"
		System::String^ connectionString = "Database=" + databaseName +
			";Server=" + serverName
			+ ";Trusted_Connection=False;User ID=" + userName + ";Password=" + password;
		logger->Trace(connectionString);
		connection =
			gcnew System::Data::SqlClient::SqlConnection(connectionString);
		try {
			connection->Open();
		}
		catch (System::Exception^ e) {
			logger->Fatal(e->Message);
		}
	}

	int getLastInsertedIdSQLServer(System::String^ tableName)
	{
		System::String^ identitySQL = "SELECT IDENT_CURRENT('" + tableName + "')";
		System::Data::SqlClient::SqlCommand^ selectCommand =
			gcnew System::Data::SqlClient::SqlCommand(identitySQL, connection);

		System::Data::SqlClient::SqlDataReader^ reader = selectCommand->ExecuteReader();
		reader->Read();
		int lastInsertedId = int::Parse(reader[0]->ToString());
		
		return lastInsertedId;
	}

	void startHeartbeatTimer() {
		heartbeatTimer = gcnew System::Windows::Forms::Timer();
		heartbeatTimer->Tick += gcnew System::EventHandler(this, &DatabaseManager::heartBeatTimerTick);
		heartbeatTimer->Interval = 500;
		heartbeatTimer->Enabled = true;
	}

	void heartBeatTimerTick(System::Object^ sender, System::EventArgs^  e) {
		sendHeartbeat();
	}

	void disconnect() {
		logger->Trace("disconnecting : " + connection->ConnectionString);
		connection->Close();
	}

	bool sendHeartbeat() {
		System::String^ heartbeatSQL = "SELECT 0";
		connect();
		System::Data::SqlClient::SqlCommand^ heartbeatCommand =
			gcnew System::Data::SqlClient::SqlCommand(heartbeatSQL, connection);
		try {
			heartbeatCommand->ExecuteReader();
			logger->Trace("Heartbeat ok");
			heartBeatOk = true;
		}
		catch (System::Exception^ e) {
			logger->Fatal(e->Message);
			logger->Trace("Heartbeat failed");
			heartBeatOk = false;
			return false;
		}
		finally{
			disconnect();
		}
		return true;
	}

	DatabaseManager()
	{
	}

	virtual ~DatabaseManager()
	{
	}

	System::Data::SqlClient::SqlConnection^ getConnection() {
		return connection;
	}

private:
	System::Data::SqlClient::SqlConnection^ connection;
	static NLog::Logger^ logger = NLog::LogManager::GetCurrentClassLogger();
};

