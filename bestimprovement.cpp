#include "bestimprovement.h"

BestImprovement::BestImprovement()
{

}

Solution* BestImprovement::getNeighbour(Solution *initial, Neighbourhood* n){
    
    n->setInstance(initial);
    int neighSize = n->getNeighbourhoodSize();
    Solution* best = initial;
    for(int i=0; i<neighSize; ++i){
        Solution* next_solution = n->getNeighbour(i);
        if(next_solution->crossings<best->crossings){
            if(best!=initial){
                delete best;
            }
            best = next_solution;
        }
        else{
            delete next_solution;
        }
    }
    return best;
}
