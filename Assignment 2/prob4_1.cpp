#include <iostream>
int main(int argc, const char * argv[])
{
	int i = 5;
	int *p_j;
	p_j = &i;//store the address of i 
	*p_j = 5 * *p_j;
	int *p_k;//
	p_k = new int;
	*p_k = i;
	delete p_k;
}