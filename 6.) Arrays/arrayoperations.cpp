//Operations on Arrays
#include <iostream> 
#include <array> //C++11 arrays
using std::cin;
using std::cout;
using std::endl;

int main() {

    int evenVal[] = { 2,4,8,10,12 };
    char vowels[] = { 'a','e','i','o','u' };

    cout << "The fourth element in  evenVal array is: " << evenVal[3] << endl;

    // updating a value in an array
    evenVal[4] = evenVal[4] * 2;
    cout << "The fifth value in evenVal array is now: " << evenVal[4] << endl;
    evenVal[4] *= 2;
    cout << "The fifth value in evenVal array is now: " << evenVal[4] << endl;

    //Printing every value in vowels array
    cout << vowels[0] << " ";
    cout << vowels[1] << " ";
    cout << vowels[2] << " ";
    cout << vowels[3] << " ";
    cout << vowels[4] << "\n";

    //Init arrays using a for loop
    const int arrayLength = 5; //must be const, arrays are fixed length
    int arr[arrayLength];
    for (int i = 0; i < arrayLength; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < arrayLength; i++)
    {
        cout << arr[i] << " ";
    }


    //C++11 arrays
    cout << "\nC++11 arrays" << endl;
    std::array<int, 5> myarray;
    for (unsigned int i = 0; i < myarray.size(); i++)
    {
        myarray[i] = i;
    }

    for (unsigned i = 0; i < myarray.size(); i++)
    {
        cout << myarray[i] << " ";
    }
    return 0;
}