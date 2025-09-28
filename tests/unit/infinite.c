#define SMOLAMBDA_SERVICES 3
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

#include<stdio.h>

#include <stdio.h>
struct main__183__state{errcode err;};
__externc void main__183(void *__void__state);
struct test__182__state{errcode err;u64 n;u64 last;};
__externc void test__182(void *__void__state);

void test__182(void *__void__state){
errcode __result__errocode=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct test__182__state *__state=(struct test__182__state*)__void__state;
struct test__182__state* __8E____state = 0 ;
u64 n= __state->n;
u64 last= __state->last;
u64 __6E=0;
cstr __4E=0;
bool __3E__z=0;
ptr __8E____task=0;
u64 __7E__z=0;
errcode __8E__err=0;
cstr __0E=0;

// IMPLEMENTATION
__0E = "123" ;
 printf ( "%lu\n" , n ); 
 __1E____end :
 __3E__z =( n == last ); 
 __3E____end :
 if(! __3E__z )goto __2E__fi ;
 __4E = "loop ended" ;
 goto __5E____oD ;
 __builtin_unreachable();
 goto __end ;
 __2E__fi :
 __6E = 1 ;
 __7E__z = n + __6E ; 
 __7E____end :
 {char mark;if(__service_stack_floor+ 5236 >=(char*)&mark) goto __service_stack_floor_handler;} __8E____state = (struct test__182__state*)__runtime_calloc(sizeof(struct test__182__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __8E____state ) ;
 __8E____state -> n = __7E__z ;
 __8E____state -> last = last ;
 __8E____task = __smolambda_add_task ( test__182 , __8E____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __8E____task ) ;
 if( __8E__err ) goto  __result_unhandled_error ;
 __end :
goto __return;

// ERROR HANDLING
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__service_stack_floor_handler:
printf("Isufficient stack for safe service call\n");
__result__errocode=__BUFFER__ERROR;
goto __failsafe;
__5E____oD :
 printf ( "%s\n" , __4E ); 
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


void main__183(void *__void__state){
errcode __result__errocode=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__183__state *__state=(struct main__183__state*)__void__state;
struct test__182__state* __BF____state = 0 ;
errcode __BF__err=0;
u64 __AF=0;
u64 __BF__n=0;
ptr __BF____task=0;
u64 __9E=0;

// IMPLEMENTATION
__9E = 1 ;
 __AF = 0 ;
 {char mark;if(__service_stack_floor+ 5228 >=(char*)&mark) goto __service_stack_floor_handler;} __BF____state = (struct test__182__state*)__runtime_calloc(sizeof(struct test__182__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __BF____state ) ;
 __BF____state -> n = __9E ;
 __BF____state -> last = __AF ;
 __BF____task = __smolambda_add_task ( test__182 , __BF____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __BF____task ) ;
 if( __BF__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __BF____task ) ;
 __BF__err = __BF____state -> err ;
 if( __BF__err )goto __CF ;
 printf ( "%lu\n" , __BF__n ); 
 __DF____end :
 __end :
goto __return;

// ERROR HANDLING
__CF :
printf("Runtime error from  __BF \n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__service_stack_floor_handler:
printf("Isufficient stack for safe service call\n");
__result__errocode=__BUFFER__ERROR;
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

