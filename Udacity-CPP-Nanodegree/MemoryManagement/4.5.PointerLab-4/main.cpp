#include <iostream>
#include <cassert>

using namespace std;

// TODO: Doubly Linked List
template <class T>
class List {
private:
    struct Node {
        T val;
        Node* prev;
        Node* next;
        Node(T val, Node* prev, Node* next) : val(val), prev(prev), next(next) {}
    };

    Node* head_;
    Node* tail_;

public:
    List() : head_(nullptr), tail_(nullptr) {}
    ~List();

    void pushFront(T);
    void pushBack(T);
    T popFront();
    T popBack();
    int size() const;
    bool empty() const { return head_ == nullptr; }
    void print() const;
};



int main() {

    List<int> list;
    list.pushFront(7);
    assert(list.size() == 1);

    list.pushFront(15);
    list.pushBack(5);
    list.pushFront(4);
    assert(list.size() == 4);
    assert(list.popBack() == 5);
    assert(list.popFront() == 4);

    list.print();

    return 0;
}

template <class T>
List<T>::~List() {
    while (head_) {
        Node *current(head_);
        head_ = head_->next;
        delete current;  // Delete node that is no longer on the list
    }
}

template <class T>
void List<T>::pushFront(T val) {
    Node* front = new Node(val, nullptr, head_);
    if (tail_ == nullptr){
        tail_ = front;
        head_ = front;
    } else {
        head_->prev = front;
        head_ = front;
    }
}

template <class T>
void List<T>::pushBack(T val) {
    Node* back = new Node(val, tail_, nullptr);
    if (head_ == nullptr){
        head_ = back;
        tail_ = back;
    } else {
        tail_->next = back;
        tail_ = back;
    }
}

template <class T>
T List<T>::popFront() {
    if (this->empty()){
        throw("List::popFront() can not be done when List::empty() is true");
    }
    Node* temp(head_);
    T val = head_->val;
    head_ = head_->next;
    if (head_){
        head_->prev = nullptr;
    } else{
        tail_ = nullptr;
    }

    delete temp;
    return val;
}

template <class T>
T List<T>::popBack() {
    if (this->empty()){
        throw("List::popBack() can not be done when List::empty() is true");
    }
    Node* temp(tail_);
    T val = tail_->val;
    tail_ = tail_->prev;
    if (tail_){
        tail_->next = nullptr;
    } else {
        head_ = nullptr;
    }

    delete temp;
    return val;
}

template <class T>
int List<T>::size() const {
    int size = 0;
    Node* current(head_);
    while (current) {
        size++;
        current = current->next;
    }
    return size;
}

template <class T>
void List<T>::print() const {
    Node* current(head_);
    while (current) {
        cout << "[" << current->val << "]" << "<->" << flush;
        current = current->next;
    }
    cout << endl;
}
