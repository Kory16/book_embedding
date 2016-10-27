#ifndef FIRST_IMPROVEMENT_H
#define FIRST_IMPROVEMENT_H

#include "stepfunction.h"

class FirstImprovement : public StepFunction
{
public:
    FirstImprovement();
    KPMPInstance& getNeighbour(KPMPInstance& initial, Neighbourhood *n);
};

#endif // FIRST_IMPROVEMENT_H
