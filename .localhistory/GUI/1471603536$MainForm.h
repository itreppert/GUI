#pragma once
#include "Test.h"

namespace GUI
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			step = 0;
			richTextBox1->LoadFile("d:\\Dokument.rtf");
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

	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Button^  btnDrawLine;




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
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->btnDrawLine = (gcnew System::Windows::Forms::Button());
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
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
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
			this->panel6->SuspendLayout();
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
			this->tableLayoutPanel1->Size = System::Drawing::Size(599, 458);
			this->tableLayoutPanel1->TabIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->ContextMenuStrip = this->contextMenuStrip1;
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Location = System::Drawing::Point(302, 3);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(294, 223);
			this->textBox1->TabIndex = 2;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3)
			{
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
			this->panel1->Size = System::Drawing::Size(293, 223);
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
			this->panel2->Location = System::Drawing::Point(3, 232);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(293, 223);
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
			this->panel3->Controls->Add(this->btnAddDoubles);
			this->panel3->Controls->Add(this->label1);
			this->panel3->Controls->Add(this->txtZweiteZahl);
			this->panel3->Controls->Add(this->txtErsteZahl);
			this->panel3->Controls->Add(this->richTextBox1);
			this->panel3->Controls->Add(this->progressBar1);
			this->panel3->Controls->Add(this->pictureBox1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(302, 232);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(294, 223);
			this->panel3->TabIndex = 4;
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
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 24);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(613, 490);
			this->tabControl1->TabIndex = 4;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->tableLayoutPanel1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(605, 464);
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
			this->tabPage2->Size = System::Drawing::Size(605, 464);
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
			this->tableLayoutPanel2->Size = System::Drawing::Size(599, 458);
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
			this->panel4->Size = System::Drawing::Size(293, 452);
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
			this->txtCollections->Location = System::Drawing::Point(302, 3);
			this->txtCollections->Multiline = true;
			this->txtCollections->Name = L"txtCollections";
			this->txtCollections->Size = System::Drawing::Size(294, 452);
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
			this->tabPage3->Size = System::Drawing::Size(605, 464);
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
			this->tabPage4->Size = System::Drawing::Size(605, 464);
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
			this->tableLayoutPanel3->Controls->Add(this->panel6, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(599, 458);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// pnlDrawing
			// 
			this->pnlDrawing->BackColor = System::Drawing::Color::Gainsboro;
			this->pnlDrawing->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlDrawing->Location = System::Drawing::Point(302, 3);
			this->pnlDrawing->Name = L"pnlDrawing";
			this->pnlDrawing->Size = System::Drawing::Size(294, 452);
			this->pnlDrawing->TabIndex = 0;
			this->pnlDrawing->Click += gcnew System::EventHandler(this, &MainForm::pnlDrawing_Click);
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->btnDrawLine);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel6->Location = System::Drawing::Point(3, 3);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(293, 452);
			this->panel6->TabIndex = 1;
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
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3)
			{
				this->toolStripMenuItem1,
					this->toolStripMenuItem3, this->toolStripMenuItem4
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(613, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5)
			{
				this->toolStripMenuItem2,
					this->toolStripSeparator1, this->mnuSaveFileDialog, this->mnuRichtextBox, this->mnuFolderBrowser
			});
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(46, 20);
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
			this->toolStripMenuItem3->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2)
			{
				this->mnuFarben,
					this->mnuSchriftart
			});
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(90, 20);
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
			this->toolStripMenuItem4->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3)
			{
				this->mnuButtonsHerstellen,
					this->mnuListControls, this->mnuTextBoxenHerstellen
			});
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(54, 20);
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
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// fontDialog1
			// 
			this->fontDialog1->ShowColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(613, 514);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
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
			this->panel6->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

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
				textBox1->AppendText("User cancelled the action !\r\n");
			}
			else if (dR == System::Windows::Forms::DialogResult::Yes)
			{
				textBox1->AppendText("You're amazing !!\r\n");
			}
			else if (dR == System::Windows::Forms::DialogResult::No)
			{
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
					 dynamicTextBox->TabIndex = 67;					 dynamicTextBox->TextChanged += gcnew System::EventHandler(this, &MainForm::dynamicTextBoxesTextChanged);
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
		System::Drawing::Graphics^ graphics = pnlDrawing->CreateGraphics();

		System::Drawing::Pen^ penRed = gcnew System::Drawing::Pen(Color::Red);
		System::Drawing::Pen^ penBlue = gcnew System::Drawing::Pen(Color::Blue);
		System::Drawing::Pen^ penGreen = gcnew System::Drawing::Pen(Color::Green);
		System::Drawing::Brush^  brushYellow = gcnew System::Drawing::SolidBrush(Color::Yellow);

		graphics->DrawLine(penRed, 0, 0, 100, 300);
		graphics->DrawLine(penBlue, 100, 200, 0, 0);
		graphics->DrawEllipse(penGreen, 20, 90, 40, 20);
		graphics->FillRectangle(brushYellow, 70, 70, 30, 60);

	}
			 System::Drawing::Point lastPoint;
	private: System::Void pnlDrawing_Click(System::Object^  sender, System::EventArgs^  e)
	{
		System::Drawing::Point actualPosition = pnlDrawing->PointToClient(this->Cursor->Position);



		System::Diagnostics::Debug::WriteLine(actualPosition.ToString());
	}
};
}
