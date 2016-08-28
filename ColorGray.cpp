#include "ColorGray.h"


ColorGray::ColorGray()
{
    gray = 0;
}

ColorGray::ColorGray(int gray)
{
    this->gray = gray < 0 ? 0 : gray > 255 ? 255 : gray;
}

ColorGray::~ColorGray()
{
}

int ColorGray::getBpp() const
{
    return 8;
}

int ColorGray::getR() const
{
    return gray;
}

int ColorGray::getG() const
{
    return gray;
}

int ColorGray::getB() const
{
    return gray;
}

int ColorGray::getA() const
{
    return 255;
}

int ColorGray::getGray() const
{
    return gray;
}

void ColorGray::setRgba(int r, int g, int b, int a)
{
    (void)a;

    r = r < 0 ? 0 : r > 255 ? 255 : r;
    g = g < 0 ? 0 : g > 255 ? 255 : g;
    b = b < 0 ? 0 : b > 255 ? 255 : b;
    this->gray = static_cast<int>(((0.21f * static_cast<float>(r))
            + (0.72f * static_cast<float>(g))
            + (0.07f * static_cast<float>(b))));
}

void ColorGray::setGray(int gray)
{
    this->gray = gray < 0 ? 0 : gray > 255 ? 255 : gray;
}
