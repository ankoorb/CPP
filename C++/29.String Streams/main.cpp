#include <iostream>
#include <sstream>

using namespace std;

// String streams lets you concatenate disparate types of data, e.g. string and double into string
int main() {

    string name = "Ankoor";
    int age = 36;

    stringstream ss;

    ss << "Name: " << name << " and age: " << age;

    // Convert to string and output
    cout << ss.str() << endl;

    // Another approach
    string info = ss.str();
    cout << info << endl;

    return 0;
}