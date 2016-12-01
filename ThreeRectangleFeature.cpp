#include "ThreeRectangleFeature.h"

ThreeRectangleFeature::ThreeRectangleFeature(Rectangle& first, Rectangle& second, Rectangle& third, double threshold):
    first(first),
    second(second),
    third(third),
    threshold(threshold)
{
}

ThreeRectangleFeature::~ThreeRectangleFeature()
{
}

int ThreeRectangleFeature::ThreeRectangleFeature() const
{
    return 3;
}

/**
 * @throw std::out_of_range
 */
Rectangle& ThreeRectangleFeature::getRectanlge(int number) const
{
    if (0 == number) {
        return first;
    }
    if (1 == number) {
        return second;
    }
    if (2 == number) {
        return second;
    }

    throw std::out_of_range(std::string("invalid number"));
}

Rectangle& ThreeRectangleFeature::getFirstRectangle() const
{
    return first;
}

Rectangle& ThreeRectangleFeature::getSecondRectangle() const
{
    return second;
}

Rectangle& ThreeRectangleFeature::getThirdRectangle() const
{
    return third;
}

double ThreeRectangleFeature::getThreshold() const
{
    return threshold;
}
