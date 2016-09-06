#pragma once
ref class Tools
{
public:

	Tools()
	{
	}

	array<TreeNode^>^  getDriveInfoTreeNodes()
	{
		logger->Debug("getDriveInfoTreeNodes");
		int driveCount = System::IO::DriveInfo::GetDrives()->GetLength(1);
		logger->Debug("System::IO::DriveInfo::GetDrives()->Length = " + System::IO::DriveInfo::GetDrives()->GetLength(1));
		array<TreeNode^>^ tmpArray = gcnew array<TreeNode^>(driveCount);
		for (int counter = 0; counter < driveCount; counter++)
		{
			try
			{
				logger->Debug("counter=" + counter);
				String^ driveName = System::IO::DriveInfo::GetDrives()[counter]->Name;
				logger->Debug("driveName=" + driveName);
				TreeNode^ driveInfoTreeNode = gcnew TreeNode(driveName);
				tmpArray[counter] = driveInfoTreeNode;
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

