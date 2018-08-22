#include <iostream>
#include "FractalCreator.h"

using namespace std;
using namespace fractal;


int main() {

    FractalCreator fractalCreator(800, 600);

    fractalCreator.addRange(0.0, RGB(0, 0, 255));
    fractalCreator.addRange(0.3, RGB(255, 0, 0));
    fractalCreator.addRange(0.5, RGB(0, 255, 0));
    fractalCreator.addRange(0.7, RGB(0, 255, 0));
    fractalCreator.addRange(1.0, RGB(0, 255, 0));

    fractalCreator.addZoom(Zoom(295, 202, 0.1));
    fractalCreator.addZoom(Zoom(312, 304, 0.1));

    fractalCreator.run("test.bmp");

    cout << "Mandelbrot Fractal Created!" << endl;

    return 0;
}





