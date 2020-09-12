#pragma once
#include "MyForm1.h"

namespace JoelBäckrudProjekt2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  btnLogin;
	private: System::Windows::Forms::TextBox^  tbxUserName;
	private: System::Windows::Forms::TextBox^  tbxPassword;
	private: System::Windows::Forms::Label^  lblUsername;
	private: System::Windows::Forms::Label^  lblPassword;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->tbxUserName = (gcnew System::Windows::Forms::TextBox());
			this->tbxPassword = (gcnew System::Windows::Forms::TextBox());
			this->lblUsername = (gcnew System::Windows::Forms::Label());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnLogin
			// 
			this->btnLogin->Enabled = false;
			this->btnLogin->Location = System::Drawing::Point(145, 96);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(75, 23);
			this->btnLogin->TabIndex = 0;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &MyForm::btnLogin_Click);
			// 
			// tbxUserName
			// 
			this->tbxUserName->Location = System::Drawing::Point(121, 26);
			this->tbxUserName->MaxLength = 20;
			this->tbxUserName->Name = L"tbxUserName";
			this->tbxUserName->Size = System::Drawing::Size(119, 20);
			this->tbxUserName->TabIndex = 1;
			this->tbxUserName->TextChanged += gcnew System::EventHandler(this, &MyForm::tbx_TextChanged);
			// 
			// tbxPassword
			// 
			this->tbxPassword->Location = System::Drawing::Point(121, 66);
			this->tbxPassword->MaxLength = 500;
			this->tbxPassword->Name = L"tbxPassword";
			this->tbxPassword->PasswordChar = '*';
			this->tbxPassword->Size = System::Drawing::Size(119, 20);
			this->tbxPassword->TabIndex = 2;
			this->tbxPassword->TextChanged += gcnew System::EventHandler(this, &MyForm::tbx_TextChanged);
			// 
			// lblUsername
			// 
			this->lblUsername->AutoSize = true;
			this->lblUsername->BackColor = System::Drawing::Color::Transparent;
			this->lblUsername->ForeColor = System::Drawing::Color::White;
			this->lblUsername->Location = System::Drawing::Point(33, 29);
			this->lblUsername->Name = L"lblUsername";
			this->lblUsername->Size = System::Drawing::Size(82, 13);
			this->lblUsername->TabIndex = 3;
			this->lblUsername->Text = L"Användarnamn:";
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->BackColor = System::Drawing::Color::Transparent;
			this->lblPassword->ForeColor = System::Drawing::Color::White;
			this->lblPassword->Location = System::Drawing::Point(33, 69);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(54, 13);
			this->lblPassword->TabIndex = 4;
			this->lblPassword->Text = L"Lösenord:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(277, 131);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->lblUsername);
			this->Controls->Add(this->tbxPassword);
			this->Controls->Add(this->tbxUserName);
			this->Controls->Add(this->btnLogin);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Logga in";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btnLogin_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		// Om texten i tbxUserName och tbxPassword motsvarar abc och 123 så öppnas huvudformen 
		// medans denna stängs(göms)
		if (tbxUserName->Text == "abc" && tbxPassword->Text == "123")
		{
			MyForm^ Register = gcnew MyForm();
			Register->Show();
			this->Hide();
		}
		else
		{
			// Klickar man logga in fast det är fel inloggningsuppgifter i tbx så kommer denna meddelandeboxen upp.
			MessageBox::Show("Du har anget fel användarnamn och/eller lösenord", "Inloggning Misslyckad", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

    // Logga in knappen stänger av sig ifall lösenordet och användarnamnet inte är minst 1 tecken långt vardera.
	private: System::Void tbx_TextChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (tbxUserName->TextLength >= 1 && tbxPassword->TextLength >= 1)
		{
			btnLogin->Enabled = true;
		}
		else
		{
			btnLogin->Enabled = false;
		}
	}

};
}
