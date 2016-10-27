#include "randomstepfun.h"

RandomStepFun::RandomStepFun()
{

}

KPMPInstance& RandomStepFun::getNeighbour(KPMPInstance& initial, Neighbourhood *n){
    std::vector<KPMPInstance> neighbours = n->getAllNeighbours(initial);
    std::srand(std::time(0));
    return neighbours[std::rand() % neighbours.size()];
}
