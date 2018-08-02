#include <iostream>
using namespace std;

void changeValue(double &value) {
    value = 3.14;
    cout << "changeValue value: " << value << endl;
}

int main() {

    int value1 = 8;
    int &value2 = value1;  // value2 is a reference value1, i.e. value2 is just another name for value1
    value2 = 10;

    cout << "Value1: " << value1 << endl;
    cout << "Value2: " << value2 << endl;

    int u = 7;
    int &v = u;
    v = 14;
    cout << "u: " << u << " v: " << v << endl;

    double value = 2.5;
    changeValue(value);
    cout << "Value: " << value << endl;
    value = 100;
    cout << "Value: " << value << endl;

    return 0;
}