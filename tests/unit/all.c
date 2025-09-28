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

#include "std/oscommon.h"

#include <stdio.h>
#include<string.h>

#include<stdlib.h>

#include<stdio.h>

#include<sys/wait.h>

#if defined(_WIN32)||defined(_WIN64)
#define popen _popen
#define pclose _pclose
#endif

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
struct main__822__state{errcode err;};
__externc void main__822(void *__void__state);
struct all__821__state{errcode err;};
__externc void all__821(void *__void__state);

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
ptr __37____4h__contents=0;
u64 __37____1h____wQ__bytesize=0;
char __37____1h____uQ=0;
cstr __37____1h____oQ=0;
bool __37____1h____nQ__z=0;
char __37____1h____gQ=0;
u64 __37____1h__self__allocated__prev=0;
bool __37____1h__success=0;
cstr __37____1h____kQ=0;
char __37____zh=0;
u64 __37____yh__z=0;
char __37__first=0;
u64 __37__len_y=0;
u64 __37__len_x=0;
ptr __37____vh__noptr=0;
char __37____vh__first=0;
u64 __37____vh__length=0;
ptr __37____1h__mem=0;
ptr __27____Qc__contents=0;
u64 __27____Nc____wQ__bytesize=0;
char __27____Nc____uQ=0;
ptr __27____Nc__mem=0;
u64 __27____Nc__next_size=0;
nominal __37____1h__self____TQ=0;
cstr __27____Nc____kQ=0;
bool __27____Nc____jQ__z=0;
bool __27____Nc____iQ=0;
char __27____Lc=0;
u64 __27____Kc__z=0;
u64 __27____Jc=0;
u64 __27__total_len=0;
u64 __27__len_y=0;
u64 __27__len_x=0;
ptr __27____Ic____m__contents=0;
char __27____Ic__first=0;
cstr __07=0;
u64 __37____1h__next_size=0;
char __y7____1h____wQ____CF=0;
char __y7____1h____gQ=0;
ptr __y7____1h__mem=0;
u64 __y7____1h__self__allocated__prev=0;
bool __y7____1h__success=0;
u64 __y7____1h__next_size=0;
bool __y7____1h____jQ__z=0;
bool __y7____1h____iQ=0;
char __y7__first=0;
u64 __y7__total_len=0;
u64 __y7__len_y=0;
u64 __y7__len_x=0;
ptr __y7____vh____m__contents=0;
ptr __37____vh__contents=0;
ptr __y7____vh__noptr=0;
ptr __y7____vh__contents=0;
nominal __p7____TQ=0;
u64 __x7____Nc____wQ__bytesize=0;
char __x7____Nc____uQ=0;
cstr __x7____Nc____oQ=0;
char __27____Nc____gQ=0;
bool __y7____1h____nQ__x=0;
bool __x7____Nc____nQ__z=0;
ptr __x7____Nc__mem=0;
char __27__first=0;
u64 __x7____Nc__self__allocated__prev=0;
u64 __x7____Nc__next_size=0;
u64 __x7____Kc__z=0;
u64 __x7____Jc=0;
char __x7__first=0;
u64 __x7__total_len=0;
u64 __x7__len_y=0;
u64 __x7__len_x=0;
ptr __x7____Ic__noptr=0;
cstr __w7=0;
cstr __v7=0;
bool __u7=0;
nominal __y7____1h__self____TQ=0;
errcode __s7__err=0;
ptr __y7____4h__contents=0;
ptr __s7____task=0;
u64 __m7__len_y=0;
ptr __y7____1h__next_acquired=0;
ptr __27____Ic__contents=0;
char __x7____Ic__first=0;
nominal __27____Nc__self____TQ=0;
ptr __x7____Nc__next_acquired=0;
bool __m7____1h____jQ__z=0;
char __y7____vh__first=0;
char command__first=0;
ptr __27____Ic__noptr=0;
bool __x7____Nc____nQ__x=0;
char __m7____1h____wQ____CF=0;
u64 __37__total_len=0;
u64 __37____xh=0;
char __m7____1h____uQ=0;
u64 __27____Nc__self__allocated__prev=0;
cstr __27____Nc____oQ=0;
bool __37____1h____nQ__x=0;
bool __x7____Nc____jQ__z=0;
bool __m7____1h____nQ__z=0;
ptr __l7____Ic__noptr=0;
char __y7____zh=0;
char __27____Nc____wQ____CF=0;
bool __27____Nc____nQ__x=0;
cstr __y7____1h____kQ=0;
u64 __p7__allocated=0;
char __x7____Lc=0;
ptr __27____Nc__next_acquired=0;
nominal __m7____1h__self____TQ=0;
u64 __x7____Ic__length=0;
u64 __y7____vh__length=0;
u64 __y7____1h____wQ__bytesize=0;
char __y7____1h____uQ=0;
ptr command__memory=0;
bool __y7____1h____nQ__z=0;
bool __l7____Nc____iQ=0;
u64 __m7__total_len=0;
nominal __x7____Nc__self____TQ=0;
cstr __l7____Nc____kQ=0;
bool __x7____Nc____iQ=0;
bool __l7____Nc____nQ__z=0;
char __m7__first=0;
u64 __y7____xh=0;
bool __l7____Nc__success=0;
bool __m7____1h____iQ=0;
cstr __y7____1h____oQ=0;
u64 command__length=0;
char __x7____Nc____wQ____CF=0;
u64 __l7____Nc__next_size=0;
ptr __x7____Qc__contents=0;
u64 __l7____Jc=0;
char __x7____Nc____gQ=0;
cstr __m7____1h____kQ=0;
char __l7__first=0;
ptr __p7____ZQ__acquired=0;
bool __l7____Nc____nQ__x=0;
nominal __l7____Nc__self____TQ=0;
char __37____1h____wQ____CF=0;
ptr __h7__acquired=0;
nominal name____b=0;
ptr __m7____vh__contents=0;
ptr __37____1h__next_acquired=0;
u64 __h7__size=0;
ptr __l7____Ic____m__contents=0;
ptr __h7____ZQ__acquired=0;
u64 __h7____ZQ____VQ=0;
bool __m7____1h____nQ__x=0;
u64 __y7____yh__z=0;
u64 __h7____dynamic_entry=0;
cstr __j7=0;
char __m7____1h____gQ=0;
cstr __k7=0;
bool __27____Nc____nQ__z=0;
u64 __l7____Ic__length=0;
u64 __h7__allocated=0;
ptr __l7____Ic__contents=0;
char __l7____Ic__first=0;
u64 __l7____Nc__self__allocated__prev=0;
cstr __17=0;
u64 __l7__len_x=0;
ptr __p7__acquired=0;
u64 __l7__len_y=0;
u64 __l7__total_len=0;
u64 __l7____Kc__z=0;
u64 __27____Ic__length=0;
char __l7____Lc=0;
bool __27____Nc__success=0;
u64 __p7____ZQ____UQ=0;
bool __l7____Nc____jQ__z=0;
u64 __p7____ZQ____dynamic_entry=0;
ptr __l7____Nc__next_acquired=0;
ptr __l7____Nc__mem=0;
char __m7____zh=0;
ptr __37____vh____m__contents=0;
char __l7____Nc____gQ=0;
u64 __p7__size=0;
cstr __l7____Nc____oQ=0;
bool __37____1h____jQ__z=0;
char __l7____Nc____uQ=0;
u64 __l7____Nc____wQ__bytesize=0;
u64 __h7____ZQ____dynamic_entry=0;
u64 __m7____1h__next_size=0;
char __l7____Nc____wQ____CF=0;
ptr __l7____Qc__contents=0;
ptr __x7____Ic__contents=0;
nominal __h7____TQ=0;
u64 __m7____vh__length=0;
bool __x7____Nc__success=0;
char __m7____vh__first=0;
ptr __m7____1h__mem=0;
ptr __m7____vh__noptr=0;
ptr __m7____vh____m__contents=0;
bool __m7____1h__success=0;
u64 __m7__len_x=0;
u64 __m7____xh=0;
bool __37____1h____iQ=0;
cstr __x7____Nc____kQ=0;
ptr __x7____Ic____m__contents=0;
u64 __m7____yh__z=0;
u64 __h7____ZQ____UQ=0;
ptr __m7____1h__next_acquired=0;
u64 __m7____1h__self__allocated__prev=0;
cstr __m7____1h____oQ=0;
u64 __m7____1h____wQ__bytesize=0;
ptr __m7____4h__contents=0;
u64 __p7____ZQ____VQ=0;
u64 __p7____dynamic_entry=0;
nominal command____c=0;
ptr command__contents=0;

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
 __l7____Ic__length = strlen ( __k7 ); __l7____Ic__contents =( ptr ) __k7 ; __l7____Ic__first = __k7 [0]; __l7____Ic__noptr =( ptr ) __l7____Ic__noptr ; 
 __l7____Ic____m__contents = __l7____Ic__contents ;
 __l7__len_x = name__length ; __l7__len_y = __l7____Ic__length ; __l7__total_len = __l7__len_x + __l7__len_y ; __l7__first = name__length ? name__first : __l7____Ic__first ; 
 __l7____Jc = 1 ;
 __l7____Kc__z = __l7__total_len + __l7____Jc ; 
 __l7____Kc____end :
 __l7____Lc = 0 ;
 __l7____Nc____iQ = __h7__acquired ;
 __l7____Nc____jQ__z =(! __l7____Nc____iQ ); 
 __l7____Nc____jQ____end :
 if(! __l7____Nc____jQ__z )goto __l7____Nc____hQ__fi ;
 __l7____Nc____kQ = "Did not initialize Dynamic" ;
 goto __l7____Nc____lQ____oD ;
 __builtin_unreachable();
 __l7____Nc____hQ__fi :
 __l7____Nc__next_size = __h7__size +1; __l7____Nc__success = true ; __l7____Nc__self__allocated__prev = __h7__allocated ; if ( __l7____Nc__next_size >= __h7__allocated ) { __h7__allocated = __h7__allocated + __h7__allocated /2+1; __l7____Nc__next_acquired =( ptr )((( ptr **) __h7__acquired )[0]? __runtime_realloc ((( ptr **) __h7__acquired )[0], __h7__allocated * sizeof ( ptr ), __l7____Nc__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __h7__allocated * sizeof ( ptr ))); if ( __l7____Nc__success = __l7____Nc__next_acquired )(( ptr **) __h7__acquired )[0]=( ptr *) __l7____Nc__next_acquired ; } if ( __l7____Nc__success ) { __l7____Nc__mem =( ptr ) __runtime_alloc ( __l7____Kc__z * sizeof ( __l7____Nc____gQ )); if ( __l7____Nc__success = __l7____Nc__mem ) {(( ptr **) __h7__acquired )[0][ __h7__size ]= __l7____Nc__mem ; __h7__size = __l7____Nc__next_size ; } } 
 __l7____Nc____nQ__x = __l7____Nc__success ;
 __l7____Nc____nQ__z =(! __l7____Nc____nQ__x ); 
 __l7____Nc____nQ____end :
 if(! __l7____Nc____nQ__z )goto __l7____Nc____mQ__fi ;
 __l7____Nc____oQ = "Failed a Dynamic allocation" ;
 goto __l7____Nc____pQ____oD ;
 __builtin_unreachable();
 __l7____Nc____mQ__fi :
 __l7____Nc____uQ = 0 ;
 __l7____Nc____wQ__bytesize = sizeof ( __l7____Nc____wQ____CF )* __l7____Kc__z ; 
 __l7____Nc____wQ____end :
 memcpy (( char *) __l7____Nc__mem ,( char *) name__contents , __l7__len_x ); memcpy (( char *) __l7____Nc__mem + __l7__len_x ,( char *) __l7____Ic____m__contents , __l7__len_y );(( char *) __l7____Nc__mem )[ __l7__total_len ]=0; 
 __l7____Qc__contents = __l7____Nc__mem ;
 __h7____TQ = __l7____Nc__self____TQ ;
 __h7__acquired = __h7__acquired ;
 __h7__size = __h7__size ;
 __h7__allocated = __h7__allocated ;
 __h7____dynamic_entry = __h7____dynamic_entry ;
 __m7____vh__length = strlen ( __j7 ); __m7____vh__contents =( ptr ) __j7 ; __m7____vh__first = __j7 [0]; __m7____vh__noptr =( ptr ) __m7____vh__noptr ; 
 __m7____vh____m__contents = __m7____vh__contents ;
 __m7__len_x = __m7____vh__length ; __m7__len_y = __l7__total_len ; __m7__total_len = __m7__len_x + __m7__len_y ; __m7__first = __m7____vh__length ? __m7____vh__first : __l7__first ; 
 __m7____xh = 1 ;
 __m7____yh__z = __m7__total_len + __m7____xh ; 
 __m7____yh____end :
 __m7____zh = 0 ;
 __m7____1h____iQ = __h7__acquired ;
 __m7____1h____jQ__z =(! __m7____1h____iQ ); 
 __m7____1h____jQ____end :
 if(! __m7____1h____jQ__z )goto __m7____1h____hQ__fi ;
 __m7____1h____kQ = "Did not initialize Dynamic" ;
 goto __m7____1h____lQ____oD ;
 __builtin_unreachable();
 __m7____1h____hQ__fi :
 __m7____1h__next_size = __h7__size +1; __m7____1h__success = true ; __m7____1h__self__allocated__prev = __h7__allocated ; if ( __m7____1h__next_size >= __h7__allocated ) { __h7__allocated = __h7__allocated + __h7__allocated /2+1; __m7____1h__next_acquired =( ptr )((( ptr **) __h7__acquired )[0]? __runtime_realloc ((( ptr **) __h7__acquired )[0], __h7__allocated * sizeof ( ptr ), __m7____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __h7__allocated * sizeof ( ptr ))); if ( __m7____1h__success = __m7____1h__next_acquired )(( ptr **) __h7__acquired )[0]=( ptr *) __m7____1h__next_acquired ; } if ( __m7____1h__success ) { __m7____1h__mem =( ptr ) __runtime_alloc ( __m7____yh__z * sizeof ( __m7____1h____gQ )); if ( __m7____1h__success = __m7____1h__mem ) {(( ptr **) __h7__acquired )[0][ __h7__size ]= __m7____1h__mem ; __h7__size = __m7____1h__next_size ; } } 
 __m7____1h____nQ__x = __m7____1h__success ;
 __m7____1h____nQ__z =(! __m7____1h____nQ__x ); 
 __m7____1h____nQ____end :
 if(! __m7____1h____nQ__z )goto __m7____1h____mQ__fi ;
 __m7____1h____oQ = "Failed a Dynamic allocation" ;
 goto __m7____1h____pQ____oD ;
 __builtin_unreachable();
 __m7____1h____mQ__fi :
 __m7____1h____uQ = 0 ;
 __m7____1h____wQ__bytesize = sizeof ( __m7____1h____wQ____CF )* __m7____yh__z ; 
 __m7____1h____wQ____end :
 memcpy (( char *) __m7____1h__mem ,( char *) __m7____vh____m__contents , __m7__len_x ); memcpy (( char *) __m7____1h__mem + __m7__len_x ,( char *) __l7____Qc__contents , __m7__len_y );(( char *) __m7____1h__mem )[ __m7__total_len ]=0; 
 __m7____4h__contents = __m7____1h__mem ;
 __h7____TQ = __m7____1h__self____TQ ;
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
 __s7____state -> command__contents = __m7____4h__contents ;
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
 __x7____Ic__length = strlen ( __w7 ); __x7____Ic__contents =( ptr ) __w7 ; __x7____Ic__first = __w7 [0]; __x7____Ic__noptr =( ptr ) __x7____Ic__noptr ; 
 __x7____Ic____m__contents = __x7____Ic__contents ;
 __x7__len_x = name__length ; __x7__len_y = __x7____Ic__length ; __x7__total_len = __x7__len_x + __x7__len_y ; __x7__first = name__length ? name__first : __x7____Ic__first ; 
 __x7____Jc = 1 ;
 __x7____Kc__z = __x7__total_len + __x7____Jc ; 
 __x7____Kc____end :
 __x7____Lc = 0 ;
 __x7____Nc____iQ = __p7__acquired ;
 __x7____Nc____jQ__z =(! __x7____Nc____iQ ); 
 __x7____Nc____jQ____end :
 if(! __x7____Nc____jQ__z )goto __x7____Nc____hQ__fi ;
 __x7____Nc____kQ = "Did not initialize Dynamic" ;
 goto __x7____Nc____lQ____oD ;
 __builtin_unreachable();
 __x7____Nc____hQ__fi :
 __x7____Nc__next_size = __p7__size +1; __x7____Nc__success = true ; __x7____Nc__self__allocated__prev = __p7__allocated ; if ( __x7____Nc__next_size >= __p7__allocated ) { __p7__allocated = __p7__allocated + __p7__allocated /2+1; __x7____Nc__next_acquired =( ptr )((( ptr **) __p7__acquired )[0]? __runtime_realloc ((( ptr **) __p7__acquired )[0], __p7__allocated * sizeof ( ptr ), __x7____Nc__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __p7__allocated * sizeof ( ptr ))); if ( __x7____Nc__success = __x7____Nc__next_acquired )(( ptr **) __p7__acquired )[0]=( ptr *) __x7____Nc__next_acquired ; } if ( __x7____Nc__success ) { __x7____Nc__mem =( ptr ) __runtime_alloc ( __x7____Kc__z * sizeof ( __x7____Nc____gQ )); if ( __x7____Nc__success = __x7____Nc__mem ) {(( ptr **) __p7__acquired )[0][ __p7__size ]= __x7____Nc__mem ; __p7__size = __x7____Nc__next_size ; } } 
 __x7____Nc____nQ__x = __x7____Nc__success ;
 __x7____Nc____nQ__z =(! __x7____Nc____nQ__x ); 
 __x7____Nc____nQ____end :
 if(! __x7____Nc____nQ__z )goto __x7____Nc____mQ__fi ;
 __x7____Nc____oQ = "Failed a Dynamic allocation" ;
 goto __x7____Nc____pQ____oD ;
 __builtin_unreachable();
 __x7____Nc____mQ__fi :
 __x7____Nc____uQ = 0 ;
 __x7____Nc____wQ__bytesize = sizeof ( __x7____Nc____wQ____CF )* __x7____Kc__z ; 
 __x7____Nc____wQ____end :
 memcpy (( char *) __x7____Nc__mem ,( char *) name__contents , __x7__len_x ); memcpy (( char *) __x7____Nc__mem + __x7__len_x ,( char *) __x7____Ic____m__contents , __x7__len_y );(( char *) __x7____Nc__mem )[ __x7__total_len ]=0; 
 __x7____Qc__contents = __x7____Nc__mem ;
 __p7____TQ = __x7____Nc__self____TQ ;
 __p7__acquired = __p7__acquired ;
 __p7__size = __p7__size ;
 __p7__allocated = __p7__allocated ;
 __p7____dynamic_entry = __p7____dynamic_entry ;
 __y7____vh__length = strlen ( __v7 ); __y7____vh__contents =( ptr ) __v7 ; __y7____vh__first = __v7 [0]; __y7____vh__noptr =( ptr ) __y7____vh__noptr ; 
 __y7____vh____m__contents = __y7____vh__contents ;
 __y7__len_x = __y7____vh__length ; __y7__len_y = __x7__total_len ; __y7__total_len = __y7__len_x + __y7__len_y ; __y7__first = __y7____vh__length ? __y7____vh__first : __x7__first ; 
 __y7____xh = 1 ;
 __y7____yh__z = __y7__total_len + __y7____xh ; 
 __y7____yh____end :
 __y7____zh = 0 ;
 __y7____1h____iQ = __p7__acquired ;
 __y7____1h____jQ__z =(! __y7____1h____iQ ); 
 __y7____1h____jQ____end :
 if(! __y7____1h____jQ__z )goto __y7____1h____hQ__fi ;
 __y7____1h____kQ = "Did not initialize Dynamic" ;
 goto __y7____1h____lQ____oD ;
 __builtin_unreachable();
 __y7____1h____hQ__fi :
 __y7____1h__next_size = __p7__size +1; __y7____1h__success = true ; __y7____1h__self__allocated__prev = __p7__allocated ; if ( __y7____1h__next_size >= __p7__allocated ) { __p7__allocated = __p7__allocated + __p7__allocated /2+1; __y7____1h__next_acquired =( ptr )((( ptr **) __p7__acquired )[0]? __runtime_realloc ((( ptr **) __p7__acquired )[0], __p7__allocated * sizeof ( ptr ), __y7____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __p7__allocated * sizeof ( ptr ))); if ( __y7____1h__success = __y7____1h__next_acquired )(( ptr **) __p7__acquired )[0]=( ptr *) __y7____1h__next_acquired ; } if ( __y7____1h__success ) { __y7____1h__mem =( ptr ) __runtime_alloc ( __y7____yh__z * sizeof ( __y7____1h____gQ )); if ( __y7____1h__success = __y7____1h__mem ) {(( ptr **) __p7__acquired )[0][ __p7__size ]= __y7____1h__mem ; __p7__size = __y7____1h__next_size ; } } 
 __y7____1h____nQ__x = __y7____1h__success ;
 __y7____1h____nQ__z =(! __y7____1h____nQ__x ); 
 __y7____1h____nQ____end :
 if(! __y7____1h____nQ__z )goto __y7____1h____mQ__fi ;
 __y7____1h____oQ = "Failed a Dynamic allocation" ;
 goto __y7____1h____pQ____oD ;
 __builtin_unreachable();
 __y7____1h____mQ__fi :
 __y7____1h____uQ = 0 ;
 __y7____1h____wQ__bytesize = sizeof ( __y7____1h____wQ____CF )* __y7____yh__z ; 
 __y7____1h____wQ____end :
 memcpy (( char *) __y7____1h__mem ,( char *) __y7____vh____m__contents , __y7__len_x ); memcpy (( char *) __y7____1h__mem + __y7__len_x ,( char *) __x7____Qc__contents , __y7__len_y );(( char *) __y7____1h__mem )[ __y7__total_len ]=0; 
 __y7____4h__contents = __y7____1h__mem ;
 __p7____TQ = __y7____1h__self____TQ ;
 __p7__acquired = __p7__acquired ;
 __p7__size = __p7__size ;
 __p7__allocated = __p7__allocated ;
 __p7____dynamic_entry = __p7____dynamic_entry ;
 printf ( "%s\n" ,( char *) __y7____4h__contents ); 
 __z7____end :
 goto __r7__el ;
 __r7__fi :
 __07 = "[ \033[32mOK\033[0m ] " ;
 __17 = ".s" ;
 __27____Ic__length = strlen ( __17 ); __27____Ic__contents =( ptr ) __17 ; __27____Ic__first = __17 [0]; __27____Ic__noptr =( ptr ) __27____Ic__noptr ; 
 __27____Ic____m__contents = __27____Ic__contents ;
 __27__len_x = name__length ; __27__len_y = __27____Ic__length ; __27__total_len = __27__len_x + __27__len_y ; __27__first = name__length ? name__first : __27____Ic__first ; 
 __27____Jc = 1 ;
 __27____Kc__z = __27__total_len + __27____Jc ; 
 __27____Kc____end :
 __27____Lc = 0 ;
 __27____Nc____iQ = __p7__acquired ;
 __27____Nc____jQ__z =(! __27____Nc____iQ ); 
 __27____Nc____jQ____end :
 if(! __27____Nc____jQ__z )goto __27____Nc____hQ__fi ;
 __27____Nc____kQ = "Did not initialize Dynamic" ;
 goto __27____Nc____lQ____oD ;
 __builtin_unreachable();
 __27____Nc____hQ__fi :
 __27____Nc__next_size = __p7__size +1; __27____Nc__success = true ; __27____Nc__self__allocated__prev = __p7__allocated ; if ( __27____Nc__next_size >= __p7__allocated ) { __p7__allocated = __p7__allocated + __p7__allocated /2+1; __27____Nc__next_acquired =( ptr )((( ptr **) __p7__acquired )[0]? __runtime_realloc ((( ptr **) __p7__acquired )[0], __p7__allocated * sizeof ( ptr ), __27____Nc__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __p7__allocated * sizeof ( ptr ))); if ( __27____Nc__success = __27____Nc__next_acquired )(( ptr **) __p7__acquired )[0]=( ptr *) __27____Nc__next_acquired ; } if ( __27____Nc__success ) { __27____Nc__mem =( ptr ) __runtime_alloc ( __27____Kc__z * sizeof ( __27____Nc____gQ )); if ( __27____Nc__success = __27____Nc__mem ) {(( ptr **) __p7__acquired )[0][ __p7__size ]= __27____Nc__mem ; __p7__size = __27____Nc__next_size ; } } 
 __27____Nc____nQ__x = __27____Nc__success ;
 __27____Nc____nQ__z =(! __27____Nc____nQ__x ); 
 __27____Nc____nQ____end :
 if(! __27____Nc____nQ__z )goto __27____Nc____mQ__fi ;
 __27____Nc____oQ = "Failed a Dynamic allocation" ;
 goto __27____Nc____pQ____oD ;
 __builtin_unreachable();
 __27____Nc____mQ__fi :
 __27____Nc____uQ = 0 ;
 __27____Nc____wQ__bytesize = sizeof ( __27____Nc____wQ____CF )* __27____Kc__z ; 
 __27____Nc____wQ____end :
 memcpy (( char *) __27____Nc__mem ,( char *) name__contents , __27__len_x ); memcpy (( char *) __27____Nc__mem + __27__len_x ,( char *) __27____Ic____m__contents , __27__len_y );(( char *) __27____Nc__mem )[ __27__total_len ]=0; 
 __27____Qc__contents = __27____Nc__mem ;
 __p7____TQ = __27____Nc__self____TQ ;
 __p7__acquired = __p7__acquired ;
 __p7__size = __p7__size ;
 __p7__allocated = __p7__allocated ;
 __p7____dynamic_entry = __p7____dynamic_entry ;
 __37____vh__length = strlen ( __07 ); __37____vh__contents =( ptr ) __07 ; __37____vh__first = __07 [0]; __37____vh__noptr =( ptr ) __37____vh__noptr ; 
 __37____vh____m__contents = __37____vh__contents ;
 __37__len_x = __37____vh__length ; __37__len_y = __27__total_len ; __37__total_len = __37__len_x + __37__len_y ; __37__first = __37____vh__length ? __37____vh__first : __27__first ; 
 __37____xh = 1 ;
 __37____yh__z = __37__total_len + __37____xh ; 
 __37____yh____end :
 __37____zh = 0 ;
 __37____1h____iQ = __p7__acquired ;
 __37____1h____jQ__z =(! __37____1h____iQ ); 
 __37____1h____jQ____end :
 if(! __37____1h____jQ__z )goto __37____1h____hQ__fi ;
 __37____1h____kQ = "Did not initialize Dynamic" ;
 goto __37____1h____lQ____oD ;
 __builtin_unreachable();
 __37____1h____hQ__fi :
 __37____1h__next_size = __p7__size +1; __37____1h__success = true ; __37____1h__self__allocated__prev = __p7__allocated ; if ( __37____1h__next_size >= __p7__allocated ) { __p7__allocated = __p7__allocated + __p7__allocated /2+1; __37____1h__next_acquired =( ptr )((( ptr **) __p7__acquired )[0]? __runtime_realloc ((( ptr **) __p7__acquired )[0], __p7__allocated * sizeof ( ptr ), __37____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __p7__allocated * sizeof ( ptr ))); if ( __37____1h__success = __37____1h__next_acquired )(( ptr **) __p7__acquired )[0]=( ptr *) __37____1h__next_acquired ; } if ( __37____1h__success ) { __37____1h__mem =( ptr ) __runtime_alloc ( __37____yh__z * sizeof ( __37____1h____gQ )); if ( __37____1h__success = __37____1h__mem ) {(( ptr **) __p7__acquired )[0][ __p7__size ]= __37____1h__mem ; __p7__size = __37____1h__next_size ; } } 
 __37____1h____nQ__x = __37____1h__success ;
 __37____1h____nQ__z =(! __37____1h____nQ__x ); 
 __37____1h____nQ____end :
 if(! __37____1h____nQ__z )goto __37____1h____mQ__fi ;
 __37____1h____oQ = "Failed a Dynamic allocation" ;
 goto __37____1h____pQ____oD ;
 __builtin_unreachable();
 __37____1h____mQ__fi :
 __37____1h____uQ = 0 ;
 __37____1h____wQ__bytesize = sizeof ( __37____1h____wQ____CF )* __37____yh__z ; 
 __37____1h____wQ____end :
 memcpy (( char *) __37____1h__mem ,( char *) __37____vh____m__contents , __37__len_x ); memcpy (( char *) __37____1h__mem + __37__len_x ,( char *) __27____Qc__contents , __37__len_y );(( char *) __37____1h__mem )[ __37__total_len ]=0; 
 __37____4h__contents = __37____1h__mem ;
 __p7____TQ = __37____1h__self____TQ ;
 __p7__acquired = __p7__acquired ;
 __p7__size = __p7__size ;
 __p7__allocated = __p7__allocated ;
 __p7____dynamic_entry = __p7____dynamic_entry ;
 printf ( "%s\n" ,( char *) __37____4h__contents ); 
 __47____end :
 __r7__el :
 __end :
goto __return;

// ERROR HANDLING
__x7____Nc____pQ____oD :
 printf ( "%s\n" , __x7____Nc____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__37____1h____lQ____oD :
 printf ( "%s\n" , __37____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__37____1h____pQ____oD :
 printf ( "%s\n" , __37____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__l7____Nc____lQ____oD :
 printf ( "%s\n" , __l7____Nc____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__l7____Nc____pQ____oD :
 printf ( "%s\n" , __l7____Nc____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__x7____Nc____lQ____oD :
 printf ( "%s\n" , __x7____Nc____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__m7____1h____lQ____oD :
 printf ( "%s\n" , __m7____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__m7____1h____pQ____oD :
 printf ( "%s\n" , __m7____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__y7____1h____lQ____oD :
 printf ( "%s\n" , __y7____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__y7____1h____pQ____oD :
 printf ( "%s\n" , __y7____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__t7 :
printf("Runtime error from run __s7 \n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
__27____Nc____lQ____oD :
 printf ( "%s\n" , __27____Nc____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__27____Nc____pQ____oD :
 printf ( "%s\n" , __27____Nc____oQ ); 
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


void all__821(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct all__821__state *__state=(struct all__821__state*)__void__state;
struct std_test__818__state* __d8____state = 0 ;
 struct std_test__818__state* __f8____state = 0 ;
 struct std_test__818__state* __h8____state = 0 ;
 struct std_test__818__state* __j8____state = 0 ;
 struct std_test__818__state* __l8____state = 0 ;
 struct std_test__818__state* __n8____state = 0 ;
 struct std_test__818__state* __p8____state = 0 ;
 struct std_test__818__state* __r8____state = 0 ;
 struct std_test__818__state* __t8____state = 0 ;
 struct std_test__818__state* __v8____state = 0 ;
 struct std_test__818__state* __x8____state = 0 ;
 struct std_test__818__state* __z8____state = 0 ;
 struct std_test__818__state* __18____state = 0 ;
 struct std_test__818__state* __38____state = 0 ;
 struct std_test__818__state* __58____state = 0 ;
 struct std_test__818__state* __78____state = 0 ;
 struct std_test__818__state* __98____state = 0 ;
 struct std_test__818__state* __B9____state = 0 ;
 struct std_test__818__state* __D9____state = 0 ;
 struct std_test__818__state* __F9____state = 0 ;
 struct std_test__818__state* __H9____state = 0 ;
cstr __G9=0;
errcode __F9__err=0;
ptr __F9____task=0;
cstr __E9=0;
ptr __D9____task=0;
errcode __B9__err=0;
cstr __A9=0;
ptr __98____task=0;
cstr __88=0;
errcode __58__err=0;
ptr __58____task=0;
cstr __48=0;
errcode __38__err=0;
ptr __38____task=0;
cstr __28=0;
errcode __18__err=0;
ptr __18____task=0;
cstr __08=0;
cstr __y8=0;
ptr __x8____task=0;
cstr __w8=0;
cstr __u8=0;
cstr __s8=0;
errcode __r8__err=0;
ptr __r8____task=0;
cstr __q8=0;
cstr __o8=0;
errcode __n8__err=0;
errcode __l8__err=0;
ptr __l8____task=0;
ptr __h8____task=0;
cstr __g8=0;
errcode __f8__err=0;
ptr __f8____task=0;
errcode __d8__err=0;
u64 i=0;
u64 __a8__value=0;
u64 __Y8____xD=0;
u64 __Y8____wD=0;
u64 __buffer_size=0;
ptr targets__dynamic=0;
cstr __X8=0;
u64 __V8__dynamic____buffer_capacity=0;
u64 __V8__dynamic____buffer_size=0;
u64 __V8__dynamic____buffer_alignment=0;
ptr __V8__surface=0;
ptr __V8__dynamic=0;
ptr __v8____task=0;
ptr __n8____task=0;
u64 __a8____0D__z=0;
u64 __Y8__start=0;
cstr __e8=0;
cstr __c8=0;
u64 __V8__dynamic____buffer_prev_capacity=0;
cstr __C9=0;
u64 __a8____zD=0;
errcode __78__err=0;
cstr __k8=0;
ptr __z8____task=0;
ptr __j8____task=0;
ptr __H9____task=0;
errcode __p8__err=0;
bool __a8____1D__z=0;
errcode __v8__err=0;
ptr __78____task=0;
errcode __z8__err=0;
u64 __Y8__sup=0;
u64 targets__dynamic____buffer_alignment=0;
cstr __68=0;
cstr __W8=0;
errcode __t8__err=0;
errcode __j8__err=0;
ptr __p8____task=0;
errcode __D9__err=0;
ptr __V8__dynamic____buffer_contents=0;
ptr __t8____task=0;
ptr __d8____task=0;
u64 targets__dynamic____buffer_size=0;
u64 __a8__self__pos=0;
cstr __m8=0;
errcode __98__err=0;
u64 __Y8__step=0;
errcode __x8__err=0;
ptr __B9____task=0;
u64 __Y8__pos=0;
errcode __H9__err=0;
cstr __i8=0;
errcode __h8__err=0;

// IMPLEMENTATION
__V8__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 __V8__surface = 0 ;
 __W8 = "buffers" ;
 if(! __V8__dynamic )goto __result__buffer_error ;
 __V8__dynamic____buffer_alignment = 1 ;
 __V8__dynamic____buffer_size = ((u64*) __V8__dynamic )[1] ;
 __V8__dynamic____buffer_capacity = ((u64*) __V8__dynamic )[2] & ~(1ULL << 63) ;
 if( __V8__dynamic____buffer_size >= __V8__dynamic____buffer_capacity ){ if( ((u64*) __V8__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __V8__dynamic____buffer_prev_capacity = __V8__dynamic____buffer_capacity ;
 __V8__dynamic____buffer_capacity = __V8__dynamic____buffer_capacity +( __V8__dynamic____buffer_capacity >>2)+1; if( __V8__dynamic____buffer_size ) ((void**) __V8__dynamic )[0] = __runtime_realloc((u64*)((void**) __V8__dynamic )[0],  __V8__dynamic____buffer_capacity * __V8__dynamic____buffer_alignment *sizeof(u64),  __V8__dynamic____buffer_prev_capacity * __V8__dynamic____buffer_alignment *sizeof(u64)); else ((void**) __V8__dynamic )[0] = __runtime_alloc( __V8__dynamic____buffer_capacity * __V8__dynamic____buffer_alignment *sizeof(u64)); ((u64*) __V8__dynamic )[2] = __V8__dynamic____buffer_capacity ;
 __V8__dynamic____buffer_contents = (ptr)((void**) __V8__dynamic )[0] ;
 if( ! __V8__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  __V8__dynamic____buffer_contents = (ptr)(((u64*) __V8__dynamic )[0]) ;
 ((u64*) __V8__dynamic )[1] = __V8__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __V8__dynamic____buffer_contents )[ __V8__dynamic____buffer_size * __V8__dynamic____buffer_alignment ], & __W8 , sizeof(u64)); __X8 = "bbuffer" ;
 if(! __V8__dynamic )goto __result__buffer_error ;
 __V8__dynamic____buffer_alignment = 1 ;
 __V8__dynamic____buffer_size = ((u64*) __V8__dynamic )[1] ;
 __V8__dynamic____buffer_capacity = ((u64*) __V8__dynamic )[2] & ~(1ULL << 63) ;
 if( __V8__dynamic____buffer_size >= __V8__dynamic____buffer_capacity ){ if( ((u64*) __V8__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __V8__dynamic____buffer_prev_capacity = __V8__dynamic____buffer_capacity ;
 __V8__dynamic____buffer_capacity = __V8__dynamic____buffer_capacity +( __V8__dynamic____buffer_capacity >>2)+1; if( __V8__dynamic____buffer_size ) ((void**) __V8__dynamic )[0] = __runtime_realloc((u64*)((void**) __V8__dynamic )[0],  __V8__dynamic____buffer_capacity * __V8__dynamic____buffer_alignment *sizeof(u64),  __V8__dynamic____buffer_prev_capacity * __V8__dynamic____buffer_alignment *sizeof(u64)); else ((void**) __V8__dynamic )[0] = __runtime_alloc( __V8__dynamic____buffer_capacity * __V8__dynamic____buffer_alignment *sizeof(u64)); ((u64*) __V8__dynamic )[2] = __V8__dynamic____buffer_capacity ;
 __V8__dynamic____buffer_contents = (ptr)((void**) __V8__dynamic )[0] ;
 if( ! __V8__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  __V8__dynamic____buffer_contents = (ptr)(((u64*) __V8__dynamic )[0]) ;
 ((u64*) __V8__dynamic )[1] = __V8__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __V8__dynamic____buffer_contents )[ __V8__dynamic____buffer_size * __V8__dynamic____buffer_alignment ], & __X8 , sizeof(u64)); targets__dynamic = __V8__dynamic ;
 __buffer_size = targets__dynamic ? ((u64*) targets__dynamic )[1]:0 ;
 __Y8__sup = __buffer_size ;
 __Y8____wD = 0 ;
 __Y8____xD = 1 ;
 __Y8__start = __Y8____wD ;
 __Y8__step = __Y8____xD ;
 __Y8__pos = __Y8____wD ;
 __Z8__loop :
 __a8__self__pos = __Y8__pos ;
 __a8__value = i ;
 __a8__value = __a8__self__pos ;
 __a8____zD = 1 ;
 __a8____0D__z = __a8__self__pos + __a8____zD ; 
 __a8____0D____end :
 __a8__self__pos = __a8____0D__z ;
 __a8____1D__z = __a8__self__pos <= __Y8__sup ; 
 __a8____1D____end :
 __Y8__pos = __a8__self__pos ;
 if(! __a8____1D__z )goto __Z8__while ;
 if(! targets__dynamic )goto __result__buffer_error ;
 targets__dynamic____buffer_alignment = 1 ;
 targets__dynamic____buffer_size = ((u64*) targets__dynamic )[1] ;
 if( __a8__value >= targets__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(& __c8 , &((u64*)((u64*) targets__dynamic )[0])[ __a8__value * targets__dynamic____buffer_alignment +0], sizeof( cstr )) ;
 __d8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __d8____state ) ;
 __d8____state -> name = __c8 ;
 __d8____task = __smolambda_add_task ( std_test__818 , __d8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __d8____task ) ;
 if( __d8__err ) goto  __result_unhandled_error ;
 goto __Z8__loop ;
 __Z8__while :
 __e8 = "buffers" ;
 __f8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __f8____state ) ;
 __f8____state -> name = __e8 ;
 __f8____task = __smolambda_add_task ( std_test__818 , __f8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __f8____task ) ;
 if( __f8__err ) goto  __result_unhandled_error ;
 __g8 = "bbuffer" ;
 __h8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __h8____state ) ;
 __h8____state -> name = __g8 ;
 __h8____task = __smolambda_add_task ( std_test__818 , __h8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __h8____task ) ;
 if( __h8__err ) goto  __result_unhandled_error ;
 __i8 = "bufferconst" ;
 __j8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __j8____state ) ;
 __j8____state -> name = __i8 ;
 __j8____task = __smolambda_add_task ( std_test__818 , __j8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __j8____task ) ;
 if( __j8__err ) goto  __result_unhandled_error ;
 __k8 = "buffergrow" ;
 __l8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __l8____state ) ;
 __l8____state -> name = __k8 ;
 __l8____task = __smolambda_add_task ( std_test__818 , __l8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __l8____task ) ;
 if( __l8__err ) goto  __result_unhandled_error ;
 __m8 = "effvec" ;
 __n8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __n8____state ) ;
 __n8____state -> name = __m8 ;
 __n8____task = __smolambda_add_task ( std_test__818 , __n8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __n8____task ) ;
 if( __n8__err ) goto  __result_unhandled_error ;
 __o8 = "fail" ;
 __p8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __p8____state ) ;
 __p8____state -> name = __o8 ;
 __p8____task = __smolambda_add_task ( std_test__818 , __p8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __p8____task ) ;
 if( __p8__err ) goto  __result_unhandled_error ;
 __q8 = "file" ;
 __r8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __r8____state ) ;
 __r8____state -> name = __q8 ;
 __r8____task = __smolambda_add_task ( std_test__818 , __r8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __r8____task ) ;
 if( __r8__err ) goto  __result_unhandled_error ;
 __s8 = "filesize" ;
 __t8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __t8____state ) ;
 __t8____state -> name = __s8 ;
 __t8____task = __smolambda_add_task ( std_test__818 , __t8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __t8____task ) ;
 if( __t8__err ) goto  __result_unhandled_error ;
 __u8 = "finally" ;
 __v8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __v8____state ) ;
 __v8____state -> name = __u8 ;
 __v8____task = __smolambda_add_task ( std_test__818 , __v8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __v8____task ) ;
 if( __v8__err ) goto  __result_unhandled_error ;
 __w8 = "nom" ;
 __x8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __x8____state ) ;
 __x8____state -> name = __w8 ;
 __x8____task = __smolambda_add_task ( std_test__818 , __x8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __x8____task ) ;
 if( __x8__err ) goto  __result_unhandled_error ;
 __y8 = "mem" ;
 __z8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __z8____state ) ;
 __z8____state -> name = __y8 ;
 __z8____task = __smolambda_add_task ( std_test__818 , __z8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __z8____task ) ;
 if( __z8__err ) goto  __result_unhandled_error ;
 __08 = "union" ;
 __18____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __18____state ) ;
 __18____state -> name = __08 ;
 __18____task = __smolambda_add_task ( std_test__818 , __18____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __18____task ) ;
 if( __18__err ) goto  __result_unhandled_error ;
 __28 = "memtest" ;
 __38____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __38____state ) ;
 __38____state -> name = __28 ;
 __38____task = __smolambda_add_task ( std_test__818 , __38____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __38____task ) ;
 if( __38__err ) goto  __result_unhandled_error ;
 __48 = "mutpoint" ;
 __58____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __58____state ) ;
 __58____state -> name = __48 ;
 __58____task = __smolambda_add_task ( std_test__818 , __58____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __58____task ) ;
 if( __58__err ) goto  __result_unhandled_error ;
 __68 = "range_test" ;
 __78____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __78____state ) ;
 __78____state -> name = __68 ;
 __78____task = __smolambda_add_task ( std_test__818 , __78____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __78____task ) ;
 if( __78__err ) goto  __result_unhandled_error ;
 __88 = "ref" ;
 __98____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __98____state ) ;
 __98____state -> name = __88 ;
 __98____task = __smolambda_add_task ( std_test__818 , __98____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __98____task ) ;
 if( __98__err ) goto  __result_unhandled_error ;
 __A9 = "strcat" ;
 __B9____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __B9____state ) ;
 __B9____state -> name = __A9 ;
 __B9____task = __smolambda_add_task ( std_test__818 , __B9____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __B9____task ) ;
 if( __B9__err ) goto  __result_unhandled_error ;
 __C9 = "vec" ;
 __D9____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __D9____state ) ;
 __D9____state -> name = __C9 ;
 __D9____task = __smolambda_add_task ( std_test__818 , __D9____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __D9____task ) ;
 if( __D9__err ) goto  __result_unhandled_error ;
 __E9 = "virtfile" ;
 __F9____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __F9____state ) ;
 __F9____state -> name = __E9 ;
 __F9____task = __smolambda_add_task ( std_test__818 , __F9____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __F9____task ) ;
 if( __F9__err ) goto  __result_unhandled_error ;
 __G9 = "accessvar" ;
 __H9____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __H9____state ) ;
 __H9____state -> name = __G9 ;
 __H9____task = __smolambda_add_task ( std_test__818 , __H9____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __H9____task ) ;
 if( __H9__err ) goto  __result_unhandled_error ;
 __end :
goto __return;

// ERROR HANDLING
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__result__buffer_error :
printf("Buffer error\n");
__result__errocode=__BUFFER__ERROR;
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
if( __V8__dynamic ){if((u64*)((u64*) __V8__dynamic )[2]) __runtime_free((u64*)((u64*) __V8__dynamic )[0]) ;
 __runtime_free( __V8__dynamic ) ;
 __V8__dynamic = 0 ;
 }__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}


void std_test__818(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__818__state *__state=(struct std_test__818__state*)__void__state;
struct run__816__state* __S7____state = 0 ;
cstr name= __state->name;
nominal __d7____1h__self____TQ=0;
ptr __d7____4h__contents=0;
char __d7____1h____wQ____CF=0;
u64 __d7____1h____wQ__bytesize=0;
char __d7____1h____uQ=0;
ptr __d7____1h__next_acquired=0;
bool __d7____1h__success=0;
u64 __d7____xh=0;
char __d7__first=0;
u64 __d7__len_y=0;
ptr __d7____vh__noptr=0;
u64 __d7____vh__length=0;
u64 __c7____Fb____wQ__bytesize=0;
bool __c7____Fb____nQ__z=0;
bool __c7____Fb____nQ__x=0;
char __d7____zh=0;
char __c7____Fb____gQ=0;
u64 __c7____Fb__self__allocated__prev=0;
u64 __d7__total_len=0;
bool __c7____Fb____jQ__z=0;
bool __c7____Fb____iQ=0;
u64 __c7____Cb__z=0;
char __c7__first=0;
u64 __c7__total_len=0;
u64 __c7__len_y=0;
ptr __c7____Ab____m__contents=0;
ptr __c7____Ab__noptr=0;
u64 __c7____Bb=0;
u64 __c7____Ab__length=0;
ptr __c7____9a____m__contents=0;
ptr __c7____9a__contents=0;
u64 __c7____9a__length=0;
cstr __b7=0;
ptr __c7____Fb__mem=0;
bool __d7____1h____nQ__x=0;
nominal __Y7____1h__self____TQ=0;
ptr __Y7____4h__contents=0;
char __Y7____1h____wQ____CF=0;
u64 __Y7____1h____wQ__bytesize=0;
cstr __Y7____1h____oQ=0;
u64 __d7____yh__z=0;
ptr __d7____vh__contents=0;
bool __d7____1h____iQ=0;
bool __Y7____1h____nQ__z=0;
bool __Y7____1h____nQ__x=0;
ptr __Y7____1h__mem=0;
char __c7____9a__first=0;
u64 __Y7____1h__next_size=0;
char __Y7____zh=0;
u64 __Y7__total_len=0;
u64 __Y7__len_y=0;
ptr __c7____9a__noptr=0;
u64 __Y7__len_x=0;
ptr __Y7____vh____m__contents=0;
ptr __c7____Ab__contents=0;
char __X7____Fb____wQ____CF=0;
ptr __X7____Ib__contents=0;
bool __X7____Fb____nQ__z=0;
char __X7____Fb____gQ=0;
ptr __X7____Fb__mem=0;
u64 __X7____Fb__self__allocated__prev=0;
u64 __X7____Fb__next_size=0;
cstr __X7____Fb____kQ=0;
char __d7____vh__first=0;
char __Y7__first=0;
bool __X7____Fb____jQ__z=0;
bool __X7____Fb____iQ=0;
u64 __Y7____yh__z=0;
char __X7____Db=0;
u64 __X7____Cb__z=0;
u64 __X7____Bb=0;
char __X7__first=0;
u64 __X7__len_y=0;
u64 __X7__len_x=0;
char __X7____Ab__first=0;
ptr __X7____9a____m__contents=0;
char __X7____9a__first=0;
cstr __W7=0;
ptr __S7____task=0;
ptr __L7____Fb__next_acquired=0;
nominal __c7____Fb__self____TQ=0;
u64 __M7____1h____wQ__bytesize=0;
u64 command__length=0;
ptr __M7____vh__contents=0;
u64 __d7____1h__next_size=0;
u64 __d7____1h__self__allocated__prev=0;
char __Y7____vh__first=0;
char __c7____Fb____wQ____CF=0;
u64 __M7__len_x=0;
u64 __X7____9a__length=0;
ptr __Y7____vh__noptr=0;
ptr __X7____9a__noptr=0;
cstr __M7____1h____oQ=0;
char __c7____Fb____uQ=0;
errcode __S7__err=0;
ptr __Y7____1h__next_acquired=0;
cstr __d7____1h____kQ=0;
bool __d7____1h____nQ__z=0;
bool __L7____Fb____nQ__z=0;
bool __M7____1h____nQ__x=0;
bool __X7____Fb__success=0;
bool __Y7____1h____jQ__z=0;
bool __Y7____1h__success=0;
cstr __V7=0;
u64 __X7____Fb____wQ__bytesize=0;
u64 __d7__len_x=0;
bool __M7____1h__success=0;
char __Y7____1h____uQ=0;
cstr __c7____Fb____oQ=0;
ptr __M7____vh__noptr=0;
ptr command__contents=0;
ptr __X7____Ab__contents=0;
bool __L7____Fb____nQ__x=0;
ptr __M7____vh____m__contents=0;
nominal command____c=0;
ptr __Y7____vh__contents=0;
u64 __L7__len_y=0;
cstr __L7____Fb____oQ=0;
char __d7____1h____gQ=0;
ptr __c7____Fb__next_acquired=0;
ptr __X7____Ab____m__contents=0;
char __M7____1h____uQ=0;
cstr __J7=0;
ptr __c7____Ib__contents=0;
u64 __P7__size=0;
bool __U7=0;
nominal __X7____Fb__self____TQ=0;
u64 __Y7____1h__self__allocated__prev=0;
ptr __L7____Ab__contents=0;
ptr __X7____Fb__next_acquired=0;
u64 __L7____Fb__next_size=0;
char __c7____Db=0;
nominal __M7____1h__self____TQ=0;
u64 __Y7____xh=0;
ptr __L7____Ab____m__contents=0;
char __c7____Ab__first=0;
bool __d7____1h____jQ__z=0;
u64 __Y7____vh__length=0;
cstr __X7____Fb____oQ=0;
ptr __d7____1h__mem=0;
u64 __P7____ZQ____dynamic_entry=0;
bool __c7____Fb__success=0;
u64 __H7____ZQ____VQ=0;
ptr __M7____4h__contents=0;
ptr command__memory=0;
bool __X7____Fb____nQ__x=0;
ptr __L7____9a__noptr=0;
char __Y7____1h____gQ=0;
u64 __P7____ZQ____UQ=0;
u64 __H7____ZQ____UQ=0;
u64 __H7____ZQ____dynamic_entry=0;
char command__first=0;
ptr __X7____Ab__noptr=0;
bool __M7____1h____iQ=0;
ptr __P7__acquired=0;
cstr __d7____1h____oQ=0;
ptr __H7__acquired=0;
u64 __H7__size=0;
u64 __L7____Fb____wQ__bytesize=0;
u64 __H7__allocated=0;
u64 __c7__len_x=0;
cstr __K7=0;
u64 __L7____9a__length=0;
ptr __L7____9a__contents=0;
ptr __X7____9a__contents=0;
char __L7____9a__first=0;
ptr __L7____9a____m__contents=0;
u64 __L7____Ab__length=0;
char __L7____Ab__first=0;
u64 __L7__len_x=0;
u64 __L7__total_len=0;
char __L7__first=0;
nominal __P7____TQ=0;
char __M7__first=0;
u64 __L7____Bb=0;
char __M7____vh__first=0;
u64 __L7____Cb__z=0;
char __L7____Db=0;
bool __L7____Fb____iQ=0;
cstr __c7____Fb____kQ=0;
cstr __L7____Fb____kQ=0;
bool __L7____Fb__success=0;
bool __L7____Fb____jQ__z=0;
ptr __L7____Ab__noptr=0;
u64 __M7____1h__self__allocated__prev=0;
u64 __L7____Fb__self__allocated__prev=0;
ptr __L7____Fb__mem=0;
u64 __M7__total_len=0;
char __L7____Fb____uQ=0;
ptr __d7____vh____m__contents=0;
cstr __a7=0;
char __L7____Fb____wQ____CF=0;
u64 __X7____Ab__length=0;
ptr __M7____1h__next_acquired=0;
u64 __H7____dynamic_entry=0;
ptr __M7____1h__mem=0;
cstr __Y7____1h____kQ=0;
ptr __H7____ZQ__acquired=0;
ptr __L7____Ib__contents=0;
nominal __H7____TQ=0;
nominal __L7____Fb__self____TQ=0;
char __L7____Fb____gQ=0;
u64 __M7____vh__length=0;
u64 __M7__len_y=0;
u64 __M7____xh=0;
u64 __M7____yh__z=0;
char __X7____Fb____uQ=0;
char __M7____zh=0;
u64 __X7__total_len=0;
bool __M7____1h____jQ__z=0;
cstr __M7____1h____kQ=0;
u64 __M7____1h__next_size=0;
char __M7____1h____gQ=0;
bool __M7____1h____nQ__z=0;
char __M7____1h____wQ____CF=0;
u64 __c7____Fb__next_size=0;
u64 __P7____dynamic_entry=0;
ptr __P7____ZQ__acquired=0;
bool __Y7____1h____iQ=0;
u64 __P7____ZQ____VQ=0;
u64 __P7__allocated=0;

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
 __L7____9a__length = strlen ( name ); __L7____9a__contents =( ptr ) name ; __L7____9a__first = name [0]; __L7____9a__noptr =( ptr ) __L7____9a__noptr ; 
 __L7____9a____m__contents = __L7____9a__contents ;
 __L7____Ab__length = strlen ( __K7 ); __L7____Ab__contents =( ptr ) __K7 ; __L7____Ab__first = __K7 [0]; __L7____Ab__noptr =( ptr ) __L7____Ab__noptr ; 
 __L7____Ab____m__contents = __L7____Ab__contents ;
 __L7__len_x = __L7____9a__length ; __L7__len_y = __L7____Ab__length ; __L7__total_len = __L7__len_x + __L7__len_y ; __L7__first = __L7____9a__length ? __L7____9a__first : __L7____Ab__first ; 
 __L7____Bb = 1 ;
 __L7____Cb__z = __L7__total_len + __L7____Bb ; 
 __L7____Cb____end :
 __L7____Db = 0 ;
 __L7____Fb____iQ = __H7__acquired ;
 __L7____Fb____jQ__z =(! __L7____Fb____iQ ); 
 __L7____Fb____jQ____end :
 if(! __L7____Fb____jQ__z )goto __L7____Fb____hQ__fi ;
 __L7____Fb____kQ = "Did not initialize Dynamic" ;
 goto __L7____Fb____lQ____oD ;
 __builtin_unreachable();
 __L7____Fb____hQ__fi :
 __L7____Fb__next_size = __H7__size +1; __L7____Fb__success = true ; __L7____Fb__self__allocated__prev = __H7__allocated ; if ( __L7____Fb__next_size >= __H7__allocated ) { __H7__allocated = __H7__allocated + __H7__allocated /2+1; __L7____Fb__next_acquired =( ptr )((( ptr **) __H7__acquired )[0]? __runtime_realloc ((( ptr **) __H7__acquired )[0], __H7__allocated * sizeof ( ptr ), __L7____Fb__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __H7__allocated * sizeof ( ptr ))); if ( __L7____Fb__success = __L7____Fb__next_acquired )(( ptr **) __H7__acquired )[0]=( ptr *) __L7____Fb__next_acquired ; } if ( __L7____Fb__success ) { __L7____Fb__mem =( ptr ) __runtime_alloc ( __L7____Cb__z * sizeof ( __L7____Fb____gQ )); if ( __L7____Fb__success = __L7____Fb__mem ) {(( ptr **) __H7__acquired )[0][ __H7__size ]= __L7____Fb__mem ; __H7__size = __L7____Fb__next_size ; } } 
 __L7____Fb____nQ__x = __L7____Fb__success ;
 __L7____Fb____nQ__z =(! __L7____Fb____nQ__x ); 
 __L7____Fb____nQ____end :
 if(! __L7____Fb____nQ__z )goto __L7____Fb____mQ__fi ;
 __L7____Fb____oQ = "Failed a Dynamic allocation" ;
 goto __L7____Fb____pQ____oD ;
 __builtin_unreachable();
 __L7____Fb____mQ__fi :
 __L7____Fb____uQ = 0 ;
 __L7____Fb____wQ__bytesize = sizeof ( __L7____Fb____wQ____CF )* __L7____Cb__z ; 
 __L7____Fb____wQ____end :
 memcpy (( char *) __L7____Fb__mem ,( char *) __L7____9a____m__contents , __L7__len_x ); memcpy (( char *) __L7____Fb__mem + __L7__len_x ,( char *) __L7____Ab____m__contents , __L7__len_y );(( char *) __L7____Fb__mem )[ __L7__total_len ]=0; 
 __L7____Ib__contents = __L7____Fb__mem ;
 __H7____TQ = __L7____Fb__self____TQ ;
 __H7__acquired = __H7__acquired ;
 __H7__size = __H7__size ;
 __H7__allocated = __H7__allocated ;
 __H7____dynamic_entry = __H7____dynamic_entry ;
 __M7____vh__length = strlen ( __J7 ); __M7____vh__contents =( ptr ) __J7 ; __M7____vh__first = __J7 [0]; __M7____vh__noptr =( ptr ) __M7____vh__noptr ; 
 __M7____vh____m__contents = __M7____vh__contents ;
 __M7__len_x = __M7____vh__length ; __M7__len_y = __L7__total_len ; __M7__total_len = __M7__len_x + __M7__len_y ; __M7__first = __M7____vh__length ? __M7____vh__first : __L7__first ; 
 __M7____xh = 1 ;
 __M7____yh__z = __M7__total_len + __M7____xh ; 
 __M7____yh____end :
 __M7____zh = 0 ;
 __M7____1h____iQ = __H7__acquired ;
 __M7____1h____jQ__z =(! __M7____1h____iQ ); 
 __M7____1h____jQ____end :
 if(! __M7____1h____jQ__z )goto __M7____1h____hQ__fi ;
 __M7____1h____kQ = "Did not initialize Dynamic" ;
 goto __M7____1h____lQ____oD ;
 __builtin_unreachable();
 __M7____1h____hQ__fi :
 __M7____1h__next_size = __H7__size +1; __M7____1h__success = true ; __M7____1h__self__allocated__prev = __H7__allocated ; if ( __M7____1h__next_size >= __H7__allocated ) { __H7__allocated = __H7__allocated + __H7__allocated /2+1; __M7____1h__next_acquired =( ptr )((( ptr **) __H7__acquired )[0]? __runtime_realloc ((( ptr **) __H7__acquired )[0], __H7__allocated * sizeof ( ptr ), __M7____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __H7__allocated * sizeof ( ptr ))); if ( __M7____1h__success = __M7____1h__next_acquired )(( ptr **) __H7__acquired )[0]=( ptr *) __M7____1h__next_acquired ; } if ( __M7____1h__success ) { __M7____1h__mem =( ptr ) __runtime_alloc ( __M7____yh__z * sizeof ( __M7____1h____gQ )); if ( __M7____1h__success = __M7____1h__mem ) {(( ptr **) __H7__acquired )[0][ __H7__size ]= __M7____1h__mem ; __H7__size = __M7____1h__next_size ; } } 
 __M7____1h____nQ__x = __M7____1h__success ;
 __M7____1h____nQ__z =(! __M7____1h____nQ__x ); 
 __M7____1h____nQ____end :
 if(! __M7____1h____nQ__z )goto __M7____1h____mQ__fi ;
 __M7____1h____oQ = "Failed a Dynamic allocation" ;
 goto __M7____1h____pQ____oD ;
 __builtin_unreachable();
 __M7____1h____mQ__fi :
 __M7____1h____uQ = 0 ;
 __M7____1h____wQ__bytesize = sizeof ( __M7____1h____wQ____CF )* __M7____yh__z ; 
 __M7____1h____wQ____end :
 memcpy (( char *) __M7____1h__mem ,( char *) __M7____vh____m__contents , __M7__len_x ); memcpy (( char *) __M7____1h__mem + __M7__len_x ,( char *) __L7____Ib__contents , __M7__len_y );(( char *) __M7____1h__mem )[ __M7__total_len ]=0; 
 __M7____4h__contents = __M7____1h__mem ;
 __H7____TQ = __M7____1h__self____TQ ;
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
 __S7____state -> command__contents = __M7____4h__contents ;
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
 __X7____9a__length = strlen ( name ); __X7____9a__contents =( ptr ) name ; __X7____9a__first = name [0]; __X7____9a__noptr =( ptr ) __X7____9a__noptr ; 
 __X7____9a____m__contents = __X7____9a__contents ;
 __X7____Ab__length = strlen ( __W7 ); __X7____Ab__contents =( ptr ) __W7 ; __X7____Ab__first = __W7 [0]; __X7____Ab__noptr =( ptr ) __X7____Ab__noptr ; 
 __X7____Ab____m__contents = __X7____Ab__contents ;
 __X7__len_x = __X7____9a__length ; __X7__len_y = __X7____Ab__length ; __X7__total_len = __X7__len_x + __X7__len_y ; __X7__first = __X7____9a__length ? __X7____9a__first : __X7____Ab__first ; 
 __X7____Bb = 1 ;
 __X7____Cb__z = __X7__total_len + __X7____Bb ; 
 __X7____Cb____end :
 __X7____Db = 0 ;
 __X7____Fb____iQ = __P7__acquired ;
 __X7____Fb____jQ__z =(! __X7____Fb____iQ ); 
 __X7____Fb____jQ____end :
 if(! __X7____Fb____jQ__z )goto __X7____Fb____hQ__fi ;
 __X7____Fb____kQ = "Did not initialize Dynamic" ;
 goto __X7____Fb____lQ____oD ;
 __builtin_unreachable();
 __X7____Fb____hQ__fi :
 __X7____Fb__next_size = __P7__size +1; __X7____Fb__success = true ; __X7____Fb__self__allocated__prev = __P7__allocated ; if ( __X7____Fb__next_size >= __P7__allocated ) { __P7__allocated = __P7__allocated + __P7__allocated /2+1; __X7____Fb__next_acquired =( ptr )((( ptr **) __P7__acquired )[0]? __runtime_realloc ((( ptr **) __P7__acquired )[0], __P7__allocated * sizeof ( ptr ), __X7____Fb__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __P7__allocated * sizeof ( ptr ))); if ( __X7____Fb__success = __X7____Fb__next_acquired )(( ptr **) __P7__acquired )[0]=( ptr *) __X7____Fb__next_acquired ; } if ( __X7____Fb__success ) { __X7____Fb__mem =( ptr ) __runtime_alloc ( __X7____Cb__z * sizeof ( __X7____Fb____gQ )); if ( __X7____Fb__success = __X7____Fb__mem ) {(( ptr **) __P7__acquired )[0][ __P7__size ]= __X7____Fb__mem ; __P7__size = __X7____Fb__next_size ; } } 
 __X7____Fb____nQ__x = __X7____Fb__success ;
 __X7____Fb____nQ__z =(! __X7____Fb____nQ__x ); 
 __X7____Fb____nQ____end :
 if(! __X7____Fb____nQ__z )goto __X7____Fb____mQ__fi ;
 __X7____Fb____oQ = "Failed a Dynamic allocation" ;
 goto __X7____Fb____pQ____oD ;
 __builtin_unreachable();
 __X7____Fb____mQ__fi :
 __X7____Fb____uQ = 0 ;
 __X7____Fb____wQ__bytesize = sizeof ( __X7____Fb____wQ____CF )* __X7____Cb__z ; 
 __X7____Fb____wQ____end :
 memcpy (( char *) __X7____Fb__mem ,( char *) __X7____9a____m__contents , __X7__len_x ); memcpy (( char *) __X7____Fb__mem + __X7__len_x ,( char *) __X7____Ab____m__contents , __X7__len_y );(( char *) __X7____Fb__mem )[ __X7__total_len ]=0; 
 __X7____Ib__contents = __X7____Fb__mem ;
 __P7____TQ = __X7____Fb__self____TQ ;
 __P7__acquired = __P7__acquired ;
 __P7__size = __P7__size ;
 __P7__allocated = __P7__allocated ;
 __P7____dynamic_entry = __P7____dynamic_entry ;
 __Y7____vh__length = strlen ( __V7 ); __Y7____vh__contents =( ptr ) __V7 ; __Y7____vh__first = __V7 [0]; __Y7____vh__noptr =( ptr ) __Y7____vh__noptr ; 
 __Y7____vh____m__contents = __Y7____vh__contents ;
 __Y7__len_x = __Y7____vh__length ; __Y7__len_y = __X7__total_len ; __Y7__total_len = __Y7__len_x + __Y7__len_y ; __Y7__first = __Y7____vh__length ? __Y7____vh__first : __X7__first ; 
 __Y7____xh = 1 ;
 __Y7____yh__z = __Y7__total_len + __Y7____xh ; 
 __Y7____yh____end :
 __Y7____zh = 0 ;
 __Y7____1h____iQ = __P7__acquired ;
 __Y7____1h____jQ__z =(! __Y7____1h____iQ ); 
 __Y7____1h____jQ____end :
 if(! __Y7____1h____jQ__z )goto __Y7____1h____hQ__fi ;
 __Y7____1h____kQ = "Did not initialize Dynamic" ;
 goto __Y7____1h____lQ____oD ;
 __builtin_unreachable();
 __Y7____1h____hQ__fi :
 __Y7____1h__next_size = __P7__size +1; __Y7____1h__success = true ; __Y7____1h__self__allocated__prev = __P7__allocated ; if ( __Y7____1h__next_size >= __P7__allocated ) { __P7__allocated = __P7__allocated + __P7__allocated /2+1; __Y7____1h__next_acquired =( ptr )((( ptr **) __P7__acquired )[0]? __runtime_realloc ((( ptr **) __P7__acquired )[0], __P7__allocated * sizeof ( ptr ), __Y7____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __P7__allocated * sizeof ( ptr ))); if ( __Y7____1h__success = __Y7____1h__next_acquired )(( ptr **) __P7__acquired )[0]=( ptr *) __Y7____1h__next_acquired ; } if ( __Y7____1h__success ) { __Y7____1h__mem =( ptr ) __runtime_alloc ( __Y7____yh__z * sizeof ( __Y7____1h____gQ )); if ( __Y7____1h__success = __Y7____1h__mem ) {(( ptr **) __P7__acquired )[0][ __P7__size ]= __Y7____1h__mem ; __P7__size = __Y7____1h__next_size ; } } 
 __Y7____1h____nQ__x = __Y7____1h__success ;
 __Y7____1h____nQ__z =(! __Y7____1h____nQ__x ); 
 __Y7____1h____nQ____end :
 if(! __Y7____1h____nQ__z )goto __Y7____1h____mQ__fi ;
 __Y7____1h____oQ = "Failed a Dynamic allocation" ;
 goto __Y7____1h____pQ____oD ;
 __builtin_unreachable();
 __Y7____1h____mQ__fi :
 __Y7____1h____uQ = 0 ;
 __Y7____1h____wQ__bytesize = sizeof ( __Y7____1h____wQ____CF )* __Y7____yh__z ; 
 __Y7____1h____wQ____end :
 memcpy (( char *) __Y7____1h__mem ,( char *) __Y7____vh____m__contents , __Y7__len_x ); memcpy (( char *) __Y7____1h__mem + __Y7__len_x ,( char *) __X7____Ib__contents , __Y7__len_y );(( char *) __Y7____1h__mem )[ __Y7__total_len ]=0; 
 __Y7____4h__contents = __Y7____1h__mem ;
 __P7____TQ = __Y7____1h__self____TQ ;
 __P7__acquired = __P7__acquired ;
 __P7__size = __P7__size ;
 __P7__allocated = __P7__allocated ;
 __P7____dynamic_entry = __P7____dynamic_entry ;
 printf ( "%s\n" ,( char *) __Y7____4h__contents ); 
 __Z7____end :
 goto __R7__el ;
 __R7__fi :
 __a7 = "[ \033[32mOK\033[0m ] " ;
 __b7 = ".s" ;
 __c7____9a__length = strlen ( name ); __c7____9a__contents =( ptr ) name ; __c7____9a__first = name [0]; __c7____9a__noptr =( ptr ) __c7____9a__noptr ; 
 __c7____9a____m__contents = __c7____9a__contents ;
 __c7____Ab__length = strlen ( __b7 ); __c7____Ab__contents =( ptr ) __b7 ; __c7____Ab__first = __b7 [0]; __c7____Ab__noptr =( ptr ) __c7____Ab__noptr ; 
 __c7____Ab____m__contents = __c7____Ab__contents ;
 __c7__len_x = __c7____9a__length ; __c7__len_y = __c7____Ab__length ; __c7__total_len = __c7__len_x + __c7__len_y ; __c7__first = __c7____9a__length ? __c7____9a__first : __c7____Ab__first ; 
 __c7____Bb = 1 ;
 __c7____Cb__z = __c7__total_len + __c7____Bb ; 
 __c7____Cb____end :
 __c7____Db = 0 ;
 __c7____Fb____iQ = __P7__acquired ;
 __c7____Fb____jQ__z =(! __c7____Fb____iQ ); 
 __c7____Fb____jQ____end :
 if(! __c7____Fb____jQ__z )goto __c7____Fb____hQ__fi ;
 __c7____Fb____kQ = "Did not initialize Dynamic" ;
 goto __c7____Fb____lQ____oD ;
 __builtin_unreachable();
 __c7____Fb____hQ__fi :
 __c7____Fb__next_size = __P7__size +1; __c7____Fb__success = true ; __c7____Fb__self__allocated__prev = __P7__allocated ; if ( __c7____Fb__next_size >= __P7__allocated ) { __P7__allocated = __P7__allocated + __P7__allocated /2+1; __c7____Fb__next_acquired =( ptr )((( ptr **) __P7__acquired )[0]? __runtime_realloc ((( ptr **) __P7__acquired )[0], __P7__allocated * sizeof ( ptr ), __c7____Fb__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __P7__allocated * sizeof ( ptr ))); if ( __c7____Fb__success = __c7____Fb__next_acquired )(( ptr **) __P7__acquired )[0]=( ptr *) __c7____Fb__next_acquired ; } if ( __c7____Fb__success ) { __c7____Fb__mem =( ptr ) __runtime_alloc ( __c7____Cb__z * sizeof ( __c7____Fb____gQ )); if ( __c7____Fb__success = __c7____Fb__mem ) {(( ptr **) __P7__acquired )[0][ __P7__size ]= __c7____Fb__mem ; __P7__size = __c7____Fb__next_size ; } } 
 __c7____Fb____nQ__x = __c7____Fb__success ;
 __c7____Fb____nQ__z =(! __c7____Fb____nQ__x ); 
 __c7____Fb____nQ____end :
 if(! __c7____Fb____nQ__z )goto __c7____Fb____mQ__fi ;
 __c7____Fb____oQ = "Failed a Dynamic allocation" ;
 goto __c7____Fb____pQ____oD ;
 __builtin_unreachable();
 __c7____Fb____mQ__fi :
 __c7____Fb____uQ = 0 ;
 __c7____Fb____wQ__bytesize = sizeof ( __c7____Fb____wQ____CF )* __c7____Cb__z ; 
 __c7____Fb____wQ____end :
 memcpy (( char *) __c7____Fb__mem ,( char *) __c7____9a____m__contents , __c7__len_x ); memcpy (( char *) __c7____Fb__mem + __c7__len_x ,( char *) __c7____Ab____m__contents , __c7__len_y );(( char *) __c7____Fb__mem )[ __c7__total_len ]=0; 
 __c7____Ib__contents = __c7____Fb__mem ;
 __P7____TQ = __c7____Fb__self____TQ ;
 __P7__acquired = __P7__acquired ;
 __P7__size = __P7__size ;
 __P7__allocated = __P7__allocated ;
 __P7____dynamic_entry = __P7____dynamic_entry ;
 __d7____vh__length = strlen ( __a7 ); __d7____vh__contents =( ptr ) __a7 ; __d7____vh__first = __a7 [0]; __d7____vh__noptr =( ptr ) __d7____vh__noptr ; 
 __d7____vh____m__contents = __d7____vh__contents ;
 __d7__len_x = __d7____vh__length ; __d7__len_y = __c7__total_len ; __d7__total_len = __d7__len_x + __d7__len_y ; __d7__first = __d7____vh__length ? __d7____vh__first : __c7__first ; 
 __d7____xh = 1 ;
 __d7____yh__z = __d7__total_len + __d7____xh ; 
 __d7____yh____end :
 __d7____zh = 0 ;
 __d7____1h____iQ = __P7__acquired ;
 __d7____1h____jQ__z =(! __d7____1h____iQ ); 
 __d7____1h____jQ____end :
 if(! __d7____1h____jQ__z )goto __d7____1h____hQ__fi ;
 __d7____1h____kQ = "Did not initialize Dynamic" ;
 goto __d7____1h____lQ____oD ;
 __builtin_unreachable();
 __d7____1h____hQ__fi :
 __d7____1h__next_size = __P7__size +1; __d7____1h__success = true ; __d7____1h__self__allocated__prev = __P7__allocated ; if ( __d7____1h__next_size >= __P7__allocated ) { __P7__allocated = __P7__allocated + __P7__allocated /2+1; __d7____1h__next_acquired =( ptr )((( ptr **) __P7__acquired )[0]? __runtime_realloc ((( ptr **) __P7__acquired )[0], __P7__allocated * sizeof ( ptr ), __d7____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __P7__allocated * sizeof ( ptr ))); if ( __d7____1h__success = __d7____1h__next_acquired )(( ptr **) __P7__acquired )[0]=( ptr *) __d7____1h__next_acquired ; } if ( __d7____1h__success ) { __d7____1h__mem =( ptr ) __runtime_alloc ( __d7____yh__z * sizeof ( __d7____1h____gQ )); if ( __d7____1h__success = __d7____1h__mem ) {(( ptr **) __P7__acquired )[0][ __P7__size ]= __d7____1h__mem ; __P7__size = __d7____1h__next_size ; } } 
 __d7____1h____nQ__x = __d7____1h__success ;
 __d7____1h____nQ__z =(! __d7____1h____nQ__x ); 
 __d7____1h____nQ____end :
 if(! __d7____1h____nQ__z )goto __d7____1h____mQ__fi ;
 __d7____1h____oQ = "Failed a Dynamic allocation" ;
 goto __d7____1h____pQ____oD ;
 __builtin_unreachable();
 __d7____1h____mQ__fi :
 __d7____1h____uQ = 0 ;
 __d7____1h____wQ__bytesize = sizeof ( __d7____1h____wQ____CF )* __d7____yh__z ; 
 __d7____1h____wQ____end :
 memcpy (( char *) __d7____1h__mem ,( char *) __d7____vh____m__contents , __d7__len_x ); memcpy (( char *) __d7____1h__mem + __d7__len_x ,( char *) __c7____Ib__contents , __d7__len_y );(( char *) __d7____1h__mem )[ __d7__total_len ]=0; 
 __d7____4h__contents = __d7____1h__mem ;
 __P7____TQ = __d7____1h__self____TQ ;
 __P7__acquired = __P7__acquired ;
 __P7__size = __P7__size ;
 __P7__allocated = __P7__allocated ;
 __P7____dynamic_entry = __P7____dynamic_entry ;
 printf ( "%s\n" ,( char *) __d7____4h__contents ); 
 __e7____end :
 __R7__el :
 __end :
goto __return;

// ERROR HANDLING
__X7____Fb____lQ____oD :
 printf ( "%s\n" , __X7____Fb____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__Y7____1h____pQ____oD :
 printf ( "%s\n" , __Y7____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__L7____Fb____lQ____oD :
 printf ( "%s\n" , __L7____Fb____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__L7____Fb____pQ____oD :
 printf ( "%s\n" , __L7____Fb____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__Y7____1h____lQ____oD :
 printf ( "%s\n" , __Y7____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__M7____1h____lQ____oD :
 printf ( "%s\n" , __M7____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__T7 :
printf("Runtime error from run __S7 \n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
__X7____Fb____pQ____oD :
 printf ( "%s\n" , __X7____Fb____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__M7____1h____pQ____oD :
 printf ( "%s\n" , __M7____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__c7____Fb____pQ____oD :
 printf ( "%s\n" , __c7____Fb____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__d7____1h____lQ____oD :
 printf ( "%s\n" , __d7____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__d7____1h____pQ____oD :
 printf ( "%s\n" , __d7____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__c7____Fb____lQ____oD :
 printf ( "%s\n" , __c7____Fb____kQ ); 
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
nominal __E7__p____V5=0;
ptr __B7__contents=0;
bool __D7____k5__z=0;
ptr __D7__contents=0;
i64 __D7__status=0;
nominal command____c=0;
nominal process____V5=0;
ptr process__contents=0;
ptr __C7__contents=0;
ptr __D7____j5__x=0;
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


void main__822(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__822__state *__state=(struct main__822__state*)__void__state;
struct all__821__state* __J9____state = 0 ;
f64 __O9__z=0;
errcode __J9__err=0;
ptr __J9____task=0;
f64 __I9__elapsed=0;
f64 __N9__elapsed=0;
cstr __L9=0;
cstr __Q9=0;

// IMPLEMENTATION
__I9__elapsed = __smo_time_eta (); 
 __I9____end :
 __J9____state = (struct all__821__state*)__runtime_calloc(sizeof(struct all__821__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __J9____state ) ;
 __J9____task = __smolambda_add_task ( all__821 , __J9____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __J9____task ) ;
 if( __J9__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __J9____task ) ;
 __J9__err = __J9____state -> err ;
 __L9 = "Completed in " ;
 printf ( "%s" , __L9 ); 
 __M9____end :
 __N9__elapsed = __smo_time_eta (); 
 __N9____end :
 __O9__z = __N9__elapsed - __I9__elapsed ; 
 __O9____end :
 printf ( "%.6f" , __O9__z ); 
 __P9____end :
 __Q9 = " sec" ;
 printf ( "%s\n" , __Q9 ); 
 __R9____end :
 __end :
goto __return;

// ERROR HANDLING
__K9 :
printf("Runtime error from all __J9 \n");
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
ptr __86____w6____Y5__noptr=0;
char __86____w6____Y5__first=0;
ptr __86____w6____Y5__contents=0;
u64 __86____w6____Y5__length=0;
ptr __86____u6__contents=0;
cstr __86__mem=0;
ptr process____u6__contents=0;
cstr process__mem=0;
char process____q6=0;
char process__first=0;
u64 __86____p6__z=0;
char __86__first=0;
cstr __86____s6____tF=0;
ptr process____w6____Y5____p__contents=0;
u64 process____s6__size=0;
bool process____s6____rF=0;
u64 process____w6____Y5__length=0;
bool process____s6____mF__z=0;
ptr __86____w6____Y5____p__contents=0;
char __86____s6____1F____8E=0;
cstr process____s6____tF=0;
ptr __86____w6__contents=0;
bool process____s6____sF__z=0;
bool __86____s6____sF__z=0;
ptr __86____s6__mem=0;
ptr process____s6__mem=0;
char process____w6____Y5__first=0;
u64 process__command__length=0;
ptr process____w6____Y5__contents=0;
ptr process____w6____a5__x=0;
u64 process____o6=0;
ptr process__command__contents=0;
u64 process____s6____lF=0;
bool process____w6____b5__z=0;
cstr process____s6____nF=0;
ptr process____l6__contents=0;
char __86____q6=0;
i64 __86____w6__status=0;
char process____s6____pF=0;
nominal process__command____b=0;
ptr process____w6__contents=0;
ptr process__command__memory=0;
char __86____s6____pF=0;
nominal process____w6____V5=0;
i64 process____w6__status=0;
ptr process____w6____Y5__noptr=0;
nominal process____l6____V5=0;
ptr process____v6__contents=0;
u64 process____s6____1F__bytesize=0;
char process____s6____1F____8E=0;
char process__command__first=0;
u64 process____p6__z=0;
u64 __86____s6____lF=0;
nominal command____b=0;
char process____s6____zF=0;
cstr __86____s6____nF=0;
ptr __76__contents=0;
u64 __86____o6=0;
bool __86____s6____mF__z=0;
ptr __66__contents=0;
bool __86____s6____rF=0;
bool process____w6____a5__z=0;
char __86____s6____zF=0;
u64 __86____s6____1F__bytesize=0;

// IMPLEMENTATION
__66__contents = 0 ;
 __76__contents = __66__contents ;
 __86____o6 = 1 ;
 __86____p6__z = command__length + __86____o6 ; 
 __86____p6____end :
 __86____q6 = 0 ;
 __86____s6____lF = 0 ;
 __86____s6____mF__z =( __86____p6__z == __86____s6____lF ); 
 __86____s6____mF____end :
 if(! __86____s6____mF__z )goto __86____s6____kF__fi ;
 __86____s6____nF = "Cannot allocate zero size" ;
 goto __86____s6____oF____oD ;
 __builtin_unreachable();
 __86____s6____kF__fi :
 __86____s6__mem = alloca ( __86____p6__z * sizeof ( __86____s6____pF )); 
 __86____s6____rF = __86____s6__mem ;
 __86____s6____sF__z =(! __86____s6____rF ); 
 __86____s6____sF____end :
 if(! __86____s6____sF__z )goto __86____s6____qF__fi ;
 __86____s6____tF = "Failed a Stack allocation" ;
 goto __86____s6____uF____oD ;
 __builtin_unreachable();
 __86____s6____qF__fi :
 __86____s6____zF = 0 ;
 __86____s6____1F__bytesize = sizeof ( __86____s6____1F____8E )* __86____p6__z ; 
 __86____s6____1F____end :
 __86__first =0; if ( __86____s6__mem ) { memcpy (( char *) __86____s6__mem , command__contents , command__length );(( char *) __86____s6__mem )[ command__length ]=0; } __86__mem =( const char *) __86____s6__mem ; 
 __86____u6__contents = 0 ;
 __86____w6____Y5__length = strlen ( __86__mem ); __86____w6____Y5__contents =( ptr ) __86__mem ; __86____w6____Y5__first = __86__mem [0]; __86____w6____Y5__noptr =( ptr ) __86____w6____Y5__noptr ; 
 __86____w6____Y5____p__contents = __86____w6____Y5__contents ;
 __86____w6__contents =( ptr ) popen (( cstr ) __86____w6____Y5____p__contents , "r" ); 
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
__86____s6____uF____oD :
 printf ( "%s\n" , __86____s6____tF ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__86____s6____oF____oD :
 printf ( "%s\n" , __86____s6____nF ); 
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
struct run__816__state* __I8____state = 0 ;
ptr name__contents= __state->name__contents;
u64 name__length= __state->name__length;
char name__first= __state->name__first;
ptr name__memory= __state->name__memory;
nominal __T8____1h__self____TQ=0;
char __T8____1h____uQ=0;
cstr __T8____1h____oQ=0;
bool __T8____1h____nQ__z=0;
bool __T8____1h____nQ__x=0;
char __T8____1h____gQ=0;
ptr __T8____1h__mem=0;
ptr __T8____1h__next_acquired=0;
u64 __T8____1h__self__allocated__prev=0;
bool __T8____1h__success=0;
u64 __T8____1h__next_size=0;
bool __T8____1h____iQ=0;
char __T8____zh=0;
u64 __T8__total_len=0;
u64 __T8__len_y=0;
ptr __T8____vh____m__contents=0;
u64 __T8____vh__length=0;
nominal __S8____Vd__self____TQ=0;
ptr __S8____Yd__contents=0;
u64 __S8____Vd____wQ__bytesize=0;
char __S8____Vd____uQ=0;
cstr __S8____Vd____oQ=0;
ptr __S8____Vd__next_acquired=0;
u64 __S8____Vd__self__allocated__prev=0;
bool __S8____Vd__success=0;
u64 __S8____Vd__next_size=0;
bool __T8____1h____jQ__z=0;
bool __S8____Vd____iQ=0;
char __S8____Td=0;
u64 __S8__total_len=0;
u64 __S8__len_y=0;
u64 __S8__len_x=0;
ptr __S8____Qd____m__contents=0;
cstr __R8=0;
ptr __S8____Qd__contents=0;
cstr __Q8=0;
ptr __O8____4h__contents=0;
char __O8____1h____wQ____CF=0;
u64 __O8____1h____wQ__bytesize=0;
char __O8____1h____uQ=0;
cstr __O8____1h____oQ=0;
bool __O8____1h____nQ__z=0;
char __O8____1h____gQ=0;
ptr __O8____1h__mem=0;
ptr __O8____1h__next_acquired=0;
u64 __O8____1h__self__allocated__prev=0;
cstr __O8____1h____kQ=0;
u64 __S8____Rd=0;
bool __O8____1h____jQ__z=0;
u64 __O8____yh__z=0;
u64 __O8__total_len=0;
u64 __O8__len_y=0;
u64 __O8__len_x=0;
ptr __O8____vh____m__contents=0;
ptr __O8____vh__noptr=0;
char __O8____vh__first=0;
ptr __O8____vh__contents=0;
u64 __S8____Sd__z=0;
u64 __O8____vh__length=0;
nominal __N8____Vd__self____TQ=0;
ptr __T8____vh__contents=0;
nominal __F8____TQ=0;
u64 __N8____Vd____wQ__bytesize=0;
char __N8____Vd____uQ=0;
cstr __T8____1h____kQ=0;
bool __N8____Vd____nQ__x=0;
u64 __T8____yh__z=0;
ptr __N8____Vd__mem=0;
bool __N8____Vd__success=0;
u64 __T8____xh=0;
bool __N8____Vd____iQ=0;
u64 __N8____Sd__z=0;
u64 __N8____Rd=0;
char __T8____vh__first=0;
char __N8__first=0;
u64 __N8__total_len=0;
ptr __N8____Qd__noptr=0;
char __N8____Qd__first=0;
ptr __N8____Qd__contents=0;
u64 __N8____Qd__length=0;
cstr __M8=0;
errcode __I8__err=0;
ptr __I8____task=0;
ptr command__memory=0;
char __T8__first=0;
char command__first=0;
u64 command__length=0;
nominal command____c=0;
u64 __N8____Vd__self__allocated__prev=0;
char __O8____zh=0;
bool __O8____1h____nQ__x=0;
ptr command__contents=0;
bool __C8____1h____jQ__z=0;
nominal __C8____1h__self____TQ=0;
char __T8____1h____wQ____CF=0;
cstr __N8____Vd____oQ=0;
char __S8____Vd____gQ=0;
u64 __B8____Rd=0;
bool __K8=0;
bool __O8____1h__success=0;
ptr __C8____1h__mem=0;
ptr __T8____4h__contents=0;
u64 __N8__len_x=0;
u64 __T8____1h____wQ__bytesize=0;
bool __N8____Vd____jQ__z=0;
u64 __C8__len_y=0;
bool __S8____Vd____jQ__z=0;
u64 __O8____xh=0;
char __N8____Td=0;
ptr __B8____Vd__next_acquired=0;
nominal __B8____Vd__self____TQ=0;
char __N8____Vd____wQ____CF=0;
char __C8____zh=0;
ptr __C8____4h__contents=0;
ptr __N8____Vd__next_acquired=0;
ptr __S8____Qd__noptr=0;
u64 __F8____ZQ____dynamic_entry=0;
char __S8____Qd__first=0;
cstr __S8____Vd____kQ=0;
ptr __B8____Qd__contents=0;
ptr __N8____Yd__contents=0;
char __B8____Qd__first=0;
bool __B8____Vd____nQ__x=0;
bool __C8____1h__success=0;
bool __N8____Vd____nQ__z=0;
u64 __N8____Vd__next_size=0;
char __C8____1h____gQ=0;
ptr __S8____Vd__mem=0;
u64 __C8__total_len=0;
u64 __C8____xh=0;
cstr __B8____Vd____kQ=0;
u64 __F8____dynamic_entry=0;
bool __O8____1h____iQ=0;
u64 __77__size=0;
ptr __N8____Qd____m__contents=0;
bool __C8____1h____iQ=0;
ptr __F8__acquired=0;
bool __S8____Vd____nQ__x=0;
u64 __77____ZQ____dynamic_entry=0;
u64 __B8____Qd__length=0;
bool __S8____Vd____nQ__z=0;
ptr __B8____Qd____m__contents=0;
cstr __C8____1h____oQ=0;
u64 __77____dynamic_entry=0;
ptr __77__acquired=0;
nominal name____c=0;
ptr __77____ZQ__acquired=0;
bool __B8____Vd____jQ__z=0;
char __B8____Td=0;
u64 __T8__len_x=0;
nominal __O8____1h__self____TQ=0;
bool __B8____Vd____nQ__z=0;
u64 __77____ZQ____UQ=0;
char __C8____1h____wQ____CF=0;
u64 __77____ZQ____VQ=0;
u64 __77__allocated=0;
nominal __77____TQ=0;
cstr __97=0;
cstr __A8=0;
ptr __F8____ZQ__acquired=0;
u64 __O8____1h__next_size=0;
ptr __B8____Qd__noptr=0;
bool __B8____Vd__success=0;
u64 __B8__len_x=0;
u64 __B8__len_y=0;
ptr __C8____vh____m__contents=0;
u64 __B8__total_len=0;
char __B8__first=0;
u64 __C8____vh__length=0;
u64 __C8____1h__next_size=0;
u64 __B8____Vd__next_size=0;
u64 __B8____Sd__z=0;
bool __B8____Vd____iQ=0;
char __N8____Vd____gQ=0;
cstr __L8=0;
u64 __B8____Vd__self__allocated__prev=0;
cstr __N8____Vd____kQ=0;
ptr __B8____Vd__mem=0;
char __B8____Vd____gQ=0;
cstr __B8____Vd____oQ=0;
u64 __B8____Vd____wQ__bytesize=0;
bool __C8____1h____nQ__x=0;
char __B8____Vd____wQ____CF=0;
char __B8____Vd____uQ=0;
ptr __B8____Yd__contents=0;
ptr __C8____vh__contents=0;
char __C8____vh__first=0;
char __O8__first=0;
ptr __C8____vh__noptr=0;
u64 __C8__len_x=0;
char __C8__first=0;
u64 __C8____yh__z=0;
u64 __S8____Qd__length=0;
cstr __C8____1h____kQ=0;
u64 __C8____1h__self__allocated__prev=0;
u64 __F8__size=0;
u64 __N8__len_y=0;
ptr __C8____1h__next_acquired=0;
bool __C8____1h____nQ__z=0;
char __C8____1h____uQ=0;
u64 __C8____1h____wQ__bytesize=0;
char __S8__first=0;
ptr __T8____vh__noptr=0;
char __S8____Vd____wQ____CF=0;
u64 __F8____ZQ____UQ=0;
u64 __F8____ZQ____VQ=0;
u64 __F8__allocated=0;

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
 __B8____Qd__length = strlen ( __A8 ); __B8____Qd__contents =( ptr ) __A8 ; __B8____Qd__first = __A8 [0]; __B8____Qd__noptr =( ptr ) __B8____Qd__noptr ; 
 __B8____Qd____m__contents = __B8____Qd__contents ;
 __B8__len_x = name__length ; __B8__len_y = __B8____Qd__length ; __B8__total_len = __B8__len_x + __B8__len_y ; __B8__first = name__length ? name__first : __B8____Qd__first ; 
 __B8____Rd = 1 ;
 __B8____Sd__z = __B8__total_len + __B8____Rd ; 
 __B8____Sd____end :
 __B8____Td = 0 ;
 __B8____Vd____iQ = __77__acquired ;
 __B8____Vd____jQ__z =(! __B8____Vd____iQ ); 
 __B8____Vd____jQ____end :
 if(! __B8____Vd____jQ__z )goto __B8____Vd____hQ__fi ;
 __B8____Vd____kQ = "Did not initialize Dynamic" ;
 goto __B8____Vd____lQ____oD ;
 __builtin_unreachable();
 __B8____Vd____hQ__fi :
 __B8____Vd__next_size = __77__size +1; __B8____Vd__success = true ; __B8____Vd__self__allocated__prev = __77__allocated ; if ( __B8____Vd__next_size >= __77__allocated ) { __77__allocated = __77__allocated + __77__allocated /2+1; __B8____Vd__next_acquired =( ptr )((( ptr **) __77__acquired )[0]? __runtime_realloc ((( ptr **) __77__acquired )[0], __77__allocated * sizeof ( ptr ), __B8____Vd__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __77__allocated * sizeof ( ptr ))); if ( __B8____Vd__success = __B8____Vd__next_acquired )(( ptr **) __77__acquired )[0]=( ptr *) __B8____Vd__next_acquired ; } if ( __B8____Vd__success ) { __B8____Vd__mem =( ptr ) __runtime_alloc ( __B8____Sd__z * sizeof ( __B8____Vd____gQ )); if ( __B8____Vd__success = __B8____Vd__mem ) {(( ptr **) __77__acquired )[0][ __77__size ]= __B8____Vd__mem ; __77__size = __B8____Vd__next_size ; } } 
 __B8____Vd____nQ__x = __B8____Vd__success ;
 __B8____Vd____nQ__z =(! __B8____Vd____nQ__x ); 
 __B8____Vd____nQ____end :
 if(! __B8____Vd____nQ__z )goto __B8____Vd____mQ__fi ;
 __B8____Vd____oQ = "Failed a Dynamic allocation" ;
 goto __B8____Vd____pQ____oD ;
 __builtin_unreachable();
 __B8____Vd____mQ__fi :
 __B8____Vd____uQ = 0 ;
 __B8____Vd____wQ__bytesize = sizeof ( __B8____Vd____wQ____CF )* __B8____Sd__z ; 
 __B8____Vd____wQ____end :
 memcpy (( char *) __B8____Vd__mem ,( char *) name__contents , __B8__len_x ); memcpy (( char *) __B8____Vd__mem + __B8__len_x ,( char *) __B8____Qd____m__contents , __B8__len_y );(( char *) __B8____Vd__mem )[ __B8__total_len ]=0; 
 __B8____Yd__contents = __B8____Vd__mem ;
 __77____TQ = __B8____Vd__self____TQ ;
 __77__acquired = __77__acquired ;
 __77__size = __77__size ;
 __77__allocated = __77__allocated ;
 __77____dynamic_entry = __77____dynamic_entry ;
 __C8____vh__length = strlen ( __97 ); __C8____vh__contents =( ptr ) __97 ; __C8____vh__first = __97 [0]; __C8____vh__noptr =( ptr ) __C8____vh__noptr ; 
 __C8____vh____m__contents = __C8____vh__contents ;
 __C8__len_x = __C8____vh__length ; __C8__len_y = __B8__total_len ; __C8__total_len = __C8__len_x + __C8__len_y ; __C8__first = __C8____vh__length ? __C8____vh__first : __B8__first ; 
 __C8____xh = 1 ;
 __C8____yh__z = __C8__total_len + __C8____xh ; 
 __C8____yh____end :
 __C8____zh = 0 ;
 __C8____1h____iQ = __77__acquired ;
 __C8____1h____jQ__z =(! __C8____1h____iQ ); 
 __C8____1h____jQ____end :
 if(! __C8____1h____jQ__z )goto __C8____1h____hQ__fi ;
 __C8____1h____kQ = "Did not initialize Dynamic" ;
 goto __C8____1h____lQ____oD ;
 __builtin_unreachable();
 __C8____1h____hQ__fi :
 __C8____1h__next_size = __77__size +1; __C8____1h__success = true ; __C8____1h__self__allocated__prev = __77__allocated ; if ( __C8____1h__next_size >= __77__allocated ) { __77__allocated = __77__allocated + __77__allocated /2+1; __C8____1h__next_acquired =( ptr )((( ptr **) __77__acquired )[0]? __runtime_realloc ((( ptr **) __77__acquired )[0], __77__allocated * sizeof ( ptr ), __C8____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __77__allocated * sizeof ( ptr ))); if ( __C8____1h__success = __C8____1h__next_acquired )(( ptr **) __77__acquired )[0]=( ptr *) __C8____1h__next_acquired ; } if ( __C8____1h__success ) { __C8____1h__mem =( ptr ) __runtime_alloc ( __C8____yh__z * sizeof ( __C8____1h____gQ )); if ( __C8____1h__success = __C8____1h__mem ) {(( ptr **) __77__acquired )[0][ __77__size ]= __C8____1h__mem ; __77__size = __C8____1h__next_size ; } } 
 __C8____1h____nQ__x = __C8____1h__success ;
 __C8____1h____nQ__z =(! __C8____1h____nQ__x ); 
 __C8____1h____nQ____end :
 if(! __C8____1h____nQ__z )goto __C8____1h____mQ__fi ;
 __C8____1h____oQ = "Failed a Dynamic allocation" ;
 goto __C8____1h____pQ____oD ;
 __builtin_unreachable();
 __C8____1h____mQ__fi :
 __C8____1h____uQ = 0 ;
 __C8____1h____wQ__bytesize = sizeof ( __C8____1h____wQ____CF )* __C8____yh__z ; 
 __C8____1h____wQ____end :
 memcpy (( char *) __C8____1h__mem ,( char *) __C8____vh____m__contents , __C8__len_x ); memcpy (( char *) __C8____1h__mem + __C8__len_x ,( char *) __B8____Yd__contents , __C8__len_y );(( char *) __C8____1h__mem )[ __C8__total_len ]=0; 
 __C8____4h__contents = __C8____1h__mem ;
 __77____TQ = __C8____1h__self____TQ ;
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
 __I8____state -> command__contents = __C8____4h__contents ;
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
 __N8____Qd__length = strlen ( __M8 ); __N8____Qd__contents =( ptr ) __M8 ; __N8____Qd__first = __M8 [0]; __N8____Qd__noptr =( ptr ) __N8____Qd__noptr ; 
 __N8____Qd____m__contents = __N8____Qd__contents ;
 __N8__len_x = name__length ; __N8__len_y = __N8____Qd__length ; __N8__total_len = __N8__len_x + __N8__len_y ; __N8__first = name__length ? name__first : __N8____Qd__first ; 
 __N8____Rd = 1 ;
 __N8____Sd__z = __N8__total_len + __N8____Rd ; 
 __N8____Sd____end :
 __N8____Td = 0 ;
 __N8____Vd____iQ = __F8__acquired ;
 __N8____Vd____jQ__z =(! __N8____Vd____iQ ); 
 __N8____Vd____jQ____end :
 if(! __N8____Vd____jQ__z )goto __N8____Vd____hQ__fi ;
 __N8____Vd____kQ = "Did not initialize Dynamic" ;
 goto __N8____Vd____lQ____oD ;
 __builtin_unreachable();
 __N8____Vd____hQ__fi :
 __N8____Vd__next_size = __F8__size +1; __N8____Vd__success = true ; __N8____Vd__self__allocated__prev = __F8__allocated ; if ( __N8____Vd__next_size >= __F8__allocated ) { __F8__allocated = __F8__allocated + __F8__allocated /2+1; __N8____Vd__next_acquired =( ptr )((( ptr **) __F8__acquired )[0]? __runtime_realloc ((( ptr **) __F8__acquired )[0], __F8__allocated * sizeof ( ptr ), __N8____Vd__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __F8__allocated * sizeof ( ptr ))); if ( __N8____Vd__success = __N8____Vd__next_acquired )(( ptr **) __F8__acquired )[0]=( ptr *) __N8____Vd__next_acquired ; } if ( __N8____Vd__success ) { __N8____Vd__mem =( ptr ) __runtime_alloc ( __N8____Sd__z * sizeof ( __N8____Vd____gQ )); if ( __N8____Vd__success = __N8____Vd__mem ) {(( ptr **) __F8__acquired )[0][ __F8__size ]= __N8____Vd__mem ; __F8__size = __N8____Vd__next_size ; } } 
 __N8____Vd____nQ__x = __N8____Vd__success ;
 __N8____Vd____nQ__z =(! __N8____Vd____nQ__x ); 
 __N8____Vd____nQ____end :
 if(! __N8____Vd____nQ__z )goto __N8____Vd____mQ__fi ;
 __N8____Vd____oQ = "Failed a Dynamic allocation" ;
 goto __N8____Vd____pQ____oD ;
 __builtin_unreachable();
 __N8____Vd____mQ__fi :
 __N8____Vd____uQ = 0 ;
 __N8____Vd____wQ__bytesize = sizeof ( __N8____Vd____wQ____CF )* __N8____Sd__z ; 
 __N8____Vd____wQ____end :
 memcpy (( char *) __N8____Vd__mem ,( char *) name__contents , __N8__len_x ); memcpy (( char *) __N8____Vd__mem + __N8__len_x ,( char *) __N8____Qd____m__contents , __N8__len_y );(( char *) __N8____Vd__mem )[ __N8__total_len ]=0; 
 __N8____Yd__contents = __N8____Vd__mem ;
 __F8____TQ = __N8____Vd__self____TQ ;
 __F8__acquired = __F8__acquired ;
 __F8__size = __F8__size ;
 __F8__allocated = __F8__allocated ;
 __F8____dynamic_entry = __F8____dynamic_entry ;
 __O8____vh__length = strlen ( __L8 ); __O8____vh__contents =( ptr ) __L8 ; __O8____vh__first = __L8 [0]; __O8____vh__noptr =( ptr ) __O8____vh__noptr ; 
 __O8____vh____m__contents = __O8____vh__contents ;
 __O8__len_x = __O8____vh__length ; __O8__len_y = __N8__total_len ; __O8__total_len = __O8__len_x + __O8__len_y ; __O8__first = __O8____vh__length ? __O8____vh__first : __N8__first ; 
 __O8____xh = 1 ;
 __O8____yh__z = __O8__total_len + __O8____xh ; 
 __O8____yh____end :
 __O8____zh = 0 ;
 __O8____1h____iQ = __F8__acquired ;
 __O8____1h____jQ__z =(! __O8____1h____iQ ); 
 __O8____1h____jQ____end :
 if(! __O8____1h____jQ__z )goto __O8____1h____hQ__fi ;
 __O8____1h____kQ = "Did not initialize Dynamic" ;
 goto __O8____1h____lQ____oD ;
 __builtin_unreachable();
 __O8____1h____hQ__fi :
 __O8____1h__next_size = __F8__size +1; __O8____1h__success = true ; __O8____1h__self__allocated__prev = __F8__allocated ; if ( __O8____1h__next_size >= __F8__allocated ) { __F8__allocated = __F8__allocated + __F8__allocated /2+1; __O8____1h__next_acquired =( ptr )((( ptr **) __F8__acquired )[0]? __runtime_realloc ((( ptr **) __F8__acquired )[0], __F8__allocated * sizeof ( ptr ), __O8____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __F8__allocated * sizeof ( ptr ))); if ( __O8____1h__success = __O8____1h__next_acquired )(( ptr **) __F8__acquired )[0]=( ptr *) __O8____1h__next_acquired ; } if ( __O8____1h__success ) { __O8____1h__mem =( ptr ) __runtime_alloc ( __O8____yh__z * sizeof ( __O8____1h____gQ )); if ( __O8____1h__success = __O8____1h__mem ) {(( ptr **) __F8__acquired )[0][ __F8__size ]= __O8____1h__mem ; __F8__size = __O8____1h__next_size ; } } 
 __O8____1h____nQ__x = __O8____1h__success ;
 __O8____1h____nQ__z =(! __O8____1h____nQ__x ); 
 __O8____1h____nQ____end :
 if(! __O8____1h____nQ__z )goto __O8____1h____mQ__fi ;
 __O8____1h____oQ = "Failed a Dynamic allocation" ;
 goto __O8____1h____pQ____oD ;
 __builtin_unreachable();
 __O8____1h____mQ__fi :
 __O8____1h____uQ = 0 ;
 __O8____1h____wQ__bytesize = sizeof ( __O8____1h____wQ____CF )* __O8____yh__z ; 
 __O8____1h____wQ____end :
 memcpy (( char *) __O8____1h__mem ,( char *) __O8____vh____m__contents , __O8__len_x ); memcpy (( char *) __O8____1h__mem + __O8__len_x ,( char *) __N8____Yd__contents , __O8__len_y );(( char *) __O8____1h__mem )[ __O8__total_len ]=0; 
 __O8____4h__contents = __O8____1h__mem ;
 __F8____TQ = __O8____1h__self____TQ ;
 __F8__acquired = __F8__acquired ;
 __F8__size = __F8__size ;
 __F8__allocated = __F8__allocated ;
 __F8____dynamic_entry = __F8____dynamic_entry ;
 printf ( "%s\n" ,( char *) __O8____4h__contents ); 
 __P8____end :
 goto __H8__el ;
 __H8__fi :
 __Q8 = "[ \033[32mOK\033[0m ] " ;
 __R8 = ".s" ;
 __S8____Qd__length = strlen ( __R8 ); __S8____Qd__contents =( ptr ) __R8 ; __S8____Qd__first = __R8 [0]; __S8____Qd__noptr =( ptr ) __S8____Qd__noptr ; 
 __S8____Qd____m__contents = __S8____Qd__contents ;
 __S8__len_x = name__length ; __S8__len_y = __S8____Qd__length ; __S8__total_len = __S8__len_x + __S8__len_y ; __S8__first = name__length ? name__first : __S8____Qd__first ; 
 __S8____Rd = 1 ;
 __S8____Sd__z = __S8__total_len + __S8____Rd ; 
 __S8____Sd____end :
 __S8____Td = 0 ;
 __S8____Vd____iQ = __F8__acquired ;
 __S8____Vd____jQ__z =(! __S8____Vd____iQ ); 
 __S8____Vd____jQ____end :
 if(! __S8____Vd____jQ__z )goto __S8____Vd____hQ__fi ;
 __S8____Vd____kQ = "Did not initialize Dynamic" ;
 goto __S8____Vd____lQ____oD ;
 __builtin_unreachable();
 __S8____Vd____hQ__fi :
 __S8____Vd__next_size = __F8__size +1; __S8____Vd__success = true ; __S8____Vd__self__allocated__prev = __F8__allocated ; if ( __S8____Vd__next_size >= __F8__allocated ) { __F8__allocated = __F8__allocated + __F8__allocated /2+1; __S8____Vd__next_acquired =( ptr )((( ptr **) __F8__acquired )[0]? __runtime_realloc ((( ptr **) __F8__acquired )[0], __F8__allocated * sizeof ( ptr ), __S8____Vd__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __F8__allocated * sizeof ( ptr ))); if ( __S8____Vd__success = __S8____Vd__next_acquired )(( ptr **) __F8__acquired )[0]=( ptr *) __S8____Vd__next_acquired ; } if ( __S8____Vd__success ) { __S8____Vd__mem =( ptr ) __runtime_alloc ( __S8____Sd__z * sizeof ( __S8____Vd____gQ )); if ( __S8____Vd__success = __S8____Vd__mem ) {(( ptr **) __F8__acquired )[0][ __F8__size ]= __S8____Vd__mem ; __F8__size = __S8____Vd__next_size ; } } 
 __S8____Vd____nQ__x = __S8____Vd__success ;
 __S8____Vd____nQ__z =(! __S8____Vd____nQ__x ); 
 __S8____Vd____nQ____end :
 if(! __S8____Vd____nQ__z )goto __S8____Vd____mQ__fi ;
 __S8____Vd____oQ = "Failed a Dynamic allocation" ;
 goto __S8____Vd____pQ____oD ;
 __builtin_unreachable();
 __S8____Vd____mQ__fi :
 __S8____Vd____uQ = 0 ;
 __S8____Vd____wQ__bytesize = sizeof ( __S8____Vd____wQ____CF )* __S8____Sd__z ; 
 __S8____Vd____wQ____end :
 memcpy (( char *) __S8____Vd__mem ,( char *) name__contents , __S8__len_x ); memcpy (( char *) __S8____Vd__mem + __S8__len_x ,( char *) __S8____Qd____m__contents , __S8__len_y );(( char *) __S8____Vd__mem )[ __S8__total_len ]=0; 
 __S8____Yd__contents = __S8____Vd__mem ;
 __F8____TQ = __S8____Vd__self____TQ ;
 __F8__acquired = __F8__acquired ;
 __F8__size = __F8__size ;
 __F8__allocated = __F8__allocated ;
 __F8____dynamic_entry = __F8____dynamic_entry ;
 __T8____vh__length = strlen ( __Q8 ); __T8____vh__contents =( ptr ) __Q8 ; __T8____vh__first = __Q8 [0]; __T8____vh__noptr =( ptr ) __T8____vh__noptr ; 
 __T8____vh____m__contents = __T8____vh__contents ;
 __T8__len_x = __T8____vh__length ; __T8__len_y = __S8__total_len ; __T8__total_len = __T8__len_x + __T8__len_y ; __T8__first = __T8____vh__length ? __T8____vh__first : __S8__first ; 
 __T8____xh = 1 ;
 __T8____yh__z = __T8__total_len + __T8____xh ; 
 __T8____yh____end :
 __T8____zh = 0 ;
 __T8____1h____iQ = __F8__acquired ;
 __T8____1h____jQ__z =(! __T8____1h____iQ ); 
 __T8____1h____jQ____end :
 if(! __T8____1h____jQ__z )goto __T8____1h____hQ__fi ;
 __T8____1h____kQ = "Did not initialize Dynamic" ;
 goto __T8____1h____lQ____oD ;
 __builtin_unreachable();
 __T8____1h____hQ__fi :
 __T8____1h__next_size = __F8__size +1; __T8____1h__success = true ; __T8____1h__self__allocated__prev = __F8__allocated ; if ( __T8____1h__next_size >= __F8__allocated ) { __F8__allocated = __F8__allocated + __F8__allocated /2+1; __T8____1h__next_acquired =( ptr )((( ptr **) __F8__acquired )[0]? __runtime_realloc ((( ptr **) __F8__acquired )[0], __F8__allocated * sizeof ( ptr ), __T8____1h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __F8__allocated * sizeof ( ptr ))); if ( __T8____1h__success = __T8____1h__next_acquired )(( ptr **) __F8__acquired )[0]=( ptr *) __T8____1h__next_acquired ; } if ( __T8____1h__success ) { __T8____1h__mem =( ptr ) __runtime_alloc ( __T8____yh__z * sizeof ( __T8____1h____gQ )); if ( __T8____1h__success = __T8____1h__mem ) {(( ptr **) __F8__acquired )[0][ __F8__size ]= __T8____1h__mem ; __F8__size = __T8____1h__next_size ; } } 
 __T8____1h____nQ__x = __T8____1h__success ;
 __T8____1h____nQ__z =(! __T8____1h____nQ__x ); 
 __T8____1h____nQ____end :
 if(! __T8____1h____nQ__z )goto __T8____1h____mQ__fi ;
 __T8____1h____oQ = "Failed a Dynamic allocation" ;
 goto __T8____1h____pQ____oD ;
 __builtin_unreachable();
 __T8____1h____mQ__fi :
 __T8____1h____uQ = 0 ;
 __T8____1h____wQ__bytesize = sizeof ( __T8____1h____wQ____CF )* __T8____yh__z ; 
 __T8____1h____wQ____end :
 memcpy (( char *) __T8____1h__mem ,( char *) __T8____vh____m__contents , __T8__len_x ); memcpy (( char *) __T8____1h__mem + __T8__len_x ,( char *) __S8____Yd__contents , __T8__len_y );(( char *) __T8____1h__mem )[ __T8__total_len ]=0; 
 __T8____4h__contents = __T8____1h__mem ;
 __F8____TQ = __T8____1h__self____TQ ;
 __F8__acquired = __F8__acquired ;
 __F8__size = __F8__size ;
 __F8__allocated = __F8__allocated ;
 __F8____dynamic_entry = __F8____dynamic_entry ;
 printf ( "%s\n" ,( char *) __T8____4h__contents ); 
 __U8____end :
 __H8__el :
 __end :
goto __return;

// ERROR HANDLING
__O8____1h____pQ____oD :
 printf ( "%s\n" , __O8____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__S8____Vd____lQ____oD :
 printf ( "%s\n" , __S8____Vd____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__T8____1h____pQ____oD :
 printf ( "%s\n" , __T8____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__B8____Vd____lQ____oD :
 printf ( "%s\n" , __B8____Vd____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__B8____Vd____pQ____oD :
 printf ( "%s\n" , __B8____Vd____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__J8 :
printf("Runtime error from run __I8 \n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
__T8____1h____lQ____oD :
 printf ( "%s\n" , __T8____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__C8____1h____lQ____oD :
 printf ( "%s\n" , __C8____1h____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__N8____Vd____lQ____oD :
 printf ( "%s\n" , __N8____Vd____kQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__N8____Vd____pQ____oD :
 printf ( "%s\n" , __N8____Vd____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__S8____Vd____pQ____oD :
 printf ( "%s\n" , __S8____Vd____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__C8____1h____pQ____oD :
 printf ( "%s\n" , __C8____1h____oQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__O8____1h____lQ____oD :
 printf ( "%s\n" , __O8____1h____kQ ); 
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
if ( __F8__acquired ) { for ( __F8____dynamic_entry =0; __F8____dynamic_entry < __F8__size ;++ __F8____dynamic_entry ) { __runtime_free ((( ptr **) __F8__acquired )[0][ __F8____dynamic_entry ]); } __runtime_free ( __F8__acquired ); __F8__acquired =0; __F8__size =0; __F8__allocated =0; } 
 if ( __F8__acquired ) { for ( __F8____ZQ____dynamic_entry =0; __F8____ZQ____dynamic_entry < __F8____ZQ____UQ ;++ __F8____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __F8__acquired )[0][ __F8____ZQ____dynamic_entry ]); } __runtime_free ( __F8__acquired ); __F8__acquired =0; __F8____ZQ____UQ =0; __F8____ZQ____VQ =0; } 
if ( __77__acquired ) { for ( __77____dynamic_entry =0; __77____dynamic_entry < __77__size ;++ __77____dynamic_entry ) { __runtime_free ((( ptr **) __77__acquired )[0][ __77____dynamic_entry ]); } __runtime_free ( __77__acquired ); __77__acquired =0; __77__size =0; __77__allocated =0; } 
 if ( __77__acquired ) { for ( __77____ZQ____dynamic_entry =0; __77____ZQ____dynamic_entry < __77____ZQ____UQ ;++ __77____ZQ____dynamic_entry ) { __runtime_free ((( ptr **) __77__acquired )[0][ __77____ZQ____dynamic_entry ]); } __runtime_free ( __77__acquired ); __77__acquired =0; __77____ZQ____UQ =0; __77____ZQ____VQ =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}


void run__814(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__814__state *__state=(struct run__814__state*)__void__state;
cstr command= __state->command;
ptr __36____a5__x=0;
ptr process__contents=0;
i64 __36__status=0;
ptr __36____Y5__contents=0;
nominal __46__p____V5=0;
ptr __36____Y5__noptr=0;
ptr __36____Y5____p__contents=0;
nominal process____V5=0;
ptr __36__contents=0;
u64 __36____Y5__length=0;
ptr __16__contents=0;
ptr __26__contents=0;
char __36____Y5__first=0;
bool __36____a5__z=0;
bool __36____b5__z=0;

// IMPLEMENTATION
__16__contents = 0 ;
 __26__contents = __16__contents ;
 __36____Y5__length = strlen ( command ); __36____Y5__contents =( ptr ) command ; __36____Y5__first = command [0]; __36____Y5__noptr =( ptr ) __36____Y5__noptr ; 
 __36____Y5____p__contents = __36____Y5__contents ;
 __36__contents =( ptr ) popen (( cstr ) __36____Y5____p__contents , "r" ); 
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



int main() {
struct main__822__state __main_args={0};
__smolambda_initialize_service_tasks(main__822, &__main_args);
return __main_args.err;
}

