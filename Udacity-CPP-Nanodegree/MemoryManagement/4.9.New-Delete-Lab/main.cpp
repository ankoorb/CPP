#include <iostream>

using namespace std;

int main() {

    int* arr_ptr = new int[5];

    for (auto i = 0; i < 5; i++){
        cout << "Please type in an int value: " << flush;
        int input;
        cin >> input;
        arr_ptr[i] = input;
    }

    for (auto i = 0; i < 5; i++){
        cout << "Number " << arr_ptr[i] << " is stored at " << (arr_ptr + i) << " address" << endl;
    }

    delete [] arr_ptr;

    return 0;
}