//
// Created by Ankoor Bhagat on 8/21/18.
//

#ifndef INC_22_REORGANIZING_MAIN_FRACTALCREATOR_H
#define INC_22_REORGANIZING_MAIN_FRACTALCREATOR_H

#include <string>
#include "Zoom.h"
using namespace std;

namespace fractal {
    class FractalCreator {
    public:
        FractalCreator(int width, int height);
        virtual ~FractalCreator();

        void calculateIteration();
        void drawFractal();
        void addZoom(const Zoom &zoom);
        void writeBitmap(string name);
    };
}


#endif //INC_22_REORGANIZING_MAIN_FRACTALCREATOR_H
