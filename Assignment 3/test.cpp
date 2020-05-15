#include <iostream>
#include <cmath>
void DoSomething(double* u, double** A);
int main(int argc, char* argv[])
{
 double* u = new double [10];
 double** A = new double* [10];
 A[0] = new double [10*10];
 for (int i=1; i<10; i++)
 {
 A[i] = A[i-1]+10;
 }
 DoSomething(u, A);
 // This will print the values allocated in
 // the function DoSomething
 std::cout << u[2] << "\n";
 std::cout << A[2][3] << "\n";
 delete[] u;
 delete[] A[0];
 delete[] A;
 return 0;
}
void DoSomething(double* u, double** A)
{
 u[2] = 1.0;
 A[2][3] = 4.0;
}