// Quality Points Calculator program
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//Assuming all header files and using std::cout declared etc
int main() {
    char grade = ' ';
    int credits = 0;
    float points = 0.0;
    float qualityPts = 0.0;

    cout << "Enter student's grade(A, B, C, or F): ";
    cin >> grade;
    cout << "\nEnter course credits: ";
    cin >> credits;

    switch (grade) {
    case 'A':
        points = 4.0;
        break;
    case 'B':
        points = 3.0;
        break;
    case 'C':
        points = 2.0;
        break;
    case 'F':
        points = 0.0;
        break;
    default:
        cout << "\nInvalid grade entered" << endl;
    }

    qualityPts = credits * points;
    cout << "\nQuality Points for course = " << qualityPts << endl;

    return 0;
}