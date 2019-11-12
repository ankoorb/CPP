#include <iostream>
#include <cstdlib>
using namespace std;

class LTMatrix{
private:
    int n;
    int* A;
public:
    LTMatrix(int n){
        this->n = n;
        A = new int [n * (n + 1)/2];
    }
    ~LTMatrix(){ delete[] A; }
    void Display(bool row=true);
    void setRowMajor(int i, int j, int x);
    void setColMajor(int i, int j, int x);
    int getRowMajor(int i, int j);
    int getColMajor(int i, int j);
    int getN(){ return n; }

};

void LTMatrix::setRowMajor(int i, int j, int x) {
    if (i >= j){
        int index = ((i * (i - 1))/2) + j - 1;
        A[index] = x;
    }
}

void LTMatrix::setColMajor(int i, int j, int x) {
    if (i >= j){
        int index = (n * (j-1) - (((j-2) * (j-1))/2)) + (i-j);
        A[index] = x;
    }
}

int LTMatrix::getRowMajor(int i, int j) {
    if (i >= j){
        int index = ((i * (i - 1))/2) + j - 1;
        return A[index];
    } else {
        return 0;
    }
}

int LTMatrix::getColMajor(int i, int j) {
    if (i >= j){
        int index = (n * (j-1) - (((j-2) * (j-1))/2)) + (i-j);
        return A[index];
    } else {
        return 0;
    }
}

void LTMatrix::Display(bool row) {
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i >= j){
                if (row){
                    cout << getRowMajor(i, j) << " ";
                } else {
                    cout << getColMajor(i, j) << " ";
                }
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

int main() {

    int d;
    cout << "Enter Dimensions: " << flush;
    cin >> d;

    LTMatrix mtx(d);

    bool row;
    cout << "\nEnter 'true' for Row Major and 'false' for Col Major: " << flush;
    cin >> row;

    for (int i=1; i<=d; i++){
        for (int j=1; j<=d; j++){
            int x = rand() % 9 + 1;
            if (row){
                mtx.setRowMajor(i, j, x);
            } else {
                mtx.setColMajor(i, j, x);
            }
        }
    }

    cout << "\nMtx" << endl;
    if (row){
        mtx.Display();
    } else {
        mtx.Display(row);
    }

    return 0;
}