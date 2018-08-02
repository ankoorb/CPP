#include <iostream>
using namespace std;

int main() {

    const int NSTRINGS = 5;
    string texts[NSTRINGS] = {"one", "two", "three", "four", "five"};
    string *pTexts = texts;
    cout << *pTexts << endl;

    // Addition
    pTexts = pTexts + 1;
    cout << *pTexts << endl;

    pTexts += 2;
    cout << *pTexts << endl;

    // Subtraction
    pTexts -= 2;
    cout << *pTexts << endl;

    // Comparison
    string *pEnd = &texts[NSTRINGS-1];
    pTexts = &texts[0];
    cout << (pTexts == pEnd) << endl;

    while (pTexts != pEnd) {
        cout << *pTexts << endl;
        pTexts++;
    }

    // Set pointer back to start
    pTexts = &texts[0];
    long elements = (long)(pEnd - pTexts);
    cout << elements << endl;

    pTexts = &texts[0];
    pTexts += NSTRINGS/2;
    cout << *pTexts << endl;

    return 0;
}