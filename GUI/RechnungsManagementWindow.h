#pragma once
#include "Rechnung.h"
#include "Rechnungsposition.h"

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für RechnungsManagementWindow
	/// </summary>
	public ref class RechnungsManagementWindow : public System::Windows::Forms::Form
	{
	public:
		RechnungsManagementWindow(void)
		{
			InitializeComponent();
			fillDgvProdukte();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~RechnungsManagementWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtKundenid;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DateTimePicker^  dtpZahlungsziel;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btnCreateRechnung;
	private: System::Windows::Forms::TextBox^  txtRechnungsNummer;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  txtProduktId;
	private: System::Windows::Forms::TextBox^  txtMenge;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  btnRechnungspositionAnlegen;
	private: System::Windows::Forms::DataGridView^  dgvProdukte;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  beschreibung;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ekpreis;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  vkpreis;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  lagerbestand;


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
			this->txtKundenid = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dtpZahlungsziel = (gcnew System::Windows::Forms::DateTimePicker());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnCreateRechnung = (gcnew System::Windows::Forms::Button());
			this->txtRechnungsNummer = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtProduktId = (gcnew System::Windows::Forms::TextBox());
			this->txtMenge = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnRechnungspositionAnlegen = (gcnew System::Windows::Forms::Button());
			this->dgvProdukte = (gcnew System::Windows::Forms::DataGridView());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->beschreibung = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ekpreis = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->vkpreis = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lagerbestand = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProdukte))->BeginInit();
			this->SuspendLayout();
			// 
			// txtKundenid
			// 
			this->txtKundenid->Location = System::Drawing::Point(50, 5);
			this->txtKundenid->Name = L"txtKundenid";
			this->txtKundenid->Size = System::Drawing::Size(100, 20);
			this->txtKundenid->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Kd.Nr.:";
			// 
			// dtpZahlungsziel
			// 
			this->dtpZahlungsziel->Location = System::Drawing::Point(50, 32);
			this->dtpZahlungsziel->Name = L"dtpZahlungsziel";
			this->dtpZahlungsziel->Size = System::Drawing::Size(200, 20);
			this->dtpZahlungsziel->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"ZZiel:";
			// 
			// btnCreateRechnung
			// 
			this->btnCreateRechnung->Location = System::Drawing::Point(256, 29);
			this->btnCreateRechnung->Name = L"btnCreateRechnung";
			this->btnCreateRechnung->Size = System::Drawing::Size(75, 23);
			this->btnCreateRechnung->TabIndex = 4;
			this->btnCreateRechnung->Text = L"Anlegen";
			this->btnCreateRechnung->UseVisualStyleBackColor = true;
			this->btnCreateRechnung->Click += gcnew System::EventHandler(this, &RechnungsManagementWindow::btnCreateRechnung_Click);
			// 
			// txtRechnungsNummer
			// 
			this->txtRechnungsNummer->Location = System::Drawing::Point(50, 91);
			this->txtRechnungsNummer->Name = L"txtRechnungsNummer";
			this->txtRechnungsNummer->Size = System::Drawing::Size(100, 20);
			this->txtRechnungsNummer->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(4, 98);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Re.Nr.:";
			// 
			// txtProduktId
			// 
			this->txtProduktId->Location = System::Drawing::Point(214, 91);
			this->txtProduktId->Name = L"txtProduktId";
			this->txtProduktId->Size = System::Drawing::Size(100, 20);
			this->txtProduktId->TabIndex = 7;
			// 
			// txtMenge
			// 
			this->txtMenge->Location = System::Drawing::Point(388, 91);
			this->txtMenge->Name = L"txtMenge";
			this->txtMenge->Size = System::Drawing::Size(100, 20);
			this->txtMenge->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(174, 98);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(34, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"P.Nr.:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(341, 98);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Menge";
			// 
			// btnRechnungspositionAnlegen
			// 
			this->btnRechnungspositionAnlegen->Location = System::Drawing::Point(549, 88);
			this->btnRechnungspositionAnlegen->Name = L"btnRechnungspositionAnlegen";
			this->btnRechnungspositionAnlegen->Size = System::Drawing::Size(75, 23);
			this->btnRechnungspositionAnlegen->TabIndex = 11;
			this->btnRechnungspositionAnlegen->Text = L"Anlegen";
			this->btnRechnungspositionAnlegen->UseVisualStyleBackColor = true;
			this->btnRechnungspositionAnlegen->Click += gcnew System::EventHandler(this, &RechnungsManagementWindow::btnRechnungspositionAnlegen_Click);
			// 
			// dgvProdukte
			// 
			this->dgvProdukte->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvProdukte->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->name, this->beschreibung,
					this->ekpreis, this->vkpreis, this->lagerbestand
			});
			this->dgvProdukte->Location = System::Drawing::Point(7, 200);
			this->dgvProdukte->MultiSelect = false;
			this->dgvProdukte->Name = L"dgvProdukte";
			this->dgvProdukte->Size = System::Drawing::Size(678, 242);
			this->dgvProdukte->TabIndex = 12;
			// 
			// name
			// 
			this->name->HeaderText = L"name";
			this->name->Name = L"name";
			// 
			// beschreibung
			// 
			this->beschreibung->HeaderText = L"beschreibung";
			this->beschreibung->Name = L"beschreibung";
			// 
			// ekpreis
			// 
			this->ekpreis->HeaderText = L"ekpreis";
			this->ekpreis->Name = L"ekpreis";
			// 
			// vkpreis
			// 
			this->vkpreis->HeaderText = L"vkpreis";
			this->vkpreis->Name = L"vkpreis";
			// 
			// lagerbestand
			// 
			this->lagerbestand->HeaderText = L"lagerbestand";
			this->lagerbestand->Name = L"lagerbestand";
			// 
			// RechnungsManagementWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(697, 446);
			this->Controls->Add(this->dgvProdukte);
			this->Controls->Add(this->btnRechnungspositionAnlegen);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txtMenge);
			this->Controls->Add(this->txtProduktId);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtRechnungsNummer);
			this->Controls->Add(this->btnCreateRechnung);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dtpZahlungsziel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtKundenid);
			this->Name = L"RechnungsManagementWindow";
			this->Text = L"RechnungsManagementWindow";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvProdukte))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int actualRechnungsid;
	private: System::Void btnCreateRechnung_Click(System::Object^  sender, System::EventArgs^  e) {
		int rechnungsid = createRechnung(int::Parse(txtKundenid->Text), dtpZahlungsziel->Value);
		actualRechnungsid = rechnungsid;
		txtRechnungsNummer->Text = actualRechnungsid.ToString();
	}

			 int createRechnung(int kundenid, DateTime zahlungszielDays) {
				 Rechnung^ rechnung = gcnew Rechnung;
				 rechnung->kunde->id = kundenid;
				 //rechnung->kunde->load();
				 rechnung->rechnungsnummer = "R1";
				 rechnung->datum = DateTime::Now;
				 rechnung->zahlungsziel = zahlungszielDays;
				 int lastCreatedId = rechnung->insert();
				 logger->Debug(lastCreatedId);
				 return lastCreatedId;
			 }

			 int createRechnungsposition(int rechnungsnummer, int produktid, int menge) {
				 Rechnungsposition^ rp = gcnew Rechnungsposition;

				 rp->rechnung->id = rechnungsnummer;
				 //rp->rechnung->load();

				 rp->produkt->id = produktid;
				 //rp->produkt->load();

				 rp->menge = menge;
				 rp->datum = DateTime::Now;
				 int insertedRechnungspositionId = rp->insert();

				 logger->Debug(insertedRechnungspositionId);
				 return insertedRechnungspositionId;
			 }

	private:
		static NLog::Logger^ logger = NLog::LogManager::GetCurrentClassLogger();
	private: System::Void btnRechnungspositionAnlegen_Click(System::Object^  sender, System::EventArgs^  e) {
		createRechnungsposition(actualRechnungsid, int::Parse(txtProduktId->Text), int::Parse(txtMenge->Text));
	}

			 void fillDgvProdukte() {
				 dgvProdukte->Rows->Add(gcnew array<System::Object^>(5) {
					 "1", "2", "3", "4","5"
				 });
					 
			 }
	};
}
