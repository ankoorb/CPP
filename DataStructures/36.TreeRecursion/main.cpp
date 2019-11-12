#include <iostream>
using namespace std;

void treeRecursion(int n){
    if (n > 0){
        cout << n << " ";
        treeRecursion(n - 1);
        treeRecursion(n - 1);
    }
}

int main() {

    int n = 3;
    treeRecursion(n);

    cout << endl;
    n = 5;
    treeRecursion(n);


    return 0;
}