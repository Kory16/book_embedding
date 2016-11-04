#ifndef NEIGHBOURHOOD_VERTEX_H
#define NEIGHBOURHOOD_VERTEX_H

#include "neighbourhood.h"

class Neighbourhood_vertex : public Neighbourhood {

	vector< vector<int> >  edgesList;
	vector<vector<unsigned int> > adjacencyList;
	unsigned int K;
	int numVertices;
	vector <int> vertexOrder;
	
public:	
	Neighbourhood_vertex(vector<unsigned int> verteOrder,vector< vector<int> > edgesList, vector<vector<unsigned int> >adjacencyList, unsigned int K, int numVertices, int randomnessCoeff);
	Solution* next();
	void calculateNeighbourhoodSize();
	Solution* getNeighbour(int num);
	void virtual setInstance(Solution* x);
private:
	int calculateCrossings(Solution* solution);
	vector< unsigned int> verteOrder;
	map<int,int> vOrder;
	void setInitialVertexOrder(vector< unsigned int> vertexOrder);
	vector<int> first;
	vector<int> second;
	void calculateLists();

};


#endif

