#include <iostream>
#include <iomanip> // Input/Output manipulation (fixed or scientific, setting precision, etc.)
using namespace std;

int main() {

    float f_value = 123.456789;
    cout << f_value << endl;

    // Manipulate I/O using <iomanip>
    cout << "fixed : " << fixed << f_value << endl; // Print in fixed notation
    cout << "scientific: " << scientific << f_value << endl; // Print in scientific notation
    cout << "Size of float: " << sizeof(f_value) << endl;

    // Setting I/O precision using <iomanip>
    cout << "setpricision: " << setprecision(20) << f_value << endl;

    // More precision than float, i.e. more significant digits
    double d_value = 123.456789;
    cout << d_value << endl;
    cout << setprecision(20) << d_value << endl; // Note garbage at the end ...
    cout << "Size of double: " << sizeof(d_value) << endl;

    // More precision than double
    long double ld_value = 123.456789;
    cout << ld_value << endl;
    cout << setprecision(20) << ld_value << endl;
    cout << "Size of long double: " << sizeof(ld_value) << endl;




    return 0;
}