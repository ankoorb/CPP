#include <iostream>
using namespace std;

int main() {

    // 2-D Array: array[row][col]
    string animals[2][3] = {
            {"Fox", "Dog", "Cat"},
            {"Lion", "Wolf", "Tiger"}
    };

    for(int i=0; i<2; i++) {
        for(int j=0; j<3; j++) {
            cout << "\t" << animals[i][j] << " " << flush;
        }
        cout << endl;
    }

    // Multiplication table up to 10
    cout << "Multiplication Table (up to 10)" << endl;
    cout << "-------------------------------" << endl;
    int table[10][10] = {};

    // Populate the array using nested for loop
    for(int i=1; i<11; i++) {
        for(int j=1; j<11; j++) {
            table[i][j] = i * j;
            cout << "\t" << j << " x " << i << " = " << table[i][j] << " " << flush;
        }
        // Print new line after inner loop
        cout << endl;
    }

    // Size of array
    cout << sizeof(table) << endl;
    cout << sizeof(table)/sizeof(table[0][0]) << endl;

    cout << sizeof(animals) << endl;
    cout << sizeof(animals[0][0]) << endl;
    cout << "Number of elements in animal: " << sizeof(animals)/sizeof(animals[0][0]) << endl;

    return 0;
}