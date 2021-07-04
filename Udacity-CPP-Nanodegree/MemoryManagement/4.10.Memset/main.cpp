#include <iostream>
#include <cstring>

using namespace std;

int main() {

    char* ptr = new char('C');
    char str[4] = "AAA";

    cout << "Before Value of *ptr: " << *ptr << endl;
    cout << "Before Value of str: " << str << endl;

    memset(ptr, 'A', 1);
    memset(str + 1, 'B', 2);

    cout << "After Value of *ptr: " << *ptr << endl;
    cout << "After Value of str: " << str << endl;

    delete ptr;

    return 0;
}