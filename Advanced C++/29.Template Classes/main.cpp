#include <iostream>
using namespace std;


template<class T, class K>
class Test {
private:
    T obj;  // Variable of type T which will be defined by user
    K val;  // Variable of type K which will be defined by user

public:
    Test(T obj, K val): obj(obj), val(val) {}//{ this->obj = obj; this->val = val; }

    void print() {
        cout << obj << " and " << val << endl;
    }
};

int main() {

    Test<string, int> test("Hello", 7);
    test.print();

    return 0;
}





/*
 * Template Classes - Allows to design classes that work with types of variables that the user
 * can specify. E.g `vector`, where user has to specify the type. `vector` is a template class
 * and that is why it member of STL. Template classes are not often useful in C++, but when
 * they are useful they can be very useful.
 *
 * Use `template<class T>` just above the class to turn class into a template class, T is the
 * letter stand for the type that the user can specify, T can be any word like Thing, but it
 * is common to use single letter for the purpose as the user has to specify the type. T is
 * traditional letter to use for a generic template type. Then T can be used in the class.
 *
 * If you define a template type you really should not get into inquiring what type it is and
 * calling specific methods on it because it kind of breaks the whole object oriented idea of
 * defining objects in such a way that you can use them without interrogating the object type
 * so it is not good to have `if` statements i.e. if object type is string do this, if object
 * type is int do that.
 *
 * `template<class T, class K>` - Used to define multiple template types
 *
 */