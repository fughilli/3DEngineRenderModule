#include "DisplayInterface.h"
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
