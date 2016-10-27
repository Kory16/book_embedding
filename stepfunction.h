#ifndef STEPFUNCTION_H
#define STEPFUNCTION_H

#include "neighbourhood.h"
#include "kpmp_instance.h"

class StepFunction
{
public:
    StepFunction();

    virtual KPMPInstance& getNeighbour(KPMPInstance& initial, Neighbourhood *n)=0;
};

#endif // STEPFUNCTION_H
