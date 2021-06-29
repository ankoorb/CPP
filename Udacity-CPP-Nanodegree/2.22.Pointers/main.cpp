#include <iostream>
#include <vector>

using namespace std;

void addOne(int* x){
    (*x)++;
}

int* subtractOne(int& x){
    x--;
    return &x;
}

int main() {

    int i = 5;
    int j = 6;

    cout << "The address of i is: " << &i << endl;
    cout << "The address of j is: " << &j << endl;

    int* ptr_to_i = &i;
    cout << "The address of i is: " << &i << endl;
    cout << "The variable ptr_to_i is: " << ptr_to_i << endl;
    cout << "The value of the variable pointed to by ptr_to_i is: " << *ptr_to_i << endl;

    vector<int> v = {1, 2, 3};
    vector<int>* pv = &v;

    for (auto e: v){
        cout << e << ", " << flush;
    }

    cout << "The first element of the pointer to a vector is: " << (*pv)[0] << endl;

    i = 1;
    addOne(ptr_to_i);
    cout << "The value of the variable i is now: " << *ptr_to_i << endl;

    j = 1;
    int* ptr_to_j = subtractOne(j);
    cout << "The value of the variable j is now: " << j << endl;
    cout << "The value of the variable pointed to by ptr_to_j is: " << *ptr_to_j << endl;


    return 0;
}