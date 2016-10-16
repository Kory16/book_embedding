#ifndef DETERMINISTICCONSTRUCTIONHEURISTIC_H
#define DETERMINISTICCONSTRUCTIONHEURISTIC_H

#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <iostream>

using namespace std;

class ConstructionHeuristic
{
public:
    ConstructionHeuristic();

    int calculatePages(vector< vector<int> > & edgesList, unsigned int K, int randomnessCoeff = 0);

private:

    unsigned int countCrossings(vector< vector<int> >::iterator begin, vector< vector<int> >::iterator end, int pageNum);

    vector<unsigned int> pageSelection(vector<vector<unsigned int> > pagesList, int groupSize=1);

    static bool compare_function (vector<unsigned int> i,vector<unsigned int> j){
        return (i[1]<j[1]);
    }
};

#endif // DETERMINISTICCONSTRUCTIONHEURISTIC_H
