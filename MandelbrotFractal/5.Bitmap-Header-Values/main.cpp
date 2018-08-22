#include <iostream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"


int main() {

    using namespace fractal;
    cout << sizeof(BitmapFileHeader) << endl;
    cout << sizeof(BitmapInfoHeader) << endl;

    return 0;
}