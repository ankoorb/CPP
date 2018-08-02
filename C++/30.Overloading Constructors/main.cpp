#include <iostream>
#include "Person.h"
using namespace std;


int main() {

    Person person_1;
    Person person_2("Ankoor");
    Person person_3("Ankoor", 100);

    cout << person_1.toString() << endl;
    cout << person_2.toString() << endl;
    cout << person_3.toString() << endl;

    return 0;
}