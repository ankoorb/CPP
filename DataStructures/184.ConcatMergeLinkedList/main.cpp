#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

Node* head = new Node;
Node* second = new Node;
Node* third = new Node;
Node* fourth = new Node;

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

void createSecond(int A[], int n){
    Node* temp;
    Node* last;

    second->data = A[0];
    second->next = nullptr;
    last = second;

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

void createFourth(int A[], int n){
    Node* temp;
    Node* last;

    fourth->data = A[0];
    fourth->next = nullptr;
    last = fourth;

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

void removeDuplicates(Node* p){
    Node* q = p->next;
    while (q != nullptr){
        if (p->data != q->data){
            p = q;
            q = q->next;
        } else {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void reverseElements(Node* p){
    int* A = new int [count(p)];

    int i = 0;
    Node* q = p;

    while (q != nullptr){
        A[i] = q->data;
        q = q->next;
        i++;
    }

    q = p;
    i--;
    while (q != nullptr){
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void reverseLinks(Node* p){
    Node* r = nullptr;
    Node* q = nullptr;

    while (p != nullptr){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

void recursiveReverse(Node* q, Node* p){
    if (p == nullptr){
        head = q;
    } else {
        recursiveReverse(p, p->next);
        p->next = q;
    }
}

void Concatenate(Node* p, Node* q){
    while (p->next != nullptr){
        p = p->next;
    }
    p->next = q;
    q = nullptr;
}

void Merge(Node* p, Node* q){

    Node* last = nullptr;

    // First element of merged list
    if (p->data < q->data){
        third = p;
        last = p;
        p = p->next;
        last->next = nullptr;
    } else {
        third = q;
        last = q;
        q = q->next;
        last->next = nullptr;
    }

    while (p != nullptr && q != nullptr){
        if (p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = nullptr;
        } else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = nullptr;
        }
    }

    // Case: When one of the list is exhausted
    if (p != nullptr){ last->next = p; }

    if (q != nullptr){ last->next = q; }
}


int main() {

    int A[] = {1, 3, 5, 7};
    create(A, sizeof(A)/sizeof(A[0]));
    cout << "\nFirst Linked List: " << flush;
    displayIterative(head);

    int B[] = {2, 4, 6, 8, 10, 12};
    createSecond(B, sizeof(B)/sizeof(B[0]));
    cout << "\nSecond Linked List: " << flush;
    displayIterative(second);

    int C[] = {9, 11, 13};
    createFourth(C, sizeof(C)/sizeof(C[0]));
    cout << "\nFourth Linked List: " << flush;
    displayIterative(fourth);

    cout << "\nConcatenated Linked List: " << flush;
    Concatenate(head, fourth);
    displayIterative(head);

    cout << "\nMerged Linked List: " << flush;
    Merge(head, second);
    displayIterative(third);



    return 0;
}
