//
// Created by Ankoor Bhagat on 8/20/18.
//


#include <complex>
#include "Mandelbrot.h"

using namespace std;

namespace fractal {

    int Mandelbrot::getIterations(double x, double y){

        complex<double> z = 0;
        complex<double> c(x, y);

        int iterations = 0;

        while(iterations < MAX_ITERATIONS){
            z = z*z + c;

            if(abs(z) > 2){  // Absolute value of complex number
                break;
            }

            iterations++;
        }

        return iterations;
    }
}
