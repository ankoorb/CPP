#include <iostream>

using namespace std;

int main() {

    int x = 100; // x is an l-value, 100 is an r-value, r-value assigned to l-value
    x = x + 20; // (x + 20) is an r-value

    string name = "Ankoor"; // name is an l-value, "Ankoor" is an r-value

    int max_num = max(20, 30); // max(20, 30) is an r-value

    int y = 15;
    int& y_ref = y; // y_ref is reference to l-value
    y_ref = 7;

    auto square = [](int& n){ return n * n; };
    cout << square(y_ref) << endl;

    return 0;
}
