#ifndef RANDOMSTEPFUN_H
#define RANDOMSTEPFUN_H

#include "stepfunction.h"
#include "kpmp_instance.h"
#include <ctime>
#include <vector>

class RandomStepFun : public StepFunction
{
public:
    RandomStepFun();
    KPMPInstance& getNeighbour(KPMPInstance& initial, Neighbourhood *n);
};

#endif // RANDOMSTEPFUN_H
