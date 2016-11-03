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
    int pageNum = num%instance->pagesNum;
    int edge = (num/instance->pagesNum)%instance->edgesListWithPages.size();
    int prevPage = instance->edgesListWithPages[edge][2];
    if (pageNum == prevPage){
        pageNum += 1;
    }
    Solution* result = new Solution(instance);
    result->edgesListWithPages[edge][2] = pageNum;

    int crossings_change = calcualteCrossingsOnPage(instance, prevPage) + calcualteCrossingsOnPage(instance, pageNum)
            - calcualteCrossingsOnPage(result, prevPage) - calcualteCrossingsOnPage(result, pageNum);
    result->crossings+=crossings_change;
    return result;
}

int NeighbourhoodPageChange::calcualteCrossingsOnPage(Solution* solution, int pageNum){
    vector < vector<int> > edgesOnPage;
    for(auto it = solution->edgesListWithPages.begin(); it!=solution->edgesListWithPages.end(); ++it){
        if (it->at(2)!=pageNum)
            continue;
        edgesOnPage.push_back(*it);
    }
    unsigned int crossings = 0;

    // for all edges on the page, count how much crossing will be caused by adding a new edge
    for(unsigned int i = 0; i<edgesOnPage.size(); i++){
        int vi1 = min(solution->getVerteOrder()[edgesOnPage[i][0]], solution->getVerteOrder()[edgesOnPage[i][1]]);
        int vi2 = max(solution->getVerteOrder()[edgesOnPage[i][0]], solution->getVerteOrder()[edgesOnPage[i][1]]);
        for(unsigned int j =i+1; j<edgesOnPage.size(); j++){
            int vj1 = min(solution->getVerteOrder()[edgesOnPage[j][0]], solution->getVerteOrder()[edgesOnPage[j][1]]);
            int vj2 = max(solution->getVerteOrder()[edgesOnPage[j][0]], solution->getVerteOrder()[edgesOnPage[j][1]]);
            if((vi1<vj1 && vj1<vi2 && vi2<vj2) || (vj1<vi1 && vi1<vj2 && vj2<vi2)){
                crossings++;
            }
        }
    }

    return crossings;
}

void NeighbourhoodPageChange::setInstance(Solution* x){
    instance = x;
    calculateNeighbourhoodSize();
    counter = -1;
}
