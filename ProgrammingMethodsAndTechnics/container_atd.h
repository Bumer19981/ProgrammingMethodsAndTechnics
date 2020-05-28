#ifndef __container_atd__
#define __container_atd__
#include <fstream>//4
using namespace std;//4
namespace simple_langtypes {
    struct Langtype;
    struct Container
    {
        struct List
        {
            struct  Node
            {
                Langtype* l;
                Node* next;
                Node* prev;
            };
            Node* head;
            Node* tail;
            int size;                                               
        };
        List list;
    }; 
    void initVec(Container& c);
    void clear(Container& c);
    void inVec(Container& c, ifstream& ifst);
    void outVec(Container& c, ofstream& ofst);
    void sort(Container& c);
    bool compare(Langtype* first, Langtype* second);
    void outProcedure(Container& c, ofstream& ofst);
}
#endif
#pragma once
