#include <iostream>
#include <string>

using namespace std;

enum class VehicleType {
    CAR = 11, BUS = 12, TRUCK = 13, BICYCLE = 14, SCOOTER = 15
};

enum class Channel {
    STDOUT, STDERR
};

void Print(Channel style, const string& msg){
    switch (style){
        case Channel::STDOUT:
            cout << msg << endl;
            break;
        case Channel::STDERR:
            cerr << msg << endl;
            break;
        default:
            cerr << "Skipping" << endl;
    }
}

int main() {
    cout << static_cast<int>(VehicleType::CAR) << endl;

    Print(Channel::STDOUT, "hello");
    Print(Channel::STDERR, "world");

    return 0;
}