#define SMOLAMBDA_SERVICES 7
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

#include <stdio.h>
#include<string.h>

#include<stdlib.h>

#include<stdio.h>

#include<sys/wait.h>

#if defined(_WIN32)||defined(_WIN64)
#define popen _popen
#define pclose _pclose
#endif

struct run__810__state{errcode err;cstr command;};
void run__810(void *__void__state);
struct run__811__state{errcode err;nominal command____b;ptr command__contents;u64 command__length;char command__first;ptr command__memory;};
void run__811(void *__void__state);
struct run__812__state{errcode err;nominal command____c;ptr command__contents;u64 command__length;char command__first;ptr command__memory;};
void run__812(void *__void__state);
struct main__817__state{errcode err;};
void main__817(void *__void__state);
struct std_test__814__state{errcode err;cstr name;};
void std_test__814(void *__void__state);
struct std_test__815__state{errcode err;nominal name____b;ptr name__contents;u64 name__length;char name__first;ptr name__memory;};
void std_test__815(void *__void__state);
struct std_test__816__state{errcode err;nominal name____c;ptr name__contents;u64 name__length;char name__first;ptr name__memory;};
void std_test__816(void *__void__state);

void std_test__816(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__816__state *__state=(struct std_test__816__state*)__void__state;
struct run__812__state* __yBB____state = 0 ;
ptr name__contents= __state->name__contents;
u64 name__length= __state->name__length;
char name__first= __state->name__first;
ptr name__memory= __state->name__memory;
cstr __9BB____2h____pQ=0;
bool __9BB____2h____oQ__z=0;
bool __9BB____2h____oQ__x=0;
char __9BB____2h____hQ=0;
ptr __9BB____2h__mem=0;
ptr __9BB____2h__next_acquired=0;
u64 __9BB__len_y=0;
ptr __9BB____wh__noptr=0;
ptr __9BB____wh__contents=0;
u64 __9BB____wh__length=0;
cstr __8BB____Wd____pQ=0;
char __8BB____Wd____hQ=0;
bool __8BB____Wd__success=0;
u64 __8BB__total_len=0;
u64 __8BB__len_y=0;
char __9BB__first=0;
u64 __8BB__len_x=0;
cstr __6BB=0;
nominal __4BB__allocator____UQ=0;
char __9BB____wh__first=0;
cstr __4BB____2h____pQ=0;
bool __4BB____2h____oQ__z=0;
bool __4BB____2h____oQ__x=0;
u64 __4BB____2h__self__allocated__prev=0;
u64 __4BB____2h__next_size=0;
cstr __4BB____2h____lQ=0;
u64 __8BB____Wd__self__allocated__prev=0;
bool __4BB____2h____kQ__z=0;
u64 __4BB____zh__z=0;
u64 __4BB____yh=0;
u64 __4BB__total_len=0;
ptr __4BB____wh____m__contents=0;
char __4BB____wh__first=0;
u64 __4BB____wh__length=0;
nominal __3BB__allocator____UQ=0;
nominal __vBB____UQ=0;
cstr __3BB____Wd____pQ=0;
u64 __3BB____Wd__self__allocated__prev=0;
bool __3BB____Wd__success=0;
u64 __3BB____Wd__next_size=0;
u64 __3BB____Td__z=0;
char __3BB__first=0;
ptr __9BB____5h__contents=0;
u64 __9BB____2h__next_size=0;
u64 __3BB__len_x=0;
ptr __3BB____Rd____m__contents=0;
ptr __9BB____wh____m__contents=0;
ptr __3BB____Rd__noptr=0;
ptr __3BB____Rd__contents=0;
bool __3BB____Wd____oQ__x=0;
cstr __1BB=0;
ptr command__memory=0;
u64 command__length=0;
ptr command__contents=0;
u64 __vBB____aQ____dynamic_entry=0;
u64 __vBB____dynamic_entry=0;
u64 __vBB__allocated=0;
u64 __vBB____aQ____VQ=0;
ptr __vBB____aQ__acquired=0;
ptr __sBB____5h__contents=0;
cstr __sBB____2h____pQ=0;
bool __sBB____2h____oQ__z=0;
ptr __sBB____2h__mem=0;
ptr __sBB____2h__next_acquired=0;
u64 __vBB____aQ____WQ=0;
u64 __sBB____2h__self__allocated__prev=0;
nominal __8BB__allocator____UQ=0;
bool __sBB____2h____kQ__z=0;
u64 __sBB____zh__z=0;
char __sBB__first=0;
bool __9BB____2h__success=0;
u64 __8BB____Rd__length=0;
u64 __sBB__total_len=0;
u64 __9BB____2h__self__allocated__prev=0;
char __8BB____Rd__first=0;
u64 __sBB__len_y=0;
u64 __sBB__len_x=0;
ptr __sBB____wh____m__contents=0;
char __sBB____wh__first=0;
ptr __sBB____wh__contents=0;
nominal __rBB__allocator____UQ=0;
bool __rBB____Ik____oQ__z=0;
bool __rBB____Ik____oQ__x=0;
cstr __7BB=0;
ptr __rBB____Ik__next_acquired=0;
bool __rBB____Ik__success=0;
nominal __sBB__allocator____UQ=0;
bool __rBB____Ik____kQ__z=0;
u64 __8BB____Td__z=0;
u64 __rBB____Fk__z=0;
u64 __rBB____Ek=0;
u64 __qBB__total_len=0;
bool __qBB____Gb____oQ__z=0;
ptr __8BB____Rd____m__contents=0;
ptr __4BB____5h__contents=0;
u64 __8BB____Wd__next_size=0;
u64 __3BB__len_y=0;
cstr __3BB____Wd____lQ=0;
bool __sBB____2h____oQ__x=0;
bool __qBB____Gb__success=0;
u64 __sBB____yh=0;
cstr __rBB____Ik____pQ=0;
u64 __9BB__total_len=0;
char __8BB__first=0;
char __3BB____Wd____hQ=0;
bool __4BB____2h__success=0;
u64 __sBB____2h__next_size=0;
bool __3BB____Wd____oQ__z=0;
cstr __oBB=0;
cstr __rBB____Ik____lQ=0;
char __rBB____Ik____hQ=0;
u64 __rBB____Ik__next_size=0;
u64 __qBB__len_x=0;
u64 __4BB__len_x=0;
u64 __lBB____aQ____WQ=0;
bool __8BB____Wd____oQ__x=0;
char __3BB____Rd__first=0;
ptr __vBB__acquired=0;
u64 __qBB____Gb__next_size=0;
ptr __rBB____Ik__mem=0;
u64 __qBB__len_y=0;
ptr __4BB____2h__mem=0;
bool __8BB____Wd____kQ__z=0;
nominal __lBB____UQ=0;
u64 __9BB____zh__z=0;
u64 __rBB__len_y=0;
bool __8BB____Wd____oQ__z=0;
ptr __rBB____Lk__contents=0;
char __qBB____Ab__first=0;
char __sBB____2h____hQ=0;
u64 __3BB____Rd__length=0;
ptr __qBB____Gb__mem=0;
ptr __yBB____task=0;
ptr __qBB____Ab__contents=0;
errcode __yBB__err=0;
cstr __qBB____Gb____pQ=0;
ptr __3BB____Zd__contents=0;
ptr __3BB____Wd__mem=0;
ptr __8BB____Wd__mem=0;
ptr __sBB____wh__noptr=0;
cstr __sBB____2h____lQ=0;
ptr __qBB____Bb__noptr=0;
u64 __9BB__len_x=0;
cstr __2BB=0;
bool __qBB____Gb____oQ__x=0;
u64 __3BB__total_len=0;
ptr __3BB____Wd__next_acquired=0;
ptr __8BB____Rd__noptr=0;
ptr __8BB____Rd__contents=0;
u64 __9BB____yh=0;
ptr __8BB____Wd__next_acquired=0;
u64 __8BB____Sd=0;
ptr __4BB____wh__noptr=0;
bool __sBB____2h__success=0;
u64 __3BB____Sd=0;
char command__first=0;
u64 __rBB____Ik__self__allocated__prev=0;
cstr __8BB____Wd____lQ=0;
ptr __4BB____wh__contents=0;
ptr __lBB__acquired=0;
u64 __vBB__size=0;
nominal name____c=0;
ptr __lBB____aQ__acquired=0;
u64 __lBB____aQ____dynamic_entry=0;
nominal __9BB__allocator____UQ=0;
u64 __lBB__size=0;
u64 __lBB__allocated=0;
ptr __qBB____Bb____m__contents=0;
nominal __qBB__allocator____UQ=0;
u64 __4BB__len_y=0;
u64 __lBB____dynamic_entry=0;
u64 __lBB____aQ____VQ=0;
cstr __nBB=0;
bool __9BB____2h____kQ__z=0;
cstr __pBB=0;
u64 __qBB____Ab__length=0;
ptr __qBB____Ab__noptr=0;
cstr __qBB____Gb____lQ=0;
ptr __qBB____Ab____m__contents=0;
u64 __qBB____Bb__length=0;
char __4BB____2h____hQ=0;
ptr __qBB____Bb__contents=0;
char __qBB____Bb__first=0;
char __qBB__first=0;
u64 __qBB____Cb=0;
ptr __4BB____2h__next_acquired=0;
u64 __qBB____Db__z=0;
bool __qBB____Gb____kQ__z=0;
u64 __qBB____Gb__self__allocated__prev=0;
cstr __9BB____2h____lQ=0;
bool __3BB____Wd____kQ__z=0;
ptr __qBB____Gb__next_acquired=0;
char __qBB____Gb____hQ=0;
char __4BB__first=0;
ptr __qBB____Jb__contents=0;
u64 __rBB__len_x=0;
u64 __rBB__total_len=0;
ptr __8BB____Zd__contents=0;
nominal command____c=0;
u64 __sBB____wh__length=0;
char __rBB__first=0;

// IMPLEMENTATION
__kBB____end :
 __lBB____aQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __lBB____aQ__acquired )(( ptr **) __lBB____aQ__acquired )[0]=0; 
 __lBB____aQ____VQ = 0 ;
 __lBB____aQ____WQ = 0 ;
 __lBB____aQ____end :
 __lBB__acquired = __lBB____aQ__acquired ;
 __lBB__size = __lBB____aQ____VQ ;
 __lBB__allocated = __lBB____aQ____WQ ;
 __lBB____dynamic_entry = __lBB____aQ____dynamic_entry ;
 __lBB____end :
 __nBB = " 2>&1" ;
 __oBB = "./smol tests/unit/" ;
 __pBB = ".s --runtime eager" ;
 __qBB____Ab__length = strlen ( __pBB ); __qBB____Ab__contents =( ptr ) __pBB ; __qBB____Ab__first = __pBB [0]; __qBB____Ab__noptr =( ptr ) __qBB____Ab__noptr ; 
 __qBB____Ab____m__contents = __qBB____Ab__contents ;
 __qBB____Ab____m____end :
 __qBB____Ab____end :
 __qBB____Bb__length = strlen ( __nBB ); __qBB____Bb__contents =( ptr ) __nBB ; __qBB____Bb__first = __nBB [0]; __qBB____Bb__noptr =( ptr ) __qBB____Bb__noptr ; 
 __qBB____Bb____m__contents = __qBB____Bb__contents ;
 __qBB____Bb____m____end :
 __qBB____Bb____end :
 __qBB__len_x = __qBB____Ab__length ; __qBB__len_y = __qBB____Bb__length ; __qBB__total_len = __qBB__len_x + __qBB__len_y ; __qBB__first = __qBB____Ab__length ? __qBB____Ab__first : __qBB____Bb__first ; 
 __qBB____Cb = 1 ;
 __qBB____Db__z = __qBB__total_len + __qBB____Cb ; 
 __qBB____Db____end :
 __qBB____Gb____kQ__z =(! __lBB__acquired ); 
 __qBB____Gb____kQ____end :
 if(! __qBB____Gb____kQ__z )goto __qBB____Gb____iQ__fi ;
 __qBB____Gb____lQ = "Did not initialize Dynamic" ;
 goto __qBB____Gb____mQ____pD ;
 __builtin_unreachable();
 __qBB____Gb____mQ____end :
 __qBB____Gb____iQ__if :
 __qBB____Gb____iQ__fi :
 __qBB____Gb__next_size = __lBB__size +1; __qBB____Gb__success = true ; __qBB____Gb__self__allocated__prev = __lBB__allocated ; if ( __qBB____Gb__next_size >= __lBB__allocated ) { __lBB__allocated = __lBB__allocated + __lBB__allocated /2+1; __qBB____Gb__next_acquired =( ptr )((( ptr **) __lBB__acquired )[0]? __runtime_realloc ((( ptr **) __lBB__acquired )[0], __lBB__allocated * sizeof ( ptr ), __qBB____Gb__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __lBB__allocated * sizeof ( ptr ))); if ( __qBB____Gb__success = __qBB____Gb__next_acquired )(( ptr **) __lBB__acquired )[0]=( ptr *) __qBB____Gb__next_acquired ; } if ( __qBB____Gb__success ) { __qBB____Gb__mem =( ptr ) __runtime_alloc ( __qBB____Db__z * sizeof ( __qBB____Gb____hQ )); if ( __qBB____Gb__success = __qBB____Gb__mem ) {(( ptr **) __lBB__acquired )[0][ __lBB__size ]= __qBB____Gb__mem ; __lBB__size = __qBB____Gb__next_size ; } } 
 __qBB____Gb____oQ__x = __qBB____Gb__success ;
 __qBB____Gb____oQ__z =(! __qBB____Gb____oQ__x ); 
 __qBB____Gb____oQ____end :
 if(! __qBB____Gb____oQ__z )goto __qBB____Gb____nQ__fi ;
 __qBB____Gb____pQ = "Failed a Dynamic allocation" ;
 goto __qBB____Gb____qQ____pD ;
 __builtin_unreachable();
 __qBB____Gb____qQ____end :
 __qBB____Gb____nQ__if :
 __qBB____Gb____nQ__fi :
 __qBB____Gb____uQ____end :
 memcpy (( char *) __qBB____Gb__mem ,( char *) __qBB____Ab____m__contents , __qBB__len_x ); memcpy (( char *) __qBB____Gb__mem + __qBB__len_x ,( char *) __qBB____Bb____m__contents , __qBB__len_y );(( char *) __qBB____Gb__mem )[ __qBB__total_len ]=0; 
 __qBB____Jb__contents = __qBB____Gb__mem ;
 __qBB____Jb____end :
 __qBB____end :
 __lBB____UQ = __qBB__allocator____UQ ;
 __lBB__acquired = __lBB__acquired ;
 __lBB__size = __lBB__size ;
 __lBB__allocated = __lBB__allocated ;
 __lBB____dynamic_entry = __lBB____dynamic_entry ;
 __rBB____Ck____j____end :
 __rBB____Ck____end :
 __rBB____Dk____j____end :
 __rBB____Dk____end :
 __rBB__len_x = name__length ; __rBB__len_y = __qBB__total_len ; __rBB__total_len = __rBB__len_x + __rBB__len_y ; __rBB__first = name__length ? name__first : __qBB__first ; 
 __rBB____Ek = 1 ;
 __rBB____Fk__z = __rBB__total_len + __rBB____Ek ; 
 __rBB____Fk____end :
 __rBB____Ik____kQ__z =(! __lBB__acquired ); 
 __rBB____Ik____kQ____end :
 if(! __rBB____Ik____kQ__z )goto __rBB____Ik____iQ__fi ;
 __rBB____Ik____lQ = "Did not initialize Dynamic" ;
 goto __rBB____Ik____mQ____pD ;
 __builtin_unreachable();
 __rBB____Ik____mQ____end :
 __rBB____Ik____iQ__if :
 __rBB____Ik____iQ__fi :
 __rBB____Ik__next_size = __lBB__size +1; __rBB____Ik__success = true ; __rBB____Ik__self__allocated__prev = __lBB__allocated ; if ( __rBB____Ik__next_size >= __lBB__allocated ) { __lBB__allocated = __lBB__allocated + __lBB__allocated /2+1; __rBB____Ik__next_acquired =( ptr )((( ptr **) __lBB__acquired )[0]? __runtime_realloc ((( ptr **) __lBB__acquired )[0], __lBB__allocated * sizeof ( ptr ), __rBB____Ik__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __lBB__allocated * sizeof ( ptr ))); if ( __rBB____Ik__success = __rBB____Ik__next_acquired )(( ptr **) __lBB__acquired )[0]=( ptr *) __rBB____Ik__next_acquired ; } if ( __rBB____Ik__success ) { __rBB____Ik__mem =( ptr ) __runtime_alloc ( __rBB____Fk__z * sizeof ( __rBB____Ik____hQ )); if ( __rBB____Ik__success = __rBB____Ik__mem ) {(( ptr **) __lBB__acquired )[0][ __lBB__size ]= __rBB____Ik__mem ; __lBB__size = __rBB____Ik__next_size ; } } 
 __rBB____Ik____oQ__x = __rBB____Ik__success ;
 __rBB____Ik____oQ__z =(! __rBB____Ik____oQ__x ); 
 __rBB____Ik____oQ____end :
 if(! __rBB____Ik____oQ__z )goto __rBB____Ik____nQ__fi ;
 __rBB____Ik____pQ = "Failed a Dynamic allocation" ;
 goto __rBB____Ik____qQ____pD ;
 __builtin_unreachable();
 __rBB____Ik____qQ____end :
 __rBB____Ik____nQ__if :
 __rBB____Ik____nQ__fi :
 __rBB____Ik____uQ____end :
 memcpy (( char *) __rBB____Ik__mem ,( char *) name__contents , __rBB__len_x ); memcpy (( char *) __rBB____Ik__mem + __rBB__len_x ,( char *) __qBB____Jb__contents , __rBB__len_y );(( char *) __rBB____Ik__mem )[ __rBB__total_len ]=0; 
 __rBB____Lk__contents = __rBB____Ik__mem ;
 __rBB____Lk____end :
 __rBB____end :
 __lBB____UQ = __rBB__allocator____UQ ;
 __lBB__acquired = __lBB__acquired ;
 __lBB__size = __lBB__size ;
 __lBB__allocated = __lBB__allocated ;
 __lBB____dynamic_entry = __lBB____dynamic_entry ;
 __sBB____wh__length = strlen ( __oBB ); __sBB____wh__contents =( ptr ) __oBB ; __sBB____wh__first = __oBB [0]; __sBB____wh__noptr =( ptr ) __sBB____wh__noptr ; 
 __sBB____wh____m__contents = __sBB____wh__contents ;
 __sBB____wh____m____end :
 __sBB____wh____end :
 __sBB____xh____j____end :
 __sBB____xh____end :
 __sBB__len_x = __sBB____wh__length ; __sBB__len_y = __rBB__total_len ; __sBB__total_len = __sBB__len_x + __sBB__len_y ; __sBB__first = __sBB____wh__length ? __sBB____wh__first : __rBB__first ; 
 __sBB____yh = 1 ;
 __sBB____zh__z = __sBB__total_len + __sBB____yh ; 
 __sBB____zh____end :
 __sBB____2h____kQ__z =(! __lBB__acquired ); 
 __sBB____2h____kQ____end :
 if(! __sBB____2h____kQ__z )goto __sBB____2h____iQ__fi ;
 __sBB____2h____lQ = "Did not initialize Dynamic" ;
 goto __sBB____2h____mQ____pD ;
 __builtin_unreachable();
 __sBB____2h____mQ____end :
 __sBB____2h____iQ__if :
 __sBB____2h____iQ__fi :
 __sBB____2h__next_size = __lBB__size +1; __sBB____2h__success = true ; __sBB____2h__self__allocated__prev = __lBB__allocated ; if ( __sBB____2h__next_size >= __lBB__allocated ) { __lBB__allocated = __lBB__allocated + __lBB__allocated /2+1; __sBB____2h__next_acquired =( ptr )((( ptr **) __lBB__acquired )[0]? __runtime_realloc ((( ptr **) __lBB__acquired )[0], __lBB__allocated * sizeof ( ptr ), __sBB____2h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __lBB__allocated * sizeof ( ptr ))); if ( __sBB____2h__success = __sBB____2h__next_acquired )(( ptr **) __lBB__acquired )[0]=( ptr *) __sBB____2h__next_acquired ; } if ( __sBB____2h__success ) { __sBB____2h__mem =( ptr ) __runtime_alloc ( __sBB____zh__z * sizeof ( __sBB____2h____hQ )); if ( __sBB____2h__success = __sBB____2h__mem ) {(( ptr **) __lBB__acquired )[0][ __lBB__size ]= __sBB____2h__mem ; __lBB__size = __sBB____2h__next_size ; } } 
 __sBB____2h____oQ__x = __sBB____2h__success ;
 __sBB____2h____oQ__z =(! __sBB____2h____oQ__x ); 
 __sBB____2h____oQ____end :
 if(! __sBB____2h____oQ__z )goto __sBB____2h____nQ__fi ;
 __sBB____2h____pQ = "Failed a Dynamic allocation" ;
 goto __sBB____2h____qQ____pD ;
 __builtin_unreachable();
 __sBB____2h____qQ____end :
 __sBB____2h____nQ__if :
 __sBB____2h____nQ__fi :
 __sBB____2h____uQ____end :
 memcpy (( char *) __sBB____2h__mem ,( char *) __sBB____wh____m__contents , __sBB__len_x ); memcpy (( char *) __sBB____2h__mem + __sBB__len_x ,( char *) __rBB____Lk__contents , __sBB__len_y );(( char *) __sBB____2h__mem )[ __sBB__total_len ]=0; 
 __sBB____5h__contents = __sBB____2h__mem ;
 __sBB____5h____end :
 __sBB____end :
 __lBB____UQ = __sBB__allocator____UQ ;
 __lBB__acquired = __lBB__acquired ;
 __lBB__size = __lBB__size ;
 __lBB__allocated = __lBB__allocated ;
 __lBB____dynamic_entry = __lBB____dynamic_entry ;
 __mBB__on :
 __uBB____end :
 __vBB____aQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __vBB____aQ__acquired )(( ptr **) __vBB____aQ__acquired )[0]=0; 
 __vBB____aQ____VQ = 0 ;
 __vBB____aQ____WQ = 0 ;
 __vBB____aQ____end :
 __vBB__acquired = __vBB____aQ__acquired ;
 __vBB__size = __vBB____aQ____VQ ;
 __vBB__allocated = __vBB____aQ____WQ ;
 __vBB____dynamic_entry = __vBB____aQ____dynamic_entry ;
 __vBB____end :
 __yBB____state = (struct run__812__state*)__runtime_calloc(sizeof(struct run__812__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __yBB____state ) ;
 __yBB____state -> command____c = command____c ;
 __yBB____state -> command__contents = __sBB____5h__contents ;
 __yBB____state -> command__length = __sBB__total_len ;
 __yBB____state -> command__first = __sBB__first ;
 __yBB____state -> command__memory = __lBB__acquired ;
 __yBB____task = __smolambda_add_task ( run__812 , __yBB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __yBB____task ) ;
 if( __yBB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __yBB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __smolambda_task_wait ( __yBB____task ) ;
 __yBB__err = __yBB____state -> err ;
 if(! __yBB__err )goto __xBB__fi ;
 __1BB = "[ \033[31mERROR\033[0m ] " ;
 __2BB = ".s" ;
 __3BB____Qd____j____end :
 __3BB____Qd____end :
 __3BB____Rd__length = strlen ( __2BB ); __3BB____Rd__contents =( ptr ) __2BB ; __3BB____Rd__first = __2BB [0]; __3BB____Rd__noptr =( ptr ) __3BB____Rd__noptr ; 
 __3BB____Rd____m__contents = __3BB____Rd__contents ;
 __3BB____Rd____m____end :
 __3BB____Rd____end :
 __3BB__len_x = name__length ; __3BB__len_y = __3BB____Rd__length ; __3BB__total_len = __3BB__len_x + __3BB__len_y ; __3BB__first = name__length ? name__first : __3BB____Rd__first ; 
 __3BB____Sd = 1 ;
 __3BB____Td__z = __3BB__total_len + __3BB____Sd ; 
 __3BB____Td____end :
 __3BB____Wd____kQ__z =(! __vBB__acquired ); 
 __3BB____Wd____kQ____end :
 if(! __3BB____Wd____kQ__z )goto __3BB____Wd____iQ__fi ;
 __3BB____Wd____lQ = "Did not initialize Dynamic" ;
 goto __3BB____Wd____mQ____pD ;
 __builtin_unreachable();
 __3BB____Wd____mQ____end :
 __3BB____Wd____iQ__if :
 __3BB____Wd____iQ__fi :
 __3BB____Wd__next_size = __vBB__size +1; __3BB____Wd__success = true ; __3BB____Wd__self__allocated__prev = __vBB__allocated ; if ( __3BB____Wd__next_size >= __vBB__allocated ) { __vBB__allocated = __vBB__allocated + __vBB__allocated /2+1; __3BB____Wd__next_acquired =( ptr )((( ptr **) __vBB__acquired )[0]? __runtime_realloc ((( ptr **) __vBB__acquired )[0], __vBB__allocated * sizeof ( ptr ), __3BB____Wd__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __vBB__allocated * sizeof ( ptr ))); if ( __3BB____Wd__success = __3BB____Wd__next_acquired )(( ptr **) __vBB__acquired )[0]=( ptr *) __3BB____Wd__next_acquired ; } if ( __3BB____Wd__success ) { __3BB____Wd__mem =( ptr ) __runtime_alloc ( __3BB____Td__z * sizeof ( __3BB____Wd____hQ )); if ( __3BB____Wd__success = __3BB____Wd__mem ) {(( ptr **) __vBB__acquired )[0][ __vBB__size ]= __3BB____Wd__mem ; __vBB__size = __3BB____Wd__next_size ; } } 
 __3BB____Wd____oQ__x = __3BB____Wd__success ;
 __3BB____Wd____oQ__z =(! __3BB____Wd____oQ__x ); 
 __3BB____Wd____oQ____end :
 if(! __3BB____Wd____oQ__z )goto __3BB____Wd____nQ__fi ;
 __3BB____Wd____pQ = "Failed a Dynamic allocation" ;
 goto __3BB____Wd____qQ____pD ;
 __builtin_unreachable();
 __3BB____Wd____qQ____end :
 __3BB____Wd____nQ__if :
 __3BB____Wd____nQ__fi :
 __3BB____Wd____uQ____end :
 memcpy (( char *) __3BB____Wd__mem ,( char *) name__contents , __3BB__len_x ); memcpy (( char *) __3BB____Wd__mem + __3BB__len_x ,( char *) __3BB____Rd____m__contents , __3BB__len_y );(( char *) __3BB____Wd__mem )[ __3BB__total_len ]=0; 
 __3BB____Zd__contents = __3BB____Wd__mem ;
 __3BB____Zd____end :
 __3BB____end :
 __vBB____UQ = __3BB__allocator____UQ ;
 __vBB__acquired = __vBB__acquired ;
 __vBB__size = __vBB__size ;
 __vBB__allocated = __vBB__allocated ;
 __vBB____dynamic_entry = __vBB____dynamic_entry ;
 __4BB____wh__length = strlen ( __1BB ); __4BB____wh__contents =( ptr ) __1BB ; __4BB____wh__first = __1BB [0]; __4BB____wh__noptr =( ptr ) __4BB____wh__noptr ; 
 __4BB____wh____m__contents = __4BB____wh__contents ;
 __4BB____wh____m____end :
 __4BB____wh____end :
 __4BB____xh____j____end :
 __4BB____xh____end :
 __4BB__len_x = __4BB____wh__length ; __4BB__len_y = __3BB__total_len ; __4BB__total_len = __4BB__len_x + __4BB__len_y ; __4BB__first = __4BB____wh__length ? __4BB____wh__first : __3BB__first ; 
 __4BB____yh = 1 ;
 __4BB____zh__z = __4BB__total_len + __4BB____yh ; 
 __4BB____zh____end :
 __4BB____2h____kQ__z =(! __vBB__acquired ); 
 __4BB____2h____kQ____end :
 if(! __4BB____2h____kQ__z )goto __4BB____2h____iQ__fi ;
 __4BB____2h____lQ = "Did not initialize Dynamic" ;
 goto __4BB____2h____mQ____pD ;
 __builtin_unreachable();
 __4BB____2h____mQ____end :
 __4BB____2h____iQ__if :
 __4BB____2h____iQ__fi :
 __4BB____2h__next_size = __vBB__size +1; __4BB____2h__success = true ; __4BB____2h__self__allocated__prev = __vBB__allocated ; if ( __4BB____2h__next_size >= __vBB__allocated ) { __vBB__allocated = __vBB__allocated + __vBB__allocated /2+1; __4BB____2h__next_acquired =( ptr )((( ptr **) __vBB__acquired )[0]? __runtime_realloc ((( ptr **) __vBB__acquired )[0], __vBB__allocated * sizeof ( ptr ), __4BB____2h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __vBB__allocated * sizeof ( ptr ))); if ( __4BB____2h__success = __4BB____2h__next_acquired )(( ptr **) __vBB__acquired )[0]=( ptr *) __4BB____2h__next_acquired ; } if ( __4BB____2h__success ) { __4BB____2h__mem =( ptr ) __runtime_alloc ( __4BB____zh__z * sizeof ( __4BB____2h____hQ )); if ( __4BB____2h__success = __4BB____2h__mem ) {(( ptr **) __vBB__acquired )[0][ __vBB__size ]= __4BB____2h__mem ; __vBB__size = __4BB____2h__next_size ; } } 
 __4BB____2h____oQ__x = __4BB____2h__success ;
 __4BB____2h____oQ__z =(! __4BB____2h____oQ__x ); 
 __4BB____2h____oQ____end :
 if(! __4BB____2h____oQ__z )goto __4BB____2h____nQ__fi ;
 __4BB____2h____pQ = "Failed a Dynamic allocation" ;
 goto __4BB____2h____qQ____pD ;
 __builtin_unreachable();
 __4BB____2h____qQ____end :
 __4BB____2h____nQ__if :
 __4BB____2h____nQ__fi :
 __4BB____2h____uQ____end :
 memcpy (( char *) __4BB____2h__mem ,( char *) __4BB____wh____m__contents , __4BB__len_x ); memcpy (( char *) __4BB____2h__mem + __4BB__len_x ,( char *) __3BB____Zd__contents , __4BB__len_y );(( char *) __4BB____2h__mem )[ __4BB__total_len ]=0; 
 __4BB____5h__contents = __4BB____2h__mem ;
 __4BB____5h____end :
 __4BB____end :
 __vBB____UQ = __4BB__allocator____UQ ;
 __vBB__acquired = __vBB__acquired ;
 __vBB__size = __vBB__size ;
 __vBB__allocated = __vBB__allocated ;
 __vBB____dynamic_entry = __vBB____dynamic_entry ;
 printf ( "%s\n" ,( char *) __4BB____5h__contents ); 
 __5BB____end :
 __xBB__if :
 goto __xBB__el ;
 __xBB__fi :
 __6BB = "[ \033[32mOK\033[0m ] " ;
 __7BB = ".s" ;
 __8BB____Qd____j____end :
 __8BB____Qd____end :
 __8BB____Rd__length = strlen ( __7BB ); __8BB____Rd__contents =( ptr ) __7BB ; __8BB____Rd__first = __7BB [0]; __8BB____Rd__noptr =( ptr ) __8BB____Rd__noptr ; 
 __8BB____Rd____m__contents = __8BB____Rd__contents ;
 __8BB____Rd____m____end :
 __8BB____Rd____end :
 __8BB__len_x = name__length ; __8BB__len_y = __8BB____Rd__length ; __8BB__total_len = __8BB__len_x + __8BB__len_y ; __8BB__first = name__length ? name__first : __8BB____Rd__first ; 
 __8BB____Sd = 1 ;
 __8BB____Td__z = __8BB__total_len + __8BB____Sd ; 
 __8BB____Td____end :
 __8BB____Wd____kQ__z =(! __vBB__acquired ); 
 __8BB____Wd____kQ____end :
 if(! __8BB____Wd____kQ__z )goto __8BB____Wd____iQ__fi ;
 __8BB____Wd____lQ = "Did not initialize Dynamic" ;
 goto __8BB____Wd____mQ____pD ;
 __builtin_unreachable();
 __8BB____Wd____mQ____end :
 __8BB____Wd____iQ__if :
 __8BB____Wd____iQ__fi :
 __8BB____Wd__next_size = __vBB__size +1; __8BB____Wd__success = true ; __8BB____Wd__self__allocated__prev = __vBB__allocated ; if ( __8BB____Wd__next_size >= __vBB__allocated ) { __vBB__allocated = __vBB__allocated + __vBB__allocated /2+1; __8BB____Wd__next_acquired =( ptr )((( ptr **) __vBB__acquired )[0]? __runtime_realloc ((( ptr **) __vBB__acquired )[0], __vBB__allocated * sizeof ( ptr ), __8BB____Wd__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __vBB__allocated * sizeof ( ptr ))); if ( __8BB____Wd__success = __8BB____Wd__next_acquired )(( ptr **) __vBB__acquired )[0]=( ptr *) __8BB____Wd__next_acquired ; } if ( __8BB____Wd__success ) { __8BB____Wd__mem =( ptr ) __runtime_alloc ( __8BB____Td__z * sizeof ( __8BB____Wd____hQ )); if ( __8BB____Wd__success = __8BB____Wd__mem ) {(( ptr **) __vBB__acquired )[0][ __vBB__size ]= __8BB____Wd__mem ; __vBB__size = __8BB____Wd__next_size ; } } 
 __8BB____Wd____oQ__x = __8BB____Wd__success ;
 __8BB____Wd____oQ__z =(! __8BB____Wd____oQ__x ); 
 __8BB____Wd____oQ____end :
 if(! __8BB____Wd____oQ__z )goto __8BB____Wd____nQ__fi ;
 __8BB____Wd____pQ = "Failed a Dynamic allocation" ;
 goto __8BB____Wd____qQ____pD ;
 __builtin_unreachable();
 __8BB____Wd____qQ____end :
 __8BB____Wd____nQ__if :
 __8BB____Wd____nQ__fi :
 __8BB____Wd____uQ____end :
 memcpy (( char *) __8BB____Wd__mem ,( char *) name__contents , __8BB__len_x ); memcpy (( char *) __8BB____Wd__mem + __8BB__len_x ,( char *) __8BB____Rd____m__contents , __8BB__len_y );(( char *) __8BB____Wd__mem )[ __8BB__total_len ]=0; 
 __8BB____Zd__contents = __8BB____Wd__mem ;
 __8BB____Zd____end :
 __8BB____end :
 __vBB____UQ = __8BB__allocator____UQ ;
 __vBB__acquired = __vBB__acquired ;
 __vBB__size = __vBB__size ;
 __vBB__allocated = __vBB__allocated ;
 __vBB____dynamic_entry = __vBB____dynamic_entry ;
 __9BB____wh__length = strlen ( __6BB ); __9BB____wh__contents =( ptr ) __6BB ; __9BB____wh__first = __6BB [0]; __9BB____wh__noptr =( ptr ) __9BB____wh__noptr ; 
 __9BB____wh____m__contents = __9BB____wh__contents ;
 __9BB____wh____m____end :
 __9BB____wh____end :
 __9BB____xh____j____end :
 __9BB____xh____end :
 __9BB__len_x = __9BB____wh__length ; __9BB__len_y = __8BB__total_len ; __9BB__total_len = __9BB__len_x + __9BB__len_y ; __9BB__first = __9BB____wh__length ? __9BB____wh__first : __8BB__first ; 
 __9BB____yh = 1 ;
 __9BB____zh__z = __9BB__total_len + __9BB____yh ; 
 __9BB____zh____end :
 __9BB____2h____kQ__z =(! __vBB__acquired ); 
 __9BB____2h____kQ____end :
 if(! __9BB____2h____kQ__z )goto __9BB____2h____iQ__fi ;
 __9BB____2h____lQ = "Did not initialize Dynamic" ;
 goto __9BB____2h____mQ____pD ;
 __builtin_unreachable();
 __9BB____2h____mQ____end :
 __9BB____2h____iQ__if :
 __9BB____2h____iQ__fi :
 __9BB____2h__next_size = __vBB__size +1; __9BB____2h__success = true ; __9BB____2h__self__allocated__prev = __vBB__allocated ; if ( __9BB____2h__next_size >= __vBB__allocated ) { __vBB__allocated = __vBB__allocated + __vBB__allocated /2+1; __9BB____2h__next_acquired =( ptr )((( ptr **) __vBB__acquired )[0]? __runtime_realloc ((( ptr **) __vBB__acquired )[0], __vBB__allocated * sizeof ( ptr ), __9BB____2h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __vBB__allocated * sizeof ( ptr ))); if ( __9BB____2h__success = __9BB____2h__next_acquired )(( ptr **) __vBB__acquired )[0]=( ptr *) __9BB____2h__next_acquired ; } if ( __9BB____2h__success ) { __9BB____2h__mem =( ptr ) __runtime_alloc ( __9BB____zh__z * sizeof ( __9BB____2h____hQ )); if ( __9BB____2h__success = __9BB____2h__mem ) {(( ptr **) __vBB__acquired )[0][ __vBB__size ]= __9BB____2h__mem ; __vBB__size = __9BB____2h__next_size ; } } 
 __9BB____2h____oQ__x = __9BB____2h__success ;
 __9BB____2h____oQ__z =(! __9BB____2h____oQ__x ); 
 __9BB____2h____oQ____end :
 if(! __9BB____2h____oQ__z )goto __9BB____2h____nQ__fi ;
 __9BB____2h____pQ = "Failed a Dynamic allocation" ;
 goto __9BB____2h____qQ____pD ;
 __builtin_unreachable();
 __9BB____2h____qQ____end :
 __9BB____2h____nQ__if :
 __9BB____2h____nQ__fi :
 __9BB____2h____uQ____end :
 memcpy (( char *) __9BB____2h__mem ,( char *) __9BB____wh____m__contents , __9BB__len_x ); memcpy (( char *) __9BB____2h__mem + __9BB__len_x ,( char *) __8BB____Zd__contents , __9BB__len_y );(( char *) __9BB____2h__mem )[ __9BB__total_len ]=0; 
 __9BB____5h__contents = __9BB____2h__mem ;
 __9BB____5h____end :
 __9BB____end :
 __vBB____UQ = __9BB__allocator____UQ ;
 __vBB__acquired = __vBB__acquired ;
 __vBB__size = __vBB__size ;
 __vBB__allocated = __vBB__allocated ;
 __vBB____dynamic_entry = __vBB____dynamic_entry ;
 printf ( "%s\n" ,( char *) __9BB____5h__contents ); 
 __ACB____end :
 __xBB__le :
 __xBB__el :
 __wBB__on :
 __end :
goto __return;

// ERROR HANDLING
__qBB____Gb____mQ____pD :
 printf ( "%s\n" , __qBB____Gb____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __qBB____Gb____qQ____pD :
 printf ( "%s\n" , __qBB____Gb____pQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __rBB____Ik____mQ____pD :
 printf ( "%s\n" , __rBB____Ik____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __rBB____Ik____qQ____pD :
 printf ( "%s\n" , __rBB____Ik____pQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __sBB____2h____mQ____pD :
 printf ( "%s\n" , __sBB____2h____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __sBB____2h____qQ____pD :
 printf ( "%s\n" , __sBB____2h____pQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __zBB :
printf("Runtime error from run __yBB \n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
 __3BB____Wd____mQ____pD :
 printf ( "%s\n" , __3BB____Wd____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __3BB____Wd____qQ____pD :
 printf ( "%s\n" , __3BB____Wd____pQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __4BB____2h____mQ____pD :
 printf ( "%s\n" , __4BB____2h____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __4BB____2h____qQ____pD :
 printf ( "%s\n" , __4BB____2h____pQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __8BB____Wd____mQ____pD :
 printf ( "%s\n" , __8BB____Wd____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __8BB____Wd____qQ____pD :
 printf ( "%s\n" , __8BB____Wd____pQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __9BB____2h____mQ____pD :
 printf ( "%s\n" , __9BB____2h____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __9BB____2h____qQ____pD :
 printf ( "%s\n" , __9BB____2h____pQ ); 
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
if ( __vBB__acquired ) { for ( __vBB____dynamic_entry =0; __vBB____dynamic_entry < __vBB__size ;++ __vBB____dynamic_entry ) { __runtime_free ((( ptr **) __vBB__acquired )[0][ __vBB____dynamic_entry ]); } __runtime_free ( __vBB__acquired ); __vBB__acquired =0; __vBB__size =0; __vBB__allocated =0; } 
 if ( __vBB__acquired ) { for ( __vBB____aQ____dynamic_entry =0; __vBB____aQ____dynamic_entry < __vBB____aQ____VQ ;++ __vBB____aQ____dynamic_entry ) { __runtime_free ((( ptr **) __vBB__acquired )[0][ __vBB____aQ____dynamic_entry ]); } __runtime_free ( __vBB__acquired ); __vBB__acquired =0; __vBB____aQ____VQ =0; __vBB____aQ____WQ =0; } 
if ( __lBB__acquired ) { for ( __lBB____dynamic_entry =0; __lBB____dynamic_entry < __lBB__size ;++ __lBB____dynamic_entry ) { __runtime_free ((( ptr **) __lBB__acquired )[0][ __lBB____dynamic_entry ]); } __runtime_free ( __lBB__acquired ); __lBB__acquired =0; __lBB__size =0; __lBB__allocated =0; } 
 if ( __lBB__acquired ) { for ( __lBB____aQ____dynamic_entry =0; __lBB____aQ____dynamic_entry < __lBB____aQ____VQ ;++ __lBB____aQ____dynamic_entry ) { __runtime_free ((( ptr **) __lBB__acquired )[0][ __lBB____aQ____dynamic_entry ]); } __runtime_free ( __lBB__acquired ); __lBB__acquired =0; __lBB____aQ____VQ =0; __lBB____aQ____WQ =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}


void main__817(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__817__state *__state=(struct main__817__state*)__void__state;
struct std_test__814__state* __CCB____state = 0 ;
 struct std_test__814__state* __ECB____state = 0 ;
 struct std_test__814__state* __GCB____state = 0 ;
 struct std_test__814__state* __ICB____state = 0 ;
 struct std_test__814__state* __KCB____state = 0 ;
 struct std_test__814__state* __MCB____state = 0 ;
 struct std_test__814__state* __OCB____state = 0 ;
 struct std_test__814__state* __QCB____state = 0 ;
 struct std_test__814__state* __SCB____state = 0 ;
 struct std_test__814__state* __UCB____state = 0 ;
 struct std_test__814__state* __WCB____state = 0 ;
 struct std_test__814__state* __YCB____state = 0 ;
 struct std_test__814__state* __aCB____state = 0 ;
 struct std_test__814__state* __cCB____state = 0 ;
 struct std_test__814__state* __eCB____state = 0 ;
 struct std_test__814__state* __gCB____state = 0 ;
 struct std_test__814__state* __iCB____state = 0 ;
 struct std_test__814__state* __kCB____state = 0 ;
 struct std_test__814__state* __mCB____state = 0 ;
 struct std_test__814__state* __oCB____state = 0 ;
 struct std_test__814__state* __qCB____state = 0 ;
cstr __nCB=0;
ptr __mCB____task=0;
cstr __hCB=0;
errcode __gCB__err=0;
errcode __eCB__err=0;
ptr __eCB____task=0;
errcode __cCB__err=0;
ptr __cCB____task=0;
cstr __bCB=0;
ptr __aCB____task=0;
cstr __ZCB=0;
errcode __YCB__err=0;
errcode __WCB__err=0;
ptr __WCB____task=0;
ptr __UCB____task=0;
errcode __SCB__err=0;
errcode __QCB__err=0;
ptr __QCB____task=0;
cstr __PCB=0;
ptr __OCB____task=0;
cstr __NCB=0;
errcode __MCB__err=0;
errcode __KCB__err=0;
errcode __ICB__err=0;
ptr __ICB____task=0;
cstr __FCB=0;
errcode __ECB__err=0;
cstr __DCB=0;
errcode __CCB__err=0;
cstr __LCB=0;
errcode __GCB__err=0;
cstr __XCB=0;
errcode __OCB__err=0;
cstr __dCB=0;
errcode __kCB__err=0;
ptr __gCB____task=0;
cstr __lCB=0;
errcode __iCB__err=0;
ptr __kCB____task=0;
ptr __SCB____task=0;
cstr __RCB=0;
ptr __MCB____task=0;
cstr __HCB=0;
ptr __qCB____task=0;
cstr __TCB=0;
errcode __qCB__err=0;
ptr __YCB____task=0;
ptr __KCB____task=0;
cstr __BCB=0;
ptr __ECB____task=0;
ptr __CCB____task=0;
errcode __UCB__err=0;
ptr __oCB____task=0;
cstr __jCB=0;
ptr __GCB____task=0;
cstr __VCB=0;
cstr __JCB=0;
cstr __fCB=0;
ptr __iCB____task=0;
cstr __pCB=0;
errcode __oCB__err=0;
errcode __mCB__err=0;
errcode __aCB__err=0;

// IMPLEMENTATION
__BCB = "buffers" ;
 __CCB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __CCB____state ) ;
 __CCB____state -> name = __BCB ;
 __CCB____task = __smolambda_add_task ( std_test__814 , __CCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __CCB____task ) ;
 if( __CCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __CCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __DCB = "bbuffer" ;
 __ECB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __ECB____state ) ;
 __ECB____state -> name = __DCB ;
 __ECB____task = __smolambda_add_task ( std_test__814 , __ECB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __ECB____task ) ;
 if( __ECB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __ECB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __FCB = "bufferconst" ;
 __GCB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __GCB____state ) ;
 __GCB____state -> name = __FCB ;
 __GCB____task = __smolambda_add_task ( std_test__814 , __GCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __GCB____task ) ;
 if( __GCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __GCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __HCB = "buffergrow" ;
 __ICB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __ICB____state ) ;
 __ICB____state -> name = __HCB ;
 __ICB____task = __smolambda_add_task ( std_test__814 , __ICB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __ICB____task ) ;
 if( __ICB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __ICB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __JCB = "effvec" ;
 __KCB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __KCB____state ) ;
 __KCB____state -> name = __JCB ;
 __KCB____task = __smolambda_add_task ( std_test__814 , __KCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __KCB____task ) ;
 if( __KCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __KCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __LCB = "fail" ;
 __MCB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __MCB____state ) ;
 __MCB____state -> name = __LCB ;
 __MCB____task = __smolambda_add_task ( std_test__814 , __MCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __MCB____task ) ;
 if( __MCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __MCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __NCB = "file" ;
 __OCB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __OCB____state ) ;
 __OCB____state -> name = __NCB ;
 __OCB____task = __smolambda_add_task ( std_test__814 , __OCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __OCB____task ) ;
 if( __OCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __OCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __PCB = "filesize" ;
 __QCB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __QCB____state ) ;
 __QCB____state -> name = __PCB ;
 __QCB____task = __smolambda_add_task ( std_test__814 , __QCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __QCB____task ) ;
 if( __QCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __QCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __RCB = "finally" ;
 __SCB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __SCB____state ) ;
 __SCB____state -> name = __RCB ;
 __SCB____task = __smolambda_add_task ( std_test__814 , __SCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __SCB____task ) ;
 if( __SCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __SCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __TCB = "map" ;
 __UCB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __UCB____state ) ;
 __UCB____state -> name = __TCB ;
 __UCB____task = __smolambda_add_task ( std_test__814 , __UCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __UCB____task ) ;
 if( __UCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __UCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __VCB = "nom" ;
 __WCB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __WCB____state ) ;
 __WCB____state -> name = __VCB ;
 __WCB____task = __smolambda_add_task ( std_test__814 , __WCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __WCB____task ) ;
 if( __WCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __WCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __XCB = "unsafe" ;
 __YCB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __YCB____state ) ;
 __YCB____state -> name = __XCB ;
 __YCB____task = __smolambda_add_task ( std_test__814 , __YCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __YCB____task ) ;
 if( __YCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __YCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __ZCB = "mem" ;
 __aCB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __aCB____state ) ;
 __aCB____state -> name = __ZCB ;
 __aCB____task = __smolambda_add_task ( std_test__814 , __aCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __aCB____task ) ;
 if( __aCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __aCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __bCB = "memtest" ;
 __cCB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __cCB____state ) ;
 __cCB____state -> name = __bCB ;
 __cCB____task = __smolambda_add_task ( std_test__814 , __cCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __cCB____task ) ;
 if( __cCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __cCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __dCB = "mutpoint" ;
 __eCB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __eCB____state ) ;
 __eCB____state -> name = __dCB ;
 __eCB____task = __smolambda_add_task ( std_test__814 , __eCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __eCB____task ) ;
 if( __eCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __eCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __fCB = "range_test" ;
 __gCB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __gCB____state ) ;
 __gCB____state -> name = __fCB ;
 __gCB____task = __smolambda_add_task ( std_test__814 , __gCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __gCB____task ) ;
 if( __gCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __gCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __hCB = "ref" ;
 __iCB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __iCB____state ) ;
 __iCB____state -> name = __hCB ;
 __iCB____task = __smolambda_add_task ( std_test__814 , __iCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __iCB____task ) ;
 if( __iCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __iCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __jCB = "strcat" ;
 __kCB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __kCB____state ) ;
 __kCB____state -> name = __jCB ;
 __kCB____task = __smolambda_add_task ( std_test__814 , __kCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __kCB____task ) ;
 if( __kCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __kCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __lCB = "vec" ;
 __mCB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __mCB____state ) ;
 __mCB____state -> name = __lCB ;
 __mCB____task = __smolambda_add_task ( std_test__814 , __mCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __mCB____task ) ;
 if( __mCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __mCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __nCB = "virtfile" ;
 __oCB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __oCB____state ) ;
 __oCB____state -> name = __nCB ;
 __oCB____task = __smolambda_add_task ( std_test__814 , __oCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __oCB____task ) ;
 if( __oCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __oCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __pCB = "accessvar" ;
 __qCB____state = (struct std_test__814__state*)__runtime_calloc(sizeof(struct std_test__814__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __qCB____state ) ;
 __qCB____state -> name = __pCB ;
 __qCB____task = __smolambda_add_task ( std_test__814 , __qCB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __qCB____task ) ;
 if( __qCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __qCB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __end :
goto __return;

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


void std_test__815(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__815__state *__state=(struct std_test__815__state*)__void__state;
struct run__812__state* __WBB____state = 0 ;
ptr name__contents= __state->name__contents;
u64 name__length= __state->name__length;
char name__first= __state->name__first;
ptr name__memory= __state->name__memory;
ptr __hBB____5h__contents=0;
cstr __hBB____2h____pQ=0;
bool __hBB____2h____oQ__z=0;
ptr __hBB____2h__next_acquired=0;
bool __hBB____2h__success=0;
u64 __hBB____2h__next_size=0;
cstr __hBB____2h____lQ=0;
bool __hBB____2h____kQ__z=0;
u64 __hBB____zh__z=0;
u64 __hBB__total_len=0;
u64 __hBB__len_y=0;
ptr __hBB____wh____m__contents=0;
char __hBB____wh__first=0;
bool __hBB____2h____oQ__x=0;
u64 __hBB____wh__length=0;
nominal __gBB__allocator____UQ=0;
bool __gBB____Oc____oQ__x=0;
u64 __gBB____Oc__next_size=0;
bool __gBB____Oc____kQ__z=0;
u64 __gBB____Kc=0;
ptr __gBB____Jc____m__contents=0;
ptr __gBB____Jc__contents=0;
ptr __cBB____5h__contents=0;
bool __cBB____2h____oQ__z=0;
bool __cBB____2h____oQ__x=0;
char __cBB____2h____hQ=0;
u64 __cBB____2h__self__allocated__prev=0;
u64 __cBB____2h__next_size=0;
cstr __gBB____Oc____pQ=0;
bool __cBB____2h__success=0;
cstr __cBB____2h____lQ=0;
u64 __cBB____zh__z=0;
u64 __cBB____yh=0;
u64 __cBB__total_len=0;
u64 __cBB__len_y=0;
u64 __hBB____yh=0;
ptr __cBB____wh__noptr=0;
char __cBB____wh__first=0;
ptr __cBB____wh__contents=0;
u64 __cBB____wh__length=0;
nominal __bBB__allocator____UQ=0;
char __bBB____Oc____hQ=0;
ptr __bBB____Oc__mem=0;
ptr __bBB____Oc__next_acquired=0;
u64 __bBB____Oc__self__allocated__prev=0;
bool __bBB____Oc__success=0;
bool __bBB____Oc____kQ__z=0;
u64 __bBB____Kc=0;
char __bBB__first=0;
ptr __bBB____Jc____m__contents=0;
ptr __cBB____2h__mem=0;
ptr __bBB____Jc__noptr=0;
bool __gBB____Oc__success=0;
u64 __bBB____Jc__length=0;
cstr __aBB=0;
u64 __hBB____2h__self__allocated__prev=0;
errcode __WBB__err=0;
char __hBB__first=0;
ptr __WBB____task=0;
char command__first=0;
nominal command____c=0;
u64 __TBB__allocated=0;
char __gBB____Jc__first=0;
u64 __TBB____aQ____WQ=0;
cstr __QBB____2h____pQ=0;
bool __QBB____2h____oQ__z=0;
char __QBB____2h____hQ=0;
ptr __QBB____2h__mem=0;
nominal __hBB__allocator____UQ=0;
u64 __QBB____2h__self__allocated__prev=0;
bool __QBB____2h__success=0;
u64 __QBB____2h__next_size=0;
ptr __gBB____Oc__next_acquired=0;
u64 __bBB__len_x=0;
ptr __hBB____wh__contents=0;
u64 __bBB__len_y=0;
u64 __QBB__total_len=0;
u64 __QBB__len_y=0;
ptr __QBB____wh____m__contents=0;
cstr __eBB=0;
ptr __QBB____wh__noptr=0;
nominal __PBB__allocator____UQ=0;
char __cBB__first=0;
ptr __hBB____wh__noptr=0;
ptr __PBB____Dj__contents=0;
bool __QBB____2h____kQ__z=0;
cstr __PBB____Aj____pQ=0;
char __gBB__first=0;
bool __PBB____Aj____oQ__z=0;
bool __PBB____Aj____oQ__x=0;
char __PBB____Aj____hQ=0;
bool __PBB____Aj__success=0;
u64 __PBB____Aj__next_size=0;
ptr command__contents=0;
ptr __OBB____Bb__noptr=0;
u64 __PBB__len_y=0;
u64 __bBB____Oc__next_size=0;
bool __gBB____Oc____oQ__z=0;
ptr __gBB____Oc__mem=0;
cstr __fBB=0;
cstr __MBB=0;
u64 __OBB____Bb__length=0;
ptr __gBB____Jc__noptr=0;
nominal __TBB____UQ=0;
bool __bBB____Oc____oQ__z=0;
u64 __PBB____Aj__self__allocated__prev=0;
u64 __PBB____7i__z=0;
char __gBB____Oc____hQ=0;
cstr __LBB=0;
u64 __OBB____Cb=0;
ptr __TBB____aQ__acquired=0;
u64 __QBB__len_x=0;
bool __bBB____Oc____oQ__x=0;
char __QBB__first=0;
u64 __OBB__total_len=0;
ptr __PBB____Aj__mem=0;
ptr __OBB____Ab__contents=0;
u64 __gBB__total_len=0;
ptr __QBB____wh__contents=0;
u64 __bBB__total_len=0;
cstr __QBB____2h____lQ=0;
u64 __QBB____zh__z=0;
u64 __gBB____Lc__z=0;
u64 command__length=0;
u64 __TBB____aQ____VQ=0;
ptr __cBB____2h__next_acquired=0;
u64 __QBB____wh__length=0;
char __OBB__first=0;
u64 __gBB__len_y=0;
cstr __bBB____Oc____lQ=0;
u64 __gBB__len_x=0;
u64 __hBB__len_x=0;
char __PBB__first=0;
u64 __gBB____Jc__length=0;
char __bBB____Jc__first=0;
cstr __NBB=0;
nominal __JBB____UQ=0;
ptr __QBB____5h__contents=0;
u64 __PBB__total_len=0;
cstr __bBB____Oc____pQ=0;
cstr __gBB____Oc____lQ=0;
ptr __hBB____2h__mem=0;
cstr __ZBB=0;
u64 __OBB____Ab__length=0;
char __OBB____Bb__first=0;
ptr __bBB____Jc__contents=0;
u64 __OBB__len_x=0;
bool __OBB____Gb__success=0;
u64 __PBB__len_x=0;
ptr __OBB____Bb__contents=0;
u64 __OBB____Db__z=0;
ptr __JBB____aQ__acquired=0;
ptr __OBB____Gb__next_acquired=0;
u64 __JBB____aQ____dynamic_entry=0;
char __QBB____wh__first=0;
ptr __QBB____2h__next_acquired=0;
ptr __PBB____Aj__next_acquired=0;
u64 __PBB____6i=0;
nominal __cBB__allocator____UQ=0;
u64 __bBB____Lc__z=0;
ptr __gBB____Rc__contents=0;
ptr __TBB__acquired=0;
ptr command__memory=0;
char __OBB____Ab__first=0;
u64 __gBB____Oc__self__allocated__prev=0;
bool __OBB____Gb____kQ__z=0;
nominal __QBB__allocator____UQ=0;
u64 __TBB____dynamic_entry=0;
ptr __JBB__acquired=0;
u64 __JBB____aQ____VQ=0;
ptr __cBB____wh____m__contents=0;
bool __PBB____Aj____kQ__z=0;
nominal __OBB__allocator____UQ=0;
u64 __cBB__len_x=0;
ptr __OBB____Jb__contents=0;
cstr __cBB____2h____pQ=0;
bool __QBB____2h____oQ__x=0;
ptr __OBB____Gb__mem=0;
nominal name____b=0;
u64 __JBB____dynamic_entry=0;
u64 __TBB__size=0;
u64 __JBB____aQ____WQ=0;
u64 __JBB__size=0;
u64 __QBB____yh=0;
u64 __JBB__allocated=0;
ptr __OBB____Ab__noptr=0;
u64 __OBB____Gb__next_size=0;
ptr __bBB____Rc__contents=0;
ptr __OBB____Ab____m__contents=0;
u64 __TBB____aQ____dynamic_entry=0;
ptr __OBB____Bb____m__contents=0;
u64 __OBB__len_y=0;
char __hBB____2h____hQ=0;
cstr __OBB____Gb____pQ=0;
cstr __OBB____Gb____lQ=0;
u64 __OBB____Gb__self__allocated__prev=0;
cstr __PBB____Aj____lQ=0;
char __OBB____Gb____hQ=0;
bool __OBB____Gb____oQ__x=0;
bool __OBB____Gb____oQ__z=0;
bool __cBB____2h____kQ__z=0;

// IMPLEMENTATION
__IBB____end :
 __JBB____aQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __JBB____aQ__acquired )(( ptr **) __JBB____aQ__acquired )[0]=0; 
 __JBB____aQ____VQ = 0 ;
 __JBB____aQ____WQ = 0 ;
 __JBB____aQ____end :
 __JBB__acquired = __JBB____aQ__acquired ;
 __JBB__size = __JBB____aQ____VQ ;
 __JBB__allocated = __JBB____aQ____WQ ;
 __JBB____dynamic_entry = __JBB____aQ____dynamic_entry ;
 __JBB____end :
 __LBB = " 2>&1" ;
 __MBB = "./smol tests/unit/" ;
 __NBB = ".s --runtime eager" ;
 __OBB____Ab__length = strlen ( __NBB ); __OBB____Ab__contents =( ptr ) __NBB ; __OBB____Ab__first = __NBB [0]; __OBB____Ab__noptr =( ptr ) __OBB____Ab__noptr ; 
 __OBB____Ab____m__contents = __OBB____Ab__contents ;
 __OBB____Ab____m____end :
 __OBB____Ab____end :
 __OBB____Bb__length = strlen ( __LBB ); __OBB____Bb__contents =( ptr ) __LBB ; __OBB____Bb__first = __LBB [0]; __OBB____Bb__noptr =( ptr ) __OBB____Bb__noptr ; 
 __OBB____Bb____m__contents = __OBB____Bb__contents ;
 __OBB____Bb____m____end :
 __OBB____Bb____end :
 __OBB__len_x = __OBB____Ab__length ; __OBB__len_y = __OBB____Bb__length ; __OBB__total_len = __OBB__len_x + __OBB__len_y ; __OBB__first = __OBB____Ab__length ? __OBB____Ab__first : __OBB____Bb__first ; 
 __OBB____Cb = 1 ;
 __OBB____Db__z = __OBB__total_len + __OBB____Cb ; 
 __OBB____Db____end :
 __OBB____Gb____kQ__z =(! __JBB__acquired ); 
 __OBB____Gb____kQ____end :
 if(! __OBB____Gb____kQ__z )goto __OBB____Gb____iQ__fi ;
 __OBB____Gb____lQ = "Did not initialize Dynamic" ;
 goto __OBB____Gb____mQ____pD ;
 __builtin_unreachable();
 __OBB____Gb____mQ____end :
 __OBB____Gb____iQ__if :
 __OBB____Gb____iQ__fi :
 __OBB____Gb__next_size = __JBB__size +1; __OBB____Gb__success = true ; __OBB____Gb__self__allocated__prev = __JBB__allocated ; if ( __OBB____Gb__next_size >= __JBB__allocated ) { __JBB__allocated = __JBB__allocated + __JBB__allocated /2+1; __OBB____Gb__next_acquired =( ptr )((( ptr **) __JBB__acquired )[0]? __runtime_realloc ((( ptr **) __JBB__acquired )[0], __JBB__allocated * sizeof ( ptr ), __OBB____Gb__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __JBB__allocated * sizeof ( ptr ))); if ( __OBB____Gb__success = __OBB____Gb__next_acquired )(( ptr **) __JBB__acquired )[0]=( ptr *) __OBB____Gb__next_acquired ; } if ( __OBB____Gb__success ) { __OBB____Gb__mem =( ptr ) __runtime_alloc ( __OBB____Db__z * sizeof ( __OBB____Gb____hQ )); if ( __OBB____Gb__success = __OBB____Gb__mem ) {(( ptr **) __JBB__acquired )[0][ __JBB__size ]= __OBB____Gb__mem ; __JBB__size = __OBB____Gb__next_size ; } } 
 __OBB____Gb____oQ__x = __OBB____Gb__success ;
 __OBB____Gb____oQ__z =(! __OBB____Gb____oQ__x ); 
 __OBB____Gb____oQ____end :
 if(! __OBB____Gb____oQ__z )goto __OBB____Gb____nQ__fi ;
 __OBB____Gb____pQ = "Failed a Dynamic allocation" ;
 goto __OBB____Gb____qQ____pD ;
 __builtin_unreachable();
 __OBB____Gb____qQ____end :
 __OBB____Gb____nQ__if :
 __OBB____Gb____nQ__fi :
 __OBB____Gb____uQ____end :
 memcpy (( char *) __OBB____Gb__mem ,( char *) __OBB____Ab____m__contents , __OBB__len_x ); memcpy (( char *) __OBB____Gb__mem + __OBB__len_x ,( char *) __OBB____Bb____m__contents , __OBB__len_y );(( char *) __OBB____Gb__mem )[ __OBB__total_len ]=0; 
 __OBB____Jb__contents = __OBB____Gb__mem ;
 __OBB____Jb____end :
 __OBB____end :
 __JBB____UQ = __OBB__allocator____UQ ;
 __JBB__acquired = __JBB__acquired ;
 __JBB__size = __JBB__size ;
 __JBB__allocated = __JBB__allocated ;
 __JBB____dynamic_entry = __JBB____dynamic_entry ;
 __PBB____4i____end :
 __PBB____5i____j____end :
 __PBB____5i____end :
 __PBB__len_x = name__length ; __PBB__len_y = __OBB__total_len ; __PBB__total_len = __PBB__len_x + __PBB__len_y ; __PBB__first = name__length ? name__first : __OBB__first ; 
 __PBB____6i = 1 ;
 __PBB____7i__z = __PBB__total_len + __PBB____6i ; 
 __PBB____7i____end :
 __PBB____Aj____kQ__z =(! __JBB__acquired ); 
 __PBB____Aj____kQ____end :
 if(! __PBB____Aj____kQ__z )goto __PBB____Aj____iQ__fi ;
 __PBB____Aj____lQ = "Did not initialize Dynamic" ;
 goto __PBB____Aj____mQ____pD ;
 __builtin_unreachable();
 __PBB____Aj____mQ____end :
 __PBB____Aj____iQ__if :
 __PBB____Aj____iQ__fi :
 __PBB____Aj__next_size = __JBB__size +1; __PBB____Aj__success = true ; __PBB____Aj__self__allocated__prev = __JBB__allocated ; if ( __PBB____Aj__next_size >= __JBB__allocated ) { __JBB__allocated = __JBB__allocated + __JBB__allocated /2+1; __PBB____Aj__next_acquired =( ptr )((( ptr **) __JBB__acquired )[0]? __runtime_realloc ((( ptr **) __JBB__acquired )[0], __JBB__allocated * sizeof ( ptr ), __PBB____Aj__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __JBB__allocated * sizeof ( ptr ))); if ( __PBB____Aj__success = __PBB____Aj__next_acquired )(( ptr **) __JBB__acquired )[0]=( ptr *) __PBB____Aj__next_acquired ; } if ( __PBB____Aj__success ) { __PBB____Aj__mem =( ptr ) __runtime_alloc ( __PBB____7i__z * sizeof ( __PBB____Aj____hQ )); if ( __PBB____Aj__success = __PBB____Aj__mem ) {(( ptr **) __JBB__acquired )[0][ __JBB__size ]= __PBB____Aj__mem ; __JBB__size = __PBB____Aj__next_size ; } } 
 __PBB____Aj____oQ__x = __PBB____Aj__success ;
 __PBB____Aj____oQ__z =(! __PBB____Aj____oQ__x ); 
 __PBB____Aj____oQ____end :
 if(! __PBB____Aj____oQ__z )goto __PBB____Aj____nQ__fi ;
 __PBB____Aj____pQ = "Failed a Dynamic allocation" ;
 goto __PBB____Aj____qQ____pD ;
 __builtin_unreachable();
 __PBB____Aj____qQ____end :
 __PBB____Aj____nQ__if :
 __PBB____Aj____nQ__fi :
 __PBB____Aj____uQ____end :
 memcpy (( char *) __PBB____Aj__mem ,( char *) name__contents , __PBB__len_x ); memcpy (( char *) __PBB____Aj__mem + __PBB__len_x ,( char *) __OBB____Jb__contents , __PBB__len_y );(( char *) __PBB____Aj__mem )[ __PBB__total_len ]=0; 
 __PBB____Dj__contents = __PBB____Aj__mem ;
 __PBB____Dj____end :
 __PBB____end :
 __JBB____UQ = __PBB__allocator____UQ ;
 __JBB__acquired = __JBB__acquired ;
 __JBB__size = __JBB__size ;
 __JBB__allocated = __JBB__allocated ;
 __JBB____dynamic_entry = __JBB____dynamic_entry ;
 __QBB____wh__length = strlen ( __MBB ); __QBB____wh__contents =( ptr ) __MBB ; __QBB____wh__first = __MBB [0]; __QBB____wh__noptr =( ptr ) __QBB____wh__noptr ; 
 __QBB____wh____m__contents = __QBB____wh__contents ;
 __QBB____wh____m____end :
 __QBB____wh____end :
 __QBB____xh____j____end :
 __QBB____xh____end :
 __QBB__len_x = __QBB____wh__length ; __QBB__len_y = __PBB__total_len ; __QBB__total_len = __QBB__len_x + __QBB__len_y ; __QBB__first = __QBB____wh__length ? __QBB____wh__first : __PBB__first ; 
 __QBB____yh = 1 ;
 __QBB____zh__z = __QBB__total_len + __QBB____yh ; 
 __QBB____zh____end :
 __QBB____2h____kQ__z =(! __JBB__acquired ); 
 __QBB____2h____kQ____end :
 if(! __QBB____2h____kQ__z )goto __QBB____2h____iQ__fi ;
 __QBB____2h____lQ = "Did not initialize Dynamic" ;
 goto __QBB____2h____mQ____pD ;
 __builtin_unreachable();
 __QBB____2h____mQ____end :
 __QBB____2h____iQ__if :
 __QBB____2h____iQ__fi :
 __QBB____2h__next_size = __JBB__size +1; __QBB____2h__success = true ; __QBB____2h__self__allocated__prev = __JBB__allocated ; if ( __QBB____2h__next_size >= __JBB__allocated ) { __JBB__allocated = __JBB__allocated + __JBB__allocated /2+1; __QBB____2h__next_acquired =( ptr )((( ptr **) __JBB__acquired )[0]? __runtime_realloc ((( ptr **) __JBB__acquired )[0], __JBB__allocated * sizeof ( ptr ), __QBB____2h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __JBB__allocated * sizeof ( ptr ))); if ( __QBB____2h__success = __QBB____2h__next_acquired )(( ptr **) __JBB__acquired )[0]=( ptr *) __QBB____2h__next_acquired ; } if ( __QBB____2h__success ) { __QBB____2h__mem =( ptr ) __runtime_alloc ( __QBB____zh__z * sizeof ( __QBB____2h____hQ )); if ( __QBB____2h__success = __QBB____2h__mem ) {(( ptr **) __JBB__acquired )[0][ __JBB__size ]= __QBB____2h__mem ; __JBB__size = __QBB____2h__next_size ; } } 
 __QBB____2h____oQ__x = __QBB____2h__success ;
 __QBB____2h____oQ__z =(! __QBB____2h____oQ__x ); 
 __QBB____2h____oQ____end :
 if(! __QBB____2h____oQ__z )goto __QBB____2h____nQ__fi ;
 __QBB____2h____pQ = "Failed a Dynamic allocation" ;
 goto __QBB____2h____qQ____pD ;
 __builtin_unreachable();
 __QBB____2h____qQ____end :
 __QBB____2h____nQ__if :
 __QBB____2h____nQ__fi :
 __QBB____2h____uQ____end :
 memcpy (( char *) __QBB____2h__mem ,( char *) __QBB____wh____m__contents , __QBB__len_x ); memcpy (( char *) __QBB____2h__mem + __QBB__len_x ,( char *) __PBB____Dj__contents , __QBB__len_y );(( char *) __QBB____2h__mem )[ __QBB__total_len ]=0; 
 __QBB____5h__contents = __QBB____2h__mem ;
 __QBB____5h____end :
 __QBB____end :
 __JBB____UQ = __QBB__allocator____UQ ;
 __JBB__acquired = __JBB__acquired ;
 __JBB__size = __JBB__size ;
 __JBB__allocated = __JBB__allocated ;
 __JBB____dynamic_entry = __JBB____dynamic_entry ;
 __KBB__on :
 __SBB____end :
 __TBB____aQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __TBB____aQ__acquired )(( ptr **) __TBB____aQ__acquired )[0]=0; 
 __TBB____aQ____VQ = 0 ;
 __TBB____aQ____WQ = 0 ;
 __TBB____aQ____end :
 __TBB__acquired = __TBB____aQ__acquired ;
 __TBB__size = __TBB____aQ____VQ ;
 __TBB__allocated = __TBB____aQ____WQ ;
 __TBB____dynamic_entry = __TBB____aQ____dynamic_entry ;
 __TBB____end :
 __WBB____state = (struct run__812__state*)__runtime_calloc(sizeof(struct run__812__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __WBB____state ) ;
 __WBB____state -> command____c = command____c ;
 __WBB____state -> command__contents = __QBB____5h__contents ;
 __WBB____state -> command__length = __QBB__total_len ;
 __WBB____state -> command__first = __QBB__first ;
 __WBB____state -> command__memory = __JBB__acquired ;
 __WBB____task = __smolambda_add_task ( run__812 , __WBB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __WBB____task ) ;
 if( __WBB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __WBB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __smolambda_task_wait ( __WBB____task ) ;
 __WBB__err = __WBB____state -> err ;
 if(! __WBB__err )goto __VBB__fi ;
 __ZBB = "[ \033[31mERROR\033[0m ] " ;
 __aBB = ".s" ;
 __bBB____Ic____end :
 __bBB____Jc__length = strlen ( __aBB ); __bBB____Jc__contents =( ptr ) __aBB ; __bBB____Jc__first = __aBB [0]; __bBB____Jc__noptr =( ptr ) __bBB____Jc__noptr ; 
 __bBB____Jc____m__contents = __bBB____Jc__contents ;
 __bBB____Jc____m____end :
 __bBB____Jc____end :
 __bBB__len_x = name__length ; __bBB__len_y = __bBB____Jc__length ; __bBB__total_len = __bBB__len_x + __bBB__len_y ; __bBB__first = name__length ? name__first : __bBB____Jc__first ; 
 __bBB____Kc = 1 ;
 __bBB____Lc__z = __bBB__total_len + __bBB____Kc ; 
 __bBB____Lc____end :
 __bBB____Oc____kQ__z =(! __TBB__acquired ); 
 __bBB____Oc____kQ____end :
 if(! __bBB____Oc____kQ__z )goto __bBB____Oc____iQ__fi ;
 __bBB____Oc____lQ = "Did not initialize Dynamic" ;
 goto __bBB____Oc____mQ____pD ;
 __builtin_unreachable();
 __bBB____Oc____mQ____end :
 __bBB____Oc____iQ__if :
 __bBB____Oc____iQ__fi :
 __bBB____Oc__next_size = __TBB__size +1; __bBB____Oc__success = true ; __bBB____Oc__self__allocated__prev = __TBB__allocated ; if ( __bBB____Oc__next_size >= __TBB__allocated ) { __TBB__allocated = __TBB__allocated + __TBB__allocated /2+1; __bBB____Oc__next_acquired =( ptr )((( ptr **) __TBB__acquired )[0]? __runtime_realloc ((( ptr **) __TBB__acquired )[0], __TBB__allocated * sizeof ( ptr ), __bBB____Oc__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __TBB__allocated * sizeof ( ptr ))); if ( __bBB____Oc__success = __bBB____Oc__next_acquired )(( ptr **) __TBB__acquired )[0]=( ptr *) __bBB____Oc__next_acquired ; } if ( __bBB____Oc__success ) { __bBB____Oc__mem =( ptr ) __runtime_alloc ( __bBB____Lc__z * sizeof ( __bBB____Oc____hQ )); if ( __bBB____Oc__success = __bBB____Oc__mem ) {(( ptr **) __TBB__acquired )[0][ __TBB__size ]= __bBB____Oc__mem ; __TBB__size = __bBB____Oc__next_size ; } } 
 __bBB____Oc____oQ__x = __bBB____Oc__success ;
 __bBB____Oc____oQ__z =(! __bBB____Oc____oQ__x ); 
 __bBB____Oc____oQ____end :
 if(! __bBB____Oc____oQ__z )goto __bBB____Oc____nQ__fi ;
 __bBB____Oc____pQ = "Failed a Dynamic allocation" ;
 goto __bBB____Oc____qQ____pD ;
 __builtin_unreachable();
 __bBB____Oc____qQ____end :
 __bBB____Oc____nQ__if :
 __bBB____Oc____nQ__fi :
 __bBB____Oc____uQ____end :
 memcpy (( char *) __bBB____Oc__mem ,( char *) name__contents , __bBB__len_x ); memcpy (( char *) __bBB____Oc__mem + __bBB__len_x ,( char *) __bBB____Jc____m__contents , __bBB__len_y );(( char *) __bBB____Oc__mem )[ __bBB__total_len ]=0; 
 __bBB____Rc__contents = __bBB____Oc__mem ;
 __bBB____Rc____end :
 __bBB____end :
 __TBB____UQ = __bBB__allocator____UQ ;
 __TBB__acquired = __TBB__acquired ;
 __TBB__size = __TBB__size ;
 __TBB__allocated = __TBB__allocated ;
 __TBB____dynamic_entry = __TBB____dynamic_entry ;
 __cBB____wh__length = strlen ( __ZBB ); __cBB____wh__contents =( ptr ) __ZBB ; __cBB____wh__first = __ZBB [0]; __cBB____wh__noptr =( ptr ) __cBB____wh__noptr ; 
 __cBB____wh____m__contents = __cBB____wh__contents ;
 __cBB____wh____m____end :
 __cBB____wh____end :
 __cBB____xh____j____end :
 __cBB____xh____end :
 __cBB__len_x = __cBB____wh__length ; __cBB__len_y = __bBB__total_len ; __cBB__total_len = __cBB__len_x + __cBB__len_y ; __cBB__first = __cBB____wh__length ? __cBB____wh__first : __bBB__first ; 
 __cBB____yh = 1 ;
 __cBB____zh__z = __cBB__total_len + __cBB____yh ; 
 __cBB____zh____end :
 __cBB____2h____kQ__z =(! __TBB__acquired ); 
 __cBB____2h____kQ____end :
 if(! __cBB____2h____kQ__z )goto __cBB____2h____iQ__fi ;
 __cBB____2h____lQ = "Did not initialize Dynamic" ;
 goto __cBB____2h____mQ____pD ;
 __builtin_unreachable();
 __cBB____2h____mQ____end :
 __cBB____2h____iQ__if :
 __cBB____2h____iQ__fi :
 __cBB____2h__next_size = __TBB__size +1; __cBB____2h__success = true ; __cBB____2h__self__allocated__prev = __TBB__allocated ; if ( __cBB____2h__next_size >= __TBB__allocated ) { __TBB__allocated = __TBB__allocated + __TBB__allocated /2+1; __cBB____2h__next_acquired =( ptr )((( ptr **) __TBB__acquired )[0]? __runtime_realloc ((( ptr **) __TBB__acquired )[0], __TBB__allocated * sizeof ( ptr ), __cBB____2h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __TBB__allocated * sizeof ( ptr ))); if ( __cBB____2h__success = __cBB____2h__next_acquired )(( ptr **) __TBB__acquired )[0]=( ptr *) __cBB____2h__next_acquired ; } if ( __cBB____2h__success ) { __cBB____2h__mem =( ptr ) __runtime_alloc ( __cBB____zh__z * sizeof ( __cBB____2h____hQ )); if ( __cBB____2h__success = __cBB____2h__mem ) {(( ptr **) __TBB__acquired )[0][ __TBB__size ]= __cBB____2h__mem ; __TBB__size = __cBB____2h__next_size ; } } 
 __cBB____2h____oQ__x = __cBB____2h__success ;
 __cBB____2h____oQ__z =(! __cBB____2h____oQ__x ); 
 __cBB____2h____oQ____end :
 if(! __cBB____2h____oQ__z )goto __cBB____2h____nQ__fi ;
 __cBB____2h____pQ = "Failed a Dynamic allocation" ;
 goto __cBB____2h____qQ____pD ;
 __builtin_unreachable();
 __cBB____2h____qQ____end :
 __cBB____2h____nQ__if :
 __cBB____2h____nQ__fi :
 __cBB____2h____uQ____end :
 memcpy (( char *) __cBB____2h__mem ,( char *) __cBB____wh____m__contents , __cBB__len_x ); memcpy (( char *) __cBB____2h__mem + __cBB__len_x ,( char *) __bBB____Rc__contents , __cBB__len_y );(( char *) __cBB____2h__mem )[ __cBB__total_len ]=0; 
 __cBB____5h__contents = __cBB____2h__mem ;
 __cBB____5h____end :
 __cBB____end :
 __TBB____UQ = __cBB__allocator____UQ ;
 __TBB__acquired = __TBB__acquired ;
 __TBB__size = __TBB__size ;
 __TBB__allocated = __TBB__allocated ;
 __TBB____dynamic_entry = __TBB____dynamic_entry ;
 printf ( "%s\n" ,( char *) __cBB____5h__contents ); 
 __dBB____end :
 __VBB__if :
 goto __VBB__el ;
 __VBB__fi :
 __eBB = "[ \033[32mOK\033[0m ] " ;
 __fBB = ".s" ;
 __gBB____Ic____end :
 __gBB____Jc__length = strlen ( __fBB ); __gBB____Jc__contents =( ptr ) __fBB ; __gBB____Jc__first = __fBB [0]; __gBB____Jc__noptr =( ptr ) __gBB____Jc__noptr ; 
 __gBB____Jc____m__contents = __gBB____Jc__contents ;
 __gBB____Jc____m____end :
 __gBB____Jc____end :
 __gBB__len_x = name__length ; __gBB__len_y = __gBB____Jc__length ; __gBB__total_len = __gBB__len_x + __gBB__len_y ; __gBB__first = name__length ? name__first : __gBB____Jc__first ; 
 __gBB____Kc = 1 ;
 __gBB____Lc__z = __gBB__total_len + __gBB____Kc ; 
 __gBB____Lc____end :
 __gBB____Oc____kQ__z =(! __TBB__acquired ); 
 __gBB____Oc____kQ____end :
 if(! __gBB____Oc____kQ__z )goto __gBB____Oc____iQ__fi ;
 __gBB____Oc____lQ = "Did not initialize Dynamic" ;
 goto __gBB____Oc____mQ____pD ;
 __builtin_unreachable();
 __gBB____Oc____mQ____end :
 __gBB____Oc____iQ__if :
 __gBB____Oc____iQ__fi :
 __gBB____Oc__next_size = __TBB__size +1; __gBB____Oc__success = true ; __gBB____Oc__self__allocated__prev = __TBB__allocated ; if ( __gBB____Oc__next_size >= __TBB__allocated ) { __TBB__allocated = __TBB__allocated + __TBB__allocated /2+1; __gBB____Oc__next_acquired =( ptr )((( ptr **) __TBB__acquired )[0]? __runtime_realloc ((( ptr **) __TBB__acquired )[0], __TBB__allocated * sizeof ( ptr ), __gBB____Oc__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __TBB__allocated * sizeof ( ptr ))); if ( __gBB____Oc__success = __gBB____Oc__next_acquired )(( ptr **) __TBB__acquired )[0]=( ptr *) __gBB____Oc__next_acquired ; } if ( __gBB____Oc__success ) { __gBB____Oc__mem =( ptr ) __runtime_alloc ( __gBB____Lc__z * sizeof ( __gBB____Oc____hQ )); if ( __gBB____Oc__success = __gBB____Oc__mem ) {(( ptr **) __TBB__acquired )[0][ __TBB__size ]= __gBB____Oc__mem ; __TBB__size = __gBB____Oc__next_size ; } } 
 __gBB____Oc____oQ__x = __gBB____Oc__success ;
 __gBB____Oc____oQ__z =(! __gBB____Oc____oQ__x ); 
 __gBB____Oc____oQ____end :
 if(! __gBB____Oc____oQ__z )goto __gBB____Oc____nQ__fi ;
 __gBB____Oc____pQ = "Failed a Dynamic allocation" ;
 goto __gBB____Oc____qQ____pD ;
 __builtin_unreachable();
 __gBB____Oc____qQ____end :
 __gBB____Oc____nQ__if :
 __gBB____Oc____nQ__fi :
 __gBB____Oc____uQ____end :
 memcpy (( char *) __gBB____Oc__mem ,( char *) name__contents , __gBB__len_x ); memcpy (( char *) __gBB____Oc__mem + __gBB__len_x ,( char *) __gBB____Jc____m__contents , __gBB__len_y );(( char *) __gBB____Oc__mem )[ __gBB__total_len ]=0; 
 __gBB____Rc__contents = __gBB____Oc__mem ;
 __gBB____Rc____end :
 __gBB____end :
 __TBB____UQ = __gBB__allocator____UQ ;
 __TBB__acquired = __TBB__acquired ;
 __TBB__size = __TBB__size ;
 __TBB__allocated = __TBB__allocated ;
 __TBB____dynamic_entry = __TBB____dynamic_entry ;
 __hBB____wh__length = strlen ( __eBB ); __hBB____wh__contents =( ptr ) __eBB ; __hBB____wh__first = __eBB [0]; __hBB____wh__noptr =( ptr ) __hBB____wh__noptr ; 
 __hBB____wh____m__contents = __hBB____wh__contents ;
 __hBB____wh____m____end :
 __hBB____wh____end :
 __hBB____xh____j____end :
 __hBB____xh____end :
 __hBB__len_x = __hBB____wh__length ; __hBB__len_y = __gBB__total_len ; __hBB__total_len = __hBB__len_x + __hBB__len_y ; __hBB__first = __hBB____wh__length ? __hBB____wh__first : __gBB__first ; 
 __hBB____yh = 1 ;
 __hBB____zh__z = __hBB__total_len + __hBB____yh ; 
 __hBB____zh____end :
 __hBB____2h____kQ__z =(! __TBB__acquired ); 
 __hBB____2h____kQ____end :
 if(! __hBB____2h____kQ__z )goto __hBB____2h____iQ__fi ;
 __hBB____2h____lQ = "Did not initialize Dynamic" ;
 goto __hBB____2h____mQ____pD ;
 __builtin_unreachable();
 __hBB____2h____mQ____end :
 __hBB____2h____iQ__if :
 __hBB____2h____iQ__fi :
 __hBB____2h__next_size = __TBB__size +1; __hBB____2h__success = true ; __hBB____2h__self__allocated__prev = __TBB__allocated ; if ( __hBB____2h__next_size >= __TBB__allocated ) { __TBB__allocated = __TBB__allocated + __TBB__allocated /2+1; __hBB____2h__next_acquired =( ptr )((( ptr **) __TBB__acquired )[0]? __runtime_realloc ((( ptr **) __TBB__acquired )[0], __TBB__allocated * sizeof ( ptr ), __hBB____2h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __TBB__allocated * sizeof ( ptr ))); if ( __hBB____2h__success = __hBB____2h__next_acquired )(( ptr **) __TBB__acquired )[0]=( ptr *) __hBB____2h__next_acquired ; } if ( __hBB____2h__success ) { __hBB____2h__mem =( ptr ) __runtime_alloc ( __hBB____zh__z * sizeof ( __hBB____2h____hQ )); if ( __hBB____2h__success = __hBB____2h__mem ) {(( ptr **) __TBB__acquired )[0][ __TBB__size ]= __hBB____2h__mem ; __TBB__size = __hBB____2h__next_size ; } } 
 __hBB____2h____oQ__x = __hBB____2h__success ;
 __hBB____2h____oQ__z =(! __hBB____2h____oQ__x ); 
 __hBB____2h____oQ____end :
 if(! __hBB____2h____oQ__z )goto __hBB____2h____nQ__fi ;
 __hBB____2h____pQ = "Failed a Dynamic allocation" ;
 goto __hBB____2h____qQ____pD ;
 __builtin_unreachable();
 __hBB____2h____qQ____end :
 __hBB____2h____nQ__if :
 __hBB____2h____nQ__fi :
 __hBB____2h____uQ____end :
 memcpy (( char *) __hBB____2h__mem ,( char *) __hBB____wh____m__contents , __hBB__len_x ); memcpy (( char *) __hBB____2h__mem + __hBB__len_x ,( char *) __gBB____Rc__contents , __hBB__len_y );(( char *) __hBB____2h__mem )[ __hBB__total_len ]=0; 
 __hBB____5h__contents = __hBB____2h__mem ;
 __hBB____5h____end :
 __hBB____end :
 __TBB____UQ = __hBB__allocator____UQ ;
 __TBB__acquired = __TBB__acquired ;
 __TBB__size = __TBB__size ;
 __TBB__allocated = __TBB__allocated ;
 __TBB____dynamic_entry = __TBB____dynamic_entry ;
 printf ( "%s\n" ,( char *) __hBB____5h__contents ); 
 __iBB____end :
 __VBB__le :
 __VBB__el :
 __UBB__on :
 __end :
goto __return;

// ERROR HANDLING
__OBB____Gb____mQ____pD :
 printf ( "%s\n" , __OBB____Gb____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __OBB____Gb____qQ____pD :
 printf ( "%s\n" , __OBB____Gb____pQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __PBB____Aj____mQ____pD :
 printf ( "%s\n" , __PBB____Aj____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __PBB____Aj____qQ____pD :
 printf ( "%s\n" , __PBB____Aj____pQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __QBB____2h____mQ____pD :
 printf ( "%s\n" , __QBB____2h____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __QBB____2h____qQ____pD :
 printf ( "%s\n" , __QBB____2h____pQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __XBB :
printf("Runtime error from run __WBB \n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
 __bBB____Oc____mQ____pD :
 printf ( "%s\n" , __bBB____Oc____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __bBB____Oc____qQ____pD :
 printf ( "%s\n" , __bBB____Oc____pQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __cBB____2h____mQ____pD :
 printf ( "%s\n" , __cBB____2h____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __cBB____2h____qQ____pD :
 printf ( "%s\n" , __cBB____2h____pQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __gBB____Oc____mQ____pD :
 printf ( "%s\n" , __gBB____Oc____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __gBB____Oc____qQ____pD :
 printf ( "%s\n" , __gBB____Oc____pQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __hBB____2h____mQ____pD :
 printf ( "%s\n" , __hBB____2h____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __hBB____2h____qQ____pD :
 printf ( "%s\n" , __hBB____2h____pQ ); 
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
if ( __TBB__acquired ) { for ( __TBB____dynamic_entry =0; __TBB____dynamic_entry < __TBB__size ;++ __TBB____dynamic_entry ) { __runtime_free ((( ptr **) __TBB__acquired )[0][ __TBB____dynamic_entry ]); } __runtime_free ( __TBB__acquired ); __TBB__acquired =0; __TBB__size =0; __TBB__allocated =0; } 
 if ( __TBB__acquired ) { for ( __TBB____aQ____dynamic_entry =0; __TBB____aQ____dynamic_entry < __TBB____aQ____VQ ;++ __TBB____aQ____dynamic_entry ) { __runtime_free ((( ptr **) __TBB__acquired )[0][ __TBB____aQ____dynamic_entry ]); } __runtime_free ( __TBB__acquired ); __TBB__acquired =0; __TBB____aQ____VQ =0; __TBB____aQ____WQ =0; } 
if ( __JBB__acquired ) { for ( __JBB____dynamic_entry =0; __JBB____dynamic_entry < __JBB__size ;++ __JBB____dynamic_entry ) { __runtime_free ((( ptr **) __JBB__acquired )[0][ __JBB____dynamic_entry ]); } __runtime_free ( __JBB__acquired ); __JBB__acquired =0; __JBB__size =0; __JBB__allocated =0; } 
 if ( __JBB__acquired ) { for ( __JBB____aQ____dynamic_entry =0; __JBB____aQ____dynamic_entry < __JBB____aQ____VQ ;++ __JBB____aQ____dynamic_entry ) { __runtime_free ((( ptr **) __JBB__acquired )[0][ __JBB____aQ____dynamic_entry ]); } __runtime_free ( __JBB__acquired ); __JBB__acquired =0; __JBB____aQ____VQ =0; __JBB____aQ____WQ =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}


void run__812(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__812__state *__state=(struct run__812__state*)__void__state;
ptr command__contents= __state->command__contents;
u64 command__length= __state->command__length;
char command__first= __state->command__first;
ptr command__memory= __state->command__memory;
nominal __oAB__p____88=0;
nominal process____88=0;
i64 __nAB__status=0;
bool __nAB____N9__z=0;
ptr process__contents=0;
ptr __nAB__contents=0;
ptr __lAB__contents=0;
nominal command____c=0;
ptr __mAB__contents=0;
ptr __nAB____M9__x=0;
bool __nAB____M9__z=0;

// IMPLEMENTATION
__lAB__contents = 0 ;
 __mAB__contents = __lAB__contents ;
 __mAB____end :
 __nAB____K9____end :
 __nAB__contents =( ptr ) popen (( cstr ) command__contents , "r" ); 
 __nAB____M9__x = __nAB__contents ;
 __nAB____M9__z =( __nAB____M9__x ); 
 __nAB____M9____end :
 __nAB____N9__z =(! __nAB____M9__z ); 
 __nAB____N9____end :
 if(! __nAB____N9__z )goto __nAB____L9__fi ;
 goto __nAB____O9 ;
 __builtin_unreachable();
 __nAB____L9__if :
 __nAB____L9__fi :
 __nAB____R9____end :
 __nAB____end :
 process__contents = __nAB__contents ;
 if ( process__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process__contents )) { } } 
 __oAB____end :
 process____88 = __oAB__p____88 ;
 __nAB__status =0; if ( process__contents ) __nAB__status = pclose (( FILE *) process__contents ); process__contents =0; if ( __nAB__status ) { if ( __nAB__status !=-1&& WIFEXITED ( __nAB__status )) __nAB__status = WEXITSTATUS ( __nAB__status ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __nAB__status ); __result__errocode = __USER__ERROR ; goto __failsafe ; } 
 __end :
goto __return;

// ERROR HANDLING
__nAB____O9 :
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


void std_test__814(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__814__state *__state=(struct std_test__814__state*)__void__state;
struct run__812__state* __4AB____state = 0 ;
cstr name= __state->name;
cstr __FBB____2h____pQ=0;
bool __FBB____2h____oQ__z=0;
cstr __FBB____2h____lQ=0;
char __FBB____2h____hQ=0;
char __FBB__first=0;
u64 __FBB__len_y=0;
u64 __FBB____wh__length=0;
ptr __EBB____Jb__contents=0;
u64 __FBB____2h__next_size=0;
bool __EBB____Gb____oQ__z=0;
u64 __EBB____Gb__self__allocated__prev=0;
bool __EBB____Gb__success=0;
u64 __EBB____Gb__next_size=0;
cstr __EBB____Gb____lQ=0;
bool __EBB____Gb____kQ__z=0;
u64 __EBB____Cb=0;
u64 __EBB__len_y=0;
ptr __EBB____Bb__noptr=0;
ptr __EBB____Ab____m__contents=0;
u64 __EBB____Ab__length=0;
cstr __DBB=0;
u64 __FBB____2h__self__allocated__prev=0;
ptr __ABB____5h__contents=0;
bool __ABB____2h____oQ__z=0;
bool __ABB____2h__success=0;
char __EBB____Bb__first=0;
cstr __ABB____2h____lQ=0;
u64 __ABB____zh__z=0;
bool __ABB____2h____oQ__x=0;
u64 __ABB____yh=0;
char __ABB__first=0;
u64 __ABB__len_x=0;
ptr __ABB____wh____m__contents=0;
char __ABB____wh__first=0;
ptr __ABB____wh__contents=0;
nominal __9AB__allocator____UQ=0;
nominal __1AB____UQ=0;
bool __EBB____Gb____oQ__x=0;
u64 __FBB__len_x=0;
ptr __9AB____Gb__mem=0;
ptr __FBB____2h__mem=0;
cstr __9AB____Gb____lQ=0;
bool __9AB____Gb____kQ__z=0;
u64 __9AB____Cb=0;
u64 __ABB____wh__length=0;
u64 __9AB__total_len=0;
bool __FBB____2h____oQ__x=0;
u64 __9AB__len_y=0;
u64 __9AB__len_x=0;
ptr __9AB____Bb____m__contents=0;
cstr __CBB=0;
ptr __9AB____Bb__noptr=0;
char __9AB____Bb__first=0;
ptr __9AB____Bb__contents=0;
u64 __9AB____Bb__length=0;
ptr __9AB____Ab____m__contents=0;
u64 __FBB____zh__z=0;
u64 __9AB____Ab__length=0;
cstr __8AB=0;
u64 __EBB____Db__z=0;
cstr __7AB=0;
bool __9AB____Gb____oQ__x=0;
ptr command__memory=0;
char command__first=0;
nominal command____c=0;
u64 __1AB__allocated=0;
u64 __1AB____aQ____WQ=0;
u64 __1AB____aQ____VQ=0;
cstr __EBB____Gb____pQ=0;
ptr __FBB____wh__contents=0;
char __EBB____Ab__first=0;
nominal __yAB__allocator____UQ=0;
ptr __yAB____5h__contents=0;
ptr __EBB____Gb__next_acquired=0;
u64 __9AB____Gb__self__allocated__prev=0;
char __EBB____Gb____hQ=0;
bool __yAB____2h____oQ__z=0;
bool __yAB____2h____oQ__x=0;
char __yAB____2h____hQ=0;
ptr __yAB____2h__next_acquired=0;
u64 __yAB____2h__next_size=0;
ptr __FBB____wh____m__contents=0;
cstr __yAB____2h____lQ=0;
bool __yAB____2h____kQ__z=0;
u64 __yAB__total_len=0;
u64 __yAB__len_y=0;
char __FBB____wh__first=0;
ptr command__contents=0;
ptr __yAB____wh____m__contents=0;
ptr __yAB____wh__noptr=0;
u64 __yAB____zh__z=0;
ptr __yAB____wh__contents=0;
cstr __xAB____2h____pQ=0;
char __xAB____2h____hQ=0;
bool __xAB____2h____oQ__x=0;
ptr __xAB____2h__mem=0;
ptr __xAB____2h__next_acquired=0;
u64 __xAB____2h__self__allocated__prev=0;
cstr __xAB____2h____lQ=0;
ptr __9AB____Ab__contents=0;
char __9AB____Gb____hQ=0;
u64 __1AB____aQ____dynamic_entry=0;
ptr __FBB____2h__next_acquired=0;
u64 __EBB__len_x=0;
ptr __ABB____wh__noptr=0;
u64 __9AB____Db__z=0;
bool __9AB____Gb__success=0;
ptr __9AB____Ab__noptr=0;
ptr __EBB____Bb____m__contents=0;
u64 __yAB____yh=0;
u64 __ABB__total_len=0;
u64 __9AB____Gb__next_size=0;
u64 __EBB____Bb__length=0;
u64 __FBB__total_len=0;
ptr __9AB____Jb__contents=0;
char __9AB__first=0;
ptr __FBB____5h__contents=0;
u64 __1AB____dynamic_entry=0;
char __EBB__first=0;
ptr __FBB____wh__noptr=0;
ptr __ABB____2h__mem=0;
cstr __uAB=0;
ptr __EBB____Bb__contents=0;
ptr __EBB____Gb__mem=0;
errcode __4AB__err=0;
u64 __1AB__size=0;
char __yAB__first=0;
ptr __4AB____task=0;
bool __FBB____2h__success=0;
bool __yAB____2h__success=0;
u64 __yAB____wh__length=0;
bool __xAB____2h__success=0;
ptr __wAB____Ab__noptr=0;
char __9AB____Ab__first=0;
u64 __yAB____2h__self__allocated__prev=0;
char __wAB__first=0;
u64 __wAB__total_len=0;
u64 __wAB____Db__z=0;
u64 __ABB__len_y=0;
nominal __EBB__allocator____UQ=0;
ptr __wAB____Bb__contents=0;
ptr __xAB____wh____m__contents=0;
bool __FBB____2h____kQ__z=0;
u64 __xAB____2h__next_size=0;
ptr __9AB____Gb__next_acquired=0;
u64 __xAB____yh=0;
ptr __EBB____Ab__noptr=0;
bool __ABB____2h____kQ__z=0;
cstr __wAB____Gb____pQ=0;
u64 __rAB____aQ____dynamic_entry=0;
cstr __ABB____2h____pQ=0;
ptr __wAB____Ab__contents=0;
bool __xAB____2h____oQ__z=0;
nominal __wAB__allocator____UQ=0;
char __wAB____Ab__first=0;
u64 __rAB__size=0;
bool __xAB____2h____kQ__z=0;
u64 __xAB__len_y=0;
u64 __EBB__total_len=0;
u64 __wAB____Gb__self__allocated__prev=0;
char __yAB____wh__first=0;
nominal __xAB__allocator____UQ=0;
u64 __wAB____Gb__next_size=0;
ptr __1AB____aQ__acquired=0;
u64 __ABB____2h__next_size=0;
ptr __ABB____2h__next_acquired=0;
nominal __ABB__allocator____UQ=0;
ptr __wAB____Gb__mem=0;
nominal __FBB__allocator____UQ=0;
ptr __wAB____Bb____m__contents=0;
u64 __wAB____Ab__length=0;
u64 __wAB__len_x=0;
ptr __1AB__acquired=0;
ptr __rAB__acquired=0;
u64 __xAB__len_x=0;
ptr __yAB____2h__mem=0;
u64 __rAB____aQ____VQ=0;
cstr __wAB____Gb____lQ=0;
u64 __rAB__allocated=0;
u64 __rAB____aQ____WQ=0;
u64 __rAB____dynamic_entry=0;
bool __wAB____Gb____oQ__z=0;
cstr __tAB=0;
ptr __wAB____Ab____m__contents=0;
char __ABB____2h____hQ=0;
u64 __wAB____Bb__length=0;
char __wAB____Bb__first=0;
ptr __wAB____Bb__noptr=0;
bool __9AB____Gb____oQ__z=0;
u64 command__length=0;
cstr __yAB____2h____pQ=0;
u64 __FBB____yh=0;
u64 __wAB__len_y=0;
cstr __9AB____Gb____pQ=0;
ptr __xAB____5h__contents=0;
u64 __wAB____Cb=0;
bool __wAB____Gb____kQ__z=0;
bool __wAB____Gb__success=0;
ptr __wAB____Gb__next_acquired=0;
char __wAB____Gb____hQ=0;
bool __wAB____Gb____oQ__x=0;
u64 __yAB__len_x=0;
cstr __vAB=0;
ptr __rAB____aQ__acquired=0;
u64 __xAB____wh__length=0;
ptr __wAB____Jb__contents=0;
nominal __rAB____UQ=0;
ptr __EBB____Ab__contents=0;
ptr __xAB____wh__contents=0;
u64 __xAB____zh__z=0;
char __xAB____wh__first=0;
ptr __xAB____wh__noptr=0;
u64 __xAB__total_len=0;
char __xAB__first=0;
u64 __ABB____2h__self__allocated__prev=0;

// IMPLEMENTATION
__qAB____end :
 __rAB____aQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __rAB____aQ__acquired )(( ptr **) __rAB____aQ__acquired )[0]=0; 
 __rAB____aQ____VQ = 0 ;
 __rAB____aQ____WQ = 0 ;
 __rAB____aQ____end :
 __rAB__acquired = __rAB____aQ__acquired ;
 __rAB__size = __rAB____aQ____VQ ;
 __rAB__allocated = __rAB____aQ____WQ ;
 __rAB____dynamic_entry = __rAB____aQ____dynamic_entry ;
 __rAB____end :
 __tAB = " 2>&1" ;
 __uAB = "./smol tests/unit/" ;
 __vAB = ".s --runtime eager" ;
 __wAB____Ab__length = strlen ( __vAB ); __wAB____Ab__contents =( ptr ) __vAB ; __wAB____Ab__first = __vAB [0]; __wAB____Ab__noptr =( ptr ) __wAB____Ab__noptr ; 
 __wAB____Ab____m__contents = __wAB____Ab__contents ;
 __wAB____Ab____m____end :
 __wAB____Ab____end :
 __wAB____Bb__length = strlen ( __tAB ); __wAB____Bb__contents =( ptr ) __tAB ; __wAB____Bb__first = __tAB [0]; __wAB____Bb__noptr =( ptr ) __wAB____Bb__noptr ; 
 __wAB____Bb____m__contents = __wAB____Bb__contents ;
 __wAB____Bb____m____end :
 __wAB____Bb____end :
 __wAB__len_x = __wAB____Ab__length ; __wAB__len_y = __wAB____Bb__length ; __wAB__total_len = __wAB__len_x + __wAB__len_y ; __wAB__first = __wAB____Ab__length ? __wAB____Ab__first : __wAB____Bb__first ; 
 __wAB____Cb = 1 ;
 __wAB____Db__z = __wAB__total_len + __wAB____Cb ; 
 __wAB____Db____end :
 __wAB____Gb____kQ__z =(! __rAB__acquired ); 
 __wAB____Gb____kQ____end :
 if(! __wAB____Gb____kQ__z )goto __wAB____Gb____iQ__fi ;
 __wAB____Gb____lQ = "Did not initialize Dynamic" ;
 goto __wAB____Gb____mQ____pD ;
 __builtin_unreachable();
 __wAB____Gb____mQ____end :
 __wAB____Gb____iQ__if :
 __wAB____Gb____iQ__fi :
 __wAB____Gb__next_size = __rAB__size +1; __wAB____Gb__success = true ; __wAB____Gb__self__allocated__prev = __rAB__allocated ; if ( __wAB____Gb__next_size >= __rAB__allocated ) { __rAB__allocated = __rAB__allocated + __rAB__allocated /2+1; __wAB____Gb__next_acquired =( ptr )((( ptr **) __rAB__acquired )[0]? __runtime_realloc ((( ptr **) __rAB__acquired )[0], __rAB__allocated * sizeof ( ptr ), __wAB____Gb__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __rAB__allocated * sizeof ( ptr ))); if ( __wAB____Gb__success = __wAB____Gb__next_acquired )(( ptr **) __rAB__acquired )[0]=( ptr *) __wAB____Gb__next_acquired ; } if ( __wAB____Gb__success ) { __wAB____Gb__mem =( ptr ) __runtime_alloc ( __wAB____Db__z * sizeof ( __wAB____Gb____hQ )); if ( __wAB____Gb__success = __wAB____Gb__mem ) {(( ptr **) __rAB__acquired )[0][ __rAB__size ]= __wAB____Gb__mem ; __rAB__size = __wAB____Gb__next_size ; } } 
 __wAB____Gb____oQ__x = __wAB____Gb__success ;
 __wAB____Gb____oQ__z =(! __wAB____Gb____oQ__x ); 
 __wAB____Gb____oQ____end :
 if(! __wAB____Gb____oQ__z )goto __wAB____Gb____nQ__fi ;
 __wAB____Gb____pQ = "Failed a Dynamic allocation" ;
 goto __wAB____Gb____qQ____pD ;
 __builtin_unreachable();
 __wAB____Gb____qQ____end :
 __wAB____Gb____nQ__if :
 __wAB____Gb____nQ__fi :
 __wAB____Gb____uQ____end :
 memcpy (( char *) __wAB____Gb__mem ,( char *) __wAB____Ab____m__contents , __wAB__len_x ); memcpy (( char *) __wAB____Gb__mem + __wAB__len_x ,( char *) __wAB____Bb____m__contents , __wAB__len_y );(( char *) __wAB____Gb__mem )[ __wAB__total_len ]=0; 
 __wAB____Jb__contents = __wAB____Gb__mem ;
 __wAB____Jb____end :
 __wAB____end :
 __rAB____UQ = __wAB__allocator____UQ ;
 __rAB__acquired = __rAB__acquired ;
 __rAB__size = __rAB__size ;
 __rAB__allocated = __rAB__allocated ;
 __rAB____dynamic_entry = __rAB____dynamic_entry ;
 __xAB____wh__length = strlen ( name ); __xAB____wh__contents =( ptr ) name ; __xAB____wh__first = name [0]; __xAB____wh__noptr =( ptr ) __xAB____wh__noptr ; 
 __xAB____wh____m__contents = __xAB____wh__contents ;
 __xAB____wh____m____end :
 __xAB____wh____end :
 __xAB____xh____j____end :
 __xAB____xh____end :
 __xAB__len_x = __xAB____wh__length ; __xAB__len_y = __wAB__total_len ; __xAB__total_len = __xAB__len_x + __xAB__len_y ; __xAB__first = __xAB____wh__length ? __xAB____wh__first : __wAB__first ; 
 __xAB____yh = 1 ;
 __xAB____zh__z = __xAB__total_len + __xAB____yh ; 
 __xAB____zh____end :
 __xAB____2h____kQ__z =(! __rAB__acquired ); 
 __xAB____2h____kQ____end :
 if(! __xAB____2h____kQ__z )goto __xAB____2h____iQ__fi ;
 __xAB____2h____lQ = "Did not initialize Dynamic" ;
 goto __xAB____2h____mQ____pD ;
 __builtin_unreachable();
 __xAB____2h____mQ____end :
 __xAB____2h____iQ__if :
 __xAB____2h____iQ__fi :
 __xAB____2h__next_size = __rAB__size +1; __xAB____2h__success = true ; __xAB____2h__self__allocated__prev = __rAB__allocated ; if ( __xAB____2h__next_size >= __rAB__allocated ) { __rAB__allocated = __rAB__allocated + __rAB__allocated /2+1; __xAB____2h__next_acquired =( ptr )((( ptr **) __rAB__acquired )[0]? __runtime_realloc ((( ptr **) __rAB__acquired )[0], __rAB__allocated * sizeof ( ptr ), __xAB____2h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __rAB__allocated * sizeof ( ptr ))); if ( __xAB____2h__success = __xAB____2h__next_acquired )(( ptr **) __rAB__acquired )[0]=( ptr *) __xAB____2h__next_acquired ; } if ( __xAB____2h__success ) { __xAB____2h__mem =( ptr ) __runtime_alloc ( __xAB____zh__z * sizeof ( __xAB____2h____hQ )); if ( __xAB____2h__success = __xAB____2h__mem ) {(( ptr **) __rAB__acquired )[0][ __rAB__size ]= __xAB____2h__mem ; __rAB__size = __xAB____2h__next_size ; } } 
 __xAB____2h____oQ__x = __xAB____2h__success ;
 __xAB____2h____oQ__z =(! __xAB____2h____oQ__x ); 
 __xAB____2h____oQ____end :
 if(! __xAB____2h____oQ__z )goto __xAB____2h____nQ__fi ;
 __xAB____2h____pQ = "Failed a Dynamic allocation" ;
 goto __xAB____2h____qQ____pD ;
 __builtin_unreachable();
 __xAB____2h____qQ____end :
 __xAB____2h____nQ__if :
 __xAB____2h____nQ__fi :
 __xAB____2h____uQ____end :
 memcpy (( char *) __xAB____2h__mem ,( char *) __xAB____wh____m__contents , __xAB__len_x ); memcpy (( char *) __xAB____2h__mem + __xAB__len_x ,( char *) __wAB____Jb__contents , __xAB__len_y );(( char *) __xAB____2h__mem )[ __xAB__total_len ]=0; 
 __xAB____5h__contents = __xAB____2h__mem ;
 __xAB____5h____end :
 __xAB____end :
 __rAB____UQ = __xAB__allocator____UQ ;
 __rAB__acquired = __rAB__acquired ;
 __rAB__size = __rAB__size ;
 __rAB__allocated = __rAB__allocated ;
 __rAB____dynamic_entry = __rAB____dynamic_entry ;
 __yAB____wh__length = strlen ( __uAB ); __yAB____wh__contents =( ptr ) __uAB ; __yAB____wh__first = __uAB [0]; __yAB____wh__noptr =( ptr ) __yAB____wh__noptr ; 
 __yAB____wh____m__contents = __yAB____wh__contents ;
 __yAB____wh____m____end :
 __yAB____wh____end :
 __yAB____xh____j____end :
 __yAB____xh____end :
 __yAB__len_x = __yAB____wh__length ; __yAB__len_y = __xAB__total_len ; __yAB__total_len = __yAB__len_x + __yAB__len_y ; __yAB__first = __yAB____wh__length ? __yAB____wh__first : __xAB__first ; 
 __yAB____yh = 1 ;
 __yAB____zh__z = __yAB__total_len + __yAB____yh ; 
 __yAB____zh____end :
 __yAB____2h____kQ__z =(! __rAB__acquired ); 
 __yAB____2h____kQ____end :
 if(! __yAB____2h____kQ__z )goto __yAB____2h____iQ__fi ;
 __yAB____2h____lQ = "Did not initialize Dynamic" ;
 goto __yAB____2h____mQ____pD ;
 __builtin_unreachable();
 __yAB____2h____mQ____end :
 __yAB____2h____iQ__if :
 __yAB____2h____iQ__fi :
 __yAB____2h__next_size = __rAB__size +1; __yAB____2h__success = true ; __yAB____2h__self__allocated__prev = __rAB__allocated ; if ( __yAB____2h__next_size >= __rAB__allocated ) { __rAB__allocated = __rAB__allocated + __rAB__allocated /2+1; __yAB____2h__next_acquired =( ptr )((( ptr **) __rAB__acquired )[0]? __runtime_realloc ((( ptr **) __rAB__acquired )[0], __rAB__allocated * sizeof ( ptr ), __yAB____2h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __rAB__allocated * sizeof ( ptr ))); if ( __yAB____2h__success = __yAB____2h__next_acquired )(( ptr **) __rAB__acquired )[0]=( ptr *) __yAB____2h__next_acquired ; } if ( __yAB____2h__success ) { __yAB____2h__mem =( ptr ) __runtime_alloc ( __yAB____zh__z * sizeof ( __yAB____2h____hQ )); if ( __yAB____2h__success = __yAB____2h__mem ) {(( ptr **) __rAB__acquired )[0][ __rAB__size ]= __yAB____2h__mem ; __rAB__size = __yAB____2h__next_size ; } } 
 __yAB____2h____oQ__x = __yAB____2h__success ;
 __yAB____2h____oQ__z =(! __yAB____2h____oQ__x ); 
 __yAB____2h____oQ____end :
 if(! __yAB____2h____oQ__z )goto __yAB____2h____nQ__fi ;
 __yAB____2h____pQ = "Failed a Dynamic allocation" ;
 goto __yAB____2h____qQ____pD ;
 __builtin_unreachable();
 __yAB____2h____qQ____end :
 __yAB____2h____nQ__if :
 __yAB____2h____nQ__fi :
 __yAB____2h____uQ____end :
 memcpy (( char *) __yAB____2h__mem ,( char *) __yAB____wh____m__contents , __yAB__len_x ); memcpy (( char *) __yAB____2h__mem + __yAB__len_x ,( char *) __xAB____5h__contents , __yAB__len_y );(( char *) __yAB____2h__mem )[ __yAB__total_len ]=0; 
 __yAB____5h__contents = __yAB____2h__mem ;
 __yAB____5h____end :
 __yAB____end :
 __rAB____UQ = __yAB__allocator____UQ ;
 __rAB__acquired = __rAB__acquired ;
 __rAB__size = __rAB__size ;
 __rAB__allocated = __rAB__allocated ;
 __rAB____dynamic_entry = __rAB____dynamic_entry ;
 __sAB__on :
 __0AB____end :
 __1AB____aQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __1AB____aQ__acquired )(( ptr **) __1AB____aQ__acquired )[0]=0; 
 __1AB____aQ____VQ = 0 ;
 __1AB____aQ____WQ = 0 ;
 __1AB____aQ____end :
 __1AB__acquired = __1AB____aQ__acquired ;
 __1AB__size = __1AB____aQ____VQ ;
 __1AB__allocated = __1AB____aQ____WQ ;
 __1AB____dynamic_entry = __1AB____aQ____dynamic_entry ;
 __1AB____end :
 __4AB____state = (struct run__812__state*)__runtime_calloc(sizeof(struct run__812__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __4AB____state ) ;
 __4AB____state -> command____c = command____c ;
 __4AB____state -> command__contents = __yAB____5h__contents ;
 __4AB____state -> command__length = __yAB__total_len ;
 __4AB____state -> command__first = __yAB__first ;
 __4AB____state -> command__memory = __rAB__acquired ;
 __4AB____task = __smolambda_add_task ( run__812 , __4AB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __4AB____task ) ;
 if( __4AB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 if( __4AB__err ){
printf("Unhandled error - despite retrieving its .err\n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;}
 __smolambda_task_wait ( __4AB____task ) ;
 __4AB__err = __4AB____state -> err ;
 if(! __4AB__err )goto __3AB__fi ;
 __7AB = "[ \033[31mERROR\033[0m ] " ;
 __8AB = ".s" ;
 __9AB____Ab__length = strlen ( name ); __9AB____Ab__contents =( ptr ) name ; __9AB____Ab__first = name [0]; __9AB____Ab__noptr =( ptr ) __9AB____Ab__noptr ; 
 __9AB____Ab____m__contents = __9AB____Ab__contents ;
 __9AB____Ab____m____end :
 __9AB____Ab____end :
 __9AB____Bb__length = strlen ( __8AB ); __9AB____Bb__contents =( ptr ) __8AB ; __9AB____Bb__first = __8AB [0]; __9AB____Bb__noptr =( ptr ) __9AB____Bb__noptr ; 
 __9AB____Bb____m__contents = __9AB____Bb__contents ;
 __9AB____Bb____m____end :
 __9AB____Bb____end :
 __9AB__len_x = __9AB____Ab__length ; __9AB__len_y = __9AB____Bb__length ; __9AB__total_len = __9AB__len_x + __9AB__len_y ; __9AB__first = __9AB____Ab__length ? __9AB____Ab__first : __9AB____Bb__first ; 
 __9AB____Cb = 1 ;
 __9AB____Db__z = __9AB__total_len + __9AB____Cb ; 
 __9AB____Db____end :
 __9AB____Gb____kQ__z =(! __1AB__acquired ); 
 __9AB____Gb____kQ____end :
 if(! __9AB____Gb____kQ__z )goto __9AB____Gb____iQ__fi ;
 __9AB____Gb____lQ = "Did not initialize Dynamic" ;
 goto __9AB____Gb____mQ____pD ;
 __builtin_unreachable();
 __9AB____Gb____mQ____end :
 __9AB____Gb____iQ__if :
 __9AB____Gb____iQ__fi :
 __9AB____Gb__next_size = __1AB__size +1; __9AB____Gb__success = true ; __9AB____Gb__self__allocated__prev = __1AB__allocated ; if ( __9AB____Gb__next_size >= __1AB__allocated ) { __1AB__allocated = __1AB__allocated + __1AB__allocated /2+1; __9AB____Gb__next_acquired =( ptr )((( ptr **) __1AB__acquired )[0]? __runtime_realloc ((( ptr **) __1AB__acquired )[0], __1AB__allocated * sizeof ( ptr ), __9AB____Gb__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __1AB__allocated * sizeof ( ptr ))); if ( __9AB____Gb__success = __9AB____Gb__next_acquired )(( ptr **) __1AB__acquired )[0]=( ptr *) __9AB____Gb__next_acquired ; } if ( __9AB____Gb__success ) { __9AB____Gb__mem =( ptr ) __runtime_alloc ( __9AB____Db__z * sizeof ( __9AB____Gb____hQ )); if ( __9AB____Gb__success = __9AB____Gb__mem ) {(( ptr **) __1AB__acquired )[0][ __1AB__size ]= __9AB____Gb__mem ; __1AB__size = __9AB____Gb__next_size ; } } 
 __9AB____Gb____oQ__x = __9AB____Gb__success ;
 __9AB____Gb____oQ__z =(! __9AB____Gb____oQ__x ); 
 __9AB____Gb____oQ____end :
 if(! __9AB____Gb____oQ__z )goto __9AB____Gb____nQ__fi ;
 __9AB____Gb____pQ = "Failed a Dynamic allocation" ;
 goto __9AB____Gb____qQ____pD ;
 __builtin_unreachable();
 __9AB____Gb____qQ____end :
 __9AB____Gb____nQ__if :
 __9AB____Gb____nQ__fi :
 __9AB____Gb____uQ____end :
 memcpy (( char *) __9AB____Gb__mem ,( char *) __9AB____Ab____m__contents , __9AB__len_x ); memcpy (( char *) __9AB____Gb__mem + __9AB__len_x ,( char *) __9AB____Bb____m__contents , __9AB__len_y );(( char *) __9AB____Gb__mem )[ __9AB__total_len ]=0; 
 __9AB____Jb__contents = __9AB____Gb__mem ;
 __9AB____Jb____end :
 __9AB____end :
 __1AB____UQ = __9AB__allocator____UQ ;
 __1AB__acquired = __1AB__acquired ;
 __1AB__size = __1AB__size ;
 __1AB__allocated = __1AB__allocated ;
 __1AB____dynamic_entry = __1AB____dynamic_entry ;
 __ABB____wh__length = strlen ( __7AB ); __ABB____wh__contents =( ptr ) __7AB ; __ABB____wh__first = __7AB [0]; __ABB____wh__noptr =( ptr ) __ABB____wh__noptr ; 
 __ABB____wh____m__contents = __ABB____wh__contents ;
 __ABB____wh____m____end :
 __ABB____wh____end :
 __ABB____xh____j____end :
 __ABB____xh____end :
 __ABB__len_x = __ABB____wh__length ; __ABB__len_y = __9AB__total_len ; __ABB__total_len = __ABB__len_x + __ABB__len_y ; __ABB__first = __ABB____wh__length ? __ABB____wh__first : __9AB__first ; 
 __ABB____yh = 1 ;
 __ABB____zh__z = __ABB__total_len + __ABB____yh ; 
 __ABB____zh____end :
 __ABB____2h____kQ__z =(! __1AB__acquired ); 
 __ABB____2h____kQ____end :
 if(! __ABB____2h____kQ__z )goto __ABB____2h____iQ__fi ;
 __ABB____2h____lQ = "Did not initialize Dynamic" ;
 goto __ABB____2h____mQ____pD ;
 __builtin_unreachable();
 __ABB____2h____mQ____end :
 __ABB____2h____iQ__if :
 __ABB____2h____iQ__fi :
 __ABB____2h__next_size = __1AB__size +1; __ABB____2h__success = true ; __ABB____2h__self__allocated__prev = __1AB__allocated ; if ( __ABB____2h__next_size >= __1AB__allocated ) { __1AB__allocated = __1AB__allocated + __1AB__allocated /2+1; __ABB____2h__next_acquired =( ptr )((( ptr **) __1AB__acquired )[0]? __runtime_realloc ((( ptr **) __1AB__acquired )[0], __1AB__allocated * sizeof ( ptr ), __ABB____2h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __1AB__allocated * sizeof ( ptr ))); if ( __ABB____2h__success = __ABB____2h__next_acquired )(( ptr **) __1AB__acquired )[0]=( ptr *) __ABB____2h__next_acquired ; } if ( __ABB____2h__success ) { __ABB____2h__mem =( ptr ) __runtime_alloc ( __ABB____zh__z * sizeof ( __ABB____2h____hQ )); if ( __ABB____2h__success = __ABB____2h__mem ) {(( ptr **) __1AB__acquired )[0][ __1AB__size ]= __ABB____2h__mem ; __1AB__size = __ABB____2h__next_size ; } } 
 __ABB____2h____oQ__x = __ABB____2h__success ;
 __ABB____2h____oQ__z =(! __ABB____2h____oQ__x ); 
 __ABB____2h____oQ____end :
 if(! __ABB____2h____oQ__z )goto __ABB____2h____nQ__fi ;
 __ABB____2h____pQ = "Failed a Dynamic allocation" ;
 goto __ABB____2h____qQ____pD ;
 __builtin_unreachable();
 __ABB____2h____qQ____end :
 __ABB____2h____nQ__if :
 __ABB____2h____nQ__fi :
 __ABB____2h____uQ____end :
 memcpy (( char *) __ABB____2h__mem ,( char *) __ABB____wh____m__contents , __ABB__len_x ); memcpy (( char *) __ABB____2h__mem + __ABB__len_x ,( char *) __9AB____Jb__contents , __ABB__len_y );(( char *) __ABB____2h__mem )[ __ABB__total_len ]=0; 
 __ABB____5h__contents = __ABB____2h__mem ;
 __ABB____5h____end :
 __ABB____end :
 __1AB____UQ = __ABB__allocator____UQ ;
 __1AB__acquired = __1AB__acquired ;
 __1AB__size = __1AB__size ;
 __1AB__allocated = __1AB__allocated ;
 __1AB____dynamic_entry = __1AB____dynamic_entry ;
 printf ( "%s\n" ,( char *) __ABB____5h__contents ); 
 __BBB____end :
 __3AB__if :
 goto __3AB__el ;
 __3AB__fi :
 __CBB = "[ \033[32mOK\033[0m ] " ;
 __DBB = ".s" ;
 __EBB____Ab__length = strlen ( name ); __EBB____Ab__contents =( ptr ) name ; __EBB____Ab__first = name [0]; __EBB____Ab__noptr =( ptr ) __EBB____Ab__noptr ; 
 __EBB____Ab____m__contents = __EBB____Ab__contents ;
 __EBB____Ab____m____end :
 __EBB____Ab____end :
 __EBB____Bb__length = strlen ( __DBB ); __EBB____Bb__contents =( ptr ) __DBB ; __EBB____Bb__first = __DBB [0]; __EBB____Bb__noptr =( ptr ) __EBB____Bb__noptr ; 
 __EBB____Bb____m__contents = __EBB____Bb__contents ;
 __EBB____Bb____m____end :
 __EBB____Bb____end :
 __EBB__len_x = __EBB____Ab__length ; __EBB__len_y = __EBB____Bb__length ; __EBB__total_len = __EBB__len_x + __EBB__len_y ; __EBB__first = __EBB____Ab__length ? __EBB____Ab__first : __EBB____Bb__first ; 
 __EBB____Cb = 1 ;
 __EBB____Db__z = __EBB__total_len + __EBB____Cb ; 
 __EBB____Db____end :
 __EBB____Gb____kQ__z =(! __1AB__acquired ); 
 __EBB____Gb____kQ____end :
 if(! __EBB____Gb____kQ__z )goto __EBB____Gb____iQ__fi ;
 __EBB____Gb____lQ = "Did not initialize Dynamic" ;
 goto __EBB____Gb____mQ____pD ;
 __builtin_unreachable();
 __EBB____Gb____mQ____end :
 __EBB____Gb____iQ__if :
 __EBB____Gb____iQ__fi :
 __EBB____Gb__next_size = __1AB__size +1; __EBB____Gb__success = true ; __EBB____Gb__self__allocated__prev = __1AB__allocated ; if ( __EBB____Gb__next_size >= __1AB__allocated ) { __1AB__allocated = __1AB__allocated + __1AB__allocated /2+1; __EBB____Gb__next_acquired =( ptr )((( ptr **) __1AB__acquired )[0]? __runtime_realloc ((( ptr **) __1AB__acquired )[0], __1AB__allocated * sizeof ( ptr ), __EBB____Gb__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __1AB__allocated * sizeof ( ptr ))); if ( __EBB____Gb__success = __EBB____Gb__next_acquired )(( ptr **) __1AB__acquired )[0]=( ptr *) __EBB____Gb__next_acquired ; } if ( __EBB____Gb__success ) { __EBB____Gb__mem =( ptr ) __runtime_alloc ( __EBB____Db__z * sizeof ( __EBB____Gb____hQ )); if ( __EBB____Gb__success = __EBB____Gb__mem ) {(( ptr **) __1AB__acquired )[0][ __1AB__size ]= __EBB____Gb__mem ; __1AB__size = __EBB____Gb__next_size ; } } 
 __EBB____Gb____oQ__x = __EBB____Gb__success ;
 __EBB____Gb____oQ__z =(! __EBB____Gb____oQ__x ); 
 __EBB____Gb____oQ____end :
 if(! __EBB____Gb____oQ__z )goto __EBB____Gb____nQ__fi ;
 __EBB____Gb____pQ = "Failed a Dynamic allocation" ;
 goto __EBB____Gb____qQ____pD ;
 __builtin_unreachable();
 __EBB____Gb____qQ____end :
 __EBB____Gb____nQ__if :
 __EBB____Gb____nQ__fi :
 __EBB____Gb____uQ____end :
 memcpy (( char *) __EBB____Gb__mem ,( char *) __EBB____Ab____m__contents , __EBB__len_x ); memcpy (( char *) __EBB____Gb__mem + __EBB__len_x ,( char *) __EBB____Bb____m__contents , __EBB__len_y );(( char *) __EBB____Gb__mem )[ __EBB__total_len ]=0; 
 __EBB____Jb__contents = __EBB____Gb__mem ;
 __EBB____Jb____end :
 __EBB____end :
 __1AB____UQ = __EBB__allocator____UQ ;
 __1AB__acquired = __1AB__acquired ;
 __1AB__size = __1AB__size ;
 __1AB__allocated = __1AB__allocated ;
 __1AB____dynamic_entry = __1AB____dynamic_entry ;
 __FBB____wh__length = strlen ( __CBB ); __FBB____wh__contents =( ptr ) __CBB ; __FBB____wh__first = __CBB [0]; __FBB____wh__noptr =( ptr ) __FBB____wh__noptr ; 
 __FBB____wh____m__contents = __FBB____wh__contents ;
 __FBB____wh____m____end :
 __FBB____wh____end :
 __FBB____xh____j____end :
 __FBB____xh____end :
 __FBB__len_x = __FBB____wh__length ; __FBB__len_y = __EBB__total_len ; __FBB__total_len = __FBB__len_x + __FBB__len_y ; __FBB__first = __FBB____wh__length ? __FBB____wh__first : __EBB__first ; 
 __FBB____yh = 1 ;
 __FBB____zh__z = __FBB__total_len + __FBB____yh ; 
 __FBB____zh____end :
 __FBB____2h____kQ__z =(! __1AB__acquired ); 
 __FBB____2h____kQ____end :
 if(! __FBB____2h____kQ__z )goto __FBB____2h____iQ__fi ;
 __FBB____2h____lQ = "Did not initialize Dynamic" ;
 goto __FBB____2h____mQ____pD ;
 __builtin_unreachable();
 __FBB____2h____mQ____end :
 __FBB____2h____iQ__if :
 __FBB____2h____iQ__fi :
 __FBB____2h__next_size = __1AB__size +1; __FBB____2h__success = true ; __FBB____2h__self__allocated__prev = __1AB__allocated ; if ( __FBB____2h__next_size >= __1AB__allocated ) { __1AB__allocated = __1AB__allocated + __1AB__allocated /2+1; __FBB____2h__next_acquired =( ptr )((( ptr **) __1AB__acquired )[0]? __runtime_realloc ((( ptr **) __1AB__acquired )[0], __1AB__allocated * sizeof ( ptr ), __FBB____2h__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __1AB__allocated * sizeof ( ptr ))); if ( __FBB____2h__success = __FBB____2h__next_acquired )(( ptr **) __1AB__acquired )[0]=( ptr *) __FBB____2h__next_acquired ; } if ( __FBB____2h__success ) { __FBB____2h__mem =( ptr ) __runtime_alloc ( __FBB____zh__z * sizeof ( __FBB____2h____hQ )); if ( __FBB____2h__success = __FBB____2h__mem ) {(( ptr **) __1AB__acquired )[0][ __1AB__size ]= __FBB____2h__mem ; __1AB__size = __FBB____2h__next_size ; } } 
 __FBB____2h____oQ__x = __FBB____2h__success ;
 __FBB____2h____oQ__z =(! __FBB____2h____oQ__x ); 
 __FBB____2h____oQ____end :
 if(! __FBB____2h____oQ__z )goto __FBB____2h____nQ__fi ;
 __FBB____2h____pQ = "Failed a Dynamic allocation" ;
 goto __FBB____2h____qQ____pD ;
 __builtin_unreachable();
 __FBB____2h____qQ____end :
 __FBB____2h____nQ__if :
 __FBB____2h____nQ__fi :
 __FBB____2h____uQ____end :
 memcpy (( char *) __FBB____2h__mem ,( char *) __FBB____wh____m__contents , __FBB__len_x ); memcpy (( char *) __FBB____2h__mem + __FBB__len_x ,( char *) __EBB____Jb__contents , __FBB__len_y );(( char *) __FBB____2h__mem )[ __FBB__total_len ]=0; 
 __FBB____5h__contents = __FBB____2h__mem ;
 __FBB____5h____end :
 __FBB____end :
 __1AB____UQ = __FBB__allocator____UQ ;
 __1AB__acquired = __1AB__acquired ;
 __1AB__size = __1AB__size ;
 __1AB__allocated = __1AB__allocated ;
 __1AB____dynamic_entry = __1AB____dynamic_entry ;
 printf ( "%s\n" ,( char *) __FBB____5h__contents ); 
 __GBB____end :
 __3AB__le :
 __3AB__el :
 __2AB__on :
 __end :
goto __return;

// ERROR HANDLING
__wAB____Gb____mQ____pD :
 printf ( "%s\n" , __wAB____Gb____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __wAB____Gb____qQ____pD :
 printf ( "%s\n" , __wAB____Gb____pQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __xAB____2h____mQ____pD :
 printf ( "%s\n" , __xAB____2h____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __xAB____2h____qQ____pD :
 printf ( "%s\n" , __xAB____2h____pQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __yAB____2h____mQ____pD :
 printf ( "%s\n" , __yAB____2h____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __yAB____2h____qQ____pD :
 printf ( "%s\n" , __yAB____2h____pQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __5AB :
printf("Runtime error from run __4AB \n");
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
 __9AB____Gb____mQ____pD :
 printf ( "%s\n" , __9AB____Gb____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __9AB____Gb____qQ____pD :
 printf ( "%s\n" , __9AB____Gb____pQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __ABB____2h____mQ____pD :
 printf ( "%s\n" , __ABB____2h____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __ABB____2h____qQ____pD :
 printf ( "%s\n" , __ABB____2h____pQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __EBB____Gb____mQ____pD :
 printf ( "%s\n" , __EBB____Gb____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __EBB____Gb____qQ____pD :
 printf ( "%s\n" , __EBB____Gb____pQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __FBB____2h____mQ____pD :
 printf ( "%s\n" , __FBB____2h____lQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __FBB____2h____qQ____pD :
 printf ( "%s\n" , __FBB____2h____pQ ); 
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
if ( __1AB__acquired ) { for ( __1AB____dynamic_entry =0; __1AB____dynamic_entry < __1AB__size ;++ __1AB____dynamic_entry ) { __runtime_free ((( ptr **) __1AB__acquired )[0][ __1AB____dynamic_entry ]); } __runtime_free ( __1AB__acquired ); __1AB__acquired =0; __1AB__size =0; __1AB__allocated =0; } 
 if ( __1AB__acquired ) { for ( __1AB____aQ____dynamic_entry =0; __1AB____aQ____dynamic_entry < __1AB____aQ____VQ ;++ __1AB____aQ____dynamic_entry ) { __runtime_free ((( ptr **) __1AB__acquired )[0][ __1AB____aQ____dynamic_entry ]); } __runtime_free ( __1AB__acquired ); __1AB__acquired =0; __1AB____aQ____VQ =0; __1AB____aQ____WQ =0; } 
if ( __rAB__acquired ) { for ( __rAB____dynamic_entry =0; __rAB____dynamic_entry < __rAB__size ;++ __rAB____dynamic_entry ) { __runtime_free ((( ptr **) __rAB__acquired )[0][ __rAB____dynamic_entry ]); } __runtime_free ( __rAB__acquired ); __rAB__acquired =0; __rAB__size =0; __rAB__allocated =0; } 
 if ( __rAB__acquired ) { for ( __rAB____aQ____dynamic_entry =0; __rAB____aQ____dynamic_entry < __rAB____aQ____VQ ;++ __rAB____aQ____dynamic_entry ) { __runtime_free ((( ptr **) __rAB__acquired )[0][ __rAB____aQ____dynamic_entry ]); } __runtime_free ( __rAB__acquired ); __rAB__acquired =0; __rAB____aQ____VQ =0; __rAB____aQ____WQ =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}


void run__811(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__811__state *__state=(struct run__811__state*)__void__state;
ptr command__contents= __state->command__contents;
u64 command__length= __state->command__length;
char command__first= __state->command__first;
ptr command__memory= __state->command__memory;
nominal __jAB__p____88=0;
bool __iAB____ZAB____E9__z=0;
bool __iAB____ZAB____D9__z=0;
ptr __iAB____ZAB____D9__x=0;
ptr __iAB____ZAB____B9____p__contents=0;
cstr __iAB____VAB____uF=0;
char __iAB____VAB____qF=0;
bool process____ZAB____D9__z=0;
ptr process__command__contents=0;
ptr __iAB____VAB__mem=0;
cstr process____VAB____uF=0;
char process____TAB=0;
bool process____VAB____tF__z=0;
bool process____VAB____nF__z=0;
ptr __gAB__contents=0;
bool process____VAB____sF=0;
i64 __iAB____ZAB__status=0;
char process__first=0;
ptr process____ZAB____D9__x=0;
char process__command__first=0;
nominal process__command____b=0;
char process____VAB____0F=0;
nominal process____ZAB____88=0;
u64 __iAB____VAB____mF=0;
ptr process____ZAB__contents=0;
char process____VAB____2F____9E=0;
u64 process____VAB____2F__bytesize=0;
ptr process____VAB__mem=0;
ptr process__command__memory=0;
ptr __iAB____ZAB__contents=0;
nominal command____b=0;
u64 process____VAB____mF=0;
ptr process____OAB__contents=0;
u64 process____RAB=0;
bool __iAB____VAB____tF__z=0;
cstr process____VAB____oF=0;
bool __iAB____VAB____sF=0;
ptr process____XAB__contents=0;
i64 process____ZAB__status=0;
char process____VAB____qF=0;
u64 process____VAB__size=0;
u64 process____SAB__z=0;
ptr __hAB__contents=0;
cstr __iAB____VAB____oF=0;
ptr process____ZAB____B9____p__contents=0;
bool process____ZAB____E9__z=0;
ptr process____YAB__contents=0;
cstr process__mem=0;
u64 __iAB____SAB__z=0;
nominal process____OAB____88=0;
u64 process__command__length=0;
bool __iAB____VAB____nF__z=0;
u64 __iAB____RAB=0;

// IMPLEMENTATION
__gAB__contents = 0 ;
 __hAB__contents = __gAB__contents ;
 __hAB____end :
 __iAB____QAB____end :
 __iAB____RAB = 1 ;
 __iAB____SAB__z = command__length + __iAB____RAB ; 
 __iAB____SAB____end :
 __iAB____VAB____mF = 0 ;
 __iAB____VAB____nF__z =( __iAB____SAB__z == __iAB____VAB____mF ); 
 __iAB____VAB____nF____end :
 if(! __iAB____VAB____nF__z )goto __iAB____VAB____lF__fi ;
 __iAB____VAB____oF = "Cannot allocate zero size" ;
 goto __iAB____VAB____pF____pD ;
 __builtin_unreachable();
 __iAB____VAB____pF____end :
 __iAB____VAB____lF__if :
 __iAB____VAB____lF__fi :
 __iAB____VAB__mem = alloca ( __iAB____SAB__z * sizeof ( __iAB____VAB____qF )); 
 __iAB____VAB____sF = __iAB____VAB__mem ;
 __iAB____VAB____tF__z =(! __iAB____VAB____sF ); 
 __iAB____VAB____tF____end :
 if(! __iAB____VAB____tF__z )goto __iAB____VAB____rF__fi ;
 __iAB____VAB____uF = "Failed a Stack allocation" ;
 goto __iAB____VAB____vF____pD ;
 __builtin_unreachable();
 __iAB____VAB____vF____end :
 __iAB____VAB____rF__if :
 __iAB____VAB____rF__fi :
 __iAB____VAB____zF____end :
 __iAB____YAB____end :
 __iAB____ZAB____B9____p____end :
 __iAB____ZAB____B9____end :
 __iAB____ZAB__contents =( ptr ) popen (( cstr ) __iAB____ZAB____B9____p__contents , "r" ); 
 __iAB____ZAB____D9__x = __iAB____ZAB__contents ;
 __iAB____ZAB____D9__z =( __iAB____ZAB____D9__x ); 
 __iAB____ZAB____D9____end :
 __iAB____ZAB____E9__z =(! __iAB____ZAB____D9__z ); 
 __iAB____ZAB____E9____end :
 if(! __iAB____ZAB____E9__z )goto __iAB____ZAB____C9__fi ;
 goto __iAB____ZAB____F9 ;
 __builtin_unreachable();
 __iAB____ZAB____C9__if :
 __iAB____ZAB____C9__fi :
 __iAB____ZAB____I9____end :
 __iAB____ZAB____end :
 __iAB____end :
 __TRANSIENT( __iAB____VAB__mem )
 process____ZAB__contents = __iAB____ZAB__contents ;
 if ( process____ZAB__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process____ZAB__contents )) { } } 
 __jAB____end :
 process____ZAB____88 = __jAB__p____88 ;
 __iAB____ZAB__status =0; if ( process____ZAB__contents ) __iAB____ZAB__status = pclose (( FILE *) process____ZAB__contents ); process____ZAB__contents =0; if ( __iAB____ZAB__status ) { if ( __iAB____ZAB__status !=-1&& WIFEXITED ( __iAB____ZAB__status )) __iAB____ZAB__status = WEXITSTATUS ( __iAB____ZAB__status ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __iAB____ZAB__status ); __result__errocode = __USER__ERROR ; goto __failsafe ; } 
 __end :
goto __return;

// ERROR HANDLING
__iAB____VAB____pF____pD :
 printf ( "%s\n" , __iAB____VAB____oF ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __iAB____VAB____vF____pD :
 printf ( "%s\n" , __iAB____VAB____uF ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __iAB____ZAB____F9 :
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


void run__810(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__810__state *__state=(struct run__810__state*)__void__state;
cstr command= __state->command;
i64 __dAB__status=0;
nominal __eAB__p____88=0;
nominal process____88=0;
ptr process__contents=0;
ptr __dAB____B9____p__contents=0;
bool __dAB____E9__z=0;
ptr __dAB__contents=0;
bool __dAB____D9__z=0;
ptr __bAB__contents=0;
ptr __cAB__contents=0;
ptr __dAB____D9__x=0;

// IMPLEMENTATION
__bAB__contents = 0 ;
 __cAB__contents = __bAB__contents ;
 __cAB____end :
 __dAB____B9____p____end :
 __dAB____B9____end :
 __dAB__contents =( ptr ) popen (( cstr ) __dAB____B9____p__contents , "r" ); 
 __dAB____D9__x = __dAB__contents ;
 __dAB____D9__z =( __dAB____D9__x ); 
 __dAB____D9____end :
 __dAB____E9__z =(! __dAB____D9__z ); 
 __dAB____E9____end :
 if(! __dAB____E9__z )goto __dAB____C9__fi ;
 goto __dAB____F9 ;
 __builtin_unreachable();
 __dAB____C9__if :
 __dAB____C9__fi :
 __dAB____I9____end :
 __dAB____end :
 process__contents = __dAB__contents ;
 if ( process__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process__contents )) { } } 
 __eAB____end :
 process____88 = __eAB__p____88 ;
 __dAB__status =0; if ( process__contents ) __dAB__status = pclose (( FILE *) process__contents ); process__contents =0; if ( __dAB__status ) { if ( __dAB__status !=-1&& WIFEXITED ( __dAB__status )) __dAB__status = WEXITSTATUS ( __dAB__status ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __dAB__status ); __result__errocode = __USER__ERROR ; goto __failsafe ; } 
 __end :
goto __return;

// ERROR HANDLING
__dAB____F9 :
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
struct main__817__state __main_args={0};
__smolambda_initialize_service_tasks(main__817, &__main_args);
return __main_args.err;
}

