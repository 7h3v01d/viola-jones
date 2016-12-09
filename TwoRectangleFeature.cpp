#include <stdexcept>
#include <sstream>
#include <string>

#include "TwoRectangleFeature.h"

TwoRectangleFeature::TwoRectangleFeature(Rectangle& first, Rectangle& second):
    first(first),
    second(second)
{
}

TwoRectangleFeature::~TwoRectangleFeature()
{
}

int TwoRectangleFeature::getRectangleCount() const
{
    return 2;
}

/**
 * @throw std::out_of_range
 */
Rectangle& TwoRectangleFeature::getRectanlge(int number) const
{
    if (0 == number) {
        return first;
    }
    if (1 == number) {
        return second;
    }

    throw std::out_of_range(std::string("invalid number"));
}

Rectangle& TwoRectangleFeature::getFirstRectangle() const
{
    return first;
}

Rectangle& TwoRectangleFeature::getSecondRectangle() const
{
    return second;
}

std::string TwoRectangleFeature::toString() const
{
    std::ostringstream s;
    s << first.toString() << "\n";
    s << second.toString();

    return s.str();
}
