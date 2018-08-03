#include <iostream>
using namespace std;

void goWrong() {

    bool error = true;

    if(error){
        //throw 8;
        //throw "Something went wrong!";
        throw string("Something went wrong!");  // Creates an object
    }
}

int main() {

    try {
        goWrong();
    }

    catch(int e) {
        cout << "Error code: " << e << endl;
    }

    catch(char const* e) {
        cout << "Error message: " << e << endl;
    }

    catch(string e) {  // Catching object with reference
        cout << "String error message: " << e << endl;
    }

    int u = 9;
    int &v = u;

    cout << u << endl;
    cout << &v << endl;


    return 0;
}

// "This is primitive string."
// string("This is non primitive string.") because string is a class in iostream