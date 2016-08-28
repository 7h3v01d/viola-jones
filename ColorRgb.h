#ifndef __COLORRGB_H__
#define __COLORRGB_H__

#include "Color.h"


class ColorRgb:
        public Color
{
    private:
        int r;
        int g;
        int b;

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
        ColorRgb();
        ColorRgb(int r, int g, int b);
        ~ColorRgb();
};

#endif /* __COLORRGB_H__ */
