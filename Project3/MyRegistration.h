#pragma once

namespace Mysql {
#include "mysql.h"

}


namespace Project3 {
	

	using namespace Mysql;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Сводка для MyRegistration
	/// </summary>
	public ref class MyRegistration : public System::Windows::Forms::Form
	{
	public:
		MyRegistration(void)
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
		~MyRegistration()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(145, 129);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(194, 20);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(83, 132);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Имя*";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(83, 168);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Фамилия*";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(145, 165);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(194, 20);
			this->textBox2->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(83, 204);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Отчество";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(145, 201);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(194, 20);
			this->textBox3->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(83, 241);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(56, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Телефон*";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(145, 238);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(194, 20);
			this->textBox4->TabIndex = 6;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(83, 50);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(37, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Login*";
			this->label5->Click += gcnew System::EventHandler(this, &MyRegistration::label5_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(145, 47);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(194, 20);
			this->textBox5->TabIndex = 8;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(83, 76);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(57, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Password*";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(145, 73);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(194, 20);
			this->textBox6->TabIndex = 10;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(160, 303);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 32);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Зарегистрироваться";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyRegistration::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(23, 357);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Отмена";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyRegistration::button2_Click);
			// 
			// MyRegistration
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(444, 392);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyRegistration";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Регистрация";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	bool flag = true;
	if (textBox1->Text == "")
	{
		flag = false;
		textBox1->Text = "не заполнено";
	}if (textBox2->Text == "")
	{
		flag = false;
		textBox2->Text = "не заполнено";
	}if (textBox3->Text == "")
	{
		flag = false;
		textBox3->Text = "не заполнено";
	}if (textBox4->Text == "")
	{
		flag = false;
		textBox4->Text = "не заполнено";
	}if (textBox5->Text == "")
	{
		flag = false;
		textBox5->Text = "не заполнено";
	}if (textBox6->Text == "")
	{
		flag = false;
		textBox6->Text = "не заполнено";
	}

	if (flag)
	{

		Mysql::MYSQL * conn;
		conn = Mysql::mysql_init(NULL);


		if (Mysql::mysql_real_connect(conn, "localhost", "root", "0000", "16063_pr2", 3306, NULL, 0))
		{
			Mysql::mysql_set_character_set(conn, "utf8");

			String^ qu = gcnew String("Select idUser from user where Login = ");
			String^ s = gcnew String(textBox5->Text);
			qu = qu->Insert(qu->Length - 1, s);
			char* str = (char*)(Marshal::StringToHGlobalAnsi(qu)).ToPointer();

			int sql_query = Mysql::mysql_query(conn, str);

			Mysql::MYSQL_RES *res = mysql_store_result(conn);
			Mysql::MYSQL_ROW row= mysql_fetch_row(res);
			row ;

			if (row != NULL)
			{
				textBox5->Text = "Введите другой логин";
			}
			else
			{
				qu = "INSERT INTO user (Name_user, LastName_user, patronymic_user, Login, Password, Phone_number, Type_user) VALUES ( ";
				qu = qu->Insert(qu->Length - 1, "\"");
				qu = qu->Insert(qu->Length - 1, textBox1->Text);
				qu = qu->Insert(qu->Length - 1, "\",");
				qu = qu->Insert(qu->Length - 1, "\"");
				qu = qu->Insert(qu->Length - 1, textBox2->Text);
				qu = qu->Insert(qu->Length - 1, "\",");
				qu = qu->Insert(qu->Length - 1, "\"");
				qu = qu->Insert(qu->Length - 1, textBox3->Text);
				qu = qu->Insert(qu->Length - 1, "\",");
				qu = qu->Insert(qu->Length - 1, "\"");
				qu = qu->Insert(qu->Length - 1, textBox5->Text);
				qu = qu->Insert(qu->Length - 1, "\",");
				qu = qu->Insert(qu->Length - 1, "\"");
				qu = qu->Insert(qu->Length - 1, textBox6->Text);
				qu = qu->Insert(qu->Length - 1, "\",");
				qu = qu->Insert(qu->Length - 1, "\"");
				qu = qu->Insert(qu->Length - 1, textBox4->Text);
				qu = qu->Insert(qu->Length - 1, "\", 3)");


				const char * query = (char*)(Marshal::StringToHGlobalAnsi(qu)).ToPointer();
				Mysql::mysql_query(conn, query);
			}







		}
		Mysql::mysql_close(conn);
		this->Close();
	}
}
private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
