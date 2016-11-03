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
    int getNeighbourhoodSize(){
        return neighbourhoodSize;
    }
    virtual void calculateNeighbourhoodSize()=0;
    virtual Solution* getNeighbour(int num)=0;

    void setSize(int size){
        k=size;
    }

    void virtual setInstance(Solution* x){
        instance = x;
    }

protected:
    int k;
    int counter;
    int neighbourhoodSize;
    Solution* instance;
};

#endif // NEIGHBOURHOOD_H
