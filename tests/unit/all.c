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
#define __IS_nominal 9
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
typedef uint64_t tag;
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

struct main__933__state{errcode err;};
__externc void main__933(void *__void__state);
struct std_test__929__state{errcode err;cstr name;};
__externc void std_test__929(void *__void__state);
struct std_test__930__state{errcode err;nominal name____FC;ptr name__contents;u64 name__length;char name__first;ptr name__memory;};
__externc void std_test__930(void *__void__state);
struct std_test__931__state{errcode err;nominal name____CC;ptr name__contents;u64 name__length;char name__first;ptr name__memory;};
__externc void std_test__931(void *__void__state);
struct all__932__state{errcode err;};
__externc void all__932(void *__void__state);
struct run__925__state{errcode err;cstr command;};
__externc void run__925(void *__void__state);
struct run__926__state{errcode err;nominal command____FC;ptr command__contents;u64 command__length;char command__first;ptr command__memory;};
__externc void run__926(void *__void__state);
struct run__927__state{errcode err;nominal command____CC;ptr command__contents;u64 command__length;char command__first;ptr command__memory;};
__externc void run__927(void *__void__state);

void run__927(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1568;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__927__state *__state=(struct run__927__state*)__void__state;
ptr command__contents= __state->command__contents;
u64 command__length= __state->command__length;
char command__first= __state->command__first;
ptr command__memory= __state->command__memory;
ptr process__command__contents=0;
u64 __YrJ=0;
ptr __XrJ=0;
char __WrJ=0;
ptr __brJ=0;
nominal process____K5G____blG=0;
nominal command____CC=0;
ptr __R7G____K5G__contents=0;
char process____x5G=0;
cstr process__mem=0;
char process__command__first=0;
u64 process____25G=0;
i64 process____L5G=0;
u64 __MrJ=0;
u64 __arJ=0;
ptr process____K5G__contents=0;
ptr __JrJ=0;
ptr process____w5G=0;
char __ErJ=0;
ptr process____T5G=0;
ptr process____G5G__mem=0;
char __RrJ=0;
ptr process____R5G=0;
ptr __UrJ=0;
nominal process__command____CC=0;
char __ArJ=0;
u64 process__command__length=0;
ptr __HrJ=0;
bool __7qJ=0;
ptr __OrJ=0;
u64 __GrJ=0;
bool process____y5G=0;
char process____55G=0;
cstr __ZrJ=0;
ptr process__command__memory=0;
ptr __FrJ=0;
cstr process____15G=0;
nominal process____W5G=0;
u64 process____t5G=0;
u64 __wqJ=0;
bool process____65G=0;
bool process____B6G=0;
ptr process____A6G=0;
ptr process____75G=0;
bool process____z5G=0;
char process____95G=0;
u64 process____85G=0;
u64 process____r5G=0;
u64 process____Q5G=0;
char process____h5G=0;
ptr process____p5G=0;
ptr __oqJ=0;
bool __DrJ=0;
bool __nqJ=0;
bool __mqJ=0;
cstr __lqJ=0;
u64 process____n5G=0;
char __crJ=0;
ptr process____b5G=0;
nominal __kqJ=0;
char process__first=0;
i64 __jqJ=0;

// IMPLEMENTATION
__XrJ = 0 ;
 __UrJ = __XrJ ;
 __arJ = 1 ;
 __GrJ = command__length + __arJ ; 
 __qqJ :
 __ArJ = 0 ;
 __RrJ = __ArJ ;
 __wqJ = __GrJ * sizeof ( __RrJ ); __oqJ =( __wqJ + __service_stack_floor >=( char *)& __wqJ )?0: alloca ( __wqJ ); 
 __nqJ = __oqJ ;
 __mqJ =(! __nqJ ); 
 __5qJ :
 if(! __mqJ )goto __8qJ ;
 __lqJ = "Insufficient stack for allocation (too much recursion or stack allocatio, or zero size requested)" ;
 goto __erJ ;
 __builtin_unreachable();
 __8qJ :
 __ErJ = 0 ;
 __MrJ = sizeof ( __ErJ )* __GrJ ; 
 __drJ :
 __RrJ = __ErJ ;
 __WrJ =0; if ( __oqJ ) { memcpy (( char *) __oqJ , command__contents , command__length );(( char *) __oqJ )[ command__length ]=0; } __ZrJ =( const char *) __oqJ ; 
 __brJ = 0 ;
 __YrJ = strlen ( __ZrJ ); __JrJ =( ptr ) __ZrJ ; __crJ = __ZrJ [0]; __FrJ =( ptr ) __FrJ ; 
 __OrJ = __JrJ ;
 __R7G____K5G__contents =( ptr ) popen (( cstr ) __OrJ , "r" ); 
 __HrJ = __R7G____K5G__contents ;
 __DrJ =( __HrJ ); 
 __pqJ :
 __7qJ =(! __DrJ ); 
 __CrJ :
 if(! __7qJ )goto __SrJ ;
 goto __frJ ;
 __builtin_unreachable();
 __SrJ :
 __TRANSIENT( __oqJ )
 process____K5G__contents = __R7G____K5G__contents ;
 if ( process____K5G__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process____K5G__contents )) { } } 
 __TrJ :
 process____K5G____blG = __kqJ ;
 __jqJ =0; if ( process____K5G__contents ) __jqJ = pclose (( FILE *) process____K5G__contents ); process____K5G__contents =0; if ( __jqJ ) { if ( __jqJ !=-1&& WIFEXITED ( __jqJ )) __jqJ = WEXITSTATUS ( __jqJ ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __jqJ ); __result__error_code = __USER__ERROR ; goto __failsafe ; } 
 __iqJ :
goto __return;

// ERROR HANDLING
__erJ :
 printf ( "%s\n" , __lqJ ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__frJ :
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


void run__926(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1180;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__926__state *__state=(struct run__926__state*)__void__state;
ptr command__contents= __state->command__contents;
u64 command__length= __state->command__length;
char command__first= __state->command__first;
ptr command__memory= __state->command__memory;
bool __0rJ=0;
ptr __zrJ=0;
bool __yrJ=0;
ptr process__contents=0;
ptr __wrJ=0;
nominal process____blG=0;
ptr __srJ=0;
ptr __z6G__contents=0;
nominal __irJ=0;
nominal command____FC=0;
i64 __hrJ=0;

// IMPLEMENTATION
__srJ = 0 ;
 __wrJ = __srJ ;
 __z6G__contents =( ptr ) popen (( cstr ) command__contents , "r" ); 
 __zrJ = __z6G__contents ;
 __0rJ =( __zrJ ); 
 __vrJ :
 __yrJ =(! __0rJ ); 
 __1rJ :
 if(! __yrJ )goto __2rJ ;
 goto __jrJ ;
 __builtin_unreachable();
 __2rJ :
 process__contents = __z6G__contents ;
 if ( process__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process__contents )) { } } 
 __xrJ :
 process____blG = __irJ ;
 __hrJ =0; if ( process__contents ) __hrJ = pclose (( FILE *) process__contents ); process__contents =0; if ( __hrJ ) { if ( __hrJ !=-1&& WIFEXITED ( __hrJ )) __hrJ = WEXITSTATUS ( __hrJ ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __hrJ ); __result__error_code = __USER__ERROR ; goto __failsafe ; } 
 __grJ :
goto __return;

// ERROR HANDLING
__jrJ :
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


void all__932(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 19124;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct all__932__state *__state=(struct all__932__state*)__void__state;
struct std_test__929__state* __jUH____state = 0 ;
 struct std_test__929__state* __lUH____state = 0 ;
 struct std_test__929__state* __nUH____state = 0 ;
 struct std_test__929__state* __pUH____state = 0 ;
 struct std_test__929__state* __rUH____state = 0 ;
 struct std_test__929__state* __tUH____state = 0 ;
 struct std_test__929__state* __vUH____state = 0 ;
 struct std_test__929__state* __xUH____state = 0 ;
 struct std_test__929__state* __zUH____state = 0 ;
 struct std_test__929__state* __1UH____state = 0 ;
 struct std_test__929__state* __3UH____state = 0 ;
 struct std_test__929__state* __5UH____state = 0 ;
 struct std_test__929__state* __7UH____state = 0 ;
 struct std_test__929__state* __9UH____state = 0 ;
 struct std_test__929__state* __BVH____state = 0 ;
 struct std_test__929__state* __DVH____state = 0 ;
 struct std_test__929__state* __FVH____state = 0 ;
 struct std_test__929__state* __HVH____state = 0 ;
 struct std_test__929__state* __JVH____state = 0 ;
 struct std_test__929__state* __LVH____state = 0 ;
 struct std_test__929__state* __NVH____state = 0 ;
 struct std_test__929__state* __PVH____state = 0 ;
 struct std_test__929__state* __RVH____state = 0 ;
 struct std_test__929__state* __TVH____state = 0 ;
 struct std_test__929__state* __VVH____state = 0 ;
 struct std_test__929__state* __XVH____state = 0 ;
 struct std_test__929__state* __ZVH____state = 0 ;
 struct std_test__929__state* __bVH____state = 0 ;
 struct std_test__929__state* __dVH____state = 0 ;
ptr __UrK=0;
ptr __RrK=0;
ptr __5lK=0;
cstr __RiK=0;
errcode __NiK=0;
cstr __C8J=0;
ptr __4oK=0;
cstr __y7J=0;
ptr __qnK=0;
ptr __ZpK=0;
cstr __UpK=0;
ptr __QpK=0;
ptr __8oK=0;
errcode __KpK=0;
ptr __EpK=0;
ptr __fyJ=0;
cstr __4xJ=0;
cstr __ywJ=0;
errcode __kwJ=0;
cstr __IqK=0;
errcode __LqK=0;
errcode __OqK=0;
ptr __FqK=0;
errcode __yrK=0;
cstr __1rK=0;
cstr __4rK=0;
errcode __vrK=0;
ptr __prK=0;
cstr __srK=0;
ptr __jrK=0;
ptr __mrK=0;
cstr __osJ=0;
errcode __nsJ=0;
errcode __7pK=0;
cstr __msJ=0;
errcode __lsJ=0;
cstr __ksJ=0;
ptr __jsJ=0;
ptr __3pK=0;
cstr __isJ=0;
ptr __hsJ=0;
errcode __gsJ=0;
cstr __fsJ=0;
cstr __zpK=0;
ptr __esJ=0;
errcode __dsJ=0;
cstr __csJ=0;
errcode __bsJ=0;
ptr __vpK=0;
cstr __asJ=0;
ptr __ZsJ=0;
errcode __YsJ=0;
cstr __XsJ=0;
errcode __rpK=0;
ptr __WsJ=0;
errcode __VsJ=0;
cstr __UsJ=0;
ptr __TsJ=0;
ptr __npK=0;
errcode __SsJ=0;
cstr __RsJ=0;
errcode __QsJ=0;
cstr __PsJ=0;
errcode __OsJ=0;
errcode __arK=0;
cstr __NsJ=0;
cstr __MsJ=0;
errcode __LsJ=0;
cstr __KsJ=0;
ptr __JsJ=0;
errcode __IsJ=0;
errcode __HsJ=0;
ptr __GsJ=0;
cstr __FsJ=0;
errcode __EsJ=0;
errcode __grK=0;
errcode __DsJ=0;
ptr __CsJ=0;
cstr __BsJ=0;
ptr __AsJ=0;
cstr __9rJ=0;
errcode __XrK=0;
ptr __8rJ=0;
errcode __7rJ=0;
cstr __6rJ=0;
ptr __5rJ=0;
errcode __4rJ=0;

// IMPLEMENTATION
__osJ = "buffers/buffer" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __jUH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __jUH____state ) ;
 __jUH____state -> name = __osJ ;
 __4oK = __smolambda_add_task ( std_test__929 , __jUH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __4oK ) ;
 if( __nsJ ) goto  __result_unhandled_error ;
 __msJ = "buffers/bbuffer" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __lUH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __lUH____state ) ;
 __lUH____state -> name = __msJ ;
 __8oK = __smolambda_add_task ( std_test__929 , __lUH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __8oK ) ;
 if( __NiK ) goto  __result_unhandled_error ;
 __RiK = "buffers/bufferconst" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __nUH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __nUH____state ) ;
 __nUH____state -> name = __RiK ;
 __EpK = __smolambda_add_task ( std_test__929 , __nUH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __EpK ) ;
 if( __lsJ ) goto  __result_unhandled_error ;
 __1rK = "buffers/buffergrow" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __pUH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __pUH____state ) ;
 __pUH____state -> name = __1rK ;
 __UrK = __smolambda_add_task ( std_test__929 , __pUH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __UrK ) ;
 if( __KpK ) goto  __result_unhandled_error ;
 __ksJ = "buffers/retbuffer" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __rUH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __rUH____state ) ;
 __rUH____state -> name = __ksJ ;
 __jsJ = __smolambda_add_task ( std_test__929 , __rUH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __jsJ ) ;
 if( __arK ) goto  __result_unhandled_error ;
 __isJ = "buffers/servbuf" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __tUH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __tUH____state ) ;
 __tUH____state -> name = __isJ ;
 __hsJ = __smolambda_add_task ( std_test__929 , __tUH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __hsJ ) ;
 if( __gsJ ) goto  __result_unhandled_error ;
 __fsJ = "resources/dynamic" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __vUH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __vUH____state ) ;
 __vUH____state -> name = __fsJ ;
 __RrK = __smolambda_add_task ( std_test__929 , __vUH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __RrK ) ;
 if( __grK ) goto  __result_unhandled_error ;
 __C8J = "resources/effvec" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __xUH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __xUH____state ) ;
 __xUH____state -> name = __C8J ;
 __esJ = __smolambda_add_task ( std_test__929 , __xUH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __esJ ) ;
 if( __XrK ) goto  __result_unhandled_error ;
 __y7J = "resources/fail" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __zUH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __zUH____state ) ;
 __zUH____state -> name = __y7J ;
 __mrK = __smolambda_add_task ( std_test__929 , __zUH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __mrK ) ;
 if( __dsJ ) goto  __result_unhandled_error ;
 __csJ = "resources/file" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __1UH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __1UH____state ) ;
 __1UH____state -> name = __csJ ;
 __ZpK = __smolambda_add_task ( std_test__929 , __1UH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __ZpK ) ;
 if( __bsJ ) goto  __result_unhandled_error ;
 __asJ = "resources/filesize" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __3UH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __3UH____state ) ;
 __3UH____state -> name = __asJ ;
 __ZsJ = __smolambda_add_task ( std_test__929 , __3UH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __ZsJ ) ;
 if( __YsJ ) goto  __result_unhandled_error ;
 __XsJ = "resources/finally" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __5UH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __5UH____state ) ;
 __5UH____state -> name = __XsJ ;
 __WsJ = __smolambda_add_task ( std_test__929 , __5UH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __WsJ ) ;
 if( __VsJ ) goto  __result_unhandled_error ;
 __4xJ = "resources/mem" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __7UH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __7UH____state ) ;
 __7UH____state -> name = __4xJ ;
 __qnK = __smolambda_add_task ( std_test__929 , __7UH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __qnK ) ;
 if( __kwJ ) goto  __result_unhandled_error ;
 __UsJ = "resources/memtest" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __9UH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __9UH____state ) ;
 __9UH____state -> name = __UsJ ;
 __jrK = __smolambda_add_task ( std_test__929 , __9UH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __jrK ) ;
 if( __yrK ) goto  __result_unhandled_error ;
 __ywJ = "resources/ref" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __BVH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __BVH____state ) ;
 __BVH____state -> name = __ywJ ;
 __TsJ = __smolambda_add_task ( std_test__929 , __BVH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __TsJ ) ;
 if( __SsJ ) goto  __result_unhandled_error ;
 __RsJ = "resources/strcat" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __DVH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __DVH____state ) ;
 __DVH____state -> name = __RsJ ;
 __5lK = __smolambda_add_task ( std_test__929 , __DVH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __5lK ) ;
 if( __QsJ ) goto  __result_unhandled_error ;
 __PsJ = "resources/vec" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __FVH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __FVH____state ) ;
 __FVH____state -> name = __PsJ ;
 __prK = __smolambda_add_task ( std_test__929 , __FVH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __prK ) ;
 if( __OsJ ) goto  __result_unhandled_error ;
 __4rK = "resources/virtfile" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __HVH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __HVH____state ) ;
 __HVH____state -> name = __4rK ;
 __fyJ = __smolambda_add_task ( std_test__929 , __HVH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __fyJ ) ;
 if( __vrK ) goto  __result_unhandled_error ;
 __NsJ = "service/fib" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __JVH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __JVH____state ) ;
 __JVH____state -> name = __NsJ ;
 __npK = __smolambda_add_task ( std_test__929 , __JVH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __npK ) ;
 if( __rpK ) goto  __result_unhandled_error ;
 __MsJ = "service/infinite" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __LVH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __LVH____state ) ;
 __LVH____state -> name = __MsJ ;
 __vpK = __smolambda_add_task ( std_test__929 , __LVH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __vpK ) ;
 if( __LsJ ) goto  __result_unhandled_error ;
 __KsJ = "types/accessvar" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __NVH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __NVH____state ) ;
 __NVH____state -> name = __KsJ ;
 __JsJ = __smolambda_add_task ( std_test__929 , __NVH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __JsJ ) ;
 if( __IsJ ) goto  __result_unhandled_error ;
 __zpK = "types/circ" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __PVH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __PVH____state ) ;
 __PVH____state -> name = __zpK ;
 __3pK = __smolambda_add_task ( std_test__929 , __PVH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __3pK ) ;
 if( __HsJ ) goto  __result_unhandled_error ;
 __srK = "types/dataunion" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __RVH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __RVH____state ) ;
 __RVH____state -> name = __srK ;
 __GsJ = __smolambda_add_task ( std_test__929 , __RVH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __GsJ ) ;
 if( __7pK ) goto  __result_unhandled_error ;
 __FsJ = "types/mutpoint" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __TVH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __TVH____state ) ;
 __TVH____state -> name = __FsJ ;
 __QpK = __smolambda_add_task ( std_test__929 , __TVH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __QpK ) ;
 if( __EsJ ) goto  __result_unhandled_error ;
 __UpK = "types/nom" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __VVH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __VVH____state ) ;
 __VVH____state -> name = __UpK ;
 __FqK = __smolambda_add_task ( std_test__929 , __VVH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __FqK ) ;
 if( __DsJ ) goto  __result_unhandled_error ;
 __IqK = "types/poly" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __XVH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __XVH____state ) ;
 __XVH____state -> name = __IqK ;
 __CsJ = __smolambda_add_task ( std_test__929 , __XVH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __CsJ ) ;
 if( __LqK ) goto  __result_unhandled_error ;
 __BsJ = "types/pong" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __ZVH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __ZVH____state ) ;
 __ZVH____state -> name = __BsJ ;
 __AsJ = __smolambda_add_task ( std_test__929 , __ZVH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __AsJ ) ;
 if( __OqK ) goto  __result_unhandled_error ;
 __9rJ = "types/range_test" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __bVH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __bVH____state ) ;
 __bVH____state -> name = __9rJ ;
 __8rJ = __smolambda_add_task ( std_test__929 , __bVH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __8rJ ) ;
 if( __7rJ ) goto  __result_unhandled_error ;
 __6rJ = "types/union" ;
 {char mark;if(__service_stack_floor+ 2840 >=(char*)&mark) goto __service_stack_floor_handler;} __dVH____state = (struct std_test__929__state*)__runtime_calloc(sizeof(struct std_test__929__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __dVH____state ) ;
 __dVH____state -> name = __6rJ ;
 __5rJ = __smolambda_add_task ( std_test__929 , __dVH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __5rJ ) ;
 if( __4rJ ) goto  __result_unhandled_error ;
 __3rJ :
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


void std_test__931(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 2716;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__931__state *__state=(struct std_test__931__state*)__void__state;
struct run__926__state* __aNH____state = 0 ;
ptr name__contents= __state->name__contents;
u64 name__length= __state->name__length;
char name__first= __state->name__first;
ptr name__memory= __state->name__memory;
u64 __V9K=0;
u64 __U9K=0;
char __T9K=0;
u64 __S9K=0;
char __R9K=0;
u64 __Q9K=0;
u64 __P9K=0;
nominal __O9K=0;
u64 __N9K=0;
char __M9K=0;
ptr __K9K=0;
cstr __J9K=0;
bool __I9K=0;
ptr __H9K=0;
ptr __G9K=0;
ptr __F9K=0;
u64 __E9K=0;
bool __D9K=0;
u64 __C9K=0;
bool __B9K=0;
char __A9K=0;
u64 __98K=0;
u64 __78K=0;
char __58K=0;
u64 __48K=0;
ptr __38K=0;
ptr __28K=0;
char __18K=0;
ptr __08K=0;
nominal __z8K=0;
cstr __y8K=0;
cstr __v8K=0;
bool __t8K=0;
ptr __s8K=0;
ptr __r8K=0;
bool __q8K=0;
u64 __p8K=0;
bool __l8K=0;
char __j8K=0;
u64 __h8K=0;
u64 __g8K=0;
ptr __f8K=0;
ptr __e8K=0;
ptr __c8K=0;
char __b8K=0;
ptr __a8K=0;
u64 __Z8K=0;
cstr __Y8K=0;
cstr __X8K=0;
u64 __W8K=0;
u64 __V8K=0;
u64 __U8K=0;
u64 __T8K=0;
u64 __S8K=0;
u64 __R8K=0;
u64 __Q8K=0;
ptr __P8K=0;
u64 __O8K=0;
char __M8K=0;
u64 __J8K=0;
char __H8K=0;
cstr __D8K=0;
u64 __B8K=0;
u64 __67K=0;
bool __47K=0;
char __27K=0;
bool __07K=0;
u64 __v7K=0;
ptr __t7K=0;
u64 __r7K=0;
nominal __p7K=0;
char __W7K=0;
bool __P7K=0;
u64 __86K=0;
cstr __76K=0;
ptr __w6K=0;
char __v6K=0;
char __r6K=0;
u64 __o6K=0;
bool __l6K=0;
ptr __YNH__acquired=0;
ptr __RNH__acquired=0;
ptr __A6K=0;
char __T5K=0;
errcode __M5K=0;
bool __L5K=0;
cstr __J5K=0;
cstr __I5K=0;
u64 __H5K=0;
ptr __G5K=0;
char __F5K=0;
ptr __E5K=0;
ptr __D5K=0;
u64 __C5K=0;
u64 __B5K=0;
bool __A5K=0;
u64 __94K=0;
char __84K=0;
u64 __74K=0;
u64 __64K=0;
char __44K=0;
char __34K=0;
char __24K=0;
bool __14K=0;
bool __04K=0;
cstr __x4K=0;
u64 __v4K=0;
bool __u4K=0;
u64 __t4K=0;
ptr __s4K=0;
nominal command____FC=0;
ptr command__memory=0;
ptr __q4K=0;
ptr command__contents=0;
bool __p4K=0;
bool __o4K=0;
char command__first=0;
cstr __l4K=0;
u64 __j4K=0;
ptr __h4K=0;
nominal __g4K=0;
nominal __f4K=0;
ptr __e4K=0;
u64 __d4K=0;
u64 command__length=0;
u64 __c4K=0;
u64 __b4K=0;
char __a4K=0;
u64 __Z4K=0;
bool __Y4K=0;
bool __X4K=0;
u64 __W4K=0;
ptr __V4K=0;
bool __U4K=0;
bool __T4K=0;
cstr __Q4K=0;
char __O4K=0;
u64 __N4K=0;
ptr __L4K=0;
cstr __H4K=0;
char __33K=0;
cstr __G4K=0;
char __23K=0;
u64 __F4K=0;
char __13K=0;
ptr __E4K=0;
bool __03K=0;
char __D4K=0;
cstr __x3K=0;
u64 __A4K=0;
u64 __93K=0;
u64 __v3K=0;
u64 __83K=0;
bool __u3K=0;
char __73K=0;
u64 __t3K=0;
u64 __63K=0;
ptr __s3K=0;
u64 __53K=0;
ptr __r3K=0;
nominal __K4K=0;
bool __q3K=0;
bool __p3K=0;
u64 __55K=0;
cstr __m3K=0;
char __k3K=0;
u64 __j3K=0;
ptr __C4K=0;
ptr __B4K=0;
ptr __h3K=0;
nominal __g3K=0;
u64 __f3K=0;
ptr __e3K=0;
char __d3K=0;
ptr __c3K=0;
nominal name____CC=0;
ptr __b3K=0;
u64 __a3K=0;
u64 __Z3K=0;
u64 __Y3K=0;
char __X3K=0;
u64 __W3K=0;
u64 __V3K=0;
char __T3K=0;
char __S3K=0;
char __R3K=0;
bool __Q3K=0;
bool __P3K=0;
cstr __M3K=0;
ptr __d5K=0;
u64 __K3K=0;
bool __J3K=0;
u64 __I3K=0;
ptr __H3K=0;
ptr __G3K=0;
bool __F3K=0;
bool __E3K=0;
bool __V5K=0;
cstr __B3K=0;
u64 __S5K=0;
char __92K=0;
u64 __82K=0;
char __P5K=0;
ptr __62K=0;
nominal __52K=0;
char __c5K=0;
u64 __O7K=0;

// IMPLEMENTATION
__P8K = __runtime_alloc ( sizeof ( ptr **)); if ( __P8K )(( ptr **) __P8K )[0]=0; 
 __Q8K = 0 ;
 __R8K = 0 ;
 __RNH__acquired = __P8K ;
 __S8K = __Q8K ;
 __T8K = __R8K ;
 __V8K = __W8K ;
 __X8K = "./smol tests/unit/" ;
 __Y8K = ".s --workers 1 --runtime eager 2>&1" ;
 __Z8K = strlen ( __Y8K ); __a8K =( ptr ) __Y8K ; __b8K = __Y8K [0]; __c8K =( ptr ) __c8K ; 
 __e8K = __a8K ;
 __O8K = name__length ; __J8K = __Z8K ; __g8K = __O8K + __J8K ; __M8K = name__length ? name__first : __b8K ; 
 __h8K = 1 ;
 __67K = __g8K + __h8K ; 
 __i8K :
 __j8K = 0 ;
 __T5K = __H8K ;
 __l8K = __RNH__acquired ;
 __07K =(! __l8K ); 
 __m8K :
 if(! __07K )goto __o8K ;
 __D8K = "Did not initialize Dynamic" ;
 goto __87K ;
 __builtin_unreachable();
 __o8K :
 __p8K = __S8K +1; __q8K = true ; __B8K = __T8K ; if ( __p8K >= __T8K ) { __T8K = __T8K + __T8K /2+1; __r8K =( ptr )((( ptr **) __RNH__acquired )[0]? __runtime_realloc ((( ptr **) __RNH__acquired )[0], __T8K * sizeof ( ptr ), __B8K * sizeof ( ptr )): __runtime_alloc ( __T8K * sizeof ( ptr ))); if (( __q8K = __r8K ))(( ptr **) __RNH__acquired )[0]=( ptr *) __r8K ; } if ( __q8K ) { __s8K =( ptr ) __runtime_alloc ( __67K * sizeof ( __T5K )); if (( __q8K = __s8K )) {(( ptr **) __RNH__acquired )[0][ __S8K ]= __s8K ; __S8K = __p8K ; } } 
 __47K = __q8K ;
 __t8K =(! __47K ); 
 __y7K :
 if(! __t8K )goto __u8K ;
 __v8K = "Failed a Dynamic allocation" ;
 goto __w8K ;
 __builtin_unreachable();
 __u8K :
 __27K = 0 ;
 __o6K = sizeof ( __27K )* __67K ; 
 __x8K :
 __T5K = __27K ;
 memcpy (( char *) __s8K ,( char *) name__contents , __O8K ); memcpy (( char *) __s8K + __O8K ,( char *) __e8K , __J8K );(( char *) __s8K )[ __g8K ]=0; 
 __t7K = __s8K ;
 __p7K = __z8K ;
 __RNH__acquired = __RNH__acquired ;
 __S8K = __S8K ;
 __T8K = __T8K ;
 __V8K = __V8K ;
 __v7K = strlen ( __X8K ); __08K =( ptr ) __X8K ; __18K = __X8K [0]; __28K =( ptr ) __28K ; 
 __38K = __08K ;
 __r7K = __v7K ; __86K = __g8K ; __48K = __r7K + __86K ; __58K = __v7K ? __18K : __M8K ; 
 __78K = 1 ;
 __98K = __48K + __78K ; 
 __a7K :
 __A9K = 0 ;
 __P5K = __W7K ;
 __l6K = __RNH__acquired ;
 __B9K =(! __l6K ); 
 __n8K :
 if(! __B9K )goto __68K ;
 __y8K = "Did not initialize Dynamic" ;
 goto __s6K ;
 __builtin_unreachable();
 __68K :
 __C9K = __S8K +1; __D9K = true ; __E9K = __T8K ; if ( __C9K >= __T8K ) { __T8K = __T8K + __T8K /2+1; __F9K =( ptr )((( ptr **) __RNH__acquired )[0]? __runtime_realloc ((( ptr **) __RNH__acquired )[0], __T8K * sizeof ( ptr ), __E9K * sizeof ( ptr )): __runtime_alloc ( __T8K * sizeof ( ptr ))); if (( __D9K = __F9K ))(( ptr **) __RNH__acquired )[0]=( ptr *) __F9K ; } if ( __D9K ) { __G9K =( ptr ) __runtime_alloc ( __98K * sizeof ( __P5K )); if (( __D9K = __G9K )) {(( ptr **) __RNH__acquired )[0][ __S8K ]= __G9K ; __S8K = __C9K ; } } 
 __P7K = __D9K ;
 __I9K =(! __P7K ); 
 __k8K :
 if(! __I9K )goto __B6K ;
 __J9K = "Failed a Dynamic allocation" ;
 goto __L9K ;
 __builtin_unreachable();
 __B6K :
 __M9K = 0 ;
 __N9K = sizeof ( __M9K )* __98K ; 
 __d8K :
 __P5K = __M9K ;
 memcpy (( char *) __G9K ,( char *) __38K , __r7K ); memcpy (( char *) __G9K + __r7K ,( char *) __t7K , __86K );(( char *) __G9K )[ __48K ]=0; 
 __d5K = __G9K ;
 __p7K = __O9K ;
 __RNH__acquired = __RNH__acquired ;
 __S8K = __S8K ;
 __T8K = __T8K ;
 __V8K = __V8K ;
 __w6K = __runtime_alloc ( sizeof ( ptr **)); if ( __w6K )(( ptr **) __w6K )[0]=0; 
 __P9K = 0 ;
 __Q9K = 0 ;
 __YNH__acquired = __w6K ;
 __S9K = __P9K ;
 __U9K = __Q9K ;
 __V9K = __55K ;
 {char mark;if(__service_stack_floor+ 1180 >=(char*)&mark) goto __service_stack_floor_handler;} __aNH____state = (struct run__926__state*)__runtime_calloc(sizeof(struct run__926__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __aNH____state ) ;
 __aNH____state -> command____FC = command____FC ;
 __aNH____state -> command__contents = __d5K ;
 __aNH____state -> command__length = __48K ;
 __aNH____state -> command__first = __58K ;
 __aNH____state -> command__memory = __RNH__acquired ;
 __f8K = __smolambda_add_task ( run__926 , __aNH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __f8K ) ;
 if( __M5K ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __f8K ) ;
 __M5K = __aNH____state -> err ;
 __L5K = __M5K ;
 if(! __L5K )goto __K5K ;
 __J5K = "[ \033[31mERROR\033[0m ] " ;
 __I5K = ".s" ;
 __H5K = strlen ( __I5K ); __G5K =( ptr ) __I5K ; __F5K = __I5K [0]; __E5K =( ptr ) __E5K ; 
 __D5K = __G5K ;
 __C5K = name__length ; __B5K = __H5K ; __94K = __C5K + __B5K ; __84K = name__length ? name__first : __F5K ; 
 __74K = 1 ;
 __64K = __94K + __74K ; 
 __54K :
 __44K = 0 ;
 __34K = __24K ;
 __14K = __YNH__acquired ;
 __04K =(! __14K ); 
 __z4K :
 if(! __04K )goto __y4K ;
 __x4K = "Did not initialize Dynamic" ;
 goto __w4K ;
 __builtin_unreachable();
 __y4K :
 __v4K = __S9K +1; __u4K = true ; __t4K = __U9K ; if ( __v4K >= __U9K ) { __U9K = __U9K + __U9K /2+1; __s4K =( ptr )((( ptr **) __YNH__acquired )[0]? __runtime_realloc ((( ptr **) __YNH__acquired )[0], __U9K * sizeof ( ptr ), __t4K * sizeof ( ptr )): __runtime_alloc ( __U9K * sizeof ( ptr ))); if (( __u4K = __s4K ))(( ptr **) __YNH__acquired )[0]=( ptr *) __s4K ; } if ( __u4K ) { __q4K =( ptr ) __runtime_alloc ( __64K * sizeof ( __34K )); if (( __u4K = __q4K )) {(( ptr **) __YNH__acquired )[0][ __S9K ]= __q4K ; __S9K = __v4K ; } } 
 __p4K = __u4K ;
 __o4K =(! __p4K ); 
 __n4K :
 if(! __o4K )goto __m4K ;
 __l4K = "Failed a Dynamic allocation" ;
 goto __k4K ;
 __builtin_unreachable();
 __m4K :
 __T9K = 0 ;
 __j4K = sizeof ( __T9K )* __64K ; 
 __i4K :
 __34K = __T9K ;
 memcpy (( char *) __q4K ,( char *) name__contents , __C5K ); memcpy (( char *) __q4K + __C5K ,( char *) __D5K , __B5K );(( char *) __q4K )[ __94K ]=0; 
 __h4K = __q4K ;
 __g4K = __f4K ;
 __YNH__acquired = __YNH__acquired ;
 __S9K = __S9K ;
 __U9K = __U9K ;
 __V9K = __V9K ;
 __S5K = strlen ( __J5K ); __A6K =( ptr ) __J5K ; __c5K = __J5K [0]; __e4K =( ptr ) __e4K ; 
 __K9K = __A6K ;
 __d4K = __S5K ; __c4K = __94K ; __b4K = __d4K + __c4K ; __a4K = __S5K ? __c5K : __84K ; 
 __Z4K = 1 ;
 __O7K = __b4K + __Z4K ; 
 __r4K :
 __r6K = 0 ;
 __R9K = __v6K ;
 __Y4K = __YNH__acquired ;
 __V5K =(! __Y4K ); 
 __88K :
 if(! __V5K )goto __V7K ;
 __76K = "Did not initialize Dynamic" ;
 goto __Z7K ;
 __builtin_unreachable();
 __V7K :
 __W4K = __S9K +1; __A5K = true ; __U8K = __U9K ; if ( __W4K >= __U9K ) { __U9K = __U9K + __U9K /2+1; __H9K =( ptr )((( ptr **) __YNH__acquired )[0]? __runtime_realloc ((( ptr **) __YNH__acquired )[0], __U9K * sizeof ( ptr ), __U8K * sizeof ( ptr )): __runtime_alloc ( __U9K * sizeof ( ptr ))); if (( __A5K = __H9K ))(( ptr **) __YNH__acquired )[0]=( ptr *) __H9K ; } if ( __A5K ) { __V4K =( ptr ) __runtime_alloc ( __O7K * sizeof ( __R9K )); if (( __A5K = __V4K )) {(( ptr **) __YNH__acquired )[0][ __S9K ]= __V4K ; __S9K = __W4K ; } } 
 __U4K = __A5K ;
 __T4K =(! __U4K ); 
 __S4K :
 if(! __T4K )goto __R4K ;
 __Q4K = "Failed a Dynamic allocation" ;
 goto __P4K ;
 __builtin_unreachable();
 __R4K :
 __O4K = 0 ;
 __N4K = sizeof ( __O4K )* __O7K ; 
 __M4K :
 __R9K = __O4K ;
 memcpy (( char *) __V4K ,( char *) __K9K , __d4K ); memcpy (( char *) __V4K + __d4K ,( char *) __h4K , __c4K );(( char *) __V4K )[ __b4K ]=0; 
 __L4K = __V4K ;
 __g4K = __K4K ;
 __YNH__acquired = __YNH__acquired ;
 __S9K = __S9K ;
 __U9K = __U9K ;
 __V9K = __V9K ;
 printf ( "%s\n" ,( char *) __L4K ); 
 __J4K :
 goto __I4K ;
 __K5K :
 __H4K = "[ \033[32mOK\033[0m ] " ;
 __G4K = ".s" ;
 __F4K = strlen ( __G4K ); __E4K =( ptr ) __G4K ; __D4K = __G4K [0]; __C4K =( ptr ) __C4K ; 
 __B4K = __E4K ;
 __A4K = name__length ; __93K = __F4K ; __83K = __A4K + __93K ; __73K = name__length ? name__first : __D4K ; 
 __63K = 1 ;
 __53K = __83K + __63K ; 
 __43K :
 __33K = 0 ;
 __23K = __13K ;
 __03K = __YNH__acquired ;
 __X4K =(! __03K ); 
 __z3K :
 if(! __X4K )goto __y3K ;
 __x3K = "Did not initialize Dynamic" ;
 goto __w3K ;
 __builtin_unreachable();
 __y3K :
 __v3K = __S9K +1; __u3K = true ; __t3K = __U9K ; if ( __v3K >= __U9K ) { __U9K = __U9K + __U9K /2+1; __s3K =( ptr )((( ptr **) __YNH__acquired )[0]? __runtime_realloc ((( ptr **) __YNH__acquired )[0], __U9K * sizeof ( ptr ), __t3K * sizeof ( ptr )): __runtime_alloc ( __U9K * sizeof ( ptr ))); if (( __u3K = __s3K ))(( ptr **) __YNH__acquired )[0]=( ptr *) __s3K ; } if ( __u3K ) { __r3K =( ptr ) __runtime_alloc ( __53K * sizeof ( __23K )); if (( __u3K = __r3K )) {(( ptr **) __YNH__acquired )[0][ __S9K ]= __r3K ; __S9K = __v3K ; } } 
 __q3K = __u3K ;
 __p3K =(! __q3K ); 
 __o3K :
 if(! __p3K )goto __n3K ;
 __m3K = "Failed a Dynamic allocation" ;
 goto __l3K ;
 __builtin_unreachable();
 __n3K :
 __k3K = 0 ;
 __j3K = sizeof ( __k3K )* __53K ; 
 __i3K :
 __23K = __k3K ;
 memcpy (( char *) __r3K ,( char *) name__contents , __A4K ); memcpy (( char *) __r3K + __A4K ,( char *) __B4K , __93K );(( char *) __r3K )[ __83K ]=0; 
 __h3K = __r3K ;
 __g4K = __g3K ;
 __YNH__acquired = __YNH__acquired ;
 __S9K = __S9K ;
 __U9K = __U9K ;
 __V9K = __V9K ;
 __f3K = strlen ( __H4K ); __e3K =( ptr ) __H4K ; __d3K = __H4K [0]; __c3K =( ptr ) __c3K ; 
 __b3K = __e3K ;
 __a3K = __f3K ; __Z3K = __83K ; __Y3K = __a3K + __Z3K ; __X3K = __f3K ? __d3K : __73K ; 
 __W3K = 1 ;
 __V3K = __Y3K + __W3K ; 
 __U3K :
 __T3K = 0 ;
 __S3K = __R3K ;
 __Q3K = __YNH__acquired ;
 __P3K =(! __Q3K ); 
 __O3K :
 if(! __P3K )goto __N3K ;
 __M3K = "Did not initialize Dynamic" ;
 goto __L3K ;
 __builtin_unreachable();
 __N3K :
 __K3K = __S9K +1; __J3K = true ; __I3K = __U9K ; if ( __K3K >= __U9K ) { __U9K = __U9K + __U9K /2+1; __H3K =( ptr )((( ptr **) __YNH__acquired )[0]? __runtime_realloc ((( ptr **) __YNH__acquired )[0], __U9K * sizeof ( ptr ), __I3K * sizeof ( ptr )): __runtime_alloc ( __U9K * sizeof ( ptr ))); if (( __J3K = __H3K ))(( ptr **) __YNH__acquired )[0]=( ptr *) __H3K ; } if ( __J3K ) { __G3K =( ptr ) __runtime_alloc ( __V3K * sizeof ( __S3K )); if (( __J3K = __G3K )) {(( ptr **) __YNH__acquired )[0][ __S9K ]= __G3K ; __S9K = __K3K ; } } 
 __F3K = __J3K ;
 __E3K =(! __F3K ); 
 __D3K :
 if(! __E3K )goto __C3K ;
 __B3K = "Failed a Dynamic allocation" ;
 goto __A3K ;
 __builtin_unreachable();
 __C3K :
 __92K = 0 ;
 __82K = sizeof ( __92K )* __V3K ; 
 __72K :
 __S3K = __92K ;
 memcpy (( char *) __G3K ,( char *) __b3K , __a3K ); memcpy (( char *) __G3K + __a3K ,( char *) __h3K , __Z3K );(( char *) __G3K )[ __Y3K ]=0; 
 __62K = __G3K ;
 __g4K = __52K ;
 __YNH__acquired = __YNH__acquired ;
 __S9K = __S9K ;
 __U9K = __U9K ;
 __V9K = __V9K ;
 printf ( "%s\n" ,( char *) __62K ); 
 __42K :
 __I4K :
 __32K :
goto __return;

// ERROR HANDLING
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__error_code =__UNHANDLED__ERROR;
goto __failsafe ;
__87K :
 printf ( "%s\n" , __D8K ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__s6K :
 printf ( "%s\n" , __y8K ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__A3K :
 printf ( "%s\n" , __B3K ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__w4K :
 printf ( "%s\n" , __x4K ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__L9K :
 printf ( "%s\n" , __J9K ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__P4K :
 printf ( "%s\n" , __Q4K ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__22K :
__result__error_code=__UNHANDLED__ERROR;
goto __failsafe;
__l3K :
 printf ( "%s\n" , __m3K ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__k4K :
 printf ( "%s\n" , __l4K ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__w8K :
 printf ( "%s\n" , __v8K ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__w3K :
 printf ( "%s\n" , __x3K ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__L3K :
 printf ( "%s\n" , __M3K ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__Z7K :
 printf ( "%s\n" , __76K ); 
__result__error_code=__USER__ERROR;
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
if ( __YNH__acquired ) { for ( __V9K =0; __V9K < __S9K ;++ __V9K ) { __runtime_free ((( ptr **) __YNH__acquired )[0][ __V9K ]); } __runtime_free ( __YNH__acquired ); __YNH__acquired =0; __S9K =0; __U9K =0; } 
 if ( __YNH__acquired ) { for ( __55K =0; __55K < __P9K ;++ __55K ) { __runtime_free ((( ptr **) __YNH__acquired )[0][ __55K ]); } __runtime_free ( __YNH__acquired ); __YNH__acquired =0; __P9K =0; __Q9K =0; } 
if ( __RNH__acquired ) { for ( __V8K =0; __V8K < __S8K ;++ __V8K ) { __runtime_free ((( ptr **) __RNH__acquired )[0][ __V8K ]); } __runtime_free ( __RNH__acquired ); __RNH__acquired =0; __S8K =0; __T8K =0; } 
 if ( __RNH__acquired ) { for ( __W8K =0; __W8K < __Q8K ;++ __W8K ) { __runtime_free ((( ptr **) __RNH__acquired )[0][ __W8K ]); } __runtime_free ( __RNH__acquired ); __RNH__acquired =0; __Q8K =0; __R8K =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__error_code;
}


void std_test__930(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 2740;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__930__state *__state=(struct std_test__930__state*)__void__state;
struct run__926__state* __BGH____state = 0 ;
ptr name__contents= __state->name__contents;
u64 name__length= __state->name__length;
char name__first= __state->name__first;
ptr name__memory= __state->name__memory;
u64 __9FL=0;
u64 __8FL=0;
u64 __7FL=0;
ptr __6FL=0;
char __5FL=0;
cstr __4FL=0;
bool __3FL=0;
bool __2FL=0;
ptr __1FL=0;
u64 __0FL=0;
bool __zFL=0;
cstr __wFL=0;
u64 __vFL=0;
bool __tFL=0;
u64 __sFL=0;
bool __rFL=0;
char __qFL=0;
char __pFL=0;
ptr __mFL=0;
char __lFL=0;
ptr __jFL=0;
u64 __hFL=0;
bool __OFL=0;
bool __NFL=0;
char __MFL=0;
char __LFL=0;
char __KFL=0;
char __JFL=0;
u64 __HFL=0;
u64 __GFL=0;
cstr __FFL=0;
u64 __EFL=0;
u64 __DFL=0;
u64 __CFL=0;
u64 __BFL=0;
ptr __AFL=0;
ptr __9EL=0;
ptr __8EL=0;
char __7EL=0;
char __6EL=0;
u64 __5EL=0;
char __4EL=0;
cstr __3EL=0;
u64 __2EL=0;
u64 __1EL=0;
cstr __0EL=0;
u64 __zEL=0;
u64 __yEL=0;
u64 __xEL=0;
nominal __wEL=0;
u64 __vEL=0;
bool __uEL=0;
ptr __tEL=0;
u64 __qEL=0;
char __pEL=0;
char __nEL=0;
u64 __mEL=0;
u64 __kEL=0;
char __jEL=0;
ptr __hEL=0;
u64 __cEL=0;
nominal __aEL=0;
cstr __YEL=0;
char __UEL=0;
ptr __SEL=0;
nominal __iFL=0;
nominal name____FC=0;
ptr __9FH__acquired=0;
u64 __KEL=0;
cstr __DEL=0;
char __6DL=0;
u64 __oBL=0;
nominal command____FC=0;
ptr command__contents=0;
u64 __mBL=0;
u64 command__length=0;
u64 __lBL=0;
char command__first=0;
ptr __2DL=0;
u64 __kBL=0;
ptr command__memory=0;
u64 __1DL=0;
u64 __jBL=0;
ptr __iBL=0;
u64 __FEL=0;
errcode __hBL=0;
bool __gBL=0;
cstr __eBL=0;
cstr __dBL=0;
u64 __cBL=0;
ptr __tDL=0;
u64 __bBL=0;
ptr __aBL=0;
char __ZBL=0;
ptr __YBL=0;
ptr __XBL=0;
u64 __WBL=0;
char __VBL=0;
char __TBL=0;
char __SBL=0;
char __RBL=0;
bool __QBL=0;
bool __PBL=0;
cstr __MBL=0;
u64 __KBL=0;
bool __JBL=0;
ptr __eFL=0;
u64 __IBL=0;
ptr __dFL=0;
ptr __HBL=0;
u64 __cFL=0;
ptr __GBL=0;
cstr __bFL=0;
bool __FBL=0;
char __aFL=0;
bool __EBL=0;
u64 __oFL=0;
u64 __nFL=0;
cstr __BBL=0;
bool __WFL=0;
u64 __VFL=0;
char __9AL=0;
bool __UFL=0;
u64 __8AL=0;
u64 __TFL=0;
ptr __6AL=0;
ptr __RFL=0;
nominal __5AL=0;
nominal __gFL=0;
nominal __4AL=0;
nominal __fFL=0;
u64 __3AL=0;
ptr __2AL=0;
char __1AL=0;
ptr __0AL=0;
ptr __zAL=0;
u64 __yAL=0;
u64 __xAL=0;
u64 __wAL=0;
bool __XFL=0;
char __vAL=0;
u64 __uAL=0;
bool __BDL=0;
u64 __tAL=0;
u64 __sAL=0;
ptr __8CL=0;
char __qAL=0;
char __pAL=0;
char __oAL=0;
bool __nAL=0;
bool __mAL=0;
cstr __jAL=0;
u64 __hAL=0;
bool __gAL=0;
u64 __fAL=0;
ptr __eAL=0;
ptr __dAL=0;
bool __cAL=0;
bool __bAL=0;
cstr __YAL=0;
char __5CL=0;
char __WAL=0;
u64 __VAL=0;
ptr __TAL=0;
nominal __SAL=0;
u64 __jCL=0;
cstr __PAL=0;
cstr __OAL=0;
u64 __okL=0;
ptr __MAL=0;
char __LAL=0;
ptr __KAL=0;
u64 __bCL=0;
ptr __JAL=0;
u64 __IAL=0;
u64 __HAL=0;
u64 __GAL=0;
char __FAL=0;
u64 __EAL=0;
u64 __DAL=0;
char __BAL=0;
char __AAL=0;
char __99K=0;
bool __89K=0;
bool __79K=0;
cstr __49K=0;
u64 __29K=0;
bool __19K=0;
u64 __09K=0;
ptr __z9K=0;
ptr __y9K=0;
bool __x9K=0;
bool __w9K=0;
ptr __2FH__acquired=0;
cstr __t9K=0;
char __r9K=0;
u64 __q9K=0;
ptr __o9K=0;
ptr __n9K=0;
ptr __m9K=0;
ptr __l9K=0;
u64 __k9K=0;
bool __g9K=0;
u64 __f9K=0;
bool __e9K=0;
bool __d9K=0;
ptr __Z9K=0;

// IMPLEMENTATION
__tEL = __runtime_alloc ( sizeof ( ptr **)); if ( __tEL )(( ptr **) __tEL )[0]=0; 
 __vEL = 0 ;
 __xEL = 0 ;
 __2FH__acquired = __tEL ;
 __yEL = __vEL ;
 __zEL = __xEL ;
 __kEL = __qEL ;
 __0EL = "./smol tests/unit/" ;
 __3EL = ".s --workers 1 --runtime eager 2>&1" ;
 __5EL = strlen ( __3EL ); __2DL =( ptr ) __3EL ; __7EL = __3EL [0]; __8EL =( ptr ) __8EL ; 
 __AFL = __2DL ;
 __CFL = name__length ; __DFL = __5EL ; __EFL = __CFL + __DFL ; __nEL = name__length ? name__first : __7EL ; 
 __GFL = 1 ;
 __HFL = __EFL + __GFL ; 
 __IFL :
 __JFL = 0 ;
 __KFL = __MFL ;
 __NFL = __2FH__acquired ;
 __OFL =(! __NFL ); 
 __PFL :
 if(! __OFL )goto __QFL ;
 __YEL = "Did not initialize Dynamic" ;
 goto __SFL ;
 __builtin_unreachable();
 __QFL :
 __TFL = __yEL +1; __UFL = true ; __VFL = __zEL ; if ( __TFL >= __zEL ) { __zEL = __zEL + __zEL /2+1; __hEL =( ptr )((( ptr **) __2FH__acquired )[0]? __runtime_realloc ((( ptr **) __2FH__acquired )[0], __zEL * sizeof ( ptr ), __VFL * sizeof ( ptr )): __runtime_alloc ( __zEL * sizeof ( ptr ))); if (( __UFL = __hEL ))(( ptr **) __2FH__acquired )[0]=( ptr *) __hEL ; } if ( __UFL ) { __RFL =( ptr ) __runtime_alloc ( __HFL * sizeof ( __KFL )); if (( __UFL = __RFL )) {(( ptr **) __2FH__acquired )[0][ __yEL ]= __RFL ; __yEL = __TFL ; } } 
 __WFL = __UFL ;
 __XFL =(! __WFL ); 
 __YFL :
 if(! __XFL )goto __ZFL ;
 __bFL = "Failed a Dynamic allocation" ;
 goto __OEL ;
 __builtin_unreachable();
 __ZFL :
 __UEL = 0 ;
 __cFL = sizeof ( __UEL )* __HFL ; 
 __QEL :
 __KFL = __UEL ;
 memcpy (( char *) __RFL ,( char *) name__contents , __CFL ); memcpy (( char *) __RFL + __CFL ,( char *) __AFL , __DFL );(( char *) __RFL )[ __EFL ]=0; 
 __eFL = __RFL ;
 __aEL = __fFL ;
 __2FH__acquired = __2FH__acquired ;
 __yEL = __yEL ;
 __zEL = __zEL ;
 __kEL = __kEL ;
 __hFL = strlen ( __0EL ); __jFL =( ptr ) __0EL ; __lFL = __0EL [0]; __SEL =( ptr ) __SEL ; 
 __mFL = __jFL ;
 __nFL = __hFL ; __oFL = __EFL ; __FEL = __nFL + __oFL ; __aFL = __hFL ? __lFL : __nEL ; 
 __KEL = 1 ;
 __bCL = __FEL + __KEL ; 
 __MEL :
 __pFL = 0 ;
 __4EL = __qFL ;
 __rFL = __2FH__acquired ;
 __tFL =(! __rFL ); 
 __uFL :
 if(! __tFL )goto __HEL ;
 __wFL = "Did not initialize Dynamic" ;
 goto __xFL ;
 __builtin_unreachable();
 __HEL :
 __cEL = __yEL +1; __zFL = true ; __0FL = __zEL ; if ( __cEL >= __zEL ) { __zEL = __zEL + __zEL /2+1; __1FL =( ptr )((( ptr **) __2FH__acquired )[0]? __runtime_realloc ((( ptr **) __2FH__acquired )[0], __zEL * sizeof ( ptr ), __0FL * sizeof ( ptr )): __runtime_alloc ( __zEL * sizeof ( ptr ))); if (( __zFL = __1FL ))(( ptr **) __2FH__acquired )[0]=( ptr *) __1FL ; } if ( __zFL ) { __tDL =( ptr ) __runtime_alloc ( __bCL * sizeof ( __4EL )); if (( __zFL = __tDL )) {(( ptr **) __2FH__acquired )[0][ __yEL ]= __tDL ; __yEL = __cEL ; } } 
 __2FL = __zFL ;
 __3FL =(! __2FL ); 
 __PDL :
 if(! __3FL )goto __hDL ;
 __DEL = "Failed a Dynamic allocation" ;
 goto __yFL ;
 __builtin_unreachable();
 __hDL :
 __5FL = 0 ;
 __oBL = sizeof ( __5FL )* __bCL ; 
 __rEL :
 __4EL = __5FL ;
 memcpy (( char *) __tDL ,( char *) __mFL , __nFL ); memcpy (( char *) __tDL + __nFL ,( char *) __eFL , __oFL );(( char *) __tDL )[ __FEL ]=0; 
 __8CL = __tDL ;
 __aEL = __iFL ;
 __2FH__acquired = __2FH__acquired ;
 __yEL = __yEL ;
 __zEL = __zEL ;
 __kEL = __kEL ;
 __6FL = __runtime_alloc ( sizeof ( ptr **)); if ( __6FL )(( ptr **) __6FL )[0]=0; 
 __jCL = 0 ;
 __vFL = 0 ;
 __9FH__acquired = __6FL ;
 __1EL = __jCL ;
 __8FL = __vFL ;
 __BFL = __9FL ;
 {char mark;if(__service_stack_floor+ 1180 >=(char*)&mark) goto __service_stack_floor_handler;} __BGH____state = (struct run__926__state*)__runtime_calloc(sizeof(struct run__926__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __BGH____state ) ;
 __BGH____state -> command____FC = command____FC ;
 __BGH____state -> command__contents = __8CL ;
 __BGH____state -> command__length = __FEL ;
 __BGH____state -> command__first = __aFL ;
 __BGH____state -> command__memory = __2FH__acquired ;
 __iBL = __smolambda_add_task ( run__926 , __BGH____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __iBL ) ;
 if( __hBL ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __iBL ) ;
 __hBL = __BGH____state -> err ;
 __gBL = __hBL ;
 if(! __gBL )goto __fBL ;
 __eBL = "[ \033[31mERROR\033[0m ] " ;
 __dBL = ".s" ;
 __bBL = strlen ( __dBL ); __aBL =( ptr ) __dBL ; __ZBL = __dBL [0]; __YBL =( ptr ) __YBL ; 
 __XBL = __aBL ;
 __WBL = name__length ; __mBL = __bBL ; __lBL = __WBL + __mBL ; __VBL = name__length ? name__first : __ZBL ; 
 __kBL = 1 ;
 __jBL = __lBL + __kBL ; 
 __UBL :
 __TBL = 0 ;
 __SBL = __RBL ;
 __QBL = __9FH__acquired ;
 __PBL =(! __QBL ); 
 __OBL :
 if(! __PBL )goto __NBL ;
 __MBL = "Did not initialize Dynamic" ;
 goto __LBL ;
 __builtin_unreachable();
 __NBL :
 __KBL = __1EL +1; __JBL = true ; __IBL = __8FL ; if ( __KBL >= __8FL ) { __8FL = __8FL + __8FL /2+1; __HBL =( ptr )((( ptr **) __9FH__acquired )[0]? __runtime_realloc ((( ptr **) __9FH__acquired )[0], __8FL * sizeof ( ptr ), __IBL * sizeof ( ptr )): __runtime_alloc ( __8FL * sizeof ( ptr ))); if (( __JBL = __HBL ))(( ptr **) __9FH__acquired )[0]=( ptr *) __HBL ; } if ( __JBL ) { __GBL =( ptr ) __runtime_alloc ( __jBL * sizeof ( __SBL )); if (( __JBL = __GBL )) {(( ptr **) __9FH__acquired )[0][ __1EL ]= __GBL ; __1EL = __KBL ; } } 
 __FBL = __JBL ;
 __EBL =(! __FBL ); 
 __DBL :
 if(! __EBL )goto __CBL ;
 __BBL = "Failed a Dynamic allocation" ;
 goto __ABL ;
 __builtin_unreachable();
 __CBL :
 __9AL = 0 ;
 __8AL = sizeof ( __9AL )* __jBL ; 
 __7AL :
 __SBL = __9AL ;
 memcpy (( char *) __GBL ,( char *) name__contents , __WBL ); memcpy (( char *) __GBL + __WBL ,( char *) __XBL , __mBL );(( char *) __GBL )[ __lBL ]=0; 
 __6AL = __GBL ;
 __5AL = __4AL ;
 __9FH__acquired = __9FH__acquired ;
 __1EL = __1EL ;
 __8FL = __8FL ;
 __BFL = __BFL ;
 __3AL = strlen ( __eBL ); __2AL =( ptr ) __eBL ; __1AL = __eBL [0]; __0AL =( ptr ) __0AL ; 
 __zAL = __2AL ;
 __yAL = __3AL ; __xAL = __lBL ; __wAL = __yAL + __xAL ; __vAL = __3AL ? __1AL : __VBL ; 
 __uAL = 1 ;
 __sAL = __wAL + __uAL ; 
 __rAL :
 __qAL = 0 ;
 __pAL = __oAL ;
 __nAL = __9FH__acquired ;
 __mAL =(! __nAL ); 
 __lAL :
 if(! __mAL )goto __kAL ;
 __jAL = "Did not initialize Dynamic" ;
 goto __iAL ;
 __builtin_unreachable();
 __kAL :
 __hAL = __1EL +1; __gAL = true ; __fAL = __8FL ; if ( __hAL >= __8FL ) { __8FL = __8FL + __8FL /2+1; __eAL =( ptr )((( ptr **) __9FH__acquired )[0]? __runtime_realloc ((( ptr **) __9FH__acquired )[0], __8FL * sizeof ( ptr ), __fAL * sizeof ( ptr )): __runtime_alloc ( __8FL * sizeof ( ptr ))); if (( __gAL = __eAL ))(( ptr **) __9FH__acquired )[0]=( ptr *) __eAL ; } if ( __gAL ) { __dAL =( ptr ) __runtime_alloc ( __sAL * sizeof ( __pAL )); if (( __gAL = __dAL )) {(( ptr **) __9FH__acquired )[0][ __1EL ]= __dAL ; __1EL = __hAL ; } } 
 __cAL = __gAL ;
 __bAL =(! __cAL ); 
 __aAL :
 if(! __bAL )goto __ZAL ;
 __YAL = "Failed a Dynamic allocation" ;
 goto __XAL ;
 __builtin_unreachable();
 __ZAL :
 __WAL = 0 ;
 __VAL = sizeof ( __WAL )* __sAL ; 
 __UAL :
 __pAL = __WAL ;
 memcpy (( char *) __dAL ,( char *) __zAL , __yAL ); memcpy (( char *) __dAL + __yAL ,( char *) __6AL , __xAL );(( char *) __dAL )[ __wAL ]=0; 
 __TAL = __dAL ;
 __5AL = __SAL ;
 __9FH__acquired = __9FH__acquired ;
 __1EL = __1EL ;
 __8FL = __8FL ;
 __BFL = __BFL ;
 printf ( "%s\n" ,( char *) __TAL ); 
 __RAL :
 goto __QAL ;
 __fBL :
 __PAL = "[ \033[32mOK\033[0m ] " ;
 __OAL = ".s" ;
 __okL = strlen ( __OAL ); __MAL =( ptr ) __OAL ; __LAL = __OAL [0]; __KAL =( ptr ) __KAL ; 
 __JAL = __MAL ;
 __IAL = name__length ; __HAL = __okL ; __GAL = __IAL + __HAL ; __FAL = name__length ? name__first : __LAL ; 
 __EAL = 1 ;
 __DAL = __GAL + __EAL ; 
 __CAL :
 __BAL = 0 ;
 __AAL = __99K ;
 __89K = __9FH__acquired ;
 __79K =(! __89K ); 
 __69K :
 if(! __79K )goto __59K ;
 __49K = "Did not initialize Dynamic" ;
 goto __39K ;
 __builtin_unreachable();
 __59K :
 __29K = __1EL +1; __19K = true ; __09K = __8FL ; if ( __29K >= __8FL ) { __8FL = __8FL + __8FL /2+1; __z9K =( ptr )((( ptr **) __9FH__acquired )[0]? __runtime_realloc ((( ptr **) __9FH__acquired )[0], __8FL * sizeof ( ptr ), __09K * sizeof ( ptr )): __runtime_alloc ( __8FL * sizeof ( ptr ))); if (( __19K = __z9K ))(( ptr **) __9FH__acquired )[0]=( ptr *) __z9K ; } if ( __19K ) { __y9K =( ptr ) __runtime_alloc ( __DAL * sizeof ( __AAL )); if (( __19K = __y9K )) {(( ptr **) __9FH__acquired )[0][ __1EL ]= __y9K ; __1EL = __29K ; } } 
 __x9K = __19K ;
 __w9K =(! __x9K ); 
 __v9K :
 if(! __w9K )goto __u9K ;
 __t9K = "Failed a Dynamic allocation" ;
 goto __s9K ;
 __builtin_unreachable();
 __u9K :
 __r9K = 0 ;
 __q9K = sizeof ( __r9K )* __DAL ; 
 __p9K :
 __AAL = __r9K ;
 memcpy (( char *) __y9K ,( char *) name__contents , __IAL ); memcpy (( char *) __y9K + __IAL ,( char *) __JAL , __HAL );(( char *) __y9K )[ __GAL ]=0; 
 __o9K = __y9K ;
 __5AL = __gFL ;
 __9FH__acquired = __9FH__acquired ;
 __1EL = __1EL ;
 __8FL = __8FL ;
 __BFL = __BFL ;
 __1DL = strlen ( __PAL ); __n9K =( ptr ) __PAL ; __6DL = __PAL [0]; __m9K =( ptr ) __m9K ; 
 __l9K = __n9K ;
 __k9K = __1DL ; __7FL = __GAL ; __tAL = __k9K + __7FL ; __jEL = __1DL ? __6DL : __FAL ; 
 __2EL = 1 ;
 __mEL = __tAL + __2EL ; 
 __j9K :
 __pEL = 0 ;
 __6EL = __LFL ;
 __uEL = __9FH__acquired ;
 __BDL =(! __uEL ); 
 __i9K :
 if(! __BDL )goto __h9K ;
 __4FL = "Did not initialize Dynamic" ;
 goto __kFL ;
 __builtin_unreachable();
 __h9K :
 __cBL = __1EL +1; __g9K = true ; __f9K = __8FL ; if ( __cBL >= __8FL ) { __8FL = __8FL + __8FL /2+1; __9EL =( ptr )((( ptr **) __9FH__acquired )[0]? __runtime_realloc ((( ptr **) __9FH__acquired )[0], __8FL * sizeof ( ptr ), __f9K * sizeof ( ptr )): __runtime_alloc ( __8FL * sizeof ( ptr ))); if (( __g9K = __9EL ))(( ptr **) __9FH__acquired )[0]=( ptr *) __9EL ; } if ( __g9K ) { __dFL =( ptr ) __runtime_alloc ( __mEL * sizeof ( __6EL )); if (( __g9K = __dFL )) {(( ptr **) __9FH__acquired )[0][ __1EL ]= __dFL ; __1EL = __cBL ; } } 
 __e9K = __g9K ;
 __d9K =(! __e9K ); 
 __MDL :
 if(! __d9K )goto __c9K ;
 __FFL = "Failed a Dynamic allocation" ;
 goto __b9K ;
 __builtin_unreachable();
 __c9K :
 __5CL = 0 ;
 __sFL = sizeof ( __5CL )* __mEL ; 
 __a9K :
 __6EL = __5CL ;
 memcpy (( char *) __dFL ,( char *) __l9K , __k9K ); memcpy (( char *) __dFL + __k9K ,( char *) __o9K , __7FL );(( char *) __dFL )[ __tAL ]=0; 
 __Z9K = __dFL ;
 __5AL = __wEL ;
 __9FH__acquired = __9FH__acquired ;
 __1EL = __1EL ;
 __8FL = __8FL ;
 __BFL = __BFL ;
 printf ( "%s\n" ,( char *) __Z9K ); 
 __Y9K :
 __QAL :
 __SDL :
goto __return;

// ERROR HANDLING
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__error_code =__UNHANDLED__ERROR;
goto __failsafe ;
__SFL :
 printf ( "%s\n" , __YEL ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__XAL :
 printf ( "%s\n" , __YAL ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__sEL :
__result__error_code=__UNHANDLED__ERROR;
goto __failsafe;
__yFL :
 printf ( "%s\n" , __DEL ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__ABL :
 printf ( "%s\n" , __BBL ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__xFL :
 printf ( "%s\n" , __wFL ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__s9K :
 printf ( "%s\n" , __t9K ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__39K :
 printf ( "%s\n" , __49K ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__kFL :
 printf ( "%s\n" , __4FL ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__b9K :
 printf ( "%s\n" , __FFL ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__service_stack_floor_handler:
printf("Insufficient stack for safe service call (too much recursion or stack allocation)\n");
__result__error_code=__STACK__ERROR;
goto __failsafe;
__OEL :
 printf ( "%s\n" , __bFL ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__LBL :
 printf ( "%s\n" , __MBL ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__iAL :
 printf ( "%s\n" , __jAL ); 
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
if ( __9FH__acquired ) { for ( __BFL =0; __BFL < __1EL ;++ __BFL ) { __runtime_free ((( ptr **) __9FH__acquired )[0][ __BFL ]); } __runtime_free ( __9FH__acquired ); __9FH__acquired =0; __1EL =0; __8FL =0; } 
 if ( __9FH__acquired ) { for ( __9FL =0; __9FL < __jCL ;++ __9FL ) { __runtime_free ((( ptr **) __9FH__acquired )[0][ __9FL ]); } __runtime_free ( __9FH__acquired ); __9FH__acquired =0; __jCL =0; __vFL =0; } 
if ( __2FH__acquired ) { for ( __kEL =0; __kEL < __yEL ;++ __kEL ) { __runtime_free ((( ptr **) __2FH__acquired )[0][ __kEL ]); } __runtime_free ( __2FH__acquired ); __2FH__acquired =0; __yEL =0; __zEL =0; } 
 if ( __2FH__acquired ) { for ( __qEL =0; __qEL < __vEL ;++ __qEL ) { __runtime_free ((( ptr **) __2FH__acquired )[0][ __qEL ]); } __runtime_free ( __2FH__acquired ); __2FH__acquired =0; __vEL =0; __xEL =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__error_code;
}


void std_test__929(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 2740;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__929__state *__state=(struct std_test__929__state*)__void__state;
struct run__926__state* __d8G____state = 0 ;
cstr name= __state->name;
u64 __eML=0;
bool __dML=0;
u64 __cML=0;
bool __ZML=0;
char __YML=0;
u64 __WML=0;
u64 __VML=0;
u64 __UML=0;
ptr __TML=0;
ptr __SML=0;
ptr __RML=0;
char __QML=0;
nominal __PML=0;
ptr __OML=0;
char __MML=0;
cstr __KML=0;
char __HML=0;
bool __GML=0;
ptr __FML=0;
ptr __EML=0;
u64 __DML=0;
bool __CML=0;
u64 __BML=0;
u64 __8LL=0;
bool __7LL=0;
char __6LL=0;
char __5LL=0;
u64 __3LL=0;
u64 __2LL=0;
bool __1LL=0;
char __0LL=0;
u64 __zLL=0;
u64 __yLL=0;
u64 __xLL=0;
ptr __wLL=0;
ptr __vLL=0;
char __uLL=0;
char __tLL=0;
bool __rLL=0;
ptr __qLL=0;
ptr __pLL=0;
ptr __oLL=0;
u64 __nLL=0;
cstr __mLL=0;
u64 __lLL=0;
u64 __kLL=0;
u64 __iLL=0;
u64 __hLL=0;
ptr __gLL=0;
u64 __fLL=0;
bool __eLL=0;
u64 __WLL=0;
char __9KL=0;
bool __QKL=0;
u64 __sLL=0;
cstr __MKL=0;
u64 __LKL=0;
u64 __IKL=0;
char __AKL=0;
ptr __sJL=0;
nominal __iJL=0;
u64 __jLL=0;
char __HJL=0;
cstr __XJL=0;
ptr __U8G__acquired=0;
u64 __AJL=0;
u64 __4IL=0;
bool __vIL=0;
u64 __rIL=0;
bool __qIL=0;
errcode __mIL=0;
bool __lIL=0;
cstr __jIL=0;
cstr __iIL=0;
u64 __hIL=0;
ptr __gIL=0;
char __fIL=0;
ptr __eIL=0;
ptr __dIL=0;
u64 __cIL=0;
ptr __bIL=0;
char __aIL=0;
ptr __ZIL=0;
ptr __YIL=0;
u64 __XIL=0;
u64 __WIL=0;
u64 __VIL=0;
char __UIL=0;
u64 __TIL=0;
u64 __SIL=0;
char __QIL=0;
char __PIL=0;
char __OIL=0;
bool __ok=0;
bool __MIL=0;
cstr __JIL=0;
u64 __HIL=0;
bool __GIL=0;
u64 __FIL=0;
ptr __EIL=0;
bool __DIL=0;
bool __CIL=0;
cstr __9HL=0;
char __7HL=0;
u64 __6HL=0;
ptr __4HL=0;
nominal __3HL=0;
nominal __2HL=0;
ptr __1HL=0;
char __0HL=0;
ptr __zHL=0;
ptr __yHL=0;
u64 __xHL=0;
u64 __wHL=0;
char __vHL=0;
u64 __uHL=0;
ptr __uML=0;
char __sHL=0;
char __rHL=0;
u64 __sML=0;
bool __qHL=0;
u64 __rML=0;
bool __pHL=0;
u64 __qML=0;
u64 __pML=0;
u64 __oML=0;
cstr __mHL=0;
ptr __nML=0;
ptr __mML=0;
u64 __kHL=0;
ptr __lML=0;
bool __jHL=0;
u64 __kML=0;
u64 __iHL=0;
ptr __hHL=0;
char __iML=0;
ptr __gHL=0;
bool __fHL=0;
bool __gML=0;
bool __eHL=0;
ptr __fML=0;
cstr __bHL=0;
char __ZHL=0;
u64 __YHL=0;
ptr __WHL=0;
nominal __VHL=0;
cstr __SHL=0;
cstr __RHL=0;
u64 __QHL=0;
ptr __PHL=0;
char __OHL=0;
ptr __NHL=0;
ptr __MHL=0;
u64 __LHL=0;
ptr __KHL=0;
char __JHL=0;
ptr __IHL=0;
ptr __HHL=0;
u64 __GHL=0;
u64 __FHL=0;
u64 __EHL=0;
char __DHL=0;
u64 __CHL=0;
char __AHL=0;
char __9GL=0;
char __8GL=0;
bool __7GL=0;
bool __6GL=0;
cstr __3GL=0;
u64 __1GL=0;
u64 __0GL=0;
ptr __zGL=0;
ptr __yGL=0;
bool __xGL=0;
cstr __uGL=0;
char __sGL=0;
u64 __rGL=0;
ptr __b8G__acquired=0;
ptr __pGL=0;
nominal __oGL=0;
u64 __nGL=0;
ptr __mGL=0;
char __lGL=0;
ptr __kGL=0;
ptr __jGL=0;
u64 __iGL=0;
u64 __hGL=0;
u64 __gGL=0;
char __fGL=0;
u64 __eGL=0;
u64 __dGL=0;
char __bGL=0;
char __aGL=0;
char __ZGL=0;
bool __YGL=0;
bool __XGL=0;
cstr __UGL=0;
u64 __SGL=0;
ptr __TLL=0;
bool __RGL=0;
u64 __QGL=0;
char __RLL=0;
ptr __PGL=0;
ptr __OGL=0;
nominal __PLL=0;
bool __NGL=0;
nominal command____FC=0;
bool __MGL=0;
cstr __NLL=0;
ptr command__contents=0;
u64 command__length=0;
cstr __JGL=0;
char command__first=0;
ptr command__memory=0;
char __HGL=0;
u64 __ILL=0;
u64 __GGL=0;
u64 __GLL=0;
ptr __EGL=0;
nominal __DGL=0;
cstr __DLL=0;

// IMPLEMENTATION
__gLL = __runtime_alloc ( sizeof ( ptr **)); if ( __gLL )(( ptr **) __gLL )[0]=0; 
 __hLL = 0 ;
 __iLL = 0 ;
 __U8G__acquired = __gLL ;
 __WLL = __hLL ;
 __jLL = __iLL ;
 __kLL = __lLL ;
 __DLL = "./smol tests/unit/" ;
 __mLL = ".s --workers 1 --runtime eager 2>&1" ;
 __nLL = strlen ( name ); __oLL =( ptr ) name ; __9KL = name [0]; __pLL =( ptr ) __pLL ; 
 __qLL = __oLL ;
 __sLL = strlen ( __mLL ); __TLL =( ptr ) __mLL ; __uLL = __mLL [0]; __vLL =( ptr ) __vLL ; 
 __wLL = __TLL ;
 __xLL = __nLL ; __yLL = __sLL ; __zLL = __xLL + __yLL ; __0LL = __nLL ? __9KL : __uLL ; 
 __2LL = 1 ;
 __3LL = __zLL + __2LL ; 
 __4LL :
 __5LL = 0 ;
 __6LL = __RLL ;
 __7LL = __U8G__acquired ;
 __eLL =(! __7LL ); 
 __9LL :
 if(! __eLL )goto __AML ;
 __MKL = "Did not initialize Dynamic" ;
 goto __tIL ;
 __builtin_unreachable();
 __AML :
 __BML = __WLL +1; __CML = true ; __DML = __jLL ; if ( __BML >= __jLL ) { __jLL = __jLL + __jLL /2+1; __EML =( ptr )((( ptr **) __U8G__acquired )[0]? __runtime_realloc ((( ptr **) __U8G__acquired )[0], __jLL * sizeof ( ptr ), __DML * sizeof ( ptr )): __runtime_alloc ( __jLL * sizeof ( ptr ))); if (( __CML = __EML ))(( ptr **) __U8G__acquired )[0]=( ptr *) __EML ; } if ( __CML ) { __FML =( ptr ) __runtime_alloc ( __3LL * sizeof ( __6LL )); if (( __CML = __FML )) {(( ptr **) __U8G__acquired )[0][ __WLL ]= __FML ; __WLL = __BML ; } } 
 __rLL = __CML ;
 __GML =(! __rLL ); 
 __IML :
 if(! __GML )goto __JML ;
 __KML = "Failed a Dynamic allocation" ;
 goto __LML ;
 __builtin_unreachable();
 __JML :
 __MML = 0 ;
 __8LL = sizeof ( __MML )* __3LL ; 
 __NML :
 __6LL = __MML ;
 memcpy (( char *) __FML ,( char *) __qLL , __xLL ); memcpy (( char *) __FML + __xLL ,( char *) __wLL , __yLL );(( char *) __FML )[ __zLL ]=0; 
 __OML = __FML ;
 __PLL = __PML ;
 __U8G__acquired = __U8G__acquired ;
 __WLL = __WLL ;
 __jLL = __jLL ;
 __kLL = __kLL ;
 __ILL = strlen ( __DLL ); __RML =( ptr ) __DLL ; __HML = __DLL [0]; __SML =( ptr ) __SML ; 
 __TML = __RML ;
 __UML = __ILL ; __GLL = __zLL ; __VML = __UML + __GLL ; __QML = __ILL ? __HML : __0LL ; 
 __IKL = 1 ;
 __WML = __VML + __IKL ; 
 __XML :
 __YML = 0 ;
 __tLL = __AKL ;
 __QKL = __U8G__acquired ;
 __ZML =(! __QKL ); 
 __xJL :
 if(! __ZML )goto __aML ;
 __XJL = "Did not initialize Dynamic" ;
 goto __bML ;
 __builtin_unreachable();
 __aML :
 __cML = __WLL +1; __dML = true ; __eML = __jLL ; if ( __cML >= __jLL ) { __jLL = __jLL + __jLL /2+1; __fML =( ptr )((( ptr **) __U8G__acquired )[0]? __runtime_realloc ((( ptr **) __U8G__acquired )[0], __jLL * sizeof ( ptr ), __eML * sizeof ( ptr )): __runtime_alloc ( __jLL * sizeof ( ptr ))); if (( __dML = __fML ))(( ptr **) __U8G__acquired )[0]=( ptr *) __fML ; } if ( __dML ) { __sJL =( ptr ) __runtime_alloc ( __WML * sizeof ( __tLL )); if (( __dML = __sJL )) {(( ptr **) __U8G__acquired )[0][ __WLL ]= __sJL ; __WLL = __cML ; } } 
 __gML = __dML ;
 __vIL =(! __gML ); 
 __hML :
 if(! __vIL )goto __dJL ;
 __NLL = "Failed a Dynamic allocation" ;
 goto __TJL ;
 __builtin_unreachable();
 __dJL :
 __iML = 0 ;
 __LKL = sizeof ( __iML )* __WML ; 
 __jML :
 __tLL = __iML ;
 memcpy (( char *) __sJL ,( char *) __TML , __UML ); memcpy (( char *) __sJL + __UML ,( char *) __OML , __GLL );(( char *) __sJL )[ __VML ]=0; 
 __lML = __sJL ;
 __PLL = __iJL ;
 __U8G__acquired = __U8G__acquired ;
 __WLL = __WLL ;
 __jLL = __jLL ;
 __kLL = __kLL ;
 __mML = __runtime_alloc ( sizeof ( ptr **)); if ( __mML )(( ptr **) __mML )[0]=0; 
 __rIL = 0 ;
 __oML = 0 ;
 __b8G__acquired = __mML ;
 __pML = __rIL ;
 __qML = __oML ;
 __rML = __sML ;
 {char mark;if(__service_stack_floor+ 1180 >=(char*)&mark) goto __service_stack_floor_handler;} __d8G____state = (struct run__926__state*)__runtime_calloc(sizeof(struct run__926__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __d8G____state ) ;
 __d8G____state -> command____FC = command____FC ;
 __d8G____state -> command__contents = __lML ;
 __d8G____state -> command__length = __VML ;
 __d8G____state -> command__first = __QML ;
 __d8G____state -> command__memory = __U8G__acquired ;
 __uML = __smolambda_add_task ( run__926 , __d8G____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __uML ) ;
 if( __mIL ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __uML ) ;
 __mIL = __d8G____state -> err ;
 __lIL = __mIL ;
 if(! __lIL )goto __kIL ;
 __jIL = "[ \033[31mERROR\033[0m ] " ;
 __iIL = ".s" ;
 __hIL = strlen ( name ); __gIL =( ptr ) name ; __fIL = name [0]; __eIL =( ptr ) __eIL ; 
 __dIL = __gIL ;
 __cIL = strlen ( __iIL ); __bIL =( ptr ) __iIL ; __aIL = __iIL [0]; __ZIL =( ptr ) __ZIL ; 
 __YIL = __bIL ;
 __XIL = __hIL ; __WIL = __cIL ; __VIL = __XIL + __WIL ; __UIL = __hIL ? __fIL : __aIL ; 
 __TIL = 1 ;
 __SIL = __VIL + __TIL ; 
 __RIL :
 __QIL = 0 ;
 __PIL = __OIL ;
 __ok = __b8G__acquired ;
 __MIL =(! __ok ); 
 __LIL :
 if(! __MIL )goto __KIL ;
 __JIL = "Did not initialize Dynamic" ;
 goto __IIL ;
 __builtin_unreachable();
 __KIL :
 __HIL = __pML +1; __GIL = true ; __FIL = __qML ; if ( __HIL >= __qML ) { __qML = __qML + __qML /2+1; __EIL =( ptr )((( ptr **) __b8G__acquired )[0]? __runtime_realloc ((( ptr **) __b8G__acquired )[0], __qML * sizeof ( ptr ), __FIL * sizeof ( ptr )): __runtime_alloc ( __qML * sizeof ( ptr ))); if (( __GIL = __EIL ))(( ptr **) __b8G__acquired )[0]=( ptr *) __EIL ; } if ( __GIL ) { __nML =( ptr ) __runtime_alloc ( __SIL * sizeof ( __PIL )); if (( __GIL = __nML )) {(( ptr **) __b8G__acquired )[0][ __pML ]= __nML ; __pML = __HIL ; } } 
 __DIL = __GIL ;
 __CIL =(! __DIL ); 
 __BIL :
 if(! __CIL )goto __AIL ;
 __9HL = "Failed a Dynamic allocation" ;
 goto __8HL ;
 __builtin_unreachable();
 __AIL :
 __7HL = 0 ;
 __6HL = sizeof ( __7HL )* __SIL ; 
 __5HL :
 __PIL = __7HL ;
 memcpy (( char *) __nML ,( char *) __dIL , __XIL ); memcpy (( char *) __nML + __XIL ,( char *) __YIL , __WIL );(( char *) __nML )[ __VIL ]=0; 
 __4HL = __nML ;
 __3HL = __2HL ;
 __b8G__acquired = __b8G__acquired ;
 __pML = __pML ;
 __qML = __qML ;
 __rML = __rML ;
 __kML = strlen ( __jIL ); __1HL =( ptr ) __jIL ; __0HL = __jIL [0]; __zHL =( ptr ) __zHL ; 
 __yHL = __1HL ;
 __AJL = __kML ; __xHL = __VIL ; __wHL = __AJL + __xHL ; __vHL = __kML ? __0HL : __UIL ; 
 __uHL = 1 ;
 __4IL = __wHL + __uHL ; 
 __tHL :
 __HJL = 0 ;
 __sHL = __rHL ;
 __qHL = __b8G__acquired ;
 __pHL =(! __qHL ); 
 __oHL :
 if(! __pHL )goto __nHL ;
 __mHL = "Did not initialize Dynamic" ;
 goto __lHL ;
 __builtin_unreachable();
 __nHL :
 __kHL = __pML +1; __jHL = true ; __iHL = __qML ; if ( __kHL >= __qML ) { __qML = __qML + __qML /2+1; __hHL =( ptr )((( ptr **) __b8G__acquired )[0]? __runtime_realloc ((( ptr **) __b8G__acquired )[0], __qML * sizeof ( ptr ), __iHL * sizeof ( ptr )): __runtime_alloc ( __qML * sizeof ( ptr ))); if (( __jHL = __hHL ))(( ptr **) __b8G__acquired )[0]=( ptr *) __hHL ; } if ( __jHL ) { __gHL =( ptr ) __runtime_alloc ( __4IL * sizeof ( __sHL )); if (( __jHL = __gHL )) {(( ptr **) __b8G__acquired )[0][ __pML ]= __gHL ; __pML = __kHL ; } } 
 __fHL = __jHL ;
 __eHL =(! __fHL ); 
 __dHL :
 if(! __eHL )goto __cHL ;
 __bHL = "Failed a Dynamic allocation" ;
 goto __aHL ;
 __builtin_unreachable();
 __cHL :
 __ZHL = 0 ;
 __YHL = sizeof ( __ZHL )* __4IL ; 
 __XHL :
 __sHL = __ZHL ;
 memcpy (( char *) __gHL ,( char *) __yHL , __AJL ); memcpy (( char *) __gHL + __AJL ,( char *) __4HL , __xHL );(( char *) __gHL )[ __wHL ]=0; 
 __WHL = __gHL ;
 __3HL = __VHL ;
 __b8G__acquired = __b8G__acquired ;
 __pML = __pML ;
 __qML = __qML ;
 __rML = __rML ;
 printf ( "%s\n" ,( char *) __WHL ); 
 __UHL :
 goto __THL ;
 __kIL :
 __SHL = "[ \033[32mOK\033[0m ] " ;
 __RHL = ".s" ;
 __QHL = strlen ( name ); __PHL =( ptr ) name ; __OHL = name [0]; __NHL =( ptr ) __NHL ; 
 __MHL = __PHL ;
 __LHL = strlen ( __RHL ); __KHL =( ptr ) __RHL ; __JHL = __RHL [0]; __IHL =( ptr ) __IHL ; 
 __HHL = __KHL ;
 __GHL = __QHL ; __FHL = __LHL ; __EHL = __GHL + __FHL ; __DHL = __QHL ? __OHL : __JHL ; 
 __CHL = 1 ;
 __fLL = __EHL + __CHL ; 
 __BHL :
 __AHL = 0 ;
 __9GL = __8GL ;
 __7GL = __b8G__acquired ;
 __6GL =(! __7GL ); 
 __5GL :
 if(! __6GL )goto __4GL ;
 __3GL = "Did not initialize Dynamic" ;
 goto __2GL ;
 __builtin_unreachable();
 __4GL :
 __1GL = __pML +1; __1LL = true ; __0GL = __qML ; if ( __1GL >= __qML ) { __qML = __qML + __qML /2+1; __zGL =( ptr )((( ptr **) __b8G__acquired )[0]? __runtime_realloc ((( ptr **) __b8G__acquired )[0], __qML * sizeof ( ptr ), __0GL * sizeof ( ptr )): __runtime_alloc ( __qML * sizeof ( ptr ))); if (( __1LL = __zGL ))(( ptr **) __b8G__acquired )[0]=( ptr *) __zGL ; } if ( __1LL ) { __yGL =( ptr ) __runtime_alloc ( __fLL * sizeof ( __9GL )); if (( __1LL = __yGL )) {(( ptr **) __b8G__acquired )[0][ __pML ]= __yGL ; __pML = __1GL ; } } 
 __xGL = __1LL ;
 __qIL =(! __xGL ); 
 __wGL :
 if(! __qIL )goto __vGL ;
 __uGL = "Failed a Dynamic allocation" ;
 goto __tGL ;
 __builtin_unreachable();
 __vGL :
 __sGL = 0 ;
 __rGL = sizeof ( __sGL )* __fLL ; 
 __qGL :
 __9GL = __sGL ;
 memcpy (( char *) __yGL ,( char *) __MHL , __GHL ); memcpy (( char *) __yGL + __GHL ,( char *) __HHL , __FHL );(( char *) __yGL )[ __EHL ]=0; 
 __pGL = __yGL ;
 __3HL = __oGL ;
 __b8G__acquired = __b8G__acquired ;
 __pML = __pML ;
 __qML = __qML ;
 __rML = __rML ;
 __nGL = strlen ( __SHL ); __mGL =( ptr ) __SHL ; __lGL = __SHL [0]; __kGL =( ptr ) __kGL ; 
 __jGL = __mGL ;
 __iGL = __nGL ; __hGL = __EHL ; __gGL = __iGL + __hGL ; __fGL = __nGL ? __lGL : __DHL ; 
 __eGL = 1 ;
 __dGL = __gGL + __eGL ; 
 __cGL :
 __bGL = 0 ;
 __aGL = __ZGL ;
 __YGL = __b8G__acquired ;
 __XGL =(! __YGL ); 
 __WGL :
 if(! __XGL )goto __VGL ;
 __UGL = "Did not initialize Dynamic" ;
 goto __TGL ;
 __builtin_unreachable();
 __VGL :
 __SGL = __pML +1; __RGL = true ; __QGL = __qML ; if ( __SGL >= __qML ) { __qML = __qML + __qML /2+1; __PGL =( ptr )((( ptr **) __b8G__acquired )[0]? __runtime_realloc ((( ptr **) __b8G__acquired )[0], __qML * sizeof ( ptr ), __QGL * sizeof ( ptr )): __runtime_alloc ( __qML * sizeof ( ptr ))); if (( __RGL = __PGL ))(( ptr **) __b8G__acquired )[0]=( ptr *) __PGL ; } if ( __RGL ) { __OGL =( ptr ) __runtime_alloc ( __dGL * sizeof ( __aGL )); if (( __RGL = __OGL )) {(( ptr **) __b8G__acquired )[0][ __pML ]= __OGL ; __pML = __SGL ; } } 
 __NGL = __RGL ;
 __MGL =(! __NGL ); 
 __LGL :
 if(! __MGL )goto __KGL ;
 __JGL = "Failed a Dynamic allocation" ;
 goto __IGL ;
 __builtin_unreachable();
 __KGL :
 __HGL = 0 ;
 __GGL = sizeof ( __HGL )* __dGL ; 
 __FGL :
 __aGL = __HGL ;
 memcpy (( char *) __OGL ,( char *) __jGL , __iGL ); memcpy (( char *) __OGL + __iGL ,( char *) __pGL , __hGL );(( char *) __OGL )[ __gGL ]=0; 
 __EGL = __OGL ;
 __3HL = __DGL ;
 __b8G__acquired = __b8G__acquired ;
 __pML = __pML ;
 __qML = __qML ;
 __rML = __rML ;
 printf ( "%s\n" ,( char *) __EGL ); 
 __CGL :
 __THL :
 __BGL :
goto __return;

// ERROR HANDLING
__LML :
 printf ( "%s\n" , __KML ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__IIL :
 printf ( "%s\n" , __JIL ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__tIL :
 printf ( "%s\n" , __MKL ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__error_code =__UNHANDLED__ERROR;
goto __failsafe ;
__bML :
 printf ( "%s\n" , __XJL ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__IGL :
 printf ( "%s\n" , __JGL ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__2GL :
 printf ( "%s\n" , __3GL ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__service_stack_floor_handler:
printf("Insufficient stack for safe service call (too much recursion or stack allocation)\n");
__result__error_code=__STACK__ERROR;
goto __failsafe;
__8HL :
 printf ( "%s\n" , __9HL ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__TJL :
 printf ( "%s\n" , __NLL ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__lHL :
 printf ( "%s\n" , __mHL ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__TGL :
 printf ( "%s\n" , __UGL ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__tGL :
 printf ( "%s\n" , __uGL ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__AGL :
__result__error_code=__UNHANDLED__ERROR;
goto __failsafe;
__aHL :
 printf ( "%s\n" , __bHL ); 
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
if ( __b8G__acquired ) { for ( __rML =0; __rML < __pML ;++ __rML ) { __runtime_free ((( ptr **) __b8G__acquired )[0][ __rML ]); } __runtime_free ( __b8G__acquired ); __b8G__acquired =0; __pML =0; __qML =0; } 
 if ( __b8G__acquired ) { for ( __sML =0; __sML < __rIL ;++ __sML ) { __runtime_free ((( ptr **) __b8G__acquired )[0][ __sML ]); } __runtime_free ( __b8G__acquired ); __b8G__acquired =0; __rIL =0; __oML =0; } 
if ( __U8G__acquired ) { for ( __kLL =0; __kLL < __WLL ;++ __kLL ) { __runtime_free ((( ptr **) __U8G__acquired )[0][ __kLL ]); } __runtime_free ( __U8G__acquired ); __U8G__acquired =0; __WLL =0; __jLL =0; } 
 if ( __U8G__acquired ) { for ( __lLL =0; __lLL < __hLL ;++ __lLL ) { __runtime_free ((( ptr **) __U8G__acquired )[0][ __lLL ]); } __runtime_free ( __U8G__acquired ); __U8G__acquired =0; __hLL =0; __iLL =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__error_code;
}


void run__925(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1164;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__925__state *__state=(struct run__925__state*)__void__state;
cstr command= __state->command;
i64 __JNL=0;
bool __INL=0;
ptr __HNL=0;
ptr __GNL=0;
ptr __ENL=0;
u64 __DNL=0;
ptr __CNL=0;
char __BNL=0;
ptr __S6G__contents=0;
ptr __ANL=0;
ptr __FNL=0;
ptr process__contents=0;
bool __4ML=0;
nominal process____blG=0;
nominal __vML=0;

// IMPLEMENTATION
__CNL = 0 ;
 __ANL = __CNL ;
 __DNL = strlen ( command ); __ENL =( ptr ) command ; __BNL = command [0]; __FNL =( ptr ) __FNL ; 
 __GNL = __ENL ;
 __S6G__contents =( ptr ) popen (( cstr ) __GNL , "r" ); 
 __HNL = __S6G__contents ;
 __INL =( __HNL ); 
 __KNL :
 __4ML =(! __INL ); 
 __LNL :
 if(! __4ML )goto __MNL ;
 goto __xML ;
 __builtin_unreachable();
 __MNL :
 process__contents = __S6G__contents ;
 if ( process__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process__contents )) { } } 
 __wML :
 process____blG = __vML ;
 __JNL =0; if ( process__contents ) __JNL = pclose (( FILE *) process__contents ); process__contents =0; if ( __JNL ) { if ( __JNL !=-1&& WIFEXITED ( __JNL )) __JNL = WEXITSTATUS ( __JNL ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __JNL ); __result__error_code = __USER__ERROR ; goto __failsafe ; } 
 __2ML :
goto __return;

// ERROR HANDLING
__xML :
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


void main__933(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 18860;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__933__state *__state=(struct main__933__state*)__void__state;
struct all__932__state* __egI____state = 0 ;
f64 __ZNL=0;
ptr __XNL=0;
errcode __WNL=0;
cstr __VNL=0;
f64 __TNL=0;
f64 __RNL=0;
cstr __PNL=0;

// IMPLEMENTATION
__ZNL = __smo_time_eta (); 
 __YNL :
 {char mark;if(__service_stack_floor+ 19124 >=(char*)&mark) goto __service_stack_floor_handler;} __egI____state = (struct all__932__state*)__runtime_calloc(sizeof(struct all__932__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __egI____state ) ;
 __XNL = __smolambda_add_task ( all__932 , __egI____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __XNL ) ;
 if( __WNL ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __XNL ) ;
 __WNL = __egI____state -> err ;
 __VNL = "Completed in " ;
 printf ( "%s" , __VNL ); 
 __UNL :
 __TNL = __smo_time_eta (); 
 __SNL :
 __RNL = __TNL - __ZNL ; 
 __oiL :
 printf ( "%.6f" , __RNL ); 
 __QNL :
 __PNL = " sec" ;
 printf ( "%s\n" , __PNL ); 
 __CnL :
 __ONL :
goto __return;

// ERROR HANDLING
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__error_code =__UNHANDLED__ERROR;
goto __failsafe ;
__NNL :
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
struct main__933__state __main_args={0};
__smolambda_initialize_service_tasks(main__933, &__main_args);
return __main_args.err;
}

