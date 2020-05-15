#include <iostream>
#include <cassert>
#include "DoubMatrix.h"
#include "DoubArray.h"

int main (int argc, char* argv[])
{
	int rowC,colC, rowv,colv;
	rowC = 2;
	colC = 2;
	rowv = 2;
	colv = 2;

	DoubMatrix C = DoubMatrix(rowC,colC);
	//Assign values to the matrix
	C.setValue(0,0,1.0);
	C.setValue(0,1,2.0);
	C.setValue(1,0,2.0);
	C.setValue(1,1,1.0);
	DoubMatrix v = DoubMatrix(rowv,colv);
	v.setValue(0,0,10.0);
	v.setValue(0,1,10.0);
	v.setValue(1,0,10.0);
	v.setValue(1,1,10.0);
	int D = 10;
	DoubMatrix A(2,2);
		
	A = C*D; 
	std::cout << "A = \n" <<  A << std::endl; 
	std::cout << "C*D =\n"<< C*D << std::endl;
	v = A.Pow(4)*v; 
	DoubMatrix u = A*A*A*A*v; 
	std::cout << "u = \n" << u << std::endl;
	std::cout << "v = \n" << v << std::endl;
}
