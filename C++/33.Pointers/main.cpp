#include <iostream>
using namespace std;

void manipulate(double value) {
    cout << "2. value of double in manipulate: " << value << endl;
    value = 10;
    cout << "3. value of double in manipulate: " << value << endl;
}

void pmanipulate(double *pvalue) {  // Type of variable is "pointer to a double"
    cout << "2. value of double in manipulate: " << *pvalue << endl;
    *pvalue = 10;
    cout << "3. value of double in manipulate: " << *pvalue << endl;
}

int main() {

    int nValue = 7;

    int* pnValue = &nValue;

    cout << "nValue: " << nValue << endl;
    cout << "Address of nValue: " << &nValue << endl;
    cout << "Pointer to int address: " << pnValue << endl;
    cout << "int value via pointer: " << *pnValue << endl;

    cout << "=========================" << endl;
    double dValue = 123.4;
    cout << "1. dValue: " << dValue << endl;
    manipulate(dValue);
    cout << "4. dValue: " << dValue << endl;

    cout << "=========================" << endl;
    cout << "1. dValue: " << dValue << endl;
    pmanipulate(&dValue);
    cout << "4. dValue: " << dValue << endl;

    cout << "=========================" << endl;
    int v = 7;
    int *pv = &v;
    cout << pv << endl;
    cout << *pv << endl;
    cout << v << endl;

    *pv = 77;
    cout << pv << endl;
    cout << *pv << endl;
    cout << v << endl;

    string s = "S";
    string *ps = &s;
    cout << ps << endl;
    cout << *ps << endl;
    cout << s << endl;

    *ps = "A";
    cout << ps << endl;
    cout << *ps << endl;
    cout << s << endl;

    return 0;
}