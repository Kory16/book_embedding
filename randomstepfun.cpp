#include "randomstepfun.h"

RandomStepFun::RandomStepFun()
{
    //RandomStepFun::neighbours = n.getAllNeighbours(initial);
}

Solution *RandomStepFun::getNeighbour(Solution* initial, Neighbourhood *n)
{
    n->setInstance(initial);
    std::srand(std::time(0));
    int neighSize = n->getNeighbourhoodSize();
    return n->getNeighbour(std::rand() % neighSize);
}
