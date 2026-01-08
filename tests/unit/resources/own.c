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

#include<string.h>

#include<stdio.h>

struct main__353__state{errcode err;};
__externc void main__353(void *__void__state);
struct test__352__state{errcode err;__new *__0pC____ret;ptr *contents____ret;u64 *length____ret;char *first____ret;ptr *memory____ret;__new s____0pC;ptr s__contents;u64 s__length;char s__first;ptr s__memory;};
__externc void test__352(void *__void__state);

void test__352(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1136;
struct test__352__state *__state=(struct test__352__state*)__void__state;
ptr s__contents= __state->s__contents;
u64 s__length= __state->s__length;
char s__first= __state->s__first;
ptr s__memory= __state->s__memory;
ptr contents = 0;
u64 length = 0;
char first = 0;
ptr memory = 0;
__new s____0pC=0;
errcode err=0;

// IMPLEMENTATION
printf ( "%.*s\n" ,( int ) s__length ,( char *) s__contents ); 
 __0LrB :
 contents = s__contents ;
 length = s__length ;
 first = s__first ;
 memory = s__memory ;
 __0IrB :
goto __return;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
*__state->contents____ret=contents;
*__state->length____ret=length;
*__state->first____ret=first;
*__state->memory____ret=memory;
__state->err =  __result__error_code;
}


void main__353(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1152;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__353__state *__state=(struct main__353__state*)__void__state;
struct test__352__state* __0rqB____state = 0 ;
ptr __0lrB=0;
u64 s__length=0;
__new __0krB=0;
char __0jrB=0;
ptr s__memory=0;
u64 __0irB=0;
ptr __0hrB=0;
ptr s__contents=0;
ptr __0ZrB=0;
cstr __0WrB=0;
ptr __0TrB=0;
char __0frB=0;
__new s____0pC=0;
char s__first=0;
u64 __0drB=0;
ptr __0grB=0;
errcode __0PrB=0;
ptr __0erB=0;

// IMPLEMENTATION
__0WrB = "123" ;
 __0drB = strlen ( __0WrB ); __0erB =( ptr ) __0WrB ; __0frB = __0WrB [0]; __0grB =0; 
 __0TrB = __0erB ;
 __0hrB = 0 ;
 __0irB = 0 ;
 __0jrB = 0 ;
 __0ZrB = 0 ;
 {char mark;if(__service_stack_floor+ 1136 >=(char*)&mark) goto __service_stack_floor_handler;} __0rqB____state = (struct test__352__state*)__runtime_calloc(sizeof(struct test__352__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0rqB____state ) ;
 __0rqB____state -> __0pC____ret = & __0krB ;
 __0rqB____state -> contents____ret = & __0hrB ;
 __0rqB____state -> length____ret = & __0irB ;
 __0rqB____state -> first____ret = & __0jrB ;
 __0rqB____state -> memory____ret = & __0ZrB ;
 __0rqB____state -> s____0pC = s____0pC ;
 __0rqB____state -> s__contents = __0TrB ;
 __0rqB____state -> s__length = __0drB ;
 __0rqB____state -> s__first = __0frB ;
 __0rqB____state -> s__memory = __0grB ;
 __0lrB = __smolambda_add_task ( test__352 , __0rqB____state ) ;
 if( __0lrB ) __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0lrB ) ;
 if( __0PrB ) goto  __result_unhandled_error ;
 printf ( "%.*s\n" ,( int ) __0irB ,( char *) __0hrB ); 
 __0OrB :
 __0NrB :
goto __return;

// ERROR HANDLING
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
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__error_code;
}



int main() {
struct main__353__state __main_args={0};
__smolambda_initialize_service_tasks(main__353, &__main_args);
return __main_args.err;
}

