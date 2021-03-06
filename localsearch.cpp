#include "localsearch.h"

LocalSearch::LocalSearch(Solution *initial)
{
	LocalSearch::initial = initial;
}

LocalSearch::~LocalSearch(){
    //delete initial;
}

 Solution *LocalSearch::calculatePages(Neighbourhood *neighbourhood, StepFunction *stepFun){
    clock_t begin = clock();
    clock_t end;
    elapsed_time = 0;
    iteration = 0;
    Solution* x = new Solution(initial);
    int sameResultCounter = 0;
    while(++iteration<1000 && x->crossings>0 && elapsed_time < 15*60 && sameResultCounter<stepFun->getMaxNonImprovementIterations()){
           Solution* new_x = stepFun->getNeighbour(x, neighbourhood);
           if(new_x->crossings<x->crossings){
               x=new_x;
               sameResultCounter=0;
           }
           else{
               sameResultCounter++;
           }
           end = clock();
           elapsed_time += double(end - begin) / CLOCKS_PER_SEC;
           cout<<"Local search iteration: "<<iteration<<", crossings: "<<x->crossings<<endl;
    }
    return x;
}
