// Odd or Even program
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int num = 0;
    cout << "Enter a number between 0 & 1000: ";
    cin >> num;

    if(num%2 == 0){
        cout << "\n Number is even";
    }else{
        cout << "\n Number is odd";
    }

    return 0;
}

// Ticket program
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    short int age = 0;
    cout << "Enter you age: ";
    cin >> age;

    if(age < 13){
        cout << "\n Ticket price is $0";
    }else if(age>=13 && age <60){
    cout << "\n Ticket price is $50";
    }else{
        cout << "\n Ticket price is $25";
    }

    return 0;
}

// Quality Points program
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main(){
    char grade = ' ';
    int credits = 0;
    float points = 0.0;
    float qualityPts = 0.0;

    cout << "Enter student's grade(A, B, C, or F): ";
    cin >> grade;
    cout << "\nEnter course credits: ";
    cin >> credits;

    switch (grade){
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
            cout << "\nInvalid value entered" << endl;
    }

    qualityPts = credits * points;
    cout << "\nQuality Points for course = " << qualityPts << endl;

    return 0;
}

//Upgraded switch case
// Odd or Even program
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int num = 0;
    cout << "Enter a number between 0 & 1000: ";
    cin >> num;

    if(num%2 == 0){
        cout << "\n Number is even";
    }else{
        cout << "\n Number is odd";
    }

    return 0;
}

// Ticket program
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    short int age = 0;
    cout << "Enter you age: ";
    cin >> age;

    if(age < 13){
        cout << "\n Ticket price is $0";
    }else if(age>=13 && age <60){
    cout << "\n Ticket price is $50";
    }else{
        cout << "\n Ticket price is $25";
    }

    return 0;
}

// Quality Points program
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main(){
    char grade = ' ';
    int credits = 0;
    float points = 0.0;
    float qualityPts = 0.0;

    cout << "Enter student's grade(A, B, C, or F): ";
    cin >> grade;
    cout << "\nEnter course credits: ";
    cin >> credits;

    switch (grade){
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
            cout << "\nInvalid value entered" << endl;
    }

    qualityPts = credits * points;
    cout << "\nQuality Points for course = " << qualityPts << endl;

    return 0;
}

// 3 Times Tables program
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main(){

    cout << "\t Three Times Tables" << endl;
    cout << "\t ------------------" << endl;
    for (int count =0; count<=12; count++ ){
        cout << "\t 3 x " << count << " = "<< 3 * count << endl;
    }

    return 0;
}

// Average program
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main(){

    int count =0;
    int value = 0;
    int total = 0;
    float average = 0.0;

    cout << "Enter any value or 9999 to STOP:"<<endl;
    cin >> value;

    while (value != 9999){
        count++;
        total += value;
        cout << "Enter any value or 9999 to STOP:"<< endl;
        cin >> value;
    }

    average = (float)total/count;

    if (count > 0){
        cout << "Average of the " << count << " values =  "<< average << endl;
    }

    return 0;
}

// Average program
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main(){

    int guess = 0;

    do{
        cout << "Enter a value between 1 and 10" << endl;
        cin >> guess;

    }while(guess!=3);

    cout << "You Guessed IT!" << endl;

    return 0;
}

//



// 3 Times Tables program
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main(){

    cout << "\t Three Times Tables" << endl;
    cout << "\t ------------------" << endl;
    for (int count =0; count<=12; count++ ){
        cout << "\t 3 x " << count << " = "<< 3 * count << endl;
    }

    return 0;
}

// Average program
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main(){

    int count =0;
    int value = 0;
    int total = 0;
    float average = 0.0;

    cout << "Enter any value or 9999 to STOP:"<<endl;
    cin >> value;

    while (value != 9999){
        count++;
        total += value;
        cout << "Enter any value or 9999 to STOP:"<< endl;
        cin >> value;
    }

    average = (float)total/count;

    if (count > 0){
        cout << "Average of the " << count << " values =  "<< average << endl;
    }

    return 0;
}

// Average program
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main(){

    int guess = 0;

    do{
        cout << "Enter a value between 1 and 10" << endl;
        cin >> guess;

    }while(guess!=3);

    cout << "You Guessed IT!" << endl;

    return 0;
}

//

for(index=0;index<)

