#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    string name;
    string color;
    int age;
};

class Snake : public Animal {
public:
    int length;
    void makeSound(){ cout << "Hiss...Hiss" << endl; }
};

class Cat : public Animal {
public:
    int height;
    void makeSound(){ cout << "Meow...Meow" << endl; }
};

int main() {

    Snake python;
    python.name = "Burmese";
    python.color = "Brown";
    python.age = 10;
    python.length = 12;
    python.makeSound();

    Cat bengal;
    bengal.name = "Sher";
    bengal.color = "Black";
    bengal.age = 4;
    bengal.height = 2;
    bengal.makeSound();

    return 0;
}