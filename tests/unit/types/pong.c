#define SMOLAMBDA_SERVICES 1
#ifdef __cplusplus
#define __externc extern "C"
#else
#define __externc
#endif
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
#define __IS_symbol 10
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
#define __DYNAMIC__ERROR 5
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
typedef uint64_t tag;
typedef uint64_t u64;
typedef long i64;
typedef uint64_t nominal;
typedef double f64;

#include<stdio.h>

struct main__187__state{errcode err;};
__externc void main__187(void *__void__state);

void main__187(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1316;
struct main__187__state *__state=(struct main__187__state*)__void__state;
u64 __XF____JF__z=0;
bool __XF____JF____G__z=0;
cstr __XF____FF=0;
tag __XF__func=0;
u64 __MF=0;
u64 __XF__n=0;
u64 __XF____IF=0;
tag __LF=0;
u64 __VF__n=0;
tag __PF=0;
tag __XF____HF=0;
tag __VF__func=0;
bool __QF__z=0;
tag pending__func=0;
u64 pending__n=0;
tag __UF____5E=0;
cstr __SF=0;
cstr __UF____3E=0;
u64 __XF____8E=0;
bool __XF____9E__z=0;
tag __XF____AF=0;
u64 __XF____BF=0;

// IMPLEMENTATION
__LF = 3 ;
 __MF = 2 ;
 pending__func = __LF ;
 pending__n = __MF ;
 __OF__loop :
 __PF = 2 ;
 __QF__z =( pending__func != __PF ); 
 __QF____end :
 if(! __QF__z )goto __OF__while ;
 __SF = "next - " ;
 if( pending__func != 3 )goto __TF ;
 printf ( "%s" , __SF ); 
 __UF____2E____end :
 __UF____3E = "ping" ;
 printf ( "%s\n" , __UF____3E ); 
 __UF____4E____end :
 __UF____5E = 1 ;
 __VF__func = __UF____5E ;
 __VF__n = pending__n ;
 goto __RF ;
 __TF :
 if( pending__func != 1 )goto __WF ;
 __XF__n = pending__n ;
 __XF____8E = 0 ;
 __XF____9E__z =( __XF__n == __XF____8E ); 
 __XF____9E____end :
 if(! __XF____9E__z )goto __XF____7E__fi ;
 __XF____AF = 2 ;
 __XF____BF = 0 ;
 __XF__func = __XF____AF ;
 __XF__n = __XF____BF ;
 goto __XF____end ;
 __XF____7E__fi :
 printf ( "%s" , __SF ); 
 __XF____EF____end :
 __XF____FF = "pong" ;
 printf ( "%s\n" , __XF____FF ); 
 __XF____GF____end :
 __XF____HF = 3 ;
 __XF____IF = 1 ;
 __XF____JF____G__z = __XF____IF > __XF__n ; 
 __XF____JF____G____end :
 if(! __XF____JF____G__z )goto __XF____JF____F__fi ;
 goto __XF____JF____H ;
 __builtin_unreachable();
 __XF____JF____F__fi :
 __XF____JF__z = __XF__n - __XF____IF ; 
 __XF____JF____end :
 __XF__func = __XF____HF ;
 __XF__n = __XF____JF__z ;
 __XF____end :
 __VF__func = __XF__func ;
 __VF__n = __XF__n ;
 goto __RF ;
 __WF :
 printf("An unforeseen dynamic option was encountered\n");
__result__error_code=__DYNAMIC__ERROR;
goto __failsafe;
 __RF :
 pending__func = __VF__func ;
 pending__n = __VF__n ;
 goto __OF__loop ;
 __OF__while :
 __end :
goto __return;

// ERROR HANDLING
__XF____JF____H :
 printf ( "Error: unsigned substraction yielded a negative\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
__state->err =  __result__error_code;
}



int main() {
struct main__187__state __main_args={0};
__smolambda_initialize_service_tasks(main__187, &__main_args);
return __main_args.err;
}

