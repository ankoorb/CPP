#include <iostream>
using namespace std;

#define Log(x) { cout << x << endl; }

class Animal {
public:
    virtual void speak() { Log("???") };  // Need to declare method virtual only in the base class
    //virtual void speak() = 0;
    virtual ~Animal() {};
};

class Canine: public Animal {
public:
    void speak() { Log("Growl!") };  // virtual is used for overriding methods
    virtual ~Canine() {};
};

class Dog: public Canine {
public:
    virtual void speak() { Log("Bark!") }
    virtual ~Dog() {};  // Destructors should always be declared virtual, as they cleans up memory
};


int main() {

    Canine * pAnimal = new Dog;  // Pointer or reference to base class type

    pAnimal->speak();

    delete pAnimal;


    return 0;
}















