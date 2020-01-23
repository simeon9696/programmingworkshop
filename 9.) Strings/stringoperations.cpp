//String operations
#include <iostream>
#include <string> //must include this library to use STL strings

using std::cin;
using std::cout;
using std::endl;


int main(){

	std::string firstName = "James";
	std::string lastName = "Bond";

	// we can add strings together to create longer strings - string concatenation
	std::string fullName = firstName + " " + lastName;

	cout << "The name is " << lastName << ", " << fullName << endl;

	return 0;
}
