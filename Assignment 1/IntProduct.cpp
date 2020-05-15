#include <iostream>
int main(int argc, char* argv[])
// Question 1.2 from the text
// This program asks the user for two integer inputs
// then it writes the product of these integers to the screen
{
	int num1, num2, result;
	std::cout << "Enter Two Integers" << std::endl;
	std::cin >> num1;
	std::cin >> num2;
	result = num1 * num2;
	std::cout << "The product of " << num1 << " and " << num2 <<" is " << result <<"\n";
	return result;
}
