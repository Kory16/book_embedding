#ifndef NEIGHBOURHOOD_PAGE_CHANGE_H
#define NEIGHBOURHOOD_PAGE_CHANGE_H

#include "neighbourhood.h"
#include "solution.h"

using namespace std;


class NeighbourhoodPageChange : public Neighbourhood
{
public:
    NeighbourhoodPageChange();

    Solution* next();
    void calculateNeighbourhoodSize();
    Solution* getNeighbour(int num);
    void virtual setInstance(Solution* x);


};

#endif // NEIGHBOURHOOD_PAGE_CHANGE_H
