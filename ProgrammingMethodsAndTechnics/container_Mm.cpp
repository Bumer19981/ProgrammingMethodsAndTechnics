#include <fstream>
#include "container_atd.h"
#include "langtype_atd.h"
using namespace std;
namespace simple_langtypes {
	void Out(langtype& l, ofstream& ofst);
	void MultiMethod(container& c, ofstream& ofst) {
		ofst << "Multimethod." << endl;
		int temp = c.list.size;
		container::List::Node* tempHead = c.list.Head;
		while (temp != 1) {
			langtype* l = tempHead->l;
			switch (l->k) {
			case 1:
				switch (tempHead->Next->l->k) {
				case 1:
					ofst << "Procedure and Procedure." << endl;
					break;
				case 2:
					ofst << "Procedure and Objectoriented." << endl;
					break;
				default:
					ofst << "Unknown langtype" << endl;
				}
				break;
			case 2:
				switch (tempHead->Next->l->k) {
				case 1:
					ofst << "Objectoriented and Procedure." << endl;
					break;
				case 2:
					ofst << "Objectoriented and Objectoriented." << endl;
					break;
				default:
					ofst << "Unknown langtype" << endl;
					ofst << "Unknown langtype" << endl;
				}
				break;
			default:
				ofst << "Unknown langtype" << endl;
			}
			Out(*l, ofst);
			Out(*tempHead->Next->l, ofst);
			tempHead = tempHead->Next;
			temp--;
		}
	}}