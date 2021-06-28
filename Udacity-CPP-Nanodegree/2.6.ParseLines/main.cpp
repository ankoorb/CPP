#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void test();
vector<int> parseLine(string line);

int main() {

    test();
    return 0;
}


void test(){
    cout << "Test Parse Line" << endl;
    string line = "0,1,0,0,0,0,";
    vector<int> solution = {0,1,0,0,0,0};
    vector<int> parsed = parseLine(line);
    if (solution != parsed){
        cout << "Failed" << endl;
    } else {
        cout << "Passed" << endl;
    }
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