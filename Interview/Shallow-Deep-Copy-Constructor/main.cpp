#include <iostream>
using namespace std;

class Shallow {
public:
    Shallow(int data);
    Shallow(const Shallow& other);
    ~Shallow(){
        cout << "Freeing Shallow: " << GetData() << endl;
        delete data_;
    };
    int GetData() const { return *data_; }
    void SetData(int data) { *data_ = data; }
private:
    int* data_;
};


Shallow::Shallow(int data) {
    data_ = new int;
    *data_ = data;
}

Shallow::Shallow(const Shallow &other) {
    data_ = other.data_;
    cout << "Shallow Copy" << endl;
}


void Display(Shallow s){
    cout << s.GetData() << endl;
}

class Deep {
public:
    Deep(int data);
    Deep(const Deep& other);

    ~Deep(){
        cout << "Freeing Deep: " << GetData() << endl;
        delete data_;
    }
    int GetData() const { return *data_; }
    void SetData(int data) { *data_ = data; }

private:
    int* data_;
};

Deep::Deep(int data) {
    data_ = new int;
    *data_ = data;
}

Deep::Deep(const Deep &other) {
    data_ = new int;
    *data_ = *other.data_;
    cout << "Deep Copy" << endl;
}

void Display(Deep d){
    cout << d.GetData() << endl;
}

int main() {

    bool shallow = false;

    if (shallow){
        Shallow x(7);
        Display(x);
        Display(x);

        Shallow y(15);

        {
            Shallow z(y);
            cout << z.GetData() << endl;
        }

        cout << y.GetData() << endl;
    } else {
        Deep a(4);
        Display(a);
        Display(a);

        Deep b(5);
        {
            Deep c(b);
            cout << c.GetData() << endl;
        }

        cout << b.GetData() << endl;
    }

    return 0;
}