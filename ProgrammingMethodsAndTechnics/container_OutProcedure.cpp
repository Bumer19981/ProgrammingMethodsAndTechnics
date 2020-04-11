#include "container_atd.h"
#include <iostream>
#include <fstream>
#include "langtype_atd.h"

using namespace std;
namespace simple_langtypes {
	void Out(langtype& s, ofstream& ofst);
	void OutProcedure(container& c, ofstream& ofst) {
		ofst << "Only procedure." << endl;
		container::List::Node* node = c.list.Head;
		for (int i = 0; i < c.list.size; i++) {
			ofst << i << ": ";
			if (node->l->k == 1) {
				Out(*node->l, ofst);
				node = node->Next;
			}
			else {
				ofst << endl;
				node = node->Next;
			}
		}
	}}