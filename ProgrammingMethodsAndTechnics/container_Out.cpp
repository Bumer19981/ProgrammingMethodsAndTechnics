#include <fstream>
#include "container_atd.h"
using namespace std;
namespace simple_langtypes {
    void out(Langtype& l, ofstream& ofst);
    int amountOfYears(Langtype& l);
    void outVec(Container& c, ofstream &ofst) {
        if (!ofst.is_open())
        {
            throw std::invalid_argument("Error writing file!");
        }
        ofst << "Container contents " << c.list.size
            << " elements." << endl;
        Container::List::Node* tempHead = c.list.head;
        int temp = c.list.size;                           
        while (temp != 0)  {                    
            Langtype* l = tempHead->l;
            out(*l, ofst);
            ofst << "amount of years = "
                << amountOfYears(*l) << endl;
            tempHead = tempHead->next;       
            temp--;                              
        }
    }  
}