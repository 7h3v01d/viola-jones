#ifndef __TWORECTANGLEFEATURE_H__
#define __TWORECTANGLEFEATURE_H__

#include "Rectangle.h"

class TwoRectangleFeature:
        public IFeature
{
    private:
        Rectangle& first;
        Rectangle& second;
        double threshold;

    public:
        int getRectangleCount() const;
        Rectangle& getRectanlge(int number) const;
        Rectangle& getFirstRectangle() const;
        Rectangle& getSecondRectangle() const;
        double getThreshold() const;

    private:
        TwoRectangleFeature();
        TwoRectangleFeature(const TwoRectangleFeature&);
        TwoRectangleFeature& operator=(const TwoRectangleFeature&);

    public:
        TwoRectangleFeature(Rectangle& first, Rectangle& second, double threshold);
        ~TwoRectangleFeature();
};

#endif /* __TWORECTANGLEFEATURE_H__ */
