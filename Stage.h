#ifndef __STAGE_H__
#define __STAGE_H__

class Stage
{
    private:
        int weakClassifierCount;
        int threshold;

    public:
        int getWeakClassifierCount() const;
        int getThreshold() const;
};

#endif /* __STAGE_H__ */
