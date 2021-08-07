#include <iostream>
#include <vector>
using namespace std;

class Point {
public:
    int x_;
    int y_;

    Point(int x, int y) : x_{x}, y_{y} {}

    friend ostream& operator<<(ostream& os, const Point& pt);
};

ostream& operator<<(ostream& os, const Point& pt){
    os << "(" << pt.x_ << ", " << pt.y_ << ")";
    return os;
}

int main() {

    // Sort in reverse
    auto cmp = [](const auto& a, const auto& b){ return a > b; };
    vector<int> v = {4, 7, 1, 6, 7, 8, 2, 4};
    sort(v.begin(), v.end(), cmp);
    cout << "Reverse sort also be done by using sort(v.rbegin(), v.rend())" << endl;
    // sort(v.rbegin(), v.rend());
    cout << "Reverse sort o/p: " << flush;
    for (const auto& e: v){
        cout << e << " " << flush;
    }
    cout << endl;


    // Sort points such that coordinate x appears first, if x's are equal sort according to y
    vector<Point> points;
    vector<pair<int, int>> data = {{1, 4}, {2, 4}, {1, 2}, {2, 5}, {3, 1}, {5, 8}, {5, 2}, {1, -1}, {2, -3}};
    for (const auto& d: data){
        points.emplace_back(Point(d.first, d.second));
    }
    cout << "Before sort i/p: " << flush;
    for (const auto& point: points){
        cout << point << ", " << flush;
    }
    cout << endl;

    auto point_cmp = [](const auto& a, const auto& b){
        if (a.x_ < b.x_){
            return true;
        } else if (a.x_ == b.x_){
            return a.y_ < b.y_;
        }
        return false;
    };

    cout << " After sort o/p: " << flush;
    sort(points.begin(), points.end(), point_cmp);
    for (const auto& point: points){
        cout << point << ", " << flush;
    }
    cout << endl;

    return 0;
}