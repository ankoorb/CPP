#include <iostream>

using namespace std;

class Test {
    friend void display();
private:
    int a_ {20};
protected:
    int b_ {56};
public:
    int c_ {64};

};

void display() {
    Test test;
    cout << test.a_ << endl;
    cout << test.b_ << endl;
    cout << test.c_ << endl;
}

class Y;

class X {
    friend Y;
private:
    int x_ {15};
};

class Y {
public:
    X x_obj;
    void func(){
        x_obj.x_ = 7;
        cout << x_obj.x_ << endl;
    }

};

int main() {

    display();
    cout << endl;

    Y y_obj;
    y_obj.func();

    return 0;
}