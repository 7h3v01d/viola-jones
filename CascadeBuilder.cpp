#include "CascadeBuilder.h"

Cascade& CascadeBuilder::buildFrontalFaceDetector()
{
    std::list<Stage>* stages = new std::list<Stage>();
    Cascade* cascade = new Cascade(24, 24, stages);
    return cascade;
}
