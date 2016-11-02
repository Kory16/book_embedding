#ifndef STEPFUNCTION_H
#define STEPFUNCTION_H

#include "neighbourhood.h"
#include "kpmp_instance.h"

class StepFunction
{
	KPMPInstance initial;
public:
    StepFunction(KPMPInstance& initial, Neighbourhood &n);
    virtual KPMPInstance& getNeighbour(Neighbourhood &n)=0;
};

#endif // STEPFUNCTION_H
