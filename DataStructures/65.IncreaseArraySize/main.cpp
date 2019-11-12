#include <iostream>
using namespace std;

int main() {

    int* A = new int[5];
    A[0] = 1;
    A[1] = 3;
    A[2] = 5;
    A[3] = 7;
    A[4] = 9;

    int* P = new int[10];

    for (int i=0; i<5; i++){
        P[i] = A[i];
    }

    delete []A;
    A = P;
    P = nullptr;

    for (int i=0; i<10; i++){
        cout << A[i] << endl;
    }


    return 0;
}