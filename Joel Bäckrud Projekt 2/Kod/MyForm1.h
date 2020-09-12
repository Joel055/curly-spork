#pragma once
#include <cctype>
#include "Contact.h"

namespace JoelBäckrudProjekt2 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
		// List samlingen som alla Contact objekt lagras i. Objekten innehåller alla personuppgifter.
		List<Contact^>^ contacts;

		// Variabler som ändras vid byte av vald radiobutton och som bestämmer om namn eller efternamn visas först och bakrundsbild eller ingen bakrundsbild.
		bool isFirstName;
		bool isBackround;
		// Beskriver dessa 3 variabler och deras användning i funktionerna där de används.
	    bool fNameOK;
	    bool sNameOK;
	    bool tNumOK;

		// Dessa 5 variabler nedan är min lösning på ett väldigt frustrerande problem med winforms Selection_Changed event när de används till GridView.
		// När man klickar på en annan rad i GridView så anropas dataGridView1_SelectionChanged funktionen. I denna funktion så har jag 
		// gjort så att om användaren klickar på en en rad där det finns personuppgifter(radindex som är mindre än contacts->Count)
		// så ska dessa uppgifter klistras in i sök/edit groupboxens textboxar(redigeringsläge) och om man klickar på en tom gridview rad så ändras det till sökläge. 
		// Grejen är den att jag har vid ett antal tillfällen i programmet gjort så att 
		// den markerade raden ändras programmatiskt, alltså utan att användaren byter rad själv genom att klicka. Detta triggerar dataGridView1_SelectionChanged eventen 
		// men av någon anledning så ligger gridView->CurrentCell->RowIndex kvar på samma plats som innan bytet av markerad rad skedde.
		// Så om jag låg på rad 1 som har namnet Joel Bäckrud 0709390909 skrivet i sig och programmet flyttar den markerade index till t.ex rad 5 så 
		// kommer fortfarande värdet för gridviewindexet innan bytet visas. Dessutom så kommer knapparna vara aktiverade som om man hade markerat en rad med uppgifter på.
		// Dessa variabler gör så att dataGridView1_SelectionChanged inte körs om man precis lagt till en person (add = true) eller om man precis sökt(search = true)
		// eller om man sökt efter en person och sedan klickar delete på denna (searchDel = true) (searchIndex = i (från sökfunktionen)
		// Vid dessa tillfällen så flyttas nämligen den markerade gridview raden programmatiskt.
		// Alla variabler behövs eftersom om man t.ex söker ett namn så behövs gridview_selectedchange ignoreras, och om man sen
		// undertiden man är på samma index vill edita så behöver man använda searchIndex variabeln för att få rätt index, och sen om man tar bort
		// på samma rad utan att flytta så behövs searchIndex igen för att kunna ta bort på rätt index. Alla dessa variabler blir ju som sagt false 
		// igen efter de gjort sitt jobb, därför behövs 1 för varje event typ.
		bool add;
		bool search;
		bool searchDel;
		bool searchEdit;
		bool btnEditMode;
		
		int searchIndex;

	public:
		MyForm1(void)
		{
			InitializeComponent();
			isFirstName = true;
			isBackround = true;
			add = false;
			search = false;
			searchDel = false;
			searchEdit = false;
			btnEditMode = false;
			rbtnFirstName->Checked = true;
			rbtnBackroundOn->Checked = true;
			contacts = gcnew List<Contact^>();
			dataGridView1->Rows->Add(30);
		}

    
	protected:
		// Dekonstruktor
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  lblFirstName;
	private: System::Windows::Forms::TextBox^  tbxFirstName;
	private: System::Windows::Forms::Label^  lblSurName;
	private: System::Windows::Forms::TextBox^  tbxSurName;
	private: System::Windows::Forms::Label^  lblPhoneNumber;
	private: System::Windows::Forms::TextBox^  tbxPhoneNumber;
	private: System::Windows::Forms::Button^  btnAdd;
	private: System::Windows::Forms::RadioButton^  rbtnFirstName;
	private: System::Windows::Forms::RadioButton^  rbtnSurName;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::GroupBox^  gbxNewPerson;
	private: System::Windows::Forms::GroupBox^  gbxSearchEdit;
	private: System::Windows::Forms::TextBox^  tbxFirstName2;
	private: System::Windows::Forms::Label^  lblFirstName2;
	private: System::Windows::Forms::Label^  lblSurName2;
	private: System::Windows::Forms::TextBox^  tbxSurName2;
	private: System::Windows::Forms::Button^  btnSearch;
	private: System::Windows::Forms::Label^  lblPhoneNumber2;
	private: System::Windows::Forms::TextBox^  tbxPhoneNumber2;
	private: System::Windows::Forms::Button^  btnEdit;
	private: System::Windows::Forms::Button^  btnDelete;
	private: System::Windows::Forms::Label^  lblInfo;
	private: System::Windows::Forms::Label^  lblInfo2;
	private: System::Windows::Forms::Label^  lblInfoContinuation;
	private: System::Windows::Forms::RadioButton^  rbtnPerformanceMode;
	private: System::Windows::Forms::RadioButton^  rbtnBackroundOn;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;


	
#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->lblFirstName = (gcnew System::Windows::Forms::Label());
			this->tbxFirstName = (gcnew System::Windows::Forms::TextBox());
			this->lblSurName = (gcnew System::Windows::Forms::Label());
			this->tbxSurName = (gcnew System::Windows::Forms::TextBox());
			this->lblPhoneNumber = (gcnew System::Windows::Forms::Label());
			this->tbxPhoneNumber = (gcnew System::Windows::Forms::TextBox());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->rbtnFirstName = (gcnew System::Windows::Forms::RadioButton());
			this->rbtnSurName = (gcnew System::Windows::Forms::RadioButton());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->gbxNewPerson = (gcnew System::Windows::Forms::GroupBox());
			this->gbxSearchEdit = (gcnew System::Windows::Forms::GroupBox());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->tbxFirstName2 = (gcnew System::Windows::Forms::TextBox());
			this->btnEdit = (gcnew System::Windows::Forms::Button());
			this->lblFirstName2 = (gcnew System::Windows::Forms::Label());
			this->lblSurName2 = (gcnew System::Windows::Forms::Label());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->tbxSurName2 = (gcnew System::Windows::Forms::TextBox());
			this->lblPhoneNumber2 = (gcnew System::Windows::Forms::Label());
			this->tbxPhoneNumber2 = (gcnew System::Windows::Forms::TextBox());
			this->lblInfo = (gcnew System::Windows::Forms::Label());
			this->lblInfo2 = (gcnew System::Windows::Forms::Label());
			this->lblInfoContinuation = (gcnew System::Windows::Forms::Label());
			this->rbtnPerformanceMode = (gcnew System::Windows::Forms::RadioButton());
			this->rbtnBackroundOn = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->gbxNewPerson->SuspendLayout();
			this->gbxSearchEdit->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblFirstName
			// 
			resources->ApplyResources(this->lblFirstName, L"lblFirstName");
			this->lblFirstName->BackColor = System::Drawing::Color::Transparent;
			this->lblFirstName->ForeColor = System::Drawing::Color::White;
			this->lblFirstName->Name = L"lblFirstName";
			// 
			// tbxFirstName
			// 
			resources->ApplyResources(this->tbxFirstName, L"tbxFirstName");
			this->tbxFirstName->Name = L"tbxFirstName";
			this->tbxFirstName->TextChanged += gcnew System::EventHandler(this, &MyForm1::tbx_TextChanged);
			this->tbxFirstName->Enter += gcnew System::EventHandler(this, &MyForm1::tbx_Enter);
			this->tbxFirstName->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm1::tbxNameInput_KeyPress);
			// 
			// lblSurName
			// 
			resources->ApplyResources(this->lblSurName, L"lblSurName");
			this->lblSurName->BackColor = System::Drawing::Color::Transparent;
			this->lblSurName->ForeColor = System::Drawing::Color::White;
			this->lblSurName->Name = L"lblSurName";
			// 
			// tbxSurName
			// 
			resources->ApplyResources(this->tbxSurName, L"tbxSurName");
			this->tbxSurName->Name = L"tbxSurName";
			this->tbxSurName->TextChanged += gcnew System::EventHandler(this, &MyForm1::tbx_TextChanged);
			this->tbxSurName->Enter += gcnew System::EventHandler(this, &MyForm1::tbx_Enter);
			this->tbxSurName->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm1::tbxNameInput_KeyPress);
			// 
			// lblPhoneNumber
			// 
			resources->ApplyResources(this->lblPhoneNumber, L"lblPhoneNumber");
			this->lblPhoneNumber->BackColor = System::Drawing::Color::Transparent;
			this->lblPhoneNumber->ForeColor = System::Drawing::Color::White;
			this->lblPhoneNumber->Name = L"lblPhoneNumber";
			// 
			// tbxPhoneNumber
			// 
			resources->ApplyResources(this->tbxPhoneNumber, L"tbxPhoneNumber");
			this->tbxPhoneNumber->Name = L"tbxPhoneNumber";
			this->tbxPhoneNumber->TextChanged += gcnew System::EventHandler(this, &MyForm1::tbx_TextChanged);
			this->tbxPhoneNumber->Enter += gcnew System::EventHandler(this, &MyForm1::tbx_Enter);
			this->tbxPhoneNumber->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm1::tbxTeleInput_KeyPress);
			// 
			// btnAdd
			// 
			resources->ApplyResources(this->btnAdd, L"btnAdd");
			this->btnAdd->ForeColor = System::Drawing::Color::Black;
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &MyForm1::btnAdd_Click);
			// 
			// rbtnFirstName
			// 
			resources->ApplyResources(this->rbtnFirstName, L"rbtnFirstName");
			this->rbtnFirstName->BackColor = System::Drawing::Color::Transparent;
			this->rbtnFirstName->ForeColor = System::Drawing::Color::White;
			this->rbtnFirstName->Name = L"rbtnFirstName";
			this->rbtnFirstName->TabStop = true;
			this->rbtnFirstName->UseVisualStyleBackColor = false;
			// 
			// rbtnSurName
			// 
			resources->ApplyResources(this->rbtnSurName, L"rbtnSurName");
			this->rbtnSurName->BackColor = System::Drawing::Color::Transparent;
			this->rbtnSurName->ForeColor = System::Drawing::Color::White;
			this->rbtnSurName->Name = L"rbtnSurName";
			this->rbtnSurName->TabStop = true;
			this->rbtnSurName->UseVisualStyleBackColor = false;
			this->rbtnSurName->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::rbtnSurName_CheckedChanged);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			resources->ApplyResources(this->dataGridView1, L"dataGridView1");
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowTemplate->Height = 20;
			this->dataGridView1->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->ShowCellErrors = false;
			this->dataGridView1->ShowCellToolTips = false;
			this->dataGridView1->ShowEditingIcon = false;
			this->dataGridView1->ShowRowErrors = false;
			this->dataGridView1->SelectionChanged += gcnew System::EventHandler(this, &MyForm1::dataGridView1_SelectionChanged);
			// 
			// Column1
			// 
			resources->ApplyResources(this->Column1, L"Column1");
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column2
			// 
			resources->ApplyResources(this->Column2, L"Column2");
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Column3
			// 
			resources->ApplyResources(this->Column3, L"Column3");
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// gbxNewPerson
			// 
			this->gbxNewPerson->BackColor = System::Drawing::Color::Transparent;
			this->gbxNewPerson->Controls->Add(this->tbxFirstName);
			this->gbxNewPerson->Controls->Add(this->lblFirstName);
			this->gbxNewPerson->Controls->Add(this->lblSurName);
			this->gbxNewPerson->Controls->Add(this->tbxSurName);
			this->gbxNewPerson->Controls->Add(this->btnAdd);
			this->gbxNewPerson->Controls->Add(this->lblPhoneNumber);
			this->gbxNewPerson->Controls->Add(this->tbxPhoneNumber);
			this->gbxNewPerson->ForeColor = System::Drawing::Color::White;
			resources->ApplyResources(this->gbxNewPerson, L"gbxNewPerson");
			this->gbxNewPerson->Name = L"gbxNewPerson";
			this->gbxNewPerson->TabStop = false;
			// 
			// gbxSearchEdit
			// 
			this->gbxSearchEdit->BackColor = System::Drawing::Color::Transparent;
			this->gbxSearchEdit->Controls->Add(this->btnDelete);
			this->gbxSearchEdit->Controls->Add(this->tbxFirstName2);
			this->gbxSearchEdit->Controls->Add(this->btnEdit);
			this->gbxSearchEdit->Controls->Add(this->lblFirstName2);
			this->gbxSearchEdit->Controls->Add(this->lblSurName2);
			this->gbxSearchEdit->Controls->Add(this->btnSearch);
			this->gbxSearchEdit->Controls->Add(this->tbxSurName2);
			this->gbxSearchEdit->Controls->Add(this->lblPhoneNumber2);
			this->gbxSearchEdit->Controls->Add(this->tbxPhoneNumber2);
			this->gbxSearchEdit->ForeColor = System::Drawing::Color::White;
			resources->ApplyResources(this->gbxSearchEdit, L"gbxSearchEdit");
			this->gbxSearchEdit->Name = L"gbxSearchEdit";
			this->gbxSearchEdit->TabStop = false;
			// 
			// btnDelete
			// 
			resources->ApplyResources(this->btnDelete, L"btnDelete");
			this->btnDelete->ForeColor = System::Drawing::Color::Black;
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &MyForm1::btnDelete_Click);
			// 
			// tbxFirstName2
			// 
			resources->ApplyResources(this->tbxFirstName2, L"tbxFirstName2");
			this->tbxFirstName2->Name = L"tbxFirstName2";
			this->tbxFirstName2->TextChanged += gcnew System::EventHandler(this, &MyForm1::tbx2_TextChanged);
			this->tbxFirstName2->Enter += gcnew System::EventHandler(this, &MyForm1::tbx2_Enter);
			this->tbxFirstName2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm1::tbxNameInput_KeyPress);
			// 
			// btnEdit
			// 
			resources->ApplyResources(this->btnEdit, L"btnEdit");
			this->btnEdit->ForeColor = System::Drawing::Color::Black;
			this->btnEdit->Name = L"btnEdit";
			this->btnEdit->UseVisualStyleBackColor = true;
			this->btnEdit->Click += gcnew System::EventHandler(this, &MyForm1::btnEdit_Click);
			// 
			// lblFirstName2
			// 
			resources->ApplyResources(this->lblFirstName2, L"lblFirstName2");
			this->lblFirstName2->BackColor = System::Drawing::Color::Transparent;
			this->lblFirstName2->ForeColor = System::Drawing::Color::White;
			this->lblFirstName2->Name = L"lblFirstName2";
			// 
			// lblSurName2
			// 
			resources->ApplyResources(this->lblSurName2, L"lblSurName2");
			this->lblSurName2->BackColor = System::Drawing::Color::Transparent;
			this->lblSurName2->ForeColor = System::Drawing::Color::White;
			this->lblSurName2->Name = L"lblSurName2";
			// 
			// btnSearch
			// 
			resources->ApplyResources(this->btnSearch, L"btnSearch");
			this->btnSearch->ForeColor = System::Drawing::Color::Black;
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &MyForm1::btnSearch_Click);
			// 
			// tbxSurName2
			// 
			resources->ApplyResources(this->tbxSurName2, L"tbxSurName2");
			this->tbxSurName2->Name = L"tbxSurName2";
			this->tbxSurName2->TextChanged += gcnew System::EventHandler(this, &MyForm1::tbx2_TextChanged);
			this->tbxSurName2->Enter += gcnew System::EventHandler(this, &MyForm1::tbx2_Enter);
			this->tbxSurName2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm1::tbxNameInput_KeyPress);
			// 
			// lblPhoneNumber2
			// 
			resources->ApplyResources(this->lblPhoneNumber2, L"lblPhoneNumber2");
			this->lblPhoneNumber2->BackColor = System::Drawing::Color::Transparent;
			this->lblPhoneNumber2->ForeColor = System::Drawing::Color::White;
			this->lblPhoneNumber2->Name = L"lblPhoneNumber2";
			// 
			// tbxPhoneNumber2
			// 
			resources->ApplyResources(this->tbxPhoneNumber2, L"tbxPhoneNumber2");
			this->tbxPhoneNumber2->Name = L"tbxPhoneNumber2";
			this->tbxPhoneNumber2->TextChanged += gcnew System::EventHandler(this, &MyForm1::tbx2_TextChanged);
			this->tbxPhoneNumber2->Enter += gcnew System::EventHandler(this, &MyForm1::tbx2_Enter);
			this->tbxPhoneNumber2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm1::tbxTeleInput_KeyPress);
			// 
			// lblInfo
			// 
			resources->ApplyResources(this->lblInfo, L"lblInfo");
			this->lblInfo->BackColor = System::Drawing::Color::Transparent;
			this->lblInfo->ForeColor = System::Drawing::Color::White;
			this->lblInfo->Name = L"lblInfo";
			// 
			// lblInfo2
			// 
			resources->ApplyResources(this->lblInfo2, L"lblInfo2");
			this->lblInfo2->BackColor = System::Drawing::Color::Transparent;
			this->lblInfo2->ForeColor = System::Drawing::Color::White;
			this->lblInfo2->Name = L"lblInfo2";
			// 
			// lblInfoContinuation
			// 
			resources->ApplyResources(this->lblInfoContinuation, L"lblInfoContinuation");
			this->lblInfoContinuation->BackColor = System::Drawing::Color::Transparent;
			this->lblInfoContinuation->ForeColor = System::Drawing::Color::White;
			this->lblInfoContinuation->Name = L"lblInfoContinuation";
			// 
			// rbtnPerformanceMode
			// 
			resources->ApplyResources(this->rbtnPerformanceMode, L"rbtnPerformanceMode");
			this->rbtnPerformanceMode->ForeColor = System::Drawing::Color::White;
			this->rbtnPerformanceMode->Name = L"rbtnPerformanceMode";
			this->rbtnPerformanceMode->TabStop = true;
			this->rbtnPerformanceMode->UseVisualStyleBackColor = true;
			this->rbtnPerformanceMode->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::rbtnPerformanceMode_CheckedChanged);
			// 
			// rbtnBackroundOn
			// 
			resources->ApplyResources(this->rbtnBackroundOn, L"rbtnBackroundOn");
			this->rbtnBackroundOn->ForeColor = System::Drawing::SystemColors::Control;
			this->rbtnBackroundOn->Name = L"rbtnBackroundOn";
			this->rbtnBackroundOn->TabStop = true;
			this->rbtnBackroundOn->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->Controls->Add(this->rbtnFirstName);
			this->groupBox1->Controls->Add(this->rbtnSurName);
			resources->ApplyResources(this->groupBox1, L"groupBox1");
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::Transparent;
			this->groupBox2->Controls->Add(this->rbtnPerformanceMode);
			this->groupBox2->Controls->Add(this->rbtnBackroundOn);
			resources->ApplyResources(this->groupBox2, L"groupBox2");
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->TabStop = false;
			// 
			// MyForm1
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->lblInfoContinuation);
			this->Controls->Add(this->lblInfo2);
			this->Controls->Add(this->lblInfo);
			this->Controls->Add(this->gbxSearchEdit);
			this->Controls->Add(this->gbxNewPerson);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm1";
			this->TransparencyKey = System::Drawing::Color::DarkRed;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm1::MyForm1_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->gbxNewPerson->ResumeLayout(false);
			this->gbxNewPerson->PerformLayout();
			this->gbxSearchEdit->ResumeLayout(false);
			this->gbxSearchEdit->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

    // Hanterar lägg till knappens enable status.
	private: System::Void tbx_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		// Aktiverar "Lägg till" knappen om inmatad information ligger i korrekt intervall och avaktiverar den om de inte gör det.
		// Samt avaktiverar knappen ifall telefon nummret redan finns i GridView
		if (tbxFirstName->Text->Length >= 2 && tbxSurName->Text->Length >= 2 && tbxPhoneNumber->Text->Length >= 8)
		{
			// bool variabel som blir false ifall telefonnummret som är inmatat i tbxPhoneNumer är samma som ett redan tillagt telefonnummer.
			bool unique = true;

			// Alla tidigare telefonnummer jämförs med nuvarande
			// Liknande jämförelsefunktioner behövs ej för namn/förnamn eftersom
			// de ej behöver vara unika.
			for (int i = 0; i < contacts->Count; i++)
			{
				if (tbxPhoneNumber->Text == contacts[i]->eTelephoneNumber)
				{
					unique = false;
					break;
				}

			}

			// Om telefonnummret inte matchar några tidigare så aktiveras knappen, annars avaktiveras
			if (unique)
			{
				btnAdd->Enabled = true;
			}
			else
			{
				btnAdd->Enabled = false;
			}
		}
		else
		{
			btnAdd->Enabled = false;
		} 
	}


    // Kontrollerar text input för namn textboxarna.
	private: System::Void tbxNameInput_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) 
	{
		// Box används till att för urskilja vilken tbx som startade KeyPress event.
		TextBox^ box = (TextBox^)sender;

		// Acceptera endast engelska bokstäver och backspace vid namn inmatning.
		if (!std::isalpha(e->KeyChar) && e->KeyChar != 0x08 && e->KeyChar)
		{
			e->Handled = true;
		}

		// Om för/efternamns storlek redan är 20 tecken(max storlek) så tillåts ej vidare inmatning (förutom backspace)
		else if (box->Text->Length == 20 && e->KeyChar != 0x08)
		{
			e->Handled = true;
		}

	}
		

    // Kontrollerar text input för telefon nummers textboxarna.
	private: System::Void tbxTeleInput_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
    {
		// Box används till att för urskilja vilken tbx som startade KeyPress event.
		TextBox^ box = (TextBox^)sender;

		// Endast siffror eller backspace tillåts som inmatning.
		if (!std::isdigit(e->KeyChar) && e->KeyChar != 0x08)
		{
			e->Handled = true;
		}

		// Ett vanligt svenskt telefon nummer ligger mellan 8-10 tecken. Så mer siffror
		// Får ej matas in ifall det är 10tecken långt, enda inmatningen som tillåts
		// i detta fall är backspace.
		else if (box->Text->Length == 10 && e->KeyChar != 0x08)
		{
			e->Handled = true;
		}
		
	}
	

    // Lägger till en ny person i gridView och lägger till ett nytt Contact objekt i contacts listan.
    private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e)
	{
		// Eftersom ett nytt contact objekt läggs till och den markerade raden i gridview ändras
		// programmatiskt i denna funktion så sätts add till true.
		add = true;

		// Contact objekt som används för att tilldela List contacts ett contact objekt.
		Contact^ newContact = gcnew Contact(tbxFirstName->Text,tbxSurName->Text,tbxPhoneNumber->Text);

		contacts->Add(newContact);

		// Utökar listan med 1 plats om antalet rader är lika med antal kontakter för att göra plats för 1 till kontakt
		if (dataGridView1->Rows->Count == contacts->Count)
		{
			dataGridView1->Rows->Add(1);
		}

		// Skriver ut efternamn innan förnamn ifall inte "Förnamn först" är vald.
		if (rbtnFirstName->Checked == true)
		{
			dataGridView1->Rows[contacts->Count - 1]->Cells[0]->Value = contacts[contacts->Count - 1]->eFirstName;
			dataGridView1->Rows[contacts->Count - 1]->Cells[1]->Value = contacts[contacts->Count - 1]->eSurName;
			dataGridView1->Rows[contacts->Count - 1]->Cells[2]->Value = contacts[contacts->Count - 1]->eTelephoneNumber;
		}
		else
		{
			dataGridView1->Rows[contacts->Count - 1]->Cells[1]->Value = contacts[contacts->Count - 1]->eFirstName;
			dataGridView1->Rows[contacts->Count - 1]->Cells[0]->Value = contacts[contacts->Count - 1]->eSurName;
			dataGridView1->Rows[contacts->Count - 1]->Cells[2]->Value = contacts[contacts->Count - 1]->eTelephoneNumber;
		}

		// Personuppgifterna som läggs till töms från inmatningboxarna
		tbxFirstName->Clear();
		tbxSurName->Clear();
		tbxPhoneNumber->Clear();

		// ny markering av rad
		dataGridView1->Rows[contacts->Count]->Selected = true;

		btnAdd->Enabled = false;
		tbxFirstName2->Enabled = true;
		tbxSurName2->Enabled = true;
		tbxPhoneNumber2->Enabled = true;
	}


    // Byter plats på alla för och efternamn när man byter rbtn
    private: System::Void rbtnSurName_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
    {
		// Temporär string som används vid byte av columntitlarna.
		String^ temp = Column1->HeaderText;
		Column1->HeaderText = Column2->HeaderText;
		Column2->HeaderText = temp;

		// Loopar igenom alla för och efternamn och byterplats
		for (int i = 0; i < contacts->Count; i++)
		{
			if (isFirstName)
			{
				dataGridView1->Rows[i]->Cells[0]->Value = contacts[i]->eSurName;
				dataGridView1->Rows[i]->Cells[1]->Value = contacts[i]->eFirstName;
			}
			else
			{
				dataGridView1->Rows[i]->Cells[0]->Value = contacts[i]->eFirstName;
				dataGridView1->Rows[i]->Cells[1]->Value = contacts[i]->eSurName;
			}
		}

		// boolvariabeln blir true om den va false och tvärtom
		isFirstName = !isFirstName;
    }


    // Kopierar namn/telefonnummer till sök/redigera textrutorna när man markerar en GridView rad om den radens index motsvarar ett contact objekt.
	// Tar också och av/på aktiverar knappar beroende på vilken GridView rad man markerat.
    private: System::Void dataGridView1_SelectionChanged(System::Object^  sender, System::EventArgs^  e)
	{
		// Om man markerar en GridView rad med personuppgifter.
		if (contacts->Count > 0 && dataGridView1->CurrentCell->RowIndex < contacts->Count && !add && !search)
	 	{   
			tbxFirstName2->Text = contacts[dataGridView1->CurrentCell->RowIndex]->eFirstName;
			tbxSurName2->Text = contacts[dataGridView1->CurrentCell->RowIndex]->eSurName;
			tbxPhoneNumber2->Text = contacts[dataGridView1->CurrentCell->RowIndex]->eTelephoneNumber;
			gbxSearchEdit->Text = "Person " + Convert::ToInt32(dataGridView1->CurrentCell->RowIndex + 1);
			
			// Om det redan står det som ska det ska ändras till så 
			// gör ej denna ändring eftersom grupprutan målas typ om då
			// vilket gör att den flimmrar till. Vilket e ganska jobbigt 
			// när det händer för ofta och i onödan.
			if (lblInfo2->Text != "* Markera en tom rad för att återgå till sökning")
			{
				lblInfo2->Text = "* Markera en tom rad för att återgå till sökning";
			}
			
			tbxFirstName2->Enabled = false;
			tbxSurName2->Enabled = false;
			tbxPhoneNumber2->Enabled = false;

			btnDelete->Enabled = true;
			btnEdit->Enabled = true;
			btnSearch->Enabled = false;
		}
		// Om man markerar en tom GridView rad.
		else if (!add && !search)
		{
			tbxFirstName2->Clear();
			tbxSurName2->Clear();
			tbxPhoneNumber2->Clear();

			btnSearch->Enabled = false;
			btnDelete->Enabled = false;
			btnEdit->Enabled = false;

			tbxFirstName2->Enabled = true;
			tbxSurName2->Enabled = true;
			tbxPhoneNumber2->Enabled = true;

			// Om rätt sak redan står så uteblir ändringen
	     	// vilket gör att den slipper målas om och flimmrar i onödan.
			if (gbxSearchEdit->Text != "Sök Person")
			{
				gbxSearchEdit->Text = "Sök Person";
				lblInfo2->Text = "* Minst ett sökord med rätt syntax krävs";
			}
		}
		else
		{
			// Om add variabeln blivit true efter tilläggning av en ny person och gridview_selectionchange
			// funktionens kodblock ignorerats så blir denna variabel false igen.
			if (add)
			{
				add = false;
			}

			// Ändra tillbaka search.
			if (search)
			{
				search = false;
			}
		}
    }


    // Rensar personuppgifterna på den markerade raden samt tar bort contact objektet på motsvarande index,
	private: System::Void btnDelete_Click(System::Object^  sender, System::EventArgs^  e)
	{
		// Om raden som tas bort blev markerad av sök funktionen( då RowIndex inte flyttas ) så används searchIndex(index där matchande personuppgifter hittades) för att 
		// kunna identifiera den nuvarande radens index.
		if (searchDel) 
		{
			searchDel = false;

			contacts->RemoveAt(searchIndex);
			dataGridView1->Rows[searchIndex]->Cells[0]->Value = "";
			dataGridView1->Rows[searchIndex]->Cells[1]->Value = "";
			dataGridView1->Rows[searchIndex]->Cells[2]->Value = "";


			// Om värdet man tog bort var det värdet längst ner i gridview / det enda värdet
			if (searchIndex == contacts->Count)
			{
				gbxSearchEdit->Text = "Sök Person";
				lblInfo2->Text = "* Minst ett sökord med rätt syntax krävs";
				tbxFirstName2->Text = "";
				tbxSurName2->Text = "";
				tbxPhoneNumber2->Text = "";
				btnDelete->Enabled = false;
				btnEdit->Enabled = false;
				tbxFirstName2->Enabled = true;
				tbxSurName2->Enabled = true;
				tbxPhoneNumber2->Enabled = true;
			}
			// Om raden som man tar bort inte är den sista raden
			else if (searchIndex < contacts->Count)
			{
				// Gör sista raden i GridView tom eftersom värderna flyttas upp ett steg
				dataGridView1->Rows[contacts->Count]->Cells[0]->Value = "";
				dataGridView1->Rows[contacts->Count]->Cells[1]->Value = "";
				dataGridView1->Rows[contacts->Count]->Cells[2]->Value = "";

				// Ändrar textboxarnas text till nya personens personuppgifter på detta index
				tbxFirstName2->Text = contacts[searchIndex]->eFirstName;
				tbxSurName2->Text = contacts[searchIndex]->eSurName;
				tbxPhoneNumber2->Text = contacts[searchIndex]->eTelephoneNumber;
				gbxSearchEdit->Text = "Person " + Convert::ToInt32(searchIndex + 1);
				lblInfo2->Text = "* Markera en tom rad för att återgå till sökning";
				btnSearch->Enabled = false;
				btnDelete->Enabled = true;
				btnEdit->Enabled = true;
				tbxFirstName2->Enabled = false;
				tbxSurName2->Enabled = false;
				tbxPhoneNumber2->Enabled = false;

				// De rader som låg efter den borttagna raden(i) flyttas upp 1 steg tills i är lika med antalet contact värden.
				for (int i = searchIndex; i < contacts->Count; i++)
				{
					dataGridView1->Rows[i]->Cells[0]->Value = contacts[i]->eFirstName;
					dataGridView1->Rows[i]->Cells[1]->Value = contacts[i]->eSurName;
					dataGridView1->Rows[i]->Cells[2]->Value = contacts[i]->eTelephoneNumber;
				}
			}
		}
		else // Om man själv markerat raden som deletas
		{
			contacts->RemoveAt(dataGridView1->CurrentCell->RowIndex);
			dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[0]->Value = "";
			dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[1]->Value = "";
			dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[2]->Value = "";

			// Om värdet man tog bort var det värdet längst ner i gridview / det enda värdet
			if (dataGridView1->CurrentCell->RowIndex == contacts->Count)
			{
				gbxSearchEdit->Text = "Sök Person";
				lblInfo2->Text = "* Minst ett sökord med rätt syntax krävs";
				tbxFirstName2->Text = "";
				tbxSurName2->Text = "";
				tbxPhoneNumber2->Text = "";
				btnDelete->Enabled = false;
				btnEdit->Enabled = false;
				tbxFirstName2->Enabled = true;
				tbxSurName2->Enabled = true;
				tbxPhoneNumber2->Enabled = true;
			}
			// Om raden som man tar bort inte är den sista raden
			else if (searchIndex < contacts->Count)
			{
				// Gör sista raden i GridView tom eftersom värderna flyttas upp ett steg
				dataGridView1->Rows[contacts->Count]->Cells[0]->Value = "";
				dataGridView1->Rows[contacts->Count]->Cells[1]->Value = "";
				dataGridView1->Rows[contacts->Count]->Cells[2]->Value = "";

				// Ändrar textboxarnas text till nya personens personuppgifter på detta index
				tbxFirstName2->Text = contacts[dataGridView1->CurrentRow->Index]->eFirstName;
				tbxSurName2->Text = contacts[dataGridView1->CurrentRow->Index]->eSurName;
				tbxPhoneNumber2->Text = contacts[dataGridView1->CurrentRow->Index]->eTelephoneNumber;
				gbxSearchEdit->Text = "Person " + Convert::ToInt32(dataGridView1->CurrentCell->RowIndex + 1);
				lblInfo2->Text = "* Markera en tom rad för att återgå till sökning";
				btnSearch->Enabled = false;
				btnDelete->Enabled = true;
				btnEdit->Enabled = true;
				tbxFirstName2->Enabled = false;
				tbxSurName2->Enabled = false;
				tbxPhoneNumber2->Enabled = false;

				// De rader som låg efter den borttagna raden(i) flyttas upp 1 steg tills i är lika med antalet contact värden.
				for (int i = dataGridView1->CurrentCell->RowIndex; i < contacts->Count; i++)
				{
					dataGridView1->Rows[i]->Cells[0]->Value = contacts[i]->eFirstName;
					dataGridView1->Rows[i]->Cells[1]->Value = contacts[i]->eSurName;
					dataGridView1->Rows[i]->Cells[2]->Value = contacts[i]->eTelephoneNumber;
				}
			}
		}
	}


    // Om man har markerat en rad i GridView vars index motsvarar ett contacts objekt så kan man klicka redigera
	// och ändra värderna i contact objektet och i gridbox rutan genom att ta bort befintliga objekt på detta
	// index och ersätta det med ett nytt som man insertar på samma index.
    private: System::Void btnEdit_Click(System::Object^  sender, System::EventArgs^  e) 
    {
		if (searchEdit) // Om man editar värderna på en gridview rad som har markerats genom koden i sökfunktionen
		{   
			// När man klickar på knappen första gången för att redigera den markerade raden och dess data
			// så är denna bool variabel false så att alla knapparna kan ändras och tbx låsas upp osv.
			// variabeln var alltså nödvändig för att kunna koppla 2 st enskilda kodblock till samma händelse btnEdit_Click
			// som skulle köras vid olika villkor
			if (!btnEditMode)
			{
				btnDelete->Enabled = false;
				btnSearch->Enabled = false;

				tbxFirstName2->Enabled = true;
				tbxSurName2->Enabled = true;
				tbxPhoneNumber2->Enabled = true;

				btnEdit->Text = "Spara";
			
				tbxFirstName->Enabled = false;
				tbxSurName->Enabled = false;
				tbxPhoneNumber->Enabled = false;

				btnEditMode = true;
			}
			else
			{
				Contact^ newContact = gcnew Contact(tbxFirstName2->Text, tbxSurName2->Text, tbxPhoneNumber2->Text);

				contacts->RemoveAt(searchIndex); // borttagning
				contacts->Insert(searchIndex, newContact); // ersättning 

				dataGridView1->Rows[searchIndex]->Cells[0]->Value = contacts[searchIndex]->eFirstName;
				dataGridView1->Rows[searchIndex]->Cells[1]->Value = contacts[searchIndex]->eSurName;
				dataGridView1->Rows[searchIndex]->Cells[2]->Value = contacts[searchIndex]->eTelephoneNumber;

				tbxFirstName->Enabled = true;
				tbxSurName->Enabled = true;
				tbxPhoneNumber->Enabled = true;

				btnEdit->Text = "Redigera";
				btnEditMode = false; // Återställer btnEditMode till false så att knappen ska få redigera funktionen igen
			}
		}
		else // om man själv markerat nuvarande rad genom att klicka på den
		{
			if (!btnEditMode)
			{
				btnDelete->Enabled = false;
				btnSearch->Enabled = false;
				tbxFirstName2->Enabled = true;
				tbxSurName2->Enabled = true;
				tbxPhoneNumber2->Enabled = true;
				btnEdit->Text = "Spara";
				btnEditMode = true;
				tbxFirstName->Enabled = false;
				tbxSurName->Enabled = false;
				tbxPhoneNumber->Enabled = false;
			}
			else
			{
				Contact^ newContact = gcnew Contact(tbxFirstName2->Text, tbxSurName2->Text, tbxPhoneNumber2->Text);

				
				contacts->RemoveAt(dataGridView1->CurrentCell->RowIndex); // borttagning
				contacts->Insert(dataGridView1->CurrentCell->RowIndex, newContact); // ersättning

				dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[0]->Value = contacts[dataGridView1->CurrentCell->RowIndex]->eFirstName;
				dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[1]->Value = contacts[dataGridView1->CurrentCell->RowIndex]->eSurName;
				dataGridView1->Rows[dataGridView1->CurrentCell->RowIndex]->Cells[2]->Value = contacts[dataGridView1->CurrentCell->RowIndex]->eTelephoneNumber;

				tbxFirstName->Enabled = true;
				tbxSurName->Enabled = true;
				tbxPhoneNumber->Enabled = true;

				btnEdit->Text = "Redigera";
				btnEditMode = false; // Återställer btnEditMode till false så att knappen ska få redigera funktionen igen
			}
		}
    }
    

    // Sökfunktionen
	private: System::Void btnSearch_Click(System::Object^  sender, System::EventArgs^  e)
	{
		// Värden som indikerar om contacts(i)->x stämmde överens med motsvarande tbx->text.
		bool fNameMatch;
		bool sNameMatch;
		bool tNumMatch;

		// Om längden i en tbx var 0 så blev xOK = true för att btnSearch skulle kunna aktiveras då en tbx var tom
		// eftersom det betydde att man inte ville söka med den delen av namnet/nummret, men här används värdet av xOK till att bestämma om
		// man överhuvudtaget ska jämföra denna tbx innehåll mot contacts. Det sparar resurser och tid att skippa det.
		// Därför sätts dessa värden på false ifall denna tbx->Text = 0

		if (tbxFirstName2->TextLength == 0)
		{
			fNameOK = false;
		}

		if (tbxSurName2->TextLength == 0)
		{
			sNameOK = false;
		}

		if (tbxPhoneNumber2->TextLength == 0)
		{
			tNumOK = false;
		}
		

		// Kör så många gånger som det finns värden i contacts.
		for (int i = 0; i < contacts->Count; i++)
		{
			// Dessa sätts på true ifall contacts[i]->eX matchar textboxen, men eftersom alla aktuella sökvärden måste matcha sina contacts[i]->eX
			// för att en rad ska markeras så sätts detta värdet till false vid början av varje repetition, för att inte (fNameMatch && sNameMatch && tNumMatch) 
			// ska kunna vara sant om dessa olika värden blir true vid olika contacts[i].
			// Searchindex sätts dessutom som -1 för det är ej ett index som någon rad kan ha.
			// och hittas alltså ingen matchande rad så ligger det kvar på -1 och då visas Inga träffar meddelandeboxen
			fNameMatch = false;
			sNameMatch = false;
			tNumMatch = false;
			searchIndex = -1;

			// Om värdet i en tbx var OK så blev ju xOK = true för att indikera det. Dessutom så betyder det att textboxen inte är tom
			// ifall xOK = true så då jämför man vid varje repetition.
			if (fNameOK)
			{
				if (tbxFirstName2->Text == contacts[i]->eFirstName)
				{
					fNameMatch = true;
					
				}
			}
			// Om xOK inte var true så betyder det att textboxen var tom, och alltså då att det inte spelar någon roll vad contacts[i]->eX är.
			// så då sätts denna textboxens matchvärde till true vid varje repetition utan att söka igenom contacts[i]->eX vilket sparar på resurser och tid.
			else
			{
				sNameMatch = true;
			}

			if (sNameOK)
			{
				if (tbxSurName2->Text == contacts[i]->eSurName)
				{
					sNameMatch = true;
				}
			}
			else
			{
				sNameMatch = true;
			}

			if (tNumOK)
			{
				if (tbxPhoneNumber2->Text == contacts[i]->eTelephoneNumber)
				{
					tNumMatch = true;
				}
			}
			else
			{
				tNumMatch = true;
			}

			// Om alla textboxar med sökvärden i matchar nuvarande contacts[i]->eX så markeras den rad i GridView med index(i)
			// och så avslutas loopen.
			if (fNameMatch && sNameMatch && tNumMatch)
			{
				search = true;
				searchDel = true;
				searchEdit = true;
				searchIndex = i;

				// Markerar den rad där matchande värden hittades.
				dataGridView1->Rows[i]->Selected = true;

				fNameOK = false;
				sNameOK = false;
				tNumOK = false;

				gbxSearchEdit->Text = "Person " + Convert::ToInt32(i + 1);
				tbxFirstName2->Text = contacts[i]->eFirstName;
				tbxSurName2->Text = contacts[i]->eSurName;
				tbxPhoneNumber2->Text = contacts[i]->eTelephoneNumber;

				if (lblInfo2->Text != "* Markera en tom rad för att återgå till sökning")
				{
					lblInfo2->Text = "* Markera en tom rad för att återgå till sökning";
				}

				btnEdit->Enabled = true;
				btnDelete->Enabled = true;
				btnSearch->Enabled = false;
				
				/* Användes vid kontroll av dessa värden, vid felsökning
				dataGridView1->Rows[10]->Cells[0]->Value = i;
				dataGridView1->Rows[11]->Cells[0]->Value = searchIndex;
				*/
				break;
			}
		}
		if (searchIndex == -1)
		{
			// Om inget index i gridView matchar sökorden så visas denna meddelandebox.
			MessageBox::Show("Sökningen gav inga träffar", "Sökning", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}


    // Hanterar sökknappens Enabled status
	private: System::Void tbx2_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		// Om alla textboxar i gbx searchedit är tomma( Text->Lenght == 0 vilket också leder till xOK) så ska sökknappen avaktiveras
		// eftersom man inte ska kunna söka efter ingenting / en griview rad vars alla värden är "".
		if (tbxFirstName2->Text->Length == 0 && tbxSurName2->Text->Length == 0 && tbxPhoneNumber2->Text->Length == 0)
		{
			btnSearch->Enabled = false;
		}
		else
		{
			// Utgå från att alla är false då texten i någon textruta ändras
			fNameOK = false;
			sNameOK = false;
			tNumOK = false;

			if (tbxFirstName2->TextLength >= 2 || tbxFirstName2->TextLength == 0)
			{
				fNameOK = true;
			}

			if (tbxSurName2->TextLength >= 2 || tbxSurName2->TextLength == 0)
			{
				sNameOK = true;
			}

			if (tbxPhoneNumber2->TextLength >= 8 || tbxPhoneNumber2->TextLength == 0)
			{
				tNumOK = true;
			}
			
			// Alla vilkor måste stämma om btnSearch->Enabled ska vara sant
			if (fNameOK && sNameOK && tNumOK)
			{
				btnSearch->Enabled = true;
			}
			else
			{
				btnSearch->Enabled = false;
			}
		}
	}
	

    // Rensar all text från sök groupboxens tbx ifall man ändrar fokus till lägg till groupboxens tbx. Dessutom så markeras första tomma rad
    // i GridView. Dessutom så ändras sökboxens aktiva knappar och text + infotexten2.
	private: System::Void tbx_Enter(System::Object^  sender, System::EventArgs^  e)
	{
		dataGridView1->Rows[contacts->Count]->Selected = true;

		// Kontrollen slipper måla om sig ifall den redan har rätta värdet
		if (gbxSearchEdit->Text != "Sök Person")
		{
			gbxSearchEdit->Text = "Sök Person";
			lblInfo2->Text = "* Minst ett sökord med rätt syntax krävs";

			btnEdit->Enabled = false;
			btnDelete->Enabled = false;
			btnSearch->Enabled = false;
		}

		tbxFirstName2->Clear();
		tbxSurName2->Clear();
		tbxPhoneNumber2->Clear();
	}

	// Rensar all text från läggtill groupboxen ifall man ändrar fokus till sökgroupboxens tbx.
	private: System::Void tbx2_Enter(System::Object^  sender, System::EventArgs^  e)
	{
		tbxFirstName->Clear();
		tbxSurName->Clear();
		tbxPhoneNumber->Clear();
	}


	// Ser till att hela programmet avslutas vid nedstängning av denna form, annars ligger ju inloggningsformen kvar i bakrunden
	private: System::Void MyForm1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
	{
		Application::Exit();
	}


    // Man kan stänga av/sätta på bakrundsbilden med denna funktion vilket leder till prestanda förbättring om den är av.
    private: System::Void rbtnPerformanceMode_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		//Image^ backround = System::Drawing::Image::FromFile("C:\\users\\public\\desktop\\Joel Bäckrud Projekt 2\\oldskool-photography-167780-unsplash.jpg");
	
		Image^ backround = System::Drawing::Image::FromFile("oldskool-photography-167780-unsplash.jpg");
		if (!isBackround)
		{
			// Väljer man bakrund så ändras formens bakrundsbild till bilden på den speciferade sökvägen.
			this->BackgroundImage = backround;
		}
		else
		{
			// Om man väljer prestanda knappen ändras bakrunden till ingenting(tas bort)
			this->BackgroundImage = nullptr;
		}
		
		isBackround = !isBackround;
    }
};
}
