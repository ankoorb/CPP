#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> parseLine(string line);
vector<vector<int>> readBoardFile(string path);
void printBoard(const vector<vector<int>> board);


int main() {

    string path = "../1.board";
    vector<vector<int>> board = readBoardFile(path);
    printBoard(board);

    return 0;
}

vector<int> parseLine(string line){
    int n;
    char c;
    istringstream l_stram(line);
    vector<int> output;

    while (l_stram >> n >> c){
        output.emplace_back(n);
    }

    return output;
}

vector<vector<int>> readBoardFile(string path){

    ifstream in_file(path);
    vector<vector<int>> board;

    if (in_file){
        string line;
        while (getline(in_file, line)){
            board.emplace_back(parseLine(line));
        }
    }

    return board;
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

