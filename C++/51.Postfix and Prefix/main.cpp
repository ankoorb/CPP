#include <iostream>
using namespace std;

int main() {

//    int u = 8;
//    ++u;  // Prefix increment operator
//    cout << "u: 8, ++u: " << u << endl;

    int v = 5;
    v++;  // Postfix increment operator
    cout << v << endl;

    // Difference between Prefix operator and Postfix operator
    // Prefix: Value will be incremented and used
    // Postfix: Value will be used and then incremented

    int w = 7;
    cout << "w: 7, w++: " << w++ << endl;


    // Check
    int value = 15;

    cout << value++ << endl; // Using value so prints: 15
    cout << value << endl;  // Value is now incremented

//    int number = value++;  // Post-fix
    int number = ++value;  // Pre-fix
    cout << "number is: " << number << endl;  // Using value so prints: 16
    cout << " value is: " << value << endl;  // Value is now incremented: 17

//    int u = 7;
//    cout << "++u: " << ++u << endl;
//    cout << "  u: " << u << endl;

    int u = 7;
    cout << "u++: " << u++ << endl;  // Use
    cout << "  u: " << u << endl;  // Increment



    return 0;
}