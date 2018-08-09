#include <iostream>
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
    Test *ptest = &test;
    // Test *pt = &getTest; // Error

    int value = 7;
    int *pvalue = &++value;
    cout << *pvalue << endl;

    //int *pValue = &value++;
    // Error because postfix operator needs to use the value and then increment it,
    // this creates a temporary copy of the value.
    cout << *pvalue << endl;

    //int *s = &(7 + value);  // (7 + value) becomes an Rvalue


    return 0;
}


/*
 * int u = 7 -> u is an Lvalue and 7 is an Rvalue, because u is on the left of = and 7
 * is on its right. C++ 11 extends the definition or changes the definition of Lvalues
 * and Rvalues.
 *
 * int *p = &u; -> This works because u is an Lvalue but int *pu = &7; -> does not
 * work because 7 is an Rvalue.
 *
 * Return values of a function are Rvalues, and Rvalues are often temporary values.
 *
 * Sometimes the distinction between Lvalues and Rvalues is confusing.
 *
 */