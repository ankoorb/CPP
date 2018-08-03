#include <iostream>
#include <map>
using namespace std;

class Person{
private:
    string name;
    int age;

public:
    // Default constructor
    Person(): name(""), age(0) {};

    // Create a copy constructor
    Person (const Person &other) {
        cout << "Copy constructor running" << endl;
        name = other.name;
        age = other.age;
    };

    // Constructor that accepts parameters
    Person(string name, int age): name(name), age(age) {};

    void print() const { cout << name << ": " << age << flush; }

    // Overloading less than operator
    bool operator<(const Person &other) const {  // There should be no space between operator and <

        // Taking care of situation when name is same but age is different
        if(name == other.name){
            return this->age < other.age;
        }
        return name < other.name;  // Using string less than operator for alphabetically sorting
    };
    // bool used because less that returns bool
    // < operator will compare this object with other object, so need to pass in other object that has to be marked
    // const reference, reference is used for efficiency as we do not want to create copy of the Person when it is passed
    // in. const used because we do not want < to change the other object. It is important to mark the whole method as
    // const because the overloaded operator should not change `this` (i.e. self) object or the other object.
};

int main() {

    map<Person, int> people;
    people[Person("Crush", 6)] = 6;
    people[Person("Kona", 1)] = 1;

    // Adding a new object with the same key -> the value of the key gets updated
    people[Person("Kona", 7)] = 15;  // considered same as people[Person("Kona", 1)], need to take age into account

    for(map<Person, int>::iterator it=people.begin(); it!=people.end(); it++){

        // NOTE: key is a Person object
        cout << it->second << " <- " << flush;
        it->first.print();
        cout << endl;
    }
    return 0;
}

/*
 * error: member function 'some_function' not viable: 'this' argument has type 'const ClassName', but function is
 * not marked const -> The keys in the map as retrieved by `first` using the iterator are `const` and map does not want
 * one to alter the keys so as important as they are, the iterator returns them as `const` and the `some_function` is
 * not marked as `const` so it could change the keys, so that is why error is returned -> Solution: mark `some_function`
 * as `const`
 *
 * error: invalid operands to binary expression ('ostream' (aka 'basic_ostream<char>') and 'void') -> This is caused
 * because C++ does not know how to compare different objects of the Person class. It has to compare because it has to
 * sort the keys of the map in the right order (comparison is done using less than i.e. < operator) -> Solution: Operator
 * overloading, i.e. implement own version of operator in the class
 */




