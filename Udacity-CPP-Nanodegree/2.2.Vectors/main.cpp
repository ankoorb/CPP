#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> a = {0, 1, 2, 3, 4};

    cout << "a = [" << flush;
    for (size_t i = 0; i < a.size(); i++){
        cout << a[i] << ", " << flush;
    }
    cout << "]" << endl;

    vector<vector<int>> b = {{1, 1, 2, 3}, {2, 1, 2, 3}, {3, 1, 2, 3}};
    cout << "b = [" << endl;
    for (size_t i = 0; i < b.size(); i++){
        cout << "[" << flush;
        for (size_t j = 0; j < b[i].size(); j++){
            cout << b[i][j] << ", " << flush;
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;

    cout << "RANGE BASED FOR LOOP \n";
    cout << "b = [" << endl;
    for (auto v: b){
        cout << "[" << flush;
        for (auto i: v){
            cout << i << ", " << flush;
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;

    return 0;
}