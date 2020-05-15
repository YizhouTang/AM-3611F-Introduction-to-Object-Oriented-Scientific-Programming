#include <iostream>
#include <cassert>
#include <cmath>
#include "DoubArray.h"
	
	DoubArray::DoubArray(int length) // constructor
	{
		assert(length > 0);

		m_array = new double[length] {};
		m_length = length;
		//std::cout << "...finishing constructor\n";
	}

	DoubArray::DoubArray(const DoubArray &org_array) // copy constructor
	{
		m_length = org_array.m_length;
		m_array = new double[m_length];

		for (int i=0; i<m_length; i++)
			m_array[i]=org_array.m_array[i];
		//std::cout << "...finishing copy constructor\n";
	}

	DoubArray::~DoubArray() // destructor
	{
		// Dynamically delete the array we allocated earlier
		delete[] m_array ;
		//std::cout << "...finishing destructor\n";
	}

	//Function to calculate the p-norm of a vector
	//x is a pointer to the vector which is of size vecSize
	double DoubArray::PNorm(int p)
		{
		if (m_normflag)
		{
			return m_norm;
		}
		else
		{
			double sum = 0.0;
			//Loop over elems x_i of x, incrementing sum by |x_i|**p
			for (int i = 0; i < m_length; i++)
			{
				double temp = fabs(m_array[i]);
				sum += pow(temp, p);
			}
			m_norm = pow(sum, 1.0 / p);
			//set the flag to be true for future use 
			m_normflag = true;
			return m_norm;
		}
	}
	
	//Overload the - operator
	DoubArray DoubArray::operator- (const DoubArray& a1) const 
	{
		DoubArray temp(m_length);
		for (int i = 0; i < m_length; i++)
		{
			temp.m_array[i] = m_array[i] - a1.m_array[i];
			
		}
		return temp;
	}
	//Overload the = operator 
	DoubArray& DoubArray::operator= (const DoubArray& array)
	{
		m_normflag = false;
		for (int i = 0; i < m_length; i++)
		{
			m_array[i] = array.m_array[i];
			
		}
		return *this;
	}
	//Overload the [] operator for different scenarios
	double& DoubArray::operator[] (const int index) 
	{
		//Check if the index is valid 
		assert(index >=0 && index < m_length);
		return m_array[index];
	}

	const double& DoubArray::operator[] (const int index) const 
	{
		//Check if the index is valid 
		assert(index >=0 && index < m_length);
		return m_array[index];
	}

	//Function to set a value of a index 
	void DoubArray::setValue(int index, double value) 
	{
		m_array[index] = value;
		//Change the flag to false because the array has been changed
		m_normflag = false;
	}
	
	//***Question 2b)
	//Overloading the stream insertion << operator
	std::ostream& operator<< (std::ostream& output, const DoubArray& array)
	{
		for (int i =0; i < array.m_length;i++)
		{
			output<< array.m_array[i];
			if (i != array.m_length -1){
				output<< " ";
			}
			output<<"\n";
		}
		return output;
	}

