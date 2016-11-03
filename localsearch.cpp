#include "localsearch.h"

LocalSearch::LocalSearch(Solution *initial)
{
	LocalSearch::initial = initial;
}

LocalSearch::~LocalSearch(){
    delete initial;
}

 Solution *LocalSearch::calculatePages(Neighbourhood *neighbourhood, StepFunction *stepFun){
    int iter = 0;
    Solution* x = initial;
    while(++iter<100 && x->crossings>0){
           Solution* new_x = stepFun->getNeighbour(x, neighbourhood);
           if(new_x->crossings<x->crossings){
               if(x!=initial){
                    delete x;
               }
               x=new_x;
           }
           //else{
           //    delete new_x;
           //}
    }
    return x;
}
