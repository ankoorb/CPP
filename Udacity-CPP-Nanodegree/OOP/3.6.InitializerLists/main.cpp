#include <iostream>
#include <cassert>

using namespace std;

namespace English {
    void Hello() { std::cout << "Hello, World!" << endl; }
}

namespace Spanish {
    void Hello() { cout << "Hola, Mundo!" << endl; }
}

class Date {
private:
    int day {1};
    int month {1};
    int year {0};

public:
    Date(int d, int m, int y);

    // Accessors
    int Day();
    int Month();
    int Year();

    // Mutators
    void Day(int d);
    void Month(int m);
    void Year(int y);
};

class Person {
public:
    string name;
    Person(string name): name(name) {}

    void display(){ cout << "Person name is: " << name << endl; }
};


int main() {

    Date date(-7, 14, 1987);

    assert(date.Day() == 1);
    assert(date.Month() == 1);
    assert(date.Year() == 1987);

    cout << date.Day() << "/" << date.Month() << "/" << date.Year() << endl;

    English::Hello();
    Spanish::Hello();

    Person ankoor("Ankoor");
    ankoor.display();

    Person allie("Allie");
    allie.display();

    assert(ankoor.name != allie.name);

    return 0;
}


Date::Date(int d, int m, int y) : year(y) { // Only year because of invariant in month and day
    Day(d);
    Month(m);
}

int Date::Day() { return day; }

int Date::Month() { return month; }

int Date::Year() { return year; }

void Date::Day(int d) { if (d >= 1 && d <= 31) day = d; }

void Date::Month(int m) { if (m >= 1 && m <= 12) month = m; }

void Date::Year(int y) { year = y; }