#include <fstream>
#include "langtype_atd.h"
#include <string>
using namespace std;
namespace simple_langtypes {
	void In(langtype::objectoriented& o, ifstream& ifst)
	{
        string line;
        getline(ifst, line);
        int words = 0;
        string array[2];
        for (int i = 0; i < line.length(); ++i) {

            if (line[i] == ' ' && line[i + 1] != '\0') {
                words += 1;
            }
        }
        if (words > 1 || words < 1)
        {
            throw std::invalid_argument("Error: wrong amount of params in objectoriented language!");
        }
        words = 0;
        for (int i = 0; i < line.length(); ++i) {

            if (line[i] == ' ' && line[i + 1] != '\0') {
                words += 1;
                i += 1;
            }
            array[words] += line[i];
            if (line[i] == ' ') {
                throw std::invalid_argument("Error: additional space char in objectoriented language!");
            }
        }
        if (array[0] != "once" && array[0] != "multiple" && array[0] != "interface") {
            throw std::invalid_argument("Error: inheritance in objectoriented language should be correct!");
        }
        try {
            o.year = stoi(array[1]);
            if (o.year < 0) {
                throw std::invalid_argument("!");
            }
        }
        catch (exception & e) {
            throw std::invalid_argument("Error: year in objectoriented language should be a positive number!");
        }
		string inheritance = array[0];
		o.year = stoi(array[1]);
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