#include <iostream>
#include "Person.h"
using namespace std;

int main() {

    Person person;
    person.set_name("Georgina");
    cout << person.toString() << endl;
    cout << "Get method: " << person.get_name() << endl;

    return 0;
}