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
	using namespace System::Text;
	/// <summary>
	/// Сводка для Admin_Form
	/// </summary>
	public ref class Admin_Form : public System::Windows::Forms::Form
	{
	public:
		System::Windows::Forms::Form^ mainForm;
		Admin_Form(System::Windows::Forms::Form^ mform)
		{
			mainForm = mform;
			//mform->Visible = false;

			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			Mysql::MYSQL * conn;
			conn = Mysql::mysql_init(NULL);


			if (Mysql::mysql_real_connect(conn, "localhost", "root", "0000", "16063_pr2", 3306, NULL, 0))
			{
				Mysql::mysql_set_character_set(conn, "utf8");

				String^ qu = gcnew String("SELECT user_.Name_user, user_.LastName_user, user_.patronymic_user, order_user.Table_number, order_user.DateTime_order, order_user.Statuse FROM user_ INNER JOIN order_user ON user_.idUser=order_user.User_idUser");
				char* query = (char*)(Marshal::StringToHGlobalAnsi(qu)).ToPointer();

				int sql_query = Mysql::mysql_query(conn, query);


				Mysql::MYSQL_RES *res;
				Mysql::MYSQL_ROW row;
				int index = 0;
				if (res = mysql_store_result(conn)) {
					while (row = mysql_fetch_row(res)) {
						dataGridView1->Rows->Add();
						String^ str = gcnew String(row[0]);
						str = str->Insert(str->Length, " ");
						str = str->Insert(str->Length, gcnew String(row[1]));
						str = str->Insert(str->Length, " ");
						str = str->Insert(str->Length, gcnew String(row[2]));
						dataGridView1->Rows[index]->Cells[0]->Value = gcnew String(str);
						dataGridView1->Rows[index]->Cells[1]->Value = gcnew String(row[4]);
						String^ state;
						switch (*(row[5]))
						{
						case '1':
							state = gcnew String("Не выполнено");
							break;
						case '2':
							state = gcnew String("Выполнено");
							break;
						default:
							break;
						}
						dataGridView1->Rows[index]->Cells[2]->Value = state;

						++index;
					}
				}


			}
			Mysql::mysql_close(conn);

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Admin_Form()
		{

			if (components)
			{
				delete components;

			}

		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;



	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  FIO;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  State;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  idOrder;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  FIO_user;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Name_Dish;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Price;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Stat;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->FIO = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->State = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->idOrder = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FIO_user = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Name_Dish = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Price = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Stat = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->FIO, this->Date,
					this->State
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(346, 395);
			this->dataGridView1->TabIndex = 0;
			// 
			// FIO
			// 
			this->FIO->HeaderText = L"ФИО";
			this->FIO->Name = L"FIO";
			this->FIO->ReadOnly = true;
			// 
			// Date
			// 
			this->Date->HeaderText = L"Дата оформления";
			this->Date->Name = L"Date";
			this->Date->ReadOnly = true;
			// 
			// State
			// 
			this->State->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->State->HeaderText = L"Статус выполнения";
			this->State->Name = L"State";
			this->State->ReadOnly = true;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10"
			});
			this->comboBox1->Location = System::Drawing::Point(452, 34);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(130, 21);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->Text = L"Столик";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(452, 112);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 30);
			this->button1->TabIndex = 2;
			this->button1->Tag = L"";
			this->button1->Text = L"Отчет за сутки";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Admin_Form::button1_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->idOrder,
					this->FIO_user, this->Name_Dish, this->Price, this->Stat
			});
			this->dataGridView2->Location = System::Drawing::Point(588, 12);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(698, 395);
			this->dataGridView2->TabIndex = 3;
			// 
			// idOrder
			// 
			this->idOrder->HeaderText = L"Номер заказа";
			this->idOrder->Name = L"idOrder";
			this->idOrder->Width = 50;
			// 
			// FIO_user
			// 
			this->FIO_user->HeaderText = L"ФИО";
			this->FIO_user->Name = L"FIO_user";
			// 
			// Name_Dish
			// 
			this->Name_Dish->HeaderText = L"Название блюд в заказе";
			this->Name_Dish->Name = L"Name_Dish";
			this->Name_Dish->Width = 300;
			// 
			// Price
			// 
			this->Price->HeaderText = L"Стоимость ";
			this->Price->Name = L"Price";
			this->Price->Width = 80;
			// 
			// Stat
			// 
			this->Stat->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Stat->HeaderText = L"Статус выполнения";
			this->Stat->Name = L"Stat";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(588, 413);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(176, 42);
			this->button2->TabIndex = 4;
			this->button2->Tag = L"";
			this->button2->Text = L"Итоговый отчет за сутки";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Admin_Form::button3_Click);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(382, 74);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 5;
			// 
			// Admin_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1294, 499);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Admin_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"\"Кагошими\"- Окно администратора";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Admin_Form::Admin_Form_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Admin_Form_ControlRemoved(System::Object^  sender, System::Windows::Forms::ControlEventArgs^  e) 
    {

	}
		private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			Mysql::MYSQL * conn;
			conn = Mysql::mysql_init(NULL);
			
				if (Mysql::mysql_real_connect(conn, "localhost", "root", "0000", "16063_pr2", 3306, NULL, 0))
				{
					Mysql::mysql_set_character_set(conn, "utf8");

					dataGridView2->Rows->Clear();
					
					String^ qu = gcnew String("SELECT Order_idOrder, user_.Name_user, user_.LastName_user Dish_idDish, Dish.Name_Dish, Dish.price, order_user.Statuse FROM order_has_dish, order_user, dish, user_ where(user_.idUser = order_user.User_idUser and date(order_user.DateTime_order)  = \"");
					DateTime date = dateTimePicker1->Value;
					qu = qu->Insert(qu->Length, gcnew String(date.ToString("yyyy-MM-dd")));
					qu = qu->Insert(qu->Length, "\" and order_user.idOrder = order_has_dish.Order_idOrder and order_has_dish.Dish_idDish = dish.idDish) Order BY order_has_dish.Order_idOrder;");
					char* query = (char*)(Marshal::StringToHGlobalAnsi(qu)).ToPointer();

					int sql_query = Mysql::mysql_query(conn, query);

					Mysql::MYSQL_RES *res;
					Mysql::MYSQL_ROW row;
					int index = 0;
					String^ id;
					if (res = mysql_store_result(conn)) {
						while (row = mysql_fetch_row(res)) {


							if (index > 0)
							{
								if (id->Equals(gcnew String(row[0])))
								{
									--index;
									String^ str = gcnew String((String^)(dataGridView2->Rows[index]->Cells[2]->Value));
									str = str->Insert(str->Length, ", ");
									str = str->Insert(str->Length, gcnew String(row[3]));
									int x = Int32::Parse(gcnew String(row[4]));
									int y = Int32::Parse(gcnew String(dataGridView2->Rows[index]->Cells[3]->Value->ToString()));

									dataGridView2->Rows[index]->Cells[3]->Value = x + y;

									dataGridView2->Rows[index]->Cells[2]->Value = str;
								}
								else
								{
									dataGridView2->Rows->Add();
									dataGridView2->Rows[index]->Cells[0]->Value = gcnew String(row[0]);

									String^ str = gcnew String(row[1]);
									str = str->Insert(str->Length, " ");
									str = str->Insert(str->Length, gcnew String(row[2]));

									dataGridView2->Rows[index]->Cells[1]->Value = str;
									dataGridView2->Rows[index]->Cells[2]->Value = gcnew String(row[3]);
									dataGridView2->Rows[index]->Cells[3]->Value = gcnew String(row[4]);

									String^ state;
									switch (*(row[5]))
									{
									case '1':
										state = gcnew String("Не выполнено");
										break;
									case '2':
										state = gcnew String("Выполнено");
										break;
									default: state = gcnew String("Выполняется");
										break;
									}
									dataGridView2->Rows[index]->Cells[4]->Value = state;
								}
							}
							else
							{
								dataGridView2->Rows->Add();
								dataGridView2->Rows[index]->Cells[0]->Value = gcnew String(row[0]);

								String^ str = gcnew String(row[1]);
								str = str->Insert(str->Length, " ");
								str = str->Insert(str->Length, gcnew String(row[2]));

								dataGridView2->Rows[index]->Cells[1]->Value = str;
								dataGridView2->Rows[index]->Cells[2]->Value = gcnew String(row[3]);

								dataGridView2->Rows[index]->Cells[3]->Value = gcnew String(row[4]);

								String^ state;
								switch (*(row[5]))
								{
								case '1':
									state = gcnew String("Не выполнено");
									break;
								case '2':
									state = gcnew String("Выполнено");
									break;
								default: state = gcnew String("Выполняется");
									break;
								}
								dataGridView2->Rows[index]->Cells[4]->Value = state;
							}


							id = gcnew String(row[0]);
							++index;


						}
					}


				}
			Mysql::mysql_close(conn);

		}
	

private: System::Void Admin_Form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	mainForm->Close();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
	
		Mysql::MYSQL * conn;
		conn = Mysql::mysql_init(NULL);
		if(comboBox1->SelectedItem!=nullptr)
		if (Mysql::mysql_real_connect(conn, "localhost", "root", "0000", "16063_pr2", 3306, NULL, 0))
		{
			Mysql::mysql_set_character_set(conn, "utf8");

			dataGridView2->Rows->Clear();
			
			String^ qu = gcnew String("SELECT Order_idOrder, user_.Name_user, user_.LastName_user Dish_idDish, Dish.Name_Dish, Dish.price, order_user.Statuse FROM order_has_dish, order_user, dish, user_ where(user_.idUser = order_user.User_idUser and date(order_user.DateTime_order)  = \"");
				
				DateTime date = dateTimePicker1->Value;
				qu = qu->Insert(qu->Length, gcnew String(date.ToString("yyyy-MM-dd")));

				qu = qu->Insert(qu->Length, "\" and order_user.Table_number = ");
				qu = qu->Insert(qu->Length, gcnew String(comboBox1->SelectedItem->ToString()));
				
			qu = qu->Insert(qu->Length," and order_user.idOrder = order_has_dish.Order_idOrder and order_has_dish.Dish_idDish = dish.idDish) Order BY order_has_dish.Order_idOrder;");
			char* query = (char*)(Marshal::StringToHGlobalAnsi(qu)).ToPointer();

			int sql_query = Mysql::mysql_query(conn, query);

			Mysql::MYSQL_RES *res;
			Mysql::MYSQL_ROW row;
			int index = 0;
			String^ id;
			if (res = mysql_store_result(conn)) {
				while (row = mysql_fetch_row(res)) {
					

					if (index > 0)
					{
						if (id->Equals(gcnew String(row[0])))
						{
							--index;
							String^ str = gcnew String((String^)(dataGridView2->Rows[index]->Cells[2]->Value));
							str = str->Insert(str->Length, ", ");
							str = str->Insert(str->Length, gcnew String(row[3]));
							int x = Int32::Parse(gcnew String(row[4]));
							int y = Int32::Parse(gcnew String(dataGridView2->Rows[index]->Cells[3]->Value->ToString()));

							dataGridView2->Rows[index]->Cells[3]->Value = x + y;

							dataGridView2->Rows[index]->Cells[2]->Value = str;
						}
						else
						{
							dataGridView2->Rows->Add();
							dataGridView2->Rows[index]->Cells[0]->Value = gcnew String(row[0]);

							String^ str = gcnew String(row[1]);
							str = str->Insert(str->Length, " ");
							str = str->Insert(str->Length, gcnew String(row[2]));

							dataGridView2->Rows[index]->Cells[1]->Value = str;
							dataGridView2->Rows[index]->Cells[2]->Value = gcnew String(row[3]);
							dataGridView2->Rows[index]->Cells[3]->Value = gcnew String(row[4]);

							String^ state;
							switch (*(row[5]))
							{
							case '1':
								state = gcnew String("Не выполнено");
								break;
							case '2':
								state = gcnew String("Выполнено");
								break;
							default: state = gcnew String("Выполняется");
								break;
							}
							dataGridView2->Rows[index]->Cells[4]->Value = state;
						}
					}
					else
					{
						dataGridView2->Rows->Add();
						dataGridView2->Rows[index]->Cells[0]->Value = gcnew String(row[0]);

						String^ str = gcnew String(row[1]);
						str = str->Insert(str->Length, " ");
						str = str->Insert(str->Length, gcnew String(row[2]));

						dataGridView2->Rows[index]->Cells[1]->Value = str;
						dataGridView2->Rows[index]->Cells[2]->Value = gcnew String(row[3]);
						
						dataGridView2->Rows[index]->Cells[3]->Value = gcnew String(row[4]);

						String^ state;
						switch (*(row[5]))
						{
						case '1':
							state = gcnew String("Не выполнено");
							break;
						case '2':
							state = gcnew String("Выполнено");
							break;
						default: state = gcnew String("Выполняется");
							break;
						}
						dataGridView2->Rows[index]->Cells[4]->Value = state;
					}


					 id = gcnew String(row[0]);
					++index;


				}
			}


		}
		Mysql::mysql_close(conn);
		
	}


};
}
