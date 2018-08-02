#include <iostream>
using namespace std;

// Passing array like this - we loose the information about the number of elements in the array
void show1(string array[]) {
    cout << "show1 sizeof(array) : " << sizeof(array) << endl;  // This returns size of the pointer which is equal to sizeof(long)
    for (int i=0; i<3; i++) {
        cout << array[i] << endl;
    }
}

void show2(const int nelements, string array[]){  // string array[10] -> 10 will be ignored by c++
    for (int i=0; i<nelements; i++) {
        cout << array[i] << endl;
    }
}

// show2 is similar to show3 (passing pointer)
void show3(const int nelements, string *array){
    cout << "show2 sizeof(*array) : " << sizeof(array) << endl;
    for (int i=0; i<nelements; i++) {
        cout << array[i] << endl;
    }
}

// If you want to retain the size information - Need to pass reference to the array)
void show4(string (&array)[3]){  // For this syntax you have to pass in number of elements correctly in [] else error
    cout << "show4 sizeof(array) : " << sizeof(array) << endl;
    for (int i=0; i<sizeof(array)/sizeof(string); i++) {
        cout << array[i] << endl;
    }
}

// Returning array from function - return a pointer
string *getArray(){
    string texts[] = {"ant", "bat", "cat", "dog"}; // The array scope is { and } and is local to function
    return texts;  // We are returning pointer to local array or variables, pointer will not exist after leaving function

    // pointer will point to something that no longer exist after the function returns
}

char *getMemory(){
    char *pMem = new char[10];  // Explicitly allocating memory, that will not be de-allocated until delete is called
    *pMem = 'a';
    return pMem;  // Remember to de-allocate memory
}

void freeMemory(char *pMem) {
    delete [] pMem;
}

// If you create a function that allocates memory, the common practice is also to create a function
// that de-allocates that memory. And in the documentation of function add calling memory de-allocating function

int *getArrays() {
    int *pArray = new int[2];
    pArray[0] = 7;
    pArray[1] = 15;
    return pArray;
}


int main() {

    string texts[] = {"apple", "banana", "cherry"};
    cout << "sizeof(texts): " << sizeof(texts) << endl;
    show1(texts);
    cout << endl;

    show2(3, texts);
    cout << endl;

    show3(3, texts);
    cout << endl;

    show4(texts);
    cout << endl;

//    string *pArray = getArray();  // Not ideal because you have to remember to de-allocate memory
//    cout << "pArray : "<< *pArray << endl;
//    pArray++;
//    cout << "pArray : "<< *pArray << endl;
//    delete [] pArray;

//    char *pMem = getMemory();
//    cout << "pMem: " << *pMem << endl;
//    pMem++;
//    cout << "pMem: " << *pMem << endl;
//    freeMemory(pMem);
//
//    int *pi = getIntArray();
//    cout << "pi: " << *pi << endl;
//    pi++;
//    cout << "pi: " << *pi << endl;

    int *pArray = getArrays();
    cout << "pArray: " << *pArray << endl;
    pArray++;
    cout << "pArray: " << *pArray << endl;


    return 0;
}