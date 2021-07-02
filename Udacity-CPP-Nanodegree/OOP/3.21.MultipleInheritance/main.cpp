#include <iostream>
#include <string>
#include <cassert>

using namespace std;


class Animal {
public:
    int age;
};

class Pet {
public:
    string name;
};

// Dog and Cat derives from both Animal and Pet
class Dog : public Animal, public Pet {
public:
    string breed;
};

class Cat : public Animal, public Pet {
public:
    string color;
};


int main() {

    Dog dog;
    dog.age = 7;
    dog.name = "Crush";
    dog.breed = "Doberman";

    assert(dog.age == 7);
    assert(dog.name == "Crush");
    assert(dog.breed == "Doberman");

    return 0;
}