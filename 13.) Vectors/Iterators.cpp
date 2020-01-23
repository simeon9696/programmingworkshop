// C++ program to illustrate the 
// iterators in vector 
#include <iostream> 
#include <vector> 

using std::cout;

// Using begin and end
void begin_end()
{
	std::vector <int> g1;
	for (int i = 1; i <= 5; i++)
		g1.push_back(i);

	cout << "Output of begin and end: ";
	for (auto i = g1.begin(); i != g1.end(); ++i)
		cout << *i << " ";
}

// Using cbegin and cend
void cbegin_cend() {

	std::vector <int> g1;
	for (int i = 1; i <= 5; i++)
		g1.push_back(i);

	cout << "\nOutput of cbegin and cend: ";
	for (auto i = g1.cbegin(); i != g1.cend(); ++i)
		cout << *i << " ";
}

int main() {

}