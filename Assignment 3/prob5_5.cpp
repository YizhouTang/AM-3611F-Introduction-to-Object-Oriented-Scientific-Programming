#include <iostream>
#include <cassert>

//Two matrices of given sizes
void multiply(double** matrixA, double** matrixB, int rowA, int colA, int rowB, int colB);

int main (int argc, char* argv[])
{
	//Parameters for matrices
	int rowA,colA, rowB, colB, rowC, colC;
	rowA = 2;
	colA = 2;
	rowB = 2;
	colB = 3;
	
	//Allocate memories dynamically for the matrices
	double** A = new double*[rowA];
	double** B = new double*[rowB];
	A[0] = new double [rowA * colA];
	B[0] = new double [rowB * colB];
	for (int i = 1; i < rowA; i ++)
	{
		A[i] = A[i-1] +colA;
	}
	for (int i = 1; i < rowB; i ++)
	{
		B[i] = B[i-1] +colB;
	}
	//Assign values to the matices
	A[0][1] = 1.0;
	A[1][0] = 1.0;
	B[0][2] = 2.0;
	B[1][2] = 3.0;
	
	//Display the matrices
	std::cout << "Matrices:\n";
	std::cout<< "A: {{" << A[0][0] << "," << A[0][1] << "},{" 
					<< A[1][0] << "," << A[1][1] << "}}\n";
	std::cout<< "B: {{" << B[0][0] << "," << B[0][1] << "," << B[0][2]<< "},{" 
					<< B[1][0] << "," << B[1][1] <<  "," << B[1][2]<< "}}\n";
	std::cout<< "\n";
	
	//Show the correct and incorrect scenarios
	std::cout << "Correct Scenario: \nResult of AB(2x2 and 2x3):\n";
	multiply (A,B,rowA,colA,rowB,colB);
	std::cout<<"\n";
	std::cout << "Incorrect Scenario: \nResult of BA(2x3 and 2x2):\n";
	multiply (B,A,rowB,colB, rowA,colA);
	delete A[0];
	delete B[0];
	delete A;
	delete B;
}

//Matrix multiplication 
void multiply(double** matrixA, double** matrixB, int rowA, int colA, int rowB, int colB)
{
	//Check if the matrices have suitable sizes
	assert (colA == rowB);
	//Construct a new matrix for answer
	double** answer = new double*[rowA];
	answer[0] = new double [rowA * colB];
	for (int i = 1; i < rowA; i ++)
	{
		answer[i] = answer[i-1] + colB;
	}
	//Compute matrix multiplication
	for (int i = 0; i < rowA; i++)
	{
		for (int j = 0; j < colB; j++)
		{
			for (int k = 0; k < colA; k++)
			{
				answer[i][j] += matrixA[i][k] * matrixB[k][j];
			}
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
	
	delete answer[0];
	delete answer;
}
