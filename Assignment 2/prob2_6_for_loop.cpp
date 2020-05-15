#include <iostream>
#include <cmath>
int main(int argc, char*argv[])
{
	double x0;
	double y;
	double dy;
	double x[101];
	//set the initial guess as the first element of the array
	x[0] = 0;
	y = exp(x[0]) + pow(x[0],3) - 5;
	dy = exp(x[0]) + 3 * pow(x[0],2); 
	
	for (int i = 1; i<101; i++)
	{
		x[i] = x[i-1] - y/dy;
		//update the variables
		y = exp(x[i]) + pow(x[i],3) -5;
		dy = exp(x[i]) + 3 * pow(x[i],2);
		//print out the results everytime
		std::cout<< "x" << i << " = " << x[i] << std::endl;
	}
}
