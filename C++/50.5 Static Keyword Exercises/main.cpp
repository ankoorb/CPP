#include <iostream>
#include "Dog.h"
using namespace std;

/*
 * 1. Define and output an public static constant
 * 2. Define and output a non constant static field.
 * 3. Output a static field with a static method
 * 4. Try incrementing static int field with postfix and prefix increment operators (pre/post)
 * 5. Try assigning object ID based on static count incremented in constructor
 */

int main() {

    // 1. Define and output an public static constant
    cout << Dog::PAWS << endl;

    // 2. Define and output a non constant static field.
    cout << Dog::id << endl;

    // 3. Output a static field with a static method
    Dog::num_paws();

    // 4. Try incrementing static int field with postfix and prefix increment operators (pre/post)
    Dog crush;
    cout << Dog::total_paws() << endl;
    Dog pluto;
    cout << Dog::total_paws() << endl;
    Dog goofy;
    cout << Dog::total_paws() << endl;



    return 0;
}