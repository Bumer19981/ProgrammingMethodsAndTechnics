#include <fstream>
#include "container_atd.h"
using namespace std;
namespace simple_langtypes {
    Langtype* in(ifstream& ifdt);

    void inVec(Container& c, ifstream& ifst) {
        if (!ifst.is_open())
        {
            throw std::invalid_argument("Error reading file!");
        }
        while (!ifst.eof()) {
            Langtype* l;
            if ((l = in(ifst)) != 0)
            {
                c.list.size++;
                Container::List::Node* temp = new Container::List::Node;
                temp->next = c.list.head;
                temp->prev = c.list.tail;
                temp->l = l;
                if (c.list.head != NULL)
                {
                    c.list.tail->next = temp;
                    c.list.tail = temp;
                    c.list.head->prev = c.list.tail;
                }
                else c.list.head = c.list.tail = temp;
            }
        }
    }
}