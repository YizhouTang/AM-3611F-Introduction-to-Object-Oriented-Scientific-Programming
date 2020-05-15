#include <iostream>
#include <cassert>
#include "DoubMatrix.h"

//Two matrices of given sizes
void multiply(DoubMatrix A, DoubMatrix matrixB, int rowA, int colA, int rowB, int colB);

int main (int argc, char* argv[])
{
	//Parameters for matrices
	
	
	int rowA,colA, rowB, colB;
	rowA = 2;
	colA = 2;
	rowB = 2;
	colB = 3;
	DoubMatrix A = DoubMatrix(rowA,colA);
	DoubMatrix B = DoubMatrix(rowB,colB);

	//Assign values to the matices
	A.setValue(0,1,1.0);
	A.setValue(1,0,1.0);
	B.setValue(0,2,2.0);
	B.setValue(1,2,3.0);
	
	//Display the matrices
	std::cout << "Matrices:\n";
	std::cout <<"A:" << std::endl;
	std::cout<< A << std::endl;
	std::cout <<"B:" << std::endl;
	std::cout << B << std::endl;
	std::cout<<"\n";
	//Show the correct and incorrect scenarios
	std::cout << "Correct Scenario: \nResult of AB(2x2 and 2x3):\n";
	DoubMatrix C = A * B;
	std::cout<<C<<std::endl;
	std::cout << "Incorrect Scenario: \nResult of BA(2x3 and 2x2):\n";
	DoubMatrix D = B * A;
}
