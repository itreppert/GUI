#pragma once

#include "Test.h"
#include "TeilenDurch0Exception.h"
#include "BlinkinButton.h"
#include "DrawingPanel.h"
#include "RegexTextBox.h"
#include "DirectoryTreeView.h"
#include "FilesListView.h"
#include "Kunde.h"
#include "Produkt.h"
#include "DatabaseManager.h"
#include "Rechnung.h"
#include "Rechnungsposition.h"
#include "RechnungsManagementWindow.h"
#include "CounterSlave.h"
namespace GUI
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace NLog;

	/// <summary>
	/// Zusammenfassung für MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:

		MainForm(void)
		{
			logger->Info("ctor");
			InitializeComponent();
			initialiseComponents();

			tabControl1->SelectTab(tabControl1->TabCount - 1);

			step = 0;
			richTextBox1->LoadFile("d:\\Dokument.rtf");
			points = gcnew ArrayList;
			points->Add(lastPoint);
			databaseManager = gcnew DatabaseManager;
			databaseManager->startHeartbeatTimer();
			checkHeartbeatDatabaseStatus->Enabled = true;

			Rechnung^ fakeRechnung = gcnew Rechnung;

			for each(int id in fakeRechnung->getIds()) {
				cmbRechnungsids->Items->Add(id);
			}

		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

		DatabaseManager^ databaseManager;
		//Logger !!
	private: static Logger^ logger = LogManager::GetCurrentClassLogger();
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  cmdChangeFormColor;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Button^  btnChangeTab;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Button^  btnCheckbox;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  btnRadioButton;
	private: System::Windows::Forms::ComboBox^  cmbBlubb;

	private: System::Windows::Forms::Button^  btnComboboxValue;
	private: System::Windows::Forms::Button^  btnComboAddItem;
	private: System::Windows::Forms::Button^  btnComboremoveItem;
	private: System::Windows::Forms::Button^  btnComboInsert;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::TextBox^  txtAnswers;
	private: System::Windows::Forms::TextBox^  txtQuestions;
			 Test^ t;
			 int progress;
			 String^ antwort1;
			 String^ antwort2;
			 String^ antwort3;
			 String^ antwort4;

	private: System::Windows::Forms::Button^  btnNextStep;

			 int step;
	private: System::Windows::Forms::Button^  btnChangeFromAnotherClass;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  btnStartProgress;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuSaveFileDialog;

	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuFarben;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuSchriftart;
	private: System::Windows::Forms::FontDialog^  fontDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuRichtextBox;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuFolderBrowser;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuClearText;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuOpen;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuSave;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuButtonsHerstellen;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuListControls;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuTextBoxenHerstellen;
	private: System::Windows::Forms::Button^  btnAddDoubles;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txtZweiteZahl;

	private: System::Windows::Forms::TextBox^  txtErsteZahl;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Button^  btnArrayList;
	private: System::Windows::Forms::TextBox^  txtCollections;
	private: System::Windows::Forms::Button^  btnQueue;
	private: System::Windows::Forms::Button^  btnStack;
	private: System::Windows::Forms::Button^  btnSortedList;
	private: System::Windows::Forms::Button^  btnHashtable;
	private: System::Windows::Forms::Button^  btnList;
	private: System::Windows::Forms::Button^  btnArray;
	private: System::Windows::Forms::Button^  btnBenchmark;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Panel^  pnlDrawing;
	private: System::Windows::Forms::Panel^  pnlGraphics;


	private: System::Windows::Forms::Button^  btnDrawLine;
	private: System::Windows::Forms::Button^  btnTranslatePoints;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  btnDrawImage;
	private: System::Windows::Forms::Button^  btnDrawHouse;
	private: System::Windows::Forms::Button^  btnDivide;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Panel^  panel5;
	private: BlinkinButton^  btnBlinkinButton;
	private: System::Windows::Forms::Panel^  panel6;
	private: DrawingPanel^  pnlHouse;
	private: System::Windows::Forms::TabPage^  tabPage6;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::TextBox^  txtTreeView;

	private: System::Windows::Forms::TreeView^  treeView1;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Button^  btnAddTreeNodeToTreeView;
	private: System::Windows::Forms::Button^  btnRemoveTreeNOde;
	private: System::Windows::Forms::Button^  btnReadDirectories;
	private: System::Windows::Forms::Button^  btnRecursion;
	private: System::Windows::Forms::Button^  btnRegex;
	private: System::Windows::Forms::TextBox^  txtRegex;
	private: System::Windows::Forms::TextBox^  txtRegexExpr;
	private: RegexTextBox^  txtAutoRegexMatcher;
	private: System::Windows::Forms::Button^  btnChangeRegexInRegexTextBox;
	private: System::Windows::Forms::Button^  btnWalkTreeViewRecursive;
	private: System::Windows::Forms::Button^  btnDriveInfo;
	private: System::Windows::Forms::TabPage^  tabPage7;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::TreeView^  trvDirectories;
	private: System::Windows::Forms::ListView^  lsvFiles;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuRefreshTreeView;
	private: System::Windows::Forms::TabPage^  tabPage8;
	private: System::Windows::Forms::Panel^  panel9;
	private: System::Windows::Forms::ListView^  lsvTest;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuFillListView;
	private: System::Windows::Forms::TabPage^  tabPage9;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
	private: DirectoryTreeView^  trvDirectory;
	private: FilesListView^  lsvFile;
	private: System::Windows::Forms::TabPage^  tabPage10;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel8;
	private: System::Windows::Forms::Panel^  panel10;
	private: System::Windows::Forms::TextBox^  txtWeb;
	private: System::Windows::Forms::Panel^  panel11;
	private: System::Windows::Forms::Panel^  panel12;
	private: System::Windows::Forms::TextBox^  txtURL;

	private: System::Windows::Forms::Button^  btnWebRequest;

	private: System::Windows::Forms::WebBrowser^  webBrowser1;
	private: System::Windows::Forms::Button^  btnFTPWebrequestDirectory;
	private: System::Windows::Forms::Button^  btnFTPDownload;
	private: System::Windows::Forms::Button^  btnFTPDownloadBinary;
	private: System::Windows::Forms::Button^  btnSendMail;
	private: System::Windows::Forms::TabPage^  tabPage11;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel9;
	private: System::Windows::Forms::Panel^  panel13;
	private: System::Windows::Forms::TextBox^  txtXMLOutput;

	private: System::Windows::Forms::Panel^  panel14;
	private: System::Windows::Forms::Panel^  panel15;
	private: System::Windows::Forms::Button^  btnCreateXMLDocument;
	private: System::Windows::Forms::Button^  btnLoadXMLDoc;
	private: System::Windows::Forms::Button^  btnCreateKundeNode;
	private: System::Windows::Forms::Button^  btnCreateClassKundeXmlNode;
	private: System::Windows::Forms::Button^  btnReadKundeFromKundenVverzeichnisXml;
	private: System::Windows::Forms::Button^  btnDeleteKundeFromVerzeichnis;
	private: System::Windows::Forms::Button^  btnUpdateKunde;
	private: System::Windows::Forms::Button^  btnCreateKundenverzeichnisXmlDocument;
	private: System::Windows::Forms::Button^  btnWriteToRegistry;
	private: System::Windows::Forms::Button^  btnLoadFromRegistry;
	private: System::Windows::Forms::Button^  btnGetHighestKundeId;
	private: System::Windows::Forms::Button^  btnDoDllMethod;
	private: System::Windows::Forms::TabPage^  tabPage12;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel10;
	private: System::Windows::Forms::Panel^  panel16;
	private: System::Windows::Forms::TextBox^  txtSQLOutput;
	private: System::Windows::Forms::Panel^  panel17;
	private: System::Windows::Forms::Panel^  panel18;
	private: System::Windows::Forms::Button^  btnConnectDatabase;
	private: System::Windows::Forms::Button^  btnDelete;
	private: System::Windows::Forms::Button^  btnInsertKunde;
	private: System::Windows::Forms::Button^  btnUpdateKundeDB;
	private: System::Windows::Forms::Button^  btnSelectKunden;
	private: System::Windows::Forms::TextBox^  txtKundeUmsatz;
	private: System::Windows::Forms::TextBox^  txtKundeBenutzername;
	private: System::Windows::Forms::TextBox^  txtKundeOrt;
	private: System::Windows::Forms::TextBox^  txtKundePlz;
	private: System::Windows::Forms::TextBox^  txtKundeStrasse;
	private: System::Windows::Forms::TextBox^  txtKundeNachname;
	private: System::Windows::Forms::TextBox^  txtKundeVorname;
	private: System::Windows::Forms::Button^  btnInsertKundeEntity;
	private: System::Windows::Forms::Button^  btnDeleteKundeEntity;
	private: System::Windows::Forms::TextBox^  txtDeleteKundeId;
	private: System::Windows::Forms::TextBox^  txtSelectKundeId;
	private: System::Windows::Forms::Button^  btnSelectKundeEntity;
	private: System::Windows::Forms::Button^  btnUpdateKundeEntity;
	private: System::Windows::Forms::ListView^  lsvKunden;

	private: System::Windows::Forms::Button^  btnFillKundenListView;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	private: System::Windows::Forms::ColumnHeader^  columnHeader5;
	private: System::Windows::Forms::ColumnHeader^  columnHeader6;
	private: System::Windows::Forms::ColumnHeader^  columnHeader7;
	private: System::Windows::Forms::ColumnHeader^  columnHeader8;
	private: System::Windows::Forms::ColumnHeader^  columnHeader9;
	private: System::Windows::Forms::ColumnHeader^  columnHeader10;
	private: System::Windows::Forms::Button^  btnFillProduktListView;
	private: System::Windows::Forms::ListView^  lsvProdukte;

	private: System::Windows::Forms::ColumnHeader^  columnHeader11;
	private: System::Windows::Forms::ColumnHeader^  columnHeader12;
	private: System::Windows::Forms::ColumnHeader^  columnHeader13;
	private: System::Windows::Forms::ColumnHeader^  columnHeader14;
	private: System::Windows::Forms::ColumnHeader^  columnHeader15;
	private: System::Windows::Forms::ColumnHeader^  columnHeader16;
	private: System::Windows::Forms::ToolStripTextBox^  txtDatabaseConnectionStatus;
	private: System::Windows::Forms::Timer^  checkHeartbeatDatabaseStatus;
	private: System::Windows::Forms::TabPage^  tabPage13;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel11;
	private: System::Windows::Forms::Panel^  panel19;
	private: System::Windows::Forms::TextBox^  txtCulture;
	private: System::Windows::Forms::Panel^  panel20;
	private: System::Windows::Forms::WebBrowser^  webBrowser2;
	private: System::Windows::Forms::Panel^  panel21;
	private: System::Windows::Forms::Button^  btnListCultures;
	private: System::Windows::Forms::Button^  btnDateTimeCulture;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
	private: System::Windows::Forms::Button^  btnReflect;
	private: System::Windows::Forms::TabPage^  tabPage14;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel12;
	private: System::Windows::Forms::Panel^  panel22;
	private: System::Windows::Forms::TextBox^  txtSQLite;

	private: System::Windows::Forms::Panel^  panel23;
	private: System::Windows::Forms::WebBrowser^  webBrowser3;
	private: System::Windows::Forms::Panel^  panel24;
	private: System::Windows::Forms::Button^  btnSqliteCreate;
	private: System::Windows::Forms::Button^  btnCreateSqliteTable;
	private: System::Windows::Forms::Button^  btnInsertSQLiteKunde;
	private: System::Windows::Forms::Button^  btnReadSQLiteKunden;
	private: System::Windows::Forms::Button^  btnGetLastInsertedId;
	private: System::Windows::Forms::Button^  btnGetLastInsertedSQLiteId;
	private: System::Windows::Forms::Button^  btnCreateRechnung;
	private: System::Windows::Forms::Button^  btnCreateRechnungspositionen;
	private: System::Windows::Forms::Button^  btnShowRechnung;
	private: System::Windows::Forms::ComboBox^  cmbRechnungsids;
	private: System::Windows::Forms::ToolStripMenuItem^  eRPToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  btnOpenRechnungsFenster;
	private: System::Windows::Forms::TabPage^  tabPage15;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel13;
	private: System::Windows::Forms::Panel^  panel25;
	private: System::Windows::Forms::TextBox^  txtThreading;
	private: System::Windows::Forms::Panel^  panel26;
	private: System::Windows::Forms::WebBrowser^  webBrowser4;
	private: System::Windows::Forms::Panel^  panel27;
	private: System::Windows::Forms::Button^  btnThreadStart;
	private: System::Windows::Forms::Button^  btnStartWorker;
	private: System::Windows::Forms::Button^  btnPlayWav;
	private: System::Windows::Forms::Button^  btnScreenshot;
	private: System::Windows::Forms::Button^  btnProcesses;
	private: System::Windows::Forms::Button^  btnKillProcess;
	private: System::Windows::Forms::NumericUpDown^  numProcessId;
	private: System::Windows::Forms::Button^  btnStartProcessByName;
	private: System::Windows::Forms::TextBox^  txtProcessName;



	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			System::Windows::Forms::TreeNode^  treeNode1 = (gcnew System::Windows::Forms::TreeNode(L"Knoten7"));
			System::Windows::Forms::TreeNode^  treeNode2 = (gcnew System::Windows::Forms::TreeNode(L"Knoten8"));
			System::Windows::Forms::TreeNode^  treeNode3 = (gcnew System::Windows::Forms::TreeNode(L"Knoten9"));
			System::Windows::Forms::TreeNode^  treeNode4 = (gcnew System::Windows::Forms::TreeNode(L"Knoten15"));
			System::Windows::Forms::TreeNode^  treeNode5 = (gcnew System::Windows::Forms::TreeNode(L"Knoten16"));
			System::Windows::Forms::TreeNode^  treeNode6 = (gcnew System::Windows::Forms::TreeNode(L"Knoten21"));
			System::Windows::Forms::TreeNode^  treeNode7 = (gcnew System::Windows::Forms::TreeNode(L"Knoten22"));
			System::Windows::Forms::TreeNode^  treeNode8 = (gcnew System::Windows::Forms::TreeNode(L"Knoten26"));
			System::Windows::Forms::TreeNode^  treeNode9 = (gcnew System::Windows::Forms::TreeNode(L"Knoten27"));
			System::Windows::Forms::TreeNode^  treeNode10 = (gcnew System::Windows::Forms::TreeNode(L"Knoten28"));
			System::Windows::Forms::TreeNode^  treeNode11 = (gcnew System::Windows::Forms::TreeNode(L"Knoten29"));
			System::Windows::Forms::TreeNode^  treeNode12 = (gcnew System::Windows::Forms::TreeNode(L"Knoten30"));
			System::Windows::Forms::TreeNode^  treeNode13 = (gcnew System::Windows::Forms::TreeNode(L"Knoten31"));
			System::Windows::Forms::TreeNode^  treeNode14 = (gcnew System::Windows::Forms::TreeNode(L"Knoten32"));
			System::Windows::Forms::TreeNode^  treeNode15 = (gcnew System::Windows::Forms::TreeNode(L"Knoten33"));
			System::Windows::Forms::TreeNode^  treeNode16 = (gcnew System::Windows::Forms::TreeNode(L"Knoten34"));
			System::Windows::Forms::TreeNode^  treeNode17 = (gcnew System::Windows::Forms::TreeNode(L"Knoten23", gcnew cli::array< System::Windows::Forms::TreeNode^  >(9) {
				treeNode8,
					treeNode9, treeNode10, treeNode11, treeNode12, treeNode13, treeNode14, treeNode15, treeNode16
			}));
			System::Windows::Forms::TreeNode^  treeNode18 = (gcnew System::Windows::Forms::TreeNode(L"Knoten24"));
			System::Windows::Forms::TreeNode^  treeNode19 = (gcnew System::Windows::Forms::TreeNode(L"Knoten25"));
			System::Windows::Forms::TreeNode^  treeNode20 = (gcnew System::Windows::Forms::TreeNode(L"Knoten17", gcnew cli::array< System::Windows::Forms::TreeNode^  >(5) {
				treeNode6,
					treeNode7, treeNode17, treeNode18, treeNode19
			}));
			System::Windows::Forms::TreeNode^  treeNode21 = (gcnew System::Windows::Forms::TreeNode(L"Knoten18"));
			System::Windows::Forms::TreeNode^  treeNode22 = (gcnew System::Windows::Forms::TreeNode(L"Knoten19"));
			System::Windows::Forms::TreeNode^  treeNode23 = (gcnew System::Windows::Forms::TreeNode(L"Knoten20"));
			System::Windows::Forms::TreeNode^  treeNode24 = (gcnew System::Windows::Forms::TreeNode(L"Knoten10", gcnew cli::array< System::Windows::Forms::TreeNode^  >(6) {
				treeNode4,
					treeNode5, treeNode20, treeNode21, treeNode22, treeNode23
			}));
			System::Windows::Forms::TreeNode^  treeNode25 = (gcnew System::Windows::Forms::TreeNode(L"Knoten11"));
			System::Windows::Forms::TreeNode^  treeNode26 = (gcnew System::Windows::Forms::TreeNode(L"Knoten12"));
			System::Windows::Forms::TreeNode^  treeNode27 = (gcnew System::Windows::Forms::TreeNode(L"Knoten13"));
			System::Windows::Forms::TreeNode^  treeNode28 = (gcnew System::Windows::Forms::TreeNode(L"Knoten14"));
			System::Windows::Forms::TreeNode^  treeNode29 = (gcnew System::Windows::Forms::TreeNode(L"Knoten0", gcnew cli::array< System::Windows::Forms::TreeNode^  >(8) {
				treeNode1,
					treeNode2, treeNode3, treeNode24, treeNode25, treeNode26, treeNode27, treeNode28
			}));
			System::Windows::Forms::ListViewItem^  listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(7) {
				L"0",
					L"1", L"2", L"3", L"4", L"5", L"6"
			}, -1));
			System::Windows::Forms::ListViewItem^  listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(8) {
				L"0",
					L"1", L"2", L"3", L"4", L"5", L"6", L"7"
			}, -1));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->mnuClearText = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuOpen = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuSave = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnStartProgress = (gcnew System::Windows::Forms::Button());
			this->btnChangeFromAnotherClass = (gcnew System::Windows::Forms::Button());
			this->btnComboInsert = (gcnew System::Windows::Forms::Button());
			this->btnComboremoveItem = (gcnew System::Windows::Forms::Button());
			this->btnComboAddItem = (gcnew System::Windows::Forms::Button());
			this->btnComboboxValue = (gcnew System::Windows::Forms::Button());
			this->btnRadioButton = (gcnew System::Windows::Forms::Button());
			this->btnCheckbox = (gcnew System::Windows::Forms::Button());
			this->btnChangeTab = (gcnew System::Windows::Forms::Button());
			this->cmdChangeFormColor = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->cmbBlubb = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->btnDivide = (gcnew System::Windows::Forms::Button());
			this->btnAddDoubles = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtZweiteZahl = (gcnew System::Windows::Forms::TextBox());
			this->txtErsteZahl = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->btnBenchmark = (gcnew System::Windows::Forms::Button());
			this->btnArray = (gcnew System::Windows::Forms::Button());
			this->btnList = (gcnew System::Windows::Forms::Button());
			this->btnHashtable = (gcnew System::Windows::Forms::Button());
			this->btnSortedList = (gcnew System::Windows::Forms::Button());
			this->btnStack = (gcnew System::Windows::Forms::Button());
			this->btnQueue = (gcnew System::Windows::Forms::Button());
			this->btnArrayList = (gcnew System::Windows::Forms::Button());
			this->txtCollections = (gcnew System::Windows::Forms::TextBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->txtAnswers = (gcnew System::Windows::Forms::TextBox());
			this->txtQuestions = (gcnew System::Windows::Forms::TextBox());
			this->btnNextStep = (gcnew System::Windows::Forms::Button());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->pnlDrawing = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pnlGraphics = (gcnew System::Windows::Forms::Panel());
			this->btnDrawHouse = (gcnew System::Windows::Forms::Button());
			this->btnDrawImage = (gcnew System::Windows::Forms::Button());
			this->btnTranslatePoints = (gcnew System::Windows::Forms::Button());
			this->btnDrawLine = (gcnew System::Windows::Forms::Button());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->btnChangeRegexInRegexTextBox = (gcnew System::Windows::Forms::Button());
			this->txtRegexExpr = (gcnew System::Windows::Forms::TextBox());
			this->txtRegex = (gcnew System::Windows::Forms::TextBox());
			this->btnRegex = (gcnew System::Windows::Forms::Button());
			this->txtTreeView = (gcnew System::Windows::Forms::TextBox());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->btnDriveInfo = (gcnew System::Windows::Forms::Button());
			this->btnWalkTreeViewRecursive = (gcnew System::Windows::Forms::Button());
			this->btnRecursion = (gcnew System::Windows::Forms::Button());
			this->btnReadDirectories = (gcnew System::Windows::Forms::Button());
			this->btnRemoveTreeNOde = (gcnew System::Windows::Forms::Button());
			this->btnAddTreeNodeToTreeView = (gcnew System::Windows::Forms::Button());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->trvDirectories = (gcnew System::Windows::Forms::TreeView());
			this->lsvFiles = (gcnew System::Windows::Forms::ListView());
			this->tabPage8 = (gcnew System::Windows::Forms::TabPage());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->lsvTest = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->tabPage9 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tabPage10 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->txtWeb = (gcnew System::Windows::Forms::TextBox());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->btnSendMail = (gcnew System::Windows::Forms::Button());
			this->btnFTPDownloadBinary = (gcnew System::Windows::Forms::Button());
			this->btnFTPDownload = (gcnew System::Windows::Forms::Button());
			this->btnFTPWebrequestDirectory = (gcnew System::Windows::Forms::Button());
			this->txtURL = (gcnew System::Windows::Forms::TextBox());
			this->btnWebRequest = (gcnew System::Windows::Forms::Button());
			this->tabPage11 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->btnDoDllMethod = (gcnew System::Windows::Forms::Button());
			this->btnLoadFromRegistry = (gcnew System::Windows::Forms::Button());
			this->btnWriteToRegistry = (gcnew System::Windows::Forms::Button());
			this->txtXMLOutput = (gcnew System::Windows::Forms::TextBox());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->btnGetHighestKundeId = (gcnew System::Windows::Forms::Button());
			this->btnCreateKundenverzeichnisXmlDocument = (gcnew System::Windows::Forms::Button());
			this->btnUpdateKunde = (gcnew System::Windows::Forms::Button());
			this->btnDeleteKundeFromVerzeichnis = (gcnew System::Windows::Forms::Button());
			this->btnReadKundeFromKundenVverzeichnisXml = (gcnew System::Windows::Forms::Button());
			this->btnCreateClassKundeXmlNode = (gcnew System::Windows::Forms::Button());
			this->btnCreateKundeNode = (gcnew System::Windows::Forms::Button());
			this->btnLoadXMLDoc = (gcnew System::Windows::Forms::Button());
			this->btnCreateXMLDocument = (gcnew System::Windows::Forms::Button());
			this->tabPage12 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel10 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel16 = (gcnew System::Windows::Forms::Panel());
			this->lsvProdukte = (gcnew System::Windows::Forms::ListView());
			this->columnHeader11 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader12 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader13 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader14 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader15 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader16 = (gcnew System::Windows::Forms::ColumnHeader());
			this->txtSQLOutput = (gcnew System::Windows::Forms::TextBox());
			this->panel17 = (gcnew System::Windows::Forms::Panel());
			this->lsvKunden = (gcnew System::Windows::Forms::ListView());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader9 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader10 = (gcnew System::Windows::Forms::ColumnHeader());
			this->panel18 = (gcnew System::Windows::Forms::Panel());
			this->cmbRechnungsids = (gcnew System::Windows::Forms::ComboBox());
			this->btnShowRechnung = (gcnew System::Windows::Forms::Button());
			this->btnCreateRechnungspositionen = (gcnew System::Windows::Forms::Button());
			this->btnCreateRechnung = (gcnew System::Windows::Forms::Button());
			this->btnGetLastInsertedId = (gcnew System::Windows::Forms::Button());
			this->btnFillProduktListView = (gcnew System::Windows::Forms::Button());
			this->btnFillKundenListView = (gcnew System::Windows::Forms::Button());
			this->btnUpdateKundeEntity = (gcnew System::Windows::Forms::Button());
			this->txtSelectKundeId = (gcnew System::Windows::Forms::TextBox());
			this->btnSelectKundeEntity = (gcnew System::Windows::Forms::Button());
			this->btnDeleteKundeEntity = (gcnew System::Windows::Forms::Button());
			this->txtDeleteKundeId = (gcnew System::Windows::Forms::TextBox());
			this->btnInsertKundeEntity = (gcnew System::Windows::Forms::Button());
			this->txtKundeUmsatz = (gcnew System::Windows::Forms::TextBox());
			this->txtKundeBenutzername = (gcnew System::Windows::Forms::TextBox());
			this->txtKundeOrt = (gcnew System::Windows::Forms::TextBox());
			this->txtKundePlz = (gcnew System::Windows::Forms::TextBox());
			this->txtKundeStrasse = (gcnew System::Windows::Forms::TextBox());
			this->txtKundeNachname = (gcnew System::Windows::Forms::TextBox());
			this->txtKundeVorname = (gcnew System::Windows::Forms::TextBox());
			this->btnSelectKunden = (gcnew System::Windows::Forms::Button());
			this->btnUpdateKundeDB = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnInsertKunde = (gcnew System::Windows::Forms::Button());
			this->btnConnectDatabase = (gcnew System::Windows::Forms::Button());
			this->tabPage13 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel11 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel19 = (gcnew System::Windows::Forms::Panel());
			this->txtCulture = (gcnew System::Windows::Forms::TextBox());
			this->panel20 = (gcnew System::Windows::Forms::Panel());
			this->webBrowser2 = (gcnew System::Windows::Forms::WebBrowser());
			this->panel21 = (gcnew System::Windows::Forms::Panel());
			this->btnReflect = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->btnDateTimeCulture = (gcnew System::Windows::Forms::Button());
			this->btnListCultures = (gcnew System::Windows::Forms::Button());
			this->tabPage14 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel12 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel22 = (gcnew System::Windows::Forms::Panel());
			this->txtSQLite = (gcnew System::Windows::Forms::TextBox());
			this->panel23 = (gcnew System::Windows::Forms::Panel());
			this->webBrowser3 = (gcnew System::Windows::Forms::WebBrowser());
			this->panel24 = (gcnew System::Windows::Forms::Panel());
			this->btnGetLastInsertedSQLiteId = (gcnew System::Windows::Forms::Button());
			this->btnReadSQLiteKunden = (gcnew System::Windows::Forms::Button());
			this->btnInsertSQLiteKunde = (gcnew System::Windows::Forms::Button());
			this->btnCreateSqliteTable = (gcnew System::Windows::Forms::Button());
			this->btnSqliteCreate = (gcnew System::Windows::Forms::Button());
			this->tabPage15 = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel13 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel25 = (gcnew System::Windows::Forms::Panel());
			this->txtThreading = (gcnew System::Windows::Forms::TextBox());
			this->panel26 = (gcnew System::Windows::Forms::Panel());
			this->webBrowser4 = (gcnew System::Windows::Forms::WebBrowser());
			this->panel27 = (gcnew System::Windows::Forms::Panel());
			this->btnKillProcess = (gcnew System::Windows::Forms::Button());
			this->numProcessId = (gcnew System::Windows::Forms::NumericUpDown());
			this->btnProcesses = (gcnew System::Windows::Forms::Button());
			this->btnScreenshot = (gcnew System::Windows::Forms::Button());
			this->btnPlayWav = (gcnew System::Windows::Forms::Button());
			this->btnStartWorker = (gcnew System::Windows::Forms::Button());
			this->btnThreadStart = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mnuSaveFileDialog = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuRichtextBox = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuFolderBrowser = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuFarben = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuSchriftart = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuButtonsHerstellen = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuListControls = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuTextBoxenHerstellen = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuRefreshTreeView = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuFillListView = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->txtDatabaseConnectionStatus = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->eRPToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnOpenRechnungsFenster = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->checkHeartbeatDatabaseStatus = (gcnew System::Windows::Forms::Timer(this->components));
			this->txtProcessName = (gcnew System::Windows::Forms::TextBox());
			this->btnStartProcessByName = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->panel4->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->pnlDrawing->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->pnlGraphics->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel7->SuspendLayout();
			this->tabPage7->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->tabPage8->SuspendLayout();
			this->panel9->SuspendLayout();
			this->tabPage9->SuspendLayout();
			this->tabPage10->SuspendLayout();
			this->tableLayoutPanel8->SuspendLayout();
			this->panel11->SuspendLayout();
			this->panel12->SuspendLayout();
			this->tabPage11->SuspendLayout();
			this->tableLayoutPanel9->SuspendLayout();
			this->panel13->SuspendLayout();
			this->panel15->SuspendLayout();
			this->tabPage12->SuspendLayout();
			this->tableLayoutPanel10->SuspendLayout();
			this->panel16->SuspendLayout();
			this->panel17->SuspendLayout();
			this->panel18->SuspendLayout();
			this->tabPage13->SuspendLayout();
			this->tableLayoutPanel11->SuspendLayout();
			this->panel20->SuspendLayout();
			this->panel21->SuspendLayout();
			this->tabPage14->SuspendLayout();
			this->tableLayoutPanel12->SuspendLayout();
			this->panel23->SuspendLayout();
			this->panel24->SuspendLayout();
			this->tabPage15->SuspendLayout();
			this->tableLayoutPanel13->SuspendLayout();
			this->panel26->SuspendLayout();
			this->panel27->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numProcessId))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->textBox1, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->panel2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel3, 1, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(856, 573);
			this->tableLayoutPanel1->TabIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->ContextMenuStrip = this->contextMenuStrip1;
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Location = System::Drawing::Point(431, 3);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(422, 280);
			this->textBox1->TabIndex = 2;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->mnuClearText,
					this->mnuOpen, this->mnuSave
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(160, 70);
			// 
			// mnuClearText
			// 
			this->mnuClearText->Name = L"mnuClearText";
			this->mnuClearText->Size = System::Drawing::Size(159, 22);
			this->mnuClearText->Text = L"TextBox löschen";
			this->mnuClearText->Click += gcnew System::EventHandler(this, &MainForm::mnuClearText_Click);
			// 
			// mnuOpen
			// 
			this->mnuOpen->Name = L"mnuOpen";
			this->mnuOpen->Size = System::Drawing::Size(159, 22);
			this->mnuOpen->Text = L"Datei öffnen";
			this->mnuOpen->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItem2_Click);
			// 
			// mnuSave
			// 
			this->mnuSave->Name = L"mnuSave";
			this->mnuSave->Size = System::Drawing::Size(159, 22);
			this->mnuSave->Text = L"Speichern als";
			this->mnuSave->Click += gcnew System::EventHandler(this, &MainForm::mnuSaveFileDialog_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->btnStartProgress);
			this->panel1->Controls->Add(this->btnChangeFromAnotherClass);
			this->panel1->Controls->Add(this->btnComboInsert);
			this->panel1->Controls->Add(this->btnComboremoveItem);
			this->panel1->Controls->Add(this->btnComboAddItem);
			this->panel1->Controls->Add(this->btnComboboxValue);
			this->panel1->Controls->Add(this->btnRadioButton);
			this->panel1->Controls->Add(this->btnCheckbox);
			this->panel1->Controls->Add(this->btnChangeTab);
			this->panel1->Controls->Add(this->cmdChangeFormColor);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(422, 280);
			this->panel1->TabIndex = 1;
			// 
			// btnStartProgress
			// 
			this->btnStartProgress->Location = System::Drawing::Point(115, 32);
			this->btnStartProgress->Name = L"btnStartProgress";
			this->btnStartProgress->Size = System::Drawing::Size(109, 23);
			this->btnStartProgress->TabIndex = 9;
			this->btnStartProgress->Text = L"Start Progress";
			this->btnStartProgress->UseVisualStyleBackColor = true;
			this->btnStartProgress->Click += gcnew System::EventHandler(this, &MainForm::btnStartProgress_Click);
			// 
			// btnChangeFromAnotherClass
			// 
			this->btnChangeFromAnotherClass->Location = System::Drawing::Point(115, 3);
			this->btnChangeFromAnotherClass->Name = L"btnChangeFromAnotherClass";
			this->btnChangeFromAnotherClass->Size = System::Drawing::Size(109, 23);
			this->btnChangeFromAnotherClass->TabIndex = 8;
			this->btnChangeFromAnotherClass->Text = L"Class Fun";
			this->btnChangeFromAnotherClass->UseVisualStyleBackColor = true;
			this->btnChangeFromAnotherClass->Click += gcnew System::EventHandler(this, &MainForm::btnChangeFromAnotherClass_Click);
			// 
			// btnComboInsert
			// 
			this->btnComboInsert->Location = System::Drawing::Point(3, 178);
			this->btnComboInsert->Name = L"btnComboInsert";
			this->btnComboInsert->Size = System::Drawing::Size(109, 23);
			this->btnComboInsert->TabIndex = 7;
			this->btnComboInsert->Text = L"Combo insert Item";
			this->btnComboInsert->UseVisualStyleBackColor = true;
			this->btnComboInsert->Click += gcnew System::EventHandler(this, &MainForm::btnComboInsert_Click);
			// 
			// btnComboremoveItem
			// 
			this->btnComboremoveItem->Location = System::Drawing::Point(4, 207);
			this->btnComboremoveItem->Name = L"btnComboremoveItem";
			this->btnComboremoveItem->Size = System::Drawing::Size(109, 23);
			this->btnComboremoveItem->TabIndex = 6;
			this->btnComboremoveItem->Text = L"Combo remove Item";
			this->btnComboremoveItem->UseVisualStyleBackColor = true;
			this->btnComboremoveItem->Click += gcnew System::EventHandler(this, &MainForm::btnComboremoveItem_Click);
			// 
			// btnComboAddItem
			// 
			this->btnComboAddItem->Location = System::Drawing::Point(3, 149);
			this->btnComboAddItem->Name = L"btnComboAddItem";
			this->btnComboAddItem->Size = System::Drawing::Size(96, 23);
			this->btnComboAddItem->TabIndex = 5;
			this->btnComboAddItem->Text = L"Combo Add Item";
			this->btnComboAddItem->UseVisualStyleBackColor = true;
			this->btnComboAddItem->Click += gcnew System::EventHandler(this, &MainForm::btnComboAddItem_Click);
			// 
			// btnComboboxValue
			// 
			this->btnComboboxValue->Location = System::Drawing::Point(4, 120);
			this->btnComboboxValue->Name = L"btnComboboxValue";
			this->btnComboboxValue->Size = System::Drawing::Size(96, 23);
			this->btnComboboxValue->TabIndex = 4;
			this->btnComboboxValue->Text = L"Combo Value";
			this->btnComboboxValue->UseVisualStyleBackColor = true;
			this->btnComboboxValue->Click += gcnew System::EventHandler(this, &MainForm::btnComboboxValue_Click);
			// 
			// btnRadioButton
			// 
			this->btnRadioButton->Location = System::Drawing::Point(4, 91);
			this->btnRadioButton->Name = L"btnRadioButton";
			this->btnRadioButton->Size = System::Drawing::Size(96, 23);
			this->btnRadioButton->TabIndex = 3;
			this->btnRadioButton->Text = L"Radiobutton";
			this->btnRadioButton->UseVisualStyleBackColor = true;
			this->btnRadioButton->Click += gcnew System::EventHandler(this, &MainForm::btnRadioButton_Click);
			// 
			// btnCheckbox
			// 
			this->btnCheckbox->Location = System::Drawing::Point(4, 62);
			this->btnCheckbox->Name = L"btnCheckbox";
			this->btnCheckbox->Size = System::Drawing::Size(96, 23);
			this->btnCheckbox->TabIndex = 2;
			this->btnCheckbox->Text = L"Checkbox";
			this->btnCheckbox->UseVisualStyleBackColor = true;
			this->btnCheckbox->Click += gcnew System::EventHandler(this, &MainForm::btnCheckbox_Click);
			// 
			// btnChangeTab
			// 
			this->btnChangeTab->Location = System::Drawing::Point(3, 32);
			this->btnChangeTab->Name = L"btnChangeTab";
			this->btnChangeTab->Size = System::Drawing::Size(97, 23);
			this->btnChangeTab->TabIndex = 1;
			this->btnChangeTab->Text = L"Change Tab";
			this->btnChangeTab->UseVisualStyleBackColor = true;
			this->btnChangeTab->Click += gcnew System::EventHandler(this, &MainForm::btnChangeTab_Click);
			// 
			// cmdChangeFormColor
			// 
			this->cmdChangeFormColor->Location = System::Drawing::Point(3, 3);
			this->cmdChangeFormColor->Name = L"cmdChangeFormColor";
			this->cmdChangeFormColor->Size = System::Drawing::Size(97, 23);
			this->cmdChangeFormColor->TabIndex = 0;
			this->cmdChangeFormColor->Text = L"Change Color";
			this->cmdChangeFormColor->UseVisualStyleBackColor = true;
			this->cmdChangeFormColor->Click += gcnew System::EventHandler(this, &MainForm::cmdChangeFormColor_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->dateTimePicker1);
			this->panel2->Controls->Add(this->trackBar1);
			this->panel2->Controls->Add(this->numericUpDown1);
			this->panel2->Controls->Add(this->maskedTextBox1);
			this->panel2->Controls->Add(this->listBox1);
			this->panel2->Controls->Add(this->cmbBlubb);
			this->panel2->Controls->Add(this->groupBox1);
			this->panel2->Controls->Add(this->checkBox1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(3, 289);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(422, 281);
			this->panel2->TabIndex = 3;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(24, 205);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 10;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &MainForm::dateTimePicker1_ValueChanged);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(10, 158);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(104, 45);
			this->trackBar1->TabIndex = 9;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MainForm::trackBar1_Scroll);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numericUpDown1->Location = System::Drawing::Point(191, 132);
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(79, 20);
			this->numericUpDown1->TabIndex = 8;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Location = System::Drawing::Point(4, 131);
			this->maskedTextBox1->Mask = L"00/00/0000 00:00";
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(172, 20);
			this->maskedTextBox1->TabIndex = 7;
			this->maskedTextBox1->ValidatingType = System::DateTime::typeid;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Bli", L"Bla", L"Blubb", L"Trallallaaaaaa" });
			this->listBox1->Location = System::Drawing::Point(133, 30);
			this->listBox1->Name = L"listBox1";
			this->listBox1->SelectionMode = System::Windows::Forms::SelectionMode::MultiSimple;
			this->listBox1->Size = System::Drawing::Size(137, 95);
			this->listBox1->TabIndex = 6;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::listBox1_SelectedIndexChanged);
			// 
			// cmbBlubb
			// 
			this->cmbBlubb->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbBlubb->FormattingEnabled = true;
			this->cmbBlubb->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Bli", L"Bla", L"Blubb", L"Trallalla", L"Whooop" });
			this->cmbBlubb->Location = System::Drawing::Point(133, 3);
			this->cmbBlubb->Name = L"cmbBlubb";
			this->cmbBlubb->Size = System::Drawing::Size(137, 21);
			this->cmbBlubb->TabIndex = 5;
			this->cmbBlubb->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::cmbBlubb_SelectedIndexChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(4, 26);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(113, 91);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(6, 65);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(85, 17);
			this->radioButton3->TabIndex = 3;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"radioButton3";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(6, 42);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(85, 17);
			this->radioButton2->TabIndex = 2;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"radioButton2";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(6, 19);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(85, 17);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"radioButton1";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(3, 3);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(80, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox1_CheckedChanged);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->btnDivide);
			this->panel3->Controls->Add(this->btnAddDoubles);
			this->panel3->Controls->Add(this->label1);
			this->panel3->Controls->Add(this->txtZweiteZahl);
			this->panel3->Controls->Add(this->txtErsteZahl);
			this->panel3->Controls->Add(this->richTextBox1);
			this->panel3->Controls->Add(this->progressBar1);
			this->panel3->Controls->Add(this->pictureBox1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(431, 289);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(422, 281);
			this->panel3->TabIndex = 4;
			// 
			// btnDivide
			// 
			this->btnDivide->Location = System::Drawing::Point(107, 196);
			this->btnDivide->Name = L"btnDivide";
			this->btnDivide->Size = System::Drawing::Size(30, 23);
			this->btnDivide->TabIndex = 11;
			this->btnDivide->Text = L"/";
			this->btnDivide->UseVisualStyleBackColor = true;
			this->btnDivide->Click += gcnew System::EventHandler(this, &MainForm::btnDivide_Click);
			// 
			// btnAddDoubles
			// 
			this->btnAddDoubles->Location = System::Drawing::Point(240, 167);
			this->btnAddDoubles->Name = L"btnAddDoubles";
			this->btnAddDoubles->Size = System::Drawing::Size(30, 23);
			this->btnAddDoubles->TabIndex = 10;
			this->btnAddDoubles->Text = L"=";
			this->btnAddDoubles->UseVisualStyleBackColor = true;
			this->btnAddDoubles->Click += gcnew System::EventHandler(this, &MainForm::btnAddDoubles_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(124, 173);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(13, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"+";
			// 
			// txtZweiteZahl
			// 
			this->txtZweiteZahl->Location = System::Drawing::Point(138, 170);
			this->txtZweiteZahl->Name = L"txtZweiteZahl";
			this->txtZweiteZahl->Size = System::Drawing::Size(100, 20);
			this->txtZweiteZahl->TabIndex = 4;
			// 
			// txtErsteZahl
			// 
			this->txtErsteZahl->Location = System::Drawing::Point(18, 170);
			this->txtErsteZahl->Name = L"txtErsteZahl";
			this->txtErsteZahl->Size = System::Drawing::Size(100, 20);
			this->txtErsteZahl->TabIndex = 3;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(93, 29);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(177, 88);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(93, 3);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(177, 14);
			this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBar1->TabIndex = 1;
			this->progressBar1->Value = 40;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(3, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(84, 82);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Controls->Add(this->tabPage6);
			this->tabControl1->Controls->Add(this->tabPage7);
			this->tabControl1->Controls->Add(this->tabPage8);
			this->tabControl1->Controls->Add(this->tabPage9);
			this->tabControl1->Controls->Add(this->tabPage10);
			this->tabControl1->Controls->Add(this->tabPage11);
			this->tabControl1->Controls->Add(this->tabPage12);
			this->tabControl1->Controls->Add(this->tabPage13);
			this->tabControl1->Controls->Add(this->tabPage14);
			this->tabControl1->Controls->Add(this->tabPage15);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 27);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(870, 605);
			this->tabControl1->TabIndex = 4;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->tableLayoutPanel1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(862, 579);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Basics";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->tableLayoutPanel2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(862, 579);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Other";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->panel4, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->txtCollections, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(856, 573);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->btnBenchmark);
			this->panel4->Controls->Add(this->btnArray);
			this->panel4->Controls->Add(this->btnList);
			this->panel4->Controls->Add(this->btnHashtable);
			this->panel4->Controls->Add(this->btnSortedList);
			this->panel4->Controls->Add(this->btnStack);
			this->panel4->Controls->Add(this->btnQueue);
			this->panel4->Controls->Add(this->btnArrayList);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(3, 3);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(422, 567);
			this->panel4->TabIndex = 0;
			// 
			// btnBenchmark
			// 
			this->btnBenchmark->Location = System::Drawing::Point(4, 207);
			this->btnBenchmark->Name = L"btnBenchmark";
			this->btnBenchmark->Size = System::Drawing::Size(121, 23);
			this->btnBenchmark->TabIndex = 8;
			this->btnBenchmark->Text = L"Benchmark";
			this->btnBenchmark->UseVisualStyleBackColor = true;
			this->btnBenchmark->Click += gcnew System::EventHandler(this, &MainForm::btnBenchmark_Click);
			// 
			// btnArray
			// 
			this->btnArray->Location = System::Drawing::Point(4, 178);
			this->btnArray->Name = L"btnArray";
			this->btnArray->Size = System::Drawing::Size(121, 23);
			this->btnArray->TabIndex = 7;
			this->btnArray->Text = L"array";
			this->btnArray->UseVisualStyleBackColor = true;
			this->btnArray->Click += gcnew System::EventHandler(this, &MainForm::btnArray_Click);
			// 
			// btnList
			// 
			this->btnList->Location = System::Drawing::Point(4, 149);
			this->btnList->Name = L"btnList";
			this->btnList->Size = System::Drawing::Size(121, 23);
			this->btnList->TabIndex = 6;
			this->btnList->Text = L"List";
			this->btnList->UseVisualStyleBackColor = true;
			this->btnList->Click += gcnew System::EventHandler(this, &MainForm::btnList_Click);
			// 
			// btnHashtable
			// 
			this->btnHashtable->Location = System::Drawing::Point(4, 120);
			this->btnHashtable->Name = L"btnHashtable";
			this->btnHashtable->Size = System::Drawing::Size(121, 23);
			this->btnHashtable->TabIndex = 4;
			this->btnHashtable->Text = L"HashTable";
			this->btnHashtable->UseVisualStyleBackColor = true;
			this->btnHashtable->Click += gcnew System::EventHandler(this, &MainForm::btnHashtable_Click);
			// 
			// btnSortedList
			// 
			this->btnSortedList->Location = System::Drawing::Point(4, 91);
			this->btnSortedList->Name = L"btnSortedList";
			this->btnSortedList->Size = System::Drawing::Size(121, 23);
			this->btnSortedList->TabIndex = 3;
			this->btnSortedList->Text = L"SortedList";
			this->btnSortedList->UseVisualStyleBackColor = true;
			this->btnSortedList->Click += gcnew System::EventHandler(this, &MainForm::btnSortedList_Click);
			// 
			// btnStack
			// 
			this->btnStack->Location = System::Drawing::Point(4, 62);
			this->btnStack->Name = L"btnStack";
			this->btnStack->Size = System::Drawing::Size(121, 23);
			this->btnStack->TabIndex = 2;
			this->btnStack->Text = L"Stack";
			this->btnStack->UseVisualStyleBackColor = true;
			this->btnStack->Click += gcnew System::EventHandler(this, &MainForm::btnStack_Click);
			// 
			// btnQueue
			// 
			this->btnQueue->Location = System::Drawing::Point(4, 33);
			this->btnQueue->Name = L"btnQueue";
			this->btnQueue->Size = System::Drawing::Size(121, 23);
			this->btnQueue->TabIndex = 1;
			this->btnQueue->Text = L"Queue";
			this->btnQueue->UseVisualStyleBackColor = true;
			this->btnQueue->Click += gcnew System::EventHandler(this, &MainForm::btnQueue_Click);
			// 
			// btnArrayList
			// 
			this->btnArrayList->Location = System::Drawing::Point(4, 4);
			this->btnArrayList->Name = L"btnArrayList";
			this->btnArrayList->Size = System::Drawing::Size(121, 23);
			this->btnArrayList->TabIndex = 0;
			this->btnArrayList->Text = L"ArrayList";
			this->btnArrayList->UseVisualStyleBackColor = true;
			this->btnArrayList->Click += gcnew System::EventHandler(this, &MainForm::btnArrayList_Click);
			// 
			// txtCollections
			// 
			this->txtCollections->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtCollections->Location = System::Drawing::Point(431, 3);
			this->txtCollections->Multiline = true;
			this->txtCollections->Name = L"txtCollections";
			this->txtCollections->Size = System::Drawing::Size(422, 567);
			this->txtCollections->TabIndex = 1;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->txtAnswers);
			this->tabPage3->Controls->Add(this->txtQuestions);
			this->tabPage3->Controls->Add(this->btnNextStep);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(862, 579);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Quiz";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// txtAnswers
			// 
			this->txtAnswers->Location = System::Drawing::Point(288, 231);
			this->txtAnswers->Multiline = true;
			this->txtAnswers->Name = L"txtAnswers";
			this->txtAnswers->Size = System::Drawing::Size(268, 203);
			this->txtAnswers->TabIndex = 2;
			// 
			// txtQuestions
			// 
			this->txtQuestions->Location = System::Drawing::Point(288, 4);
			this->txtQuestions->Multiline = true;
			this->txtQuestions->Name = L"txtQuestions";
			this->txtQuestions->Size = System::Drawing::Size(268, 203);
			this->txtQuestions->TabIndex = 1;
			// 
			// btnNextStep
			// 
			this->btnNextStep->Location = System::Drawing::Point(7, 7);
			this->btnNextStep->Name = L"btnNextStep";
			this->btnNextStep->Size = System::Drawing::Size(75, 23);
			this->btnNextStep->TabIndex = 0;
			this->btnNextStep->Text = L"Next";
			this->btnNextStep->UseVisualStyleBackColor = true;
			this->btnNextStep->Click += gcnew System::EventHandler(this, &MainForm::btnNextStep_Click);
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->tableLayoutPanel3);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(862, 579);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Graphics";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->pnlDrawing, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->pnlGraphics, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(856, 573);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// pnlDrawing
			// 
			this->pnlDrawing->BackColor = System::Drawing::Color::Gainsboro;
			this->pnlDrawing->Controls->Add(this->pictureBox2);
			this->pnlDrawing->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlDrawing->Location = System::Drawing::Point(431, 3);
			this->pnlDrawing->Name = L"pnlDrawing";
			this->pnlDrawing->Size = System::Drawing::Size(422, 567);
			this->pnlDrawing->TabIndex = 0;
			this->pnlDrawing->Click += gcnew System::EventHandler(this, &MainForm::pnlDrawing_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(0, 0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(422, 567);
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MainForm::pnlDrawing_Click);
			this->pictureBox2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pnlDrawing_Paint);
			// 
			// pnlGraphics
			// 
			this->pnlGraphics->Controls->Add(this->btnDrawHouse);
			this->pnlGraphics->Controls->Add(this->btnDrawImage);
			this->pnlGraphics->Controls->Add(this->btnTranslatePoints);
			this->pnlGraphics->Controls->Add(this->btnDrawLine);
			this->pnlGraphics->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlGraphics->Location = System::Drawing::Point(3, 3);
			this->pnlGraphics->Name = L"pnlGraphics";
			this->pnlGraphics->Size = System::Drawing::Size(422, 567);
			this->pnlGraphics->TabIndex = 1;
			// 
			// btnDrawHouse
			// 
			this->btnDrawHouse->Location = System::Drawing::Point(3, 90);
			this->btnDrawHouse->Name = L"btnDrawHouse";
			this->btnDrawHouse->Size = System::Drawing::Size(75, 23);
			this->btnDrawHouse->TabIndex = 3;
			this->btnDrawHouse->Text = L"Draw House";
			this->btnDrawHouse->UseVisualStyleBackColor = true;
			this->btnDrawHouse->Click += gcnew System::EventHandler(this, &MainForm::btnDrawHouse_Click);
			// 
			// btnDrawImage
			// 
			this->btnDrawImage->Location = System::Drawing::Point(3, 61);
			this->btnDrawImage->Name = L"btnDrawImage";
			this->btnDrawImage->Size = System::Drawing::Size(75, 23);
			this->btnDrawImage->TabIndex = 2;
			this->btnDrawImage->Text = L"Draw Image";
			this->btnDrawImage->UseVisualStyleBackColor = true;
			this->btnDrawImage->Click += gcnew System::EventHandler(this, &MainForm::btnDrawImage_Click);
			// 
			// btnTranslatePoints
			// 
			this->btnTranslatePoints->Location = System::Drawing::Point(3, 32);
			this->btnTranslatePoints->Name = L"btnTranslatePoints";
			this->btnTranslatePoints->Size = System::Drawing::Size(75, 23);
			this->btnTranslatePoints->TabIndex = 1;
			this->btnTranslatePoints->Text = L"Zoom";
			this->btnTranslatePoints->UseVisualStyleBackColor = true;
			this->btnTranslatePoints->Click += gcnew System::EventHandler(this, &MainForm::btnTranslatePoints_Click);
			// 
			// btnDrawLine
			// 
			this->btnDrawLine->Location = System::Drawing::Point(3, 3);
			this->btnDrawLine->Name = L"btnDrawLine";
			this->btnDrawLine->Size = System::Drawing::Size(75, 23);
			this->btnDrawLine->TabIndex = 0;
			this->btnDrawLine->Text = L"Draw Line";
			this->btnDrawLine->UseVisualStyleBackColor = true;
			this->btnDrawLine->Click += gcnew System::EventHandler(this, &MainForm::btnDrawLine_Click);
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->tableLayoutPanel4);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(862, 579);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Own Components";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->Controls->Add(this->textBox2, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->panel5, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->panel6, 0, 1);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 2;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 22.91667F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 77.08334F)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(856, 573);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox2->Location = System::Drawing::Point(431, 3);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(422, 125);
			this->textBox2->TabIndex = 0;
			// 
			// panel5
			// 
			this->panel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel5->Location = System::Drawing::Point(3, 3);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(422, 125);
			this->panel5->TabIndex = 1;
			// 
			// panel6
			// 
			this->panel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel6->Location = System::Drawing::Point(3, 134);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(422, 436);
			this->panel6->TabIndex = 2;
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->tableLayoutPanel5);
			this->tabPage6->Location = System::Drawing::Point(4, 22);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(862, 579);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"Trees";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 2;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel5->Controls->Add(this->panel8, 0, 1);
			this->tableLayoutPanel5->Controls->Add(this->txtTreeView, 1, 0);
			this->tableLayoutPanel5->Controls->Add(this->treeView1, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->panel7, 1, 1);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 2;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 55.20833F)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 44.79167F)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(856, 573);
			this->tableLayoutPanel5->TabIndex = 1;
			// 
			// panel8
			// 
			this->panel8->Controls->Add(this->btnChangeRegexInRegexTextBox);
			this->panel8->Controls->Add(this->txtRegexExpr);
			this->panel8->Controls->Add(this->txtRegex);
			this->panel8->Controls->Add(this->btnRegex);
			this->panel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel8->Location = System::Drawing::Point(3, 319);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(422, 251);
			this->panel8->TabIndex = 2;
			// 
			// btnChangeRegexInRegexTextBox
			// 
			this->btnChangeRegexInRegexTextBox->Location = System::Drawing::Point(3, 72);
			this->btnChangeRegexInRegexTextBox->Name = L"btnChangeRegexInRegexTextBox";
			this->btnChangeRegexInRegexTextBox->Size = System::Drawing::Size(103, 23);
			this->btnChangeRegexInRegexTextBox->TabIndex = 4;
			this->btnChangeRegexInRegexTextBox->Text = L"Change Regex";
			this->btnChangeRegexInRegexTextBox->UseVisualStyleBackColor = true;
			this->btnChangeRegexInRegexTextBox->Click += gcnew System::EventHandler(this, &MainForm::btnChangeRegexInRegexTextBox_Click);
			// 
			// txtRegexExpr
			// 
			this->txtRegexExpr->Location = System::Drawing::Point(3, 6);
			this->txtRegexExpr->Name = L"txtRegexExpr";
			this->txtRegexExpr->Size = System::Drawing::Size(416, 20);
			this->txtRegexExpr->TabIndex = 6;
			this->txtRegexExpr->Text = L"^([\\+][0-9]{1,3}[ \\.\\-])\?([\\(]{1}[0-9]{1,6}[\\)])\?([0-9 \\.\\-\\/]{3,20})((x|ext|exte"
				L"nsion)[ ]\?[0-9]{1,4})\?$";
			// 
			// txtRegex
			// 
			this->txtRegex->Location = System::Drawing::Point(112, 43);
			this->txtRegex->Name = L"txtRegex";
			this->txtRegex->Size = System::Drawing::Size(307, 20);
			this->txtRegex->TabIndex = 5;
			this->txtRegex->Text = L"+49 (0) 123 456789";
			// 
			// btnRegex
			// 
			this->btnRegex->Location = System::Drawing::Point(3, 43);
			this->btnRegex->Name = L"btnRegex";
			this->btnRegex->Size = System::Drawing::Size(103, 23);
			this->btnRegex->TabIndex = 4;
			this->btnRegex->Text = L"Regex";
			this->btnRegex->UseVisualStyleBackColor = true;
			this->btnRegex->Click += gcnew System::EventHandler(this, &MainForm::btnRegex_Click);
			// 
			// txtTreeView
			// 
			this->txtTreeView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtTreeView->Location = System::Drawing::Point(431, 3);
			this->txtTreeView->Multiline = true;
			this->txtTreeView->Name = L"txtTreeView";
			this->txtTreeView->Size = System::Drawing::Size(422, 310);
			this->txtTreeView->TabIndex = 0;
			// 
			// treeView1
			// 
			this->treeView1->AllowDrop = true;
			this->treeView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->treeView1->Location = System::Drawing::Point(3, 3);
			this->treeView1->Name = L"treeView1";
			treeNode1->Name = L"Knoten7";
			treeNode1->Text = L"Knoten7";
			treeNode2->Name = L"Knoten8";
			treeNode2->Text = L"Knoten8";
			treeNode3->Name = L"Knoten9";
			treeNode3->Text = L"Knoten9";
			treeNode4->Name = L"Knoten15";
			treeNode4->Text = L"Knoten15";
			treeNode5->Name = L"Knoten16";
			treeNode5->Text = L"Knoten16";
			treeNode6->Name = L"Knoten21";
			treeNode6->Text = L"Knoten21";
			treeNode7->Name = L"Knoten22";
			treeNode7->Text = L"Knoten22";
			treeNode8->Name = L"Knoten26";
			treeNode8->Text = L"Knoten26";
			treeNode9->Name = L"Knoten27";
			treeNode9->Text = L"Knoten27";
			treeNode10->Name = L"Knoten28";
			treeNode10->Text = L"Knoten28";
			treeNode11->Name = L"Knoten29";
			treeNode11->Text = L"Knoten29";
			treeNode12->Name = L"Knoten30";
			treeNode12->Text = L"Knoten30";
			treeNode13->Name = L"Knoten31";
			treeNode13->Text = L"Knoten31";
			treeNode14->Name = L"Knoten32";
			treeNode14->Text = L"Knoten32";
			treeNode15->Name = L"Knoten33";
			treeNode15->Text = L"Knoten33";
			treeNode16->Name = L"Knoten34";
			treeNode16->Text = L"Knoten34";
			treeNode17->Name = L"Knoten23";
			treeNode17->Text = L"Knoten23";
			treeNode18->Name = L"Knoten24";
			treeNode18->Text = L"Knoten24";
			treeNode19->Name = L"Knoten25";
			treeNode19->Text = L"Knoten25";
			treeNode20->Name = L"Knoten17";
			treeNode20->Text = L"Knoten17";
			treeNode21->Name = L"Knoten18";
			treeNode21->Text = L"Knoten18";
			treeNode22->Name = L"Knoten19";
			treeNode22->Text = L"Knoten19";
			treeNode23->Name = L"Knoten20";
			treeNode23->Text = L"Knoten20";
			treeNode24->Name = L"Knoten10";
			treeNode24->Text = L"Knoten10";
			treeNode25->Name = L"Knoten11";
			treeNode25->Text = L"Knoten11";
			treeNode26->Name = L"Knoten12";
			treeNode26->Text = L"Knoten12";
			treeNode27->Name = L"Knoten13";
			treeNode27->Text = L"Knoten13";
			treeNode28->Name = L"Knoten14";
			treeNode28->Text = L"Knoten14";
			treeNode29->Name = L"Knoten0";
			treeNode29->Text = L"Knoten0";
			this->treeView1->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode29 });
			this->treeView1->Size = System::Drawing::Size(422, 310);
			this->treeView1->TabIndex = 3;
			this->treeView1->ItemDrag += gcnew System::Windows::Forms::ItemDragEventHandler(this, &MainForm::treeView1_ItemDrag);
			this->treeView1->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &MainForm::treeView1_AfterSelect);
			this->treeView1->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::treeView1_DragDrop);
			this->treeView1->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::treeView1_DragEnter);
			this->treeView1->DragOver += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::treeView1_DragOver);
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->btnDriveInfo);
			this->panel7->Controls->Add(this->btnWalkTreeViewRecursive);
			this->panel7->Controls->Add(this->btnRecursion);
			this->panel7->Controls->Add(this->btnReadDirectories);
			this->panel7->Controls->Add(this->btnRemoveTreeNOde);
			this->panel7->Controls->Add(this->btnAddTreeNodeToTreeView);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel7->Location = System::Drawing::Point(431, 319);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(422, 251);
			this->panel7->TabIndex = 4;
			// 
			// btnDriveInfo
			// 
			this->btnDriveInfo->Location = System::Drawing::Point(3, 119);
			this->btnDriveInfo->Name = L"btnDriveInfo";
			this->btnDriveInfo->Size = System::Drawing::Size(103, 23);
			this->btnDriveInfo->TabIndex = 5;
			this->btnDriveInfo->Text = L"DriveInfo";
			this->btnDriveInfo->UseVisualStyleBackColor = true;
			this->btnDriveInfo->Click += gcnew System::EventHandler(this, &MainForm::btnDriveInfo_Click);
			// 
			// btnWalkTreeViewRecursive
			// 
			this->btnWalkTreeViewRecursive->Location = System::Drawing::Point(3, 72);
			this->btnWalkTreeViewRecursive->Name = L"btnWalkTreeViewRecursive";
			this->btnWalkTreeViewRecursive->Size = System::Drawing::Size(103, 23);
			this->btnWalkTreeViewRecursive->TabIndex = 4;
			this->btnWalkTreeViewRecursive->Text = L"Tree Recursive";
			this->btnWalkTreeViewRecursive->UseVisualStyleBackColor = true;
			this->btnWalkTreeViewRecursive->Click += gcnew System::EventHandler(this, &MainForm::btnWalkTreeViewRecursive_Click);
			// 
			// btnRecursion
			// 
			this->btnRecursion->Location = System::Drawing::Point(220, 3);
			this->btnRecursion->Name = L"btnRecursion";
			this->btnRecursion->Size = System::Drawing::Size(88, 23);
			this->btnRecursion->TabIndex = 3;
			this->btnRecursion->Text = L"recursion";
			this->btnRecursion->UseVisualStyleBackColor = true;
			this->btnRecursion->Click += gcnew System::EventHandler(this, &MainForm::btnRecursion_Click);
			// 
			// btnReadDirectories
			// 
			this->btnReadDirectories->Location = System::Drawing::Point(97, 32);
			this->btnReadDirectories->Name = L"btnReadDirectories";
			this->btnReadDirectories->Size = System::Drawing::Size(103, 23);
			this->btnReadDirectories->TabIndex = 2;
			this->btnReadDirectories->Text = L"Read Directrories";
			this->btnReadDirectories->UseVisualStyleBackColor = true;
			this->btnReadDirectories->Click += gcnew System::EventHandler(this, &MainForm::btnReadDirectories_Click);
			// 
			// btnRemoveTreeNOde
			// 
			this->btnRemoveTreeNOde->Location = System::Drawing::Point(97, 3);
			this->btnRemoveTreeNOde->Name = L"btnRemoveTreeNOde";
			this->btnRemoveTreeNOde->Size = System::Drawing::Size(117, 23);
			this->btnRemoveTreeNOde->TabIndex = 1;
			this->btnRemoveTreeNOde->Text = L"Remove TreeNode";
			this->btnRemoveTreeNOde->UseVisualStyleBackColor = true;
			this->btnRemoveTreeNOde->Click += gcnew System::EventHandler(this, &MainForm::btnRemoveTreeNOde_Click);
			// 
			// btnAddTreeNodeToTreeView
			// 
			this->btnAddTreeNodeToTreeView->Location = System::Drawing::Point(3, 3);
			this->btnAddTreeNodeToTreeView->Name = L"btnAddTreeNodeToTreeView";
			this->btnAddTreeNodeToTreeView->Size = System::Drawing::Size(88, 23);
			this->btnAddTreeNodeToTreeView->TabIndex = 0;
			this->btnAddTreeNodeToTreeView->Text = L"Add TreeNode";
			this->btnAddTreeNodeToTreeView->UseVisualStyleBackColor = true;
			this->btnAddTreeNodeToTreeView->Click += gcnew System::EventHandler(this, &MainForm::btnAddTreeNodeToTreeView_Click);
			// 
			// tabPage7
			// 
			this->tabPage7->Controls->Add(this->tableLayoutPanel6);
			this->tabPage7->Location = System::Drawing::Point(4, 22);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Padding = System::Windows::Forms::Padding(3);
			this->tabPage7->Size = System::Drawing::Size(862, 579);
			this->tabPage7->TabIndex = 6;
			this->tabPage7->Text = L"Explorer";
			this->tabPage7->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 2;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				49.41589F)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50.58411F)));
			this->tableLayoutPanel6->Controls->Add(this->trvDirectories, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->lsvFiles, 1, 0);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 1;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(856, 573);
			this->tableLayoutPanel6->TabIndex = 0;
			// 
			// trvDirectories
			// 
			this->trvDirectories->Dock = System::Windows::Forms::DockStyle::Fill;
			this->trvDirectories->Location = System::Drawing::Point(3, 3);
			this->trvDirectories->Name = L"trvDirectories";
			this->trvDirectories->Size = System::Drawing::Size(417, 567);
			this->trvDirectories->TabIndex = 0;
			this->trvDirectories->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &MainForm::trvDirectories_AfterSelect);
			// 
			// lsvFiles
			// 
			this->lsvFiles->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lsvFiles->Location = System::Drawing::Point(426, 3);
			this->lsvFiles->Name = L"lsvFiles";
			this->lsvFiles->Size = System::Drawing::Size(427, 567);
			this->lsvFiles->TabIndex = 1;
			this->lsvFiles->UseCompatibleStateImageBehavior = false;
			// 
			// tabPage8
			// 
			this->tabPage8->Controls->Add(this->panel9);
			this->tabPage8->Location = System::Drawing::Point(4, 22);
			this->tabPage8->Name = L"tabPage8";
			this->tabPage8->Padding = System::Windows::Forms::Padding(3);
			this->tabPage8->Size = System::Drawing::Size(862, 579);
			this->tabPage8->TabIndex = 7;
			this->tabPage8->Text = L"ListView";
			this->tabPage8->UseVisualStyleBackColor = true;
			// 
			// panel9
			// 
			this->panel9->Controls->Add(this->lsvTest);
			this->panel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel9->Location = System::Drawing::Point(3, 3);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(856, 573);
			this->panel9->TabIndex = 0;
			// 
			// lsvTest
			// 
			this->lsvTest->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->columnHeader1, this->columnHeader2 });
			this->lsvTest->Location = System::Drawing::Point(48, 35);
			this->lsvTest->Name = L"lsvTest";
			this->lsvTest->Size = System::Drawing::Size(488, 320);
			this->lsvTest->TabIndex = 0;
			this->lsvTest->UseCompatibleStateImageBehavior = false;
			this->lsvTest->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Name";
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Size";
			// 
			// tabPage9
			// 
			this->tabPage9->Controls->Add(this->tableLayoutPanel7);
			this->tabPage9->Location = System::Drawing::Point(4, 22);
			this->tabPage9->Name = L"tabPage9";
			this->tabPage9->Padding = System::Windows::Forms::Padding(3);
			this->tabPage9->Size = System::Drawing::Size(862, 579);
			this->tabPage9->TabIndex = 8;
			this->tabPage9->Text = L"Explorer";
			this->tabPage9->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel7
			// 
			this->tableLayoutPanel7->ColumnCount = 2;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				49.41589F)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50.58411F)));
			this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel7->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 1;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(856, 573);
			this->tableLayoutPanel7->TabIndex = 1;
			// 
			// tabPage10
			// 
			this->tabPage10->Controls->Add(this->tableLayoutPanel8);
			this->tabPage10->Location = System::Drawing::Point(4, 22);
			this->tabPage10->Name = L"tabPage10";
			this->tabPage10->Padding = System::Windows::Forms::Padding(3);
			this->tabPage10->Size = System::Drawing::Size(862, 579);
			this->tabPage10->TabIndex = 9;
			this->tabPage10->Text = L"Web";
			this->tabPage10->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel8
			// 
			this->tableLayoutPanel8->ColumnCount = 2;
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel8->Controls->Add(this->panel10, 0, 1);
			this->tableLayoutPanel8->Controls->Add(this->txtWeb, 1, 0);
			this->tableLayoutPanel8->Controls->Add(this->panel11, 1, 1);
			this->tableLayoutPanel8->Controls->Add(this->panel12, 0, 0);
			this->tableLayoutPanel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel8->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
			this->tableLayoutPanel8->RowCount = 2;
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 31.25F)));
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 68.75F)));
			this->tableLayoutPanel8->Size = System::Drawing::Size(856, 573);
			this->tableLayoutPanel8->TabIndex = 2;
			// 
			// panel10
			// 
			this->panel10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel10->Location = System::Drawing::Point(3, 182);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(422, 388);
			this->panel10->TabIndex = 2;
			// 
			// txtWeb
			// 
			this->txtWeb->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtWeb->Location = System::Drawing::Point(431, 3);
			this->txtWeb->Multiline = true;
			this->txtWeb->Name = L"txtWeb";
			this->txtWeb->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->txtWeb->Size = System::Drawing::Size(422, 173);
			this->txtWeb->TabIndex = 0;
			// 
			// panel11
			// 
			this->panel11->Controls->Add(this->webBrowser1);
			this->panel11->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel11->Location = System::Drawing::Point(431, 182);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(422, 388);
			this->panel11->TabIndex = 4;
			// 
			// webBrowser1
			// 
			this->webBrowser1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->webBrowser1->Location = System::Drawing::Point(0, 0);
			this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser1->Name = L"webBrowser1";
			this->webBrowser1->Size = System::Drawing::Size(422, 388);
			this->webBrowser1->TabIndex = 0;
			// 
			// panel12
			// 
			this->panel12->Controls->Add(this->btnSendMail);
			this->panel12->Controls->Add(this->btnFTPDownloadBinary);
			this->panel12->Controls->Add(this->btnFTPDownload);
			this->panel12->Controls->Add(this->btnFTPWebrequestDirectory);
			this->panel12->Controls->Add(this->txtURL);
			this->panel12->Controls->Add(this->btnWebRequest);
			this->panel12->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel12->Location = System::Drawing::Point(3, 3);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(422, 173);
			this->panel12->TabIndex = 5;
			// 
			// btnSendMail
			// 
			this->btnSendMail->Location = System::Drawing::Point(146, 76);
			this->btnSendMail->Name = L"btnSendMail";
			this->btnSendMail->Size = System::Drawing::Size(130, 23);
			this->btnSendMail->TabIndex = 11;
			this->btnSendMail->Text = L"Send Mail";
			this->btnSendMail->UseVisualStyleBackColor = true;
			this->btnSendMail->Click += gcnew System::EventHandler(this, &MainForm::btnSendMail_Click);
			// 
			// btnFTPDownloadBinary
			// 
			this->btnFTPDownloadBinary->Location = System::Drawing::Point(3, 131);
			this->btnFTPDownloadBinary->Name = L"btnFTPDownloadBinary";
			this->btnFTPDownloadBinary->Size = System::Drawing::Size(130, 23);
			this->btnFTPDownloadBinary->TabIndex = 10;
			this->btnFTPDownloadBinary->Text = L"FTP Download Bin";
			this->btnFTPDownloadBinary->UseVisualStyleBackColor = true;
			this->btnFTPDownloadBinary->Click += gcnew System::EventHandler(this, &MainForm::btnFTPDownloadBinary_Click);
			// 
			// btnFTPDownload
			// 
			this->btnFTPDownload->Location = System::Drawing::Point(3, 102);
			this->btnFTPDownload->Name = L"btnFTPDownload";
			this->btnFTPDownload->Size = System::Drawing::Size(130, 23);
			this->btnFTPDownload->TabIndex = 9;
			this->btnFTPDownload->Text = L"FTP Download";
			this->btnFTPDownload->UseVisualStyleBackColor = true;
			this->btnFTPDownload->Click += gcnew System::EventHandler(this, &MainForm::btnFTPDownload_Click);
			// 
			// btnFTPWebrequestDirectory
			// 
			this->btnFTPWebrequestDirectory->Location = System::Drawing::Point(3, 73);
			this->btnFTPWebrequestDirectory->Name = L"btnFTPWebrequestDirectory";
			this->btnFTPWebrequestDirectory->Size = System::Drawing::Size(130, 23);
			this->btnFTPWebrequestDirectory->TabIndex = 8;
			this->btnFTPWebrequestDirectory->Text = L"FTP Directory";
			this->btnFTPWebrequestDirectory->UseVisualStyleBackColor = true;
			this->btnFTPWebrequestDirectory->Click += gcnew System::EventHandler(this, &MainForm::btnFTPWebrequestDirectory_Click);
			// 
			// txtURL
			// 
			this->txtURL->Location = System::Drawing::Point(84, 5);
			this->txtURL->Name = L"txtURL";
			this->txtURL->Size = System::Drawing::Size(335, 20);
			this->txtURL->TabIndex = 7;
			this->txtURL->Text = L"http://www.zeit.de/index";
			// 
			// btnWebRequest
			// 
			this->btnWebRequest->Location = System::Drawing::Point(3, 3);
			this->btnWebRequest->Name = L"btnWebRequest";
			this->btnWebRequest->Size = System::Drawing::Size(75, 23);
			this->btnWebRequest->TabIndex = 6;
			this->btnWebRequest->Text = L"Go";
			this->btnWebRequest->UseVisualStyleBackColor = true;
			this->btnWebRequest->Click += gcnew System::EventHandler(this, &MainForm::btnWebRequest_Click);
			// 
			// tabPage11
			// 
			this->tabPage11->Controls->Add(this->tableLayoutPanel9);
			this->tabPage11->Location = System::Drawing::Point(4, 22);
			this->tabPage11->Name = L"tabPage11";
			this->tabPage11->Padding = System::Windows::Forms::Padding(3);
			this->tabPage11->Size = System::Drawing::Size(862, 579);
			this->tabPage11->TabIndex = 10;
			this->tabPage11->Text = L"XML";
			this->tabPage11->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel9
			// 
			this->tableLayoutPanel9->ColumnCount = 2;
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel9->Controls->Add(this->panel13, 0, 1);
			this->tableLayoutPanel9->Controls->Add(this->txtXMLOutput, 1, 0);
			this->tableLayoutPanel9->Controls->Add(this->panel14, 1, 1);
			this->tableLayoutPanel9->Controls->Add(this->panel15, 0, 0);
			this->tableLayoutPanel9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel9->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel9->Name = L"tableLayoutPanel9";
			this->tableLayoutPanel9->RowCount = 2;
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 31.25F)));
			this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 68.75F)));
			this->tableLayoutPanel9->Size = System::Drawing::Size(856, 573);
			this->tableLayoutPanel9->TabIndex = 3;
			// 
			// panel13
			// 
			this->panel13->Controls->Add(this->btnDoDllMethod);
			this->panel13->Controls->Add(this->btnLoadFromRegistry);
			this->panel13->Controls->Add(this->btnWriteToRegistry);
			this->panel13->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel13->Location = System::Drawing::Point(3, 182);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(422, 388);
			this->panel13->TabIndex = 2;
			// 
			// btnDoDllMethod
			// 
			this->btnDoDllMethod->Location = System::Drawing::Point(331, 3);
			this->btnDoDllMethod->Name = L"btnDoDllMethod";
			this->btnDoDllMethod->Size = System::Drawing::Size(88, 23);
			this->btnDoDllMethod->TabIndex = 16;
			this->btnDoDllMethod->Text = L"Call Dll";
			this->btnDoDllMethod->UseVisualStyleBackColor = true;
			this->btnDoDllMethod->Click += gcnew System::EventHandler(this, &MainForm::btnDoDllMethod_Click);
			// 
			// btnLoadFromRegistry
			// 
			this->btnLoadFromRegistry->Location = System::Drawing::Point(97, 3);
			this->btnLoadFromRegistry->Name = L"btnLoadFromRegistry";
			this->btnLoadFromRegistry->Size = System::Drawing::Size(88, 23);
			this->btnLoadFromRegistry->TabIndex = 15;
			this->btnLoadFromRegistry->Text = L"Load Registry";
			this->btnLoadFromRegistry->UseVisualStyleBackColor = true;
			this->btnLoadFromRegistry->Click += gcnew System::EventHandler(this, &MainForm::btnLoadFromRegistry_Click);
			// 
			// btnWriteToRegistry
			// 
			this->btnWriteToRegistry->Location = System::Drawing::Point(3, 3);
			this->btnWriteToRegistry->Name = L"btnWriteToRegistry";
			this->btnWriteToRegistry->Size = System::Drawing::Size(88, 23);
			this->btnWriteToRegistry->TabIndex = 14;
			this->btnWriteToRegistry->Text = L"Write Registry";
			this->btnWriteToRegistry->UseVisualStyleBackColor = true;
			this->btnWriteToRegistry->Click += gcnew System::EventHandler(this, &MainForm::btnWriteToRegistry_Click);
			// 
			// txtXMLOutput
			// 
			this->txtXMLOutput->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtXMLOutput->Location = System::Drawing::Point(431, 3);
			this->txtXMLOutput->Multiline = true;
			this->txtXMLOutput->Name = L"txtXMLOutput";
			this->txtXMLOutput->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->txtXMLOutput->Size = System::Drawing::Size(422, 173);
			this->txtXMLOutput->TabIndex = 0;
			// 
			// panel14
			// 
			this->panel14->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel14->Location = System::Drawing::Point(431, 182);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(422, 388);
			this->panel14->TabIndex = 4;
			// 
			// panel15
			// 
			this->panel15->Controls->Add(this->btnGetHighestKundeId);
			this->panel15->Controls->Add(this->btnCreateKundenverzeichnisXmlDocument);
			this->panel15->Controls->Add(this->btnUpdateKunde);
			this->panel15->Controls->Add(this->btnDeleteKundeFromVerzeichnis);
			this->panel15->Controls->Add(this->btnReadKundeFromKundenVverzeichnisXml);
			this->panel15->Controls->Add(this->btnCreateClassKundeXmlNode);
			this->panel15->Controls->Add(this->btnCreateKundeNode);
			this->panel15->Controls->Add(this->btnLoadXMLDoc);
			this->panel15->Controls->Add(this->btnCreateXMLDocument);
			this->panel15->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel15->Location = System::Drawing::Point(3, 3);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(422, 173);
			this->panel15->TabIndex = 5;
			// 
			// btnGetHighestKundeId
			// 
			this->btnGetHighestKundeId->Location = System::Drawing::Point(153, 61);
			this->btnGetHighestKundeId->Name = L"btnGetHighestKundeId";
			this->btnGetHighestKundeId->Size = System::Drawing::Size(90, 23);
			this->btnGetHighestKundeId->TabIndex = 14;
			this->btnGetHighestKundeId->Text = L"Highest Id";
			this->btnGetHighestKundeId->UseVisualStyleBackColor = true;
			this->btnGetHighestKundeId->Click += gcnew System::EventHandler(this, &MainForm::btnGetHighestKundeId_Click);
			// 
			// btnCreateKundenverzeichnisXmlDocument
			// 
			this->btnCreateKundenverzeichnisXmlDocument->Location = System::Drawing::Point(153, 32);
			this->btnCreateKundenverzeichnisXmlDocument->Name = L"btnCreateKundenverzeichnisXmlDocument";
			this->btnCreateKundenverzeichnisXmlDocument->Size = System::Drawing::Size(140, 23);
			this->btnCreateKundenverzeichnisXmlDocument->TabIndex = 13;
			this->btnCreateKundenverzeichnisXmlDocument->Text = L"Create Kundenverzeichnis";
			this->btnCreateKundenverzeichnisXmlDocument->UseVisualStyleBackColor = true;
			this->btnCreateKundenverzeichnisXmlDocument->Click += gcnew System::EventHandler(this, &MainForm::btnCreateKundenverzeichnisXmlDocument_Click);
			// 
			// btnUpdateKunde
			// 
			this->btnUpdateKunde->Location = System::Drawing::Point(153, 3);
			this->btnUpdateKunde->Name = L"btnUpdateKunde";
			this->btnUpdateKunde->Size = System::Drawing::Size(118, 23);
			this->btnUpdateKunde->TabIndex = 12;
			this->btnUpdateKunde->Text = L"Update Kunde XML";
			this->btnUpdateKunde->UseVisualStyleBackColor = true;
			this->btnUpdateKunde->Click += gcnew System::EventHandler(this, &MainForm::btnUpdateKunde_Click);
			// 
			// btnDeleteKundeFromVerzeichnis
			// 
			this->btnDeleteKundeFromVerzeichnis->Location = System::Drawing::Point(3, 148);
			this->btnDeleteKundeFromVerzeichnis->Name = L"btnDeleteKundeFromVerzeichnis";
			this->btnDeleteKundeFromVerzeichnis->Size = System::Drawing::Size(118, 23);
			this->btnDeleteKundeFromVerzeichnis->TabIndex = 11;
			this->btnDeleteKundeFromVerzeichnis->Text = L"Delete Kunde XML";
			this->btnDeleteKundeFromVerzeichnis->UseVisualStyleBackColor = true;
			this->btnDeleteKundeFromVerzeichnis->Click += gcnew System::EventHandler(this, &MainForm::btnDeleteKundeFromVerzeichnis_Click);
			// 
			// btnReadKundeFromKundenVverzeichnisXml
			// 
			this->btnReadKundeFromKundenVverzeichnisXml->Location = System::Drawing::Point(3, 119);
			this->btnReadKundeFromKundenVverzeichnisXml->Name = L"btnReadKundeFromKundenVverzeichnisXml";
			this->btnReadKundeFromKundenVverzeichnisXml->Size = System::Drawing::Size(118, 23);
			this->btnReadKundeFromKundenVverzeichnisXml->TabIndex = 10;
			this->btnReadKundeFromKundenVverzeichnisXml->Text = L"Read Kunde XML";
			this->btnReadKundeFromKundenVverzeichnisXml->UseVisualStyleBackColor = true;
			this->btnReadKundeFromKundenVverzeichnisXml->Click += gcnew System::EventHandler(this, &MainForm::btnReadKundeFromKundenVverzeichnisXml_Click);
			// 
			// btnCreateClassKundeXmlNode
			// 
			this->btnCreateClassKundeXmlNode->Location = System::Drawing::Point(3, 90);
			this->btnCreateClassKundeXmlNode->Name = L"btnCreateClassKundeXmlNode";
			this->btnCreateClassKundeXmlNode->Size = System::Drawing::Size(118, 23);
			this->btnCreateClassKundeXmlNode->TabIndex = 9;
			this->btnCreateClassKundeXmlNode->Text = L"Class Kunde Node";
			this->btnCreateClassKundeXmlNode->UseVisualStyleBackColor = true;
			this->btnCreateClassKundeXmlNode->Click += gcnew System::EventHandler(this, &MainForm::btnCreateClassKundeXmlNode_Click);
			// 
			// btnCreateKundeNode
			// 
			this->btnCreateKundeNode->Location = System::Drawing::Point(3, 61);
			this->btnCreateKundeNode->Name = L"btnCreateKundeNode";
			this->btnCreateKundeNode->Size = System::Drawing::Size(118, 23);
			this->btnCreateKundeNode->TabIndex = 8;
			this->btnCreateKundeNode->Text = L"Create Kunde Node";
			this->btnCreateKundeNode->UseVisualStyleBackColor = true;
			this->btnCreateKundeNode->Click += gcnew System::EventHandler(this, &MainForm::btnCreateKundeNode_Click);
			// 
			// btnLoadXMLDoc
			// 
			this->btnLoadXMLDoc->Location = System::Drawing::Point(3, 32);
			this->btnLoadXMLDoc->Name = L"btnLoadXMLDoc";
			this->btnLoadXMLDoc->Size = System::Drawing::Size(105, 23);
			this->btnLoadXMLDoc->TabIndex = 7;
			this->btnLoadXMLDoc->Text = L"Load XMLDoc";
			this->btnLoadXMLDoc->UseVisualStyleBackColor = true;
			this->btnLoadXMLDoc->Click += gcnew System::EventHandler(this, &MainForm::btnLoadXMLDoc_Click);
			// 
			// btnCreateXMLDocument
			// 
			this->btnCreateXMLDocument->Location = System::Drawing::Point(3, 3);
			this->btnCreateXMLDocument->Name = L"btnCreateXMLDocument";
			this->btnCreateXMLDocument->Size = System::Drawing::Size(105, 23);
			this->btnCreateXMLDocument->TabIndex = 6;
			this->btnCreateXMLDocument->Text = L"Create XMLDoc";
			this->btnCreateXMLDocument->UseVisualStyleBackColor = true;
			this->btnCreateXMLDocument->Click += gcnew System::EventHandler(this, &MainForm::btnCreateXMLDocument_Click);
			// 
			// tabPage12
			// 
			this->tabPage12->Controls->Add(this->tableLayoutPanel10);
			this->tabPage12->Location = System::Drawing::Point(4, 22);
			this->tabPage12->Name = L"tabPage12";
			this->tabPage12->Padding = System::Windows::Forms::Padding(3);
			this->tabPage12->Size = System::Drawing::Size(862, 579);
			this->tabPage12->TabIndex = 11;
			this->tabPage12->Text = L"SQL";
			this->tabPage12->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel10
			// 
			this->tableLayoutPanel10->ColumnCount = 2;
			this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				42.87383F)));
			this->tableLayoutPanel10->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				57.12617F)));
			this->tableLayoutPanel10->Controls->Add(this->panel16, 0, 1);
			this->tableLayoutPanel10->Controls->Add(this->txtSQLOutput, 1, 0);
			this->tableLayoutPanel10->Controls->Add(this->panel17, 1, 1);
			this->tableLayoutPanel10->Controls->Add(this->panel18, 0, 0);
			this->tableLayoutPanel10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel10->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel10->Name = L"tableLayoutPanel10";
			this->tableLayoutPanel10->RowCount = 2;
			this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 65.45139F)));
			this->tableLayoutPanel10->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 34.54861F)));
			this->tableLayoutPanel10->Size = System::Drawing::Size(856, 573);
			this->tableLayoutPanel10->TabIndex = 4;
			// 
			// panel16
			// 
			this->panel16->Controls->Add(this->lsvProdukte);
			this->panel16->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel16->Location = System::Drawing::Point(3, 378);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(360, 192);
			this->panel16->TabIndex = 2;
			// 
			// lsvProdukte
			// 
			this->lsvProdukte->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->columnHeader11,
					this->columnHeader12, this->columnHeader13, this->columnHeader14, this->columnHeader15, this->columnHeader16
			});
			this->lsvProdukte->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lsvProdukte->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(1) { listViewItem1 });
			this->lsvProdukte->Location = System::Drawing::Point(0, 0);
			this->lsvProdukte->Name = L"lsvProdukte";
			this->lsvProdukte->Size = System::Drawing::Size(360, 192);
			this->lsvProdukte->TabIndex = 1;
			this->lsvProdukte->UseCompatibleStateImageBehavior = false;
			this->lsvProdukte->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader11
			// 
			this->columnHeader11->Text = L"id";
			// 
			// columnHeader12
			// 
			this->columnHeader12->Text = L"name";
			// 
			// columnHeader13
			// 
			this->columnHeader13->Text = L"beschreibung";
			// 
			// columnHeader14
			// 
			this->columnHeader14->Text = L"ekpreis";
			// 
			// columnHeader15
			// 
			this->columnHeader15->Text = L"vkpreis";
			// 
			// columnHeader16
			// 
			this->columnHeader16->Text = L"lagerbestand";
			// 
			// txtSQLOutput
			// 
			this->txtSQLOutput->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtSQLOutput->Location = System::Drawing::Point(369, 3);
			this->txtSQLOutput->Multiline = true;
			this->txtSQLOutput->Name = L"txtSQLOutput";
			this->txtSQLOutput->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->txtSQLOutput->Size = System::Drawing::Size(484, 369);
			this->txtSQLOutput->TabIndex = 0;
			// 
			// panel17
			// 
			this->panel17->Controls->Add(this->lsvKunden);
			this->panel17->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel17->Location = System::Drawing::Point(369, 378);
			this->panel17->Name = L"panel17";
			this->panel17->Size = System::Drawing::Size(484, 192);
			this->panel17->TabIndex = 4;
			// 
			// lsvKunden
			// 
			this->lsvKunden->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(8) {
				this->columnHeader3, this->columnHeader4,
					this->columnHeader5, this->columnHeader6, this->columnHeader7, this->columnHeader8, this->columnHeader9, this->columnHeader10
			});
			this->lsvKunden->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lsvKunden->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(1) { listViewItem2 });
			this->lsvKunden->Location = System::Drawing::Point(0, 0);
			this->lsvKunden->Name = L"lsvKunden";
			this->lsvKunden->Size = System::Drawing::Size(484, 192);
			this->lsvKunden->TabIndex = 0;
			this->lsvKunden->UseCompatibleStateImageBehavior = false;
			this->lsvKunden->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"id";
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"vorname";
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"nachname";
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"strasse";
			// 
			// columnHeader7
			// 
			this->columnHeader7->Text = L"plz";
			// 
			// columnHeader8
			// 
			this->columnHeader8->Text = L"ort";
			// 
			// columnHeader9
			// 
			this->columnHeader9->Text = L"umsatz";
			// 
			// columnHeader10
			// 
			this->columnHeader10->Text = L"benutzername";
			// 
			// panel18
			// 
			this->panel18->Controls->Add(this->cmbRechnungsids);
			this->panel18->Controls->Add(this->btnShowRechnung);
			this->panel18->Controls->Add(this->btnCreateRechnungspositionen);
			this->panel18->Controls->Add(this->btnCreateRechnung);
			this->panel18->Controls->Add(this->btnGetLastInsertedId);
			this->panel18->Controls->Add(this->btnFillProduktListView);
			this->panel18->Controls->Add(this->btnFillKundenListView);
			this->panel18->Controls->Add(this->btnUpdateKundeEntity);
			this->panel18->Controls->Add(this->txtSelectKundeId);
			this->panel18->Controls->Add(this->btnSelectKundeEntity);
			this->panel18->Controls->Add(this->btnDeleteKundeEntity);
			this->panel18->Controls->Add(this->txtDeleteKundeId);
			this->panel18->Controls->Add(this->btnInsertKundeEntity);
			this->panel18->Controls->Add(this->txtKundeUmsatz);
			this->panel18->Controls->Add(this->txtKundeBenutzername);
			this->panel18->Controls->Add(this->txtKundeOrt);
			this->panel18->Controls->Add(this->txtKundePlz);
			this->panel18->Controls->Add(this->txtKundeStrasse);
			this->panel18->Controls->Add(this->txtKundeNachname);
			this->panel18->Controls->Add(this->txtKundeVorname);
			this->panel18->Controls->Add(this->btnSelectKunden);
			this->panel18->Controls->Add(this->btnUpdateKundeDB);
			this->panel18->Controls->Add(this->btnDelete);
			this->panel18->Controls->Add(this->btnInsertKunde);
			this->panel18->Controls->Add(this->btnConnectDatabase);
			this->panel18->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel18->Location = System::Drawing::Point(3, 3);
			this->panel18->Name = L"panel18";
			this->panel18->Size = System::Drawing::Size(360, 369);
			this->panel18->TabIndex = 5;
			// 
			// cmbRechnungsids
			// 
			this->cmbRechnungsids->FormattingEnabled = true;
			this->cmbRechnungsids->Location = System::Drawing::Point(148, 294);
			this->cmbRechnungsids->Name = L"cmbRechnungsids";
			this->cmbRechnungsids->Size = System::Drawing::Size(62, 21);
			this->cmbRechnungsids->TabIndex = 24;
			this->cmbRechnungsids->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::cmbRechnungsids_SelectedIndexChanged);
			// 
			// btnShowRechnung
			// 
			this->btnShowRechnung->Location = System::Drawing::Point(4, 294);
			this->btnShowRechnung->Name = L"btnShowRechnung";
			this->btnShowRechnung->Size = System::Drawing::Size(138, 23);
			this->btnShowRechnung->TabIndex = 23;
			this->btnShowRechnung->Text = L"Rechnung anzeigen";
			this->btnShowRechnung->UseVisualStyleBackColor = true;
			this->btnShowRechnung->Click += gcnew System::EventHandler(this, &MainForm::btnShowRechnung_Click);
			// 
			// btnCreateRechnungspositionen
			// 
			this->btnCreateRechnungspositionen->Location = System::Drawing::Point(216, 294);
			this->btnCreateRechnungspositionen->Name = L"btnCreateRechnungspositionen";
			this->btnCreateRechnungspositionen->Size = System::Drawing::Size(138, 23);
			this->btnCreateRechnungspositionen->TabIndex = 22;
			this->btnCreateRechnungspositionen->Text = L"Create Rechnungspos.";
			this->btnCreateRechnungspositionen->UseVisualStyleBackColor = true;
			this->btnCreateRechnungspositionen->Click += gcnew System::EventHandler(this, &MainForm::btnCreateRechnungspositionen_Click);
			// 
			// btnCreateRechnung
			// 
			this->btnCreateRechnung->Location = System::Drawing::Point(216, 265);
			this->btnCreateRechnung->Name = L"btnCreateRechnung";
			this->btnCreateRechnung->Size = System::Drawing::Size(138, 23);
			this->btnCreateRechnung->TabIndex = 21;
			this->btnCreateRechnung->Text = L"Create Rechnung";
			this->btnCreateRechnung->UseVisualStyleBackColor = true;
			this->btnCreateRechnung->Click += gcnew System::EventHandler(this, &MainForm::btnCreateRechnung_Click);
			// 
			// btnGetLastInsertedId
			// 
			this->btnGetLastInsertedId->Location = System::Drawing::Point(216, 236);
			this->btnGetLastInsertedId->Name = L"btnGetLastInsertedId";
			this->btnGetLastInsertedId->Size = System::Drawing::Size(138, 23);
			this->btnGetLastInsertedId->TabIndex = 20;
			this->btnGetLastInsertedId->Text = L"Last Inserted Id";
			this->btnGetLastInsertedId->UseVisualStyleBackColor = true;
			this->btnGetLastInsertedId->Click += gcnew System::EventHandler(this, &MainForm::btnGetLastInsertedId_Click);
			// 
			// btnFillProduktListView
			// 
			this->btnFillProduktListView->Location = System::Drawing::Point(4, 265);
			this->btnFillProduktListView->Name = L"btnFillProduktListView";
			this->btnFillProduktListView->Size = System::Drawing::Size(138, 23);
			this->btnFillProduktListView->TabIndex = 19;
			this->btnFillProduktListView->Text = L"Fill Produktlistview";
			this->btnFillProduktListView->UseVisualStyleBackColor = true;
			this->btnFillProduktListView->Click += gcnew System::EventHandler(this, &MainForm::btnFillProduktListView_Click);
			// 
			// btnFillKundenListView
			// 
			this->btnFillKundenListView->Location = System::Drawing::Point(4, 236);
			this->btnFillKundenListView->Name = L"btnFillKundenListView";
			this->btnFillKundenListView->Size = System::Drawing::Size(138, 23);
			this->btnFillKundenListView->TabIndex = 18;
			this->btnFillKundenListView->Text = L"Fill Kundenlistview";
			this->btnFillKundenListView->UseVisualStyleBackColor = true;
			this->btnFillKundenListView->Click += gcnew System::EventHandler(this, &MainForm::btnFillKundenListView_Click);
			// 
			// btnUpdateKundeEntity
			// 
			this->btnUpdateKundeEntity->Location = System::Drawing::Point(94, 180);
			this->btnUpdateKundeEntity->Name = L"btnUpdateKundeEntity";
			this->btnUpdateKundeEntity->Size = System::Drawing::Size(116, 23);
			this->btnUpdateKundeEntity->TabIndex = 17;
			this->btnUpdateKundeEntity->Text = L"Update Kunde Entity";
			this->btnUpdateKundeEntity->UseVisualStyleBackColor = true;
			this->btnUpdateKundeEntity->Click += gcnew System::EventHandler(this, &MainForm::btnUpdateKundeEntity_Click);
			// 
			// txtSelectKundeId
			// 
			this->txtSelectKundeId->Location = System::Drawing::Point(234, 211);
			this->txtSelectKundeId->Name = L"txtSelectKundeId";
			this->txtSelectKundeId->Size = System::Drawing::Size(100, 20);
			this->txtSelectKundeId->TabIndex = 16;
			this->txtSelectKundeId->Text = L"5";
			// 
			// btnSelectKundeEntity
			// 
			this->btnSelectKundeEntity->Location = System::Drawing::Point(94, 209);
			this->btnSelectKundeEntity->Name = L"btnSelectKundeEntity";
			this->btnSelectKundeEntity->Size = System::Drawing::Size(116, 23);
			this->btnSelectKundeEntity->TabIndex = 15;
			this->btnSelectKundeEntity->Text = L"Select Kunde Enetity";
			this->btnSelectKundeEntity->UseVisualStyleBackColor = true;
			this->btnSelectKundeEntity->Click += gcnew System::EventHandler(this, &MainForm::btnSelectKundeEntity_Click);
			// 
			// btnDeleteKundeEntity
			// 
			this->btnDeleteKundeEntity->Location = System::Drawing::Point(94, 151);
			this->btnDeleteKundeEntity->Name = L"btnDeleteKundeEntity";
			this->btnDeleteKundeEntity->Size = System::Drawing::Size(123, 23);
			this->btnDeleteKundeEntity->TabIndex = 14;
			this->btnDeleteKundeEntity->Text = L"Delete Kunde Entity";
			this->btnDeleteKundeEntity->UseVisualStyleBackColor = true;
			this->btnDeleteKundeEntity->Click += gcnew System::EventHandler(this, &MainForm::btnDeleteKundeEntity_Click);
			// 
			// txtDeleteKundeId
			// 
			this->txtDeleteKundeId->Location = System::Drawing::Point(234, 153);
			this->txtDeleteKundeId->Name = L"txtDeleteKundeId";
			this->txtDeleteKundeId->Size = System::Drawing::Size(100, 20);
			this->txtDeleteKundeId->TabIndex = 13;
			this->txtDeleteKundeId->Text = L"5";
			// 
			// btnInsertKundeEntity
			// 
			this->btnInsertKundeEntity->Location = System::Drawing::Point(110, 33);
			this->btnInsertKundeEntity->Name = L"btnInsertKundeEntity";
			this->btnInsertKundeEntity->Size = System::Drawing::Size(107, 23);
			this->btnInsertKundeEntity->TabIndex = 12;
			this->btnInsertKundeEntity->Text = L"Insert Kunde Entity";
			this->btnInsertKundeEntity->UseVisualStyleBackColor = true;
			this->btnInsertKundeEntity->Click += gcnew System::EventHandler(this, &MainForm::btnInsertKundeEntity_Click);
			// 
			// txtKundeUmsatz
			// 
			this->txtKundeUmsatz->Location = System::Drawing::Point(4, 114);
			this->txtKundeUmsatz->Name = L"txtKundeUmsatz";
			this->txtKundeUmsatz->Size = System::Drawing::Size(100, 20);
			this->txtKundeUmsatz->TabIndex = 11;
			this->txtKundeUmsatz->Text = L"5647";
			// 
			// txtKundeBenutzername
			// 
			this->txtKundeBenutzername->Location = System::Drawing::Point(216, 88);
			this->txtKundeBenutzername->Name = L"txtKundeBenutzername";
			this->txtKundeBenutzername->Size = System::Drawing::Size(100, 20);
			this->txtKundeBenutzername->TabIndex = 10;
			this->txtKundeBenutzername->Text = L"Haenschen";
			// 
			// txtKundeOrt
			// 
			this->txtKundeOrt->Location = System::Drawing::Point(110, 88);
			this->txtKundeOrt->Name = L"txtKundeOrt";
			this->txtKundeOrt->Size = System::Drawing::Size(100, 20);
			this->txtKundeOrt->TabIndex = 9;
			this->txtKundeOrt->Text = L"Entenhausen";
			// 
			// txtKundePlz
			// 
			this->txtKundePlz->Location = System::Drawing::Point(4, 88);
			this->txtKundePlz->Name = L"txtKundePlz";
			this->txtKundePlz->Size = System::Drawing::Size(100, 20);
			this->txtKundePlz->TabIndex = 8;
			this->txtKundePlz->Text = L"45674";
			// 
			// txtKundeStrasse
			// 
			this->txtKundeStrasse->Location = System::Drawing::Point(216, 62);
			this->txtKundeStrasse->Name = L"txtKundeStrasse";
			this->txtKundeStrasse->Size = System::Drawing::Size(100, 20);
			this->txtKundeStrasse->TabIndex = 7;
			this->txtKundeStrasse->Text = L"Strasse 3";
			// 
			// txtKundeNachname
			// 
			this->txtKundeNachname->Location = System::Drawing::Point(110, 62);
			this->txtKundeNachname->Name = L"txtKundeNachname";
			this->txtKundeNachname->Size = System::Drawing::Size(100, 20);
			this->txtKundeNachname->TabIndex = 6;
			this->txtKundeNachname->Text = L"Dampf";
			// 
			// txtKundeVorname
			// 
			this->txtKundeVorname->Location = System::Drawing::Point(4, 62);
			this->txtKundeVorname->Name = L"txtKundeVorname";
			this->txtKundeVorname->Size = System::Drawing::Size(100, 20);
			this->txtKundeVorname->TabIndex = 5;
			this->txtKundeVorname->Text = L"Hans";
			// 
			// btnSelectKunden
			// 
			this->btnSelectKunden->Location = System::Drawing::Point(3, 209);
			this->btnSelectKunden->Name = L"btnSelectKunden";
			this->btnSelectKunden->Size = System::Drawing::Size(85, 23);
			this->btnSelectKunden->TabIndex = 4;
			this->btnSelectKunden->Text = L"Select Kunden";
			this->btnSelectKunden->UseVisualStyleBackColor = true;
			this->btnSelectKunden->Click += gcnew System::EventHandler(this, &MainForm::btnSelectKunden_Click);
			// 
			// btnUpdateKundeDB
			// 
			this->btnUpdateKundeDB->Location = System::Drawing::Point(3, 180);
			this->btnUpdateKundeDB->Name = L"btnUpdateKundeDB";
			this->btnUpdateKundeDB->Size = System::Drawing::Size(85, 23);
			this->btnUpdateKundeDB->TabIndex = 3;
			this->btnUpdateKundeDB->Text = L"Update Kunde";
			this->btnUpdateKundeDB->UseVisualStyleBackColor = true;
			this->btnUpdateKundeDB->Click += gcnew System::EventHandler(this, &MainForm::btnUpdateK_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(3, 151);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(85, 23);
			this->btnDelete->TabIndex = 2;
			this->btnDelete->Text = L"Delete Kunde";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &MainForm::btnDelete_Click);
			// 
			// btnInsertKunde
			// 
			this->btnInsertKunde->Location = System::Drawing::Point(3, 32);
			this->btnInsertKunde->Name = L"btnInsertKunde";
			this->btnInsertKunde->Size = System::Drawing::Size(85, 23);
			this->btnInsertKunde->TabIndex = 1;
			this->btnInsertKunde->Text = L"Insert Kunde";
			this->btnInsertKunde->UseVisualStyleBackColor = true;
			this->btnInsertKunde->Click += gcnew System::EventHandler(this, &MainForm::btnInsertKunde_Click);
			// 
			// btnConnectDatabase
			// 
			this->btnConnectDatabase->Location = System::Drawing::Point(3, 3);
			this->btnConnectDatabase->Name = L"btnConnectDatabase";
			this->btnConnectDatabase->Size = System::Drawing::Size(85, 23);
			this->btnConnectDatabase->TabIndex = 0;
			this->btnConnectDatabase->Text = L"Connect DB";
			this->btnConnectDatabase->UseVisualStyleBackColor = true;
			this->btnConnectDatabase->Click += gcnew System::EventHandler(this, &MainForm::btnConnectDatabase_Click);
			// 
			// tabPage13
			// 
			this->tabPage13->Controls->Add(this->tableLayoutPanel11);
			this->tabPage13->Location = System::Drawing::Point(4, 22);
			this->tabPage13->Name = L"tabPage13";
			this->tabPage13->Padding = System::Windows::Forms::Padding(3);
			this->tabPage13->Size = System::Drawing::Size(862, 579);
			this->tabPage13->TabIndex = 12;
			this->tabPage13->Text = L"Globalization";
			this->tabPage13->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel11
			// 
			this->tableLayoutPanel11->ColumnCount = 2;
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel11->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel11->Controls->Add(this->panel19, 0, 1);
			this->tableLayoutPanel11->Controls->Add(this->txtCulture, 1, 0);
			this->tableLayoutPanel11->Controls->Add(this->panel20, 1, 1);
			this->tableLayoutPanel11->Controls->Add(this->panel21, 0, 0);
			this->tableLayoutPanel11->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel11->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel11->Name = L"tableLayoutPanel11";
			this->tableLayoutPanel11->RowCount = 2;
			this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 51.13438F)));
			this->tableLayoutPanel11->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 48.86562F)));
			this->tableLayoutPanel11->Size = System::Drawing::Size(856, 573);
			this->tableLayoutPanel11->TabIndex = 3;
			// 
			// panel19
			// 
			this->panel19->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel19->Location = System::Drawing::Point(3, 295);
			this->panel19->Name = L"panel19";
			this->panel19->Size = System::Drawing::Size(422, 275);
			this->panel19->TabIndex = 2;
			// 
			// txtCulture
			// 
			this->txtCulture->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtCulture->Location = System::Drawing::Point(431, 3);
			this->txtCulture->Multiline = true;
			this->txtCulture->Name = L"txtCulture";
			this->txtCulture->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->txtCulture->Size = System::Drawing::Size(422, 286);
			this->txtCulture->TabIndex = 0;
			// 
			// panel20
			// 
			this->panel20->Controls->Add(this->webBrowser2);
			this->panel20->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel20->Location = System::Drawing::Point(431, 295);
			this->panel20->Name = L"panel20";
			this->panel20->Size = System::Drawing::Size(422, 275);
			this->panel20->TabIndex = 4;
			// 
			// webBrowser2
			// 
			this->webBrowser2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->webBrowser2->Location = System::Drawing::Point(0, 0);
			this->webBrowser2->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser2->Name = L"webBrowser2";
			this->webBrowser2->Size = System::Drawing::Size(422, 275);
			this->webBrowser2->TabIndex = 0;
			// 
			// panel21
			// 
			this->panel21->Controls->Add(this->btnReflect);
			this->panel21->Controls->Add(this->dateTimePicker2);
			this->panel21->Controls->Add(this->btnDateTimeCulture);
			this->panel21->Controls->Add(this->btnListCultures);
			this->panel21->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel21->Location = System::Drawing::Point(3, 3);
			this->panel21->Name = L"panel21";
			this->panel21->Size = System::Drawing::Size(422, 286);
			this->panel21->TabIndex = 5;
			// 
			// btnReflect
			// 
			this->btnReflect->Location = System::Drawing::Point(3, 103);
			this->btnReflect->Name = L"btnReflect";
			this->btnReflect->Size = System::Drawing::Size(75, 23);
			this->btnReflect->TabIndex = 3;
			this->btnReflect->Text = L"Reflect";
			this->btnReflect->UseVisualStyleBackColor = true;
			this->btnReflect->Click += gcnew System::EventHandler(this, &MainForm::btnReflect_Click);
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(3, 61);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker2->TabIndex = 2;
			this->dateTimePicker2->ValueChanged += gcnew System::EventHandler(this, &MainForm::dateTimePicker2_ValueChanged);
			// 
			// btnDateTimeCulture
			// 
			this->btnDateTimeCulture->Location = System::Drawing::Point(3, 32);
			this->btnDateTimeCulture->Name = L"btnDateTimeCulture";
			this->btnDateTimeCulture->Size = System::Drawing::Size(75, 23);
			this->btnDateTimeCulture->TabIndex = 1;
			this->btnDateTimeCulture->Text = L"DateTime";
			this->btnDateTimeCulture->UseVisualStyleBackColor = true;
			this->btnDateTimeCulture->Click += gcnew System::EventHandler(this, &MainForm::btnDateTimeCulture_Click);
			// 
			// btnListCultures
			// 
			this->btnListCultures->Location = System::Drawing::Point(3, 3);
			this->btnListCultures->Name = L"btnListCultures";
			this->btnListCultures->Size = System::Drawing::Size(75, 23);
			this->btnListCultures->TabIndex = 0;
			this->btnListCultures->Text = L"List Cultures";
			this->btnListCultures->UseVisualStyleBackColor = true;
			this->btnListCultures->Click += gcnew System::EventHandler(this, &MainForm::btnListCultures_Click);
			// 
			// tabPage14
			// 
			this->tabPage14->Controls->Add(this->tableLayoutPanel12);
			this->tabPage14->Location = System::Drawing::Point(4, 22);
			this->tabPage14->Name = L"tabPage14";
			this->tabPage14->Padding = System::Windows::Forms::Padding(3);
			this->tabPage14->Size = System::Drawing::Size(862, 579);
			this->tabPage14->TabIndex = 13;
			this->tabPage14->Text = L"SQLite";
			this->tabPage14->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel12
			// 
			this->tableLayoutPanel12->ColumnCount = 2;
			this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel12->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel12->Controls->Add(this->panel22, 0, 1);
			this->tableLayoutPanel12->Controls->Add(this->txtSQLite, 1, 0);
			this->tableLayoutPanel12->Controls->Add(this->panel23, 1, 1);
			this->tableLayoutPanel12->Controls->Add(this->panel24, 0, 0);
			this->tableLayoutPanel12->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel12->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel12->Name = L"tableLayoutPanel12";
			this->tableLayoutPanel12->RowCount = 2;
			this->tableLayoutPanel12->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 51.13438F)));
			this->tableLayoutPanel12->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 48.86562F)));
			this->tableLayoutPanel12->Size = System::Drawing::Size(856, 573);
			this->tableLayoutPanel12->TabIndex = 4;
			// 
			// panel22
			// 
			this->panel22->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel22->Location = System::Drawing::Point(3, 295);
			this->panel22->Name = L"panel22";
			this->panel22->Size = System::Drawing::Size(422, 275);
			this->panel22->TabIndex = 2;
			// 
			// txtSQLite
			// 
			this->txtSQLite->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtSQLite->Location = System::Drawing::Point(431, 3);
			this->txtSQLite->Multiline = true;
			this->txtSQLite->Name = L"txtSQLite";
			this->txtSQLite->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->txtSQLite->Size = System::Drawing::Size(422, 286);
			this->txtSQLite->TabIndex = 0;
			// 
			// panel23
			// 
			this->panel23->Controls->Add(this->webBrowser3);
			this->panel23->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel23->Location = System::Drawing::Point(431, 295);
			this->panel23->Name = L"panel23";
			this->panel23->Size = System::Drawing::Size(422, 275);
			this->panel23->TabIndex = 4;
			// 
			// webBrowser3
			// 
			this->webBrowser3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->webBrowser3->Location = System::Drawing::Point(0, 0);
			this->webBrowser3->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser3->Name = L"webBrowser3";
			this->webBrowser3->Size = System::Drawing::Size(422, 275);
			this->webBrowser3->TabIndex = 0;
			// 
			// panel24
			// 
			this->panel24->Controls->Add(this->btnGetLastInsertedSQLiteId);
			this->panel24->Controls->Add(this->btnReadSQLiteKunden);
			this->panel24->Controls->Add(this->btnInsertSQLiteKunde);
			this->panel24->Controls->Add(this->btnCreateSqliteTable);
			this->panel24->Controls->Add(this->btnSqliteCreate);
			this->panel24->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel24->Location = System::Drawing::Point(3, 3);
			this->panel24->Name = L"panel24";
			this->panel24->Size = System::Drawing::Size(422, 286);
			this->panel24->TabIndex = 5;
			// 
			// btnGetLastInsertedSQLiteId
			// 
			this->btnGetLastInsertedSQLiteId->Location = System::Drawing::Point(3, 119);
			this->btnGetLastInsertedSQLiteId->Name = L"btnGetLastInsertedSQLiteId";
			this->btnGetLastInsertedSQLiteId->Size = System::Drawing::Size(142, 23);
			this->btnGetLastInsertedSQLiteId->TabIndex = 4;
			this->btnGetLastInsertedSQLiteId->Text = L"Last id Kunden";
			this->btnGetLastInsertedSQLiteId->UseVisualStyleBackColor = true;
			this->btnGetLastInsertedSQLiteId->Click += gcnew System::EventHandler(this, &MainForm::btnGetLastInsertedSQLiteId_Click);
			// 
			// btnReadSQLiteKunden
			// 
			this->btnReadSQLiteKunden->Location = System::Drawing::Point(3, 90);
			this->btnReadSQLiteKunden->Name = L"btnReadSQLiteKunden";
			this->btnReadSQLiteKunden->Size = System::Drawing::Size(142, 23);
			this->btnReadSQLiteKunden->TabIndex = 3;
			this->btnReadSQLiteKunden->Text = L"Read Kunden";
			this->btnReadSQLiteKunden->UseVisualStyleBackColor = true;
			this->btnReadSQLiteKunden->Click += gcnew System::EventHandler(this, &MainForm::btnReadSQLiteKunden_Click);
			// 
			// btnInsertSQLiteKunde
			// 
			this->btnInsertSQLiteKunde->Location = System::Drawing::Point(3, 61);
			this->btnInsertSQLiteKunde->Name = L"btnInsertSQLiteKunde";
			this->btnInsertSQLiteKunde->Size = System::Drawing::Size(142, 23);
			this->btnInsertSQLiteKunde->TabIndex = 2;
			this->btnInsertSQLiteKunde->Text = L"Insert Kunde";
			this->btnInsertSQLiteKunde->UseVisualStyleBackColor = true;
			this->btnInsertSQLiteKunde->Click += gcnew System::EventHandler(this, &MainForm::btnInsertSQLiteKunde_Click);
			// 
			// btnCreateSqliteTable
			// 
			this->btnCreateSqliteTable->Location = System::Drawing::Point(3, 32);
			this->btnCreateSqliteTable->Name = L"btnCreateSqliteTable";
			this->btnCreateSqliteTable->Size = System::Drawing::Size(142, 23);
			this->btnCreateSqliteTable->TabIndex = 1;
			this->btnCreateSqliteTable->Text = L"Create SQLite table";
			this->btnCreateSqliteTable->UseVisualStyleBackColor = true;
			this->btnCreateSqliteTable->Click += gcnew System::EventHandler(this, &MainForm::btnCreateSqliteTable_Click);
			// 
			// btnSqliteCreate
			// 
			this->btnSqliteCreate->Location = System::Drawing::Point(3, 3);
			this->btnSqliteCreate->Name = L"btnSqliteCreate";
			this->btnSqliteCreate->Size = System::Drawing::Size(142, 23);
			this->btnSqliteCreate->TabIndex = 0;
			this->btnSqliteCreate->Text = L"Create SQLite database";
			this->btnSqliteCreate->UseVisualStyleBackColor = true;
			this->btnSqliteCreate->Click += gcnew System::EventHandler(this, &MainForm::btnSqliteCreate_Click);
			// 
			// tabPage15
			// 
			this->tabPage15->Controls->Add(this->tableLayoutPanel13);
			this->tabPage15->Location = System::Drawing::Point(4, 22);
			this->tabPage15->Name = L"tabPage15";
			this->tabPage15->Padding = System::Windows::Forms::Padding(3);
			this->tabPage15->Size = System::Drawing::Size(862, 579);
			this->tabPage15->TabIndex = 14;
			this->tabPage15->Text = L"tabPage15";
			this->tabPage15->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel13
			// 
			this->tableLayoutPanel13->ColumnCount = 2;
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel13->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel13->Controls->Add(this->panel25, 0, 1);
			this->tableLayoutPanel13->Controls->Add(this->txtThreading, 1, 0);
			this->tableLayoutPanel13->Controls->Add(this->panel26, 1, 1);
			this->tableLayoutPanel13->Controls->Add(this->panel27, 0, 0);
			this->tableLayoutPanel13->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel13->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel13->Name = L"tableLayoutPanel13";
			this->tableLayoutPanel13->RowCount = 2;
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 51.13438F)));
			this->tableLayoutPanel13->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 48.86562F)));
			this->tableLayoutPanel13->Size = System::Drawing::Size(856, 573);
			this->tableLayoutPanel13->TabIndex = 5;
			// 
			// panel25
			// 
			this->panel25->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel25->Location = System::Drawing::Point(3, 295);
			this->panel25->Name = L"panel25";
			this->panel25->Size = System::Drawing::Size(422, 275);
			this->panel25->TabIndex = 2;
			// 
			// txtThreading
			// 
			this->txtThreading->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtThreading->Location = System::Drawing::Point(431, 3);
			this->txtThreading->Multiline = true;
			this->txtThreading->Name = L"txtThreading";
			this->txtThreading->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->txtThreading->Size = System::Drawing::Size(422, 286);
			this->txtThreading->TabIndex = 0;
			// 
			// panel26
			// 
			this->panel26->Controls->Add(this->webBrowser4);
			this->panel26->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel26->Location = System::Drawing::Point(431, 295);
			this->panel26->Name = L"panel26";
			this->panel26->Size = System::Drawing::Size(422, 275);
			this->panel26->TabIndex = 4;
			// 
			// webBrowser4
			// 
			this->webBrowser4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->webBrowser4->Location = System::Drawing::Point(0, 0);
			this->webBrowser4->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser4->Name = L"webBrowser4";
			this->webBrowser4->Size = System::Drawing::Size(422, 275);
			this->webBrowser4->TabIndex = 0;
			// 
			// panel27
			// 
			this->panel27->Controls->Add(this->btnStartProcessByName);
			this->panel27->Controls->Add(this->txtProcessName);
			this->panel27->Controls->Add(this->btnKillProcess);
			this->panel27->Controls->Add(this->numProcessId);
			this->panel27->Controls->Add(this->btnProcesses);
			this->panel27->Controls->Add(this->btnScreenshot);
			this->panel27->Controls->Add(this->btnPlayWav);
			this->panel27->Controls->Add(this->btnStartWorker);
			this->panel27->Controls->Add(this->btnThreadStart);
			this->panel27->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel27->Location = System::Drawing::Point(3, 3);
			this->panel27->Name = L"panel27";
			this->panel27->Size = System::Drawing::Size(422, 286);
			this->panel27->TabIndex = 5;
			// 
			// btnKillProcess
			// 
			this->btnKillProcess->Location = System::Drawing::Point(3, 151);
			this->btnKillProcess->Name = L"btnKillProcess";
			this->btnKillProcess->Size = System::Drawing::Size(142, 23);
			this->btnKillProcess->TabIndex = 6;
			this->btnKillProcess->Text = L"redruM";
			this->btnKillProcess->UseVisualStyleBackColor = true;
			this->btnKillProcess->Click += gcnew System::EventHandler(this, &MainForm::btnKillProcess_Click);
			// 
			// numProcessId
			// 
			this->numProcessId->Location = System::Drawing::Point(150, 151);
			this->numProcessId->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->numProcessId->Name = L"numProcessId";
			this->numProcessId->Size = System::Drawing::Size(120, 20);
			this->numProcessId->TabIndex = 5;
			// 
			// btnProcesses
			// 
			this->btnProcesses->Location = System::Drawing::Point(3, 119);
			this->btnProcesses->Name = L"btnProcesses";
			this->btnProcesses->Size = System::Drawing::Size(142, 23);
			this->btnProcesses->TabIndex = 4;
			this->btnProcesses->Text = L"Processes";
			this->btnProcesses->UseVisualStyleBackColor = true;
			this->btnProcesses->Click += gcnew System::EventHandler(this, &MainForm::btnProcesses_Click);
			// 
			// btnScreenshot
			// 
			this->btnScreenshot->Location = System::Drawing::Point(3, 90);
			this->btnScreenshot->Name = L"btnScreenshot";
			this->btnScreenshot->Size = System::Drawing::Size(142, 23);
			this->btnScreenshot->TabIndex = 3;
			this->btnScreenshot->Text = L"Screenshot";
			this->btnScreenshot->UseVisualStyleBackColor = true;
			this->btnScreenshot->Click += gcnew System::EventHandler(this, &MainForm::btnScreenshot_Click);
			// 
			// btnPlayWav
			// 
			this->btnPlayWav->Location = System::Drawing::Point(3, 61);
			this->btnPlayWav->Name = L"btnPlayWav";
			this->btnPlayWav->Size = System::Drawing::Size(142, 23);
			this->btnPlayWav->TabIndex = 2;
			this->btnPlayWav->Text = L"Play WAV";
			this->btnPlayWav->UseVisualStyleBackColor = true;
			this->btnPlayWav->Click += gcnew System::EventHandler(this, &MainForm::btnPlayWav_Click);
			// 
			// btnStartWorker
			// 
			this->btnStartWorker->Location = System::Drawing::Point(3, 32);
			this->btnStartWorker->Name = L"btnStartWorker";
			this->btnStartWorker->Size = System::Drawing::Size(142, 23);
			this->btnStartWorker->TabIndex = 1;
			this->btnStartWorker->Text = L"Thread Object";
			this->btnStartWorker->UseVisualStyleBackColor = true;
			this->btnStartWorker->Click += gcnew System::EventHandler(this, &MainForm::btnStartWorker_Click);
			// 
			// btnThreadStart
			// 
			this->btnThreadStart->Location = System::Drawing::Point(3, 3);
			this->btnThreadStart->Name = L"btnThreadStart";
			this->btnThreadStart->Size = System::Drawing::Size(142, 23);
			this->btnThreadStart->TabIndex = 0;
			this->btnThreadStart->Text = L"Thread Simple Method";
			this->btnThreadStart->UseVisualStyleBackColor = true;
			this->btnThreadStart->Click += gcnew System::EventHandler(this, &MainForm::btnThreadStart_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->toolStripMenuItem1,
					this->toolStripMenuItem3, this->toolStripMenuItem4, this->txtDatabaseConnectionStatus, this->eRPToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(870, 27);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->toolStripMenuItem2,
					this->toolStripSeparator1, this->mnuSaveFileDialog, this->mnuRichtextBox, this->mnuFolderBrowser
			});
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(46, 23);
			this->toolStripMenuItem1->Text = L"Datei";
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(190, 22);
			this->toolStripMenuItem2->Text = L"Öffnen";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItem2_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(187, 6);
			// 
			// mnuSaveFileDialog
			// 
			this->mnuSaveFileDialog->Name = L"mnuSaveFileDialog";
			this->mnuSaveFileDialog->Size = System::Drawing::Size(190, 22);
			this->mnuSaveFileDialog->Text = L"Speichern";
			this->mnuSaveFileDialog->Click += gcnew System::EventHandler(this, &MainForm::mnuSaveFileDialog_Click);
			// 
			// mnuRichtextBox
			// 
			this->mnuRichtextBox->Name = L"mnuRichtextBox";
			this->mnuRichtextBox->Size = System::Drawing::Size(190, 22);
			this->mnuRichtextBox->Text = L"Richtextbox Speichern";
			this->mnuRichtextBox->Click += gcnew System::EventHandler(this, &MainForm::mnuRichtextBox_Click);
			// 
			// mnuFolderBrowser
			// 
			this->mnuFolderBrowser->Name = L"mnuFolderBrowser";
			this->mnuFolderBrowser->Size = System::Drawing::Size(190, 22);
			this->mnuFolderBrowser->Text = L"FolderBrowserDialog";
			this->mnuFolderBrowser->Click += gcnew System::EventHandler(this, &MainForm::mnuFolderBrowser_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->mnuFarben,
					this->mnuSchriftart
			});
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(90, 23);
			this->toolStripMenuItem3->Text = L"Einstellungen";
			// 
			// mnuFarben
			// 
			this->mnuFarben->Name = L"mnuFarben";
			this->mnuFarben->Size = System::Drawing::Size(122, 22);
			this->mnuFarben->Text = L"Farben";
			this->mnuFarben->Click += gcnew System::EventHandler(this, &MainForm::mnuFarben_Click);
			// 
			// mnuSchriftart
			// 
			this->mnuSchriftart->Name = L"mnuSchriftart";
			this->mnuSchriftart->Size = System::Drawing::Size(122, 22);
			this->mnuSchriftart->Text = L"Schriftart";
			this->mnuSchriftart->Click += gcnew System::EventHandler(this, &MainForm::mnuSchriftart_Click);
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->mnuButtonsHerstellen,
					this->mnuListControls, this->mnuTextBoxenHerstellen, this->mnuRefreshTreeView, this->mnuFillListView
			});
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(54, 23);
			this->toolStripMenuItem4->Text = L"Debug";
			// 
			// mnuButtonsHerstellen
			// 
			this->mnuButtonsHerstellen->Name = L"mnuButtonsHerstellen";
			this->mnuButtonsHerstellen->Size = System::Drawing::Size(198, 22);
			this->mnuButtonsHerstellen->Text = L"Buttons herstellen";
			this->mnuButtonsHerstellen->Click += gcnew System::EventHandler(this, &MainForm::mnuButtonsHerstellen_Click);
			// 
			// mnuListControls
			// 
			this->mnuListControls->Name = L"mnuListControls";
			this->mnuListControls->Size = System::Drawing::Size(198, 22);
			this->mnuListControls->Text = L"Liste Controls tabPage2";
			this->mnuListControls->Click += gcnew System::EventHandler(this, &MainForm::mnuListControls_Click);
			// 
			// mnuTextBoxenHerstellen
			// 
			this->mnuTextBoxenHerstellen->Name = L"mnuTextBoxenHerstellen";
			this->mnuTextBoxenHerstellen->Size = System::Drawing::Size(198, 22);
			this->mnuTextBoxenHerstellen->Text = L"TextBoxen herstellen";
			this->mnuTextBoxenHerstellen->Click += gcnew System::EventHandler(this, &MainForm::mnuTextBoxenHerstellen_Click);
			// 
			// mnuRefreshTreeView
			// 
			this->mnuRefreshTreeView->Name = L"mnuRefreshTreeView";
			this->mnuRefreshTreeView->Size = System::Drawing::Size(198, 22);
			this->mnuRefreshTreeView->Text = L"Refresh ExplorerTree";
			this->mnuRefreshTreeView->Click += gcnew System::EventHandler(this, &MainForm::mnuRefreshTreeView_Click);
			// 
			// mnuFillListView
			// 
			this->mnuFillListView->Name = L"mnuFillListView";
			this->mnuFillListView->Size = System::Drawing::Size(198, 22);
			this->mnuFillListView->Text = L"Fill ListView";
			this->mnuFillListView->Click += gcnew System::EventHandler(this, &MainForm::mnuFillListView_Click);
			// 
			// txtDatabaseConnectionStatus
			// 
			this->txtDatabaseConnectionStatus->Name = L"txtDatabaseConnectionStatus";
			this->txtDatabaseConnectionStatus->Size = System::Drawing::Size(100, 23);
			// 
			// eRPToolStripMenuItem
			// 
			this->eRPToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->btnOpenRechnungsFenster });
			this->eRPToolStripMenuItem->Name = L"eRPToolStripMenuItem";
			this->eRPToolStripMenuItem->Size = System::Drawing::Size(39, 23);
			this->eRPToolStripMenuItem->Text = L"ERP";
			// 
			// btnOpenRechnungsFenster
			// 
			this->btnOpenRechnungsFenster->Name = L"btnOpenRechnungsFenster";
			this->btnOpenRechnungsFenster->Size = System::Drawing::Size(173, 22);
			this->btnOpenRechnungsFenster->Text = L"Rechnung anlegen";
			this->btnOpenRechnungsFenster->Click += gcnew System::EventHandler(this, &MainForm::btnOpenRechnungsFenster_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// fontDialog1
			// 
			this->fontDialog1->ShowColor = true;
			// 
			// checkHeartbeatDatabaseStatus
			// 
			this->checkHeartbeatDatabaseStatus->Interval = 500;
			this->checkHeartbeatDatabaseStatus->Tick += gcnew System::EventHandler(this, &MainForm::checkHeartbeatDatabaseStatus_Tick);
			// 
			// txtProcessName
			// 
			this->txtProcessName->Location = System::Drawing::Point(151, 183);
			this->txtProcessName->Name = L"txtProcessName";
			this->txtProcessName->Size = System::Drawing::Size(125, 20);
			this->txtProcessName->TabIndex = 7;
			// 
			// btnStartProcessByName
			// 
			this->btnStartProcessByName->Location = System::Drawing::Point(3, 180);
			this->btnStartProcessByName->Name = L"btnStartProcessByName";
			this->btnStartProcessByName->Size = System::Drawing::Size(142, 23);
			this->btnStartProcessByName->TabIndex = 8;
			this->btnStartProcessByName->Text = L"Start Process";
			this->btnStartProcessByName->UseVisualStyleBackColor = true;
			this->btnStartProcessByName->Click += gcnew System::EventHandler(this, &MainForm::btnStartProcessByName_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(870, 632);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->contextMenuStrip1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->pnlDrawing->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->pnlGraphics->ResumeLayout(false);
			this->tabPage5->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->tabPage6->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->tabPage7->ResumeLayout(false);
			this->tableLayoutPanel6->ResumeLayout(false);
			this->tabPage8->ResumeLayout(false);
			this->panel9->ResumeLayout(false);
			this->tabPage9->ResumeLayout(false);
			this->tabPage10->ResumeLayout(false);
			this->tableLayoutPanel8->ResumeLayout(false);
			this->tableLayoutPanel8->PerformLayout();
			this->panel11->ResumeLayout(false);
			this->panel12->ResumeLayout(false);
			this->panel12->PerformLayout();
			this->tabPage11->ResumeLayout(false);
			this->tableLayoutPanel9->ResumeLayout(false);
			this->tableLayoutPanel9->PerformLayout();
			this->panel13->ResumeLayout(false);
			this->panel15->ResumeLayout(false);
			this->tabPage12->ResumeLayout(false);
			this->tableLayoutPanel10->ResumeLayout(false);
			this->tableLayoutPanel10->PerformLayout();
			this->panel16->ResumeLayout(false);
			this->panel17->ResumeLayout(false);
			this->panel18->ResumeLayout(false);
			this->panel18->PerformLayout();
			this->tabPage13->ResumeLayout(false);
			this->tableLayoutPanel11->ResumeLayout(false);
			this->tableLayoutPanel11->PerformLayout();
			this->panel20->ResumeLayout(false);
			this->panel21->ResumeLayout(false);
			this->tabPage14->ResumeLayout(false);
			this->tableLayoutPanel12->ResumeLayout(false);
			this->tableLayoutPanel12->PerformLayout();
			this->panel23->ResumeLayout(false);
			this->panel24->ResumeLayout(false);
			this->tabPage15->ResumeLayout(false);
			this->tableLayoutPanel13->ResumeLayout(false);
			this->tableLayoutPanel13->PerformLayout();
			this->panel26->ResumeLayout(false);
			this->panel27->ResumeLayout(false);
			this->panel27->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numProcessId))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void initialiseComponents()
		{
			this->trvDirectory = gcnew DirectoryTreeView("d:\\temp\\");
			// 
			// trvDirectory
			// 
			this->trvDirectory->Dock = System::Windows::Forms::DockStyle::Fill;
			this->trvDirectory->Location = System::Drawing::Point(3, 3);
			this->trvDirectory->Name = L"trvDirectory";
			this->trvDirectory->Size = System::Drawing::Size(417, 570);
			this->trvDirectory->TabIndex = 0;
			this->tableLayoutPanel7->Controls->Add(this->trvDirectory, 0, 0);
			this->trvDirectory->buildNodes();
			this->trvDirectory->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &MainForm::trvDirectoryAfterSelect);


			ColumnHeader^ nameColumn = gcnew ColumnHeader();
			nameColumn->Text = "Name";
			ColumnHeader^ sizeColumn = gcnew ColumnHeader();
			sizeColumn->Text = "Size";
			this->lsvFile = gcnew FilesListView("d:\\");
			// 
			// lsvFile
			// 
			this->lsvFile->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { nameColumn, sizeColumn });
			this->lsvFile->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lsvFile->Location = System::Drawing::Point(426, 3);
			this->lsvFile->Name = L"lsvFile";
			this->lsvFile->Size = System::Drawing::Size(427, 570);
			this->lsvFile->TabIndex = 1;
			this->lsvFile->UseCompatibleStateImageBehavior = false;
			this->tableLayoutPanel7->Controls->Add(this->lsvFile, 1, 0);
			this->lsvFile->View = System::Windows::Forms::View::Details;
			this->lsvFile->buildFilesLIstViewItems();

			this->btnBlinkinButton = gcnew BlinkinButton(250, System::Drawing::Color::Coral, System::Drawing::Color::CornflowerBlue);
			// 
			// btnBlinkinButton
			// 
			this->btnBlinkinButton->Location = System::Drawing::Point(3, 3);
			this->btnBlinkinButton->Name = L"btnBlinkinButton";
			this->btnBlinkinButton->Size = System::Drawing::Size(75, 23);
			this->btnBlinkinButton->TabIndex = 0;
			this->btnBlinkinButton->Text = L"button1";
			this->btnBlinkinButton->UseVisualStyleBackColor = true;
			this->btnBlinkinButton->Click += gcnew System::EventHandler(this, &GUI::MainForm::BlinkinButtonOnClick);
			this->btnBlinkinButton->MouseHover += gcnew System::EventHandler(this, &GUI::MainForm::BlinkinButtonOnMouseHover);

			this->panel5->Controls->Add(this->btnBlinkinButton);

			this->pnlHouse = (gcnew DrawingPanel);
			// 
			// pnlHouse
			// 
			this->pnlHouse->Location = System::Drawing::Point(25, 25);
			this->pnlHouse->Name = L"pnlHouse";
			this->pnlHouse->Size = System::Drawing::Size(300, 300);
			this->pnlHouse->TabIndex = 0;

			this->panel6->Controls->Add(this->pnlHouse);

			this->txtAutoRegexMatcher = (gcnew RegexTextBox);
			// 
			// txtAutoRegexMatcher
			// 
			this->txtAutoRegexMatcher->Location = System::Drawing::Point(3, 117);
			this->txtAutoRegexMatcher->Name = L"txtAutoRegexMatcher";
			this->txtAutoRegexMatcher->Size = System::Drawing::Size(307, 20);
			this->txtAutoRegexMatcher->TabIndex = 7;
			this->txtAutoRegexMatcher->Text = L"+49 (0) 123 456789";

			this->panel8->Controls->Add(this->txtAutoRegexMatcher);




		}

	private: System::Void BlinkinButtonOnMouseHover(System::Object^  sender, System::EventArgs^  e)
	{
		logger->Debug("I got hovered from the form !!!");
	}

	private: System::Void BlinkinButtonOnClick(System::Object^  sender, System::EventArgs^  e)
	{
		this->btnBlinkinButton->changeConfig(125, Color::Yellow, Color::OrangeRed);
	}

	private: System::Void cmdChangeFormColor_Click(System::Object^  sender, System::EventArgs^  e)
	{
		cmdChangeFormColor->BackColor = System::Drawing::Color(Color::HotPink);
		this->BackColor = System::Drawing::Color(Color::GreenYellow);
	}

	private: System::Void btnChangeTab_Click(System::Object^  sender, System::EventArgs^  e)
	{

		textBox1->AppendText(tabControl1->SelectedIndex.ToString());

		tabControl1->SelectedIndex = 1;
		tabControl1->SelectTab(1);

		textBox1->AppendText(textBox1->GetType()->ToString());

	}
	private: System::Void btnCheckbox_Click(System::Object^  sender, System::EventArgs^  e)
	{

		textBox1->AppendText(checkBox1->Checked.ToString());

		if (checkBox1->Checked)
		{
			System::Windows::Forms::DialogResult dR =
				MessageBox::Show("Oh nooooo, I'm checked !\r\n", "Please click !", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Warning);
			if (dR == System::Windows::Forms::DialogResult::Cancel)
			{
				System::Diagnostics::Debug::WriteLine("User clicked cancel");
				textBox1->AppendText("User cancelled the action !\r\n");
			}
			else if (dR == System::Windows::Forms::DialogResult::Yes)
			{
				System::Diagnostics::Debug::WriteLine("User clicked yes");
				textBox1->AppendText("You're amazing !!\r\n");
			}
			else if (dR == System::Windows::Forms::DialogResult::No)
			{
				System::Diagnostics::Debug::WriteLine("User clicked no");
				textBox1->AppendText("Whaaaaat ??!!\r\n");
			}
		}
		else
		{
			MessageBox::Show("Pleaseeeeee check me !\r\n");
		}
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		textBox1->AppendText("You changed the checkBox1 to " + checkBox1->Checked.ToString() + "\r\n");
	}

			 RadioButton^ gimmeActiveRadioButton()
			 {
				 if (radioButton1->Checked)
				 {
					 return radioButton1;
				 }
				 else if (radioButton2->Checked)
				 {
					 return radioButton2;
				 }
				 else if (radioButton3->Checked)
				 {
					 return radioButton3;
				 }
			 }

	private: System::Void btnRadioButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		textBox1->AppendText("Radiobutton : " + gimmeActiveRadioButton()->Name);
	}
	private: System::Void btnComboboxValue_Click(System::Object^  sender, System::EventArgs^  e)
	{

	}
	private: System::Void cmbBlubb_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		textBox1->AppendText(cmbBlubb->Text);
	}
	private: System::Void btnComboAddItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		cmbBlubb->Items->Add("WoW");
	}
	private: System::Void btnComboremoveItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		cmbBlubb->Items->RemoveAt(2);
	}
	private: System::Void btnComboInsert_Click(System::Object^  sender, System::EventArgs^  e)
	{
		cmbBlubb->Items->Insert(2, "Test");
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		int selectedItemsCount = listBox1->SelectedItems->Count;

		for (int i = 0;i < selectedItemsCount;i++)
		{
			textBox1->AppendText(listBox1->SelectedItems[i]->ToString() + "\r\n");
		}
	}
	private: System::Void btnNextStep_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (step == 0)
		{
			txtQuestions->Clear();
			txtQuestions->AppendText("Wie heisst Du ?\r\n");
			txtAnswers->Clear();
		}
		else if (step == 1)
		{
			txtQuestions->AppendText("Du heisst also " + txtAnswers->Text + " !\r\n");
			antwort1 = txtAnswers->Text;
			txtQuestions->AppendText("Wie alt bist Du ?\r\n");
			txtAnswers->Clear();
		}
		else if (step == 2)
		{
			txtQuestions->AppendText("Du bist also " + txtAnswers->Text + " alt !\r\n");
			antwort2 = txtAnswers->Text;
			txtQuestions->AppendText("Was ist Deine Lieblingsfarbe ?\r\n");
			txtAnswers->Clear();
		}
		else if (step == 3)
		{
			txtQuestions->AppendText("Deine Lieblingsfarbe ist also " + txtAnswers->Text + " !\r\n");
			antwort3 = txtAnswers->Text;
			txtQuestions->AppendText("Danke für's Gespräch !\r\n");
			txtAnswers->Clear();
		}
		step++;
	}

	private: System::Void btnChangeFromAnotherClass_Click(System::Object^  sender, System::EventArgs^  e)
	{
		t = gcnew Test();
		//t->changeTextBoxText(this);
	}


	private: System::Void btnStartProgress_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//for(int counter = 0;counter <=100 ;counter++){
		//	System::Threading::Thread::Sleep(500);
		//	progressBar1->Value = counter;
		//}
		progress = 0;
		timer1->Enabled = true;
	}


	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		if (progress <= 100)
		{
			progressBar1->Value = progress;
			progress += 5;
		}
		else
		{
			timer1->Enabled = false;
		}
	}

	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e)
	{
		textBox1->AppendText(trackBar1->Value + "\r\n");
	}
	private: System::Void toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		openFileDialog1->Filter
			= "Solution Files|*.sln;*.vcxproj|Text Files|*.txt|Image Files(*.BMP;*.JPG;*.GIF)|*.BMP;*.JPG;*.GIF|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->InitialDirectory = "d:\\";

		System::Windows::Forms::DialogResult dialogResult = openFileDialog1->ShowDialog();

		if (dialogResult == System::Windows::Forms::DialogResult::OK)
		{
			if (openFileDialog1->Multiselect == true)
			{
				for each(String^ einFileName in openFileDialog1->FileNames)
				{
					textBox1->AppendText(einFileName + "\r\n");
				}
			}
			else
			{
				textBox1->AppendText(openFileDialog1->FileName + "\r\n");
				String^ inhaltDerDatei = System::IO::File::ReadAllText(openFileDialog1->FileName);
				textBox1->AppendText(inhaltDerDatei);
			}
		}
		else
		{
			textBox1->AppendText("Datei auswählen !\r\n");
		}
	}
	private: System::Void mnuFarben_Click(System::Object^  sender, System::EventArgs^  e)
	{

		System::Windows::Forms::DialogResult dialogResult = colorDialog1->ShowDialog();
		if (dialogResult == System::Windows::Forms::DialogResult::OK)
		{
			textBox1->BackColor = colorDialog1->Color;
		}
	}
	private: System::Void mnuSaveFileDialog_Click(System::Object^  sender, System::EventArgs^  e)
	{
		saveFileDialog1->Filter = "Solution Files|*.sln;*.vcxproj|Text Files|*.txt|Image Files(*.BMP;*.JPG;*.GIF)|*.BMP;*.JPG;*.GIF|All files (*.*)|*.*";
		saveFileDialog1->FilterIndex = 2;
		saveFileDialog1->InitialDirectory = "d:\\";

		System::Windows::Forms::DialogResult dialogResult = saveFileDialog1->ShowDialog();
		if (dialogResult == System::Windows::Forms::DialogResult::OK)
		{
			System::IO::File::WriteAllText(saveFileDialog1->FileName, textBox1->Text);
		}
	}

	private: System::Void mnuSchriftart_Click(System::Object^  sender, System::EventArgs^  e)
	{
		System::Windows::Forms::DialogResult dialogResult = fontDialog1->ShowDialog();
		if (dialogResult == System::Windows::Forms::DialogResult::OK)
		{
			textBox1->Font = fontDialog1->Font;
			textBox1->ForeColor = fontDialog1->Color;
		}
	}

	private: System::Void mnuRichtextBox_Click(System::Object^  sender, System::EventArgs^  e)
	{
		richTextBox1->SaveFile("d:\\richtexttest.rtf");
	}

	private: System::Void mnuFolderBrowser_Click(System::Object^  sender, System::EventArgs^  e)
	{
		folderBrowserDialog1->ShowDialog();
	}
	private: System::Void mnuClearText_Click(System::Object^  sender, System::EventArgs^  e)
	{
		textBox1->Clear();
	}

	private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e)
	{
		DateTime t = dateTimePicker1->Value;
		DateTime aktuelleZeit = DateTime::Now;
		textBox1->AppendText(t.ToLongDateString() + "\n");
		textBox1->AppendText(aktuelleZeit.ToLongTimeString() + "\n");

		TimeSpan dauer(10, 10, 10, 10);

		DateTime summe = t.Add(dauer);
	}
	private: System::Void mnuButtonsHerstellen_Click(System::Object^  sender, System::EventArgs^  e)
	{

		for (int counter = 0; counter < 10;counter++)
		{
			System::Windows::Forms::Button^  btnDynamicButton = gcnew System::Windows::Forms::Button;

			btnDynamicButton->Location = System::Drawing::Point(0, 0 + 25 * counter);
			btnDynamicButton->Name = L"btnDynamicButton" + counter;
			btnDynamicButton->Size = System::Drawing::Size(109, 23);
			btnDynamicButton->TabIndex = 8;
			btnDynamicButton->Text = L"I'm dynamic " + counter;
			btnDynamicButton->UseVisualStyleBackColor = true;
			btnDynamicButton->Click += gcnew System::EventHandler(this, &MainForm::dynamicButtonsClick);

			tabPage2->Controls->Add(btnDynamicButton);
		}
	}

	private: System::Void mnuListControls_Click(System::Object^  sender, System::EventArgs^  e)
	{
		for each(Control^ control in tabPage2->Controls)
		{
			textBox1->AppendText(control->Name + "\n");
		}
	}

	private: System::Void dynamicButtonsClick(System::Object^  sender, System::EventArgs^  e)
	{
		textBox1->AppendText("Dynamic Button clicked !\t" + ((Button^)sender)->Name + "\n");
		if (((Button^)sender)->Name == "btnDynamicButton3")
		{
			MessageBox::Show("Du hast den richtigen Button gedrückt !");
		}
	}
	private: System::Void mnuTextBoxenHerstellen_Click(System::Object^  sender, System::EventArgs^  e)
	{
		createTextBoxes();
	}

			 void createTextBoxes()
			 {
				 for (int counter = 0;counter < 10;counter++)
				 {
					 TextBox^  dynamicTextBox = gcnew TextBox;

					 dynamicTextBox->Location = System::Drawing::Point(200, 0 + 25 * counter);
					 dynamicTextBox->Name = L"textBox" + counter;
					 dynamicTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
					 dynamicTextBox->TabIndex = 67;
					 dynamicTextBox->TextChanged += gcnew System::EventHandler(this, &MainForm::dynamicTextBoxesTextChanged);
					 tabPage2->Controls->Add(dynamicTextBox);
				 }
			 }

	private: System::Void dynamicTextBoxesTextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		textBox1->AppendText(((TextBox^)sender)->Name + " TextChanged : " + ((TextBox^)sender)->Text + "\n");
	}

	private: System::Void btnAddDoubles_Click(System::Object^  sender, System::EventArgs^  e)
	{
		double ersteZahl = Double::Parse(txtErsteZahl->Text);
		double zweiteZahl = Double::Parse(txtZweiteZahl->Text);
		double ergebnis = ersteZahl + zweiteZahl;
		textBox1->AppendText(ergebnis.ToString("N2"));
	}
	private: System::Void btnArrayList_Click(System::Object^  sender, System::EventArgs^  e)
	{
		ArrayList^ listeVonElementen = gcnew ArrayList;

		listeVonElementen->Add("Bli");

		txtCollections->AppendText("\n:::" + listeVonElementen[0]->ToString() + "\n");
		listeVonElementen->Add("Bla");
		listeVonElementen->Add("Blubb");
		listeVonElementen->Add("Yeah");
		listeVonElementen->Add(this);
		listeVonElementen->Add(3);
		listeVonElementen->Add(gcnew Button);
		listeVonElementen->Remove("Bli");
		txtCollections->AppendText(listeVonElementen->IndexOf("Yeah").ToString());
		listeVonElementen->Insert(3, "Blubbbbbb");
		listeVonElementen->Reverse();

		for each(Object^ o in listeVonElementen)
		{
			txtCollections->AppendText(o->GetType() + " | " + o->ToString() + "\r\n");
		}
	}
	private: System::Void btnQueue_Click(System::Object^  sender, System::EventArgs^  e)
	{
		System::Collections::Queue^ queue = gcnew System::Collections::Queue;
		queue->Enqueue("1");
		queue->Enqueue("3");
		queue->Enqueue("2");
		queue->Enqueue("4");

		txtCollections->Text += queue->Count.ToString();

		int count = queue->Count;

		for (int counter = 1;counter <= count;counter++)
		{
			txtCollections->AppendText(queue->Dequeue()->ToString());
			//NICHT rausnehmen, nur drauf schauen
			//txtCollections->AppendText(queue->Peek()->ToString());
		}
	}
	private: System::Void btnStack_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Stack^ stack = gcnew Stack;
		stack->Push("1");
		//stack->Push(1);
		//stack->Push(this);
		stack->Push("2");
		stack->Push("3");
		stack->Push("4");
		stack->Push("5");

		int count = stack->Count;
		for (int counter = 0;counter < count;counter++)
		{
			txtCollections->AppendText((String^)stack->Pop());
		}
	}
	private: System::Void btnSortedList_Click(System::Object^  sender, System::EventArgs^  e)
	{
		SortedList^ sortedList = gcnew SortedList;

		sortedList->Add(1, "Sieger");
		//sortedList->Add(1, "Sieger");  -> Fehler, existiert schon
		sortedList->Add(3, "Drittplatzierter");
		sortedList->Add(2, "Zweiter Sieger");

		for each(int key in sortedList->Keys)
		{
			txtCollections->AppendText(key + " | " + sortedList[key] + "\r\n");
		}



		SortedList^ sortedList1 = gcnew SortedList;

		DateTime d = DateTime(1971, 12, 12);

		sortedList1->Add(d, "Sieger3");
		sortedList1->Add(DateTime(1970, 12, 12), "Sieger2");
		sortedList1->Add(DateTime(1968, 12, 12), "Sieger1");

		for each(DateTime key in sortedList1->Keys)
		{
			txtCollections->AppendText(key + " | " + sortedList1[key] + "\r\n");
		}


	}




	private: System::Void btnHashtable_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Hashtable^ openWith = gcnew Hashtable;
		// Add some elements to the hash table. There are no
		// duplicate keys, but some of the values are duplicates.
		openWith->Add("txt", "notepad.exe");
		//openWith->Add("txt", "notepad.exe"); -> Fehler
		openWith->Add("bmp", "paint.exe");
		openWith->Add("dib", "paint.exe");
		openWith->Add("rtf", "wordpad.exe");

		txtCollections->AppendText(openWith["txt"] + "\r\n");
		openWith["rtf"] = "winword.exe";

		//If the key "ht" doesn't exist, add entry to our Hashtable
		if (!openWith->ContainsKey("ht"))
		{
			openWith->Add("ht", "hypertrm.exe");
		}

		for each(DictionaryEntry de in openWith)
		{
			txtCollections->AppendText(de.Key + " | " + de.Value + "\r\n");
		}
	}

	private: System::Void btnList_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Fully qualified				  |Diamantoperator
		System::Collections::Generic::List<String^>^ phrases = gcnew System::Collections::Generic::List<String^>();
		phrases->Add("Text");
		phrases->Add("Text1");
		phrases->Add("Text2");
		phrases->Add("Text3");
		//phrases->Add(34);-> Fehler
		for each(String^ oneElement in phrases)
		{
			txtCollections->AppendText(oneElement);
		}

	}
	private: System::Void btnArray_Click(System::Object^  sender, System::EventArgs^  e)
	{
		array<String^>^ myArr = { L"The", L"quick", L"brown", L"fox",
			L"jumps", L"over", L"the", L"lazy", L"dog" };
		Array::Resize(myArr, myArr->Length + 5);

		array<Byte>^ buffer = gcnew array<Byte>(1024);

		ArrayList^ l = gcnew ArrayList(myArr);
		l->AddRange(myArr);

		array<String ^, 3> ^ my3DArray = gcnew array<String ^, 3>(3, 5, 6);
		my3DArray[0, 0, 0] = "Bla";

		ArrayList^ zeile = gcnew ArrayList;
		ArrayList^ spalte = gcnew ArrayList;

		spalte->Add(zeile);

		((ArrayList^)spalte[0])[0] = "j";
	}

	private: System::Void btnBenchmark_Click(System::Object^  sender, System::EventArgs^  e)
	{
		int size = 10000000;

		ArrayList^ numbers = gcnew ArrayList;

		DateTime startTime = DateTime::Now;

		for (int counter = 0; counter < size; counter++)
		{
			numbers->Add(counter);
		}

		DateTime endTime = DateTime::Now;

		txtCollections->AppendText("\r\nCreation of 1M int in ArrayList :" + endTime.Subtract(startTime).TotalMilliseconds);

		//////////////////////////////////////////////////////////

		startTime = DateTime::Now;


		array<int>^ intArray = gcnew array<int>(size);
		for (int counter = 0; counter < size; counter++)
		{
			intArray[counter] = counter;
		}
		endTime = DateTime::Now;

		txtCollections->AppendText("\r\nCreation of 1M int in array :" + endTime.Subtract(startTime).TotalMilliseconds);

		//////////////////////////////////////////////////////////
		startTime = DateTime::Now;

		for (int counter = 0;counter < size;counter++)
		{
			int temp = (int)numbers[counter];
		}

		endTime = DateTime::Now;

		txtCollections->AppendText("\r\nAccessing 1M int in ArrayList :" + endTime.Subtract(startTime).TotalMilliseconds);


		//////////////////////////////////////////////////////////
		startTime = DateTime::Now;

		for (int counter = 0;counter < size;counter++)
		{
			int temp = intArray[counter];
		}

		endTime = DateTime::Now;

		txtCollections->AppendText("\r\nAccessing 1M int in array :" + endTime.Subtract(startTime).TotalMilliseconds);
	}
	private: System::Void btnDrawLine_Click(System::Object^  sender, System::EventArgs^  e)
	{
		System::Drawing::Graphics^ graphics = pictureBox2->CreateGraphics();

		System::Drawing::Pen^ penRed = gcnew System::Drawing::Pen(Color::Red);
		System::Drawing::Pen^ penBlue = gcnew System::Drawing::Pen(Color::Blue);
		System::Drawing::Pen^ penGreen = gcnew System::Drawing::Pen(Color::Green);
		System::Drawing::Brush^  brushYellow = gcnew System::Drawing::SolidBrush(Color::Yellow);

		graphics->DrawLine(penRed, 0, 0, 100, 300);
		graphics->DrawLine(penBlue, 100, 200, 0, 0);
		graphics->DrawEllipse(penGreen, 20, 90, 40, 20);
		graphics->FillRectangle(brushYellow, 70, 70, 30, 60);
	}
			 System::Drawing::Point lastPoint = Point(0, 0);
			 ArrayList^ points;
	private: System::Void pnlDrawing_Click(System::Object^  sender, System::EventArgs^  e)
	{

		System::Drawing::Graphics^ graphics = pictureBox2->CreateGraphics();
		System::Drawing::Pen^ penBlack = gcnew System::Drawing::Pen(Color::Black, 4);
		//													|Umrechnung		|aktuelle Mouseposition Bildschirm
		System::Drawing::Point actualPosition = pnlDrawing->PointToClient(this->Cursor->Position);
		graphics->DrawLine(penBlack, lastPoint, actualPosition);

		lastPoint = actualPosition;
		points->Add(lastPoint);


		System::Diagnostics::Debug::WriteLine(actualPosition.ToString());
	}

	private: System::Void pnlDrawing_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
	{
		drawLinesByPoints(e->Graphics);
	}

			 void drawLinesByPoints(Graphics^ g)
			 {
				 System::Drawing::Pen^ penBlack = gcnew System::Drawing::Pen(Color::Black, 4);
				 int pointsCount = points->Count;
				 logger->Info("Amount of points in points :" + pointsCount);
				 for (int counter = 0; counter < pointsCount - 1;counter++)
				 {
					 logger->Debug((Point)points[counter]);
					 g->DrawLine(penBlack, (Point)points[counter], (Point)points[counter + 1]);
				 }
			 }

			 void translatePoints(int factor)
			 {
				 logger->Debug("factor =" + factor);
				 int pointsCount = points->Count;
				 logger->Info("Amount of points in points :" + pointsCount);
				 for (int counter = 0; counter < pointsCount - 1;counter++)
				 {
					 logger->Trace("old point:" + (Point)points[counter]);
					 Point newPoint = Point(((Point)points[counter]).X * factor, ((Point)points[counter]).Y * factor);
					 points[counter] = newPoint;
					 logger->Trace("new point:" + newPoint);
				 }
			 }

	private: System::Void btnTranslatePoints_Click(System::Object^  sender, System::EventArgs^  e)
	{
		translatePoints(2);
		pnlDrawing->CreateGraphics()->Clear(Color::Gainsboro);
		pnlDrawing->Refresh();
	}

	private: System::Void btnDrawImage_Click(System::Object^  sender, System::EventArgs^  e)
	{
		System::Drawing::Pen^ penBlack = gcnew System::Drawing::Pen(Color::Black, 4);

		System::Drawing::Image^ image = Image::FromFile("d:\\spaghettimonster.jpg");
		Graphics^ imageGraphics = Graphics::FromImage(image);
		imageGraphics->DrawLine(penBlack, 0, 0, 200, 200);

		Point ulCorner = Point(100, 0);
		pnlGraphics->CreateGraphics()->DrawImage(image, ulCorner);

		image->Save("d:\\spaghettimonster12.jpg");
	}

	private: System::Void btnDrawHouse_Click(System::Object^  sender, System::EventArgs^  e)
	{
		for (double counter = 0.1;counter < 1;counter += 0.1)
		{
			drawHouse(pnlGraphics->CreateGraphics(), 0 + 20 * counter, 0 + 20 * counter, counter, counter);
		}
	}


			 void drawHouse(Graphics^ graphics, int startPositionX, int startPositionY, double scaleFactorX, double scaleFactorY)
			 {
				 System::Drawing::Pen^ penBlue = gcnew System::Drawing::Pen(Color::Blue);
				 drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 0, 300, 0, 100, scaleFactorX, scaleFactorY);
				 drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 0, 100, 200, 100, scaleFactorX, scaleFactorY);
				 drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 200, 100, 200, 300, scaleFactorX, scaleFactorY);
				 drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 200, 300, 0, 300, scaleFactorX, scaleFactorY);
				 drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 0, 100, 100, 20, scaleFactorX, scaleFactorY);
				 drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 100, 20, 200, 100, scaleFactorX, scaleFactorY);
				 drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 100, 20, 300, 20, scaleFactorX, scaleFactorY);
				 drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 300, 20, 400, 100, scaleFactorX, scaleFactorY);
				 drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 400, 100, 200, 100, scaleFactorX, scaleFactorY);
				 drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 400, 300, 400, 100, scaleFactorX, scaleFactorY);
				 drawSpecialLine(graphics, penBlue, startPositionX, startPositionY, 200, 300, 400, 300, scaleFactorX, scaleFactorY);
			 }

			 void drawSpecialLine(Graphics^ graphics, Pen^ pen, float startPositionX, float startPositionY, float x1, float y1, float x2, float y2, float scaleFactorX, float scaleFactorY)
			 {
				 graphics->DrawLine(pen, startPositionX + x1 * scaleFactorX, startPositionY + y1 * scaleFactorY, startPositionX + x2 * scaleFactorX, startPositionY + y2 * scaleFactorY);

			 }
	private: System::Void btnDivide_Click(System::Object^  sender, System::EventArgs^  e)
	{
		double ersteZahl = double::Parse(txtErsteZahl->Text);
		double zweiteZahl = double::Parse(txtZweiteZahl->Text);
		try
		{
			divide(ersteZahl, zweiteZahl);
		}
		catch (TeilenDurch0Exception^ ex)
		{
			logger->Fatal(ex->Message);
			logger->Fatal("Zähler war : " + ex->zaehler);
			txtZweiteZahl->BackColor = Color::LightSalmon;
		}
		catch (Exception^ ex)
		{
			logger->Fatal(ex->Message);
		}
		finally{
			//Aufräumarbeiten
		}
	}

	private:
		/// <summary>Divides two numbers (number1, number2) and returns the result as int
		/// </summary>
		/// <param name="number1">Is the numerator as <code>int</code></param>
		/// <param name="number2">Is the denominator as <code>int</code></param>
		/// <returns>The result of the division</returns>
		/// <exception cref="Notepad.TeilenDurch0Exception">Thrown when number2 == 0</exception>
		int divide(int number1, int number2)
		{
			if (number2 == 0)
			{
				TeilenDurch0Exception^ ex = gcnew TeilenDurch0Exception("Teilen durch 0 is nich !", number1);
				throw ex;
			}
			return number1 / number2;
		}


	private: System::Void btnAddTreeNodeToTreeView_Click(System::Object^  sender, System::EventArgs^  e)
	{
		treeView1->ExpandAll();
		TreeNode^ anotherNode = gcnew TreeNode("I'm amazingly dynamic!");
		anotherNode->Name = "I'm amazingly dynamic!";
		treeView1->Nodes[0]->Nodes->Add(anotherNode);
	}
	private: System::Void treeView1_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e)
	{
		txtTreeView->AppendText(e->Node->Name + "\r\n");
		txtTreeView->AppendText("Parent : " + e->Node->Parent + "\r\n");
		e->Node->BackColor = Color::LightSalmon;
	}

	private: System::Void btnRemoveTreeNOde_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (treeView1->SelectedNode)
		{
			treeView1->Nodes->Remove(treeView1->SelectedNode);
		}
	}
	private: System::Void btnReadDirectories_Click(System::Object^  sender, System::EventArgs^  e)
	{
		TreeNode^ root = gcnew TreeNode("d:\\");

		for each(String^ oneDirectory in  System::IO::Directory::GetDirectories("d:\\"))
		{
			TreeNode^ directoryNode = gcnew TreeNode(oneDirectory);
			root->Nodes->Add(directoryNode);
		}
		treeView1->Nodes->Add(root);
	}

			 int fakultaet(int n)
			 {
				 logger->Trace("Einsprung");
				 logger->Trace("n=" + n);
				 if (n == 1)
				 {
					 logger->Trace("Raussprung");
					 logger->Trace("n=" + n);
					 return 1;
				 }
				 int result = n*fakultaet(n - 1);
				 logger->Trace("result=" + result);
				 logger->Trace("Raussprung");
				 return result;
			 }

			 //Fakultät 5!
			 //5! = 5 * 4 * 3 * 2 * 1
	private: System::Void btnRecursion_Click(System::Object^  sender, System::EventArgs^  e)
	{
		txtTreeView->AppendText(fakultaet(4).ToString());
	}
	private: System::Void btnRegex_Click(System::Object^  sender, System::EventArgs^  e)
	{
		System::Text::RegularExpressions::Regex^ regex
			= gcnew System::Text::RegularExpressions::Regex(txtRegexExpr->Text);

		if (regex->IsMatch(txtRegex->Text))
		{
			txtRegex->BackColor = Color::White;
		}
		else
		{
			txtRegex->BackColor = Color::LightSalmon;
		}
	}

	private: System::Void btnChangeRegexInRegexTextBox_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->txtAutoRegexMatcher->reconfigure(txtRegexExpr->Text, Color::LightPink);
	}

	private: System::Void btnWalkTreeViewRecursive_Click(System::Object^  sender, System::EventArgs^  e)
	{
		showTreeNodes(treeView1->Nodes[0], 0);
	}
			 //Rekursion
			 void showTreeNodes(TreeNode^ t, int level)
			 {
				 level++;
				 logger->Trace(level + " : " + t->Name);
				 for each(TreeNode^ tn in t->Nodes)
				 {
					 showTreeNodes(tn, level);
				 }
			 }

	private: System::Void btnDriveInfo_Click(System::Object^  sender, System::EventArgs^  e)
	{
		for each(System::IO::DriveInfo^ d in  System::IO::DriveInfo::GetDrives())
		{
			txtTreeView->AppendText(d->Name + "\r\n");
		}
	}

			 void addTreeNodeToTreeView(String^ nodeText)
			 {
				 TreeNode^ t = gcnew TreeNode(nodeText);
				 t->Text = nodeText;
				 trvDirectories->Nodes->Add(t);
			 }

	private: System::Void mnuRefreshTreeView_Click(System::Object^ sender, System::EventArgs^  e)
	{
		for each(System::IO::DriveInfo^ d in System::IO::DriveInfo::GetDrives())
		{
			addTreeNodeToTreeView(d->Name);
			logger->Trace(d->Name);
		}
	}
			 void addDirectoriesToDirectoryTreeNode(TreeNode^ directoryTreeNode)
			 {
				 try
				 {
					 String^ path = directoryTreeNode->Text;
					 if (tryToGetDirectories(path))
					 {
						 for each(String^ directoryPath in System::IO::Directory::GetDirectories(path))
						 {
							 TreeNode^ dirNode1 = gcnew TreeNode(directoryPath);
							 dirNode1->Name = directoryPath;
							 directoryTreeNode->Nodes->Add(dirNode1);
							 logger->Trace("dirNode1->Name=" + dirNode1->Name);
							 if (tryToGetDirectories(dirNode1->Name))
							 {
								 for each(String^ directoryPath2 in System::IO::Directory::GetDirectories(dirNode1->Name))
								 {
									 TreeNode^ dirNode2 = gcnew TreeNode(directoryPath2);
									 dirNode1->Nodes->Add(dirNode2);
								 }
							 }
							 else
							 {
								 logger->Debug(dirNode1->Name + " problem !");
							 }
						 }
					 }
					 else
					 {
						 logger->Debug(path + " problem !");
					 }
				 }
				 catch (Exception^ e)
				 {
					 logger->Fatal(e->Message);
				 }
			 }

			 bool tryToGetDirectories(String^ path)
			 {
				 try
				 {
					 System::IO::Directory::GetDirectories(path);
				 }
				 catch (Exception^e)
				 {
					 logger->Debug(e->Message);
					 return false;
				 }
				 return true;
			 }


	private: System::Void trvDirectories_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e)
	{
		if (e->Node->Tag)
		{
			logger->Trace("Node " + e->Node->Name + " already clicked !");
		}
		else
		{
			addDirectoriesToDirectoryTreeNode(e->Node);
			e->Node->Tag = true;
		}

	}

			 ListViewItem^ getFilesListViewItem(String^ name, int size)
			 {
				 System::Windows::Forms::ListViewItem^  oneListViewItem =
					 gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(2)
				 {
					 name,
						 size.ToString()
				 }, -1);
				 return oneListViewItem;
			 }

			 void fillListViewByDirectoryPath(String^ path)
			 {
				 try
				 {
					 for each(String^ filePath in System::IO::Directory::GetFiles(path))
					 {
						 System::IO::FileInfo^ fileInfo = gcnew System::IO::FileInfo(filePath);
						 logger->Debug(filePath + " : " + fileInfo->Length);
						 ListViewItem^ newFileItem = getFilesListViewItem(filePath, fileInfo->Length);
						 lsvTest->Items->Add(newFileItem);
					 }
				 }
				 catch (Exception^ e)
				 {
					 logger->Fatal(e->Message);
				 }
			 }


	private: System::Void mnuFillListView_Click(System::Object^  sender, System::EventArgs^  e)
	{
		fillListViewByDirectoryPath("d:\\");
	}

			 void trvDirectoryAfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e)
			 {
				 lsvFile->startPath = e->Node->Text;
				 lsvFile->buildFilesLIstViewItems();
			 }
	private: System::Void treeView1_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
	{
		logger->Debug("treeView1_DragEnter");
		e->Effect = e->AllowedEffect;
	}
	private: System::Void treeView1_DragOver(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
	{
		// Retrieve the client coordinates of the mouse position.
		Point targetPoint = treeView1->PointToClient(Point(e->X, e->Y));
		//logger->Debug(Point(e->X, e->Y) + " ---  " + targetPoint);
		// Select the node at the mouse position.
		TreeNode^ draggedNode = (TreeNode^)(e->Data->GetData(TreeNode::typeid));
		bool isDraggedNodeContained = containsNode(draggedNode, treeView1->GetNodeAt(targetPoint));
		logger->Info(isDraggedNodeContained);

		if (isDraggedNodeContained)
		{
			treeView1->Cursor = Cursors::No;
		}
		else
		{
			treeView1->Cursor = Cursors::Hand;
			treeView1->SelectedNode = treeView1->GetNodeAt(targetPoint);
			treeView1->SelectedNode->Expand();
		}
	}

	private: System::Void treeView1_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
	{
		logger->Debug("treeView1_DragDrop");
		// Retrieve the client coordinates of the drop location.
		Point targetPoint = treeView1->PointToClient(Point(e->X, e->Y));
		// Retrieve the node at the drop location.
		TreeNode^ targetNode = treeView1->GetNodeAt(targetPoint);
		// Retrieve the node that was dragged.
		TreeNode^ draggedNode = (TreeNode^)e->Data->GetData(TreeNode::typeid);
		// Confirm that the node at the drop location is not 
		// the dragged node or a descendant of the dragged node.
		if (!draggedNode->Equals(targetNode) && !containsNode(draggedNode, targetNode))
		{
			logger->Debug("!draggedNode->Equals(targetNode) && !ContainsNode(draggedNode, targetNode)");
			// If it is a move operation, remove the node from its current 
			// location and add it to the node at the drop location.
			if (e->Effect == DragDropEffects::Move)
			{
				draggedNode->Remove();
				targetNode->Nodes->Add(draggedNode);
			}
			// If it is a copy operation, clone the dragged node 
			// and add it to the node at the drop location.
			else
				// If it is a copy operation, clone the dragged node 
				// and add it to the node at the drop location.
				if (e->Effect == DragDropEffects::Copy)
				{
					targetNode->Nodes->Add((TreeNode^)(draggedNode->Clone()));
				}
			// Expand the node at the location 
			// to show the dropped node.
			targetNode->Expand();
		}
	}
	private: System::Void treeView1_ItemDrag(System::Object^  sender, System::Windows::Forms::ItemDragEventArgs^  e)
	{
		logger->Debug("treeView1_ItemDrag");
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			DoDragDrop(e->Item, DragDropEffects::Move);
		}
		// Copy the dragged node when the right mouse button is used.
		else
			// Copy the dragged node when the right mouse button is used.
			if (e->Button == System::Windows::Forms::MouseButtons::Right)
			{
				DoDragDrop(e->Item, DragDropEffects::Copy);
			}
	}

			 bool containsNode(TreeNode^ draggedNode, TreeNode^ targetDropNode)
			 {
				 try
				 {
					 // Check the parent node of the second node.
					 if (targetDropNode->Parent == nullptr)
						 return false;

					 if (targetDropNode->Parent->Equals(draggedNode))
						 return true;

					 // If the parent node is not null or equal to the first node, 
					 // call the ContainsNode method recursively using the parent of 
					 // the second node.
					 return containsNode(draggedNode, targetDropNode->Parent);
				 }
				 catch (Exception^ e)
				 {
					 logger->Fatal(e->Message);
					 return true;
				 }
			 }

	private: System::Void btnWebRequest_Click(System::Object^  sender, System::EventArgs^  e)
	{

		webBrowser1->Navigate(txtURL->Text);

		System::Net::HttpWebRequest^ httpWebRequest =
			(System::Net::HttpWebRequest^)System::Net::WebRequest::Create(txtURL->Text);
		httpWebRequest->UserAgent = "Mozilla/5.0 (Windows NT 6.3; WOW64; rv:47.0) Gecko/20100101 Firefox/47.0";

		System::Net::HttpWebResponse^ response = (System::Net::HttpWebResponse^)httpWebRequest->GetResponse();
		System::IO::Stream^ dataStream = response->GetResponseStream();
		System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(dataStream);

		String^ htmlPage = reader->ReadToEnd();
		txtWeb->Text = htmlPage;
		response->Close();
		reader->Close();
	}

	private: System::Void btnFTPWebrequestDirectory_Click(System::Object^  sender, System::EventArgs^  e)
	{
		System::Net::FtpWebRequest^ datenAustauschRequest =
			(System::Net::FtpWebRequest^)System::Net::WebRequest::Create("ftp://datenaustausch.alfanetz.de/Klassenraum-319");

		datenAustauschRequest->Credentials = gcnew System::Net::NetworkCredential("alfaftp", "alfa");
		datenAustauschRequest->Method = System::Net::WebRequestMethods::Ftp::ListDirectory;

		System::Net::FtpWebResponse^ response = (System::Net::FtpWebResponse^)datenAustauschRequest->GetResponse();
		System::IO::StreamReader^ streamReader = gcnew System::IO::StreamReader(response->GetResponseStream());

		String^ directory = streamReader->ReadLine();
		txtWeb->Text = "";
		while (!String::IsNullOrEmpty(directory))
		{
			txtWeb->AppendText(directory + "\r\n");
			directory = streamReader->ReadLine();
		}
		response->Close();
		streamReader->Close();
	}
	private: System::Void btnFTPDownload_Click(System::Object^  sender, System::EventArgs^  e)
	{
		System::Net::FtpWebRequest^ request = (System::Net::FtpWebRequest^)System::Net::WebRequest::Create("ftp://datenaustausch.alfanetz.de/Klassenraum-319/Kram/NLog.config");
		request->Method = System::Net::WebRequestMethods::Ftp::DownloadFile;
		request->UsePassive = true;
		request->Credentials = gcnew System::Net::NetworkCredential("alfaftp", "alfa");
		System::Net::FtpWebResponse^ response = (System::Net::FtpWebResponse^)request->GetResponse();
		System::IO::Stream^ responseStream = response->GetResponseStream();
		System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(responseStream);

		txtWeb->AppendText(reader->ReadToEnd());
		logger->Trace("Download Complete, status " + response->StatusDescription);

		response->Close();
		reader->Close();

	}
	private: System::Void btnFTPDownloadBinary_Click(System::Object^  sender, System::EventArgs^  e)
	{
		System::Net::FtpWebRequest^ request = (System::Net::FtpWebRequest^)System::Net::WebRequest::Create("ftp://ftp.rz.uni-saarland.de/pub/get/Deckblatt.pdf");
		request->Credentials = gcnew System::Net::NetworkCredential("anonymous", "bla@bla.de");
		request->Method = System::Net::WebRequestMethods::Ftp::DownloadFile;

		int bytesRead = 0;
		array<Byte>^ buffer = gcnew array<Byte>(1024);

		System::IO::Stream^ reader = request->GetResponse()->GetResponseStream();
		if (!System::IO::Directory::Exists("d:\\temp\\"))
		{
			System::IO::Directory::CreateDirectory("d:\\temp\\");
		}
		System::IO::FileStream^ fileStream = gcnew System::IO::FileStream("d:\\temp\\bla.pdf", System::IO::FileMode::Create);
		while (true)
		{
			bytesRead = reader->Read(buffer, 0, buffer->Length);

			if (bytesRead == 0)
				break;

			fileStream->Write(buffer, 0, bytesRead);
		}
		fileStream->Close();
	}
	private: System::Void btnSendMail_Click(System::Object^  sender, System::EventArgs^  e)
	{
		System::Net::Mail::MailMessage^ aMessage = gcnew System::Net::Mail::MailMessage;

		aMessage->To->Add(gcnew System::Net::Mail::MailAddress("newuser@localhost"));
		aMessage->From = gcnew System::Net::Mail::MailAddress("newuser@localhost");

		aMessage->CC->Add(gcnew System::Net::Mail::MailAddress("bla@itreppert.de"));
		aMessage->Body = "Hallo lieber Blablabla,sfdsfsfsdf blubb !";
		aMessage->Subject = "Hallo!";

		System::Net::Mail::SmtpClient^ client = gcnew System::Net::Mail::SmtpClient();

		client->Host = "localhost";
		client->Port = 25;
		client->Credentials = gcnew System::Net::NetworkCredential("newuser@localhost", "newuser");

		try
		{
			client->Send(aMessage);
		}
		catch (Exception^ e)
		{
			logger->Error(e->Message);
		}
	}
	private: System::Void btnCreateXMLDocument_Click(System::Object^  sender, System::EventArgs^  e)
	{

	}
	private: System::Void btnLoadXMLDoc_Click(System::Object^  sender, System::EventArgs^  e)
	{
		System::Xml::XmlDocument^ kundenVerzeichnisXMLDocument = gcnew System::Xml::XmlDocument();
		try
		{
			kundenVerzeichnisXMLDocument->Load("d:\\Kunden.xml");
		}
		catch (Exception^ e)
		{
			logger->Fatal(e->Message);
		}

		System::Xml::XmlNode^ resultKundenNode = kundenVerzeichnisXMLDocument->SelectSingleNode("//Kunde[@id='3']");
		txtXMLOutput->AppendText(resultKundenNode->InnerXml);

		System::Xml::XmlNodeList^ xmlNodeList = kundenVerzeichnisXMLDocument->SelectNodes("//Kunde");

		for each(System::Xml::XmlNode^ node in xmlNodeList)
		{
			txtXMLOutput->AppendText(node->InnerXml);
		}
	}
	private: System::Void btnCreateKundeNode_Click(System::Object^  sender, System::EventArgs^  e)
	{

		addKundeNodeToKundeVerzeichnisXml("7", "Otto", "Normalverbraucher", "Blastreet 2", "34545", "Bugsdehude", "43545,54", "Flotto", "Normalkunden");
		addKundeNodeToKundeVerzeichnisXml("8", "Hans", "Normalverbraucher", "Blubbtreet 2", "34545", "Bugsdehude", "43545,54", "Flotto", "Geschaeftskunden");
	}

			 void addKundeNodeToKundeVerzeichnisXml(String^ id, String^ vorname, String^ nachname, String^ strasse, String^plz, String^ ort, String^ umsatz, String^ benutzername, String^ kundeType)
			 {
				 System::Xml::XmlDocument^ kundenVerzeichnisXMLDocument = gcnew System::Xml::XmlDocument();
				 try
				 {
					 kundenVerzeichnisXMLDocument->Load("d:\\Kunden.xml");

					 System::Xml::XmlNode^ targetNode =
						 kundenVerzeichnisXMLDocument->SelectSingleNode("/Kundenverzeichnis/" + kundeType);
					 System::Xml::XmlNode^ kundeNode =
						 kundenVerzeichnisXMLDocument->CreateNode(System::Xml::XmlNodeType::Element, "Kunde", "");
					 System::Xml::XmlAttribute^ idAttribute = kundenVerzeichnisXMLDocument->CreateAttribute("id");
					 idAttribute->Value = id;
					 kundeNode->Attributes->Append(idAttribute);
					 System::Xml::XmlNode^ vornameNode =
						 kundenVerzeichnisXMLDocument->CreateNode(System::Xml::XmlNodeType::Element, "vorname", "");
					 vornameNode->InnerText = vorname;
					 System::Xml::XmlNode^ nachnameNode =
						 kundenVerzeichnisXMLDocument->CreateNode(System::Xml::XmlNodeType::Element, "nachname", "");
					 nachnameNode->InnerText = nachname;
					 System::Xml::XmlNode^ strasseNode =
						 kundenVerzeichnisXMLDocument->CreateNode(System::Xml::XmlNodeType::Element, "strasse", "");
					 strasseNode->InnerText = strasse;
					 System::Xml::XmlNode^ plzNode =
						 kundenVerzeichnisXMLDocument->CreateNode(System::Xml::XmlNodeType::Element, "plz", "");
					 plzNode->InnerText = plz;
					 System::Xml::XmlNode^ ortNode =
						 kundenVerzeichnisXMLDocument->CreateNode(System::Xml::XmlNodeType::Element, "ort", "");
					 ortNode->InnerText = ort;
					 System::Xml::XmlNode^ umsatzNode =
						 kundenVerzeichnisXMLDocument->CreateNode(System::Xml::XmlNodeType::Element, "umsatz", "");
					 umsatzNode->InnerText = umsatz;
					 System::Xml::XmlNode^ benutzernameNode =
						 kundenVerzeichnisXMLDocument->CreateNode(System::Xml::XmlNodeType::Element, "benutzername", "");
					 benutzernameNode->InnerText = benutzername;

					 targetNode->AppendChild(kundeNode);
					 kundeNode->AppendChild(vornameNode);
					 kundeNode->AppendChild(nachnameNode);
					 kundeNode->AppendChild(strasseNode);
					 kundeNode->AppendChild(plzNode);
					 kundeNode->AppendChild(ortNode);
					 kundeNode->AppendChild(umsatzNode);
					 kundeNode->AppendChild(benutzernameNode);

					 kundenVerzeichnisXMLDocument->Save("d:\\Kunden.xml");
				 }
				 catch (Exception^ e)
				 {
					 logger->Fatal(e->Message);
				 }
			 }
	private: System::Void btnCreateClassKundeXmlNode_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Entity
		//Persistenceobject
		//DAO -> Data Access Object
		Kunde^ holger;
		holger->id = 9;
		holger->vorname = "Holger";
		holger->nachname = "Reppert";
		holger->strasse = "Blubbstrasse 12";
		holger->plz = "66123";
		holger->ort = "Saarbrücken";
		holger->umsatz = 4564564.45;
		holger->benutzername = "Peppl";

		System::Xml::XmlDocument^ xmlDoc = gcnew System::Xml::XmlDocument;
		xmlDoc->Load("d:\\Kunden.xml");
		holger->addToVerzeichnisXml(xmlDoc, "Normalkunde");
	}
	private: System::Void btnReadKundeFromKundenVverzeichnisXml_Click(System::Object^  sender, System::EventArgs^  e)
	{


		System::Xml::XmlDocument^ sourceKundenverzeichnis = gcnew System::Xml::XmlDocument;
		sourceKundenverzeichnis->Load("d:\\Kunden.xml");
		double sum = 0;
		for (int counter = 1;counter < 8;counter++)
		{

			Kunde^ anonymous = gcnew Kunde;
			anonymous->id = counter;
			anonymous->getFromVerzeichnisXml(sourceKundenverzeichnis);
			sum += anonymous->umsatz;
			logger->Trace(anonymous->ToString());
		}
		logger->Trace("Gesamtumsatz:" + sum);
	}
	private: System::Void btnDeleteKundeFromVerzeichnis_Click(System::Object^  sender, System::EventArgs^  e)
	{
		System::Xml::XmlDocument^ sourceKundenverzeichnis = gcnew System::Xml::XmlDocument;
		sourceKundenverzeichnis->Load("d:\\Kunden.xml");

		Kunde^ armeWurst = gcnew Kunde;
		armeWurst->id = 7;
		armeWurst->deleteFromVerzeichnisXml(sourceKundenverzeichnis);

		sourceKundenverzeichnis->Save("d:\\Kunden.xml");
	}
	private: System::Void btnUpdateKunde_Click(System::Object^  sender, System::EventArgs^  e)
	{
		System::Xml::XmlDocument^ sourceKundenverzeichnis = gcnew System::Xml::XmlDocument;
		sourceKundenverzeichnis->Load("d:\\Kunden.xml");

		Kunde^ anonymous = gcnew Kunde;
		anonymous->id = 5;
		anonymous->getFromVerzeichnisXml(sourceKundenverzeichnis);
		anonymous->vorname = "Hal";
		anonymous->updateKunde(sourceKundenverzeichnis);
	}
	private: System::Void btnCreateKundenverzeichnisXmlDocument_Click(System::Object^  sender, System::EventArgs^  e)
	{
		logger->Trace("btnCreateKundenverzeichnisXmlDocument_Click");
		System::Xml::XmlDocument^ kundenVerzeichnis = Kunde::getEmptyVerzeichnisXmlDocument("d:\\Kundenverzeichnis.xml");
		Kunde^ holger = gcnew Kunde;
		holger->id = 9;
		holger->vorname = "Holger";
		holger->nachname = "Reppert";
		holger->strasse = "Blubbstrasse 12";
		holger->plz = "66123";
		holger->ort = "Saarbrücken";
		holger->umsatz = 4564564.45;
		holger->benutzername = "Peppl";

		holger->addToVerzeichnisXml(kundenVerzeichnis, "Geschaeftskunden");

		kundenVerzeichnis->Save("d:\\Kundenverzeichnis.xml");
	}

	private: System::Void btnWriteToRegistry_Click(System::Object^  sender, System::EventArgs^  e)
	{
		writeWindowsPositionToRegistry();
	}

			 void writeWindowsPositionToRegistry()
			 {
				 Microsoft::Win32::RegistryKey^ rk = Microsoft::Win32::Registry::CurrentUser;
				 Microsoft::Win32::RegistryKey^ att = rk->CreateSubKey("GUIWindowPosition");

				 att->SetValue("X", this->Location.X.ToString());
				 att->SetValue("Y", this->Location.Y.ToString());

			 }

			 void setWindowPositionByRegistry()
			 {
				 try
				 {
					 Microsoft::Win32::RegistryKey^ rk = Microsoft::Win32::Registry::CurrentUser;
					 Microsoft::Win32::RegistryKey^ att = rk->CreateSubKey("GUIWindowPosition");
					 int x = int::Parse((String^)att->GetValue("X"));
					 int y = int::Parse((String^)att->GetValue("Y"));

					 this->Location = Point(x, y);
				 }
				 catch (Exception^ e)
				 {
					 logger->Fatal(e->Message);
				 }
			 }

	private: System::Void btnLoadFromRegistry_Click(System::Object^  sender, System::EventArgs^  e)
	{
		setWindowPositionByRegistry();
	}

	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		setWindowPositionByRegistry();
	}

	private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{
		writeWindowsPositionToRegistry();
	}

	private: System::Void btnGetHighestKundeId_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Kunde::getHighestId("d:\\Kunden.xml");
	}

	private: System::Void btnDoDllMethod_Click(System::Object^  sender, System::EventArgs^  e) {
		Tools::FileTools^ ft = gcnew Tools::FileTools;
		ft->print();
		ft->printAgain();
	}

			 System::Data::SqlClient::SqlConnection^ localhostConnection;


	private: System::Void btnConnectDatabase_Click(System::Object^  sender, System::EventArgs^  e) {
		connectToSqlServer();

	}

			 void insertIntoKunden() {
				 localhostConnection->Open();

				 //INSERT INTO Kunden (vorname,nachname,strasse,plz,ort,benutzername,umsatz) VALUES('Holger','Reppert','Blastreet','66111','Saarbridges','Blondie',20000);
				 String^ sqlInsertIntoKundenCommand =
					 "INSERT INTO Kunden (vorname,nachname,strasse,plz,ort,benutzername,umsatz) VALUES('"
					 + txtKundeVorname->Text + "','"
					 + txtKundeNachname->Text + "','"
					 + txtKundeStrasse->Text + "','"
					 + txtKundePlz->Text + "','"
					 + txtKundeOrt->Text + "','"
					 + txtKundeBenutzername->Text + "',"
					 + txtKundeUmsatz->Text + ");";

				 System::Data::SqlClient::SqlCommand^ insertIntoKundenCommand =
					 gcnew System::Data::SqlClient::SqlCommand(sqlInsertIntoKundenCommand, localhostConnection);
				 int betroffeneZeile = insertIntoKundenCommand->ExecuteNonQuery();
				 txtSQLOutput->AppendText(betroffeneZeile.ToString());
				 localhostConnection->Close();
			 }

			 void deleteKunde() {
				 localhostConnection->Open();

				 //DELETE FROM Kunden WHERE id=?
				 String^ sqlDeleteKundeCommand =
					 "DELETE FROM Kunden WHERE id=" + txtDeleteKundeId->Text;

				 System::Data::SqlClient::SqlCommand^ deleteKundeCommand =
					 gcnew System::Data::SqlClient::SqlCommand(sqlDeleteKundeCommand, localhostConnection);
				 int betroffeneZeile = deleteKundeCommand->ExecuteNonQuery();
				 txtSQLOutput->AppendText(betroffeneZeile.ToString());
				 localhostConnection->Close();
			 }

			 void updateKunde() {
				 localhostConnection->Open();

				 //DELETE FROM Kunden WHERE id=?
				 String^ sqlUpdateKundenCommand =
					 "UPDATE Kunden SET umsatz=1000000.01 WHERE id=6";

				 System::Data::SqlClient::SqlCommand^ updateKundeCommand =
					 gcnew System::Data::SqlClient::SqlCommand(sqlUpdateKundenCommand, localhostConnection);
				 int betroffeneZeile = updateKundeCommand->ExecuteNonQuery();
				 txtSQLOutput->AppendText(betroffeneZeile.ToString());
				 localhostConnection->Close();
			 }



			 void connectToSqlServer() {
				 String^ serverName = "localhost";
				 String^ databaseName = "Firma";
				 String^ userName = "sa";
				 String^ password = "sa";

				 //"Database=Firma;Server=localhost;Trusted_Connection=False;User ID=sa;Password=sa"
				 String^ connectionString = "Database=" + databaseName +
					 ";Server=" + serverName
					 + ";Trusted_Connection=False;User ID=" + userName + ";Password=" + password;

				 localhostConnection =
					 gcnew System::Data::SqlClient::SqlConnection(connectionString);
			 }

	private: System::Void btnInsertKunde_Click(System::Object^  sender, System::EventArgs^  e) {
		insertIntoKunden();
		logger->Debug(getLastInsertedIdSQLServer("Kunden"));
	}
	private: System::Void btnDelete_Click(System::Object^  sender, System::EventArgs^  e) {
		deleteKunde();
	}
	private: System::Void btnUpdateK_Click(System::Object^  sender, System::EventArgs^  e) {
		updateKunde();
	}
	private: System::Void btnSelectKunden_Click(System::Object^  sender, System::EventArgs^  e) {
		localhostConnection->Open();

		//Select * FROM Kunden
		String^ sqlSelectKundenCommand =
			"Select * FROM Kunden";

		System::Data::SqlClient::SqlCommand^ selectKundenCommand =
			gcnew System::Data::SqlClient::SqlCommand(sqlSelectKundenCommand, localhostConnection);


		System::Data::SqlClient::SqlDataReader^ kundenDataReader = selectKundenCommand->ExecuteReader();
		while (kundenDataReader->Read())
		{
			String^ kundenZeile = kundenDataReader["id"] + ", " + kundenDataReader["vorname"] + ", " +
				kundenDataReader["nachname"] + ", " + kundenDataReader["strasse"] + ", " +
				kundenDataReader["plz"] + ", " + kundenDataReader["ort"] + ", " +
				kundenDataReader["umsatz"] + ", " + kundenDataReader["benutzername"];

			txtSQLOutput->AppendText(kundenZeile + "\r\n");
		}

	}
	private: System::Void btnInsertKundeEntity_Click(System::Object^  sender, System::EventArgs^  e) {
		Kunde^ insertKunde = gcnew Kunde;

		insertKunde->vorname = txtKundeVorname->Text;
		insertKunde->nachname = txtKundeNachname->Text;
		insertKunde->strasse = txtKundeStrasse->Text;
		insertKunde->plz = txtKundePlz->Text;
		insertKunde->ort = txtKundeOrt->Text;
		insertKunde->benutzername = txtKundeBenutzername->Text;

		System::Globalization::CultureInfo^ cultureInfoUS = gcnew System::Globalization::CultureInfo("en-US");

		insertKunde->umsatz = double::Parse(txtKundeUmsatz->Text, cultureInfoUS);

		txtSQLOutput->AppendText(insertKunde->insert() + "\r\n");
	}

	private: System::Void btnDeleteKundeEntity_Click(System::Object^  sender, System::EventArgs^  e) {
		Kunde^ deleteKunde = gcnew Kunde;
		deleteKunde->id = int::Parse(txtDeleteKundeId->Text);
		txtSQLOutput->AppendText(deleteKunde->deleteMe() + "\r\n");
	}

	private: System::Void btnSelectKundeEntity_Click(System::Object^  sender, System::EventArgs^  e) {
		Kunde^ kundeMitId = gcnew Kunde;
		kundeMitId->id = int::Parse(txtSelectKundeId->Text);
		kundeMitId->load();

		txtSQLOutput->AppendText(kundeMitId->ToString() + "\r\n");
	}
	private: System::Void btnUpdateKundeEntity_Click(System::Object^  sender, System::EventArgs^  e) {
		Kunde^ kundeMitId = gcnew Kunde;

		kundeMitId->id = int::Parse(txtSelectKundeId->Text);
		kundeMitId->load();
		kundeMitId->vorname = "Ignaz";
		kundeMitId->nachname = "Brod";
		kundeMitId->update();

		ArrayList^ kundenListe = gcnew ArrayList;

		for (int id = 1; id < 5;id++) {
			kundenListe->Add(Kunde::getById(id));
		}

	}

	private: System::Void btnFillKundenListView_Click(System::Object^  sender, System::EventArgs^  e) {
		Kunde^ kundeMitId = gcnew Kunde;


		ArrayList^ ids = kundeMitId->getIdArrayList();

		for each(int id in ids) {
			kundeMitId->id = id;
			kundeMitId->load();

			lsvKunden->Items->Add(kundeMitId->getAsListViewItem());
		}
		lsvKunden->AutoResizeColumns(ColumnHeaderAutoResizeStyle::ColumnContent);
	}
	private: System::Void btnFillProduktListView_Click(System::Object^  sender, System::EventArgs^  e) {
		Produkt^ produktMitId = gcnew Produkt;


		ArrayList^ ids = produktMitId->getIdArrayList();

		for each(int id in ids) {
			produktMitId->id = id;
			produktMitId->load();

			lsvProdukte->Items->Add(produktMitId->getAsListViewItem());
		}
		lsvProdukte->AutoResizeColumns(ColumnHeaderAutoResizeStyle::ColumnContent);
	}
	private: System::Void checkHeartbeatDatabaseStatus_Tick(System::Object^  sender, System::EventArgs^  e) {
		Application::DoEvents();
		if (databaseManager->heartBeatOk) {
			txtDatabaseConnectionStatus->BackColor = Color::White;
			txtDatabaseConnectionStatus->Text = "Connection OK";
			Application::DoEvents();
		}
		else {
			txtDatabaseConnectionStatus->BackColor = Color::Red;
			txtDatabaseConnectionStatus->Text = "Connection Problem";
			Application::DoEvents();
		}
	}
	private: System::Void btnListCultures_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Globalization::CultureInfo^ en = System::Globalization::CultureInfo::CreateSpecificCulture("de-DE");
		for each(System::Globalization::CultureInfo^ cI in
			System::Globalization::CultureInfo::GetCultures(System::Globalization::CultureTypes::AllCultures)) {
			txtCulture->AppendText(cI->NativeName + " : " + cI->TextInfo->CultureName + " : " + cI->ThreeLetterISOLanguageName + " : " + cI->DisplayName + " : " + cI->DateTimeFormat->ToString() + " : " + cI->Name + "\r\n");
		}
	}
	private: System::Void btnDateTimeCulture_Click(System::Object^  sender, System::EventArgs^  e) {
		DateTime^ dt = DateTime::Now;

		System::Globalization::CultureInfo^ cultureInfoUS = gcnew System::Globalization::CultureInfo("en-US");
		System::Globalization::CultureInfo^ cultureInfoDE = gcnew System::Globalization::CultureInfo("de-DE");

		logger->Info(dt->ToString(cultureInfoDE));
		logger->Info(dt->ToString(cultureInfoUS));

		double price = 345.56;

		logger->Info(price.ToString(cultureInfoDE));
		logger->Info(price.ToString(cultureInfoUS));

		String^ date = "7/5/2016";

		DateTime dateTimeFromString = DateTime::Parse(date, cultureInfoUS);

		logger->Info(dateTimeFromString.ToString(cultureInfoDE));
	}

	private: System::Void dateTimePicker2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		System::Globalization::CultureInfo^ cultureInfoUS = gcnew System::Globalization::CultureInfo("en-US");
		//Standard für Programm !! ist US
		System::Windows::Forms::Application::CurrentCulture = cultureInfoUS;
		dateTimePicker2->Format = DateTimePickerFormat::Custom;
		dateTimePicker2->CustomFormat = cultureInfoUS->DateTimeFormat->LongDatePattern;   // "MMM-dd-yyyy";
	}

	private: System::Void btnReflect_Click(System::Object^  sender, System::EventArgs^  e) {
		Kunde^ k = gcnew Kunde;
		Type^ typeOfKunde = k->GetType();
		for each(System::Reflection::FieldInfo^ fieldInfo in typeOfKunde->GetFields())
		{
			logger->Info(fieldInfo->FieldType->ToString() + " : " + fieldInfo->Name);
		}

		for each(System::Reflection::FieldInfo^ fieldInfo in typeOfKunde->GetFields(System::Reflection::BindingFlags::NonPublic |
			System::Reflection::BindingFlags::Instance))
		{
			logger->Info(fieldInfo->FieldType->ToString() + " : " + fieldInfo->Name);
		}


		for each(System::Reflection::MethodInfo^ methodInfo in typeOfKunde->GetMethods())
		{
			logger->Info(methodInfo->ReturnType->Name + " : " + methodInfo->Name);
			for each(System::Reflection::ParameterInfo^ paramInfo in methodInfo->GetParameters())
			{
				logger->Info(paramInfo->ParameterType + " : " + paramInfo->Name);
			}
		}

		//					| Direkter Zugriff auf Typ über typeid
		Type^ typeOfForm = Form::typeid;

		for each(System::Reflection::EventInfo^ eventInfo in typeOfForm->GetEvents())
		{
			logger->Info("Formevent : " + eventInfo->Name);
		}

		//Form^ newForm = gcnew Form;
		((Form^)Activator::CreateInstance(typeOfForm))->Show();

		Form^ dynForm = ((Form^)Activator::CreateInstance(typeOfForm));


		//DateTime^ dt = gcnew DateTime(2008, 12, 12);
		logger->Debug(((DateTime^)Activator::CreateInstance(DateTime::typeid, gcnew array<Object^>{2008, 12, 12}))->ToString());
	}

			 SQLite::SQLiteConnection^ sqLiteConnection;

	private: System::Void btnSqliteCreate_Click(System::Object^  sender, System::EventArgs^  e) {
		createSQLiteDatabase();

	}

			 void createSQLiteDatabase() {
				 String^ dbFilePath = "d:\\GUI.sqlite";
				 try {
					 SQLite::SQLiteConnectionStringBuilder^ sb = gcnew SQLite::SQLiteConnectionStringBuilder();
					 sb->FailIfMissing = false;
					 sb->DataSource = dbFilePath;
					 logger->Debug(sb->ConnectionString);
					 sqLiteConnection = gcnew SQLite::SQLiteConnection(sb->ConnectionString);
				 }
				 catch (Exception^ e) {
					 logger->Fatal(e->Message);
				 }
			 }

			 void createSQLiteTableStructure()
			 {
				 try
				 {
					 sqLiteConnection->Open();
					 String^ createTableString = "CREATE TABLE Kunden (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, vorname varchar(50) NOT NULL, nachname varchar(50) NOT NULL)";
					 SQLite::SQLiteCommand^ createTableCommand = gcnew SQLite::SQLiteCommand(createTableString, sqLiteConnection);
					 int result = createTableCommand->ExecuteNonQuery();
					 sqLiteConnection->Close();
				 }
				 catch (Exception^ e)
				 {
					 logger->Fatal(e->Message);
				 }
			 }

	private: System::Void btnCreateSqliteTable_Click(System::Object^  sender, System::EventArgs^  e) {
		createSQLiteTableStructure();
	}

			 void insertIntoSQLiteKundenTable()
			 {
				 try
				 {
					 sqLiteConnection->Open();
					 String^ insertIntoKundenSQLite = "INSERT INTO Kunden (vorname,nachname) VALUES('Heinz','Becker')";
					 SQLite::SQLiteCommand^ insertCommand = gcnew SQLite::SQLiteCommand(insertIntoKundenSQLite, sqLiteConnection);
					 insertCommand->ExecuteNonQuery();
					 getLastInsertedIdSQLite();
					 //sqLiteConnection->Close();
				 }
				 catch (Exception^ e)
				 {
					 logger->Fatal(e->Message);
				 }
			 }

	private: System::Void btnInsertSQLiteKunde_Click(System::Object^  sender, System::EventArgs^  e) {
		insertIntoSQLiteKundenTable();
	}

			 void readSQLiteKundenTable()
			 {
				 sqLiteConnection->Open();
				 String^ selectKundenSQLiteString = "SELECT * FROM Kunden";
				 SQLite::SQLiteCommand^ selectCommand = gcnew SQLite::SQLiteCommand(selectKundenSQLiteString, sqLiteConnection);
				 SQLite::SQLiteDataReader^ sDR = selectCommand->ExecuteReader();

				 while (sDR->Read())
				 {
					 txtSQLite->AppendText((Int64)sDR["id"] + " " + (String^)sDR["vorname"] + " " + (String^)sDR["nachname"] + "\r\n");
				 }
				 sqLiteConnection->Close();
			 }

	private: System::Void btnReadSQLiteKunden_Click(System::Object^  sender, System::EventArgs^  e) {
		readSQLiteKundenTable();
	}

			 int getLastInsertedIdSQLServer(String^ tableName)
			 {
				 localhostConnection->Open();
				 System::String^ identitySQL = "SELECT IDENT_CURRENT('" + tableName + "')";
				 System::Data::SqlClient::SqlCommand^ selectCommand =
					 gcnew System::Data::SqlClient::SqlCommand(identitySQL, localhostConnection);

				 System::Data::SqlClient::SqlDataReader^ reader = selectCommand->ExecuteReader();
				 reader->Read();
				 int lastInsertedId = int::Parse(reader[0]->ToString());

				 localhostConnection->Close();
				 return lastInsertedId;
			 }

			 int getLastInsertedIdSQLite() {
				 /* sqLiteConnection->Open();*/
				 String^ sql = "select last_insert_rowid()";
				 SQLite::SQLiteCommand^ selectCommand = gcnew SQLite::SQLiteCommand(sql, sqLiteConnection);
				 int lastId = (Int64)selectCommand->ExecuteScalar();
				 logger->Debug(lastId);
				 sqLiteConnection->Close();
				 return lastId;
			 }

	private: System::Void btnGetLastInsertedId_Click(System::Object^  sender, System::EventArgs^  e) {
		logger->Debug(getLastInsertedIdSQLServer("Kunden"));
	}

	private: System::Void btnGetLastInsertedSQLiteId_Click(System::Object^  sender, System::EventArgs^  e) {
		getLastInsertedIdSQLite();
	}

			 void createRechnung() {
				 Rechnung^ rechnung = gcnew Rechnung;
				 rechnung->kunde->id = 59;
				 rechnung->kunde->load();
				 rechnung->rechnungsnummer = "R1";
				 rechnung->datum = DateTime::Now;
				 rechnung->zahlungsziel = DateTime::Now + TimeSpan(3, 0, 0, 0);
				 logger->Debug(rechnung->insert());

			 }

			 void createRechnungsposition() {
				 Rechnungsposition^ rechnungsposition = gcnew Rechnungsposition;
				 rechnungsposition->rechnung->id = 6;
				 rechnungsposition->rechnung->load();

				 rechnungsposition->produkt->id = 3;
				 rechnungsposition->produkt->load();

				 rechnungsposition->position = 1;
				 rechnungsposition->datum = System::DateTime::Now;

				 rechnungsposition->menge = 10;
				 rechnungsposition->insert();

				 rechnungsposition = gcnew Rechnungsposition;
				 rechnungsposition->rechnung->id = 6;
				 rechnungsposition->rechnung->load();

				 rechnungsposition->produkt->id = 2;
				 rechnungsposition->produkt->load();

				 rechnungsposition->position = 2;
				 rechnungsposition->datum = System::DateTime::Now;

				 rechnungsposition->menge = 5;
				 rechnungsposition->insert();

				 rechnungsposition = gcnew Rechnungsposition;
				 rechnungsposition->rechnung->id = 6;
				 rechnungsposition->rechnung->load();

				 rechnungsposition->produkt->id = 1;
				 rechnungsposition->produkt->load();

				 rechnungsposition->position = 3;
				 rechnungsposition->datum = System::DateTime::Now;

				 rechnungsposition->menge = 2;
				 rechnungsposition->insert();

			 }

	private: System::Void btnCreateRechnung_Click(System::Object^  sender, System::EventArgs^  e) {
		createRechnung();
	}

	private: System::Void btnCreateRechnungspositionen_Click(System::Object^  sender, System::EventArgs^  e) {
		createRechnungsposition();
	}

	private: System::Void btnShowRechnung_Click(System::Object^  sender, System::EventArgs^  e) {

	}

			 void showRechnungById(int id) {
				 Rechnung^ rechnung = gcnew Rechnung;
				 rechnung->id = id;
				 rechnung->load();

				 txtSQLOutput->AppendText(rechnung->kunde->vorname + " " + rechnung->kunde->nachname + "\t\t\t" + rechnung->datum->ToShortDateString() + "\r\n");
				 txtSQLOutput->AppendText("\t\t\tZahlungsziel:" + rechnung->zahlungsziel->ToShortDateString() + "\r\n");
				 txtSQLOutput->AppendText(rechnung->kunde->plz + " " + rechnung->kunde->ort + "\r\n");

				 Rechnungsposition^ rp = gcnew Rechnungsposition;
				 rp->id = rechnung->id;
				 txtSQLOutput->AppendText("\r\n");
				 for each(Rechnungsposition^ eineRP in  rp->getRechnungspositionen()) {
					 txtSQLOutput->AppendText(eineRP->position + "\t" + eineRP->produkt->beschreibung + "\t" + eineRP->produkt->vkpreis + "\t"
						 + eineRP->menge + "\t" + (eineRP->produkt->vkpreis * eineRP->menge) + "\r\n");
				 }
				 txtSQLOutput->AppendText("Summe:\t\t\t\t\t" + rp->getRechnungspositionenSumme() + "\r\n");
				 txtSQLOutput->AppendText("      \t\t\t\t\t---------------\r\n");
				 txtSQLOutput->AppendText("      \t\t\t\t\t---------------\r\n");
			 }
	private: System::Void cmbRechnungsids_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		showRechnungById(int::Parse(cmbRechnungsids->SelectedItem->ToString()));
	}
	private: System::Void btnOpenRechnungsFenster_Click(System::Object^  sender, System::EventArgs^  e) {
		RechnungsManagementWindow^ rmW = gcnew RechnungsManagementWindow;
		rmW->ShowDialog();//Modal
	}

			 static void doCount() {
				 for (int i = 0; i < 1000;i++) {
					 Application::DoEvents();
					 System::Diagnostics::Debug::WriteLine(i);
				 }
			 }
	private: System::Void btnThreadStart_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Threading::Thread^ thread =
			gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(&doCount));
		thread->Start();
	}

			 System::Collections::Generic::List<System::Threading::Thread^>^ threadList;
			 System::Collections::Generic::List<CounterSlave^>^ workerList;

			 void startWorkers() {
				 threadList = gcnew System::Collections::Generic::List<System::Threading::Thread^>;
				 workerList = gcnew System::Collections::Generic::List<CounterSlave^>;

				 for (int threadCounter = 0; threadCounter < 10;threadCounter++) {
					 CounterSlave^ worker = gcnew CounterSlave(0, 100, "Arbeiter " + threadCounter);
					 workerList->Add(worker);
					 System::Threading::Thread^ t = gcnew System::Threading::Thread(
						 gcnew System::Threading::ThreadStart(worker, &CounterSlave::startWorking));
					 threadList->Add(t);

					 if (threadCounter == 2) {
						 t->Priority = System::Threading::ThreadPriority::Highest;
					 }
					 else {
						 t->Priority = System::Threading::ThreadPriority::Lowest;
					 }
					 t->Start();
				 }
			 }

	private: System::Void btnStartWorker_Click(System::Object^  sender, System::EventArgs^  e) {
		startWorkers();
	}
	private: System::Void btnPlayWav_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer("d:\\GIGGLE.wav");
		System::Media::SoundPlayer^ player1 = gcnew System::Media::SoundPlayer("d:\\APPLAUSE.wav");
		System::Media::SoundPlayer^ player2 = gcnew System::Media::SoundPlayer("d:\\ARROW.wav");
		player->Play();
		/*player1->Play();
		player2->Play();*/
	}
	private: System::Void btnScreenshot_Click(System::Object^  sender, System::EventArgs^  e) {
		Bitmap^ screenshotImage = gcnew Bitmap(Screen::PrimaryScreen->Bounds.Width,
			Screen::PrimaryScreen->Bounds.Height);

		Graphics^ g = Graphics::FromImage(screenshotImage);

		g->CopyFromScreen(Screen::PrimaryScreen->Bounds.X,
			Screen::PrimaryScreen->Bounds.Y,
			0, 0,
			screenshotImage->Size,
			CopyPixelOperation::SourceCopy);
		screenshotImage->Save("d:\\screen.bmp");

		//Form to Bitmap
		Bitmap^ formImage = gcnew Bitmap(this->Width,
			this->Height);

		this->DrawToBitmap(formImage, Rectangle(0, 0, this->Width, this->Height));

		formImage->Save("d:\\form.bmp");
	}
	private: System::Void btnProcesses_Click(System::Object^  sender, System::EventArgs^  e) {
		for each(System::Diagnostics::Process^ p in System::Diagnostics::Process::GetProcesses()) {
			txtThreading->AppendText(p->ProcessName + " " + p->Id + "\r\n");
			if (p->ProcessName == "notepad++") {
				p->Kill();
			}
		}


	}
	private: System::Void btnKillProcess_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Diagnostics::Process::GetProcessById(Decimal::ToInt32(numProcessId->Value))->Kill();
	}
	private: System::Void btnStartProcessByName_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Diagnostics::Process^ notepadProcess = System::Diagnostics::Process::Start(txtProcessName->Text);
	}
	};
}
