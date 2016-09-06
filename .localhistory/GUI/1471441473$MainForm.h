#pragma once

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
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
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
	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnComboremoveItem = (gcnew System::Windows::Forms::Button());
			this->btnComboAddItem = (gcnew System::Windows::Forms::Button());
			this->btnComboboxValue = (gcnew System::Windows::Forms::Button());
			this->btnRadioButton = (gcnew System::Windows::Forms::Button());
			this->btnCheckbox = (gcnew System::Windows::Forms::Button());
			this->btnChangeTab = (gcnew System::Windows::Forms::Button());
			this->cmdChangeFormColor = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->cmbBlubb = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->btnComboInsert = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
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
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(558, 491);
			this->tableLayoutPanel1->TabIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Location = System::Drawing::Point(282, 3);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(273, 239);
			this->textBox1->TabIndex = 2;
			// 
			// panel1
			// 
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
			this->panel1->Size = System::Drawing::Size(273, 239);
			this->panel1->TabIndex = 1;
			// 
			// btnComboremoveItem
			// 
			this->btnComboremoveItem->Location = System::Drawing::Point(105, 149);
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
			this->panel2->Controls->Add(this->cmbBlubb);
			this->panel2->Controls->Add(this->groupBox1);
			this->panel2->Controls->Add(this->checkBox1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(3, 248);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(273, 240);
			this->panel2->TabIndex = 3;
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
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(572, 523);
			this->tabControl1->TabIndex = 4;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->tableLayoutPanel1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(564, 497);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Basics";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(564, 497);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Other";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(564, 497);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"tabPage3";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// btnComboInsert
			// 
			this->btnComboInsert->Location = System::Drawing::Point(8, 178);
			this->btnComboInsert->Name = L"btnComboInsert";
			this->btnComboInsert->Size = System::Drawing::Size(109, 23);
			this->btnComboInsert->TabIndex = 7;
			this->btnComboInsert->Text = L"Combo insert Item";
			this->btnComboInsert->UseVisualStyleBackColor = true;
			this->btnComboInsert->Click += gcnew System::EventHandler(this, &MainForm::btnComboInsert_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(572, 523);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->ResumeLayout(false);

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
};
}
