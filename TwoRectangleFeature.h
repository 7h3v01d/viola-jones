#ifndef __TWORECTANGLEFEATURE_H__
#define __TWORECTANGLEFEATURE_H__

#include "Rectangle.h"

class TwoRectangleFeature:
        public Feature
{
    public:
        int getRectangleCount() const;
        Rectangle& getRectanlge(int number);
        Rectangle& getFirstRectangle();
        Rectangle& getSecondRectangle();

    private:
        TwoRectangleFeature();
        TwoRectangleFeature(const TwoRectangleFeature&);
        TwoRectangleFeature& operator=(const TwoRectangleFeature&);

    public:
        TwoRectangleFeature(Rectangle& first, Rectangle& second);
};

#endif /* __TWORECTANGLEFEATURE_H__ */
