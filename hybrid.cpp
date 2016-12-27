#include "hybrid.h"

Hybrid::Hybrid()
{

}

void Hybrid::setLocalSearchParameters(Neighbourhood *neighbourhood, StepFunction *stepFun){
    this->neighbourhood = neighbourhood;
    this->stepFun = stepFun;
}

void Hybrid::setGAparameters(int size, double crossOverProb, double mutationProb, int iter){
    this->populationSize = size;
    this->crossOverProability = crossOverProb;
    this->mutationProbability = mutationProb;
    this->maxIterationNum = iter;
}

void Hybrid::setOtherParameters(int bestSolutionsNum){
    this->solutionsExplorNum = bestSolutionsNum;
}

Solution* Hybrid::calculate(vector< vector <int> >& edgesList, int pagesNum, int verticesNum){
    // Genetic Algorithm
    GeneticAlgorithm geneticAlgorithm;
    geneticAlgorithm.setParameters(this->populationSize, this->crossOverProability, this->mutationProbability, this->maxIterationNum);
    Solution* solution = geneticAlgorithm.run(edgesList, pagesNum, verticesNum);
    if(solution->crossings==0){
        return solution;
    }

    vector<Solution*> population = geneticAlgorithm.getPopulation();
    vector<Solution*> bestSolutions = this->findBestSolutions(population, solutionsExplorNum);

    // Local search to explore neighbourhood
    Solution* solution_lc;
    int iterations = 0;
    for(auto it = bestSolutions.begin(); it!=bestSolutions.end(); ++it){
        LocalSearch ls(*it);
        solution_lc = ls.calculatePages(this->neighbourhood, this->stepFun);
        iterations+=ls.iteration;
        if(solution_lc->crossings < solution->crossings){
            delete solution;
            solution = solution_lc;
        }
        else{
            delete solution_lc;
        }
    }
    cout<<"Local search iterations: "<<iterations-solutionsExplorNum<<endl;
    cout<<"Final solution "<<solution->crossings<<" crossings."<<endl;
    return solution;
}

vector<Solution*> Hybrid::findBestSolutions(vector<Solution*> solutions, int k){
    if (solutions.size() == 0 || k<=0){
        return vector<Solution*>();
    }
    sort(solutions.begin(), solutions.end(), Solution::compare_solutions);
    return vector<Solution*>(solutions.begin(), solutions.begin()+k);
}
