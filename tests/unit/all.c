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

struct main__822__state{errcode err;};
__externc void main__822(void *__void__state);
struct std_test__818__state{errcode err;cstr name;};
__externc void std_test__818(void *__void__state);
struct std_test__819__state{errcode err;nominal name____b;ptr name__contents;u64 name__length;char name__first;ptr name__memory;};
__externc void std_test__819(void *__void__state);
struct std_test__820__state{errcode err;nominal name____c;ptr name__contents;u64 name__length;char name__first;ptr name__memory;};
__externc void std_test__820(void *__void__state);
struct run__814__state{errcode err;cstr command;};
__externc void run__814(void *__void__state);
struct run__815__state{errcode err;nominal command____b;ptr command__contents;u64 command__length;char command__first;ptr command__memory;};
__externc void run__815(void *__void__state);
struct run__816__state{errcode err;nominal command____c;ptr command__contents;u64 command__length;char command__first;ptr command__memory;};
__externc void run__816(void *__void__state);
struct all__821__state{errcode err;};
__externc void all__821(void *__void__state);

void run__815(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__815__state *__state=(struct run__815__state*)__void__state;
ptr command__contents= __state->command__contents;
u64 command__length= __state->command__length;
char command__first= __state->command__first;
ptr command__memory= __state->command__memory;
nominal __lAB__p____78=0;
bool __kAB____YAB____D9__z=0;
bool __kAB____YAB____C9__z=0;
ptr __kAB____YAB____A9__noptr=0;
char __kAB____YAB____A9__first=0;
ptr __kAB____WAB__contents=0;
ptr __kAB____YAB____C9__x=0;
cstr __kAB__mem=0;
bool process____YAB____C9__z=0;
bool process____UAB____mF__z=0;
ptr process____XAB__contents=0;
u64 process____YAB____A9__length=0;
u64 __kAB____YAB____A9__length=0;
ptr process____YAB____A9____p__contents=0;
u64 __kAB____RAB__z=0;
ptr __kAB____YAB____A9__contents=0;
ptr __kAB____UAB__mem=0;
cstr process____UAB____nF=0;
bool __kAB____UAB____sF__z=0;
u64 process____UAB____1F__bytesize=0;
bool process____UAB____rF=0;
u64 process____UAB__size=0;
i64 __kAB____YAB__status=0;
char process__command__first=0;
ptr process____YAB____A9__contents=0;
ptr __jAB__contents=0;
i64 process____YAB__status=0;
char process____UAB____pF=0;
u64 process__command__length=0;
ptr process____NAB__contents=0;
ptr process____WAB__contents=0;
char process____YAB____A9__first=0;
char process____SAB=0;
ptr process__command__memory=0;
u64 process____UAB____lF=0;
nominal process__command____b=0;
ptr process____UAB__mem=0;
char __kAB____UAB____1F____8E=0;
char process____UAB____1F____8E=0;
char process__first=0;
ptr __kAB____YAB____A9____p__contents=0;
cstr process__mem=0;
bool process____YAB____D9__z=0;
ptr process____YAB____A9__noptr=0;
char process____UAB____zF=0;
char __kAB____SAB=0;
cstr process____UAB____tF=0;
ptr process____YAB__contents=0;
ptr process__command__contents=0;
ptr process____YAB____C9__x=0;
nominal command____b=0;
nominal process____NAB____78=0;
nominal process____YAB____78=0;
u64 process____QAB=0;
u64 process____RAB__z=0;
bool process____UAB____sF__z=0;
ptr __iAB__contents=0;
char __kAB__first=0;
u64 __kAB____QAB=0;
u64 __kAB____UAB____lF=0;
bool __kAB____UAB____mF__z=0;
cstr __kAB____UAB____nF=0;
char __kAB____UAB____pF=0;
ptr __kAB____YAB__contents=0;
bool __kAB____UAB____rF=0;
cstr __kAB____UAB____tF=0;
char __kAB____UAB____zF=0;
u64 __kAB____UAB____1F__bytesize=0;

// IMPLEMENTATION
__iAB__contents = 0 ;
 __jAB__contents = __iAB__contents ;
 __kAB____QAB = 1 ;
 __kAB____RAB__z = command__length + __kAB____QAB ; 
 __kAB____RAB____end :
 __kAB____SAB = 0 ;
 __kAB____UAB____lF = 0 ;
 __kAB____UAB____mF__z =( __kAB____RAB__z == __kAB____UAB____lF ); 
 __kAB____UAB____mF____end :
 if(! __kAB____UAB____mF__z )goto __kAB____UAB____kF__fi ;
 __kAB____UAB____nF = "Cannot allocate zero size" ;
 goto __kAB____UAB____oF____oD ;
 __builtin_unreachable();
 __kAB____UAB____kF__fi :
 __kAB____UAB__mem = alloca ( __kAB____RAB__z * sizeof ( __kAB____UAB____pF )); 
 __kAB____UAB____rF = __kAB____UAB__mem ;
 __kAB____UAB____sF__z =(! __kAB____UAB____rF ); 
 __kAB____UAB____sF____end :
 if(! __kAB____UAB____sF__z )goto __kAB____UAB____qF__fi ;
 __kAB____UAB____tF = "Failed a Stack allocation" ;
 goto __kAB____UAB____uF____oD ;
 __builtin_unreachable();
 __kAB____UAB____qF__fi :
 __kAB____UAB____zF = 0 ;
 __kAB____UAB____1F__bytesize = sizeof ( __kAB____UAB____1F____8E )* __kAB____RAB__z ; 
 __kAB____UAB____1F____end :
 __kAB__first =0; if ( __kAB____UAB__mem ) { memcpy (( char *) __kAB____UAB__mem , command__contents , command__length );(( char *) __kAB____UAB__mem )[ command__length ]=0; } __kAB__mem =( const char *) __kAB____UAB__mem ; 
 __kAB____WAB__contents = 0 ;
 __kAB____YAB____A9__length = strlen ( __kAB__mem ); __kAB____YAB____A9__contents =( ptr ) __kAB__mem ; __kAB____YAB____A9__first = __kAB__mem [0]; __kAB____YAB____A9__noptr =( ptr ) __kAB____YAB____A9__noptr ; 
 __kAB____YAB____A9____p__contents = __kAB____YAB____A9__contents ;
 __kAB____YAB__contents =( ptr ) popen (( cstr ) __kAB____YAB____A9____p__contents , "r" ); 
 __kAB____YAB____C9__x = __kAB____YAB__contents ;
 __kAB____YAB____C9__z =( __kAB____YAB____C9__x ); 
 __kAB____YAB____C9____end :
 __kAB____YAB____D9__z =(! __kAB____YAB____C9__z ); 
 __kAB____YAB____D9____end :
 if(! __kAB____YAB____D9__z )goto __kAB____YAB____B9__fi ;
 goto __kAB____YAB____E9 ;
 __builtin_unreachable();
 __kAB____YAB____B9__fi :
 __TRANSIENT( __kAB____UAB__mem )
 process____YAB__contents = __kAB____YAB__contents ;
 if ( process____YAB__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process____YAB__contents )) { } } 
 __lAB____end :
 process____YAB____78 = __lAB__p____78 ;
 __kAB____YAB__status =0; if ( process____YAB__contents ) __kAB____YAB__status = pclose (( FILE *) process____YAB__contents ); process____YAB__contents =0; if ( __kAB____YAB__status ) { if ( __kAB____YAB__status !=-1&& WIFEXITED ( __kAB____YAB__status )) __kAB____YAB__status = WEXITSTATUS ( __kAB____YAB__status ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __kAB____YAB__status ); __result__errocode = __USER__ERROR ; goto __failsafe ; } 
 __end :
goto __return;

// ERROR HANDLING
__kAB____YAB____E9 :
 printf ( "Error: Failed to start process\n" ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__kAB____UAB____uF____oD :
 printf ( "%s\n" , __kAB____UAB____tF ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__kAB____UAB____oF____oD :
 printf ( "%s\n" , __kAB____UAB____nF ); 
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
nominal __qAB__p____78=0;
nominal process____78=0;
ptr process__contents=0;
ptr __pAB__contents=0;
i64 __pAB__status=0;
nominal command____c=0;
ptr __nAB__contents=0;
bool __pAB____M9__z=0;
ptr __pAB____L9__x=0;
ptr __oAB__contents=0;
bool __pAB____L9__z=0;

// IMPLEMENTATION
__nAB__contents = 0 ;
 __oAB__contents = __nAB__contents ;
 __pAB__contents =( ptr ) popen (( cstr ) command__contents , "r" ); 
 __pAB____L9__x = __pAB__contents ;
 __pAB____L9__z =( __pAB____L9__x ); 
 __pAB____L9____end :
 __pAB____M9__z =(! __pAB____L9__z ); 
 __pAB____M9____end :
 if(! __pAB____M9__z )goto __pAB____K9__fi ;
 goto __pAB____N9 ;
 __builtin_unreachable();
 __pAB____K9__fi :
 process__contents = __pAB__contents ;
 if ( process__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process__contents )) { } } 
 __qAB____end :
 process____78 = __qAB__p____78 ;
 __pAB__status =0; if ( process__contents ) __pAB__status = pclose (( FILE *) process__contents ); process__contents =0; if ( __pAB__status ) { if ( __pAB__status !=-1&& WIFEXITED ( __pAB__status )) __pAB__status = WEXITSTATUS ( __pAB__status ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __pAB__status ); __result__errocode = __USER__ERROR ; goto __failsafe ; } 
 __end :
goto __return;

// ERROR HANDLING
__pAB____N9 :
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


void run__814(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__814__state *__state=(struct run__814__state*)__void__state;
cstr command= __state->command;
i64 __fAB__status=0;
nominal __gAB__p____78=0;
ptr __fAB____A9__noptr=0;
char __fAB____A9__first=0;
ptr __dAB__contents=0;
ptr process__contents=0;
ptr __eAB__contents=0;
ptr __fAB__contents=0;
u64 __fAB____A9__length=0;
ptr __fAB____A9__contents=0;
bool __fAB____C9__z=0;
nominal process____78=0;
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


void std_test__820(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__820__state *__state=(struct std_test__820__state*)__void__state;
struct run__816__state* __0BB____state = 0 ;
ptr name__contents= __state->name__contents;
u64 name__length= __state->name__length;
char name__first= __state->name__first;
ptr name__memory= __state->name__memory;
nominal __BCB____1h__self____TQ=0;
ptr __BCB____4h__contents=0;
char __BCB____1h____wQ____CF=0;
u64 __BCB____1h____wQ__bytesize=0;
char __BCB____1h____uQ=0;
ptr __BCB____1h__mem=0;
ptr __BCB____1h__next_acquired=0;
u64 __BCB____1h__next_size=0;
char __BCB____zh=0;
u64 __BCB__total_len=0;
u64 __BCB__len_y=0;
u64 __BCB__len_x=0;
ptr __BCB____vh__noptr=0;
ptr __ACB____Yd__contents=0;
cstr __ACB____Vd____oQ=0;
bool __ACB____Vd____nQ__x=0;
char __ACB____Vd____gQ=0;
ptr __ACB____Vd__mem=0;
ptr __ACB____Vd__next_acquired=0;
u64 __ACB____Vd__self__allocated__prev=0;
bool __ACB____Vd__success=0;
cstr __ACB____Vd____kQ=0;
bool __ACB____Vd____iQ=0;
u64 __ACB____Sd__z=0;
u64 __ACB__len_x=0;
cstr __9BB=0;
char __6BB____1h____wQ____CF=0;
u64 __6BB____1h____wQ__bytesize=0;
cstr __6BB____1h____oQ=0;
bool __6BB____1h____nQ__z=0;
bool __6BB____1h____nQ__x=0;
ptr __6BB____1h__next_acquired=0;
u64 __6BB____1h__next_size=0;
u64 __ACB____Rd=0;
cstr __BCB____1h____kQ=0;
u64 __6BB____xh=0;
u64 __6BB__total_len=0;
u64 __6BB__len_x=0;
ptr __6BB____vh____m__contents=0;
ptr __6BB____vh__noptr=0;
char __6BB____vh__first=0;
nominal __5BB____Vd__self____TQ=0;
nominal __xBB____TQ=0;
u64 __ACB____Vd____wQ__bytesize=0;
char __6BB__first=0;
ptr __5BB____Yd__contents=0;
cstr __5BB____Vd____oQ=0;
char __ACB____Vd____wQ____CF=0;
bool __5BB____Vd____nQ__x=0;
u64 __5BB____Vd__next_size=0;
cstr __5BB____Vd____kQ=0;
char __5BB____Vd____wQ____CF=0;
bool __5BB____Vd____nQ__z=0;
bool __5BB____Vd____iQ=0;
char __5BB____Td=0;
u64 __5BB____Sd__z=0;
u64 __5BB____Rd=0;
char __5BB__first=0;
u64 __5BB__len_x=0;
ptr __5BB____Qd__noptr=0;
char __5BB____Qd__first=0;
ptr __5BB____Qd__contents=0;
bool __6BB____1h__success=0;
u64 __5BB____Qd__length=0;
u64 __5BB____Vd____wQ__bytesize=0;
ptr __0BB____task=0;
ptr command__memory=0;
u64 command__length=0;
ptr command__contents=0;
u64 __xBB____dynamic_entry=0;
bool __6BB____1h____jQ__z=0;
u64 __xBB__size=0;
nominal __uBB____1h__self____TQ=0;
ptr __uBB____4h__contents=0;
char __uBB____1h____wQ____CF=0;
u64 __uBB____1h____wQ__bytesize=0;
char __uBB____1h____uQ=0;
cstr __uBB____1h____oQ=0;
char __ACB____Vd____uQ=0;
u64 __6BB____1h__self__allocated__prev=0;
bool __uBB____1h____nQ__x=0;
char __uBB____1h____gQ=0;
ptr __uBB____1h__mem=0;
ptr __uBB____1h__next_acquired=0;
u64 __6BB__len_y=0;
cstr __uBB____1h____kQ=0;
bool __uBB____1h____jQ__z=0;
u64 __6BB____yh__z=0;
cstr __4BB=0;
char __uBB____zh=0;
ptr __6BB____1h__mem=0;
char __uBB__first=0;
char __ACB____Td=0;
u64 __uBB__total_len=0;
u64 __uBB__len_x=0;
char __uBB____vh__first=0;
ptr __uBB____vh__contents=0;
nominal __tBB____Hk__self____TQ=0;
ptr __BCB____vh____m__contents=0;
u64 __tBB____Hk____wQ__bytesize=0;
char __tBB____Hk____uQ=0;
u64 __uBB____1h__next_size=0;
u64 __uBB__len_y=0;
bool __tBB____Hk____nQ__z=0;
bool __tBB____Hk____nQ__x=0;
char __tBB____Hk____gQ=0;
ptr __tBB____Hk__mem=0;
u64 __tBB____Hk__self__allocated__prev=0;
u64 __xBB____ZQ____dynamic_entry=0;
u64 __BCB____vh__length=0;
bool __2BB=0;
char __sBB____Fb____gQ=0;
u64 __6BB____vh__length=0;
ptr __tBB____Kk__contents=0;
u64 __ACB__len_y=0;
char __6BB____zh=0;
bool __uBB____1h____iQ=0;
bool __tBB____Hk____jQ__z=0;
char __BCB____1h____gQ=0;
u64 __oBB____ZQ____UQ=0;
ptr __ACB____Qd__contents=0;
char __tBB____Hk____wQ____CF=0;
u64 __BCB____xh=0;
u64 __sBB____Fb__self__allocated__prev=0;
char __tBB__first=0;
char __BCB____vh__first=0;
u64 __ACB__total_len=0;
nominal command____c=0;
char __5BB____Vd____uQ=0;
ptr __uBB____vh__noptr=0;
char __ACB__first=0;
ptr __5BB____Vd__next_acquired=0;
char command__first=0;
char __5BB____Vd____gQ=0;
bool __tBB____Hk__success=0;
char __BCB__first=0;
bool __sBB____Fb____iQ=0;
cstr __3BB=0;
u64 __uBB____vh__length=0;
ptr __6BB____vh__contents=0;
char __6BB____1h____gQ=0;
bool __BCB____1h__success=0;
char __ACB____Qd__first=0;
nominal __6BB____1h__self____TQ=0;
ptr __BCB____vh__contents=0;
bool __5BB____Vd____jQ__z=0;
char __6BB____1h____uQ=0;
u64 __xBB__allocated=0;
cstr __rBB=0;
u64 __ACB____Qd__length=0;
bool __ACB____Vd____nQ__z=0;
bool __sBB____Fb____nQ__z=0;
ptr __sBB____Ib__contents=0;
u64 __uBB____xh=0;
cstr __qBB=0;
u64 __sBB__len_y=0;
ptr __5BB____Qd____m__contents=0;
u64 __sBB____Ab__length=0;
u64 __BCB____yh__z=0;
ptr __6BB____4h__contents=0;
ptr __xBB__acquired=0;
u64 __5BB__total_len=0;
u64 __oBB____dynamic_entry=0;
bool __uBB____1h__success=0;
cstr __tBB____Hk____oQ=0;
ptr __sBB____9a__contents=0;
nominal __sBB____Fb__self____TQ=0;
u64 __tBB__total_len=0;
ptr __ACB____Qd__noptr=0;
ptr __oBB__acquired=0;
u64 __ACB____Vd__next_size=0;
nominal name____c=0;
ptr __sBB____Ab__noptr=0;
bool __uBB____1h____nQ__z=0;
bool __BCB____1h____jQ__z=0;
ptr __ACB____Qd____m__contents=0;
u64 __5BB____Vd__self__allocated__prev=0;
u64 __sBB____Fb____wQ__bytesize=0;
u64 __oBB____ZQ____dynamic_entry=0;
u64 __uBB____1h__self__allocated__prev=0;
bool __6BB____1h____iQ=0;
u64 __xBB____ZQ____UQ=0;
u64 __oBB__size=0;
ptr __5BB____Vd__mem=0;
bool __BCB____1h____iQ=0;
nominal __ACB____Vd__self____TQ=0;
bool __BCB____1h____nQ__z=0;
char __sBB____Db=0;
bool __ACB____Vd____jQ__z=0;
ptr __sBB____Fb__mem=0;
cstr __6BB____1h____kQ=0;
ptr __sBB____9a____m__contents=0;
cstr __lBB=0;
u64 __BCB____1h__self__allocated__prev=0;
ptr __oBB____ZQ__acquired=0;
bool __sBB____Fb____jQ__z=0;
u64 __oBB____ZQ____VQ=0;
u64 __oBB__allocated=0;
ptr __tBB____Hk__next_acquired=0;
u64 __sBB____9a__length=0;
nominal __oBB____TQ=0;
char __sBB____9a__first=0;
u64 __sBB____Cb__z=0;
ptr __sBB____9a__noptr=0;
ptr __sBB____Ab__contents=0;
char __sBB____Ab__first=0;
bool __tBB____Hk____iQ=0;
ptr __sBB____Ab____m__contents=0;
ptr __xBB____ZQ__acquired=0;
u64 __sBB__len_x=0;
u64 __sBB__total_len=0;
u64 __xBB____ZQ____VQ=0;
char __sBB__first=0;
bool __BCB____1h____nQ__x=0;
u64 __sBB____Bb=0;
u64 __5BB__len_y=0;
cstr __sBB____Fb____kQ=0;
cstr __BCB____1h____oQ=0;
u64 __sBB____Fb__next_size=0;
ptr __sBB____Fb__next_acquired=0;
u64 __uBB____yh__z=0;
bool __sBB____Fb____nQ__x=0;
cstr __sBB____Fb____oQ=0;
bool __5BB____Vd__success=0;
char __sBB____Fb____uQ=0;
char __sBB____Fb____wQ____CF=0;
cstr __8BB=0;
u64 __tBB__len_x=0;
u64 __tBB__len_y=0;
u64 __tBB____Dk=0;
errcode __0BB__err=0;
ptr __uBB____vh____m__contents=0;
u64 __tBB____Ek__z=0;
char __tBB____Fk=0;
cstr __tBB____Hk____kQ=0;
bool __sBB____Fb__success=0;
u64 __tBB____Hk__next_size=0;

// IMPLEMENTATION
__lBB = " 2>&1" ;
 __oBB____ZQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __oBB____ZQ__acquired )(( ptr **) __oBB____ZQ__acquired )[0]=0; 
 __oBB____ZQ____UQ = 0 ;
 __oBB____ZQ____VQ = 0 ;
 __oBB__acquired = __oBB____ZQ__acquired ;
 __oBB__size = __oBB____ZQ____UQ ;
 __oBB__allocated = __oBB____ZQ____VQ ;
 __oBB____dynamic_entry = __oBB____ZQ____dynamic_entry ;
 __qBB = "./smol tests/unit/" ;
 __rBB = ".s --workers 1 --runtime eager" ;
 __sBB____9a__length = strlen ( __rBB ); __sBB____9a__contents =( ptr ) __rBB ; __sBB____9a__first = __rBB [0]; __sBB____9a__noptr =( ptr ) __sBB____9a__noptr ; 
 __sBB____9a____m__contents = __sBB____9a__contents ;
 __sBB____Ab__length = strlen ( __lBB ); __sBB____Ab__contents =( ptr ) __lBB ; __sBB____Ab__first = __lBB [0]; __sBB____Ab__noptr =( ptr ) __sBB____Ab__noptr ; 
 __sBB____Ab____m__contents = __sBB____Ab__contents ;
 __sBB__len_x = __sBB____9a__length ; __sBB__len_y = __sBB____Ab__length ; __sBB__total_len = __sBB__len_x + __sBB__len_y ; __sBB__first = __sBB____9a__length ? __sBB____9a__first : __sBB____Ab__first ; 
 __sBB____Bb = 1 ;
 __sBB____Cb__z = __sBB__total_len + __sBB____Bb ; 
 __sBB____Cb____end :
 __sBB____Db = 0 ;
 __sBB____Fb____iQ = __oBB__acquired ;
 __sBB____Fb____jQ__z =(! __sBB____Fb____iQ ); 
 __sBB____Fb____jQ____end :
 if(! __sBB____Fb____jQ__z )goto __sBB____Fb____hQ__fi ;
 __sBB____Fb____kQ = "Did not initialize Dynamic" ;
 goto __sBB____Fb____lQ____oD ;
 __builtin_unreachable();
 __sBB____Fb____hQ__fi :
 __sBB____Fb__next_size = __oBB__size +1; __sBB____Fb__success = true ; __sBB____Fb__self__allocated__prev = __oBB__allocated ; if ( __sBB____Fb__next_size >= __oBB__allocated ) { __oBB__allocated = __oBB__allocated + __oBB__allocated /2+1; __sBB____Fb__next_acquired =( ptr )((( ptr **) __oBB__acquired )[0]? __runtime_realloc ((( ptr **) __oBB__acquired )[0], __oBB__allocated * sizeof ( ptr ), __sBB____Fb__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __oBB__allocated * sizeof ( ptr ))); if ( __sBB____Fb__success = __sBB____Fb__next_acquired )(( ptr **) __oBB__acquired )[0]=( ptr *) __sBB____Fb__next_acquired ; } if ( __sBB____Fb__success ) { __sBB____Fb__mem =( ptr ) __runtime_alloc ( __sBB____Cb__z * sizeof ( __sBB____Fb____gQ )); if ( __sBB____Fb__success = __sBB____Fb__mem ) {(( ptr **) __oBB__acquired )[0][ __oBB__size ]= __sBB____Fb__mem ; __oBB__size = __sBB____Fb__next_size ; } } 
 __sBB____Fb____nQ__x = __sBB____Fb__success ;
 __sBB____Fb____nQ__z =(! __sBB____Fb____nQ__x ); 
 __sBB____Fb____nQ____end :
 if(! __sBB____Fb____nQ__z )goto __sBB____Fb____mQ__fi ;
 __sBB____Fb____oQ = "Failed a Dynamic allocation" ;
 goto __sBB____Fb____pQ____oD ;
 __builtin_unreachable();
 __sBB____Fb____mQ__fi :
 __sBB____Fb____uQ = 0 ;
 __sBB____Fb____wQ__bytesize = sizeof ( __sBB____Fb____wQ____CF )* __sBB____Cb__z ; 
 __sBB____Fb____wQ____end :
 memcpy (( char *) __sBB____Fb__mem ,( char *) __sBB____9a____m__contents , __sBB__len_x ); memcpy (( char *) __sBB____Fb__mem + __sBB__len_x ,( char *) __sBB____Ab____m__contents , __sBB__len_y );(( char *) __sBB____Fb__mem )[ __sBB__total_len ]=0; 
 __sBB____Ib__contents = __sBB____Fb__mem ;
 __oBB____TQ = __sBB____Fb__self____TQ ;
 __oBB__acquired = __oBB__acquired ;
 __oBB__size = __oBB__size ;
 __oBB__allocated = __oBB__allocated ;
 __oBB____dynamic_entry = __oBB____dynamic_entry ;
 __tBB__len_x = name__length ; __tBB__len_y = __sBB__total_len ; __tBB__total_len = __tBB__len_x + __tBB__len_y ; __tBB__first = name__length ? name__first : __sBB__first ; 
 __tBB____Dk = 1 ;
 __tBB____Ek__z = __tBB__total_len + __tBB____Dk ; 
 __tBB____Ek____end :
 __tBB____Fk = 0 ;
 __tBB____Hk____iQ = __oBB__acquired ;
 __tBB____Hk____jQ__z =(! __tBB____Hk____iQ ); 
 __tBB____Hk____jQ____end :
 if(! __tBB____Hk____jQ__z )goto __tBB____Hk____hQ__fi ;
 __tBB____Hk____kQ = "Did not initialize Dynamic" ;
 goto __tBB____Hk____lQ____oD ;
 __builtin_unreachable();
 __tBB____Hk____hQ__fi :
 __tBB____Hk__next_size = __oBB__size +1; __tBB____Hk__success = true ; __tBB____Hk__self__allocated__prev = __oBB__allocated ; if ( __tBB____Hk__next_size >= __oBB__allocated ) { __oBB__allocated = __oBB__allocated + __oBB__allocated /2+1; __tBB____Hk__next_acquired =( ptr )((( ptr **) __oBB__acquired )[0]? __runtime_realloc ((( ptr **) __oBB__acquired )[0], __oBB__allocated * sizeof ( ptr ), __tBB____Hk__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __oBB__allocated * sizeof ( ptr ))); if ( __tBB____Hk__success = __tBB____Hk__next_acquired )(( ptr **) __oBB__acquired )[0]=( ptr *) __tBB____Hk__next_acquired ; } if ( __tBB____Hk__success ) { __tBB____Hk__mem =( ptr ) __runtime_alloc ( __tBB____Ek__z * sizeof ( __tBB____Hk____gQ )); if ( __tBB____Hk__success = __tBB____Hk__mem ) {(( ptr **) __oBB__acquired )[0][ __oBB__size ]= __tBB____Hk__mem ; __oBB__size = __tBB____Hk__next_size ; } } 
 __tBB____Hk____nQ__x = __tBB____Hk__success ;
 __tBB____Hk____nQ__z =(! __tBB____Hk____nQ__x ); 
 __tBB____Hk____nQ____end :
 if(! __tBB____Hk____nQ__z )goto __tBB____Hk____mQ__fi ;
 __tBB____Hk____oQ = "Failed a Dynamic allocation" ;
 goto __tBB____Hk____pQ____oD ;
 __builtin_unreachable();
 __tBB____Hk____mQ__fi :
 __tBB____Hk____uQ = 0 ;
 __tBB____Hk____wQ__bytesize = sizeof ( __tBB____Hk____wQ____CF )* __tBB____Ek__z ; 
 __tBB____Hk____wQ____end :
 memcpy (( char *) __tBB____Hk__mem ,( char *) name__contents , __tBB__len_x ); memcpy (( char *) __tBB____Hk__mem + __tBB__len_x ,( char *) __sBB____Ib__contents , __tBB__len_y );(( char *) __tBB____Hk__mem )[ __tBB__total_len ]=0; 
 __tBB____Kk__contents = __tBB____Hk__mem ;
 __oBB____TQ = __tBB____Hk__self____TQ ;
 __oBB__acquired = __oBB__acquired ;
 __oBB__size = __oBB__size ;
 __oBB__allocated = __oBB__allocated ;
 __oBB____dynamic_entry = __oBB____dynamic_entry ;
 __uBB____vh__length = strlen ( __qBB ); __uBB____vh__contents =( ptr ) __qBB ; __uBB____vh__first = __qBB [0]; __uBB____vh__noptr =( ptr ) __uBB____vh__noptr ; 
 __uBB____vh____m__contents = __uBB____vh__contents ;
 __uBB__len_x = __uBB____vh__length ; __uBB__len_y = __tBB__total_len ; __uBB__total_len = __uBB__len_x + __uBB__len_y ; __uBB__first = __uBB____vh__length ? __uBB____vh__first : __tBB__first ; 
 __uBB____xh = 1 ;
 __uBB____yh__z = __uBB__total_len + __uBB____xh ; 
 __uBB____yh____end :
 __uBB____zh = 0 ;
 __uBB____1h____iQ = __oBB__acquired ;
 __uBB____1h____jQ__z =(! __uBB____1h____iQ ); 
 __uBB____1h____jQ____end :
 if(! __uBB____1h____jQ__z )goto __uBB____1h____hQ__fi ;
 __uBB____1h____kQ = "Did not initialize Dynamic" ;
 goto __uBB____1h____lQ____oD ;
 __builtin_unreachable();
 __uBB____1h____hQ__fi :
 __uBB____1h__next_size = __oBB__size +1; __uBB____1h__success = true ; __uBB____1h__self__allocated__prev = __oBB__allocated ; if ( __uBB____1h__next_size >= __oBB__allocated ) { __oBB__allocated = __oBB__allocated + __oBB__allocated /2+1; __uBB____1h__next_acquired =( ptr )((( ptr **) __oBB__acquired )[0]? __runtime_realloc ((( ptr **) __oBB__acquired )[0], __oBB__allocated * sizeof ( ptr ), __uBB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __oBB__allocated * sizeof ( ptr ))); if ( __uBB____1h__success = __uBB____1h__next_acquired )(( ptr **) __oBB__acquired )[0]=( ptr *) __uBB____1h__next_acquired ; } if ( __uBB____1h__success ) { __uBB____1h__mem =( ptr ) __runtime_alloc ( __uBB____yh__z * sizeof ( __uBB____1h____gQ )); if ( __uBB____1h__success = __uBB____1h__mem ) {(( ptr **) __oBB__acquired )[0][ __oBB__size ]= __uBB____1h__mem ; __oBB__size = __uBB____1h__next_size ; } } 
 __uBB____1h____nQ__x = __uBB____1h__success ;
 __uBB____1h____nQ__z =(! __uBB____1h____nQ__x ); 
 __uBB____1h____nQ____end :
 if(! __uBB____1h____nQ__z )goto __uBB____1h____mQ__fi ;
 __uBB____1h____oQ = "Failed a Dynamic allocation" ;
 goto __uBB____1h____pQ____oD ;
 __builtin_unreachable();
 __uBB____1h____mQ__fi :
 __uBB____1h____uQ = 0 ;
 __uBB____1h____wQ__bytesize = sizeof ( __uBB____1h____wQ____CF )* __uBB____yh__z ; 
 __uBB____1h____wQ____end :
 memcpy (( char *) __uBB____1h__mem ,( char *) __uBB____vh____m__contents , __uBB__len_x ); memcpy (( char *) __uBB____1h__mem + __uBB__len_x ,( char *) __tBB____Kk__contents , __uBB__len_y );(( char *) __uBB____1h__mem )[ __uBB__total_len ]=0; 
 __uBB____4h__contents = __uBB____1h__mem ;
 __oBB____TQ = __uBB____1h__self____TQ ;
 __oBB__acquired = __oBB__acquired ;
 __oBB__size = __oBB__size ;
 __oBB__allocated = __oBB__allocated ;
 __oBB____dynamic_entry = __oBB____dynamic_entry ;
 __xBB____ZQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __xBB____ZQ__acquired )(( ptr **) __xBB____ZQ__acquired )[0]=0; 
 __xBB____ZQ____UQ = 0 ;
 __xBB____ZQ____VQ = 0 ;
 __xBB__acquired = __xBB____ZQ__acquired ;
 __xBB__size = __xBB____ZQ____UQ ;
 __xBB__allocated = __xBB____ZQ____VQ ;
 __xBB____dynamic_entry = __xBB____ZQ____dynamic_entry ;
 __0BB____state = (struct run__816__state*)__runtime_calloc(sizeof(struct run__816__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0BB____state ) ;
 __0BB____state -> command____c = command____c ;
 __0BB____state -> command__contents = __uBB____4h__contents ;
 __0BB____state -> command__length = __uBB__total_len ;
 __0BB____state -> command__first = __uBB__first ;
 __0BB____state -> command__memory = __oBB__acquired ;
 __0BB____task = __smolambda_add_task ( run__816 , __0BB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0BB____task ) ;
 if( __0BB__err ) goto  __result_unhandled_error ;
 if( __0BB__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __0BB____task ) ;
 __0BB__err = __0BB____state -> err ;
 __2BB = __0BB__err ;
 if(! __2BB )goto __zBB__fi ;
 __3BB = "[ \033[31mERROR\033[0m ] " ;
 __4BB = ".s" ;
 __5BB____Qd__length = strlen ( __4BB ); __5BB____Qd__contents =( ptr ) __4BB ; __5BB____Qd__first = __4BB [0]; __5BB____Qd__noptr =( ptr ) __5BB____Qd__noptr ; 
 __5BB____Qd____m__contents = __5BB____Qd__contents ;
 __5BB__len_x = name__length ; __5BB__len_y = __5BB____Qd__length ; __5BB__total_len = __5BB__len_x + __5BB__len_y ; __5BB__first = name__length ? name__first : __5BB____Qd__first ; 
 __5BB____Rd = 1 ;
 __5BB____Sd__z = __5BB__total_len + __5BB____Rd ; 
 __5BB____Sd____end :
 __5BB____Td = 0 ;
 __5BB____Vd____iQ = __xBB__acquired ;
 __5BB____Vd____jQ__z =(! __5BB____Vd____iQ ); 
 __5BB____Vd____jQ____end :
 if(! __5BB____Vd____jQ__z )goto __5BB____Vd____hQ__fi ;
 __5BB____Vd____kQ = "Did not initialize Dynamic" ;
 goto __5BB____Vd____lQ____oD ;
 __builtin_unreachable();
 __5BB____Vd____hQ__fi :
 __5BB____Vd__next_size = __xBB__size +1; __5BB____Vd__success = true ; __5BB____Vd__self__allocated__prev = __xBB__allocated ; if ( __5BB____Vd__next_size >= __xBB__allocated ) { __xBB__allocated = __xBB__allocated + __xBB__allocated /2+1; __5BB____Vd__next_acquired =( ptr )((( ptr **) __xBB__acquired )[0]? __runtime_realloc ((( ptr **) __xBB__acquired )[0], __xBB__allocated * sizeof ( ptr ), __5BB____Vd__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __xBB__allocated * sizeof ( ptr ))); if ( __5BB____Vd__success = __5BB____Vd__next_acquired )(( ptr **) __xBB__acquired )[0]=( ptr *) __5BB____Vd__next_acquired ; } if ( __5BB____Vd__success ) { __5BB____Vd__mem =( ptr ) __runtime_alloc ( __5BB____Sd__z * sizeof ( __5BB____Vd____gQ )); if ( __5BB____Vd__success = __5BB____Vd__mem ) {(( ptr **) __xBB__acquired )[0][ __xBB__size ]= __5BB____Vd__mem ; __xBB__size = __5BB____Vd__next_size ; } } 
 __5BB____Vd____nQ__x = __5BB____Vd__success ;
 __5BB____Vd____nQ__z =(! __5BB____Vd____nQ__x ); 
 __5BB____Vd____nQ____end :
 if(! __5BB____Vd____nQ__z )goto __5BB____Vd____mQ__fi ;
 __5BB____Vd____oQ = "Failed a Dynamic allocation" ;
 goto __5BB____Vd____pQ____oD ;
 __builtin_unreachable();
 __5BB____Vd____mQ__fi :
 __5BB____Vd____uQ = 0 ;
 __5BB____Vd____wQ__bytesize = sizeof ( __5BB____Vd____wQ____CF )* __5BB____Sd__z ; 
 __5BB____Vd____wQ____end :
 memcpy (( char *) __5BB____Vd__mem ,( char *) name__contents , __5BB__len_x ); memcpy (( char *) __5BB____Vd__mem + __5BB__len_x ,( char *) __5BB____Qd____m__contents , __5BB__len_y );(( char *) __5BB____Vd__mem )[ __5BB__total_len ]=0; 
 __5BB____Yd__contents = __5BB____Vd__mem ;
 __xBB____TQ = __5BB____Vd__self____TQ ;
 __xBB__acquired = __xBB__acquired ;
 __xBB__size = __xBB__size ;
 __xBB__allocated = __xBB__allocated ;
 __xBB____dynamic_entry = __xBB____dynamic_entry ;
 __6BB____vh__length = strlen ( __3BB ); __6BB____vh__contents =( ptr ) __3BB ; __6BB____vh__first = __3BB [0]; __6BB____vh__noptr =( ptr ) __6BB____vh__noptr ; 
 __6BB____vh____m__contents = __6BB____vh__contents ;
 __6BB__len_x = __6BB____vh__length ; __6BB__len_y = __5BB__total_len ; __6BB__total_len = __6BB__len_x + __6BB__len_y ; __6BB__first = __6BB____vh__length ? __6BB____vh__first : __5BB__first ; 
 __6BB____xh = 1 ;
 __6BB____yh__z = __6BB__total_len + __6BB____xh ; 
 __6BB____yh____end :
 __6BB____zh = 0 ;
 __6BB____1h____iQ = __xBB__acquired ;
 __6BB____1h____jQ__z =(! __6BB____1h____iQ ); 
 __6BB____1h____jQ____end :
 if(! __6BB____1h____jQ__z )goto __6BB____1h____hQ__fi ;
 __6BB____1h____kQ = "Did not initialize Dynamic" ;
 goto __6BB____1h____lQ____oD ;
 __builtin_unreachable();
 __6BB____1h____hQ__fi :
 __6BB____1h__next_size = __xBB__size +1; __6BB____1h__success = true ; __6BB____1h__self__allocated__prev = __xBB__allocated ; if ( __6BB____1h__next_size >= __xBB__allocated ) { __xBB__allocated = __xBB__allocated + __xBB__allocated /2+1; __6BB____1h__next_acquired =( ptr )((( ptr **) __xBB__acquired )[0]? __runtime_realloc ((( ptr **) __xBB__acquired )[0], __xBB__allocated * sizeof ( ptr ), __6BB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __xBB__allocated * sizeof ( ptr ))); if ( __6BB____1h__success = __6BB____1h__next_acquired )(( ptr **) __xBB__acquired )[0]=( ptr *) __6BB____1h__next_acquired ; } if ( __6BB____1h__success ) { __6BB____1h__mem =( ptr ) __runtime_alloc ( __6BB____yh__z * sizeof ( __6BB____1h____gQ )); if ( __6BB____1h__success = __6BB____1h__mem ) {(( ptr **) __xBB__acquired )[0][ __xBB__size ]= __6BB____1h__mem ; __xBB__size = __6BB____1h__next_size ; } } 
 __6BB____1h____nQ__x = __6BB____1h__success ;
 __6BB____1h____nQ__z =(! __6BB____1h____nQ__x ); 
 __6BB____1h____nQ____end :
 if(! __6BB____1h____nQ__z )goto __6BB____1h____mQ__fi ;
 __6BB____1h____oQ = "Failed a Dynamic allocation" ;
 goto __6BB____1h____pQ____oD ;
 __builtin_unreachable();
 __6BB____1h____mQ__fi :
 __6BB____1h____uQ = 0 ;
 __6BB____1h____wQ__bytesize = sizeof ( __6BB____1h____wQ____CF )* __6BB____yh__z ; 
 __6BB____1h____wQ____end :
 memcpy (( char *) __6BB____1h__mem ,( char *) __6BB____vh____m__contents , __6BB__len_x ); memcpy (( char *) __6BB____1h__mem + __6BB__len_x ,( char *) __5BB____Yd__contents , __6BB__len_y );(( char *) __6BB____1h__mem )[ __6BB__total_len ]=0; 
 __6BB____4h__contents = __6BB____1h__mem ;
 __xBB____TQ = __6BB____1h__self____TQ ;
 __xBB__acquired = __xBB__acquired ;
 __xBB__size = __xBB__size ;
 __xBB__allocated = __xBB__allocated ;
 __xBB____dynamic_entry = __xBB____dynamic_entry ;
 printf ( "%s\n" ,( char *) __6BB____4h__contents ); 
 __7BB____end :
 goto __zBB__el ;
 __zBB__fi :
 __8BB = "[ \033[32mOK\033[0m ] " ;
 __9BB = ".s" ;
 __ACB____Qd__length = strlen ( __9BB ); __ACB____Qd__contents =( ptr ) __9BB ; __ACB____Qd__first = __9BB [0]; __ACB____Qd__noptr =( ptr ) __ACB____Qd__noptr ; 
 __ACB____Qd____m__contents = __ACB____Qd__contents ;
 __ACB__len_x = name__length ; __ACB__len_y = __ACB____Qd__length ; __ACB__total_len = __ACB__len_x + __ACB__len_y ; __ACB__first = name__length ? name__first : __ACB____Qd__first ; 
 __ACB____Rd = 1 ;
 __ACB____Sd__z = __ACB__total_len + __ACB____Rd ; 
 __ACB____Sd____end :
 __ACB____Td = 0 ;
 __ACB____Vd____iQ = __xBB__acquired ;
 __ACB____Vd____jQ__z =(! __ACB____Vd____iQ ); 
 __ACB____Vd____jQ____end :
 if(! __ACB____Vd____jQ__z )goto __ACB____Vd____hQ__fi ;
 __ACB____Vd____kQ = "Did not initialize Dynamic" ;
 goto __ACB____Vd____lQ____oD ;
 __builtin_unreachable();
 __ACB____Vd____hQ__fi :
 __ACB____Vd__next_size = __xBB__size +1; __ACB____Vd__success = true ; __ACB____Vd__self__allocated__prev = __xBB__allocated ; if ( __ACB____Vd__next_size >= __xBB__allocated ) { __xBB__allocated = __xBB__allocated + __xBB__allocated /2+1; __ACB____Vd__next_acquired =( ptr )((( ptr **) __xBB__acquired )[0]? __runtime_realloc ((( ptr **) __xBB__acquired )[0], __xBB__allocated * sizeof ( ptr ), __ACB____Vd__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __xBB__allocated * sizeof ( ptr ))); if ( __ACB____Vd__success = __ACB____Vd__next_acquired )(( ptr **) __xBB__acquired )[0]=( ptr *) __ACB____Vd__next_acquired ; } if ( __ACB____Vd__success ) { __ACB____Vd__mem =( ptr ) __runtime_alloc ( __ACB____Sd__z * sizeof ( __ACB____Vd____gQ )); if ( __ACB____Vd__success = __ACB____Vd__mem ) {(( ptr **) __xBB__acquired )[0][ __xBB__size ]= __ACB____Vd__mem ; __xBB__size = __ACB____Vd__next_size ; } } 
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
 __xBB____TQ = __ACB____Vd__self____TQ ;
 __xBB__acquired = __xBB__acquired ;
 __xBB__size = __xBB__size ;
 __xBB__allocated = __xBB__allocated ;
 __xBB____dynamic_entry = __xBB____dynamic_entry ;
 __BCB____vh__length = strlen ( __8BB ); __BCB____vh__contents =( ptr ) __8BB ; __BCB____vh__first = __8BB [0]; __BCB____vh__noptr =( ptr ) __BCB____vh__noptr ; 
 __BCB____vh____m__contents = __BCB____vh__contents ;
 __BCB__len_x = __BCB____vh__length ; __BCB__len_y = __ACB__total_len ; __BCB__total_len = __BCB__len_x + __BCB__len_y ; __BCB__first = __BCB____vh__length ? __BCB____vh__first : __ACB__first ; 
 __BCB____xh = 1 ;
 __BCB____yh__z = __BCB__total_len + __BCB____xh ; 
 __BCB____yh____end :
 __BCB____zh = 0 ;
 __BCB____1h____iQ = __xBB__acquired ;
 __BCB____1h____jQ__z =(! __BCB____1h____iQ ); 
 __BCB____1h____jQ____end :
 if(! __BCB____1h____jQ__z )goto __BCB____1h____hQ__fi ;
 __BCB____1h____kQ = "Did not initialize Dynamic" ;
 goto __BCB____1h____lQ____oD ;
 __builtin_unreachable();
 __BCB____1h____hQ__fi :
 __BCB____1h__next_size = __xBB__size +1; __BCB____1h__success = true ; __BCB____1h__self__allocated__prev = __xBB__allocated ; if ( __BCB____1h__next_size >= __xBB__allocated ) { __xBB__allocated = __xBB__allocated + __xBB__allocated /2+1; __BCB____1h__next_acquired =( ptr )((( ptr **) __xBB__acquired )[0]? __runtime_realloc ((( ptr **) __xBB__acquired )[0], __xBB__allocated * sizeof ( ptr ), __BCB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __xBB__allocated * sizeof ( ptr ))); if ( __BCB____1h__success = __BCB____1h__next_acquired )(( ptr **) __xBB__acquired )[0]=( ptr *) __BCB____1h__next_acquired ; } if ( __BCB____1h__success ) { __BCB____1h__mem =( ptr ) __runtime_alloc ( __BCB____yh__z * sizeof ( __BCB____1h____gQ )); if ( __BCB____1h__success = __BCB____1h__mem ) {(( ptr **) __xBB__acquired )[0][ __xBB__size ]= __BCB____1h__mem ; __xBB__size = __BCB____1h__next_size ; } } 
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
 __xBB____TQ = __BCB____1h__self____TQ ;
 __xBB__acquired = __xBB__acquired ;
 __xBB__size = __xBB__size ;
 __xBB__allocated = __xBB__allocated ;
 __xBB____dynamic_entry = __xBB____dynamic_entry ;
 printf ( "%s\n" ,( char *) __BCB____4h__contents ); 
 __CCB____end :
 __zBB__el :
 __end :
goto __return;

// ERROR HANDLING
__6BB____1h____lQ____oD :
 printf ( "%s\n" , __6BB____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__5BB____Vd____pQ____oD :
 printf ( "%s\n" , __5BB____Vd____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__ACB____Vd____pQ____oD :
 printf ( "%s\n" , __ACB____Vd____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__6BB____1h____pQ____oD :
 printf ( "%s\n" , __6BB____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__ACB____Vd____lQ____oD :
 printf ( "%s\n" , __ACB____Vd____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__5BB____Vd____lQ____oD :
 printf ( "%s\n" , __5BB____Vd____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__BCB____1h____pQ____oD :
 printf ( "%s\n" , __BCB____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__sBB____Fb____lQ____oD :
 printf ( "%s\n" , __sBB____Fb____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__1BB :
printf("Runtime error from run __0BB \n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
__BCB____1h____lQ____oD :
 printf ( "%s\n" , __BCB____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__tBB____Hk____lQ____oD :
 printf ( "%s\n" , __tBB____Hk____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__sBB____Fb____pQ____oD :
 printf ( "%s\n" , __sBB____Fb____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__tBB____Hk____pQ____oD :
 printf ( "%s\n" , __tBB____Hk____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__uBB____1h____lQ____oD :
 printf ( "%s\n" , __uBB____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__uBB____1h____pQ____oD :
 printf ( "%s\n" , __uBB____1h____oQ ); 
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
if ( __xBB__acquired ) { for ( __xBB____dynamic_entry =0; __xBB____dynamic_entry < __xBB__size ;++ __xBB____dynamic_entry ) { __runtime_free ((( ptr **) __xBB__acquired )[0][ __xBB____dynamic_entry ]); } __runtime_free ( __xBB__acquired ); __xBB__acquired =0; __xBB__size =0; __xBB__allocated =0; } 
 if ( __xBB__acquired ) { for ( __xBB____ZQ____dynamic_entry =0; __xBB____ZQ____dynamic_entry < __xBB____ZQ____UQ ;++ __xBB____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __xBB__acquired )[0][ __xBB____ZQ____dynamic_entry ]); } __runtime_free ( __xBB__acquired ); __xBB__acquired =0; __xBB____ZQ____UQ =0; __xBB____ZQ____VQ =0; } 
if ( __oBB__acquired ) { for ( __oBB____dynamic_entry =0; __oBB____dynamic_entry < __oBB__size ;++ __oBB____dynamic_entry ) { __runtime_free ((( ptr **) __oBB__acquired )[0][ __oBB____dynamic_entry ]); } __runtime_free ( __oBB__acquired ); __oBB__acquired =0; __oBB__size =0; __oBB__allocated =0; } 
 if ( __oBB__acquired ) { for ( __oBB____ZQ____dynamic_entry =0; __oBB____ZQ____dynamic_entry < __oBB____ZQ____UQ ;++ __oBB____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __oBB__acquired )[0][ __oBB____ZQ____dynamic_entry ]); } __runtime_free ( __oBB__acquired ); __oBB__acquired =0; __oBB____ZQ____UQ =0; __oBB____ZQ____VQ =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}


void std_test__819(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__819__state *__state=(struct std_test__819__state*)__void__state;
struct run__816__state* __YBB____state = 0 ;
ptr name__contents= __state->name__contents;
u64 name__length= __state->name__length;
char name__first= __state->name__first;
ptr name__memory= __state->name__memory;
char __jBB____1h____wQ____CF=0;
bool __jBB____1h____nQ__z=0;
nominal __jBB____1h__self____TQ=0;
char __jBB____1h____gQ=0;
u64 __jBB____1h__self__allocated__prev=0;
cstr __jBB____1h____kQ=0;
bool __jBB____1h____jQ__z=0;
u64 __jBB____xh=0;
ptr __jBB____vh____m__contents=0;
ptr __jBB____vh__noptr=0;
ptr __jBB____vh__contents=0;
u64 __jBB____vh__length=0;
ptr __iBB____Qc__contents=0;
u64 __iBB____Nc____wQ__bytesize=0;
bool __iBB____Nc____nQ__x=0;
char __iBB____Nc____gQ=0;
ptr __iBB____Nc__mem=0;
ptr __iBB____Nc__next_acquired=0;
u64 __jBB__total_len=0;
cstr __iBB____Nc____kQ=0;
bool __iBB____Nc____iQ=0;
u64 __iBB____Kc__z=0;
u64 __iBB__total_len=0;
u64 __iBB__len_y=0;
ptr __iBB____Ic____m__contents=0;
ptr __iBB____Ic__noptr=0;
ptr __iBB____Ic__contents=0;
cstr __gBB=0;
nominal __eBB____1h__self____TQ=0;
ptr __eBB____4h__contents=0;
char __eBB____1h____uQ=0;
cstr __eBB____1h____oQ=0;
bool __eBB____1h____nQ__z=0;
bool __eBB____1h____nQ__x=0;
ptr __eBB____1h__next_acquired=0;
bool __eBB____1h__success=0;
cstr __eBB____1h____kQ=0;
bool __eBB____1h____jQ__z=0;
bool __eBB____1h____iQ=0;
char __eBB____zh=0;
u64 __eBB____xh=0;
u64 __eBB____1h____wQ__bytesize=0;
u64 __eBB__total_len=0;
u64 __eBB__len_y=0;
u64 __eBB__len_x=0;
ptr __eBB____vh__noptr=0;
char __eBB____vh__first=0;
u64 __eBB____vh__length=0;
nominal __dBB____Nc__self____TQ=0;
char __iBB____Nc____uQ=0;
ptr __dBB____Qc__contents=0;
char __dBB____Nc____wQ____CF=0;
u64 __dBB____Nc____wQ__bytesize=0;
cstr __dBB____Nc____oQ=0;
char __dBB____Nc____gQ=0;
ptr __dBB____Nc__mem=0;
ptr __dBB____Nc__next_acquired=0;
bool __dBB____Nc__success=0;
char __eBB____1h____gQ=0;
char __dBB__first=0;
u64 __dBB__len_y=0;
ptr __dBB____Ic____m__contents=0;
char __dBB____Ic__first=0;
u64 __dBB____Ic__length=0;
cstr __cBB=0;
cstr __bBB=0;
bool __aBB=0;
u64 __iBB____Jc=0;
ptr command__memory=0;
u64 __VBB____dynamic_entry=0;
cstr __dBB____Nc____kQ=0;
nominal __SBB____1h__self____TQ=0;
cstr __iBB____Nc____oQ=0;
ptr __SBB____4h__contents=0;
char __SBB____1h____wQ____CF=0;
u64 __SBB____1h____wQ__bytesize=0;
cstr __SBB____1h____oQ=0;
nominal command____c=0;
bool __SBB____1h____nQ__z=0;
char __SBB____1h____gQ=0;
ptr __SBB____1h__mem=0;
ptr __SBB____1h__next_acquired=0;
bool __SBB____1h__success=0;
u64 __SBB____1h__next_size=0;
cstr __SBB____1h____kQ=0;
u64 __jBB____yh__z=0;
bool __SBB____1h____jQ__z=0;
bool __SBB____1h____iQ=0;
ptr __eBB____vh____m__contents=0;
u64 __SBB____yh__z=0;
u64 __SBB__total_len=0;
u64 __iBB____Nc__next_size=0;
u64 __SBB__len_x=0;
ptr __SBB____vh__noptr=0;
char __SBB____vh__first=0;
ptr __SBB____vh__contents=0;
u64 __VBB__allocated=0;
nominal __RBB____9i__self____TQ=0;
ptr __RBB____Cj__contents=0;
u64 __RBB____9i____wQ__bytesize=0;
char __RBB____9i____uQ=0;
bool __iBB____Nc____jQ__z=0;
bool __RBB____9i____nQ__z=0;
bool __jBB____1h____nQ__x=0;
ptr __QBB____Fb__next_acquired=0;
ptr __QBB____Fb__mem=0;
bool __RBB____9i____nQ__x=0;
u64 __jBB__len_y=0;
u64 __eBB____yh__z=0;
u64 __dBB__total_len=0;
u64 __dBB____Kc__z=0;
char __RBB____9i____wQ____CF=0;
char __eBB____1h____wQ____CF=0;
cstr __jBB____1h____oQ=0;
nominal __iBB____Nc__self____TQ=0;
u64 __RBB____6i__z=0;
char __eBB__first=0;
u64 __iBB____Ic__length=0;
bool __iBB____Nc____nQ__z=0;
char __iBB____Lc=0;
ptr command__contents=0;
char __jBB__first=0;
u64 __jBB____1h__next_size=0;
ptr __QBB____Ab__noptr=0;
u64 __QBB____Fb__self__allocated__prev=0;
char __jBB____vh__first=0;
char __QBB____Fb____uQ=0;
bool __iBB____Nc__success=0;
u64 __dBB____Nc__next_size=0;
ptr __YBB____task=0;
u64 __SBB____1h__self__allocated__prev=0;
bool __dBB____Nc____iQ=0;
char command__first=0;
ptr __VBB____ZQ__acquired=0;
bool __dBB____Nc____jQ__z=0;
u64 __RBB__total_len=0;
nominal __QBB____Fb__self____TQ=0;
char __RBB____7i=0;
errcode __YBB__err=0;
char __SBB____1h____uQ=0;
u64 __eBB____1h__self__allocated__prev=0;
char __dBB____Nc____uQ=0;
nominal name____b=0;
u64 __QBB__total_len=0;
char __jBB____1h____uQ=0;
u64 __SBB__len_y=0;
char __iBB__first=0;
ptr __dBB____Ic__noptr=0;
bool __QBB____Fb____nQ__z=0;
u64 __VBB____ZQ____UQ=0;
u64 __QBB____Bb=0;
ptr __jBB____1h__mem=0;
u64 __VBB____ZQ____dynamic_entry=0;
char __SBB__first=0;
u64 __MBB__size=0;
cstr __QBB____Fb____oQ=0;
u64 __SBB____vh__length=0;
ptr __eBB____1h__mem=0;
bool __dBB____Nc____nQ__z=0;
char __SBB____zh=0;
bool __jBB____1h____iQ=0;
ptr __jBB____1h__next_acquired=0;
char __RBB____9i____gQ=0;
ptr __RBB____9i__next_acquired=0;
ptr __SBB____vh____m__contents=0;
ptr __RBB____9i__mem=0;
bool __jBB____1h__success=0;
u64 command__length=0;
char __iBB____Ic__first=0;
bool __RBB____9i____jQ__z=0;
bool __QBB____Fb____nQ__x=0;
u64 __iBB__len_x=0;
u64 __dBB____Nc__self__allocated__prev=0;
u64 __QBB____Ab__length=0;
u64 __jBB____1h____wQ__bytesize=0;
u64 __QBB____Cb__z=0;
bool __dBB____Nc____nQ__x=0;
bool __QBB____Fb__success=0;
ptr __VBB__acquired=0;
ptr __MBB__acquired=0;
u64 __iBB____Nc__self__allocated__prev=0;
ptr __dBB____Ic__contents=0;
cstr __JBB=0;
ptr __MBB____ZQ__acquired=0;
u64 __VBB__size=0;
u64 __QBB____Fb____wQ__bytesize=0;
u64 __MBB____ZQ____UQ=0;
u64 __MBB____ZQ____VQ=0;
u64 __MBB__allocated=0;
u64 __MBB____dynamic_entry=0;
cstr __hBB=0;
u64 __MBB____ZQ____dynamic_entry=0;
cstr __OBB=0;
cstr __RBB____9i____kQ=0;
u64 __QBB____9a__length=0;
bool __RBB____9i__success=0;
ptr __QBB____9a__contents=0;
ptr __jBB____4h__contents=0;
nominal __VBB____TQ=0;
char __QBB____9a__first=0;
u64 __dBB____Jc=0;
ptr __QBB____9a__noptr=0;
ptr __QBB____9a____m__contents=0;
ptr __QBB____Ab__contents=0;
char __QBB____Ab__first=0;
ptr __QBB____Ab____m__contents=0;
char __iBB____Nc____wQ____CF=0;
u64 __QBB__len_x=0;
u64 __RBB__len_y=0;
u64 __QBB__len_y=0;
bool __RBB____9i____iQ=0;
char __QBB____Fb____wQ____CF=0;
ptr __eBB____vh__contents=0;
char __QBB__first=0;
cstr __RBB____9i____oQ=0;
bool __QBB____Fb____jQ__z=0;
char __QBB____Db=0;
nominal __MBB____TQ=0;
bool __QBB____Fb____iQ=0;
u64 __RBB__len_x=0;
cstr __QBB____Fb____kQ=0;
u64 __jBB__len_x=0;
bool __SBB____1h____nQ__x=0;
u64 __QBB____Fb__next_size=0;
char __QBB____Fb____gQ=0;
u64 __VBB____ZQ____VQ=0;
cstr __PBB=0;
char __jBB____zh=0;
char __dBB____Lc=0;
ptr __QBB____Ib__contents=0;
u64 __eBB____1h__next_size=0;
u64 __SBB____xh=0;
char __RBB__first=0;
u64 __RBB____5i=0;
u64 __RBB____9i__next_size=0;
u64 __dBB__len_x=0;
u64 __RBB____9i__self__allocated__prev=0;

// IMPLEMENTATION
__JBB = " 2>&1" ;
 __MBB____ZQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __MBB____ZQ__acquired )(( ptr **) __MBB____ZQ__acquired )[0]=0; 
 __MBB____ZQ____UQ = 0 ;
 __MBB____ZQ____VQ = 0 ;
 __MBB__acquired = __MBB____ZQ__acquired ;
 __MBB__size = __MBB____ZQ____UQ ;
 __MBB__allocated = __MBB____ZQ____VQ ;
 __MBB____dynamic_entry = __MBB____ZQ____dynamic_entry ;
 __OBB = "./smol tests/unit/" ;
 __PBB = ".s --workers 1 --runtime eager" ;
 __QBB____9a__length = strlen ( __PBB ); __QBB____9a__contents =( ptr ) __PBB ; __QBB____9a__first = __PBB [0]; __QBB____9a__noptr =( ptr ) __QBB____9a__noptr ; 
 __QBB____9a____m__contents = __QBB____9a__contents ;
 __QBB____Ab__length = strlen ( __JBB ); __QBB____Ab__contents =( ptr ) __JBB ; __QBB____Ab__first = __JBB [0]; __QBB____Ab__noptr =( ptr ) __QBB____Ab__noptr ; 
 __QBB____Ab____m__contents = __QBB____Ab__contents ;
 __QBB__len_x = __QBB____9a__length ; __QBB__len_y = __QBB____Ab__length ; __QBB__total_len = __QBB__len_x + __QBB__len_y ; __QBB__first = __QBB____9a__length ? __QBB____9a__first : __QBB____Ab__first ; 
 __QBB____Bb = 1 ;
 __QBB____Cb__z = __QBB__total_len + __QBB____Bb ; 
 __QBB____Cb____end :
 __QBB____Db = 0 ;
 __QBB____Fb____iQ = __MBB__acquired ;
 __QBB____Fb____jQ__z =(! __QBB____Fb____iQ ); 
 __QBB____Fb____jQ____end :
 if(! __QBB____Fb____jQ__z )goto __QBB____Fb____hQ__fi ;
 __QBB____Fb____kQ = "Did not initialize Dynamic" ;
 goto __QBB____Fb____lQ____oD ;
 __builtin_unreachable();
 __QBB____Fb____hQ__fi :
 __QBB____Fb__next_size = __MBB__size +1; __QBB____Fb__success = true ; __QBB____Fb__self__allocated__prev = __MBB__allocated ; if ( __QBB____Fb__next_size >= __MBB__allocated ) { __MBB__allocated = __MBB__allocated + __MBB__allocated /2+1; __QBB____Fb__next_acquired =( ptr )((( ptr **) __MBB__acquired )[0]? __runtime_realloc ((( ptr **) __MBB__acquired )[0], __MBB__allocated * sizeof ( ptr ), __QBB____Fb__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __MBB__allocated * sizeof ( ptr ))); if ( __QBB____Fb__success = __QBB____Fb__next_acquired )(( ptr **) __MBB__acquired )[0]=( ptr *) __QBB____Fb__next_acquired ; } if ( __QBB____Fb__success ) { __QBB____Fb__mem =( ptr ) __runtime_alloc ( __QBB____Cb__z * sizeof ( __QBB____Fb____gQ )); if ( __QBB____Fb__success = __QBB____Fb__mem ) {(( ptr **) __MBB__acquired )[0][ __MBB__size ]= __QBB____Fb__mem ; __MBB__size = __QBB____Fb__next_size ; } } 
 __QBB____Fb____nQ__x = __QBB____Fb__success ;
 __QBB____Fb____nQ__z =(! __QBB____Fb____nQ__x ); 
 __QBB____Fb____nQ____end :
 if(! __QBB____Fb____nQ__z )goto __QBB____Fb____mQ__fi ;
 __QBB____Fb____oQ = "Failed a Dynamic allocation" ;
 goto __QBB____Fb____pQ____oD ;
 __builtin_unreachable();
 __QBB____Fb____mQ__fi :
 __QBB____Fb____uQ = 0 ;
 __QBB____Fb____wQ__bytesize = sizeof ( __QBB____Fb____wQ____CF )* __QBB____Cb__z ; 
 __QBB____Fb____wQ____end :
 memcpy (( char *) __QBB____Fb__mem ,( char *) __QBB____9a____m__contents , __QBB__len_x ); memcpy (( char *) __QBB____Fb__mem + __QBB__len_x ,( char *) __QBB____Ab____m__contents , __QBB__len_y );(( char *) __QBB____Fb__mem )[ __QBB__total_len ]=0; 
 __QBB____Ib__contents = __QBB____Fb__mem ;
 __MBB____TQ = __QBB____Fb__self____TQ ;
 __MBB__acquired = __MBB__acquired ;
 __MBB__size = __MBB__size ;
 __MBB__allocated = __MBB__allocated ;
 __MBB____dynamic_entry = __MBB____dynamic_entry ;
 __RBB__len_x = name__length ; __RBB__len_y = __QBB__total_len ; __RBB__total_len = __RBB__len_x + __RBB__len_y ; __RBB__first = name__length ? name__first : __QBB__first ; 
 __RBB____5i = 1 ;
 __RBB____6i__z = __RBB__total_len + __RBB____5i ; 
 __RBB____6i____end :
 __RBB____7i = 0 ;
 __RBB____9i____iQ = __MBB__acquired ;
 __RBB____9i____jQ__z =(! __RBB____9i____iQ ); 
 __RBB____9i____jQ____end :
 if(! __RBB____9i____jQ__z )goto __RBB____9i____hQ__fi ;
 __RBB____9i____kQ = "Did not initialize Dynamic" ;
 goto __RBB____9i____lQ____oD ;
 __builtin_unreachable();
 __RBB____9i____hQ__fi :
 __RBB____9i__next_size = __MBB__size +1; __RBB____9i__success = true ; __RBB____9i__self__allocated__prev = __MBB__allocated ; if ( __RBB____9i__next_size >= __MBB__allocated ) { __MBB__allocated = __MBB__allocated + __MBB__allocated /2+1; __RBB____9i__next_acquired =( ptr )((( ptr **) __MBB__acquired )[0]? __runtime_realloc ((( ptr **) __MBB__acquired )[0], __MBB__allocated * sizeof ( ptr ), __RBB____9i__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __MBB__allocated * sizeof ( ptr ))); if ( __RBB____9i__success = __RBB____9i__next_acquired )(( ptr **) __MBB__acquired )[0]=( ptr *) __RBB____9i__next_acquired ; } if ( __RBB____9i__success ) { __RBB____9i__mem =( ptr ) __runtime_alloc ( __RBB____6i__z * sizeof ( __RBB____9i____gQ )); if ( __RBB____9i__success = __RBB____9i__mem ) {(( ptr **) __MBB__acquired )[0][ __MBB__size ]= __RBB____9i__mem ; __MBB__size = __RBB____9i__next_size ; } } 
 __RBB____9i____nQ__x = __RBB____9i__success ;
 __RBB____9i____nQ__z =(! __RBB____9i____nQ__x ); 
 __RBB____9i____nQ____end :
 if(! __RBB____9i____nQ__z )goto __RBB____9i____mQ__fi ;
 __RBB____9i____oQ = "Failed a Dynamic allocation" ;
 goto __RBB____9i____pQ____oD ;
 __builtin_unreachable();
 __RBB____9i____mQ__fi :
 __RBB____9i____uQ = 0 ;
 __RBB____9i____wQ__bytesize = sizeof ( __RBB____9i____wQ____CF )* __RBB____6i__z ; 
 __RBB____9i____wQ____end :
 memcpy (( char *) __RBB____9i__mem ,( char *) name__contents , __RBB__len_x ); memcpy (( char *) __RBB____9i__mem + __RBB__len_x ,( char *) __QBB____Ib__contents , __RBB__len_y );(( char *) __RBB____9i__mem )[ __RBB__total_len ]=0; 
 __RBB____Cj__contents = __RBB____9i__mem ;
 __MBB____TQ = __RBB____9i__self____TQ ;
 __MBB__acquired = __MBB__acquired ;
 __MBB__size = __MBB__size ;
 __MBB__allocated = __MBB__allocated ;
 __MBB____dynamic_entry = __MBB____dynamic_entry ;
 __SBB____vh__length = strlen ( __OBB ); __SBB____vh__contents =( ptr ) __OBB ; __SBB____vh__first = __OBB [0]; __SBB____vh__noptr =( ptr ) __SBB____vh__noptr ; 
 __SBB____vh____m__contents = __SBB____vh__contents ;
 __SBB__len_x = __SBB____vh__length ; __SBB__len_y = __RBB__total_len ; __SBB__total_len = __SBB__len_x + __SBB__len_y ; __SBB__first = __SBB____vh__length ? __SBB____vh__first : __RBB__first ; 
 __SBB____xh = 1 ;
 __SBB____yh__z = __SBB__total_len + __SBB____xh ; 
 __SBB____yh____end :
 __SBB____zh = 0 ;
 __SBB____1h____iQ = __MBB__acquired ;
 __SBB____1h____jQ__z =(! __SBB____1h____iQ ); 
 __SBB____1h____jQ____end :
 if(! __SBB____1h____jQ__z )goto __SBB____1h____hQ__fi ;
 __SBB____1h____kQ = "Did not initialize Dynamic" ;
 goto __SBB____1h____lQ____oD ;
 __builtin_unreachable();
 __SBB____1h____hQ__fi :
 __SBB____1h__next_size = __MBB__size +1; __SBB____1h__success = true ; __SBB____1h__self__allocated__prev = __MBB__allocated ; if ( __SBB____1h__next_size >= __MBB__allocated ) { __MBB__allocated = __MBB__allocated + __MBB__allocated /2+1; __SBB____1h__next_acquired =( ptr )((( ptr **) __MBB__acquired )[0]? __runtime_realloc ((( ptr **) __MBB__acquired )[0], __MBB__allocated * sizeof ( ptr ), __SBB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __MBB__allocated * sizeof ( ptr ))); if ( __SBB____1h__success = __SBB____1h__next_acquired )(( ptr **) __MBB__acquired )[0]=( ptr *) __SBB____1h__next_acquired ; } if ( __SBB____1h__success ) { __SBB____1h__mem =( ptr ) __runtime_alloc ( __SBB____yh__z * sizeof ( __SBB____1h____gQ )); if ( __SBB____1h__success = __SBB____1h__mem ) {(( ptr **) __MBB__acquired )[0][ __MBB__size ]= __SBB____1h__mem ; __MBB__size = __SBB____1h__next_size ; } } 
 __SBB____1h____nQ__x = __SBB____1h__success ;
 __SBB____1h____nQ__z =(! __SBB____1h____nQ__x ); 
 __SBB____1h____nQ____end :
 if(! __SBB____1h____nQ__z )goto __SBB____1h____mQ__fi ;
 __SBB____1h____oQ = "Failed a Dynamic allocation" ;
 goto __SBB____1h____pQ____oD ;
 __builtin_unreachable();
 __SBB____1h____mQ__fi :
 __SBB____1h____uQ = 0 ;
 __SBB____1h____wQ__bytesize = sizeof ( __SBB____1h____wQ____CF )* __SBB____yh__z ; 
 __SBB____1h____wQ____end :
 memcpy (( char *) __SBB____1h__mem ,( char *) __SBB____vh____m__contents , __SBB__len_x ); memcpy (( char *) __SBB____1h__mem + __SBB__len_x ,( char *) __RBB____Cj__contents , __SBB__len_y );(( char *) __SBB____1h__mem )[ __SBB__total_len ]=0; 
 __SBB____4h__contents = __SBB____1h__mem ;
 __MBB____TQ = __SBB____1h__self____TQ ;
 __MBB__acquired = __MBB__acquired ;
 __MBB__size = __MBB__size ;
 __MBB__allocated = __MBB__allocated ;
 __MBB____dynamic_entry = __MBB____dynamic_entry ;
 __VBB____ZQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __VBB____ZQ__acquired )(( ptr **) __VBB____ZQ__acquired )[0]=0; 
 __VBB____ZQ____UQ = 0 ;
 __VBB____ZQ____VQ = 0 ;
 __VBB__acquired = __VBB____ZQ__acquired ;
 __VBB__size = __VBB____ZQ____UQ ;
 __VBB__allocated = __VBB____ZQ____VQ ;
 __VBB____dynamic_entry = __VBB____ZQ____dynamic_entry ;
 __YBB____state = (struct run__816__state*)__runtime_calloc(sizeof(struct run__816__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __YBB____state ) ;
 __YBB____state -> command____c = command____c ;
 __YBB____state -> command__contents = __SBB____4h__contents ;
 __YBB____state -> command__length = __SBB__total_len ;
 __YBB____state -> command__first = __SBB__first ;
 __YBB____state -> command__memory = __MBB__acquired ;
 __YBB____task = __smolambda_add_task ( run__816 , __YBB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __YBB____task ) ;
 if( __YBB__err ) goto  __result_unhandled_error ;
 if( __YBB__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __YBB____task ) ;
 __YBB__err = __YBB____state -> err ;
 __aBB = __YBB__err ;
 if(! __aBB )goto __XBB__fi ;
 __bBB = "[ \033[31mERROR\033[0m ] " ;
 __cBB = ".s" ;
 __dBB____Ic__length = strlen ( __cBB ); __dBB____Ic__contents =( ptr ) __cBB ; __dBB____Ic__first = __cBB [0]; __dBB____Ic__noptr =( ptr ) __dBB____Ic__noptr ; 
 __dBB____Ic____m__contents = __dBB____Ic__contents ;
 __dBB__len_x = name__length ; __dBB__len_y = __dBB____Ic__length ; __dBB__total_len = __dBB__len_x + __dBB__len_y ; __dBB__first = name__length ? name__first : __dBB____Ic__first ; 
 __dBB____Jc = 1 ;
 __dBB____Kc__z = __dBB__total_len + __dBB____Jc ; 
 __dBB____Kc____end :
 __dBB____Lc = 0 ;
 __dBB____Nc____iQ = __VBB__acquired ;
 __dBB____Nc____jQ__z =(! __dBB____Nc____iQ ); 
 __dBB____Nc____jQ____end :
 if(! __dBB____Nc____jQ__z )goto __dBB____Nc____hQ__fi ;
 __dBB____Nc____kQ = "Did not initialize Dynamic" ;
 goto __dBB____Nc____lQ____oD ;
 __builtin_unreachable();
 __dBB____Nc____hQ__fi :
 __dBB____Nc__next_size = __VBB__size +1; __dBB____Nc__success = true ; __dBB____Nc__self__allocated__prev = __VBB__allocated ; if ( __dBB____Nc__next_size >= __VBB__allocated ) { __VBB__allocated = __VBB__allocated + __VBB__allocated /2+1; __dBB____Nc__next_acquired =( ptr )((( ptr **) __VBB__acquired )[0]? __runtime_realloc ((( ptr **) __VBB__acquired )[0], __VBB__allocated * sizeof ( ptr ), __dBB____Nc__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __VBB__allocated * sizeof ( ptr ))); if ( __dBB____Nc__success = __dBB____Nc__next_acquired )(( ptr **) __VBB__acquired )[0]=( ptr *) __dBB____Nc__next_acquired ; } if ( __dBB____Nc__success ) { __dBB____Nc__mem =( ptr ) __runtime_alloc ( __dBB____Kc__z * sizeof ( __dBB____Nc____gQ )); if ( __dBB____Nc__success = __dBB____Nc__mem ) {(( ptr **) __VBB__acquired )[0][ __VBB__size ]= __dBB____Nc__mem ; __VBB__size = __dBB____Nc__next_size ; } } 
 __dBB____Nc____nQ__x = __dBB____Nc__success ;
 __dBB____Nc____nQ__z =(! __dBB____Nc____nQ__x ); 
 __dBB____Nc____nQ____end :
 if(! __dBB____Nc____nQ__z )goto __dBB____Nc____mQ__fi ;
 __dBB____Nc____oQ = "Failed a Dynamic allocation" ;
 goto __dBB____Nc____pQ____oD ;
 __builtin_unreachable();
 __dBB____Nc____mQ__fi :
 __dBB____Nc____uQ = 0 ;
 __dBB____Nc____wQ__bytesize = sizeof ( __dBB____Nc____wQ____CF )* __dBB____Kc__z ; 
 __dBB____Nc____wQ____end :
 memcpy (( char *) __dBB____Nc__mem ,( char *) name__contents , __dBB__len_x ); memcpy (( char *) __dBB____Nc__mem + __dBB__len_x ,( char *) __dBB____Ic____m__contents , __dBB__len_y );(( char *) __dBB____Nc__mem )[ __dBB__total_len ]=0; 
 __dBB____Qc__contents = __dBB____Nc__mem ;
 __VBB____TQ = __dBB____Nc__self____TQ ;
 __VBB__acquired = __VBB__acquired ;
 __VBB__size = __VBB__size ;
 __VBB__allocated = __VBB__allocated ;
 __VBB____dynamic_entry = __VBB____dynamic_entry ;
 __eBB____vh__length = strlen ( __bBB ); __eBB____vh__contents =( ptr ) __bBB ; __eBB____vh__first = __bBB [0]; __eBB____vh__noptr =( ptr ) __eBB____vh__noptr ; 
 __eBB____vh____m__contents = __eBB____vh__contents ;
 __eBB__len_x = __eBB____vh__length ; __eBB__len_y = __dBB__total_len ; __eBB__total_len = __eBB__len_x + __eBB__len_y ; __eBB__first = __eBB____vh__length ? __eBB____vh__first : __dBB__first ; 
 __eBB____xh = 1 ;
 __eBB____yh__z = __eBB__total_len + __eBB____xh ; 
 __eBB____yh____end :
 __eBB____zh = 0 ;
 __eBB____1h____iQ = __VBB__acquired ;
 __eBB____1h____jQ__z =(! __eBB____1h____iQ ); 
 __eBB____1h____jQ____end :
 if(! __eBB____1h____jQ__z )goto __eBB____1h____hQ__fi ;
 __eBB____1h____kQ = "Did not initialize Dynamic" ;
 goto __eBB____1h____lQ____oD ;
 __builtin_unreachable();
 __eBB____1h____hQ__fi :
 __eBB____1h__next_size = __VBB__size +1; __eBB____1h__success = true ; __eBB____1h__self__allocated__prev = __VBB__allocated ; if ( __eBB____1h__next_size >= __VBB__allocated ) { __VBB__allocated = __VBB__allocated + __VBB__allocated /2+1; __eBB____1h__next_acquired =( ptr )((( ptr **) __VBB__acquired )[0]? __runtime_realloc ((( ptr **) __VBB__acquired )[0], __VBB__allocated * sizeof ( ptr ), __eBB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __VBB__allocated * sizeof ( ptr ))); if ( __eBB____1h__success = __eBB____1h__next_acquired )(( ptr **) __VBB__acquired )[0]=( ptr *) __eBB____1h__next_acquired ; } if ( __eBB____1h__success ) { __eBB____1h__mem =( ptr ) __runtime_alloc ( __eBB____yh__z * sizeof ( __eBB____1h____gQ )); if ( __eBB____1h__success = __eBB____1h__mem ) {(( ptr **) __VBB__acquired )[0][ __VBB__size ]= __eBB____1h__mem ; __VBB__size = __eBB____1h__next_size ; } } 
 __eBB____1h____nQ__x = __eBB____1h__success ;
 __eBB____1h____nQ__z =(! __eBB____1h____nQ__x ); 
 __eBB____1h____nQ____end :
 if(! __eBB____1h____nQ__z )goto __eBB____1h____mQ__fi ;
 __eBB____1h____oQ = "Failed a Dynamic allocation" ;
 goto __eBB____1h____pQ____oD ;
 __builtin_unreachable();
 __eBB____1h____mQ__fi :
 __eBB____1h____uQ = 0 ;
 __eBB____1h____wQ__bytesize = sizeof ( __eBB____1h____wQ____CF )* __eBB____yh__z ; 
 __eBB____1h____wQ____end :
 memcpy (( char *) __eBB____1h__mem ,( char *) __eBB____vh____m__contents , __eBB__len_x ); memcpy (( char *) __eBB____1h__mem + __eBB__len_x ,( char *) __dBB____Qc__contents , __eBB__len_y );(( char *) __eBB____1h__mem )[ __eBB__total_len ]=0; 
 __eBB____4h__contents = __eBB____1h__mem ;
 __VBB____TQ = __eBB____1h__self____TQ ;
 __VBB__acquired = __VBB__acquired ;
 __VBB__size = __VBB__size ;
 __VBB__allocated = __VBB__allocated ;
 __VBB____dynamic_entry = __VBB____dynamic_entry ;
 printf ( "%s\n" ,( char *) __eBB____4h__contents ); 
 __fBB____end :
 goto __XBB__el ;
 __XBB__fi :
 __gBB = "[ \033[32mOK\033[0m ] " ;
 __hBB = ".s" ;
 __iBB____Ic__length = strlen ( __hBB ); __iBB____Ic__contents =( ptr ) __hBB ; __iBB____Ic__first = __hBB [0]; __iBB____Ic__noptr =( ptr ) __iBB____Ic__noptr ; 
 __iBB____Ic____m__contents = __iBB____Ic__contents ;
 __iBB__len_x = name__length ; __iBB__len_y = __iBB____Ic__length ; __iBB__total_len = __iBB__len_x + __iBB__len_y ; __iBB__first = name__length ? name__first : __iBB____Ic__first ; 
 __iBB____Jc = 1 ;
 __iBB____Kc__z = __iBB__total_len + __iBB____Jc ; 
 __iBB____Kc____end :
 __iBB____Lc = 0 ;
 __iBB____Nc____iQ = __VBB__acquired ;
 __iBB____Nc____jQ__z =(! __iBB____Nc____iQ ); 
 __iBB____Nc____jQ____end :
 if(! __iBB____Nc____jQ__z )goto __iBB____Nc____hQ__fi ;
 __iBB____Nc____kQ = "Did not initialize Dynamic" ;
 goto __iBB____Nc____lQ____oD ;
 __builtin_unreachable();
 __iBB____Nc____hQ__fi :
 __iBB____Nc__next_size = __VBB__size +1; __iBB____Nc__success = true ; __iBB____Nc__self__allocated__prev = __VBB__allocated ; if ( __iBB____Nc__next_size >= __VBB__allocated ) { __VBB__allocated = __VBB__allocated + __VBB__allocated /2+1; __iBB____Nc__next_acquired =( ptr )((( ptr **) __VBB__acquired )[0]? __runtime_realloc ((( ptr **) __VBB__acquired )[0], __VBB__allocated * sizeof ( ptr ), __iBB____Nc__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __VBB__allocated * sizeof ( ptr ))); if ( __iBB____Nc__success = __iBB____Nc__next_acquired )(( ptr **) __VBB__acquired )[0]=( ptr *) __iBB____Nc__next_acquired ; } if ( __iBB____Nc__success ) { __iBB____Nc__mem =( ptr ) __runtime_alloc ( __iBB____Kc__z * sizeof ( __iBB____Nc____gQ )); if ( __iBB____Nc__success = __iBB____Nc__mem ) {(( ptr **) __VBB__acquired )[0][ __VBB__size ]= __iBB____Nc__mem ; __VBB__size = __iBB____Nc__next_size ; } } 
 __iBB____Nc____nQ__x = __iBB____Nc__success ;
 __iBB____Nc____nQ__z =(! __iBB____Nc____nQ__x ); 
 __iBB____Nc____nQ____end :
 if(! __iBB____Nc____nQ__z )goto __iBB____Nc____mQ__fi ;
 __iBB____Nc____oQ = "Failed a Dynamic allocation" ;
 goto __iBB____Nc____pQ____oD ;
 __builtin_unreachable();
 __iBB____Nc____mQ__fi :
 __iBB____Nc____uQ = 0 ;
 __iBB____Nc____wQ__bytesize = sizeof ( __iBB____Nc____wQ____CF )* __iBB____Kc__z ; 
 __iBB____Nc____wQ____end :
 memcpy (( char *) __iBB____Nc__mem ,( char *) name__contents , __iBB__len_x ); memcpy (( char *) __iBB____Nc__mem + __iBB__len_x ,( char *) __iBB____Ic____m__contents , __iBB__len_y );(( char *) __iBB____Nc__mem )[ __iBB__total_len ]=0; 
 __iBB____Qc__contents = __iBB____Nc__mem ;
 __VBB____TQ = __iBB____Nc__self____TQ ;
 __VBB__acquired = __VBB__acquired ;
 __VBB__size = __VBB__size ;
 __VBB__allocated = __VBB__allocated ;
 __VBB____dynamic_entry = __VBB____dynamic_entry ;
 __jBB____vh__length = strlen ( __gBB ); __jBB____vh__contents =( ptr ) __gBB ; __jBB____vh__first = __gBB [0]; __jBB____vh__noptr =( ptr ) __jBB____vh__noptr ; 
 __jBB____vh____m__contents = __jBB____vh__contents ;
 __jBB__len_x = __jBB____vh__length ; __jBB__len_y = __iBB__total_len ; __jBB__total_len = __jBB__len_x + __jBB__len_y ; __jBB__first = __jBB____vh__length ? __jBB____vh__first : __iBB__first ; 
 __jBB____xh = 1 ;
 __jBB____yh__z = __jBB__total_len + __jBB____xh ; 
 __jBB____yh____end :
 __jBB____zh = 0 ;
 __jBB____1h____iQ = __VBB__acquired ;
 __jBB____1h____jQ__z =(! __jBB____1h____iQ ); 
 __jBB____1h____jQ____end :
 if(! __jBB____1h____jQ__z )goto __jBB____1h____hQ__fi ;
 __jBB____1h____kQ = "Did not initialize Dynamic" ;
 goto __jBB____1h____lQ____oD ;
 __builtin_unreachable();
 __jBB____1h____hQ__fi :
 __jBB____1h__next_size = __VBB__size +1; __jBB____1h__success = true ; __jBB____1h__self__allocated__prev = __VBB__allocated ; if ( __jBB____1h__next_size >= __VBB__allocated ) { __VBB__allocated = __VBB__allocated + __VBB__allocated /2+1; __jBB____1h__next_acquired =( ptr )((( ptr **) __VBB__acquired )[0]? __runtime_realloc ((( ptr **) __VBB__acquired )[0], __VBB__allocated * sizeof ( ptr ), __jBB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __VBB__allocated * sizeof ( ptr ))); if ( __jBB____1h__success = __jBB____1h__next_acquired )(( ptr **) __VBB__acquired )[0]=( ptr *) __jBB____1h__next_acquired ; } if ( __jBB____1h__success ) { __jBB____1h__mem =( ptr ) __runtime_alloc ( __jBB____yh__z * sizeof ( __jBB____1h____gQ )); if ( __jBB____1h__success = __jBB____1h__mem ) {(( ptr **) __VBB__acquired )[0][ __VBB__size ]= __jBB____1h__mem ; __VBB__size = __jBB____1h__next_size ; } } 
 __jBB____1h____nQ__x = __jBB____1h__success ;
 __jBB____1h____nQ__z =(! __jBB____1h____nQ__x ); 
 __jBB____1h____nQ____end :
 if(! __jBB____1h____nQ__z )goto __jBB____1h____mQ__fi ;
 __jBB____1h____oQ = "Failed a Dynamic allocation" ;
 goto __jBB____1h____pQ____oD ;
 __builtin_unreachable();
 __jBB____1h____mQ__fi :
 __jBB____1h____uQ = 0 ;
 __jBB____1h____wQ__bytesize = sizeof ( __jBB____1h____wQ____CF )* __jBB____yh__z ; 
 __jBB____1h____wQ____end :
 memcpy (( char *) __jBB____1h__mem ,( char *) __jBB____vh____m__contents , __jBB__len_x ); memcpy (( char *) __jBB____1h__mem + __jBB__len_x ,( char *) __iBB____Qc__contents , __jBB__len_y );(( char *) __jBB____1h__mem )[ __jBB__total_len ]=0; 
 __jBB____4h__contents = __jBB____1h__mem ;
 __VBB____TQ = __jBB____1h__self____TQ ;
 __VBB__acquired = __VBB__acquired ;
 __VBB__size = __VBB__size ;
 __VBB__allocated = __VBB__allocated ;
 __VBB____dynamic_entry = __VBB____dynamic_entry ;
 printf ( "%s\n" ,( char *) __jBB____4h__contents ); 
 __kBB____end :
 __XBB__el :
 __end :
goto __return;

// ERROR HANDLING
__dBB____Nc____lQ____oD :
 printf ( "%s\n" , __dBB____Nc____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__RBB____9i____pQ____oD :
 printf ( "%s\n" , __RBB____9i____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__ZBB :
printf("Runtime error from run __YBB \n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
__eBB____1h____pQ____oD :
 printf ( "%s\n" , __eBB____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__jBB____1h____pQ____oD :
 printf ( "%s\n" , __jBB____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__jBB____1h____lQ____oD :
 printf ( "%s\n" , __jBB____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__dBB____Nc____pQ____oD :
 printf ( "%s\n" , __dBB____Nc____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__QBB____Fb____lQ____oD :
 printf ( "%s\n" , __QBB____Fb____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__iBB____Nc____pQ____oD :
 printf ( "%s\n" , __iBB____Nc____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__QBB____Fb____pQ____oD :
 printf ( "%s\n" , __QBB____Fb____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__eBB____1h____lQ____oD :
 printf ( "%s\n" , __eBB____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__RBB____9i____lQ____oD :
 printf ( "%s\n" , __RBB____9i____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__iBB____Nc____lQ____oD :
 printf ( "%s\n" , __iBB____Nc____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__SBB____1h____lQ____oD :
 printf ( "%s\n" , __SBB____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__SBB____1h____pQ____oD :
 printf ( "%s\n" , __SBB____1h____oQ ); 
__result__errocode=__USER__ERROR;
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
if ( __VBB__acquired ) { for ( __VBB____dynamic_entry =0; __VBB____dynamic_entry < __VBB__size ;++ __VBB____dynamic_entry ) { __runtime_free ((( ptr **) __VBB__acquired )[0][ __VBB____dynamic_entry ]); } __runtime_free ( __VBB__acquired ); __VBB__acquired =0; __VBB__size =0; __VBB__allocated =0; } 
 if ( __VBB__acquired ) { for ( __VBB____ZQ____dynamic_entry =0; __VBB____ZQ____dynamic_entry < __VBB____ZQ____UQ ;++ __VBB____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __VBB__acquired )[0][ __VBB____ZQ____dynamic_entry ]); } __runtime_free ( __VBB__acquired ); __VBB__acquired =0; __VBB____ZQ____UQ =0; __VBB____ZQ____VQ =0; } 
if ( __MBB__acquired ) { for ( __MBB____dynamic_entry =0; __MBB____dynamic_entry < __MBB__size ;++ __MBB____dynamic_entry ) { __runtime_free ((( ptr **) __MBB__acquired )[0][ __MBB____dynamic_entry ]); } __runtime_free ( __MBB__acquired ); __MBB__acquired =0; __MBB__size =0; __MBB__allocated =0; } 
 if ( __MBB__acquired ) { for ( __MBB____ZQ____dynamic_entry =0; __MBB____ZQ____dynamic_entry < __MBB____ZQ____UQ ;++ __MBB____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __MBB__acquired )[0][ __MBB____ZQ____dynamic_entry ]); } __runtime_free ( __MBB__acquired ); __MBB__acquired =0; __MBB____ZQ____UQ =0; __MBB____ZQ____VQ =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}


void std_test__818(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__818__state *__state=(struct std_test__818__state*)__void__state;
struct run__816__state* __6AB____state = 0 ;
cstr name= __state->name;
nominal __HBB____1h__self____TQ=0;
u64 __HBB____1h____wQ__bytesize=0;
bool __HBB____1h____nQ__z=0;
bool __HBB____1h____nQ__x=0;
ptr __HBB____1h__mem=0;
ptr __HBB____1h__next_acquired=0;
bool __HBB____1h__success=0;
u64 __HBB____1h__next_size=0;
bool __HBB____1h____jQ__z=0;
char __HBB____zh=0;
u64 __HBB____xh=0;
u64 __HBB__total_len=0;
ptr __HBB____vh__noptr=0;
u64 __HBB____1h__self__allocated__prev=0;
ptr __HBB____vh__contents=0;
u64 __HBB____vh__length=0;
ptr __GBB____Ib__contents=0;
u64 __GBB____Fb____wQ__bytesize=0;
char __GBB____Fb____uQ=0;
cstr __GBB____Fb____oQ=0;
char __HBB____vh__first=0;
bool __GBB____Fb____nQ__z=0;
ptr __GBB____Fb__mem=0;
u64 __GBB____Fb__self__allocated__prev=0;
bool __GBB____Fb__success=0;
u64 __GBB____Fb__next_size=0;
char __GBB____Db=0;
u64 __GBB____Cb__z=0;
u64 __GBB____Bb=0;
u64 __GBB__total_len=0;
ptr __GBB____Ab__noptr=0;
ptr __GBB____Ab__contents=0;
ptr __GBB____9a____m__contents=0;
char __GBB____9a__first=0;
u64 __GBB____9a__length=0;
nominal __CBB____1h__self____TQ=0;
ptr __CBB____4h__contents=0;
bool __CBB____1h____nQ__z=0;
ptr __CBB____1h__mem=0;
u64 __CBB____1h__self__allocated__prev=0;
ptr __CBB____1h__next_acquired=0;
bool __CBB____1h__success=0;
cstr __CBB____1h____kQ=0;
ptr __GBB____Fb__next_acquired=0;
u64 __CBB____xh=0;
char __CBB__first=0;
u64 __CBB__total_len=0;
ptr __CBB____vh__noptr=0;
char __CBB____vh__first=0;
ptr __CBB____vh__contents=0;
u64 __CBB____vh__length=0;
nominal __3AB____TQ=0;
char __BBB____Fb____wQ____CF=0;
cstr __BBB____Fb____oQ=0;
bool __BBB____Fb__success=0;
bool __BBB____Fb____jQ__z=0;
char __CBB____1h____wQ____CF=0;
bool __BBB____Fb____iQ=0;
u64 __BBB____Cb__z=0;
u64 __BBB____Bb=0;
ptr __BBB____Ab__contents=0;
ptr __BBB____9a____m__contents=0;
ptr __BBB____9a__contents=0;
u64 __BBB__len_x=0;
cstr __ABB=0;
cstr __9AB=0;
bool __8AB=0;
errcode __6AB__err=0;
char command__first=0;
u64 command__length=0;
nominal command____c=0;
u64 __3AB____dynamic_entry=0;
u64 __3AB__allocated=0;
u64 __3AB__size=0;
u64 __3AB____ZQ____VQ=0;
ptr __3AB____ZQ__acquired=0;
u64 __0AB____1h____wQ__bytesize=0;
char __0AB____1h____gQ=0;
ptr __0AB____1h__mem=0;
bool __0AB____1h__success=0;
cstr __0AB____1h____kQ=0;
nominal __GBB____Fb__self____TQ=0;
ptr __GBB____9a__contents=0;
bool __0AB____1h____jQ__z=0;
u64 __0AB____yh__z=0;
u64 __0AB____xh=0;
char __0AB__first=0;
char __BBB__first=0;
char __0AB____1h____uQ=0;
u64 __0AB__total_len=0;
ptr __BBB____Ib__contents=0;
u64 __0AB__len_x=0;
u64 __BBB____9a__length=0;
ptr command__contents=0;
ptr __0AB____vh____m__contents=0;
ptr __0AB____vh__noptr=0;
char __0AB____vh__first=0;
ptr __0AB____vh__contents=0;
u64 __0AB____vh__length=0;
nominal __zAB____1h__self____TQ=0;
char __zAB____1h____wQ____CF=0;
cstr __0AB____1h____oQ=0;
u64 __zAB____1h____wQ__bytesize=0;
char __CBB____1h____uQ=0;
char __zAB____1h____uQ=0;
u64 __3AB____ZQ____dynamic_entry=0;
bool __zAB____1h____nQ__z=0;
bool __GBB____Fb____nQ__x=0;
u64 __BBB____Fb____wQ__bytesize=0;
u64 __yAB____Bb=0;
char __CBB____1h____gQ=0;
char __BBB____Ab__first=0;
bool __BBB____Fb____nQ__x=0;
bool __zAB____1h__success=0;
char __GBB____Fb____gQ=0;
u64 __0AB____1h__next_size=0;
char __GBB__first=0;
u64 __uAB____ZQ____VQ=0;
ptr __uAB____ZQ__acquired=0;
u64 __BBB__total_len=0;
u64 __HBB__len_x=0;
bool __CBB____1h____jQ__z=0;
char __zAB__first=0;
char __BBB____9a__first=0;
cstr __CBB____1h____oQ=0;
bool __GBB____Fb____jQ__z=0;
ptr __yAB____Fb__next_acquired=0;
u64 __3AB____ZQ____UQ=0;
ptr __HBB____4h__contents=0;
ptr __GBB____Ab____m__contents=0;
bool __CBB____1h____iQ=0;
bool __zAB____1h____iQ=0;
char __HBB____1h____wQ____CF=0;
u64 __BBB____Fb__next_size=0;
u64 __0AB__len_y=0;
ptr __HBB____vh____m__contents=0;
u64 __zAB____yh__z=0;
char __HBB____1h____gQ=0;
char __yAB____9a__first=0;
nominal __0AB____1h__self____TQ=0;
ptr __BBB____Ab__noptr=0;
cstr __zAB____1h____oQ=0;
ptr __zAB____vh__noptr=0;
char __BBB____Fb____gQ=0;
ptr __zAB____vh____m__contents=0;
bool __yAB____Fb____nQ__z=0;
ptr __0AB____1h__next_acquired=0;
bool __yAB____Fb____iQ=0;
u64 __CBB__len_y=0;
bool __zAB____1h____nQ__x=0;
u64 __CBB__len_x=0;
u64 __zAB____xh=0;
char __GBB____Fb____wQ____CF=0;
u64 __BBB____Fb__self__allocated__prev=0;
char __0AB____zh=0;
u64 __HBB____yh__z=0;
u64 __BBB____Ab__length=0;
cstr __HBB____1h____kQ=0;
u64 __GBB____Ab__length=0;
cstr __HBB____1h____oQ=0;
u64 __zAB____1h__next_size=0;
char __BBB____Fb____uQ=0;
bool __0AB____1h____nQ__x=0;
cstr __EBB=0;
char __GBB____Ab__first=0;
ptr __BBB____Fb__next_acquired=0;
char __HBB__first=0;
u64 __GBB__len_y=0;
bool __CBB____1h____nQ__x=0;
u64 __yAB__len_x=0;
ptr __0AB____4h__contents=0;
bool __yAB____Fb____jQ__z=0;
bool __zAB____1h____jQ__z=0;
char __BBB____Db=0;
cstr __xAB=0;
bool __0AB____1h____nQ__z=0;
u64 __CBB____1h____wQ__bytesize=0;
cstr __wAB=0;
ptr __BBB____Fb__mem=0;
ptr __yAB____9a__contents=0;
ptr __BBB____Ab____m__contents=0;
bool __HBB____1h____iQ=0;
ptr __CBB____vh____m__contents=0;
u64 __CBB____1h__next_size=0;
bool __BBB____Fb____nQ__z=0;
char __yAB____Ab__first=0;
nominal __BBB____Fb__self____TQ=0;
bool __GBB____Fb____iQ=0;
u64 __zAB____vh__length=0;
u64 __0AB____1h__self__allocated__prev=0;
u64 __yAB____Fb__self__allocated__prev=0;
u64 __GBB__len_x=0;
cstr __rAB=0;
ptr __yAB____Fb__mem=0;
ptr command__memory=0;
u64 __zAB____1h__self__allocated__prev=0;
u64 __yAB____Fb____wQ__bytesize=0;
ptr __zAB____4h__contents=0;
ptr __3AB__acquired=0;
char __0AB____1h____wQ____CF=0;
ptr __uAB__acquired=0;
u64 __uAB____ZQ____UQ=0;
u64 __CBB____yh__z=0;
cstr __zAB____1h____kQ=0;
u64 __uAB__size=0;
char __CBB____zh=0;
u64 __zAB__len_y=0;
u64 __uAB__allocated=0;
char __yAB__first=0;
u64 __uAB____dynamic_entry=0;
char __zAB____vh__first=0;
u64 __uAB____ZQ____dynamic_entry=0;
u64 __yAB____9a__length=0;
ptr __yAB____9a__noptr=0;
u64 __BBB__len_y=0;
ptr __yAB____9a____m__contents=0;
ptr __yAB____Ab__contents=0;
ptr __yAB____Ab__noptr=0;
ptr __yAB____Ab____m__contents=0;
u64 __yAB__len_y=0;
u64 __yAB__total_len=0;
char __yAB____Db=0;
u64 __yAB____Cb__z=0;
char __yAB____Fb____wQ____CF=0;
cstr __yAB____Fb____kQ=0;
char __HBB____1h____uQ=0;
ptr __GBB____9a__noptr=0;
bool __0AB____1h____iQ=0;
bool __yAB____Fb__success=0;
cstr __BBB____Fb____kQ=0;
char __yAB____Fb____gQ=0;
ptr __6AB____task=0;
bool __yAB____Fb____nQ__x=0;
u64 __yAB____Fb__next_size=0;
u64 __HBB__len_y=0;
char __yAB____Fb____uQ=0;
ptr __yAB____Ib__contents=0;
nominal __uAB____TQ=0;
nominal __yAB____Fb__self____TQ=0;
ptr __zAB____vh__contents=0;
u64 __zAB__len_x=0;
u64 __zAB__total_len=0;
u64 __yAB____Ab__length=0;
char __zAB____zh=0;
cstr __FBB=0;
cstr __GBB____Fb____kQ=0;
ptr __zAB____1h__next_acquired=0;
ptr __BBB____9a__noptr=0;
ptr __zAB____1h__mem=0;
cstr __yAB____Fb____oQ=0;
char __zAB____1h____gQ=0;

// IMPLEMENTATION
__rAB = " 2>&1" ;
 __uAB____ZQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __uAB____ZQ__acquired )(( ptr **) __uAB____ZQ__acquired )[0]=0; 
 __uAB____ZQ____UQ = 0 ;
 __uAB____ZQ____VQ = 0 ;
 __uAB__acquired = __uAB____ZQ__acquired ;
 __uAB__size = __uAB____ZQ____UQ ;
 __uAB__allocated = __uAB____ZQ____VQ ;
 __uAB____dynamic_entry = __uAB____ZQ____dynamic_entry ;
 __wAB = "./smol tests/unit/" ;
 __xAB = ".s --workers 1 --runtime eager" ;
 __yAB____9a__length = strlen ( __xAB ); __yAB____9a__contents =( ptr ) __xAB ; __yAB____9a__first = __xAB [0]; __yAB____9a__noptr =( ptr ) __yAB____9a__noptr ; 
 __yAB____9a____m__contents = __yAB____9a__contents ;
 __yAB____Ab__length = strlen ( __rAB ); __yAB____Ab__contents =( ptr ) __rAB ; __yAB____Ab__first = __rAB [0]; __yAB____Ab__noptr =( ptr ) __yAB____Ab__noptr ; 
 __yAB____Ab____m__contents = __yAB____Ab__contents ;
 __yAB__len_x = __yAB____9a__length ; __yAB__len_y = __yAB____Ab__length ; __yAB__total_len = __yAB__len_x + __yAB__len_y ; __yAB__first = __yAB____9a__length ? __yAB____9a__first : __yAB____Ab__first ; 
 __yAB____Bb = 1 ;
 __yAB____Cb__z = __yAB__total_len + __yAB____Bb ; 
 __yAB____Cb____end :
 __yAB____Db = 0 ;
 __yAB____Fb____iQ = __uAB__acquired ;
 __yAB____Fb____jQ__z =(! __yAB____Fb____iQ ); 
 __yAB____Fb____jQ____end :
 if(! __yAB____Fb____jQ__z )goto __yAB____Fb____hQ__fi ;
 __yAB____Fb____kQ = "Did not initialize Dynamic" ;
 goto __yAB____Fb____lQ____oD ;
 __builtin_unreachable();
 __yAB____Fb____hQ__fi :
 __yAB____Fb__next_size = __uAB__size +1; __yAB____Fb__success = true ; __yAB____Fb__self__allocated__prev = __uAB__allocated ; if ( __yAB____Fb__next_size >= __uAB__allocated ) { __uAB__allocated = __uAB__allocated + __uAB__allocated /2+1; __yAB____Fb__next_acquired =( ptr )((( ptr **) __uAB__acquired )[0]? __runtime_realloc ((( ptr **) __uAB__acquired )[0], __uAB__allocated * sizeof ( ptr ), __yAB____Fb__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __uAB__allocated * sizeof ( ptr ))); if ( __yAB____Fb__success = __yAB____Fb__next_acquired )(( ptr **) __uAB__acquired )[0]=( ptr *) __yAB____Fb__next_acquired ; } if ( __yAB____Fb__success ) { __yAB____Fb__mem =( ptr ) __runtime_alloc ( __yAB____Cb__z * sizeof ( __yAB____Fb____gQ )); if ( __yAB____Fb__success = __yAB____Fb__mem ) {(( ptr **) __uAB__acquired )[0][ __uAB__size ]= __yAB____Fb__mem ; __uAB__size = __yAB____Fb__next_size ; } } 
 __yAB____Fb____nQ__x = __yAB____Fb__success ;
 __yAB____Fb____nQ__z =(! __yAB____Fb____nQ__x ); 
 __yAB____Fb____nQ____end :
 if(! __yAB____Fb____nQ__z )goto __yAB____Fb____mQ__fi ;
 __yAB____Fb____oQ = "Failed a Dynamic allocation" ;
 goto __yAB____Fb____pQ____oD ;
 __builtin_unreachable();
 __yAB____Fb____mQ__fi :
 __yAB____Fb____uQ = 0 ;
 __yAB____Fb____wQ__bytesize = sizeof ( __yAB____Fb____wQ____CF )* __yAB____Cb__z ; 
 __yAB____Fb____wQ____end :
 memcpy (( char *) __yAB____Fb__mem ,( char *) __yAB____9a____m__contents , __yAB__len_x ); memcpy (( char *) __yAB____Fb__mem + __yAB__len_x ,( char *) __yAB____Ab____m__contents , __yAB__len_y );(( char *) __yAB____Fb__mem )[ __yAB__total_len ]=0; 
 __yAB____Ib__contents = __yAB____Fb__mem ;
 __uAB____TQ = __yAB____Fb__self____TQ ;
 __uAB__acquired = __uAB__acquired ;
 __uAB__size = __uAB__size ;
 __uAB__allocated = __uAB__allocated ;
 __uAB____dynamic_entry = __uAB____dynamic_entry ;
 __zAB____vh__length = strlen ( name ); __zAB____vh__contents =( ptr ) name ; __zAB____vh__first = name [0]; __zAB____vh__noptr =( ptr ) __zAB____vh__noptr ; 
 __zAB____vh____m__contents = __zAB____vh__contents ;
 __zAB__len_x = __zAB____vh__length ; __zAB__len_y = __yAB__total_len ; __zAB__total_len = __zAB__len_x + __zAB__len_y ; __zAB__first = __zAB____vh__length ? __zAB____vh__first : __yAB__first ; 
 __zAB____xh = 1 ;
 __zAB____yh__z = __zAB__total_len + __zAB____xh ; 
 __zAB____yh____end :
 __zAB____zh = 0 ;
 __zAB____1h____iQ = __uAB__acquired ;
 __zAB____1h____jQ__z =(! __zAB____1h____iQ ); 
 __zAB____1h____jQ____end :
 if(! __zAB____1h____jQ__z )goto __zAB____1h____hQ__fi ;
 __zAB____1h____kQ = "Did not initialize Dynamic" ;
 goto __zAB____1h____lQ____oD ;
 __builtin_unreachable();
 __zAB____1h____hQ__fi :
 __zAB____1h__next_size = __uAB__size +1; __zAB____1h__success = true ; __zAB____1h__self__allocated__prev = __uAB__allocated ; if ( __zAB____1h__next_size >= __uAB__allocated ) { __uAB__allocated = __uAB__allocated + __uAB__allocated /2+1; __zAB____1h__next_acquired =( ptr )((( ptr **) __uAB__acquired )[0]? __runtime_realloc ((( ptr **) __uAB__acquired )[0], __uAB__allocated * sizeof ( ptr ), __zAB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __uAB__allocated * sizeof ( ptr ))); if ( __zAB____1h__success = __zAB____1h__next_acquired )(( ptr **) __uAB__acquired )[0]=( ptr *) __zAB____1h__next_acquired ; } if ( __zAB____1h__success ) { __zAB____1h__mem =( ptr ) __runtime_alloc ( __zAB____yh__z * sizeof ( __zAB____1h____gQ )); if ( __zAB____1h__success = __zAB____1h__mem ) {(( ptr **) __uAB__acquired )[0][ __uAB__size ]= __zAB____1h__mem ; __uAB__size = __zAB____1h__next_size ; } } 
 __zAB____1h____nQ__x = __zAB____1h__success ;
 __zAB____1h____nQ__z =(! __zAB____1h____nQ__x ); 
 __zAB____1h____nQ____end :
 if(! __zAB____1h____nQ__z )goto __zAB____1h____mQ__fi ;
 __zAB____1h____oQ = "Failed a Dynamic allocation" ;
 goto __zAB____1h____pQ____oD ;
 __builtin_unreachable();
 __zAB____1h____mQ__fi :
 __zAB____1h____uQ = 0 ;
 __zAB____1h____wQ__bytesize = sizeof ( __zAB____1h____wQ____CF )* __zAB____yh__z ; 
 __zAB____1h____wQ____end :
 memcpy (( char *) __zAB____1h__mem ,( char *) __zAB____vh____m__contents , __zAB__len_x ); memcpy (( char *) __zAB____1h__mem + __zAB__len_x ,( char *) __yAB____Ib__contents , __zAB__len_y );(( char *) __zAB____1h__mem )[ __zAB__total_len ]=0; 
 __zAB____4h__contents = __zAB____1h__mem ;
 __uAB____TQ = __zAB____1h__self____TQ ;
 __uAB__acquired = __uAB__acquired ;
 __uAB__size = __uAB__size ;
 __uAB__allocated = __uAB__allocated ;
 __uAB____dynamic_entry = __uAB____dynamic_entry ;
 __0AB____vh__length = strlen ( __wAB ); __0AB____vh__contents =( ptr ) __wAB ; __0AB____vh__first = __wAB [0]; __0AB____vh__noptr =( ptr ) __0AB____vh__noptr ; 
 __0AB____vh____m__contents = __0AB____vh__contents ;
 __0AB__len_x = __0AB____vh__length ; __0AB__len_y = __zAB__total_len ; __0AB__total_len = __0AB__len_x + __0AB__len_y ; __0AB__first = __0AB____vh__length ? __0AB____vh__first : __zAB__first ; 
 __0AB____xh = 1 ;
 __0AB____yh__z = __0AB__total_len + __0AB____xh ; 
 __0AB____yh____end :
 __0AB____zh = 0 ;
 __0AB____1h____iQ = __uAB__acquired ;
 __0AB____1h____jQ__z =(! __0AB____1h____iQ ); 
 __0AB____1h____jQ____end :
 if(! __0AB____1h____jQ__z )goto __0AB____1h____hQ__fi ;
 __0AB____1h____kQ = "Did not initialize Dynamic" ;
 goto __0AB____1h____lQ____oD ;
 __builtin_unreachable();
 __0AB____1h____hQ__fi :
 __0AB____1h__next_size = __uAB__size +1; __0AB____1h__success = true ; __0AB____1h__self__allocated__prev = __uAB__allocated ; if ( __0AB____1h__next_size >= __uAB__allocated ) { __uAB__allocated = __uAB__allocated + __uAB__allocated /2+1; __0AB____1h__next_acquired =( ptr )((( ptr **) __uAB__acquired )[0]? __runtime_realloc ((( ptr **) __uAB__acquired )[0], __uAB__allocated * sizeof ( ptr ), __0AB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __uAB__allocated * sizeof ( ptr ))); if ( __0AB____1h__success = __0AB____1h__next_acquired )(( ptr **) __uAB__acquired )[0]=( ptr *) __0AB____1h__next_acquired ; } if ( __0AB____1h__success ) { __0AB____1h__mem =( ptr ) __runtime_alloc ( __0AB____yh__z * sizeof ( __0AB____1h____gQ )); if ( __0AB____1h__success = __0AB____1h__mem ) {(( ptr **) __uAB__acquired )[0][ __uAB__size ]= __0AB____1h__mem ; __uAB__size = __0AB____1h__next_size ; } } 
 __0AB____1h____nQ__x = __0AB____1h__success ;
 __0AB____1h____nQ__z =(! __0AB____1h____nQ__x ); 
 __0AB____1h____nQ____end :
 if(! __0AB____1h____nQ__z )goto __0AB____1h____mQ__fi ;
 __0AB____1h____oQ = "Failed a Dynamic allocation" ;
 goto __0AB____1h____pQ____oD ;
 __builtin_unreachable();
 __0AB____1h____mQ__fi :
 __0AB____1h____uQ = 0 ;
 __0AB____1h____wQ__bytesize = sizeof ( __0AB____1h____wQ____CF )* __0AB____yh__z ; 
 __0AB____1h____wQ____end :
 memcpy (( char *) __0AB____1h__mem ,( char *) __0AB____vh____m__contents , __0AB__len_x ); memcpy (( char *) __0AB____1h__mem + __0AB__len_x ,( char *) __zAB____4h__contents , __0AB__len_y );(( char *) __0AB____1h__mem )[ __0AB__total_len ]=0; 
 __0AB____4h__contents = __0AB____1h__mem ;
 __uAB____TQ = __0AB____1h__self____TQ ;
 __uAB__acquired = __uAB__acquired ;
 __uAB__size = __uAB__size ;
 __uAB__allocated = __uAB__allocated ;
 __uAB____dynamic_entry = __uAB____dynamic_entry ;
 __3AB____ZQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __3AB____ZQ__acquired )(( ptr **) __3AB____ZQ__acquired )[0]=0; 
 __3AB____ZQ____UQ = 0 ;
 __3AB____ZQ____VQ = 0 ;
 __3AB__acquired = __3AB____ZQ__acquired ;
 __3AB__size = __3AB____ZQ____UQ ;
 __3AB__allocated = __3AB____ZQ____VQ ;
 __3AB____dynamic_entry = __3AB____ZQ____dynamic_entry ;
 __6AB____state = (struct run__816__state*)__runtime_calloc(sizeof(struct run__816__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __6AB____state ) ;
 __6AB____state -> command____c = command____c ;
 __6AB____state -> command__contents = __0AB____4h__contents ;
 __6AB____state -> command__length = __0AB__total_len ;
 __6AB____state -> command__first = __0AB__first ;
 __6AB____state -> command__memory = __uAB__acquired ;
 __6AB____task = __smolambda_add_task ( run__816 , __6AB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __6AB____task ) ;
 if( __6AB__err ) goto  __result_unhandled_error ;
 if( __6AB__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __6AB____task ) ;
 __6AB__err = __6AB____state -> err ;
 __8AB = __6AB__err ;
 if(! __8AB )goto __5AB__fi ;
 __9AB = "[ \033[31mERROR\033[0m ] " ;
 __ABB = ".s" ;
 __BBB____9a__length = strlen ( name ); __BBB____9a__contents =( ptr ) name ; __BBB____9a__first = name [0]; __BBB____9a__noptr =( ptr ) __BBB____9a__noptr ; 
 __BBB____9a____m__contents = __BBB____9a__contents ;
 __BBB____Ab__length = strlen ( __ABB ); __BBB____Ab__contents =( ptr ) __ABB ; __BBB____Ab__first = __ABB [0]; __BBB____Ab__noptr =( ptr ) __BBB____Ab__noptr ; 
 __BBB____Ab____m__contents = __BBB____Ab__contents ;
 __BBB__len_x = __BBB____9a__length ; __BBB__len_y = __BBB____Ab__length ; __BBB__total_len = __BBB__len_x + __BBB__len_y ; __BBB__first = __BBB____9a__length ? __BBB____9a__first : __BBB____Ab__first ; 
 __BBB____Bb = 1 ;
 __BBB____Cb__z = __BBB__total_len + __BBB____Bb ; 
 __BBB____Cb____end :
 __BBB____Db = 0 ;
 __BBB____Fb____iQ = __3AB__acquired ;
 __BBB____Fb____jQ__z =(! __BBB____Fb____iQ ); 
 __BBB____Fb____jQ____end :
 if(! __BBB____Fb____jQ__z )goto __BBB____Fb____hQ__fi ;
 __BBB____Fb____kQ = "Did not initialize Dynamic" ;
 goto __BBB____Fb____lQ____oD ;
 __builtin_unreachable();
 __BBB____Fb____hQ__fi :
 __BBB____Fb__next_size = __3AB__size +1; __BBB____Fb__success = true ; __BBB____Fb__self__allocated__prev = __3AB__allocated ; if ( __BBB____Fb__next_size >= __3AB__allocated ) { __3AB__allocated = __3AB__allocated + __3AB__allocated /2+1; __BBB____Fb__next_acquired =( ptr )((( ptr **) __3AB__acquired )[0]? __runtime_realloc ((( ptr **) __3AB__acquired )[0], __3AB__allocated * sizeof ( ptr ), __BBB____Fb__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __3AB__allocated * sizeof ( ptr ))); if ( __BBB____Fb__success = __BBB____Fb__next_acquired )(( ptr **) __3AB__acquired )[0]=( ptr *) __BBB____Fb__next_acquired ; } if ( __BBB____Fb__success ) { __BBB____Fb__mem =( ptr ) __runtime_alloc ( __BBB____Cb__z * sizeof ( __BBB____Fb____gQ )); if ( __BBB____Fb__success = __BBB____Fb__mem ) {(( ptr **) __3AB__acquired )[0][ __3AB__size ]= __BBB____Fb__mem ; __3AB__size = __BBB____Fb__next_size ; } } 
 __BBB____Fb____nQ__x = __BBB____Fb__success ;
 __BBB____Fb____nQ__z =(! __BBB____Fb____nQ__x ); 
 __BBB____Fb____nQ____end :
 if(! __BBB____Fb____nQ__z )goto __BBB____Fb____mQ__fi ;
 __BBB____Fb____oQ = "Failed a Dynamic allocation" ;
 goto __BBB____Fb____pQ____oD ;
 __builtin_unreachable();
 __BBB____Fb____mQ__fi :
 __BBB____Fb____uQ = 0 ;
 __BBB____Fb____wQ__bytesize = sizeof ( __BBB____Fb____wQ____CF )* __BBB____Cb__z ; 
 __BBB____Fb____wQ____end :
 memcpy (( char *) __BBB____Fb__mem ,( char *) __BBB____9a____m__contents , __BBB__len_x ); memcpy (( char *) __BBB____Fb__mem + __BBB__len_x ,( char *) __BBB____Ab____m__contents , __BBB__len_y );(( char *) __BBB____Fb__mem )[ __BBB__total_len ]=0; 
 __BBB____Ib__contents = __BBB____Fb__mem ;
 __3AB____TQ = __BBB____Fb__self____TQ ;
 __3AB__acquired = __3AB__acquired ;
 __3AB__size = __3AB__size ;
 __3AB__allocated = __3AB__allocated ;
 __3AB____dynamic_entry = __3AB____dynamic_entry ;
 __CBB____vh__length = strlen ( __9AB ); __CBB____vh__contents =( ptr ) __9AB ; __CBB____vh__first = __9AB [0]; __CBB____vh__noptr =( ptr ) __CBB____vh__noptr ; 
 __CBB____vh____m__contents = __CBB____vh__contents ;
 __CBB__len_x = __CBB____vh__length ; __CBB__len_y = __BBB__total_len ; __CBB__total_len = __CBB__len_x + __CBB__len_y ; __CBB__first = __CBB____vh__length ? __CBB____vh__first : __BBB__first ; 
 __CBB____xh = 1 ;
 __CBB____yh__z = __CBB__total_len + __CBB____xh ; 
 __CBB____yh____end :
 __CBB____zh = 0 ;
 __CBB____1h____iQ = __3AB__acquired ;
 __CBB____1h____jQ__z =(! __CBB____1h____iQ ); 
 __CBB____1h____jQ____end :
 if(! __CBB____1h____jQ__z )goto __CBB____1h____hQ__fi ;
 __CBB____1h____kQ = "Did not initialize Dynamic" ;
 goto __CBB____1h____lQ____oD ;
 __builtin_unreachable();
 __CBB____1h____hQ__fi :
 __CBB____1h__next_size = __3AB__size +1; __CBB____1h__success = true ; __CBB____1h__self__allocated__prev = __3AB__allocated ; if ( __CBB____1h__next_size >= __3AB__allocated ) { __3AB__allocated = __3AB__allocated + __3AB__allocated /2+1; __CBB____1h__next_acquired =( ptr )((( ptr **) __3AB__acquired )[0]? __runtime_realloc ((( ptr **) __3AB__acquired )[0], __3AB__allocated * sizeof ( ptr ), __CBB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __3AB__allocated * sizeof ( ptr ))); if ( __CBB____1h__success = __CBB____1h__next_acquired )(( ptr **) __3AB__acquired )[0]=( ptr *) __CBB____1h__next_acquired ; } if ( __CBB____1h__success ) { __CBB____1h__mem =( ptr ) __runtime_alloc ( __CBB____yh__z * sizeof ( __CBB____1h____gQ )); if ( __CBB____1h__success = __CBB____1h__mem ) {(( ptr **) __3AB__acquired )[0][ __3AB__size ]= __CBB____1h__mem ; __3AB__size = __CBB____1h__next_size ; } } 
 __CBB____1h____nQ__x = __CBB____1h__success ;
 __CBB____1h____nQ__z =(! __CBB____1h____nQ__x ); 
 __CBB____1h____nQ____end :
 if(! __CBB____1h____nQ__z )goto __CBB____1h____mQ__fi ;
 __CBB____1h____oQ = "Failed a Dynamic allocation" ;
 goto __CBB____1h____pQ____oD ;
 __builtin_unreachable();
 __CBB____1h____mQ__fi :
 __CBB____1h____uQ = 0 ;
 __CBB____1h____wQ__bytesize = sizeof ( __CBB____1h____wQ____CF )* __CBB____yh__z ; 
 __CBB____1h____wQ____end :
 memcpy (( char *) __CBB____1h__mem ,( char *) __CBB____vh____m__contents , __CBB__len_x ); memcpy (( char *) __CBB____1h__mem + __CBB__len_x ,( char *) __BBB____Ib__contents , __CBB__len_y );(( char *) __CBB____1h__mem )[ __CBB__total_len ]=0; 
 __CBB____4h__contents = __CBB____1h__mem ;
 __3AB____TQ = __CBB____1h__self____TQ ;
 __3AB__acquired = __3AB__acquired ;
 __3AB__size = __3AB__size ;
 __3AB__allocated = __3AB__allocated ;
 __3AB____dynamic_entry = __3AB____dynamic_entry ;
 printf ( "%s\n" ,( char *) __CBB____4h__contents ); 
 __DBB____end :
 goto __5AB__el ;
 __5AB__fi :
 __EBB = "[ \033[32mOK\033[0m ] " ;
 __FBB = ".s" ;
 __GBB____9a__length = strlen ( name ); __GBB____9a__contents =( ptr ) name ; __GBB____9a__first = name [0]; __GBB____9a__noptr =( ptr ) __GBB____9a__noptr ; 
 __GBB____9a____m__contents = __GBB____9a__contents ;
 __GBB____Ab__length = strlen ( __FBB ); __GBB____Ab__contents =( ptr ) __FBB ; __GBB____Ab__first = __FBB [0]; __GBB____Ab__noptr =( ptr ) __GBB____Ab__noptr ; 
 __GBB____Ab____m__contents = __GBB____Ab__contents ;
 __GBB__len_x = __GBB____9a__length ; __GBB__len_y = __GBB____Ab__length ; __GBB__total_len = __GBB__len_x + __GBB__len_y ; __GBB__first = __GBB____9a__length ? __GBB____9a__first : __GBB____Ab__first ; 
 __GBB____Bb = 1 ;
 __GBB____Cb__z = __GBB__total_len + __GBB____Bb ; 
 __GBB____Cb____end :
 __GBB____Db = 0 ;
 __GBB____Fb____iQ = __3AB__acquired ;
 __GBB____Fb____jQ__z =(! __GBB____Fb____iQ ); 
 __GBB____Fb____jQ____end :
 if(! __GBB____Fb____jQ__z )goto __GBB____Fb____hQ__fi ;
 __GBB____Fb____kQ = "Did not initialize Dynamic" ;
 goto __GBB____Fb____lQ____oD ;
 __builtin_unreachable();
 __GBB____Fb____hQ__fi :
 __GBB____Fb__next_size = __3AB__size +1; __GBB____Fb__success = true ; __GBB____Fb__self__allocated__prev = __3AB__allocated ; if ( __GBB____Fb__next_size >= __3AB__allocated ) { __3AB__allocated = __3AB__allocated + __3AB__allocated /2+1; __GBB____Fb__next_acquired =( ptr )((( ptr **) __3AB__acquired )[0]? __runtime_realloc ((( ptr **) __3AB__acquired )[0], __3AB__allocated * sizeof ( ptr ), __GBB____Fb__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __3AB__allocated * sizeof ( ptr ))); if ( __GBB____Fb__success = __GBB____Fb__next_acquired )(( ptr **) __3AB__acquired )[0]=( ptr *) __GBB____Fb__next_acquired ; } if ( __GBB____Fb__success ) { __GBB____Fb__mem =( ptr ) __runtime_alloc ( __GBB____Cb__z * sizeof ( __GBB____Fb____gQ )); if ( __GBB____Fb__success = __GBB____Fb__mem ) {(( ptr **) __3AB__acquired )[0][ __3AB__size ]= __GBB____Fb__mem ; __3AB__size = __GBB____Fb__next_size ; } } 
 __GBB____Fb____nQ__x = __GBB____Fb__success ;
 __GBB____Fb____nQ__z =(! __GBB____Fb____nQ__x ); 
 __GBB____Fb____nQ____end :
 if(! __GBB____Fb____nQ__z )goto __GBB____Fb____mQ__fi ;
 __GBB____Fb____oQ = "Failed a Dynamic allocation" ;
 goto __GBB____Fb____pQ____oD ;
 __builtin_unreachable();
 __GBB____Fb____mQ__fi :
 __GBB____Fb____uQ = 0 ;
 __GBB____Fb____wQ__bytesize = sizeof ( __GBB____Fb____wQ____CF )* __GBB____Cb__z ; 
 __GBB____Fb____wQ____end :
 memcpy (( char *) __GBB____Fb__mem ,( char *) __GBB____9a____m__contents , __GBB__len_x ); memcpy (( char *) __GBB____Fb__mem + __GBB__len_x ,( char *) __GBB____Ab____m__contents , __GBB__len_y );(( char *) __GBB____Fb__mem )[ __GBB__total_len ]=0; 
 __GBB____Ib__contents = __GBB____Fb__mem ;
 __3AB____TQ = __GBB____Fb__self____TQ ;
 __3AB__acquired = __3AB__acquired ;
 __3AB__size = __3AB__size ;
 __3AB__allocated = __3AB__allocated ;
 __3AB____dynamic_entry = __3AB____dynamic_entry ;
 __HBB____vh__length = strlen ( __EBB ); __HBB____vh__contents =( ptr ) __EBB ; __HBB____vh__first = __EBB [0]; __HBB____vh__noptr =( ptr ) __HBB____vh__noptr ; 
 __HBB____vh____m__contents = __HBB____vh__contents ;
 __HBB__len_x = __HBB____vh__length ; __HBB__len_y = __GBB__total_len ; __HBB__total_len = __HBB__len_x + __HBB__len_y ; __HBB__first = __HBB____vh__length ? __HBB____vh__first : __GBB__first ; 
 __HBB____xh = 1 ;
 __HBB____yh__z = __HBB__total_len + __HBB____xh ; 
 __HBB____yh____end :
 __HBB____zh = 0 ;
 __HBB____1h____iQ = __3AB__acquired ;
 __HBB____1h____jQ__z =(! __HBB____1h____iQ ); 
 __HBB____1h____jQ____end :
 if(! __HBB____1h____jQ__z )goto __HBB____1h____hQ__fi ;
 __HBB____1h____kQ = "Did not initialize Dynamic" ;
 goto __HBB____1h____lQ____oD ;
 __builtin_unreachable();
 __HBB____1h____hQ__fi :
 __HBB____1h__next_size = __3AB__size +1; __HBB____1h__success = true ; __HBB____1h__self__allocated__prev = __3AB__allocated ; if ( __HBB____1h__next_size >= __3AB__allocated ) { __3AB__allocated = __3AB__allocated + __3AB__allocated /2+1; __HBB____1h__next_acquired =( ptr )((( ptr **) __3AB__acquired )[0]? __runtime_realloc ((( ptr **) __3AB__acquired )[0], __3AB__allocated * sizeof ( ptr ), __HBB____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __3AB__allocated * sizeof ( ptr ))); if ( __HBB____1h__success = __HBB____1h__next_acquired )(( ptr **) __3AB__acquired )[0]=( ptr *) __HBB____1h__next_acquired ; } if ( __HBB____1h__success ) { __HBB____1h__mem =( ptr ) __runtime_alloc ( __HBB____yh__z * sizeof ( __HBB____1h____gQ )); if ( __HBB____1h__success = __HBB____1h__mem ) {(( ptr **) __3AB__acquired )[0][ __3AB__size ]= __HBB____1h__mem ; __3AB__size = __HBB____1h__next_size ; } } 
 __HBB____1h____nQ__x = __HBB____1h__success ;
 __HBB____1h____nQ__z =(! __HBB____1h____nQ__x ); 
 __HBB____1h____nQ____end :
 if(! __HBB____1h____nQ__z )goto __HBB____1h____mQ__fi ;
 __HBB____1h____oQ = "Failed a Dynamic allocation" ;
 goto __HBB____1h____pQ____oD ;
 __builtin_unreachable();
 __HBB____1h____mQ__fi :
 __HBB____1h____uQ = 0 ;
 __HBB____1h____wQ__bytesize = sizeof ( __HBB____1h____wQ____CF )* __HBB____yh__z ; 
 __HBB____1h____wQ____end :
 memcpy (( char *) __HBB____1h__mem ,( char *) __HBB____vh____m__contents , __HBB__len_x ); memcpy (( char *) __HBB____1h__mem + __HBB__len_x ,( char *) __GBB____Ib__contents , __HBB__len_y );(( char *) __HBB____1h__mem )[ __HBB__total_len ]=0; 
 __HBB____4h__contents = __HBB____1h__mem ;
 __3AB____TQ = __HBB____1h__self____TQ ;
 __3AB__acquired = __3AB__acquired ;
 __3AB__size = __3AB__size ;
 __3AB__allocated = __3AB__allocated ;
 __3AB____dynamic_entry = __3AB____dynamic_entry ;
 printf ( "%s\n" ,( char *) __HBB____4h__contents ); 
 __IBB____end :
 __5AB__el :
 __end :
goto __return;

// ERROR HANDLING
__HBB____1h____lQ____oD :
 printf ( "%s\n" , __HBB____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__7AB :
printf("Runtime error from run __6AB \n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
__GBB____Fb____lQ____oD :
 printf ( "%s\n" , __GBB____Fb____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__CBB____1h____lQ____oD :
 printf ( "%s\n" , __CBB____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__yAB____Fb____pQ____oD :
 printf ( "%s\n" , __yAB____Fb____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__CBB____1h____pQ____oD :
 printf ( "%s\n" , __CBB____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__HBB____1h____pQ____oD :
 printf ( "%s\n" , __HBB____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__yAB____Fb____lQ____oD :
 printf ( "%s\n" , __yAB____Fb____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__0AB____1h____pQ____oD :
 printf ( "%s\n" , __0AB____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__zAB____1h____lQ____oD :
 printf ( "%s\n" , __zAB____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__BBB____Fb____lQ____oD :
 printf ( "%s\n" , __BBB____Fb____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__BBB____Fb____pQ____oD :
 printf ( "%s\n" , __BBB____Fb____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__GBB____Fb____pQ____oD :
 printf ( "%s\n" , __GBB____Fb____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__zAB____1h____pQ____oD :
 printf ( "%s\n" , __zAB____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__0AB____1h____lQ____oD :
 printf ( "%s\n" , __0AB____1h____kQ ); 
__result__errocode=__USER__ERROR;
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
if ( __3AB__acquired ) { for ( __3AB____dynamic_entry =0; __3AB____dynamic_entry < __3AB__size ;++ __3AB____dynamic_entry ) { __runtime_free ((( ptr **) __3AB__acquired )[0][ __3AB____dynamic_entry ]); } __runtime_free ( __3AB__acquired ); __3AB__acquired =0; __3AB__size =0; __3AB__allocated =0; } 
 if ( __3AB__acquired ) { for ( __3AB____ZQ____dynamic_entry =0; __3AB____ZQ____dynamic_entry < __3AB____ZQ____UQ ;++ __3AB____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __3AB__acquired )[0][ __3AB____ZQ____dynamic_entry ]); } __runtime_free ( __3AB__acquired ); __3AB__acquired =0; __3AB____ZQ____UQ =0; __3AB____ZQ____VQ =0; } 
if ( __uAB__acquired ) { for ( __uAB____dynamic_entry =0; __uAB____dynamic_entry < __uAB__size ;++ __uAB____dynamic_entry ) { __runtime_free ((( ptr **) __uAB__acquired )[0][ __uAB____dynamic_entry ]); } __runtime_free ( __uAB__acquired ); __uAB__acquired =0; __uAB__size =0; __uAB__allocated =0; } 
 if ( __uAB__acquired ) { for ( __uAB____ZQ____dynamic_entry =0; __uAB____ZQ____dynamic_entry < __uAB____ZQ____UQ ;++ __uAB____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __uAB__acquired )[0][ __uAB____ZQ____dynamic_entry ]); } __runtime_free ( __uAB__acquired ); __uAB__acquired =0; __uAB____ZQ____UQ =0; __uAB____ZQ____VQ =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}


void all__821(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct all__821__state *__state=(struct all__821__state*)__void__state;
struct std_test__818__state* __ECB____state = 0 ;
 struct std_test__818__state* __GCB____state = 0 ;
 struct std_test__818__state* __ICB____state = 0 ;
 struct std_test__818__state* __KCB____state = 0 ;
 struct std_test__818__state* __MCB____state = 0 ;
 struct std_test__818__state* __OCB____state = 0 ;
 struct std_test__818__state* __QCB____state = 0 ;
 struct std_test__818__state* __SCB____state = 0 ;
 struct std_test__818__state* __UCB____state = 0 ;
 struct std_test__818__state* __WCB____state = 0 ;
 struct std_test__818__state* __YCB____state = 0 ;
 struct std_test__818__state* __aCB____state = 0 ;
 struct std_test__818__state* __cCB____state = 0 ;
 struct std_test__818__state* __eCB____state = 0 ;
 struct std_test__818__state* __gCB____state = 0 ;
 struct std_test__818__state* __iCB____state = 0 ;
 struct std_test__818__state* __kCB____state = 0 ;
 struct std_test__818__state* __mCB____state = 0 ;
 struct std_test__818__state* __oCB____state = 0 ;
errcode __oCB__err=0;
errcode __mCB__err=0;
ptr __mCB____task=0;
cstr __lCB=0;
errcode __kCB__err=0;
cstr __jCB=0;
errcode __iCB__err=0;
ptr __iCB____task=0;
cstr __hCB=0;
errcode __gCB__err=0;
ptr __gCB____task=0;
ptr __eCB____task=0;
cstr __dCB=0;
errcode __cCB__err=0;
ptr __cCB____task=0;
ptr __aCB____task=0;
errcode __WCB__err=0;
ptr __WCB____task=0;
cstr __PCB=0;
errcode __OCB__err=0;
ptr __OCB____task=0;
cstr __NCB=0;
ptr __MCB____task=0;
cstr __JCB=0;
ptr __ICB____task=0;
errcode __GCB__err=0;
ptr __GCB____task=0;
cstr __FCB=0;
errcode __ECB__err=0;
ptr __ECB____task=0;
cstr __DCB=0;
errcode __YCB__err=0;
errcode __SCB__err=0;
errcode __eCB__err=0;
ptr __oCB____task=0;
ptr __kCB____task=0;
cstr __VCB=0;
errcode __ICB__err=0;
cstr __XCB=0;
cstr __TCB=0;
errcode __MCB__err=0;
ptr __SCB____task=0;
ptr __QCB____task=0;
cstr __ZCB=0;
cstr __fCB=0;
ptr __UCB____task=0;
errcode __UCB__err=0;
errcode __QCB__err=0;
cstr __bCB=0;
cstr __HCB=0;
cstr __nCB=0;
errcode __KCB__err=0;
ptr __YCB____task=0;
cstr __RCB=0;
cstr __LCB=0;
errcode __aCB__err=0;
ptr __KCB____task=0;

// IMPLEMENTATION
__DCB = "buffers" ;
 __ECB____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __ECB____state ) ;
 __ECB____state -> name = __DCB ;
 __ECB____task = __smolambda_add_task ( std_test__818 , __ECB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __ECB____task ) ;
 if( __ECB__err ) goto  __result_unhandled_error ;
 if( __ECB__err ) goto  __result_unhandled_error ;
 __FCB = "bbuffer" ;
 __GCB____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __GCB____state ) ;
 __GCB____state -> name = __FCB ;
 __GCB____task = __smolambda_add_task ( std_test__818 , __GCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __GCB____task ) ;
 if( __GCB__err ) goto  __result_unhandled_error ;
 if( __GCB__err ) goto  __result_unhandled_error ;
 __HCB = "bufferconst" ;
 __ICB____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __ICB____state ) ;
 __ICB____state -> name = __HCB ;
 __ICB____task = __smolambda_add_task ( std_test__818 , __ICB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __ICB____task ) ;
 if( __ICB__err ) goto  __result_unhandled_error ;
 if( __ICB__err ) goto  __result_unhandled_error ;
 __JCB = "buffergrow" ;
 __KCB____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __KCB____state ) ;
 __KCB____state -> name = __JCB ;
 __KCB____task = __smolambda_add_task ( std_test__818 , __KCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __KCB____task ) ;
 if( __KCB__err ) goto  __result_unhandled_error ;
 if( __KCB__err ) goto  __result_unhandled_error ;
 __LCB = "effvec" ;
 __MCB____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __MCB____state ) ;
 __MCB____state -> name = __LCB ;
 __MCB____task = __smolambda_add_task ( std_test__818 , __MCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __MCB____task ) ;
 if( __MCB__err ) goto  __result_unhandled_error ;
 if( __MCB__err ) goto  __result_unhandled_error ;
 __NCB = "fail" ;
 __OCB____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __OCB____state ) ;
 __OCB____state -> name = __NCB ;
 __OCB____task = __smolambda_add_task ( std_test__818 , __OCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __OCB____task ) ;
 if( __OCB__err ) goto  __result_unhandled_error ;
 if( __OCB__err ) goto  __result_unhandled_error ;
 __PCB = "file" ;
 __QCB____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __QCB____state ) ;
 __QCB____state -> name = __PCB ;
 __QCB____task = __smolambda_add_task ( std_test__818 , __QCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __QCB____task ) ;
 if( __QCB__err ) goto  __result_unhandled_error ;
 if( __QCB__err ) goto  __result_unhandled_error ;
 __RCB = "filesize" ;
 __SCB____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __SCB____state ) ;
 __SCB____state -> name = __RCB ;
 __SCB____task = __smolambda_add_task ( std_test__818 , __SCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __SCB____task ) ;
 if( __SCB__err ) goto  __result_unhandled_error ;
 if( __SCB__err ) goto  __result_unhandled_error ;
 __TCB = "finally" ;
 __UCB____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __UCB____state ) ;
 __UCB____state -> name = __TCB ;
 __UCB____task = __smolambda_add_task ( std_test__818 , __UCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __UCB____task ) ;
 if( __UCB__err ) goto  __result_unhandled_error ;
 if( __UCB__err ) goto  __result_unhandled_error ;
 __VCB = "nom" ;
 __WCB____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __WCB____state ) ;
 __WCB____state -> name = __VCB ;
 __WCB____task = __smolambda_add_task ( std_test__818 , __WCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __WCB____task ) ;
 if( __WCB__err ) goto  __result_unhandled_error ;
 if( __WCB__err ) goto  __result_unhandled_error ;
 __XCB = "mem" ;
 __YCB____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __YCB____state ) ;
 __YCB____state -> name = __XCB ;
 __YCB____task = __smolambda_add_task ( std_test__818 , __YCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __YCB____task ) ;
 if( __YCB__err ) goto  __result_unhandled_error ;
 if( __YCB__err ) goto  __result_unhandled_error ;
 __ZCB = "memtest" ;
 __aCB____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __aCB____state ) ;
 __aCB____state -> name = __ZCB ;
 __aCB____task = __smolambda_add_task ( std_test__818 , __aCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __aCB____task ) ;
 if( __aCB__err ) goto  __result_unhandled_error ;
 if( __aCB__err ) goto  __result_unhandled_error ;
 __bCB = "mutpoint" ;
 __cCB____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __cCB____state ) ;
 __cCB____state -> name = __bCB ;
 __cCB____task = __smolambda_add_task ( std_test__818 , __cCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __cCB____task ) ;
 if( __cCB__err ) goto  __result_unhandled_error ;
 if( __cCB__err ) goto  __result_unhandled_error ;
 __dCB = "range_test" ;
 __eCB____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __eCB____state ) ;
 __eCB____state -> name = __dCB ;
 __eCB____task = __smolambda_add_task ( std_test__818 , __eCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __eCB____task ) ;
 if( __eCB__err ) goto  __result_unhandled_error ;
 if( __eCB__err ) goto  __result_unhandled_error ;
 __fCB = "ref" ;
 __gCB____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __gCB____state ) ;
 __gCB____state -> name = __fCB ;
 __gCB____task = __smolambda_add_task ( std_test__818 , __gCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __gCB____task ) ;
 if( __gCB__err ) goto  __result_unhandled_error ;
 if( __gCB__err ) goto  __result_unhandled_error ;
 __hCB = "strcat" ;
 __iCB____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __iCB____state ) ;
 __iCB____state -> name = __hCB ;
 __iCB____task = __smolambda_add_task ( std_test__818 , __iCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __iCB____task ) ;
 if( __iCB__err ) goto  __result_unhandled_error ;
 if( __iCB__err ) goto  __result_unhandled_error ;
 __jCB = "vec" ;
 __kCB____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __kCB____state ) ;
 __kCB____state -> name = __jCB ;
 __kCB____task = __smolambda_add_task ( std_test__818 , __kCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __kCB____task ) ;
 if( __kCB__err ) goto  __result_unhandled_error ;
 if( __kCB__err ) goto  __result_unhandled_error ;
 __lCB = "virtfile" ;
 __mCB____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __mCB____state ) ;
 __mCB____state -> name = __lCB ;
 __mCB____task = __smolambda_add_task ( std_test__818 , __mCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __mCB____task ) ;
 if( __mCB__err ) goto  __result_unhandled_error ;
 if( __mCB__err ) goto  __result_unhandled_error ;
 __nCB = "accessvar" ;
 __oCB____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __oCB____state ) ;
 __oCB____state -> name = __nCB ;
 __oCB____task = __smolambda_add_task ( std_test__818 , __oCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __oCB____task ) ;
 if( __oCB__err ) goto  __result_unhandled_error ;
 if( __oCB__err ) goto  __result_unhandled_error ;
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


void main__822(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__822__state *__state=(struct main__822__state*)__void__state;
struct all__821__state* __qCB____state = 0 ;
f64 __uCB__elapsed=0;
errcode __qCB__err=0;
ptr __qCB____task=0;
f64 __pCB__elapsed=0;
cstr __sCB=0;
f64 __vCB__z=0;
cstr __xCB=0;

// IMPLEMENTATION
__pCB__elapsed = __smo_time_eta (); 
 __pCB____end :
 __qCB____state = (struct all__821__state*)__runtime_calloc(sizeof(struct all__821__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __qCB____state ) ;
 __qCB____task = __smolambda_add_task ( all__821 , __qCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __qCB____task ) ;
 if( __qCB__err ) goto  __result_unhandled_error ;
 if( __qCB__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __qCB____task ) ;
 __qCB__err = __qCB____state -> err ;
 __sCB = "Completed in " ;
 printf ( "%s" , __sCB ); 
 __tCB____end :
 __uCB__elapsed = __smo_time_eta (); 
 __uCB____end :
 __vCB__z = __uCB__elapsed - __pCB__elapsed ; 
 __vCB____end :
 printf ( "%.6f" , __vCB__z ); 
 __wCB____end :
 __xCB = " sec" ;
 printf ( "%s\n" , __xCB ); 
 __yCB____end :
 __end :
goto __return;

// ERROR HANDLING
__rCB :
printf("Runtime error from all __qCB \n");
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
struct main__822__state __main_args={0};
__smolambda_initialize_service_tasks(main__822, &__main_args);
return __main_args.err;
}

