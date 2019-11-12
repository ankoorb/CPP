#include <iostream>
using namespace std;

class Node{
public:
    Node* prev;
    int data;
    Node* next;
};

class CircularDoublyLinkedList{
private:
    Node* head;
public:
    CircularDoublyLinkedList(int A[0], int n);
    ~CircularDoublyLinkedList();
    void Display();
    int Length();
    int Insert(int index, int x);
    int Delete(int index);
    Node* getHead(){ return head; }
};


CircularDoublyLinkedList::CircularDoublyLinkedList(int *A, int n) {
    Node* t;
    Node* tail;

    head = new Node;
    head->prev = head;
    head->data = A[0];
    head->next = head;
    tail = head;

    for (int i=1; i<n; i++){
        t = new Node;
        t->prev = tail;
        t->data = A[i];
        t->next = head;
        head->prev = t;
        tail->next = t;
        tail = t;
    }
}

int CircularDoublyLinkedList::Length() {
    int length = 0;
    Node* p = head;
    if (head == nullptr){
        return 0;
    }
    do {
        length++;
        p = p->next;
    } while (p != head);

    return length;
}

void CircularDoublyLinkedList::Display() {
    Node* p = head;
    do {
        cout << p->data << " <-> " << flush;
        p = p->next;
    } while (p != head);
    cout << endl;
}

CircularDoublyLinkedList::~CircularDoublyLinkedList() {
    Node* p = head;
}


int main() {

    int A[] {1, 3, 5, 7, 9};

    CircularDoublyLinkedList cdll(A, sizeof(A)/sizeof(A[0]));
    Node* h = cdll.getHead();
    cout << h->data << endl;
    cout << "Length: " << cdll.Length() << endl;

    cdll.Display();

    return 0;
}

//class DoublyLinkedList{
//private:
//    Node* head;
//public:
//    DoublyLinkedList();
//    DoublyLinkedList(int A[], int n);
//    ~DoublyLinkedList();
//    void Display();
//    int Length();
//    void Insert(int index, int x);
//    int Delete(int index);
//    void Reverse();
//};
//
//
//DoublyLinkedList::DoublyLinkedList() {
//    head = new Node;
//    head->prev = nullptr;
//    head->data = INT_MIN;
//    head->next = nullptr;
//}
//
//DoublyLinkedList::DoublyLinkedList(int *A, int n) {
//
//    head = new Node;
//    head->prev = nullptr;
//    head->data = A[0];
//    head->next = nullptr;
//    Node* tail = head;
//
//    for (int i=1; i<n; i++){
//        Node* t = new Node;
//        t->prev = tail;
//        t->data = A[i];
//        t->next = tail->next; // tail->next is pointing to NULL
//        tail->next = t;
//        tail = t;
//    }
//}
//
//void DoublyLinkedList::Display() {
//    Node* p = head;
//    while (p != nullptr){
//        cout << p->data << flush;
//        p = p->next;
//        if (p != nullptr){
//            cout << " <-> " << flush;
//        }
//    }
//    cout << endl;
//}
//
//int DoublyLinkedList::Length() {
//    int length = 0;
//    Node* p = head;
//    while (p != nullptr){
//        length++;
//        p = p->next;
//    }
//    return length;
//}
//
//void DoublyLinkedList::Insert(int index, int x) {
//
//    if (index < 0 || index > Length()){
//        return;
//    }
//
//    Node* p = head;
//    Node* t = new Node;
//    t->data = x;
//
//    if (index == 0){
//        t->prev = nullptr;
//        t->next = head;
//        head->prev = t;
//        head = t;
//    } else {
//        for (int i=0; i<index-1; i++){
//            p = p->next;
//        }
//        t->prev = p;
//        t->next = p->next;
//        if (p->next){
//            p->next->prev = t;
//        }
//        p->next = t;
//    }
//}
//
//int DoublyLinkedList::Delete(int index) {
//    int x = -1;
//    Node* p = head;
//
//    if (index < 0 || index > Length()){
//        return x;
//    }
//
//    if (index == 1){
//        head = head->next;
//        if (head){
//            head->prev = nullptr;
//        }
//        x = p->data;
//        delete p;
//    } else {
//        for (int i=0; i<index-1; i++){
//            p = p->next;
//        }
//        p->prev->next = p->next;
//        if (p->next){
//            p->next->prev = p->prev;
//        }
//        x = p->data;
//        delete p;
//    }
//    return x;
//}
//
//void DoublyLinkedList::Reverse() {
//    Node* p = head;
//    Node* temp;
//    while (p != nullptr){
//        temp = p->next;
//        p->next = p->prev;
//        p->prev = temp;
//        p = p->prev;
//
//        // Need to check the below condition again
//        if (p->next == nullptr){
//            p->next = p->prev;
//            p->prev = nullptr;
//            head = p;
//            break;
//        }
//    }
//}
//
//DoublyLinkedList::~DoublyLinkedList() {
//    Node* p = head;
//    while (head){
//        head = head->next;
//        delete p;
//        p = head;
//    }
//}
//
