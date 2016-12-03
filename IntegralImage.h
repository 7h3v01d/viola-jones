#ifndef __INTEGRALIMAGE_H__
#define __INTEGRALIMAGE_H__

#include <string>

#include "Image.h"

#include <vector>

class IntegralImage
{
    private:
        int width;
        int height;
        std::vector<int> integrals;

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
        IntegralImage& operator=(IntegralImage&);
        IntegralImage(int width, int height);

    public:
        ~IntegralImage();

    public:
        static IntegralImage fromImage(const Image& image);
};

#endif /* __INTEGRALIMAGE_H__ */
