#include <fstream>
#include "langtype_atd.h"
#include <string.h>
using namespace std;
namespace simple_langtypes {
    void Out(langtype::objectoriented& o, ofstream& ofst)
    {
        string inheritance;
        if (o.inheritance == o.once) {
            inheritance = "once";
        }
        else if (o.inheritance == o.multiple) {
            inheritance = "multiple";
        }
        else {
            inheritance = "interface";
        }
        ofst << "It is an object-oriented language: inheritance = " << inheritance << ", year = " << o.year << endl;
    }
}