#include <iostream>

using namespace std;

int main() {

    int i = 1;

    int& j = i;
    cout << "The value of j is: " << j << endl;

    i = 5;
    cout << "The value of i is changed to: " << i << endl;
    cout << "The value of j is now: " << j << endl;

    j = 7;
    cout << "The value of j is now: " << j << endl;
    cout << "The value of i is changed to: " << i << endl;


    return 0;
}