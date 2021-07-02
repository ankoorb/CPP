#include <iostream>
#include <cassert>

using namespace std;

// Polymorphism can be achieved by (1) Overloading, and (2) Overriding

void hello(){ cout << "Hello, World!" << endl; }

class Human {
public:
    void hello(Human human) { cout << "Hello, Human!" << endl; }
};

class Dog {};

class Cat {};

class Bird {};

// TODO: Overload hello() function
void hello(Dog dog) { cout << "Hello, Dog!" << endl; }
void hello(Cat cat) { cout << "Hello, Cat!" << endl; }
void hello(Bird bird) { cout << "Hello, Bird!" << endl; }

int main() {

    Human human;
    human.hello(human);

    hello();

    hello(Dog());
    hello(Cat());
    hello(Bird());

    return 0;
}