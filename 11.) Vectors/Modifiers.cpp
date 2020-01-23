#include <iostream> 
#include <vector> 

using std::cout;

void assign() {

	// Assign vector 
	std::vector<int> v;

	// fill the array with 10 five times 
	v.assign(5, 10);

	cout << "The vector elements are: ";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}
void fill_vector() {
	std::vector<int> v;
	for (int i = 1; i <= 5; i++)
		v.push_back(i);
}

void remove_last() {
	std::vector<int> v;
	for (int i = 1; i <= 5; i++)
		v.push_back(i);

	// removes last element 
	v.pop_back();

	// prints the vector 
	cout << "\nThe vector elements are: ";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}

void insert() {

	std::vector<int> v;
	for (int i = 1; i <= 5; i++)
		v.push_back(i);
	// inserts 5 at the beginning 
	v.insert(v.begin(), 5);

	cout << "\nThe first element is: " << v[0];
}

void remove() {

	std::vector<int> v;
	for (int i = 1; i <= 5; i++)
		v.push_back(i);
	// removes the first element 
	v.erase(v.begin());

	cout << "\nThe first element is: " << v[0];

}

void swap() {
// two vector to perform swap 
std::vector<int> v1, v2;
v1.push_back(1);
v1.push_back(2);
v2.push_back(3);
v2.push_back(4);

cout << "\n\nVector 1: ";
for (int i = 0; i < v1.size(); i++)
	cout << v1[i] << " ";

cout << "\nVector 2: ";
for (int i = 0; i < v2.size(); i++)
	cout << v2[i] << " ";

// Swaps v1 and v2 
v1.swap(v2);

cout << "\nAfter Swap \nVector 1: ";
for (int i = 0; i < v1.size(); i++)
	cout << v1[i] << " ";

cout << "\nVector 2: ";
for (int i = 0; i < v2.size(); i++)
	cout << v2[i] << " ";
}