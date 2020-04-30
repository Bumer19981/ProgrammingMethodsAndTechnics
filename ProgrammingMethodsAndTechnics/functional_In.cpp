#include <fstream>
#include "langtype_atd.h"
#include <string.h>
using namespace std;
namespace simple_langtypes {
    void In(langtype::functional& f, ifstream& ifst) {
        string typification;
        ifst >> typification >> f.isLazyCalculations >> f.year;
        typification == "dinamic" ? f.typification = f.dynamic : f.typification = f.strict;
    }
}