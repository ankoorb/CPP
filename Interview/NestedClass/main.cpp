#include <iostream>

using namespace std;

class Outer {
public:
    class Inner {
        public:
            void show(){
                cout << "Inner member: " << z_ << endl;
                cout << "Outer static member (from Inner): " << y_ << endl;
            }
        private:
            int z_ {4};
    };

    void display(){
        cout << "Outer member: " << x_ << endl;
        cout << "Outer static member (from Outer): " << y_ << endl;
        cout << "Inner member function 'show' (from Outer): " << endl;
        inner_.show();
    }

private:
    int x_ {7};
    static int y_;
    Inner inner_;

};

int Outer::y_ = 15;

int main() {

    Outer outer;
    outer.display();

    return 0;
}
