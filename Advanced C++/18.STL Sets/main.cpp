#include <iostream>
#include <set>
using namespace std;

class Dog {
private:
    int id;
    string name;

public:
    Dog(): id(0), name("") {};
    Dog(int id, string name): id(id), name(name){};
    void print() const {
        cout << "Name: " << name << " & id: " << id << endl;
    }

    // Overloading < operator
    bool const operator<(const Dog &other) const {  // Reference to an existing object
        if(name == other.name){
            return id < other.id;
        }
        return this->name < other.name; // or name < other.name;
    };
};

int main() {

//    // Declare a set to store integers
//    set<int> numbers;
//
//    // Insert elements to set
//    numbers.insert(7);
//    numbers.insert(6);
//    numbers.insert(7);  // Same value
//
//    for(set<int>::iterator it = numbers.begin(); it != numbers.end(); it++){
//        cout << *it << endl;
//    }
//    cout << endl;
//
//    // Find if an object is in set
//    set<int>::iterator itFind = numbers.find(7);
//
//    if(itFind != numbers.end()){  // As long as it doesn't search through the entire set and come off
//        // the end without finding it
//        cout << "Found: " << *itFind << endl;
//    }
//    cout << endl;
//
//    // Using another method
//    if(numbers.count(7)){  // Count returns 0 or 1
//        cout << "Number found!" << endl;
//    }
//    cout << endl;


//    // Dob object
//    Dog crush(6, "Crush");
//    crush.print();
//    cout << endl;

    // Set of Dog objects
    set<Dog> dogs;

    dogs.insert(Dog(1, "Crush"));
    dogs.insert(Dog(3, "Kona"));
    dogs.insert(Dog(2, "Crush"));

    for(set<Dog>::iterator it = dogs.begin(); it != dogs.end(); it++){
        it->print();
    }

    return 0;
}

/*
 * set - It only stores unique elements, `setObject.insert()` method to insert the elements and it orders
 * the elements as well.
 */