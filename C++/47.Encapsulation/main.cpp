#include <iostream>
using namespace std;

class Frog {
private:
    string name;
    string getName() { return name; }

public:
    Frog(string name): name(name) {};
    void info() { cout << "Frog's name is: " << getName() << endl; }
};


int main() {

    Frog frog("Mr. Toad");  // Implicitly calling constructor
    //cout << frog.getName() << endl;  // frog.name will return because name is private
    frog.info();

    return 0;
}