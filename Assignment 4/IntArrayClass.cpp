#include <iostream>
#include <cassert>

class IntArray
{
private:
  int *m_array;
  int m_length;

public:
  IntArray(int length) // constructor
  {
    assert(length > 0);

    m_array = new int[length];
    m_length = length;
    //std::cout << "...finishing constructor\n";
  }

  IntArray(const IntArray &org_array) // copy constructor
  {
    m_length = org_array.m_length;

    m_array = new int[m_length];

    for (int i=0; i<m_length; i++)
      m_array[i]=org_array.m_array[i];

    //std::cout << "...finishing copy constructor\n";
  }


  ~IntArray() // destructor
  {
    // Dynamically delete the array we allocated earlier
    delete[] m_array ;
    //std::cout << "...finishing destructor\n";
  }

  void setValue(int index, int value) { m_array[index] = value; }
  int& getValue(int index) { return m_array[index]; }

  int getLength() { return m_length; }
};

int main()
{
  IntArray ar(10); // allocate 10 integer "array" via constructor

  for (int count=0; count < 10; ++count)
    ar.setValue(count, count+1);

  std::cout << "The value of element 5 is: " << ar.getValue(5) << std::endl;

  IntArray br(ar);

  std::cout << "The value of element 5 is: " << br.getValue(5) << std::endl;

  return 0;
} // ar and br go out of scope and are destroyed here, 
  // so ~IntArray() destructor function is called here
