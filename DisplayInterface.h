#ifndef DISPLAY_INTERFACE_H
#define DISPLAY_INTERFACE_H

#include "G3DUtilities.h"

class Triangle2d;
class Line2d;
class Vector2d;

struct G3D_Color
{
    uint8_t r, g, b;

//    G3D_Color(uint8_t _r, uint8_t _g, uint8_t _b)
//    {
//        r=_r;g=_g;b=_b;
//    }
};

class DisplayInterface
{
protected:
    virtual void triArea(const Triangle2d& tri, const G3D_Color& color);
public:
    virtual void drawBox(const Line2d& diag, const G3D_Color& color);
    virtual void drawTri(const Triangle2d& tri, const G3D_Color& color, bool filled);
    virtual void drawLine(const Line2d& line, const G3D_Color& color);
    virtual void drawPoint(const Vector2d& point, const G3D_Color& color) = 0;
    virtual void clear(const G3D_Color& color) = 0;
};

G3D_Color rgbToColor(uint8_t r, uint8_t g, uint8_t b);
G3D_Color grayscaleToColor(uint8_t grayscale);

#endif // DISPLAY_INTERFACE_H
