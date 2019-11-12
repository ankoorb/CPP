#include <iostream>
using namespace std;

void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Delete(int A[], int n){
    int x = A[0];  // Max element
    A[0] = A[n-1];

    int i = 0;
    int j = 2 * i + 1;

    while (j < n-1){
        // Compare left and right children
        if (A[j] < A[j+1]){
            j = j+1;
        }

        // Compare parent and largest child
        if (A[i] < A[j]){
            swap(A, i, j);
            i = j;
            j = 2 * i + 1;
        } else {
            break;
        }
    }
    return x;
}


template <class T>
void Print(T& vec, int n, char c){
    cout << c << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

int main() {

    int A[] = {40, 35, 30, 15, 10, 25, 5};
    Print(A, sizeof(A)/sizeof(A[0]), 'A');

    int n = sizeof(A)/sizeof(A[0]);
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        int max = Delete(A, n);
        cout << "max: " << max << endl;
        Print(A, sizeof(A)/sizeof(A[0]), 'A');
    }

    return 0;
}