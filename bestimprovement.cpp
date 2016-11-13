#include "bestimprovement.h"

BestImprovement::BestImprovement()
{

}

Solution* BestImprovement::getNeighbour(Solution *initial, Neighbourhood* n){
    
    n->setInstance(initial);
    //int neighSize = n->getNeighbourhoodSize();
    Solution* best = initial;
    Solution* next_solution = n->next();
    while (next_solution!=nullptr) {
        if(next_solution->crossings<best->crossings){
            if(best!=initial){
                delete best;
            }
            best = next_solution;
        }
        else{
            delete next_solution;
        }
       next_solution = n->next();
    }
    return best;
}
