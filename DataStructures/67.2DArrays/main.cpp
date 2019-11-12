#include <iostream>
using namespace std;

int main() {

    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};

    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        for (int j=0; j<sizeof(A[0])/sizeof(int); j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    int* B[3];
    B[0] = new int [4];
    B[1] = new int [4];
    B[2] = new int [4];

    for (int i=0; i<3; i++){
        for (int j=0; j<4; j++){
            cout << B[i][j] << " ";
        }
        cout << endl;
    }


    cout << endl;
    int** C;
    C = new int* [3];
    C[0] = new int [4];
    C[1] = new int [4];
    C[2] = new int [4];

    unsigned int x[4] [3] ={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    cout << x+3 << " " << *(x+3) << " " << *(x+2)+3 << endl;



    return 0;
}