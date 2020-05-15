#include <cmath>
#include <iostream>
int main (int argc, char* argv[])
// Question 1.4 from the text
// This program declares four 2x2 matrices of double precision floating point numbers:
// A,B,C,D, and assigns values to the entries of A and B. It then calculates C and D.
// C = A + B
// D = AB
// Lastly it prints the entries of these matrices to screen

{
	//Declare arrays of double precision floating point numbers of length 3
	double A[2][2] = {{1.0,2.0},{ 3.0,4.0}};
	double B[2][2] = {{1.0,2.0},{ 3.0,4.0}};
	double C[2][2];
	double D[2][2];
	
	//Compute C
	C[0][0] = A[0][0] + B[0][0];
	C[0][1] = A[0][1] + B[0][1];
	C[1][0] = A[1][0] + B[1][0];
	C[1][1] = A[1][1] + B[1][1];
	
	//Compute D 
	D[0][0] = (A[0][0] * B[0][0]) + (A[0][1] * B[1][0]);
	D[0][1] = (A[0][0] * B[0][1]) + (A[0][1] * B[1][1]);
	D[1][0] = (A[1][0] * B[0][0]) + (A[1][1] * B[1][0]);
	D[1][1] = (A[1][0] * B[0][1]) + (A[1][1] * B[1][1]);

	// Print out the results
	std::cout<< "A: {{" << A[0][0] << "," << A[0][1] << "},{" << A[1][0] << "," << A[1][1] << "}}" << std::endl;
	std::cout<< "B: {{" << B[0][0] << "," << B[0][1] << "},{" << B[1][0] << "," << B[1][1] << "}}" << std::endl;
	std::cout<< "C: {{" << C[0][0] << "," << C[0][1] << "},{" << C[1][0] << "," << C[1][1] << "}}" << std::endl;
	std::cout<< "D: {{" << D[0][0] << "," << D[0][1] << "},{" << D[1][0] << "," << D[1][1] << "}}" << std::endl;


	return 0;
}