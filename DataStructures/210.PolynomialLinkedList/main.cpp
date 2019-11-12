#include <iostream>
#include <cmath>
using namespace std;

class Node{
public:
    int coeff;
    int exp;
    Node* next;
};

class Polynomial{
private:
    Node* head;
public:
    Polynomial(){
        head = new Node;
        Node* t = new Node;
        Node* tail;
        tail = head;
        int n;
        cout << "Enter number of terms in the polynomial: " << flush;
        cin >> n;
        for (int i=0; i<n; i++){
            cout << "\nEnter each term with coeff and exp: " << flush;
            cin >> t->coeff >> t->exp;
            t->next = nullptr;
            if (head == nullptr){
                head = t;
                tail = t;
            } else {
                tail->next = t;
                tail = t;
            }
        }
    }

    void Display(){
        Node* p = head;
        while (p != nullptr){
            cout << p->coeff << " x^" << p->exp << " + " << flush;
            p = p->next;
        }
    }

    long Evaluate(int x){
        long val = 0;
        Node* p = head;
        while (p){
            val += p->coeff * pow(x, p->exp);
            p = p->next;
        }
        return val;
    }
};

int main() {

    Polynomial poly;
    cout << poly.Evaluate(2);
    poly.Display();

    return 0;
}