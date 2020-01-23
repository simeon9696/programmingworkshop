// Average program
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

    //Assuming all header files and using std::cout declared etc.
    int count = 0;
    int value = 0;
    int total = 0;
    float average = 0.0; //Init float or double with decimal point 

    cout << "Enter any value or 9999 to STOP:" << endl;
    cin >> value;

    while (value != 9999) {
        count++;
        total += value;
        cout << "Enter any value or 9999 to STOP:" << endl;
        cin >> value;
    }

    average = (float)total / count;

    if (count > 0) {
        cout << "Average of the " << count << " values =  " << average << endl;
    }

    return 0;
}