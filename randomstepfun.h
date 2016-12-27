#ifndef RANDOMSTEPFUN_H
#define RANDOMSTEPFUN_H

#include "stepfunction.h"
#include "solution.h"
#include <ctime>
#include <vector>

class RandomStepFun : public StepFunction
{

    //vector<KPMPInstance> neighbours;

public:
    RandomStepFun();
    Solution * getNeighbour(Solution *initial, Neighbourhood* n);
    int getMaxNonImprovementIterations(){
        return 10;
    }
};

#endif // RANDOMSTEPFUN_H
