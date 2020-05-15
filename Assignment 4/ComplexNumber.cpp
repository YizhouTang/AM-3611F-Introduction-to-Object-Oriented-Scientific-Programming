#include "ComplexNumber.h"
#include <cmath>

// Constructor that sets complex number z=x+iy
// Note that as I have set defaults in the prototype to 0.0, this will
// also be called in the case where no arguments are given
ComplexNumber::ComplexNumber(double x, double y)
{
  mRealPart = x;
  mImaginaryPart = y;
}

// Method for computing the modulus of a complex number.  
// Note that one could improve this to reduce risk of over/underflow.
double ComplexNumber::CalculateModulus() const
{
 return sqrt(mRealPart*mRealPart+
              mImaginaryPart*mImaginaryPart);
}

// Method for computing the argument of a complex number
double ComplexNumber::CalculateArgument() const
{
  return atan2(mImaginaryPart, mRealPart);
}

// Method for raising complex number to the power n using De Moivre's 
// theorem - first complex number must be converted to polar form
ComplexNumber ComplexNumber::CalculatePower(double n) const
{
  double modulus = CalculateModulus();
  double argument = CalculateArgument();
  double mod_of_result = pow(modulus, n);
  double arg_of_result = argument*n;
  double real_part = mod_of_result*cos(arg_of_result);
  double imag_part = mod_of_result*sin(arg_of_result);
  ComplexNumber z(real_part, imag_part);
  return z;
}

// Overloading the = (assignment) operator
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& z)
{
  mRealPart = z.mRealPart;
  mImaginaryPart = z.mImaginaryPart;
  return *this;
}

// Overloading the unary - operator
ComplexNumber ComplexNumber::operator-() const
{
  ComplexNumber w;
  w.mRealPart = -mRealPart;
  w.mImaginaryPart = -mImaginaryPart;
  return w;
}

// Overloading the binary + operator
ComplexNumber operator+(const ComplexNumber& z1, 
                        const ComplexNumber& z2)
{
  ComplexNumber w;
  w.mRealPart = z1.mRealPart + z2.mRealPart;
  w.mImaginaryPart = z1.mImaginaryPart + z2.mImaginaryPart;
  return w;
}

// Overloading the binary - operator
ComplexNumber operator-(const ComplexNumber& z1, 
                        const ComplexNumber& z2)
{
  ComplexNumber w;
  w.mRealPart = z1.mRealPart - z2.mRealPart;
  w.mImaginaryPart = z1.mImaginaryPart - z2.mImaginaryPart;
  return w;
}

// Overloading the stream insertion << operator
std::ostream& operator<<(std::ostream& output, const ComplexNumber& z)
{
  // Format as "(a + bi)" or as "(a - bi)"
  output << "(" << z.mRealPart << " ";
  if (z.mImaginaryPart >= 0.0)
  {
    return output << "+ " << z.mImaginaryPart << "i)";
  }
  else
  {
  // z.mImaginaryPart < 0.0
  // Replace + with minus sign
    return output << "- " << -z.mImaginaryPart << "i)";
  }
}
//1
double ComplexNumber::GetRealPart(){
	return mRealPart;
}

double ComplexNumber::GetImaginaryPart(){
	return mImaginaryPart;
}
//2
double RealPart(ComplexNumber z){
	return z.GetImaginaryPart();
}
double ImaginaryPart(ComplexNumber z){
	return z.GetRealPart();
}

//3
ComplexNumber::ComplexNumber(const ComplexNumber &org_num){
	mImaginaryPart = org_num.mImaginaryPart;
	mRealPart = org_num.mRealPart;
}

//4
ComplexNumber::ComplexNumber(double x){
	mImaginaryPart = 0;
	mRealPart = x;
}
//5
ComplexNumber ComplexNumber::CalculateConjugate() const{
	ComplexNumber temp(mRealPart,-mImaginaryPart);
	return temp;
}
//6
void ComplexNumber::SetConjugate(){
	mImaginaryPart = - mImaginaryPart;
}
	

