//
// Created by Ankoor Bhagat on 8/20/18.
//

#ifndef INC_17_COLOR_TRANSFORMS_BITMAPFILEHEADER_H
#define INC_17_COLOR_TRANSFORMS_BITMAPFILEHEADER_H

#include <cstdint>  // For using 32 bit integer type
using namespace std;

#pragma pack(2)

namespace fractal {

    // Create a struct
    struct BitmapFileHeader {
        char header[2]{'B', 'M'};  // In C++ 11 {value} is used to initialize variable
        int32_t fileSize;
        int32_t reserved{0};
        int32_t dataOffset;
    };

}

#endif //INC_17_COLOR_TRANSFORMS_BITMAPFILEHEADER_H
