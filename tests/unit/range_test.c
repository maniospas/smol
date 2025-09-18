#define SMOLAMBDA_SERVICES 1
#include <string.h>
#include "std/runtime/auto.h"
#define __IS_i64 1
#define __IS_f64 2
#define __IS_u64 3
#define __IS_ptr 4
#define __IS_char 5
#define __IS_errcode 6
#define __IS_cstr 7
#define __IS_bool 8
#define __IS_nominal 9
#ifdef __cplusplus
#define __NULL nullptr
#else
#include <stddef.h>
#define __NULL NULL
#endif
#define __USER__ERROR 1
#define __BUFFER__ERROR 2
#define __UNHANDLED__ERROR 3
#define __TRANSIENT(message)
#define __builtin_assume(cond) do { if (!(cond)) __builtin_unreachable(); } while (0)
#ifdef __cplusplus
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <stdbool.h>
#else
#ifndef bool
typedef int bool;
#define true 1
#define false 0
#endif
#endif
#ifndef __GNUC__
#ifndef __builtin_unreachable
#define __builtin_unreachable();
#endif
#endif
#include <stdint.h>
typedef void* ptr;
typedef int errcode;
typedef const char* cstr;
typedef uint64_t u64;
typedef long i64;
typedef uint64_t nominal;
typedef double f64;

#include<stdio.h>

struct main__182__state{errcode err;};
void main__182(void *__void__state);

void main__182(void *__void__state){
errcode __result__errocode=0;
struct main__182__state *__state=(struct main__182__state*)__void__state;
u64 __7E__value=0;
u64 __7E__self__pos=0;
u64 __3E____xD=0;
u64 __1E=0;
u64 __7E____0D=0;
u64 __4E__self__pos=0;
u64 r__pos=0;
u64 __7E____1D__z=0;
u64 __4E____1D__z=0;
u64 __4E__value=0;
u64 i=0;
u64 __4E____0D=0;

// IMPLEMENTATION
__1E = 0 ;
 __3E____xD = 0 ;
 goto __3E____zD____end ;
 __3E____zD____end :
 goto __3E____end ;
 __3E____end :
 r__pos = __3E____xD ;
 __4E__self__pos = r__pos ;
 __4E__value = i ;
 __4E__value = __4E__self__pos ;
 __4E____0D = 1 ;
 __4E____1D__z = __4E__self__pos + __4E____0D ; 
 goto __4E____1D____end ;
 __4E____1D____end :
 __4E__self__pos = __4E____1D__z ;
 __4E____2D____end :
 goto __4E____end ;
 __4E____end :
 r__pos = __4E__self__pos ;
 i = __4E__value ;
 printf ( "%lu\n" , i ); 
 __5E____end :
 printf ( "%lu\n" , __1E ); 
 __6E____end :
 __7E__self__pos = r__pos ;
 __7E__value = i ;
 __7E__value = __7E__self__pos ;
 __7E____0D = 1 ;
 __7E____1D__z = __7E__self__pos + __7E____0D ; 
 goto __7E____1D____end ;
 __7E____1D____end :
 __7E__self__pos = __7E____1D__z ;
 __7E____2D____end :
 goto __7E____end ;
 __7E____end :
 r__pos = __7E__self__pos ;
 i = __7E__value ;
 printf ( "%lu\n" , i ); 
 __8E____end :
 printf ( "%lu\n" , __1E ); 
 __9E____end :
 __end :
goto __return;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
__state->err =  __result__errocode;
}



int main() {
struct main__182__state __main_args={0};
__smolambda_initialize_service_tasks(main__182, &__main_args);
return __main_args.err;
}

