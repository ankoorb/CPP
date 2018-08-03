#include <iostream>
using namespace std;

class CanGoWrong {
public:
    CanGoWrong() {
        char *pMemory = new char[999999999999998];  // Allocating some memory
        delete [] pMemory;
    }
};

int main() {

    //CanGoWrong wrong;  // Error output -> std::bad_alloc

    try {
        CanGoWrong wrong;
    }
    catch(bad_alloc &e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    cout << "Still running!" << endl;

    // Check out Standard Exception reference: http://www.cplusplus.com/reference/exception/exception/?kw=exception

    return 0;
}