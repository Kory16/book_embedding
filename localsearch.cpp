#include "localsearch.h"

LocalSearch::LocalSearch(Solution *initial)
{
	LocalSearch::initial = initial;
}

 Solution *LocalSearch::calculatePages(Neighbourhood *neighbourhood, StepFunction *stepFun){
    int iter = 0;
    Solution* x = initial;
    Solution* new_x;
    while(++iter<100 && x->crossings>0){
           new_x = stepFun->getNeighbour(x, neighbourhood);
           if(new_x->crossings<x->crossings){
               x=new_x;
           }
    }
    return x;
}
