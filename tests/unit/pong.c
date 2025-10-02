#define SMOLAMBDA_SERVICES 1
#ifdef __cplusplus
#define __externc extern "C"
#else
#define __externc
#endif
#include <string.h>
#include "std/runtime/eager.h"
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
#define __STACK__ERROR 4
#define __TRANSIENT(message)
#define __builtin_assume(cond) do { if(!(cond)) __builtin_unreachable(); } while(0)
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

struct main__201__state{errcode err;};
__externc void main__201(void *__void__state);

void main__201(void *__void__state){
errcode __result__errocode=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1396;
struct main__201__state *__state=(struct main__201__state*)__void__state;
nominal __2F__call____BF=0;
u64 __2F____lF__z=0;
cstr __2F____gF=0;
u64 __2F____eF____AF=0;
u64 __2F__call__n=0;
u64 __2F__call__id=0;
u64 __0F____8E=0;
u64 __xF____VF__z=0;
u64 __xF____UF=0;
bool __2F____cF__z=0;
cstr __xF____SF=0;
bool __wF____LF__z=0;
u64 __2F____jF____6E=0;
bool __sF=0;
nominal __xF__call____BF=0;
u64 __xF____OF=0;
nominal call____BF=0;
u64 call__n=0;
u64 __xF____QF=0;
u64 call__id=0;
u64 __2F____kF=0;
u64 __xF____YF____8E=0;
u64 __oF____6E=0;
bool __xF____RF__z=0;
bool __2F____lF____G__z=0;
u64 __xF__i=0;
u64 __xF__call__id=0;
u64 __2F____bF=0;
bool __1F____MF__z=0;
u64 __xF__call__n=0;
u64 __pF=0;
u64 __vF____6E=0;

// IMPLEMENTATION
__oF____6E = 0 ;
 __pF = 4 ;
 call__id = __oF____6E ;
 call__n = __pF ;
 __rF__loop :
 __sF = call__n ;
 if(! __sF )goto __rF__while ;
 __vF____6E = 0 ;
 __wF____LF__z =( __vF____6E == call__id ); 
 __wF____LF____end :
 if(! __wF____LF__z )goto __tF__fi ;
 __xF__call__id = call__id ;
 __xF__call__n = call__n ;
 __xF____OF = 0 ;
 __xF__i = __xF____OF ;
 __xF____QF = 0 ;
 __xF____RF__z = __xF__call__n <= __xF____QF ; 
 __xF____RF____end :
 if(! __xF____RF__z )goto __xF____PF__fi ;
 goto __xF____end ;
 __xF____PF__fi :
 __xF____SF = "ping" ;
 printf ( "%s\n" , __xF____SF ); 
 __xF____TF____end :
 __xF____UF = 1 ;
 __xF____VF__z = __xF__i + __xF____UF ; 
 __xF____VF____end :
 __xF__i = __xF____VF__z ;
 printf ( "%lu\n" , __xF__i ); 
 __xF____WF____end :
 __xF____YF____8E = 1 ;
 __xF__call__id = __xF____YF____8E ;
 __xF____end :
 call____BF = __xF__call____BF ;
 call__id = __xF__call__id ;
 call__n = __xF__call__n ;
 goto __tF__el ;
 __tF__fi :
 __0F____8E = 1 ;
 __1F____MF__z =( __0F____8E == call__id ); 
 __1F____MF____end :
 if(! __1F____MF__z )goto __yF__fi ;
 __2F__call__id = call__id ;
 __2F__call__n = call__n ;
 __2F____bF = 0 ;
 __2F____cF__z =( __2F__call__n == __2F____bF ); 
 __2F____cF____end :
 if(! __2F____cF__z )goto __2F____aF__fi ;
 __2F____eF____AF = 2 ;
 __2F__call__id = __2F____eF____AF ;
 goto __2F____end ;
 __2F____aF__fi :
 __2F____gF = "pong" ;
 printf ( "%s\n" , __2F____gF ); 
 __2F____hF____end :
 __2F____jF____6E = 0 ;
 __2F____kF = 1 ;
 __2F____lF____G__z = __2F____kF > __2F__call__n ; 
 __2F____lF____G____end :
 if(! __2F____lF____G__z )goto __2F____lF____F__fi ;
 goto __2F____lF____H ;
 __builtin_unreachable();
 __2F____lF____F__fi :
 __2F____lF__z = __2F__call__n - __2F____kF ; 
 __2F____lF____end :
 __2F__call__id = __2F____jF____6E ;
 __2F__call__n = __2F____lF__z ;
 __2F____end :
 call____BF = __2F__call____BF ;
 call__id = __2F__call__id ;
 call__n = __2F__call__n ;
 __yF__fi :
 __tF__el :
 goto __rF__loop ;
 __rF__while :
 __end :
goto __return;

// ERROR HANDLING
__2F____lF____H :
 printf ( "Error: unsigned substraction yielded a negative\n" ); 
__result__errocode=__USER__ERROR;
goto __failsafe;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
__state->err =  __result__errocode;
}



int main() {
struct main__201__state __main_args={0};
__smolambda_initialize_service_tasks(main__201, &__main_args);
return __main_args.err;
}

