#include <cmath>
#include <iostream>
int main (int argc, char* argv[])
//Question 1.3 from the text
//This program declares two vectors as arrays of double precision floating point numbers
// of length 3 and assigns values to each of the entries.
// It calculates the dot product of these vectors and prints it to screen.
// Lastly, it also prints the Euclidean norm of both vectors to screen.
{
	//Declare arrays of double precision floating point numbers of length 3
	double array1[3] = {1.1,2.2,3.3};
	double array2[3] = {4.4,5.5,6.6};
	// Compute the dot product of the two arrays
	double dotProduct;
	dotProduct = (array1[0] * array2[0]) + (array1[1] * array2[1]) + (array1[2] * array2[2]);
	
	// Print out the results
	std::cout<< "array1: {" << array1[0] << "," << array1[1] << "," << array1[2] << "}" << std::endl;
	std::cout<< "array1: {" << array2[0] << "," << array2[1] << "," << array2[2] << "}" << std::endl;
	std::cout << "The dot product of array1 and array2 is " << dotProduct << std::endl;
	
	// Euclidean norm of both vectors
	double norm1;
	double norm2;
	norm1 = sqrt(pow(array1[0],2) + pow(array1[1],2) + pow(array1[2],2));
	norm2 = sqrt(pow(array2[0],2) + pow(array2[1],2) + pow(array2[2],2));
	std::cout<<"The Euclidean norm of array1 is " << norm1 << std::endl;
	std::cout<<"The Euclidean norm of array2 is " << norm2 << std::endl;
	return 0;
}