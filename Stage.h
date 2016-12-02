#ifndef __STAGE_H__
#define __STAGE_H__

#include <list>

#include "WeakClassifier.h"

class Stage
{
    private:
        std::list<WeakClassifier>& weakClassifiers;
        double threshold;

    public:
        int getWeakClassifierCount() const;
        WeakClassifier& getWeakClassifier(int number) const;
        double getThreshold() const;

    private:
        Stage();
        Stage(const Stage&);
        Stage& operator=(const Stage&);

    public:
        Stage(std::list<WeakClassifier>& weakClassifiers, double threshold);
};

#endif /* __STAGE_H__ */
