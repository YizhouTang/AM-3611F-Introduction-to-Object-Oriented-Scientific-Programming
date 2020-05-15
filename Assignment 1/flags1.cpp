#include <iostream>
int main(int argc, char* argv[])
//Question 1.7 from the text
//This program is meant to be used to 
//investigate the use of the compiler error warning flags
// 1. Attempt to change a constant integer variable's value
{
	//Declare two variables
	const int integerTest1 = 10;
	//Attempt to change integerTest1's value
	integerTest1 = 100;
}