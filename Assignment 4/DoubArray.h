#ifndef DOUBARRAY_H
#define DOUBARRAY_H
#include "DoubMatrix.h"
class DoubMatrix;
DoubArray operator*(const DoubArray& v0,const DoubMatrix& m1);
DoubMatrix operator*(const DoubMatrix& m0,const DoubArray& v1);

class DoubArray
{
private:
	double *m_array;
	int m_length;
	double m_norm;
	bool m_normflag = false;

public:
	DoubArray(int length);
	DoubArray(const DoubArray &org_array);
	~DoubArray();
	double PNorm(int p);
	DoubArray operator- (const DoubArray& a1) const;
	DoubArray& operator= (const DoubArray& array);
	double& operator[] (const int index);
	const double& operator[] (const int index) const;
	void setValue(int index, double value);
	double & getValue(int index) { return m_array[index]; }
	int getLength() { return m_length; }
	//2 b)
	friend std::ostream& operator<< (std::ostream& output, const DoubArray& array);
	//2 d)
	//Multiplication: vector & matrix 
	friend DoubArray operator*(const DoubArray& v0,const DoubMatrix& m1);
	//Multiplication: matrix & vector 
	friend DoubMatrix operator*(const DoubMatrix& m0,const DoubArray& v1);
};
#endif