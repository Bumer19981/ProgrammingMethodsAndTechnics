#include <fstream>
#include "langtype_atd.h"
#include <string.h>
using namespace std;
namespace simple_langtypes {
    void Out(langtype::functional& f, ofstream& ofst) {
        string typification = f.typification == 0 ? "strict" : "dinamic";
        ofst << "It is a functional language: typification = " << typification
            << ", lazy calculations = " << f.isLazyCalculations << endl;
    }
}