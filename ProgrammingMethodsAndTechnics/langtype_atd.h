#ifndef __langtype_atd__
#define __langtype_atd__

#include <fstream>//4
using namespace std;//4

namespace simple_langtypes {
    struct langtype {
        int k;
        int mentions;
        struct procedure {
            bool isAbstract;
            short int year;
        } p;
        struct objectoriented {
            short int year;
            enum inheritance { once, multiple, interface } inheritance;
        } o;
        struct functional {
            short int year;
            enum typification { strict, dynamic } typification;
            bool isLazyCalculations;
        } f;
    };
    void In(langtype::procedure& p, ifstream& ist);
    void In(langtype::objectoriented& o, ifstream& ist);
    void In(langtype::functional& f, ifstream& ist);
    langtype* In(ifstream& ifst);
    void Out(langtype::procedure& p, ofstream& ofst);
    void Out(langtype::objectoriented& o, ofstream& ofst);
    void Out(langtype::functional& o, ofstream& ofst);
    void Out(langtype& l, ofstream& ofst);
    int AmountOfYears(langtype& l);
}
#endif
#pragma /*once*/
