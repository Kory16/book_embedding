#include "randomstepfun.h"

RandomStepFun::RandomStepFun(KPMPInstance& initial, Neighbourhood &n) : StepFunction(initial,n)
{
	RandomStepFun::neighbours = n.getAllNeighbours(initial);
}

KPMPInstance& RandomStepFun::getNeighbour(Neighbourhood &n)
{    
    std::srand(std::time(0));
    return RandomStepFun::neighbours[std::rand() % neighbours.size()];
}
