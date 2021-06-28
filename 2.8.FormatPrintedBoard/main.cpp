#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

enum class State {
    kEmpty,
    kObstacle
};

string cellString(State cell);
vector<State> parseLine(string line);
vector<vector<State>> readBoardFile(string path);
void printBoard(const vector<vector<State>> board);


int main() {

    string path = "../1.board";
    vector<vector<State>> board = readBoardFile(path);
    printBoard(board);

    return 0;
}

vector<State> parseLine(string line){
    int n;
    char c;
    istringstream l_stream(line);
    vector<State> output;

    while (l_stream >> n >> c && c == ','){
        output.emplace_back(n == 0 ? State::kEmpty : State::kObstacle);
    }

    return output;
}

vector<vector<State>> readBoardFile(string path){

    ifstream in_file(path);
    vector<vector<State>> board;

    if (in_file){
        string line;
        while (getline(in_file, line)){
            board.emplace_back(parseLine(line));
        }
    }

    return board;
}

void printBoard(const vector<vector<State>> board){
    for (auto row: board){
        cout << "[" << flush;
        for (auto v: row){
            cout << cellString(v) << ", " << flush;
        }
        cout << "]" << endl;
    }
}

string cellString(State cell){
    switch (cell){
        case State::kObstacle:
            return "⛰️  ";
        default:
            return "0  ";
    }
}

