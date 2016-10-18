#ifndef DETERMINISTICCONSTRUCTIONHEURISTIC_H
#define DETERMINISTICCONSTRUCTIONHEURISTIC_H

#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <map>

using namespace std;

class ConstructionHeuristic
{
public:
    ConstructionHeuristic();

    int calculatePages(vector< vector<int> > & edgesList, vector<vector<unsigned int> > &adjacencyList, unsigned int K, int numVertices, int randomnessCoeff = 0);

    vector< vector <int> > getEdgesWithPages(){
        return edgesListWithPages;
    }

    vector <unsigned int> getVerteOrder(){
        vector <unsigned int> result;
        for(auto it=vertexOrder.begin(); it!=vertexOrder.end(); ++it){
            result.push_back(it->first);
        }
        return result;
    }

private:
    vector< vector <int> > edgesListWithPages;
    map <int, int> vertexOrder; // vertex numer: vertex position

    void setVertexOrder(vector<vector<unsigned int> > &adjacencyList, int numVertices);
    void DFS(int v, bool visited[], vector<vector<unsigned int> > &adjacencyList, int numVertices);
    void calculateEdgesLenAndSort(vector< vector<int> > & edgesList);

    unsigned int countCrossings(vector< vector<int> >::iterator begin, vector< vector<int> >::iterator end, int pageNum);

    vector<unsigned int> pageSelection(vector<vector<unsigned int> > pagesList, int groupSize=1);



    static bool compare_function (vector<unsigned int> i,vector<unsigned int> j){
        return (i[1]<j[1]);
    }

    static bool compare_edges_function (vector<int> i,vector<int> j){
        return (i[3]>j[3]);
    }
};

#endif // DETERMINISTICCONSTRUCTIONHEURISTIC_H
