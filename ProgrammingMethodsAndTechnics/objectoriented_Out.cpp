//---------------------------------------------------
#include <fstream>
#include "langtype_atd.h"
using namespace std;
namespace simple_langtypes {
    void Out(langtype::objectoriented& o, ofstream& ofst)
    {
        ofst << "It is an object-oriented language: year = " << o.year << endl;
    }
}