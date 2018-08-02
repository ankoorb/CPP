#include <iostream>
using namespace std;

int main() {

    string texts[] = {"one", "two", "three"};
    cout << sizeof(texts)/sizeof(string) << endl;

    for(int i=0; i<sizeof(texts)/sizeof(string); i++){
        cout << texts[i] << " " << flush;
    }
    cout << endl;


    // Declare a pointer of type string
    string *ptexts = texts;  // Pointer pointing at start of the array (first element)

    for(int i=0; i<sizeof(texts)/sizeof(string); i++){
        cout << ptexts[i] << " " << flush;  // Used ptexts[i]
    }
    cout << endl;

    // De-referencing pointer to access elements
    for(int i=0; i<sizeof(texts)/sizeof(string); i++){
        cout << *ptexts << " " << flush;  // Used *ptexts
    }
    cout << " - Outputs first element only!" << endl;

    // Fixing the first element only output
    for(int i=0; i<sizeof(texts)/sizeof(string); i++){
        cout << *ptexts << " " << flush;  // Used *ptexts
        ptexts += 1;
    }

    cout << endl;

//    for(int i=0; i<sizeof(texts)/sizeof(string); i++, ptexts++){
//        cout << *ptexts << " " << flush;  // Used *ptexts
//    }

    cout << endl;

    string *pElement = texts;
    string *pEnd = &(texts[2]);

    while (true) {
        cout << *pElement << " " << flush;
        if (pElement == pEnd) {
            break;
        }
        pElement ++;
    }

    cout << endl;

    int i = 7;
    int *pi = &(i);
    cout << pi << " " << &i << " " << *pi << endl;

    int ia[] = {1, 2};
    cout << sizeof(int) << endl;
    cout << sizeof(ia) << endl;

    int *pia = ia;
    cout << pia << endl;
    cout << *pia << endl;

    float f = 3.14;
    cout << sizeof(float) << endl;
    cout << sizeof(f) << endl;

    float *pf = &f;
    cout << pf << endl;
    cout << *pf << endl;

    string s[] = {"a", "b"};
    cout << sizeof(string) << endl;
    cout << sizeof(s) << endl;

    string *ps = s;
    cout << ps << endl;  // 0x7fff5c7c7b00
    cout << *ps << endl;  // Prints "a" only!
    cout << ps[0] << ps[1] << ps[2] << endl;  // ab???...
    cout << *ps << endl;
    ps = ps + 1;
    cout << ps << endl;  // 0x7fff5c7c7b18
    cout << *ps << endl;

    return 0;
}