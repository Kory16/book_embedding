#include "neighbourhood.h"

Neighbourhood::Neighbourhood()
{
    k=1;
    counter = -1;
    instance = nullptr;
    neighbourhoodSize = 0;
}

Neighbourhood::~Neighbourhood(){
    delete instance;
}

int Neighbourhood::calcualteCrossingsOnPage(Solution* solution, int pageNum){
    vector < vector<int> > edgesOnPage;
    for(auto it = solution->edgesListWithPages.begin(); it!=solution->edgesListWithPages.end(); ++it){
        if (it->at(2)!=pageNum)
            continue;
        edgesOnPage.push_back(*it);
    }
    unsigned int crossings = 0;

    // for all edges on the page, count how much crossing will be caused by adding a new edge
    for(unsigned int i = 0; i<edgesOnPage.size(); i++){
        int vi1 = min(solution->vertexOrder[edgesOnPage[i][0]], solution->vertexOrder[edgesOnPage[i][1]]);
        int vi2 = max(solution->vertexOrder[edgesOnPage[i][0]], solution->vertexOrder[edgesOnPage[i][1]]);
        for(unsigned int j =i+1; j<edgesOnPage.size(); j++){
            int vj1 = min(solution->vertexOrder[edgesOnPage[j][0]], solution->vertexOrder[edgesOnPage[j][1]]);
            int vj2 = max(solution->vertexOrder[edgesOnPage[j][0]], solution->vertexOrder[edgesOnPage[j][1]]);
            if((vi1<vj1 && vj1<vi2 && vi2<vj2) || (vj1<vi1 && vi1<vj2 && vj2<vi2)){
                crossings++;
            }
        }
    }

    return crossings;
}
