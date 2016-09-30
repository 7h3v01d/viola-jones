#ifndef __COLOR_H__
#define __COLOR_H__

class Color
{
    public:
        virtual int getBpp() const = 0;
        virtual int getR() const = 0;
        virtual int getG() const = 0;
        virtual int getB() const = 0;
        virtual int getA() const = 0;
        virtual int getGray() const = 0;
        virtual void setRgba(int r, int g, int b, int a) = 0;
        virtual void setGray(int gray) = 0;

    public:
        virtual ~Color() {}
};

#endif /* __COLOR_H__ */
