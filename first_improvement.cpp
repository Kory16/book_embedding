#include "first_improvement.h"

FirstImprovement::FirstImprovement()
{
}

Solution* FirstImprovement::getNeighbour(Solution *initial, Neighbourhood* n){
    
    n->setInstance(initial);
    int neighSize = n->getNeighbourhoodSize();
    Solution* best = initial;
    for(int i=0; i<neighSize-1; ++i){
        Solution* next_solution = n->getNeighbour(i);
        if(next_solution->crossings<best->crossings){
            return next_solution;
        }
        delete next_solution;
    }
    return best;
}
