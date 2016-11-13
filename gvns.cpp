#include "gvns.h"

GVNS::GVNS(Solution *initial)
{
    this->initial = initial;
}

GVNS::~GVNS(){
    delete initial;
}

Solution* GVNS::calculatePages(vector<Neighbourhood *> neighbourhoods){
    clock_t begin = clock();
    clock_t end;
    elapsed_time = 0;
    iteration = 0;
    Solution* x = initial;
    int sameResultCounter = 0;
    int k = 0;
    int l=0;
    RandomStepFun* rnd = new RandomStepFun();
    BestImprovement* bst = new BestImprovement();
    while(++iteration<1000 && x->crossings>0 && elapsed_time < 15*60 && sameResultCounter<10){
        k = 0;
        while(k < neighbourhoods.size()){
            // shaking
            neighbourhoods[k]->setSize(3);
            Solution * x1 = rnd->getNeighbour(x, neighbourhoods[k]);
            l=1;
            while(l<=4){
                neighbourhoods[k]->setSize(l);
                Solution * x2 = bst->getNeighbour(x1, neighbourhoods[k]);
                if(x2==x1){
                    l++;
                }
                else{
                    if(x2->crossings < x1->crossings){
                        delete x1;
                        x1=x2;
                        l=1;
                    }
                    else{
                        l++;
                        delete x2;
                    }
                }

            }
            if(x1->crossings<x->crossings){
                if(x!=initial){
                    delete x;
                }
                x=x1;
                k=1;
            }
            else{
                k++;
                delete x1;
            }
        }
           end = clock();
           elapsed_time += double(end - begin) / CLOCKS_PER_SEC;
    }
    return x;
}
