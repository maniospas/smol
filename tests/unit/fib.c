#define SMOLAMBDA_SERVICES 3
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
#include "std/oscommon.h"

struct main__186__state{errcode err;};
void main__186(void *__void__state);
struct fib__185__state{errcode err;u64 *__7E____ret;u64 n;};
void fib__185(void *__void__state);

void main__186(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__186__state *__state=(struct main__186__state*)__void__state;
struct fib__185__state* __JF____state = 0 ;
f64 __OF__message=0;
f64 __NF__z=0;
f64 __NF__x=0;
f64 __MF__elapsed=0;
f64 __HF__elapsed=0;
f64 tic=0;
errcode __JF__err=0;
ptr __JF____task=0;
u64 __IF=0;
u64 __JF____7E=0;

// IMPLEMENTATION
__HF__elapsed = __smo_time_eta (); 
 tic = __HF__elapsed ;
 __IF = 25 ;
 __JF____7E = 0 ;
 __JF____state = (struct fib__185__state*)__runtime_calloc(sizeof(struct fib__185__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __JF____state ) ;
 __JF____state -> __7E____ret = & __JF____7E ;
 __JF____state -> n = __IF ;
 __JF____task = __smolambda_add_task ( fib__185 , __JF____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __JF____task ) ;
 if( __JF__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __JF__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __JF__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __smolambda_task_wait ( __JF____task ) ;
 __JF__err = __JF____state -> err ;
 if( __JF__err )goto __KF ;
 printf ( "%lu\n" , __JF____7E ); 
 __LF____end :
 __MF__elapsed = __smo_time_eta (); 
 __NF__x = __MF__elapsed ;
 __NF__z = __NF__x - tic ; 
 __OF__message = __NF__z ;
 printf ( "%.6f\n" , __OF__message ); 
 __OF____end :
 __end :
goto __return;

// ERROR HANDLING
__KF :
printf("Runtime error from fib __JF \n");
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


void fib__185(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct fib__185__state *__state=(struct fib__185__state*)__void__state;
struct fib__185__state* __AF____state = 0 ;
 struct fib__185__state* __EF____state = 0 ;
u64 __7E= *__state->__7E____ret;
u64 n= __state->n;
u64 __GF__z=0;
errcode __EF__err=0;
u64 __CF=0;
errcode __AF__err=0;
u64 __AF____7E=0;
u64 __5E=0;
u64 __9E__z=0;
u64 __DF__z=0;
errcode err=0;
bool __DF____G__z=0;
u64 __EF____7E=0;
ptr __EF____task=0;
ptr __AF____task=0;
bool __6E__z=0;
u64 __8E=0;
bool __9E____G__z=0;

// IMPLEMENTATION
__5E = 2 ;
 __6E__z = n <= __5E ; 
 if(! __6E__z )goto __4E__fi ;
 __7E = 1 ;
 goto __end ;
 __4E__if :
 __4E__fi :
 __8E = 1 ;
 __9E____G__z = __8E > n ; 
 if(! __9E____G__z )goto __9E____F__fi ;
 goto __9E____H ;
 __builtin_unreachable();
 __9E____F__if :
 __9E____F__fi :
 __9E__z = n - __8E ; 
 __AF____7E = 0 ;
 __AF____state = (struct fib__185__state*)__runtime_calloc(sizeof(struct fib__185__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __AF____state ) ;
 __AF____state -> __7E____ret = & __AF____7E ;
 __AF____state -> n = __9E__z ;
 __AF____task = __smolambda_add_task ( fib__185 , __AF____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __AF____task ) ;
 if( __AF__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __AF__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __smolambda_task_wait ( __AF____task ) ;
 __AF__err = __AF____state -> err ;
 if( __AF__err )goto __BF ;
 __CF = 2 ;
 __DF____G__z = __CF > n ; 
 if(! __DF____G__z )goto __DF____F__fi ;
 goto __DF____H ;
 __builtin_unreachable();
 __DF____F__if :
 __DF____F__fi :
 __DF__z = n - __CF ; 
 __EF____7E = 0 ;
 __EF____state = (struct fib__185__state*)__runtime_calloc(sizeof(struct fib__185__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __EF____state ) ;
 __EF____state -> __7E____ret = & __EF____7E ;
 __EF____state -> n = __DF__z ;
 __EF____task = __smolambda_add_task ( fib__185 , __EF____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __EF____task ) ;
 if( __EF__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __EF__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __smolambda_task_wait ( __EF____task ) ;
 __EF__err = __EF____state -> err ;
 if( __EF__err )goto __FF ;
 __GF__z = __AF____7E + __EF____7E ; 
 err = err ;
 __7E = __GF__z ;
 goto __end ;
 __end :
goto __return;

// ERROR HANDLING
__9E____H :
 printf ( "Error: unsigned substraction yielded a negative\n" ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __BF :
printf("Runtime error from fib __AF \n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
 __DF____H :
 printf ( "Error: unsigned substraction yielded a negative\n" ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __FF :
printf("Runtime error from fib __EF \n");
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
*__state->__7E____ret=__7E;
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}



int main() {
struct main__186__state __main_args={0};
__smolambda_initialize_service_tasks(main__186, &__main_args);
return __main_args.err;
}

