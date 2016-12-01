#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include "solution.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <map>

using namespace std;

class GeneticAlgorithm
{
public:
    GeneticAlgorithm();
    void setParameters(int size, int k, double crossOverProb, double mutationProb, int iter);
    Solution* run(vector< vector <int> >& edgesListWithPages, int pagesNum, int verticesNum);

private:
    void initialize(vector< vector <int> >& edgesListWithPages, int pagesNum, int verticesNum);
    void select();
    void evaluate();
    void crossOver();
    void crossOverVertices(Solution* parent1, Solution* parent2, Solution* child1, Solution* child2);
    void crossOverPages(Solution *parent1, Solution *parent2, Solution *child1, Solution *child2);
    void mutate();
    void mutateVertices(int x);
    void mutatePages(int x);
    void replace();
    Solution* findBest();
    int calculateCrossings(Solution * solution);
    int calcualteCrossingsOnPage(Solution* solution, int pageNum);
    void clearPopulation(vector<Solution*> p);

    double crossOverProbability;
    double mutationProbability;
    int k; // how many the best parents is inserted to the new population
    int populationSize;
    int iterations;

    vector<Solution*> population;
    vector<Solution*> selectedPopulation;
    vector<Solution*> newPopulation;

    static bool compare_function (Solution* i, Solution j){
        return (i->crossings>j.crossings);
    }

};

#endif // GENETICALGORITHM_H
