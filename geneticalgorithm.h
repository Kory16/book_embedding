#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include "solution.h"
#include <vector>
#include <iostream>

using namespace std;

class GeneticAlgorithm
{
public:
    GeneticAlgorithm();
    void setParameters(int size, int k, double crossOverProb, double mutationProb, int iter);
    Solution* run();

private:
    void initialize();
    void select();
    void evaluate();
    void crossOver();
    void crossOverVertices();
    void crossOverPages();
    void mutate();
    void mutateVertices();
    void mutatePages();
    void replace();
    Solution* findBest();

    double crossOverProbability;
    double mutationProbability;
    int k; // how many the best parents is inserted to the new population
    int populationSize;
    int iterations;

    vector<Solution*> population;
    vector<Solution*> newPopulation;

    static bool compare_function (Solution* i, Solution j){
        return (i->crossings>j.crossings);
    }

};

#endif // GENETICALGORITHM_H
