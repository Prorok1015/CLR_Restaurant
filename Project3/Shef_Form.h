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
	/// Сводка для Shef_Form
	/// </summary>
	public ref class Shef_Form : public System::Windows::Forms::Form
	{
	public:
		System::Windows::Forms::Form^ mainForm;
		Shef_Form(System::Windows::Forms::Form^ mform)
		{
			mainForm = mform;
			//mainForm->Visible = false;

			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			Mysql::MYSQL * conn;
			conn = Mysql::mysql_init(NULL);


			if (Mysql::mysql_real_connect(conn, "localhost", "root", "0000", "16063_pr2", 3306, NULL, 0))
			{
				Mysql::mysql_set_character_set(conn, "utf16");

				String^ qu = gcnew String("SELECT Order_idOrder, Dish_idDish, Dish.Name_Dish FROM order_has_dish, order_user, dish where (order_user.Statuse = 1 and order_user.idOrder = order_has_dish.Order_idOrder and order_has_dish.Dish_idDish = dish.idDish) Order BY order_has_dish.Order_idOrder; ");
				char* query = (char*)(Marshal::StringToHGlobalAnsi(qu)).ToPointer();

				int sql_query = Mysql::mysql_query(conn, query);

				Mysql::MYSQL_RES *res;
				Mysql::MYSQL_ROW row;
				int index = 0;
				char id;
				if (res = mysql_store_result(conn)) {
					while (row = mysql_fetch_row(res)) {
						
						if (index > 0)
						{
							if (id == *(row[0]))
							{
								--index;
								String^ str = gcnew String((String^)(dataGridView1->Rows[index]->Cells[1]->Value));
								str = str->Insert(str->Length, ", ");
								str = str->Insert(str->Length, gcnew String(row[2]));

								dataGridView1->Rows[index]->Cells[1]->Value = str;
							}
							else
							{
								dataGridView1->Rows->Add();
								dataGridView1->Rows[index]->Cells[0]->Value = gcnew String(row[0]);
								dataGridView1->Rows[index]->Cells[1]->Value = gcnew String(row[2]);
								dataGridView1->Rows[index]->Cells[2]->Value = gcnew String("Не выполнено");
							}
						}
						else
						{
							dataGridView1->Rows->Add();
							dataGridView1->Rows[index]->Cells[0]->Value = gcnew String(row[0]);
							dataGridView1->Rows[index]->Cells[1]->Value = gcnew String(row[2]);
							dataGridView1->Rows[index]->Cells[2]->Value = gcnew String("Не выполнено");
						}

						
						id = *(row[0]);
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
		~Shef_Form()
		{
			if (components)
			{
				delete components;

			}

		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  idOrder;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dish_name;
	private: System::Windows::Forms::DataGridViewButtonColumn^  End_order;



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
			this->idOrder = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dish_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->End_order = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->idOrder,
					this->dish_name, this->End_order
			});
			this->dataGridView1->Location = System::Drawing::Point(79, 25);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(859, 488);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Shef_Form::dataGridView1_CellContentClick);
			// 
			// idOrder
			// 
			this->idOrder->HeaderText = L"Номер заказа";
			this->idOrder->Name = L"idOrder";
			this->idOrder->ReadOnly = true;
			// 
			// dish_name
			// 
			this->dish_name->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->dish_name->HeaderText = L"Список блюд";
			this->dish_name->Name = L"dish_name";
			this->dish_name->ReadOnly = true;
			// 
			// End_order
			// 
			this->End_order->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->End_order->HeaderText = L"Выполнить";
			this->End_order->Name = L"End_order";
			this->End_order->Text = L"Выполнить";
			// 
			// Shef_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1032, 553);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Shef_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"\"Кагошими\"- Окно шефа";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Shef_Form::Shef_Form_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {

		if (e->ColumnIndex == dataGridView1->Columns["End_order"]->Index && e->RowIndex >= 0)
		{
			String^ str = gcnew String("Выполнено");
			if (!(str->Equals(dataGridView1->Rows[e->RowIndex]->Cells[2]->Value)))
			{
				dataGridView1->Rows[e->RowIndex]->Cells[2]->Value = "Выполнено";
				Mysql::MYSQL * conn;
				conn = Mysql::mysql_init(NULL);


				if (Mysql::mysql_real_connect(conn, "localhost", "root", "0000", "16063_pr2", 3306, NULL, 0))
				{
					Mysql::mysql_set_character_set(conn, "utf8");

					String^ qu = gcnew String(" UPDATE order_user SET Statuse = 2 WHERE idOrder = ");
					qu = qu->Insert(qu->Length, (String^)(dataGridView1->Rows[e->RowIndex]->Cells[0]->Value));
					char* query = (char*)(Marshal::StringToHGlobalAnsi(qu)).ToPointer();

					int sql_query = Mysql::mysql_query(conn, query);
				}
			}





		}
	}

private: System::Void Shef_Form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	mainForm->Close();
}
};
}
