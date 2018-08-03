#include <iostream>
#include <fstream>
using namespace std;

int main() {

    string inFileName = "/Users/ankoor/Desktop/Programming/C++/test.txt";
    ifstream  inFile;  // Input file stream

    inFile.open(inFileName);  // Open file

    if(inFile.is_open()) {

        string line;

//        inFile >> line;  // Get inFile into line using extraction operator
//        cout << line << endl;  // Prints only first word!

//        getline(inFile, line);
//        cout << line << endl;  // Prints first line only

        // Using while loop
        while(!inFile.eof()){  // eof -> End of file
            getline(inFile, line);
            cout << line << endl;  // Prints the whole file
        }

        inFile.close();
    }
    else {
        cout << "Can not open file: " << inFileName << endl;
    }

    return 0;
}