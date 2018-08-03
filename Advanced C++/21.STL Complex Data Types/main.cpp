#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {

    // Map of vectors
    map<string, vector<int>> scores;

    scores["Crush"].push_back(10);
    scores["Crush"].push_back(20);

    scores["Kona"].push_back(15);
    scores["Kona"].push_back(25);

    for(map<string, vector<int>>::iterator it = scores.begin(); it != scores.end(); it++){
        string name = it->first;
        vector<int> scoreList = it->second;
        cout << name << ": " << flush;
        for(int i=0; i<scoreList.size(); i++){
            cout << scoreList[i] << " " << flush;
        }
        cout << endl;
    }
    return 0;
}

/*
 * Complex nested data types -> Nested STL Types to represent any data structure.
 *
 * vector of maps/map of vectors/vector of maps of vector
 *
 * vector of maps -> It is better to use vector of data type you created (e.g. class)
 *
 */