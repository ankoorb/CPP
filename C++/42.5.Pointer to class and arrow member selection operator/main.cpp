#include <iostream>
using namespace std;

class Dog {
public:
    Dog(){};
    ~Dog(){};
    void speak() { cout << "Bark!" << endl; }
};

int main() {

    Dog dogObject;
    dogObject.speak();  // Accessing speak with object

    Dog *dogPointer = &dogObject;
    dogPointer->speak();  // Accessing speak with pointer

    Dog *crush;
    crush->speak();

    return 0;
}