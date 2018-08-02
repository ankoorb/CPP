#include <iostream>
using namespace std;

class Animal {
private:
    string name;
public:
    Animal() { cout << "Animal created." << endl; }
    ~Animal() { cout << "Destructor called." << endl; }

    void setName(string name) { this->name = name; }
    void speak() const { cout << "Animal name: " << name << endl; };
};

// Create a function that returns pointer to object of Animal class
Animal *createAnimal() {
    Animal *pAnimal = new Animal;
    pAnimal->setName("Snoops");
    return pAnimal;
}

int main() {

    Animal *pCat = createAnimal();
    pCat->speak();
    delete pCat;  // De-allocate memory

    return 0;
}