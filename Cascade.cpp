#include <stdexcept>
#include <string>

#include "Cascade.h"

Cascade::Cascade(int detectorWidth, int detectorHeight, std::vector<Stage>& stages):
    detectorWidth(detectorWidth),
    detectorHeight(detectorHeight),
    stages(stages)
{
}

Cascade::~Cascade()
{
}

int Cascade::getDetectorWidth() const
{
    return detectorWidth;
}

int Cascade::getDetectorHeight() const
{
    return detectorHeight;
}

int Cascade::getStageCount() const
{
    return static_cast<int>(stages.size());
}

/**
 * @throw std::out_of_range
 */
Stage& Cascade::getStage(int number) const
{
    if (number >= static_cast<int>(stages.size())) {
        throw std::out_of_range(std::string("invalid number"));
    }

    return stages[number];
}
