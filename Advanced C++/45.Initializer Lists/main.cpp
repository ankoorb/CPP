#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

class Test {
public:
    Test(initializer_list<string> texts){
        // Accessing values from the list in constructor
        for(auto t: texts){ cout << t << endl; }
    }

    // Method that uses initializer list
    void print(initializer_list<string> texts){
        for(auto t: texts){ cout << t << endl; }
    }
};


int main() {

    vector<int> nums {1, 3, 5};
    cout << nums[2] << endl;

    Test test{"Apple", "Orange", "Mango"};
    cout << endl;

    test.print({"one", "two", "three"});

    return 0;
}

/*
 * #include <initializer_list> to use initializer_list which is a template type
 *
 * initializer_list is iterable using for loop
 *
 */