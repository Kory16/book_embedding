#ifndef LOCALSEARCH_H
#define LOCALSEARCH_H

#include <vector>
#include <list>
#include <map>

#include "neighbourhood.h"
#include "stepfunction.h"
#include "solution.h"
#include <ctime>

class LocalSearch
{

public:
    LocalSearch(Solution* initial);
    ~LocalSearch();

    Solution* calculatePages(Neighbourhood *neighbourhood, StepFunction *stepFun);
    int iteration;
    clock_t elapsed_time;

    Solution * initial;
private:

	
};

#endif // LOCALSEARCH_H
