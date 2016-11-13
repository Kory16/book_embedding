#ifndef GVNS_H
#define GVNS_H

#include <vector>
#include <ctime>

#include "solution.h"
#include "neighbourhood.h"
#include "stepfunction.h"
#include "randomstepfun.h"
#include "bestimprovement.h"

using namespace std;

class GVNS
{
public:
    GVNS(Solution * initial);

    ~GVNS();

    Solution* calculatePages(vector<Neighbourhood *> neighbourhoods);
    int iteration;
    clock_t elapsed_time;
    Solution * initial;
};

#endif // GVNS_H
