#ifndef __ICOLOR_H__
#define __ICOLOR_H__

#include <string>

class IColor
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
        virtual std::string toString() = 0;

    public:
        virtual ~IColor() {}
};

#endif /* __ICOLOR_H__ */
