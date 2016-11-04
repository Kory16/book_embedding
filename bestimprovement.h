#ifndef BESTIMPROVEMENT_H
#define BESTIMPROVEMENT_H

#include "stepfunction.h"

class BestImprovement : public StepFunction
{
public:
    BestImprovement();
    Solution * getNeighbour(Solution *initial, Neighbourhood* n);
};

#endif // BESTIMPROVEMENT_H
