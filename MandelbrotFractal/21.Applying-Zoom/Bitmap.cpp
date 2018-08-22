//
// Created by Ankoor Bhagat on 8/21/18.
//

#include <fstream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace std;
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

        // Writing Bitmap
        ofstream file;
        file.open(filename, ios::out|ios::binary);

        if (!file){
            return false;
        }

        // Writing data to the file
        file.write((char *)&fileHeader, sizeof(fileHeader));
        file.write((char *)&infoHeader, sizeof(infoHeader));

        // error: cannot cast from type 'unique_ptr<uint8_t []>' to pointer type 'char *'
        // Instead of unique_ptr type object we need raw pointer to cast it to 'char *' pointer, so use
        // get() method of unique_ptr
        file.write((char *)m_pPixel.get(), m_width * m_height * 3);  // Writing pixel data


        file.close();
        if (!file){
            return false;
        }

        return true;
    }

    void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {

        // unique_ptr can not be cast to an ordinary pointer so use get() to get pointer to the underlying memory
        // managed by unique_ptr
        uint8_t *pPixel = m_pPixel.get();

        pPixel += (y * 3) * m_width + (x * 3); // y * m_width -> Number of pixels before the one we are interested in

        // Reverse order because of Bitmap format
        pPixel[0] = blue;
        pPixel[1] = green;
        pPixel[2] = red;
    }

}
