#ifndef TRIGGER_METHOD_TWO_H
#define TRIGGER_METHOD_TWO_H

#include "TriggerMethod.h"
#include "Sonar.h"

class TriggerMethodTwo : public TriggerMethod
{
    private:
    public:
        TriggerMethodTwo(Sonar* comingSensor, Sonar leavingSensor) :
                TriggerMethod() {
            
        }
};

#endif
