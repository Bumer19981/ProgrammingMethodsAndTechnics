#include <fstream>
#include "container_atd.h"
using namespace std;
namespace simple_langtypes {
    void Out(langtype& l, ofstream& ofst);
    int AmountOfYears(langtype& l);
    void OutVec(container& c, ofstream &ofst) {
        ofst << "Container contents " << c.list.size
            << " elements." << endl;
        container::List::Node* tempHead = c.list.Head;                

        int temp = c.list.size;                           
        while (temp != 0)  {                    
            langtype* l = tempHead->l;
            Out(*l, ofst);
            ofst << "amount of years = "
                << AmountOfYears(*l) << endl;
            tempHead = tempHead->Next;       
            temp--;                              
        }
    }  
}