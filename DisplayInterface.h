#ifndef DISPLAY_INTERFACE_H
#define DISPLAY_INTERFACE_H

#include "G3DUtilities.h"

class DisplayInterface
{
public:
    virtual void drawTri(tri_2d_t& tri, uint16_t color);
};

uint16_t rgbToColor(uint8_t r, uint8_t g, uint8_t b)
{
    uint16_t retColor;
    retColor = (r>>3);
    retColor <<= 5;
    retColor = (g>>2);
    retColor <<= 6;
    retColor = (b>>3);
    return retColor;
}
uint16_t grayscaleToColor(uint8_t grayscale)
{
    uint16_t retColor;
    retColor = (grayscale>>3);
    retColor <<= 5;
    retColor = (grayscale>>2);
    retColor <<= 6;
    retColor = (grayscale>>3);
    return retColor;
}

#endif // DISPLAY_INTERFACE_H
