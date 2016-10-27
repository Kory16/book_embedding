#include "localsearch.h"

LocalSearch::LocalSearch()
{

}

 KPMPInstance & LocalSearch::calculatePages(KPMPInstance & initial, Neighbourhood *neighbourhood, StepFunction *stepFun){
    int iter = 0;
    KPMPInstance x = initial;
    KPMPInstance new_x;
    while(++iter<100 && x.crossings>0){
           new_x = stepFun->getNeighbour(x, neighbourhood);
           if(new_x.crossings<x.crossings){
               x=new_x;
           }
    }
    return x;
}
