#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using namespace std;


class Date {
private:
    int day {1};
    int month {1};
    int year {0};
    bool leapYear(int y) const;
    int daysInMonth(int m, int y) const;

public:
    Date(int d, int m, int y);
    int Day() const { return day; }
    int Month() const { return month; }
    int Year() const { return year; }
    void Day(int d);
    void Month(int m);
    void Year(int y);
    string String() const;
};


int main() {

    Date date(29, 2, 2020);

    assert(date.Day() == 29);
    assert(date.Month() == 2);
    assert(date.Year() == 2020);
    assert(date.String() == "February 29, 2020");

    cout << date.Day() << "/" << date.Month() << "/" << date.Year() << endl;

    return 0;
}


Date::Date(int d, int m, int y) {
    Year(y);
    Month(m);
    Day(d);
}

void Date::Day(int d) {
    if (d >= 1 && d <= daysInMonth(Month(), Year())){
        day = d;
    }
}

void Date::Month(int m) {
    if (m >= 1 && m <= 12){
        month = m;
    }
}

void Date::Year(int y) { year = y; }

int Date::daysInMonth(int m, int y) const {
    if (m == 2){
        return leapYear(y) ? 29 : 28;
    } else if (m == 4 || m == 6 || m == 9 || m == 11){
        return 30;
    } else {
        return 31;
    }
}

bool Date::leapYear(int y) const {
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

string Date::String() const {
    vector<string> months {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[month-1] + " " + to_string(Day()) + ", " + to_string(Year());
}











