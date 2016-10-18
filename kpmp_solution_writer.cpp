#include <iostream>
#include <fstream>
#include "kpmp_solution_writer.h"

void KPMPSolutionWriter::write(string path) const {
	ofstream outfile(path, ios::out);	
	write(outfile);
	outfile.close();
}

void KPMPSolutionWriter::write(ostream &out) const {
    out << "# Number of crossings: "<<crossingsNumber<<endl;
    out << "# Elapsed time: "<<elapsedTime<<" [s]"<<endl;
	out << spineOrder.size() << endl;
	out << K << endl;	
	
	for(unsigned int  i : spineOrder)
		out << i << endl;
	
	for(PageEntry *e : edgePartition)
		out << e->a << " " << e->b << " [" << e->page << "]" << endl;
}

void KPMPSolutionWriter::print() const {	
	write(cout);
}
