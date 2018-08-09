#include <iostream>
#include <vector>
using namespace std;

class Test {
private:
    static const int SIZE = 100;  // Number of ints in a buffer
    int *m_pBuffer;
public:
    Test(){
        cout << "Constructor" << endl;
        m_pBuffer = new int [SIZE]{};  // Allocating memory
        //memset(m_pBuffer, 0, sizeof(int)*SIZE);

    }

    Test(int i){
        cout << "Parameterized Constructor" << endl;
        m_pBuffer = new int [SIZE]{};  // Allocating memory
        for(int i=0; i<SIZE; i++){
            m_pBuffer[i] = 7 * i;
        }
    }

    Test(const Test &other){
        cout << "Copy Constructor" << endl;

        // Allocate byte and copy the bytes from other object using memcopy
        m_pBuffer = new int [SIZE]{};  // Allocating memory
        memcpy(m_pBuffer, other.m_pBuffer, sizeof(int)*SIZE);  // Copy bytes from other

    }

    Test &operator=(const Test &other){
        cout << "Overridden assignment" << endl;
        m_pBuffer = new int [SIZE]{};  // Allocating memory
        memcpy(m_pBuffer, other.m_pBuffer, sizeof(int)*SIZE);  // Copy bytes from other
        return *this;
    }

    ~Test(){
        cout << "Destructor" << endl;
        delete [] m_pBuffer;
    }

    friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test){
    out << "Hello from test";
    return out;
}

// Function that returns object of type Test
Test getTest(){
    return Test();
}

int main() {

    Test test = getTest();  // getTest() output is an Rvalue
    cout << test << endl;

    vector<Test> vec;
    vec.push_back(Test());

    Test &lr_test = test;  // Lvalue reference
    //Test &rr_test = getTest();  // Error
    const Test &rr_test = getTest();
    cout << rr_test << endl;

    Test t(Test());  // Copy constructor



    return 0;
}


/*
 * The references in C++ 98 are called Lvalue references in C++ 11. Lvalue reference
 * is a normal kind of reference. We only can bind Lvalue references to Lvalues.
 * However `const` Lvalue references can bind to Rvalues, because lifetime of the
 * Rvalue gets extended beyond the lifetime it would normally have.
 *
 * The copy constructor always has a const Lvalue reference parameter to it.
 */






























