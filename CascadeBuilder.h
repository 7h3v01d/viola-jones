#ifndef __CASCADEBUILDER_H__
#define __CASCADEBUILDER_H__

#include "Cascade.h"

class CascadeBuilder
{
    private:
        CascadeBuilder();
        CascadeBuilder(const CascadeBuilder&);
        CascadeBuilder& operator=(const CascadeBuilder&);

    public:
        static Cascade& buildFrontalFaceDetector();
};

#endif /* __CASCADEBUILDER_H__ */
