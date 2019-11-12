#include <iostream>
using namespace std;

void Insert(int A[], int n){
    int i = n;
    int temp = A[i];

    while (i > 1 && temp > A[i/2]){
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

int Delete(int A[], int n){
    int i;
    int j;
    int temp;
    int val = A[1];

    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = i * 2;

    while (j < n-1){
        if (A[j+1] > A[j]){
            j += 1;
        }
        if (A[i] < A[j]){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        } else {
            break;
        }
    }
    return val;
}



int main() {

    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};

    for (int i=2; i<sizeof(H)/sizeof(H[0]); i++){
        Insert(H, i);
    }

    for (int i=1; i<sizeof(H)/sizeof(H[0]); i++){
        cout << H[i] << " " << flush;
    }
    cout << endl;

    cout << "Deleted: " << Delete(H, sizeof(H)/sizeof(H[0])) << endl;
    cout << "Deleted: " << Delete(H, sizeof(H)/sizeof(H[0])) << endl;


    for (int i=1; i<sizeof(H)/sizeof(H[0]); i++){
        cout << H[i] << " " << flush;
    }
    cout << endl;


    return 0;
}