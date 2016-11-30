#include "Rectangle.h"

/**
 * @throw std::out_of_range
 */
Rectangle::Rectangle(int x, int y, int width, int height, double weight):
        x(x),
        y(y),
        width(width),
        height(height),
        weight(weight)
{
    if (width < 1
            || height < 1) {
        throw std::out_of_range(std::string("invalid dimensions"));
    }
}

Rectangle::~Rectangle()
{
}

int Rectangle::getX() const
{
    return x;
}

int Rectangle::getY() const
{
    return y;
}

int Rectangle::getWidth() const
{
    return width;
}

int Rectangle::getHeight() const
{
    return height;
}

double Rectangle::getWeight() const
{
    return weight;
}
