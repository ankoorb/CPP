#include <iostream>
#include <string>

using namespace std;

int* createArray(int n){
    int* ptr = new int[n];
    return ptr;
}

int* resizeArray(int* ptr, int size, int extra){
    int* new_ptr = new int[size + extra];
    for (auto i = 0; i < size; i++){
        new_ptr[i] = ptr[i];
    }
    delete []ptr;
    return new_ptr;
}

int main() {

    int size;
    cout << "Enter size of array: " << flush;
    cin >> size;

    int* ptr = createArray(size);
    for (auto i = 0; i < size; i++){
        ptr[i] = i * i;
    }


    cout << "Array: " << flush;
    for (auto i = 0; i < size; i++){
        cout << ptr[i] << ", " << flush;
    }
    cout << endl;

    int extra = size * 2;
    ptr = resizeArray(ptr, size, extra);

    cout << "Array: " << flush;
    for (auto i = 0; i < size + extra; i++){
        cout << ptr[i] << ", " << flush;
    }

    return 0;
}