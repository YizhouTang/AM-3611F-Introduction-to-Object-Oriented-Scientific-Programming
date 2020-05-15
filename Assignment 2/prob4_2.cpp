#include <iostream>
int main(int argc, const char * argv[])
{
	int a = 1;
	int b = 2;
	int *p_i;
	int *p_j;
	int *p_k;
	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";
	p_i = &a;
	p_j = &b;
	p_k = new int;
	*p_k = a;
	*p_i = b;
	*p_j = *p_k;
	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";
	delete p_k; 
}