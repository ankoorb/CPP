#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    // 0xFF123456, 2 digits in hex corresponds to 1 byte

    // NOTE: 2 digits in
    unsigned char alpha = 0xFF;
    unsigned char red = 0x12;
    unsigned char green = 0x34;
    unsigned char blue = 0x56;


    unsigned int color = 0;  // 4 bytes: 1st byte: alpha, 2nd byte: red, and so on


    cout << color << endl;  // Display in Decimal
    cout << hex << color << endl;  // Display in Hexadecimal

    cout << setfill('0') << setw(8) << hex << color << endl;

    // Left shift bit
//    color = color << 24;  // color <<= 8;
//    cout << setfill('0') << setw(8) << hex << color << endl;

    color += alpha;
    color <<= 8;
    color += red;
    color <<=8;
    color += green;
    color <<= 8;
    color += blue;
    cout << setfill('0') << setw(8) << hex << color << endl;

    cout << sizeof(unsigned char) << endl;

    return 0;
}