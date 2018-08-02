#include <iostream>
using namespace std;

class Alphabet {
private:
    string name;
public:
    Alphabet() { cout << "Alphabet Created!" << endl; }
    ~Alphabet() { cout << "Alphabet destroyed!" << endl; }

    void setName(string name) { this->name = name; }
    void display() const { cout << "Alphabet: " << name << endl; }
};

int main() {

    Alphabet *pArray = new Alphabet[26];

    char c = 'A';

    for (int i=0; i<26; i++, c++) {
        string s(1, c);
        pArray[i].setName(s);
        pArray[i].display();
    }

    delete [] pArray;

    return 0;
}