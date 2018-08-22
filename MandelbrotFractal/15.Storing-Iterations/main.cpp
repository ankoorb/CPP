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

    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{});
    unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{});

    for(int x=0; x<WIDTH; x++){
        for(int y=0; y<HEIGHT; y++){
            double xFractal = (x - WIDTH/2 - 200) * (float)2/WIDTH;
            double yFractal = (y - HEIGHT/2) * (float)2/HEIGHT;

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);

            fractal[y * WIDTH + x] = iterations;

            if(iterations != Mandelbrot::MAX_ITERATIONS){
                histogram[iterations]++;  // Incrementing pointer
            }

            uint8_t color = (uint8_t)(256 * (double)iterations/Mandelbrot::MAX_ITERATIONS);

            color = color * color * color;

            bitmap.setPixel(x, y, color, color*1.25, color*1.5);
            if(xFractal < min){ min = color; }
            if(xFractal > max){ max = color; }
        }
    }

    bitmap.write("test.bmp");
    cout << "Finished!" << endl;

    return 0;
}





