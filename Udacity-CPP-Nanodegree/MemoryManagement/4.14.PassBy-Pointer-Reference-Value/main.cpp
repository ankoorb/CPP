#include <iostream>
#include <cstdio>
#include <bitset>
#include <string>

using namespace std;

// Pass by pointer
void addThree(int* val){
    *val += 3;
}

// Pass by reference
void multiplyFive(int& x){
    x *= 5;
}

// Pass by value
void addTwo(int x){
    x += 2;
}

void CallByValue(int i) {
    int j = 1;
    printf("call-by-value: %p\n", &j);
}

void CallByPointer(int *i) {
    int j = 1;
    printf("call-by-pointer: %p\n", &j);
}

void CallByReference(int &i) {
    int j = 1;
    printf("call-by-reference: %p\n", &j);
}

int main() {

    int val = 0;
    addThree(&val);
    cout << "val: " << val << endl;

    multiplyFive(val);
    cout << "val: " << val << endl;

    addTwo(val);
    cout << "val: " << val << endl;

    // Stack example
    int i = 0;

    printf("stack bottom: %p\n", &i);

    CallByValue(i);
    CallByPointer(&i);
    CallByReference(i);

    return 0;
}