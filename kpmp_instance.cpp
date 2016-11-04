#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>
#include "kpmp_instance.h"
#include "kpmp_solution_writer.h"

KPMPInstance* KPMPInstance::readInstance(string filename) {
	// read in instance
	KPMPInstance* instance = new KPMPInstance();
	ifstream instFile (filename);
	string tmp;
	if (instFile.is_open()) {
		while(instFile.peek() == '#')
			instFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// skip comments
		instFile >> instance->numVertices;
		instFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// skip remainder of line

		while(instFile.peek() == '#')
			getline(instFile, tmp);	// skip comments
		instFile >> instance->K;
		instFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// skip remainder of line

		while(instFile.peek() == '#')
			instFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// skip comments
		instance->adjacencyMatrix = new bool*[instance->numVertices];
		for (unsigned int i=0; i < instance->numVertices; i++) {
			instFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// skip vertices
			instance->adjacencyList.push_back(vector<unsigned int>());

			instance->adjacencyMatrix[i] = new bool[instance->numVertices];
			for (unsigned int j=0; j < instance->numVertices; j++)
				instance->adjacencyMatrix[i][j] = false;
		}

		while(true) {
			if(instFile.peek() == '#')
				instFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// skip comments
			else {
				unsigned int a, b;
				instFile >> a >> b;
				if(instFile.eof())
					break;
				instFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// skip remainder of line (page number)
				instance->adjacencyList[a].push_back(b);
				instance->adjacencyList[b].push_back(a);
				instance->adjacencyMatrix[a][b] = true;
				instance->adjacencyMatrix[b][a] = true;

                instance->edgesList.push_back(vector<int>());
                instance->edgesList.back().push_back(a);
                instance->edgesList.back().push_back(b);
                //instance->edgesList.back().push_back(-1);
                //instance->edgesList.back().push_back(abs(b-a));
			}
		}

		instFile.close();

		for (unsigned int i=0; i < instance->numVertices; i++) {
			std::sort(instance->adjacencyList[i].begin(), instance->adjacencyList[i].end());
			auto last = std::unique(instance->adjacencyList[i].begin(), instance->adjacencyList[i].end());
			instance->adjacencyList[i].erase(last, instance->adjacencyList[i].end());
		}

        //sort(instance->edgesList.begin(), instance->edgesList.end(), KPMPInstance::compare_function);
	}
	else {
		cerr << "Unable to open file";
		return NULL;
	}

	return instance;
}

vector <unsigned int> KPMPInstance::getVerteOrder(){
    vector <unsigned int> result;
    for(int i=0; i<vertexOrder.size(); ++i){
        result.push_back(0);
    }
    for(auto it=vertexOrder.begin(); it!=vertexOrder.end(); ++it){
        result[it->second] = it->first;
    }
    return result;
}

Solution* KPMPInstance::generateRandomSolution(){
    Solution* result = new Solution(this->getK(), this->getNumVertices());
    std::srand(std::time(0));
    for(auto it=this->edgesList.begin(); it!=edgesList.end(); it++){
        result->edgesListWithPages.push_back(vector<int>());
        result->edgesListWithPages.back().push_back(it->at(0));
        result->edgesListWithPages.back().push_back(it->at(1));
        result->edgesListWithPages.back().push_back(rand()%getK());
    }

    vector<int> v;
    for (int i=1; i<getNumVertices(); ++i) v.push_back(i); // 1 2 3 4 5 6 7 8 9

    // using built-in random generator:
    std::random_shuffle ( v.begin(), v.end() );

    for(int i=0; i<v.size(); ++i){
        result->vertexOrder[v[i]] = i;
    }

    return result;
}

int main() {
    string instanceNum = "10";
    KPMPInstance* instance = KPMPInstance::readInstance("/home/magda/instances/automatic-" + instanceNum + ".txt"); //Magda
    //KPMPInstance* instance = KPMPInstance::readInstance("F:\\TUWIEN\\courses\\heuristic\\instances\\automatic-" + instanceNum + ".txt"); //Kornel
	ConstructionHeuristic dch;

	//generating initial guess
    clock_t begin = clock();
    Solution* solution = dch.calculatePages(instance->edgesList, instance->adjacencyList, instance->getK(), instance->getNumVertices(), 50);
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	//local search Neighbourhood 1
    //Neighbourhood_vertex * nv = new Neighbourhood_vertex();
    NeighbourhoodPageChange* npc = new NeighbourhoodPageChange();
    NeighbourhoodVertexReplacement* nvr = new NeighbourhoodVertexReplacement();

    RandomStepFun* rnd = new RandomStepFun();
    BestImprovement* bst = new BestImprovement();
    FirstImprovement* frs = new FirstImprovement();

    LocalSearch ls(solution);
    solution = ls.calculatePages(npc, rnd);

	//writing solution
    KPMPSolutionWriter writer(instance->getK());
    for(int i=0; i<solution->edgesListWithPages.size(); i++){
        writer.addEdgeOnPage(solution->edgesListWithPages[i][0], solution->edgesListWithPages[i][1], solution->edgesListWithPages[i][2]);
    }
    writer.setSpineOrder(solution->getVerteOrder());
    writer.setCrossingsNum(solution->crossings);
    writer.setElapsedTime(ls.elapsed_time);
    writer.setIterartions(ls.iteration);
    writer.write("/home/magda/instances/result" + instanceNum + ".txt"); //Magda
    //writer.write("F:\\TUWIEN\\courses\\heuristic\\instances\\result" + instanceNum + ".txt"); //Kornel
	//getchar();
    return 0;
}
