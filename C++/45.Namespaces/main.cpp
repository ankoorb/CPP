#include "Dog.h"
#include "Animal.h"

using namespace dog;
using namespace canine;


int main() {

    dog::Dog pluto;
    pluto.speak();

    canine::Dog crush;
    crush.speak();

    cout << dog::NAME << endl;
    cout << canine::NAME << endl;

    return 0;
}