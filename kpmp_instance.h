
#ifndef INSTANCE_READER_H_
#define INSTANCE_READER_H_

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <map>
#include "constructionheuristic.h"
#include "kpmp_solution_writer.h"
#include "solution.h"
#include "localsearch.h"
#include "NeighbourhoodPageChange.h"
#include "neighbourhood_vertex.h"
#include "randomstepfun.h"

using namespace std;

class KPMPInstance {
private: 
	unsigned int K;
	unsigned int numVertices;
	bool **adjacencyMatrix;

public:
    KPMPInstance(){}
    vector< vector<int> > edgesList;
    vector<vector<unsigned int> > adjacencyList;
    map <int, int> vertexOrder;
    int crossings;
    vector <unsigned int> getVerteOrder();

	static KPMPInstance* readInstance(string filename);

	~KPMPInstance() {
		for(unsigned i = 0; i < numVertices; i++)
			delete[] adjacencyMatrix[i];
		delete[] adjacencyMatrix;
	}

	unsigned int getK() const {
		return K;
	}

	unsigned int getNumVertices() const {
		return numVertices;
	}

    vector<vector<int> > getEdgesList(){
        return edgesList;
    }

	vector<vector<unsigned int> > getAdjacencyList() const {
		return adjacencyList;
	}

	bool** getAdjacencyMatrix() const {
		return adjacencyMatrix;
	}

    /*static bool compare_function (vector<int> i,vector<int> j){
        return (i[3]>j[3]);
    }*/
};

#endif /* INSTANCE_READER_H_ */
