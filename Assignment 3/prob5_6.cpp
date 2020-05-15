#include <iostream>
#include <cassert>
//A vector and a matrix of given sizes (assume row vector)
void multiply(double* vector, double** matrix, int size, int rowB, int colB);

//A matrix and a vector of given sizes （assume column vector)
void multiply(double** matrix, double* vector, int rowA, int colA, int size);

//A scalar and a matrix of a given size
void multiply(double scalar, double** matrix, int rowB, int colB);

//A matrix of a given size and a scalar
void multiply(double** matrix,double scalar, int rowA, int colA);

int main (int argc, char* argv[])
{
	int rowA,colA, size;
	rowA = 2;
	colA = 2;
	size = 2;

	//Allocate memories dynamically for the matrix
	double** A = new double*[rowA];
	A[0] = new double [rowA * colA];
	for (int i = 1; i < rowA; i ++)
	{
		A[i] = A[i-1] +colA;
	}
	//Assign values to the matrix
	A[0][1] = 2.0;
	A[1][0] = 2.0;
	
	double* B = new double [size];
	B[1] = 10;
	B[0] = 0;
	
	//Display the matrix and vectors
	std::cout << "Matrix:\n";
	std::cout<< "A: {{" << A[0][0] << "," << A[0][1] << "},{" 
					<< A[1][0] << "," << A[1][1] << "}}\n";
	std::cout << "Vector:\n";
	std::cout <<" B: {" << B[0] << ", "<< B[1] << "}\n";
	
	//Question 1: Vector x matrix, assuming the vector is a row vector (1 x n)
	std::cout << "Question 1, Vector & Matrix Multiplication, BA (Assume row vector):\n";
	multiply(B,A, size,rowA,colA);
	//Question 2: Matrix x vector, assuming the vector is a column vector 
	std::cout << "Question 2, Matrix & Vector Multiplication, AB (Assume column vector):\n";
	multiply(A,B,rowA,colA,size);
	std::cout << "Question 3, Scalar & Matrix Multiplication, 2A:\n";
	multiply(2,A, rowA,colA);
	std::cout << "Question 4, Matrix & Scalar Multiplication, A*2:\n";
	multiply(A,2, rowA,colA);
	
	delete A[0];
	delete A;
	delete B;
	
}

//Vector x matrix (assume vector is row vector)
void multiply(double* vector, double** matrix, int size, int rowB, int colB)
{
	assert(size == rowB);
	double* answer = new double[size];
	//Compute matrix multiplication
	for (int i = 0; i < rowB; i ++)
	{
		for (int j = 0; j < size;j++)
		{
			answer[i] += vector[j] * matrix[i][j];
		}
	}
	std::cout << "{";
	for (int i =0; i < size;i++)
	{
		std::cout << answer[i];
		if (i != size-1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "}\n";
}
//Matrix x vector (assume vector is column vector)
void multiply(double** matrix, double* vector, int rowA, int colA, int size)
{
	assert(colA == size);
	double* answer = new double[size];
	//Compute matrix multiplication
	for (int i = 0; i < rowA; i ++)
	{
		for (int j = 0; j < size;j++)
		{
			answer[i] += matrix[i][j] * vector[j] ;
		}
	}
	
	std::cout << "{";
	for (int i =0; i < size;i++)
	{
		std::cout <<"{"<< answer[i] << "}";
		if (i != size-1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "}\n";
	delete answer;
}

//Scalar x matrix
void multiply(double scalar, double** matrix, int rowB, int colB)
{
	//Construct a new matrix for answer
	double** answer = new double*[rowB];
	answer[0] = new double [rowB * colB];
	for (int i = 1; i < rowB; i ++)
	{
		answer[i] = answer[i-1] + colB;
	}
	
	//Compute matrix multiplication
	for (int i = 0; i < rowB; i++)
	{
		for (int j = 0; j < colB; j++)
		{
			answer[i][j] = scalar * matrix[i][j];
		}
	}
	//Display the result to the screen
	//This is done so that it can print matrices with any sizes correctly 
	std::cout<<"{";
	for (int i =0; i <rowB;i++)
	{
		if(i != 0){
			std::cout<<",";
		}
		std::cout<<"{";
		for (int j = 0; j <colB; j++)
		{
			std::cout<<answer[i][j];
			if (j != colB -1){
				std::cout<< ", ";
			}
		}
		std::cout<<"}";
	}
	std::cout<<"}\n";
}

//Matrix x scalar
void multiply(double** matrix,double scalar, int rowA, int colA)
{
	//Construct a new matrix for answer
	double** answer = new double*[rowA];
	answer[0] = new double [rowA * colA];
	for (int i = 1; i < rowA; i ++)
	{
		answer[i] = answer[i-1] + colA;
	}
	
	//Compute matrix multiplication
	for (int i = 0; i < rowA; i++)
	{
		for (int j = 0; j < colA; j++)
		{
			answer[i][j] = scalar * matrix[i][j];
		}
	}
	//Display the result to the screen
	//This is done so that it can print matrices with any sizes correctly 
	std::cout<<"{";
	for (int i =0; i <rowA;i++)
	{
		if(i != 0){
			std::cout<<",";
		}
		std::cout<<"{";
		for (int j = 0; j <colA; j++)
		{
			std::cout<<answer[i][j];
			if (j != colA -1){
				std::cout<< ", ";
			}
		}
		std::cout<<"}";
	}
	std::cout<<"}\n";
	delete answer[0];
	delete answer;
}