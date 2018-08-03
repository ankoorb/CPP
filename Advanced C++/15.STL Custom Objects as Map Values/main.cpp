#include <iostream>
#include <map>
using namespace std;

class Person{
private:
    string name;
    int age;

public:
    Person(): name(""), age(0) {};  // If this is not used then error: no matching constructor for initialization of 'Person'

    // Create a copy constructor
    Person (const Person &other) {
        cout << "Copy constructor running" << endl;
        name = other.name;
        age = other.age;
    };

    Person(string name, int age): name(name), age(age) {};
    void print() { cout << name << ": " << age << endl; }
};

int main() {

    map<int, Person> people;
    people[0] = Person("Kona", 1);
    people[1] = Person("Crush", 6);

    people.insert(make_pair(3, Person("Spot", 7)));  // Copy constructor runs

    for(map<int, Person>::iterator it=people.begin(); it!=people.end(); it++){

        // NOTE: Value is a Person object
        cout << it->first << ": " << flush;
        it->second.print();
    }


    return 0;
}

/*
 * error: no matching constructor for initialization of 'Person' - When you define your own constructor that has
 * parameters you loose the default implementation of a constructor with no parameters and map needs that to construct
 * the object and then assign values to the object using the object that you set that equal to (e.g. Person("Kona", 1)).
 * To fix this create a parameter less constructor.
 *
 * people[1] = Person("Crush", 6) -> map is constructing the object using default parameter-less constructor and then
 * assigning values to the object using the assignment operator (=), by default C++ gives classes a default implementation
 * of the assignment operator which does a shallow copy, this is not good when using pointer. So sometimes you will need
 * to override assignment operator.
 *
 * In general you do not want to copy pointers when you do a copy of an object because then you just get a pointer that
 * is pointing at the same place that your other object's pointer was pointing to.
 *
 * If you do not want to copy the values of some instance variables when you do the copy or you want to change them
 * somehow in the copy then you want to provide a copy constructor as well as overriding assignment operator.
 *
 * Map always sorts objects in the order of its keys
 */