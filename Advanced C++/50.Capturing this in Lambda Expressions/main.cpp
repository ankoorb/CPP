#include <iostream>
using namespace std;

class Test {
private:
    int u{1};
    int v{2};
public:
    void run(){
        // Local variables x and y
        int x{6};
        int y{7};

        auto lambda = [this, x, y](){
            cout << x << " and " << y << endl;
            this->u = 15; v = 7;
            cout << u << " and " << v << endl;
        };
        lambda();
    }
};

int main() {

    Test t;
    t.run();

    return 0;
}

/*
 * capturing `this` in lambda expressions.
 *
 *
 * We can not capture u and v in lambda expression because of error: 'this' cannot
 * be implicitly captured in this context so capture `this` in capture brackets, and
 * `this` can be first or last or anywhere.
 *
 * NOTE [=, this] is not allowed because of error. But [&, this] is allowed.
 *
 * Using `this` to capture instance variables - The instance variables are captured
 * by reference.
 *
 */

//auto lambda = [x, y](){
//    cout << x << " and " << y << endl;
//    cout << u << " and " << v << endl; // Can not capture instance variables as error is raised
//};