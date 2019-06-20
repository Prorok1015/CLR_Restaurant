#pragma once

namespace Project3 {

#include "MyRegistration.h"
#include "Admin_Form.h"
#include "Client_Form.h"
#include "Shef_Form.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		System::Windows::Forms::Form ^ reg_form;

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
	
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label4;

	protected:

	private:
		
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 20.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(57, 277);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(179, 40);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Регистрация";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(106, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 28);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Войти";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(501, 153);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(288, 365);
			this->panel1->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(35, 150);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Password";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(35, 107);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Login";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(94, 147);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(151, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(95, 104);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(151, 20);
			this->textBox1->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(23, 204);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(245, 48);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Войти";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::White;
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label4->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(319, 66);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(710, 59);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Ресторан японской кухни \"Кагошими\"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1280, 590);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Ресторан \"Кагошими\"- Авторизация";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		
		reg_form = gcnew Project3::MyRegistration();
		reg_form->ShowDialog();
		delete(reg_form);
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

		bool flag = true;

		if (textBox1->Text == "")
		{
			flag = false;
			textBox1->Text = "Не заполнено";
		}if (textBox2->Text == "")
		{
			flag = false;
			textBox2->Text = "Не заполнено";
		}


		if (flag)
		{

			Mysql::MYSQL * conn;
			conn = Mysql::mysql_init(NULL);


			if (Mysql::mysql_real_connect(conn, "localhost" , "root", "0000", "16063_pr2", 3306, NULL, 0))
			{
				Mysql::mysql_set_character_set(conn, "utf8");

				String^ qu = gcnew String("Select idUser, Type_user from user_ where (Login = \"");

				qu = qu->Insert(qu->Length, textBox1->Text);
				qu = qu->Insert(qu->Length, "\" and Password_ = \"");
				qu = qu->Insert(qu->Length, textBox2->Text);
				qu = qu->Insert(qu->Length, "\")");
				char* query = (char*)(Marshal::StringToHGlobalAnsi(qu)).ToPointer();

				int sql_query = Mysql::mysql_query(conn, query);

				
					Mysql::MYSQL_RES *res = mysql_store_result(conn);
					if(res)
					{
						Mysql::MYSQL_ROW row = mysql_fetch_row(res);
						if (row != NULL)
						{
							textBox1->Clear();
							textBox2->Clear();

							switch (*(row[1]))
							{
							case '1': reg_form = gcnew Project3::Admin_Form(this);
								reg_form->Show();
								//this->Visible = false;
								break;
							case '2': reg_form = gcnew Project3::Shef_Form(this);
								reg_form->Show();
								//this->Visible = false;
								break;
							case '3': reg_form = gcnew Project3::Client_Form(this, gcnew String(row[0]));
								reg_form->Show();
								//this->Visible = false;
								break;
							default:
								break;
							}
						}
					}
				Mysql::mysql_close(conn);
			}
		}
	}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	
	
	
}
};
}
