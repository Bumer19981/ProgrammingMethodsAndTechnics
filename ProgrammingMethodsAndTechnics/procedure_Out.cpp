#include <fstream>
#include "langtype_atd.h"
using namespace std;
namespace simple_langtypes {
    void out(Langtype::Procedure& p, ofstream& ofst) {
        ofst << "It is a procedure language: is abstract = " << p.isAbstract
            << ", year = " << p.year << endl;
    }
}