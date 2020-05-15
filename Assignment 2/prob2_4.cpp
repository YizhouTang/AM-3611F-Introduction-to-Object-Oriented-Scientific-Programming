#include <iostream>
int main (int argc, char* argv[])
{
	double u[3] = {1.0, 2.0, 3.0};
	double v[3] = {6.0, 5.0, 4.0}; 
	double A[3][3] = {{1.0, 5.0, 0.0}, 
					  {7.0, 1.0, 2.0}, 
					  {0.0, 0.0, 1.0}};
	double B[3][3] = {{-2.0, 0.0, 1.0}, 
					  {1.0, 0.0, 0.0},
					  {4.0, 1.0, 0.0}};
	double w[3];
	for (int i = 0; i < 3; i++)
	{
		w[i] = u[i] - 3.0 * v[i];
	}
	
	//Solutions start here
	//x= u - v
	double x[3];
	for (int i = 0; i < 3; i++)
	{
		x[i] = u[i] - v[i];
	}
	//y = Au
	double y[3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j <3; j++)
		{
			y[i] += A[i][j] * u[j];
		}
	}
	//z = Au -v
	double z[3];
	for (int i = 0; i < 3; i++)
	{
		z[i] = y[i] - v[i];
	}
	//C = 4A -3B
	double C[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			C[i][j] = 4*A[i][j] - 3*B[i][j];
		}
	}
	//D = AB
	double D[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				D[i][j] = A[i][k] * B[k][j];
			}
		}
	}
	//Print out the results
	std::cout<< "x: {{" << x[0] << "," << x[1] <<","<< x[2] << "}}" << std::endl;
	std::cout<< "y: {{" << y[0] << "," << y[1] <<","<< y[2] << "}}" << std::endl;
	std::cout<< "z: {{" << z[0] << "," << z[1] <<","<< z[2] << "}}" << std::endl;
	std::cout<< "C: {{" << C[0][0] << "," << C[0][1] << "," << C[0][2] << "},{" 
						<< C[1][0] << "," << C[1][1] << "," << C[1][2] << "},{" 
						<< C[2][0] << "," << C[2][1] << "," << C[2][2] << "}}" << std::endl;
	std::cout<< "D: {{" << D[0][0] << "," << D[0][1] << "," << D[0][2] << "},{" 
						<< D[1][0] << "," << D[1][1] << "," << D[1][2] << "},{" 
						<< D[2][0] << "," << D[2][1] << "," << D[2][2] << "}}" << std::endl;
	return 0;
}
