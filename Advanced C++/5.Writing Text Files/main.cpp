#include <iostream>
#include <fstream>  // For reading data or writing data
using namespace std;

int main() {

    // ofstream -> Output file stream
    ofstream outFile;  // Object of type ofstream

    string outputFileName = "test.txt";
    outFile.open(outputFileName);  // Open the file

    if(outFile.is_open()) {
        outFile << "Hello there" << endl;
        outFile << 123456789 << endl;
        for(int i=0; i<100; i++){
            outFile << i << ". Ankoor!" << endl;
        }
        outFile.close();  // Must close file
    }
    else {
        cout << "Could not create file: " << outputFileName << endl;
    }

    return 0;
}