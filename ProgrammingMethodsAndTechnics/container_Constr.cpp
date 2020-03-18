#include "container_atd.h"
#include "langtype_atd.h"
namespace simple_langtypes {
    void InitVec(container & c) 
    {
        c.list.Head = NULL;
        c.list.Tail = NULL;
        c.list.size = 0;
    }
    void Clear(container &c)
    {
        while (c.list.size != 0)                        
        {
            container::List::Node* temp = c.list.Head->Next;
            delete c.list.Head;                           
            c.list.Head = temp;                          
            c.list.size--;                             
        }
    }
}