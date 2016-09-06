#pragma once
public ref class Tools
{
public:

	Tools()
	{
	}

	array<System::Windows::Forms::TreeNode^>^  getDriveInfoSystem::Windows::Forms::TreeNodes()
	{
		logger->Debug("getDriveInfoSystem::Windows::Forms::TreeNodes");
		int driveCount = System::IO::DriveInfo::GetDrives()->GetLength(1);
		logger->Debug("System::IO::DriveInfo::GetDrives()->Length = " + System::IO::DriveInfo::GetDrives()->GetLength(1));
		array<System::Windows::Forms::TreeNode^>^ tmpArray = gcnew array<System::Windows::Forms::TreeNode^>(driveCount);
		for (int counter = 0; counter < driveCount; counter++)
		{
			try
			{
				logger->Debug("counter=" + counter);
				String^ driveName = System::IO::DriveInfo::GetDrives()[counter]->Name;
				logger->Debug("driveName=" + driveName);
				System::Windows::Forms::TreeNode^ driveInfoSystem::Windows::Forms::TreeNode = gcnew System::Windows::Forms::TreeNode(driveName);
				tmpArray[counter] = driveInfoSystem::Windows::Forms::TreeNode;
			}
			catch (Exception^ e)
			{
				logger->Fatal(e->Message);
			}
		}		return tmpArray;	}

	virtual ~Tools()
	{
	}

private:static NLog::Logger^ logger = NLog::LogManager::GetCurrentClassLogger();
};

