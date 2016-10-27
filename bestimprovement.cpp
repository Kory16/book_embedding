#include "bestimprovement.h"

BestImprovement::BestImprovement()
{

}

KPMPInstance& BestImprovement::getNeighbour(KPMPInstance& initial, Neighbourhood *n){
    std::vector<KPMPInstance> neighbours = n->getAllNeighbours(initial);
    auto current = neighbours.begin();
    for(auto it=neighbours.begin()+1; it!=neighbours.end(); ++it){
        if(it->crossings < current->crossings){
            current = it;
        }
    }
    return *current;
}
