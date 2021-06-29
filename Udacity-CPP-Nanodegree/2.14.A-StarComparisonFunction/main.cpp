#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

enum class State {
    kEmpty,
    kObstacle,
    kClosed
};

string cellString(State cell);
vector<State> parseLine(string line);
vector<vector<State>> readBoardFile(string path);
void printBoard(const vector<vector<State>> board);
vector<vector<State>> Search(vector<vector<State>> board, int init[2], int goal[2]);
int heuristic(int x1, int y1, int x2, int y2);
void addToOpen(int x, int y, int g, int h, vector<vector<int>>& open_node, vector<vector<State>>& grid);
bool compare(const vector<int>& a, const vector<int>& b);



int main() {

    string path = "../1.board";
    vector<vector<State>> board = readBoardFile(path);

    int init[2] = {0, 0};
    int goal[2] = {4, 5};

    vector<vector<State>> solution = Search(board, init, goal);

    printBoard(solution);


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
        for (auto v: row){
            cout << cellString(v) << flush;
        }
        cout <<  endl;
    }
}

string cellString(State cell){
    switch (cell){
        case State::kObstacle:
            return "⛰️  ";
        default:
            return "0   ";
    }
}

vector<vector<State>> Search(vector<vector<State>> board, int init[2], int goal[2]){

    vector<vector<int>> open;

    int x = init[0];
    int y = init[1];
    int g = 0;
    int h = heuristic(x, y, goal[0], goal[1]);

    addToOpen(x, y, g, h, open, board);

    return vector<vector<State>>{};
}

int heuristic(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

void addToOpen(int x, int y, int g, int h, vector<vector<int>>& open_node, vector<vector<State>>& grid){
    vector<int> node = {x, y, g, h};
    open_node.emplace_back(node);
    grid[x][y] = State::kClosed;
}

bool compare(const vector<int>& a, const vector<int>& b){
    int af = a[2] + a[3];
    int bf = b[2] + b[3];
    return af > bf;
}
