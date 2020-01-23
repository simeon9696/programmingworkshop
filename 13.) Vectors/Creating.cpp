#include <iostream>
#include <string>
#include <vector>


///////////////////////////////////////////////////////////
	void init_zero() {

		// Creates a vector with all values initialize as zero.
		// Vector with 5 integers
		// Default value of integers will be 0.
		std::vector < int > vec_of_ints(5);
		for (int x : vec_of_ints)
			std::cout << x << std::endl;
	}
////////////////////////////////////////////////////////////

	// The old fashion way like Arrays 
	void byHand() {
		std::vector < int > vec_of_numbers(8);
		vec_of_numbers = { 1, 2, 3, 4, 5 };
		for (int y : vec_of_numbers)
			std::cout << y << std::endl;

	}
////////////////////////////////////////////////////////////	
	//Using an Array to fill vectors 

	 // Array of string objects
	void by_array() {
		std::string arr[] = {
			"first",
			"sec",
			"third",
			"fourth"
		};

		// Vector with a string array
		std::vector < std::string > vec_of_str(arr,arr +sizeof(arr) / sizeof(std::string));
		for (std::string str : vec_of_str)
			std::cout << str << std::endl;

	}
///////////////////////////////////////////////////////////

