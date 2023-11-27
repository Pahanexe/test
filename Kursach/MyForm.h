#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Gaus.h"
#include "LUP.h"
namespace Kursach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			workspace->RowCount = 2;
			workspace->ColumnCount = 2;
			for (int row = 0; row < workspace->RowCount; row++) {
				for (int col = 0; col < workspace->ColumnCount; col++) {
					workspace->Rows[row]->Cells[col]->Value = "0";
				}
			}
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

	private: System::Windows::Forms::Label^ ask1;
	private: System::Windows::Forms::NumericUpDown^ Msize;
	private: System::Windows::Forms::Button^ Gausbutton;
	private: System::Windows::Forms::Button^ randombutton;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ workspace;
	private: System::Windows::Forms::Button^ LUPbutton;
	private: System::ComponentModel::IContainer^ components;




	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->ask1 = (gcnew System::Windows::Forms::Label());
			this->Msize = (gcnew System::Windows::Forms::NumericUpDown());
			this->Gausbutton = (gcnew System::Windows::Forms::Button());
			this->randombutton = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->workspace = (gcnew System::Windows::Forms::DataGridView());
			this->LUPbutton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Msize))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->workspace))->BeginInit();
			this->SuspendLayout();
			// 
			// ask1
			// 
			this->ask1->AutoSize = true;
			this->ask1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ask1->Location = System::Drawing::Point(12, 38);
			this->ask1->Name = L"ask1";
			this->ask1->Size = System::Drawing::Size(207, 20);
			this->ask1->TabIndex = 8;
			this->ask1->Text = L"Оберіть розмір матриці";
			// 
			// Msize
			// 
			this->Msize->Location = System::Drawing::Point(47, 61);
			this->Msize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->Msize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->Msize->Name = L"Msize";
			this->Msize->Size = System::Drawing::Size(120, 22);
			this->Msize->TabIndex = 9;
			this->Msize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->Msize->ValueChanged += gcnew System::EventHandler(this, &MyForm::Msize_ValueChanged);
			// 
			// Gausbutton
			// 
			this->Gausbutton->Location = System::Drawing::Point(19, 217);
			this->Gausbutton->Name = L"Gausbutton";
			this->Gausbutton->Size = System::Drawing::Size(140, 49);
			this->Gausbutton->TabIndex = 11;
			this->Gausbutton->Text = L"Gaus\r\n";
			this->Gausbutton->UseVisualStyleBackColor = true;
			this->Gausbutton->Click += gcnew System::EventHandler(this, &MyForm::Gausbutton_Click);
			// 
			// randombutton
			// 
			this->randombutton->Location = System::Drawing::Point(19, 127);
			this->randombutton->Name = L"randombutton";
			this->randombutton->Size = System::Drawing::Size(103, 46);
			this->randombutton->TabIndex = 12;
			this->randombutton->Text = L"Random";
			this->randombutton->UseVisualStyleBackColor = true;
			this->randombutton->Click += gcnew System::EventHandler(this, &MyForm::randombutton_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->workspace);
			this->panel1->Location = System::Drawing::Point(279, 38);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(400, 300);
			this->panel1->TabIndex = 13;
			// 
			// workspace
			// 
			this->workspace->AllowUserToAddRows = false;
			this->workspace->AllowUserToResizeColumns = false;
			this->workspace->AllowUserToResizeRows = false;
			this->workspace->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->workspace->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->workspace->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->workspace->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->workspace->ColumnHeadersVisible = false;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->workspace->DefaultCellStyle = dataGridViewCellStyle2;
			this->workspace->Dock = System::Windows::Forms::DockStyle::Fill;
			this->workspace->Location = System::Drawing::Point(0, 0);
			this->workspace->MaximumSize = System::Drawing::Size(400, 300);
			this->workspace->MinimumSize = System::Drawing::Size(400, 300);
			this->workspace->Name = L"workspace";
			this->workspace->RowHeadersVisible = false;
			this->workspace->RowHeadersWidth = 51;
			this->workspace->RowTemplate->Height = 24;
			this->workspace->Size = System::Drawing::Size(400, 300);
			this->workspace->TabIndex = 14;
			this->workspace->CellValidating += gcnew System::Windows::Forms::DataGridViewCellValidatingEventHandler(this, &MyForm::workspace_CellValidating);
			// 
			// LUPbutton
			// 
			this->LUPbutton->Location = System::Drawing::Point(19, 272);
			this->LUPbutton->Name = L"LUPbutton";
			this->LUPbutton->Size = System::Drawing::Size(140, 49);
			this->LUPbutton->TabIndex = 14;
			this->LUPbutton->Text = L"LUP\r\n";
			this->LUPbutton->UseVisualStyleBackColor = true;
			this->LUPbutton->Click += gcnew System::EventHandler(this, &MyForm::LUPbutton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(812, 426);
			this->Controls->Add(this->LUPbutton);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->randombutton);
			this->Controls->Add(this->Gausbutton);
			this->Controls->Add(this->Msize);
			this->Controls->Add(this->ask1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(1500, 900);
			this->MinimumSize = System::Drawing::Size(700, 300);
			this->Name = L"MyForm";
			this->Text = L"Kursova";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Msize))->EndInit();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->workspace))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void Msize_ValueChanged(System::Object^ sender, System::EventArgs^ e) {


		workspace->Columns->Clear();
		for (size_t i = 0; i < Msize->Value; i++)
		{
			workspace->Columns->Add(i.ToString(), i.ToString());
			workspace->Rows->Add();
		}
		for (int row = 0; row < workspace->RowCount; row++) {
			for (int col = 0; col < workspace->ColumnCount; col++) {
				// Установите значение в ноль
				workspace->Rows[row]->Cells[col]->Value = "0";
			}
		}

	}
	private: System::Void randombutton_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < Msize->Value; i++)
		{
			for (int j = 0; j < Msize->Value; j++)
			{
				int randomNumber = rand() % 201 - 100; // Генерация числа от -100 до 100
				workspace->Rows[i]->Cells[j]->Value = randomNumber.ToString();
			}
		}
	}
	private: System::Void Gausbutton_Click(System::Object^ sender, System::EventArgs^ e) {

		int s = System::Decimal::ToInt32(Msize->Value);
		Matrix a(s);


		Matrix* in = new Matrix(s);

		for (int i = 0; i < Msize->Value; i++) {
			for (int j = 0; j < Msize->Value; j++) {
				// Получаем значение ячейки DataGridView и переводим его в float
				String^ cellValue = workspace->Rows[i]->Cells[j]->Value->ToString();
				float floatValue = 0.0f;
				if (float::TryParse(cellValue, floatValue)) {
					a.setValue(i, j, floatValue);
				}
			}
		}

		in = InverseGausMatrixSolver::solve(&a);

		for (int i = 0; i < Msize->Value; i++) {
			for (int j = 0; j < Msize->Value; j++) {
				float value = in->getValue(i, j); // Вам нужно реализовать метод GetValue в вашем классе Matrix
				workspace->Rows[i]->Cells[j]->Value = value.ToString();
			}
		}

	}
	private: System::Void LUPbutton_Click(System::Object^ sender, System::EventArgs^ e) {

		int s = System::Decimal::ToInt32(Msize->Value);
		Matrix a(s);


		Matrix* in = new Matrix(s);

		for (int i = 0; i < Msize->Value; i++) {
			for (int j = 0; j < Msize->Value; j++) {
				// Получаем значение ячейки DataGridView и переводим его в float
				String^ cellValue = workspace->Rows[i]->Cells[j]->Value->ToString();
				float floatValue = 0.0f;
				if (float::TryParse(cellValue, floatValue)) {
					a.setValue(i, j, floatValue);
				}
			}
		}

		in = InverseLUPMatrixSolver::solve(&a);

		for (int i = 0; i < Msize->Value; i++) {
			for (int j = 0; j < Msize->Value; j++) {
				float value = in->getValue(i, j); // Вам нужно реализовать метод GetValue в вашем классе Matrix
				workspace->Rows[i]->Cells[j]->Value = value.ToString();
			}
		}

	}
	private: System::Void workspace_CellValidating(System::Object^ sender, System::Windows::Forms::DataGridViewCellValidatingEventArgs^ e) {
		if (workspace->IsCurrentCellDirty) {
			String^ input = e->FormattedValue->ToString();
			float floatValue;

			// Пытаемся преобразовать строку в float
			if (!float::TryParse(input, floatValue)) {
				// Если преобразование не удалось, отменяем ввод и выводим сообщение об ошибке
				workspace->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value = "0";
				e->Cancel = true;

				MessageBox::Show("Пожалуйста, введите корректное число типа float.", "Ошибка",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	};
}
