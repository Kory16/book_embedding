#ifndef BESTIMPROVEMENT_H
#define BESTIMPROVEMENT_H

#include "stepfunction.h"

class BestImprovement : public StepFunction
{
	vector<KPMPInstance> neighbours;
public:
    BestImprovement(KPMPInstance& initial, Neighbourhood &n);
    KPMPInstance& getNeighbour(Neighbourhood &n);
};

#endif // BESTIMPROVEMENT_H
