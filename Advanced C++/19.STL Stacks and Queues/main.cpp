#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Test {
private:
    string name;
public:
    Test(string name): name(name) {}
    //~Test(){ cout << "Object destroyed!" << endl;}
    void print(){ cout << name << endl; }

};

int main() {

//    // Create stack object
//    stack<Test> testStack;
//
//    // Adding items to top of stack
//    testStack.push(Test("Crush"));  // First added
//    testStack.push(Test("Kona"));  // Last added
//    cout << endl;
//
//    // Looking at the top item of the stack
//    Test &testItem1 = testStack.top();
//    testItem1.print();
//    cout << endl;
//
//    // Popping items off the stack
//    testStack.pop();  // This does not return anything because it has void return type
//    testItem1.print();  // Item is popped but still print -> Invalid code
//    cout << endl;

    /*
     * // Invalid code because the object is destroyed.
     * Test &testItem1 = testStack.top();
     * testStack.pop();
     * testItem1.print();  // Reference refers to destroyed object
     */

//    Test testItem2 = testStack.top();
//    testItem2.print();
//    cout << endl;


//    cout << testStack.size() << endl;
//
//    // Iterating through a stack
//    while(testStack.size() > 0) {
//        Test &test = testStack.top();
//        test.print();  // Prints in reverse order
//        testStack.pop();
//    }



//    cout << endl;
//
    // Create queue object
    queue<Test> testQueue;

    // Adding items to queue
    testQueue.push(Test("Spot"));
    testQueue.push(Test("Paroh"));

    Test &testQf = testQueue.front();
    testQf.print();

    testQueue.back().print();
    cout << endl;

    // Iterating through a queue
    while(testQueue.size() > 0){
        Test &testItem = testQueue.front();
        testItem.print();
        testQueue.pop();
    }
    return 0;
}

/*
 * stack - It is a Last In First Out (LIFO) structure, analogy stack of cards. Adding items to
 * top of stack use `stackObject.push(item)`.
 *
 * To get an object from a stack there is no way to iterate through a stack or a queue. If you
 * think you want to iterate through a stack, you do not need a stack you need a vector or list.
 *
 * Careful - Lot of collections i.e. STL classes, when you access objects within the collection of
 * objects stored in this data structure (e.g. objects stored in vector), the STL class will return
 * a reference of the object that is in it. `testStack.top()` is returning reference to the object
 * in the `testStack` and because of equality operator in `Test testItem1 = testStack.top();` we are
 * actually copying the object that the reference refers to into testItem1, so it is using shallow
 * copy here using the default implementation of the assignment operator, and it is just copying the
 * values of the instance variables into testItem1, so this means that when we add objects to the stack
 * like this we are going to be destroying the original objects that we added -> Use reference
 * `Test &testItem1 = testStack.top();` -> returns reference to the existing object in the stack
 *
 * Using reference -> when you do pop the object is removed and discarded
 *
 * If you do get a reference to your object you have to be aware that as soon as you pop the object
 * off the stack it is destroyed and the reference is invalidated
 *
 * Iterating through a stack (sort of) -> The only way to iterate through a stack is to remove objects
 * from it using `stackObject.size()` method
 *
 * queue - It is a First In First Out (FIFO) structure, analogy a cash register.
 *
 * `queueObject.back()` -> For checking what is at the back of the queue.
 *
 */