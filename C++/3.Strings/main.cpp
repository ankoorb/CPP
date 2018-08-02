#include <iostream>
using namespace std;

int main() {

    // Declare string variables
    string text = "This is a string."; // string is class and text is object
    string text1 = "Hello ";
    string text2 = "Fred.";

    cout << text << endl;
    cout << text1 << text2 << endl;

    // String concatenation
    cout << "String concatenation: " << text1 + text2 << endl;

    return 0;
}