#include <iostream>
#include <fstream>
#include <cassert>
int main (int argc, char* argv[])
{
	double x[4] = {0.0, 1.0, 1.0, 0.0};
	double y[4] = {0.0, 0.0, 1.0, 1.0};
	
	std::ofstream write_output("x_and_y.dat");
	//Check if the file is opened
	assert(write_output.is_open());
	//Scientific format, plus signs are shown for positive numbers,
	//and precision is set to 10 significant figures
	write_output.setf(std::ios::scientific);
	write_output.setf(std::ios::showpos);
	write_output.precision(10);
	//write x to the file
	for (int i = 0; i < 4; i++)
	{
		write_output << x[i];
		if (i == 3)
		{ 
			write_output << "\n";
			// Extend the code so that the output stream is ﬂushed immediately 
			// after each line of the ﬁle is written.
			write_output.flush();
		}
		else
		{
			write_output << " ";
		}
	}
	//write y to the file 
	for (int i = 0; i < 4; i++)
	{
		write_output << y[i];
		if (i <= 3)
		{
			write_output << " ";
		}
	}
	// Extend the code so that the output stream is ﬂushed immediately 
	// after each line of the ﬁle is written.
	write_output.flush();
	return 0;
}
