#include <iostream>
// Write code that sends the address of an integer 
// to a function that changes the value of the integer.
void pointerFunc(int* pointerA);

int main (int argc, char* argv[])
{
	int x = 5;
	std::cout <<"Address = " << &x << '\n';
	pointerFunc(&x);
	
}

void pointerFunc(int* ptr)
{
	*ptr = 6;
	std::cout << "The value of p_x is " << *ptr << '\n';
}

	