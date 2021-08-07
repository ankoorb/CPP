#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {

    float pi = M_PI;
    float big_number = 1e7;
    cout << "PI before: " << pi << endl;

    pi += big_number;
    pi -= big_number;

    cout << "PI after: " << pi << endl;
    cout << "delta: " << M_PI - pi << endl;

    return 0;
}