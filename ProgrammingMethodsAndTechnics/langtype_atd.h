#ifndef __langtype_atd__
#define __langtype_atd__
#include <fstream>//4
using namespace std;//4
namespace simple_langtypes {
    struct Langtype {
        int k;
        int mentions;
        struct Procedure {
            bool isAbstract;
            short int year;
        } p;
        struct Objectoriented {
            short int year;
            enum Inheritance { 
                ONCE,
                MULTIPLE,
                INTERFACE
            };
            Inheritance inheritance;
        } o;
        struct Functional {
            short int year;
            enum Typification { 
                STRICT,
                DYNAMIC
            };
            Typification typification;
            bool isLazyCalculations;
        } f;
    };
    void in(Langtype::Procedure& p, ifstream& ist);
    void in(Langtype::Objectoriented& o, ifstream& ist);
    void in(Langtype::Functional& f, ifstream& ist);
    Langtype* in(ifstream& ifst);
    void out(Langtype::Procedure& p, ofstream& ofst);
    void out(Langtype::Objectoriented& o, ofstream& ofst);
    void out(Langtype::Functional& o, ofstream& ofst);
    void out(Langtype& l, ofstream& ofst);
    int amountOfYears(Langtype& l);
}
#endif
#pragma
