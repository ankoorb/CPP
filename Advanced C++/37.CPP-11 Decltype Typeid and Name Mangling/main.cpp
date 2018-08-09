#include <iostream>
#include <typeinfo>
using namespace std;

int main() {

    int value;
    cout << typeid(value).name() << endl;

    double number;
    cout << typeid(number).name() << endl;

    string text;
    decltype(text) name = "Crush";  // Declare variable of existing type
    cout << name << endl;
    cout << typeid(name).name() << endl;

    return 0;
}

/*
 * typeid - #include <typeinfo> header. C++ 98
 *
 * typeid(object) returns type information about object, typeid(object).name() returns
 * name of type
 *
 * typeid(object).name() -> i: integer type, d: double type
 *
 * For string "NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE" is returned.
 * C++ does name mangling, where it takes names of the things like variables and functions
 * and it adds a lot of characters to them to get more information about what those are. So
 * returned output gives a lot of information about string type.
 *
 * C++ 11
 * decltype - Allows to declare variables of existing type
 *
 */