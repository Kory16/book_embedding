#include "neighbourhood_vertex.h"
#include "constructionheuristic.h"

Neighbourhood_vertex::Neighbourhood_vertex()
{
   
}

Solution * Neighbourhood_vertex::next()
{
    if(increaseVerticesNum(firstl) < 0){
        if(increaseVerticesNum(secondl) < 0){
            return nullptr;
        }
    }
    Solution* result = new Solution(instance);
    for(int i=0; i<k; i++){
        swapVertexes(result, firstl[i], secondl[i]);
    }
    result->crossings=calculateCrossings(result);
    return result;
}

void Neighbourhood_vertex::calculateNeighbourhoodSize()
{
    neighbourhoodSize = instance->vertexNum * (instance->vertexNum-1);
	neighbourhoodSize = neighbourhoodSize / 2; //to avoid calculating twice
}

/*Solution * Neighbourhood_vertex::getNeighbour(int num)
{

//    Solution * result = new Solution(instance);

//    int c = -1;
//    int x=0, y=1;
//    for(int i=0; i<instance->vertexNum && c!=num; i++){
//        for(int j=i+1; j<instance->vertexNum && c!=num; j++){
//            c++;
//            x=i;
//            y=j;
//        }
//    }

//    int tmp = result->vertexOrder[x];
//    result->vertexOrder[x] = result->vertexOrder[y];
//    result->vertexOrder[y] = tmp;

//    result->crossings = calculateCrossings(result);
//    return result;


    std::map<int, int>::iterator buffer = instance->vertexOrder.find(firstl.at(num)-1);
	int buf = buffer->second;

    instance->vertexOrder.find(firstl.at(num)-1)->second = instance->vertexOrder.find(secondl.at(num)-1)->second;
    instance->vertexOrder.find(secondl.at(num)-1)->second = buf;
	Solution * result = new Solution(instance);
    result->vertexOrder = instance->vertexOrder; //overwriting with new vertexorder
	int crossings = calculateCrossings(result);
	result->crossings = crossings;
	return result;

}*/

void Neighbourhood_vertex::setInstance(Solution * x)
{
	instance = x;
    //Neighbourhood_vertex::calculateLists();
    //calculateNeighbourhoodSize();
    //counter = -1;
    firstl.clear();
    secondl.clear();
    for(int i=0; i<k; ++i){
        firstl.push_back(i);
        secondl.push_back(i);
    }
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

Solution* Neighbourhood_vertex::getRandomNeighbour(){
    //std::srand(std::time(0));
    Solution* result = new Solution(instance);
    for(int i=0; i<k; i++){
        swapVertexes(result, rand()%instance->vertexNum, rand()%instance->vertexNum);
    }
    result->crossings=calculateCrossings(result);
    return result;
}

void Neighbourhood_vertex::swapVertexes(Solution* s, int v1, int v2){
    if(v1!=v2){
        int tmp = s->vertexOrder[v1];
        s->vertexOrder[v1] = s->vertexOrder[v2];
        s->vertexOrder[v2] = tmp;
    }

}

int Neighbourhood_vertex::increaseVerticesNum(vector<int>& vertices){
    int i=k-1;
    while(i>=0){
        if(vertices[i]<instance->vertexNum-1){
            vertices[i]+=1;
            return i;
        }
        else{
            vertices[i]==0;
            i--;
        }
    }
    return i;
}
