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

// Function that takes Lvalue reference
void check(const Test &value){
    cout << "Lvalue function" << endl;
}

// Function that takes Rvalue reference
void check(Test &&value){  // Do not need const Rvalue references because
                            // they can change values and steal resources from
                            // objects you no longer need and they can only do that
                            // if they are not const
    cout << "Rvalue function" << endl;
}

int main() {

    Test test = getTest();

//    Test &lr_test = test;  // Lvalure reference pointing at an Lvalue
//    Test &&rr_test = Test();  // Rvalue reference pointing at an Rvalue
//    Test &&rvr_test = getTest();

    //Test &&rvr_test = lr_test;  // Can not bind Rvalue reference to Lvalue

    check(test);
    check(getTest());
    check(Test());

    return 0;
}

/*
 * Functions return temporary values. Use && to defile Rvalue reference.
 *
 * Rvalue references gives us a way to differentiate between temporary values and
 * non-temporary values or more precisely Rvalues and Lvalues.
 */































