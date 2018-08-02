#include <iostream>
using namespace std;

int main() {

    char text[] = "hello world!";
    cout << sizeof(text) << endl;

    for (int i=sizeof(text)-2; i>=0; i--) {
        cout << text[i] << flush;
    }

    cout << " " << endl;

    // Using pointers
    char *pStart = text;
    int nchars = sizeof(text) - 1;
    char *pEnd = text + nchars -1;

    cout << *pStart << nchars << *pEnd << endl;

    while (pStart < pEnd) {

        // Swapping characters around
        char s = *pStart;
        *pStart = *pEnd;
        *pEnd = s;

        pStart++;
        pEnd--;
    }

    cout << text << endl;

    // Using inbuilt reverse function
    string s = "Hello World!";
    reverse(s.begin(), s.end());
    cout << s << endl;


    return 0;
}