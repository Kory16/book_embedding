#include "neighbourhood_vertex.h"
#include "constructionheuristic.h"

Neighbourhood_vertex::Neighbourhood_vertex(vector<unsigned int> verteOrder,vector<vector<int>>edgesList, vector<vector<unsigned int> > adjacencyList, unsigned int K, int numVertices, int randomnessCoeff)
{
	Neighbourhood_vertex::edgesList = edgesList;
	Neighbourhood_vertex::adjacencyList = adjacencyList;
	Neighbourhood_vertex::K = K;
	Neighbourhood_vertex::numVertices = numVertices;
	for (int i = 0; i < Neighbourhood_vertex::numVertices; i++) {
		Neighbourhood_vertex::vertexOrder.push_back(i);
	}
	Neighbourhood_vertex::setInitialVertexOrder(verteOrder);
	Neighbourhood_vertex::calculateLists();
}

Solution * Neighbourhood_vertex::next()
{
	counter++;
	return getNeighbour(counter);
}

void Neighbourhood_vertex::calculateNeighbourhoodSize()
{
	neighbourhoodSize = Neighbourhood_vertex::instance->vertexNum * (Neighbourhood_vertex::instance->vertexNum)-1;
	neighbourhoodSize = neighbourhoodSize / 2; //to avoid calculating twice
}

Solution * Neighbourhood_vertex::getNeighbour(int num)
{
	int buffer = Neighbourhood_vertex::verteOrder[Neighbourhood_vertex::first[num]];
	Neighbourhood_vertex::verteOrder[Neighbourhood_vertex::first[num]] = Neighbourhood_vertex::verteOrder[Neighbourhood_vertex::second[num]];
	Neighbourhood_vertex::verteOrder[Neighbourhood_vertex::second[num]] = buffer;
	Solution * result = new Solution(instance);
	for (int i = 0; i < Neighbourhood_vertex::numVertices;i++) { //converting vector to map
		Neighbourhood_vertex::vOrder.insert(std::pair< int,int>(i, Neighbourhood_vertex::verteOrder[i]));
	}
	result->vertexOrder = Neighbourhood_vertex::vOrder; //overwriting with new vertexorder
	return result;
}

void Neighbourhood_vertex::setInstance(Solution * x)
{
	instance = x;
	calculateNeighbourhoodSize();
	counter = -1;
}

int Neighbourhood_vertex::calculateCrossings(Solution * solution)
{
	//really inefficient, lacks interative evaluation
	ConstructionHeuristic cr;
	solution = cr.calculatePages(Neighbourhood_vertex::edgesList,Neighbourhood_vertex::adjacencyList,Neighbourhood_vertex::K,Neighbourhood_vertex::numVertices,0);
	return solution->crossings;
}

void Neighbourhood_vertex::setInitialVertexOrder(vector<unsigned int> vertexOrder)
{
	Neighbourhood_vertex::verteOrder = verteOrder;
}

void Neighbourhood_vertex::calculateLists()
{
	int count = Neighbourhood_vertex::numVertices;
	int number_to_write = 1;
	for (int j = 1; j < Neighbourhood_vertex::numVertices; j++) {
		for (int i = 1; i < count; i++) {
			first.push_back(number_to_write);
			second.push_back(number_to_write + i);
		}
		number_to_write++;
		count--;
	}
}
