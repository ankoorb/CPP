#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
    Point(int x, int y) : x_{x}, y_{y} { count++; }
    ~Point(){ count--; }

    float distance(const Point& other){
        int dx = x_ - other.x_;
        int dy = y_ - other.y_;
        return sqrt(dx * dx + dy * dy);
    }

    static float distance(const Point& p, const Point& q){
        int dx = p.x_ - q.x_;
        int dy = p.y_ - q.y_;
        return sqrt(dx * dx + dy * dy);
    }

    static int getCount(){ return count; }

private:
    int x_;
    int y_;
    static int count;
};

int Point::count = 0; // Need to initialize outside class

int main() {

    Point p(1, 3);
    Point q(3, 4);
    Point r(5, 7);
    Point s(6, 2);

    cout << "Number of Points: " << Point::getCount() << endl;
    cout << "Distance b/w p and q: " << p.distance(q) << endl;
    cout << "Distance b/w p and q: " << Point::distance(p, q) << endl;
    cout << "Distance b/w r and s: " << Point::distance(r, s) << endl;


    return 0;
}