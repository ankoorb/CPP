#include <iostream>
#include "Bitmap.h"

using namespace std;
using namespace fractal;


int main() {

    int const WIDTH = 800;
    int const HEIGHT = 600;
    Bitmap bitmap(WIDTH, HEIGHT);

    for(int x=0; x<WIDTH; x++){
        for(int y=0; y<HEIGHT; y++){
            bitmap.setPixel(x, y, 255, 99, 71);
        }
    }

    bitmap.write("test.bmp");


    cout << "Finished!" << endl;

    return 0;
}


