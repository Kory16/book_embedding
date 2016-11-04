#include "localsearch.h"

LocalSearch::LocalSearch(Solution *initial)
{
	LocalSearch::initial = initial;
}

LocalSearch::~LocalSearch(){
    delete initial;
}

 Solution *LocalSearch::calculatePages(Neighbourhood *neighbourhood, StepFunction *stepFun){
    clock_t begin = clock();
    clock_t end;
    elapsed_time = 0;
    iteration = 0;
    Solution* x = initial;
    int sameResultCounter = 0;
    while(++iteration<1000 && x->crossings>0 && elapsed_time < 15*60 && sameResultCounter<10){
           Solution* new_x = stepFun->getNeighbour(x, neighbourhood);
           if(new_x->crossings<x->crossings){
               if(x!=initial){
                    delete x;
               }
               x=new_x;
           }
           else{
               sameResultCounter++;
           }
           end = clock();
           elapsed_time = double(end - begin) / CLOCKS_PER_SEC;
    }
    return x;
}
