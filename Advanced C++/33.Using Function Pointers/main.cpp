#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Checks string size
bool match(string text){
    return text.size() == 3;
}

int countStrings(vector<string> &data, bool (*test)(string)){
    int tally = 0;
    for(int i=0; i<data.size(); i++){
        if(test(data[i])){
            tally++;
        }
    }
    return tally;
}

int main() {

    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("two");
    texts.push_back("one");


    cout << match("one") << endl;

    // How many strings in vector match length equal to 3
    cout << count_if(texts.begin(), texts.end(), match) << endl;

    cout << countStrings(texts, match) << endl;

    return 0;
}

/*
 * count_if -> From algorithm
 *
 */