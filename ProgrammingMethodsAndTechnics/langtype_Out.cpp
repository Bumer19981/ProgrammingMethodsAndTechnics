#include <fstream>
#include "langtype_atd.h"
using namespace std;
namespace simple_langtypes {
    /*void Out(langtype::procedure& p, ofstream& ofst);
    void Out(langtype::objectoriented& o, ofstream& ofst);
    void Out(langtype::functional& o, ofstream& ofst);*/
    void Out(langtype& l, ofstream& ofst) {
        switch (l.k) {
        case 1:
            Out(l.p, ofst);
            break;
        case 2:
            Out(l.o, ofst);
            break;
        case 3:
            Out(l.f, ofst);
            break;
        default:
            ofst << "Incorrect language!" << endl;
        }
        ofst << "mentions = " << l.mentions << endl;
    }
}