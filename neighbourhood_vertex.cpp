#include "neighbourhood_vertex.h"
#include "constructionheuristic.h"

Neighbourhood_vertex::Neighbourhood_vertex()
{
    //Neighbourhood_vertex::calculateLists();
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
    /*int buffer = Neighbourhood_vertex::verteOrder[Neighbourhood_vertex::first[num]];
	Neighbourhood_vertex::verteOrder[Neighbourhood_vertex::first[num]] = Neighbourhood_vertex::verteOrder[Neighbourhood_vertex::second[num]];
	Neighbourhood_vertex::verteOrder[Neighbourhood_vertex::second[num]] = buffer;
	Solution * result = new Solution(instance);
	for (int i = 0; i < Neighbourhood_vertex::numVertices;i++) { //converting vector to map
		Neighbourhood_vertex::vOrder.insert(std::pair< int,int>(i, Neighbourhood_vertex::verteOrder[i]));
	}
	result->vertexOrder = Neighbourhood_vertex::vOrder; //overwriting with new vertexorder
    return result;*/

    Solution * result = new Solution(instance);

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
    int crossings = 0;
    for(int i=0; i<solution->pagesNum; ++i){
        crossings+=this->calcualteCrossingsOnPage(solution, i);
    }
    return crossings;
}

/*void Neighbourhood_vertex::calculateLists()
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
}*/
