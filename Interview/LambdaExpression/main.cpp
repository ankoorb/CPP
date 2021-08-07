#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    vector<int> v = {1, 2, 3, 4, 5};
    for_each(v.begin(), v.end(), [](const int& i){ cout << i << " ";});
    cout << endl;

    transform(v.begin(), v.end(), v.begin(), [](int& i){ return i * 10; });
    for_each(v.begin(), v.end(), [](const int& i){ cout << i << " ";});
    cout << endl;

    vector<string> s = {"Ferrari", "Renault", "Lotus", "Mercedez"};
    for_each(s.begin(), s.end(), [](const string& e){ cout << e << " ";});
    cout << endl;

    return 0;
}