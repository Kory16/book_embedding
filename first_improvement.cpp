#include "first_improvement.h"

FirstImprovement::FirstImprovement()
{
}

Solution* FirstImprovement::getNeighbour(Solution *initial, Neighbourhood* n){
    
    n->setInstance(initial);
    //int neighSize = n->getNeighbourhoodSize();
    Solution* best = initial;
    Solution* next_solution = n->next();
    while (next_solution!=nullptr) {
        if(next_solution->crossings<best->crossings){
            return next_solution;
        }
        next_solution = n->next();
    }
    return best;
}
