#include <iostream>
using namespace std;

class Animal {
private:
    string name;
public:
    Animal() { cout << "Animal created." << endl; }
    Animal(const Animal &other):
            name(other.name) {
        cout << "Animal created by copyong." << endl;
    }

    ~Animal() { cout << "Destructor called." << endl; }

    void setName(string name) { this->name = name; }
    void speak() const { cout << "Animal name: " << name << endl;}
};

int main() {

    Animal dog;
    dog.setName("Crush");
    dog.speak();

    Animal *pDog = new Animal();
    pDog->setName("Crush");
    pDog->speak();
    delete pDog;  // Always call a delete when use new because it causes memory leak and crash

    Animal *pCat = NULL;
    delete pCat;

    cout << sizeof(pDog) << endl;
    cout << sizeof(long) << endl;

    return 0;
}