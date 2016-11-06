#include "solution.h"

Solution::Solution(int pagesNum, int vertexNum):pagesNum(pagesNum), vertexNum(vertexNum)
{

}

Solution::Solution(const Solution *x){
    this->crossings = x->crossings;
    this->edgesListWithPages = x->edgesListWithPages;
    this->pagesNum = x->pagesNum;
    this->vertexNum = x->vertexNum;
    this->vertexOrder = x->vertexOrder;
}

vector <unsigned int> Solution::getVerteOrder(){
    vector <unsigned int> result;
    for(int i=0; i<vertexOrder.size(); ++i){
        result.push_back(0);
    }
    for(auto it=vertexOrder.begin(); it!=vertexOrder.end(); ++it){
        result[it->first] = it->second;
    }
    return result;
}
