//
// Created by Ankoor Bhagat on 8/16/18.
//

#include "Bitmap.h"

namespace fractal {

    Bitmap::Bitmap(int width, int height)
            : m_width(width), m_height(height), m_pPixel(new uint8_t[width * height * 3]) {};
    Bitmap::~Bitmap() {};

    bool Bitmap::write(string filename) {
        return false;
    }

    void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {}

}
