#include <iostream>
using namespace std;

int main() {

    // Array of ints
    int values[3]; // Declaring an array
    values[0] = 3;
    values[1] = 6;
    values[2] = 9;

    cout << "Array of Integers" << endl;
    cout << "-----------------" << endl;
    cout << values[0] << endl;
    cout << values[1] << endl;
    cout << values[2] << endl;

    // Array of doubles: Declare and initialize array
    double dvalues[2] = {3.14, 5.5};

    cout << endl << "Array of Doubles" << endl;
    cout << "-----------------" << endl;
    cout << dvalues[0] << endl;
    cout << dvalues[1] << endl;

    // Array of strings: Declare and initialize array
    string svalues[3] = {"Apple", "Banana", "Citrus"};
    cout << endl << "Array of Strings" << endl;
    cout << "-----------------" << endl;
    for(int i=0; i<3; i++) {
        cout << "Element at index "<< i << ": " << svalues[i] << endl;
    }

    // Initialize an array with zero values
    int zero_array[5] = {};
    cout << endl << "Array of Zeros" << endl;
    cout << "-----------------" << endl;
    for(int i=0; i<5; i++) {
        zero_array[i] = 0;
        cout << "Element at index "<< i << ": " << zero_array[i] << endl;
    }

    // NOTE: C++ will not stop you accessing elements that do not exist.
    cout << endl << "Accessing elements that do not exist (BAD IDEA)" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << svalues[10] << endl;
    cout << "Garbage: " << values[5] << endl;

    // Table of 12
    int table[10] = {};
    cout << endl << "Multiplication table of 12" << endl;
    cout << "---------------------------" << endl;
    for(int i=1; i<11; i++) {
        table[i] = i * 12;
        cout << "12 x "<< i << " = " << table[i] << endl;
    }

    cout << "One line For Loop" << endl;
    for(int i=0; i<5; i++) {cout << 2 * i << endl;}

    return 0;
}