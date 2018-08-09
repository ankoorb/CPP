//
// Created by Ankoor Bhagat on 8/3/18.
//

#ifndef INC_42_MAKING_CLASSES_ITERABLE_RING_H
#define INC_42_MAKING_CLASSES_ITERABLE_RING_H


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

    // Begin method
    iterator begin(){
        return iterator(0, *this);
    }

    // End method
    iterator end(){
        return iterator(m_size, *this);
    }
};

template <class T>
class ring<T>::iterator {
private:
    int m_position;
    ring &m_ring;

public:
    // Constructor
    iterator(int pos, ring &r_ring): m_position(pos), m_ring(r_ring){
    }

    // ++ operator overloading
    iterator &operator++(int){  // Postfix ++ takes int parameter
        iterator old = *this;
        ++(*this);
        return old;
    }

    iterator &operator++(){  // Prefix
        ++m_position;
        return *this;
    }

    // * operator overloading (used in *it when using for loop)
    T &operator*(){
        return m_ring.get(m_position);
    }

    // == operator overloading
    bool operator==(const iterator &other) const {
        return m_position == other.m_position;
    }

    // != operator overloading
    bool operator!=(const iterator &other) const {
        return !(*this == other);
    }
};



#endif //INC_42_MAKING_CLASSES_ITERABLE_RING_H
