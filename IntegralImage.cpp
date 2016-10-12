#include <stdexcept>
#include <string>

#include "IntegralImage.h"

IntegralImage::IntegralImage(int width, int height)
{
    this->width = width;
    this->height = height;
    size = width * height * sizeof(int);
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

int IntegralImage::getSize() const
{
    return size;
}

int IntegralImage::getInt(int x, int y) const
{
    try {
        return getIntegral(x, y);
    }
    catch (std::out_of_range& e) {}

    return 0;
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
    for (int y = 0; y < image.getHeight(); ++y) {
        for (int x = 0; x < image.getWidth(); ++x) {
            integral->integrals[(y * image.getWidth()) + x] = image.getColor(x, y).getGray()
                    + integral->getInt(x - 1, y)
                    + integral->getInt(x, y - 1)
                    - integral->getInt(x - 1, y - 1);
        }
    }

    return *integral;
}
