#include "neighbourhoodvertexreplacement.h"

NeighbourhoodVertexReplacement::NeighbourhoodVertexReplacement()
{

}

Solution* NeighbourhoodVertexReplacement::next(){
    counter++;
    return getNeighbour(counter);
}

void NeighbourhoodVertexReplacement::calculateNeighbourhoodSize(){
    neighbourhoodSize = this->instance->vertexNum*(this->instance->vertexNum - 1);
}

Solution* NeighbourhoodVertexReplacement::getNeighbour(int num){
    int posNum = num%(instance->vertexNum-1);
    int vertex = num/(instance->vertexNum-1);
    int prevPosNum = instance->vertexOrder[vertex];
    if (posNum >= prevPosNum){
        posNum += 1;
    }

    Solution* result = new Solution(instance);

    int first = min(posNum, prevPosNum);
    int second = max(posNum, prevPosNum);
    int sign = (posNum-prevPosNum > 0) ? 1 : ((posNum-prevPosNum < 0) ? -1 : 0);
    for(auto it = result->vertexOrder.begin(); it!=result->vertexOrder.end(); it++){
        if(it->first==vertex){
            it->second = posNum;
        }
        else{
            if(it->second >=first && it->second <= second){
                it->second -= sign;
            }
        }
    }
    int test = calculateCrossings(instance);
    result->crossings=calculateCrossings(result);
    return result;
}


void NeighbourhoodVertexReplacement::setInstance(Solution* x){
    instance = x;
    calculateNeighbourhoodSize();
    counter = -1;
}

int NeighbourhoodVertexReplacement::calculateCrossings(Solution * solution)
{
    int crossings = 0;
    for(int i=0; i<solution->pagesNum; ++i){
        crossings+=this->calcualteCrossingsOnPage(solution, i);
    }
    return crossings;
}
