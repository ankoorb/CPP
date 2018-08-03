#include <iostream>
#include <exception>
using namespace std;

void goWrong(){
    bool error1Detected = true;
    bool error2Detected = false;

    if(error1Detected) {
        throw bad_alloc();
    }

    if(error2Detected) {
        throw exception();
    }
}

int main() {

    try {
        goWrong();
    }

    catch(exception &e) {  // this will accept bad_alloc because
        // bad_alloc is subclass of exception (polymorphism)
        cout << "Catching exception: " << e.what() << endl;
    }
    catch(bad_alloc &e) {
        cout << "Catching bad_alloc: " << e.what() << endl;
    }
    catch(exception &e) {  // this will accept bad_alloc because
        // bad_alloc is subclass of exception (polymorphism)
        cout << "Catching exception: " << e.what() << endl;
    }

    return 0;
}

// Before commenting out second - Catching exception: std::bad_alloc -> this is wrong
// Catch exception with subclasses before parent classes
// After commenting out first - Catching bad_alloc: std::bad_alloc