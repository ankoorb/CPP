//
// Created by Ankoor Bhagat on 8/21/18.
//

#ifndef INC_18_ZOOM_CLASS_ZOOM_H
#define INC_18_ZOOM_CLASS_ZOOM_H

struct Zoom {
    int x{0};
    int y{0};
    double scale{0.0};
    Zoom(int x, int y, double scale): x(x), y(y), scale(scale){};
};

#endif //INC_18_ZOOM_CLASS_ZOOM_H
