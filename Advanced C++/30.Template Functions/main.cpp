#include <iostream>
using namespace std;

//void print(int n) { cout << n << endl; }  // Function that takes int

template<class T>
//template <typename T>  // Can also be used but class is more common
void Print(T n){ cout << n << endl; }


int main() {

//    print(5);

    Print<string>("Hello");
    Print<int>(10);

    // C++ does automatic type inference. C++ looks at arguments and infer what type is needed
    Print("Crush");
    Print(7);

    return 0;
}

/*
 * Template function can be part of class or template classes.
 *
 * Exercise: See if you can think of some code where you put in a type or not actually makes
 * a difference to the program. HINT: Remember you can overload function with same name
 */