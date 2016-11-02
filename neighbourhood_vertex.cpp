#include "neighbourhood_vertex.h"

Neighbourhood_vertex::Neighbourhood_vertex(vector<unsigned int> vertexOrder) : Neighbourhood()
{
	//get vertex order of initial solution
	Neighbourhood_vertex::vertexOrder = vertexOrder;
}

vector<KPMPInstance> Neighbourhood_vertex::getAllNeighbours(KPMPInstance & x, vector <unsigned int> constheur)
{
	
	//fill result vector with KPMP elements
	//generate vertex order variations
	//save vertex order variations into KPMP stuctures
	//return result
	return Neighbourhood_vertex::neighbours;
}

KPMPInstance & Neighbourhood_vertex::next(KPMPInstance & x)
{
	// TODO: insert return statement here
	return x;
}
