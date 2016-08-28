#ifndef __COLOR_H__
#define __COLOR_H__

class Color
{
    public:
        virtual int getBpp() const { return 0; }
        virtual int getR() const { return 0; }
        virtual int getG() const { return 0; }
        virtual int getB() const {return 0; }
        virtual int getA() const { return 0; }
        virtual int getGray() const { return 0; }
        virtual void setRgba(int r, int g, int b, int a) { (void)r; (void)g; (void)b; (void)a; }
        virtual void setGray(int gray) { (void)gray; }

    public:
        virtual ~Color() {}
};

#endif /* __COLOR_H__ */
