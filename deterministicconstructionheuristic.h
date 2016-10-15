#ifndef DETERMINISTICCONSTRUCTIONHEURISTIC_H
#define DETERMINISTICCONSTRUCTIONHEURISTIC_H

#include <vector>

using namespace std;

class DeterministicConstructionHeuristic
{
public:
    DeterministicConstructionHeuristic();

    void calculatePages(vector< vector<int> > *edgesList);

private:

    int countCrossings(vector< vector<int> > edgesList);
};

#endif // DETERMINISTICCONSTRUCTIONHEURISTIC_H
