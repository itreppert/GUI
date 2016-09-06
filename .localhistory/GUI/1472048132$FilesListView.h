#pragma once
ref class FilesListView : public System::Windows::Forms::ListView
{
public:

	FilesListView()
	{
		this->ListView::ListView();
	}

	FilesListView(System::String^ startPath)
	{
		this->startPath = startPath;
		this->ListView::ListView();
	}

	void buildFilesLIstViewItems()
	{
		this->Items->Clear();

		for each(System::String^ subPath in System::IO::Directory::GetFiles(startPath))
		{
			System::IO::FileInfo^ fi = gcnew System::IO::FileInfo(subPath);

			System::Windows::Forms::ListViewItem^  fileListViewItem = gcnew System::Windows::Forms::ListViewItem(
				gcnew array< System::String^  >(2)
			{
				subPath, fi->Length.ToString()
			}, -2);
			this->Items->Add(fileListViewItem);
		}
	}

	System::String^ startPath;
};

