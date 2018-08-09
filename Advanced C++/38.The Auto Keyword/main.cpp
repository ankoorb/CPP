#include <iostream>
#include <typeinfo>
using namespace std;

//auto test() { return 15; } // Does not work
auto test() -> int { return 15; }  // Trailing return types

template <class T>
auto check(T value) -> decltype(value) { return value; }

template <class T, class K>
auto check(T value1, K value2) -> decltype(value1 + value2) { // can call function in decltype
    return value1 + value2;
}

int get(){ return 75; }

auto func() -> decltype(get()){
    return get();
}



int main() {

    auto value = 7;
    cout << typeid(value).name() << endl;

    auto text = "Hello";
    cout << text << endl;

    cout << test() << endl;

    cout << check(text) << endl;

    cout << check(3, 9) << endl;

    cout << func() << endl;


    return 0;
}

/*
 * C++ 98: auto is the default storage class specifier for variables, so `auto int value = 7`
 * is used.
 *
 * C++ 11: auto has been extended and type declaration can be missed out, e.g. `auto value = 7`
 * and C++ automatically infers the type by looking at initialized value.
 *
 * auto can also be used to infer return type of functions. C++ 11 introduces trailing return
 * types. `auto functionName() -> type;`. It is useful if using template functions. Use
 * `decltype` to inquire about type and use it with trailing return types.
 *
 *
 *
 */