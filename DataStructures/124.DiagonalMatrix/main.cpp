#include <iostream>
using namespace std;

struct Mtx{
    int A[10];
    int n;
};

void Set(struct Mtx* m, int i, int j, int x){
    if (i == j){
        m->A[i-1] = x;
    }
}

int Get(struct Mtx m, int i, int j){
    if (i == j){
        return m.A[i-1];
    } else {
        return 0;
    }
}

void Display(struct Mtx m){
    for (int i=0; i < m.n; i++){
        for (int j=0; j < m.n; j++){
            if (i == j){
                cout << m.A[i] << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

int main() {


    struct Mtx m;
    m.n = 4;

    Set(&m, 1, 1, 5);
    Set(&m, 2, 2, 8);
    Set(&m, 3, 3, 9);
    Set(&m, 4, 4, 12);

    Display(m);

    cout << Get(m , 2, 2) << endl;


    return 0;
}