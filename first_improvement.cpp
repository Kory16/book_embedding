#include "first_improvement.h"

FirstImprovement::FirstImprovement()
{

}

KPMPInstance& FirstImprovement::getNeighbour(KPMPInstance& initial, Neighbourhood *n){
    std::vector<KPMPInstance> neighbours = n->getAllNeighbours(initial);
    int crossings=initial.crossings;
    for(auto it=neighbours.begin(); it!=neighbours.end(); ++it){
        if(it->crossings < crossings){
            return *it;
        }
    }
    return initial;
}
