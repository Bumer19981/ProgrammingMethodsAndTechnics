//---------------------------------------------------
#include <fstream>
#include "langtype_atd.h"
using namespace std;
namespace simple_langtypes {
    void In(langtype::objectoriented& o, ifstream& ifst)
    {
        ifst >> o.year;
    }
}