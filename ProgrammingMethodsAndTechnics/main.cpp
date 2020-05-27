#include <iostream>
#include <fstream>
#include "container_atd.h"
using namespace std;
//namespace simple_langtypes {
	//void InitVec(container& c);
	//void Clear(container& c);
	//void InVec(container& c, ifstream& ifst);
	//void OutVec(container& c, ofstream& ofst);
	//void Sort(container& c);
	//void OutProcedure(container& c, ofstream& ofst);
//}
using namespace simple_langtypes;
int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "incorrected command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}
	string inputPath = argv[1];
	string outputPath = argv[2];
	try {
		ifstream file(inputPath);
		file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		ofstream outfile(outputPath);

		cout << "Start" << endl;
		container c;
		InitVec(c);
		InVec(c, file);
		outfile << "Filled container. " << endl;
		OutVec(c, outfile);
		OutProcedure(c, outfile);

		Sort(c);
		outfile << "Sorted container. " << endl;
		OutVec(c, outfile);
		Clear(c);
		outfile << "Empty container. " << endl;
		OutVec(c, outfile);
		cout << "Stop" << endl;
	}
	catch (std::invalid_argument & ia)
	{
		std::cerr << ia.what();
	}
	catch (std::ifstream::failure f)
	{
		std::cerr << "Error reading input file";
	}
	getchar();
	return 0;
}
