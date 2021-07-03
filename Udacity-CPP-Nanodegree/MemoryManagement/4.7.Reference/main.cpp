#include <iostream>
#include <string>

using namespace std;

void addSpaces(const char*& str){
    char* temp = new char(sizeof(str) * 2);

    char* start = temp;

    while (*str != '\0'){
        *temp++ = *str++;
        *temp++ = ' ';
    }
    str = start;
}

int main() {

    string str = "Hello World";
    const char* ptr = str.c_str();

    cout << "String str is : " << ptr << endl;

    addSpaces(ptr);
    cout << "String str is : " << ptr << endl;

    return 0;
}