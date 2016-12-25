#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <map>

using namespace std;


class Solution
{
public:
    Solution(int pagesNum, int vertexNum);
    Solution(const Solution* x);
    vector< vector <int> > edgesListWithPages; // [ [start verte, end vertex, page, edge length],..]
    map <int, int> vertexOrder; // {vertex numer: vertex position, ... }
    int crossings;
    int pagesNum;
    int vertexNum;
    vector <unsigned int> getVerteOrder();
    double fitness;

    static bool compare_solutions (Solution* i,Solution* j){
        return (i->crossings<j->crossings);
    }
};

#endif // SOLUTION_H
