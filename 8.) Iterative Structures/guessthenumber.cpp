// Guess the Number program
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

    int guess = 0;
    //Executes the do loop before checking the while terminating condition
    do {
        cout << "Enter a value between 1 and 10" << endl;
        cin >> guess;

    } while (guess != 3);

    cout << "You Guessed IT!" << endl;

    return 0;
}
