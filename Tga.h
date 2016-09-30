#ifndef __TGA_H__
#define __TGA_H__

#include "Color.h"
#include "File.h"


class Tga
{
    private:
        enum ColorMapType {
            NO_COLOR_MAP = 0,
            COLOR_MAP = 1
        };
        enum ImageType {
            NO_IMAGE_DATA = 0,
            UNCOMPRESSED_COLOR_MAPPED = 1,
            UNCOMPRESSED_TRUE_COLOR = 2,
            UNOMPRESSED_BLACK_AND_WHITE = 3,
            RLE_COLOR_MAPPED = 9,
            RLE_TRUE_COLOR = 10,
            RLE_BLACK_AND_WHITE = 11
        };
        enum ImageOrigin {
            BOTTOM_LEFT = 0,
            BOTTOM_RIGHT = 1,
            TOP_LEFT = 2,
            TOP_RIGHT = 3
        };
        struct ColorMapSpecification {
            int firstEntryIndex:16;
            int colorMapLength:16;
            int colorMapEntrySize:8;
        };
        struct ImageDescriptor {
            int alphaChannelBits:4;
            ImageOrigin imageOrigin:2;
            int unused:2;
        };
        struct ImageSpecification {
            int xOriginOfImage:16;
            int yOriginOfImage:16;
            int imageWidth:16;
            int imageHeight:16;
            int pixelDepth:8;
            ImageDescriptor imageDescriptor;
        };

    private:
        File& file;
        int idLength;
        ColorMapType colorMapType;
        ImageType imageType;
        ColorMapSpecification colorMapSpecification;
        ImageSpecification imageSpecification;
        int imageDataPos;


    public:
        int getWidth() const;
        int getHeight() const;
        int getBpp() const;
        void getColors(Color *colors[]) const;

    private:
        Tga(File& file);

    public:
        ~Tga();

    public:
        friend class Image;
};

#endif /* __TGA_H__ */
