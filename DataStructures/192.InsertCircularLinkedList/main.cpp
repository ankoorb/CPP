#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class CircularLinkedList{
private:
    Node* head;
public:
    CircularLinkedList(){
        head = nullptr;
    }
    CircularLinkedList(int A[], int n);
    ~CircularLinkedList();
    void Display();
    void recursiveDisplay(Node* p);
    int Length();
    void Insert(int index, int x);
    Node* getHead(){ return head; }
};

CircularLinkedList::CircularLinkedList(int *A, int n) {

    Node* t;
    Node* tail;

    head = new Node;

    head->data = A[0];
    head->next = head;
    tail = head;

    for (int i=1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}

CircularLinkedList::~CircularLinkedList() {
    Node* p = head;
    Node* tail = head;

    while (tail->next != head){
        tail = tail->next;
    }

    while (head){
        head = head->next;
        delete p;
        p = head;
        tail->next = head;
    }
}

void CircularLinkedList::Display() {
    Node* p = head;
    do {
        cout << p->data << " -> " << flush;
        p = p->next;
    } while (p != head);
    cout << endl;
}

void CircularLinkedList::recursiveDisplay(Node *p) {
    static int flag = 0;
    if (p != head || flag == 0){
        flag = 1;
        cout << p->data << " -> " << flush;
        recursiveDisplay(p->next);
    }
    flag = 0;
}

int CircularLinkedList::Length() {
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

void CircularLinkedList::Insert(int index, int x) {
    Node* p = head;
    Node* t = new Node;
    t->data = x;
    t->next = nullptr;

    if (index < 0 || index > Length()){
        return;
    }

    if (index == 0){
        if (head == nullptr){
            head = t;
            head->next = head;
        } else {
            while (p->next != head){
                p = p->next;
            }
            t->next = head;
            p->next = t;
            head = t;
        }
    } else {
        for (int i=0; i<index-1; i++){
            cout << p->data << endl;
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }

}


int main() {

    int A[] = {1, 3, 5, 7, 9};

    CircularLinkedList cl(A, sizeof(A)/sizeof(A[0]));

    cout << "Length: " << cl.Length() << endl;

    cl.Insert(5, 11);

    cl.Display();

    Node* h = cl.getHead();
    cl.recursiveDisplay(h);

    cout << endl;


    CircularLinkedList c;
    c.Insert(0, 10);
    c.Insert(0, 20);
    c.Insert(0, 30);
    c.Insert(0, 40);
    c.Insert(0, 50);

    cout << "Length: " << c.Length() << endl;
    c.Display();


    return 0;
}