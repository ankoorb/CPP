#include <iostream>
#include "Person.h"
using namespace std;

int main() {

    Person noone;
    Person jon("Jon", 21);
    Person arya("Arya", 18);

    cout << noone.toString() << endl;
    cout << jon.toString() << endl;
    cout << arya.toString() << endl;

    return 0;
}