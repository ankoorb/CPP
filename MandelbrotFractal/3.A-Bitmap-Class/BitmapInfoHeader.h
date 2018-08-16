//
// Created by Ankoor Bhagat on 7/22/18.
//

#ifndef INC_3_A_BITMAP_CLASS_BITMAPINFOHEADER_H
#define INC_3_A_BITMAP_CLASS_BITMAPINFOHEADER_H

#include <cstdint>
using namespace std;

namespace fractal {

    #pragma pack(2)
    struct BitmapInfoHeader {
        int32_t headerSize{40};  // Total bytes = 40 so memory sum from width to importantColors = 40
        int32_t width;
        int32_t height;
        int16_t planes{1};
        int16_t bitsPerPixel{24};
        int32_t compression{0};
        int32_t dataSize{0};
        int32_t horizontalResolution{2400};
        int32_t verticalResolution{2400};
        int32_t colors{0};
        int32_t importantColors{0};
    };

}

#endif //INC_3_A_BITMAP_CLASS_BITMAPINFOHEADER_H
