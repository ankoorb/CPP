//
// Created by Ankoor Bhagat on 8/17/18.
//

#ifndef INC_10_FRACTAL_ALGORITHM_BITMAP_H
#define INC_10_FRACTAL_ALGORITHM_BITMAP_H


#include <string>
#include <cstdint>
using namespace std;

namespace fractal {

    class Bitmap {
    private:
        int m_width{0};
        int m_height{0};

        unique_ptr<uint8_t[]> m_pPixel{nullptr};

    public:
        Bitmap(int width, int height);
        bool write(string filename);
        void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
        virtual ~Bitmap();

    };
}


#endif //INC_10_FRACTAL_ALGORITHM_BITMAP_H
