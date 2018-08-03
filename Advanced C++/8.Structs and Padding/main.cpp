#include <iostream>
using namespace std;

#pragma pack(push, 1)  // Turning off padding
struct Person {
    //char c;  // Uncommenting still shows sizeof(Person) = 64
    char name[50];  // char array to store 50 characters
    int age;
    double weight;
};

// Undo directive so that it does not apply to every thing
#pragma pack(pop)  // Turning on padding



int main() {

    int w = sizeof(Person);
    int x = 50 * sizeof(char);
    int y = sizeof(int);
    int z = sizeof(double);
    int sum = x + y + z;
    cout << "Size of Person struct: " << w << endl;
    cout << "Total size of Person struct member types: " << sum << endl;
    cout << "Extra bytes due to struct padding: " << w - sum << endl;

    return 0;
}

/*
 * The only difference between a struct and a class is that the members of the struct
 * are public by default. structs are often used for writing to files.
 *
 * When variables are declared in C++, they are stored on an area of memory known as
 * the stack which is relatively small area of memory used for storing local variables
 * and keeping track of function calls.
 *
 * Objects of string class contain pointers. Because string class does not know how much
 * text one will want to store, it does not store text directly. What it does is that it
 * has a pointer inside it and it uses new with that pointer to allocate some memory on
 * the heap which is much bigger area of memory.
 *
 * `string text` -> Using this if we write to binary file, text will not get written,
 * instead pointer to text will get written. And if we read the pointer with a different
 * copy of the program, it is going to read a pointer address that no longer points
 * anywhere, thus we can not use string, so use char instead;
 *
 * C++ pads structs to make it more efficient to transfer text to and from memory. It is
 * better to write to file  by turning off padding using a preprocessor directive
 * `#pragma pack(push, 1)` and `#pragma pack(pop)` to turn padding on
 */