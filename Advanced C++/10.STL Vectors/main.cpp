#include <iostream>
#include <vector>
using namespace std;

int main() {

    // Declaring vector of type string, i.e. vector will contain 5 strings
    vector<string> texts(5);  // If using push_back then no need to supply value 5

    // Setting elements in the vector
    texts[0] = "cat";
    texts[1] = "bat";
    texts[2] = "ant";
    texts[3] = "dog";

    cout << texts[3] << endl;

    // Adding extra string to vector
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("six");

    cout << texts.size() << endl;  // Size of vector
    cout << texts[5] << endl;

    // Iterating through a vector
    for(int i=0; i<texts.size(); i++){
        cout << texts[i] << endl;
    }

    // Recommended syntax for iterating through a vector
    vector<string>::iterator it = texts.begin();  // Get iterator from vector of strings
    it++;
    cout << "iterator: " << *it << endl;

    for(vector<string>::iterator it = texts.begin(); it != texts.end(); it++){
        cout << *it << endl;
    }

    vector<string>::iterator i = texts.begin();  // Get iterator from vector of strings
    i+=2;
    cout << "iterator: " << *i  << endl;



    return 0;
}

/*
 * vector - It is a resizable array. And it is a template class
 * vector<type> - Telling vector what type of object it is going to work with, e.g. vector<int>
 * vector<string> texts[n] - Create a vector that will contain n strings
 * Since vector is resizable it will automatically handle memory
 *
 * If vector is pre-sized then do not use vector[n] = value to set element off the end of current size of vector
 *
 * texts.begin() -> Gives iterator which points to the first element of the vector
 *
 * texts.end
 */