#include <iostream>
using namespace std;

// .h header file
class Test {
public:
    // Initialization of const must be done right here
    static int const MAX = 1000;
    int id;
private:
    static int count;  // static variable
public:
    Test() { id = ++count; }
    static void info() {  // static method
        cout << count << endl;
    }
    int getID() {
        return id;
    }
};

// .cpp source
int Test::count = 0;
// no need to do this initialization for static constants

int main() {

    Test::info();
    //cout << Test::MAX << endl;

    Test test1;
    cout << "Object-1 ID: " << test1.getID() << endl;
    Test::info();
    Test test2;
    Test::info();
    cout << "Object-2 ID: " << test2.getID() << endl;



    return 0;
}