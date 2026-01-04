#define SMOLAMBDA_SERVICES 2
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
#define __IS_new 9
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
typedef char bool;
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
typedef uint64_t __new;
typedef double f64;

#include<stdio.h>

struct samples__207__state{errcode err;ptr *dynamic____ret;ptr *surface____ret;};
__externc void samples__207(void *__void__state);
struct main__208__state{errcode err;};
__externc void main__208(void *__void__state);

void main__208(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1088;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__208__state *__state=(struct main__208__state*)__void__state;
struct samples__207__state* __0ea____state = 0 ;
ptr __0ea__dynamic=0;
u64 buf__dynamic____buffer_size=0;
ptr __0za=0;
u64 __06a=0;
errcode __05a=0;
u64 __0xa=0;
u64 buf__dynamic____buffer_alignment=0;
ptr __04a=0;

// IMPLEMENTATION
__0ea__dynamic = 0 ;
 __04a = 0 ;
 {char mark;if(__service_stack_floor+ 1100 >=(char*)&mark) goto __service_stack_floor_handler;} __0ea____state = (struct samples__207__state*)__runtime_calloc(sizeof(struct samples__207__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0ea____state ) ;
 __0ea____state -> dynamic____ret = & __0ea__dynamic ;
 __0ea____state -> surface____ret = & __04a ;
 __0za = __smolambda_add_task ( samples__207 , __0ea____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0za ) ;
 if( __05a ) goto  __result_unhandled_error ;
 __06a = 0 ;
 if(! __0ea__dynamic )goto __result__buffer_error ;
 buf__dynamic____buffer_alignment = 8 ;
 buf__dynamic____buffer_size = ((u64*) __0ea__dynamic )[1] ;
 if( __06a >= buf__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(& __0xa , &((char*)((void**) __0ea__dynamic )[0])[ __06a * buf__dynamic____buffer_alignment ], sizeof( u64 )) ;
 printf ( "%llu\n" ,( unsigned long long ) __0xa ); 
 __0wa :
 __0va :
goto __return;

// ERROR HANDLING
__result__buffer_error :
printf("Buffer error\n");
__result__error_code=__BUFFER__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__error_code =__UNHANDLED__ERROR;
goto __failsafe ;
__service_stack_floor_handler:
printf("Insufficient stack for safe service call (too much recursion or stack allocation)\n");
__result__error_code=__STACK__ERROR;
goto __failsafe;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:
__runtime_apply_linked(__smolambda_all_tasks, __smolambda_task_wait, 0);
__runtime_apply_linked(__smolambda_all_tasks, __smolambda_task_destroy, 1);
__smolambda_all_tasks = 0;

// HOTPATH SKIPS TO HERE
__return:
__runtime_apply_linked(__smolambda_all_tasks, __smolambda_task_wait, 0);
__runtime_apply_linked(__smolambda_all_tasks, __smolambda_task_destroy, 1);
if( __0ea__dynamic ){if((u64*)((u64*) __0ea__dynamic )[2]) __runtime_free((u64*)((u64*) __0ea__dynamic )[0]) ;
 __runtime_free( __0ea__dynamic ) ;
 __0ea__dynamic = 0 ;
 }__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__error_code;
}


void samples__207(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1100;
struct samples__207__state *__state=(struct samples__207__state*)__void__state;
ptr dynamic = 0;
ptr surface = 0;
ptr __0Eb=0;
ptr buf__dynamic=0;
u64 __0Db=0;
u64 __0Cb=0;
u64 __0Fb=0;
errcode err=0;
u64 __0Gb=0;
u64 __0Bb=0;
u64 __0Ab=0;
ptr __0Ra__dynamic=0;
ptr __08a=0;

// IMPLEMENTATION
__0Ra__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 __0Eb = 0 ;
 __0Cb = 42 ;
 if(! __0Ra__dynamic )goto __result__buffer_error ;
 __0Db = 8 ;
 __0Fb = ((u64*) __0Ra__dynamic )[1] ;
 __0Gb = ((u64*) __0Ra__dynamic )[2] & ~(1ULL << 63) ;
 if( __0Fb >= __0Gb ){ if( ((u64*) __0Ra__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __0Bb = __0Gb ;
 __0Gb = __0Gb +( __0Gb >>2)+1; if( __0Fb ) ((void**) __0Ra__dynamic )[0] = __runtime_realloc((u64*)((void**) __0Ra__dynamic )[0],  __0Gb * __0Db , __0Bb * __0Db ) ;
 else ((void**) __0Ra__dynamic )[0] = __runtime_alloc( __0Gb * __0Db ) ;
 ((u64*) __0Ra__dynamic )[2] = __0Gb ;
 __08a = (ptr)((void**) __0Ra__dynamic )[0] ;
 if(! __08a )goto __result__buffer_error ;
 } else  __08a = (ptr)(((u64*) __0Ra__dynamic )[0]) ;
 ((u64*) __0Ra__dynamic )[1] = __0Fb +1 ;
 memcpy(&((char*) __08a )[ __0Fb * __0Db ], & __0Cb , 8 ) ;
 __0Ab = 10 ;
 if(! __0Ra__dynamic )goto __result__buffer_error ;
 __0Db = 8 ;
 __0Fb = ((u64*) __0Ra__dynamic )[1] ;
 __0Gb = ((u64*) __0Ra__dynamic )[2] & ~(1ULL << 63) ;
 if( __0Fb >= __0Gb ){ if( ((u64*) __0Ra__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __0Bb = __0Gb ;
 __0Gb = __0Gb +( __0Gb >>2)+1; if( __0Fb ) ((void**) __0Ra__dynamic )[0] = __runtime_realloc((u64*)((void**) __0Ra__dynamic )[0],  __0Gb * __0Db , __0Bb * __0Db ) ;
 else ((void**) __0Ra__dynamic )[0] = __runtime_alloc( __0Gb * __0Db ) ;
 ((u64*) __0Ra__dynamic )[2] = __0Gb ;
 __08a = (ptr)((void**) __0Ra__dynamic )[0] ;
 if(! __08a )goto __result__buffer_error ;
 } else  __08a = (ptr)(((u64*) __0Ra__dynamic )[0]) ;
 ((u64*) __0Ra__dynamic )[1] = __0Fb +1 ;
 memcpy(&((char*) __08a )[ __0Fb * __0Db ], & __0Ab , 8 ) ;
 buf__dynamic = __0Ra__dynamic ;
 dynamic = buf__dynamic ;
 surface = __0Eb ;
 __07a :
goto __return;

// ERROR HANDLING
__result__buffer_error :
printf("Buffer error\n");
__result__error_code=__BUFFER__ERROR;
goto __failsafe;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:
if( dynamic ){if((u64*)((u64*) dynamic )[2]) __runtime_free((u64*)((u64*) dynamic )[0]) ;
 __runtime_free( dynamic ) ;
 dynamic = 0 ;
 }dynamic=0;

// HOTPATH SKIPS TO HERE
__return:
*__state->dynamic____ret=dynamic;
*__state->surface____ret=surface;
__state->err =  __result__error_code;
}



int main() {
struct main__208__state __main_args={0};
__smolambda_initialize_service_tasks(main__208, &__main_args);
return __main_args.err;
}

