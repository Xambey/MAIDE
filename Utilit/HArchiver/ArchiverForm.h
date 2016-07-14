#pragma once
#include "HArchiver.h"
#include "AboutProgram.h"
#include <string>
namespace HArchiver {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ArchiverForm
	/// </summary>
	public ref class ArchiverForm : public System::Windows::Forms::Form
	{
	public:
		ArchiverForm(void)
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
		~ArchiverForm()
		{
			if (components)
			{
				delete components;
			}
		}







	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog2;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog2;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  оПрограммеToolStripMenuItem;

	private: System::ComponentModel::IContainer^  components;
	protected:

	protected:

	protected:


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ArchiverForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->saveFileDialog2 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Info;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(361, 48);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(72, 38);
			this->button1->TabIndex = 1;
			this->button1->Text = L"обзор";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ArchiverForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::Info;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(361, 96);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(72, 38);
			this->button2->TabIndex = 3;
			this->button2->Text = L"обзор";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &ArchiverForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::Info;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(439, 48);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(156, 38);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Архивировать";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &ArchiverForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::Info;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Location = System::Drawing::Point(439, 96);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(156, 38);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Извлечь";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &ArchiverForm::button4_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &ArchiverForm::openFileDialog1_FileOk);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(8, 54);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(347, 26);
			this->textBox1->TabIndex = 6;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(8, 102);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(347, 26);
			this->textBox2->TabIndex = 7;
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			this->openFileDialog2->Filter = L"Harchiver files(*.ha)|*.ha";
			this->openFileDialog2->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &ArchiverForm::openFileDialog2_FileOk);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileName = L"HArchive";
			this->saveFileDialog1->Filter = L"Harchiver files(*.ha)|*.ha";
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &ArchiverForm::saveFileDialog1_FileOk);
			// 
			// saveFileDialog2
			// 
			this->saveFileDialog2->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &ArchiverForm::saveFileDialog2_FileOk);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->оПрограммеToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(607, 33);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(134, 29);
			this->оПрограммеToolStripMenuItem->Text = L"о программе";
			this->оПрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &ArchiverForm::оПрограммеToolStripMenuItem_Click);
			// 
			// ArchiverForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(607, 150);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->HelpButton = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"ArchiverForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Harchiver";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		openFileDialog1->ShowDialog();
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		openFileDialog2->ShowDialog();
	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBox1->Text != "" && textBox1->Text != "Файл не выбран!") {
			saveFileDialog1->ShowDialog();
		}
		else textBox1->Text = "Файл не выбран!";
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBox2->Text != "" && textBox2->Text != "Файл не выбран!")
			saveFileDialog2->ShowDialog();
		else textBox2->Text = "Файл не выбран!";
	}
	private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		Archiver ar;
		ar.Archive(textBox1->Text, saveFileDialog1->FileName);
	}
	private: System::Void saveFileDialog2_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {

		Archiver ar;
		ar.UnArchive(textBox2->Text, saveFileDialog2->FileName);
	}
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		textBox1->Text = openFileDialog1->FileName;
		std::string s(""), res("");
		Archiver need;
		need.MarshalString(textBox1->Text, s);
		bool f = false;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] != '.'&& !f) continue;
			else
				f = true;

			if (f && s[i] == '\\') {
				break;
			}
			else
				res += s[i];
		}
		std::string inv;
		for (int i = res.length() - 1; i >= 0; i--) {
			inv += res[i];
		}
		inv += "ha";
		String^ final = gcnew String(inv.c_str());

		saveFileDialog1->FileName = final;
	}
	private: System::Void openFileDialog2_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		textBox2->Text = openFileDialog2->FileName;
		std::string s, res;

		Archiver need;
		need.MarshalString(textBox2->Text, s);

		ifstream in(s, ios_base::binary);
		if (!in.is_open())
			throw "File not found";

		bool f = false;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] != '.'&& !f) continue;
			else
				f = true;

			if (f && s[i] == '\\') {
				break;
			}
			else
				res += s[i];
		}
		std::string inv;
		for (int i = res.length() - 1; i >= 0; i--) {
			inv += res[i];
		}
		inv.pop_back();
		string format;
		string filename;
		filename += "Harchiver files(*.";
		char l;
		in.read(&l , 1);
		int v = (int)l;
		for (int i = 0; i < v; i++) {
			in.read(&l, 1);
			format.push_back(l);
		}
		in.close();
		filename += format + ") | *." + format;;
		String^ k = gcnew String(filename.c_str());
		String^ final = gcnew String(inv.c_str());

		saveFileDialog2->FileName = final;
		saveFileDialog2->Filter = k;
	}
	private: System::Void оПрограммеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		AboutProgram^ about = gcnew AboutProgram();
		about->Show();
	}
	};
}
