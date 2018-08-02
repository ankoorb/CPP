#include <iostream>

using namespace std;

int main() {

    int value = 9876543210; // Prints wrong value because value is too big
    cout << value << endl;

    cout << "Maximum int value: " << INT_MAX << endl;
    cout << "Minimum int value: " << INT_MIN << endl;

    long int l_value = 9876543210; // Prints correct value
    cout << l_value << endl;

    short int s_value = 1e-10;
    cout << s_value << endl;
    s_value = 100;


    // sizeof(<variable>) finds out how much memory different types of variables use. 1 byte = 8 bits.
    cout << "Size of int: " << sizeof(value) << " bytes" << endl; // Bytes
    cout << "Size of long int: " << sizeof(l_value) << " bytes" << endl; // Bytes
    cout << "Size of short int: " << sizeof(s_value) << " bytes" << endl; // Bytes

    unsigned int u_value = 123456789;
    cout << u_value << endl;
    cout << "Size of unsigned int: " << sizeof(u_value) << " bytes" << endl; // Bytes

    unsigned int neg = -12345;
    cout << neg << endl; // Prints wrong value because unsigned int only stores positive values

    return 0;
}

// Google search "limits.h" to find out about INT_MAX, INT_MIN, and others.