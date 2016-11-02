#include "bestimprovement.h"

BestImprovement::BestImprovement(KPMPInstance& initial, Neighbourhood &n) : StepFunction(initial,n)
{
	std::vector<KPMPInstance> neighbours = n.getAllNeighbours(initial);

}

KPMPInstance& BestImprovement::getNeighbour(Neighbourhood &n){
    
    auto current = neighbours.begin();
    for(auto it=neighbours.begin()+1; it!=neighbours.end(); ++it){
        if(it->crossings < current->crossings){
            current = it;
        }
    }
    return *current;
}
