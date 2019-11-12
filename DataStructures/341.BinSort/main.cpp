#include <iostream>
using namespace std;

template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

int Max(int A[], int n){
    int max = INT_MIN;
    for (int i=0; i<n; i++){
        if (A[i] > max){
            max = A[i];
        }
    }
    return max;
}

// Linked List node
class Node{
public:
    int value;
    Node* next;
};

void Insert(Node** ptrBins, int idx){
    Node* temp = new Node;
    temp->value = idx;
    temp->next = nullptr;

    if (ptrBins[idx] == nullptr){
        ptrBins[idx] = temp;  // ptrBins[idx] is head ptr
    } else {
        Node* p = ptrBins[idx];
        while (p->next != nullptr){
            p = p->next;
        }
        p->next = temp;
    }
}

int Delete(Node** ptrBins, int idx){
    Node* p = ptrBins[idx];  // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}

void BinSort(int A[], int n){
    int max = Max(A, n);

    // Create bins array
    Node** bins = new Node* [max + 1];

    // Initialize bins array with nullptr
    for (int i=0; i<max+1; i++){
        bins[i] = nullptr;
    }

    // Update count array values based on A values
    for (int i=0; i<n; i++){
        Insert(bins, A[i]);
    }

    // Update A with sorted elements
    int i = 0;
    int j = 0;
    while (i < max+1){
        while (bins[i] != nullptr){
            A[j++] = Delete(bins, i);
        }
        i++;
    }

    // Delete heap memory
    delete [] bins;
}

int main() {

    int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int n = sizeof(A)/sizeof(A[0]);

    Print(A, n, "\t\tA");
    BinSort(A, n);
    Print(A, n, " Sorted A");
    cout << endl;

    Node** B = new Node* [3];
    B[0] = new Node;
    B[0]->value = 10;
    B[0]->next = nullptr;
    cout << B[0]->value << endl;

    return 0;
}
