#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {

    Matrix A(3, 4, 7);
    Matrix B = A.Transpose();

    vector<int> vec(4, -5);
    vector<int> prod = A * vec; // Check for bug
    cout << A << endl;
    for_each(vec.begin(), vec.end(), [](const auto& v){ cout << v << endl; });

    Matrix I = Matrix::Identity(5, 5);

    Matrix K(3, 3, 1);
    Matrix IMG(10, 10, 1);

    Matrix F = Matrix::Conv(IMG, K);
    cout << F << endl;




    return 0;
}