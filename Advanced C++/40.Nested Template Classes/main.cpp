#include <iostream>
#include "ring.h"
using namespace std;

int main() {

    ring<string>::iterator it;
    it.print();

//    ring<string> texts(3);  // Max 3 strings in buffer
//    texts.add("one");
//    texts.add("two");
//    texts.add("three");
//    texts.add("four");  // This should over write "one"
//
//    for(int i=0; i<texts.size(); i++){
//        cout << texts.get(i) << endl;
//    }

    return 0;
}

/*
 * Implementing Ring Buffer Class - A ring buffer or a circular buffer is some kind of area
 * of memory which you can write to when you get to the end of it, if you keep writing it
 * starts writing to the beginning. This is often used in multimedia applications because
 * you can write to the buffer and you can read just a bit ahead of it. And when you run
 * out of memory instead of stopping the read and write it just cycles on around the same
 * bit of memory. Nested template classes are needed to implement iterator syntax for
 * ring buffer class.
 *
 * Because we are implementing a template class so need to put declaration and implementation
 * of template class in `.h` file (`.cpp` is deleted)
 *
 *
 *
 *
 */

//class ring {
//public:
//    class iterator {
//    public:
//        void print(){ cout << "Hello from iterator!" << endl; }
//    };
//};

/*
 * The above syntax is widely used but in general this is not a good practice because the
 * nesting level is going to get deep and will look confusing. So good practice is to take
 * implementation outside of the class.
 *
 * But with template classes separating out implementations is tricky and involves hacks.
 *
 *
 *
 */