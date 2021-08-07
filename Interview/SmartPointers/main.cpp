#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Point {
public:
    int x_ = 0;
    int y_ = 0;
    Point(){}
    Point(int x, int y) : x_{x}, y_{y} {}
};

class State {
public:
    State(int x){ cout << "Status: Alive!" << endl; }
    ~State(){ cout << "\nStatus: Dead!" << endl; }
};

class Shape {
public:
    virtual void Print() const = 0;
};

class Square : public Shape {
public:
    void Print() const override { cout << "Square" << endl; }
};

class Rectangle : public Shape {
public:
    void Print() const override { cout << "Rectangle" << endl; }
};

class Triangle :  public Shape {
public:
    void Print() const override { cout << "Triangle" << endl; }
};

class Circle : public Shape {
public:
    void Print() const override { cout << "Circle" << endl; }
};

int main() {

    // UNIQUE Pointer
    cout << "UNIQUE Pointer\n" << endl;
    // C++ 11 style
    unique_ptr<Point> a_ptr = unique_ptr<Point>(new Point);
    cout << a_ptr->x_ << ", " << a_ptr->y_ << endl;

    unique_ptr<Point> b_ptr = unique_ptr<Point>(new Point(1, 2));
    cout << b_ptr->x_ << ", " << b_ptr->y_ << endl;

    // unique_ptr has no copy constructor so it can not be copied
    // unique_ptr can be moved
    unique_ptr<Point> e_ptr = move(a_ptr);
    cout << e_ptr->x_ << ", " << e_ptr->y_ << endl;
    // Do not access a_ptr because error

    // Modern C++ style
    auto c_ptr = make_unique<Point>(3, 4);
    cout << c_ptr->x_ << ", " << c_ptr->y_ << endl;

    Point d(4, 5);
    auto d_ptr = make_unique<Point>(d);
    cout << d_ptr->x_ << ", " << d_ptr->y_ << endl;

    // SHARED Pointer: Allocate once and multiple object to point it
    // C++ 11 style and Modern C++ style
    cout << "\nSHARED Pointer\n" << endl;
    shared_ptr<Point> f_ptr = shared_ptr<Point>(new Point);
    cout << f_ptr->x_ << ", " << f_ptr->y_ << endl;

    shared_ptr<Point> g_ptr = shared_ptr<Point>(new Point(6, 7));
    cout << g_ptr->x_ << ", " << g_ptr->y_ << endl;

    auto h_ptr = make_shared<Point>(7, 8);
    cout << h_ptr->x_ << ", " << h_ptr->y_ << endl;
    cout << "Count: " << h_ptr.use_count() << endl;

    {
        auto i_ptr = h_ptr;
        auto j_ptr = h_ptr;
        auto k_ptr = h_ptr;
        cout << "Count: " << h_ptr.use_count() << endl;
    }

    cout << "Count: " << h_ptr.use_count() << endl;
    cout << endl;

    auto m_ptr = make_shared<State>(7);
    cout << "Count (main): " << m_ptr.use_count() << endl;
    {
        auto n_ptr = m_ptr;
        auto o_ptr = m_ptr;
        cout << "Count (local): " << m_ptr.use_count() << endl;
    }
    cout << "Count (main): " << m_ptr.use_count() << endl;
    cout << endl;

    cout << "Polymorphic use of Smart Pointers\n" << endl;
    vector<unique_ptr<Shape>> shapes;
    shapes.emplace_back(new Square);

    shapes.emplace_back(make_unique<Rectangle>());

    auto triangle = unique_ptr<Triangle>(new Triangle);
    // Whenever you want to put something in a vector, by default it is copied
    // we can not copy because of unique_pointer so we have to move it to vector
    shapes.emplace_back(move(triangle));

    auto circle = make_unique<Circle>();
    shapes.emplace_back(move(circle));

    for (const auto& shape: shapes){
        shape->Print();
    }

    return 0;
}