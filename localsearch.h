#ifndef LOCALSEARCH_H
#define LOCALSEARCH_H

#include <vector>
#include <list>
#include <map>

#include "neighbourhood.h"
#include "stepfunction.h"
#include "kpmp_instance.h"

class LocalSearch
{

	KPMPInstance initial;

public:
    LocalSearch(KPMPInstance & initial);

    KPMPInstance calculatePages(Neighbourhood &neighbourhood, StepFunction &stepFun);
private:
	
};

#endif // LOCALSEARCH_H
