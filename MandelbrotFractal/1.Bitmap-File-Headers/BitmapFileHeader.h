//
// Created by Ankoor Bhagat on 7/21/18.
//

#ifndef INC_1_BITMAP_FILE_HEADERS_BITMAPFILEHEADER_H
#define INC_1_BITMAP_FILE_HEADERS_BITMAPFILEHEADER_H

#include <cstdint>  // For using 32 bit integer type
using namespace std;

// Create a struct
#pragma pack(2)  //  2 byte boundaries
struct BitmapFileHeader {
    char header[2]{'B', 'M'};
    int32_t fileSize;
    int32_t reserved{0};
    int32_t dataOffset;
};

#endif //INC_1_BITMAP_FILE_HEADERS_BITMAPFILEHEADER_H
