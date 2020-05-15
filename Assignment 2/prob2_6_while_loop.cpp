#include <iostream>
#include <cmath>
int main(int argc, char*argv[])
//Modified code, while loop, x_prev and x_next, without array
//Also included 2.5.3, a check that can be performed on the iterates
{
	double y;
	double dy;
	double x_prev;
	double x_next;
	bool notConverged = true;
	double epsilon = 1e-10;
	int count = 0;
	//Compute the first value before the loop
	x_prev = 0;
	y = exp(x_prev) + pow(x_prev,3) - 5;
	dy = exp(x_prev) + 3 * pow(x_prev,2);
	std::cout<< "Initial guess = 0" << std::endl;
	std::cout<< "User-prescribed epsilon = " << epsilon <<std::endl;
	while (notConverged)
	{
		x_next = x_prev - y/dy;
		//update the variables
		y = exp(x_next) + pow(x_next,3) -5;
		dy = exp(x_next) + 3 * pow(x_next,2);
		count += 1;
		//If the value is lower than epsilon then stop the loop
		if (fabs(x_next - x_prev) < epsilon)
		{
			notConverged = false;
		}
		x_prev = x_next;
		std::cout<< "x" << count << " = " << x_next << std::endl;
		//2.5.3
		//Check the accuracy
		//Print out the result of f(x_next), allowing the user to see how close it is to 0
		//the smaller the more confident about the result
		std::cout<< "f(x) = "<< y <<std::endl;
	}
}
