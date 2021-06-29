#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void readBoardFile(string path);

int main() {

    ifstream in_file;
    in_file.open("../1.board");

    if (in_file){
        cout << "The file stream has been created!" << endl;

        string line;
        while (getline(in_file, line)){
            cout << line << endl;
        }
    }

    cout << "Reading Board File" << endl;
    string path = "../1.board";
    readBoardFile(path);

    return 0;
}

void readBoardFile(string path){
    ifstream in_file(path);

    if (in_file){
        string line;
        while (getline(in_file, line)){
            cout << line << endl;
        }
    }
}