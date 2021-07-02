#include <iostream>
#include <cassert>

using namespace std;

class Point {
public:
    int x_;
    int y_;

    Point(int x = 0, int y = 0);
    Point operator+(const Point& other);
};

Point::Point(int x, int y) : x_(x), y_(y) {}

Point Point::operator+(const Point &other) {
    Point p;
    p.x_ = this->x_ + other.x_;
    p.y_ = this->y_ + other.y_;
    return p;
}

int main() {

    Point p1(10, 5);
    Point p2(2, 4);

    Point p3 = p1 + p2;
    assert(p3.x_ == p1.x_ + p2.x_);
    assert(p3.y_ == p1.y_ + p2.y_);

    return 0;
}