#include <iostream>
using namespace std;

int main() {

    int array[] = {2, 4, 6, 8};
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of array: " << sizeof(array) << endl;
    for(int i=0; i<sizeof(array)/sizeof(int); i++) {
        cout << array[i] << " " << flush;
    }

    // Sizeof - 2-D Array
    string animals[2][3] = {
            {"Kitten", "Puppy", "Cub"},
            {"Cat", "Dog", "Bear"}
    };
    cout << "\nSize of string: " << sizeof(string) << endl;
    cout << "Size of animals: " << sizeof(animals) << endl;
    cout << sizeof(animals[0]) << endl;
    for(int i=0; i<sizeof(animals)/sizeof(animals[0]); i++) {
        for(int j=0; j<sizeof(animals[0])/sizeof(string); j++) {
            cout << "\t" << animals[i][j] << " " << flush;
        }
        cout << endl;
    }

    return 0;
}