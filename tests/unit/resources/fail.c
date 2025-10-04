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
#include<string.h>

#include<stdlib.h>

#include<stdio.h>

struct test__778__state{errcode err;};
__externc void test__778(void *__void__state);
struct main__779__state{errcode err;};
__externc void main__779(void *__void__state);

void main__779(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__779__state *__state=(struct main__779__state*)__void__state;
struct test__778__state* __g5____state = 0 ;
bool __j5=0;
errcode __g5__err=0;
bool __k5__z=0;
ptr __g5____task=0;
cstr __l5=0;

// IMPLEMENTATION
__g5____state = (struct test__778__state*)__runtime_calloc(sizeof(struct test__778__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __g5____state ) ;
 __g5____task = __smolambda_add_task ( test__778 , __g5____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __g5____task ) ;
 if( __g5__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __g5____task ) ;
 __g5__err = __g5____state -> err ;
 __j5 = __g5__err ;
 __k5__z =(! __j5 ); 
 __k5____end :
 if(! __k5__z )goto __h5__fi ;
 __l5 = "Failed to detect error" ;
 goto __m5____oD ;
 __builtin_unreachable();
 __h5__fi :
 __end :
goto __return;

// ERROR HANDLING
__m5____oD :
 printf ( "%s\n" , __l5 ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__i5 :
printf("Runtime error from  __g5 \n");
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


void test__778(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct test__778__state *__state=(struct test__778__state*)__void__state;
u64 __e5____PB__z=0;
char __e5__first=0;
bool __e5____IB__z=0;
ptr __b5____Ib__contents=0;
char __b5____Fb____uQ=0;
cstr __b5____Fb____oQ=0;
bool __b5____Fb____nQ__z=0;
ptr __b5____Fb__mem=0;
ptr __b5____Fb__next_acquired=0;
u64 __b5____Fb__self__allocated__prev=0;
bool __b5____Fb__success=0;
u64 __b5____Fb__next_size=0;
bool __b5____Fb____nQ__x=0;
bool __b5____Fb____iQ=0;
u64 __b5____Cb__z=0;
u64 __b5____Bb=0;
u64 __b5__total_len=0;
bool __e5____PB____G__z=0;
bool __b5____Fb____jQ__z=0;
u64 __X5__allocated=0;
ptr __b5____Ab__contents=0;
u64 __X5____dynamic_entry=0;
cstr __a5=0;
char __b5____Fb____gQ=0;
char __b5__first=0;
ptr __e5__contents=0;
u64 __X5__size=0;
char __b5____Db=0;
u64 __b5____Fb____wQ__bytesize=0;
cstr __Z5=0;
char __b5____Ab__first=0;
bool __e5____LB__z=0;
ptr __b5____9a__contents=0;
u64 __e5____PB__x=0;
u64 __b5____9a__length=0;
cstr __b5____Fb____kQ=0;
ptr __X5__acquired=0;
ptr __X5____ZQ__acquired=0;
u64 __X5____ZQ____UQ=0;
u64 __b5__len_y=0;
u64 __X5____ZQ____VQ=0;
char __b5____9a__first=0;
u64 __d5=0;
u64 __X5____ZQ____dynamic_entry=0;
ptr __b5____9a__noptr=0;
ptr __b5____9a____m__contents=0;
u64 __c5=0;
char __b5____Fb____wQ____CF=0;
ptr __b5____Ab____m__contents=0;
u64 __b5____Ab__length=0;
ptr __b5____Ab__noptr=0;
u64 __b5__len_x=0;

// IMPLEMENTATION
__X5____ZQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __X5____ZQ__acquired )(( ptr **) __X5____ZQ__acquired )[0]=0; 
 __X5____ZQ____UQ = 0 ;
 __X5____ZQ____VQ = 0 ;
 __X5__acquired = __X5____ZQ__acquired ;
 __X5__size = __X5____ZQ____UQ ;
 __X5__allocated = __X5____ZQ____VQ ;
 __X5____dynamic_entry = __X5____ZQ____dynamic_entry ;
 __Z5 = "Hi there!" ;
 __a5 = " We are manually failing but still displaying this heap-allocated error message" ;
 __b5____9a__length = strlen ( __Z5 ); __b5____9a__contents =( ptr ) __Z5 ; __b5____9a__first = __Z5 [0]; __b5____9a__noptr =( ptr ) __b5____9a__noptr ; 
 __b5____9a____m__contents = __b5____9a__contents ;
 __b5____Ab__length = strlen ( __a5 ); __b5____Ab__contents =( ptr ) __a5 ; __b5____Ab__first = __a5 [0]; __b5____Ab__noptr =( ptr ) __b5____Ab__noptr ; 
 __b5____Ab____m__contents = __b5____Ab__contents ;
 __b5__len_x = __b5____9a__length ; __b5__len_y = __b5____Ab__length ; __b5__total_len = __b5__len_x + __b5__len_y ; __b5__first = __b5____9a__length ? __b5____9a__first : __b5____Ab__first ; 
 __b5____Bb = 1 ;
 __b5____Cb__z = __b5__total_len + __b5____Bb ; 
 __b5____Cb____end :
 __b5____Db = 0 ;
 __b5____Fb____iQ = __X5__acquired ;
 __b5____Fb____jQ__z =(! __b5____Fb____iQ ); 
 __b5____Fb____jQ____end :
 if(! __b5____Fb____jQ__z )goto __b5____Fb____hQ__fi ;
 __b5____Fb____kQ = "Did not initialize Dynamic" ;
 goto __b5____Fb____lQ____oD ;
 __builtin_unreachable();
 __b5____Fb____hQ__fi :
 __b5____Fb__next_size = __X5__size +1; __b5____Fb__success = true ; __b5____Fb__self__allocated__prev = __X5__allocated ; if ( __b5____Fb__next_size >= __X5__allocated ) { __X5__allocated = __X5__allocated + __X5__allocated /2+1; __b5____Fb__next_acquired =( ptr )((( ptr **) __X5__acquired )[0]? __runtime_realloc ((( ptr **) __X5__acquired )[0], __X5__allocated * sizeof ( ptr ), __b5____Fb__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __X5__allocated * sizeof ( ptr ))); if ( __b5____Fb__success = __b5____Fb__next_acquired )(( ptr **) __X5__acquired )[0]=( ptr *) __b5____Fb__next_acquired ; } if ( __b5____Fb__success ) { __b5____Fb__mem =( ptr ) __runtime_alloc ( __b5____Cb__z * sizeof ( __b5____Fb____gQ )); if ( __b5____Fb__success = __b5____Fb__mem ) {(( ptr **) __X5__acquired )[0][ __X5__size ]= __b5____Fb__mem ; __X5__size = __b5____Fb__next_size ; } } 
 __b5____Fb____nQ__x = __b5____Fb__success ;
 __b5____Fb____nQ__z =(! __b5____Fb____nQ__x ); 
 __b5____Fb____nQ____end :
 if(! __b5____Fb____nQ__z )goto __b5____Fb____mQ__fi ;
 __b5____Fb____oQ = "Failed a Dynamic allocation" ;
 goto __b5____Fb____pQ____oD ;
 __builtin_unreachable();
 __b5____Fb____mQ__fi :
 __b5____Fb____uQ = 0 ;
 __b5____Fb____wQ__bytesize = sizeof ( __b5____Fb____wQ____CF )* __b5____Cb__z ; 
 __b5____Fb____wQ____end :
 memcpy (( char *) __b5____Fb__mem ,( char *) __b5____9a____m__contents , __b5__len_x ); memcpy (( char *) __b5____Fb__mem + __b5__len_x ,( char *) __b5____Ab____m__contents , __b5__len_y );(( char *) __b5____Fb__mem )[ __b5__total_len ]=0; 
 __b5____Ib__contents = __b5____Fb__mem ;
 __X5__acquired = __X5__acquired ;
 __X5__size = __X5__size ;
 __X5__allocated = __X5__allocated ;
 __X5____dynamic_entry = __X5____dynamic_entry ;
 __c5 = 0 ;
 __d5 = 60 ;
 __e5____IB__z = __d5 < __c5 ; 
 __e5____IB____end :
 if(! __e5____IB__z )goto __e5____HB__fi ;
 goto __e5____JB ;
 __builtin_unreachable();
 __e5____HB__fi :
 __e5____LB__z = __d5 > __b5__total_len ; 
 __e5____LB____end :
 if(! __e5____LB__z )goto __e5____KB__fi ;
 goto __e5____MB ;
 __builtin_unreachable();
 __e5____KB__fi :
 __e5__contents =( ptr )(( char *) __b5____Ib__contents + __c5 * sizeof ( char )); __e5__first = __c5 == __d5 ? 0. (( __builtin_constant_p ( __c5 )&& __c5 ==0)? __b5__first :(( char *) __b5____Ib__contents )[ __c5 ]); 
 __e5____PB__x = __d5 ;
 __e5____PB____G__z = __c5 > __e5____PB__x ; 
 __e5____PB____G____end :
 if(! __e5____PB____G__z )goto __e5____PB____F__fi ;
 goto __e5____PB____H ;
 __builtin_unreachable();
 __e5____PB____F__fi :
 __e5____PB__z = __e5____PB__x - __c5 ; 
 __e5____PB____end :
 goto __f5____qD ;
 __builtin_unreachable();
 __end :
goto __return;

// ERROR HANDLING
__e5____PB____H :
 printf ( "Error: unsigned substraction yielded a negative\n" ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__f5____qD :
 printf ( "%.*s\n" ,( int ) __e5____PB__z ,( char *) __e5__contents ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__e5____MB :
 printf ( "String slice must end at most at the length of the base string\n" ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__e5____JB :
 printf ( "String slice cannot end before it starts\n" ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__b5____Fb____pQ____oD :
 printf ( "%s\n" , __b5____Fb____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__b5____Fb____lQ____oD :
 printf ( "%s\n" , __b5____Fb____kQ ); 
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
if ( __X5__acquired ) { for ( __X5____dynamic_entry =0; __X5____dynamic_entry < __X5__size ;++ __X5____dynamic_entry ) { __runtime_free ((( ptr **) __X5__acquired )[0][ __X5____dynamic_entry ]); } __runtime_free ( __X5__acquired ); __X5__acquired =0; __X5__size =0; __X5__allocated =0; } 
 if ( __X5__acquired ) { for ( __X5____ZQ____dynamic_entry =0; __X5____ZQ____dynamic_entry < __X5____ZQ____UQ ;++ __X5____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __X5__acquired )[0][ __X5____ZQ____dynamic_entry ]); } __runtime_free ( __X5__acquired ); __X5__acquired =0; __X5____ZQ____UQ =0; __X5____ZQ____VQ =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}



int main() {
struct main__779__state __main_args={0};
__smolambda_initialize_service_tasks(main__779, &__main_args);
return __main_args.err;
}

