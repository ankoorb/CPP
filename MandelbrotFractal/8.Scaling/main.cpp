#include <iostream>
#include "Bitmap.h"

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

            if(xFractal < min){ min = xFractal; }
            if(xFractal > max){ max = xFractal; }
        }
    }

    bitmap.write("test.bmp");

    cout << "Min: " << min << ", Max: " << max << endl;

    cout << "Finished!" << endl;

    return 0;
}


