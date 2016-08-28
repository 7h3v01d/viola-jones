#ifndef __COLORGRAY_H__
#define __COLORGRAY_H__

#include "Color.h"


class ColorGray:
        public Color
{
    private:
        int gray;

    public:
        int getBpp() const;
        int getR() const;
        int getG() const;
        int getB() const;
        int getA() const;
        int getGray() const;
        void setRgba(int r, int g, int b, int a);
        void setGray(int gray);

    public:
        ColorGray();
        ColorGray(int gray);
        ~ColorGray();
};

#endif /* __COLORGRAY_H__ */
