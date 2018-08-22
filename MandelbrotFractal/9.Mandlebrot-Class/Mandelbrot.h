//
// Created by Ankoor Bhagat on 8/17/18.
//

#ifndef INC_9_MANDLEBROT_CLASS_MANDELBROT_H
#define INC_9_MANDLEBROT_CLASS_MANDELBROT_H


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


#endif //INC_9_MANDLEBROT_CLASS_MANDELBROT_H
