#include <stdexcept>
#include <string>

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
            || BOTTOM_LEFT != imageSpecification.imageDescriptor.imageOrigin
            || 0 != imageSpecification.imageDescriptor.unused
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

void Tga::getColors(std::vector<IColor*> colors) const
{
    file.setPosition(imageDataPos);

    for (int y = imageSpecification.imageHeight - 1; y >= 0; --y) {
        for (int x = 0; x < imageSpecification.imageWidth; ++x) {
            int b = file.readByte();
            int g = file.readByte();
            int r = file.readByte();
            colors[(y * imageSpecification.imageWidth) + x]->setRgba(r, g, b, 255);
        }
    }
}
