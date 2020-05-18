#include <iostream>
#include <fstream>
#include "container_atd.h"
using namespace std;
namespace simple_langtypes {
	//void InitVec(container& c);
	//void Clear(container& c);
	//void InVec(container& c, ifstream& ifst);
	//void OutVec(container& c, ofstream& ofst);
	//void Sort(container& c);
	//void OutProcedure(container& c, ofstream& ofst);
}
using namespace simple_langtypes;
int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "incorrected command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	container c;
	InitVec(c);
	InVec(c, ifst);
	ofst << "Filled container. " << endl;
	OutVec(c, ofst);
	OutProcedure(c, ofst);
	Sort(c);
	ofst << "Sorted container. " << endl;
	OutVec(c, ofst);
	Clear(c);
	ofst << "Empty container. " << endl;
	OutVec(c, ofst);
	cout << "Stop" << endl;
	return 0;
}
