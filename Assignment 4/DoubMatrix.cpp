#include <iostream>
#include <cassert>
#include "DoubMatrix.h"

	DoubMatrix::DoubMatrix(int n, int m) // constructor
	{
		assert(n > 0 && m >0);
		m_n = n;
		m_m = m;
		m_size = n*m;
		
		//Allocate memories dynamically for the matrix
		m_matrix = new double*[m_n];
		m_matrix[0] = new double [m_size];
		for (int i = 1; i < m_n; i ++)
		{
			m_matrix[i] = m_matrix[i-1] + m_m;
		}
		//std::cout << "...finishing constructor\n";
	}

	DoubMatrix::DoubMatrix(const DoubMatrix &org_matrix) // copy constructor
	{
		m_n = org_matrix.m_n;
		m_m = org_matrix.m_m;
		m_size = org_matrix.m_size;
		
		m_matrix = new double*[m_n];
		m_matrix[0] = new double [m_size];
		for (int i = 0; i < m_n; i ++)
			for (int j = 0; j <m_m; j++)
			{
				m_matrix[i][j] = org_matrix.getValue(i,j);
			}
		//std::cout << "...finishing copy constructor\n";
	}

	DoubMatrix::~DoubMatrix() // destructor
	{
		// Dynamically delete the array we allocated earlier
		delete[] m_matrix[0];
		delete[] m_matrix ;
		//std::cout << "...finishing destructor\n";
	}
	//Overloading the stream insertion << operator 
	std::ostream& operator<< (std::ostream& output, const DoubMatrix& matrix)
	{
		for (int i =0; i < matrix.m_n;i++)
		{
			for (int j = 0; j <matrix.m_m; j++)
			{
				output<<matrix.m_matrix[i][j];
				if (j != matrix.m_m -1){
					output<< " ";
				}
			}
			output<<"\n";
		}
		return output;
	}
	//Overloading the * operator 
	DoubMatrix operator*(const DoubMatrix& m0,const DoubMatrix& m1)
	{
		//Check if the matrices have suitable v1.m_sizes
		assert (m0.m_m == m1.m_n);
		//Construct a new matrix for answer
		DoubMatrix answer = DoubMatrix(m0.m_n,m1.m_m);
		//Compute matrix multiplication
		for (int i = 0; i < m0.m_n; i++)
		{
			for (int j = 0; j < m1.m_m; j++)
			{
				for (int k = 0; k < m0.m_m; k++)
				{
					answer.m_matrix[i][j] += m0.m_matrix[i][k] * m1.m_matrix[k][j];
				}
			}
		}
		return answer;
	}	
	//2 d)
	//Multiplication: vector & matrix 
	DoubArray operator*(const DoubArray& v0,const DoubMatrix& m1)
	{
		assert(v0.m_length == m1.m_n);
		DoubArray answer = DoubArray(v0.m_length);
		for (int i = 0; i < m1.m_n; i ++)
		{
			for (int j = 0; j < v0.m_length;j++)
			{
				answer[i] += v0[j] * m1.getValue(i,j);
			}
		}
		return answer; 
	}
	//Multiplication: matrix & vector 
	DoubMatrix operator*(const DoubMatrix& m0,const DoubArray& v1)
	{
		assert(m0.m_m == v1.m_length);
		DoubMatrix answer = DoubMatrix(m0.m_n,1);
		//Compute matrix multiplication
		for (int i = 0; i < m0.m_n; i++)
		{
			for (int j = 0; j < 1; j++)
			{
				for (int k = 0; k < m0.m_m; k++)
				{
					answer.m_matrix[i][j] += m0.m_matrix[i][k] * v1.m_array[k];
				}
			}
		}
		
		return answer;
	}
	
	//Multiplciation: scalar & matrix
	DoubMatrix operator*(const int scalar,const DoubMatrix& m1)
	{
		DoubMatrix answer = DoubMatrix(m1.m_n,m1.m_m);
		//Compute matrix multiplication
		for (int i = 0; i < m1.m_n; i++)
		{
			for (int j = 0; j < m1.m_m; j++)
			{
				answer.setValue(i,j,scalar * m1.getValue(i,j));
			}
		}
		return answer;
	}
	
	//Multiplciation: matrix & scalar
	DoubMatrix operator*(const DoubMatrix& m0,const int scalar)
	{
		DoubMatrix answer = DoubMatrix(m0.m_n,m0.m_m);
		for (int i = 0; i < m0.m_n; i++)
		{
			for (int j = 0; j < m0.m_m; j++)
			{
				answer.setValue(i,j,scalar * m0.getValue(i,j));
			}
		}
		return answer;
	}
	
	//2e)Overloading the = operator 
	DoubMatrix& DoubMatrix::operator= (const DoubMatrix& matrix)
	{
		m_n = matrix.m_n;
		m_m = matrix.m_m;
		m_size = matrix.m_size;
		for (int i = 0; i < matrix.m_n; i++)
		{
			for (int j = 0; j < matrix.m_m; j++)
			{
				m_matrix[i][j] = matrix.m_matrix[i][j];
			}
		}
		return *this;
	}
	//2f) pth power
	DoubMatrix DoubMatrix::Pow(int p)
	{
		//Check if it is a square 
		assert(m_n == m_n);
		for (int i = 0; i < p; i++)
		{
			(*this) = (*this) * (*this);
		}
		return *this;
	}
	
	
		
	
	

