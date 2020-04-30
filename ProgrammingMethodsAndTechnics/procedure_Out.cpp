#include <fstream>
#include "langtype_atd.h"
using namespace std;
namespace simple_langtypes {
    void Out(langtype::procedure& p, ofstream& ofst) {
        ofst << "It is a procedure language: is abstract = " << p.isAbstract
            << ", year = " << p.year << endl;
    }
}