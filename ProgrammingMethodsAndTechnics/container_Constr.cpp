#include "container_atd.h"
#include "langtype_atd.h"
namespace simple_langtypes {
    void initVec(Container & c) 
    {
        c.list.head = NULL;
        c.list.tail = NULL;
        c.list.size = 0;
    }
    void clear(Container &c)
    {
        while (c.list.size != 0)                        
        {
            Container::List::Node* temp = c.list.head->next;
            delete c.list.head;                           
            c.list.head = temp;                          
            c.list.size--;                             
        }
        c.list.head = NULL;
        c.list.tail = NULL;
    }
}