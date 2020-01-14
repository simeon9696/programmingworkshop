#include <iostream>
using namespace std;

int main(){


    int      a;//Integer
    char     b;//Character
    bool     c;//Boolean
    float    d;//Floating Point
    double   e;//Double Floating Point
    //void      ;//Void
    wchar_t  f;//Wide Character    


    std::cout << "Int  = " << sizeof(int) << " byte(s)" << std::endl;
    std::cout << "Char  = " << sizeof(char) << " byte(s)" << std::endl;
    std::cout << "Float  = " << sizeof(float) << " byte(s)" << std::endl;
    std::cout << "Double  = " << sizeof(double) << " byte(s)" << std::endl;
    std::cout << "Void  = " << "0" << " byte(s)" << std::endl;
    std::cout << "Wide Character  = " << sizeof(double) << " byte(s)" << std::endl;
    


    return 0;
}