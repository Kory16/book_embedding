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

Solution* GeneticAlgorithm::run(){
    int i = 0;
    Solution* best = nullptr;
    initialize();
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

void GeneticAlgorithm::initialize(){

}

void GeneticAlgorithm::select(){

}

void GeneticAlgorithm::evaluate(){

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
