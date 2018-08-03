#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(push, 1)
struct Person {
    char name[50];
    int age;
    double weight;
};
#pragma pack(pop)

// Initialize a struct
Person someone = {"Jon Snoe", 21, 175.5};

int main() {

    // Write Binary File
    string fileName = "test.bin";  // NOTE: File extension does not have to be bin

    ofstream outputFile;

    outputFile.open(fileName, ios::binary);  // It is important to use ios::binary

    if(outputFile.is_open()){

        outputFile.write((char *)&someone, sizeof(Person));  // Old way of casting between pointers
//        outputFile.write(reinterpret_cast<char*>(&someone), sizeof(Person));  // New way

        outputFile.close();
    } else {
        cout << "Could not create file: " << fileName << endl;
    }

    // Read Binary File
    Person someoneElse;

    ifstream inputFile;

    inputFile.open(fileName, ios::binary);  // It is important to use ios::binary

    if(inputFile.is_open()){

        inputFile.read(reinterpret_cast<char*>(&someoneElse), sizeof(Person));

        inputFile.close();
    } else {
        cout << "Could not read file: " << fileName << endl;
    }

    cout << "name: " << someoneElse.name << endl;
    cout << "age: " << someoneElse.age << endl;
    cout << "weight: " << someoneElse.weight << endl;

    return 0;
}

/*
 * ios::binary -> It is important use this to prevent C++ from messing up file because
 * of new line character
 */