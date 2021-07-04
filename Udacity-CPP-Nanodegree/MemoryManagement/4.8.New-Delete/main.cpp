#include <iostream>

using namespace std;

int main() {

    double* ptr = new double(23);
    double* arr_ptr = new double[4];

    for (auto i = 0; i < 3; i++){
        *ptr = ++(*ptr);
        arr_ptr[i] = *ptr;
        cout << "Address        : " << ptr << ", Value          : " << *ptr << endl;
        cout << "Address array  : " << arr_ptr << ", Value array    : "<< arr_ptr[i] << endl;
    }

    delete ptr;
    delete [] arr_ptr;

    return 0;
}