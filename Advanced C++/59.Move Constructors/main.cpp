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
    Test(Test &&other){  // Move constructor has to take a mutable Rvalue reference.
                         // It can not be const as it has to change other.
        cout << "Move Constructor" << endl;
        m_pBuffer = other.m_pBuffer;
        other.m_pBuffer = nullptr;
        // Problem is that destructor of other will de-allocate that buffer and we
        // have stolen that buffer
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

    vector<Test> vec;
    vec.push_back(Test());

    return 0;
}

/*
 * Move Constructor looks a lot like a copy constructor except is uses Rvalue references.
 *
 * In this example: In Move Constructor we do not have to allocate any more memory, but
 * in Copy Constructor we have to allocate memory so Move Constructor is very efficient.
 *
 */































