#include <stdexcept>

#include "Tga.h"


Tga::Tga(File& file):
    file(file)
{
    idLength = file.readByte();

    colorMapType = static_cast<ColorMapType>(file.readByte());
    if (NO_COLOR_MAP != colorMapType) {
        throw std::runtime_error(std::string("unsupported tga"));
    }

    imageType = static_cast<ImageType>(file.readByte());
    if (UNCOMPRESSED_TRUE_COLOR != imageType) {
        throw std::runtime_error(std::string("unsupported tga"));
    }

    file.read(static_cast<void *>(&colorMapSpecification), 5);
    if (0 != colorMapSpecification.firstEntryIndex
            || 0 != colorMapSpecification.colorMapLength
            || 0 != colorMapSpecification.colorMapEntrySize) {
        throw std::runtime_error(std::string("unsupported tga"));
    }

    file.read(static_cast<void *>(&imageSpecification), 10);
    if (0 == imageSpecification.imageWidth
            || 0 == imageSpecification.imageHeight
            || 24 != imageSpecification.pixelDepth
           // || TOP_LEFT != imageSpecification.imageDescriptor.imageOrigin
           // || 0 != imageSpecification.imageDescriptor.unused
            ) {
        throw std::runtime_error(std::string("unsupported tga"));
    }

    file.skip(idLength);

    imageDataPos = file.getPosition();
    file.skip(imageSpecification.imageWidth
            * imageSpecification.imageHeight
            * (imageSpecification.pixelDepth / 8));
}

Tga::~Tga()
{
}

int Tga::getWidth() const
{
    return imageSpecification.imageWidth;
}

int Tga::getHeight() const
{
    return imageSpecification.imageHeight;
}

int Tga::getBpp() const
{
    return imageSpecification.pixelDepth;
}

void Tga::getColors(Color *colors) const
{
    file.setPosition(imageDataPos);

    for (int y = 0; y < imageSpecification.imageHeight; ++y) {
        for (int x = 0; x < imageSpecification.imageWidth; ++x) {
            int r = file.readByte();
            int g = file.readByte();
            int b = file.readByte();
            colors[(y * imageSpecification.imageWidth) + x].setRGBA(r, g, b, 255);
        }
    }
}
