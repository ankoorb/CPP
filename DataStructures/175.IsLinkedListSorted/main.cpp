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

int Max(Node* p){
    int m = INT_MIN;
    while (p){
        if (p->data > m){
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

int Min(Node* p){
    int m = INT_MAX;
    while (p){
        if (p->data < m){
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

int recursiveMax(Node* p){
    int m;
    if (p == NULL){
        return INT_MIN;
    }
    m = recursiveMax(p->next);
    if (p->data > m){
        return p->data;
    } else {
        return m;
    }
}

int recursiveMin(Node* p){
    int m;
    if (p == NULL){
        return INT_MIN;
    }
    m = recursiveMax(p->next);
    return p->data < m ? p->data : m;
}

Node* Search(Node* p, int key){
    while (p){
        if (p->data == key){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

Node* recursiveSearch(Node* p, int key){
    if (p == nullptr){
        return nullptr;
    }

    if (p->data == key){
        return p;
    }

    return recursiveSearch(p->next, key);
}

Node* improvedSearch(Node* p, int key){
    Node* q;// = nullptr;
    while (p){
        if (p->data == key){
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        q = p;
        p = p->next;
    }
}

void Insert(Node* p, int position, int x){

    Node* t = new Node;

    if (position == 0){
        t->data = x;
        t->next = head;
        head = t;
    } else if (position > 0){
        for (int i=0; i<position-1 && p; i++){
            p = p->next;
        }
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

void insert(Node*p, int index, int x){

    Node* t = new Node;

    if (index < 0 || index > count(p)){
        return;
    }

    t->data = x;

    if (index == 0) {
        t->next = head;
        head = t;
    } else {
        for (int i=0; i<index-1; i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }

}

void sortedInsertX(Node* p, int x){

    Node* t = new Node;
    t->data = x;
    t->next = nullptr;

    Node* q = nullptr;

    if (p->data > x){
        t->next = p;
        head = t;
    } else {

        while (p && p->data < x){
            q = p;
            p = p->next;
        }
        t->next = q->next;
        q->next = t;
    }
}

void sortedInsert3(Node* p, int x){

    Node* t = new Node;
    t->data = x;
    t->next = nullptr;

    Node* q = nullptr;

    // Case: No nodes in the Linked List
    if (head == nullptr){
        head = t;
    } else {
        // Traverse to find insert position
        while (p && p->data < x){
            q = p;
            p = p->next;
        }

        // Case: Insert position is first - insert node before first
        if (p == head){
            t->next = head;
            head = t;
        } else {
            t->next = q->next;
            q->next = t;
        }
    }
}

void sortedInsert2(Node* p, int x){

    Node* t = new Node;
    t->data = x;
    t->next = nullptr;

    if (head == nullptr){
        head = t;
    } else {

        // Traverse to find insert position
        while (p && p->next->data < x){
            p = p->next;
        }

        // Case: Insert position is first - insert node before first
        if (p == head){
            t->next = head;
            head = t;
        } else {
            t->next = p->next;
            p->next = t;
        }
    }
}

int Delete(Node* p, int index){

    Node* q = nullptr;
    int x = -1;

    // Check validity of index
    if (index < 1 || index > count(p)){
        return x;
    }

    if (index == 1){
        q = head;
        head = head->next;
        x = q->data;
        delete q;
        return x;
    } else {
        for (int i=0; i<index-1; i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

int isSorted(Node* p){
    int x = INT_MIN;
    while (p != nullptr){
        if (p->data < x){
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}


int main() {

    int A[] = {10, 20, 30, 40, 50, 25};
    create(A, sizeof(A)/sizeof(A[0]));

    displayIterative(head);

    cout << isSorted(head) << endl;


    return 0;
}
