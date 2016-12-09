#include "CascadeBuilder.h"

Cascade& CascadeBuilder::buildFrontalFaceDetector()
{
    std::vector<Stage>* stages = new std::vector<Stage>();
    Cascade* cascade = new Cascade(24, 24, *stages);

    return *cascade;
}
