#include <iostream>
using namespace std;

template<class T, class K>
class Test {
private:
    T obj;

public:
    Test(T obj){
        this->obj = obj;
    }

    void print(){
        cout << obj << endl;
    }
};

int main() {

    Test<string, int> test("Hello");
    test.print();

    return 0;
}

/*
 * One important thing about template classes is that it is not so easy to separate the
 * implementation from the actual class.
 *
 * With templates, C++ has to see both the implementation (.cpp) and the definition (.h) all
 * together before it can compile the code (without templates C++ has to see the definition
 * (.h) file to compile the code) because behind the scenes C++ is going to create the class
 *
 * For Template class - It is better generally to put implementation and definition in *.h file
 *
 *
 */