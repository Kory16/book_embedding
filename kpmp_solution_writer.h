
#ifndef KPMP_SOLUTION_WRITER_H_
#define KPMP_SOLUTION_WRITER_H_

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct PageEntry {
	unsigned int a, b;
	unsigned int page;

	PageEntry(unsigned int a, unsigned int b, unsigned int page) {
		this->a = a;
		this->b = b;
		this->page = page;
	}
};

class KPMPSolutionWriter {
private: 
	unsigned int K = 0;
	vector<unsigned int> spineOrder;
	vector<PageEntry*> edgePartition;
    int crossingsNumber = 0;
    double elapsedTime = 0;
	
public:
	KPMPSolutionWriter(unsigned int K) {
		this->K = K;
	}
	
	~KPMPSolutionWriter() {
		for(PageEntry *e : edgePartition)
			delete e;	
	}
	
	void setSpineOrder(vector<unsigned int> spineOrder) {
		this->spineOrder = spineOrder;
	}

    void setCrossingsNum(int val){
        this->crossingsNumber = val;
    }

    void setElapsedTime(double val){
        this->elapsedTime = val;
    }
	
	void addEdgeOnPage(unsigned int vertexA, unsigned int vertexB, unsigned int page) {
		edgePartition.push_back(new PageEntry(std::min(vertexA, vertexB), std::max(vertexA, vertexB), page));
	}
	
	void write(string path) const;
	
	void write(ostream &out) const;
	
	void print() const;
};

#endif /* KPMP_SOLUTION_WRITER_H_ */
