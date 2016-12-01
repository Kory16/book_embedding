#include "NeighbourhoodPageChange.h"

NeighbourhoodPageChange::NeighbourhoodPageChange()
{

}

Solution* NeighbourhoodPageChange::next(){
    if(changePages() < 0){
        if(changeEdges() < 0){
            return nullptr;
        }
    }
    Solution* result = new Solution(instance);
    for(int i=0; i<k; i++){
        changePage(result, edges[i], pages[i]);
    }
    //result->crossings=calculateCrossings(result);
    return result;
}

void NeighbourhoodPageChange::calculateNeighbourhoodSize(){
    /*neighbourhoodSize = 1;
    int edges = instance->edgesListWithPages.size();
    for(int i=0; i<this->k; ++i){
        neighbourhoodSize = neighbourhoodSize * (edges - i);
    }*/
    neighbourhoodSize = instance->edgesListWithPages.size() * (instance->pagesNum - 1);
}

/*Solution* NeighbourhoodPageChange::getNeighbour(int num){
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
}*/

void NeighbourhoodPageChange::changePage(Solution* s, int edge, int pageNum){
    int prevPage = s->edgesListWithPages[edge][2];
    if (pageNum >= prevPage){
        pageNum += 1;
    }
    int a=calcualteCrossingsOnPage(s, prevPage);
    int b=calcualteCrossingsOnPage(s, pageNum);

    s->edgesListWithPages[edge][2] = pageNum;

    int c=calcualteCrossingsOnPage(s, prevPage);
    int d=calcualteCrossingsOnPage(s, pageNum);

    int crossings_change = a + b - c -d;
    s->crossings-=crossings_change;
}

Solution* NeighbourhoodPageChange::getRandomNeighbour(){
    //std::srand(std::time(0));
    Solution* result = new Solution(instance);
    int edgesNum = instance->edgesListWithPages.size();
    for(int i=0; i<k; i++){
        changePage(result, rand()%edgesNum, rand()%(instance->pagesNum-1));
    }
    //result->crossings=calculateCrossings(result);
    return result;
}


void NeighbourhoodPageChange::setInstance(Solution* x){
    instance = x;
    //calculateNeighbourhoodSize();
    //counter = -1;
    edges.clear();
    pages.clear();
    for(int i=0; i<k; ++i){
        edges.push_back(i);
        pages.push_back(0);
    }
    //pages[k-1] = -1;
}

int NeighbourhoodPageChange::changeEdges(){
    int i=k-1;
    int edgesNum = instance->edgesListWithPages.size();
    while(i>=0){
        if(edges[i]<edgesNum-1){
            edges[i]+=1;

            for(int j=i+1; j<k; ++j){
                if(edges[i] + j-i >= edgesNum){
                    return -1;
                }
                edges[j] = edges[i] + j-i;
            }

            return i;
        }
        else{
            i--;
        }
    }
    return i;
}

int NeighbourhoodPageChange::changePages(){
    int i=k-1;
    while(i>=0){
        if(pages[i]<instance->pagesNum-1){
            pages[i]+=1;
            return i;
        }
        else{
            pages[i]==0;
            i--;
        }
    }
    return i;
}
