#include <iostream>
using namespace std;

class Parent {
public:
    virtual void speak(){ cout << "Parent" << endl; }
};

class Son: public Parent {

};

class Daughter: public Parent {

};

int main() {

    Parent parent;
    Son son;
    Daughter daughter;

    Parent *pps = &son;
    //Daughter *pds = dynamic_cast<Daughter *>(pps);  // dynamic_cast returns nullptr
    //Daughter *pds = static_cast<Daughter *>(pps);  // Works and unsafe
    Daughter *pds = reinterpret_cast<Daughter *>(pps);
    if(pds == nullptr){
        cout << "Invalid cast" << endl;
    } else {
        cout << pds << endl;
    }

    return 0;
}

/*
 * `reinterpret_cast` - It has even less checking that `static_cast`. If some situation
 * arises where you genuinely need to cast what appears to be one type of pointer to a
 * completely different type, and static_cast and dynamic_cast would not do it for
 * some reason then use `reinterpret_cast`, but generally it is best to avoid
 * `reinterpret_cast`
 */

