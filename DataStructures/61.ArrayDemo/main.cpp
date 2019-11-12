#include <iostream>
using namespace std;

int main() {

    int A[5];
    cout << A[2] << endl;

    int B[3] = {10, 20, 30};
    cout << 2[B] << endl;
    cout << B[2] << endl;

    int C[5] = {0, 1};
    cout << C[3] << endl;

    int D[3] = {0};
    cout << D[2] << endl;

    int E[] = {1, 2, 3, 4};
    cout << E[2] << endl;

    for (int i=0; i<5; i++){
        cout << A+i << " " << &A[i]<< endl;
    }

    return 0;
}