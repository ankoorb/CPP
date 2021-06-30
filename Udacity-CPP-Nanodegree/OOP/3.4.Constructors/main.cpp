#include <iostream>
#include <cassert>

using namespace std;

class Date {
private:
    int day {1};
    int month {1};
    int year {0};

public:
    Date(int d, int m, int y){
        Day(d);
        Month(m);
        Year(y);
    }

    // Accessors
    int Day(){ return day; }
    int Month(){ return month; }
    int Year(){ return year; }

    // Mutators
    void Day(int d){ if (d >= 1 && d <= 31) day = d; }
    void Month(int m){ if (m >= 1 && m <= 12) month = m; }
    void Year(int y){ year = y; }
};


int main() {

    Date date(-7, 14, 1987);

    assert(date.Day() == 1);
    assert(date.Month() == 1);
    assert(date.Year() == 1987);

    cout << date.Day() << "/" << date.Month() << "/" << date.Year() << endl;

    return 0;
}
