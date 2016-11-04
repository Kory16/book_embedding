#ifndef NEIGHBOURHOODVERTEXREPLACEMENT_H
#define NEIGHBOURHOODVERTEXREPLACEMENT_H

#include "neighbourhood.h"
#include "cmath"


class NeighbourhoodVertexReplacement : public Neighbourhood
{
public:
    NeighbourhoodVertexReplacement();

    Solution* next();
    void calculateNeighbourhoodSize();
    Solution* getNeighbour(int num);

    void setInstance(Solution* x);
};

#endif // NEIGHBOURHOODVERTEXREPLACEMENT_H
