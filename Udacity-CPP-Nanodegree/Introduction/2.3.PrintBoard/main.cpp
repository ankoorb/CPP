#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<int>> board);

int main() {
    vector<vector<int>> board{{0, 1, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0},
                              {0, 0, 0, 0, 1, 0}};

    printBoard(board);

    return 0;
}

void printBoard(const vector<vector<int>> board){
    for (auto row: board){
        cout << "[" << flush;
        for (auto v: row){
            cout << v << ", " << flush;
        }
        cout << "]" << endl;
    }
}