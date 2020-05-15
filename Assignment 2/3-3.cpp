
//3.3
//The code above shows a way of using while loop and command line argument solving x and y for a specific differential equation via Implicit Eular method, which is "dy/dx = -y", and then save the data into a file named "XY.dat"
#include <fstream>
#include <iostream>
#include <cassert>
#include <cstdlib>
int main(int argc, const char * argv[]){

    std::ofstream print_output("XY.dat");
    assert(print_output.is_open());
    
    std::cout << "Number of command line arguments = "<< argc << "\n";
    for (int i=0; i <argc; i++)
    {
        std::cout << "Argument " << i << " = " << argv[i];
        std::cout << "\n";
    }
    std::string program_name = argv[0];
    int number_of_points = atoi(argv[1]);
    assert(number_of_points > 1);
    
    std::cout << "Program name = " << program_name << "\n";
    std::cout << "Number of nodes = " << number_of_points<< "\n";
    
    std::cout << "Using the implicit Euler's method to calculate x and y\n";
    std::cout << "Xi          " << "             Yi" << "\n";
    
    double h = 1/(double)number_of_points;
    double x = 0.0, y = 1.0;
    int row_numbers = 0;
    while(x < 1){
        std::cout << x << "           " << "            " << y << "\n";
        print_output << x <<"                    "<< y << "\n";
        print_output<<"\n";
        x += h;
        y = y/(1+h);
        row_numbers++;
    }
    std::cout<< "row numbers = "<< row_numbers << "\n";
    
    
    
    
    
//4.2
//The code below illustrates the way of allocating data. Part A shows how to calculating the numbers of lines, part B shows not only printing the line number, but also dynamically allocated array.
    
    std::ifstream read_file("XY.dat");
    assert(read_file.is_open());

    double dummy_x, dummy_y;
    int i = 0;

    while (!read_file.eof())
    {
        read_file >> dummy_x >>dummy_y;
        i++;
    }
    
    std::cout<<"The number of line use dummy is: "<<i-1<<"\n";
    
    read_file.seekg(std::ios::beg);
    double *x1, *y1;
    x1 = new double [i-1];
    y1 = new double [i-1];
    
    int j= 0;
    while (j<i)
    {
        read_file >> x1[i] >> y1[i];
        //std::cout << x[i] <<"   "<< y[i] << "\n";
        j++;
    }
    std::cout<<"The number of line use array is: "<<j-1<<"\n";

    delete[] x1;
    delete[] y1;
    
    return 0;
}
