//2D Arrays
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

    //Declaration
    float monthTempValues[4][7]; // an array of 4 one-dimension arrays of type float

    //Declaration and Initialization
    // all array sizes must be specified with the exception of the first one
    int timesTables[][12] = { {1,2,3,4,5,6,7,8,9,10,11,12}, {2,4,6,8,10,12,14,16,18,20,22,24}, {3,6,9,12,15,18,21,24,27,30,33,36} };

    // output each array element's value 
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cout << "Element at timesTables[" << i
                << "][" << j << "]: ";
            cout << timesTables[i][j] << endl;
        }
    }
                             
    return 0;
}