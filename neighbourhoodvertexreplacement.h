#ifndef NEIGHBOURHOODVERTEXREPLACEMENT_H
#define NEIGHBOURHOODVERTEXREPLACEMENT_H

#include "neighbourhood.h"
#include <ctime>
#include <vector>

using namespace std;

class NeighbourhoodVertexReplacement : public Neighbourhood
{
public:
    NeighbourhoodVertexReplacement();

    Solution* next();
    void calculateNeighbourhoodSize();
    //Solution* getNeighbour(int num);
    Solution* getRandomNeighbour();

    void setInstance(Solution* x);

private:
    void replaceVertex(Solution* s, int vertex, int posNum);
    vector<int> vertices;
    vector<int> positions;
    int changeVertices();
    int changePositions();
};

#endif // NEIGHBOURHOODVERTEXREPLACEMENT_H
