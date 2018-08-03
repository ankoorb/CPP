#include <iostream>
using namespace std;

template <class T>
void print(T data){
    cout << "Template Version: " << data << endl;
}

void print(int value){
    cout << "Non Template Version: " << value << endl;
}

// Situation
template <class T>
void show(){
    cout << T() << endl;  // T() runs constructor of class T
}

int main() {

    print<string>("Hello");
    print<int>(15);

    cout << endl;
    print("World");
    print(7);
    print<>(7);  // Put at least <> to use template version of function

    // Situation
    //show<>(); // C++ can not infer type because there is no argument list.
    show<double>(); // This works where default value of double is used



    return 0;
}


/*
 * NOTE: Functions can be overloaded as long as their argument list is different.
 *
 * There are situations in which your code literally is not going to compile so you can not
 * use template function unless you put not only <> brackets but type as well. Situation:
 *
 * Remember C++ looks at argument list to infer the type you mean if you try to use type
 * inference with <> or by not specifying even diamond brackets at all
 */