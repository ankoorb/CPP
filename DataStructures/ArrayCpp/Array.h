//
// Created by Ankoor Bhagat on 8/13/19.
//

#ifndef ARRAYCPP_ARRAY_H
#define ARRAYCPP_ARRAY_H


class Array {

private:
    int* A;
    int size;
    int length;
    void swap(int* x, int* y);

public:
    // Constructor and Destructor
    Array();
    Array(int sz);
    ~Array();

    // Methods
    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    int LinearSearch(int key, bool toHead=false);
    int BinarySearch(int key);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    double Avg();
    void Reverse();
    void AuxiliaryReverse();
    void LeftRotate();
    void insertInSorted(int x);
    bool isSorted();
    void NegPosRearrange();
    int RecursiveBinarySearch(int l, int h, int key);
    Array* Merge(Array B);
    Array* Union(Array B);
    Array* Intersection(Array B);
    Array* Difference(Array B);
};


#endif //ARRAYCPP_ARRAY_H
