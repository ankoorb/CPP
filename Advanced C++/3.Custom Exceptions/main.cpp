#include <iostream>
#include <exception>
using namespace std;

class CustomException: public exception {  // Inherit from exception class
public:
    /* Overriding what() method in exception class. Method name is shown
     * here: http://www.cplusplus.com/reference/exception/exception/?kw=exception
     * const throw () means method can not throw an exception, and this allows
     * compiler to optimize code, but disadvantages outweigh advantages so it is
     * better to not use const throw () in virtual const char* what() const throw()
     */

    virtual const char* what() const throw() {
        return "Something bad happened!";
    };
};

class Test {
public:
    void goWrong() {
        throw CustomException();
    }
};

int main() {

    Test test;

    try {
        test.goWrong();
    }
    catch(CustomException &e) {  // Catching reference to CustomException
        cout << e.what() << endl;
    }

    return 0;
}