#include <iostream>
#include <cassert>

class DateClass // members are private by default
{
  int m_month; // private by default, only accessible to other members
  int m_day; // private by default, only accessible to other members
  int m_year; // private by default, only accessible to other members

public:
  void setDate(int month, int day, int year) // public, accessible to anyone
  {
    // setDate() can access the private members of the class because 
    // it is a member of the class itself
    assert((month>=1) && (month <=12));
    m_month = month;
    assert((day>=1) && (day<=31));
    m_day = day;
    m_year = year;
  }

  void print() // public, can be accessed by anyone
  {
    std::cout << m_month << "/" << m_day << "/" << m_year;
  }
};

int main()
{
  DateClass date;
  date.setDate(10, 14, 2020); // okay, because setDate() is public

  date.print(); // okay, because print() is public
  std::cout << std::endl;

  return 0;
}
