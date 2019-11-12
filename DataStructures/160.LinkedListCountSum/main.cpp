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
    cout << endl;
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

int count(Node* p){
    int c = 0;
    while (p != NULL){
        c += 1;
        p = p->next;
    }
    return c;
}

int recursiveCount(Node* p){
    if (p == NULL){
        return 0;
    }
    return recursiveCount(p->next) + 1;
}

int sum(Node* p){
    int s = 0;
    while (p != NULL){
        s += p->data;
        p = p->next;
    }
    return s;
}

int recursiveSum(Node* p){
    if (p == NULL){
        return 0;
    }
    return recursiveSum(p->next) + p->data;
}



int main() {

    int A[] = {3, 5, 7, 10, 15, 8, 12, 20};
    create(A, sizeof(A)/sizeof(A[0]));

    displayIterative(head);

    recursiveDisplay(head);

    recursiveReverseDisplay(head);

    cout << endl;
    cout << count(head) << endl;
    cout << recursiveCount(head) << endl;

    cout << endl;
    cout << sum(head) << endl;
    cout << recursiveSum(head) << endl;

    return 0;
}
