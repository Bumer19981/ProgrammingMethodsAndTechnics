#ifndef __container_atd__
#define __container_atd__
#include <iostream>
namespace simple_langtypes {
    struct langtype;
    struct container
    {
        struct List
        {
            struct  Node
            {
                langtype* l;
                Node* Next;
                Node* Prev;
            };
            Node* Head;
            Node* Tail;
            int size;                                               
        };
        List list;
    }; 
}
#endif
#pragma once
