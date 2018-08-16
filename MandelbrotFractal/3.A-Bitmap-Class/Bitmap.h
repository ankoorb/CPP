//
// Created by Ankoor Bhagat on 7/22/18.
//

#ifndef INC_3_A_BITMAP_CLASS_BITMAP_H
#define INC_3_A_BITMAP_CLASS_BITMAP_H

#include <string>
#include <cstdint>
using namespace std;

namespace fractal {

    class Bitmap {
    private:
        int m_width{0};  // Initialize to 0
        int m_height{0};
    public:
        Bitmap(int width, int height);
        bool write(string filename);
        void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
        virtual ~Bitmap();

    };
}

#endif //INC_3_A_BITMAP_CLASS_BITMAP_H
