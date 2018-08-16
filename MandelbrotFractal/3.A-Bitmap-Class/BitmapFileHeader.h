//
// Created by Ankoor Bhagat on 7/22/18.
//

#ifndef INC_3_A_BITMAP_CLASS_BITMAPFILEHEADER_H
#define INC_3_A_BITMAP_CLASS_BITMAPFILEHEADER_H


#include <cstdint>  // For using 32 bit integer type
using namespace std;

namespace fractal {

    // Create a struct
    #pragma pack(2)
    struct BitmapFileHeader {
        char header[2]{'B', 'M'};  // In C++ 11 {value} is used to initialize variable
        int32_t fileSize;
        int32_t reserved{0};
        int32_t dataOffset;
    };

}

#endif //INC_3_A_BITMAP_CLASS_BITMAPFILEHEADER_H
