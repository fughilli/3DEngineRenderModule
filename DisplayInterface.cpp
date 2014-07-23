#include "DisplayInterface.h"

#ifdef ENERGIA
#include "LCD_screen.h"

class LCDDisplay : public DisplayInterface
{
private:
    LCD_screen * diScreen;
public:
    LCDDisplay(LCD_screen_font& _diScreen);
    void drawTri(tri_2d_t& tri, uint16_t color);
};

LCDDisplay::LCDDisplay(LCD_screen_font& _diScreen)
{
    diScreen = *_diScreen;
}

void LCDDisplay::drawTri(tri_2d_t& tri, uint16_t color)
{
    diScreen->triangle(tri.x1, tri.y1, tri.x2, tri.y2, tri.x3, tri.y3, color);
}
#else

#endif

G3D_Color rgbToColor(uint8_t r, uint8_t g, uint8_t b)
{
    return {r,g,b};//G3D_Color(r, g, b);
}
G3D_Color grayscaleToColor(uint8_t grayscale)
{
    return {grayscale,grayscale,grayscale};//G3D_Color(grayscale, grayscale, grayscale);
}
