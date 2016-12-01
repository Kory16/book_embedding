#include "neighbourhoodvertexreplacement.h"

NeighbourhoodVertexReplacement::NeighbourhoodVertexReplacement()
{

}

Solution* NeighbourhoodVertexReplacement::next(){
    if(changePositions() < 0){
        if(changeVertices() < 0){
            return nullptr;
        }
    }
    Solution* result = new Solution(instance);
    for(int i=0; i<k; i++){
        replaceVertex(result, vertices[i], positions[i]);
    }
    result->crossings=calculateCrossings(result);
    return result;
}

int NeighbourhoodVertexReplacement::changeVertices(){
    int i=k-1;
    while(i>=0){
        if(vertices[i]<instance->vertexNum-1){
            vertices[i]+=1;

            for(int j=i+1; j<k; ++j){
                if(vertices[i] + j-i >= instance->vertexNum){
                    return -1;
                }
                vertices[j] = vertices[i] + j-i;
            }

            return i;
        }
        else{
            i--;
        }
    }
    return i;
}

int NeighbourhoodVertexReplacement::changePositions(){
    int i=k-1;
    while(i>=0){
        if(positions[i]<instance->vertexNum-1){
            positions[i]+=1;
            return i;
        }
        else{
            positions[i]==0;
            i--;
        }
    }
    return i;
}

void NeighbourhoodVertexReplacement::calculateNeighbourhoodSize(){
    neighbourhoodSize = 1;
    for(int i=0; i<this->k; ++i){
        neighbourhoodSize=neighbourhoodSize * (this->instance->vertexNum - i)/(i+1);
    }
    neighbourhoodSize*=pow((this->instance->vertexNum - 1), this->k);
    //neighbourhoodSize = this->instance->vertexNum*(this->instance->vertexNum - 1);
}

Solution* NeighbourhoodVertexReplacement::getRandomNeighbour(){
    //std::srand(std::time(0));
    Solution* result = new Solution(instance);
    for(int i=0; i<k; i++){
        replaceVertex(result, rand()%instance->vertexNum, rand()%(instance->vertexNum - 1));
    }
    result->crossings=calculateCrossings(result);
    return result;
}

/*Solution* NeighbourhoodVertexReplacement::getNeighbour(int num){
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
}*/

void NeighbourhoodVertexReplacement::replaceVertex(Solution* s, int vertex, int posNum){
    int prevPosNum = s->vertexOrder[vertex];
    if (posNum >= prevPosNum){
        posNum += 1;
    }
    int first = min(posNum, prevPosNum);
    int second = max(posNum, prevPosNum);
    int sign = (posNum-prevPosNum > 0) ? 1 : ((posNum-prevPosNum < 0) ? -1 : 0);
    for(auto it = s->vertexOrder.begin(); it!=s->vertexOrder.end(); it++){
        if(it->first==vertex){
            it->second = posNum;
        }
        else{
            if(it->second >=first && it->second <= second){
                it->second -= sign;
            }
        }
    }
    //s->crossings=calculateCrossings(s);
}

void NeighbourhoodVertexReplacement::setInstance(Solution* x){
    instance = x;
    //calculateNeighbourhoodSize();
    vertices.clear();
    positions.clear();
    for(int i=0; i<k; ++i){
        vertices.push_back(i);
        positions.push_back(0);
    }
    //positions[k-1] = -1;
}


