#include <iostream>
using namespace std;

int main() {

    // 32 bit color in hex
    //int color = 0x12345687;  // RGBA

    int color = 0x123456;  // RGB for simplicity, each is one byte

    int red = color & 0xFF0000;

    // 0xFF0000 = 111111110000000000000000 (8: 1, 8:0, 8:0) is called mask

    // Bitwise & operator will look at each bit in color and mask and set value if there is 1 else set 0

    cout << hex << "color: " << color << endl;
    cout << hex << "  red: " << red << endl;
    cout << endl;


    // Bitshift to get value
    int RED = (color & 0xFF0000) >> 16;  // shifting by 2 bytes, i.e. 2 * 8 bits
    int GREEN = (color & 0x00FF00) >> 8; // shifting by 1 byte
    int BLUE = (color & 0x0000FF); //

    cout << hex << "  RED: " << RED << endl;
    cout << hex << "GREEN: " << GREEN << endl;
    cout << hex << " BLUE: " << BLUE << endl;
    cout << endl;

    // Or do the following instead of bits
    unsigned char uRed = color >> 16;
    unsigned char uGreen = color >> 8;
    unsigned char uBlue = color;
    cout << hex << "  uRed: " << (int)uRed << endl;
    cout << hex << "uGreen: " << (int)uGreen << endl;
    cout << hex << " uBlue: " << (int)uBlue << endl;

    /*
     *
     */

    return 0;
}