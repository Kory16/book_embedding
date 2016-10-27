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
public:
    LocalSearch();

    KPMPInstance & calculatePages(KPMPInstance & initial, Neighbourhood *neighbourhood, StepFunction *stepFun);


private:


};

#endif // LOCALSEARCH_H
