#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

enum class State {
    kEmpty,
    kObstacle,
    kClosed,
    kPath,
    kStart,
    kFinish
};

string cellString(State cell);
vector<State> parseLine(string line);
vector<vector<State>> readBoardFile(string path);
void printBoard(const vector<vector<State>> board);
vector<vector<State>> Search(vector<vector<State>> board, int init[2], int goal[2]);
int heuristic(int x1, int y1, int x2, int y2);
void addToOpen(int x, int y, int g, int h, vector<vector<int>>& open_node, vector<vector<State>>& grid);
bool compare(const vector<int>& a, const vector<int>& b);
void cellSort(vector<vector<int>>* v);
bool checkValidCell(int x, int y, vector<vector<State>>& grid);
void expandNeighbors(vector<int>& current, vector<vector<int>>& open, vector<vector<State>>& grid, int goal[2]);



int main() {

    string path = "../1.board";
    vector<vector<State>> board = readBoardFile(path);

    int init[2] = {0, 0};
    int goal[2] = {4, 5};

    vector<vector<State>> solution = Search(board, init, goal);

    printBoard(solution);
    cout << endl;


    path = "../2.board";
    int dest[2] = {16, 23};
    board = readBoardFile(path);
    solution = Search(board, init, dest);
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
        case State::kPath:
            return "🚗  ";
        case State::kStart:
            return "🚦  ";
        case State::kFinish:
            return "🏁  ";
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

    while (open.size() > 0){
        cellSort(&open);
        auto current = open.back();
        open.pop_back();
        x = current[0];
        y = current[1];
        board[x][y] = State::kPath;

        if (x == goal[0] && y == goal[1]){
            board[init[0]][init[1]] = State::kStart;
            board[goal[0]][goal[1]] = State::kFinish;
            return board;
        }

        expandNeighbors(current, open, board, goal);
    }

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

void cellSort(vector<vector<int>>* v){
    sort(v->begin(), v->end(), compare);
}

bool checkValidCell(int x, int y, vector<vector<State>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == State::kEmpty){
        return true;
    }
    return false;
}

void expandNeighbors(vector<int>& current, vector<vector<int>>& open, vector<vector<State>>& grid, int goal[2]){
    int x = current[0];
    int y = current[1];
    int g = current[2];

    const vector<vector<int>> deltas = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    for (auto delta: deltas){
        int xx = x + delta[0];
        int yy = y + delta[1];
        if (checkValidCell(xx, yy, grid)){
            int gg = g + 1;
            int hh = heuristic(xx, yy, goal[0], goal[1]);
            addToOpen(xx, yy, gg, hh, open, grid);
        }
    }
}