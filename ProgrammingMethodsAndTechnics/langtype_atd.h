#ifndef __langtype_atd__
#define __langtype_atd__
namespace simple_langtypes {
    struct langtype {      
        int k;
        struct procedure {
            bool isAbstract;
            short int year;
        } p;
        struct objectoriented {
            short int year;
        } o;
    };
}
#endif
#pragma /*once*/
