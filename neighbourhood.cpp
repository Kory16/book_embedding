#include "neighbourhood.h"

Neighbourhood::Neighbourhood()
{
    k=1;
    counter = -1;
    instance = nullptr;
    neighbourhoodSize = 0;
}

Neighbourhood::~Neighbourhood(){
    delete instance;
}
