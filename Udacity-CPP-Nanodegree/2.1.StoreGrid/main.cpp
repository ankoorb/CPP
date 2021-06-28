#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> board = {{0, 1, 0, 0, 0, 0},
                                 {0, 1, 0, 0, 0, 0},
                                 {0, 1, 0, 0, 0, 0},
                                 {0, 1, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 1, 0}};

    cout << "Grid Stored\n" << endl;

    for (auto row: board){
        for (auto i=0; i<row.size(); i++){
            cout << row[i] << ", " << flush;
        }
        cout << endl;
    }

    return 0;
}