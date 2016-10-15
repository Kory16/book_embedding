#include "deterministicconstructionheuristic.h"

DeterministicConstructionHeuristic::DeterministicConstructionHeuristic()
{

}

vector<vector<int> > DeterministicConstructionHeuristic::calculatePages(vector<vector<int> > edgesList, unsigned int K){
    edgesList.at(0)[2] = 0;
    for(unsigned int i = 1; i<edgesList.size(); i++){
        vector<unsigned int> CL;
        for(unsigned int j=0; j<K; j++){
            edgesList.at(i)[2]=j;
            int crossings = countCrossings(edgesList.begin(), edgesList.begin()+i, j);
            CL.push_back(crossings);
        }
        edgesList.at(i)[2] = choseMinimumCrossingPage(CL);
    }
    return edgesList;
}

unsigned int DeterministicConstructionHeuristic::choseMinimumCrossingPage(vector< unsigned int> pagesList){
    unsigned int min = pagesList[0];
    unsigned int minPage = 0;
    for(unsigned int i=1; i<pagesList.size(); i++){
        if(pagesList[i]<min){
            min = pagesList[i];
            minPage = i;
        }
    }
    return minPage;
}

unsigned int DeterministicConstructionHeuristic::countCrossings(vector< vector<int> >::iterator begin, vector< vector<int> >::iterator end, int pageNum){
    vector < vector<int> > edgesOnPage;
    for(; begin!=end; begin++){
        if (begin->at(2)!=pageNum)
            continue;
        edgesOnPage.push_back(*begin);
    }
    unsigned int crossings = 0;
    for(unsigned int i = 0; i<edgesOnPage.size(); i++){
        for(unsigned int j=i+1; j<edgesOnPage.size(); j++){
            int vi1 = min(edgesOnPage[i][0], edgesOnPage[i][1]);
            int vi2 = max(edgesOnPage[i][0], edgesOnPage[i][1]);
            int vj1 = min(edgesOnPage[j][0], edgesOnPage[j][1]);
            int vj2 = max(edgesOnPage[j][0], edgesOnPage[j][1]);
            if(vi1<vj1 && vj1<vi2 && vi2 <vj2){
                crossings++;
            }
        }
    }

    return crossings;
}
