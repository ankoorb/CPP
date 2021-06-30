#include <iostream>
#include <cassert>

using namespace std;

struct Date {
    int day {1};
    int month {1};
    int year {0};
};

struct NewDate {
private:
    int day {1};
    int month {1};
    int year {0};

public:
    // Accessors
    int Day(){ return day; }
    int Month() { return month; }
    int Year() { return year; }

    // Mutators
    void Day(int d) { day = d; }
    void Month(int m) { month = m; }
    void Year(int y) { year = y; }
};

int main() {

    Date date;

    assert(date.day == 1);
    assert(date.month == 1);
    assert(date.year == 0);

    cout << date.day << "/" << date.month << "/" << date.year << endl;

    NewDate ndate;

    ndate.Day(7);
    ndate.Month(4);
    ndate.Year(1987);
    assert(ndate.Day() == 7);
    assert(ndate.Month() == 4);
    assert(ndate.Year() == 1987);

    cout << ndate.Day() << "/" << ndate.Month() << "/" << ndate.Year() << endl;

    return 0;
}