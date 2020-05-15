#include <fstream>
#include <iostream>
#include <cassert>
#include <cmath>
#include "DoubArray.h"


int getN();
void ImpEuler(int N,DoubArray *y);
void ImpEuler2(int N, DoubArray *y);

int main(int argc, const char * argv[])
{
	int numGridPoints = getN();
	//Ensure that the number of grid points is greater than 1
	assert(numGridPoints > 1);

	DoubArray *y1 = new DoubArray(numGridPoints+1);
	ImpEuler(numGridPoints,y1);
	//Print out the descriptions
	std::cout << "Column 1: N \n";
	std::cout<< "Column 2: Euler solution \n";
	std::cout<< "Column 3: Exact solution \n";
	std::cout<< "Column 4: Difference between the exact and Euler solution \n";
	for (int i = 10; i<110; i += 10){
		DoubArray *y2 = new DoubArray(i+1);
		ImpEuler2(i,y2);
	}
}

int getN(){
	int N;
	std::cout << "Pleaes enter the number of gridpoints N. \n";
	std::cin >> N;
	return N;
}
//Question e
void ImpEuler(int N,DoubArray *y){
	std::cout << "Number of grid points = " << N << std::endl;
	//Use the number of grid points to calculate the step size h 
	double h = 1.0 / N;
	//Code is going to print a file called xy.dat
	std::ofstream write_output("xy.dat");
	//Check if the file is opened
	assert(write_output.is_open());
	//Print out the results 
	std::cout << "Column 1: the calculated values of x Column 2: the calculated values of y"<< std::endl;
	//y(0) = 1
	(*y)[0] = 1.0;
	double x = 0.0;
	std::cout << x <<"	"<< (*y)[0] << "\n";
	write_output << x <<"	"<< (*y)[0] << "\n";
	//Iterate from 0 to 1
	for (int i =1; i<( N+1); i++)
	{
		x += h;
		//Calculate the next y 
		(*y)[i] = (*y)[i-1] / (1+h*sin(i*h));
		
		std::cout << x <<"	"<< (*y)[i] << "\n";
		write_output << x <<"	"<< (*y)[i] << "\n";
	}
}
//questionf
void ImpEuler2(int N,DoubArray *y){
	//Use the number of grid points to calculate the step size h 
	double h = 1.0 / N;
	//Code is going to print a file called ImpEuler.dat
	std::ofstream write_output("ImpEuler.dat", std::ios::app);
	//Check if the file is opened
	assert(write_output.is_open());
	
	double x = 0.0;
	(*y)[0] = 1.0;
	//Exact solution when x = 0
	DoubArray *exactSolution = new DoubArray(N+1);
	(*exactSolution)[0] = 1.0;
	//Difference between the exact and Euler solution 
	DoubArray *difference = new DoubArray(N+1);

	for (int i =1; i<( N+1); i++)
	{
		x += h;
		//Calculate the next y 
		(*y)[i] = (*y)[i-1] / (1+h*sin(i*h));
		//Calculate exact solution 
		(*exactSolution)[i] = exp(-1+cos(x));
		//Calculate difference
		(*difference) = (*exactSolution) - (*y);
	}
	std::cout << N <<"	"<< (*y)[N] <<"	"<< (*exactSolution)[N]<<"	"<< (*difference)[N] << "\n";
	write_output << h <<"	"<< (*difference).PNorm(1) <<"	"<< (*difference).PNorm(2)<< "\n";
}
