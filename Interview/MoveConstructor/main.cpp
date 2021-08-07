#include <iostream>
#include <vector>
using namespace std;

void LIncrement(int& x){
    x++;
}

void RIncrement(int&& x){
    x++;
    cout << x << endl;
}


class Move {
public:
    Move(int data);
    Move(const Move& other);

    // Move Constructor: Do not use const
    Move(Move&& other);

    ~Move();
    int GetData() const { return *data_; }
    void SetData(int data) { *data_ = data; }

private:
    int* data_;
};

Move::Move(int data) {
    data_ = new int;
    *data_ = data;
}

Move::Move(const Move &other) {
    data_ = new int;
    *data_ = *other.data_;
    cout << "Copy Constructor: " << *data_ << endl;
}

Move::Move(Move &&other) {
    data_ = other.data_;
    other.data_ = nullptr;
    cout << "Move Constructor: " << *data_ << endl;
}

Move::~Move() {
    if (data_ != nullptr){
        cout << "Freeing data: " << data_ << endl;
    } else {
        cout << "Freeing data: nullptr" << endl;
    }
    delete data_;
}


int main() {

    // L-value reference

    int x = 7;
    int& l_ref = x;  // L-value reference
    l_ref = 15;
    cout << x << endl;

    int y = 999;
    LIncrement(y);
    cout << y << endl;

    //LIncrement(15); // Error because 15 is R-value

    // Move semantics is all about R-value reference

    int&& r_ref = 100; // 200 is R-value and r_ref is R-value reference
    r_ref = -100;
    cout << r_ref << endl;

    RIncrement(9999);

    // Inefficient copying
    cout << "\nInefficient copying\n" << endl;
    vector<Move> vec;
    //vec.emplace_back(Move(10));  // Move(10) is creating temp objects i.e. R-value
    //vec.emplace_back(Move(20));  // Deep copying is being done here to emplace_back in vec
    // Copy constructors will be called to copy the temp objects

    // Move constructor
    cout << "\nEfficient moving\n" << endl;
    vec.emplace_back(Move(10));
    vec.emplace_back(Move(20));
    // Move constructors will be called for the temp R-values


    return 0;
}
