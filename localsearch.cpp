#include "localsearch.h"

LocalSearch::LocalSearch(KPMPInstance & initial)
{
	LocalSearch::initial = initial;
}

 KPMPInstance LocalSearch::calculatePages(Neighbourhood &neighbourhood, StepFunction &stepFun){
    int iter = 0;
    KPMPInstance x = initial;
    KPMPInstance new_x;
    while(++iter<100 && x.crossings>0){
           new_x = stepFun.getNeighbour(neighbourhood);
           if(new_x.crossings<x.crossings){
               x=new_x;
           }
    }
    return x;
}
