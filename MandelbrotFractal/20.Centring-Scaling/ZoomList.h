//
// Created by Ankoor Bhagat on 8/21/18.
//

#ifndef INC_20_CENTRING_SCALING_ZOOMLIST_H
#define INC_20_CENTRING_SCALING_ZOOMLIST_H


#include <vector>
#include <utility>
#include "Zoom.h"
using namespace std;
namespace fractal {

    class ZoomList {
    private:
        double m_xCenter{0};
        double m_yCenter{0};
        double m_scale{1.0};
        int m_width{0};
        int m_height{0};
        vector<Zoom> zooms;
    public:
        ZoomList(int width, int height);
        void add(const Zoom &zoom);
        pair<double, double> doZoom(int x, int y);
    };

}



#endif //INC_19_ZOOM_LIST_CLASS_ZOOMLIST_H
