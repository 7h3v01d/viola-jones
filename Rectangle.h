#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

class Rectangle
{
    private:
        int x;
        int y;
        int width;
        int height;
        double weight;

    public:
        int getX() const;
        int getY() const;
        int getWidth() const;
        int getHeight() const;
        double getWeight() const;

    private:
        Rectangle();
        Rectangle(const Rectangle&);
        Rectangle& operator=(const Rectangle&);

    public:
        Rectangle(int x, int y, int width, int height, double weight);
        ~Rectangle();
};

#endif /* __RECTANGLE_H__ */
