#ifndef __INTEGRALIMAGE_H__
#define __INTEGRALIMAGE_H__

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

    private:
        int getInt(int x, int y) const;

    private:
        IntegralImage(int width, int height);

    public:
        ~IntegralImage();

    public:
        static IntegralImage& fromImage(Image& image);
};

#endif /* __INTEGRALIMAGE_H__ */
