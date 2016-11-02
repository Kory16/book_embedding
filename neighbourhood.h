#ifndef NEIGHBOURHOOD_H
#define NEIGHBOURHOOD_H

#include <vector>
#include "kpmp_instance.h"

using namespace std;

class Neighbourhood
{
public:
    Neighbourhood();

    virtual vector<KPMPInstance> getAllNeighbours (KPMPInstance & x)=0;
    virtual KPMPInstance& next(KPMPInstance& x)=0;

    void setSize(int size){
        k=size;
    }

private:
    int k;
};

#endif // NEIGHBOURHOOD_H
