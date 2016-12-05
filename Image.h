#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <vector>
#include <string>

#include "IColor.h"
#include "File.h"

class Image
{
    private:
        int width;
        int height;
        int bpp;
        int size;
        std::vector<IColor*> colors;

    public:
        int getWidth() const;
        int getHeight() const;
        int getBpp() const;
        int getSize() const;
        IColor& getColor(int x, int y) const;
        void scale(int width, int height);
        std::string toString() const;

    private:
        Image();
        Image& operator=(const Image&);
        Image(int width, int height, int bpp);

    public:
        ~Image();

    public:
        static Image loadFromFile(const std::string& filename);

    private:
        static Image loadTga(File& file);
};

#endif /* __IMAGE_H__ */
