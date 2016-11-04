#include "neighbourhood_vertex.h"
#include "constructionheuristic.h"

Neighbourhood_vertex::Neighbourhood_vertex()
{
	

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
	std::map<int,int>::iterator buffer = Neighbourhood_vertex::instance->vertexOrder.find(firstl.at(num));
	Neighbourhood_vertex::instance->vertexOrder.find(firstl.at(num))->second = Neighbourhood_vertex::instance->vertexOrder.find(secondl.at(num))->second;
	Neighbourhood_vertex::instance->vertexOrder.find(secondl.at(num))->second = buffer->second;
	Solution * result = new Solution(instance);
	result->vertexOrder = Neighbourhood_vertex::instance->vertexOrder; //overwriting with new vertexorder
	int crossings = calculateCrossings(result);
	result->crossings = crossings;
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
	map<int, int> this_order = solution->vertexOrder;
	//TODO calculate crossings from new vertexorder
	return solution->crossings;
}

void Neighbourhood_vertex::calculateLists()
{
	int count = Neighbourhood_vertex::instance->vertexOrder.size();
	int number_to_write = 1;
	for (int j = 1; j < Neighbourhood_vertex::instance->vertexOrder.size(); j++) {
		for (int i = 1; i < count; i++) {
			firstl.push_back(number_to_write);
			secondl.push_back(number_to_write + i);
		}
		number_to_write++;
		count--;
	}
}
