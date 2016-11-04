#ifndef NEIGHBOURHOOD_VERTEX_H
#define NEIGHBOURHOOD_VERTEX_H

#include "neighbourhood.h"

class Neighbourhood_vertex : public Neighbourhood {
	
public:	
    Neighbourhood_vertex();
	Solution* next();
	void calculateNeighbourhoodSize();
	Solution* getNeighbour(int num);
	void virtual setInstance(Solution* x);


private:
    int calculateCrossings(Solution* solution);
    //map<int,int> vOrder;
    //vector<int> first;
    //vector<int> second;
    //void calculateLists();

};


#endif

