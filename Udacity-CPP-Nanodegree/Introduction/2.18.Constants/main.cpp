#include <iostream>
#include <vector>

using namespace std;

int sum(const vector<int>& v){
    int total = 0;
    for (int i: v){
        total += i;
    }
    return total;
}

int main() {

    int i;
    cout << "Enter an integer value for i: " << flush;
    cin >> i;

    const int j = i * 2;
    constexpr int k = 3;

    cout << "j = " << j << endl;
    cout << "k = " << k << endl;

    // j++; // Error

    // constexpr int m = i * 2; // Error

    const int m = i * 2;
    cout << "m = " << m << endl;

    vector<int> v = {0, 1, 2, 3, 4};
    cout << sum(v) << endl;

    return 0;
}