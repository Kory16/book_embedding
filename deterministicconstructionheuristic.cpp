#include "deterministicconstructionheuristic.h"

ConstructionHeuristic::ConstructionHeuristic()
{
}

vector<vector<int> > ConstructionHeuristic::calculatePages(vector<vector<int> > edgesList, unsigned int K){
    edgesList.at(0)[2] = 0;
    for(unsigned int i = 1; i<edgesList.size(); i++){
        vector<vector<unsigned int> > CL;
        //cout <<"Current EDGE: " <<edgesList.at(i)[0] << "," << edgesList.at(i)[1]<<endl;
        for(unsigned int j=0; j<K; j++){
            //edgesList.at(i)[2]=j;
            int crossings = countCrossings(edgesList.begin(), edgesList.begin()+i, j);
            CL.push_back(vector<unsigned int>());
            CL.back().push_back(j);
            CL.back().push_back(crossings);
        }
        edgesList.at(i)[2] = pageSelection(CL);
        //cout <<"Putting it to page " <<edgesList.at(i)[2] <<endl;
    }
    return edgesList;
}

/*unsigned int ConstructionHeuristic::choseMinimumCrossingPage(vector< unsigned int> pagesList){
    unsigned int min = pagesList[0];
    unsigned int minPage = 0;
    for(unsigned int i=1; i<pagesList.size(); i++){
        if(pagesList[i]<min){
            min = pagesList[i];
            minPage = i;
        }
    }
    return minPage;
}*/

unsigned int ConstructionHeuristic::pageSelection(vector<vector<unsigned int> > pagesList, int groupSize){
    /*cout <<  "BEFORE: "<<endl;
    for (int k = 0; k<pagesList.size();k++){
        cout << pagesList[k][0] << " , "<<pagesList[k][1]<<endl;
    }*/
    sort(pagesList.begin(), pagesList.end(), ConstructionHeuristic::compare_function);
    std::srand(std::time(0));
    int randPage = std::rand() % groupSize;
    /*for (int k = 0; k<pagesList.size();k++){
        cout << pagesList[k][0] << " , "<<pagesList[k][1]<<endl;
    }
    cout << pagesList[randPage][0] << endl;*/
    return pagesList[randPage][0];
}

unsigned int ConstructionHeuristic::countCrossings(vector< vector<int> >::iterator begin, vector< vector<int> >::iterator end, int pageNum){
    vector < vector<int> > edgesOnPage;
    for(; begin!=end; begin++){
        if (begin->at(2)!=pageNum)
            continue;
        edgesOnPage.push_back(*begin);
    }
    unsigned int crossings = 0;
    int vj1 = min(end->at(0), end->at(1));
    int vj2 = max(end->at(0), end->at(1));
    for(unsigned int i = 0; i<edgesOnPage.size(); i++){
        int vi1 = min(edgesOnPage[i][0], edgesOnPage[i][1]);
        int vi2 = max(edgesOnPage[i][0], edgesOnPage[i][1]);
        if((vi1<vj1 && vj1<vi2 && vi2<vj2) || (vj1<vi1 && vi1<vj2 && vj2<vi2)){
            crossings++;
        }
    }

    return crossings;
}
