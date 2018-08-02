#include <iostream>
using namespace std;

int main() {

    double value1 = (double)5/2;
    cout << value1 << endl;

    int value2 = 7.3;
    cout << value2 << endl;

    int value3 = 8;
    value3 += 1;  // value3 = value3 + 1 or value3++
    cout << value3 << endl;

    int value4 = 10;
    value4 /= 5;  // value4 = value4/5
    cout << value4 << endl;

    int value5 = 13 % 5;
    cout << value5 << endl;

    double equation = ((5/4)%2)+(2.3*6);
    cout << equation << endl;

    // Write a for loop that iterates 10000 times, output a dot (on the same line) every 100 iterations

    for(int i = 0; i < 10000; i++) {
        if(i%100 == 0){
            cout << "." << flush;
        }
        else {
            continue;
        }
    }


    return 0;
}


/*
 * 1. Take a large number of seconds and convert it to hours, minutes and seconds
 * 2. Write a for loop that iterates 10000 times, output a dot (on the same line) every 100 iterations
 */