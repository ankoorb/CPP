#include <iostream>
using namespace std;

class Test {
private:
    int id;
    string name;
public:
    Test(): id(id), name(name){}
    Test(int id, string name): id(id), name(name){}
    void print() { cout << id << ": " << name << endl; }

    // Assignment operator overloading
    const Test &operator=(const Test &other){ // We have first implicit argument already
        cout << "Assignment running" << endl;
        id = other.id;
        name = other.name;
        return *this;
    }
    // explicit argument: const Test &other -> is const because we do not want RHS to change
    // and using reference because it is more efficient to pass references than passing objects

    // Copy constructor
    Test(const Test &other) {
        cout << "Copy constructor running" << endl;
        id = other.id;
        name = other.name;
//        *this = other;  // Can use if we have implement assignment operator
    }
};

int main() {

    Test test1(1, "Crush");
//    cout << "test1 - ";
//    test1.print();

//    Test test2(7, "Kona");
////    cout << "test2 - ";
////    test2.print();
//
//    // Assigning
////    test2 = test1;
////    cout << "After assignment test2 - ";
////    test2.print();  // Prints 1: Crush
////    cout << endl;
//
//    Test test3;
//    test3 = test2 = test1;
//    test3.print();
//
//    test3.operator=(test2);
//    cout << "test3 - ";
//    test3.print();
//
//    cout << endl;
//
    // This is called copy initialization
    Test test4 = test1;  // This will not run if copy construction is not implemented
    test4.print();


    return 0;
}




/*
 * `object2 = object1` -> This works because C++ provides a default implementation of something that
 * causes this to work. What it is actually doing is a shallow copy. It is copying all the values of
 * the variables in `object1` over to `object2`. Sometimes you want a shallow copy but other times
 * need a deep copy, e.g. If you had an `id` that had to be unique for every object you might not want
 * to give `object2` the same `id` as `object1` (you might want to change the `id` to a unique `id` but
 * give it the same name. You might also have pointers in the construction for example could allocate
 * memory, if you have pointer in `object1` that is pointing in some allocated memory, you do a shallow
 * copy to copy the value to `object2`, you have now got a copy of that pointer pointing at the memory
 * `object1` allocated, you have stolen `object1`'s memory rather that allocating your own in the copy.
 * So sometimes you want to override this kind of behaviour.
 *
 * `object2 = object1` can be thought of as calling a method on `object2` and providing it with
 * the argument `object1`. The operator `=` has 2 arguments to it (`object1` and `object2`). If we
 * implement a method and call it on `object2` and pass it `object1`, this also actually got 2 arguments
 * because not only `object1` is an argument but the method receives an implicit first argument which
 * is a reference to the object being called on and that enables you to use `this` operator in your
 * methods. `test2.print()` seems to have no arguments but there is an implicit first argument. So if
 * we implement the `=` operator as a method call with one argument, it has actually got 2 arguments
 * (`object1` and `object2`). Because it has 2 arguments to it we call it a binary operator.
 *
 *
 * `test3 = test2 = test1` -> Return reference from method call.
 *
 * `test3.operator=(test2)` is equivalent to `test3 = test2`, and you can see that the `=` operator is
 * like a method call where the method name is `operator=`
 *
 * Return type for assignment operator overloading should be `const reference` because you do not want
 * to change things?
 *
 * Copy Initialization (Test test4 = test1;) -> If you take an object and do not give initial values
 * (i.e. Test test4), and you just immediately assign the declared object to another it does not actually
 * use the `=` operator it actually uses the copy constructor
 *
 * Rule of Three in C++: If you define a copy constructor or an assignment operator or a destructor. If
 * you implement any one of those then you should implement the other 2 as well.
 *
 *
 */