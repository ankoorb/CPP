//
// Created by Ankoor Bhagat on 8/21/18.
//

#ifndef INC_25_RGB_CLASS_RGB_H
#define INC_25_RGB_CLASS_RGB_H

namespace fractal {
    struct RGB {
        double r;
        double g;
        double b;
        RGB(double r, double g, double b);
    };

    RGB operator-(const RGB& first, const RGB& second);
}


#endif //INC_25_RGB_CLASS_RGB_H
