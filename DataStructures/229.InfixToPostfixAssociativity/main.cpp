#include <iostream>
#include <stack>
using namespace std;

class Node{
public:
    char data;
    Node* next;
};

class Stack{
private:
    Node* top;
public:
    Stack();
    ~Stack();
    void push(char x);
    char pop();
    char peek(int index);
    int isEmpty();
    int isFull();
    char stackTop();
};

Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    Node* p = top;
    while (top){
        top = top->next;
        delete p;
        p = top;
    }
}

void Stack::push(char x) {
    Node* t = new Node;
    if (t == nullptr){
        cout << "Stack Overflow!" << endl;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char Stack::pop() {
    Node* p;
    char x = -1;
    if (top == nullptr){
        cout << "Stack Underflow!" << endl;
    } else {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}

int Stack::isFull() {
    Node* t = new Node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}

int Stack::isEmpty() {
    return top ? 0 : 1;
}

char Stack::stackTop() {
    if (top){
        return top->data;
    }
    return -1;
}

char Stack::peek(int index) {
    if (isEmpty()){
        return -1;
    } else {
        Node* p = top;

        for (int i=0; p != nullptr && i<index-1; i++){
            p = p->next;
        }

        if (p != nullptr){
            return p->data;
        } else {
            return -1;
        }
    }
}

int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')'){
        return 0;
    }
    return 1;
}

int outPrecedence(char x){
    if (x == '+' || x == '-'){
        return 1;
    } else if (x == '*' || x == '/'){
        return 3;
    } else if (x == '^'){
        return 6;
    } else if (x == '('){
        return 7;
    } else if (x == ')'){
        return 0;
    }
    return -1;
}

int inPrecedence(char x){
    if (x == '+' || x == '-'){
        return 2;
    } else if (x == '*' || x == '/'){
        return 4;
    } else if (x == '^'){
        return 5;
    } else if (x == '('){
        return 0;
    }
    return -1;
}

char* convert(char* infix){

    char* postfix = new char [strlen(infix)+1];

    Stack stk;

    int i = 0;
    int j = 0;

    while (infix[i] != '\0'){
        if (isOperand(infix[i])){
            postfix[j++] = infix[i++];
        } else {
            if (outPrecedence(infix[i]) > inPrecedence(stk.stackTop())){
                stk.push(infix[i++]);
            } else if (outPrecedence(infix[i]) == inPrecedence(stk.stackTop())){
                stk.pop();
            }
            else {
                postfix[j++] = stk.pop();
            }
        }
    }

    while (! stk.isEmpty() && stk.stackTop() != ')'){
        postfix[j++] = stk.pop();
    }

    postfix[j] = '\0';

    return postfix;
}

char* convert2(char* infix){
    char* postfix = new char [strlen(infix) + 1];

    stack<char> stk;

    int i = 0;
    int j = 0;

    while (infix[i] != '\0'){
        if (isOperand(infix[i])){
            postfix[j++] = infix[i++];
        } else {
            if (stk.empty() || outPrecedence(infix[i]) > inPrecedence(stk.top())){
                stk.push(infix[i++]);
            } else if (outPrecedence(infix[i]) == inPrecedence(stk.top())){
                stk.pop();
            }
            else {
                postfix[j++] = stk.top();
                stk.pop();
            }
        }
    }

    while (! stk.empty() && stk.top() != ')'){
        postfix[j++] = stk.top();
        stk.pop();
    }

    postfix[j] = '\0';

    return postfix;

}


int main() {

    char infix[] = "((a+b)*c)-d^e^f";

    cout << convert(infix) << endl;
    cout << convert2(infix) << endl;

}

