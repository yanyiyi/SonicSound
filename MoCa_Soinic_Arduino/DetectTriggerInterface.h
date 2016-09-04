#ifndef TRIGGER_METHOD_H
#define TRIGGER_METHOD_H

class TriggerMethod
{
    public:
        bool isTrigger;

        TriggerMethod() {
            isTrigger = false;
        }
        
        virtual void update() = 0;
        virtual void toggle() = 0;
        virtual void reset() = 0;
        virtual byte getID() = 0;
};

#endif
