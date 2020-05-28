#include <fstream>
#include "langtype_atd.h"
#include <string.h>
using namespace std;
namespace simple_langtypes {
    void out(Langtype::Functional& f, ofstream& ofst) {
        string typification = f.typification == f.STRICT ? "strict" : "dinamic";
        ofst << "It is a functional language: typification = " << typification
            << ", lazy calculations = " << f.isLazyCalculations << ", year = " << f.year << endl;;
    }
}