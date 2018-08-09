#include <iostream>
#include <vector>
using namespace std;

class C {
public:
    string text;
    int id;
};

struct S {
    string text;
    int id;
};

int main() {

    // Using {} to initialize an array
    int value[] = {1, 3, 5};
    cout << value[1] << endl;

    // Using {} to initialize public member variables of a class or struct
    C c_obj = {"Hello", 7};
    cout << c_obj.text << endl;

    S s_obj = {"World", 15};
    cout << s_obj.text << endl;

    // Vector
    vector<int> v_obj = {1, 2, 3};  // works
    v_obj.push_back(4);
    for(auto i: v_obj){ cout << i << endl; }

    return 0;
}

/*
 * This style of initialization using {} is more commonly used in `struct` because by default
 * members are public.
 *
 * In C++ 11 - {} can be used to initialize things even custom types
 *
 */