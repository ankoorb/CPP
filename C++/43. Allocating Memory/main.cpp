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


int main() {

    int *pInt = new int;
    *pInt = 7;
    cout << *pInt << endl;
    delete pInt;

    Animal *pDog = new Animal;  // Allocating memory and also instantiating an object in memory
    delete pDog;

    Animal *pAnimal = new Animal[2];  // Creates 10 Animal objects and allocate memory for

    pAnimal[1].setName("Crush");
    pAnimal[1].speak();

    delete [] pAnimal;  // Free up memory that pAnimal is pointing at

    char *pMem = new char[1000];
    delete [] pMem;

    char c = 'a';
    c++;
    string s(3, c);
    cout << s << endl;

    return 0;
}