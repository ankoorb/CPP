#include <iostream>
#include <vector>
using namespace std;

int main() {

    int value{7};
    cout << value << endl;

    string text{"Hello"};
    cout << text << endl;

    int numbers[]{1, 3, 7};
    cout << numbers[1] << endl;

    int *pInt = new int[3]{2, 4, 8}; // value in [] is required else error
    cout << pInt[1] << endl;
    delete pInt;

    // Initializing default values using empty {}
    int u{};
    cout << "u: " << u << endl;

    string s{};
    cout << "s: " << s << endl;

    int *pVal{&value};
    cout << pVal << ": " << *pVal << endl;

    double *pNum{};  // Equivalent to double *pNum = nullptr
    cout << pNum << endl;

    int array[3]{};
    cout << array[2] << endl;

    // Anonymous struct
    struct {
        int value;  // int value = 5; does not work because you loose implicit constructor, need to implement constructor
        string text;
    } c{6, "Crush"};
    cout << c.text << endl;

    // Initializing vector
    vector<string> t{"Crush", "Kona"};  // No need to use t.push_back(...)
    cout << t[1] << endl;

    return 0;
}

/*
 * type variable{value}; - Initializing a variable in C++ 11
 *
 * nullptr - It can not be cast into an int and it is used specifically to initialize
 * pointers. NULL is not a C++ keyword.
 */