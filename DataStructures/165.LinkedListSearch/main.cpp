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

    cout << endl;
    cout << Max(head) << endl;
    cout << Min(head) << endl;
    cout << recursiveMax(head) << endl;
    cout << recursiveMin(head) << endl;

    cout << endl;
    cout << Search(head, 15) << endl;
    cout << Search(head, 0) << endl;
    cout << recursiveSearch(head, 15) << endl;
    cout << recursiveSearch(head, 0) << endl;
    cout << "Improved Search" << endl;
    cout << improvedSearch(head, 15) << endl;
    cout << improvedSearch(head, 0) << endl;

    displayIterative(head);

    return 0;
}
