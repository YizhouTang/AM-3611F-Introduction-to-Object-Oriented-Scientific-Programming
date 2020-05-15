#include <iostream>
#include <string>
int main(int argc, char* argv[])
// Question 1.5 from the text
// This program asks the user for two separate strings (given name and family name)
// then prints the user's full name to the screen
{
	std::string givenName;
	std::string familyName;
	//Asks user for given name
	std::cout << "Enter your given name" << std::endl;
	//Save the input into the varaible "givenName"
	std::cin >> givenName;
	//Ask user for last name
	std::cout << "Enter your last name" << std::endl;
	//Save the input into the variable "lastName"
	std::cin >> familyName;
	//Print out the full name to the screen
	std::cout<< "Your name is " << givenName << " " << familyName << std::endl;
	return 0;
}