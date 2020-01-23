/*
    Author: Simeon Ramjit
    Date: 14-01-2020
    File Summary:   kpis.cpp contains the main function, there are no other project files involved.
                    This program will extract the following Key Performance Indicators
                        -Highest profit margin and the details (Product ID, Category, Sub-Category, Product Name and Sales amount)
                        //Challenge for you
                            - Find the most popular customer in an area
                            - Most popular customer and their information (Customer ID, Customer Name, City, State and Postal Code)
                            - Most popular area of sales
   
   This is not meant to be the most efficent or best solution to the problem, there are multiple areas to improve on 
   and you should explore them.S
*/

//adding libraries. Libraries are always included at the top of file
#include <iostream>     //Allows us to stream information in and out of the console
#include <fstream>      //Allows us to stream information in and out of files
#include <string>       //Allows us to use strings
#include <vector>       //Allows the use of vectors
#include <sstream>      //To convert data from strings to other data types
#include <algorithm>    //To use the *max_element function https://en.cppreference.com/w/cpp/algorithm
#include <chrono>       //To use timing features https://www.geeksforgeeks.org/measure-execution-time-function-cpp/

/*  
    Use only select parts of namespace std
    See more information here:
    https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice 
*/
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;
using std::stringstream;
using namespace std::chrono; 


int indexOfLargestElement(vector<float>&); //Function declaration. The definition is after int main(){} (scroll straight to end)

int main()
{
    //Store name of file to be processed
    string filename = "superstore.csv";
    //Print welcome message
    cout << "====================================Welcome to the KPI Extractor for " << filename << "====================================\n"<<endl;
    cout << "It will extract the following information: \n";
    cout << "\t-Highest profit margin and the details (Product ID, Category, Sub-Category, Product Name and Sales amount) \n"
         << endl;

    //Check if file is available for processing
    //Why use strings and not char below? 
    //What happens if we use char and enter 2 characters instead with the first char being accepted?
    string acceptedAnsOne = "y";
    string acceptedAnsTwo = "Y";
    string userDecision = " ";
    string checkValidityMessage = "\nProceeding to check file validity...";
    cout << "\nIs the file in the project directory"
         << " and has the name " << filename << "? Y/N: ";
    cin >> userDecision;
    if (userDecision == acceptedAnsOne || userDecision == acceptedAnsTwo) {
        cout << checkValidityMessage << endl;
    }
    else {
        while (userDecision != acceptedAnsOne && userDecision != acceptedAnsTwo) { //Make sure to understand this logic
            cout << "Place file in project directory and press Y + Enter when complete: ";
            cin >> userDecision;

            if (userDecision == acceptedAnsOne || userDecision == acceptedAnsTwo) {
                cout << checkValidityMessage << endl;
                break; //User confirmed file is present in directory so end while loop
            }
        }
    }

    //We need to declare vectors to hold our data. Our file had 21 columns, so 21 vectors. 
    //Because they can be dynamically sized, we don't have to include a size just yet
    //We do it outside of the 'file handler' so we'll be able to access the vectors after
    //the file is closed

    vector<int>     rowId;          //Column 1
    vector<string>  orderId;        //Column 2
    vector<string>  orderDate;      //Column 3
    vector<string>  shipDate;       //Column 4
    vector<string>  shipMode;       //Column 5
    vector<string>  customerID;     //Column 6    
    vector<string>  customerName;   //Column 7
    vector<string>  segment;        //Column 8
    vector<string>  country;        //Column 9
    vector<string>  city;           //Column 10
    vector<string>  state;          //Column 11
    vector<string>  postalCode;     //Column 12
    vector<string>  region;         //Column 13
    vector<string>  productId;      //Column 14
    vector<string>  category;       //Column 15
    vector<string>  subCategory;    //Column 16
    vector<string>  productName;    //Column 17
    vector<float>   sales;          //Column 18
    vector<int>     quantity;       //Column 19
    vector<float>   discount;       //Column 20
    vector<float>   profit;         //Column 21

    //Attempt to open file
    ifstream dataset; //Declare input file stream
    unsigned int rowCount = 0; //Number of rows could never be negative, let's use the available space (remember how unsigned nums are represented in mem?)

    // Use auto keyword to avoid typing long 
    // type definitions. To get the timepoint 
    // at this instant use function now().

    // To be used at start of while loop that parses file. Declared and initialized right away so that auto infers the appropriate variable type.
    auto start = high_resolution_clock::now(); 

    //To be used at end of while loop that parses file. Declared and initialized right away so that auto infers the appropriate variable type.
    auto stop = high_resolution_clock::now(); 
                               
    dataset.open(filename);
    if (!dataset) {
        cout << "\nUh-oh, seems like we can't find the file. Recheck directory" << endl;
        return 0; //End program execution
    }
    else {
        cout << "\nFile found. Extracting KPIs now..." << endl;
        //Let's get the line count in the file
        string t = "";
        while (getline(dataset, t)) { //In a CSV file, each row is delimited by \n which is default for getline(...)
            rowCount++;
        }
        //Display number of rows, should match the excel file
        //In this case we intend to use all of the data in the excel file. So after extracting the data, the size of any vector
        //should match the number of rows in the excel file.

        rowCount = rowCount - 1; //To account for column headings
        cout << "Number of data rows (total number of rows - row with headings) is: " << rowCount << endl; 
        

        //Since we used getline() to get the number of lines in the files, the stream position is at the end of the file.
        //In order to continue processing the data in the file, we need to reset the position to the start of the file.

        dataset.clear(); //Clear .eof bit
        dataset.seekg(0); //Reset stream position to start to file

        //Now we read in each row again, except for the first one
        //That entire string will consist of comma separated values
        //We can use stringstream to place the whole row into a stream 
        //which can then be used with getline again to get the value
        //in between comma's. In order to skip the column headings,
        //we can just call getline() once and then enter the while loop

         cout << "Attempting to read dataset, parse data and create vectors. This can take some time..." << endl;
         start = high_resolution_clock::now(); //Get timepoint of when file parsing begins
         getline(dataset, t); //Now the file stream position is on the second row
         while (getline(dataset, t)) { //In a CSV file, each row is delimited by \n which is default for getline(...)
            stringstream ss(t);        
            string parsed = "";
            int vectorIndex = 0;
            while (getline(ss, parsed, ',')) {  
                stringstream commaSepValStream(parsed);
                int id = 0;
                int quantityCount = 0;
                float salesAmt = 0.0; //Remember to always initialize floats with the decimal point
                float discountAmt = 0.0;
                float profitMargin = 0.0;
                switch (vectorIndex) {
                    case 0:
                        commaSepValStream >> id;
                        rowId.push_back(id);
                        break;
                    case 1:
                        orderId.push_back(parsed);
                        break;
                    case 2:
                        orderDate.push_back(parsed);
                        break;
                    case 3:
                        shipDate.push_back(parsed);
                        break;
                    case 4:
                        shipMode.push_back(parsed);
                        break;
                    case 5:
                        customerID.push_back(parsed);
                        break;
                    case 6:
                        customerName.push_back(parsed);
                        break;
                    case 7:
                        segment.push_back(parsed);
                        break;
                    case 8:
                        country.push_back(parsed);
                        break;
                    case 9:
                        city.push_back(parsed);
                        break;
                    case 10:
                        state.push_back(parsed);
                        break;
                    case 11:
                        postalCode.push_back(parsed);
                        break;
                    case 12:
                        region.push_back(parsed);
                        break;
                    case 13:
                        productId.push_back(parsed);
                        break;
                    case 14:
                        category.push_back(parsed);
                        break;
                    case 15:
                        subCategory.push_back(parsed);
                        break;
                    case 16:
                        productName.push_back(parsed);
                        break;
                    case 17:
                        commaSepValStream >> salesAmt;
                        sales.push_back(salesAmt);
                        break;
                    case 18:
                        commaSepValStream >> quantityCount;
                        quantity.push_back(quantityCount);
                        break;
                    case 19:
                        commaSepValStream >> discountAmt;
                        discount.push_back(discountAmt);
                        break;
                    case 20:
                        commaSepValStream >> profitMargin;
                        profit.push_back(profitMargin);
                        break;
                    default:
                        ; //Do nothing at all in the default statement
                }//Switch case statement
                vectorIndex = vectorIndex + 1;
            }//While loop for vector index
        }//While loop to set up vectors
        stop = high_resolution_clock::now(); //Get timepoint of when file parsing ends
    }// File if-else-open
    
    dataset.close(); //Close file as soon as we're done with it.

    // Subtract stop and start timepoints and cast it to required unit. Predefined units are nanoseconds, microseconds, milliseconds, 
    // seconds, minutes, hours. Use duration_cast() function. 
    auto duration = duration_cast<microseconds>(stop - start);

    //Let's see if all the rows were read in
    const int expectedColumnCount = rowCount; //Not necessary, just for demonstration of const, could have compared to rowCount instead
    if (rowId.size() == expectedColumnCount) //
        cout << "\nAll rows successfully read in! All vectors successfully created in "
        << duration.count() / 1000000.0 //Remember to add .0 to denote that you want a floating number output
        <<"s"
        << endl;  //Note how long lines can be broken up

    ////Uncomment this block to print the first three columns just for visualization
    //for (unsigned int i = 0; i < rowId.size(); i++) {
    //    cout << rowId[i] << "\t" <<
    //            orderId[i] << "\t" <<
    //            orderDate[i] << "\t" << endl;
    //}

    /*----------------------------------------------------Finding the maximum profit-------------------------------------------------------------*/
    /*
        As per our KPIs, we're gonna attempt to find the largest profit i.e. the largest value in the 'profit' vector. Let's use a function
        that takes in a the address of a vector of type float (pass by reference) for speed and returns the index of the largest element in it.

    */
        int largestElemPosition = indexOfLargestElement(profit); //Get largest element in vector 'profit'
        if (largestElemPosition == -1) {
            cout << "Cannot find maximum value in an empty vector" << endl;
        }
        else {
            cout << "\n=============================================Maximum Profit Margin Found=============================================" << endl;
            cout << "Product ID \tProduct Name \t\t\t\tCategory \tSub-Category  \tSales Amount \tProfit Margin" << endl;
            cout << productId[largestElemPosition]
                << "\t" << productName[largestElemPosition]
                << "\t" << category[largestElemPosition]
                << "\t" << subCategory[largestElemPosition]
                << "\t\t" << sales[largestElemPosition]
                << "\t\t" << profit[largestElemPosition]
                << endl;
        }

    return 0; //End of program. Notice the absence of blocking code e.g. getchar() or SYSTEM("PAUSE").
}


int indexOfLargestElement(vector<float>& vect)
{
    int largestElementPosition = 0;
    const int emptyVector = -1;
    //Check if vector is empty
    if (vect.empty()) { 
        largestElementPosition = emptyVector; //Some value that should not be possible under normal conditions
    }
    else { //if it's not empty...
        /*
        To find a largest or maximum element of a vector, we can use *max_element() function which is defined in <algorithm> header.
        It accepts a range of iterators from which we have to find the maximum / largest element and returns the iterator pointing
        the maximum element between the given range.Note: T use *max_element() function – include <algorithm> header
        or we can simply use <bits/stdc++.h> header file.
        */

        float max = *max_element(vect.begin(), vect.end()); //This returns the maximum value in a vector
        //vector<float>::iterator it = std::find(tempVect.begin(), tempVect.end(), max);
        //Or we can use auto
        auto it = std::find(vect.begin(), vect.end(), max); //This returns an iterator for the position of the element 'max' in the vector
        largestElementPosition = std::distance(vect.begin(), it); //This gives the actual index of the element in the vector
    }
    
    return largestElementPosition; //Function was defined as type int, therefore we have to return an int
}