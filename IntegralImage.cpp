#include <stdexcept>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

#include "IntegralImage.h"

IntegralImage::IntegralImage(int width, int height):
    width(width),
    height(height),
    integrals(width * height)
{
}

IntegralImage::~IntegralImage()
{
}

int IntegralImage::getWidth() const
{
    return width;
}

int IntegralImage::getHeight() const
{
    return height;
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

std::string IntegralImage::toString() const
{
    std::ostringstream s;
    int w = static_cast<int>(::floor(::log10(static_cast<double>(integrals[(width * height) - 1])))) + 1;
    for (int y = 0, i = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            s << std::setfill(' ') << std::setw(w) << integrals[i++];
            if (x < width - 1) {
                s << " ";
            }
        }
        if (y < height - 1) {
            s << "\n";
        }
    }

    return s.str();
}

IntegralImage IntegralImage::fromImage(const Image& image)
{
    IntegralImage integral(image.getWidth(), image.getHeight());
    for (int y = 0; y < image.getHeight(); ++y) {
        for (int x = 0; x < image.getWidth(); ++x) {
            integral.integrals[(y * image.getWidth()) + x] = image.getColor(x, y).getGray()
                + integral.getInt(x - 1, y)
                + integral.getInt(x, y - 1)
                - integral.getInt(x - 1, y - 1);
        }
    }

    return integral;
}
