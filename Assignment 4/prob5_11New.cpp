#include <iostream>
#include <cmath>
#include "ComplexNumber.h"

int InJuliaSet(int ix,int iy, int Nx, int Ny);

int main (int argc, char* argv[])
{
	//Convert to integer
	//Number of elements in the y direction
	int Ny = atoi(argv[1]);
	//Number of elements in the x direction 
	int Nx = 2 * Ny;
	
	int** pixcelArray = new int*[Ny];
	pixcelArray[0] = new int [Ny * Nx];
	for (int i = 1; i < Nx; i ++)
	{
		pixcelArray[i] = pixcelArray[i-1] +Nx;
	}
	//Use the InJuliaSet function on every single element of the matrix
	for (int i =0; i < Ny; i++)
	{
		for (int j = 0; j <Nx; j++)
		{
			pixcelArray[i][j] =InJuliaSet(j,i,Nx,Ny);
		}
	}
	
	//Print out the results
	for (int i =0; i < Ny; i++)
	{
		for (int j = 0; j <Nx; j++)
		{
			//"X " if in the set, "  " if not in the set
			if (pixcelArray[i][j] == 1)
			{
				std::cout << "X ";
			}
			else
			{
				std::cout<<"  ";
			}
			
			if (j == Nx-1)
			{
				std::cout<< "\n";
			}
		}
	}
}

int InJuliaSet(int ix,int iy, int Nx, int Ny)
{
	ComplexNumber z;
	double zx;
	double zy;
	double cx;
	double cy;
	cx = 0.7885*cos(M_PI);
	cy = 0.7885*sin(M_PI);
	//zx = scaled x coordinate of pixel ix (scale to lie in (-2, 2))
	//zx represents the real part of z 
	zx = -2.0 + static_cast<double>(ix)/static_cast<double>(Nx)*(4.0);
	//zy = scaled y coordinate of pixel iy (scale to lie in (-1, 1))
	//zy represents the imaginary part of z 
	zy = -1.0 + static_cast<double>(iy)/static_cast<double>(Ny)*(2.0);
	z = ComplexNumber(zx,zy);
	
	int iteration = 0;
	int max_iteration = 1000;
	while ((( pow(RealPart(z),2) + pow(ImaginaryPart(z),2) < 4) && (iteration < max_iteration)))
	{
		double xtemp;
		double zytemp;
		double zxtemp;
		xtemp = pow(RealPart(z),2) -pow(ImaginaryPart(z),2);
		zytemp = 2.0*RealPart(z)*ImaginaryPart(z) + cy;
		zxtemp = xtemp + cx;
		z = ComplexNumber(zx,zy);
		
		iteration ++;
	}
	
	if (iteration == max_iteration)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
	
