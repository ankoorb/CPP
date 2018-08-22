//
// Created by Ankoor Bhagat on 8/16/18.
//

#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace fractal;

namespace fractal {

    Bitmap::Bitmap(int width, int height)
            : m_width(width), m_height(height), m_pPixel(new uint8_t[width * height * 3]{}) {};  // Memory init to 0
    Bitmap::~Bitmap() {};

    bool Bitmap::write(string filename) {
        BitmapFileHeader fileHeader;
        BitmapInfoHeader infoHeader;

        fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;

        // dataOffset: Distance from beginning of the file to where the data actually starts
        fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

        infoHeader.width = m_width;
        infoHeader.height = m_height;

        return false;
    }

    void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {}

}