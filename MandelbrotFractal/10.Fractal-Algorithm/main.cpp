#include <iostream>
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace std;
using namespace fractal;


int main() {

    int const WIDTH = 800;
    int const HEIGHT = 600;
    Bitmap bitmap(WIDTH, HEIGHT);

    double min = 999999;
    double max = -999999;

    for(int x=0; x<WIDTH; x++){
        for(int y=0; y<HEIGHT; y++){
            double xFractal = (x - WIDTH/2) * (float)2/WIDTH;
            double yFractal = (y - HEIGHT/2) * (float)2/HEIGHT;

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);
            uint8_t red = (uint8_t)(256 * (double)iterations/Mandelbrot::MAX_ITERATIONS);

            red = red * red;

            bitmap.setPixel(x, y, red, 0, 0);
            if(xFractal < min){ min = red; }
            if(xFractal > max){ max = red; }
        }
    }

    bitmap.write("test.bmp");

    cout << "Min: " << min << ", Max: " << max << endl;

    cout << "Finished!" << endl;

    return 0;
}


