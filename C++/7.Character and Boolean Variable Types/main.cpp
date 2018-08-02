#include <iostream>
using namespace std;

int main() {

    // Boolean: true = 1 and false = 0
    bool b_value = true;
    cout << "bool type: " << b_value << endl;
    cout << "Size of bool: " << sizeof(bool) << endl;

    // Character
    char c_value = 'g';
    cout << "char type: " << c_value << endl;
    cout << "Size of char: " << sizeof(char) << endl;

    // char designed to represent single characters from ascii characters set
    char i_value = 55;
    cout << "integer set as char type : " << i_value << endl; // Prints 7

    i_value = '7';
    cout << i_value << endl;
    cout << "Actual number: " << (int)i_value << endl; // (int)variable - casting variable to int

    return 0;
}