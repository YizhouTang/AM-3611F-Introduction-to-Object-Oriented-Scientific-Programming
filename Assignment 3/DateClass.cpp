#include <iostream>
#include <cassert>

class DateClass // members are private by default
{
private:
	int m_month;
	int m_day; 
	int m_year; 

public:
	//Constructor with parameters
	DateClass(int month = 1, int day = 1, int year = 2018)
	{
		assert(setDate(month,day,year));
		setDate(month,day,year);
	}

	bool setDate(int month, int day, int year) // public, accessible to anyone
	{
		//Check if the day is appropriate for the month given
		bool succesful = true;
		m_month = month;
		m_day = day;
		m_year = year;
		if ((month < 1) || (month >12))
		{
			std::cout << "Month out of range.\n";
			succesful = false;
		}
		switch(m_month)
		{
			//Months with 31 days
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if ((m_month < 1) || (m_month >31))
				{
					std::cout << "Date out of range. \n";
					succesful = false;
				}
				break;
			//months with 30 days
			case 4:
			case 6:
			case 9:
			case 11:
				if ((m_month < 1) || (m_month >30))
				{
					std::cout << "Date out of range. \n";
					succesful = false;
				}
				break;
			//Feburary special case 
			case 2:
				if (m_year % 4 == 0)
				{
					if ((m_month < 1) || (m_month >29))
					{
						std::cout << "Date out of range. \n";
						succesful = false;
					}
				}
				else 
				{
					if ((m_month < 1) || (m_month >28))
					{
						std::cout << "Date out of range. \n";
						succesful = false;
					}
				}
				break;
		}
		if ((m_year < -5000) || (m_year > 2500))
		{
			std::cout << "Year out of range.\n";
			succesful = false;
		}
		//Return if the method has succesfully set the appropriate date 
		return (succesful);
		}

	void print() // public, can be accessed by anyone
	{
		std::cout << m_month << "/" << m_day << "/" << m_year;
	}
};

int main()
{
	DateClass date;
	if (date.setDate(10, 14, 2020))
	{
		std::cout << "The date was set succesfully.\n";
	}
	else
	{
		std::cout << "The date was not set succesfully.\n";
	}
	
	date.print(); // okay, because print() is public
	std::cout << std::endl;
	
	std::cout<<"Direct Initialization Result:\n";
	DateClass directDate(10,14,2020);
	directDate.print();
	std::cout << std::endl;
	
	std::cout << "Uniform Initialization Result:\n";
	DateClass uniformDate{10,14,2020};
	uniformDate.print();
	std::cout << std::endl;
	
	std::cout <<"Implicit Copy Constructor:\n";
	DateClass copyDate(date);
	copyDate.print();
	
	std::cout << std::endl;

	return 0;
}
