#pragma once
namespace Mysql {
#include "mysql.h"

}
namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	/// <summary>
	/// Сводка для Client_Form
	/// </summary>
	public ref class Client_Form : public System::Windows::Forms::Form
	{
	public:
		System::Windows::Forms::Form^ mainForm;
	private: System::Windows::Forms::Label^  label2;
	public:
		String^ id_user;
		Client_Form(System::Windows::Forms::Form^ mform, String^ id_us)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			mainForm = mform;
			id_user = id_us;
			//mainForm->Visible = false;
			Mysql::MYSQL * conn;
			conn = Mysql::mysql_init(NULL);
			
				if (Mysql::mysql_real_connect(conn, "localhost", "root", "0000", "16063_pr2", 3306, NULL, 0))
				{
					Mysql::mysql_set_character_set(conn, "utf8");

					dataGridView2->Rows->Clear();

					String^ qu = gcnew String("SELECT dish.idDish, dish.Name_dish, products.Name_Product,products_has_dish.Gramms, products.Calories, Dish.price FROM products, products_has_dish, dish where (dish.idDish = products_has_dish.Dish_idDish and products.idProduct = products_has_dish.Products_idProduct) Order BY dish.idDish;");
					char* query = (char*)(Marshal::StringToHGlobalAnsi(qu)).ToPointer();

					int sql_query = Mysql::mysql_query(conn, query);


					Mysql::MYSQL_RES *res;
					Mysql::MYSQL_ROW row;
					String^ id;
					int index = 0;
					if (res = mysql_store_result(conn)) {
						while (row = mysql_fetch_row(res)) {
							if (index > 0)
							{
								if (id->Equals(gcnew String(row[0])))
								{
									--index;
									String^ str = gcnew String((String^)(dataGridView1->Rows[index]->Cells[2]->Value));
									str = str->Insert(str->Length, ", ");
									str = str->Insert(str->Length, gcnew String(row[2]));
									str = str->Insert(str->Length, "(");
									str = str->Insert(str->Length, gcnew String(row[3]));
									str = str->Insert(str->Length, ")");
									dataGridView1->Rows[index]->Cells[2]->Value = str;
								}
								else
								{
									dataGridView1->Rows->Add();
									dataGridView1->Rows[index]->Cells[0]->Value = gcnew String(row[0]);
									dataGridView1->Rows[index]->Cells[1]->Value = gcnew String(row[1]);
									String^ str = gcnew String(row[2]);
									str = str->Insert(str->Length, "(");
									str = str->Insert(str->Length, gcnew String(row[3]));
									str = str->Insert(str->Length, ")");
									dataGridView1->Rows[index]->Cells[2]->Value = str;
									dataGridView1->Rows[index]->Cells[3]->Value = gcnew String(row[4]);
									dataGridView1->Rows[index]->Cells[4]->Value = gcnew String(row[5]);
									dataGridView1->Rows[index]->Cells[5]->Value = false;
								}
							}
							else
							{
								dataGridView1->Rows->Add();
								dataGridView1->Rows[index]->Cells[0]->Value = gcnew String(row[0]);
								dataGridView1->Rows[index]->Cells[1]->Value = gcnew String(row[1]);
								String^ str = gcnew String(row[2]);
								str = str->Insert(str->Length, "(");
								str = str->Insert(str->Length, gcnew String(row[3]));
								str = str->Insert(str->Length, ")");
								dataGridView1->Rows[index]->Cells[2]->Value = str;
								dataGridView1->Rows[index]->Cells[3]->Value = gcnew String(row[4]);
								dataGridView1->Rows[index]->Cells[4]->Value = gcnew String(row[5]);
								dataGridView1->Rows[index]->Cells[5]->Value = false;
							}

							id = gcnew String(row[0]);
							
							++index;
						}
					}
				}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Client_Form()
		{
			if (components)
			{
				delete components;
				mainForm->Close();
			}
			
		}
	private: System::Windows::Forms::ComboBox^  comboBox1;
	protected:
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::Button^  button1;










	private: System::Windows::Forms::Label^  label1;




private: System::Windows::Forms::DataGridViewTextBoxColumn^  idDish;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Name_Dish;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Sostav;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Calorienost;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Price;
private: System::Windows::Forms::DataGridViewCheckBoxColumn^  chek;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Id_dish;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Name_dish_K;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  price_k;
private: System::Windows::Forms::DataGridViewButtonColumn^  otmena;













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
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->idDish = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Name_Dish = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Sostav = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Calorienost = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Price = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->chek = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Id_dish = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Name_dish_K = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->price_k = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->otmena = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->ForeColor = System::Drawing::SystemColors::InfoText;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10"
			});
			this->comboBox1->Location = System::Drawing::Point(308, 453);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->Text = L"Столик";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(56, 454);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 1;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->idDish,
					this->Name_Dish, this->Sostav, this->Calorienost, this->Price, this->chek
			});
			this->dataGridView1->Location = System::Drawing::Point(462, 37);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(522, 509);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Client_Form::dataGridView1_CellContentClick);
			// 
			// idDish
			// 
			this->idDish->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->idDish->HeaderText = L"Номер блюда";
			this->idDish->Name = L"idDish";
			this->idDish->Width = 50;
			// 
			// Name_Dish
			// 
			this->Name_Dish->HeaderText = L"Название Блюда";
			this->Name_Dish->Name = L"Name_Dish";
			this->Name_Dish->ReadOnly = true;
			// 
			// Sostav
			// 
			this->Sostav->HeaderText = L"Состав";
			this->Sostav->Name = L"Sostav";
			this->Sostav->ReadOnly = true;
			// 
			// Calorienost
			// 
			this->Calorienost->HeaderText = L"Калорийность";
			this->Calorienost->Name = L"Calorienost";
			this->Calorienost->ReadOnly = true;
			this->Calorienost->Width = 70;
			// 
			// Price
			// 
			this->Price->HeaderText = L"Цена";
			this->Price->Name = L"Price";
			this->Price->ReadOnly = true;
			this->Price->Width = 70;
			// 
			// chek
			// 
			this->chek->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->chek->FalseValue = L"0";
			this->chek->HeaderText = L"Добавить в корзину";
			this->chek->Name = L"chek";
			this->chek->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->chek->TrueValue = L"1";
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Id_dish,
					this->Name_dish_K, this->price_k, this->otmena
			});
			this->dataGridView2->Location = System::Drawing::Point(57, 73);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(373, 368);
			this->dataGridView2->TabIndex = 3;
			this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Client_Form::dataGridView2_CellContentClick);
			// 
			// Id_dish
			// 
			this->Id_dish->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
			this->Id_dish->HeaderText = L"ID";
			this->Id_dish->Name = L"Id_dish";
			this->Id_dish->ReadOnly = true;
			this->Id_dish->Width = 43;
			// 
			// Name_dish_K
			// 
			this->Name_dish_K->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Name_dish_K->FillWeight = 86.9489F;
			this->Name_dish_K->HeaderText = L"Название блюда";
			this->Name_dish_K->Name = L"Name_dish_K";
			this->Name_dish_K->ReadOnly = true;
			// 
			// price_k
			// 
			this->price_k->HeaderText = L"Цена";
			this->price_k->Name = L"price_k";
			this->price_k->ReadOnly = true;
			this->price_k->Width = 50;
			// 
			// otmena
			// 
			this->otmena->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->otmena->FillWeight = 30;
			this->otmena->HeaderText = L"";
			this->otmena->Name = L"otmena";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 21.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(57, 495);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(372, 51);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Сделать заказ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Client_Form::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(191, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 33);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Корзина";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::Red;
			this->label2->Location = System::Drawing::Point(133, 549);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 24);
			this->label2->TabIndex = 6;
			// 
			// Client_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1015, 591);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->comboBox1);
			this->Name = L"Client_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"\"Кагошими\"- Окно клиента";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Client_Form::Client_Form_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Client_Form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		mainForm->Close();
	}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {

	
		if (e->ColumnIndex == dataGridView1->Columns["chek"]->Index && e->RowIndex >= 0)
			if (!Convert::ToBoolean(dataGridView1->Rows[e->RowIndex]->Cells[5]->Value))
			{
			
				dataGridView1->Rows[e->RowIndex]->Cells[5]->Value = true;

				dataGridView2->Rows->Add();
				dataGridView2->Rows[dataGridView2->Rows->Count - 1]->Cells[0]->Value = dataGridView1->Rows[e->RowIndex]->Cells[0]->Value;
				dataGridView2->Rows[dataGridView2->Rows->Count - 1]->Cells[1]->Value = dataGridView1->Rows[e->RowIndex]->Cells[1]->Value;
				dataGridView2->Rows[dataGridView2->Rows->Count - 1]->Cells[2]->Value = dataGridView1->Rows[e->RowIndex]->Cells[4]->Value;
				dataGridView2->Rows[dataGridView2->Rows->Count - 1]->Cells[3]->Value = "Удалить";
			}
			else if (dataGridView2->RowCount != 0)
				{
					for (int i = 0; i < dataGridView2->RowCount; ++i)
					{
						String^ str = gcnew String((String^)(dataGridView2->Rows[i]->Cells[0]->Value));
						if (str->Equals(gcnew String((String^)(dataGridView1->Rows[e->RowIndex]->Cells[0]->Value))))
						{
							dataGridView2->Rows->RemoveAt(i);
							dataGridView1->Rows[e->RowIndex]->Cells[5]->Value = false;
						}
					}
			
				}
	}
	private: System::Void dataGridView2_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {

		if (e->ColumnIndex == dataGridView2->Columns["otmena"]->Index && e->RowIndex >= 0)
			{
				for (int i = 0; i < dataGridView2->RowCount; ++i)
				{
					String^ str = gcnew String((String^)(dataGridView1->Rows[i]->Cells[0]->Value));
					if (str->Equals(gcnew String((String^)(dataGridView2->Rows[e->RowIndex]->Cells[0]->Value))))
					{
						dataGridView2->Rows->RemoveAt(e->RowIndex);
						dataGridView1->Rows[i]->Cells[5]->Value = false;
					}
				}

			}
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	if (comboBox1->SelectedItem != nullptr)
	{
		Mysql::MYSQL * conn;
		conn = Mysql::mysql_init(NULL);

		if (Mysql::mysql_real_connect(conn, "localhost", "root", "0000", "16063_pr2", 3306, NULL, 0))
		{
			Mysql::mysql_set_character_set(conn, "utf8");



			String^ qu = gcnew String("INSERT INTO order_user (Table_number, DateTime_order, Statuse, User_idUser) VALUES ( ");
			qu = qu->Insert(qu->Length, gcnew String(comboBox1->SelectedItem->ToString()));
			qu = qu->Insert(qu->Length, ", \"");
			DateTime^ DT = dateTimePicker1->Value;
			qu = qu->Insert(qu->Length, DT->ToString("yyyy-MM-ddTHH:mm:ss"));
			qu = qu->Insert(qu->Length, "\", 1, ");
			qu = qu->Insert(qu->Length, id_user);
			qu = qu->Insert(qu->Length, ")");
			char* query = (char*)(Marshal::StringToHGlobalAnsi(qu)).ToPointer();

			int sql_query = Mysql::mysql_query(conn, query);

			Mysql::MYSQL_RES *res;
			Mysql::MYSQL_ROW row;

			if (sql_query == 0)
			{
				qu = qu->Remove(0);
				qu = gcnew String("Select idOrder From order_user where (");
				qu = qu->Insert(qu->Length, " DateTime_order =\"");
				qu = qu->Insert(qu->Length, DT->ToString("yyyy-MM-ddTHH:mm:ss"));
				qu = qu->Insert(qu->Length, "\")");
				query = (char*)(Marshal::StringToHGlobalAnsi(qu)).ToPointer();

				int sql_query = Mysql::mysql_query(conn, query);

				if (res = mysql_store_result(conn))
					row = mysql_fetch_row(res);

				if (sql_query == 0)
				{

					for (int i = 0; i < dataGridView2->RowCount; ++i)
					{
						qu = qu->Remove(0);
						qu = "INSERT INTO order_has_dish (Order_idOrder, Dish_idDish) VALUES(";
						qu = qu->Insert(qu->Length, gcnew String(row[0]));
						qu = qu->Insert(qu->Length, ", ");
						qu = qu->Insert(qu->Length, gcnew String((String^)(dataGridView2->Rows[i]->Cells[0]->Value)));
						qu = qu->Insert(qu->Length, ") ");
						query = (char*)(Marshal::StringToHGlobalAnsi(qu)).ToPointer();
						sql_query = Mysql::mysql_query(conn, query);
						dataGridView1->Rows[i]->Cells[5]->Value = false;

					}
					dataGridView2->Rows->Clear();
					label2->Text = "Ваш заказ зарегестрирован!";
				}
			}
		}
	}
	else {
		label2->Text = "Выберите столик";
	}
}
};
}
