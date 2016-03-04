#pragma once

namespace BPC2E_C04A {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  text_re_A;
	private: System::Windows::Forms::Button^  bt_add;
	protected: 

	protected: 

	private: System::Windows::Forms::Label^  label_real;
	private: System::Windows::Forms::Label^  label_A;
	private: System::Windows::Forms::Label^  label_imag;
	private: System::Windows::Forms::TextBox^  text_im_A;
	private: System::Windows::Forms::TextBox^  text_im_B;
	private: System::Windows::Forms::Label^  label_B;
	private: System::Windows::Forms::TextBox^  text_re_B;
	private: System::Windows::Forms::Button^  bt_sub;
	private: System::Windows::Forms::Button^  bt_mult;
	private: System::Windows::Forms::Button^  bt_div;

	private: System::Windows::Forms::Label^  Res_re;
	private: System::Windows::Forms::Label^  Res_im;



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
		this->text_re_A = (gcnew System::Windows::Forms::TextBox());
		this->bt_add = (gcnew System::Windows::Forms::Button());
		this->label_real = (gcnew System::Windows::Forms::Label());
		this->label_A = (gcnew System::Windows::Forms::Label());
		this->label_imag = (gcnew System::Windows::Forms::Label());
		this->text_im_A = (gcnew System::Windows::Forms::TextBox());
		this->text_im_B = (gcnew System::Windows::Forms::TextBox());
		this->label_B = (gcnew System::Windows::Forms::Label());
		this->text_re_B = (gcnew System::Windows::Forms::TextBox());
		this->bt_sub = (gcnew System::Windows::Forms::Button());
		this->bt_mult = (gcnew System::Windows::Forms::Button());
		this->bt_div = (gcnew System::Windows::Forms::Button());
		this->Res_re = (gcnew System::Windows::Forms::Label());
		this->Res_im = (gcnew System::Windows::Forms::Label());
		this->SuspendLayout();
		// 
		// text_re_A
		// 
		this->text_re_A->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(238)));
		this->text_re_A->Location = System::Drawing::Point(34, 33);
		this->text_re_A->Name = L"text_re_A";
		this->text_re_A->Size = System::Drawing::Size(100, 22);
		this->text_re_A->TabIndex = 0;
		this->text_re_A->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
		// 
		// bt_add
		// 
		this->bt_add->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		this->bt_add->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(238)));
		this->bt_add->Location = System::Drawing::Point(252, 9);
		this->bt_add->Name = L"bt_add";
		this->bt_add->Size = System::Drawing::Size(48, 23);
		this->bt_add->TabIndex = 1;
		this->bt_add->Text = L"A+B";
		this->bt_add->UseVisualStyleBackColor = true;
		this->bt_add->Click += gcnew System::EventHandler(this, &Form1::bt_add_Click);
		// 
		// label_real
		// 
		this->label_real->AutoSize = true;
		this->label_real->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(238)));
		this->label_real->Location = System::Drawing::Point(67, 9);
		this->label_real->Name = L"label_real";
		this->label_real->Size = System::Drawing::Size(35, 20);
		this->label_real->TabIndex = 2;
		this->label_real->Text = L"real";
		// 
		// label_A
		// 
		this->label_A->AutoSize = true;
		this->label_A->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(238)));
		this->label_A->Location = System::Drawing::Point(8, 33);
		this->label_A->Name = L"label_A";
		this->label_A->Size = System::Drawing::Size(20, 20);
		this->label_A->TabIndex = 3;
		this->label_A->Text = L"A";
		// 
		// label_imag
		// 
		this->label_imag->AutoSize = true;
		this->label_imag->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(238)));
		this->label_imag->Location = System::Drawing::Point(173, 9);
		this->label_imag->Name = L"label_imag";
		this->label_imag->Size = System::Drawing::Size(47, 20);
		this->label_imag->TabIndex = 5;
		this->label_imag->Text = L"imag.";
		// 
		// text_im_A
		// 
		this->text_im_A->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(238)));
		this->text_im_A->Location = System::Drawing::Point(146, 33);
		this->text_im_A->Name = L"text_im_A";
		this->text_im_A->Size = System::Drawing::Size(100, 22);
		this->text_im_A->TabIndex = 4;
		this->text_im_A->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
		// 
		// text_im_B
		// 
		this->text_im_B->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(238)));
		this->text_im_B->Location = System::Drawing::Point(146, 65);
		this->text_im_B->Name = L"text_im_B";
		this->text_im_B->Size = System::Drawing::Size(100, 22);
		this->text_im_B->TabIndex = 8;
		this->text_im_B->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
		// 
		// label_B
		// 
		this->label_B->AutoSize = true;
		this->label_B->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(238)));
		this->label_B->Location = System::Drawing::Point(8, 65);
		this->label_B->Name = L"label_B";
		this->label_B->Size = System::Drawing::Size(20, 20);
		this->label_B->TabIndex = 7;
		this->label_B->Text = L"B";
		// 
		// text_re_B
		// 
		this->text_re_B->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(238)));
		this->text_re_B->Location = System::Drawing::Point(34, 65);
		this->text_re_B->Name = L"text_re_B";
		this->text_re_B->Size = System::Drawing::Size(100, 22);
		this->text_re_B->TabIndex = 6;
		this->text_re_B->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
		// 
		// bt_sub
		// 
		this->bt_sub->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		this->bt_sub->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(238)));
		this->bt_sub->Location = System::Drawing::Point(252, 38);
		this->bt_sub->Name = L"bt_sub";
		this->bt_sub->Size = System::Drawing::Size(48, 23);
		this->bt_sub->TabIndex = 9;
		this->bt_sub->Text = L"A-B";
		this->bt_sub->UseVisualStyleBackColor = true;
		this->bt_sub->Click += gcnew System::EventHandler(this, &Form1::bt_sub_Click);
		// 
		// bt_mult
		// 
		this->bt_mult->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		this->bt_mult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(238)));
		this->bt_mult->Location = System::Drawing::Point(252, 67);
		this->bt_mult->Name = L"bt_mult";
		this->bt_mult->Size = System::Drawing::Size(48, 23);
		this->bt_mult->TabIndex = 10;
		this->bt_mult->Text = L"A*B";
		this->bt_mult->UseVisualStyleBackColor = true;
		this->bt_mult->Click += gcnew System::EventHandler(this, &Form1::bt_mult_Click);
		// 
		// bt_div
		// 
		this->bt_div->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		this->bt_div->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(238)));
		this->bt_div->Location = System::Drawing::Point(252, 96);
		this->bt_div->Name = L"bt_div";
		this->bt_div->Size = System::Drawing::Size(48, 23);
		this->bt_div->TabIndex = 11;
		this->bt_div->Text = L"A*B";
		this->bt_div->UseVisualStyleBackColor = true;
		this->bt_div->Click += gcnew System::EventHandler(this, &Form1::bt_div_Click);
		// 
		// Res_re
		// 
		this->Res_re->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(238)));
		this->Res_re->Location = System::Drawing::Point(34, 95);
		this->Res_re->Name = L"Res_re";
		this->Res_re->Size = System::Drawing::Size(100, 20);
		this->Res_re->TabIndex = 12;
		this->Res_re->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// Res_im
		// 
		this->Res_im->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(238)));
		this->Res_im->Location = System::Drawing::Point(146, 95);
		this->Res_im->Name = L"Res_im";
		this->Res_im->Size = System::Drawing::Size(100, 20);
		this->Res_im->TabIndex = 13;
		this->Res_im->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		// 
		// Form1
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::SystemColors::Control;
		this->ClientSize = System::Drawing::Size(307, 126);
		this->Controls->Add(this->Res_im);
		this->Controls->Add(this->Res_re);
		this->Controls->Add(this->bt_div);
		this->Controls->Add(this->bt_mult);
		this->Controls->Add(this->bt_sub);
		this->Controls->Add(this->text_im_B);
		this->Controls->Add(this->label_B);
		this->Controls->Add(this->text_re_B);
		this->Controls->Add(this->label_imag);
		this->Controls->Add(this->text_im_A);
		this->Controls->Add(this->label_A);
		this->Controls->Add(this->label_real);
		this->Controls->Add(this->bt_add);
		this->Controls->Add(this->text_re_A);
		this->Name = L"Form1";
		this->Text = L"Complex Calculator";
		this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
		this->ResumeLayout(false);
		this->PerformLayout();

			}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 }
	double get_re_A(void)
	{
		return System::Convert::ToDouble(this->text_re_A->Text);
	}
	
	double get_re_B(void)
	{
		return System::Convert::ToDouble(this->text_re_B->Text);
	}
	double get_im_A(void)
	{
		return System::Convert::ToDouble(this->text_im_A->Text);
	}
	
	double get_im_B(void)
	{
		return System::Convert::ToDouble(this->text_im_B->Text);
	}
private: System::Void bt_add_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		this->Res_re->Text = System::Convert::ToString(get_re_A()+get_re_B());
		this->Res_im->Text = System::Convert::ToString(get_im_A()+get_im_B());
	}

private: System::Void bt_sub_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Res_re->Text = System::Convert::ToString(get_re_A()-get_re_B());
		this->Res_im->Text = System::Convert::ToString(get_im_A()-get_im_B());		
	}

private: System::Void bt_mult_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		this->Res_re->Text = System::Convert::ToString((get_re_A()*get_re_B())-(get_im_A()*get_im_B()));
		this->Res_im->Text = System::Convert::ToString((get_re_A()*get_im_B())+(get_im_A()*get_re_B()));
	}

private: System::Void bt_div_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Res_re->Text = System::Convert::ToString(((get_re_A()*get_re_B())+(get_im_A()*get_im_B()))/(get_im_A()*get_im_A()+get_im_B()*get_im_B()));
		this->Res_im->Text = System::Convert::ToString(((get_re_A()*get_im_B())+(get_im_A()*get_re_B()))/(get_im_A()*get_im_A()+get_im_B()*get_im_B()));
	}
};
}

