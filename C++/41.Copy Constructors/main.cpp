#include <iostream>
using namespace std;

class Animal {
private:
    string name;
public:
    // Constructor
    Animal() { cout << "Animal Created!" << endl;}

    // Copy Constructor (explicit)
    Animal(const Animal &(other)): name(other.name) {
        cout << "Animal Created by Copying!" << endl;
    }

    void setName (string name) { this->name = name;}
    void speak() const { cout << "Animal name: " << name << endl;}
};

int main() {

    Animal dog1;
    dog1.setName("Crush");

    Animal dog2 = dog1;  // Why constructor is not called for here?
    dog2.speak();

    /*
    Because we are implicitly invoking copy constructor. C++ implicitly
    created a special constructor called copy constructor that simply
    copies settings from one object to another. Copy constructor can
    be explicitly defined.
    */
    dog2.setName("Lucy Lu");  // Can set animal name independently;

    dog1.speak();
    dog2.speak();

    Animal dog3(dog1);
    dog3.speak();

    return 0;
}