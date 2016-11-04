#ifndef NEIGHBOURHOOD_VERTEX_H
#define NEIGHBOURHOOD_VERTEX_H

#include "neighbourhood.h"

class Neighbourhood_vertex : public Neighbourhood {

	
public:	
	Neighbourhood_vertex();
    vector <int> vertexOrder;
	Solution* next();
	void calculateNeighbourhoodSize();
	Solution* getNeighbour(int num);
	void virtual setInstance(Solution* x);


private:

	int calculateCrossings(Solution* solution);
	vector<unsigned int> verteOrder;
	vector<int> firstl;
	vector<int> secondl;
    void calculateLists();

};


#endif

