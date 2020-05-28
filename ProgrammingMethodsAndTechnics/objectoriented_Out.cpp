#include <fstream>
#include "langtype_atd.h"
#include <string.h>
using namespace std;
namespace simple_langtypes {
	void out(Langtype::Objectoriented& o, ofstream& ofst)
	{
		string inheritance;
		if (o.inheritance == o.ONCE) {
			inheritance = "once";
		}
		else if (o.inheritance == o.MULTIPLE) {
			inheritance = "multiple";
		}
		else {
			inheritance = "interface";
		}
		ofst << "It is an object-oriented language: inheritance = " << inheritance << ", year = " << o.year << endl;
	}
}