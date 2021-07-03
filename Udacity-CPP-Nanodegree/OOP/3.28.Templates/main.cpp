#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// Templates enable generic programming by generalizing a function to apply to any class
// Templates use types as parameters

template <typename Type>
Type Sum(Type x, Type y){
    return x + y;
}

template <typename T>
T Product(T x, T y){
    return x * y;
}

int main() {

    cout << Sum<double>(20.0, 13.7) << endl;
    cout << Sum<int>(20, 13) << endl;
    cout << Sum<string>("Formula", " 1") << endl;
    cout << Sum<char>('F', '1') << endl;

    assert(Product<int>(10, 2) == 20);

    return 0;
}