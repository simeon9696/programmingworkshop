// 3 Times Tables program
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

    cout << "\t Three Times Tables" << endl;
    cout << "\t ------------------" << endl;
    for (int count = 0; count <= 12; count++) {
        cout << "\t 3 x " << count << " = " << 3 * count << endl;
    }

    return 0;
}