#include <iostream>
#include <fstream>
#include <cassert>
int main(int argc, char* argv[])
{
	std::ifstream read_file("xy.dat");
	if (!read_file.is_open())
	{
		return 1;
	}
	int number_of_rows = 0;
	double dummy1, dummy2;
	while (read_file >> dummy1 >> dummy2)
	{
		number_of_rows++;
	}
	std::cout << "Number of rows = "
			  << number_of_rows << "\n";
	read_file.clear();
	read_file.seekg(std::ios::beg);
	double* x;
	x = new double [number_of_rows];
	double* y;
	y = new double [number_of_rows];
	
	for (int i = 0; i< number_of_rows; i++)
	{
		read_file >> dummy1 >> dummy2;
		x[i] = dummy1;
		y[i] = dummy2;
	}
	//Code is going to print a file called prob4_5.dat
	std::ofstream write_output("prob4_5.dat");
	//Check if the file is opened
	assert(write_output.is_open());
	
	for (int i =0; i< number_of_rows; i++)
	{
		write_output << x[i] <<","<< y[i] << "\n";
	}
	delete[] x;
	delete[] y;
	return 0;
}
