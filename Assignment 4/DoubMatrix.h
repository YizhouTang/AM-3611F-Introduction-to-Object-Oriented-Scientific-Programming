#ifndef DOUBMATRIX_H
#define DOUBMATRIX_H
#include "DoubArray.h"

class DoubMatrix
{
private:
	double** m_matrix;
	// n x m matrices
	int m_n;
	int m_m;
	int m_size;

public:
	//2 c)
	DoubMatrix(int n, int m);
	DoubMatrix(const DoubMatrix &org_matrix);
	~DoubMatrix();
	void setValue(int n,int m, int value) { m_matrix[n][m] = value; }
	double& getValue(int n, int m) const { return m_matrix[n][m]; }
	int getSize() { return m_size; }
	friend std::ostream& operator<< (std::ostream& output, const DoubMatrix& matrix);
	//Multiplication: matrix & matrix 
	friend DoubMatrix operator*(const DoubMatrix& m0,const DoubMatrix& m1);
	
	//2 d)
	//Multiplication: vector & matrix 
	friend DoubArray operator*(const DoubArray& v0,const DoubMatrix& m1);
	//Multiplication: matrix & vector 
	friend DoubMatrix operator*(const DoubMatrix& m0,const DoubArray& v1);
	//Multiplciation: scalar & matrix
	friend DoubMatrix operator*(const int scalar,const DoubMatrix& m1);
	//Multiplciation: matrix & scalar
	friend DoubMatrix operator*(const DoubMatrix& m0,const int scalar);
	
	//2 e)
	//Overloading the = operator 
	DoubMatrix& operator= (const DoubMatrix& matrix);
	
	//2 f)
	//pth power
	DoubMatrix Pow(int p);
};

#endif
