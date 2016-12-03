#include <stdexcept>
#include <string>

#include "Stage.h"

Stage::Stage(std::vector<WeakClassifier>& weakClassifiers, double threshold):
    weakClassifiers(weakClassifiers),
    threshold(threshold)
{
}

int Stage::getWeakClassifierCount() const
{
    return static_cast<int>(weakClassifiers.size());
}

/**
 * @throw std::out_of_range
 */
WeakClassifier& Stage::getWeakClassifier(int number) const
{
    if (number >= static_cast<int>(weakClassifiers.size())) {
        throw std::out_of_range(std::string("invalid number"));
    }

    return weakClassifiers[number];
}

double Stage::getThreshold() const
{
    return threshold;
}
