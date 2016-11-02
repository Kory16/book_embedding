#ifndef NEIGHBOURHOOD_VERTEX_H
#define NEIGHBOURHOOD_VERTEX_H

#include "neighbourhood.h"

class Neighbourhood_vertex : public Neighbourhood {

	vector<KPMPInstance> neighbours;
	vector<unsigned int> vertexOrder;
	map <int, int> prev_vertexOrder;
public:	
	Neighbourhood_vertex(vector<unsigned int> vertexOrder);
	vector<KPMPInstance> getAllNeighbours(KPMPInstance & x, vector <unsigned int> contheur);
	KPMPInstance& next(KPMPInstance& x);


};


#endif

