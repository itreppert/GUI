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
	/// Zusammenfassung f�r MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			step = 0;
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
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode f�r die Designerunterst�tzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor ge�ndert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
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
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->txtAnswers = (gcnew System::Windows::Forms::TextBox());
			this->txtQuestions = (gcnew System::Windows::Forms::TextBox());
			this->btnNextStep = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tableLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage3->SuspendLayout();
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
			this->tableLayoutPanel1->Size = System::Drawing::Size(558, 467);
			this->tableLayoutPanel1->TabIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Location = System::Drawing::Point(282, 3);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(273, 227);
			this->textBox1->TabIndex = 2;
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
			this->panel1->Size = System::Drawing::Size(273, 227);
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
			this->panel2->Controls->Add(this->trackBar1);
			this->panel2->Controls->Add(this->numericUpDown1);
			this->panel2->Controls->Add(this->maskedTextBox1);
			this->panel2->Controls->Add(this->listBox1);
			this->panel2->Controls->Add(this->cmbBlubb);
			this->panel2->Controls->Add(this->groupBox1);
			this->panel2->Controls->Add(this->checkBox1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(3, 236);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(273, 228);
			this->panel2->TabIndex = 3;
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
			this->panel3->Controls->Add(this->richTextBox1);
			this->panel3->Controls->Add(this->progressBar1);
			this->panel3->Controls->Add(this->pictureBox1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(282, 236);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(273, 228);
			this->panel3->TabIndex = 4;
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
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 24);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(572, 499);
			this->tabControl1->TabIndex = 4;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->tableLayoutPanel1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(564, 473);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Basics";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(564, 473);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Other";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->txtAnswers);
			this->tabPage3->Controls->Add(this->txtQuestions);
			this->tabPage3->Controls->Add(this->btnNextStep);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(564, 473);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"tabPage3";
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
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2)
			{
				this->toolStripMenuItem1,
					this->toolStripMenuItem3
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(572, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3)
			{
				this->toolStripMenuItem2,
					this->toolStripSeparator1, this->toolStripMenuItem4
			});
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(46, 20);
			this->toolStripMenuItem1->Text = L"Datei";
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(152, 22);
			this->toolStripMenuItem2->Text = L"�ffnen";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItem2_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(90, 20);
			this->toolStripMenuItem3->Text = L"Einstellungen";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(149, 6);
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(152, 22);
			this->toolStripMenuItem4->Text = L"Speichern";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(572, 523);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
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
			txtQuestions->AppendText("Danke f�r's Gespr�ch !\r\n");
			txtAnswers->Clear();
		}
		step++;
	}

	private: System::Void btnChangeFromAnotherClass_Click(System::Object^  sender, System::EventArgs^  e)
	{
		t = gcnew Test(textBox1);
		t->changeTextBoxText();
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
		}else{
			timer1->Enabled = false;
		}
	}
	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e)
	{
		textBox1->AppendText(trackBar1->Value + "\r\n");
	}
private: System::Void toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e)
{
	System::Windows::Forms::DialogResult dialogResult=  openFileDialog1->ShowDialog();
}
};
}
