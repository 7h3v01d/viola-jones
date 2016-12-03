#ifndef __THREERECTANGLEFEATURE_H__
#define __THREERECTANGLEFEATURE_H__

#include "Rectangle.h"

class ThreeRectangleFeature:
    public IFeature
{
    private:
        Rectangle& first;
        Rectangle& second;
        Rectangle& third;

    public:
        int getRectangleCount() const;
        Rectangle& getRectanlge(int number) const;
        Rectangle& getFirstRectangle() const;
        Rectangle& getSecondRectangle() const;
        Rectangle& getThirdRectangle() const;

    private:
        ThreeRectangleFeature();
        ThreeRectangleFeature(const ThreeRectangleFeature&);
        ThreeRectangleFeature& operator=(const ThreeRectangleFeature&);

    public:
        ThreeRectangleFeature(Rectangle& first, Rectangle& second, Rectangle& third);
        ~ThreeRectangleFeature();
};

#endif /* __THREERECTANGLEFEATURE_H__ */
