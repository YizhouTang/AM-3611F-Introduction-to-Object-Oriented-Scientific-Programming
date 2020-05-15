#include <iostream>

void swapDouble(double& i, double& j);

int main(int argc, char* argv[])
{
	double x = 1.1;
	double y = 2.2;

	
	std::cout <<"x: "<< x<<"\n";
	std::cout <<"y: "<< y<<"\n";	
	swapDouble(x,y);
	std::cout <<"x: "<< x<<"\n";
	std::cout <<"y: "<< y<<"\n";
}

void swapDouble(double& i, double& j)
{
	double temp = i;
	i = j;
	j = temp;
	
}