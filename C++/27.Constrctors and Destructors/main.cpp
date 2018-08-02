#include <iostream>
#include "Dog.h"

using namespace std;

int main() {

    cout << "Starting program ..." << endl;

    // Instantiate a dog from Dog class. { and } used to de-allocate memory i.e. call Destructor.
    {
        Dog pluto;  // Constructor runs
        pluto.speak();
    }

    cout << "Ending Program ..." << endl;

    return 0;
}