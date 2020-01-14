#include<iostream> //For Console I/O
#include<string>   //For the String DataType
#include<fstream>   //For file management


using namespace std;
const int NUMBER_OF_YEARS = 4;

    


//Extract the year port of the date format: DD/MM/YYYY
string getYear(string date){
    int stringLength = date.length();
    string year = "";                                   //Go programming practice to initialize your variables
    year = date.substr(stringLength-2,stringLength-1);  //Gets a substring of the input string (date) for the last four characters
    return year;                                        //Return Year
}

//This function calculates the Year Over Year KPI
//It takes two parameters yr1 and yr2 where yr2 > yr1
double YOY(double yr2, double yr1){
    double YOY = 0.00;
    double currentPeriodRevenue = yr2;
    double priorPeriodTevenue = yr1;
    YOY = ((currentPeriodRevenue - priorPeriodTevenue)/ priorPeriodTevenue ) * 100;
    return YOY;
}

//This function reads an excel sheet for the years and sales colomns
void readSpreadSheet(double sales[], string fileDirectory){
    ifstream inFile;

    double sales14 = 0;
    double sales15 = 0;
    double sales16 = 0;
    double sales17 = 0;


    string date = "";
    string sale = "";
    int lineNumber = 0;

    inFile.open(fileDirectory);

    if(inFile.is_open()){
        cout << "File has been opened" << endl;
    }


    while (!inFile.eof()){
        //Read Year and Corresponding Sale Amt
        //Iterate through the colomns to get to specific ones
        cout << "Row: " << lineNumber << " --->  ";
        std::getline( inFile, date, ',');
        std::getline( inFile, sale);

        if (lineNumber != 0){

         cout << date << ": $" << stod(sale) << endl; 
         string year = getYear(date);

         if(year == "14"){
            sales14 += stod(sale);
         }
         else if(year == "15"){
            sales15 += stod(sale);
         }
         else if(year == "16"){
            sales16 += stod(sale);
         }
         else if(year == "17"){
            sales17 += stod(sale);
         }
        }
       
        
        lineNumber++;
    }

    inFile.close();
    // cout << "sale[0] = " << sales14 << endl;
    // cout << "sale[1] = " << sales15 << endl;
    // cout << "sale[2] = " << sales16 << endl;
    // cout << "sale[3] = " << sales17 << endl;

    sales[0] =  sales14;
    sales[1] =  sales15;
    sales[2] =  sales16;
    sales[3] =  sales17;



    return; //Return Void
}

//Utility function to print arrays
void printArray(double arr [], int arrSize){
    for (int i = 0; i<arrSize;i++){
        cout << arr[i] << endl;
    }
}



int main(){
    double sales[NUMBER_OF_YEARS] = {0,0,0,0};
    readSpreadSheet(sales,"Sample - Superstore.csv");
    //printArray(sales, NUMBER_OF_YEARS);

    
    //sales[0] == 2014
    //sales[1] == 2015
    //sales[2] == 2016
    //sales[3] == 2017

    // cout << getYear("01/12/2020") << endl; //Test with literal value
    // cout << YOY(1000.00,500.00) << endl;
    cout << "Year Over Year Growth: " << endl;
    cout << YOY(sales[1],sales[0]) << "%" << endl;
    cout << YOY(sales[2],sales[1]) << "%" << endl;
    cout << YOY(sales[3],sales[2]) << "%" << endl;

    cout << "Done" << endl;
    return 0;
}
