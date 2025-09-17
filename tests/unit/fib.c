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

#include <stdio.h>
struct main__183__state{errcode err;};
void main__183(void *__void__state);
struct fib__182__state{errcode err;u64 *__4E____ret;u64 n;};
void fib__182(void *__void__state);

void main__183(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__183__state *__state=(struct main__183__state*)__void__state;
struct fib__182__state* __8E____state = 0 ;
 struct fib__182__state* __CF____state = 0 ;
 struct fib__182__state* __GF____state = 0 ;
u64 __IF__message=0;
u64 __GF____5E=0;
u64 __GF____3E__x=0;
u64 __GF____2E=0;
u64 __GF____6E__z=0;
u64 __GF____3E__y=0;
u64 __GF____4E=0;
u64 __8E____6E__z=0;
u64 __CF__n=0;
bool __8E____3E__z=0;
u64 __8E__n2=0;
u64 __8E____3E__y=0;
u64 __8E____5E=0;
errcode __8E__err=0;
u64 __GF__n=0;
u64 __8E__n=0;
u64 __8E____6E__x=0;
u64 __EF__message=0;
u64 __CF____3E__y=0;
u64 __AF__message=0;
u64 __FF=0;
u64 __8E____4E=0;
u64 __CF____6E__y=0;
u64 __8E____2E=0;
u64 __8E____6E__y=0;
u64 __CF____3E__x=0;
u64 __BF=0;
u64 __8E____3E__x=0;
u64 __GF____6E__x=0;
errcode __CF__err=0;
bool __GF____3E__z=0;
u64 __GF____6E__y=0;
u64 __GF__n2=0;
u64 __CF____2E=0;
u64 __CF____6E__x=0;
u64 __7E=0;
u64 __CF____4E=0;
u64 __CF__n2=0;
bool __CF____3E__z=0;
u64 __CF____5E=0;
ptr __CF____task=0;
u64 __CF____6E__z=0;
errcode __GF__err=0;
ptr __8E____task=0;
ptr __GF____task=0;

// IMPLEMENTATION
__7E = 1 ;
 __8E____4E = 0 ;
 __8E____state = (struct fib__182__state*)__runtime_calloc(sizeof(struct fib__182__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __8E____state ) ;
 __8E____state -> __4E____ret = & __8E____4E ;
 __8E____state -> n = __7E ;
 __8E____task = __smolambda_add_task ( fib__182 , __8E____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __8E____task ) ;
 if( __8E__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __8E__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __8E__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __smolambda_task_wait ( __8E____task ) ;
 __8E__err = __8E____state -> err ;
 if( __8E__err )goto __9E ;
 __AF__message = __8E____4E ;
 printf ( "%lu\n" , __AF__message ); 
 __AF____end :
 __BF = 2 ;
 __CF____4E = 0 ;
 __CF____state = (struct fib__182__state*)__runtime_calloc(sizeof(struct fib__182__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __CF____state ) ;
 __CF____state -> __4E____ret = & __CF____4E ;
 __CF____state -> n = __BF ;
 __CF____task = __smolambda_add_task ( fib__182 , __CF____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __CF____task ) ;
 if( __CF__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __CF__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __CF__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __smolambda_task_wait ( __CF____task ) ;
 __CF__err = __CF____state -> err ;
 if( __CF__err )goto __DF ;
 __EF__message = __CF____4E ;
 printf ( "%lu\n" , __EF__message ); 
 __EF____end :
 __FF = 3 ;
 __GF____4E = 0 ;
 __GF____state = (struct fib__182__state*)__runtime_calloc(sizeof(struct fib__182__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __GF____state ) ;
 __GF____state -> __4E____ret = & __GF____4E ;
 __GF____state -> n = __FF ;
 __GF____task = __smolambda_add_task ( fib__182 , __GF____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __GF____task ) ;
 if( __GF__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __GF__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __GF__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __smolambda_task_wait ( __GF____task ) ;
 __GF__err = __GF____state -> err ;
 if( __GF__err )goto __HF ;
 __IF__message = __GF____4E ;
 printf ( "%lu\n" , __IF__message ); 
 __IF____end :
 __end :
goto __return;

// ERROR HANDLING
__9E :
printf("Runtime error from fib __8E \n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
 __DF :
printf("Runtime error from fib __CF \n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
 __HF :
printf("Runtime error from fib __GF \n");
__result__errocode=__UNHANDLED__ERROR;
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


void fib__182(void *__void__state){
errcode __result__errocode=0;
struct fib__182__state *__state=(struct fib__182__state*)__void__state;
u64 __4E= *__state->__4E____ret;
u64 n= __state->n;
u64 __6E__y=0;
u64 __2E=0;
u64 __3E__x=0;
errcode err=0;
u64 __6E__x=0;
u64 __3E__y=0;
u64 n2=0;
bool __3E__z=0;
u64 __6E__z=0;
u64 __5E=0;

// IMPLEMENTATION
__2E = 1 ;
 __3E__x = n ;
 __3E__y = __2E ;
 __3E__z = __3E__x <= __3E__y ; 
 goto __3E____end ;
 __3E____end :
 if(! __3E__z )goto __1E__fi ;
 __4E = 1 ;
 goto __end ;
 __1E__if :
 __1E__fi :
 __5E = 1 ;
 __6E__x = n ;
 __6E__y = __5E ;
 __6E__z = __6E__x + __6E__y ; 
 goto __6E____end ;
 __6E____end :
 n2 = __6E__z ;
 err = err ;
 n2 = __4E ;
 goto __end ;
 __end :
goto __return;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
*__state->__4E____ret=__4E;
__state->err =  __result__errocode;
}



int main() {
struct main__183__state __main_args={0};
__smolambda_initialize_service_tasks(main__183, &__main_args);
return __main_args.err;
}

