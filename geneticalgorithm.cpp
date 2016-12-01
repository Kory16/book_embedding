#include "geneticalgorithm.h"

GeneticAlgorithm::GeneticAlgorithm()
{
    this->populationSize = 50;
    this->k = 10;
    this->crossOverProbability = 0.8;
    this->mutationProbability = 0.2;
    this->maxIterations = 20;
}

void GeneticAlgorithm::setParameters(int size, double crossOverProb, double mutationProb, int iter){
    this->populationSize = size;
    //this->k = k;
    this->crossOverProbability = crossOverProb;
    this->mutationProbability = mutationProb;
    this->maxIterations = iter;
}

Solution* GeneticAlgorithm::run(vector<vector<int> > &edgesList, int pagesNum, int verticesNum){
    iterations = 0;
    Solution* best = nullptr;
    Solution* currentBest = nullptr;
    initialize(edgesList, pagesNum, verticesNum);
    evaluate();
    while(iterations<this->maxIterations){
        select();
        crossOver();
        mutate();
        replace();
        evaluate();
        currentBest = findBest();
        if(best != nullptr && best->crossings > currentBest->crossings){
            delete best;
            best = new Solution(currentBest);
        }
        else{
            if(best==nullptr){
                best = new Solution(currentBest);
            }
        }
        cout<<"Iteration "<<iterations<<" , best instance crossings: "<<currentBest->crossings<<endl;
        iterations++;
    }
    return best;
}

void GeneticAlgorithm::initialize(vector< vector <int> > & edgesList, int pagesNum, int verticesNum){
    clearPopulation(this->population);

    vector<int> v;
    for (int i=0; i<verticesNum; ++i) v.push_back(i); // 1 2 3 4 5 6 7 8 9

    for (int i=0; i<this->populationSize; ++i){
        Solution* result = new Solution(pagesNum, verticesNum);
        for(auto it=edgesList.begin(); it!=edgesList.end(); it++){
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
    //clearPopulation(selectedPopulation);
    //std::srand(std::time(0));
    double totalFitness = 0;
    for(auto it = this->population.begin(); it!=this->population.end(); ++it){
       totalFitness += (*it)->fitness;
    }
    for(int i=0; i<populationSize; ++i){
        double p = (double)rand()/ RAND_MAX * totalFitness;
        auto it = this->population.begin();
        double fitnessSum = 0;
        while(p>=fitnessSum && p<fitnessSum + (*it)->fitness){
            fitnessSum += (*it)->fitness;
            ++it;
        }
        this->selectedPopulation.push_back((*it));
    }
}

void GeneticAlgorithm::evaluate(){
    for(auto it = this->population.begin(); it!=this->population.end(); ++it){
       (*it)->crossings = calculateCrossings(*it);
        (*it)->fitness = 1.0/(*it)->crossings;
    }
}

void GeneticAlgorithm::crossOver(){
    int first = 0;
    int one;
    double p;

    for(int i=0; i<populationSize; ++i){
        p = (double)rand()/RAND_MAX;
        if(p<crossOverProbability){
            ++first;
            if (first%2 == 0){
                Solution* child1 = new Solution(selectedPopulation[one]);
                Solution* child2 = new Solution(selectedPopulation[i]);
                crossOverVertices(selectedPopulation[one], selectedPopulation[i], child1, child2);
                crossOverPages(selectedPopulation[one], selectedPopulation[i], child1, child2);
                newPopulation.push_back(child1);
                newPopulation.push_back(child2);
            }
            else{
                one = i;
            }
        }
        else{
            newPopulation.push_back(new Solution(selectedPopulation[i]));
        }
    }
}

void GeneticAlgorithm::crossOverVertices(Solution *parent1, Solution *parent2, Solution *child1, Solution *child2){
    // partially matched crossover
    int cp1 = rand()%parent1->vertexNum;
    int cp2 = rand()%parent1->vertexNum;
    if(cp1==cp2) return;
    int start = min(cp1, cp2);
    int end = max(cp1, cp2);
    vector<unsigned int> vertices1 = parent1->getVerteOrder();
    vector<unsigned int> vertices2 = parent2->getVerteOrder();
    for(int i=start; i<end; i++){
        int vertex = vertices2[i];
        child1->vertexOrder[vertices1[i]] = child1->vertexOrder[vertex];
        child1->vertexOrder[vertex] = i;

        vertex = vertices1[i];
        child2->vertexOrder[vertices2[i]] = child2->vertexOrder[vertex];
        child2->vertexOrder[vertex] = i;
    }
}

void GeneticAlgorithm::crossOverPages(Solution *parent1, Solution *parent2, Solution *child1, Solution *child2){
    int crossoverPoint = rand()%parent1->edgesListWithPages.size();;
    for(int i=0; i<crossoverPoint; ++i){
        child2->edgesListWithPages[i][2] = parent1->edgesListWithPages[i][2];
        child1->edgesListWithPages[i][2] = child2->edgesListWithPages[i][2];
    }
}

void GeneticAlgorithm::mutate(){
    double p;
    for(int i=0; i<populationSize; ++i){
        p = (double)rand()/RAND_MAX;
        if(p<mutationProbability){
            mutateVertices(i);
            mutatePages(i);
        }
    }
}

void GeneticAlgorithm::mutateVertices(int y){
    int vertex = rand()%newPopulation[y]->vertexNum;
    int prevPosNum = newPopulation[y]->vertexOrder[vertex];
    int posNum = (prevPosNum + 1) % newPopulation[y]->vertexNum;
    int first = min(posNum, prevPosNum);
    int second = max(posNum, prevPosNum);
    int sign = (posNum-prevPosNum > 0) ? 1 : ((posNum-prevPosNum < 0) ? -1 : 0);
    for(auto it = newPopulation[y]->vertexOrder.begin(); it!=newPopulation[y]->vertexOrder.end(); it++){
        if(it->first==vertex){
            it->second = posNum;
        }
        else{
            if(it->second >=first && it->second <= second){
                it->second -= sign;
            }
        }
    }

}

void GeneticAlgorithm::mutatePages(int x){
    int edge = rand()%newPopulation[x]->edgesListWithPages.size();
    int page = rand()%newPopulation[x]->pagesNum;
    newPopulation[x]->edgesListWithPages[edge][2] = page;
}

void GeneticAlgorithm::replace(){
    clearPopulation(population);
    selectedPopulation.clear();
    population = newPopulation;
    newPopulation.clear();
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
