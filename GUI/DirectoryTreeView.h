#pragma once
ref class DirectoryTreeView :public System::Windows::Forms::TreeView
{
public:

	DirectoryTreeView()
	{
		this->TreeView::TreeView();
	}

	DirectoryTreeView(System::String^ startPath)
	{
		this->startPath = startPath;
		this->TreeView::TreeView();
	}

	void buildNodes()
	{
		this->Nodes->Clear();
		System::Windows::Forms::TreeNode^ rootNode = gcnew System::Windows::Forms::TreeNode(startPath);
		this->Nodes->Add(rootNode);
		createDirectoryNodesRecursive(startPath, rootNode, 0);
		this->ExpandAll();
	}

	void createDirectoryNodesRecursive(System::String^ path, System::Windows::Forms::TreeNode^ parentNode, int level)
	{
		level++;
		//System::Diagnostics::Debug::WriteLine(level + " : " + startPath);
		System::Windows::Forms::TreeNode^ aNode = gcnew System::Windows::Forms::TreeNode(path);
		parentNode->Nodes->Add(aNode);
		//TODO Double root node problem
		array<System::String^>^ paths = gcnew array<System::String^>(1000);

		try
		{
			paths = System::IO::Directory::GetDirectories(path);
			for each(System::String^ path in paths)
			{
				createDirectoryNodesRecursive(path, aNode, level);
			}
		}
		catch (System::Exception^ e)
		{
			logger->Error(e->Message);
			logger->Error(startPath);
		}
	}

	System::String^ startPath;
	static NLog::Logger^ logger = NLog::LogManager::GetCurrentClassLogger();
};

