#include <iostream>
#include "ring.h"

int main() {

    ring<string> texts(3);

    texts.add("one");
    texts.add("two");
    texts.add(("three"));
    texts.add("four");

    // C++ 98 style
    for(ring<string>::iterator it = texts.begin(); it !=
            texts.end(); it++){
        cout << *it << endl;
    }

    cout << endl;

    // C++ 11 style
    for(auto text: texts){
        cout << text << endl;
    }

    return 0;
}