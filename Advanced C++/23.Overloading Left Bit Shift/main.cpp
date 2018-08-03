#include <iostream>
using namespace std;

class Test {
private:
    int id;
    string name;
public:
    Test(): id(0), name("") {}
    Test(int id, string name): id(id), name(name){}
    void print(){ cout << id << ": " << name << endl; }
    const Test &operator=(const Test &other) {
        id = other.id;
        name = other.name;
        return *this;
    }
    Test(const Test &other){ *this = other; }

    // Overloading left bit shift operator
    friend ostream &operator<<(ostream &out, const Test &test){
        out << test.id << ": " << test.name;
        return out;
    }

};

int main() {

    Test test1(6, "Crush");
    cout << test1 << endl;  // now works after operator overloading

    Test test2(1, "Kona");
    cout << test1 << " " << test2 << endl;


    //int value = 1 + (2 + 5);  // + operator has right-left associativity, i.e. first 2 + 5, then 1 + (7)

    return 0;
}

/*
 * Left bit shift operator
 *
 * Currently `cout << test1 << endl;` does not work. The first `<<` has 2 arguments: `cout` which is an
 * object of type `ostream` (output stream) and `test1` object. If you look at second `<<` your first
 * thought will be that it has 2 arguments `test1` object and `endl`, but in fact some operators in
 * C++ are right-left associative and others are left-right associative.
 *
 * `<<` operator has left-right associativity. So in `cout << test1 << endl;` first we are going to do
 * the left bit first i.e. `cout << test1`, then we are going to do `test1 << endl;` so we have left-right
 * associativity. In fact `cout << test1` returns an object which is a reference to an `ostream`, and then
 * second `<<` has 2 arguments: reference to an `ostream` and `endl`. So in both cases the first argument
 * the `<<` operator has is `ostream` object.
 *
 * Overloading left bit shift operator: Return type of function should be reference to an ostream
 *
 */