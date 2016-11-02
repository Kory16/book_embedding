#ifndef FIRST_IMPROVEMENT_H
#define FIRST_IMPROVEMENT_H

#include "stepfunction.h"

class FirstImprovement : public StepFunction
{
	KPMPInstance initial;
	vector<KPMPInstance> neighbours;
	int crossings;
public:
    FirstImprovement(KPMPInstance& initial, Neighbourhood &n);
    KPMPInstance& getNeighbour(Neighbourhood &n);
};

#endif // FIRST_IMPROVEMENT_H
