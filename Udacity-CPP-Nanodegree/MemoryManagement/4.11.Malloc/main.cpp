#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {

    int *ptr = nullptr;

    ptr = new(std::nothrow) int;

    ptr = (int*)malloc(4 * sizeof(int));

    for (auto i = 0; i < 4; i++){
        cout << "Address: " << &ptr[i] << ", Value: " << ptr[i] << endl;
    }

    cout << endl;

    for (auto i = 0; i < 4; i++){
        memset(&ptr[i], ('A' + i), sizeof(int));
    }

    for (auto i = 0; i < 4; i++){
        cout << "Address: " << &ptr[i] << ", Value: " << char(ptr[i]) << endl;
    }


    return 0;
}