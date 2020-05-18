#ifndef __container_atd__
#define __container_atd__

#include <fstream>//4
using namespace std;//4

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
    void InitVec(container& c);
    void Clear(container& c);
    void InVec(container& c, ifstream& ifst);
    void OutVec(container& c, ofstream& ofst);
    void Sort(container& c);
    bool Compare(langtype* first, langtype* second);
    void OutProcedure(container& c, ofstream& ofst);
}
#endif
#pragma once
