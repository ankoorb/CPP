#include <iostream>
using namespace std;

class Test {
    int id {7};
    string name {"Crush"};

public:
    Test() = default;  // Create implicit constructor
    Test(const Test &other) = delete;  // Delete implementation of copy constructor
    Test &operator=(const Test &other) = delete; // delete implementation of = operator
    Test(int id): id(id){}
    void print(){ cout << id << ": " << name << endl; }
};

int main() {

    Test t;
    t.print();

    Test s(3);
    s.print();

    // Using copy constructor
    Test u = s;
    u.print();

    // Using assignment operator
    s = t;
    s.print();

    return 0;
}

/*
 * If you want to make object unable to copy other object then use `delete` to delete implementations
 *
 *
 */

/*
 * Sometimes you do not want default implementation, e.g. there is implicit equals operator, we can make
 * it explicit
 */

//#include <iostream>
//using namespace std;
//
//class Test {
//    int id {7};
//    string name {"Crush"};
//
//public:
//    Test() = default;  // Create implicit constructor
//    Test(const Test &other) = default;  // Copy constructor
//    Test &operator=(const Test &other) = default; // Explicit = operator
//    Test(int id): id(id){}
//    void print(){ cout << id << ": " << name << endl; }
//};
//
//int main() {
//
//    Test t;
//    t.print();
//
//    Test s(3);
//    s.print();
//
//    // Using copy constructor
//    Test u = s;
//    u.print();
//
//    // Using assignment operator
//    s = t;
//    s.print();
//
//    return 0;
//}

/*
 * If a constructor is defined that takes a argument and uses that to initialize a member variable. The
 * constructor is going to run after the member variables are created and initialized, so the constructor
 * will override the default initializations. This works for copy constructor as well
 *
 * If you define any constructor in C++, then you are going to loose the implicit constructor. C++ 11
 * provides a way to create implicit constructors by setting constructor equal to `default`.
 *
 */

//#include <iostream>
//using namespace std;
//
//class Test {
//    int id {7};
//    string name {"Crush"};
//
//public:
//    Test() = default;  // Create implicit constructor
//    Test(const Test &other)= default;  // Copy constructor
//    Test(int id): id(id){}
//
//    void print(){ cout << id << ": " << name << endl; }
//};
//
//int main() {
//
//    Test t;
//    t.print();
//
//    Test s(3);
//    s.print();
//
//    // Using copy constructor
//    s = t;
//    s.print();
//
//    return 0;
//}

/*
 * If member variables in a class are initialized, then all the objects of that class will have variables
 * initialized.
 */

//#include <iostream>
//using namespace std;
//
//class Test {
//    int id{7};
//    string name{"Crush"};
//
//public:
//    void print(){ cout << id << ": " << name << endl; }
//};
//
//int main() {
//
//    Test t;
//    t.print();
//
//    return 0;
//}


