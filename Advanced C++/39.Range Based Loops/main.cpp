#include <iostream>
#include <vector>
using namespace std;

int main() {

    string texts[] = {"one", "two", "three"};

    for(auto text: texts){
        cout << text << endl;
    }

    vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(3);
    numbers.push_back(5);

    for(auto i: numbers){
        cout << i << endl;
    }

    string s = "hello!";
    for(auto c: s){ cout << c << endl; }

    return 0;
}

/*
 * Enhanced For Loop - It is a good time saver.
 *
 * Creating a string array - `string texts[] = {"one", "two"}`, using auto
 * `auto texts = {"one", "two"}`, so no need to use type declaration and []
 *
 * `auto i: array` - `auto` will give variable of right type. For loop will initialize the
 * variable and set the value of it to each of the values in array in turn.
 *
 */