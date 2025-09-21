#define SMOLAMBDA_SERVICES 8
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

#include<sys/wait.h>

#if defined(_WIN32)||defined(_WIN64)
#define popen _popen
#define pclose _pclose
#endif

#include<string.h>

#include<stdlib.h>

#include<stdio.h>

#include <stdio.h>
#include "std/oscommon.h"

struct main__823__state{errcode err;};
extern "C" void main__823(void *__void__state);
struct std_test__819__state{errcode err;cstr name;};
extern "C" void std_test__819(void *__void__state);
struct std_test__820__state{errcode err;nominal name____b;ptr name__contents;u64 name__length;char name__first;ptr name__memory;};
extern "C" void std_test__820(void *__void__state);
struct std_test__821__state{errcode err;nominal name____c;ptr name__contents;u64 name__length;char name__first;ptr name__memory;};
extern "C" void std_test__821(void *__void__state);
struct all__822__state{errcode err;};
extern "C" void all__822(void *__void__state);
struct run__815__state{errcode err;cstr command;};
extern "C" void run__815(void *__void__state);
struct run__816__state{errcode err;nominal command____b;ptr command__contents;u64 command__length;char command__first;ptr command__memory;};
extern "C" void run__816(void *__void__state);
struct run__817__state{errcode err;nominal command____c;ptr command__contents;u64 command__length;char command__first;ptr command__memory;};
extern "C" void run__817(void *__void__state);

void run__815(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__815__state *__state=(struct run__815__state*)__void__state;
cstr command= __state->command;
i64 __fAB__status=0;
ptr __fAB__contents=0;
bool __fAB____C9__z=0;
errcode err=0;
ptr __fAB____A9__contents=0;
u64 __fAB____A9__length=0;
nominal __gAB__p____78=0;
ptr process__contents=0;
nominal process____78=0;
ptr __dAB__contents=0;
ptr __eAB__contents=0;
char __fAB____A9__first=0;
ptr __fAB____A9__noptr=0;
ptr __fAB____A9____p__contents=0;
ptr __fAB____C9__x=0;
bool __fAB____D9__z=0;

// IMPLEMENTATION
__dAB__contents = 0 ;
 __eAB__contents = __dAB__contents ;
 __fAB____A9__length = strlen ( command ); __fAB____A9__contents =( ptr ) command ; __fAB____A9__first = command [0]; __fAB____A9__noptr =( ptr ) __fAB____A9__noptr ; 
 __fAB____A9____p__contents = __fAB____A9__contents ;
 __fAB__contents =( ptr ) popen (( cstr ) __fAB____A9____p__contents , "r" ); 
 __fAB____C9__x = __fAB__contents ;
 __fAB____C9__z =( __fAB____C9__x ); 
 __fAB____C9____end :
 __fAB____D9__z =(! __fAB____C9__z ); 
 __fAB____D9____end :
 if(! __fAB____D9__z )goto __fAB____B9__fi ;
 goto __fAB____E9 ;
 __builtin_unreachable();
 __fAB____B9__fi :
 process__contents = __fAB__contents ;
 if ( process__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process__contents )) { } } 
 __gAB____end :
 process____78 = __gAB__p____78 ;
 __fAB__status =0; if ( process__contents ) __fAB__status = pclose (( FILE *) process__contents ); process__contents =0; if ( __fAB__status ) { if ( __fAB__status !=-1&& WIFEXITED ( __fAB__status )) __fAB__status = WEXITSTATUS ( __fAB__status ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __fAB__status ); __result__errocode = __USER__ERROR ; goto __failsafe ; } 
 __end :
goto __return;

// ERROR HANDLING
__fAB____E9 :
 printf ( "Error: Failed to start process\n" ); 
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


void all__822(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct all__822__state *__state=(struct all__822__state*)__void__state;
struct std_test__819__state* __KCB____state = 0 ;
 struct std_test__819__state* __MCB____state = 0 ;
 struct std_test__819__state* __OCB____state = 0 ;
 struct std_test__819__state* __QCB____state = 0 ;
 struct std_test__819__state* __SCB____state = 0 ;
 struct std_test__819__state* __UCB____state = 0 ;
 struct std_test__819__state* __WCB____state = 0 ;
 struct std_test__819__state* __YCB____state = 0 ;
 struct std_test__819__state* __aCB____state = 0 ;
 struct std_test__819__state* __cCB____state = 0 ;
 struct std_test__819__state* __eCB____state = 0 ;
 struct std_test__819__state* __gCB____state = 0 ;
 struct std_test__819__state* __iCB____state = 0 ;
 struct std_test__819__state* __kCB____state = 0 ;
 struct std_test__819__state* __mCB____state = 0 ;
 struct std_test__819__state* __oCB____state = 0 ;
 struct std_test__819__state* __qCB____state = 0 ;
 struct std_test__819__state* __sCB____state = 0 ;
 struct std_test__819__state* __uCB____state = 0 ;
 struct std_test__819__state* __wCB____state = 0 ;
 struct std_test__819__state* __yCB____state = 0 ;
errcode __yCB__err=0;
cstr __vCB=0;
errcode __uCB__err=0;
ptr __uCB____task=0;
cstr __tCB=0;
errcode __sCB__err=0;
cstr __rCB=0;
errcode __qCB__err=0;
errcode __mCB__err=0;
ptr __mCB____task=0;
cstr __lCB=0;
cstr __jCB=0;
errcode __iCB__err=0;
ptr __iCB____task=0;
cstr __hCB=0;
errcode __gCB__err=0;
ptr __gCB____task=0;
cstr __fCB=0;
ptr __eCB____task=0;
cstr __dCB=0;
errcode __aCB__err=0;
cstr __ZCB=0;
errcode __YCB__err=0;
ptr __YCB____task=0;
cstr __VCB=0;
cstr __RCB=0;
errcode __QCB__err=0;
ptr __QCB____task=0;
cstr __PCB=0;
errcode __OCB__err=0;
ptr __OCB____task=0;
cstr __NCB=0;
errcode __cCB__err=0;
ptr __MCB____task=0;
cstr __LCB=0;
errcode __KCB__err=0;
cstr __JCB=0;
cstr __nCB=0;
errcode __kCB__err=0;
ptr __SCB____task=0;
errcode __SCB__err=0;
errcode __oCB__err=0;
ptr __oCB____task=0;
cstr __pCB=0;
ptr __cCB____task=0;
errcode __eCB__err=0;
errcode __MCB__err=0;
ptr __yCB____task=0;
ptr __KCB____task=0;
ptr __wCB____task=0;
cstr __TCB=0;
ptr __UCB____task=0;
errcode err=0;
ptr __kCB____task=0;
errcode __WCB__err=0;
cstr __XCB=0;
cstr __xCB=0;
ptr __sCB____task=0;
ptr __WCB____task=0;
errcode __wCB__err=0;
ptr __qCB____task=0;
ptr __aCB____task=0;
errcode __UCB__err=0;
cstr __bCB=0;

// IMPLEMENTATION
__JCB = "buffers" ;
 __KCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __KCB____state ) ;
 __KCB____state -> name = __JCB ;
 __KCB____task = __smolambda_add_task ( std_test__819 , __KCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __KCB____task ) ;
 if( __KCB__err ) goto  __result_unhandled_error ;
 if( __KCB__err ) goto  __result_unhandled_error ;
 __LCB = "bbuffer" ;
 __MCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __MCB____state ) ;
 __MCB____state -> name = __LCB ;
 __MCB____task = __smolambda_add_task ( std_test__819 , __MCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __MCB____task ) ;
 if( __MCB__err ) goto  __result_unhandled_error ;
 if( __MCB__err ) goto  __result_unhandled_error ;
 __NCB = "bufferconst" ;
 __OCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __OCB____state ) ;
 __OCB____state -> name = __NCB ;
 __OCB____task = __smolambda_add_task ( std_test__819 , __OCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __OCB____task ) ;
 if( __OCB__err ) goto  __result_unhandled_error ;
 if( __OCB__err ) goto  __result_unhandled_error ;
 __PCB = "buffergrow" ;
 __QCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __QCB____state ) ;
 __QCB____state -> name = __PCB ;
 __QCB____task = __smolambda_add_task ( std_test__819 , __QCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __QCB____task ) ;
 if( __QCB__err ) goto  __result_unhandled_error ;
 if( __QCB__err ) goto  __result_unhandled_error ;
 __RCB = "effvec" ;
 __SCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __SCB____state ) ;
 __SCB____state -> name = __RCB ;
 __SCB____task = __smolambda_add_task ( std_test__819 , __SCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __SCB____task ) ;
 if( __SCB__err ) goto  __result_unhandled_error ;
 if( __SCB__err ) goto  __result_unhandled_error ;
 __TCB = "fail" ;
 __UCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __UCB____state ) ;
 __UCB____state -> name = __TCB ;
 __UCB____task = __smolambda_add_task ( std_test__819 , __UCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __UCB____task ) ;
 if( __UCB__err ) goto  __result_unhandled_error ;
 if( __UCB__err ) goto  __result_unhandled_error ;
 __VCB = "file" ;
 __WCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __WCB____state ) ;
 __WCB____state -> name = __VCB ;
 __WCB____task = __smolambda_add_task ( std_test__819 , __WCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __WCB____task ) ;
 if( __WCB__err ) goto  __result_unhandled_error ;
 if( __WCB__err ) goto  __result_unhandled_error ;
 __XCB = "filesize" ;
 __YCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __YCB____state ) ;
 __YCB____state -> name = __XCB ;
 __YCB____task = __smolambda_add_task ( std_test__819 , __YCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __YCB____task ) ;
 if( __YCB__err ) goto  __result_unhandled_error ;
 if( __YCB__err ) goto  __result_unhandled_error ;
 __ZCB = "finally" ;
 __aCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __aCB____state ) ;
 __aCB____state -> name = __ZCB ;
 __aCB____task = __smolambda_add_task ( std_test__819 , __aCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __aCB____task ) ;
 if( __aCB__err ) goto  __result_unhandled_error ;
 if( __aCB__err ) goto  __result_unhandled_error ;
 __bCB = "map" ;
 __cCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __cCB____state ) ;
 __cCB____state -> name = __bCB ;
 __cCB____task = __smolambda_add_task ( std_test__819 , __cCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __cCB____task ) ;
 if( __cCB__err ) goto  __result_unhandled_error ;
 if( __cCB__err ) goto  __result_unhandled_error ;
 __dCB = "nom" ;
 __eCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __eCB____state ) ;
 __eCB____state -> name = __dCB ;
 __eCB____task = __smolambda_add_task ( std_test__819 , __eCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __eCB____task ) ;
 if( __eCB__err ) goto  __result_unhandled_error ;
 if( __eCB__err ) goto  __result_unhandled_error ;
 __fCB = "unsafe" ;
 __gCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __gCB____state ) ;
 __gCB____state -> name = __fCB ;
 __gCB____task = __smolambda_add_task ( std_test__819 , __gCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __gCB____task ) ;
 if( __gCB__err ) goto  __result_unhandled_error ;
 if( __gCB__err ) goto  __result_unhandled_error ;
 __hCB = "mem" ;
 __iCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __iCB____state ) ;
 __iCB____state -> name = __hCB ;
 __iCB____task = __smolambda_add_task ( std_test__819 , __iCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __iCB____task ) ;
 if( __iCB__err ) goto  __result_unhandled_error ;
 if( __iCB__err ) goto  __result_unhandled_error ;
 __jCB = "memtest" ;
 __kCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __kCB____state ) ;
 __kCB____state -> name = __jCB ;
 __kCB____task = __smolambda_add_task ( std_test__819 , __kCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __kCB____task ) ;
 if( __kCB__err ) goto  __result_unhandled_error ;
 if( __kCB__err ) goto  __result_unhandled_error ;
 __lCB = "mutpoint" ;
 __mCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __mCB____state ) ;
 __mCB____state -> name = __lCB ;
 __mCB____task = __smolambda_add_task ( std_test__819 , __mCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __mCB____task ) ;
 if( __mCB__err ) goto  __result_unhandled_error ;
 if( __mCB__err ) goto  __result_unhandled_error ;
 __nCB = "range_test" ;
 __oCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __oCB____state ) ;
 __oCB____state -> name = __nCB ;
 __oCB____task = __smolambda_add_task ( std_test__819 , __oCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __oCB____task ) ;
 if( __oCB__err ) goto  __result_unhandled_error ;
 if( __oCB__err ) goto  __result_unhandled_error ;
 __pCB = "ref" ;
 __qCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __qCB____state ) ;
 __qCB____state -> name = __pCB ;
 __qCB____task = __smolambda_add_task ( std_test__819 , __qCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __qCB____task ) ;
 if( __qCB__err ) goto  __result_unhandled_error ;
 if( __qCB__err ) goto  __result_unhandled_error ;
 __rCB = "strcat" ;
 __sCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __sCB____state ) ;
 __sCB____state -> name = __rCB ;
 __sCB____task = __smolambda_add_task ( std_test__819 , __sCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __sCB____task ) ;
 if( __sCB__err ) goto  __result_unhandled_error ;
 if( __sCB__err ) goto  __result_unhandled_error ;
 __tCB = "vec" ;
 __uCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __uCB____state ) ;
 __uCB____state -> name = __tCB ;
 __uCB____task = __smolambda_add_task ( std_test__819 , __uCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __uCB____task ) ;
 if( __uCB__err ) goto  __result_unhandled_error ;
 if( __uCB__err ) goto  __result_unhandled_error ;
 __vCB = "virtfile" ;
 __wCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __wCB____state ) ;
 __wCB____state -> name = __vCB ;
 __wCB____task = __smolambda_add_task ( std_test__819 , __wCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __wCB____task ) ;
 if( __wCB__err ) goto  __result_unhandled_error ;
 if( __wCB__err ) goto  __result_unhandled_error ;
 __xCB = "accessvar" ;
 __yCB____state = (struct std_test__819__state*)__runtime_calloc(sizeof(struct std_test__819__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __yCB____state ) ;
 __yCB____state -> name = __xCB ;
 __yCB____task = __smolambda_add_task ( std_test__819 , __yCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __yCB____task ) ;
 if( __yCB__err ) goto  __result_unhandled_error ;
 if( __yCB__err ) goto  __result_unhandled_error ;
 __end :
goto __return;

// ERROR HANDLING
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


void std_test__821(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__821__state *__state=(struct std_test__821__state*)__void__state;
struct run__817__state* __5BB____state = 0 ;
ptr name__contents= __state->name__contents;
u64 name__length= __state->name__length;
char name__first= __state->name__first;
ptr name__memory= __state->name__memory;
nominal __GCB____1h__self____TQ=0;
char __GCB____1h____wQ____CF=0;
char __GCB____1h____uQ=0;
bool __GCB____1h____nQ__x=0;
char __GCB____1h____gQ=0;
ptr __GCB____1h__mem=0;
bool __GCB____1h__success=0;
cstr __GCB____1h____kQ=0;
bool __GCB____1h____jQ__z=0;
u64 __GCB____xh=0;
char __GCB__first=0;
u64 __GCB__total_len=0;
u64 __GCB__len_y=0;
u64 __GCB__len_x=0;
ptr __GCB____vh____m__contents=0;
u64 __GCB____vh__length=0;
char __FCB____Vd____wQ____CF=0;
bool __FCB____Vd____nQ__z=0;
bool __FCB____Vd____nQ__x=0;
char __FCB____Vd____gQ=0;
ptr __FCB____Vd__mem=0;
bool __FCB____Vd____iQ=0;
u64 __FCB____Rd=0;
char __FCB__first=0;
u64 __FCB__total_len=0;
u64 __FCB__len_y=0;
ptr __FCB____Qd__noptr=0;
char __FCB____Qd__first=0;
u64 __FCB____Qd__length=0;
ptr __BCB____4h__contents=0;
char __BCB____1h____wQ____CF=0;
bool __BCB____1h____nQ__x=0;
ptr __BCB____1h__mem=0;
ptr __BCB____1h__next_acquired=0;
u64 __FCB____Vd__next_size=0;
char __GCB____vh__first=0;
ptr __FCB____Yd__contents=0;
bool __BCB____1h____jQ__z=0;
u64 __BCB____yh__z=0;
u64 __BCB__len_x=0;
bool __BCB____1h____iQ=0;
u64 __BCB__len_y=0;
ptr __BCB____vh__contents=0;
nominal __ACB____Vd__self____TQ=0;
nominal __2BB____TQ=0;
char __ACB____Vd____uQ=0;
ptr __GCB____vh__noptr=0;
bool __BCB____1h__success=0;
cstr __ACB____Vd____oQ=0;
char __ACB____Vd____gQ=0;
u64 __ACB____Vd__self__allocated__prev=0;
char __FCB____Vd____uQ=0;
bool __ACB____Vd__success=0;
ptr __FCB____Vd__next_acquired=0;
bool __ACB____Vd____jQ__z=0;
char __ACB____Td=0;
bool __ACB____Vd____iQ=0;
u64 __ACB____Rd=0;
u64 __ACB__len_y=0;
ptr __ACB____Qd____m__contents=0;
char __ACB____Qd__first=0;
ptr __ACB____Qd__contents=0;
cstr __9BB=0;
ptr __FCB____Qd__contents=0;
errcode __5BB__err=0;
ptr __5BB____task=0;
ptr command__memory=0;
bool __FCB____Vd____jQ__z=0;
ptr command__contents=0;
nominal command____c=0;
u64 __2BB__allocated=0;
u64 __2BB____ZQ____VQ=0;
ptr __2BB____ZQ__acquired=0;
ptr __zBB____4h__contents=0;
cstr __zBB____1h____oQ=0;
bool __zBB____1h____nQ__z=0;
bool __zBB____1h____nQ__x=0;
u64 __zBB____1h__self__allocated__prev=0;
u64 __2BB____dynamic_entry=0;
u64 __zBB____1h__next_size=0;
char __FCB____Td=0;
bool __zBB____1h____iQ=0;
char __zBB____zh=0;
u64 __zBB____yh__z=0;
u64 __zBB____xh=0;
bool __GCB____1h____nQ__z=0;
u64 __zBB__total_len=0;
u64 __zBB__len_y=0;
ptr __zBB____vh__noptr=0;
cstr __BCB____1h____kQ=0;
u64 __zBB____vh__length=0;
ptr __yBB____Kk__contents=0;
char __yBB____Hk____wQ____CF=0;
char __BCB____vh__first=0;
u64 __BCB____xh=0;
bool __yBB____Hk____nQ__z=0;
char __yBB____Hk____gQ=0;
ptr __yBB____Hk__mem=0;
ptr __yBB____Hk__next_acquired=0;
u64 __yBB____Hk__self__allocated__prev=0;
u64 __yBB____Hk__next_size=0;
u64 __GCB____1h__self__allocated__prev=0;
ptr __ACB____Vd__mem=0;
cstr __yBB____Hk____kQ=0;
bool __GCB____1h____iQ=0;
bool __yBB____Hk____jQ__z=0;
bool __zBB____1h__success=0;
ptr __zBB____1h__mem=0;
char __BCB____zh=0;
nominal __yBB____Hk__self____TQ=0;
bool __yBB____Hk____nQ__x=0;
u64 __2BB__size=0;
u64 __ACB____Qd__length=0;
nominal __tBB____TQ=0;
char __ACB____Vd____wQ____CF=0;
u64 __yBB____Hk____wQ__bytesize=0;
bool __xBB____Fb____nQ__x=0;
u64 __FCB__len_x=0;
ptr __BCB____vh__noptr=0;
u64 __BCB__total_len=0;
u64 __BCB____vh__length=0;
u64 __ACB____Sd__z=0;
u64 __ACB__len_x=0;
char __yBB____Hk____uQ=0;
char __xBB____9a__first=0;
char __xBB____Fb____gQ=0;
char __yBB__first=0;
cstr __8BB=0;
u64 __ACB____Vd__next_size=0;
bool __yBB____Hk__success=0;
bool __yBB____Hk____iQ=0;
ptr __tBB____ZQ__acquired=0;
ptr __FCB____Qd____m__contents=0;
u64 __zBB____1h____wQ__bytesize=0;
char __zBB____vh__first=0;
ptr __tBB__acquired=0;
char __BCB____1h____gQ=0;
bool __BCB____1h____nQ__z=0;
char __zBB__first=0;
bool __FCB____Vd__success=0;
char __zBB____1h____uQ=0;
cstr __FCB____Vd____kQ=0;
cstr __yBB____Hk____oQ=0;
u64 __ACB__total_len=0;
bool __xBB____Fb____nQ__z=0;
bool __ACB____Vd____nQ__z=0;
ptr __ACB____Yd__contents=0;
char __GCB____zh=0;
u64 __yBB__total_len=0;
char command__first=0;
u64 __GCB____1h__next_size=0;
u64 __xBB__len_y=0;
u64 __2BB____ZQ____UQ=0;
nominal __zBB____1h__self____TQ=0;
u64 __FCB____Sd__z=0;
u64 __xBB____9a__length=0;
cstr __ACB____Vd____kQ=0;
ptr __zBB____vh____m__contents=0;
ptr __xBB____9a__contents=0;
u64 __xBB____Fb____wQ__bytesize=0;
char __yBB____Fk=0;
u64 __BCB____1h__next_size=0;
u64 command__length=0;
ptr __GCB____4h__contents=0;
nominal __BCB____1h__self____TQ=0;
nominal __FCB____Vd__self____TQ=0;
char __ACB__first=0;
u64 __2BB____ZQ____dynamic_entry=0;
u64 __BCB____1h__self__allocated__prev=0;
bool __xBB____Fb____jQ__z=0;
bool __ACB____Vd____nQ__x=0;
u64 __zBB__len_x=0;
ptr __xBB____Ib__contents=0;
ptr __ACB____Qd__noptr=0;
bool __zBB____1h____jQ__z=0;
ptr __xBB____Fb__mem=0;
cstr __DCB=0;
char __BCB__first=0;
cstr __ECB=0;
cstr __zBB____1h____kQ=0;
ptr __BCB____vh____m__contents=0;
cstr __BCB____1h____oQ=0;
u64 __GCB____1h____wQ__bytesize=0;
cstr __FCB____Vd____oQ=0;
cstr __GCB____1h____oQ=0;
cstr __qBB=0;
bool __xBB____Fb____iQ=0;
bool __7BB=0;
u64 __xBB____Fb__self__allocated__prev=0;
char __xBB____Db=0;
u64 __ACB____Vd____wQ__bytesize=0;
errcode err=0;
ptr __GCB____1h__next_acquired=0;
u64 __xBB__len_x=0;
ptr __xBB____9a__noptr=0;
ptr __xBB____Ab__contents=0;
u64 __yBB__len_y=0;
u64 __yBB____Dk=0;
u64 __yBB__len_x=0;
u64 __FCB____Vd__self__allocated__prev=0;
char __zBB____1h____gQ=0;
ptr __xBB____Ab__noptr=0;
u64 __FCB____Vd____wQ__bytesize=0;
u64 __tBB__allocated=0;
ptr __2BB__acquired=0;
nominal name____c=0;
u64 __tBB____ZQ____UQ=0;
u64 __tBB____ZQ____VQ=0;
ptr __GCB____vh__contents=0;
u64 __tBB__size=0;
u64 __tBB____ZQ____dynamic_entry=0;
u64 __tBB____dynamic_entry=0;
char __zBB____1h____wQ____CF=0;
cstr __vBB=0;
cstr __wBB=0;
ptr __xBB____9a____m__contents=0;
u64 __GCB____yh__z=0;
ptr __ACB____Vd__next_acquired=0;
u64 __xBB____Ab__length=0;
char __xBB____Ab__first=0;
ptr __xBB____Ab____m__contents=0;
u64 __xBB__total_len=0;
u64 __BCB____1h____wQ__bytesize=0;
char __xBB__first=0;
u64 __xBB____Bb=0;
u64 __xBB____Cb__z=0;
cstr __xBB____Fb____kQ=0;
u64 __xBB____Fb__next_size=0;
char __BCB____1h____uQ=0;
bool __xBB____Fb__success=0;
ptr __zBB____vh__contents=0;
ptr __xBB____Fb__next_acquired=0;
cstr __xBB____Fb____oQ=0;
char __xBB____Fb____uQ=0;
char __xBB____Fb____wQ____CF=0;
nominal __xBB____Fb__self____TQ=0;
ptr __zBB____1h__next_acquired=0;
u64 __yBB____Ek__z=0;

// IMPLEMENTATION
__qBB = " 2>&1" ;
 __tBB____ZQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __tBB____ZQ__acquired )(( ptr **) __tBB____ZQ__acquired )[0]=0; 
 __tBB____ZQ____UQ = 0 ;
 __tBB____ZQ____VQ = 0 ;
 __tBB__acquired = __tBB____ZQ__acquired ;
 __tBB__size = __tBB____ZQ____UQ ;
 __tBB__allocated = __tBB____ZQ____VQ ;
 __tBB____dynamic_entry = __tBB____ZQ____dynamic_entry ;
 __vBB = "./smol tests/unit/" ;
 __wBB = ".s --runtime eager" ;
 __xBB____9a__length = strlen ( __wBB ); __xBB____9a__contents =( ptr ) __wBB ; __xBB____9a__first = __wBB [0]; __xBB____9a__noptr =( ptr ) __xBB____9a__noptr ; 
 __xBB____9a____m__contents = __xBB____9a__contents ;
 __xBB____Ab__length = strlen ( __qBB ); __xBB____Ab__contents =( ptr ) __qBB ; __xBB____Ab__first = __qBB [0]; __xBB____Ab__noptr =( ptr ) __xBB____Ab__noptr ; 
 __xBB____Ab____m__contents = __xBB____Ab__contents ;
 __xBB__len_x = __xBB____9a__length ; __xBB__len_y = __xBB____Ab__length ; __xBB__total_len = __xBB__len_x + __xBB__len_y ; __xBB__first = __xBB____9a__length ? __xBB____9a__first : __xBB____Ab__first ; 
 __xBB____Bb = 1 ;
 __xBB____Cb__z = __xBB__total_len + __xBB____Bb ; 
 __xBB____Cb____end :
 __xBB____Db = 0 ;
 __xBB____Fb____iQ = __tBB__acquired ;
 __xBB____Fb____jQ__z =(! __xBB____Fb____iQ ); 
 __xBB____Fb____jQ____end :
 if(! __xBB____Fb____jQ__z )goto __xBB____Fb____hQ__fi ;
 __xBB____Fb____kQ = "Did not initialize Dynamic" ;
 goto __xBB____Fb____lQ____oD ;
 __builtin_unreachable();
 __xBB____Fb____hQ__fi :
 __xBB____Fb__next_size = __tBB__size +1; __xBB____Fb__success = true ; __xBB____Fb__self__allocated__prev = __tBB__allocated ; if ( __xBB____Fb__next_size >= __tBB__allocated ) { __tBB__allocated = __tBB__allocated + __tBB__allocated /2+1; __xBB____Fb__next_acquired =( ptr )((( ptr **) __tBB__acquired )[0]? __runtime_realloc ((( ptr **) __tBB__acquired )[0], __tBB__allocated * sizeof ( ptr ), __xBB____Fb__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __tBB__allocated * sizeof ( ptr ))); if ( __xBB____Fb__success = __xBB____Fb__next_acquired )(( ptr **) __tBB__acquired )[0]=( ptr *) __xBB____Fb__next_acquired ; } if ( __xBB____Fb__success ) { __xBB____Fb__mem =( ptr ) __runtime_alloc ( __xBB____Cb__z * sizeof ( __xBB____Fb____gQ )); if ( __xBB____Fb__success = __xBB____Fb__mem ) {(( ptr **) __tBB__acquired )[0][ __tBB__size ]= __xBB____Fb__mem ; __tBB__size = __xBB____Fb__next_size ; } } 
 __xBB____Fb____nQ__x = __xBB____Fb__success ;
 __xBB____Fb____nQ__z =(! __xBB____Fb____nQ__x ); 
 __xBB____Fb____nQ____end :
 if(! __xBB____Fb____nQ__z )goto __xBB____Fb____mQ__fi ;
 __xBB____Fb____oQ = "Failed a Dynamic allocation" ;
 goto __xBB____Fb____pQ____oD ;
 __builtin_unreachable();
 __xBB____Fb____mQ__fi :
 __xBB____Fb____uQ = 0 ;
 __xBB____Fb____wQ__bytesize = sizeof ( __xBB____Fb____wQ____CF )* __xBB____Cb__z ; 
 __xBB____Fb____wQ____end :
 memcpy (( char *) __xBB____Fb__mem ,( char *) __xBB____9a____m__contents , __xBB__len_x ); memcpy (( char *) __xBB____Fb__mem + __xBB__len_x ,( char *) __xBB____Ab____m__contents , __xBB__len_y );(( char *) __xBB____Fb__mem )[ __xBB__total_len ]=0; 
 __xBB____Ib__contents = __xBB____Fb__mem ;
 __tBB____TQ = __xBB____Fb__self____TQ ;
 __tBB__acquired = __tBB__acquired ;
 __tBB__size = __tBB__size ;
 __tBB__allocated = __tBB__allocated ;
 __tBB____dynamic_entry = __tBB____dynamic_entry ;
 __yBB__len_x = name__length ; __yBB__len_y = __xBB__total_len ; __yBB__total_len = __yBB__len_x + __yBB__len_y ; __yBB__first = name__length ? name__first : __xBB__first ; 
 __yBB____Dk = 1 ;
 __yBB____Ek__z = __yBB__total_len + __yBB____Dk ; 
 __yBB____Ek____end :
 __yBB____Fk = 0 ;
 __yBB____Hk____iQ = __tBB__acquired ;
 __yBB____Hk____jQ__z =(! __yBB____Hk____iQ ); 
 __yBB____Hk____jQ____end :
 if(! __yBB____Hk____jQ__z )goto __yBB____Hk____hQ__fi ;
 __yBB____Hk____kQ = "Did not initialize Dynamic" ;
 goto __yBB____Hk____lQ____oD ;
 __builtin_unreachable();
 __yBB____Hk____hQ__fi :
 __yBB____Hk__next_size = __tBB__size +1; __yBB____Hk__success = true ; __yBB____Hk__self__allocated__prev = __tBB__allocated ; if ( __yBB____Hk__next_size >= __tBB__allocated ) { __tBB__allocated = __tBB__allocated + __tBB__allocated /2+1; __yBB____Hk__next_acquired =( ptr )((( ptr **) __tBB__acquired )[0]? __runtime_realloc ((( ptr **) __tBB__acquired )[0], __tBB__allocated * sizeof ( ptr ), __yBB____Hk__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __tBB__allocated * sizeof ( ptr ))); if ( __yBB____Hk__success = __yBB____Hk__next_acquired )(( ptr **) __tBB__acquired )[0]=( ptr *) __yBB____Hk__next_acquired ; } if ( __yBB____Hk__success ) { __yBB____Hk__mem =( ptr ) __runtime_alloc ( __yBB____Ek__z * sizeof ( __yBB____Hk____gQ )); if ( __yBB____Hk__success = __yBB____Hk__mem ) {(( ptr **) __tBB__acquired )[0][ __tBB__size ]= __yBB____Hk__mem ; __tBB__size = __yBB____Hk__next_size ; } } 
 __yBB____Hk____nQ__x = __yBB____Hk__success ;
 __yBB____Hk____nQ__z =(! __yBB____Hk____nQ__x ); 
 __yBB____Hk____nQ____end :
 if(! __yBB____Hk____nQ__z )goto __yBB____Hk____mQ__fi ;
 __yBB____Hk____oQ = "Failed a Dynamic allocation" ;
 goto __yBB____Hk____pQ____oD ;
 __builtin_unreachable();
 __yBB____Hk____mQ__fi :
 __yBB____Hk____uQ = 0 ;
 __yBB____Hk____wQ__bytesize = sizeof ( __yBB____Hk____wQ____CF )* __yBB____Ek__z ; 
 __yBB____Hk____wQ____end :
 memcpy (( char *) __yBB____Hk__mem ,( char *) name__contents , __yBB__len_x ); memcpy (( char *) __yBB____Hk__mem + __yBB__len_x ,( char *) __xBB____Ib__contents , __yBB__len_y );(( char *) __yBB____Hk__mem )[ __yBB__total_len ]=0; 
 __yBB____Kk__contents = __yBB____Hk__mem ;
 __tBB____TQ = __yBB____Hk__self____TQ ;
 __tBB__acquired = __tBB__acquired ;
 __tBB__size = __tBB__size ;
 __tBB__allocated = __tBB__allocated ;
 __tBB____dynamic_entry = __tBB____dynamic_entry ;
 __zBB____vh__length = strlen ( __vBB ); __zBB____vh__contents =( ptr ) __vBB ; __zBB____vh__first = __vBB [0]; __zBB____vh__noptr =( ptr ) __zBB____vh__noptr ; 
 __zBB____vh____m__contents = __zBB____vh__contents ;
 __zBB__len_x = __zBB____vh__length ; __zBB__len_y = __yBB__total_len ; __zBB__total_len = __zBB__len_x + __zBB__len_y ; __zBB__first = __zBB____vh__length ? __zBB____vh__first : __yBB__first ; 
 __zBB____xh = 1 ;
 __zBB____yh__z = __zBB__total_len + __zBB____xh ; 
 __zBB____yh____end :
 __zBB____zh = 0 ;
 __zBB____1h____iQ = __tBB__acquired ;
 __zBB____1h____jQ__z =(! __zBB____1h____iQ ); 
 __zBB____1h____jQ____end :
 if(! __zBB____1h____jQ__z )goto __zBB____1h____hQ__fi ;
 __zBB____1h____kQ = "Did not initialize Dynamic" ;
 goto __zBB____1h____lQ____oD ;
 __builtin_unreachable();
 __zBB____1h____hQ__fi :
 __zBB____1h__next_size = __tBB__size +1; __zBB____1h__success = true ; __zBB____1h__self__allocated__prev = __tBB__allocated ; if ( __zBB____1h__next_size >= __tBB__allocated ) { __tBB__allocated = __tBB__allocated + __tBB__allocated /2+1; __zBB____1h__next_acquired =( ptr )((( ptr **) __tBB__acquired )[0]? __runtime_realloc ((( ptr **) __tBB__acquired )[0], __tBB__allocated * sizeof ( ptr ), __zBB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __tBB__allocated * sizeof ( ptr ))); if ( __zBB____1h__success = __zBB____1h__next_acquired )(( ptr **) __tBB__acquired )[0]=( ptr *) __zBB____1h__next_acquired ; } if ( __zBB____1h__success ) { __zBB____1h__mem =( ptr ) __runtime_alloc ( __zBB____yh__z * sizeof ( __zBB____1h____gQ )); if ( __zBB____1h__success = __zBB____1h__mem ) {(( ptr **) __tBB__acquired )[0][ __tBB__size ]= __zBB____1h__mem ; __tBB__size = __zBB____1h__next_size ; } } 
 __zBB____1h____nQ__x = __zBB____1h__success ;
 __zBB____1h____nQ__z =(! __zBB____1h____nQ__x ); 
 __zBB____1h____nQ____end :
 if(! __zBB____1h____nQ__z )goto __zBB____1h____mQ__fi ;
 __zBB____1h____oQ = "Failed a Dynamic allocation" ;
 goto __zBB____1h____pQ____oD ;
 __builtin_unreachable();
 __zBB____1h____mQ__fi :
 __zBB____1h____uQ = 0 ;
 __zBB____1h____wQ__bytesize = sizeof ( __zBB____1h____wQ____CF )* __zBB____yh__z ; 
 __zBB____1h____wQ____end :
 memcpy (( char *) __zBB____1h__mem ,( char *) __zBB____vh____m__contents , __zBB__len_x ); memcpy (( char *) __zBB____1h__mem + __zBB__len_x ,( char *) __yBB____Kk__contents , __zBB__len_y );(( char *) __zBB____1h__mem )[ __zBB__total_len ]=0; 
 __zBB____4h__contents = __zBB____1h__mem ;
 __tBB____TQ = __zBB____1h__self____TQ ;
 __tBB__acquired = __tBB__acquired ;
 __tBB__size = __tBB__size ;
 __tBB__allocated = __tBB__allocated ;
 __tBB____dynamic_entry = __tBB____dynamic_entry ;
 __2BB____ZQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __2BB____ZQ__acquired )(( ptr **) __2BB____ZQ__acquired )[0]=0; 
 __2BB____ZQ____UQ = 0 ;
 __2BB____ZQ____VQ = 0 ;
 __2BB__acquired = __2BB____ZQ__acquired ;
 __2BB__size = __2BB____ZQ____UQ ;
 __2BB__allocated = __2BB____ZQ____VQ ;
 __2BB____dynamic_entry = __2BB____ZQ____dynamic_entry ;
 __5BB____state = (struct run__817__state*)__runtime_calloc(sizeof(struct run__817__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __5BB____state ) ;
 __5BB____state -> command____c = command____c ;
 __5BB____state -> command__contents = __zBB____4h__contents ;
 __5BB____state -> command__length = __zBB__total_len ;
 __5BB____state -> command__first = __zBB__first ;
 __5BB____state -> command__memory = __tBB__acquired ;
 __5BB____task = __smolambda_add_task ( run__817 , __5BB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __5BB____task ) ;
 if( __5BB__err ) goto  __result_unhandled_error ;
 if( __5BB__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __5BB____task ) ;
 __5BB__err = __5BB____state -> err ;
 __7BB = __5BB__err ;
 if(! __7BB )goto __4BB__fi ;
 __8BB = "[ \033[31mERROR\033[0m ] " ;
 __9BB = ".s" ;
 __ACB____Qd__length = strlen ( __9BB ); __ACB____Qd__contents =( ptr ) __9BB ; __ACB____Qd__first = __9BB [0]; __ACB____Qd__noptr =( ptr ) __ACB____Qd__noptr ; 
 __ACB____Qd____m__contents = __ACB____Qd__contents ;
 __ACB__len_x = name__length ; __ACB__len_y = __ACB____Qd__length ; __ACB__total_len = __ACB__len_x + __ACB__len_y ; __ACB__first = name__length ? name__first : __ACB____Qd__first ; 
 __ACB____Rd = 1 ;
 __ACB____Sd__z = __ACB__total_len + __ACB____Rd ; 
 __ACB____Sd____end :
 __ACB____Td = 0 ;
 __ACB____Vd____iQ = __2BB__acquired ;
 __ACB____Vd____jQ__z =(! __ACB____Vd____iQ ); 
 __ACB____Vd____jQ____end :
 if(! __ACB____Vd____jQ__z )goto __ACB____Vd____hQ__fi ;
 __ACB____Vd____kQ = "Did not initialize Dynamic" ;
 goto __ACB____Vd____lQ____oD ;
 __builtin_unreachable();
 __ACB____Vd____hQ__fi :
 __ACB____Vd__next_size = __2BB__size +1; __ACB____Vd__success = true ; __ACB____Vd__self__allocated__prev = __2BB__allocated ; if ( __ACB____Vd__next_size >= __2BB__allocated ) { __2BB__allocated = __2BB__allocated + __2BB__allocated /2+1; __ACB____Vd__next_acquired =( ptr )((( ptr **) __2BB__acquired )[0]? __runtime_realloc ((( ptr **) __2BB__acquired )[0], __2BB__allocated * sizeof ( ptr ), __ACB____Vd__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __2BB__allocated * sizeof ( ptr ))); if ( __ACB____Vd__success = __ACB____Vd__next_acquired )(( ptr **) __2BB__acquired )[0]=( ptr *) __ACB____Vd__next_acquired ; } if ( __ACB____Vd__success ) { __ACB____Vd__mem =( ptr ) __runtime_alloc ( __ACB____Sd__z * sizeof ( __ACB____Vd____gQ )); if ( __ACB____Vd__success = __ACB____Vd__mem ) {(( ptr **) __2BB__acquired )[0][ __2BB__size ]= __ACB____Vd__mem ; __2BB__size = __ACB____Vd__next_size ; } } 
 __ACB____Vd____nQ__x = __ACB____Vd__success ;
 __ACB____Vd____nQ__z =(! __ACB____Vd____nQ__x ); 
 __ACB____Vd____nQ____end :
 if(! __ACB____Vd____nQ__z )goto __ACB____Vd____mQ__fi ;
 __ACB____Vd____oQ = "Failed a Dynamic allocation" ;
 goto __ACB____Vd____pQ____oD ;
 __builtin_unreachable();
 __ACB____Vd____mQ__fi :
 __ACB____Vd____uQ = 0 ;
 __ACB____Vd____wQ__bytesize = sizeof ( __ACB____Vd____wQ____CF )* __ACB____Sd__z ; 
 __ACB____Vd____wQ____end :
 memcpy (( char *) __ACB____Vd__mem ,( char *) name__contents , __ACB__len_x ); memcpy (( char *) __ACB____Vd__mem + __ACB__len_x ,( char *) __ACB____Qd____m__contents , __ACB__len_y );(( char *) __ACB____Vd__mem )[ __ACB__total_len ]=0; 
 __ACB____Yd__contents = __ACB____Vd__mem ;
 __2BB____TQ = __ACB____Vd__self____TQ ;
 __2BB__acquired = __2BB__acquired ;
 __2BB__size = __2BB__size ;
 __2BB__allocated = __2BB__allocated ;
 __2BB____dynamic_entry = __2BB____dynamic_entry ;
 __BCB____vh__length = strlen ( __8BB ); __BCB____vh__contents =( ptr ) __8BB ; __BCB____vh__first = __8BB [0]; __BCB____vh__noptr =( ptr ) __BCB____vh__noptr ; 
 __BCB____vh____m__contents = __BCB____vh__contents ;
 __BCB__len_x = __BCB____vh__length ; __BCB__len_y = __ACB__total_len ; __BCB__total_len = __BCB__len_x + __BCB__len_y ; __BCB__first = __BCB____vh__length ? __BCB____vh__first : __ACB__first ; 
 __BCB____xh = 1 ;
 __BCB____yh__z = __BCB__total_len + __BCB____xh ; 
 __BCB____yh____end :
 __BCB____zh = 0 ;
 __BCB____1h____iQ = __2BB__acquired ;
 __BCB____1h____jQ__z =(! __BCB____1h____iQ ); 
 __BCB____1h____jQ____end :
 if(! __BCB____1h____jQ__z )goto __BCB____1h____hQ__fi ;
 __BCB____1h____kQ = "Did not initialize Dynamic" ;
 goto __BCB____1h____lQ____oD ;
 __builtin_unreachable();
 __BCB____1h____hQ__fi :
 __BCB____1h__next_size = __2BB__size +1; __BCB____1h__success = true ; __BCB____1h__self__allocated__prev = __2BB__allocated ; if ( __BCB____1h__next_size >= __2BB__allocated ) { __2BB__allocated = __2BB__allocated + __2BB__allocated /2+1; __BCB____1h__next_acquired =( ptr )((( ptr **) __2BB__acquired )[0]? __runtime_realloc ((( ptr **) __2BB__acquired )[0], __2BB__allocated * sizeof ( ptr ), __BCB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __2BB__allocated * sizeof ( ptr ))); if ( __BCB____1h__success = __BCB____1h__next_acquired )(( ptr **) __2BB__acquired )[0]=( ptr *) __BCB____1h__next_acquired ; } if ( __BCB____1h__success ) { __BCB____1h__mem =( ptr ) __runtime_alloc ( __BCB____yh__z * sizeof ( __BCB____1h____gQ )); if ( __BCB____1h__success = __BCB____1h__mem ) {(( ptr **) __2BB__acquired )[0][ __2BB__size ]= __BCB____1h__mem ; __2BB__size = __BCB____1h__next_size ; } } 
 __BCB____1h____nQ__x = __BCB____1h__success ;
 __BCB____1h____nQ__z =(! __BCB____1h____nQ__x ); 
 __BCB____1h____nQ____end :
 if(! __BCB____1h____nQ__z )goto __BCB____1h____mQ__fi ;
 __BCB____1h____oQ = "Failed a Dynamic allocation" ;
 goto __BCB____1h____pQ____oD ;
 __builtin_unreachable();
 __BCB____1h____mQ__fi :
 __BCB____1h____uQ = 0 ;
 __BCB____1h____wQ__bytesize = sizeof ( __BCB____1h____wQ____CF )* __BCB____yh__z ; 
 __BCB____1h____wQ____end :
 memcpy (( char *) __BCB____1h__mem ,( char *) __BCB____vh____m__contents , __BCB__len_x ); memcpy (( char *) __BCB____1h__mem + __BCB__len_x ,( char *) __ACB____Yd__contents , __BCB__len_y );(( char *) __BCB____1h__mem )[ __BCB__total_len ]=0; 
 __BCB____4h__contents = __BCB____1h__mem ;
 __2BB____TQ = __BCB____1h__self____TQ ;
 __2BB__acquired = __2BB__acquired ;
 __2BB__size = __2BB__size ;
 __2BB__allocated = __2BB__allocated ;
 __2BB____dynamic_entry = __2BB____dynamic_entry ;
 printf ( "%s\n" ,( char *) __BCB____4h__contents ); 
 __CCB____end :
 goto __4BB__el ;
 __4BB__fi :
 __DCB = "[ \033[32mOK\033[0m ] " ;
 __ECB = ".s" ;
 __FCB____Qd__length = strlen ( __ECB ); __FCB____Qd__contents =( ptr ) __ECB ; __FCB____Qd__first = __ECB [0]; __FCB____Qd__noptr =( ptr ) __FCB____Qd__noptr ; 
 __FCB____Qd____m__contents = __FCB____Qd__contents ;
 __FCB__len_x = name__length ; __FCB__len_y = __FCB____Qd__length ; __FCB__total_len = __FCB__len_x + __FCB__len_y ; __FCB__first = name__length ? name__first : __FCB____Qd__first ; 
 __FCB____Rd = 1 ;
 __FCB____Sd__z = __FCB__total_len + __FCB____Rd ; 
 __FCB____Sd____end :
 __FCB____Td = 0 ;
 __FCB____Vd____iQ = __2BB__acquired ;
 __FCB____Vd____jQ__z =(! __FCB____Vd____iQ ); 
 __FCB____Vd____jQ____end :
 if(! __FCB____Vd____jQ__z )goto __FCB____Vd____hQ__fi ;
 __FCB____Vd____kQ = "Did not initialize Dynamic" ;
 goto __FCB____Vd____lQ____oD ;
 __builtin_unreachable();
 __FCB____Vd____hQ__fi :
 __FCB____Vd__next_size = __2BB__size +1; __FCB____Vd__success = true ; __FCB____Vd__self__allocated__prev = __2BB__allocated ; if ( __FCB____Vd__next_size >= __2BB__allocated ) { __2BB__allocated = __2BB__allocated + __2BB__allocated /2+1; __FCB____Vd__next_acquired =( ptr )((( ptr **) __2BB__acquired )[0]? __runtime_realloc ((( ptr **) __2BB__acquired )[0], __2BB__allocated * sizeof ( ptr ), __FCB____Vd__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __2BB__allocated * sizeof ( ptr ))); if ( __FCB____Vd__success = __FCB____Vd__next_acquired )(( ptr **) __2BB__acquired )[0]=( ptr *) __FCB____Vd__next_acquired ; } if ( __FCB____Vd__success ) { __FCB____Vd__mem =( ptr ) __runtime_alloc ( __FCB____Sd__z * sizeof ( __FCB____Vd____gQ )); if ( __FCB____Vd__success = __FCB____Vd__mem ) {(( ptr **) __2BB__acquired )[0][ __2BB__size ]= __FCB____Vd__mem ; __2BB__size = __FCB____Vd__next_size ; } } 
 __FCB____Vd____nQ__x = __FCB____Vd__success ;
 __FCB____Vd____nQ__z =(! __FCB____Vd____nQ__x ); 
 __FCB____Vd____nQ____end :
 if(! __FCB____Vd____nQ__z )goto __FCB____Vd____mQ__fi ;
 __FCB____Vd____oQ = "Failed a Dynamic allocation" ;
 goto __FCB____Vd____pQ____oD ;
 __builtin_unreachable();
 __FCB____Vd____mQ__fi :
 __FCB____Vd____uQ = 0 ;
 __FCB____Vd____wQ__bytesize = sizeof ( __FCB____Vd____wQ____CF )* __FCB____Sd__z ; 
 __FCB____Vd____wQ____end :
 memcpy (( char *) __FCB____Vd__mem ,( char *) name__contents , __FCB__len_x ); memcpy (( char *) __FCB____Vd__mem + __FCB__len_x ,( char *) __FCB____Qd____m__contents , __FCB__len_y );(( char *) __FCB____Vd__mem )[ __FCB__total_len ]=0; 
 __FCB____Yd__contents = __FCB____Vd__mem ;
 __2BB____TQ = __FCB____Vd__self____TQ ;
 __2BB__acquired = __2BB__acquired ;
 __2BB__size = __2BB__size ;
 __2BB__allocated = __2BB__allocated ;
 __2BB____dynamic_entry = __2BB____dynamic_entry ;
 __GCB____vh__length = strlen ( __DCB ); __GCB____vh__contents =( ptr ) __DCB ; __GCB____vh__first = __DCB [0]; __GCB____vh__noptr =( ptr ) __GCB____vh__noptr ; 
 __GCB____vh____m__contents = __GCB____vh__contents ;
 __GCB__len_x = __GCB____vh__length ; __GCB__len_y = __FCB__total_len ; __GCB__total_len = __GCB__len_x + __GCB__len_y ; __GCB__first = __GCB____vh__length ? __GCB____vh__first : __FCB__first ; 
 __GCB____xh = 1 ;
 __GCB____yh__z = __GCB__total_len + __GCB____xh ; 
 __GCB____yh____end :
 __GCB____zh = 0 ;
 __GCB____1h____iQ = __2BB__acquired ;
 __GCB____1h____jQ__z =(! __GCB____1h____iQ ); 
 __GCB____1h____jQ____end :
 if(! __GCB____1h____jQ__z )goto __GCB____1h____hQ__fi ;
 __GCB____1h____kQ = "Did not initialize Dynamic" ;
 goto __GCB____1h____lQ____oD ;
 __builtin_unreachable();
 __GCB____1h____hQ__fi :
 __GCB____1h__next_size = __2BB__size +1; __GCB____1h__success = true ; __GCB____1h__self__allocated__prev = __2BB__allocated ; if ( __GCB____1h__next_size >= __2BB__allocated ) { __2BB__allocated = __2BB__allocated + __2BB__allocated /2+1; __GCB____1h__next_acquired =( ptr )((( ptr **) __2BB__acquired )[0]? __runtime_realloc ((( ptr **) __2BB__acquired )[0], __2BB__allocated * sizeof ( ptr ), __GCB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __2BB__allocated * sizeof ( ptr ))); if ( __GCB____1h__success = __GCB____1h__next_acquired )(( ptr **) __2BB__acquired )[0]=( ptr *) __GCB____1h__next_acquired ; } if ( __GCB____1h__success ) { __GCB____1h__mem =( ptr ) __runtime_alloc ( __GCB____yh__z * sizeof ( __GCB____1h____gQ )); if ( __GCB____1h__success = __GCB____1h__mem ) {(( ptr **) __2BB__acquired )[0][ __2BB__size ]= __GCB____1h__mem ; __2BB__size = __GCB____1h__next_size ; } } 
 __GCB____1h____nQ__x = __GCB____1h__success ;
 __GCB____1h____nQ__z =(! __GCB____1h____nQ__x ); 
 __GCB____1h____nQ____end :
 if(! __GCB____1h____nQ__z )goto __GCB____1h____mQ__fi ;
 __GCB____1h____oQ = "Failed a Dynamic allocation" ;
 goto __GCB____1h____pQ____oD ;
 __builtin_unreachable();
 __GCB____1h____mQ__fi :
 __GCB____1h____uQ = 0 ;
 __GCB____1h____wQ__bytesize = sizeof ( __GCB____1h____wQ____CF )* __GCB____yh__z ; 
 __GCB____1h____wQ____end :
 memcpy (( char *) __GCB____1h__mem ,( char *) __GCB____vh____m__contents , __GCB__len_x ); memcpy (( char *) __GCB____1h__mem + __GCB__len_x ,( char *) __FCB____Yd__contents , __GCB__len_y );(( char *) __GCB____1h__mem )[ __GCB__total_len ]=0; 
 __GCB____4h__contents = __GCB____1h__mem ;
 __2BB____TQ = __GCB____1h__self____TQ ;
 __2BB__acquired = __2BB__acquired ;
 __2BB__size = __2BB__size ;
 __2BB__allocated = __2BB__allocated ;
 __2BB____dynamic_entry = __2BB____dynamic_entry ;
 printf ( "%s\n" ,( char *) __GCB____4h__contents ); 
 __HCB____end :
 __4BB__el :
 __end :
goto __return;

// ERROR HANDLING
__ACB____Vd____lQ____oD :
 printf ( "%s\n" , __ACB____Vd____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__GCB____1h____pQ____oD :
 printf ( "%s\n" , __GCB____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__FCB____Vd____lQ____oD :
 printf ( "%s\n" , __FCB____Vd____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__BCB____1h____pQ____oD :
 printf ( "%s\n" , __BCB____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__xBB____Fb____lQ____oD :
 printf ( "%s\n" , __xBB____Fb____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__ACB____Vd____pQ____oD :
 printf ( "%s\n" , __ACB____Vd____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__GCB____1h____lQ____oD :
 printf ( "%s\n" , __GCB____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__FCB____Vd____pQ____oD :
 printf ( "%s\n" , __FCB____Vd____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__xBB____Fb____pQ____oD :
 printf ( "%s\n" , __xBB____Fb____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__yBB____Hk____lQ____oD :
 printf ( "%s\n" , __yBB____Hk____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__6BB :
printf("Runtime error from None __5BB \n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
__BCB____1h____lQ____oD :
 printf ( "%s\n" , __BCB____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__yBB____Hk____pQ____oD :
 printf ( "%s\n" , __yBB____Hk____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__zBB____1h____pQ____oD :
 printf ( "%s\n" , __zBB____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__zBB____1h____lQ____oD :
 printf ( "%s\n" , __zBB____1h____kQ ); 
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
if ( __2BB__acquired ) { for ( __2BB____dynamic_entry =0; __2BB____dynamic_entry < __2BB__size ;++ __2BB____dynamic_entry ) { __runtime_free ((( ptr **) __2BB__acquired )[0][ __2BB____dynamic_entry ]); } __runtime_free ( __2BB__acquired ); __2BB__acquired =0; __2BB__size =0; __2BB__allocated =0; } 
 if ( __2BB__acquired ) { for ( __2BB____ZQ____dynamic_entry =0; __2BB____ZQ____dynamic_entry < __2BB____ZQ____UQ ;++ __2BB____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __2BB__acquired )[0][ __2BB____ZQ____dynamic_entry ]); } __runtime_free ( __2BB__acquired ); __2BB__acquired =0; __2BB____ZQ____UQ =0; __2BB____ZQ____VQ =0; } 
if ( __tBB__acquired ) { for ( __tBB____dynamic_entry =0; __tBB____dynamic_entry < __tBB__size ;++ __tBB____dynamic_entry ) { __runtime_free ((( ptr **) __tBB__acquired )[0][ __tBB____dynamic_entry ]); } __runtime_free ( __tBB__acquired ); __tBB__acquired =0; __tBB__size =0; __tBB__allocated =0; } 
 if ( __tBB__acquired ) { for ( __tBB____ZQ____dynamic_entry =0; __tBB____ZQ____dynamic_entry < __tBB____ZQ____UQ ;++ __tBB____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __tBB__acquired )[0][ __tBB____ZQ____dynamic_entry ]); } __runtime_free ( __tBB__acquired ); __tBB__acquired =0; __tBB____ZQ____UQ =0; __tBB____ZQ____VQ =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}


void std_test__820(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__820__state *__state=(struct std_test__820__state*)__void__state;
struct run__817__state* __cBB____state = 0 ;
ptr name__contents= __state->name__contents;
u64 name__length= __state->name__length;
char name__first= __state->name__first;
ptr name__memory= __state->name__memory;
char __nBB____1h____wQ____CF=0;
char __nBB____1h____uQ=0;
ptr __nBB____1h__next_acquired=0;
u64 __nBB____1h__next_size=0;
cstr __nBB____1h____kQ=0;
bool __nBB____1h____iQ=0;
char __nBB____zh=0;
u64 __nBB____yh__z=0;
u64 __nBB____xh=0;
char __nBB__first=0;
u64 __nBB__len_y=0;
u64 __nBB__len_x=0;
ptr __nBB____4h__contents=0;
ptr __nBB____vh__noptr=0;
ptr __nBB____vh__contents=0;
u64 __mBB____Nc____wQ__bytesize=0;
char __mBB____Nc____gQ=0;
u64 __mBB____Nc__next_size=0;
cstr __mBB____Nc____kQ=0;
bool __mBB____Nc____jQ__z=0;
u64 __nBB____1h__self__allocated__prev=0;
char __mBB____Lc=0;
u64 __mBB____Kc__z=0;
u64 __mBB__total_len=0;
u64 __mBB__len_y=0;
ptr __mBB____Ic____m__contents=0;
char __mBB____Ic__first=0;
ptr __mBB____Ic__contents=0;
cstr __kBB=0;
cstr __mBB____Nc____oQ=0;
char __iBB____1h____wQ____CF=0;
char __iBB____1h____uQ=0;
cstr __iBB____1h____oQ=0;
bool __iBB____1h____nQ__x=0;
ptr __iBB____1h__next_acquired=0;
bool __iBB____1h__success=0;
u64 __iBB____1h__next_size=0;
u64 __iBB____1h__self__allocated__prev=0;
cstr __iBB____1h____kQ=0;
bool __iBB____1h____jQ__z=0;
ptr __mBB____Ic__noptr=0;
u64 __iBB____yh__z=0;
u64 __iBB__len_x=0;
ptr __iBB____vh____m__contents=0;
ptr __iBB____vh__contents=0;
u64 __hBB____Nc____wQ__bytesize=0;
bool __hBB____Nc____nQ__z=0;
char __hBB____Nc____gQ=0;
bool __nBB____1h____nQ__x=0;
ptr __hBB____Nc__mem=0;
ptr __hBB____Nc__next_acquired=0;
bool __hBB____Nc__success=0;
u64 __hBB____Nc__next_size=0;
cstr __hBB____Nc____kQ=0;
bool __hBB____Nc____jQ__z=0;
bool __hBB____Nc____iQ=0;
ptr __nBB____1h__mem=0;
char __hBB____Lc=0;
u64 __hBB____Kc__z=0;
u64 __hBB____Jc=0;
char __hBB____Ic__first=0;
ptr __cBB____task=0;
ptr command__memory=0;
char command__first=0;
ptr command__contents=0;
nominal command____c=0;
u64 __ZBB____dynamic_entry=0;
bool __nBB____1h__success=0;
u64 __ZBB__size=0;
ptr __ZBB____ZQ__acquired=0;
ptr __WBB____4h__contents=0;
char __WBB____1h____uQ=0;
bool __WBB____1h____nQ__z=0;
bool __mBB____Nc____iQ=0;
bool __WBB____1h____nQ__x=0;
ptr __WBB____1h__mem=0;
ptr __WBB____1h__next_acquired=0;
ptr __iBB____1h__mem=0;
u64 command__length=0;
bool __WBB____1h__success=0;
u64 __WBB____1h__next_size=0;
cstr __WBB____1h____kQ=0;
u64 __iBB____vh__length=0;
bool __WBB____1h____iQ=0;
char __WBB____zh=0;
u64 __WBB____yh__z=0;
cstr __hBB____Nc____oQ=0;
u64 __WBB__total_len=0;
ptr __WBB____vh____m__contents=0;
ptr __iBB____vh__noptr=0;
cstr __WBB____1h____oQ=0;
char __WBB____vh__first=0;
ptr __mBB____Nc__mem=0;
ptr __WBB____vh__contents=0;
nominal __VBB____9i__self____TQ=0;
u64 __VBB____9i____wQ__bytesize=0;
char __VBB____9i____uQ=0;
cstr __VBB____9i____oQ=0;
bool __VBB____9i____nQ__z=0;
ptr __VBB____9i__mem=0;
ptr __VBB____Cj__contents=0;
u64 __WBB__len_y=0;
bool __iBB____1h____nQ__z=0;
u64 __nBB____vh__length=0;
char __iBB____vh__first=0;
u64 __QBB__size=0;
nominal __nBB____1h__self____TQ=0;
nominal __ZBB____TQ=0;
char __iBB____1h____gQ=0;
cstr __gBB=0;
u64 __WBB____1h__self__allocated__prev=0;
char __mBB____Nc____wQ____CF=0;
u64 __QBB____ZQ____dynamic_entry=0;
u64 __WBB____1h____wQ__bytesize=0;
errcode err=0;
bool __VBB____9i____iQ=0;
cstr __NBB=0;
u64 __QBB____dynamic_entry=0;
char __UBB____Ab__first=0;
u64 __ZBB__allocated=0;
ptr __nBB____vh____m__contents=0;
char __UBB____9a__first=0;
u64 __UBB____Cb__z=0;
nominal name____b=0;
ptr __mBB____Qc__contents=0;
bool __iBB____1h____iQ=0;
char __iBB__first=0;
errcode __cBB__err=0;
ptr __WBB____vh__noptr=0;
ptr __mBB____Nc__next_acquired=0;
u64 __iBB__total_len=0;
char __hBB____Nc____wQ____CF=0;
u64 __UBB__len_y=0;
char __VBB____9i____gQ=0;
u64 __iBB__len_y=0;
u64 __ZBB____ZQ____UQ=0;
ptr __UBB____Ab__contents=0;
bool __mBB____Nc____nQ__z=0;
bool __mBB____Nc__success=0;
char __iBB____zh=0;
u64 __nBB____1h____wQ__bytesize=0;
char __VBB____7i=0;
char __hBB__first=0;
ptr __UBB____Ib__contents=0;
u64 __WBB____xh=0;
u64 __VBB__total_len=0;
cstr __nBB____1h____oQ=0;
u64 __mBB____Ic__length=0;
u64 __hBB__len_y=0;
ptr __UBB____Fb__next_acquired=0;
ptr __hBB____Qc__contents=0;
bool __UBB____Fb____iQ=0;
u64 __mBB____Nc__self__allocated__prev=0;
nominal __iBB____1h__self____TQ=0;
ptr __UBB____9a__noptr=0;
cstr __UBB____Fb____oQ=0;
cstr __fBB=0;
cstr __TBB=0;
char __mBB____Nc____uQ=0;
u64 __ZBB____ZQ____dynamic_entry=0;
bool __nBB____1h____jQ__z=0;
bool __UBB____Fb____nQ__x=0;
u64 __VBB____5i=0;
bool __VBB____9i____jQ__z=0;
bool __VBB____9i____nQ__x=0;
bool __mBB____Nc____nQ__x=0;
ptr __hBB____Ic____m__contents=0;
bool __hBB____Nc____nQ__x=0;
bool __eBB=0;
char __hBB____Nc____uQ=0;
ptr __iBB____4h__contents=0;
u64 __UBB____Ab__length=0;
u64 __UBB__len_x=0;
u64 __hBB__total_len=0;
u64 __WBB__len_x=0;
ptr __UBB____9a__contents=0;
ptr __hBB____Ic__noptr=0;
bool __VBB____9i__success=0;
nominal __hBB____Nc__self____TQ=0;
cstr __SBB=0;
bool __WBB____1h____jQ__z=0;
ptr __UBB____Ab__noptr=0;
char __WBB____1h____gQ=0;
u64 __QBB__allocated=0;
char __UBB____Db=0;
u64 __UBB____Fb____wQ__bytesize=0;
u64 __hBB____Ic__length=0;
u64 __VBB____6i__z=0;
char __UBB____Fb____uQ=0;
u64 __nBB__total_len=0;
u64 __mBB____Jc=0;
u64 __VBB__len_y=0;
ptr __ZBB__acquired=0;
char __nBB____vh__first=0;
ptr __QBB__acquired=0;
cstr __UBB____Fb____kQ=0;
nominal __mBB____Nc__self____TQ=0;
ptr __QBB____ZQ__acquired=0;
u64 __iBB____1h____wQ__bytesize=0;
u64 __QBB____ZQ____UQ=0;
u64 __QBB____ZQ____VQ=0;
u64 __UBB____9a__length=0;
u64 __hBB____Nc__self__allocated__prev=0;
ptr __UBB____9a____m__contents=0;
ptr __UBB____Ab____m__contents=0;
bool __UBB____Fb__success=0;
u64 __iBB____xh=0;
u64 __UBB__total_len=0;
char __UBB__first=0;
u64 __WBB____vh__length=0;
bool __UBB____Fb____jQ__z=0;
u64 __hBB__len_x=0;
u64 __UBB____Fb__next_size=0;
char __mBB__first=0;
u64 __UBB____Fb__self__allocated__prev=0;
u64 __UBB____Bb=0;
ptr __UBB____Fb__mem=0;
char __UBB____Fb____gQ=0;
u64 __VBB__len_x=0;
bool __UBB____Fb____nQ__z=0;
ptr __hBB____Ic__contents=0;
cstr __lBB=0;
char __WBB____1h____wQ____CF=0;
nominal __QBB____TQ=0;
char __nBB____1h____gQ=0;
char __VBB____9i____wQ____CF=0;
u64 __VBB____9i__next_size=0;
nominal __WBB____1h__self____TQ=0;
nominal __UBB____Fb__self____TQ=0;
char __VBB__first=0;
char __UBB____Fb____wQ____CF=0;
char __WBB__first=0;
u64 __mBB__len_x=0;
cstr __VBB____9i____kQ=0;
bool __nBB____1h____nQ__z=0;
u64 __ZBB____ZQ____VQ=0;
u64 __VBB____9i__self__allocated__prev=0;
ptr __VBB____9i__next_acquired=0;

// IMPLEMENTATION
__NBB = " 2>&1" ;
 __QBB____ZQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __QBB____ZQ__acquired )(( ptr **) __QBB____ZQ__acquired )[0]=0; 
 __QBB____ZQ____UQ = 0 ;
 __QBB____ZQ____VQ = 0 ;
 __QBB__acquired = __QBB____ZQ__acquired ;
 __QBB__size = __QBB____ZQ____UQ ;
 __QBB__allocated = __QBB____ZQ____VQ ;
 __QBB____dynamic_entry = __QBB____ZQ____dynamic_entry ;
 __SBB = "./smol tests/unit/" ;
 __TBB = ".s --runtime eager" ;
 __UBB____9a__length = strlen ( __TBB ); __UBB____9a__contents =( ptr ) __TBB ; __UBB____9a__first = __TBB [0]; __UBB____9a__noptr =( ptr ) __UBB____9a__noptr ; 
 __UBB____9a____m__contents = __UBB____9a__contents ;
 __UBB____Ab__length = strlen ( __NBB ); __UBB____Ab__contents =( ptr ) __NBB ; __UBB____Ab__first = __NBB [0]; __UBB____Ab__noptr =( ptr ) __UBB____Ab__noptr ; 
 __UBB____Ab____m__contents = __UBB____Ab__contents ;
 __UBB__len_x = __UBB____9a__length ; __UBB__len_y = __UBB____Ab__length ; __UBB__total_len = __UBB__len_x + __UBB__len_y ; __UBB__first = __UBB____9a__length ? __UBB____9a__first : __UBB____Ab__first ; 
 __UBB____Bb = 1 ;
 __UBB____Cb__z = __UBB__total_len + __UBB____Bb ; 
 __UBB____Cb____end :
 __UBB____Db = 0 ;
 __UBB____Fb____iQ = __QBB__acquired ;
 __UBB____Fb____jQ__z =(! __UBB____Fb____iQ ); 
 __UBB____Fb____jQ____end :
 if(! __UBB____Fb____jQ__z )goto __UBB____Fb____hQ__fi ;
 __UBB____Fb____kQ = "Did not initialize Dynamic" ;
 goto __UBB____Fb____lQ____oD ;
 __builtin_unreachable();
 __UBB____Fb____hQ__fi :
 __UBB____Fb__next_size = __QBB__size +1; __UBB____Fb__success = true ; __UBB____Fb__self__allocated__prev = __QBB__allocated ; if ( __UBB____Fb__next_size >= __QBB__allocated ) { __QBB__allocated = __QBB__allocated + __QBB__allocated /2+1; __UBB____Fb__next_acquired =( ptr )((( ptr **) __QBB__acquired )[0]? __runtime_realloc ((( ptr **) __QBB__acquired )[0], __QBB__allocated * sizeof ( ptr ), __UBB____Fb__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __QBB__allocated * sizeof ( ptr ))); if ( __UBB____Fb__success = __UBB____Fb__next_acquired )(( ptr **) __QBB__acquired )[0]=( ptr *) __UBB____Fb__next_acquired ; } if ( __UBB____Fb__success ) { __UBB____Fb__mem =( ptr ) __runtime_alloc ( __UBB____Cb__z * sizeof ( __UBB____Fb____gQ )); if ( __UBB____Fb__success = __UBB____Fb__mem ) {(( ptr **) __QBB__acquired )[0][ __QBB__size ]= __UBB____Fb__mem ; __QBB__size = __UBB____Fb__next_size ; } } 
 __UBB____Fb____nQ__x = __UBB____Fb__success ;
 __UBB____Fb____nQ__z =(! __UBB____Fb____nQ__x ); 
 __UBB____Fb____nQ____end :
 if(! __UBB____Fb____nQ__z )goto __UBB____Fb____mQ__fi ;
 __UBB____Fb____oQ = "Failed a Dynamic allocation" ;
 goto __UBB____Fb____pQ____oD ;
 __builtin_unreachable();
 __UBB____Fb____mQ__fi :
 __UBB____Fb____uQ = 0 ;
 __UBB____Fb____wQ__bytesize = sizeof ( __UBB____Fb____wQ____CF )* __UBB____Cb__z ; 
 __UBB____Fb____wQ____end :
 memcpy (( char *) __UBB____Fb__mem ,( char *) __UBB____9a____m__contents , __UBB__len_x ); memcpy (( char *) __UBB____Fb__mem + __UBB__len_x ,( char *) __UBB____Ab____m__contents , __UBB__len_y );(( char *) __UBB____Fb__mem )[ __UBB__total_len ]=0; 
 __UBB____Ib__contents = __UBB____Fb__mem ;
 __QBB____TQ = __UBB____Fb__self____TQ ;
 __QBB__acquired = __QBB__acquired ;
 __QBB__size = __QBB__size ;
 __QBB__allocated = __QBB__allocated ;
 __QBB____dynamic_entry = __QBB____dynamic_entry ;
 __VBB__len_x = name__length ; __VBB__len_y = __UBB__total_len ; __VBB__total_len = __VBB__len_x + __VBB__len_y ; __VBB__first = name__length ? name__first : __UBB__first ; 
 __VBB____5i = 1 ;
 __VBB____6i__z = __VBB__total_len + __VBB____5i ; 
 __VBB____6i____end :
 __VBB____7i = 0 ;
 __VBB____9i____iQ = __QBB__acquired ;
 __VBB____9i____jQ__z =(! __VBB____9i____iQ ); 
 __VBB____9i____jQ____end :
 if(! __VBB____9i____jQ__z )goto __VBB____9i____hQ__fi ;
 __VBB____9i____kQ = "Did not initialize Dynamic" ;
 goto __VBB____9i____lQ____oD ;
 __builtin_unreachable();
 __VBB____9i____hQ__fi :
 __VBB____9i__next_size = __QBB__size +1; __VBB____9i__success = true ; __VBB____9i__self__allocated__prev = __QBB__allocated ; if ( __VBB____9i__next_size >= __QBB__allocated ) { __QBB__allocated = __QBB__allocated + __QBB__allocated /2+1; __VBB____9i__next_acquired =( ptr )((( ptr **) __QBB__acquired )[0]? __runtime_realloc ((( ptr **) __QBB__acquired )[0], __QBB__allocated * sizeof ( ptr ), __VBB____9i__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __QBB__allocated * sizeof ( ptr ))); if ( __VBB____9i__success = __VBB____9i__next_acquired )(( ptr **) __QBB__acquired )[0]=( ptr *) __VBB____9i__next_acquired ; } if ( __VBB____9i__success ) { __VBB____9i__mem =( ptr ) __runtime_alloc ( __VBB____6i__z * sizeof ( __VBB____9i____gQ )); if ( __VBB____9i__success = __VBB____9i__mem ) {(( ptr **) __QBB__acquired )[0][ __QBB__size ]= __VBB____9i__mem ; __QBB__size = __VBB____9i__next_size ; } } 
 __VBB____9i____nQ__x = __VBB____9i__success ;
 __VBB____9i____nQ__z =(! __VBB____9i____nQ__x ); 
 __VBB____9i____nQ____end :
 if(! __VBB____9i____nQ__z )goto __VBB____9i____mQ__fi ;
 __VBB____9i____oQ = "Failed a Dynamic allocation" ;
 goto __VBB____9i____pQ____oD ;
 __builtin_unreachable();
 __VBB____9i____mQ__fi :
 __VBB____9i____uQ = 0 ;
 __VBB____9i____wQ__bytesize = sizeof ( __VBB____9i____wQ____CF )* __VBB____6i__z ; 
 __VBB____9i____wQ____end :
 memcpy (( char *) __VBB____9i__mem ,( char *) name__contents , __VBB__len_x ); memcpy (( char *) __VBB____9i__mem + __VBB__len_x ,( char *) __UBB____Ib__contents , __VBB__len_y );(( char *) __VBB____9i__mem )[ __VBB__total_len ]=0; 
 __VBB____Cj__contents = __VBB____9i__mem ;
 __QBB____TQ = __VBB____9i__self____TQ ;
 __QBB__acquired = __QBB__acquired ;
 __QBB__size = __QBB__size ;
 __QBB__allocated = __QBB__allocated ;
 __QBB____dynamic_entry = __QBB____dynamic_entry ;
 __WBB____vh__length = strlen ( __SBB ); __WBB____vh__contents =( ptr ) __SBB ; __WBB____vh__first = __SBB [0]; __WBB____vh__noptr =( ptr ) __WBB____vh__noptr ; 
 __WBB____vh____m__contents = __WBB____vh__contents ;
 __WBB__len_x = __WBB____vh__length ; __WBB__len_y = __VBB__total_len ; __WBB__total_len = __WBB__len_x + __WBB__len_y ; __WBB__first = __WBB____vh__length ? __WBB____vh__first : __VBB__first ; 
 __WBB____xh = 1 ;
 __WBB____yh__z = __WBB__total_len + __WBB____xh ; 
 __WBB____yh____end :
 __WBB____zh = 0 ;
 __WBB____1h____iQ = __QBB__acquired ;
 __WBB____1h____jQ__z =(! __WBB____1h____iQ ); 
 __WBB____1h____jQ____end :
 if(! __WBB____1h____jQ__z )goto __WBB____1h____hQ__fi ;
 __WBB____1h____kQ = "Did not initialize Dynamic" ;
 goto __WBB____1h____lQ____oD ;
 __builtin_unreachable();
 __WBB____1h____hQ__fi :
 __WBB____1h__next_size = __QBB__size +1; __WBB____1h__success = true ; __WBB____1h__self__allocated__prev = __QBB__allocated ; if ( __WBB____1h__next_size >= __QBB__allocated ) { __QBB__allocated = __QBB__allocated + __QBB__allocated /2+1; __WBB____1h__next_acquired =( ptr )((( ptr **) __QBB__acquired )[0]? __runtime_realloc ((( ptr **) __QBB__acquired )[0], __QBB__allocated * sizeof ( ptr ), __WBB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __QBB__allocated * sizeof ( ptr ))); if ( __WBB____1h__success = __WBB____1h__next_acquired )(( ptr **) __QBB__acquired )[0]=( ptr *) __WBB____1h__next_acquired ; } if ( __WBB____1h__success ) { __WBB____1h__mem =( ptr ) __runtime_alloc ( __WBB____yh__z * sizeof ( __WBB____1h____gQ )); if ( __WBB____1h__success = __WBB____1h__mem ) {(( ptr **) __QBB__acquired )[0][ __QBB__size ]= __WBB____1h__mem ; __QBB__size = __WBB____1h__next_size ; } } 
 __WBB____1h____nQ__x = __WBB____1h__success ;
 __WBB____1h____nQ__z =(! __WBB____1h____nQ__x ); 
 __WBB____1h____nQ____end :
 if(! __WBB____1h____nQ__z )goto __WBB____1h____mQ__fi ;
 __WBB____1h____oQ = "Failed a Dynamic allocation" ;
 goto __WBB____1h____pQ____oD ;
 __builtin_unreachable();
 __WBB____1h____mQ__fi :
 __WBB____1h____uQ = 0 ;
 __WBB____1h____wQ__bytesize = sizeof ( __WBB____1h____wQ____CF )* __WBB____yh__z ; 
 __WBB____1h____wQ____end :
 memcpy (( char *) __WBB____1h__mem ,( char *) __WBB____vh____m__contents , __WBB__len_x ); memcpy (( char *) __WBB____1h__mem + __WBB__len_x ,( char *) __VBB____Cj__contents , __WBB__len_y );(( char *) __WBB____1h__mem )[ __WBB__total_len ]=0; 
 __WBB____4h__contents = __WBB____1h__mem ;
 __QBB____TQ = __WBB____1h__self____TQ ;
 __QBB__acquired = __QBB__acquired ;
 __QBB__size = __QBB__size ;
 __QBB__allocated = __QBB__allocated ;
 __QBB____dynamic_entry = __QBB____dynamic_entry ;
 __ZBB____ZQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __ZBB____ZQ__acquired )(( ptr **) __ZBB____ZQ__acquired )[0]=0; 
 __ZBB____ZQ____UQ = 0 ;
 __ZBB____ZQ____VQ = 0 ;
 __ZBB__acquired = __ZBB____ZQ__acquired ;
 __ZBB__size = __ZBB____ZQ____UQ ;
 __ZBB__allocated = __ZBB____ZQ____VQ ;
 __ZBB____dynamic_entry = __ZBB____ZQ____dynamic_entry ;
 __cBB____state = (struct run__817__state*)__runtime_calloc(sizeof(struct run__817__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __cBB____state ) ;
 __cBB____state -> command____c = command____c ;
 __cBB____state -> command__contents = __WBB____4h__contents ;
 __cBB____state -> command__length = __WBB__total_len ;
 __cBB____state -> command__first = __WBB__first ;
 __cBB____state -> command__memory = __QBB__acquired ;
 __cBB____task = __smolambda_add_task ( run__817 , __cBB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __cBB____task ) ;
 if( __cBB__err ) goto  __result_unhandled_error ;
 if( __cBB__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __cBB____task ) ;
 __cBB__err = __cBB____state -> err ;
 __eBB = __cBB__err ;
 if(! __eBB )goto __bBB__fi ;
 __fBB = "[ \033[31mERROR\033[0m ] " ;
 __gBB = ".s" ;
 __hBB____Ic__length = strlen ( __gBB ); __hBB____Ic__contents =( ptr ) __gBB ; __hBB____Ic__first = __gBB [0]; __hBB____Ic__noptr =( ptr ) __hBB____Ic__noptr ; 
 __hBB____Ic____m__contents = __hBB____Ic__contents ;
 __hBB__len_x = name__length ; __hBB__len_y = __hBB____Ic__length ; __hBB__total_len = __hBB__len_x + __hBB__len_y ; __hBB__first = name__length ? name__first : __hBB____Ic__first ; 
 __hBB____Jc = 1 ;
 __hBB____Kc__z = __hBB__total_len + __hBB____Jc ; 
 __hBB____Kc____end :
 __hBB____Lc = 0 ;
 __hBB____Nc____iQ = __ZBB__acquired ;
 __hBB____Nc____jQ__z =(! __hBB____Nc____iQ ); 
 __hBB____Nc____jQ____end :
 if(! __hBB____Nc____jQ__z )goto __hBB____Nc____hQ__fi ;
 __hBB____Nc____kQ = "Did not initialize Dynamic" ;
 goto __hBB____Nc____lQ____oD ;
 __builtin_unreachable();
 __hBB____Nc____hQ__fi :
 __hBB____Nc__next_size = __ZBB__size +1; __hBB____Nc__success = true ; __hBB____Nc__self__allocated__prev = __ZBB__allocated ; if ( __hBB____Nc__next_size >= __ZBB__allocated ) { __ZBB__allocated = __ZBB__allocated + __ZBB__allocated /2+1; __hBB____Nc__next_acquired =( ptr )((( ptr **) __ZBB__acquired )[0]? __runtime_realloc ((( ptr **) __ZBB__acquired )[0], __ZBB__allocated * sizeof ( ptr ), __hBB____Nc__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __ZBB__allocated * sizeof ( ptr ))); if ( __hBB____Nc__success = __hBB____Nc__next_acquired )(( ptr **) __ZBB__acquired )[0]=( ptr *) __hBB____Nc__next_acquired ; } if ( __hBB____Nc__success ) { __hBB____Nc__mem =( ptr ) __runtime_alloc ( __hBB____Kc__z * sizeof ( __hBB____Nc____gQ )); if ( __hBB____Nc__success = __hBB____Nc__mem ) {(( ptr **) __ZBB__acquired )[0][ __ZBB__size ]= __hBB____Nc__mem ; __ZBB__size = __hBB____Nc__next_size ; } } 
 __hBB____Nc____nQ__x = __hBB____Nc__success ;
 __hBB____Nc____nQ__z =(! __hBB____Nc____nQ__x ); 
 __hBB____Nc____nQ____end :
 if(! __hBB____Nc____nQ__z )goto __hBB____Nc____mQ__fi ;
 __hBB____Nc____oQ = "Failed a Dynamic allocation" ;
 goto __hBB____Nc____pQ____oD ;
 __builtin_unreachable();
 __hBB____Nc____mQ__fi :
 __hBB____Nc____uQ = 0 ;
 __hBB____Nc____wQ__bytesize = sizeof ( __hBB____Nc____wQ____CF )* __hBB____Kc__z ; 
 __hBB____Nc____wQ____end :
 memcpy (( char *) __hBB____Nc__mem ,( char *) name__contents , __hBB__len_x ); memcpy (( char *) __hBB____Nc__mem + __hBB__len_x ,( char *) __hBB____Ic____m__contents , __hBB__len_y );(( char *) __hBB____Nc__mem )[ __hBB__total_len ]=0; 
 __hBB____Qc__contents = __hBB____Nc__mem ;
 __ZBB____TQ = __hBB____Nc__self____TQ ;
 __ZBB__acquired = __ZBB__acquired ;
 __ZBB__size = __ZBB__size ;
 __ZBB__allocated = __ZBB__allocated ;
 __ZBB____dynamic_entry = __ZBB____dynamic_entry ;
 __iBB____vh__length = strlen ( __fBB ); __iBB____vh__contents =( ptr ) __fBB ; __iBB____vh__first = __fBB [0]; __iBB____vh__noptr =( ptr ) __iBB____vh__noptr ; 
 __iBB____vh____m__contents = __iBB____vh__contents ;
 __iBB__len_x = __iBB____vh__length ; __iBB__len_y = __hBB__total_len ; __iBB__total_len = __iBB__len_x + __iBB__len_y ; __iBB__first = __iBB____vh__length ? __iBB____vh__first : __hBB__first ; 
 __iBB____xh = 1 ;
 __iBB____yh__z = __iBB__total_len + __iBB____xh ; 
 __iBB____yh____end :
 __iBB____zh = 0 ;
 __iBB____1h____iQ = __ZBB__acquired ;
 __iBB____1h____jQ__z =(! __iBB____1h____iQ ); 
 __iBB____1h____jQ____end :
 if(! __iBB____1h____jQ__z )goto __iBB____1h____hQ__fi ;
 __iBB____1h____kQ = "Did not initialize Dynamic" ;
 goto __iBB____1h____lQ____oD ;
 __builtin_unreachable();
 __iBB____1h____hQ__fi :
 __iBB____1h__next_size = __ZBB__size +1; __iBB____1h__success = true ; __iBB____1h__self__allocated__prev = __ZBB__allocated ; if ( __iBB____1h__next_size >= __ZBB__allocated ) { __ZBB__allocated = __ZBB__allocated + __ZBB__allocated /2+1; __iBB____1h__next_acquired =( ptr )((( ptr **) __ZBB__acquired )[0]? __runtime_realloc ((( ptr **) __ZBB__acquired )[0], __ZBB__allocated * sizeof ( ptr ), __iBB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __ZBB__allocated * sizeof ( ptr ))); if ( __iBB____1h__success = __iBB____1h__next_acquired )(( ptr **) __ZBB__acquired )[0]=( ptr *) __iBB____1h__next_acquired ; } if ( __iBB____1h__success ) { __iBB____1h__mem =( ptr ) __runtime_alloc ( __iBB____yh__z * sizeof ( __iBB____1h____gQ )); if ( __iBB____1h__success = __iBB____1h__mem ) {(( ptr **) __ZBB__acquired )[0][ __ZBB__size ]= __iBB____1h__mem ; __ZBB__size = __iBB____1h__next_size ; } } 
 __iBB____1h____nQ__x = __iBB____1h__success ;
 __iBB____1h____nQ__z =(! __iBB____1h____nQ__x ); 
 __iBB____1h____nQ____end :
 if(! __iBB____1h____nQ__z )goto __iBB____1h____mQ__fi ;
 __iBB____1h____oQ = "Failed a Dynamic allocation" ;
 goto __iBB____1h____pQ____oD ;
 __builtin_unreachable();
 __iBB____1h____mQ__fi :
 __iBB____1h____uQ = 0 ;
 __iBB____1h____wQ__bytesize = sizeof ( __iBB____1h____wQ____CF )* __iBB____yh__z ; 
 __iBB____1h____wQ____end :
 memcpy (( char *) __iBB____1h__mem ,( char *) __iBB____vh____m__contents , __iBB__len_x ); memcpy (( char *) __iBB____1h__mem + __iBB__len_x ,( char *) __hBB____Qc__contents , __iBB__len_y );(( char *) __iBB____1h__mem )[ __iBB__total_len ]=0; 
 __iBB____4h__contents = __iBB____1h__mem ;
 __ZBB____TQ = __iBB____1h__self____TQ ;
 __ZBB__acquired = __ZBB__acquired ;
 __ZBB__size = __ZBB__size ;
 __ZBB__allocated = __ZBB__allocated ;
 __ZBB____dynamic_entry = __ZBB____dynamic_entry ;
 printf ( "%s\n" ,( char *) __iBB____4h__contents ); 
 __jBB____end :
 goto __bBB__el ;
 __bBB__fi :
 __kBB = "[ \033[32mOK\033[0m ] " ;
 __lBB = ".s" ;
 __mBB____Ic__length = strlen ( __lBB ); __mBB____Ic__contents =( ptr ) __lBB ; __mBB____Ic__first = __lBB [0]; __mBB____Ic__noptr =( ptr ) __mBB____Ic__noptr ; 
 __mBB____Ic____m__contents = __mBB____Ic__contents ;
 __mBB__len_x = name__length ; __mBB__len_y = __mBB____Ic__length ; __mBB__total_len = __mBB__len_x + __mBB__len_y ; __mBB__first = name__length ? name__first : __mBB____Ic__first ; 
 __mBB____Jc = 1 ;
 __mBB____Kc__z = __mBB__total_len + __mBB____Jc ; 
 __mBB____Kc____end :
 __mBB____Lc = 0 ;
 __mBB____Nc____iQ = __ZBB__acquired ;
 __mBB____Nc____jQ__z =(! __mBB____Nc____iQ ); 
 __mBB____Nc____jQ____end :
 if(! __mBB____Nc____jQ__z )goto __mBB____Nc____hQ__fi ;
 __mBB____Nc____kQ = "Did not initialize Dynamic" ;
 goto __mBB____Nc____lQ____oD ;
 __builtin_unreachable();
 __mBB____Nc____hQ__fi :
 __mBB____Nc__next_size = __ZBB__size +1; __mBB____Nc__success = true ; __mBB____Nc__self__allocated__prev = __ZBB__allocated ; if ( __mBB____Nc__next_size >= __ZBB__allocated ) { __ZBB__allocated = __ZBB__allocated + __ZBB__allocated /2+1; __mBB____Nc__next_acquired =( ptr )((( ptr **) __ZBB__acquired )[0]? __runtime_realloc ((( ptr **) __ZBB__acquired )[0], __ZBB__allocated * sizeof ( ptr ), __mBB____Nc__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __ZBB__allocated * sizeof ( ptr ))); if ( __mBB____Nc__success = __mBB____Nc__next_acquired )(( ptr **) __ZBB__acquired )[0]=( ptr *) __mBB____Nc__next_acquired ; } if ( __mBB____Nc__success ) { __mBB____Nc__mem =( ptr ) __runtime_alloc ( __mBB____Kc__z * sizeof ( __mBB____Nc____gQ )); if ( __mBB____Nc__success = __mBB____Nc__mem ) {(( ptr **) __ZBB__acquired )[0][ __ZBB__size ]= __mBB____Nc__mem ; __ZBB__size = __mBB____Nc__next_size ; } } 
 __mBB____Nc____nQ__x = __mBB____Nc__success ;
 __mBB____Nc____nQ__z =(! __mBB____Nc____nQ__x ); 
 __mBB____Nc____nQ____end :
 if(! __mBB____Nc____nQ__z )goto __mBB____Nc____mQ__fi ;
 __mBB____Nc____oQ = "Failed a Dynamic allocation" ;
 goto __mBB____Nc____pQ____oD ;
 __builtin_unreachable();
 __mBB____Nc____mQ__fi :
 __mBB____Nc____uQ = 0 ;
 __mBB____Nc____wQ__bytesize = sizeof ( __mBB____Nc____wQ____CF )* __mBB____Kc__z ; 
 __mBB____Nc____wQ____end :
 memcpy (( char *) __mBB____Nc__mem ,( char *) name__contents , __mBB__len_x ); memcpy (( char *) __mBB____Nc__mem + __mBB__len_x ,( char *) __mBB____Ic____m__contents , __mBB__len_y );(( char *) __mBB____Nc__mem )[ __mBB__total_len ]=0; 
 __mBB____Qc__contents = __mBB____Nc__mem ;
 __ZBB____TQ = __mBB____Nc__self____TQ ;
 __ZBB__acquired = __ZBB__acquired ;
 __ZBB__size = __ZBB__size ;
 __ZBB__allocated = __ZBB__allocated ;
 __ZBB____dynamic_entry = __ZBB____dynamic_entry ;
 __nBB____vh__length = strlen ( __kBB ); __nBB____vh__contents =( ptr ) __kBB ; __nBB____vh__first = __kBB [0]; __nBB____vh__noptr =( ptr ) __nBB____vh__noptr ; 
 __nBB____vh____m__contents = __nBB____vh__contents ;
 __nBB__len_x = __nBB____vh__length ; __nBB__len_y = __mBB__total_len ; __nBB__total_len = __nBB__len_x + __nBB__len_y ; __nBB__first = __nBB____vh__length ? __nBB____vh__first : __mBB__first ; 
 __nBB____xh = 1 ;
 __nBB____yh__z = __nBB__total_len + __nBB____xh ; 
 __nBB____yh____end :
 __nBB____zh = 0 ;
 __nBB____1h____iQ = __ZBB__acquired ;
 __nBB____1h____jQ__z =(! __nBB____1h____iQ ); 
 __nBB____1h____jQ____end :
 if(! __nBB____1h____jQ__z )goto __nBB____1h____hQ__fi ;
 __nBB____1h____kQ = "Did not initialize Dynamic" ;
 goto __nBB____1h____lQ____oD ;
 __builtin_unreachable();
 __nBB____1h____hQ__fi :
 __nBB____1h__next_size = __ZBB__size +1; __nBB____1h__success = true ; __nBB____1h__self__allocated__prev = __ZBB__allocated ; if ( __nBB____1h__next_size >= __ZBB__allocated ) { __ZBB__allocated = __ZBB__allocated + __ZBB__allocated /2+1; __nBB____1h__next_acquired =( ptr )((( ptr **) __ZBB__acquired )[0]? __runtime_realloc ((( ptr **) __ZBB__acquired )[0], __ZBB__allocated * sizeof ( ptr ), __nBB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __ZBB__allocated * sizeof ( ptr ))); if ( __nBB____1h__success = __nBB____1h__next_acquired )(( ptr **) __ZBB__acquired )[0]=( ptr *) __nBB____1h__next_acquired ; } if ( __nBB____1h__success ) { __nBB____1h__mem =( ptr ) __runtime_alloc ( __nBB____yh__z * sizeof ( __nBB____1h____gQ )); if ( __nBB____1h__success = __nBB____1h__mem ) {(( ptr **) __ZBB__acquired )[0][ __ZBB__size ]= __nBB____1h__mem ; __ZBB__size = __nBB____1h__next_size ; } } 
 __nBB____1h____nQ__x = __nBB____1h__success ;
 __nBB____1h____nQ__z =(! __nBB____1h____nQ__x ); 
 __nBB____1h____nQ____end :
 if(! __nBB____1h____nQ__z )goto __nBB____1h____mQ__fi ;
 __nBB____1h____oQ = "Failed a Dynamic allocation" ;
 goto __nBB____1h____pQ____oD ;
 __builtin_unreachable();
 __nBB____1h____mQ__fi :
 __nBB____1h____uQ = 0 ;
 __nBB____1h____wQ__bytesize = sizeof ( __nBB____1h____wQ____CF )* __nBB____yh__z ; 
 __nBB____1h____wQ____end :
 memcpy (( char *) __nBB____1h__mem ,( char *) __nBB____vh____m__contents , __nBB__len_x ); memcpy (( char *) __nBB____1h__mem + __nBB__len_x ,( char *) __mBB____Qc__contents , __nBB__len_y );(( char *) __nBB____1h__mem )[ __nBB__total_len ]=0; 
 __nBB____4h__contents = __nBB____1h__mem ;
 __ZBB____TQ = __nBB____1h__self____TQ ;
 __ZBB__acquired = __ZBB__acquired ;
 __ZBB__size = __ZBB__size ;
 __ZBB__allocated = __ZBB__allocated ;
 __ZBB____dynamic_entry = __ZBB____dynamic_entry ;
 printf ( "%s\n" ,( char *) __nBB____4h__contents ); 
 __oBB____end :
 __bBB__el :
 __end :
goto __return;

// ERROR HANDLING
__mBB____Nc____lQ____oD :
 printf ( "%s\n" , __mBB____Nc____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__dBB :
printf("Runtime error from None __cBB \n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
__WBB____1h____pQ____oD :
 printf ( "%s\n" , __WBB____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__hBB____Nc____pQ____oD :
 printf ( "%s\n" , __hBB____Nc____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__VBB____9i____lQ____oD :
 printf ( "%s\n" , __VBB____9i____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__UBB____Fb____pQ____oD :
 printf ( "%s\n" , __UBB____Fb____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__iBB____1h____pQ____oD :
 printf ( "%s\n" , __iBB____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__nBB____1h____pQ____oD :
 printf ( "%s\n" , __nBB____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__nBB____1h____lQ____oD :
 printf ( "%s\n" , __nBB____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__UBB____Fb____lQ____oD :
 printf ( "%s\n" , __UBB____Fb____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__mBB____Nc____pQ____oD :
 printf ( "%s\n" , __mBB____Nc____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__VBB____9i____pQ____oD :
 printf ( "%s\n" , __VBB____9i____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__WBB____1h____lQ____oD :
 printf ( "%s\n" , __WBB____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__iBB____1h____lQ____oD :
 printf ( "%s\n" , __iBB____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__hBB____Nc____lQ____oD :
 printf ( "%s\n" , __hBB____Nc____kQ ); 
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
if ( __ZBB__acquired ) { for ( __ZBB____dynamic_entry =0; __ZBB____dynamic_entry < __ZBB__size ;++ __ZBB____dynamic_entry ) { __runtime_free ((( ptr **) __ZBB__acquired )[0][ __ZBB____dynamic_entry ]); } __runtime_free ( __ZBB__acquired ); __ZBB__acquired =0; __ZBB__size =0; __ZBB__allocated =0; } 
 if ( __ZBB__acquired ) { for ( __ZBB____ZQ____dynamic_entry =0; __ZBB____ZQ____dynamic_entry < __ZBB____ZQ____UQ ;++ __ZBB____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __ZBB__acquired )[0][ __ZBB____ZQ____dynamic_entry ]); } __runtime_free ( __ZBB__acquired ); __ZBB__acquired =0; __ZBB____ZQ____UQ =0; __ZBB____ZQ____VQ =0; } 
if ( __QBB__acquired ) { for ( __QBB____dynamic_entry =0; __QBB____dynamic_entry < __QBB__size ;++ __QBB____dynamic_entry ) { __runtime_free ((( ptr **) __QBB__acquired )[0][ __QBB____dynamic_entry ]); } __runtime_free ( __QBB__acquired ); __QBB__acquired =0; __QBB__size =0; __QBB__allocated =0; } 
 if ( __QBB__acquired ) { for ( __QBB____ZQ____dynamic_entry =0; __QBB____ZQ____dynamic_entry < __QBB____ZQ____UQ ;++ __QBB____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __QBB__acquired )[0][ __QBB____ZQ____dynamic_entry ]); } __runtime_free ( __QBB__acquired ); __QBB__acquired =0; __QBB____ZQ____UQ =0; __QBB____ZQ____VQ =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}


void run__817(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__817__state *__state=(struct run__817__state*)__void__state;
ptr command__contents= __state->command__contents;
u64 command__length= __state->command__length;
char command__first= __state->command__first;
ptr command__memory= __state->command__memory;
i64 __rAB__status=0;
nominal __sAB__p____78=0;
nominal command____c=0;
bool __rAB____M9__z=0;
ptr __rAB__contents=0;
ptr __pAB__contents=0;
ptr __rAB____L9__x=0;
errcode err=0;
ptr process__contents=0;
nominal process____78=0;
bool __rAB____L9__z=0;
ptr __qAB__contents=0;

// IMPLEMENTATION
__pAB__contents = 0 ;
 __qAB__contents = __pAB__contents ;
 __rAB__contents =( ptr ) popen (( cstr ) command__contents , "r" ); 
 __rAB____L9__x = __rAB__contents ;
 __rAB____L9__z =( __rAB____L9__x ); 
 __rAB____L9____end :
 __rAB____M9__z =(! __rAB____L9__z ); 
 __rAB____M9____end :
 if(! __rAB____M9__z )goto __rAB____K9__fi ;
 goto __rAB____N9 ;
 __builtin_unreachable();
 __rAB____K9__fi :
 process__contents = __rAB__contents ;
 if ( process__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process__contents )) { } } 
 __sAB____end :
 process____78 = __sAB__p____78 ;
 __rAB__status =0; if ( process__contents ) __rAB__status = pclose (( FILE *) process__contents ); process__contents =0; if ( __rAB__status ) { if ( __rAB__status !=-1&& WIFEXITED ( __rAB__status )) __rAB__status = WEXITSTATUS ( __rAB__status ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __rAB__status ); __result__errocode = __USER__ERROR ; goto __failsafe ; } 
 __end :
goto __return;

// ERROR HANDLING
__rAB____N9 :
 printf ( "Error: Failed to start process\n" ); 
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


void run__816(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__816__state *__state=(struct run__816__state*)__void__state;
ptr command__contents= __state->command__contents;
u64 command__length= __state->command__length;
char command__first= __state->command__first;
ptr command__memory= __state->command__memory;
nominal __mAB__p____78=0;
bool __lAB____YAB____D9__z=0;
bool __lAB____YAB____C9__z=0;
ptr __lAB____YAB____C9__x=0;
ptr __lAB____YAB____A9____p__contents=0;
ptr __lAB____YAB____A9__noptr=0;
char __lAB____YAB____A9__first=0;
ptr __lAB____YAB____A9__contents=0;
u64 __lAB____YAB____A9__length=0;
char __lAB____UAB____1F____8E=0;
ptr __kAB__contents=0;
char process____UAB____1F____8E=0;
ptr process____XAB__contents=0;
cstr __lAB__mem=0;
ptr __lAB____UAB__mem=0;
ptr process____YAB____C9__x=0;
char __lAB____SAB=0;
char __lAB__first=0;
char process____UAB____zF=0;
ptr process__command__contents=0;
char process__first=0;
char process____UAB____pF=0;
char __lAB____UAB____pF=0;
i64 process____YAB__status=0;
bool process____UAB____mF__z=0;
u64 __lAB____RAB__z=0;
ptr __lAB____WAB__contents=0;
cstr process____UAB____nF=0;
u64 process____UAB__size=0;
bool process____YAB____C9__z=0;
cstr process__mem=0;
ptr process____YAB__contents=0;
ptr process____YAB____A9__contents=0;
ptr __lAB____YAB__contents=0;
bool __lAB____UAB____rF=0;
nominal process____YAB____78=0;
ptr process__command__memory=0;
u64 process____UAB____1F__bytesize=0;
bool process____YAB____D9__z=0;
ptr process____YAB____A9__noptr=0;
u64 process____UAB____lF=0;
bool __lAB____UAB____sF__z=0;
char process____YAB____A9__first=0;
u64 __lAB____UAB____1F__bytesize=0;
nominal process__command____b=0;
char process__command__first=0;
u64 process____QAB=0;
nominal process____NAB____78=0;
bool process____UAB____rF=0;
u64 process____RAB__z=0;
char process____SAB=0;
ptr process____WAB__contents=0;
ptr process____UAB__mem=0;
bool process____UAB____sF__z=0;
u64 __lAB____QAB=0;
ptr process____NAB__contents=0;
u64 process__command__length=0;
u64 process____YAB____A9__length=0;
ptr process____YAB____A9____p__contents=0;
nominal command____b=0;
ptr __jAB__contents=0;
u64 __lAB____UAB____lF=0;
bool __lAB____UAB____mF__z=0;
cstr process____UAB____tF=0;
cstr __lAB____UAB____nF=0;
i64 __lAB____YAB__status=0;
cstr __lAB____UAB____tF=0;
errcode err=0;
char __lAB____UAB____zF=0;

// IMPLEMENTATION
__jAB__contents = 0 ;
 __kAB__contents = __jAB__contents ;
 __lAB____QAB = 1 ;
 __lAB____RAB__z = command__length + __lAB____QAB ; 
 __lAB____RAB____end :
 __lAB____SAB = 0 ;
 __lAB____UAB____lF = 0 ;
 __lAB____UAB____mF__z =( __lAB____RAB__z == __lAB____UAB____lF ); 
 __lAB____UAB____mF____end :
 if(! __lAB____UAB____mF__z )goto __lAB____UAB____kF__fi ;
 __lAB____UAB____nF = "Cannot allocate zero size" ;
 goto __lAB____UAB____oF____oD ;
 __builtin_unreachable();
 __lAB____UAB____kF__fi :
 __lAB____UAB__mem = alloca ( __lAB____RAB__z * sizeof ( __lAB____UAB____pF )); 
 __lAB____UAB____rF = __lAB____UAB__mem ;
 __lAB____UAB____sF__z =(! __lAB____UAB____rF ); 
 __lAB____UAB____sF____end :
 if(! __lAB____UAB____sF__z )goto __lAB____UAB____qF__fi ;
 __lAB____UAB____tF = "Failed a Stack allocation" ;
 goto __lAB____UAB____uF____oD ;
 __builtin_unreachable();
 __lAB____UAB____qF__fi :
 __lAB____UAB____zF = 0 ;
 __lAB____UAB____1F__bytesize = sizeof ( __lAB____UAB____1F____8E )* __lAB____RAB__z ; 
 __lAB____UAB____1F____end :
 __lAB__first =0; if ( __lAB____UAB__mem ) { memcpy (( char *) __lAB____UAB__mem , command__contents , command__length );(( char *) __lAB____UAB__mem )[ command__length ]=0; } __lAB__mem =( const char *) __lAB____UAB__mem ; 
 __lAB____WAB__contents = 0 ;
 __lAB____YAB____A9__length = strlen ( __lAB__mem ); __lAB____YAB____A9__contents =( ptr ) __lAB__mem ; __lAB____YAB____A9__first = __lAB__mem [0]; __lAB____YAB____A9__noptr =( ptr ) __lAB____YAB____A9__noptr ; 
 __lAB____YAB____A9____p__contents = __lAB____YAB____A9__contents ;
 __lAB____YAB__contents =( ptr ) popen (( cstr ) __lAB____YAB____A9____p__contents , "r" ); 
 __lAB____YAB____C9__x = __lAB____YAB__contents ;
 __lAB____YAB____C9__z =( __lAB____YAB____C9__x ); 
 __lAB____YAB____C9____end :
 __lAB____YAB____D9__z =(! __lAB____YAB____C9__z ); 
 __lAB____YAB____D9____end :
 if(! __lAB____YAB____D9__z )goto __lAB____YAB____B9__fi ;
 goto __lAB____YAB____E9 ;
 __builtin_unreachable();
 __lAB____YAB____B9__fi :
 __TRANSIENT( __lAB____UAB__mem )
 process____YAB__contents = __lAB____YAB__contents ;
 if ( process____YAB__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process____YAB__contents )) { } } 
 __mAB____end :
 process____YAB____78 = __mAB__p____78 ;
 __lAB____YAB__status =0; if ( process____YAB__contents ) __lAB____YAB__status = pclose (( FILE *) process____YAB__contents ); process____YAB__contents =0; if ( __lAB____YAB__status ) { if ( __lAB____YAB__status !=-1&& WIFEXITED ( __lAB____YAB__status )) __lAB____YAB__status = WEXITSTATUS ( __lAB____YAB__status ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __lAB____YAB__status ); __result__errocode = __USER__ERROR ; goto __failsafe ; } 
 __end :
goto __return;

// ERROR HANDLING
__lAB____YAB____E9 :
 printf ( "Error: Failed to start process\n" ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__lAB____UAB____uF____oD :
 printf ( "%s\n" , __lAB____UAB____tF ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__lAB____UAB____oF____oD :
 printf ( "%s\n" , __lAB____UAB____nF ); 
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


void std_test__819(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__819__state *__state=(struct std_test__819__state*)__void__state;
struct run__817__state* __9AB____state = 0 ;
cstr name= __state->name;
nominal __KBB____1h__self____TQ=0;
ptr __KBB____4h__contents=0;
char __KBB____1h____wQ____CF=0;
char __KBB____1h____uQ=0;
cstr __KBB____1h____oQ=0;
bool __KBB____1h____nQ__z=0;
char __KBB____1h____gQ=0;
ptr __KBB____1h__mem=0;
bool __KBB____1h__success=0;
u64 __KBB____1h____wQ__bytesize=0;
u64 __KBB____yh__z=0;
char __KBB__first=0;
u64 __KBB__len_x=0;
char __KBB____vh__first=0;
cstr __JBB____Fb____oQ=0;
bool __JBB____Fb____nQ__z=0;
bool __JBB____Fb____nQ__x=0;
ptr __JBB____Fb__mem=0;
u64 __JBB____Fb__self__allocated__prev=0;
bool __JBB____Fb__success=0;
bool __JBB____Fb____iQ=0;
u64 __JBB____Cb__z=0;
u64 __JBB____Bb=0;
ptr __JBB____Ab__noptr=0;
ptr __JBB____9a__noptr=0;
cstr __IBB=0;
cstr __HBB=0;
char __FBB____1h____wQ____CF=0;
bool __FBB____1h____nQ__z=0;
char __FBB____1h____gQ=0;
ptr __FBB____1h__next_acquired=0;
u64 __FBB____1h__self__allocated__prev=0;
cstr __FBB____1h____kQ=0;
bool __FBB____1h____jQ__z=0;
bool __FBB____1h____iQ=0;
u64 __KBB____1h__next_size=0;
u64 __FBB__total_len=0;
u64 __FBB__len_y=0;
u64 __FBB__len_x=0;
ptr __FBB____vh____m__contents=0;
char __FBB____vh__first=0;
ptr __FBB____vh__contents=0;
u64 __FBB____vh__length=0;
nominal __6AB____TQ=0;
ptr __EBB____Ib__contents=0;
char __EBB____Fb____wQ____CF=0;
u64 __EBB____Fb____wQ__bytesize=0;
char __EBB____Fb____uQ=0;
cstr __EBB____Fb____oQ=0;
bool __EBB____Fb____nQ__z=0;
char __EBB____Fb____gQ=0;
ptr __EBB____Fb__next_acquired=0;
bool __EBB____Fb__success=0;
u64 __JBB____9a__length=0;
ptr __KBB____vh__contents=0;
cstr __EBB____Fb____kQ=0;
u64 __KBB____vh__length=0;
bool __EBB____Fb____iQ=0;
char __EBB____Db=0;
u64 __EBB____Bb=0;
char __EBB__first=0;
bool __KBB____1h____iQ=0;
u64 __EBB__len_y=0;
char __JBB____Fb____uQ=0;
ptr __EBB____Ab____m__contents=0;
ptr __EBB____Ab__noptr=0;
char __EBB____Ab__first=0;
ptr __EBB____Ab__contents=0;
u64 __EBB____Ab__length=0;
char __EBB____9a__first=0;
ptr __EBB____9a__contents=0;
u64 __EBB____9a__length=0;
cstr __DBB=0;
cstr __CBB=0;
bool __EBB____Fb____nQ__x=0;
bool __BBB=0;
errcode __9AB__err=0;
ptr __9AB____task=0;
ptr __EBB____9a____m__contents=0;
u64 command__length=0;
u64 __6AB____ZQ____dynamic_entry=0;
u64 __6AB____dynamic_entry=0;
u64 __6AB__allocated=0;
ptr __6AB____ZQ__acquired=0;
nominal __3AB____1h__self____TQ=0;
ptr __3AB____4h__contents=0;
char __3AB____1h____wQ____CF=0;
u64 __JBB__len_x=0;
char __3AB____1h____uQ=0;
ptr __3AB____1h__next_acquired=0;
bool __3AB____1h__success=0;
u64 __JBB____Ab__length=0;
u64 __6AB____ZQ____VQ=0;
cstr __3AB____1h____kQ=0;
u64 __JBB____Fb____wQ__bytesize=0;
bool __3AB____1h____jQ__z=0;
ptr __JBB____Ib__contents=0;
char __3AB____zh=0;
u64 __3AB____yh__z=0;
u64 __3AB__len_y=0;
u64 __3AB__len_x=0;
ptr __KBB____vh__noptr=0;
char __3AB__first=0;
ptr __3AB____vh____m__contents=0;
ptr __3AB____vh__noptr=0;
char __3AB____vh__first=0;
ptr __2AB____4h__contents=0;
char __2AB____1h____wQ____CF=0;
bool __EBB____Fb____jQ__z=0;
char __2AB____1h____uQ=0;
bool __KBB____1h____nQ__x=0;
bool __2AB____1h____nQ__x=0;
char __2AB____1h____gQ=0;
char __FBB____1h____uQ=0;
cstr __1AB____Fb____oQ=0;
ptr __3AB____1h__mem=0;
u64 __6AB__size=0;
u64 __xAB____ZQ____VQ=0;
ptr __2AB____1h__mem=0;
u64 __JBB__total_len=0;
cstr __3AB____1h____oQ=0;
ptr __1AB____Ab__contents=0;
u64 __2AB____vh__length=0;
char __JBB____Fb____wQ____CF=0;
char command__first=0;
u64 __3AB__total_len=0;
u64 __2AB__total_len=0;
char __JBB__first=0;
u64 __FBB____xh=0;
char __3AB____1h____gQ=0;
u64 __6AB____ZQ____UQ=0;
u64 __xAB____ZQ____UQ=0;
bool __FBB____1h____nQ__x=0;
ptr command__contents=0;
ptr __EBB____Fb__mem=0;
bool __2AB____1h____iQ=0;
bool __1AB____Fb____nQ__x=0;
bool __2AB____1h____nQ__z=0;
bool __KBB____1h____jQ__z=0;
cstr __KBB____1h____kQ=0;
ptr command__memory=0;
u64 __KBB____xh=0;
u64 __EBB__total_len=0;
u64 __KBB__len_y=0;
u64 __3AB____1h__next_size=0;
ptr __FBB____4h__contents=0;
ptr __JBB____9a____m__contents=0;
u64 __FBB____1h____wQ__bytesize=0;
u64 __1AB__total_len=0;
ptr __3AB____vh__contents=0;
u64 __1AB____9a__length=0;
char __KBB____zh=0;
u64 __2AB____xh=0;
nominal __FBB____1h__self____TQ=0;
char __JBB____Ab__first=0;
u64 __2AB____yh__z=0;
u64 __FBB____1h__next_size=0;
ptr __1AB____9a__noptr=0;
char __1AB____9a__first=0;
char __JBB____Fb____gQ=0;
cstr __FBB____1h____oQ=0;
char __JBB____Db=0;
u64 __3AB____1h____wQ__bytesize=0;
char __FBB____zh=0;
ptr __1AB____Fb__mem=0;
ptr __FBB____1h__mem=0;
ptr __JBB____Ab____m__contents=0;
ptr __1AB____Ib__contents=0;
ptr __xAB____ZQ__acquired=0;
nominal __2AB____1h__self____TQ=0;
u64 __2AB____1h____wQ__bytesize=0;
char __2AB____vh__first=0;
ptr __FBB____vh__noptr=0;
nominal __EBB____Fb__self____TQ=0;
bool __FBB____1h__success=0;
ptr __2AB____1h__next_acquired=0;
nominal command____c=0;
u64 __JBB____Fb__next_size=0;
ptr __1AB____Ab____m__contents=0;
ptr __KBB____1h__next_acquired=0;
u64 __JBB__len_y=0;
u64 __EBB____Cb__z=0;
cstr __0AB=0;
char __1AB____Fb____uQ=0;
cstr __JBB____Fb____kQ=0;
ptr __1AB____9a____m__contents=0;
ptr __JBB____Fb__next_acquired=0;
u64 __EBB____Fb__next_size=0;
nominal __1AB____Fb__self____TQ=0;
u64 __1AB__len_x=0;
ptr __JBB____Ab__contents=0;
u64 __1AB____Ab__length=0;
char __1AB____Fb____gQ=0;
nominal __JBB____Fb__self____TQ=0;
u64 __3AB____vh__length=0;
bool __3AB____1h____nQ__x=0;
u64 __2AB____1h__self__allocated__prev=0;
u64 __KBB____1h__self__allocated__prev=0;
u64 __3AB____1h__self__allocated__prev=0;
bool __3AB____1h____iQ=0;
cstr __2AB____1h____kQ=0;
ptr __KBB____vh____m__contents=0;
char __1AB____Ab__first=0;
errcode err=0;
bool __1AB____Fb__success=0;
ptr __6AB__acquired=0;
ptr __xAB__acquired=0;
cstr __2AB____1h____oQ=0;
cstr __uAB=0;
u64 __xAB__size=0;
u64 __xAB__allocated=0;
u64 __xAB____dynamic_entry=0;
char __FBB__first=0;
u64 __xAB____ZQ____dynamic_entry=0;
cstr __zAB=0;
u64 __2AB__len_x=0;
bool __3AB____1h____nQ__z=0;
cstr __1AB____Fb____kQ=0;
ptr __1AB____Ab__noptr=0;
bool __1AB____Fb____jQ__z=0;
u64 __1AB__len_y=0;
bool __JBB____Fb____jQ__z=0;
char __1AB__first=0;
u64 __1AB____Fb__self__allocated__prev=0;
u64 __1AB____Cb__z=0;
char __JBB____9a__first=0;
char __1AB____Db=0;
ptr __JBB____9a__contents=0;
u64 __1AB____Bb=0;
bool __1AB____Fb____iQ=0;
char __2AB____zh=0;
u64 __EBB__len_x=0;
u64 __3AB____xh=0;
bool __1AB____Fb____nQ__z=0;
u64 __1AB____Fb__next_size=0;
ptr __1AB____Fb__next_acquired=0;
u64 __EBB____Fb__self__allocated__prev=0;
ptr __EBB____9a__noptr=0;
u64 __1AB____Fb____wQ__bytesize=0;
char __1AB____Fb____wQ____CF=0;
u64 __KBB__total_len=0;
ptr __1AB____9a__contents=0;
nominal __xAB____TQ=0;
ptr __2AB____vh__contents=0;
ptr __2AB____vh__noptr=0;
ptr __2AB____vh____m__contents=0;
u64 __2AB__len_y=0;
char __2AB__first=0;
bool __2AB____1h____jQ__z=0;
u64 __2AB____1h__next_size=0;
u64 __FBB____yh__z=0;
bool __2AB____1h__success=0;

// IMPLEMENTATION
__uAB = " 2>&1" ;
 __xAB____ZQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __xAB____ZQ__acquired )(( ptr **) __xAB____ZQ__acquired )[0]=0; 
 __xAB____ZQ____UQ = 0 ;
 __xAB____ZQ____VQ = 0 ;
 __xAB__acquired = __xAB____ZQ__acquired ;
 __xAB__size = __xAB____ZQ____UQ ;
 __xAB__allocated = __xAB____ZQ____VQ ;
 __xAB____dynamic_entry = __xAB____ZQ____dynamic_entry ;
 __zAB = "./smol tests/unit/" ;
 __0AB = ".s --runtime eager" ;
 __1AB____9a__length = strlen ( __0AB ); __1AB____9a__contents =( ptr ) __0AB ; __1AB____9a__first = __0AB [0]; __1AB____9a__noptr =( ptr ) __1AB____9a__noptr ; 
 __1AB____9a____m__contents = __1AB____9a__contents ;
 __1AB____Ab__length = strlen ( __uAB ); __1AB____Ab__contents =( ptr ) __uAB ; __1AB____Ab__first = __uAB [0]; __1AB____Ab__noptr =( ptr ) __1AB____Ab__noptr ; 
 __1AB____Ab____m__contents = __1AB____Ab__contents ;
 __1AB__len_x = __1AB____9a__length ; __1AB__len_y = __1AB____Ab__length ; __1AB__total_len = __1AB__len_x + __1AB__len_y ; __1AB__first = __1AB____9a__length ? __1AB____9a__first : __1AB____Ab__first ; 
 __1AB____Bb = 1 ;
 __1AB____Cb__z = __1AB__total_len + __1AB____Bb ; 
 __1AB____Cb____end :
 __1AB____Db = 0 ;
 __1AB____Fb____iQ = __xAB__acquired ;
 __1AB____Fb____jQ__z =(! __1AB____Fb____iQ ); 
 __1AB____Fb____jQ____end :
 if(! __1AB____Fb____jQ__z )goto __1AB____Fb____hQ__fi ;
 __1AB____Fb____kQ = "Did not initialize Dynamic" ;
 goto __1AB____Fb____lQ____oD ;
 __builtin_unreachable();
 __1AB____Fb____hQ__fi :
 __1AB____Fb__next_size = __xAB__size +1; __1AB____Fb__success = true ; __1AB____Fb__self__allocated__prev = __xAB__allocated ; if ( __1AB____Fb__next_size >= __xAB__allocated ) { __xAB__allocated = __xAB__allocated + __xAB__allocated /2+1; __1AB____Fb__next_acquired =( ptr )((( ptr **) __xAB__acquired )[0]? __runtime_realloc ((( ptr **) __xAB__acquired )[0], __xAB__allocated * sizeof ( ptr ), __1AB____Fb__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __xAB__allocated * sizeof ( ptr ))); if ( __1AB____Fb__success = __1AB____Fb__next_acquired )(( ptr **) __xAB__acquired )[0]=( ptr *) __1AB____Fb__next_acquired ; } if ( __1AB____Fb__success ) { __1AB____Fb__mem =( ptr ) __runtime_alloc ( __1AB____Cb__z * sizeof ( __1AB____Fb____gQ )); if ( __1AB____Fb__success = __1AB____Fb__mem ) {(( ptr **) __xAB__acquired )[0][ __xAB__size ]= __1AB____Fb__mem ; __xAB__size = __1AB____Fb__next_size ; } } 
 __1AB____Fb____nQ__x = __1AB____Fb__success ;
 __1AB____Fb____nQ__z =(! __1AB____Fb____nQ__x ); 
 __1AB____Fb____nQ____end :
 if(! __1AB____Fb____nQ__z )goto __1AB____Fb____mQ__fi ;
 __1AB____Fb____oQ = "Failed a Dynamic allocation" ;
 goto __1AB____Fb____pQ____oD ;
 __builtin_unreachable();
 __1AB____Fb____mQ__fi :
 __1AB____Fb____uQ = 0 ;
 __1AB____Fb____wQ__bytesize = sizeof ( __1AB____Fb____wQ____CF )* __1AB____Cb__z ; 
 __1AB____Fb____wQ____end :
 memcpy (( char *) __1AB____Fb__mem ,( char *) __1AB____9a____m__contents , __1AB__len_x ); memcpy (( char *) __1AB____Fb__mem + __1AB__len_x ,( char *) __1AB____Ab____m__contents , __1AB__len_y );(( char *) __1AB____Fb__mem )[ __1AB__total_len ]=0; 
 __1AB____Ib__contents = __1AB____Fb__mem ;
 __xAB____TQ = __1AB____Fb__self____TQ ;
 __xAB__acquired = __xAB__acquired ;
 __xAB__size = __xAB__size ;
 __xAB__allocated = __xAB__allocated ;
 __xAB____dynamic_entry = __xAB____dynamic_entry ;
 __2AB____vh__length = strlen ( name ); __2AB____vh__contents =( ptr ) name ; __2AB____vh__first = name [0]; __2AB____vh__noptr =( ptr ) __2AB____vh__noptr ; 
 __2AB____vh____m__contents = __2AB____vh__contents ;
 __2AB__len_x = __2AB____vh__length ; __2AB__len_y = __1AB__total_len ; __2AB__total_len = __2AB__len_x + __2AB__len_y ; __2AB__first = __2AB____vh__length ? __2AB____vh__first : __1AB__first ; 
 __2AB____xh = 1 ;
 __2AB____yh__z = __2AB__total_len + __2AB____xh ; 
 __2AB____yh____end :
 __2AB____zh = 0 ;
 __2AB____1h____iQ = __xAB__acquired ;
 __2AB____1h____jQ__z =(! __2AB____1h____iQ ); 
 __2AB____1h____jQ____end :
 if(! __2AB____1h____jQ__z )goto __2AB____1h____hQ__fi ;
 __2AB____1h____kQ = "Did not initialize Dynamic" ;
 goto __2AB____1h____lQ____oD ;
 __builtin_unreachable();
 __2AB____1h____hQ__fi :
 __2AB____1h__next_size = __xAB__size +1; __2AB____1h__success = true ; __2AB____1h__self__allocated__prev = __xAB__allocated ; if ( __2AB____1h__next_size >= __xAB__allocated ) { __xAB__allocated = __xAB__allocated + __xAB__allocated /2+1; __2AB____1h__next_acquired =( ptr )((( ptr **) __xAB__acquired )[0]? __runtime_realloc ((( ptr **) __xAB__acquired )[0], __xAB__allocated * sizeof ( ptr ), __2AB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __xAB__allocated * sizeof ( ptr ))); if ( __2AB____1h__success = __2AB____1h__next_acquired )(( ptr **) __xAB__acquired )[0]=( ptr *) __2AB____1h__next_acquired ; } if ( __2AB____1h__success ) { __2AB____1h__mem =( ptr ) __runtime_alloc ( __2AB____yh__z * sizeof ( __2AB____1h____gQ )); if ( __2AB____1h__success = __2AB____1h__mem ) {(( ptr **) __xAB__acquired )[0][ __xAB__size ]= __2AB____1h__mem ; __xAB__size = __2AB____1h__next_size ; } } 
 __2AB____1h____nQ__x = __2AB____1h__success ;
 __2AB____1h____nQ__z =(! __2AB____1h____nQ__x ); 
 __2AB____1h____nQ____end :
 if(! __2AB____1h____nQ__z )goto __2AB____1h____mQ__fi ;
 __2AB____1h____oQ = "Failed a Dynamic allocation" ;
 goto __2AB____1h____pQ____oD ;
 __builtin_unreachable();
 __2AB____1h____mQ__fi :
 __2AB____1h____uQ = 0 ;
 __2AB____1h____wQ__bytesize = sizeof ( __2AB____1h____wQ____CF )* __2AB____yh__z ; 
 __2AB____1h____wQ____end :
 memcpy (( char *) __2AB____1h__mem ,( char *) __2AB____vh____m__contents , __2AB__len_x ); memcpy (( char *) __2AB____1h__mem + __2AB__len_x ,( char *) __1AB____Ib__contents , __2AB__len_y );(( char *) __2AB____1h__mem )[ __2AB__total_len ]=0; 
 __2AB____4h__contents = __2AB____1h__mem ;
 __xAB____TQ = __2AB____1h__self____TQ ;
 __xAB__acquired = __xAB__acquired ;
 __xAB__size = __xAB__size ;
 __xAB__allocated = __xAB__allocated ;
 __xAB____dynamic_entry = __xAB____dynamic_entry ;
 __3AB____vh__length = strlen ( __zAB ); __3AB____vh__contents =( ptr ) __zAB ; __3AB____vh__first = __zAB [0]; __3AB____vh__noptr =( ptr ) __3AB____vh__noptr ; 
 __3AB____vh____m__contents = __3AB____vh__contents ;
 __3AB__len_x = __3AB____vh__length ; __3AB__len_y = __2AB__total_len ; __3AB__total_len = __3AB__len_x + __3AB__len_y ; __3AB__first = __3AB____vh__length ? __3AB____vh__first : __2AB__first ; 
 __3AB____xh = 1 ;
 __3AB____yh__z = __3AB__total_len + __3AB____xh ; 
 __3AB____yh____end :
 __3AB____zh = 0 ;
 __3AB____1h____iQ = __xAB__acquired ;
 __3AB____1h____jQ__z =(! __3AB____1h____iQ ); 
 __3AB____1h____jQ____end :
 if(! __3AB____1h____jQ__z )goto __3AB____1h____hQ__fi ;
 __3AB____1h____kQ = "Did not initialize Dynamic" ;
 goto __3AB____1h____lQ____oD ;
 __builtin_unreachable();
 __3AB____1h____hQ__fi :
 __3AB____1h__next_size = __xAB__size +1; __3AB____1h__success = true ; __3AB____1h__self__allocated__prev = __xAB__allocated ; if ( __3AB____1h__next_size >= __xAB__allocated ) { __xAB__allocated = __xAB__allocated + __xAB__allocated /2+1; __3AB____1h__next_acquired =( ptr )((( ptr **) __xAB__acquired )[0]? __runtime_realloc ((( ptr **) __xAB__acquired )[0], __xAB__allocated * sizeof ( ptr ), __3AB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __xAB__allocated * sizeof ( ptr ))); if ( __3AB____1h__success = __3AB____1h__next_acquired )(( ptr **) __xAB__acquired )[0]=( ptr *) __3AB____1h__next_acquired ; } if ( __3AB____1h__success ) { __3AB____1h__mem =( ptr ) __runtime_alloc ( __3AB____yh__z * sizeof ( __3AB____1h____gQ )); if ( __3AB____1h__success = __3AB____1h__mem ) {(( ptr **) __xAB__acquired )[0][ __xAB__size ]= __3AB____1h__mem ; __xAB__size = __3AB____1h__next_size ; } } 
 __3AB____1h____nQ__x = __3AB____1h__success ;
 __3AB____1h____nQ__z =(! __3AB____1h____nQ__x ); 
 __3AB____1h____nQ____end :
 if(! __3AB____1h____nQ__z )goto __3AB____1h____mQ__fi ;
 __3AB____1h____oQ = "Failed a Dynamic allocation" ;
 goto __3AB____1h____pQ____oD ;
 __builtin_unreachable();
 __3AB____1h____mQ__fi :
 __3AB____1h____uQ = 0 ;
 __3AB____1h____wQ__bytesize = sizeof ( __3AB____1h____wQ____CF )* __3AB____yh__z ; 
 __3AB____1h____wQ____end :
 memcpy (( char *) __3AB____1h__mem ,( char *) __3AB____vh____m__contents , __3AB__len_x ); memcpy (( char *) __3AB____1h__mem + __3AB__len_x ,( char *) __2AB____4h__contents , __3AB__len_y );(( char *) __3AB____1h__mem )[ __3AB__total_len ]=0; 
 __3AB____4h__contents = __3AB____1h__mem ;
 __xAB____TQ = __3AB____1h__self____TQ ;
 __xAB__acquired = __xAB__acquired ;
 __xAB__size = __xAB__size ;
 __xAB__allocated = __xAB__allocated ;
 __xAB____dynamic_entry = __xAB____dynamic_entry ;
 __6AB____ZQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __6AB____ZQ__acquired )(( ptr **) __6AB____ZQ__acquired )[0]=0; 
 __6AB____ZQ____UQ = 0 ;
 __6AB____ZQ____VQ = 0 ;
 __6AB__acquired = __6AB____ZQ__acquired ;
 __6AB__size = __6AB____ZQ____UQ ;
 __6AB__allocated = __6AB____ZQ____VQ ;
 __6AB____dynamic_entry = __6AB____ZQ____dynamic_entry ;
 __9AB____state = (struct run__817__state*)__runtime_calloc(sizeof(struct run__817__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __9AB____state ) ;
 __9AB____state -> command____c = command____c ;
 __9AB____state -> command__contents = __3AB____4h__contents ;
 __9AB____state -> command__length = __3AB__total_len ;
 __9AB____state -> command__first = __3AB__first ;
 __9AB____state -> command__memory = __xAB__acquired ;
 __9AB____task = __smolambda_add_task ( run__817 , __9AB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __9AB____task ) ;
 if( __9AB__err ) goto  __result_unhandled_error ;
 if( __9AB__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __9AB____task ) ;
 __9AB__err = __9AB____state -> err ;
 __BBB = __9AB__err ;
 if(! __BBB )goto __8AB__fi ;
 __CBB = "[ \033[31mERROR\033[0m ] " ;
 __DBB = ".s" ;
 __EBB____9a__length = strlen ( name ); __EBB____9a__contents =( ptr ) name ; __EBB____9a__first = name [0]; __EBB____9a__noptr =( ptr ) __EBB____9a__noptr ; 
 __EBB____9a____m__contents = __EBB____9a__contents ;
 __EBB____Ab__length = strlen ( __DBB ); __EBB____Ab__contents =( ptr ) __DBB ; __EBB____Ab__first = __DBB [0]; __EBB____Ab__noptr =( ptr ) __EBB____Ab__noptr ; 
 __EBB____Ab____m__contents = __EBB____Ab__contents ;
 __EBB__len_x = __EBB____9a__length ; __EBB__len_y = __EBB____Ab__length ; __EBB__total_len = __EBB__len_x + __EBB__len_y ; __EBB__first = __EBB____9a__length ? __EBB____9a__first : __EBB____Ab__first ; 
 __EBB____Bb = 1 ;
 __EBB____Cb__z = __EBB__total_len + __EBB____Bb ; 
 __EBB____Cb____end :
 __EBB____Db = 0 ;
 __EBB____Fb____iQ = __6AB__acquired ;
 __EBB____Fb____jQ__z =(! __EBB____Fb____iQ ); 
 __EBB____Fb____jQ____end :
 if(! __EBB____Fb____jQ__z )goto __EBB____Fb____hQ__fi ;
 __EBB____Fb____kQ = "Did not initialize Dynamic" ;
 goto __EBB____Fb____lQ____oD ;
 __builtin_unreachable();
 __EBB____Fb____hQ__fi :
 __EBB____Fb__next_size = __6AB__size +1; __EBB____Fb__success = true ; __EBB____Fb__self__allocated__prev = __6AB__allocated ; if ( __EBB____Fb__next_size >= __6AB__allocated ) { __6AB__allocated = __6AB__allocated + __6AB__allocated /2+1; __EBB____Fb__next_acquired =( ptr )((( ptr **) __6AB__acquired )[0]? __runtime_realloc ((( ptr **) __6AB__acquired )[0], __6AB__allocated * sizeof ( ptr ), __EBB____Fb__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __6AB__allocated * sizeof ( ptr ))); if ( __EBB____Fb__success = __EBB____Fb__next_acquired )(( ptr **) __6AB__acquired )[0]=( ptr *) __EBB____Fb__next_acquired ; } if ( __EBB____Fb__success ) { __EBB____Fb__mem =( ptr ) __runtime_alloc ( __EBB____Cb__z * sizeof ( __EBB____Fb____gQ )); if ( __EBB____Fb__success = __EBB____Fb__mem ) {(( ptr **) __6AB__acquired )[0][ __6AB__size ]= __EBB____Fb__mem ; __6AB__size = __EBB____Fb__next_size ; } } 
 __EBB____Fb____nQ__x = __EBB____Fb__success ;
 __EBB____Fb____nQ__z =(! __EBB____Fb____nQ__x ); 
 __EBB____Fb____nQ____end :
 if(! __EBB____Fb____nQ__z )goto __EBB____Fb____mQ__fi ;
 __EBB____Fb____oQ = "Failed a Dynamic allocation" ;
 goto __EBB____Fb____pQ____oD ;
 __builtin_unreachable();
 __EBB____Fb____mQ__fi :
 __EBB____Fb____uQ = 0 ;
 __EBB____Fb____wQ__bytesize = sizeof ( __EBB____Fb____wQ____CF )* __EBB____Cb__z ; 
 __EBB____Fb____wQ____end :
 memcpy (( char *) __EBB____Fb__mem ,( char *) __EBB____9a____m__contents , __EBB__len_x ); memcpy (( char *) __EBB____Fb__mem + __EBB__len_x ,( char *) __EBB____Ab____m__contents , __EBB__len_y );(( char *) __EBB____Fb__mem )[ __EBB__total_len ]=0; 
 __EBB____Ib__contents = __EBB____Fb__mem ;
 __6AB____TQ = __EBB____Fb__self____TQ ;
 __6AB__acquired = __6AB__acquired ;
 __6AB__size = __6AB__size ;
 __6AB__allocated = __6AB__allocated ;
 __6AB____dynamic_entry = __6AB____dynamic_entry ;
 __FBB____vh__length = strlen ( __CBB ); __FBB____vh__contents =( ptr ) __CBB ; __FBB____vh__first = __CBB [0]; __FBB____vh__noptr =( ptr ) __FBB____vh__noptr ; 
 __FBB____vh____m__contents = __FBB____vh__contents ;
 __FBB__len_x = __FBB____vh__length ; __FBB__len_y = __EBB__total_len ; __FBB__total_len = __FBB__len_x + __FBB__len_y ; __FBB__first = __FBB____vh__length ? __FBB____vh__first : __EBB__first ; 
 __FBB____xh = 1 ;
 __FBB____yh__z = __FBB__total_len + __FBB____xh ; 
 __FBB____yh____end :
 __FBB____zh = 0 ;
 __FBB____1h____iQ = __6AB__acquired ;
 __FBB____1h____jQ__z =(! __FBB____1h____iQ ); 
 __FBB____1h____jQ____end :
 if(! __FBB____1h____jQ__z )goto __FBB____1h____hQ__fi ;
 __FBB____1h____kQ = "Did not initialize Dynamic" ;
 goto __FBB____1h____lQ____oD ;
 __builtin_unreachable();
 __FBB____1h____hQ__fi :
 __FBB____1h__next_size = __6AB__size +1; __FBB____1h__success = true ; __FBB____1h__self__allocated__prev = __6AB__allocated ; if ( __FBB____1h__next_size >= __6AB__allocated ) { __6AB__allocated = __6AB__allocated + __6AB__allocated /2+1; __FBB____1h__next_acquired =( ptr )((( ptr **) __6AB__acquired )[0]? __runtime_realloc ((( ptr **) __6AB__acquired )[0], __6AB__allocated * sizeof ( ptr ), __FBB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __6AB__allocated * sizeof ( ptr ))); if ( __FBB____1h__success = __FBB____1h__next_acquired )(( ptr **) __6AB__acquired )[0]=( ptr *) __FBB____1h__next_acquired ; } if ( __FBB____1h__success ) { __FBB____1h__mem =( ptr ) __runtime_alloc ( __FBB____yh__z * sizeof ( __FBB____1h____gQ )); if ( __FBB____1h__success = __FBB____1h__mem ) {(( ptr **) __6AB__acquired )[0][ __6AB__size ]= __FBB____1h__mem ; __6AB__size = __FBB____1h__next_size ; } } 
 __FBB____1h____nQ__x = __FBB____1h__success ;
 __FBB____1h____nQ__z =(! __FBB____1h____nQ__x ); 
 __FBB____1h____nQ____end :
 if(! __FBB____1h____nQ__z )goto __FBB____1h____mQ__fi ;
 __FBB____1h____oQ = "Failed a Dynamic allocation" ;
 goto __FBB____1h____pQ____oD ;
 __builtin_unreachable();
 __FBB____1h____mQ__fi :
 __FBB____1h____uQ = 0 ;
 __FBB____1h____wQ__bytesize = sizeof ( __FBB____1h____wQ____CF )* __FBB____yh__z ; 
 __FBB____1h____wQ____end :
 memcpy (( char *) __FBB____1h__mem ,( char *) __FBB____vh____m__contents , __FBB__len_x ); memcpy (( char *) __FBB____1h__mem + __FBB__len_x ,( char *) __EBB____Ib__contents , __FBB__len_y );(( char *) __FBB____1h__mem )[ __FBB__total_len ]=0; 
 __FBB____4h__contents = __FBB____1h__mem ;
 __6AB____TQ = __FBB____1h__self____TQ ;
 __6AB__acquired = __6AB__acquired ;
 __6AB__size = __6AB__size ;
 __6AB__allocated = __6AB__allocated ;
 __6AB____dynamic_entry = __6AB____dynamic_entry ;
 printf ( "%s\n" ,( char *) __FBB____4h__contents ); 
 __GBB____end :
 goto __8AB__el ;
 __8AB__fi :
 __HBB = "[ \033[32mOK\033[0m ] " ;
 __IBB = ".s" ;
 __JBB____9a__length = strlen ( name ); __JBB____9a__contents =( ptr ) name ; __JBB____9a__first = name [0]; __JBB____9a__noptr =( ptr ) __JBB____9a__noptr ; 
 __JBB____9a____m__contents = __JBB____9a__contents ;
 __JBB____Ab__length = strlen ( __IBB ); __JBB____Ab__contents =( ptr ) __IBB ; __JBB____Ab__first = __IBB [0]; __JBB____Ab__noptr =( ptr ) __JBB____Ab__noptr ; 
 __JBB____Ab____m__contents = __JBB____Ab__contents ;
 __JBB__len_x = __JBB____9a__length ; __JBB__len_y = __JBB____Ab__length ; __JBB__total_len = __JBB__len_x + __JBB__len_y ; __JBB__first = __JBB____9a__length ? __JBB____9a__first : __JBB____Ab__first ; 
 __JBB____Bb = 1 ;
 __JBB____Cb__z = __JBB__total_len + __JBB____Bb ; 
 __JBB____Cb____end :
 __JBB____Db = 0 ;
 __JBB____Fb____iQ = __6AB__acquired ;
 __JBB____Fb____jQ__z =(! __JBB____Fb____iQ ); 
 __JBB____Fb____jQ____end :
 if(! __JBB____Fb____jQ__z )goto __JBB____Fb____hQ__fi ;
 __JBB____Fb____kQ = "Did not initialize Dynamic" ;
 goto __JBB____Fb____lQ____oD ;
 __builtin_unreachable();
 __JBB____Fb____hQ__fi :
 __JBB____Fb__next_size = __6AB__size +1; __JBB____Fb__success = true ; __JBB____Fb__self__allocated__prev = __6AB__allocated ; if ( __JBB____Fb__next_size >= __6AB__allocated ) { __6AB__allocated = __6AB__allocated + __6AB__allocated /2+1; __JBB____Fb__next_acquired =( ptr )((( ptr **) __6AB__acquired )[0]? __runtime_realloc ((( ptr **) __6AB__acquired )[0], __6AB__allocated * sizeof ( ptr ), __JBB____Fb__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __6AB__allocated * sizeof ( ptr ))); if ( __JBB____Fb__success = __JBB____Fb__next_acquired )(( ptr **) __6AB__acquired )[0]=( ptr *) __JBB____Fb__next_acquired ; } if ( __JBB____Fb__success ) { __JBB____Fb__mem =( ptr ) __runtime_alloc ( __JBB____Cb__z * sizeof ( __JBB____Fb____gQ )); if ( __JBB____Fb__success = __JBB____Fb__mem ) {(( ptr **) __6AB__acquired )[0][ __6AB__size ]= __JBB____Fb__mem ; __6AB__size = __JBB____Fb__next_size ; } } 
 __JBB____Fb____nQ__x = __JBB____Fb__success ;
 __JBB____Fb____nQ__z =(! __JBB____Fb____nQ__x ); 
 __JBB____Fb____nQ____end :
 if(! __JBB____Fb____nQ__z )goto __JBB____Fb____mQ__fi ;
 __JBB____Fb____oQ = "Failed a Dynamic allocation" ;
 goto __JBB____Fb____pQ____oD ;
 __builtin_unreachable();
 __JBB____Fb____mQ__fi :
 __JBB____Fb____uQ = 0 ;
 __JBB____Fb____wQ__bytesize = sizeof ( __JBB____Fb____wQ____CF )* __JBB____Cb__z ; 
 __JBB____Fb____wQ____end :
 memcpy (( char *) __JBB____Fb__mem ,( char *) __JBB____9a____m__contents , __JBB__len_x ); memcpy (( char *) __JBB____Fb__mem + __JBB__len_x ,( char *) __JBB____Ab____m__contents , __JBB__len_y );(( char *) __JBB____Fb__mem )[ __JBB__total_len ]=0; 
 __JBB____Ib__contents = __JBB____Fb__mem ;
 __6AB____TQ = __JBB____Fb__self____TQ ;
 __6AB__acquired = __6AB__acquired ;
 __6AB__size = __6AB__size ;
 __6AB__allocated = __6AB__allocated ;
 __6AB____dynamic_entry = __6AB____dynamic_entry ;
 __KBB____vh__length = strlen ( __HBB ); __KBB____vh__contents =( ptr ) __HBB ; __KBB____vh__first = __HBB [0]; __KBB____vh__noptr =( ptr ) __KBB____vh__noptr ; 
 __KBB____vh____m__contents = __KBB____vh__contents ;
 __KBB__len_x = __KBB____vh__length ; __KBB__len_y = __JBB__total_len ; __KBB__total_len = __KBB__len_x + __KBB__len_y ; __KBB__first = __KBB____vh__length ? __KBB____vh__first : __JBB__first ; 
 __KBB____xh = 1 ;
 __KBB____yh__z = __KBB__total_len + __KBB____xh ; 
 __KBB____yh____end :
 __KBB____zh = 0 ;
 __KBB____1h____iQ = __6AB__acquired ;
 __KBB____1h____jQ__z =(! __KBB____1h____iQ ); 
 __KBB____1h____jQ____end :
 if(! __KBB____1h____jQ__z )goto __KBB____1h____hQ__fi ;
 __KBB____1h____kQ = "Did not initialize Dynamic" ;
 goto __KBB____1h____lQ____oD ;
 __builtin_unreachable();
 __KBB____1h____hQ__fi :
 __KBB____1h__next_size = __6AB__size +1; __KBB____1h__success = true ; __KBB____1h__self__allocated__prev = __6AB__allocated ; if ( __KBB____1h__next_size >= __6AB__allocated ) { __6AB__allocated = __6AB__allocated + __6AB__allocated /2+1; __KBB____1h__next_acquired =( ptr )((( ptr **) __6AB__acquired )[0]? __runtime_realloc ((( ptr **) __6AB__acquired )[0], __6AB__allocated * sizeof ( ptr ), __KBB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __6AB__allocated * sizeof ( ptr ))); if ( __KBB____1h__success = __KBB____1h__next_acquired )(( ptr **) __6AB__acquired )[0]=( ptr *) __KBB____1h__next_acquired ; } if ( __KBB____1h__success ) { __KBB____1h__mem =( ptr ) __runtime_alloc ( __KBB____yh__z * sizeof ( __KBB____1h____gQ )); if ( __KBB____1h__success = __KBB____1h__mem ) {(( ptr **) __6AB__acquired )[0][ __6AB__size ]= __KBB____1h__mem ; __6AB__size = __KBB____1h__next_size ; } } 
 __KBB____1h____nQ__x = __KBB____1h__success ;
 __KBB____1h____nQ__z =(! __KBB____1h____nQ__x ); 
 __KBB____1h____nQ____end :
 if(! __KBB____1h____nQ__z )goto __KBB____1h____mQ__fi ;
 __KBB____1h____oQ = "Failed a Dynamic allocation" ;
 goto __KBB____1h____pQ____oD ;
 __builtin_unreachable();
 __KBB____1h____mQ__fi :
 __KBB____1h____uQ = 0 ;
 __KBB____1h____wQ__bytesize = sizeof ( __KBB____1h____wQ____CF )* __KBB____yh__z ; 
 __KBB____1h____wQ____end :
 memcpy (( char *) __KBB____1h__mem ,( char *) __KBB____vh____m__contents , __KBB__len_x ); memcpy (( char *) __KBB____1h__mem + __KBB__len_x ,( char *) __JBB____Ib__contents , __KBB__len_y );(( char *) __KBB____1h__mem )[ __KBB__total_len ]=0; 
 __KBB____4h__contents = __KBB____1h__mem ;
 __6AB____TQ = __KBB____1h__self____TQ ;
 __6AB__acquired = __6AB__acquired ;
 __6AB__size = __6AB__size ;
 __6AB__allocated = __6AB__allocated ;
 __6AB____dynamic_entry = __6AB____dynamic_entry ;
 printf ( "%s\n" ,( char *) __KBB____4h__contents ); 
 __LBB____end :
 __8AB__el :
 __end :
goto __return;

// ERROR HANDLING
__FBB____1h____lQ____oD :
 printf ( "%s\n" , __FBB____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__ABB :
printf("Runtime error from None __9AB \n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__JBB____Fb____lQ____oD :
 printf ( "%s\n" , __JBB____Fb____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__KBB____1h____pQ____oD :
 printf ( "%s\n" , __KBB____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__FBB____1h____pQ____oD :
 printf ( "%s\n" , __FBB____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__EBB____Fb____pQ____oD :
 printf ( "%s\n" , __EBB____Fb____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__JBB____Fb____pQ____oD :
 printf ( "%s\n" , __JBB____Fb____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__1AB____Fb____lQ____oD :
 printf ( "%s\n" , __1AB____Fb____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__1AB____Fb____pQ____oD :
 printf ( "%s\n" , __1AB____Fb____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__2AB____1h____lQ____oD :
 printf ( "%s\n" , __2AB____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__2AB____1h____pQ____oD :
 printf ( "%s\n" , __2AB____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__EBB____Fb____lQ____oD :
 printf ( "%s\n" , __EBB____Fb____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__KBB____1h____lQ____oD :
 printf ( "%s\n" , __KBB____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__3AB____1h____lQ____oD :
 printf ( "%s\n" , __3AB____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__3AB____1h____pQ____oD :
 printf ( "%s\n" , __3AB____1h____oQ ); 
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
if ( __6AB__acquired ) { for ( __6AB____dynamic_entry =0; __6AB____dynamic_entry < __6AB__size ;++ __6AB____dynamic_entry ) { __runtime_free ((( ptr **) __6AB__acquired )[0][ __6AB____dynamic_entry ]); } __runtime_free ( __6AB__acquired ); __6AB__acquired =0; __6AB__size =0; __6AB__allocated =0; } 
 if ( __6AB__acquired ) { for ( __6AB____ZQ____dynamic_entry =0; __6AB____ZQ____dynamic_entry < __6AB____ZQ____UQ ;++ __6AB____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __6AB__acquired )[0][ __6AB____ZQ____dynamic_entry ]); } __runtime_free ( __6AB__acquired ); __6AB__acquired =0; __6AB____ZQ____UQ =0; __6AB____ZQ____VQ =0; } 
if ( __xAB__acquired ) { for ( __xAB____dynamic_entry =0; __xAB____dynamic_entry < __xAB__size ;++ __xAB____dynamic_entry ) { __runtime_free ((( ptr **) __xAB__acquired )[0][ __xAB____dynamic_entry ]); } __runtime_free ( __xAB__acquired ); __xAB__acquired =0; __xAB__size =0; __xAB__allocated =0; } 
 if ( __xAB__acquired ) { for ( __xAB____ZQ____dynamic_entry =0; __xAB____ZQ____dynamic_entry < __xAB____ZQ____UQ ;++ __xAB____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __xAB__acquired )[0][ __xAB____ZQ____dynamic_entry ]); } __runtime_free ( __xAB__acquired ); __xAB__acquired =0; __xAB____ZQ____UQ =0; __xAB____ZQ____VQ =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}


void main__823(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__823__state *__state=(struct main__823__state*)__void__state;
struct all__822__state* __1CB____state = 0 ;
f64 __0CB__elapsed=0;
cstr __8CB=0;
f64 __5CB__elapsed=0;
errcode __1CB__err=0;
errcode err=0;
f64 __6CB__z=0;
cstr __3CB=0;
ptr __1CB____task=0;

// IMPLEMENTATION
__0CB__elapsed = __smo_time_eta (); 
 __0CB____end :
 __1CB____state = (struct all__822__state*)__runtime_calloc(sizeof(struct all__822__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __1CB____state ) ;
 __1CB____task = __smolambda_add_task ( all__822 , __1CB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __1CB____task ) ;
 if( __1CB__err ) goto  __result_unhandled_error ;
 if( __1CB__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __1CB____task ) ;
 __1CB__err = __1CB____state -> err ;
 __3CB = "Completed in " ;
 printf ( "%s" , __3CB ); 
 __4CB____end :
 __5CB__elapsed = __smo_time_eta (); 
 __5CB____end :
 __6CB__z = __5CB__elapsed - __0CB__elapsed ; 
 __6CB____end :
 printf ( "%.6f" , __6CB__z ); 
 __7CB____end :
 __8CB = " sec" ;
 printf ( "%s\n" , __8CB ); 
 __9CB____end :
 __end :
goto __return;

// ERROR HANDLING
__2CB :
printf("Runtime error from None __1CB \n");
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



int main() {
struct main__823__state __main_args={0};
__smolambda_initialize_service_tasks(main__823, &__main_args);
return __main_args.err;
}

