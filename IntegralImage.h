#ifndef __INTEGRALIMAGE_H__
#define __INTEGRALIMAGE_H__

#include <string>

#include "Image.h"


class IntegralImage
{
    private:
        int width;
        int height;
        int size;
        int *integrals;

    public:
        int getWidth() const;
        int getHeight() const;
        int getSize() const;
        int getIntegral(int x, int y) const;
        std::string toString() const;

    private:
        int getInt(int x, int y) const;

    private:
        IntegralImage();
        IntegralImage(const IntegralImage&);
        IntegralImage(int width, int height);
        IntegralImage& operator=(IntegralImage&);

    public:
        ~IntegralImage();

    public:
        static IntegralImage& fromImage(Image& image);
};

#endif /* __INTEGRALIMAGE_H__ */
