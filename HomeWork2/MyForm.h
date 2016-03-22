
#pragma once
#include <fstream>
#include <iostream>
void get_data(int [][2]);
namespace HomeWork2 {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	private:
		System::Drawing::Brush^ yelloBrush;
		System::Drawing::Brush^ whiteBrush;
		System::Drawing::Graphics^ g;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Panel^  panel1;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(433, 168);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(122, 79);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Push";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(415, 439);
			this->panel1->TabIndex = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(567, 463);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

		g = panel1->CreateGraphics();	
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		int pic_location[9*9][2];	
		get_data(pic_location);
		g = panel1->CreateGraphics();
		Bitmap^ bmp = gcnew Bitmap(L"dwceagles2.bmp");
		for (int i = 0; i < 9*9; i++)
		{
				g->DrawImage(bmp, pic_location[i][0], pic_location[i][1]);
			
		}

	}
	};
}


void get_data(int piclocation[][2]) {
	
	std::ifstream in_stream;					
	in_stream.open("picloc.txt");
	int count = 0;
	while (!in_stream.eof()) {					//stream coordinates from file into array
		in_stream >> piclocation[count][0];
		in_stream >> piclocation[count][1];
		count++;
	}
}

