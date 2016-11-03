#ifndef LOCALSEARCH_H
#define LOCALSEARCH_H

#include <vector>
#include <list>
#include <map>

#include "neighbourhood.h"
#include "stepfunction.h"
#include "solution.h"

class LocalSearch
{

    Solution * initial;

public:
    LocalSearch(Solution* initial);
    ~LocalSearch();

    Solution* calculatePages(Neighbourhood *neighbourhood, StepFunction *stepFun);
private:
	
};

#endif // LOCALSEARCH_H
