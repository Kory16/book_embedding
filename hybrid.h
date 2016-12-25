#ifndef HYBRID_H
#define HYBRID_H

#include "solution.h"
#include "geneticalgorithm.h"
#include "localsearch.h"
#include "neighbourhood.h"
#include "stepfunction.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Hybrid
{
public:
    Hybrid();
    void setLocalSearchParameters(Neighbourhood *neighbourhood, StepFunction *stepFun);
    void setGAparameters(int size, double crossOverProb, double mutationProb, int iter);
    void setOtherParameters(int bestSolutionsNum);
    Solution* calculate(vector< vector <int> >& edgesList, int pagesNum, int verticesNum);

private:
    Neighbourhood *neighbourhood;
    StepFunction *stepFun;
    int populationSize;
    double crossOverProability;
    double mutationProbability;
    int maxIterationNum;
    int solutionsExplorNum;

    vector<Solution *> findBestSolutions(vector<Solution*> solutions, int k);

};

#endif // HYBRID_H
