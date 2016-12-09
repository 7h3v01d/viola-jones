#include <stdexcept>
#include <sstream>
#include <iomanip>

#include "Image.h"
#include "ColorRgb.h"
#include "ColorGray.h"
#include "Tga.h"

Image::Image(int width, int height, int bpp):
    width(width),
    height(height),
    bpp(bpp),
    size(width * height * (bpp / 8)),
    colors(width * height)
{
    for (int i = 0; i < width * height; ++i) {
        colors[i] = new ColorRgb();
    }
}

Image::~Image()
{
    for (int i = 0; i < width * height; ++i) {
        delete colors[i];
    }
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
IColor& Image::getColor(int x, int y) const
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
 * @throw std::out_of_range
 * @throw std::bad_alloc
 */
void Image::scale(int width, int height)
{
    if (width < 1
        || height < 1) {
        throw std::out_of_range(std::string("invalid scale"));
    }
    std::vector<IColor*> newColors(width * height);
    for (int i = 0; i < width * height; ++i) {
        try {
            newColors[i] = new ColorRgb();
        }
        catch (std::bad_alloc&) {
            for (int j = 0; j < i; ++j) {
                delete newColors[j];
            }
            throw;
        }
    }
    float scaleX = static_cast<float>(this->width - 1) / static_cast<float>(width -1);
    float scaleY = static_cast<float>(this->height - 1) / static_cast<float>(height -1);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int oldX = static_cast<int>(static_cast<float>(x) * scaleX);
            int oldY = static_cast<int>(static_cast<float>(y) * scaleY);
            IColor& c = *colors[(oldY * this->width) + oldX];
            newColors[(y * width) + x]->setRgba(c.getR(), c.getG(), c.getB(), c.getA());
        }
    }
    for (int i = 0; i < this->width * this->height; ++i) {
        delete colors[i];
    }
    this->width = width;
    this->height = height;
    size = width * height * (bpp / 8);
    colors = newColors;
}

std::string Image::toString() const
{
    std::ostringstream s;
    for (int y = 0, i = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            s << std::setfill(' ') << std::setw(3) << colors[i++]->getGray();
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

/**
 * @throw std::runtime_error
 */
Image Image::loadFromFile(const std::string& filename)
{
    std::string ext = filename.substr(filename.rfind('.'));
    if (std::string(".tga") == ext) {
        File file = File::openExisting(filename);
        return loadTga(file);
    }

    throw std::runtime_error(std::string("unsupported file"));
}

Image Image::loadTga(File& file)
{
    Tga tga(file);

    Image image(tga.getWidth(), tga.getHeight(), tga.getBpp());
    tga.getColors(image.colors);

    return image;
}
