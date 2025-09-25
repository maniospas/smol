#define SMOLAMBDA_SERVICES 3
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

#include <stdio.h>
#include<stdio.h>

struct test__182__state{errcode err;u64 n;u64 last;};
__externc void test__182(void *__void__state);
struct main__183__state{errcode err;};
__externc void main__183(void *__void__state);

void main__183(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__183__state *__state=(struct main__183__state*)__void__state;
struct test__182__state* __AF____state = 0 ;
u64 __AF__n=0;
u64 __9E=0;
errcode __AF__err=0;
u64 __8E=0;
ptr __AF____task=0;

// IMPLEMENTATION
__8E = 1 ;
 __9E = 10 ;
 __AF____state = (struct test__182__state*)__runtime_calloc(sizeof(struct test__182__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __AF____state ) ;
 __AF____state -> n = __8E ;
 __AF____state -> last = __9E ;
 __AF____task = __smolambda_add_task ( test__182 , __AF____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __AF____task ) ;
 if( __AF__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __AF____task ) ;
 __AF__err = __AF____state -> err ;
 if( __AF__err )goto __BF ;
 printf ( "%lu\n" , __AF__n ); 
 __CF____end :
 __end :
goto __return;

// ERROR HANDLING
__BF :
printf("Runtime error from  __AF \n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:
__runtime_apply_linked(__smolambda_all_tasks, __smolambda_task_wait, 0);
__runtime_apply_linked(__smolambda_all_tasks, __smolambda_task_destroy, 1);
__smolambda_all_tasks = 0;

// HOTPATH SKIPS TO HERE
__return:
__runtime_apply_linked(__smolambda_all_tasks, __smolambda_task_wait, 0);
__runtime_apply_linked(__smolambda_all_tasks, __smolambda_task_destroy, 1);
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}


void test__182(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct test__182__state *__state=(struct test__182__state*)__void__state;
struct test__182__state* __7E____state = 0 ;
u64 n= __state->n;
u64 last= __state->last;
errcode __7E__err=0;
ptr __7E____task=0;
u64 __5E=0;
u64 __6E__z=0;
cstr __3E=0;
bool __2E__z=0;

// IMPLEMENTATION
printf ( "%lu\n" , n ); 
 __0E____end :
 __2E__z =( n == last ); 
 __2E____end :
 if(! __2E__z )goto __1E__fi ;
 __3E = "loop ended" ;
 goto __4E____oD ;
 __builtin_unreachable();
 goto __end ;
 __1E__fi :
 __5E = 1 ;
 __6E__z = n + __5E ; 
 __6E____end :
 __7E____state = (struct test__182__state*)__runtime_calloc(sizeof(struct test__182__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __7E____state ) ;
 __7E____state -> n = __6E__z ;
 __7E____state -> last = last ;
 __7E____task = __smolambda_add_task ( test__182 , __7E____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __7E____task ) ;
 if( __7E__err ) goto  __result_unhandled_error ;
 __end :
goto __return;

// ERROR HANDLING
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__4E____oD :
 printf ( "%s\n" , __3E ); 
__result__errocode=__USER__ERROR;
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
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}



int main() {
struct main__183__state __main_args={0};
__smolambda_initialize_service_tasks(main__183, &__main_args);
return __main_args.err;
}

