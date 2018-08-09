#include <iostream>
#include "ring.h"
using namespace std;

int main() {

    ring<string> texts(3);

    texts.add("one");
    texts.add("two");
    texts.add("three");
    texts.add("four");

    for(int i=0; i<texts.size(); i++){
        cout << texts.get(i) << endl;
    }

    return 0;
}