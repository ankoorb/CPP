#include <iostream>
#include <cmath>

using namespace std;

void compute(double* sin_, double* cos_, double angle){
    *sin_ = sin(angle);
    *cos_ = cos(angle);
}

int main() {

    double _sin;
    double _cos;
    double angle;

    cout << "Input value for variable _sin: " << flush;
    cin >> _sin;

    cout << "Input value for variable _cos: " << flush;
    cin >> _cos;

    cout << "Input value for variable angle: " << flush;
    cin >> angle;

    compute(&_sin, &_cos, angle);
    cout << "Value of _sin: " << _sin << endl;
    cout << "Value of _cos: " << _cos << endl;

    return 0;
}