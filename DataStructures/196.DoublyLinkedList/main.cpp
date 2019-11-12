#include <iostream>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;
};

class DoublyLinkedList{
private:
    Node* head;
public:
    DoublyLinkedList();
    DoublyLinkedList(int A[], int n);
    ~DoublyLinkedList();
    void Display();
    int Length();
};


DoublyLinkedList::DoublyLinkedList() {
    head = new Node;
    head->prev = nullptr;
    head->data = INT_MIN;
    head->next = nullptr;
}

DoublyLinkedList::DoublyLinkedList(int *A, int n) {

    head = new Node;
    head->prev = nullptr;
    head->data = A[0];
    head->next = nullptr;
    Node* tail = head;

    for (int i=1; i<n; i++){
        Node* t = new Node;
        t->prev = tail;
        t->data = A[i];
        t->next = tail->next; // tail->next is pointing to NULL
        tail->next = t;
        tail = t;
    }
}

DoublyLinkedList::~DoublyLinkedList() {}

void DoublyLinkedList::Display() {
    Node* p = head;
    while (p != nullptr){
        cout << p->data << flush;
        p = p->next;
        if (p != nullptr){
            cout << " <-> " << flush;
        }
    }
    cout << endl;
}

int DoublyLinkedList::Length() {
    int length = 0;
    Node* p = head;
    while (p != nullptr){
        length++;
        p = p->next;
    }
    return length;
}

int main() {

    int A[] {1, 3, 5, 7, 9};

    DoublyLinkedList dll(A, sizeof(A)/sizeof(A[0]));
    cout << "Length: " << dll.Length() << endl;
    dll.Display();

    return 0;
}