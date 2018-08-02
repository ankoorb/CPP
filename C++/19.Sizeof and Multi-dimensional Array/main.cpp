#include <iostream>
using namespace std;

int main() {

    string fruits[][3] = {
            {"Apple", "Banana", "Cherry"},
            {"Dragonfruit", "Eggfruit", "Fig"},
            {"Guava", "Honeydew", "Imbe"},
            {"Jackfruit", "Kiwi", "Lychee"},
            {"Mango", "Nectarine", "Orange"},
            {"Peach", "Quince", "Raspberry"},
            {"Strawberry", "Tangerine", "Ugni"}
    };

    cout << "Size of string: " << sizeof(string) << endl;
    cout << "Size of fruits array: " << sizeof(fruits) << endl;
    cout << "Size of a row in fruits array: " << sizeof(fruits[0]) << endl;
    cout << "Size of an element in fruits array: " << sizeof(fruits[0][0]) << endl;

    for(int i=0; i<sizeof(fruits)/sizeof(fruits[0]); i++) {
        for(int j=0; j<sizeof(fruits[0])/sizeof(string); j++) {
            cout << "\t" << fruits[i][j] << " " << flush;
        }
        cout << endl;
    }



    return 0;
}