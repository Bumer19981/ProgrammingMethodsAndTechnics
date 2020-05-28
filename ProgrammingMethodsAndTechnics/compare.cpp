#include "langtype_atd.h"
using namespace std;
namespace simple_langtypes {
    //int AmountOfYears(langtype& l);
    bool compare(Langtype* first, Langtype* second) {
        return amountOfYears(*first) < amountOfYears(*second);
    }}