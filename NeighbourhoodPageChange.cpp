#include "NeighbourhoodPageChange.h"

NeighbourhoodPageChange::NeighbourhoodPageChange()
{

}

Solution* NeighbourhoodPageChange::next(){
    counter++;
    return getNeighbour(counter);
}

void NeighbourhoodPageChange::calculateNeighbourhoodSize(){
    /*neighbourhoodSize = 1;
    int edges = instance->edgesListWithPages.size();
    for(int i=0; i<this->k; ++i){
        neighbourhoodSize = neighbourhoodSize * (edges - i);
    }*/
    neighbourhoodSize = instance->edgesListWithPages.size() * (instance->pagesNum - 1);
}

Solution* NeighbourhoodPageChange::getNeighbour(int num){
    int pageNum = num%(instance->pagesNum-1);
    int edge = (num/instance->pagesNum)%instance->edgesListWithPages.size();
    int prevPage = instance->edgesListWithPages[edge][2];
    if (pageNum >= prevPage){
        pageNum += 1;
    }
    Solution* result = new Solution(instance);
    result->edgesListWithPages[edge][2] = pageNum;

    int a=calcualteCrossingsOnPage(instance, prevPage);
    int b=calcualteCrossingsOnPage(instance, pageNum);
    int c=calcualteCrossingsOnPage(result, prevPage);
    int d=calcualteCrossingsOnPage(result, pageNum);

    int crossings_change = calcualteCrossingsOnPage(instance, prevPage) + calcualteCrossingsOnPage(instance, pageNum)
            - calcualteCrossingsOnPage(result, prevPage) - calcualteCrossingsOnPage(result, pageNum);
    result->crossings-=crossings_change;
    return result;
}


void NeighbourhoodPageChange::setInstance(Solution* x){
    instance = x;
    calculateNeighbourhoodSize();
    counter = -1;
}
