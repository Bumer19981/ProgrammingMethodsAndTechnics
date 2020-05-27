#include <fstream>
#include "langtype_atd.h"
#include <string>
using namespace std;
namespace simple_langtypes {
    void In(langtype::functional& f, ifstream& ifst) {
        string line;
        getline(ifst, line);
        int words = 0;
        string array[3];
        for (int i = 0; i < line.length(); ++i) {

            if (line[i] == ' ' && line[i + 1] != '\0') {
                words += 1;
            }
        }
        if (words > 2 || words < 2)
        {
            throw std::invalid_argument("Error: wrong amount of params in functional language!");
        }
        words = 0;
        for (int i = 0; i < line.length(); ++i) {

            if (line[i] == ' ' && line[i + 1] != '\0') {
                words += 1;
                i += 1;
            }
            array[words] += line[i];
            if (line[i] == ' ') {
                throw std::invalid_argument("Error: additional space char in functional language!");
            }
        }
        if (array[0] != "dinamic" && array[0] != "strict") {
            throw std::invalid_argument("Error: typification in functional language should be correct!");
        }
        if (array[1] != "1" && array[1] != "0") {
            throw std::invalid_argument("Error: isLazyCalculations in functional language should be a bool!");
        }
        try {
            f.year = stoi(array[2]);
            if (f.year < 0) {
                throw std::invalid_argument("!");
            }
        }
        catch(exception & e){
            throw std::invalid_argument("Error: year in functional language should be a positive number!");
        }
     

        string typification = array[0];
        f.isLazyCalculations = 1 ? array[1] == "1" : 0;
        f.year = stoi(array[2]);
        typification == "dinamic" ? f.typification = f.dynamic : f.typification = f.strict;
    }
}