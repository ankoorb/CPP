#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

// Function
bool check(string &s){
    return s.size() == 5;
}

// Functor
class Test {
public:
    bool operator()(string &t){
        return t.size() == 5;
    }
} t_obj;  // Pass t_obj to count_if


void run(function<bool(string&)> check){  // run can accept anything that is callable
    string t = "crush";
    cout << check(t) << endl;
}

int main() {

//    // Passing lambda expression to count_if
    int size = 5;
//    vector<string> texts{"one", "two", "three"};
//    long int c = count_if(texts.begin(), texts.end(),
//                          [size](string s){ return s.size() == size; });
//    cout << c << endl;
//
//    // Passing function pointer to count_if
//    c = count_if(texts.begin(), texts.end(), check);
//    cout << c << endl;
//
//    // Passing functor to count_if
//    c = count_if(texts.begin(), texts.end(), t_obj);
//    cout << c << endl;

    // Making a function that can accept anything callable
    auto lambda = [size](string s){ return s.size() == size; };
    run(lambda);
    run(check);  // Function pointer
    run(t_obj);  // Functor

    // Function - Handy way
    function<int(int, int)> add = [](int x, int y){ return x + y; };
    cout << add(7, 3) << endl;

    return 0;
}

/*
 * Standard Function Type - A nice convenience in C++ 11 that lets you define a type
 * equivalent to what it can be used to reference any callable type in C++ 11 (which
 * basically means anything you can call with round brackets)
 *
 * We can pass in anything that is callable to `count_if` - How does it do that? - It
 * uses standard function
 *
 * string s = "Crush"; s.size() returns size of a string.
 *
 * #include <functional> - Use `function<return_type(type&)> functionName in ()
 *
 */