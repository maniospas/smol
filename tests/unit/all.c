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

struct main__822__state{errcode err;};
__externc void main__822(void *__void__state);
struct run__814__state{errcode err;cstr command;};
__externc void run__814(void *__void__state);
struct run__815__state{errcode err;nominal command____b;ptr command__contents;u64 command__length;char command__first;ptr command__memory;};
__externc void run__815(void *__void__state);
struct run__816__state{errcode err;nominal command____c;ptr command__contents;u64 command__length;char command__first;ptr command__memory;};
__externc void run__816(void *__void__state);
struct std_test__818__state{errcode err;cstr name;};
__externc void std_test__818(void *__void__state);
struct std_test__819__state{errcode err;nominal name____b;ptr name__contents;u64 name__length;char name__first;ptr name__memory;};
__externc void std_test__819(void *__void__state);
struct std_test__820__state{errcode err;nominal name____c;ptr name__contents;u64 name__length;char name__first;ptr name__memory;};
__externc void std_test__820(void *__void__state);
struct all__821__state{errcode err;};
__externc void all__821(void *__void__state);

void std_test__820(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__820__state *__state=(struct std_test__820__state*)__void__state;
struct run__816__state* __I8____state = 0 ;
ptr name__contents= __state->name__contents;
u64 name__length= __state->name__length;
char name__first= __state->name__first;
ptr name__memory= __state->name__memory;
nominal __T8____op__self____TQ=0;
ptr __T8____vp__contents=0;
char __T8____op____wQ____dE=0;
char __T8____op____uQ=0;
cstr __T8____op____oQ=0;
char __T8__first=0;
u64 __T8__len_x=0;
ptr __T8____ep__noptr=0;
u64 __T8____lp__z=0;
char __T8____ep__first=0;
ptr __T8____ep__contents=0;
u64 __T8____ep__length=0;
cstr __S8____hh____oQ=0;
bool __S8____hh____nQ__z=0;
ptr __S8____hh__next_acquired=0;
char __S8____fh=0;
u64 __S8____eh__z=0;
u64 __S8____dh=0;
u64 __T8____op__next_size=0;
bool __S8____hh__success=0;
char __S8__first=0;
u64 __S8__len_y=0;
ptr __S8____ch__noptr=0;
char __S8____ch__first=0;
cstr __R8=0;
nominal __O8____op__self____TQ=0;
ptr __O8____vp__contents=0;
char __O8____op____wQ____dE=0;
u64 __O8____op____wQ__bytesize=0;
char __O8____op____uQ=0;
ptr __S8____ch__contents=0;
cstr __O8____op____oQ=0;
bool __O8____op____nQ__z=0;
bool __O8____op____nQ__x=0;
ptr __O8____op__mem=0;
ptr __O8____op__next_acquired=0;
bool __O8____op__success=0;
u64 __O8____op__next_size=0;
ptr __S8____ch____u__contents=0;
cstr __Q8=0;
bool __O8____op____jQ__z=0;
u64 __O8____kp=0;
u64 __O8__total_len=0;
u64 __O8__len_y=0;
char __O8__first=0;
u64 __O8__len_x=0;
ptr __O8____ep__noptr=0;
ptr __O8____ep__contents=0;
u64 __O8____ep__length=0;
nominal __N8____hh__self____TQ=0;
nominal __F8____TQ=0;
char __O8____op____gQ=0;
char __N8____hh____gQ=0;
u64 __S8__len_x=0;
ptr __N8____hh__mem=0;
ptr __N8____hh__next_acquired=0;
u64 __N8____hh__next_size=0;
bool __N8____hh____jQ__z=0;
bool __N8____hh____iQ=0;
char __N8____fh=0;
u64 __N8____eh__z=0;
u64 __N8____dh=0;
u64 __N8__total_len=0;
ptr __N8____ch__noptr=0;
u64 __N8____ch__length=0;
char __S8____hh____gQ=0;
cstr __M8=0;
errcode __I8__err=0;
char command__first=0;
u64 command__length=0;
ptr command__contents=0;
ptr __C8____ep____u__contents=0;
bool __T8____op____jQ__z=0;
u64 __C8____ep__length=0;
cstr __N8____hh____oQ=0;
u64 __N8____hh__self__allocated__prev=0;
char __B8____hh____gQ=0;
u64 __B8____hh__next_size=0;
u64 __T8____op__self__allocated__prev=0;
char __C8____ep__first=0;
u64 __F8____dynamic_entry=0;
char __N8____hh____wQ____dE=0;
u64 __N8__len_y=0;
bool __B8____hh____nQ__x=0;
char __O8____ep__first=0;
char __C8____mp=0;
bool __T8____op____nQ__x=0;
nominal __S8____hh__self____TQ=0;
u64 __T8____op____wQ__bytesize=0;
char __N8__first=0;
u64 __S8____hh__self__allocated__prev=0;
ptr __S8____nh__contents=0;
u64 __S8____ch__length=0;
bool __T8____op__success=0;
bool __O8____op____iQ=0;
char __N8____hh____uQ=0;
bool __K8=0;
bool __N8____hh____nQ__z=0;
u64 __C8__len_x=0;
char __S8____hh____uQ=0;
ptr __B8____ch__noptr=0;
u64 __F8__allocated=0;
cstr __L8=0;
u64 __B8____ch__length=0;
ptr __N8____nh__contents=0;
char __N8____ch__first=0;
char __O8____mp=0;
ptr __I8____task=0;
bool __S8____hh____nQ__x=0;
char __B8____ch__first=0;
u64 __T8__total_len=0;
ptr __T8____ep____u__contents=0;
char __S8____hh____wQ____dE=0;
char __B8____hh____uQ=0;
ptr __O8____ep____u__contents=0;
bool __S8____hh____iQ=0;
u64 __C8____op____wQ__bytesize=0;
ptr __C8____vp__contents=0;
ptr __T8____op__mem=0;
ptr __F8__acquired=0;
char __T8____mp=0;
cstr __S8____hh____kQ=0;
char __B8____hh____wQ____dE=0;
u64 __O8____lp__z=0;
ptr __B8____nh__contents=0;
u64 __B8____eh__z=0;
cstr __T8____op____kQ=0;
u64 __O8____op__self__allocated__prev=0;
bool __B8____hh____iQ=0;
char __C8____op____wQ____dE=0;
cstr __A8=0;
u64 __F8____ZQ____dynamic_entry=0;
u64 __C8__len_y=0;
cstr __C8____op____oQ=0;
u64 __S8____hh__next_size=0;
ptr __F8____ZQ__acquired=0;
bool __N8____hh__success=0;
ptr __77__acquired=0;
u64 __T8__len_y=0;
nominal name____c=0;
u64 __T8____kp=0;
bool __C8____op____iQ=0;
u64 __77____ZQ____VQ=0;
ptr __77____ZQ__acquired=0;
u64 __B8__len_x=0;
bool __T8____op____nQ__z=0;
cstr __N8____hh____kQ=0;
ptr __C8____ep__noptr=0;
char __B8____fh=0;
u64 __77____ZQ____UQ=0;
u64 __77__size=0;
u64 __77__allocated=0;
nominal __77____TQ=0;
cstr __97=0;
u64 __F8____ZQ____UQ=0;
u64 __C8__total_len=0;
u64 __N8____hh____wQ__bytesize=0;
ptr __B8____ch__contents=0;
ptr __B8____ch____u__contents=0;
u64 __B8__len_y=0;
u64 __B8__total_len=0;
u64 __S8__total_len=0;
char __B8__first=0;
bool __C8____op____jQ__z=0;
u64 __B8____dh=0;
bool __S8____hh____jQ__z=0;
u64 __C8____op__next_size=0;
bool __B8____hh____jQ__z=0;
ptr __B8____hh__next_acquired=0;
bool __N8____hh____nQ__x=0;
u64 __C8____lp__z=0;
cstr __B8____hh____kQ=0;
ptr command__memory=0;
bool __B8____hh__success=0;
bool __T8____op____iQ=0;
u64 __B8____hh__self__allocated__prev=0;
u64 __N8__len_x=0;
ptr __N8____ch__contents=0;
ptr __B8____hh__mem=0;
bool __C8____op____nQ__z=0;
bool __B8____hh____nQ__z=0;
cstr __B8____hh____oQ=0;
u64 __B8____hh____wQ__bytesize=0;
nominal __B8____hh__self____TQ=0;
ptr __C8____ep__contents=0;
char __C8__first=0;
u64 __77____dynamic_entry=0;
u64 __C8____kp=0;
cstr __O8____op____kQ=0;
ptr __C8____op__mem=0;
ptr __S8____hh__mem=0;
u64 __77____ZQ____dynamic_entry=0;
cstr __C8____op____kQ=0;
bool __C8____op__success=0;
u64 __C8____op__self__allocated__prev=0;
ptr __C8____op__next_acquired=0;
char __C8____op____gQ=0;
u64 __S8____hh____wQ__bytesize=0;
u64 __F8__size=0;
bool __C8____op____nQ__x=0;
ptr __T8____op__next_acquired=0;
ptr __N8____ch____u__contents=0;
char __C8____op____uQ=0;
char __T8____op____gQ=0;
nominal command____c=0;
nominal __C8____op__self____TQ=0;
u64 __F8____ZQ____VQ=0;

// IMPLEMENTATION
__77____ZQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __77____ZQ__acquired )(( ptr **) __77____ZQ__acquired )[0]=0; 
 __77____ZQ____UQ = 0 ;
 __77____ZQ____VQ = 0 ;
 __77__acquired = __77____ZQ__acquired ;
 __77__size = __77____ZQ____UQ ;
 __77__allocated = __77____ZQ____VQ ;
 __77____dynamic_entry = __77____ZQ____dynamic_entry ;
 __97 = "./smol tests/unit/" ;
 __A8 = ".s --workers 1 --runtime eager 2>&1" ;
 __B8____ch__length = strlen ( __A8 ); __B8____ch__contents =( ptr ) __A8 ; __B8____ch__first = __A8 [0]; __B8____ch__noptr =( ptr ) __B8____ch__noptr ; 
 __B8____ch____u__contents = __B8____ch__contents ;
 __B8__len_x = name__length ; __B8__len_y = __B8____ch__length ; __B8__total_len = __B8__len_x + __B8__len_y ; __B8__first = name__length ? name__first : __B8____ch__first ; 
 __B8____dh = 1 ;
 __B8____eh__z = __B8__total_len + __B8____dh ; 
 __B8____eh____end :
 __B8____fh = 0 ;
 __B8____hh____iQ = __77__acquired ;
 __B8____hh____jQ__z =(! __B8____hh____iQ ); 
 __B8____hh____jQ____end :
 if(! __B8____hh____jQ__z )goto __B8____hh____hQ__fi ;
 __B8____hh____kQ = "Did not initialize Dynamic" ;
 goto __B8____hh____lQ____7D ;
 __builtin_unreachable();
 __B8____hh____hQ__fi :
 __B8____hh__next_size = __77__size +1; __B8____hh__success = true ; __B8____hh__self__allocated__prev = __77__allocated ; if ( __B8____hh__next_size >= __77__allocated ) { __77__allocated = __77__allocated + __77__allocated /2+1; __B8____hh__next_acquired =( ptr )((( ptr **) __77__acquired )[0]? __runtime_realloc ((( ptr **) __77__acquired )[0], __77__allocated * sizeof ( ptr ), __B8____hh__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __77__allocated * sizeof ( ptr ))); if ( __B8____hh__success = __B8____hh__next_acquired )(( ptr **) __77__acquired )[0]=( ptr *) __B8____hh__next_acquired ; } if ( __B8____hh__success ) { __B8____hh__mem =( ptr ) __runtime_alloc ( __B8____eh__z * sizeof ( __B8____hh____gQ )); if ( __B8____hh__success = __B8____hh__mem ) {(( ptr **) __77__acquired )[0][ __77__size ]= __B8____hh__mem ; __77__size = __B8____hh__next_size ; } } 
 __B8____hh____nQ__x = __B8____hh__success ;
 __B8____hh____nQ__z =(! __B8____hh____nQ__x ); 
 __B8____hh____nQ____end :
 if(! __B8____hh____nQ__z )goto __B8____hh____mQ__fi ;
 __B8____hh____oQ = "Failed a Dynamic allocation" ;
 goto __B8____hh____pQ____7D ;
 __builtin_unreachable();
 __B8____hh____mQ__fi :
 __B8____hh____uQ = 0 ;
 __B8____hh____wQ__bytesize = sizeof ( __B8____hh____wQ____dE )* __B8____eh__z ; 
 __B8____hh____wQ____end :
 memcpy (( char *) __B8____hh__mem ,( char *) name__contents , __B8__len_x ); memcpy (( char *) __B8____hh__mem + __B8__len_x ,( char *) __B8____ch____u__contents , __B8__len_y );(( char *) __B8____hh__mem )[ __B8__total_len ]=0; 
 __B8____nh__contents = __B8____hh__mem ;
 __77____TQ = __B8____hh__self____TQ ;
 __77__acquired = __77__acquired ;
 __77__size = __77__size ;
 __77__allocated = __77__allocated ;
 __77____dynamic_entry = __77____dynamic_entry ;
 __C8____ep__length = strlen ( __97 ); __C8____ep__contents =( ptr ) __97 ; __C8____ep__first = __97 [0]; __C8____ep__noptr =( ptr ) __C8____ep__noptr ; 
 __C8____ep____u__contents = __C8____ep__contents ;
 __C8__len_x = __C8____ep__length ; __C8__len_y = __B8__total_len ; __C8__total_len = __C8__len_x + __C8__len_y ; __C8__first = __C8____ep__length ? __C8____ep__first : __B8__first ; 
 __C8____kp = 1 ;
 __C8____lp__z = __C8__total_len + __C8____kp ; 
 __C8____lp____end :
 __C8____mp = 0 ;
 __C8____op____iQ = __77__acquired ;
 __C8____op____jQ__z =(! __C8____op____iQ ); 
 __C8____op____jQ____end :
 if(! __C8____op____jQ__z )goto __C8____op____hQ__fi ;
 __C8____op____kQ = "Did not initialize Dynamic" ;
 goto __C8____op____lQ____7D ;
 __builtin_unreachable();
 __C8____op____hQ__fi :
 __C8____op__next_size = __77__size +1; __C8____op__success = true ; __C8____op__self__allocated__prev = __77__allocated ; if ( __C8____op__next_size >= __77__allocated ) { __77__allocated = __77__allocated + __77__allocated /2+1; __C8____op__next_acquired =( ptr )((( ptr **) __77__acquired )[0]? __runtime_realloc ((( ptr **) __77__acquired )[0], __77__allocated * sizeof ( ptr ), __C8____op__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __77__allocated * sizeof ( ptr ))); if ( __C8____op__success = __C8____op__next_acquired )(( ptr **) __77__acquired )[0]=( ptr *) __C8____op__next_acquired ; } if ( __C8____op__success ) { __C8____op__mem =( ptr ) __runtime_alloc ( __C8____lp__z * sizeof ( __C8____op____gQ )); if ( __C8____op__success = __C8____op__mem ) {(( ptr **) __77__acquired )[0][ __77__size ]= __C8____op__mem ; __77__size = __C8____op__next_size ; } } 
 __C8____op____nQ__x = __C8____op__success ;
 __C8____op____nQ__z =(! __C8____op____nQ__x ); 
 __C8____op____nQ____end :
 if(! __C8____op____nQ__z )goto __C8____op____mQ__fi ;
 __C8____op____oQ = "Failed a Dynamic allocation" ;
 goto __C8____op____pQ____7D ;
 __builtin_unreachable();
 __C8____op____mQ__fi :
 __C8____op____uQ = 0 ;
 __C8____op____wQ__bytesize = sizeof ( __C8____op____wQ____dE )* __C8____lp__z ; 
 __C8____op____wQ____end :
 memcpy (( char *) __C8____op__mem ,( char *) __C8____ep____u__contents , __C8__len_x ); memcpy (( char *) __C8____op__mem + __C8__len_x ,( char *) __B8____nh__contents , __C8__len_y );(( char *) __C8____op__mem )[ __C8__total_len ]=0; 
 __C8____vp__contents = __C8____op__mem ;
 __77____TQ = __C8____op__self____TQ ;
 __77__acquired = __77__acquired ;
 __77__size = __77__size ;
 __77__allocated = __77__allocated ;
 __77____dynamic_entry = __77____dynamic_entry ;
 __F8____ZQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __F8____ZQ__acquired )(( ptr **) __F8____ZQ__acquired )[0]=0; 
 __F8____ZQ____UQ = 0 ;
 __F8____ZQ____VQ = 0 ;
 __F8__acquired = __F8____ZQ__acquired ;
 __F8__size = __F8____ZQ____UQ ;
 __F8__allocated = __F8____ZQ____VQ ;
 __F8____dynamic_entry = __F8____ZQ____dynamic_entry ;
 __I8____state = (struct run__816__state*)__runtime_calloc(sizeof(struct run__816__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __I8____state ) ;
 __I8____state -> command____c = command____c ;
 __I8____state -> command__contents = __C8____vp__contents ;
 __I8____state -> command__length = __C8__total_len ;
 __I8____state -> command__first = __C8__first ;
 __I8____state -> command__memory = __77__acquired ;
 __I8____task = __smolambda_add_task ( run__816 , __I8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __I8____task ) ;
 if( __I8__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __I8____task ) ;
 __I8__err = __I8____state -> err ;
 __K8 = __I8__err ;
 if(! __K8 )goto __H8__fi ;
 __L8 = "[ \033[31mERROR\033[0m ] " ;
 __M8 = ".s" ;
 __N8____ch__length = strlen ( __M8 ); __N8____ch__contents =( ptr ) __M8 ; __N8____ch__first = __M8 [0]; __N8____ch__noptr =( ptr ) __N8____ch__noptr ; 
 __N8____ch____u__contents = __N8____ch__contents ;
 __N8__len_x = name__length ; __N8__len_y = __N8____ch__length ; __N8__total_len = __N8__len_x + __N8__len_y ; __N8__first = name__length ? name__first : __N8____ch__first ; 
 __N8____dh = 1 ;
 __N8____eh__z = __N8__total_len + __N8____dh ; 
 __N8____eh____end :
 __N8____fh = 0 ;
 __N8____hh____iQ = __F8__acquired ;
 __N8____hh____jQ__z =(! __N8____hh____iQ ); 
 __N8____hh____jQ____end :
 if(! __N8____hh____jQ__z )goto __N8____hh____hQ__fi ;
 __N8____hh____kQ = "Did not initialize Dynamic" ;
 goto __N8____hh____lQ____7D ;
 __builtin_unreachable();
 __N8____hh____hQ__fi :
 __N8____hh__next_size = __F8__size +1; __N8____hh__success = true ; __N8____hh__self__allocated__prev = __F8__allocated ; if ( __N8____hh__next_size >= __F8__allocated ) { __F8__allocated = __F8__allocated + __F8__allocated /2+1; __N8____hh__next_acquired =( ptr )((( ptr **) __F8__acquired )[0]? __runtime_realloc ((( ptr **) __F8__acquired )[0], __F8__allocated * sizeof ( ptr ), __N8____hh__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __F8__allocated * sizeof ( ptr ))); if ( __N8____hh__success = __N8____hh__next_acquired )(( ptr **) __F8__acquired )[0]=( ptr *) __N8____hh__next_acquired ; } if ( __N8____hh__success ) { __N8____hh__mem =( ptr ) __runtime_alloc ( __N8____eh__z * sizeof ( __N8____hh____gQ )); if ( __N8____hh__success = __N8____hh__mem ) {(( ptr **) __F8__acquired )[0][ __F8__size ]= __N8____hh__mem ; __F8__size = __N8____hh__next_size ; } } 
 __N8____hh____nQ__x = __N8____hh__success ;
 __N8____hh____nQ__z =(! __N8____hh____nQ__x ); 
 __N8____hh____nQ____end :
 if(! __N8____hh____nQ__z )goto __N8____hh____mQ__fi ;
 __N8____hh____oQ = "Failed a Dynamic allocation" ;
 goto __N8____hh____pQ____7D ;
 __builtin_unreachable();
 __N8____hh____mQ__fi :
 __N8____hh____uQ = 0 ;
 __N8____hh____wQ__bytesize = sizeof ( __N8____hh____wQ____dE )* __N8____eh__z ; 
 __N8____hh____wQ____end :
 memcpy (( char *) __N8____hh__mem ,( char *) name__contents , __N8__len_x ); memcpy (( char *) __N8____hh__mem + __N8__len_x ,( char *) __N8____ch____u__contents , __N8__len_y );(( char *) __N8____hh__mem )[ __N8__total_len ]=0; 
 __N8____nh__contents = __N8____hh__mem ;
 __F8____TQ = __N8____hh__self____TQ ;
 __F8__acquired = __F8__acquired ;
 __F8__size = __F8__size ;
 __F8__allocated = __F8__allocated ;
 __F8____dynamic_entry = __F8____dynamic_entry ;
 __O8____ep__length = strlen ( __L8 ); __O8____ep__contents =( ptr ) __L8 ; __O8____ep__first = __L8 [0]; __O8____ep__noptr =( ptr ) __O8____ep__noptr ; 
 __O8____ep____u__contents = __O8____ep__contents ;
 __O8__len_x = __O8____ep__length ; __O8__len_y = __N8__total_len ; __O8__total_len = __O8__len_x + __O8__len_y ; __O8__first = __O8____ep__length ? __O8____ep__first : __N8__first ; 
 __O8____kp = 1 ;
 __O8____lp__z = __O8__total_len + __O8____kp ; 
 __O8____lp____end :
 __O8____mp = 0 ;
 __O8____op____iQ = __F8__acquired ;
 __O8____op____jQ__z =(! __O8____op____iQ ); 
 __O8____op____jQ____end :
 if(! __O8____op____jQ__z )goto __O8____op____hQ__fi ;
 __O8____op____kQ = "Did not initialize Dynamic" ;
 goto __O8____op____lQ____7D ;
 __builtin_unreachable();
 __O8____op____hQ__fi :
 __O8____op__next_size = __F8__size +1; __O8____op__success = true ; __O8____op__self__allocated__prev = __F8__allocated ; if ( __O8____op__next_size >= __F8__allocated ) { __F8__allocated = __F8__allocated + __F8__allocated /2+1; __O8____op__next_acquired =( ptr )((( ptr **) __F8__acquired )[0]? __runtime_realloc ((( ptr **) __F8__acquired )[0], __F8__allocated * sizeof ( ptr ), __O8____op__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __F8__allocated * sizeof ( ptr ))); if ( __O8____op__success = __O8____op__next_acquired )(( ptr **) __F8__acquired )[0]=( ptr *) __O8____op__next_acquired ; } if ( __O8____op__success ) { __O8____op__mem =( ptr ) __runtime_alloc ( __O8____lp__z * sizeof ( __O8____op____gQ )); if ( __O8____op__success = __O8____op__mem ) {(( ptr **) __F8__acquired )[0][ __F8__size ]= __O8____op__mem ; __F8__size = __O8____op__next_size ; } } 
 __O8____op____nQ__x = __O8____op__success ;
 __O8____op____nQ__z =(! __O8____op____nQ__x ); 
 __O8____op____nQ____end :
 if(! __O8____op____nQ__z )goto __O8____op____mQ__fi ;
 __O8____op____oQ = "Failed a Dynamic allocation" ;
 goto __O8____op____pQ____7D ;
 __builtin_unreachable();
 __O8____op____mQ__fi :
 __O8____op____uQ = 0 ;
 __O8____op____wQ__bytesize = sizeof ( __O8____op____wQ____dE )* __O8____lp__z ; 
 __O8____op____wQ____end :
 memcpy (( char *) __O8____op__mem ,( char *) __O8____ep____u__contents , __O8__len_x ); memcpy (( char *) __O8____op__mem + __O8__len_x ,( char *) __N8____nh__contents , __O8__len_y );(( char *) __O8____op__mem )[ __O8__total_len ]=0; 
 __O8____vp__contents = __O8____op__mem ;
 __F8____TQ = __O8____op__self____TQ ;
 __F8__acquired = __F8__acquired ;
 __F8__size = __F8__size ;
 __F8__allocated = __F8__allocated ;
 __F8____dynamic_entry = __F8____dynamic_entry ;
 printf ( "%s\n" ,( char *) __O8____vp__contents ); 
 __P8____end :
 goto __H8__el ;
 __H8__fi :
 __Q8 = "[ \033[32mOK\033[0m ] " ;
 __R8 = ".s" ;
 __S8____ch__length = strlen ( __R8 ); __S8____ch__contents =( ptr ) __R8 ; __S8____ch__first = __R8 [0]; __S8____ch__noptr =( ptr ) __S8____ch__noptr ; 
 __S8____ch____u__contents = __S8____ch__contents ;
 __S8__len_x = name__length ; __S8__len_y = __S8____ch__length ; __S8__total_len = __S8__len_x + __S8__len_y ; __S8__first = name__length ? name__first : __S8____ch__first ; 
 __S8____dh = 1 ;
 __S8____eh__z = __S8__total_len + __S8____dh ; 
 __S8____eh____end :
 __S8____fh = 0 ;
 __S8____hh____iQ = __F8__acquired ;
 __S8____hh____jQ__z =(! __S8____hh____iQ ); 
 __S8____hh____jQ____end :
 if(! __S8____hh____jQ__z )goto __S8____hh____hQ__fi ;
 __S8____hh____kQ = "Did not initialize Dynamic" ;
 goto __S8____hh____lQ____7D ;
 __builtin_unreachable();
 __S8____hh____hQ__fi :
 __S8____hh__next_size = __F8__size +1; __S8____hh__success = true ; __S8____hh__self__allocated__prev = __F8__allocated ; if ( __S8____hh__next_size >= __F8__allocated ) { __F8__allocated = __F8__allocated + __F8__allocated /2+1; __S8____hh__next_acquired =( ptr )((( ptr **) __F8__acquired )[0]? __runtime_realloc ((( ptr **) __F8__acquired )[0], __F8__allocated * sizeof ( ptr ), __S8____hh__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __F8__allocated * sizeof ( ptr ))); if ( __S8____hh__success = __S8____hh__next_acquired )(( ptr **) __F8__acquired )[0]=( ptr *) __S8____hh__next_acquired ; } if ( __S8____hh__success ) { __S8____hh__mem =( ptr ) __runtime_alloc ( __S8____eh__z * sizeof ( __S8____hh____gQ )); if ( __S8____hh__success = __S8____hh__mem ) {(( ptr **) __F8__acquired )[0][ __F8__size ]= __S8____hh__mem ; __F8__size = __S8____hh__next_size ; } } 
 __S8____hh____nQ__x = __S8____hh__success ;
 __S8____hh____nQ__z =(! __S8____hh____nQ__x ); 
 __S8____hh____nQ____end :
 if(! __S8____hh____nQ__z )goto __S8____hh____mQ__fi ;
 __S8____hh____oQ = "Failed a Dynamic allocation" ;
 goto __S8____hh____pQ____7D ;
 __builtin_unreachable();
 __S8____hh____mQ__fi :
 __S8____hh____uQ = 0 ;
 __S8____hh____wQ__bytesize = sizeof ( __S8____hh____wQ____dE )* __S8____eh__z ; 
 __S8____hh____wQ____end :
 memcpy (( char *) __S8____hh__mem ,( char *) name__contents , __S8__len_x ); memcpy (( char *) __S8____hh__mem + __S8__len_x ,( char *) __S8____ch____u__contents , __S8__len_y );(( char *) __S8____hh__mem )[ __S8__total_len ]=0; 
 __S8____nh__contents = __S8____hh__mem ;
 __F8____TQ = __S8____hh__self____TQ ;
 __F8__acquired = __F8__acquired ;
 __F8__size = __F8__size ;
 __F8__allocated = __F8__allocated ;
 __F8____dynamic_entry = __F8____dynamic_entry ;
 __T8____ep__length = strlen ( __Q8 ); __T8____ep__contents =( ptr ) __Q8 ; __T8____ep__first = __Q8 [0]; __T8____ep__noptr =( ptr ) __T8____ep__noptr ; 
 __T8____ep____u__contents = __T8____ep__contents ;
 __T8__len_x = __T8____ep__length ; __T8__len_y = __S8__total_len ; __T8__total_len = __T8__len_x + __T8__len_y ; __T8__first = __T8____ep__length ? __T8____ep__first : __S8__first ; 
 __T8____kp = 1 ;
 __T8____lp__z = __T8__total_len + __T8____kp ; 
 __T8____lp____end :
 __T8____mp = 0 ;
 __T8____op____iQ = __F8__acquired ;
 __T8____op____jQ__z =(! __T8____op____iQ ); 
 __T8____op____jQ____end :
 if(! __T8____op____jQ__z )goto __T8____op____hQ__fi ;
 __T8____op____kQ = "Did not initialize Dynamic" ;
 goto __T8____op____lQ____7D ;
 __builtin_unreachable();
 __T8____op____hQ__fi :
 __T8____op__next_size = __F8__size +1; __T8____op__success = true ; __T8____op__self__allocated__prev = __F8__allocated ; if ( __T8____op__next_size >= __F8__allocated ) { __F8__allocated = __F8__allocated + __F8__allocated /2+1; __T8____op__next_acquired =( ptr )((( ptr **) __F8__acquired )[0]? __runtime_realloc ((( ptr **) __F8__acquired )[0], __F8__allocated * sizeof ( ptr ), __T8____op__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __F8__allocated * sizeof ( ptr ))); if ( __T8____op__success = __T8____op__next_acquired )(( ptr **) __F8__acquired )[0]=( ptr *) __T8____op__next_acquired ; } if ( __T8____op__success ) { __T8____op__mem =( ptr ) __runtime_alloc ( __T8____lp__z * sizeof ( __T8____op____gQ )); if ( __T8____op__success = __T8____op__mem ) {(( ptr **) __F8__acquired )[0][ __F8__size ]= __T8____op__mem ; __F8__size = __T8____op__next_size ; } } 
 __T8____op____nQ__x = __T8____op__success ;
 __T8____op____nQ__z =(! __T8____op____nQ__x ); 
 __T8____op____nQ____end :
 if(! __T8____op____nQ__z )goto __T8____op____mQ__fi ;
 __T8____op____oQ = "Failed a Dynamic allocation" ;
 goto __T8____op____pQ____7D ;
 __builtin_unreachable();
 __T8____op____mQ__fi :
 __T8____op____uQ = 0 ;
 __T8____op____wQ__bytesize = sizeof ( __T8____op____wQ____dE )* __T8____lp__z ; 
 __T8____op____wQ____end :
 memcpy (( char *) __T8____op__mem ,( char *) __T8____ep____u__contents , __T8__len_x ); memcpy (( char *) __T8____op__mem + __T8__len_x ,( char *) __S8____nh__contents , __T8__len_y );(( char *) __T8____op__mem )[ __T8__total_len ]=0; 
 __T8____vp__contents = __T8____op__mem ;
 __F8____TQ = __T8____op__self____TQ ;
 __F8__acquired = __F8__acquired ;
 __F8__size = __F8__size ;
 __F8__allocated = __F8__allocated ;
 __F8____dynamic_entry = __F8____dynamic_entry ;
 printf ( "%s\n" ,( char *) __T8____vp__contents ); 
 __U8____end :
 __H8__el :
 __end :
goto __return;

// ERROR HANDLING
__N8____hh____pQ____7D :
 printf ( "%s\n" , __N8____hh____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__T8____op____pQ____7D :
 printf ( "%s\n" , __T8____op____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__O8____op____lQ____7D :
 printf ( "%s\n" , __O8____op____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__S8____hh____pQ____7D :
 printf ( "%s\n" , __S8____hh____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__B8____hh____lQ____7D :
 printf ( "%s\n" , __B8____hh____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__S8____hh____lQ____7D :
 printf ( "%s\n" , __S8____hh____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__B8____hh____pQ____7D :
 printf ( "%s\n" , __B8____hh____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__O8____op____pQ____7D :
 printf ( "%s\n" , __O8____op____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__C8____op____lQ____7D :
 printf ( "%s\n" , __C8____op____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__C8____op____pQ____7D :
 printf ( "%s\n" , __C8____op____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__N8____hh____lQ____7D :
 printf ( "%s\n" , __N8____hh____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__T8____op____lQ____7D :
 printf ( "%s\n" , __T8____op____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__J8 :
printf("Runtime error from run __I8 \n");
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
if ( __F8__acquired ) { for ( __F8____dynamic_entry =0; __F8____dynamic_entry < __F8__size ;++ __F8____dynamic_entry ) { __runtime_free ((( ptr **) __F8__acquired )[0][ __F8____dynamic_entry ]); } __runtime_free ( __F8__acquired ); __F8__acquired =0; __F8__size =0; __F8__allocated =0; } 
 if ( __F8__acquired ) { for ( __F8____ZQ____dynamic_entry =0; __F8____ZQ____dynamic_entry < __F8____ZQ____UQ ;++ __F8____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __F8__acquired )[0][ __F8____ZQ____dynamic_entry ]); } __runtime_free ( __F8__acquired ); __F8__acquired =0; __F8____ZQ____UQ =0; __F8____ZQ____VQ =0; } 
if ( __77__acquired ) { for ( __77____dynamic_entry =0; __77____dynamic_entry < __77__size ;++ __77____dynamic_entry ) { __runtime_free ((( ptr **) __77__acquired )[0][ __77____dynamic_entry ]); } __runtime_free ( __77__acquired ); __77__acquired =0; __77__size =0; __77__allocated =0; } 
 if ( __77__acquired ) { for ( __77____ZQ____dynamic_entry =0; __77____ZQ____dynamic_entry < __77____ZQ____UQ ;++ __77____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __77__acquired )[0][ __77____ZQ____dynamic_entry ]); } __runtime_free ( __77__acquired ); __77__acquired =0; __77____ZQ____UQ =0; __77____ZQ____VQ =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}


void std_test__819(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__819__state *__state=(struct std_test__819__state*)__void__state;
struct run__816__state* __s7____state = 0 ;
ptr name__contents= __state->name__contents;
u64 name__length= __state->name__length;
char name__first= __state->name__first;
ptr name__memory= __state->name__memory;
ptr __37____vp__contents=0;
u64 __37____op____wQ__bytesize=0;
char __37____op____uQ=0;
cstr __37____op____oQ=0;
char __37____op____gQ=0;
ptr __37____op__mem=0;
u64 __37____op__self__allocated__prev=0;
bool __37____op__success=0;
u64 __37____op__next_size=0;
cstr __37____op____kQ=0;
bool __37____op____jQ__z=0;
bool __37____op____iQ=0;
char __37__first=0;
u64 __37__total_len=0;
u64 __37__len_y=0;
u64 __37__len_x=0;
ptr __37____ep____u__contents=0;
ptr __37____ep__contents=0;
u64 __37____ep__length=0;
nominal __27____wf__self____TQ=0;
ptr __27____2f__contents=0;
u64 __27____wf____wQ__bytesize=0;
char __27____wf____uQ=0;
bool __27____wf____nQ__z=0;
bool __27____wf____nQ__x=0;
char __27____wf____gQ=0;
ptr __27____wf__next_acquired=0;
bool __27____wf__success=0;
cstr __27____wf____kQ=0;
char __27____uf=0;
u64 __27____tf__z=0;
u64 __27____sf=0;
u64 __37____kp=0;
char __27__first=0;
u64 __27__total_len=0;
ptr __37____op__next_acquired=0;
ptr __27____wf__mem=0;
ptr __27____rf____u__contents=0;
char __27____rf__first=0;
ptr __27____rf__contents=0;
u64 __27____rf__length=0;
nominal __y7____op__self____TQ=0;
ptr __y7____vp__contents=0;
u64 __y7____op____wQ__bytesize=0;
cstr __y7____op____oQ=0;
bool __y7____op____nQ__z=0;
char __y7____op____gQ=0;
bool __y7____op__success=0;
cstr __y7____op____kQ=0;
bool __y7____op____jQ__z=0;
char __y7____mp=0;
u64 __y7____lp__z=0;
char __y7__first=0;
u64 __y7__len_x=0;
ptr __y7____ep__noptr=0;
ptr __y7____ep__contents=0;
u64 __y7____ep__length=0;
nominal __x7____wf__self____TQ=0;
u64 __y7__total_len=0;
ptr __x7____2f__contents=0;
u64 __x7____wf____wQ__bytesize=0;
char __x7____wf____uQ=0;
bool __x7____wf____nQ__z=0;
u64 __y7__len_y=0;
bool __x7____wf____nQ__x=0;
ptr __x7____wf__mem=0;
ptr __x7____wf__next_acquired=0;
u64 __x7____wf__self__allocated__prev=0;
u64 __x7____wf__next_size=0;
bool __37____op____nQ__x=0;
bool __x7____wf____jQ__z=0;
u64 __x7____tf__z=0;
char __x7__first=0;
ptr __x7____rf__contents=0;
u64 __x7____rf__length=0;
cstr __w7=0;
u64 __27__len_x=0;
cstr __v7=0;
ptr __37____ep__noptr=0;
u64 __27____wf__next_size=0;
errcode __s7__err=0;
bool __x7____wf____iQ=0;
cstr __m7____op____kQ=0;
u64 __x7____sf=0;
char __m7____op____gQ=0;
bool __m7____op__success=0;
cstr __l7____wf____kQ=0;
cstr __17=0;
ptr __l7____wf__mem=0;
u64 __h7__allocated=0;
bool __m7____op____jQ__z=0;
u64 command__length=0;
char __37____mp=0;
ptr __s7____task=0;
nominal __37____op__self____TQ=0;
char __x7____uf=0;
u64 __x7__len_x=0;
char __x7____wf____gQ=0;
char __37____ep__first=0;
ptr __l7____rf__noptr=0;
ptr __27____rf__noptr=0;
u64 __y7____op__next_size=0;
u64 __h7____ZQ____VQ=0;
cstr __x7____wf____oQ=0;
u64 __p7__allocated=0;
bool __y7____op____nQ__x=0;
char __37____op____wQ____dE=0;
ptr __y7____op__next_acquired=0;
u64 __27____wf__self__allocated__prev=0;
ptr __x7____rf__noptr=0;
bool __27____wf____iQ=0;
u64 __h7____ZQ____UQ=0;
char __l7__first=0;
char __y7____ep__first=0;
char __x7____wf____wQ____dE=0;
char __l7____wf____gQ=0;
ptr __p7__acquired=0;
ptr __y7____ep____u__contents=0;
u64 __l7____rf__length=0;
u64 __m7__len_y=0;
bool __y7____op____iQ=0;
ptr __x7____rf____u__contents=0;
ptr __l7____2f__contents=0;
char __y7____op____uQ=0;
u64 __p7__size=0;
bool __x7____wf__success=0;
nominal name____b=0;
u64 __m7____kp=0;
bool __u7=0;
char __m7__first=0;
ptr command__contents=0;
ptr __y7____op__mem=0;
bool __l7____wf__success=0;
u64 __h7__size=0;
u64 __l7____wf____wQ__bytesize=0;
char __x7____rf__first=0;
nominal __l7____wf__self____TQ=0;
u64 __m7____op__self__allocated__prev=0;
u64 __27__len_y=0;
bool __27____wf____jQ__z=0;
ptr __h7__acquired=0;
cstr __27____wf____oQ=0;
ptr __m7____op__mem=0;
ptr __h7____ZQ__acquired=0;
u64 __h7____dynamic_entry=0;
cstr __j7=0;
cstr __k7=0;
char __l7____rf__first=0;
ptr __l7____rf____u__contents=0;
ptr command__memory=0;
u64 __l7__len_x=0;
bool __l7____wf____jQ__z=0;
u64 __l7__total_len=0;
u64 __x7__total_len=0;
u64 __l7____sf=0;
u64 __l7____tf__z=0;
cstr __m7____op____oQ=0;
char __l7____uf=0;
bool __37____op____nQ__z=0;
u64 __h7____ZQ____dynamic_entry=0;
cstr __l7____wf____oQ=0;
u64 __y7____op__self__allocated__prev=0;
bool __m7____op____nQ__x=0;
u64 __l7____wf__next_size=0;
ptr __l7____rf__contents=0;
u64 __l7____wf__self__allocated__prev=0;
ptr __l7____wf__next_acquired=0;
nominal __p7____TQ=0;
bool __l7____wf____nQ__x=0;
bool __l7____wf____nQ__z=0;
u64 __p7____dynamic_entry=0;
char __27____wf____wQ____dE=0;
char __l7____wf____uQ=0;
char __l7____wf____wQ____dE=0;
nominal __h7____TQ=0;
u64 __m7____ep__length=0;
u64 __37____lp__z=0;
ptr __m7____ep__contents=0;
char __m7____ep__first=0;
ptr __m7____ep__noptr=0;
cstr __07=0;
bool __l7____wf____iQ=0;
ptr __m7____ep____u__contents=0;
u64 __m7__len_x=0;
u64 __p7____ZQ____UQ=0;
u64 __m7__total_len=0;
bool __m7____op____nQ__z=0;
u64 __m7____lp__z=0;
char __m7____mp=0;
bool __m7____op____iQ=0;
char __y7____op____wQ____dE=0;
u64 __m7____op__next_size=0;
u64 __y7____kp=0;
ptr __m7____op__next_acquired=0;
u64 __x7__len_y=0;
char __m7____op____uQ=0;
u64 __m7____op____wQ__bytesize=0;
ptr __m7____vp__contents=0;
char __m7____op____wQ____dE=0;
nominal __m7____op__self____TQ=0;
cstr __x7____wf____kQ=0;
ptr __p7____ZQ__acquired=0;
u64 __p7____ZQ____VQ=0;
u64 __p7____ZQ____dynamic_entry=0;
nominal command____c=0;
u64 __l7__len_y=0;
char command__first=0;

// IMPLEMENTATION
__h7____ZQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __h7____ZQ__acquired )(( ptr **) __h7____ZQ__acquired )[0]=0; 
 __h7____ZQ____UQ = 0 ;
 __h7____ZQ____VQ = 0 ;
 __h7__acquired = __h7____ZQ__acquired ;
 __h7__size = __h7____ZQ____UQ ;
 __h7__allocated = __h7____ZQ____VQ ;
 __h7____dynamic_entry = __h7____ZQ____dynamic_entry ;
 __j7 = "./smol tests/unit/" ;
 __k7 = ".s --workers 1 --runtime eager 2>&1" ;
 __l7____rf__length = strlen ( __k7 ); __l7____rf__contents =( ptr ) __k7 ; __l7____rf__first = __k7 [0]; __l7____rf__noptr =( ptr ) __l7____rf__noptr ; 
 __l7____rf____u__contents = __l7____rf__contents ;
 __l7__len_x = name__length ; __l7__len_y = __l7____rf__length ; __l7__total_len = __l7__len_x + __l7__len_y ; __l7__first = name__length ? name__first : __l7____rf__first ; 
 __l7____sf = 1 ;
 __l7____tf__z = __l7__total_len + __l7____sf ; 
 __l7____tf____end :
 __l7____uf = 0 ;
 __l7____wf____iQ = __h7__acquired ;
 __l7____wf____jQ__z =(! __l7____wf____iQ ); 
 __l7____wf____jQ____end :
 if(! __l7____wf____jQ__z )goto __l7____wf____hQ__fi ;
 __l7____wf____kQ = "Did not initialize Dynamic" ;
 goto __l7____wf____lQ____7D ;
 __builtin_unreachable();
 __l7____wf____hQ__fi :
 __l7____wf__next_size = __h7__size +1; __l7____wf__success = true ; __l7____wf__self__allocated__prev = __h7__allocated ; if ( __l7____wf__next_size >= __h7__allocated ) { __h7__allocated = __h7__allocated + __h7__allocated /2+1; __l7____wf__next_acquired =( ptr )((( ptr **) __h7__acquired )[0]? __runtime_realloc ((( ptr **) __h7__acquired )[0], __h7__allocated * sizeof ( ptr ), __l7____wf__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __h7__allocated * sizeof ( ptr ))); if ( __l7____wf__success = __l7____wf__next_acquired )(( ptr **) __h7__acquired )[0]=( ptr *) __l7____wf__next_acquired ; } if ( __l7____wf__success ) { __l7____wf__mem =( ptr ) __runtime_alloc ( __l7____tf__z * sizeof ( __l7____wf____gQ )); if ( __l7____wf__success = __l7____wf__mem ) {(( ptr **) __h7__acquired )[0][ __h7__size ]= __l7____wf__mem ; __h7__size = __l7____wf__next_size ; } } 
 __l7____wf____nQ__x = __l7____wf__success ;
 __l7____wf____nQ__z =(! __l7____wf____nQ__x ); 
 __l7____wf____nQ____end :
 if(! __l7____wf____nQ__z )goto __l7____wf____mQ__fi ;
 __l7____wf____oQ = "Failed a Dynamic allocation" ;
 goto __l7____wf____pQ____7D ;
 __builtin_unreachable();
 __l7____wf____mQ__fi :
 __l7____wf____uQ = 0 ;
 __l7____wf____wQ__bytesize = sizeof ( __l7____wf____wQ____dE )* __l7____tf__z ; 
 __l7____wf____wQ____end :
 memcpy (( char *) __l7____wf__mem ,( char *) name__contents , __l7__len_x ); memcpy (( char *) __l7____wf__mem + __l7__len_x ,( char *) __l7____rf____u__contents , __l7__len_y );(( char *) __l7____wf__mem )[ __l7__total_len ]=0; 
 __l7____2f__contents = __l7____wf__mem ;
 __h7____TQ = __l7____wf__self____TQ ;
 __h7__acquired = __h7__acquired ;
 __h7__size = __h7__size ;
 __h7__allocated = __h7__allocated ;
 __h7____dynamic_entry = __h7____dynamic_entry ;
 __m7____ep__length = strlen ( __j7 ); __m7____ep__contents =( ptr ) __j7 ; __m7____ep__first = __j7 [0]; __m7____ep__noptr =( ptr ) __m7____ep__noptr ; 
 __m7____ep____u__contents = __m7____ep__contents ;
 __m7__len_x = __m7____ep__length ; __m7__len_y = __l7__total_len ; __m7__total_len = __m7__len_x + __m7__len_y ; __m7__first = __m7____ep__length ? __m7____ep__first : __l7__first ; 
 __m7____kp = 1 ;
 __m7____lp__z = __m7__total_len + __m7____kp ; 
 __m7____lp____end :
 __m7____mp = 0 ;
 __m7____op____iQ = __h7__acquired ;
 __m7____op____jQ__z =(! __m7____op____iQ ); 
 __m7____op____jQ____end :
 if(! __m7____op____jQ__z )goto __m7____op____hQ__fi ;
 __m7____op____kQ = "Did not initialize Dynamic" ;
 goto __m7____op____lQ____7D ;
 __builtin_unreachable();
 __m7____op____hQ__fi :
 __m7____op__next_size = __h7__size +1; __m7____op__success = true ; __m7____op__self__allocated__prev = __h7__allocated ; if ( __m7____op__next_size >= __h7__allocated ) { __h7__allocated = __h7__allocated + __h7__allocated /2+1; __m7____op__next_acquired =( ptr )((( ptr **) __h7__acquired )[0]? __runtime_realloc ((( ptr **) __h7__acquired )[0], __h7__allocated * sizeof ( ptr ), __m7____op__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __h7__allocated * sizeof ( ptr ))); if ( __m7____op__success = __m7____op__next_acquired )(( ptr **) __h7__acquired )[0]=( ptr *) __m7____op__next_acquired ; } if ( __m7____op__success ) { __m7____op__mem =( ptr ) __runtime_alloc ( __m7____lp__z * sizeof ( __m7____op____gQ )); if ( __m7____op__success = __m7____op__mem ) {(( ptr **) __h7__acquired )[0][ __h7__size ]= __m7____op__mem ; __h7__size = __m7____op__next_size ; } } 
 __m7____op____nQ__x = __m7____op__success ;
 __m7____op____nQ__z =(! __m7____op____nQ__x ); 
 __m7____op____nQ____end :
 if(! __m7____op____nQ__z )goto __m7____op____mQ__fi ;
 __m7____op____oQ = "Failed a Dynamic allocation" ;
 goto __m7____op____pQ____7D ;
 __builtin_unreachable();
 __m7____op____mQ__fi :
 __m7____op____uQ = 0 ;
 __m7____op____wQ__bytesize = sizeof ( __m7____op____wQ____dE )* __m7____lp__z ; 
 __m7____op____wQ____end :
 memcpy (( char *) __m7____op__mem ,( char *) __m7____ep____u__contents , __m7__len_x ); memcpy (( char *) __m7____op__mem + __m7__len_x ,( char *) __l7____2f__contents , __m7__len_y );(( char *) __m7____op__mem )[ __m7__total_len ]=0; 
 __m7____vp__contents = __m7____op__mem ;
 __h7____TQ = __m7____op__self____TQ ;
 __h7__acquired = __h7__acquired ;
 __h7__size = __h7__size ;
 __h7__allocated = __h7__allocated ;
 __h7____dynamic_entry = __h7____dynamic_entry ;
 __p7____ZQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __p7____ZQ__acquired )(( ptr **) __p7____ZQ__acquired )[0]=0; 
 __p7____ZQ____UQ = 0 ;
 __p7____ZQ____VQ = 0 ;
 __p7__acquired = __p7____ZQ__acquired ;
 __p7__size = __p7____ZQ____UQ ;
 __p7__allocated = __p7____ZQ____VQ ;
 __p7____dynamic_entry = __p7____ZQ____dynamic_entry ;
 __s7____state = (struct run__816__state*)__runtime_calloc(sizeof(struct run__816__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __s7____state ) ;
 __s7____state -> command____c = command____c ;
 __s7____state -> command__contents = __m7____vp__contents ;
 __s7____state -> command__length = __m7__total_len ;
 __s7____state -> command__first = __m7__first ;
 __s7____state -> command__memory = __h7__acquired ;
 __s7____task = __smolambda_add_task ( run__816 , __s7____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __s7____task ) ;
 if( __s7__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __s7____task ) ;
 __s7__err = __s7____state -> err ;
 __u7 = __s7__err ;
 if(! __u7 )goto __r7__fi ;
 __v7 = "[ \033[31mERROR\033[0m ] " ;
 __w7 = ".s" ;
 __x7____rf__length = strlen ( __w7 ); __x7____rf__contents =( ptr ) __w7 ; __x7____rf__first = __w7 [0]; __x7____rf__noptr =( ptr ) __x7____rf__noptr ; 
 __x7____rf____u__contents = __x7____rf__contents ;
 __x7__len_x = name__length ; __x7__len_y = __x7____rf__length ; __x7__total_len = __x7__len_x + __x7__len_y ; __x7__first = name__length ? name__first : __x7____rf__first ; 
 __x7____sf = 1 ;
 __x7____tf__z = __x7__total_len + __x7____sf ; 
 __x7____tf____end :
 __x7____uf = 0 ;
 __x7____wf____iQ = __p7__acquired ;
 __x7____wf____jQ__z =(! __x7____wf____iQ ); 
 __x7____wf____jQ____end :
 if(! __x7____wf____jQ__z )goto __x7____wf____hQ__fi ;
 __x7____wf____kQ = "Did not initialize Dynamic" ;
 goto __x7____wf____lQ____7D ;
 __builtin_unreachable();
 __x7____wf____hQ__fi :
 __x7____wf__next_size = __p7__size +1; __x7____wf__success = true ; __x7____wf__self__allocated__prev = __p7__allocated ; if ( __x7____wf__next_size >= __p7__allocated ) { __p7__allocated = __p7__allocated + __p7__allocated /2+1; __x7____wf__next_acquired =( ptr )((( ptr **) __p7__acquired )[0]? __runtime_realloc ((( ptr **) __p7__acquired )[0], __p7__allocated * sizeof ( ptr ), __x7____wf__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __p7__allocated * sizeof ( ptr ))); if ( __x7____wf__success = __x7____wf__next_acquired )(( ptr **) __p7__acquired )[0]=( ptr *) __x7____wf__next_acquired ; } if ( __x7____wf__success ) { __x7____wf__mem =( ptr ) __runtime_alloc ( __x7____tf__z * sizeof ( __x7____wf____gQ )); if ( __x7____wf__success = __x7____wf__mem ) {(( ptr **) __p7__acquired )[0][ __p7__size ]= __x7____wf__mem ; __p7__size = __x7____wf__next_size ; } } 
 __x7____wf____nQ__x = __x7____wf__success ;
 __x7____wf____nQ__z =(! __x7____wf____nQ__x ); 
 __x7____wf____nQ____end :
 if(! __x7____wf____nQ__z )goto __x7____wf____mQ__fi ;
 __x7____wf____oQ = "Failed a Dynamic allocation" ;
 goto __x7____wf____pQ____7D ;
 __builtin_unreachable();
 __x7____wf____mQ__fi :
 __x7____wf____uQ = 0 ;
 __x7____wf____wQ__bytesize = sizeof ( __x7____wf____wQ____dE )* __x7____tf__z ; 
 __x7____wf____wQ____end :
 memcpy (( char *) __x7____wf__mem ,( char *) name__contents , __x7__len_x ); memcpy (( char *) __x7____wf__mem + __x7__len_x ,( char *) __x7____rf____u__contents , __x7__len_y );(( char *) __x7____wf__mem )[ __x7__total_len ]=0; 
 __x7____2f__contents = __x7____wf__mem ;
 __p7____TQ = __x7____wf__self____TQ ;
 __p7__acquired = __p7__acquired ;
 __p7__size = __p7__size ;
 __p7__allocated = __p7__allocated ;
 __p7____dynamic_entry = __p7____dynamic_entry ;
 __y7____ep__length = strlen ( __v7 ); __y7____ep__contents =( ptr ) __v7 ; __y7____ep__first = __v7 [0]; __y7____ep__noptr =( ptr ) __y7____ep__noptr ; 
 __y7____ep____u__contents = __y7____ep__contents ;
 __y7__len_x = __y7____ep__length ; __y7__len_y = __x7__total_len ; __y7__total_len = __y7__len_x + __y7__len_y ; __y7__first = __y7____ep__length ? __y7____ep__first : __x7__first ; 
 __y7____kp = 1 ;
 __y7____lp__z = __y7__total_len + __y7____kp ; 
 __y7____lp____end :
 __y7____mp = 0 ;
 __y7____op____iQ = __p7__acquired ;
 __y7____op____jQ__z =(! __y7____op____iQ ); 
 __y7____op____jQ____end :
 if(! __y7____op____jQ__z )goto __y7____op____hQ__fi ;
 __y7____op____kQ = "Did not initialize Dynamic" ;
 goto __y7____op____lQ____7D ;
 __builtin_unreachable();
 __y7____op____hQ__fi :
 __y7____op__next_size = __p7__size +1; __y7____op__success = true ; __y7____op__self__allocated__prev = __p7__allocated ; if ( __y7____op__next_size >= __p7__allocated ) { __p7__allocated = __p7__allocated + __p7__allocated /2+1; __y7____op__next_acquired =( ptr )((( ptr **) __p7__acquired )[0]? __runtime_realloc ((( ptr **) __p7__acquired )[0], __p7__allocated * sizeof ( ptr ), __y7____op__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __p7__allocated * sizeof ( ptr ))); if ( __y7____op__success = __y7____op__next_acquired )(( ptr **) __p7__acquired )[0]=( ptr *) __y7____op__next_acquired ; } if ( __y7____op__success ) { __y7____op__mem =( ptr ) __runtime_alloc ( __y7____lp__z * sizeof ( __y7____op____gQ )); if ( __y7____op__success = __y7____op__mem ) {(( ptr **) __p7__acquired )[0][ __p7__size ]= __y7____op__mem ; __p7__size = __y7____op__next_size ; } } 
 __y7____op____nQ__x = __y7____op__success ;
 __y7____op____nQ__z =(! __y7____op____nQ__x ); 
 __y7____op____nQ____end :
 if(! __y7____op____nQ__z )goto __y7____op____mQ__fi ;
 __y7____op____oQ = "Failed a Dynamic allocation" ;
 goto __y7____op____pQ____7D ;
 __builtin_unreachable();
 __y7____op____mQ__fi :
 __y7____op____uQ = 0 ;
 __y7____op____wQ__bytesize = sizeof ( __y7____op____wQ____dE )* __y7____lp__z ; 
 __y7____op____wQ____end :
 memcpy (( char *) __y7____op__mem ,( char *) __y7____ep____u__contents , __y7__len_x ); memcpy (( char *) __y7____op__mem + __y7__len_x ,( char *) __x7____2f__contents , __y7__len_y );(( char *) __y7____op__mem )[ __y7__total_len ]=0; 
 __y7____vp__contents = __y7____op__mem ;
 __p7____TQ = __y7____op__self____TQ ;
 __p7__acquired = __p7__acquired ;
 __p7__size = __p7__size ;
 __p7__allocated = __p7__allocated ;
 __p7____dynamic_entry = __p7____dynamic_entry ;
 printf ( "%s\n" ,( char *) __y7____vp__contents ); 
 __z7____end :
 goto __r7__el ;
 __r7__fi :
 __07 = "[ \033[32mOK\033[0m ] " ;
 __17 = ".s" ;
 __27____rf__length = strlen ( __17 ); __27____rf__contents =( ptr ) __17 ; __27____rf__first = __17 [0]; __27____rf__noptr =( ptr ) __27____rf__noptr ; 
 __27____rf____u__contents = __27____rf__contents ;
 __27__len_x = name__length ; __27__len_y = __27____rf__length ; __27__total_len = __27__len_x + __27__len_y ; __27__first = name__length ? name__first : __27____rf__first ; 
 __27____sf = 1 ;
 __27____tf__z = __27__total_len + __27____sf ; 
 __27____tf____end :
 __27____uf = 0 ;
 __27____wf____iQ = __p7__acquired ;
 __27____wf____jQ__z =(! __27____wf____iQ ); 
 __27____wf____jQ____end :
 if(! __27____wf____jQ__z )goto __27____wf____hQ__fi ;
 __27____wf____kQ = "Did not initialize Dynamic" ;
 goto __27____wf____lQ____7D ;
 __builtin_unreachable();
 __27____wf____hQ__fi :
 __27____wf__next_size = __p7__size +1; __27____wf__success = true ; __27____wf__self__allocated__prev = __p7__allocated ; if ( __27____wf__next_size >= __p7__allocated ) { __p7__allocated = __p7__allocated + __p7__allocated /2+1; __27____wf__next_acquired =( ptr )((( ptr **) __p7__acquired )[0]? __runtime_realloc ((( ptr **) __p7__acquired )[0], __p7__allocated * sizeof ( ptr ), __27____wf__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __p7__allocated * sizeof ( ptr ))); if ( __27____wf__success = __27____wf__next_acquired )(( ptr **) __p7__acquired )[0]=( ptr *) __27____wf__next_acquired ; } if ( __27____wf__success ) { __27____wf__mem =( ptr ) __runtime_alloc ( __27____tf__z * sizeof ( __27____wf____gQ )); if ( __27____wf__success = __27____wf__mem ) {(( ptr **) __p7__acquired )[0][ __p7__size ]= __27____wf__mem ; __p7__size = __27____wf__next_size ; } } 
 __27____wf____nQ__x = __27____wf__success ;
 __27____wf____nQ__z =(! __27____wf____nQ__x ); 
 __27____wf____nQ____end :
 if(! __27____wf____nQ__z )goto __27____wf____mQ__fi ;
 __27____wf____oQ = "Failed a Dynamic allocation" ;
 goto __27____wf____pQ____7D ;
 __builtin_unreachable();
 __27____wf____mQ__fi :
 __27____wf____uQ = 0 ;
 __27____wf____wQ__bytesize = sizeof ( __27____wf____wQ____dE )* __27____tf__z ; 
 __27____wf____wQ____end :
 memcpy (( char *) __27____wf__mem ,( char *) name__contents , __27__len_x ); memcpy (( char *) __27____wf__mem + __27__len_x ,( char *) __27____rf____u__contents , __27__len_y );(( char *) __27____wf__mem )[ __27__total_len ]=0; 
 __27____2f__contents = __27____wf__mem ;
 __p7____TQ = __27____wf__self____TQ ;
 __p7__acquired = __p7__acquired ;
 __p7__size = __p7__size ;
 __p7__allocated = __p7__allocated ;
 __p7____dynamic_entry = __p7____dynamic_entry ;
 __37____ep__length = strlen ( __07 ); __37____ep__contents =( ptr ) __07 ; __37____ep__first = __07 [0]; __37____ep__noptr =( ptr ) __37____ep__noptr ; 
 __37____ep____u__contents = __37____ep__contents ;
 __37__len_x = __37____ep__length ; __37__len_y = __27__total_len ; __37__total_len = __37__len_x + __37__len_y ; __37__first = __37____ep__length ? __37____ep__first : __27__first ; 
 __37____kp = 1 ;
 __37____lp__z = __37__total_len + __37____kp ; 
 __37____lp____end :
 __37____mp = 0 ;
 __37____op____iQ = __p7__acquired ;
 __37____op____jQ__z =(! __37____op____iQ ); 
 __37____op____jQ____end :
 if(! __37____op____jQ__z )goto __37____op____hQ__fi ;
 __37____op____kQ = "Did not initialize Dynamic" ;
 goto __37____op____lQ____7D ;
 __builtin_unreachable();
 __37____op____hQ__fi :
 __37____op__next_size = __p7__size +1; __37____op__success = true ; __37____op__self__allocated__prev = __p7__allocated ; if ( __37____op__next_size >= __p7__allocated ) { __p7__allocated = __p7__allocated + __p7__allocated /2+1; __37____op__next_acquired =( ptr )((( ptr **) __p7__acquired )[0]? __runtime_realloc ((( ptr **) __p7__acquired )[0], __p7__allocated * sizeof ( ptr ), __37____op__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __p7__allocated * sizeof ( ptr ))); if ( __37____op__success = __37____op__next_acquired )(( ptr **) __p7__acquired )[0]=( ptr *) __37____op__next_acquired ; } if ( __37____op__success ) { __37____op__mem =( ptr ) __runtime_alloc ( __37____lp__z * sizeof ( __37____op____gQ )); if ( __37____op__success = __37____op__mem ) {(( ptr **) __p7__acquired )[0][ __p7__size ]= __37____op__mem ; __p7__size = __37____op__next_size ; } } 
 __37____op____nQ__x = __37____op__success ;
 __37____op____nQ__z =(! __37____op____nQ__x ); 
 __37____op____nQ____end :
 if(! __37____op____nQ__z )goto __37____op____mQ__fi ;
 __37____op____oQ = "Failed a Dynamic allocation" ;
 goto __37____op____pQ____7D ;
 __builtin_unreachable();
 __37____op____mQ__fi :
 __37____op____uQ = 0 ;
 __37____op____wQ__bytesize = sizeof ( __37____op____wQ____dE )* __37____lp__z ; 
 __37____op____wQ____end :
 memcpy (( char *) __37____op__mem ,( char *) __37____ep____u__contents , __37__len_x ); memcpy (( char *) __37____op__mem + __37__len_x ,( char *) __27____2f__contents , __37__len_y );(( char *) __37____op__mem )[ __37__total_len ]=0; 
 __37____vp__contents = __37____op__mem ;
 __p7____TQ = __37____op__self____TQ ;
 __p7__acquired = __p7__acquired ;
 __p7__size = __p7__size ;
 __p7__allocated = __p7__allocated ;
 __p7____dynamic_entry = __p7____dynamic_entry ;
 printf ( "%s\n" ,( char *) __37____vp__contents ); 
 __47____end :
 __r7__el :
 __end :
goto __return;

// ERROR HANDLING
__37____op____lQ____7D :
 printf ( "%s\n" , __37____op____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__37____op____pQ____7D :
 printf ( "%s\n" , __37____op____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__m7____op____lQ____7D :
 printf ( "%s\n" , __m7____op____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__l7____wf____lQ____7D :
 printf ( "%s\n" , __l7____wf____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__27____wf____pQ____7D :
 printf ( "%s\n" , __27____wf____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__y7____op____lQ____7D :
 printf ( "%s\n" , __y7____op____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__l7____wf____pQ____7D :
 printf ( "%s\n" , __l7____wf____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__t7 :
printf("Runtime error from run __s7 \n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
__x7____wf____lQ____7D :
 printf ( "%s\n" , __x7____wf____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__x7____wf____pQ____7D :
 printf ( "%s\n" , __x7____wf____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__m7____op____pQ____7D :
 printf ( "%s\n" , __m7____op____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__y7____op____pQ____7D :
 printf ( "%s\n" , __y7____op____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__27____wf____lQ____7D :
 printf ( "%s\n" , __27____wf____kQ ); 
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
if ( __p7__acquired ) { for ( __p7____dynamic_entry =0; __p7____dynamic_entry < __p7__size ;++ __p7____dynamic_entry ) { __runtime_free ((( ptr **) __p7__acquired )[0][ __p7____dynamic_entry ]); } __runtime_free ( __p7__acquired ); __p7__acquired =0; __p7__size =0; __p7__allocated =0; } 
 if ( __p7__acquired ) { for ( __p7____ZQ____dynamic_entry =0; __p7____ZQ____dynamic_entry < __p7____ZQ____UQ ;++ __p7____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __p7__acquired )[0][ __p7____ZQ____dynamic_entry ]); } __runtime_free ( __p7__acquired ); __p7__acquired =0; __p7____ZQ____UQ =0; __p7____ZQ____VQ =0; } 
if ( __h7__acquired ) { for ( __h7____dynamic_entry =0; __h7____dynamic_entry < __h7__size ;++ __h7____dynamic_entry ) { __runtime_free ((( ptr **) __h7__acquired )[0][ __h7____dynamic_entry ]); } __runtime_free ( __h7__acquired ); __h7__acquired =0; __h7__size =0; __h7__allocated =0; } 
 if ( __h7__acquired ) { for ( __h7____ZQ____dynamic_entry =0; __h7____ZQ____dynamic_entry < __h7____ZQ____UQ ;++ __h7____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __h7__acquired )[0][ __h7____ZQ____dynamic_entry ]); } __runtime_free ( __h7__acquired ); __h7__acquired =0; __h7____ZQ____UQ =0; __h7____ZQ____VQ =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}


void std_test__818(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__818__state *__state=(struct std_test__818__state*)__void__state;
struct run__816__state* __S7____state = 0 ;
cstr name= __state->name;
char __d7____op____wQ____dE=0;
char __d7____op____uQ=0;
ptr __d7____op__mem=0;
ptr __d7____op__next_acquired=0;
cstr __d7____op____kQ=0;
bool __d7____op____jQ__z=0;
char __d7____mp=0;
u64 __d7__total_len=0;
u64 __d7__len_x=0;
char __d7____ep__first=0;
ptr __d7____ep__contents=0;
u64 __d7____ep__length=0;
char __c7____Be____gQ=0;
ptr __c7____Be__next_acquired=0;
bool __c7____Be__success=0;
u64 __c7____Be__next_size=0;
bool __c7____Be____jQ__z=0;
char __c7____9d=0;
ptr __d7____ep__noptr=0;
char __c7__first=0;
u64 __c7__total_len=0;
u64 __c7__len_x=0;
u64 __c7____6d__length=0;
ptr __c7____5d____u__contents=0;
ptr __c7____5d__noptr=0;
ptr __c7____5d__contents=0;
cstr __b7=0;
ptr __Y7____vp__contents=0;
u64 __d7____op____wQ__bytesize=0;
char __Y7____op____uQ=0;
cstr __Y7____op____oQ=0;
char __Y7____op____gQ=0;
ptr __Y7____op__mem=0;
ptr __Y7____op__next_acquired=0;
u64 __c7____Be__self__allocated__prev=0;
bool __Y7____op____jQ__z=0;
ptr __c7____6d____u__contents=0;
char __Y7____op____wQ____dE=0;
bool __Y7____op____iQ=0;
u64 __Y7____kp=0;
char __Y7__first=0;
u64 __Y7__len_x=0;
ptr __Y7____ep____u__contents=0;
ptr __Y7____ep__noptr=0;
char __Y7____ep__first=0;
ptr __Y7____ep__contents=0;
u64 __Y7____ep__length=0;
cstr __X7____Be____oQ=0;
bool __X7____Be____nQ__z=0;
bool __X7____Be____nQ__x=0;
bool __X7____Be__success=0;
u64 __X7____Be__next_size=0;
u64 __c7____8d__z=0;
bool __X7____Be____jQ__z=0;
bool __X7____Be____iQ=0;
char __X7____9d=0;
u64 __X7____8d__z=0;
u64 __X7__total_len=0;
nominal __P7____TQ=0;
u64 __X7__len_x=0;
ptr __X7____6d__noptr=0;
char __X7____6d__first=0;
ptr __X7____6d__contents=0;
u64 __X7____6d__length=0;
char __X7____Be____uQ=0;
ptr __X7____5d____u__contents=0;
ptr __c7____6d__contents=0;
ptr __X7____5d__noptr=0;
char __c7____Be____uQ=0;
ptr __X7____5d__contents=0;
cstr __W7=0;
ptr __S7____task=0;
u64 __L7____5d__length=0;
u64 __d7____kp=0;
u64 __X7__len_y=0;
u64 __L7____Be__self__allocated__prev=0;
ptr __M7____ep__contents=0;
bool __c7____Be____nQ__x=0;
u64 __M7____ep__length=0;
u64 __c7____7d=0;
char __L7____5d__first=0;
u64 __Y7__total_len=0;
cstr __V7=0;
cstr __J7=0;
char __c7____Be____wQ____dE=0;
nominal __d7____op__self____TQ=0;
bool __d7____op____iQ=0;
ptr __M7____ep____u__contents=0;
cstr __M7____op____kQ=0;
ptr __M7____ep__noptr=0;
u64 __d7__len_y=0;
char __L7____Be____wQ____dE=0;
bool __L7____Be____jQ__z=0;
nominal __c7____Be__self____TQ=0;
char __c7____6d__first=0;
cstr __L7____Be____kQ=0;
u64 __P7____ZQ____dynamic_entry=0;
bool __d7____op__success=0;
nominal __X7____Be__self____TQ=0;
errcode __S7__err=0;
nominal __Y7____op__self____TQ=0;
char __L7__first=0;
u64 __c7____5d__length=0;
ptr __c7____6d__noptr=0;
cstr __a7=0;
bool __d7____op____nQ__x=0;
ptr __X7____Be__mem=0;
u64 __P7____ZQ____VQ=0;
bool __M7____op____nQ__z=0;
ptr __M7____op__mem=0;
ptr __c7____He__contents=0;
u64 __c7____Be____wQ__bytesize=0;
bool __Y7____op____nQ__x=0;
ptr __L7____5d____u__contents=0;
ptr __H7____ZQ__acquired=0;
ptr __c7____Be__mem=0;
ptr __L7____5d__noptr=0;
u64 __d7____op__next_size=0;
char __X7____5d__first=0;
u64 __X7____Be____wQ__bytesize=0;
char __X7____Be____wQ____dE=0;
u64 __X7____Be__self__allocated__prev=0;
bool __L7____Be____nQ__x=0;
cstr __c7____Be____oQ=0;
ptr command__contents=0;
ptr __X7____He__contents=0;
u64 __X7____7d=0;
u64 __M7__total_len=0;
ptr __d7____ep____u__contents=0;
ptr __X7____6d____u__contents=0;
u64 __M7__len_x=0;
u64 __Y7____op__self__allocated__prev=0;
ptr __M7____vp__contents=0;
u64 __P7__size=0;
char __d7____op____gQ=0;
u64 __Y7__len_y=0;
ptr __L7____Be__next_acquired=0;
u64 __d7____lp__z=0;
char __M7____ep__first=0;
nominal __H7____TQ=0;
cstr __X7____Be____kQ=0;
u64 __L7____Be____wQ__bytesize=0;
ptr __L7____5d__contents=0;
bool __c7____Be____iQ=0;
ptr __L7____6d__noptr=0;
ptr __H7__acquired=0;
u64 __Y7____op__next_size=0;
u64 __H7____ZQ____UQ=0;
u64 __H7____ZQ____VQ=0;
u64 command__length=0;
char __X7__first=0;
u64 __H7__size=0;
bool __M7____op____iQ=0;
u64 __H7__allocated=0;
ptr __X7____Be__next_acquired=0;
u64 __H7____ZQ____dynamic_entry=0;
cstr __c7____Be____kQ=0;
u64 __Y7____lp__z=0;
bool __U7=0;
u64 __L7__len_x=0;
u64 __M7____op____wQ__bytesize=0;
cstr __K7=0;
u64 __Y7____op____wQ__bytesize=0;
u64 __L7__len_y=0;
u64 __L7____6d__length=0;
cstr __d7____op____oQ=0;
ptr __L7____6d__contents=0;
char __L7____6d__first=0;
char __d7__first=0;
ptr __L7____6d____u__contents=0;
ptr __L7____He__contents=0;
u64 __X7____5d__length=0;
ptr __P7__acquired=0;
u64 __L7__total_len=0;
u64 __c7__len_y=0;
bool __Y7____op____nQ__z=0;
u64 __L7____8d__z=0;
u64 __L7____7d=0;
cstr __Y7____op____kQ=0;
bool __L7____Be____iQ=0;
char __M7____mp=0;
char __X7____Be____gQ=0;
bool __Y7____op__success=0;
nominal __L7____Be__self____TQ=0;
bool __L7____Be__success=0;
ptr __L7____Be__mem=0;
char __L7____Be____gQ=0;
bool __L7____Be____nQ__z=0;
u64 __L7____Be__next_size=0;
char __L7____Be____uQ=0;
bool __d7____op____nQ__z=0;
char __M7____op____uQ=0;
u64 __M7__len_y=0;
char __c7____5d__first=0;
char __M7__first=0;
char command__first=0;
u64 __M7____kp=0;
u64 __d7____op__self__allocated__prev=0;
u64 __M7____lp__z=0;
bool __c7____Be____nQ__z=0;
bool __M7____op____jQ__z=0;
bool __M7____op__success=0;
u64 __H7____dynamic_entry=0;
u64 __M7____op__self__allocated__prev=0;
ptr __M7____op__next_acquired=0;
char __M7____op____gQ=0;
bool __M7____op____nQ__x=0;
ptr __d7____vp__contents=0;
char __L7____9d=0;
char __Y7____mp=0;
cstr __L7____Be____oQ=0;
cstr __M7____op____oQ=0;
char __M7____op____wQ____dE=0;
nominal __M7____op__self____TQ=0;
u64 __P7____dynamic_entry=0;
ptr __P7____ZQ__acquired=0;
u64 __P7____ZQ____UQ=0;
nominal command____c=0;
u64 __P7__allocated=0;
u64 __M7____op__next_size=0;
ptr command__memory=0;

// IMPLEMENTATION
__H7____ZQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __H7____ZQ__acquired )(( ptr **) __H7____ZQ__acquired )[0]=0; 
 __H7____ZQ____UQ = 0 ;
 __H7____ZQ____VQ = 0 ;
 __H7__acquired = __H7____ZQ__acquired ;
 __H7__size = __H7____ZQ____UQ ;
 __H7__allocated = __H7____ZQ____VQ ;
 __H7____dynamic_entry = __H7____ZQ____dynamic_entry ;
 __J7 = "./smol tests/unit/" ;
 __K7 = ".s --workers 1 --runtime eager 2>&1" ;
 __L7____5d__length = strlen ( name ); __L7____5d__contents =( ptr ) name ; __L7____5d__first = name [0]; __L7____5d__noptr =( ptr ) __L7____5d__noptr ; 
 __L7____5d____u__contents = __L7____5d__contents ;
 __L7____6d__length = strlen ( __K7 ); __L7____6d__contents =( ptr ) __K7 ; __L7____6d__first = __K7 [0]; __L7____6d__noptr =( ptr ) __L7____6d__noptr ; 
 __L7____6d____u__contents = __L7____6d__contents ;
 __L7__len_x = __L7____5d__length ; __L7__len_y = __L7____6d__length ; __L7__total_len = __L7__len_x + __L7__len_y ; __L7__first = __L7____5d__length ? __L7____5d__first : __L7____6d__first ; 
 __L7____7d = 1 ;
 __L7____8d__z = __L7__total_len + __L7____7d ; 
 __L7____8d____end :
 __L7____9d = 0 ;
 __L7____Be____iQ = __H7__acquired ;
 __L7____Be____jQ__z =(! __L7____Be____iQ ); 
 __L7____Be____jQ____end :
 if(! __L7____Be____jQ__z )goto __L7____Be____hQ__fi ;
 __L7____Be____kQ = "Did not initialize Dynamic" ;
 goto __L7____Be____lQ____7D ;
 __builtin_unreachable();
 __L7____Be____hQ__fi :
 __L7____Be__next_size = __H7__size +1; __L7____Be__success = true ; __L7____Be__self__allocated__prev = __H7__allocated ; if ( __L7____Be__next_size >= __H7__allocated ) { __H7__allocated = __H7__allocated + __H7__allocated /2+1; __L7____Be__next_acquired =( ptr )((( ptr **) __H7__acquired )[0]? __runtime_realloc ((( ptr **) __H7__acquired )[0], __H7__allocated * sizeof ( ptr ), __L7____Be__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __H7__allocated * sizeof ( ptr ))); if ( __L7____Be__success = __L7____Be__next_acquired )(( ptr **) __H7__acquired )[0]=( ptr *) __L7____Be__next_acquired ; } if ( __L7____Be__success ) { __L7____Be__mem =( ptr ) __runtime_alloc ( __L7____8d__z * sizeof ( __L7____Be____gQ )); if ( __L7____Be__success = __L7____Be__mem ) {(( ptr **) __H7__acquired )[0][ __H7__size ]= __L7____Be__mem ; __H7__size = __L7____Be__next_size ; } } 
 __L7____Be____nQ__x = __L7____Be__success ;
 __L7____Be____nQ__z =(! __L7____Be____nQ__x ); 
 __L7____Be____nQ____end :
 if(! __L7____Be____nQ__z )goto __L7____Be____mQ__fi ;
 __L7____Be____oQ = "Failed a Dynamic allocation" ;
 goto __L7____Be____pQ____7D ;
 __builtin_unreachable();
 __L7____Be____mQ__fi :
 __L7____Be____uQ = 0 ;
 __L7____Be____wQ__bytesize = sizeof ( __L7____Be____wQ____dE )* __L7____8d__z ; 
 __L7____Be____wQ____end :
 memcpy (( char *) __L7____Be__mem ,( char *) __L7____5d____u__contents , __L7__len_x ); memcpy (( char *) __L7____Be__mem + __L7__len_x ,( char *) __L7____6d____u__contents , __L7__len_y );(( char *) __L7____Be__mem )[ __L7__total_len ]=0; 
 __L7____He__contents = __L7____Be__mem ;
 __H7____TQ = __L7____Be__self____TQ ;
 __H7__acquired = __H7__acquired ;
 __H7__size = __H7__size ;
 __H7__allocated = __H7__allocated ;
 __H7____dynamic_entry = __H7____dynamic_entry ;
 __M7____ep__length = strlen ( __J7 ); __M7____ep__contents =( ptr ) __J7 ; __M7____ep__first = __J7 [0]; __M7____ep__noptr =( ptr ) __M7____ep__noptr ; 
 __M7____ep____u__contents = __M7____ep__contents ;
 __M7__len_x = __M7____ep__length ; __M7__len_y = __L7__total_len ; __M7__total_len = __M7__len_x + __M7__len_y ; __M7__first = __M7____ep__length ? __M7____ep__first : __L7__first ; 
 __M7____kp = 1 ;
 __M7____lp__z = __M7__total_len + __M7____kp ; 
 __M7____lp____end :
 __M7____mp = 0 ;
 __M7____op____iQ = __H7__acquired ;
 __M7____op____jQ__z =(! __M7____op____iQ ); 
 __M7____op____jQ____end :
 if(! __M7____op____jQ__z )goto __M7____op____hQ__fi ;
 __M7____op____kQ = "Did not initialize Dynamic" ;
 goto __M7____op____lQ____7D ;
 __builtin_unreachable();
 __M7____op____hQ__fi :
 __M7____op__next_size = __H7__size +1; __M7____op__success = true ; __M7____op__self__allocated__prev = __H7__allocated ; if ( __M7____op__next_size >= __H7__allocated ) { __H7__allocated = __H7__allocated + __H7__allocated /2+1; __M7____op__next_acquired =( ptr )((( ptr **) __H7__acquired )[0]? __runtime_realloc ((( ptr **) __H7__acquired )[0], __H7__allocated * sizeof ( ptr ), __M7____op__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __H7__allocated * sizeof ( ptr ))); if ( __M7____op__success = __M7____op__next_acquired )(( ptr **) __H7__acquired )[0]=( ptr *) __M7____op__next_acquired ; } if ( __M7____op__success ) { __M7____op__mem =( ptr ) __runtime_alloc ( __M7____lp__z * sizeof ( __M7____op____gQ )); if ( __M7____op__success = __M7____op__mem ) {(( ptr **) __H7__acquired )[0][ __H7__size ]= __M7____op__mem ; __H7__size = __M7____op__next_size ; } } 
 __M7____op____nQ__x = __M7____op__success ;
 __M7____op____nQ__z =(! __M7____op____nQ__x ); 
 __M7____op____nQ____end :
 if(! __M7____op____nQ__z )goto __M7____op____mQ__fi ;
 __M7____op____oQ = "Failed a Dynamic allocation" ;
 goto __M7____op____pQ____7D ;
 __builtin_unreachable();
 __M7____op____mQ__fi :
 __M7____op____uQ = 0 ;
 __M7____op____wQ__bytesize = sizeof ( __M7____op____wQ____dE )* __M7____lp__z ; 
 __M7____op____wQ____end :
 memcpy (( char *) __M7____op__mem ,( char *) __M7____ep____u__contents , __M7__len_x ); memcpy (( char *) __M7____op__mem + __M7__len_x ,( char *) __L7____He__contents , __M7__len_y );(( char *) __M7____op__mem )[ __M7__total_len ]=0; 
 __M7____vp__contents = __M7____op__mem ;
 __H7____TQ = __M7____op__self____TQ ;
 __H7__acquired = __H7__acquired ;
 __H7__size = __H7__size ;
 __H7__allocated = __H7__allocated ;
 __H7____dynamic_entry = __H7____dynamic_entry ;
 __P7____ZQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __P7____ZQ__acquired )(( ptr **) __P7____ZQ__acquired )[0]=0; 
 __P7____ZQ____UQ = 0 ;
 __P7____ZQ____VQ = 0 ;
 __P7__acquired = __P7____ZQ__acquired ;
 __P7__size = __P7____ZQ____UQ ;
 __P7__allocated = __P7____ZQ____VQ ;
 __P7____dynamic_entry = __P7____ZQ____dynamic_entry ;
 __S7____state = (struct run__816__state*)__runtime_calloc(sizeof(struct run__816__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __S7____state ) ;
 __S7____state -> command____c = command____c ;
 __S7____state -> command__contents = __M7____vp__contents ;
 __S7____state -> command__length = __M7__total_len ;
 __S7____state -> command__first = __M7__first ;
 __S7____state -> command__memory = __H7__acquired ;
 __S7____task = __smolambda_add_task ( run__816 , __S7____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __S7____task ) ;
 if( __S7__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __S7____task ) ;
 __S7__err = __S7____state -> err ;
 __U7 = __S7__err ;
 if(! __U7 )goto __R7__fi ;
 __V7 = "[ \033[31mERROR\033[0m ] " ;
 __W7 = ".s" ;
 __X7____5d__length = strlen ( name ); __X7____5d__contents =( ptr ) name ; __X7____5d__first = name [0]; __X7____5d__noptr =( ptr ) __X7____5d__noptr ; 
 __X7____5d____u__contents = __X7____5d__contents ;
 __X7____6d__length = strlen ( __W7 ); __X7____6d__contents =( ptr ) __W7 ; __X7____6d__first = __W7 [0]; __X7____6d__noptr =( ptr ) __X7____6d__noptr ; 
 __X7____6d____u__contents = __X7____6d__contents ;
 __X7__len_x = __X7____5d__length ; __X7__len_y = __X7____6d__length ; __X7__total_len = __X7__len_x + __X7__len_y ; __X7__first = __X7____5d__length ? __X7____5d__first : __X7____6d__first ; 
 __X7____7d = 1 ;
 __X7____8d__z = __X7__total_len + __X7____7d ; 
 __X7____8d____end :
 __X7____9d = 0 ;
 __X7____Be____iQ = __P7__acquired ;
 __X7____Be____jQ__z =(! __X7____Be____iQ ); 
 __X7____Be____jQ____end :
 if(! __X7____Be____jQ__z )goto __X7____Be____hQ__fi ;
 __X7____Be____kQ = "Did not initialize Dynamic" ;
 goto __X7____Be____lQ____7D ;
 __builtin_unreachable();
 __X7____Be____hQ__fi :
 __X7____Be__next_size = __P7__size +1; __X7____Be__success = true ; __X7____Be__self__allocated__prev = __P7__allocated ; if ( __X7____Be__next_size >= __P7__allocated ) { __P7__allocated = __P7__allocated + __P7__allocated /2+1; __X7____Be__next_acquired =( ptr )((( ptr **) __P7__acquired )[0]? __runtime_realloc ((( ptr **) __P7__acquired )[0], __P7__allocated * sizeof ( ptr ), __X7____Be__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __P7__allocated * sizeof ( ptr ))); if ( __X7____Be__success = __X7____Be__next_acquired )(( ptr **) __P7__acquired )[0]=( ptr *) __X7____Be__next_acquired ; } if ( __X7____Be__success ) { __X7____Be__mem =( ptr ) __runtime_alloc ( __X7____8d__z * sizeof ( __X7____Be____gQ )); if ( __X7____Be__success = __X7____Be__mem ) {(( ptr **) __P7__acquired )[0][ __P7__size ]= __X7____Be__mem ; __P7__size = __X7____Be__next_size ; } } 
 __X7____Be____nQ__x = __X7____Be__success ;
 __X7____Be____nQ__z =(! __X7____Be____nQ__x ); 
 __X7____Be____nQ____end :
 if(! __X7____Be____nQ__z )goto __X7____Be____mQ__fi ;
 __X7____Be____oQ = "Failed a Dynamic allocation" ;
 goto __X7____Be____pQ____7D ;
 __builtin_unreachable();
 __X7____Be____mQ__fi :
 __X7____Be____uQ = 0 ;
 __X7____Be____wQ__bytesize = sizeof ( __X7____Be____wQ____dE )* __X7____8d__z ; 
 __X7____Be____wQ____end :
 memcpy (( char *) __X7____Be__mem ,( char *) __X7____5d____u__contents , __X7__len_x ); memcpy (( char *) __X7____Be__mem + __X7__len_x ,( char *) __X7____6d____u__contents , __X7__len_y );(( char *) __X7____Be__mem )[ __X7__total_len ]=0; 
 __X7____He__contents = __X7____Be__mem ;
 __P7____TQ = __X7____Be__self____TQ ;
 __P7__acquired = __P7__acquired ;
 __P7__size = __P7__size ;
 __P7__allocated = __P7__allocated ;
 __P7____dynamic_entry = __P7____dynamic_entry ;
 __Y7____ep__length = strlen ( __V7 ); __Y7____ep__contents =( ptr ) __V7 ; __Y7____ep__first = __V7 [0]; __Y7____ep__noptr =( ptr ) __Y7____ep__noptr ; 
 __Y7____ep____u__contents = __Y7____ep__contents ;
 __Y7__len_x = __Y7____ep__length ; __Y7__len_y = __X7__total_len ; __Y7__total_len = __Y7__len_x + __Y7__len_y ; __Y7__first = __Y7____ep__length ? __Y7____ep__first : __X7__first ; 
 __Y7____kp = 1 ;
 __Y7____lp__z = __Y7__total_len + __Y7____kp ; 
 __Y7____lp____end :
 __Y7____mp = 0 ;
 __Y7____op____iQ = __P7__acquired ;
 __Y7____op____jQ__z =(! __Y7____op____iQ ); 
 __Y7____op____jQ____end :
 if(! __Y7____op____jQ__z )goto __Y7____op____hQ__fi ;
 __Y7____op____kQ = "Did not initialize Dynamic" ;
 goto __Y7____op____lQ____7D ;
 __builtin_unreachable();
 __Y7____op____hQ__fi :
 __Y7____op__next_size = __P7__size +1; __Y7____op__success = true ; __Y7____op__self__allocated__prev = __P7__allocated ; if ( __Y7____op__next_size >= __P7__allocated ) { __P7__allocated = __P7__allocated + __P7__allocated /2+1; __Y7____op__next_acquired =( ptr )((( ptr **) __P7__acquired )[0]? __runtime_realloc ((( ptr **) __P7__acquired )[0], __P7__allocated * sizeof ( ptr ), __Y7____op__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __P7__allocated * sizeof ( ptr ))); if ( __Y7____op__success = __Y7____op__next_acquired )(( ptr **) __P7__acquired )[0]=( ptr *) __Y7____op__next_acquired ; } if ( __Y7____op__success ) { __Y7____op__mem =( ptr ) __runtime_alloc ( __Y7____lp__z * sizeof ( __Y7____op____gQ )); if ( __Y7____op__success = __Y7____op__mem ) {(( ptr **) __P7__acquired )[0][ __P7__size ]= __Y7____op__mem ; __P7__size = __Y7____op__next_size ; } } 
 __Y7____op____nQ__x = __Y7____op__success ;
 __Y7____op____nQ__z =(! __Y7____op____nQ__x ); 
 __Y7____op____nQ____end :
 if(! __Y7____op____nQ__z )goto __Y7____op____mQ__fi ;
 __Y7____op____oQ = "Failed a Dynamic allocation" ;
 goto __Y7____op____pQ____7D ;
 __builtin_unreachable();
 __Y7____op____mQ__fi :
 __Y7____op____uQ = 0 ;
 __Y7____op____wQ__bytesize = sizeof ( __Y7____op____wQ____dE )* __Y7____lp__z ; 
 __Y7____op____wQ____end :
 memcpy (( char *) __Y7____op__mem ,( char *) __Y7____ep____u__contents , __Y7__len_x ); memcpy (( char *) __Y7____op__mem + __Y7__len_x ,( char *) __X7____He__contents , __Y7__len_y );(( char *) __Y7____op__mem )[ __Y7__total_len ]=0; 
 __Y7____vp__contents = __Y7____op__mem ;
 __P7____TQ = __Y7____op__self____TQ ;
 __P7__acquired = __P7__acquired ;
 __P7__size = __P7__size ;
 __P7__allocated = __P7__allocated ;
 __P7____dynamic_entry = __P7____dynamic_entry ;
 printf ( "%s\n" ,( char *) __Y7____vp__contents ); 
 __Z7____end :
 goto __R7__el ;
 __R7__fi :
 __a7 = "[ \033[32mOK\033[0m ] " ;
 __b7 = ".s" ;
 __c7____5d__length = strlen ( name ); __c7____5d__contents =( ptr ) name ; __c7____5d__first = name [0]; __c7____5d__noptr =( ptr ) __c7____5d__noptr ; 
 __c7____5d____u__contents = __c7____5d__contents ;
 __c7____6d__length = strlen ( __b7 ); __c7____6d__contents =( ptr ) __b7 ; __c7____6d__first = __b7 [0]; __c7____6d__noptr =( ptr ) __c7____6d__noptr ; 
 __c7____6d____u__contents = __c7____6d__contents ;
 __c7__len_x = __c7____5d__length ; __c7__len_y = __c7____6d__length ; __c7__total_len = __c7__len_x + __c7__len_y ; __c7__first = __c7____5d__length ? __c7____5d__first : __c7____6d__first ; 
 __c7____7d = 1 ;
 __c7____8d__z = __c7__total_len + __c7____7d ; 
 __c7____8d____end :
 __c7____9d = 0 ;
 __c7____Be____iQ = __P7__acquired ;
 __c7____Be____jQ__z =(! __c7____Be____iQ ); 
 __c7____Be____jQ____end :
 if(! __c7____Be____jQ__z )goto __c7____Be____hQ__fi ;
 __c7____Be____kQ = "Did not initialize Dynamic" ;
 goto __c7____Be____lQ____7D ;
 __builtin_unreachable();
 __c7____Be____hQ__fi :
 __c7____Be__next_size = __P7__size +1; __c7____Be__success = true ; __c7____Be__self__allocated__prev = __P7__allocated ; if ( __c7____Be__next_size >= __P7__allocated ) { __P7__allocated = __P7__allocated + __P7__allocated /2+1; __c7____Be__next_acquired =( ptr )((( ptr **) __P7__acquired )[0]? __runtime_realloc ((( ptr **) __P7__acquired )[0], __P7__allocated * sizeof ( ptr ), __c7____Be__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __P7__allocated * sizeof ( ptr ))); if ( __c7____Be__success = __c7____Be__next_acquired )(( ptr **) __P7__acquired )[0]=( ptr *) __c7____Be__next_acquired ; } if ( __c7____Be__success ) { __c7____Be__mem =( ptr ) __runtime_alloc ( __c7____8d__z * sizeof ( __c7____Be____gQ )); if ( __c7____Be__success = __c7____Be__mem ) {(( ptr **) __P7__acquired )[0][ __P7__size ]= __c7____Be__mem ; __P7__size = __c7____Be__next_size ; } } 
 __c7____Be____nQ__x = __c7____Be__success ;
 __c7____Be____nQ__z =(! __c7____Be____nQ__x ); 
 __c7____Be____nQ____end :
 if(! __c7____Be____nQ__z )goto __c7____Be____mQ__fi ;
 __c7____Be____oQ = "Failed a Dynamic allocation" ;
 goto __c7____Be____pQ____7D ;
 __builtin_unreachable();
 __c7____Be____mQ__fi :
 __c7____Be____uQ = 0 ;
 __c7____Be____wQ__bytesize = sizeof ( __c7____Be____wQ____dE )* __c7____8d__z ; 
 __c7____Be____wQ____end :
 memcpy (( char *) __c7____Be__mem ,( char *) __c7____5d____u__contents , __c7__len_x ); memcpy (( char *) __c7____Be__mem + __c7__len_x ,( char *) __c7____6d____u__contents , __c7__len_y );(( char *) __c7____Be__mem )[ __c7__total_len ]=0; 
 __c7____He__contents = __c7____Be__mem ;
 __P7____TQ = __c7____Be__self____TQ ;
 __P7__acquired = __P7__acquired ;
 __P7__size = __P7__size ;
 __P7__allocated = __P7__allocated ;
 __P7____dynamic_entry = __P7____dynamic_entry ;
 __d7____ep__length = strlen ( __a7 ); __d7____ep__contents =( ptr ) __a7 ; __d7____ep__first = __a7 [0]; __d7____ep__noptr =( ptr ) __d7____ep__noptr ; 
 __d7____ep____u__contents = __d7____ep__contents ;
 __d7__len_x = __d7____ep__length ; __d7__len_y = __c7__total_len ; __d7__total_len = __d7__len_x + __d7__len_y ; __d7__first = __d7____ep__length ? __d7____ep__first : __c7__first ; 
 __d7____kp = 1 ;
 __d7____lp__z = __d7__total_len + __d7____kp ; 
 __d7____lp____end :
 __d7____mp = 0 ;
 __d7____op____iQ = __P7__acquired ;
 __d7____op____jQ__z =(! __d7____op____iQ ); 
 __d7____op____jQ____end :
 if(! __d7____op____jQ__z )goto __d7____op____hQ__fi ;
 __d7____op____kQ = "Did not initialize Dynamic" ;
 goto __d7____op____lQ____7D ;
 __builtin_unreachable();
 __d7____op____hQ__fi :
 __d7____op__next_size = __P7__size +1; __d7____op__success = true ; __d7____op__self__allocated__prev = __P7__allocated ; if ( __d7____op__next_size >= __P7__allocated ) { __P7__allocated = __P7__allocated + __P7__allocated /2+1; __d7____op__next_acquired =( ptr )((( ptr **) __P7__acquired )[0]? __runtime_realloc ((( ptr **) __P7__acquired )[0], __P7__allocated * sizeof ( ptr ), __d7____op__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __P7__allocated * sizeof ( ptr ))); if ( __d7____op__success = __d7____op__next_acquired )(( ptr **) __P7__acquired )[0]=( ptr *) __d7____op__next_acquired ; } if ( __d7____op__success ) { __d7____op__mem =( ptr ) __runtime_alloc ( __d7____lp__z * sizeof ( __d7____op____gQ )); if ( __d7____op__success = __d7____op__mem ) {(( ptr **) __P7__acquired )[0][ __P7__size ]= __d7____op__mem ; __P7__size = __d7____op__next_size ; } } 
 __d7____op____nQ__x = __d7____op__success ;
 __d7____op____nQ__z =(! __d7____op____nQ__x ); 
 __d7____op____nQ____end :
 if(! __d7____op____nQ__z )goto __d7____op____mQ__fi ;
 __d7____op____oQ = "Failed a Dynamic allocation" ;
 goto __d7____op____pQ____7D ;
 __builtin_unreachable();
 __d7____op____mQ__fi :
 __d7____op____uQ = 0 ;
 __d7____op____wQ__bytesize = sizeof ( __d7____op____wQ____dE )* __d7____lp__z ; 
 __d7____op____wQ____end :
 memcpy (( char *) __d7____op__mem ,( char *) __d7____ep____u__contents , __d7__len_x ); memcpy (( char *) __d7____op__mem + __d7__len_x ,( char *) __c7____He__contents , __d7__len_y );(( char *) __d7____op__mem )[ __d7__total_len ]=0; 
 __d7____vp__contents = __d7____op__mem ;
 __P7____TQ = __d7____op__self____TQ ;
 __P7__acquired = __P7__acquired ;
 __P7__size = __P7__size ;
 __P7__allocated = __P7__allocated ;
 __P7____dynamic_entry = __P7____dynamic_entry ;
 printf ( "%s\n" ,( char *) __d7____vp__contents ); 
 __e7____end :
 __R7__el :
 __end :
goto __return;

// ERROR HANDLING
__d7____op____lQ____7D :
 printf ( "%s\n" , __d7____op____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__L7____Be____pQ____7D :
 printf ( "%s\n" , __L7____Be____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__Y7____op____pQ____7D :
 printf ( "%s\n" , __Y7____op____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__d7____op____pQ____7D :
 printf ( "%s\n" , __d7____op____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__c7____Be____lQ____7D :
 printf ( "%s\n" , __c7____Be____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__Y7____op____lQ____7D :
 printf ( "%s\n" , __Y7____op____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__M7____op____lQ____7D :
 printf ( "%s\n" , __M7____op____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__M7____op____pQ____7D :
 printf ( "%s\n" , __M7____op____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__T7 :
printf("Runtime error from run __S7 \n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
__L7____Be____lQ____7D :
 printf ( "%s\n" , __L7____Be____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__X7____Be____lQ____7D :
 printf ( "%s\n" , __X7____Be____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__X7____Be____pQ____7D :
 printf ( "%s\n" , __X7____Be____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__c7____Be____pQ____7D :
 printf ( "%s\n" , __c7____Be____oQ ); 
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
if ( __P7__acquired ) { for ( __P7____dynamic_entry =0; __P7____dynamic_entry < __P7__size ;++ __P7____dynamic_entry ) { __runtime_free ((( ptr **) __P7__acquired )[0][ __P7____dynamic_entry ]); } __runtime_free ( __P7__acquired ); __P7__acquired =0; __P7__size =0; __P7__allocated =0; } 
 if ( __P7__acquired ) { for ( __P7____ZQ____dynamic_entry =0; __P7____ZQ____dynamic_entry < __P7____ZQ____UQ ;++ __P7____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __P7__acquired )[0][ __P7____ZQ____dynamic_entry ]); } __runtime_free ( __P7__acquired ); __P7__acquired =0; __P7____ZQ____UQ =0; __P7____ZQ____VQ =0; } 
if ( __H7__acquired ) { for ( __H7____dynamic_entry =0; __H7____dynamic_entry < __H7__size ;++ __H7____dynamic_entry ) { __runtime_free ((( ptr **) __H7__acquired )[0][ __H7____dynamic_entry ]); } __runtime_free ( __H7__acquired ); __H7__acquired =0; __H7__size =0; __H7__allocated =0; } 
 if ( __H7__acquired ) { for ( __H7____ZQ____dynamic_entry =0; __H7____ZQ____dynamic_entry < __H7____ZQ____UQ ;++ __H7____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __H7__acquired )[0][ __H7____ZQ____dynamic_entry ]); } __runtime_free ( __H7__acquired ); __H7__acquired =0; __H7____ZQ____UQ =0; __H7____ZQ____VQ =0; } 
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
i64 __D7__status=0;
nominal __E7__p____V5=0;
nominal command____c=0;
ptr __D7____j5__x=0;
bool __D7____k5__z=0;
ptr __C7__contents=0;
ptr process__contents=0;
ptr __D7__contents=0;
ptr __B7__contents=0;
nominal process____V5=0;
bool __D7____j5__z=0;

// IMPLEMENTATION
__B7__contents = 0 ;
 __C7__contents = __B7__contents ;
 __D7__contents =( ptr ) popen (( cstr ) command__contents , "r" ); 
 __D7____j5__x = __D7__contents ;
 __D7____j5__z =( __D7____j5__x ); 
 __D7____j5____end :
 __D7____k5__z =(! __D7____j5__z ); 
 __D7____k5____end :
 if(! __D7____k5__z )goto __D7____i5__fi ;
 goto __D7____l5 ;
 __builtin_unreachable();
 __D7____i5__fi :
 process__contents = __D7__contents ;
 if ( process__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process__contents )) { } } 
 __E7____end :
 process____V5 = __E7__p____V5 ;
 __D7__status =0; if ( process__contents ) __D7__status = pclose (( FILE *) process__contents ); process__contents =0; if ( __D7__status ) { if ( __D7__status !=-1&& WIFEXITED ( __D7__status )) __D7__status = WEXITSTATUS ( __D7__status ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __D7__status ); __result__errocode = __USER__ERROR ; goto __failsafe ; } 
 __end :
goto __return;

// ERROR HANDLING
__D7____l5 :
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


void run__815(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__815__state *__state=(struct run__815__state*)__void__state;
ptr command__contents= __state->command__contents;
u64 command__length= __state->command__length;
char command__first= __state->command__first;
ptr command__memory= __state->command__memory;
nominal __96__p____V5=0;
bool __86____w6____b5__z=0;
bool __86____w6____a5__z=0;
ptr __86____w6____a5__x=0;
ptr __86____w6____Y5____x__contents=0;
char __86____w6____Y5__first=0;
u64 __86____w6____Y5__length=0;
ptr __86____u6__contents=0;
char __86__first=0;
ptr process____w6____Y5__noptr=0;
ptr process____w6____Y5__contents=0;
bool __86____s6____iF__z=0;
cstr process____s6____jF=0;
char process____q6=0;
cstr process__mem=0;
ptr __86____w6____Y5__noptr=0;
ptr process____v6__contents=0;
u64 process__command__length=0;
ptr process____w6____a5__x=0;
ptr __76__contents=0;
char process____s6____tF____XE=0;
bool process____s6____ZF__z=0;
ptr process____u6__contents=0;
ptr __86____s6__mem=0;
i64 __86____w6__status=0;
u64 process____s6____YF=0;
cstr __86____s6____jF=0;
u64 process____s6__size=0;
ptr process__command__contents=0;
char process____s6____fF=0;
bool process____s6____hF=0;
ptr __66__contents=0;
u64 __86____p6__z=0;
bool process____w6____a5__z=0;
char __86____s6____rF=0;
bool __86____s6____hF=0;
u64 process____p6__z=0;
u64 process____o6=0;
bool process____s6____iF__z=0;
ptr __86____w6__contents=0;
bool process____w6____b5__z=0;
char __86____s6____fF=0;
char process__first=0;
char process____w6____Y5__first=0;
ptr __86____w6____Y5__contents=0;
ptr process____l6__contents=0;
cstr process____s6____dF=0;
nominal process____l6____V5=0;
nominal process__command____b=0;
char process____s6____rF=0;
ptr process__command__memory=0;
u64 process____w6____Y5__length=0;
nominal command____b=0;
char process__command__first=0;
ptr process____s6__mem=0;
bool __86____s6____ZF__z=0;
ptr process____w6__contents=0;
ptr process____w6____Y5____x__contents=0;
u64 process____s6____tF__bytesize=0;
cstr __86__mem=0;
u64 __86____o6=0;
char __86____q6=0;
i64 process____w6__status=0;
nominal process____w6____V5=0;
u64 __86____s6____YF=0;
cstr __86____s6____dF=0;
u64 __86____s6____tF__bytesize=0;
char __86____s6____tF____XE=0;

// IMPLEMENTATION
__66__contents = 0 ;
 __76__contents = __66__contents ;
 __86____o6 = 1 ;
 __86____p6__z = command__length + __86____o6 ; 
 __86____p6____end :
 __86____q6 = 0 ;
 __86____s6____YF = 0 ;
 __86____s6____ZF__z =( __86____p6__z == __86____s6____YF ); 
 __86____s6____ZF____end :
 if(! __86____s6____ZF__z )goto __86____s6____XF__fi ;
 __86____s6____dF = "Cannot allocate zero size" ;
 goto __86____s6____eF____7D ;
 __builtin_unreachable();
 __86____s6____XF__fi :
 __86____s6__mem = alloca ( __86____p6__z * sizeof ( __86____s6____fF )); 
 __86____s6____hF = __86____s6__mem ;
 __86____s6____iF__z =(! __86____s6____hF ); 
 __86____s6____iF____end :
 if(! __86____s6____iF__z )goto __86____s6____gF__fi ;
 __86____s6____jF = "Failed a Stack allocation" ;
 goto __86____s6____kF____7D ;
 __builtin_unreachable();
 __86____s6____gF__fi :
 __86____s6____rF = 0 ;
 __86____s6____tF__bytesize = sizeof ( __86____s6____tF____XE )* __86____p6__z ; 
 __86____s6____tF____end :
 __86__first =0; if ( __86____s6__mem ) { memcpy (( char *) __86____s6__mem , command__contents , command__length );(( char *) __86____s6__mem )[ command__length ]=0; } __86__mem =( const char *) __86____s6__mem ; 
 __86____u6__contents = 0 ;
 __86____w6____Y5__length = strlen ( __86__mem ); __86____w6____Y5__contents =( ptr ) __86__mem ; __86____w6____Y5__first = __86__mem [0]; __86____w6____Y5__noptr =( ptr ) __86____w6____Y5__noptr ; 
 __86____w6____Y5____x__contents = __86____w6____Y5__contents ;
 __86____w6__contents =( ptr ) popen (( cstr ) __86____w6____Y5____x__contents , "r" ); 
 __86____w6____a5__x = __86____w6__contents ;
 __86____w6____a5__z =( __86____w6____a5__x ); 
 __86____w6____a5____end :
 __86____w6____b5__z =(! __86____w6____a5__z ); 
 __86____w6____b5____end :
 if(! __86____w6____b5__z )goto __86____w6____Z5__fi ;
 goto __86____w6____c5 ;
 __builtin_unreachable();
 __86____w6____Z5__fi :
 __TRANSIENT( __86____s6__mem )
 process____w6__contents = __86____w6__contents ;
 if ( process____w6__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process____w6__contents )) { } } 
 __96____end :
 process____w6____V5 = __96__p____V5 ;
 __86____w6__status =0; if ( process____w6__contents ) __86____w6__status = pclose (( FILE *) process____w6__contents ); process____w6__contents =0; if ( __86____w6__status ) { if ( __86____w6__status !=-1&& WIFEXITED ( __86____w6__status )) __86____w6__status = WEXITSTATUS ( __86____w6__status ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __86____w6__status ); __result__errocode = __USER__ERROR ; goto __failsafe ; } 
 __end :
goto __return;

// ERROR HANDLING
__86____w6____c5 :
 printf ( "Error: Failed to start process\n" ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__86____s6____kF____7D :
 printf ( "%s\n" , __86____s6____jF ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__86____s6____eF____7D :
 printf ( "%s\n" , __86____s6____dF ); 
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


void all__821(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct all__821__state *__state=(struct all__821__state*)__void__state;
struct std_test__818__state* __W8____state = 0 ;
 struct std_test__818__state* __Y8____state = 0 ;
 struct std_test__818__state* __a8____state = 0 ;
 struct std_test__818__state* __c8____state = 0 ;
 struct std_test__818__state* __e8____state = 0 ;
 struct std_test__818__state* __g8____state = 0 ;
 struct std_test__818__state* __i8____state = 0 ;
 struct std_test__818__state* __k8____state = 0 ;
 struct std_test__818__state* __m8____state = 0 ;
 struct std_test__818__state* __o8____state = 0 ;
 struct std_test__818__state* __q8____state = 0 ;
 struct std_test__818__state* __s8____state = 0 ;
 struct std_test__818__state* __u8____state = 0 ;
 struct std_test__818__state* __w8____state = 0 ;
 struct std_test__818__state* __y8____state = 0 ;
 struct std_test__818__state* __08____state = 0 ;
 struct std_test__818__state* __28____state = 0 ;
 struct std_test__818__state* __48____state = 0 ;
 struct std_test__818__state* __68____state = 0 ;
errcode __68__err=0;
cstr __58=0;
errcode __28__err=0;
ptr __28____task=0;
errcode __08__err=0;
ptr __08____task=0;
cstr __z8=0;
errcode __y8__err=0;
errcode __w8__err=0;
ptr __w8____task=0;
cstr __v8=0;
ptr __u8____task=0;
errcode __s8__err=0;
errcode __q8__err=0;
cstr __p8=0;
cstr __n8=0;
errcode __m8__err=0;
ptr __m8____task=0;
cstr __l8=0;
cstr __j8=0;
ptr __i8____task=0;
cstr __h8=0;
errcode __g8__err=0;
ptr __g8____task=0;
cstr __f8=0;
errcode __e8__err=0;
errcode __c8__err=0;
ptr __c8____task=0;
cstr __b8=0;
ptr __a8____task=0;
cstr __Z8=0;
errcode __Y8__err=0;
cstr __X8=0;
ptr __W8____task=0;
cstr __x8=0;
ptr __k8____task=0;
errcode __k8__err=0;
ptr __48____task=0;
errcode __a8__err=0;
ptr __Y8____task=0;
ptr __e8____task=0;
errcode __i8__err=0;
ptr __q8____task=0;
errcode __u8__err=0;
ptr __s8____task=0;
ptr __68____task=0;
cstr __r8=0;
errcode __W8__err=0;
cstr __t8=0;
errcode __o8__err=0;
cstr __38=0;
errcode __48__err=0;
cstr __18=0;
ptr __y8____task=0;
cstr __V8=0;
cstr __d8=0;
ptr __o8____task=0;

// IMPLEMENTATION
__V8 = "buffers" ;
 __W8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __W8____state ) ;
 __W8____state -> name = __V8 ;
 __W8____task = __smolambda_add_task ( std_test__818 , __W8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __W8____task ) ;
 if( __W8__err ) goto  __result_unhandled_error ;
 __X8 = "bbuffer" ;
 __Y8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __Y8____state ) ;
 __Y8____state -> name = __X8 ;
 __Y8____task = __smolambda_add_task ( std_test__818 , __Y8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __Y8____task ) ;
 if( __Y8__err ) goto  __result_unhandled_error ;
 __Z8 = "bufferconst" ;
 __a8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __a8____state ) ;
 __a8____state -> name = __Z8 ;
 __a8____task = __smolambda_add_task ( std_test__818 , __a8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __a8____task ) ;
 if( __a8__err ) goto  __result_unhandled_error ;
 __b8 = "buffergrow" ;
 __c8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __c8____state ) ;
 __c8____state -> name = __b8 ;
 __c8____task = __smolambda_add_task ( std_test__818 , __c8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __c8____task ) ;
 if( __c8__err ) goto  __result_unhandled_error ;
 __d8 = "effvec" ;
 __e8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __e8____state ) ;
 __e8____state -> name = __d8 ;
 __e8____task = __smolambda_add_task ( std_test__818 , __e8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __e8____task ) ;
 if( __e8__err ) goto  __result_unhandled_error ;
 __f8 = "fail" ;
 __g8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __g8____state ) ;
 __g8____state -> name = __f8 ;
 __g8____task = __smolambda_add_task ( std_test__818 , __g8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __g8____task ) ;
 if( __g8__err ) goto  __result_unhandled_error ;
 __h8 = "file" ;
 __i8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __i8____state ) ;
 __i8____state -> name = __h8 ;
 __i8____task = __smolambda_add_task ( std_test__818 , __i8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __i8____task ) ;
 if( __i8__err ) goto  __result_unhandled_error ;
 __j8 = "filesize" ;
 __k8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __k8____state ) ;
 __k8____state -> name = __j8 ;
 __k8____task = __smolambda_add_task ( std_test__818 , __k8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __k8____task ) ;
 if( __k8__err ) goto  __result_unhandled_error ;
 __l8 = "finally" ;
 __m8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __m8____state ) ;
 __m8____state -> name = __l8 ;
 __m8____task = __smolambda_add_task ( std_test__818 , __m8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __m8____task ) ;
 if( __m8__err ) goto  __result_unhandled_error ;
 __n8 = "nom" ;
 __o8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __o8____state ) ;
 __o8____state -> name = __n8 ;
 __o8____task = __smolambda_add_task ( std_test__818 , __o8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __o8____task ) ;
 if( __o8__err ) goto  __result_unhandled_error ;
 __p8 = "mem" ;
 __q8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __q8____state ) ;
 __q8____state -> name = __p8 ;
 __q8____task = __smolambda_add_task ( std_test__818 , __q8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __q8____task ) ;
 if( __q8__err ) goto  __result_unhandled_error ;
 __r8 = "memtest" ;
 __s8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __s8____state ) ;
 __s8____state -> name = __r8 ;
 __s8____task = __smolambda_add_task ( std_test__818 , __s8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __s8____task ) ;
 if( __s8__err ) goto  __result_unhandled_error ;
 __t8 = "mutpoint" ;
 __u8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __u8____state ) ;
 __u8____state -> name = __t8 ;
 __u8____task = __smolambda_add_task ( std_test__818 , __u8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __u8____task ) ;
 if( __u8__err ) goto  __result_unhandled_error ;
 __v8 = "range_test" ;
 __w8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __w8____state ) ;
 __w8____state -> name = __v8 ;
 __w8____task = __smolambda_add_task ( std_test__818 , __w8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __w8____task ) ;
 if( __w8__err ) goto  __result_unhandled_error ;
 __x8 = "ref" ;
 __y8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __y8____state ) ;
 __y8____state -> name = __x8 ;
 __y8____task = __smolambda_add_task ( std_test__818 , __y8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __y8____task ) ;
 if( __y8__err ) goto  __result_unhandled_error ;
 __z8 = "strcat" ;
 __08____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __08____state ) ;
 __08____state -> name = __z8 ;
 __08____task = __smolambda_add_task ( std_test__818 , __08____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __08____task ) ;
 if( __08__err ) goto  __result_unhandled_error ;
 __18 = "vec" ;
 __28____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __28____state ) ;
 __28____state -> name = __18 ;
 __28____task = __smolambda_add_task ( std_test__818 , __28____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __28____task ) ;
 if( __28__err ) goto  __result_unhandled_error ;
 __38 = "virtfile" ;
 __48____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __48____state ) ;
 __48____state -> name = __38 ;
 __48____task = __smolambda_add_task ( std_test__818 , __48____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __48____task ) ;
 if( __48__err ) goto  __result_unhandled_error ;
 __58 = "accessvar" ;
 __68____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __68____state ) ;
 __68____state -> name = __58 ;
 __68____task = __smolambda_add_task ( std_test__818 , __68____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __68____task ) ;
 if( __68__err ) goto  __result_unhandled_error ;
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


void run__814(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__814__state *__state=(struct run__814__state*)__void__state;
cstr command= __state->command;
i64 __36__status=0;
ptr __36__contents=0;
char __36____Y5__first=0;
ptr process__contents=0;
bool __36____b5__z=0;
nominal process____V5=0;
ptr __36____a5__x=0;
ptr __36____Y5__contents=0;
ptr __16__contents=0;
nominal __46__p____V5=0;
ptr __26__contents=0;
ptr __36____Y5__noptr=0;
u64 __36____Y5__length=0;
ptr __36____Y5____x__contents=0;
bool __36____a5__z=0;

// IMPLEMENTATION
__16__contents = 0 ;
 __26__contents = __16__contents ;
 __36____Y5__length = strlen ( command ); __36____Y5__contents =( ptr ) command ; __36____Y5__first = command [0]; __36____Y5__noptr =( ptr ) __36____Y5__noptr ; 
 __36____Y5____x__contents = __36____Y5__contents ;
 __36__contents =( ptr ) popen (( cstr ) __36____Y5____x__contents , "r" ); 
 __36____a5__x = __36__contents ;
 __36____a5__z =( __36____a5__x ); 
 __36____a5____end :
 __36____b5__z =(! __36____a5__z ); 
 __36____b5____end :
 if(! __36____b5__z )goto __36____Z5__fi ;
 goto __36____c5 ;
 __builtin_unreachable();
 __36____Z5__fi :
 process__contents = __36__contents ;
 if ( process__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process__contents )) { } } 
 __46____end :
 process____V5 = __46__p____V5 ;
 __36__status =0; if ( process__contents ) __36__status = pclose (( FILE *) process__contents ); process__contents =0; if ( __36__status ) { if ( __36__status !=-1&& WIFEXITED ( __36__status )) __36__status = WEXITSTATUS ( __36__status ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __36__status ); __result__errocode = __USER__ERROR ; goto __failsafe ; } 
 __end :
goto __return;

// ERROR HANDLING
__36____c5 :
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


void main__822(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__822__state *__state=(struct main__822__state*)__void__state;
struct all__821__state* __88____state = 0 ;
f64 __C9__elapsed=0;
cstr __A9=0;
ptr __88____task=0;
f64 __D9__z=0;
cstr __F9=0;
errcode __88__err=0;
f64 __78__elapsed=0;

// IMPLEMENTATION
__78__elapsed = __smo_time_eta (); 
 __78____end :
 __88____state = (struct all__821__state*)__runtime_calloc(sizeof(struct all__821__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __88____state ) ;
 __88____task = __smolambda_add_task ( all__821 , __88____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __88____task ) ;
 if( __88__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __88____task ) ;
 __88__err = __88____state -> err ;
 __A9 = "Completed in " ;
 printf ( "%s" , __A9 ); 
 __B9____end :
 __C9__elapsed = __smo_time_eta (); 
 __C9____end :
 __D9__z = __C9__elapsed - __78__elapsed ; 
 __D9____end :
 printf ( "%.6f" , __D9__z ); 
 __E9____end :
 __F9 = " sec" ;
 printf ( "%s\n" , __F9 ); 
 __G9____end :
 __end :
goto __return;

// ERROR HANDLING
__98 :
printf("Runtime error from all __88 \n");
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

