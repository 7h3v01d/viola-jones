#include <cstdlib>

#include <stdexcept>

#include "Image.h"
#include "ColorRgb.h"
#include "ColorGray.h"
#include "Tga.h"


Image::Image(int width, int height, int bpp)
{
    this->width = width;
    this->height = height;
    this->bpp = bpp;
    size = width * height * (bpp / 8);
    colors = new Color*[width * height];
    for (int i = 0; i < width * height; ++i) {
        colors[i] = new ColorRgb();
    }
}

Image::~Image()
{
    for (int i = 0; i < width * height; ++i) {
        delete colors[i];
    }
    delete[] colors;
}

int Image::getWidth() const
{
    return width;
}

int Image::getHeight() const
{
    return height;
}

int Image::getBpp() const
{
    return bpp;
}

int Image::getSize() const
{
    return size;
}

/**
 * @throw std::out_of_range
 */
Color& Image::getColor(int x, int y) const
{
    if (x >= width
            || y >= height
            || x < 0
            || y < 0) {
        throw std::out_of_range(std::string("invalid coordinates"));
    }

    return *colors[(y * width) + x];
}

/**
 * @throw std::runtime_error
 */
Image& Image::loadFromFile(const std::string& filename)
{
    std::string ext = filename.substr(filename.rfind('.'));
    if (std::string(".tga") == ext) {
        return loadTga(File::openExisting(filename));
    }

    throw std::runtime_error(std::string("unsupported file"));
}

Image& Image::loadTga(File& file)
{
    Tga tga(file);

    Image *image = new Image(tga.getWidth(), tga.getHeight(), tga.getBpp());
    tga.getColors(image->colors);

    return *image;
}
