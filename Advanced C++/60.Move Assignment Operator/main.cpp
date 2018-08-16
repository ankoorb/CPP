#include <iostream>
#include <vector>
using namespace std;

class Test {
private:
    static const int SIZE = 100;
    int *m_pBuffer{nullptr};
public:
    Test(){ m_pBuffer = new int [SIZE]{}; }

    Test(int i){
        m_pBuffer = new int [SIZE]{};  // Allocating memory
        for(int i=0; i<SIZE; i++){
            m_pBuffer[i] = 7 * i;
        }
    }

    Test(const Test &other){
        // Allocate byte and copy the bytes from other object using memcopy
        m_pBuffer = new int [SIZE]{};  // Allocating memory
        memcpy(m_pBuffer, other.m_pBuffer, sizeof(int)*SIZE);  // Copy bytes from other

    }

    Test &operator=(const Test &other){
        m_pBuffer = new int [SIZE]{};  // Allocating memory
        memcpy(m_pBuffer, other.m_pBuffer, sizeof(int)*SIZE);  // Copy bytes from other
        return *this;
    }

    // Move Constructor: Initialize m_pBuffer with a nullptr
    Test(Test &&other){
        cout << "Move Constructor" << endl;
        m_pBuffer = other.m_pBuffer;
        other.m_pBuffer = nullptr;
    }

    // Move Assignment Operator
    Test &operator=(Test &&other){

        cout << "Move Assignment" << endl;
        // This object which we are assigning to will have already allocated memory
        // so we need to free up any memory that has been allocated
        delete [] m_pBuffer;
        m_pBuffer = other.m_pBuffer;
        other.m_pBuffer = nullptr;

        return *this;
    }

    ~Test(){
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

    Test test;
    test = getTest();

    return 0;
}

/*
 * It is safe to delete a `nullptr`, as long as you are initializing your pointer
 * to `nullptr` in C++ 11.
 *
 * Move Assignment Operator - It looks a lot like normal assignment operator.
 *
 */































