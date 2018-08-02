#include <iostream>
#include "Dog.h"

using namespace std;

int main() {

    Dog crush;
    crush.make_sad();
    crush.speak();
    crush.make_happy();
    crush.speak();

    Dog lucy;
    lucy.make_happy();
    lucy.speak();

    return 0;
}