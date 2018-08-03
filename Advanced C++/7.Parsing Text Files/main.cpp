#include <iostream>
#include <fstream>
using namespace std;

int main() {

    string inFileName = "/Users/ankoor/Desktop/Programming/C++/stats.txt";

    ifstream inFile;
    inFile.open(inFileName);

    if(!inFile.is_open()){
        return 1;
    }

    // Parse file
    while(inFile){  // or use !inFile.eof()
        string line;
        getline(inFile, line, ':');  // Get line from input into string up to delimiter ':', single quote because a single char

        int population;
        inFile >> population;

        // Discarding new line character
//        inFile.get();  // Older C++
        inFile >> ws;  // C++ 11 to remove white space

        cout << "'" << line << "'" << "->" << "'" << population << "'" << endl;
    }

    inFile.close();

    return 0;
}

/*
 * In C++ 11 -> Built-in Regular Expression libraries
 * C functions that can be used in C++
 */