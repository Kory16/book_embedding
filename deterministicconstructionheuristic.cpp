#include "deterministicconstructionheuristic.h"

ConstructionHeuristic::ConstructionHeuristic()
{
}

int ConstructionHeuristic::calculatePages(vector< vector<int> > & edgesList, vector<vector<unsigned int> > &adjacencyList, unsigned int K, int numVertices, int randomnessCoeff){
    setVertexOrder(adjacencyList, numVertices);
    calculateEdgesLenAndSort(edgesList);
    this->edgesListWithPages[0][2] = 0;
    int crossings = 0;
    int groupSize = min(max(int(randomnessCoeff*K/100), 1), int(K));
    for(int i=1; i<this->edgesListWithPages.size(); i++){
        vector<vector<unsigned int> > CL;
        for(unsigned int j=0; j<K; j++){
            int crossings = countCrossings(this->edgesListWithPages.begin(), this->edgesListWithPages.begin()+i, j);
            CL.push_back(vector<unsigned int>());
            CL.back().push_back(j);
            CL.back().push_back(crossings);
        }
        vector<unsigned int> selectedPage = pageSelection(CL, groupSize);
        this->edgesListWithPages[i][2] = selectedPage[0];
        crossings += selectedPage[1];
    }
    return crossings;
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

vector<unsigned int> ConstructionHeuristic::pageSelection(vector<vector<unsigned int> > pagesList, int groupSize){
    sort(pagesList.begin(), pagesList.end(), ConstructionHeuristic::compare_function);
    std::srand(std::time(0));
    int randPage = std::rand() % groupSize;
    return pagesList[randPage];
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

void ConstructionHeuristic::setVertexOrder(vector<vector<unsigned int> > &adjacencyList, int numVertices){
    bool *visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    int maxVertex = 0;
    int maxVertexDegree = adjacencyList[0].size();
    for(int i=1; i<numVertices; i++){
        if(maxVertexDegree<adjacencyList[i].size()){
            maxVertex = i;
            maxVertexDegree = adjacencyList[i].size();
        }
    }

    DFS(maxVertex, visited, adjacencyList, numVertices);
}

void ConstructionHeuristic::DFS(int v, bool visited[], vector<vector<unsigned int> > &adjacencyList, int numVertices){
    visited[v] = true;
    this->vertexOrder[v] = this->vertexOrder.size();
    if(this->vertexOrder.size()<numVertices){
        for(auto i = adjacencyList[v].end(); i!=adjacencyList[v].begin(); --i){
            if(!visited[*(i-1)]){
                DFS(*(i-1), visited, adjacencyList, numVertices);
            }
        }

    }

}

void ConstructionHeuristic::calculateEdgesLenAndSort(vector< vector<int> > & edgesList){
    for(auto it = edgesList.begin(); it!=edgesList.end(); it++){
        this->edgesListWithPages.push_back(vector<int>());
        int begin = it->at(0);
        int end = it->at(1);
        this->edgesListWithPages.back().push_back(begin);
        this->edgesListWithPages.back().push_back(end);
        this->edgesListWithPages.back().push_back(-1); // for page assigment
        this->edgesListWithPages.back().push_back(abs(this->vertexOrder[begin]-this->vertexOrder[end]));
    }
    sort(edgesListWithPages.begin(), edgesListWithPages.end(), ConstructionHeuristic::compare_edges_function);
}
