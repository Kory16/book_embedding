#ifndef RANDOMSTEPFUN_H
#define RANDOMSTEPFUN_H

#include "stepfunction.h"
#include "kpmp_instance.h"
#include <ctime>
#include <vector>

class RandomStepFun : public StepFunction
{

	vector<KPMPInstance> neighbours;

public:
    RandomStepFun(KPMPInstance& initial, Neighbourhood &n);
    KPMPInstance& getNeighbour(Neighbourhood &n);
};

#endif // RANDOMSTEPFUN_H
