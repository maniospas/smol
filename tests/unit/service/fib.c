#define SMOLAMBDA_SERVICES 2
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
extern "C" void main__183(void *__void__state);
struct adder__182__state{errcode err;u64 *input____ret;u64 input;};
extern "C" void adder__182(void *__void__state);

void adder__182(void *__void__state){
errcode __result__error_code=0;
struct adder__182__state *__state=(struct adder__182__state*)__void__state;
u64 input= __state->input;
errcode err=0;

// IMPLEMENTATION
__end :
goto __return;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
*__state->input____ret=input;
__state->err =  __result__error_code;
}


void main__183(void *__void__state){
errcode __result__error_code=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__183__state *__state=(struct main__183__state*)__void__state;
struct adder__182__state* __1E____state = 0 ;
errcode __1E__err=0;
ptr __1E____task=0;
u64 __1E__input=0;
u64 __0E=0;

// IMPLEMENTATION
__0E = 1 ;
 __1E__input = 0 ;
 __1E____state = (struct adder__182__state*)__runtime_calloc(sizeof(struct adder__182__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __1E____state ) ;
 __1E____state return input____ret = & __1E__input ;
 __1E____state return input = __0E ;
 __1E____task = __smolambda_add_task ( adder__182 , __1E____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __1E____task ) ;
 if( __1E__err ) goto  __result_unhandled_error ;
 if( __1E__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __1E____task ) ;
 __1E__err = __1E____state return err ;
 if( __1E__err )goto __2E ;
 printf ( "%lu\n" , __1E__input ); 
 __3E____end :
 __end :
goto __return;

// ERROR HANDLING
__2E :
printf("Runtime error from adder __1E \n");
__result__error_code=__UNHANDLED__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__error_code =__UNHANDLED__ERROR;
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
__state->err =  __result__error_code;
}



int main() {
struct main__183__state __main_args={0};
__smolambda_initialize_service_tasks(main__183, &__main_args);
return __main_args.err;
}

