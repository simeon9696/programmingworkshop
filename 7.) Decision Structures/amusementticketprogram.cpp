// Amuzement Park Ticket program
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    short int age = 0;
    cout << "Enter your age: ";
    cin >> age;

    if (age < 13) {
        cout << "\nTicket price is $0";
    }
    else if (age >= 13 && age < 60) {
        cout << "\nTicket price is $50";
    }
    else {
        cout << "\nTicket price is $25";
    }

    return 0;
}