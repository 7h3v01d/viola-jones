#ifndef __TWORECTANGLEFEATURE_H__
#define __TWORECTANGLEFEATURE_H__

#include "Rectangle.h"

class TwoRectangleFeature:
    public IFeature
{
    private:
        Rectangle& first;
        Rectangle& second;

    public:
        int getRectangleCount() const;
        Rectangle& getRectanlge(int number) const;
        Rectangle& getFirstRectangle() const;
        Rectangle& getSecondRectangle() const;

    private:
        TwoRectangleFeature();
        TwoRectangleFeature(const TwoRectangleFeature&);
        TwoRectangleFeature& operator=(const TwoRectangleFeature&);

    public:
        TwoRectangleFeature(Rectangle& first, Rectangle& second);
        ~TwoRectangleFeature();
};

#endif /* __TWORECTANGLEFEATURE_H__ */
