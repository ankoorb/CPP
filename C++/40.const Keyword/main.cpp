#include <iostream>
using namespace std;

class Animal {
private:
    string name;
public:
    void setName(string name) {this->name = name;};
    void speak() const {cout << "Animal name is: " << name << endl;};
};

int main() {

    const double pi = 3.14159;
    cout << pi << endl;

    Animal dog;
    dog.setName("Crush");
    dog.speak();

    int value = 8;
    int *pvalue = &value;
    //const int *pvalue = &value;  // Pointer to an int that is const, we cant change the int that pointer points at
    //int *const pvalue = &value;  // Constant pointer to an int, i.e. int is not constant anymore, the pointer is constant, we cant reassign pointer to point somewhere else
    //const int *const pvalue = &value;  // Constant pointer to an int that is const, we cant change anything

    cout << *pvalue << endl;

    // Changing pointer variable
    int number = 11;
    pvalue = &number;  // Error when pointer is a const
    cout << *pvalue << endl;
    *pvalue = 12;  // Error when pointer to an int that is const

    cout << *pvalue << endl;

    return 0;
}