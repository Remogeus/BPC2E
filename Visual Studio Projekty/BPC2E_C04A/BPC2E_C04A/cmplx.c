#include <stdafx.h>
#include "cmplx.h"

double get_re_A(void)
{
	double re_A;
	re_A = System::Convert::ToDouble(this->text_re_A->Text);
	return re_A;
}
	
double get_re_B(void)
{
	double re_B;
	re_B = System::Convert::ToDouble(this->text_re_B->Text);
	return re_B;
}
double get_im_A(void)
{
	double im_A;
	im_A = System::Convert::ToDouble(this->text_im_A->Text);
	return im_A;
}
	
double get_im_B(void)
{
	double im_B;
	im_B = System::Convert::ToDouble(this->text_im_B->Text);
	return im_B
}

void c_add(double re, double im, get_re_A(),get_re_B(),get_im_A(),get_im_B())
{
	re = get_re_A()+get_re_B();
	im = get_im_A()+get_im_B();
}