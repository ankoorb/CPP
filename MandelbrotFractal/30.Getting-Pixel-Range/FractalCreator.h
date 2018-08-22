//
// Created by Ankoor Bhagat on 8/21/18.
//

#ifndef INC_22_REORGANIZING_MAIN_FRACTALCREATOR_H
#define INC_22_REORGANIZING_MAIN_FRACTALCREATOR_H

#include <string>
#include <math.h>
#include <vector>
#include "Zoom.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"

using namespace std;

namespace fractal {
    class FractalCreator {
    private:
        int m_width;
        int m_height;
        unique_ptr<int[]> m_histogram;
        unique_ptr<int[]> m_fractal;
        Bitmap m_bitmap;
        ZoomList m_zoomlist;
        int m_total{0};

        vector<int> m_ranges;
        vector<RGB> m_colors;
        vector<int> m_rangeTotals;

        bool m_bGotFirstRange{false};

    public:
        FractalCreator(int width, int height);
        virtual ~FractalCreator();
        void addZoom(const Zoom &zoom);
        void addRange(double rangeEnd, const RGB& rgb);
        int getRange(int iterations) const;

    private:
        void calculateIteration();
        void calculateTotalIterations();
        void calculateRangeTotals();
        void drawFractal();
        void writeBitmap(string name);


    public:
        void run(string name);
    };
}


#endif //INC_22_REORGANIZING_MAIN_FRACTALCREATOR_H
