#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>

class ComplexNumber
{
private:
	double mRealPart;
	double mImaginaryPart;
public:
	ComplexNumber(double x=0, double y=0);  //set defaults to 0
	double CalculateModulus() const;
	double CalculateArgument() const;
	ComplexNumber CalculatePower(double n) const;
	ComplexNumber& operator=(const ComplexNumber& z);
	ComplexNumber operator-() const;
	friend ComplexNumber operator+(const ComplexNumber& z1,
                                 const ComplexNumber& z2);
	friend ComplexNumber operator-(const ComplexNumber& z1,
                                 const ComplexNumber& z2);
	friend std::ostream& operator<<(std::ostream& output,
                                  const ComplexNumber& z);
	//1
	double GetRealPart();
	double GetImaginaryPart();
	//2
	friend double RealPart(ComplexNumber z);
	friend double ImaginaryPart(ComplexNumber z);
	//3
	ComplexNumber(const ComplexNumber &org_num); //copy constructor
	//4
	ComplexNumber(double x);
	//5
	ComplexNumber CalculateConjugate() const;
	//6
	void SetConjugate();
};

#endif
