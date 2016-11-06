#include "neighbourhood_vertex.h"
#include "constructionheuristic.h"

Neighbourhood_vertex::Neighbourhood_vertex()
{
   
}

Solution * Neighbourhood_vertex::next()
{
	counter++;
	return getNeighbour(counter);
}

void Neighbourhood_vertex::calculateNeighbourhoodSize()
{
    neighbourhoodSize = instance->vertexNum * (instance->vertexNum-1);
	neighbourhoodSize = neighbourhoodSize / 2; //to avoid calculating twice
}

Solution * Neighbourhood_vertex::getNeighbour(int num)
{

   /* Solution * result = new Solution(instance);

    int c = -1;
    int x=0, y=1;
    for(int i=0; i<instance->vertexNum && c!=num; i++){
        for(int j=i+1; j<instance->vertexNum && c!=num; j++){
            c++;
            x=i;
            y=j;
        }
    }

    int tmp = result->vertexOrder[x];
    result->vertexOrder[x] = result->vertexOrder[y];
    result->vertexOrder[y] = tmp;

    result->crossings = calculateCrossings(result);
    return result;*/


	std::map<int, int>::iterator buffer = Neighbourhood_vertex::instance->vertexOrder.find(firstl.at(num)-1);
	int buf = buffer->second;

	Neighbourhood_vertex::instance->vertexOrder.find(firstl.at(num)-1)->second = Neighbourhood_vertex::instance->vertexOrder.find(secondl.at(num)-1)->second;
	Neighbourhood_vertex::instance->vertexOrder.find(secondl.at(num)-1)->second = buf;
	Solution * result = new Solution(instance);
	result->vertexOrder = Neighbourhood_vertex::instance->vertexOrder; //overwriting with new vertexorder
	int crossings = calculateCrossings(result);
	result->crossings = crossings;
	return result;

}

void Neighbourhood_vertex::setInstance(Solution * x)
{
	instance = x;
	Neighbourhood_vertex::calculateLists();
	calculateNeighbourhoodSize();
	counter = -1;
}

int Neighbourhood_vertex::calculateCrossings(Solution * solution)
{
    int crossings = 0;
    for(int i=0; i<solution->pagesNum; ++i){
        crossings+=this->calcualteCrossingsOnPage(solution, i);
    }
    return crossings;
}



void Neighbourhood_vertex::calculateLists()
{
	int count = Neighbourhood_vertex::instance->vertexNum;
	int number_to_write = 1;
	for (int j = 1; j < Neighbourhood_vertex::instance->vertexNum; j++) {
		for (int i = 1; i < count; i++) {
			firstl.push_back(number_to_write);
			secondl.push_back(number_to_write + i);
		}
		number_to_write++;
		count--;
	}
}
