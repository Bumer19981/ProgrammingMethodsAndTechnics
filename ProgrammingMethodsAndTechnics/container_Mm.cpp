#include <fstream>
#include "container_atd.h"
#include "langtype_atd.h"
using namespace std;
namespace simple_langtypes {
	void MultiMethod(Container& c, ofstream& ofst) {
		ofst << "Multimethod." << endl;
		for (int i = 1; i < c.list.size; i++) {
			Container::List::Node* tempHead0 = c.list.head;
			int counter0 = 0;
			while (counter0 != i - 1) {
				tempHead0 = tempHead0->next;
				counter0 += 1;
			}
			for (int j = i + 1; j <= c.list.size; j++) {
				Container::List::Node* tempHead1 = c.list.head;
				int counter1 = 0;
				while (counter1 != j - 1) {
					tempHead1 = tempHead1->next;
					counter1 += 1;
				}
				switch (tempHead0->l->k) {
				case 1:
					switch (tempHead1->l->k) {
					case 1:
						ofst << "Procedure and Procedure." << endl;
						break;
					case 2:
						ofst << "Procedure and Objectoriented." << endl;
						break;
					case 3:
						ofst << "Procedure and Functional." << endl;
						break;
					default:
						ofst << "Unknown langtype" << endl;
					}
					break;
				case 2:
					switch (tempHead1->l->k) {
					case 1:
						ofst << "Objectoriented and Procedure." << endl;
						break;
					case 2:
						ofst << "Objectoriented and Objectoriented." << endl;
						break;
					case 3:
						ofst << "Objectoriented and Functional." << endl;
						break;
					default:
						ofst << "Unknown langtype" << endl;
					}
					break;
				case 3:
					switch (tempHead1->l->k) {
					case 1:
						ofst << "Functional and Procedure." << endl;
						break;
					case 2:
						ofst << "Functional and Objectoriented." << endl;
						break;
					case 3:
						ofst << "Functional and Functional." << endl;
						break;
					default:
						ofst << "Unknown langtype" << endl;
					}
					break;
				default:
					ofst << "Unknown langtype" << endl;
				}
				Langtype* l0 = tempHead0->l;
				Langtype* l1 = tempHead1->l;
				out(*l0, ofst);
				out(*l1, ofst);
			}
		}
	}}