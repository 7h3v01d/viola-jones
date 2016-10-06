#include "IntegralImage.h"

IntegralImage::IntegralImage(int width, int height)
{
    this->width = width;
    this->height = height;
    integrals = new int[width * height];
}

IntegralImage::~IntegralImage()
{
    delete[] integrals;
}

int IntegralImage::getWidth() const
{
    return width;
}

int IntegralImage::getHeight() const
{
    return height;
}

/**
 * @throw std::out_of_range
 */
int IntegralImage::getIntegral(int x, int y) const
{
    if (x >= width
            || y >= height
            || x < 0
            || y < 0) {
        throw std::out_of_range(std::string("invalid coordinates"));
    }

    return integrals[(y * width) + x];
}

IntegralImage& IntegralImage::fromImage(Image& image)
{
    IntegralImage *integral = new IntegralImage(image.getWidth(), image.getHeight());

    return *integral;
}
