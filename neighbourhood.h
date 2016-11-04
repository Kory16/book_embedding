#ifndef NEIGHBOURHOOD_H
#define NEIGHBOURHOOD_H

#include <vector>
#include "solution.h"

using namespace std;

class Neighbourhood
{
public:
    Neighbourhood();
    virtual ~Neighbourhood();

    //virtual vector<KPMPInstance> getAllNeighbours (KPMPInstance & x)=0;
    virtual Solution* next()=0;
    virtual void calculateNeighbourhoodSize()=0;
    virtual Solution* getNeighbour(int num)=0;

    void virtual setInstance(Solution* x){
        instance = x;
    }

    void setSize(int size){
        k=size;
    }

    int getNeighbourhoodSize(){
        return neighbourhoodSize;
    }

protected:
    int k;
    int counter;
    int neighbourhoodSize;
    Solution* instance;

    int calcualteCrossingsOnPage(Solution* solution, int pageNum);
    int calculateCrossings(Solution * solution);
};

#endif // NEIGHBOURHOOD_H
