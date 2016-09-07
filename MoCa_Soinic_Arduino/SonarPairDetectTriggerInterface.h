#ifndef SONAR_PAIR_DETECT_TRIGGER_INTERFACE_H
#define SONAR_PAIR_DETECT_TRIGGER_INTERFACE_H

class SonarPairDetectTriggerInterface
{
    public:
        virtual void detect() = 0;
        virtual bool isTrigger() = 0;
        virtual void toggle() = 0;
        virtual void reset() = 0;
        virtual byte getID() = 0;
        virtual int getDistance() = 0;
        virtual void debug() = 0;
};

#endif
