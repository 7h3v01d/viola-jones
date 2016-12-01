#include "ColorRgb.h"


ColorRgb::ColorRgb():
    r(0),
    g(0),
    b(0)
{
}

ColorRgb::ColorRgb(int r, int g, int b)
{
    this->r = r < 0 ? 0 : r > 255 ? 255 : r;
    this->g = g < 0 ? 0 : g > 255 ? 255 : g;
    this->b = b < 0 ? 0 : b > 255 ? 255 : b;
}

ColorRgb::~ColorRgb()
{
}

int ColorRgb::getBpp() const
{
    return 24;
}

int ColorRgb::getR() const
{
    return r;
}

int ColorRgb::getG() const
{
    return g;
}

int ColorRgb::getB() const
{
    return b;
}

int ColorRgb::getA() const
{
    return 255;
}

int ColorRgb::getGray() const
{
    return static_cast<int>((0.21f * static_cast<float>(r))
            + (0.72f * static_cast<float>(g))
            + (0.07f * static_cast<float>(b)));
}

void ColorRgb::setRgba(int r, int g, int b, int a)
{
    (void)a;

    this->r = r < 0 ? 0 : r > 255 ? 255 : r;
    this->g = g < 0 ? 0 : g > 255 ? 255 : g;
    this->b = b < 0 ? 0 : b > 255 ? 255 : b;
}

void ColorRgb::setGray(int gray)
{
    gray = gray < 0 ? 0 : gray > 255 ? 255 : gray;
    r = gray;
    g = gray;
    b = gray;
}
