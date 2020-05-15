#include <iostream>
#include <cmath>

void randNumbers(double array[],int size);
double mean(double array[], int size);
void stdev_skew(double array[], int size, double mean, double& stdev,double* p_Skew = nullptr);

int main (int argc, char* argv[])
{
	//Convert to integer
	int N = atoi(argv[1]);
	//Pointer for the array
	double *dynamic_array;
	//Dynamically allocate array based off of user's input 
	dynamic_array = new double[N];
	//Call the randNumbers function to fill in random numbers to the array
	randNumbers(dynamic_array, N);
	
	//display the array 
	std::cout << "The Array:"<< std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout <<dynamic_array[i] << "\n";
	}
	//Calculate and display the mean of the array
	double average;
	average = mean(dynamic_array,N);
	std::cout <<"Mean: " << average<< "\n";
	
	//Calculate and display the standard deviation and the skew of the array
	double stdev, skew;
	
	std::cout<<"stdev_skew(dynamic_array, N, average, stdev), output:\n";
	stdev_skew(dynamic_array, N, average, stdev);
	std::cout << "\n";
	std::cout<<"stdev_skew(dynamic_array, N, average, stdev,skew), output:\n";
	stdev_skew(dynamic_array, N, average, stdev,&skew);
	
	//de-allocate at the end of the main function 
	delete [] dynamic_array;
	
	return 0;
}

void randNumbers(double *array, int size)
{
	for (int i = 0; i < size;i++)
	{
		int randomint;
		randomint = std::rand();
		double randomdoub;
		randomdoub = static_cast<double>(randomint) / RAND_MAX;
		array[i] = randomdoub;
	}
}

double mean(double *array, int size)
{
	//Mean calculation
	double sum = 0;
	for (int i =0; i < size; i++)
	{
		sum += array[i];
	}
	double average;
	average = sum / size;
	return average;
}

void stdev_skew(double *array, int size, double mean, double& stdev,double* p_Skew){
	//Standard deviation calculation
	stdev = 0;
	for (int i = 0; i < size; i++)
	{
		//double a = array[i];
		stdev += pow(array[i] - mean,2.0);
	}
	stdev = sqrt(stdev / double(size));
	std::cout <<"Standard Deviation: " << stdev<< "\n";
	//Only calculate skew if the variable is given in the input
	if (p_Skew){
		*p_Skew =0;
		for (int i = 0; i < size; i++)
		{
			*p_Skew += pow(array[i] - mean,3.0);
		}
		*p_Skew = *p_Skew/(size*pow(stdev,3.0));
		std::cout <<"Skew: " << *p_Skew << "\n";
	}
}

 