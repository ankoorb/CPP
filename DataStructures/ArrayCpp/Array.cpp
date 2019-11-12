//
// Created by Ankoor Bhagat on 8/13/19.
//
#include <iostream>
#include "Array.h"
using namespace std;

Array::Array() {
    size = 10;
    length = 0;
    A = new int [size];
}

Array::Array(int sz) {
    size = sz;
    length = 0;
    A = new int [size];
}

Array::~Array() {
    delete[] A;
}

void Array::swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Array::Display() {
    for (int i = 0; i < length; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int Array::Get(int index) {
    if (index >= 0 && index < length){
        return A[index];
    }
}

void Array::Set(int index, int x) {
    if (index >= 0 && index < length){
        A[index] = x;
    }
}

int Array::Max() {
    int max = 0;
    for (int i = 0; i < length; i++){
        if (A[i] > max){
            max = A[i];
        }
    }
    return max;
}

int Array::Min() {
    int min = 0;
    for (int i = 0; i < length; i++){
        if (A[i] < min){
            min = A[i];
        }
    }
    return min;
}

int Array::Sum() {
    int s = 0;
    for (int i=0; i < length; i++){
        s += A[i];
    }
    return s;
}

double Array::Avg() {
    double s = 0;
    for (int i=0; i < length; i++){
        s += A[i];
    }
    return s/length;
}

void Array::Append(int x) {
    if (length < size){
        A[length] = x;
        length++;
    }
}

void Array::Insert(int index, int x) {
    if (index >= 0 && index <= length){
        for (int i = length; i > index; i--){
            A[i] = A[i-1];
        }
        A[index] = x;
        length++;
    }
}

void Array::AuxiliaryReverse() {
    int* B = new int [length];  // Length is # of elements

    for (int i = length - 1, j = 0; i >= 0; i--, j++){
        B[j] = A[i];
    }

    for (int i = 0; i < length; i++){
        A[i] = B[i];
    }

    delete[] B;
    B = nullptr;
}

void Array::Reverse() {
    for (int i = 0, j = length - 1; i < j; i++, j--){
        swap(&A[i], &A[j]);
    }
}

void Array::LeftRotate() {
    int temp = A[0];
    for (int i = 0; i < length; i++){
        A[i] = A[i+1];
    }
    A[length-1] = temp;
}

void Array::insertInSorted(int x) {
    // If length = size then there is no space to add element
    if (length == size){
        return;
    }

    int i = length - 1;
    while (i >= 0 && A[i] > x){
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length++;
}

bool Array::isSorted() {
    for (int i = 0; i < length - 1; i++){
        if (A[i] > A[i+1]){
            return false;
        }
    }
    return true;
}

void Array::NegPosRearrange() {
    int i = 0;
    int j = length - 1;
    while (i < j){
        while (A[i] < 0){
            i++;
        }
        while (A[j] >= 0){
            j--;
        }
        if (i < j){
            swap(&A[i], &A[j]);
        }
    }
}

int Array::LinearSearch(int key, bool toHead) {
    for (int i=0; i < length; i++){
        if (A[i] == key){
            if (toHead){
                swap(&A[i], &A[0]);  // Move to Head
            } else {
                swap(&A[i], &A[i-1]);  // Transposition
            }

            return i;
        }
    }
    return -1;
}

int Array::BinarySearch(int key) {
    int l = 0;
    int h = length - 1;
    int mid;
    while (l <= h){
        mid = l + (h - l)/2;
        if (key == A[mid]){
            return mid;
        } else if (key < A[mid]){
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int Array::RecursiveBinarySearch(int l, int h, int key) {
    int mid;
    if (l <= h){
        mid = l + (h - l)/2;
        if (key == A[mid]) {
            return mid;
        } else if (key < A[mid]){
            return RecursiveBinarySearch(l, mid-1, key);
        } else {
            return RecursiveBinarySearch(mid+1, h, key);
        }
    }
    return -1;
}

int Array::Delete(int index) {
    if (index >= 0 && index <= length){
        int x = A[index];
        for (int i = index; i < length-1; i++){
            A[i] = A[i+1];
        }
        length--;
        return x;
    }
}

Array* Array::Merge(Array B) {
    Array* C = new Array(length + B.length);
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < length && j < B.length){
        if (A[i] < B.Get(j)){
            C->Set(k++, A[i++]);
        } else {
            C->Set(k++, B.Get(j++));
        }
    }
    for (; i < length; i++){
        C->Set(k++, A[i]);
    }
    for (; j < B.length; j++){
        C->Set(k++, B.Get(j));
    }
    return C;
}

Array* Array::Intersection(Array B) {
    Array* C = new Array(length + B.length);
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < length && j < B.length){
        if (A[i] < B.Get(j)){
            i++;
        } else if (A[i] > B.Get(j)){
            j++;
        }
        else {
            C->Set(k++, A[i]);
            i++;
            j++;
        }
    }

    return C;
}

Array* Array::Union(Array B) {
    Array* C = new Array(length + B.length);
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < length && j < B.length){
        if (A[i] < B.Get(j)){
            C->Set(k++, A[i++]);
        } else if (A[i] > B.Get(j)){
            C->Set(k++, B.Get(j++));
        }
        else {
            i++;
            j++;
        }
    }
    for (; i < length; i++){
        C->Set(k++, A[i]);
    }
    for (; j < B.length; j++){
        C->Set(k++, B.Get(j));
    }
    return C;
}

Array* Array::Difference(Array B) {
    Array* C = new Array(length + B.length);
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < length && j < B.length){
        if (A[i] < B.Get(j)){
            C->Set(k++, A[i]);
            i++;
        } else if (A[i] > B.Get(j)){
            j++;
        }
        else {
            i++;
            j++;
        }
    }
    for (; i < length; i++){
        C->Set(k++, A[i]);
    }

    return C;
}

