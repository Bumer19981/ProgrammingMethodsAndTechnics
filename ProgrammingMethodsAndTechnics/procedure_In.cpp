#include <fstream>
#include "langtype_atd.h"
#include <string>
using namespace std;
namespace simple_langtypes {
    void in(Langtype::Procedure& p, ifstream& ifst) {
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
            throw std::invalid_argument("Error: wrong amount of params in procedure language!");
        }
        words = 0;
        for (int i = 0; i < line.length(); ++i) {

            if (line[i] == ' ' && line[i + 1] != '\0') {
                words += 1;
                i += 1;
            }
            array[words] += line[i];
            if (line[i] == ' ') {
                throw std::invalid_argument("Error: additional space char in procedure language!");
            }
        }
        if (array[0] != "0" && array[0] != "1") {
            throw std::invalid_argument("Error: isAbstract in procedure language should be correct!");
        }
        try {
            p.year = stoi(array[1]);
            if (p.year < 0) {
                throw std::invalid_argument("!");
            }
        }
        catch (exception & e) {
            throw std::invalid_argument("Error: year in procedure language should be a positive number!");
        }
        p.isAbstract = 1 ? array[0] == "1" : 0;
        p.year = stoi(array[1]);
    }
}
