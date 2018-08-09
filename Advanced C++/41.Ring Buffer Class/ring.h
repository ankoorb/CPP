//
// Created by Ankoor Bhagat on 8/2/18.
//

#ifndef INC_41_RING_BUFFER_CLASS_RING_H
#define INC_41_RING_BUFFER_CLASS_RING_H

#include <iostream>
using namespace std;

template <class T>
class ring {
private:
    int m_position;
    int m_size;
    T *m_values;

public:
    class iterator;

public:

    // Constructor that takes in size
    ring(int size): m_position(0), m_size(size), m_values(NULL){
        m_values = new T[m_size];
    }

    // Delete memory
    ~ring(){
        delete [] m_values;
    }

    // Method to return size
    int size(){ return m_size; }

    // Method to add data to buffer
    void add(T value){
        m_values[m_position] = value;  // Add value

        // Increment buffer
        m_position ++;

        if(m_position == m_size){
            m_position = 0;
        }
    }

    // Get method
    T &get(int pos){  // Return a reference of type T
        return m_values[pos];
    }

};

template <class T>
class ring<T>::iterator {};

#endif //INC_41_RING_BUFFER_CLASS_RING_H
