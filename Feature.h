#ifndef __FEATURE_H__
#define __FEATURE_H__

#include "Rectangle.h"

class Feature
{
    public:
        virtual int getRectangleCount() const = 0;
        virtual Rectangle& getRectanlge(int number) const = 0;

    public:
        virtual ~Feature();
};

#endif /* __FEATURE_H__ */
