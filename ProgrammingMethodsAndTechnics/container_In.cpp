#include <fstream>
#include "container_atd.h"
using namespace std;
namespace simple_langtypes {
    langtype* In(ifstream& ifdt);

    void InVec(container& c, ifstream& ifst) {
        while (!ifst.eof()) {
            langtype* l;
            if ((l = In(ifst)) != 0)
            {
                c.list.size++;
                container::List::Node* temp = new container::List::Node;
                temp->Next = c.list.Head;
                temp->Prev = c.list.Tail;
                temp->l = l;
                if (c.list.Head != NULL)
                {
                    c.list.Tail->Next = temp;
                    c.list.Tail = temp;
                    c.list.Head->Prev = c.list.Tail;
                }
                else c.list.Head = c.list.Tail = temp;
            }
        }
    }
}