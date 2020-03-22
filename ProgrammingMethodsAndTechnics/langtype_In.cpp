#include <fstream>
#include "langtype_atd.h"
using namespace std;
namespace simple_langtypes {
    void In(langtype::procedure& p, ifstream& ist);
    void In(langtype::objectoriented& o, ifstream& ist);
    void In(langtype::functional& f, ifstream& ist);
    langtype* In(ifstream& ifst)
    {
        langtype* l;
        int k;
        ifst >> k;
        if (k == 1) {
            l = new langtype;
            l->k = 1;
            In(l->p, ifst);
            return l;
        }
        else if (k == 2) {
            l = new langtype;
            l->k = 2;
            In(l->o, ifst);
            return l;
        }
        else if (k == 3) {
            l = new langtype;
            l->k = 3;
            In(l->f, ifst);
            return l;
        }
        else{
            return 0;
        }
    }
}