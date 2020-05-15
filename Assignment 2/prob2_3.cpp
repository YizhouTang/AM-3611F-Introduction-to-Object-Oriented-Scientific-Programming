//2.3
//Yizhou Tang

//2.3 In this exercise you are asked to write and test a program which sums a list 
//of numbers which are provided by a user via std::cin
#include <iostream>
int main(int argc, char* argv[])
{
	int sum = 0;
	int inputInt = 0;
	bool overLimit = false; 
	//Instructions:
	std::cout << "Enter a list of numbers" << std::endl;
	std::cout << "Instruction:" << std::endl;
	std::cout << "Enter each integer followed by the return key" << std::endl;
	std::cout << "Enter -1 at the end of the list of integers to be added" << std::endl;
	std::cout << "Enter -2 to reset" << std::endl;
	
	while ((inputInt != -1) && (overLimit == false))
	{
		std::cin >> inputInt;
		//check for positive integer 
		if (inputInt > 0) 
		{
			sum += inputInt;
		}
		//check if user wants to reset 
		else if (inputInt == -2)
		{
			sum = 0;
		}
		if (sum > 100)
		{
			overLimit = true;
			std::cout << "Sum exceeded 100" << std::endl;
		}
	}
	//print out the result
	std::cout << "Sum: " << sum << std::endl;
}

