#ifndef __CASCADE_H__
#define __CASCADE_H__

#include <list>

#include "Stage.h"

class Cascade
{
    private:
        int detectorWidth;
        int detectorHeight;
        std::list<Stage>& stages;

    public:
        int getDetectorWidth() const;
        int getDetectorHeight() const;
        int getStageCount() const;
        Stage& getStage(int number) const;

    private:
        Cascade();
        Cascade(const Cascade&);
        Cascade& operator=(const Cascade&);

    public:
        Cascade(int detectorWidth, int detectorHeight, std::list<Stage>& stages);
        ~Cascade();
};

#endif /* __CASCADE_H__ */
