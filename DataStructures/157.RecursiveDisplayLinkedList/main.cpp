#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

Node* head = new Node;

void create(int A[], int n){
    Node* temp;
    Node* last;

    head->data = A[0];
    head->next = nullptr;
    last = head;

    // Create a Linked List
    for (int i=1; i<n; i++){

        // Create a temporary Node
        temp = new Node;

        // Populate temporary Node
        temp->data = A[i];
        temp->next = nullptr;

        // last's next is pointing to temp
        last->next = temp;
        last = temp;
    }
}

void displayIterative(Node* p){
    while (p != nullptr){
        cout << p->data << " -> " << flush;
        p = p->next;
    }
}

void recursiveDisplay(Node* p){
    if (p != nullptr){
        cout << p->data << " " << flush;
        recursiveDisplay(p->next);
    }
    cout << endl;
}

void recursiveReverseDisplay(Node* p){
    if (p != nullptr){
        recursiveReverseDisplay(p->next);
        cout << p->data << " " << flush;
    }
}

int main() {

    int A[] = {3, 5, 7, 10, 15};
    create(A, sizeof(A)/sizeof(A[0]));

    recursiveDisplay(head);

    recursiveReverseDisplay(head);

    return 0;
}