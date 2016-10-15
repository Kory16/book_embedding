#ifndef DETERMINISTICCONSTRUCTIONHEURISTIC_H
#define DETERMINISTICCONSTRUCTIONHEURISTIC_H

#include <vector>
#include <cmath>

using namespace std;

class DeterministicConstructionHeuristic
{
public:
    DeterministicConstructionHeuristic();

    vector< vector<int> > calculatePages(vector< vector<int> > edgesList, unsigned int K);

private:

    unsigned int countCrossings(vector< vector<int> >::iterator begin, vector< vector<int> >::iterator end, int pageNum);

    unsigned int choseMinimumCrossingPage(vector<unsigned int> pagesList);
};

#endif // DETERMINISTICCONSTRUCTIONHEURISTIC_H
