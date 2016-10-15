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
                instance->edgesList.back().push_back(-1);
                instance->edgesList.back().push_back(abs(b-a));
			}
		}

		instFile.close();

		for (unsigned int i=0; i < instance->numVertices; i++) {
			std::sort(instance->adjacencyList[i].begin(), instance->adjacencyList[i].end());
			auto last = std::unique(instance->adjacencyList[i].begin(), instance->adjacencyList[i].end());
			instance->adjacencyList[i].erase(last, instance->adjacencyList[i].end());
		}

        sort(instance->edgesList.begin(), instance->edgesList.end(), KPMPInstance::compare_function);
	}
	else {
		cerr << "Unable to open file";
		return NULL;
	}

	return instance;
}

int main() {
    KPMPInstance* instance = KPMPInstance::readInstance("/home/kory/books-data/automatic-1.txt");
    ConstructionHeuristic dch;
    vector< vector<int> > result = dch.calculatePages(instance->getEdgesList(), instance->getK());
    KPMPSolutionWriter writer(instance->getK());
    for(int i=0; i<result.size(); i++){
        writer.addEdgeOnPage(result[i][0], result[i][1], result[i][2]);
    }
    writer.write("/home/kory/books-data/result.txt");
    return 0;
}
