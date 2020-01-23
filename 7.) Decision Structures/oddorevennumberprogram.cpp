// Odd or Even Number program
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int num = 0;
    cout << "Enter a number between 0 & 1000: ";
    cin >> num;

    if (num % 2 == 0) {
        cout << "\nNumber is even";
    }
    else {
        cout << "\nNumber is odd";
    }

    return 0;
}