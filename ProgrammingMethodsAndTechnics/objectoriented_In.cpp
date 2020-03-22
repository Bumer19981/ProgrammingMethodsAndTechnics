#include <fstream>
#include "langtype_atd.h"
#include <string.h>
using namespace std;
namespace simple_langtypes {
	void In(langtype::objectoriented& o, ifstream& ifst)
	{
		string inheritance;
		ifst >> inheritance >> o.year;
		if (inheritance == "once") {
			o.inheritance = o.once;
		}
		else if (inheritance == "multiple")
		{
			o.inheritance = o.multiple;
		}
		else
		{
			o.inheritance = o.interface;
		}
	}
}