#include <iostream>
#include <cmath>
using namespace std;

class Term{
public:
    int coeff;
    int exp;
};

class Polynomial{
private:
    int n;
    Term* T;
public:
    Polynomial(int n){
        this->n = n;
        T = new Term [n];
    }

    ~Polynomial(){ delete[] T; };

    int evaluate(int x);

    friend istream& operator>>(istream& is, Polynomial& p);
    friend ostream& operator<<(ostream& os, Polynomial& p);

    Polynomial& operator+(Polynomial& p);
};

istream& operator>>(istream& is, Polynomial& p){
    cout << "Enter Polynomial Coefficients and Exponents" << endl;
    for (int i=0; i<p.n; i++){
        is >> p.T[i].coeff >> p.T[i].exp;
    }
    return is;
}

ostream& operator<<(ostream& os, Polynomial& p){
    os << "Polynomial: " << flush;
    for (int i=0; i<p.n; i++){
        os << p.T[i].coeff << " X^" << p.T[i].exp << flush;
        if (i < p.n - 1){
            os << " + " << flush;
        }
    }
    return os;
}

Polynomial& Polynomial::operator+(Polynomial &p) {

    Polynomial* s = new Polynomial(n + p.n);

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < p.n){
        if (T[i].exp > p.T[j].exp){
            s->T[k++] = T[i++];
        } else if (p.T[j].exp > T[i].exp){
            s->T[k++] = p.T[j++];
        } else {
            s->T[k] = T[i];
            s->T[k++].coeff = T[i++].coeff + p.T[j++].coeff;
        }
    }

    // When one of the polynomial is exhausted and other has terms left
    for (; i<n; i++){
        s->T[k++] = T[i];
    }

    for (; j<p.n; j++){
        s->T[k++] = p.T[j];
    }

    s->n = k;

    return *s;
}

int Polynomial::evaluate(int x) {
    int p = 0;
    for (int i=0; i<n; i++){
        p += T[i].coeff * pow(x, T[i].exp);
    }
    return p;
}

int main() {

    Polynomial p1(3);
    Polynomial p2(5);

    cin >> p1;
    cin >> p2;

    cout << p1 << endl;
    cout << p2 << endl;
    cout << p1 + p2 << endl;
    cout << (p1 + p2).evaluate(5) << endl;

    return 0;
}