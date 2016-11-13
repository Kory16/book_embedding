#ifndef NEIGHBOURHOOD_PAGE_CHANGE_H
#define NEIGHBOURHOOD_PAGE_CHANGE_H

#include "neighbourhood.h"
#include "solution.h"
#include <ctime>
#include <vector>

using namespace std;

class NeighbourhoodPageChange : public Neighbourhood
{
public:
    NeighbourhoodPageChange();

    Solution* next();
    void calculateNeighbourhoodSize();
    //Solution* getNeighbour(int num);
    void virtual setInstance(Solution* x);
    Solution* getRandomNeighbour();

private:
    void changePage(Solution* s, int edge, int pageNum);
    vector<int> edges;
    vector<int> pages;
    int changeEdges();
    int changePages();

};

#endif // NEIGHBOURHOOD_PAGE_CHANGE_H
