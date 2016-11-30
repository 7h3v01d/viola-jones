#ifndef __THREERECTANGLEFEATURE_H__
#define __THREERECTANGLEFEATURE_H__

#include "Rectangle.h"

class ThreeRectangleFeature:
        public Feature
{
    public:
        int getRectangleCount() const;
        Rectangle& getRectanlge(int number);
        Rectangle& getFirstRectangle();
        Rectangle& getSecondRectangle();
        Rectangle& getThirdRectangle();

    private:
        ThreeRectangleFeature();
        ThreeRectangleFeature(const ThreeRectangleFeature&);
        ThreeRectangleFeature& operator=(const ThreeRectangleFeature&);

    public:
        ThreeRectangleFeature(Rectangle& first, Rectangle& second);
};

#endif /* __THREERECTANGLEFEATURE_H__ */
