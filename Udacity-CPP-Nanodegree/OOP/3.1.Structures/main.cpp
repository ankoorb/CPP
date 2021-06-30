#include <iostream>
#include <cassert>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

int main() {

    Date date;

    date.day = 29;
    date.month = 8;
    date.year = 1981;

    assert(date.day == 29);
    assert(date.month == 8);
    assert(date.year == 1981);

    cout << date.day << "/" << date.month << "/" << date.year << endl;

    return 0;
}