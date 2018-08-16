#include <iostream>
using namespace std;

class Test {};

//template<typename T>
//void call(T &&arg){
//    check(arg);
//}

//template<typename T>
//void call(T &&arg){
//    check(static_cast<T>(arg));
//}
//
template<typename T>
void call(T &&arg){
    check(forward<T>(arg));
}

void check(Test &test){
    cout << "Lvalue" << endl;
}

void check(Test &&test){
    cout << "Rvalue" << endl;
}

int main() {

    Test test;

    // Rvalue reference to Rvalue
    auto &&rt = Test();

    // Lvalue reference to Lvalue
    auto &t = test;

    // Rvalue reference to Lvalue
    auto &&tt = test;  // References collapse because of use of `auto` (Reference collapsing rule)

    call(Test());
    call(test);

    return 0;
}


/*
 * Perfect Forwarding - Idea behind perfect forwarding is that you might want to call
 * the right version of a function depending on whether you passed to your template
 * function a Rvalue or an Lvalue.
 */