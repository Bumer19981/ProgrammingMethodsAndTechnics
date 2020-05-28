#include "container_atd.h"
#include <iostream>
#include <fstream>
#include "langtype_atd.h"

using namespace std;
namespace simple_langtypes {
	void out(Langtype& s, ofstream& ofst);
	int amountOfYears(Langtype& l);
	void outProcedure(Container& c, ofstream& ofst) {
		if (!ofst.is_open())
		{
			throw std::invalid_argument("Error writing file!");
		}
		ofst << "Only procedure." << endl;
		Container::List::Node* node = c.list.head;
		for (int i = 0; i < c.list.size; i++) {
			ofst << i << ": ";
			if (node->l->k == 1) {
				out(*node->l, ofst);
				ofst << "amount of years = "
					<< amountOfYears(*node->l) << endl;
				node = node->next;
			}
			else {
				ofst << endl;
				node = node->next;
			}
		}
	}}