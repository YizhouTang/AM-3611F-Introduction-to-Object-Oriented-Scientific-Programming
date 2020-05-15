#include <fstream>
#include <iostream>
#include <cassert>
int main(int argc, const char * argv[])
{
	int numGridPoints = atoi(argv[1]);
	//Ensure that the number of grid points is greater than 1
	assert(numGridPoints > 1);
	std::cout << "Number of grid points = " << numGridPoints << std::endl;
	//Use the number of grid points to calculate the step size h 
	double h = 1.0 / numGridPoints;
	//Code is going to print a file called xy.dat
	std::ofstream write_output("xy.dat");
	//Check if the file is opened
	assert(write_output.is_open());
	//Print out the results 
	std::cout << "Column 1: the calculated values of x Column 2: the calculated values of y"<< std::endl;
	//y(0) = 1
	double y = 1.0;
	double x = 0.0;
	std::cout << x <<"	"<< y << "\n";
	write_output << x <<"	"<< y << "\n";
	//Iterate from 0 to 1, note x<1, we already have x= 0 and y(0) =1, so we only need N-1 more grid points 
	for (int i =0; i< numGridPoints-1; i++)
	{
		x += h;
		//Calculate the next y 
		y = y/(1+h);
		std::cout << x <<"	"<< y << "\n";
		write_output << x <<"	"<< y << "\n";
	}
}