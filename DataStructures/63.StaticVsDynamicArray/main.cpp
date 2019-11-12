#include <iostream>
using namespace std;


int main() {

    int A[5] = {2, 4, 6, 8};
    int* p = new int [5];

    p[0] = 1;
    p[2] = 3;
    p[3] = 5;
    p[4] = 7;
    p[5] = 9;

    for(int i=0; i<5; i++){
        cout << A[i] << endl;
        cout << p[i] << endl;
    }


    return 0;
}