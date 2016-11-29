#include "geneticalgorithm.h"

GeneticAlgorithm::GeneticAlgorithm()
{
    this->populationSize = 50;
    this->k = 10;
    this->crossOverProbability = 0.8;
    this->mutationProbability = 0.2;
    this->iterations = 20;
}

void GeneticAlgorithm::setParameters(int size, int k, double crossOverProb, double mutationProb, int iter){
    this->populationSize = size;
    this->k = k;
    this->crossOverProbability = crossOverProb;
    this->mutationProbability = mutationProb;
    this->iterations = iter;
}

Solution* GeneticAlgorithm::run(vector<vector<int> > &edgesListWithPages, int pagesNum, int verticesNum){
    int i = 0;
    Solution* best = nullptr;
    initialize(edgesListWithPages, pagesNum, verticesNum);
    evaluate();
    while(i<this->iterations){
        select();
        crossOver();
        mutate();
        replace();
        evaluate();
        best = findBest();
        cout<<"Iteration "<<i<<" , best instance crossings: "<<best->crossings<<endl;
        i++;
    }
    return best;
}

void GeneticAlgorithm::initialize(vector< vector <int> > & edgesListWithPages, int pagesNum, int verticesNum){
    clearPopulation(this->population);

    vector<int> v;
    for (int i=1; i<verticesNum; ++i) v.push_back(i); // 1 2 3 4 5 6 7 8 9

    std::srand(std::time(0));
    for (int i=0; i<this->populationSize; ++i){
        Solution* result = new Solution(pagesNum, verticesNum);
        for(auto it=edgesListWithPages.begin(); it!=edgesListWithPages.end(); it++){
            result->edgesListWithPages.push_back(vector<int>());
            result->edgesListWithPages.back().push_back(it->at(0));
            result->edgesListWithPages.back().push_back(it->at(1));
            result->edgesListWithPages.back().push_back(rand()%pagesNum);
        }

        // using built-in random generator:
        std::random_shuffle ( v.begin(), v.end() );

        for(int i=0; i<v.size(); ++i){
            result->vertexOrder[v[i]] = i;
        }

        this->population.push_back(result);
    }
}

void GeneticAlgorithm::select(){
    // roulette wheel selection
    clearPopulation(this->newPopulation);
    std::srand(std::time(0));
    double totalFitness = 0;
    for(auto it = this->population.begin(); it!=this->population.end(); ++it){
       totalFitness += (*it)->fitness;
    }
    for(int i=0; i<populationSize; ++i){
        int p = (double)rand()/ RAND_MAX * totalFitness;
        auto it = this->population.begin();
        double fitnessSum = 0;
        while(p>=fitnessSum && p<fitnessSum + (*it)->fitness){
            fitnessSum += (*it)->fitness;
            ++it;
        }
        this->newPopulation.push_back((*it));
    }
}

void GeneticAlgorithm::evaluate(){
    for(auto it = this->population.begin(); it!=this->population.end(); ++it){
       (*it)->crossings = calculateCrossings(*it);
        (*it)->fitness = 1.0/(*it)->crossings;
    }
}

void GeneticAlgorithm::crossOver(){

}

void GeneticAlgorithm::crossOverVertices(){

}

void GeneticAlgorithm::crossOverPages(){

}

void GeneticAlgorithm::mutate(){

}

void GeneticAlgorithm::mutateVertices(){

}

void GeneticAlgorithm::mutatePages(){

}

void GeneticAlgorithm::replace(){

}

Solution* GeneticAlgorithm::findBest(){
    if (this->population.size() == 0){
        return nullptr;
    }
    Solution* best = this->population[0];
    for(auto it=this->population.begin()+1; it!=this->population.end(); ++it){
        if(best->crossings>(*it)->crossings){
            best = *it;
        }
    }
    return best;
}

int GeneticAlgorithm::calcualteCrossingsOnPage(Solution* solution, int pageNum){
    vector < vector<int> > edgesOnPage;
    for(auto it = solution->edgesListWithPages.begin(); it!=solution->edgesListWithPages.end(); ++it){
        if (it->at(2)!=pageNum)
            continue;
        edgesOnPage.push_back(*it);
    }
    unsigned int crossings = 0;

    // for all edges on the page, count how much crossing will be caused by adding a new edge
    for(unsigned int i = 0; i<edgesOnPage.size(); i++){
        int vi1 = min(solution->vertexOrder[edgesOnPage[i][0]], solution->vertexOrder[edgesOnPage[i][1]]);
        int vi2 = max(solution->vertexOrder[edgesOnPage[i][0]], solution->vertexOrder[edgesOnPage[i][1]]);
        for(unsigned int j =i+1; j<edgesOnPage.size(); j++){
            int vj1 = min(solution->vertexOrder[edgesOnPage[j][0]], solution->vertexOrder[edgesOnPage[j][1]]);
            int vj2 = max(solution->vertexOrder[edgesOnPage[j][0]], solution->vertexOrder[edgesOnPage[j][1]]);
            if((vi1<vj1 && vj1<vi2 && vi2<vj2) || (vj1<vi1 && vi1<vj2 && vj2<vi2)){
                crossings++;
            }
        }
    }

    return crossings;
}

int GeneticAlgorithm::calculateCrossings(Solution * solution)
{
    int crossings = 0;
    for(int i=0; i<solution->pagesNum; ++i){
        crossings+=this->calcualteCrossingsOnPage(solution, i);
    }
    return crossings;
}

void GeneticAlgorithm::clearPopulation(vector<Solution*> p){
    for(int i =0; i<p.size(); ++i){
        delete p[i];
    }
    p.clear();
}
