#include <iostream>
using namespace std;

class Animal {  // Animal is superclass
public:
    void speak() {
        cout << "Animal Speaking: Grrr!" << endl;
    }
};

class Canine: public Animal {  // Canine is subclass of Animal
public:
    void jump() {
        cout << "Canine Jumping!" << endl;
    }
};

class Dog: public Canine {  // Dog is subclass of Canine and Animal
public:
    void attack() {
        cout << "Dog Attacking!" << endl;
    }
};

int main() {

    Animal A;
    A.speak();

    Canine C;
    C.speak();
    C.jump();

    Dog D;
    D.speak();
    D.jump();
    D.attack();

    return 0;
}