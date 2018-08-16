//
// Created by Ankoor Bhagat on 7/22/18.
//

#include "Bitmap.h"

namespace fractal {

    Bitmap::Bitmap(int width, int height): m_width(width), m_height(height) {};
    Bitmap::~Bitmap() {};

    bool Bitmap::write(string filename) {
        return false;
    }

    void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {}

}
