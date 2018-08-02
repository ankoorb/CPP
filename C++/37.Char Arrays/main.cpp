#include <iostream>
using namespace std;


int main() {

//    char text[] = {'a', 'b', 'c', 'd', 'e'};
    char text[] = "abcde";
    cout << sizeof(text) << text << endl;

    for (int i=0; i<sizeof(text); i++) {
        cout << i << ": " << (int)text[i] << " " << flush;
    }

    for (int i=0; i<sizeof(text)/sizeof(char); i++) {
        cout << i << ": " << (int)text[i] << endl;
    }

    int k = 0;
    while (true) {

        if (text[k] == 0) {
            break;
        }

        cout << text[k] << flush;
        k++;
    }

    return 0;
}