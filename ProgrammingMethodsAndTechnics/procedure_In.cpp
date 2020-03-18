#include <fstream>
#include "langtype_atd.h"
using namespace std;
namespace simple_langtypes {
    void In(langtype::procedure& p, ifstream& ifst) {
        ifst >> p.isAbstract >> p.year;
    }
}
