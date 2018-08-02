#include <iostream>
using namespace std;

/*
 * == equality test
 * != not equal test
 * < less than test
 * > greater than test
 * <= less than or equal to
 * >= greater than or equal to
 */

int main() {

    int value1 = 7;
    int value2 = 4;

    if(value1 >= 5) {
        cout << "Condition 1: true" << endl;
    } else {
        cout << "Condition 1: false" << endl;
    }

    // AND example
    if(value1 == 7 && value2 < 3) {
        cout << "Condition 2: true" << endl;
    } else {
        cout << "Condition 2: false" << endl;
    }

    // OR example
    if(value1 == 7 || value2 < 3) {
        cout << "Condition 3: true" << endl;
    } else {
        cout << "Condition 3: false" << endl;
    }

    // Complex condition
    if((value1 != 8 && value1 == 10) || value2 < 10) {
        cout << "Condition 4: true" << endl;
    } else {
        cout << "Condition 4: false" << endl;
    }

    bool condition = (value1 != 8 || value2 == 10) and value1 < 10;
    if(condition) {
        cout << "Condition 5: true" << endl;
    } else {
        cout << "Condition 5: true" << endl;
    }

    return 0;
}