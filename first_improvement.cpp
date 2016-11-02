#include "first_improvement.h"

FirstImprovement::FirstImprovement(KPMPInstance& initial, Neighbourhood &n) : StepFunction(initial, n)
{
	std::vector<KPMPInstance> neighbours = n.getAllNeighbours(initial);
	FirstImprovement::crossings = initial.crossings;
}

KPMPInstance& FirstImprovement::getNeighbour(Neighbourhood &n){
    
    for(auto it=neighbours.begin(); it!=neighbours.end(); ++it){
        if(it->crossings < FirstImprovement::crossings){
            return *it;
        }
    }
    return FirstImprovement::initial;
}
