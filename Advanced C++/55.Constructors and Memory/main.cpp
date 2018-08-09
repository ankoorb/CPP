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

    Test t;
    cout << t << endl;

    return 0;
}

/*
 * Allocating Memory in a class (Tips and Tricks)
 *
 * There are 3 efficient ways to set memory to 0 (Common thing that you want to do if
 * you create a buffer is that to set all the bytes in the buffer to zero, this tend
 * to help you reduce bugs, because then you know that buffer should be zero until you
 * have written to it) - (1) Using `memset`, however people say it is prone to cause
 * bugs, (2) Use () in `m_pBuffer = new int [SIZE]()`, (3) Use {} in `m_pBuffer = new int [SIZE]{}`
 *
 * Use `memcpy` to copy bytes from one to another.
 *
 * There are tools that can detect memory leaks. Memory leaks are often hard to spot.
 */