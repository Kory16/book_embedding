#include "stepfunction.h"

StepFunction::StepFunction(KPMPInstance& initial, Neighbourhood &n)
{
	StepFunction::initial = initial;
}

KPMPInstance& StepFunction::getNeighbour(Neighbourhood &n){
	return initial;
   
}
