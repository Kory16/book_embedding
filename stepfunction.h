#ifndef STEPFUNCTION_H
#define STEPFUNCTION_H

#include "neighbourhood.h"
#include "solution.h"

class StepFunction
{

public:
    StepFunction();
    virtual Solution* getNeighbour(Solution* initial, Neighbourhood *n)=0;
    virtual int getMaxNonImprovementIterations(){
        return 1;
    }
};

#endif // STEPFUNCTION_H
