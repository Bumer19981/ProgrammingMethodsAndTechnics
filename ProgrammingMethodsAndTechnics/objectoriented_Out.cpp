#include <fstream>
#include "langtype_atd.h"
#include <string.h>
using namespace std;
namespace simple_langtypes {
    void Out(langtype::objectoriented& o, ofstream& ofst)
    {
        string inheritance;
        if (o.inheritance == 0) {
            inheritance = "once";
        }
        else if (o.inheritance == 1) {
            inheritance = "multiple";
        }
        else {
            inheritance = "inherit";
        }
        ofst << "It is an object-oriented language: inheritance = " << inheritance << ", year = " << o.year << endl;
    }
}