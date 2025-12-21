#define SMOLAMBDA_SERVICES 8
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

#include<stdlib.h>

#include<sys/wait.h>

#if defined(_WIN32)||defined(_WIN64)
#define popen _popen
#define pclose _pclose
#endif

#include<stdio.h>

#include <stdio.h>
#include "std/oscommon.h"

struct main__386__state{errcode err;};
__externc void main__386(void *__void__state);
struct all__385__state{errcode err;};
__externc void all__385(void *__void__state);
struct run__378__state{errcode err;cstr command;};
__externc void run__378(void *__void__state);
struct run__379__state{errcode err;__new command____0sC;ptr command__contents;u64 command__length;char command__first;ptr command__memory;};
__externc void run__379(void *__void__state);
struct run__380__state{errcode err;__new command____0pC;ptr command__contents;u64 command__length;char command__first;ptr command__memory;};
__externc void run__380(void *__void__state);
struct std_test__382__state{errcode err;cstr name;};
__externc void std_test__382(void *__void__state);
struct std_test__383__state{errcode err;__new name____0sC;ptr name__contents;u64 name__length;char name__first;ptr name__memory;};
__externc void std_test__383(void *__void__state);
struct std_test__384__state{errcode err;__new name____0pC;ptr name__contents;u64 name__length;char name__first;ptr name__memory;};
__externc void std_test__384(void *__void__state);

void std_test__384(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1856;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__384__state *__state=(struct std_test__384__state*)__void__state;
struct run__379__state* __062B____state = 0 ;
ptr name__contents= __state->name__contents;
u64 name__length= __state->name__length;
char name__first= __state->name__first;
ptr name__memory= __state->name__memory;
u64 __0cfD=0;
u64 __0bfD=0;
u64 __0YfD=0;
u64 __0XfD=0;
char __0WfD=0;
u64 __0VfD=0;
cstr __0UfD=0;
ptr __042B__acquired=0;
bool __0OeD=0;
char __0OfD=0;
ptr __0RfD=0;
cstr __0MfD=0;
ptr __0NfD=0;
u64 __0GfD=0;
u64 __0JfD=0;
bool __0EfD=0;
__new name____0pC=0;
u64 __0HfD=0;
u64 __0FfD=0;
ptr __0QfD=0;
u64 __0TfD=0;
u64 __0KfD=0;
u64 __0IfD=0;
cstr __0LfD=0;
bool __00eD=0;
ptr __0x2B__acquired=0;
u64 __0mdD=0;
bool __0yeD=0;
u64 __0CfD=0;
ptr __0DfD=0;
ptr __0fdD=0;
ptr __0edD=0;
bool __0ddD=0;
bool __0cdD=0;
u64 __02eD=0;
cstr __0ZdD=0;
bool __0XdD=0;
ptr __0VdD=0;
__new __0TdD=0;
__new __0SdD=0;
u64 __0RdD=0;
ptr __0QdD=0;
char __0PdD=0;
u64 command__length=0;
ptr __0OdD=0;
ptr __0NdD=0;
u64 __0MdD=0;
char command__first=0;
u64 __0LdD=0;
u64 __0KdD=0;
char __0JdD=0;
ptr command__memory=0;
u64 __0IdD=0;
u64 __0HdD=0;
bool __0FdD=0;
bool __0EdD=0;
ptr command__contents=0;
cstr __0BdD=0;
bool __09cD=0;
u64 __08cD=0;
ptr __07cD=0;
ptr __06cD=0;
bool __05cD=0;
bool __04cD=0;
cstr __01cD=0;
bool __0zcD=0;
ptr __0wcD=0;
__new __0ucD=0;
__new command____0sC=0;
ptr __0tcD=0;
u64 __0scD=0;
u64 __0rcD=0;
ptr __0qcD=0;
errcode __0pcD=0;
cstr __0ncD=0;
cstr __0mcD=0;
cstr __0hcD=0;
cstr __0gcD=0;
u64 __0acD=0;

// IMPLEMENTATION
__0DfD = __runtime_alloc ( sizeof ( ptr **)); if ( __0DfD )(( ptr **) __0DfD )[0]=0; 
 __0FfD = 0 ;
 __0GfD = 0 ;
 __0x2B__acquired = __0DfD ;
 __0HfD = __0FfD ;
 __0IfD = __0GfD ;
 __0JfD = __0KfD ;
 __0LfD = "./smol tests/unit/" ;
 __0MfD = ".s --workers 1 --runtime eager 2>&1" ;
 __0CfD = strlen ( __0LfD ); __0NfD =( ptr ) __0LfD ; __0OfD = __0LfD [0]; __0QfD =0; 
 __0RfD = __0NfD ;
 __0TfD = __0CfD ; __02eD = name__length ; __0VfD = __0TfD + __02eD ; __0WfD = __0CfD ? __0OfD : name__first ; 
 __0XfD = 1 ;
 __0YfD = __0VfD + __0XfD ; 
 __0ZfD :
 __0yeD = __0x2B__acquired ;
 __00eD =(! __0yeD ); 
 __0veD :
 if(! __00eD )goto __0afD ;
 __0UfD = "Did not initialize Dynamic" ;
 [[unlikely]] goto __0SfD ;
 __builtin_unreachable();
 __0afD :
 __0bfD = __0HfD +1; __0EfD = true ; __0cfD = __0IfD ; if ( __0bfD >= __0IfD ) { __0IfD = __0IfD + __0IfD /2+1; __0fdD =( ptr )((( ptr **) __0x2B__acquired )[0]? __runtime_realloc ((( ptr **) __0x2B__acquired )[0], __0IfD * sizeof ( ptr ), __0cfD * sizeof ( ptr )): __runtime_alloc ( __0IfD * sizeof ( ptr ))); if (( __0EfD = __0fdD ))(( ptr **) __0x2B__acquired )[0]=( ptr *) __0fdD ; } if ( __0EfD ) { __0edD =( ptr ) __runtime_alloc ( __0YfD ); if (( __0EfD = __0edD )) {(( ptr **) __0x2B__acquired )[0][ __0HfD ]= __0edD ; __0HfD = __0bfD ; } } 
 __0ddD = __0EfD ;
 __0cdD =(! __0ddD ); 
 __0bdD :
 if(! __0cdD )goto __0adD ;
 __0ZdD = "Failed a Dynamic allocation" ;
 [[unlikely]] goto __0YdD ;
 __builtin_unreachable();
 __0adD :
 __0XdD =(( char *) __0QfD >=(( char *) __0edD )&&( char *) __0QfD <=(( char *) __0edD )+ __0TfD )||((( char *) name__memory )+ __0TfD >=(( char *) __0edD )&&( char *) name__memory <=(( char *) __0edD )+ __0VfD ); 
 if(! __0XdD )goto __0WdD ;
 [[unlikely]] goto __0PfD ;
 __builtin_unreachable();
 __0WdD :
 memcpy (( char *) __0edD ,( char *) __0RfD , __0TfD ); memcpy (( char *) __0edD + __0TfD ,( char *) name__contents , __02eD );(( char *) __0edD )[ __0VfD ]=0; 
 __0VdD = __0edD ;
 if ( __0x2B__acquired && __0VdD )((( char *) __0VdD )[ __0VfD ])=0; 
 __0UdD :
 __0TdD = __0SdD ;
 __0x2B__acquired = __0x2B__acquired ;
 __0HfD = __0HfD ;
 __0IfD = __0IfD ;
 __0JfD = __0JfD ;
 __0RdD = strlen ( __0MfD ); __0QdD =( ptr ) __0MfD ; __0PdD = __0MfD [0]; __0OdD =0; 
 __0NdD = __0QdD ;
 __0MdD = __0VfD ; __0LdD = __0RdD ; __0KdD = __0MdD + __0LdD ; __0JdD = __0VfD ? __0WfD : __0PdD ; 
 __0IdD = 1 ;
 __0HdD = __0KdD + __0IdD ; 
 __0GdD :
 __0FdD = __0x2B__acquired ;
 __0EdD =(! __0FdD ); 
 __0DdD :
 if(! __0EdD )goto __0CdD ;
 __0BdD = "Did not initialize Dynamic" ;
 [[unlikely]] goto __0AdD ;
 __builtin_unreachable();
 __0CdD :
 __0mdD = __0HfD +1; __09cD = true ; __08cD = __0IfD ; if ( __0mdD >= __0IfD ) { __0IfD = __0IfD + __0IfD /2+1; __07cD =( ptr )((( ptr **) __0x2B__acquired )[0]? __runtime_realloc ((( ptr **) __0x2B__acquired )[0], __0IfD * sizeof ( ptr ), __08cD * sizeof ( ptr )): __runtime_alloc ( __0IfD * sizeof ( ptr ))); if (( __09cD = __07cD ))(( ptr **) __0x2B__acquired )[0]=( ptr *) __07cD ; } if ( __09cD ) { __06cD =( ptr ) __runtime_alloc ( __0HdD ); if (( __09cD = __06cD )) {(( ptr **) __0x2B__acquired )[0][ __0HfD ]= __06cD ; __0HfD = __0mdD ; } } 
 __05cD = __09cD ;
 __04cD =(! __05cD ); 
 __03cD :
 if(! __04cD )goto __02cD ;
 __01cD = "Failed a Dynamic allocation" ;
 [[unlikely]] goto __00cD ;
 __builtin_unreachable();
 __02cD :
 __0zcD =(( char *) __0x2B__acquired >=(( char *) __06cD )&&( char *) __0x2B__acquired <=(( char *) __06cD )+ __0MdD )||((( char *) __0OdD )+ __0MdD >=(( char *) __06cD )&&( char *) __0OdD <=(( char *) __06cD )+ __0KdD ); 
 if(! __0zcD )goto __0ycD ;
 [[unlikely]] goto __0xcD ;
 __builtin_unreachable();
 __0ycD :
 memcpy (( char *) __06cD ,( char *) __0VdD , __0MdD ); memcpy (( char *) __06cD + __0MdD ,( char *) __0NdD , __0LdD );(( char *) __06cD )[ __0KdD ]=0; 
 __0wcD = __06cD ;
 if ( __0x2B__acquired && __0wcD )((( char *) __0wcD )[ __0KdD ])=0; 
 __0vcD :
 __0TdD = __0ucD ;
 __0x2B__acquired = __0x2B__acquired ;
 __0HfD = __0HfD ;
 __0IfD = __0IfD ;
 __0JfD = __0JfD ;
 __0tcD = __runtime_alloc ( sizeof ( ptr **)); if ( __0tcD )(( ptr **) __0tcD )[0]=0; 
 __0scD = 0 ;
 __0rcD = 0 ;
 __042B__acquired = __0tcD ;
 {char mark;if(__service_stack_floor+ 1196 >=(char*)&mark) goto __service_stack_floor_handler;} __062B____state = (struct run__379__state*)__runtime_calloc(sizeof(struct run__379__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __062B____state ) ;
 __062B____state -> command____0sC = command____0sC ;
 __062B____state -> command__contents = __0wcD ;
 __062B____state -> command__length = __0KdD ;
 __062B____state -> command__first = __0JdD ;
 __062B____state -> command__memory = __0x2B__acquired ;
 __0qcD = __smolambda_add_task ( run__379 , __062B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0qcD ) ;
 if( __0pcD ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __0qcD ) ;
 __0pcD = __062B____state -> err ;
 __0OeD = __0pcD ;
 if(! __0OeD )goto __0ocD ;
 __0ncD = "[ \033[31mERROR\033[0m ] " ;
 __0mcD = ".s\n" ;
 printf ( "%s" , __0ncD ); 
 __0lcD :
 printf ( "%.*s" ,( int ) name__length ,( char *) name__contents ); 
 __0kcD :
 printf ( "%s" , __0mcD ); 
 __0jcD :
 goto __0icD ;
 __0ocD :
 __0hcD = "[ \033[32mOK\033[0m ] " ;
 __0gcD = ".s\n" ;
 printf ( "%s" , __0hcD ); 
 __0fcD :
 printf ( "%.*s" ,( int ) name__length ,( char *) name__contents ); 
 __0ecD :
 printf ( "%s" , __0gcD ); 
 __0dcD :
 __0icD :
 __0ccD :
goto __return;

// ERROR HANDLING
__00cD :
 printf ( "%s\n" , __01cD ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0xcD :
 printf ( "String concatenation would corrupt one of the operands due to writing on its memory region - consider larger or non-overlapping circular buffers or arenas.\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0AdD :
 printf ( "%s\n" , __0BdD ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__error_code =__UNHANDLED__ERROR;
goto __failsafe ;
__0PfD :
 printf ( "String concatenation would corrupt one of the operands due to writing on its memory region - consider larger or non-overlapping circular buffers or arenas.\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0bcD :
__result__error_code=__UNHANDLED__ERROR;
goto __failsafe;
__0YdD :
 printf ( "%s\n" , __0ZdD ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__service_stack_floor_handler:
printf("Insufficient stack for safe service call (too much recursion or stack allocation)\n");
__result__error_code=__STACK__ERROR;
goto __failsafe;
__0SfD :
 printf ( "%s\n" , __0UfD ); 
__result__error_code=__USER__ERROR;
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
if ( __042B__acquired ) { for ( __0acD =0; __0acD < __0scD ;++ __0acD ) { __runtime_free ((( ptr **) __042B__acquired )[0][ __0acD ]); } __runtime_free ( __042B__acquired ); __042B__acquired =0; __0scD =0; __0rcD =0; } 
 if ( __042B__acquired ) { for ( __0acD =0; __0acD < __0scD ;++ __0acD ) { __runtime_free ((( ptr **) __042B__acquired )[0][ __0acD ]); } __runtime_free ( __042B__acquired ); __042B__acquired =0; __0scD =0; __0rcD =0; } 
if ( __0x2B__acquired ) { for ( __0JfD =0; __0JfD < __0HfD ;++ __0JfD ) { __runtime_free ((( ptr **) __0x2B__acquired )[0][ __0JfD ]); } __runtime_free ( __0x2B__acquired ); __0x2B__acquired =0; __0HfD =0; __0IfD =0; } 
 if ( __0x2B__acquired ) { for ( __0KfD =0; __0KfD < __0FfD ;++ __0KfD ) { __runtime_free ((( ptr **) __0x2B__acquired )[0][ __0KfD ]); } __runtime_free ( __0x2B__acquired ); __0x2B__acquired =0; __0FfD =0; __0GfD =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__error_code;
}


void std_test__383(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1864;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__383__state *__state=(struct std_test__383__state*)__void__state;
struct run__379__state* __0SzB____state = 0 ;
ptr name__contents= __state->name__contents;
u64 name__length= __state->name__length;
char name__first= __state->name__first;
ptr name__memory= __state->name__memory;
u64 __0ZiD=0;
u64 __0YiD=0;
cstr __0XiD=0;
u64 __0WiD=0;
u64 __0UiD=0;
u64 __0TiD=0;
u64 __0SiD=0;
ptr __0RiD=0;
u64 __0QiD=0;
cstr __0PiD=0;
u64 __0DiD=0;
u64 __0CiD=0;
u64 __0BiD=0;
cstr __07hD=0;
u64 __02hD=0;
ptr __00hD=0;
char __0xhD=0;
char __0diD=0;
u64 __0ciD=0;
ptr __0biD=0;
bool __0thD=0;
ptr __0aiD=0;
ptr __0QzB__acquired=0;
u64 __0eiD=0;
ptr __0JzB__acquired=0;
ptr command__memory=0;
char command__first=0;
bool __0ngD=0;
u64 __0mgD=0;
ptr __0lgD=0;
ptr __0kgD=0;
u64 command__length=0;
bool __0jgD=0;
ptr command__contents=0;
bool __0igD=0;
cstr __0fgD=0;
bool __0dgD=0;
ptr __0agD=0;
__new __0YgD=0;
__new __0XgD=0;
u64 __0WgD=0;
ptr __0VgD=0;
char __0UgD=0;
ptr __0TgD=0;
ptr __0SgD=0;
u64 __0RgD=0;
u64 __0QgD=0;
u64 __0PgD=0;
char __0OgD=0;
u64 __0NgD=0;
u64 __0MgD=0;
bool __0KgD=0;
bool __0JgD=0;
cstr __0GgD=0;
u64 __0EgD=0;
bool __0DgD=0;
u64 __0CgD=0;
ptr __0BgD=0;
ptr __0AgD=0;
bool __09fD=0;
bool __08fD=0;
cstr __05fD=0;
bool __03fD=0;
ptr __00fD=0;
__new __0yfD=0;
ptr __0xfD=0;
u64 __0wfD=0;
u64 __0vfD=0;
bool __0fiD=0;
__new command____0sC=0;
ptr __0ufD=0;
errcode __0tfD=0;
bool __0sfD=0;
cstr __0qfD=0;
cstr __0pfD=0;
cstr __0kfD=0;
cstr __0jfD=0;
__new name____0sC=0;
u64 __0dfD=0;

// IMPLEMENTATION
__0RiD = __runtime_alloc ( sizeof ( ptr **)); if ( __0RiD )(( ptr **) __0RiD )[0]=0; 
 __0SiD = 0 ;
 __0BiD = 0 ;
 __0JzB__acquired = __0RiD ;
 __0TiD = __0SiD ;
 __0UiD = __0BiD ;
 __0WiD = __0CiD ;
 __0XiD = "./smol tests/unit/" ;
 __07hD = ".s --workers 1 --runtime eager 2>&1" ;
 __0ZiD = strlen ( __0XiD ); __0aiD =( ptr ) __0XiD ; __0xhD = __0XiD [0]; __0biD =0; 
 __00hD = __0aiD ;
 __0QiD = __0ZiD ; __0DiD = name__length ; __0ciD = __0QiD + __0DiD ; __0diD = __0ZiD ? __0xhD : name__first ; 
 __02hD = 1 ;
 __0eiD = __0ciD + __02hD ; 
 __0OiD :
 __0fiD = __0JzB__acquired ;
 __0thD =(! __0fiD ); 
 __0giD :
 if(! __0thD )goto __0ViD ;
 __0PiD = "Did not initialize Dynamic" ;
 [[unlikely]] goto __0hiD ;
 __builtin_unreachable();
 __0ViD :
 __0YiD = __0TiD +1; __0ngD = true ; __0mgD = __0UiD ; if ( __0YiD >= __0UiD ) { __0UiD = __0UiD + __0UiD /2+1; __0lgD =( ptr )((( ptr **) __0JzB__acquired )[0]? __runtime_realloc ((( ptr **) __0JzB__acquired )[0], __0UiD * sizeof ( ptr ), __0mgD * sizeof ( ptr )): __runtime_alloc ( __0UiD * sizeof ( ptr ))); if (( __0ngD = __0lgD ))(( ptr **) __0JzB__acquired )[0]=( ptr *) __0lgD ; } if ( __0ngD ) { __0kgD =( ptr ) __runtime_alloc ( __0eiD ); if (( __0ngD = __0kgD )) {(( ptr **) __0JzB__acquired )[0][ __0TiD ]= __0kgD ; __0TiD = __0YiD ; } } 
 __0jgD = __0ngD ;
 __0igD =(! __0jgD ); 
 __0hgD :
 if(! __0igD )goto __0ggD ;
 __0fgD = "Failed a Dynamic allocation" ;
 [[unlikely]] goto __0egD ;
 __builtin_unreachable();
 __0ggD :
 __0dgD =(( char *) __0biD >=(( char *) __0kgD )&&( char *) __0biD <=(( char *) __0kgD )+ __0QiD )||((( char *) name__memory )+ __0QiD >=(( char *) __0kgD )&&( char *) name__memory <=(( char *) __0kgD )+ __0ciD ); 
 if(! __0dgD )goto __0cgD ;
 [[unlikely]] goto __0bgD ;
 __builtin_unreachable();
 __0cgD :
 memcpy (( char *) __0kgD ,( char *) __00hD , __0QiD ); memcpy (( char *) __0kgD + __0QiD ,( char *) name__contents , __0DiD );(( char *) __0kgD )[ __0ciD ]=0; 
 __0agD = __0kgD ;
 if ( __0JzB__acquired && __0agD )((( char *) __0agD )[ __0ciD ])=0; 
 __0ZgD :
 __0YgD = __0XgD ;
 __0JzB__acquired = __0JzB__acquired ;
 __0TiD = __0TiD ;
 __0UiD = __0UiD ;
 __0WiD = __0WiD ;
 __0WgD = strlen ( __07hD ); __0VgD =( ptr ) __07hD ; __0UgD = __07hD [0]; __0TgD =0; 
 __0SgD = __0VgD ;
 __0RgD = __0ciD ; __0QgD = __0WgD ; __0PgD = __0RgD + __0QgD ; __0OgD = __0ciD ? __0diD : __0UgD ; 
 __0NgD = 1 ;
 __0MgD = __0PgD + __0NgD ; 
 __0LgD :
 __0KgD = __0JzB__acquired ;
 __0JgD =(! __0KgD ); 
 __0IgD :
 if(! __0JgD )goto __0HgD ;
 __0GgD = "Did not initialize Dynamic" ;
 [[unlikely]] goto __0FgD ;
 __builtin_unreachable();
 __0HgD :
 __0EgD = __0TiD +1; __0DgD = true ; __0CgD = __0UiD ; if ( __0EgD >= __0UiD ) { __0UiD = __0UiD + __0UiD /2+1; __0BgD =( ptr )((( ptr **) __0JzB__acquired )[0]? __runtime_realloc ((( ptr **) __0JzB__acquired )[0], __0UiD * sizeof ( ptr ), __0CgD * sizeof ( ptr )): __runtime_alloc ( __0UiD * sizeof ( ptr ))); if (( __0DgD = __0BgD ))(( ptr **) __0JzB__acquired )[0]=( ptr *) __0BgD ; } if ( __0DgD ) { __0AgD =( ptr ) __runtime_alloc ( __0MgD ); if (( __0DgD = __0AgD )) {(( ptr **) __0JzB__acquired )[0][ __0TiD ]= __0AgD ; __0TiD = __0EgD ; } } 
 __09fD = __0DgD ;
 __08fD =(! __09fD ); 
 __07fD :
 if(! __08fD )goto __06fD ;
 __05fD = "Failed a Dynamic allocation" ;
 [[unlikely]] goto __04fD ;
 __builtin_unreachable();
 __06fD :
 __03fD =(( char *) __0JzB__acquired >=(( char *) __0AgD )&&( char *) __0JzB__acquired <=(( char *) __0AgD )+ __0RgD )||((( char *) __0TgD )+ __0RgD >=(( char *) __0AgD )&&( char *) __0TgD <=(( char *) __0AgD )+ __0PgD ); 
 if(! __03fD )goto __02fD ;
 [[unlikely]] goto __01fD ;
 __builtin_unreachable();
 __02fD :
 memcpy (( char *) __0AgD ,( char *) __0agD , __0RgD ); memcpy (( char *) __0AgD + __0RgD ,( char *) __0SgD , __0QgD );(( char *) __0AgD )[ __0PgD ]=0; 
 __00fD = __0AgD ;
 if ( __0JzB__acquired && __00fD )((( char *) __00fD )[ __0PgD ])=0; 
 __0zfD :
 __0YgD = __0yfD ;
 __0JzB__acquired = __0JzB__acquired ;
 __0TiD = __0TiD ;
 __0UiD = __0UiD ;
 __0WiD = __0WiD ;
 __0xfD = __runtime_alloc ( sizeof ( ptr **)); if ( __0xfD )(( ptr **) __0xfD )[0]=0; 
 __0wfD = 0 ;
 __0vfD = 0 ;
 __0QzB__acquired = __0xfD ;
 {char mark;if(__service_stack_floor+ 1196 >=(char*)&mark) goto __service_stack_floor_handler;} __0SzB____state = (struct run__379__state*)__runtime_calloc(sizeof(struct run__379__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0SzB____state ) ;
 __0SzB____state -> command____0sC = command____0sC ;
 __0SzB____state -> command__contents = __00fD ;
 __0SzB____state -> command__length = __0PgD ;
 __0SzB____state -> command__first = __0OgD ;
 __0SzB____state -> command__memory = __0JzB__acquired ;
 __0ufD = __smolambda_add_task ( run__379 , __0SzB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0ufD ) ;
 if( __0tfD ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __0ufD ) ;
 __0tfD = __0SzB____state -> err ;
 __0sfD = __0tfD ;
 if(! __0sfD )goto __0rfD ;
 __0qfD = "[ \033[31mERROR\033[0m ] " ;
 __0pfD = ".s\n" ;
 printf ( "%s" , __0qfD ); 
 __0ofD :
 printf ( "%.*s" ,( int ) name__length ,( char *) name__contents ); 
 __0nfD :
 printf ( "%s" , __0pfD ); 
 __0mfD :
 goto __0lfD ;
 __0rfD :
 __0kfD = "[ \033[32mOK\033[0m ] " ;
 __0jfD = ".s\n" ;
 printf ( "%s" , __0kfD ); 
 __0ifD :
 printf ( "%.*s" ,( int ) name__length ,( char *) name__contents ); 
 __0hfD :
 printf ( "%s" , __0jfD ); 
 __0gfD :
 __0lfD :
 __0ffD :
goto __return;

// ERROR HANDLING
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__error_code =__UNHANDLED__ERROR;
goto __failsafe ;
__0efD :
__result__error_code=__UNHANDLED__ERROR;
goto __failsafe;
__0FgD :
 printf ( "%s\n" , __0GgD ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__04fD :
 printf ( "%s\n" , __05fD ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0bgD :
 printf ( "String concatenation would corrupt one of the operands due to writing on its memory region - consider larger or non-overlapping circular buffers or arenas.\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0egD :
 printf ( "%s\n" , __0fgD ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__service_stack_floor_handler:
printf("Insufficient stack for safe service call (too much recursion or stack allocation)\n");
__result__error_code=__STACK__ERROR;
goto __failsafe;
__01fD :
 printf ( "String concatenation would corrupt one of the operands due to writing on its memory region - consider larger or non-overlapping circular buffers or arenas.\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0hiD :
 printf ( "%s\n" , __0PiD ); 
__result__error_code=__USER__ERROR;
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
if ( __0QzB__acquired ) { for ( __0dfD =0; __0dfD < __0wfD ;++ __0dfD ) { __runtime_free ((( ptr **) __0QzB__acquired )[0][ __0dfD ]); } __runtime_free ( __0QzB__acquired ); __0QzB__acquired =0; __0wfD =0; __0vfD =0; } 
 if ( __0QzB__acquired ) { for ( __0dfD =0; __0dfD < __0wfD ;++ __0dfD ) { __runtime_free ((( ptr **) __0QzB__acquired )[0][ __0dfD ]); } __runtime_free ( __0QzB__acquired ); __0QzB__acquired =0; __0wfD =0; __0vfD =0; } 
if ( __0JzB__acquired ) { for ( __0WiD =0; __0WiD < __0TiD ;++ __0WiD ) { __runtime_free ((( ptr **) __0JzB__acquired )[0][ __0WiD ]); } __runtime_free ( __0JzB__acquired ); __0JzB__acquired =0; __0TiD =0; __0UiD =0; } 
 if ( __0JzB__acquired ) { for ( __0CiD =0; __0CiD < __0SiD ;++ __0CiD ) { __runtime_free ((( ptr **) __0JzB__acquired )[0][ __0CiD ]); } __runtime_free ( __0JzB__acquired ); __0JzB__acquired =0; __0SiD =0; __0BiD =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__error_code;
}


void std_test__382(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1832;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__382__state *__state=(struct std_test__382__state*)__void__state;
struct run__379__state* __0nvB____state = 0 ;
cstr name= __state->name;
u64 __0nlD=0;
cstr __0mlD=0;
u64 __0glD=0;
ptr __0lvB__acquired=0;
u64 __0ykD=0;
ptr __0gkD=0;
u64 __0UkD=0;
char __0alD=0;
u64 __0dlD=0;
char __0YlD=0;
ptr __0blD=0;
u64 __0ZlD=0;
u64 __0SlD=0;
cstr __0VlD=0;
u64 __0QlD=0;
u64 __0TlD=0;
u64 __0elD=0;
ptr __0RlD=0;
bool __0clD=0;
bool __0NlD=0;
ptr __0IlD=0;
ptr __0LlD=0;
ptr __04jD=0;
char __0WlD=0;
ptr __0ilD=0;
char command__first=0;
cstr __0UlD=0;
u64 __0XlD=0;
bool __0jlD=0;
ptr command__memory=0;
u64 __0OlD=0;
ptr __0evB__acquired=0;
u64 __0MlD=0;
u64 __0PlD=0;
ptr __02kD=0;
u64 __05kD=0;
bool __0njD=0;
bool __0mjD=0;
cstr __0jjD=0;
bool __0hjD=0;
ptr __0ejD=0;
ptr __09kD=0;
__new __0cjD=0;
__new __0bjD=0;
u64 __0ajD=0;
ptr __0ZjD=0;
char __0YjD=0;
ptr __0XjD=0;
ptr __0WjD=0;
u64 __0TjD=0;
char __0SjD=0;
u64 __0RjD=0;
u64 __0QjD=0;
bool __0OjD=0;
bool __0NjD=0;
cstr __0KjD=0;
u64 __0IjD=0;
bool __0HjD=0;
u64 __0GjD=0;
ptr __0FjD=0;
ptr __0EjD=0;
bool __0DjD=0;
bool __0CjD=0;
u64 __0VjD=0;
u64 command__length=0;
cstr __09iD=0;
bool __07iD=0;
ptr __04iD=0;
__new __02iD=0;
ptr __01iD=0;
u64 __00iD=0;
u64 __0ziD=0;
u64 __0UjD=0;
ptr command__contents=0;
__new command____0sC=0;
ptr __0yiD=0;
errcode __0xiD=0;
bool __0wiD=0;
cstr __0uiD=0;
cstr __0tiD=0;
cstr __0oiD=0;
cstr __0niD=0;
u64 __0iiD=0;

// IMPLEMENTATION
__0LlD = __runtime_alloc ( sizeof ( ptr **)); if ( __0LlD )(( ptr **) __0LlD )[0]=0; 
 __0OlD = 0 ;
 __0MlD = 0 ;
 __0evB__acquired = __0LlD ;
 __0PlD = __0OlD ;
 __0QlD = __0MlD ;
 __0SlD = __0TlD ;
 __0UlD = "./smol tests/unit/" ;
 __0VlD = ".s --workers 1 --runtime eager 2>&1" ;
 __0XlD = strlen ( __0UlD ); __0gkD =( ptr ) __0UlD ; __0YlD = __0UlD [0]; __04jD =0; 
 __09kD = __0gkD ;
 __0ZlD = strlen ( name ); __02kD =( ptr ) name ; __0alD = name [0]; __0blD =0; 
 __0IlD = __02kD ;
 __0dlD = __0XlD ; __0elD = __0ZlD ; __05kD = __0dlD + __0elD ; __0WlD = __0XlD ? __0YlD : __0alD ; 
 __0ykD = 1 ;
 __0glD = __05kD + __0ykD ; 
 __0hlD :
 __0NlD = __0evB__acquired ;
 __0jlD =(! __0NlD ); 
 __0klD :
 if(! __0jlD )goto __0llD ;
 __0mlD = "Did not initialize Dynamic" ;
 [[unlikely]] goto __0flD ;
 __builtin_unreachable();
 __0llD :
 __0UkD = __0PlD +1; __0clD = true ; __0nlD = __0QlD ; if ( __0UkD >= __0QlD ) { __0QlD = __0QlD + __0QlD /2+1; __0ilD =( ptr )((( ptr **) __0evB__acquired )[0]? __runtime_realloc ((( ptr **) __0evB__acquired )[0], __0QlD * sizeof ( ptr ), __0nlD * sizeof ( ptr )): __runtime_alloc ( __0QlD * sizeof ( ptr ))); if (( __0clD = __0ilD ))(( ptr **) __0evB__acquired )[0]=( ptr *) __0ilD ; } if ( __0clD ) { __0RlD =( ptr ) __runtime_alloc ( __0glD ); if (( __0clD = __0RlD )) {(( ptr **) __0evB__acquired )[0][ __0PlD ]= __0RlD ; __0PlD = __0UkD ; } } 
 __0njD = __0clD ;
 __0mjD =(! __0njD ); 
 __0ljD :
 if(! __0mjD )goto __0kjD ;
 __0jjD = "Failed a Dynamic allocation" ;
 [[unlikely]] goto __0ijD ;
 __builtin_unreachable();
 __0kjD :
 __0hjD =(( char *) __04jD >=(( char *) __0RlD )&&( char *) __04jD <=(( char *) __0RlD )+ __0dlD )||((( char *) __0blD )+ __0dlD >=(( char *) __0RlD )&&( char *) __0blD <=(( char *) __0RlD )+ __05kD ); 
 if(! __0hjD )goto __0gjD ;
 [[unlikely]] goto __0fjD ;
 __builtin_unreachable();
 __0gjD :
 memcpy (( char *) __0RlD ,( char *) __09kD , __0dlD ); memcpy (( char *) __0RlD + __0dlD ,( char *) __0IlD , __0elD );(( char *) __0RlD )[ __05kD ]=0; 
 __0ejD = __0RlD ;
 if ( __0evB__acquired && __0ejD )((( char *) __0ejD )[ __05kD ])=0; 
 __0djD :
 __0cjD = __0bjD ;
 __0evB__acquired = __0evB__acquired ;
 __0PlD = __0PlD ;
 __0QlD = __0QlD ;
 __0SlD = __0SlD ;
 __0ajD = strlen ( __0VlD ); __0ZjD =( ptr ) __0VlD ; __0YjD = __0VlD [0]; __0XjD =0; 
 __0WjD = __0ZjD ;
 __0VjD = __05kD ; __0UjD = __0ajD ; __0TjD = __0VjD + __0UjD ; __0SjD = __05kD ? __0WlD : __0YjD ; 
 __0RjD = 1 ;
 __0QjD = __0TjD + __0RjD ; 
 __0PjD :
 __0OjD = __0evB__acquired ;
 __0NjD =(! __0OjD ); 
 __0MjD :
 if(! __0NjD )goto __0LjD ;
 __0KjD = "Did not initialize Dynamic" ;
 [[unlikely]] goto __0JjD ;
 __builtin_unreachable();
 __0LjD :
 __0IjD = __0PlD +1; __0HjD = true ; __0GjD = __0QlD ; if ( __0IjD >= __0QlD ) { __0QlD = __0QlD + __0QlD /2+1; __0FjD =( ptr )((( ptr **) __0evB__acquired )[0]? __runtime_realloc ((( ptr **) __0evB__acquired )[0], __0QlD * sizeof ( ptr ), __0GjD * sizeof ( ptr )): __runtime_alloc ( __0QlD * sizeof ( ptr ))); if (( __0HjD = __0FjD ))(( ptr **) __0evB__acquired )[0]=( ptr *) __0FjD ; } if ( __0HjD ) { __0EjD =( ptr ) __runtime_alloc ( __0QjD ); if (( __0HjD = __0EjD )) {(( ptr **) __0evB__acquired )[0][ __0PlD ]= __0EjD ; __0PlD = __0IjD ; } } 
 __0DjD = __0HjD ;
 __0CjD =(! __0DjD ); 
 __0BjD :
 if(! __0CjD )goto __0AjD ;
 __09iD = "Failed a Dynamic allocation" ;
 [[unlikely]] goto __08iD ;
 __builtin_unreachable();
 __0AjD :
 __07iD =(( char *) __0evB__acquired >=(( char *) __0EjD )&&( char *) __0evB__acquired <=(( char *) __0EjD )+ __0VjD )||((( char *) __0XjD )+ __0VjD >=(( char *) __0EjD )&&( char *) __0XjD <=(( char *) __0EjD )+ __0TjD ); 
 if(! __07iD )goto __06iD ;
 [[unlikely]] goto __05iD ;
 __builtin_unreachable();
 __06iD :
 memcpy (( char *) __0EjD ,( char *) __0ejD , __0VjD ); memcpy (( char *) __0EjD + __0VjD ,( char *) __0WjD , __0UjD );(( char *) __0EjD )[ __0TjD ]=0; 
 __04iD = __0EjD ;
 if ( __0evB__acquired && __04iD )((( char *) __04iD )[ __0TjD ])=0; 
 __03iD :
 __0cjD = __02iD ;
 __0evB__acquired = __0evB__acquired ;
 __0PlD = __0PlD ;
 __0QlD = __0QlD ;
 __0SlD = __0SlD ;
 __01iD = __runtime_alloc ( sizeof ( ptr **)); if ( __01iD )(( ptr **) __01iD )[0]=0; 
 __00iD = 0 ;
 __0ziD = 0 ;
 __0lvB__acquired = __01iD ;
 {char mark;if(__service_stack_floor+ 1196 >=(char*)&mark) goto __service_stack_floor_handler;} __0nvB____state = (struct run__379__state*)__runtime_calloc(sizeof(struct run__379__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0nvB____state ) ;
 __0nvB____state -> command____0sC = command____0sC ;
 __0nvB____state -> command__contents = __04iD ;
 __0nvB____state -> command__length = __0TjD ;
 __0nvB____state -> command__first = __0SjD ;
 __0nvB____state -> command__memory = __0evB__acquired ;
 __0yiD = __smolambda_add_task ( run__379 , __0nvB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0yiD ) ;
 if( __0xiD ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __0yiD ) ;
 __0xiD = __0nvB____state -> err ;
 __0wiD = __0xiD ;
 if(! __0wiD )goto __0viD ;
 __0uiD = "[ \033[31mERROR\033[0m ] " ;
 __0tiD = ".s\n" ;
 printf ( "%s" , __0uiD ); 
 __0siD :
 printf ( "%s" , name ); 
 __0riD :
 printf ( "%s" , __0tiD ); 
 __0qiD :
 goto __0piD ;
 __0viD :
 __0oiD = "[ \033[32mOK\033[0m ] " ;
 __0niD = ".s\n" ;
 printf ( "%s" , __0oiD ); 
 __0BlD :
 printf ( "%s" , name ); 
 __0miD :
 printf ( "%s" , __0niD ); 
 __0liD :
 __0piD :
 __0kiD :
goto __return;

// ERROR HANDLING
__0jiD :
__result__error_code=__UNHANDLED__ERROR;
goto __failsafe;
__08iD :
 printf ( "%s\n" , __09iD ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0fjD :
 printf ( "String concatenation would corrupt one of the operands due to writing on its memory region - consider larger or non-overlapping circular buffers or arenas.\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__error_code =__UNHANDLED__ERROR;
goto __failsafe ;
__05iD :
 printf ( "String concatenation would corrupt one of the operands due to writing on its memory region - consider larger or non-overlapping circular buffers or arenas.\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0JjD :
 printf ( "%s\n" , __0KjD ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0ijD :
 printf ( "%s\n" , __0jjD ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__service_stack_floor_handler:
printf("Insufficient stack for safe service call (too much recursion or stack allocation)\n");
__result__error_code=__STACK__ERROR;
goto __failsafe;
__0flD :
 printf ( "%s\n" , __0mlD ); 
__result__error_code=__USER__ERROR;
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
if ( __0lvB__acquired ) { for ( __0iiD =0; __0iiD < __00iD ;++ __0iiD ) { __runtime_free ((( ptr **) __0lvB__acquired )[0][ __0iiD ]); } __runtime_free ( __0lvB__acquired ); __0lvB__acquired =0; __00iD =0; __0ziD =0; } 
 if ( __0lvB__acquired ) { for ( __0iiD =0; __0iiD < __00iD ;++ __0iiD ) { __runtime_free ((( ptr **) __0lvB__acquired )[0][ __0iiD ]); } __runtime_free ( __0lvB__acquired ); __0lvB__acquired =0; __00iD =0; __0ziD =0; } 
if ( __0evB__acquired ) { for ( __0SlD =0; __0SlD < __0PlD ;++ __0SlD ) { __runtime_free ((( ptr **) __0evB__acquired )[0][ __0SlD ]); } __runtime_free ( __0evB__acquired ); __0evB__acquired =0; __0PlD =0; __0QlD =0; } 
 if ( __0evB__acquired ) { for ( __0TlD =0; __0TlD < __0OlD ;++ __0TlD ) { __runtime_free ((( ptr **) __0evB__acquired )[0][ __0TlD ]); } __runtime_free ( __0evB__acquired ); __0evB__acquired =0; __0OlD =0; __0MlD =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__error_code;
}


void run__379(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1196;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__379__state *__state=(struct run__379__state*)__void__state;
ptr command__contents= __state->command__contents;
u64 command__length= __state->command__length;
char command__first= __state->command__first;
ptr command__memory= __state->command__memory;
ptr __0EmD=0;
ptr __0BmD=0;
bool __0AmD=0;
bool __09lD=0;
ptr __0CmD=0;
__new command____0sC=0;
__new process____0onB=0;
ptr __04tB__contents=0;
ptr process__contents=0;
__new __0qlD=0;
i64 __0plD=0;

// IMPLEMENTATION
__0BmD = 0 ;
 __0CmD = __0BmD ;
 if ( command__memory && command__contents )((( char *) command__contents )[ command__length ])=0; 
 __0DmD :
 __04tB__contents =( ptr ) popen (( cstr ) command__contents , "r" ); 
 __0EmD = __04tB__contents ;
 __0AmD =( __0EmD ); 
 __0vlD :
 __09lD =(! __0AmD ); 
 __0ulD :
 if(! __09lD )goto __0tlD ;
 [[unlikely]] goto __0slD ;
 __builtin_unreachable();
 __0tlD :
 process__contents = __04tB__contents ;
 if ( process__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process__contents )) { } } 
 __0rlD :
 process____0onB = __0qlD ;
 __0plD =0; if ( process__contents ) __0plD = pclose (( FILE *) process__contents ); process__contents =0; if ( __0plD ) { if ( __0plD !=-1&& WIFEXITED ( __0plD )) __0plD = WEXITSTATUS ( __0plD ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __0plD ); __result__error_code = __USER__ERROR ; goto __failsafe ; } 
 __0olD :
goto __return;

// ERROR HANDLING
__0slD :
 printf ( "Error: Failed to start process\n" ); 
__result__error_code=__USER__ERROR;
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


void run__378(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1180;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__378__state *__state=(struct run__378__state*)__void__state;
cstr command= __state->command;
ptr __0hmD=0;
char __0gmD=0;
ptr __0fmD=0;
ptr __0emD=0;
__new process____0onB=0;
ptr __0StB__contents=0;
ptr __0ZmD=0;
ptr __0UmD=0;
u64 __0dmD=0;
ptr process__contents=0;
bool __0LmD=0;
bool __0kmD=0;
__new __0HmD=0;
ptr __0imD=0;
i64 __0GmD=0;

// IMPLEMENTATION
__0emD = 0 ;
 __0fmD = __0emD ;
 __0dmD = strlen ( command ); __0ZmD =( ptr ) command ; __0gmD = command [0]; __0hmD =0; 
 __0imD = __0ZmD ;
 if ( __0hmD && __0imD )((( char *) __0imD )[ __0dmD ])=0; 
 __0jmD :
 __0StB__contents =( ptr ) popen (( cstr ) __0imD , "r" ); 
 __0UmD = __0StB__contents ;
 __0kmD =( __0UmD ); 
 __0MmD :
 __0LmD =(! __0kmD ); 
 __0SmD :
 if(! __0LmD )goto __0KmD ;
 [[unlikely]] goto __0JmD ;
 __builtin_unreachable();
 __0KmD :
 process__contents = __0StB__contents ;
 if ( process__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process__contents )) { } } 
 __0ImD :
 process____0onB = __0HmD ;
 __0GmD =0; if ( process__contents ) __0GmD = pclose (( FILE *) process__contents ); process__contents =0; if ( __0GmD ) { if ( __0GmD !=-1&& WIFEXITED ( __0GmD )) __0GmD = WEXITSTATUS ( __0GmD ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __0GmD ); __result__error_code = __USER__ERROR ; goto __failsafe ; } 
 __0FmD :
goto __return;

// ERROR HANDLING
__0JmD :
 printf ( "Error: Failed to start process\n" ); 
__result__error_code=__USER__ERROR;
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


void all__385(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 12680;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct all__385__state *__state=(struct all__385__state*)__void__state;
struct std_test__382__state* __0Y6B____state = 0 ;
 struct std_test__382__state* __0a6B____state = 0 ;
 struct std_test__382__state* __0c6B____state = 0 ;
 struct std_test__382__state* __0e6B____state = 0 ;
 struct std_test__382__state* __0g6B____state = 0 ;
 struct std_test__382__state* __0i6B____state = 0 ;
 struct std_test__382__state* __0k6B____state = 0 ;
 struct std_test__382__state* __0m6B____state = 0 ;
 struct std_test__382__state* __0o6B____state = 0 ;
 struct std_test__382__state* __0q6B____state = 0 ;
 struct std_test__382__state* __0s6B____state = 0 ;
 struct std_test__382__state* __0u6B____state = 0 ;
 struct std_test__382__state* __0w6B____state = 0 ;
 struct std_test__382__state* __0y6B____state = 0 ;
 struct std_test__382__state* __006B____state = 0 ;
 struct std_test__382__state* __026B____state = 0 ;
 struct std_test__382__state* __046B____state = 0 ;
 struct std_test__382__state* __066B____state = 0 ;
 struct std_test__382__state* __086B____state = 0 ;
 struct std_test__382__state* __0A7B____state = 0 ;
 struct std_test__382__state* __0C7B____state = 0 ;
 struct std_test__382__state* __0E7B____state = 0 ;
 struct std_test__382__state* __0G7B____state = 0 ;
 struct std_test__382__state* __0I7B____state = 0 ;
 struct std_test__382__state* __0K7B____state = 0 ;
 struct std_test__382__state* __0M7B____state = 0 ;
 struct std_test__382__state* __0O7B____state = 0 ;
 struct std_test__382__state* __0Q7B____state = 0 ;
 struct std_test__382__state* __0S7B____state = 0 ;
 struct std_test__382__state* __0U7B____state = 0 ;
 struct std_test__382__state* __0W7B____state = 0 ;
 struct std_test__382__state* __0Y7B____state = 0 ;
cstr __0JoD=0;
ptr __0IoD=0;
errcode __0HoD=0;
cstr __0GoD=0;
ptr __0FoD=0;
errcode __0EoD=0;
cstr __0DoD=0;
ptr __0CoD=0;
errcode __0BoD=0;
cstr __0AoD=0;
ptr __09nD=0;
errcode __08nD=0;
cstr __07nD=0;
ptr __06nD=0;
errcode __05nD=0;
cstr __04nD=0;
ptr __03nD=0;
errcode __02nD=0;
cstr __01nD=0;
ptr __00nD=0;
errcode __0znD=0;
cstr __0ynD=0;
ptr __0xnD=0;
errcode __0wnD=0;
cstr __0vnD=0;
ptr __0unD=0;
errcode __0tnD=0;
cstr __0snD=0;
ptr __0rnD=0;
errcode __0qnD=0;
cstr __0pnD=0;
ptr __0onD=0;
errcode __0nnD=0;
cstr __0mnD=0;
ptr __0lnD=0;
errcode __0knD=0;
cstr __0jnD=0;
ptr __0inD=0;
errcode __0hnD=0;
cstr __0gnD=0;
ptr __0fnD=0;
errcode __0enD=0;
cstr __0dnD=0;
ptr __0cnD=0;
errcode __0bnD=0;
cstr __0anD=0;
ptr __0ZnD=0;
errcode __0YnD=0;
cstr __0XnD=0;
ptr __0WnD=0;
errcode __0VnD=0;
cstr __0UnD=0;
ptr __0TnD=0;
errcode __0SnD=0;
cstr __0RnD=0;
ptr __0QnD=0;
errcode __0PnD=0;
cstr __0OnD=0;
ptr __0NnD=0;
errcode __0MnD=0;
cstr __0LnD=0;
ptr __0KnD=0;
errcode __0JnD=0;
cstr __0InD=0;
ptr __0HnD=0;
errcode __0GnD=0;
cstr __0FnD=0;
ptr __0EnD=0;
errcode __0DnD=0;
cstr __0CnD=0;
ptr __0BnD=0;
errcode __0AnD=0;
cstr __09mD=0;
ptr __08mD=0;
errcode __07mD=0;
cstr __06mD=0;
ptr __05mD=0;
errcode __04mD=0;
cstr __03mD=0;
ptr __02mD=0;
errcode __01mD=0;
cstr __00mD=0;
ptr __0zmD=0;
errcode __0ymD=0;
cstr __0xmD=0;
ptr __0wmD=0;
errcode __0vmD=0;
cstr __0umD=0;
ptr __0tmD=0;
errcode __0smD=0;
cstr __0rmD=0;
ptr __0qmD=0;
errcode __0pmD=0;
cstr __0omD=0;
ptr __0nmD=0;
errcode __0mmD=0;

// IMPLEMENTATION
__0JoD = "buffers/buffer" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0Y6B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0Y6B____state ) ;
 __0Y6B____state -> name = __0JoD ;
 __0IoD = __smolambda_add_task ( std_test__382 , __0Y6B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0IoD ) ;
 if( __0HoD ) goto  __result_unhandled_error ;
 __0GoD = "buffers/bbuffer" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0a6B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0a6B____state ) ;
 __0a6B____state -> name = __0GoD ;
 __0FoD = __smolambda_add_task ( std_test__382 , __0a6B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0FoD ) ;
 if( __0EoD ) goto  __result_unhandled_error ;
 __0DoD = "buffers/bufferconst" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0c6B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0c6B____state ) ;
 __0c6B____state -> name = __0DoD ;
 __0CoD = __smolambda_add_task ( std_test__382 , __0c6B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0CoD ) ;
 if( __0BoD ) goto  __result_unhandled_error ;
 __0AoD = "buffers/buffergrow" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0e6B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0e6B____state ) ;
 __0e6B____state -> name = __0AoD ;
 __09nD = __smolambda_add_task ( std_test__382 , __0e6B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __09nD ) ;
 if( __08nD ) goto  __result_unhandled_error ;
 __07nD = "buffers/retbuffer" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0g6B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0g6B____state ) ;
 __0g6B____state -> name = __07nD ;
 __06nD = __smolambda_add_task ( std_test__382 , __0g6B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __06nD ) ;
 if( __05nD ) goto  __result_unhandled_error ;
 __04nD = "buffers/servbuf" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0i6B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0i6B____state ) ;
 __0i6B____state -> name = __04nD ;
 __03nD = __smolambda_add_task ( std_test__382 , __0i6B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __03nD ) ;
 if( __02nD ) goto  __result_unhandled_error ;
 __01nD = "resources/dynamic" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0k6B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0k6B____state ) ;
 __0k6B____state -> name = __01nD ;
 __00nD = __smolambda_add_task ( std_test__382 , __0k6B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __00nD ) ;
 if( __0znD ) goto  __result_unhandled_error ;
 __0ynD = "resources/effvec" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0m6B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0m6B____state ) ;
 __0m6B____state -> name = __0ynD ;
 __0xnD = __smolambda_add_task ( std_test__382 , __0m6B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0xnD ) ;
 if( __0wnD ) goto  __result_unhandled_error ;
 __0vnD = "resources/fail" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0o6B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0o6B____state ) ;
 __0o6B____state -> name = __0vnD ;
 __0unD = __smolambda_add_task ( std_test__382 , __0o6B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0unD ) ;
 if( __0tnD ) goto  __result_unhandled_error ;
 __0snD = "resources/file" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0q6B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0q6B____state ) ;
 __0q6B____state -> name = __0snD ;
 __0rnD = __smolambda_add_task ( std_test__382 , __0q6B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0rnD ) ;
 if( __0qnD ) goto  __result_unhandled_error ;
 __0pnD = "resources/filesize" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0s6B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0s6B____state ) ;
 __0s6B____state -> name = __0pnD ;
 __0onD = __smolambda_add_task ( std_test__382 , __0s6B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0onD ) ;
 if( __0nnD ) goto  __result_unhandled_error ;
 __0mnD = "resources/finally" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0u6B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0u6B____state ) ;
 __0u6B____state -> name = __0mnD ;
 __0lnD = __smolambda_add_task ( std_test__382 , __0u6B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0lnD ) ;
 if( __0knD ) goto  __result_unhandled_error ;
 __0jnD = "resources/mem" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0w6B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0w6B____state ) ;
 __0w6B____state -> name = __0jnD ;
 __0inD = __smolambda_add_task ( std_test__382 , __0w6B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0inD ) ;
 if( __0hnD ) goto  __result_unhandled_error ;
 __0gnD = "resources/memtest" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0y6B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0y6B____state ) ;
 __0y6B____state -> name = __0gnD ;
 __0fnD = __smolambda_add_task ( std_test__382 , __0y6B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0fnD ) ;
 if( __0enD ) goto  __result_unhandled_error ;
 __0dnD = "resources/map" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __006B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __006B____state ) ;
 __006B____state -> name = __0dnD ;
 __0cnD = __smolambda_add_task ( std_test__382 , __006B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0cnD ) ;
 if( __0bnD ) goto  __result_unhandled_error ;
 __0anD = "resources/ref" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __026B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __026B____state ) ;
 __026B____state -> name = __0anD ;
 __0ZnD = __smolambda_add_task ( std_test__382 , __026B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0ZnD ) ;
 if( __0YnD ) goto  __result_unhandled_error ;
 __0XnD = "resources/strcat" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __046B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __046B____state ) ;
 __046B____state -> name = __0XnD ;
 __0WnD = __smolambda_add_task ( std_test__382 , __046B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0WnD ) ;
 if( __0VnD ) goto  __result_unhandled_error ;
 __0UnD = "resources/vec" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __066B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __066B____state ) ;
 __066B____state -> name = __0UnD ;
 __0TnD = __smolambda_add_task ( std_test__382 , __066B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0TnD ) ;
 if( __0SnD ) goto  __result_unhandled_error ;
 __0RnD = "resources/virtfile" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __086B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __086B____state ) ;
 __086B____state -> name = __0RnD ;
 __0QnD = __smolambda_add_task ( std_test__382 , __086B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0QnD ) ;
 if( __0PnD ) goto  __result_unhandled_error ;
 __0OnD = "service/fib" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0A7B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0A7B____state ) ;
 __0A7B____state -> name = __0OnD ;
 __0NnD = __smolambda_add_task ( std_test__382 , __0A7B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0NnD ) ;
 if( __0MnD ) goto  __result_unhandled_error ;
 __0LnD = "service/infinite" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0C7B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0C7B____state ) ;
 __0C7B____state -> name = __0LnD ;
 __0KnD = __smolambda_add_task ( std_test__382 , __0C7B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0KnD ) ;
 if( __0JnD ) goto  __result_unhandled_error ;
 __0InD = "types/accessvar" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0E7B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0E7B____state ) ;
 __0E7B____state -> name = __0InD ;
 __0HnD = __smolambda_add_task ( std_test__382 , __0E7B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0HnD ) ;
 if( __0GnD ) goto  __result_unhandled_error ;
 __0FnD = "types/circ" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0G7B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0G7B____state ) ;
 __0G7B____state -> name = __0FnD ;
 __0EnD = __smolambda_add_task ( std_test__382 , __0G7B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0EnD ) ;
 if( __0DnD ) goto  __result_unhandled_error ;
 __0CnD = "types/dataunion" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0I7B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0I7B____state ) ;
 __0I7B____state -> name = __0CnD ;
 __0BnD = __smolambda_add_task ( std_test__382 , __0I7B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0BnD ) ;
 if( __0AnD ) goto  __result_unhandled_error ;
 __09mD = "types/mutpoint" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0K7B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0K7B____state ) ;
 __0K7B____state -> name = __09mD ;
 __08mD = __smolambda_add_task ( std_test__382 , __0K7B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __08mD ) ;
 if( __07mD ) goto  __result_unhandled_error ;
 __06mD = "types/nom" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0M7B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0M7B____state ) ;
 __0M7B____state -> name = __06mD ;
 __05mD = __smolambda_add_task ( std_test__382 , __0M7B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __05mD ) ;
 if( __04mD ) goto  __result_unhandled_error ;
 __03mD = "types/poly" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0O7B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0O7B____state ) ;
 __0O7B____state -> name = __03mD ;
 __02mD = __smolambda_add_task ( std_test__382 , __0O7B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __02mD ) ;
 if( __01mD ) goto  __result_unhandled_error ;
 __00mD = "types/pong" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0Q7B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0Q7B____state ) ;
 __0Q7B____state -> name = __00mD ;
 __0zmD = __smolambda_add_task ( std_test__382 , __0Q7B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0zmD ) ;
 if( __0ymD ) goto  __result_unhandled_error ;
 __0xmD = "types/range_test" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0S7B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0S7B____state ) ;
 __0S7B____state -> name = __0xmD ;
 __0wmD = __smolambda_add_task ( std_test__382 , __0S7B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0wmD ) ;
 if( __0vmD ) goto  __result_unhandled_error ;
 __0umD = "types/union" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0U7B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0U7B____state ) ;
 __0U7B____state -> name = __0umD ;
 __0tmD = __smolambda_add_task ( std_test__382 , __0U7B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0tmD ) ;
 if( __0smD ) goto  __result_unhandled_error ;
 __0rmD = "types/units" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0W7B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0W7B____state ) ;
 __0W7B____state -> name = __0rmD ;
 __0qmD = __smolambda_add_task ( std_test__382 , __0W7B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0qmD ) ;
 if( __0pmD ) goto  __result_unhandled_error ;
 __0omD = "sgn" ;
 {char mark;if(__service_stack_floor+ 1868 >=(char*)&mark) goto __service_stack_floor_handler;} __0Y7B____state = (struct std_test__382__state*)__runtime_calloc(sizeof(struct std_test__382__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0Y7B____state ) ;
 __0Y7B____state -> name = __0omD ;
 __0nmD = __smolambda_add_task ( std_test__382 , __0Y7B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0nmD ) ;
 if( __0mmD ) goto  __result_unhandled_error ;
 __0lmD :
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


void run__380(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1552;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__380__state *__state=(struct run__380__state*)__void__state;
ptr command__contents= __state->command__contents;
u64 command__length= __state->command__length;
char command__first= __state->command__first;
ptr command__memory= __state->command__memory;
bool __0hYE=0;
ptr process____0MsB=0;
ptr __0eYE=0;
u64 __0bYE=0;
ptr __0SYE=0;
u64 __0fYE=0;
ptr process____0FsB__mem=0;
ptr process____0JsB__contents=0;
ptr process____02sB=0;
u64 process__command__length=0;
u64 process____0isB=0;
ptr process__command__contents=0;
char process__command__first=0;
ptr __0PYE=0;
ptr __0buB____0JsB__contents=0;
u64 process____0YsB=0;
u64 process____0osB=0;
__new process__command____0pC=0;
bool __01XE=0;
bool __0RYE=0;
ptr process____0ysB=0;
ptr __0HYE=0;
ptr process____0ssB=0;
bool __0KYE=0;
bool process____01sB=0;
u64 process____04sB=0;
__new process____0JsB____0onB=0;
bool process____0lsB=0;
char __0yXE=0;
ptr process____0vsB=0;
char process__first=0;
ptr __07XE=0;
bool process____0ksB=0;
char __0FYE=0;
ptr process____0usB=0;
ptr __04XE=0;
u64 __0xXE=0;
u64 __06XE=0;
char process____0hsB=0;
u64 process____0bsB=0;
__new __0wXE=0;
__new process____0gsB=0;
bool process____0qsB=0;
cstr process____0nsB=0;
cstr __0tXE=0;
ptr process____0LsB=0;
__new command____0pC=0;
cstr __0qXE=0;
ptr __0pXE=0;
ptr __0nXE=0;
i64 __0mXE=0;
i64 process____0KsB=0;
cstr process__mem=0;
ptr process__command__memory=0;

// IMPLEMENTATION
__0PYE = 0 ;
 __0eYE = __0PYE ;
 __06XE = 1 ;
 __0bYE = command__length + __06XE ; 
 __0vXE :
 __0fYE = __0bYE ; __0SYE =( __0fYE + __service_stack_floor >=( char *)& __0fYE )?0: alloca ( __0fYE ); 
 __0hYE = __0SYE ;
 __0KYE =(! __0hYE ); 
 __0uXE :
 if(! __0KYE )goto __0sXE ;
 __0tXE = "Insufficient stack for allocation (too much recursion or stack allocation, or zero size requested)" ;
 [[unlikely]] goto __0rXE ;
 __builtin_unreachable();
 __0sXE :
 __0yXE =0; if ( __0SYE ) { memcpy (( char *) __0SYE , command__contents , command__length );(( char *) __0SYE )[ command__length ]=0; } __0qXE =( const char *) __0SYE ; 
 __04XE = 0 ;
 __0xXE = strlen ( __0qXE ); __07XE =( ptr ) __0qXE ; __0FYE = __0qXE [0]; __0HYE =0; 
 __0pXE = __07XE ;
 if ( __0HYE && __0pXE )((( char *) __0pXE )[ __0xXE ])=0; 
 __0oXE :
 __0buB____0JsB__contents =( ptr ) popen (( cstr ) __0pXE , "r" ); 
 __0nXE = __0buB____0JsB__contents ;
 __01XE =( __0nXE ); 
 __0NYE :
 __0RYE =(! __01XE ); 
 __0OYE :
 if(! __0RYE )goto __0aYE ;
 [[unlikely]] goto __0CYE ;
 __builtin_unreachable();
 __0aYE :
 __TRANSIENT( __0SYE )
 process____0JsB__contents = __0buB____0JsB__contents ;
 if ( process____0JsB__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process____0JsB__contents )) { } } 
 __0zXE :
 process____0JsB____0onB = __0wXE ;
 __0mXE =0; if ( process____0JsB__contents ) __0mXE = pclose (( FILE *) process____0JsB__contents ); process____0JsB__contents =0; if ( __0mXE ) { if ( __0mXE !=-1&& WIFEXITED ( __0mXE )) __0mXE = WEXITSTATUS ( __0mXE ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __0mXE ); __result__error_code = __USER__ERROR ; goto __failsafe ; } 
 __0lXE :
goto __return;

// ERROR HANDLING
__0rXE :
 printf ( "%s\n" , __0tXE ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0CYE :
 printf ( "Error: Failed to start process\n" ); 
__result__error_code=__USER__ERROR;
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


void main__386(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 12392;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__386__state *__state=(struct main__386__state*)__void__state;
struct all__385__state* __0bsC____state = 0 ;
f64 __0wYE=0;
ptr __0uYE=0;
errcode __0tYE=0;
cstr __0sYE=0;
f64 __0qYE=0;
f64 __0oYE=0;
cstr __0lYE=0;

// IMPLEMENTATION
__0wYE = __smo_time_eta (); 
 __0vYE :
 {char mark;if(__service_stack_floor+ 12680 >=(char*)&mark) goto __service_stack_floor_handler;} __0bsC____state = (struct all__385__state*)__runtime_calloc(sizeof(struct all__385__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0bsC____state ) ;
 __0uYE = __smolambda_add_task ( all__385 , __0bsC____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0uYE ) ;
 if( __0tYE ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __0uYE ) ;
 __0tYE = __0bsC____state -> err ;
 __0sYE = "Completed in " ;
 printf ( "%s" , __0sYE ); 
 __0rYE :
 __0qYE = __smo_time_eta (); 
 __0pYE :
 __0oYE = __0qYE - __0wYE ; 
 __0nYE :
 printf ( "%.6f" , __0oYE ); 
 __0mYE :
 __0lYE = " sec" ;
 printf ( "%s\n" , __0lYE ); 
 __0kYE :
 __0jYE :
goto __return;

// ERROR HANDLING
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__error_code =__UNHANDLED__ERROR;
goto __failsafe ;
__0iYE :
__result__error_code=__UNHANDLED__ERROR;
goto __failsafe;
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
struct main__386__state __main_args={0};
__smolambda_initialize_service_tasks(main__386, &__main_args);
return __main_args.err;
}

