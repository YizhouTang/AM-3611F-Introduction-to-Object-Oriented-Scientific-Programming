#include <iostream>
#include <cassert>
int main (int argc, char* argv[])
{
	double A[2][2] = {{4.0,10.0},{1.0,1.0}};
	double d;
	//calculate the determinant of the matrix
	d = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	//Assert statement to check if the determinant of the matrix is nonzero
	assert(d !=0 );
	//calculate the inverse of A
	double inverseA[2][2];
	inverseA[0][0] = 1/d * A[1][1];
	inverseA[1][1] = 1/d * A[0][0];
	inverseA[0][1] = 1/d * -A[1][0];
	inverseA[1][0] = 1/d * -A[0][1];
	//print out the summary
	std::cout<< "A: {{" << A[0][0] << "," << A[0][1] << "},{" << A[1][0] << "," << A[1][1] << "}}" << std::endl;
	std::cout<< "The determinant: "<< d << std::endl;
	std::cout<< "Multiply 1/determinant to the matrix below to get the inverse of A:"<< std::endl;
	std::cout<< "{{" << A[1][1] << "," << -A[1][0] << "},{" << -A[0][1] << "," << A[0][0] << "}}" << std::endl;
	std::cout<< "As a result, the inverse of A is {{" << inverseA[0][0] << "," << inverseA[0][1] << "},{" << inverseA[1][0] << "," << inverseA[1][1] << "}}" << std::endl;	
	return 0;
}