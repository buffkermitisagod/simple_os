#include "code16gcc.h"
__asm__ ("jmpl  $0, $main\n");


#define __NOINLINE  __attribute__((noinline))
#define __REGPARM   __attribute__ ((regparm(3)))
#define __NORETURN  __attribute__((noreturn))

void    __NOINLINE __REGPARM print(const char   *s){
        while(*s){
                __asm__ __volatile__ ("int  $0x10" : : "a"(0x0E00 | *s), "b"(7));
                s++;
        }
}

void __NORETURN main(){
    print("woo hoo!\r\n:)");
    while(1);
}
