//
// Created by Ankoor Bhagat on 8/20/18.
//

#ifndef INC_18_ZOOM_CLASS_MANDELBRO_H
#define INC_18_ZOOM_CLASS_MANDELBRO_H


namespace fractal {

    class Mandelbrot {
    public:
        static const int MAX_ITERATIONS = 10000;

    public:
        Mandelbrot();
        virtual ~Mandelbrot();

        static int getIterations(double x, double y);

    };
}


#endif //INC_18_ZOOM_CLASS_MANDELBRO_H
