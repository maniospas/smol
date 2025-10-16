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
#define __DYokMIC__ERROR 5
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

#include<string.h>

struct main__196__state{errcode err;};
__externc void main__196(void *__void__state);

void main__196(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1108;
struct main__196__state *__state=(struct main__196__state*)__void__state;
ptr __VF____5E__ref__dynamic=0;
ptr __VF____4E____m__contents=0;
ptr __VF____4E__noptr=0;
u64 __VF____3E__dynamic____buffer_size=0;
cstr __UF=0;
ptr __VF____3E__dynamic____buffer_contents=0;
u64 __VF____4E__length=0;
ptr __VF____3E__surface=0;
ptr __VF____4E__contents=0;
u64 __VF____3E__dynamic____buffer_alignment=0;
u64 __VF____3E__dynamic____buffer_capacity=0;
ptr __VF____3E__dynamic=0;
char __VF____4E__first=0;

// IMPLEMENTATION
__UF = "first" ;
 __VF____3E__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 __VF____3E__surface = 0 ;
 __VF____4E__length = strlen ( __UF ); __VF____4E__contents =( ptr ) __UF ; __VF____4E__first = __UF [0]; __VF____4E__noptr =( ptr ) __VF____4E__noptr ; 
 __VF____4E____m__contents = __VF____4E__contents ;
 if(! __VF____3E__dynamic )goto __result__buffer_error ;
 __VF____3E__dynamic____buffer_alignment = 4 ;
 __VF____3E__dynamic____buffer_size = ((u64*) __VF____3E__dynamic )[1] ;
 __VF____3E__dynamic____buffer_capacity = ((u64*) __VF____3E__dynamic )[2] & ~(1ULL << 63) ;
 if( __VF____3E__dynamic____buffer_size >= __VF____3E__dynamic____buffer_capacity ){ if( ((u64*) __VF____3E__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __VF____3E__dynamic____buffer_capacity = __VF____3E__dynamic____buffer_capacity +( __VF____3E__dynamic____buffer_capacity >>2)+1; if( __VF____3E__dynamic____buffer_size ) ((void**) __VF____3E__dynamic )[0] = __runtime_realloc((u64*)((void**) __VF____3E__dynamic )[0],  __VF____3E__dynamic____buffer_capacity * __VF____3E__dynamic____buffer_alignment *sizeof(u64),  __VF____3E__dynamic____buffer_capacity * __VF____3E__dynamic____buffer_alignment *sizeof(u64)); else ((void**) __VF____3E__dynamic )[0] = __runtime_alloc( __VF____3E__dynamic____buffer_capacity * __VF____3E__dynamic____buffer_alignment *sizeof(u64)); ((u64*) __VF____3E__dynamic )[2] = __VF____3E__dynamic____buffer_capacity ;
 __VF____3E__dynamic____buffer_contents = (ptr)((void**) __VF____3E__dynamic )[0] ;
 if( ! __VF____3E__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  __VF____3E__dynamic____buffer_contents = (ptr)(((u64*) __VF____3E__dynamic )[0]) ;
 ((u64*) __VF____3E__dynamic )[1] = __VF____3E__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __VF____3E__dynamic____buffer_contents )[ __VF____3E__dynamic____buffer_size * __VF____3E__dynamic____buffer_alignment +0], & __VF____4E____m__contents , sizeof(ptr)); memcpy(&((u64*) __VF____3E__dynamic____buffer_contents )[ __VF____3E__dynamic____buffer_size * __VF____3E__dynamic____buffer_alignment +1], & __VF____4E__length , sizeof(u64)); memcpy(&((u64*) __VF____3E__dynamic____buffer_contents )[ __VF____3E__dynamic____buffer_size * __VF____3E__dynamic____buffer_alignment +2], & __VF____4E__first , sizeof(char)); memcpy(&((u64*) __VF____3E__dynamic____buffer_contents )[ __VF____3E__dynamic____buffer_size * __VF____3E__dynamic____buffer_alignment +3], & __VF____4E__noptr , sizeof(ptr)); __VF____5E__ref__dynamic = __VF____3E__dynamic ;
 __VF__ref__dynamic = __VF____5E__ref__dynamic ;
 __end :
goto __return;

// ERROR HANDLING
__result__buffer_error :
printf("Buffer error\n");
__result__error_code=__BUFFER__ERROR;
goto __failsafe;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
if( __VF__ref__dynamic ){if((u64*)((u64*) __VF__ref__dynamic )[2]) __runtime_free((u64*)((u64*) __VF__ref__dynamic )[0]) ;
 __runtime_free( __VF__ref__dynamic ) ;
 __VF__ref__dynamic = 0 ;
 }__state->err =  __result__error_code;
}



int main() {
struct main__196__state __main_args={0};
__smolambda_initialize_service_tasks(main__196, &__main_args);
return __main_args.err;
}

