#ifndef __IFEATURE_H__
#define __IFEATURE_H__

#include "Rectangle.h"

class IFeature
{
    public:
        virtual int getRectangleCount() const = 0;
        virtual Rectangle& getRectanlge(int number) const = 0;

    public:
        virtual ~IFeature() {};
};

#endif /* __IFEATURE_H__ */
