#include "langtype_atd.h"
using namespace std;
namespace simple_langtypes {
    int AmountOfYears(langtype& l);
    bool Compare(langtype* first, langtype* second) {
        return AmountOfYears(*first) < AmountOfYears(*second);
    }}