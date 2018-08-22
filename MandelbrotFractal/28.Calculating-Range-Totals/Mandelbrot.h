//
// Created by Ankoor Bhagat on 8/21/18.
//

#ifndef INC_23_REORGANIZING_MAIN_MANDELBROT_H
#define INC_23_REORGANIZING_MAIN_MANDELBROT_H


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


#endif //INC_19_ZOOM_LIST_CLASS_MANDELBROT_H
