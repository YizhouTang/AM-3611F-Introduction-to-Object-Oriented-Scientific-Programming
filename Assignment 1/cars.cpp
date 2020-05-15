#include <iostream>
int main(int argc, char* argv[])
//This program records 5 inputs(number of cars drove past the user's house)from the user into an integer array
// then calculates and prints out the average of these 5 integers
{
	//Declare an empty array for user inputs 
	int carNums[5];
	int sum;
	double result;
	//Ask the user for inputs and record them into the array
	std::cout << "Enter the number of cars drove past your house each day(5 entries)" << std::endl;
	std::cin >> carNums[0];
	std::cin >> carNums[1];
	std::cin >> carNums[2];
	std::cin >> carNums[3];
	std::cin >> carNums[4];
	//Calculate the sum of all 5 numbers
	sum = carNums[0] + carNums[1] + carNums[2] + carNums[3] + carNums[4];
	//Divide the sum by 5 to get the average
	//Use C++ static_cast to convert "sum" to a double
	result = static_cast<double> (sum) / 5;
	//Print out the final statement
	std::cout << "The average of the number of cars drove past your house each day for 5 days is " << result << std::endl;
}
