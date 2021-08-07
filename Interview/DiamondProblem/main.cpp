#include <iostream>
#include <string>

using namespace std;

class Mammal {
protected:
    const string name_;
public:
    Mammal() : name_{""}{}
    Mammal(const string& name) : name_{name}{}
    void eat() { cout << "This Mammal " << name_ << " is eating" << endl; }
};

class Lion : virtual public Mammal {
public:
    void groom();
};

class Tiger : virtual public Mammal {
public:
    void groom();
};

class Liger : public Tiger, public Lion {
public:
    void nap();
};

int main() {

    Liger lyle {"Lyle"};

    return 0;
}
