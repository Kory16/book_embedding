#ifndef BESTIMPROVEMENT_H
#define BESTIMPROVEMENT_H

#include "stepfunction.h"

class BestImprovement : public StepFunction
{
public:
    BestImprovement();
    KPMPInstance& getNeighbour(KPMPInstance& initial, Neighbourhood *n);
};

#endif // BESTIMPROVEMENT_H
