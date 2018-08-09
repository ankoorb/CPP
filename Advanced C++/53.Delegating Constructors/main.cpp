#include <iostream>
using namespace std;

class Parent {
private:
    int id;
    string text;
public:
    Parent(): Parent("Hello"){  // Calling constructor with parameter within class
        id = 7;
        cout << "No parameter Parent constructor" << endl;
    }
    Parent(string text){
        id = 7;
        this->text = text;
        cout << "string parameter Parent constructor" << endl;
    }
};

class Child: public Parent {
public:
    Child() = default; // NOTE: Can not use Parent() = default; in Parent class
};

int main() {

    Parent parent("Crush");
    Child child;

    return 0;
}

/*
 *
 */


//#include <iostream>
//using namespace std;
//
//class Parent {
//private:
//    int id;
//    string text;
//public:
//    Parent(){
//        id = 7;
//        cout << "No parameter Parent constructor" << endl;
//    }
//    Parent(string text){
//        id = 7;
//        this->text = text;
//        cout << "string parameter Parent constructor" << endl;
//    }
//};
//
//class Child: public Parent {
//public:
//    Child(): Parent("Hello"){}
//};
//
//int main() {
//
//    Parent parent("Crush");
//    Child child;
//
//    return 0;
//}

/*
 * When Child class object is constructed it must run constructor in Parent class.
 * Parent class constructors are not inherited i.e. Parent class constructors can
 * not be called from Child class, but they do exist in the Child class. In Parent
 * class if there is no default constructor and you define a constructor that takes
 * a parameter then the default implementation of no parameter constructor is lost.
 * Child class is trying to run that constructor but it can not so we get compilation
 * error - Solution: Need to specify in Child class which constructor to run.
 *
 * In C++ 11: We can select what constructor we want to use if there are several
 * different constructors in Parent class, and this is called delegating constructor.
 * In C++ 98 we could not call one constructor from another within a class. Good
 * practice is to avoid recursion, pick either no parameter constructor or constructor
 * with most parameters and call that from the other constructors.
 *
 */