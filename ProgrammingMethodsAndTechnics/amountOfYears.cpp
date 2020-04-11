#include <fstream>
#include "langtype_atd.h"
#include <string.h>
#include <ctime>
using namespace std;
namespace simple_langtypes {
	int AmountOfYears(langtype& l)
	{
		time_t now = time(0);
		struct tm ltm;
		localtime_s(&ltm, &now);
		int yearNow = 1900 + ltm.tm_year;
		if (l.k == 1) {
			return yearNow - l.p.year;
		}
		else if (l.k == 2) {
			return yearNow - l.o.year;
		}
		else {
			return -1;
		}
	}
}