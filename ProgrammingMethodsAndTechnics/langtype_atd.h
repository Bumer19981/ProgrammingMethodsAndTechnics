#ifndef __langtype_atd__
#define __langtype_atd__
namespace simple_langtypes {
    struct langtype {
        int k;
        int mentions;
        struct procedure {
            bool isAbstract;
            short int year;
        } p;
        struct objectoriented {
            short int year;
            enum inheritance { once, multiple, interface } inheritance;
        } o;
        struct functional {
            short int year;
            enum typification { strict, dynamic } typification;
            bool isLazyCalculations;
        } f;
    };
}
#endif
#pragma /*once*/
