#include <iostream>
using namespace std;

class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class BST{
private:
    Node* root;
public:
    BST(){ root = nullptr; }
    Node* getRoot(){ return root; }
    void iInsert(int key);
    void Inorder(Node* p);
    Node* iSearch(int key);
    Node* rInsert(Node* p, int key);
    Node* rSearch(Node* p, int key);
};

void BST::iInsert(int key) {

    Node* t = root;
    Node* p;
    Node* r;

    // root is empty
    if (root == nullptr){
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }

    while(t != nullptr){
        r = t;
        if (key < t->data){
            t = t->lchild;
        } else if (key > t->data){
            t = t->rchild;
        } else {
            return;
        }
    }

    // Now t points at NULL and r points at insert location
    p = new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;

    if (key < r->data){
        r->lchild = p;
    } else {
        r->rchild = p;
    }

}

void BST::Inorder(Node* p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

Node* BST::iSearch(int key) {
    Node* t = root;
    while (t != nullptr){
        if (key == t->data){
            return t;
        } else if (key < t->data){
            t = t->lchild;
        } else {
            t = t->rchild;
        }
    }
    return nullptr;
}

Node* BST::rInsert(Node *p, int key) {
    Node* t;
    if (p == nullptr){
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
    }

    if (key < p->data){
        p->lchild = rInsert(p->lchild, key);
    } else if (key > p->data){
        p->rchild = rInsert(p->rchild, key);
    }
    return t;
}

Node* BST::rSearch(Node *p, int key) {
    if (p == nullptr){
        return nullptr;
    }

    if (key == p->data){
        return p;
    } else if (key < p->data){
        return rSearch(p->lchild, key);
    } else {
        return rSearch(p->rchild, key);
    }
}


int main() {

    BST bst;

    // Iterative insert
    bst.iInsert(10);
    bst.iInsert(5);
    bst.iInsert(20);
    bst.iInsert(8);
    bst.iInsert(30);

    // Inorder traversal
    bst.Inorder(bst.getRoot());
    cout << endl;

    // Iterative search
    Node* temp = bst.iSearch(2);
    if (temp != nullptr){
        cout << temp->data << endl;
    } else {
        cout << "Element not found" << endl;
    }

    // Recursive search
    temp = bst.rSearch(bst.getRoot(), 20);
    if (temp != nullptr){
        cout << temp->data << endl;
    } else {
        cout << "Element not found" << endl;
    }

    // Recursive insert (Need to debug)
    bst.rInsert(bst.getRoot(), 30);
    bst.rInsert(bst.getRoot(), 20);
    bst.rInsert(bst.getRoot(), 10);
    bst.Inorder(bst.getRoot());
    cout << endl;

    return 0;
}