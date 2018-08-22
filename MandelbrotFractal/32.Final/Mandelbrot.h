//
// Created by Ankoor Bhagat on 8/21/18.
//

#ifndef INC_32_FINAL_MANDELBROT_H
#define INC_32_FINAL_MANDELBROT_H


namespace fractal {

    class Mandelbrot {
    public:
        static const int MAX_ITERATIONS = 1000;

    public:
        Mandelbrot();
        virtual ~Mandelbrot();

        static int getIterations(double x, double y);

    };
}


#endif //INC_32_FINAL_MANDELBROT_H
