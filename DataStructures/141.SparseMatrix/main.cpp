#include <iostream>
using namespace std;

struct Element{  // Can use class with public members
    int i;
    int j;
    int x;
};

class Sparse {
private:
    int m;
    int n;
    int count;  // Non-zero element count
    struct Element* E;

public:
    Sparse(int m, int n, int count) {
        this->m = m;
        this->n = n;
        this->count = count;
        E = new Element [count];
    }

    // Copy constructor
    Sparse(Sparse& other){
        m = other.m;
        n = other.n;
        count = other.count;
        E = new Element [count];

        for (int i=0; i<count; i++){
            E[i].i = other.E[i].i;
            E[i].j = other.E[i].j;
            E[i].x = other.E[i].x;
        }
    }

    ~Sparse() { delete[] E; };

    // I/O stream operator overloading
    friend istream& operator>>(istream& is, Sparse& s);
    friend ostream& operator<<(ostream& os, Sparse& s);

    // Assignment operator overloading
    void operator=(Sparse& s);

    // Add operator overloading
    Sparse& operator+(Sparse& other);

};

istream& operator>>(istream& is, Sparse& s){
    cout << "Enter Non-Zero Elements" << endl;
    for (int i=0; i<s.count; i++){
        cin >> s.E[i].i >> s.E[i].j >> s.E[i].x;
    }
    return is;
}

ostream& operator<<(ostream& os, Sparse& s){
    cout << "\nSparse Matrix" << endl;
    int k = 0;
    for (int i=0; i<s.m; i++){
        for (int j=0; j<s.n; j++){
            if (i == s.E[k].i && j == s.E[k].j){
                cout << s.E[k++].x << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    return os;
}

void Sparse::operator=(Sparse &s) {
    m = s.m;
    n = s.n;
    count = s.count;
    E = new Element [count];
    for (int i=0; i<count; i++){
        E[i].i = s.E[i].i;
        E[i].j = s.E[i].j;
        E[i].x = s.E[i].x;
    }
}

Sparse& Sparse::operator+(Sparse& other) {

    Sparse* S = new Sparse(0, 0, 0);

    if (m != other.m && n != other.n){
        return *S;
    }

    S->m = m;
    S->n = n;
    S->count = count + other.count;

    // Index trackers
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < count && j < other.count){
        // Row comparison
        if (E[i].i < other.E[j].i){
            S->E[k++] = E[i++];
        } else if (E[i].i > other.E[j].i){
            S->E[k++] = other.E[j++];
        } else {
            // Column comparison
            if (E[i].j < other.E[j].j){
                S->E[k++] = E[i++];
            } else if (E[i].j > other.E[j].j){
                S->E[k++] = other.E[j++];
            } else {
                // Add
                S->E[k] = E[i];
                S->E[k++].x = E[i++].x + other.E[j++].x;
            }
        }
    }

    for (; i < count; i++){
        S->E[k++] = E[i++];
    }

    for (; j < other.count; j++){
        S->E[k++] = other.E[j++];
    }

    S->count = k;

    return *S;
}



int main() {


    Sparse s1(3, 3, 3);
    Sparse s2(3, 3, 3);

    cin >> s1;
    cin >> s2;

    cout << s1;
    cout << s2;

    cout << s1 + s2;

    // Sparse s3(3, 3, 3); s3 = s1 + s2; // Does not work!

    return 0;
}