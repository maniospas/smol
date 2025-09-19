#define SMOLAMBDA_SERVICES 1
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

#include<string.h>

#include<stdlib.h>

#include<stdio.h>

struct main__787__state{errcode err;};
void main__787(void *__void__state);

void main__787(void *__void__state){
errcode __result__errocode=0;
struct main__787__state *__state=(struct main__787__state*)__void__state;
ptr __l9__message__contents=0;
nominal __k9____d9____Vi__self__contents____5E=0;
nominal __k9____d9____Vi__self__type=0;
u64 __k9____d9____Vi____TS__bytesize=0;
bool __k9____d9____Vi____LS__z=0;
u64 __k9____d9____Vi__size=0;
u64 __k9____d9____Si__z=0;
nominal __k9____P9__contents____6E____0E=0;
nominal __k9____c9____jb__self__type=0;
nominal __k9____P9__type=0;
char __k9____d9____Vi____TS____8E=0;
char __k9____c9____jb____TS____8E=0;
char __k9____c9____jb____RS=0;
ptr __k9____c9____jb___contents=0;
cstr __k9____c9____jb____MS=0;
bool __k9____c9____jb____LS__z=0;
u64 __k9____c9____jb____KS__z=0;
u64 __k9____c9____jb____KS__x=0;
u64 __k9____c9____fb=0;
u64 __k9____c9__len_y=0;
char __k9____c9____eb__first=0;
ptr __k9____c9____eb__contents=0;
nominal __k9____c9____jb__self__contents____5E=0;
ptr __k9____a9=0;
u64 __k9____Y9=0;
ptr __k9____X9=0;
u64 __k9____c9____gb__z=0;
u64 __k9__segments__dynamic____buffer_alignment=0;
bool __k9____T9____1D__z=0;
u64 __k9____T9____0D__z=0;
char __k9____c9____jb____IS=0;
u64 __k9__i=0;
nominal __k9____P9__contents____5E=0;
u64 __k9____T9__value=0;
u64 __k9____R9__pos=0;
u64 __k9____R9____wD=0;
u64 __k9____P9__length=0;
u64 __k9____P9__contents__bytesize=0;
u64 __k9____c9__total_len=0;
ptr __k9____P9__contents__underlying=0;
ptr __k9____P9__contents__mem=0;
u64 __k9____d9__len_x=0;
u64 __k9____P9____HW____fO=0;
char __k9____P9____GW____QI____zF=0;
u64 __k9____d9__total_len=0;
cstr __k9____P9____GW____QI____tF=0;
ptr __k9____c9____mb__contents=0;
bool __k9____P9____GW____QI____sF__z=0;
char __k9____P9____GW____QI____pF=0;
bool __k9____P9____GW____QI____mF__z=0;
u64 __k9____P9____GW____QI____lF=0;
char __k9____P9____HW____hO=0;
char __k9____P9____GW____OI=0;
u64 __k9____P9__size=0;
ptr __k9____d9____Yi__contents=0;
cstr __k9____b9=0;
ptr __k9__combined__memory=0;
char __k9__combined__first=0;
ptr __k9__combined__contents=0;
ptr __k9____L9____m__contents=0;
ptr __k9____L9__noptr=0;
ptr __k9____L9__contents=0;
char __k9____d9____Vi____IS=0;
char __k9____d9__first=0;
u64 __k9____d9____Vi____KS__z=0;
u64 __k9____O9=0;
u64 __k9__combined__length=0;
cstr __i9=0;
char __k9____P9__contents____7E=0;
ptr segments__dynamic=0;
u64 __k9____c9____jb__size=0;
u64 __k9____T9____zD=0;
u64 __k9____R9____xD=0;
u64 __k9____d9____Ri=0;
ptr __k9____c9____eb__noptr=0;
char __k9____Z9=0;
char __k9____c9____hb=0;
u64 __k9____P9____GW____QI____1F__bytesize=0;
ptr __h9____88____m__contents=0;
u64 __k9____d9____Vi____KS__x=0;
u64 __k9____P9__contents__size=0;
char __k9____L9__first=0;
u64 __k9____buffer_size=0;
ptr __j9____88__noptr=0;
cstr __k9____P9____GW____QI____nF=0;
u64 __f9__dynamic____buffer_alignment=0;
ptr __j9____88__contents=0;
u64 __f9__dynamic____buffer_size=0;
u64 __k9____c9____eb__length=0;
u64 __k9____c9____jb____TS__bytesize=0;
ptr __k9____P9____GW____QI__mem=0;
cstr __k9____d9____Vi____MS=0;
u64 __k9____d9__len_y=0;
u64 __k9__segments__dynamic____buffer_size=0;
char __k9____P9____HW____iO=0;
cstr __k9____K9=0;
char __k9____d9____Vi____RS=0;
ptr __k9____c9____eb____m__contents=0;
bool __k9____P9____GW____QI____rF=0;
cstr __g9=0;
char __k9____c9__first=0;
ptr __f9__surface=0;
ptr __k9____d9____Vi___contents=0;
u64 __k9____c9__len_x=0;
char __k9____P9____GW____QI____1F____8E=0;
char __k9____d9____Ti=0;
u64 __f9__dynamic____buffer_capacity=0;
ptr __f9__dynamic=0;
u64 __h9____88__length=0;
nominal __k9____d9____Vi__self__contents____6E____0E=0;
ptr __h9____88__contents=0;
char __h9____88__first=0;
ptr __h9____88__noptr=0;
u64 __f9__dynamic____buffer_prev_capacity=0;
u64 __k9____T9__self__pos=0;
ptr __f9__dynamic____buffer_contents=0;
nominal __k9____c9____jb__self__contents____6E____0E=0;
u64 __j9____88__length=0;
char __j9____88__first=0;
ptr __j9____88____m__contents=0;
u64 __k9____L9__length=0;

// IMPLEMENTATION
__f9__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 __f9__surface = 0 ;
 __g9 = "I think." ;
 __h9____88__length = strlen ( __g9 ); __h9____88__contents =( ptr ) __g9 ; __h9____88__first = __g9 [0]; __h9____88__noptr =( ptr ) __h9____88__noptr ; 
 __h9____88____m__contents = __h9____88__contents ;
 if(! __f9__dynamic )goto __result__buffer_error ;
 __f9__dynamic____buffer_alignment = 4 ;
 __f9__dynamic____buffer_size = ((u64*) __f9__dynamic )[1] ;
 __f9__dynamic____buffer_capacity = ((u64*) __f9__dynamic )[2] & ~(1ULL << 63) ;
 if( __f9__dynamic____buffer_size >= __f9__dynamic____buffer_capacity ){ if( ((u64*) __f9__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __f9__dynamic____buffer_prev_capacity = __f9__dynamic____buffer_capacity ;
 __f9__dynamic____buffer_capacity = __f9__dynamic____buffer_capacity +( __f9__dynamic____buffer_capacity >>2)+1; if( __f9__dynamic____buffer_size ) ((void**) __f9__dynamic )[0] = __runtime_realloc((u64*)((void**) __f9__dynamic )[0],  __f9__dynamic____buffer_capacity * __f9__dynamic____buffer_alignment *sizeof(u64),  __f9__dynamic____buffer_prev_capacity * __f9__dynamic____buffer_alignment *sizeof(u64)); else ((void**) __f9__dynamic )[0] = __runtime_alloc( __f9__dynamic____buffer_capacity * __f9__dynamic____buffer_alignment *sizeof(u64)); ((u64*) __f9__dynamic )[2] = __f9__dynamic____buffer_capacity ;
 __f9__dynamic____buffer_contents = (ptr)((void**) __f9__dynamic )[0] ;
 if( ! __f9__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  __f9__dynamic____buffer_contents = (ptr)(((u64*) __f9__dynamic )[0]) ;
 ((u64*) __f9__dynamic )[1] = __f9__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __f9__dynamic____buffer_contents )[ __f9__dynamic____buffer_size * __f9__dynamic____buffer_alignment +0], & __h9____88____m__contents , sizeof(ptr)); memcpy(&((u64*) __f9__dynamic____buffer_contents )[ __f9__dynamic____buffer_size * __f9__dynamic____buffer_alignment +1], & __h9____88__length , sizeof(u64)); memcpy(&((u64*) __f9__dynamic____buffer_contents )[ __f9__dynamic____buffer_size * __f9__dynamic____buffer_alignment +2], & __h9____88__first , sizeof(char)); memcpy(&((u64*) __f9__dynamic____buffer_contents )[ __f9__dynamic____buffer_size * __f9__dynamic____buffer_alignment +3], & __h9____88__noptr , sizeof(ptr)); __i9 = "Therefore I am." ;
 __j9____88__length = strlen ( __i9 ); __j9____88__contents =( ptr ) __i9 ; __j9____88__first = __i9 [0]; __j9____88__noptr =( ptr ) __j9____88__noptr ; 
 __j9____88____m__contents = __j9____88__contents ;
 if(! __f9__dynamic )goto __result__buffer_error ;
 __f9__dynamic____buffer_alignment = 4 ;
 __f9__dynamic____buffer_size = ((u64*) __f9__dynamic )[1] ;
 __f9__dynamic____buffer_capacity = ((u64*) __f9__dynamic )[2] & ~(1ULL << 63) ;
 if( __f9__dynamic____buffer_size >= __f9__dynamic____buffer_capacity ){ if( ((u64*) __f9__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __f9__dynamic____buffer_prev_capacity = __f9__dynamic____buffer_capacity ;
 __f9__dynamic____buffer_capacity = __f9__dynamic____buffer_capacity +( __f9__dynamic____buffer_capacity >>2)+1; if( __f9__dynamic____buffer_size ) ((void**) __f9__dynamic )[0] = __runtime_realloc((u64*)((void**) __f9__dynamic )[0],  __f9__dynamic____buffer_capacity * __f9__dynamic____buffer_alignment *sizeof(u64),  __f9__dynamic____buffer_prev_capacity * __f9__dynamic____buffer_alignment *sizeof(u64)); else ((void**) __f9__dynamic )[0] = __runtime_alloc( __f9__dynamic____buffer_capacity * __f9__dynamic____buffer_alignment *sizeof(u64)); ((u64*) __f9__dynamic )[2] = __f9__dynamic____buffer_capacity ;
 __f9__dynamic____buffer_contents = (ptr)((void**) __f9__dynamic )[0] ;
 if( ! __f9__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  __f9__dynamic____buffer_contents = (ptr)(((u64*) __f9__dynamic )[0]) ;
 ((u64*) __f9__dynamic )[1] = __f9__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __f9__dynamic____buffer_contents )[ __f9__dynamic____buffer_size * __f9__dynamic____buffer_alignment +0], & __j9____88____m__contents , sizeof(ptr)); memcpy(&((u64*) __f9__dynamic____buffer_contents )[ __f9__dynamic____buffer_size * __f9__dynamic____buffer_alignment +1], & __j9____88__length , sizeof(u64)); memcpy(&((u64*) __f9__dynamic____buffer_contents )[ __f9__dynamic____buffer_size * __f9__dynamic____buffer_alignment +2], & __j9____88__first , sizeof(char)); memcpy(&((u64*) __f9__dynamic____buffer_contents )[ __f9__dynamic____buffer_size * __f9__dynamic____buffer_alignment +3], & __j9____88__noptr , sizeof(ptr)); segments__dynamic = __f9__dynamic ;
 __k9____K9 = "" ;
 __k9____L9__length = strlen ( __k9____K9 ); __k9____L9__contents =( ptr ) __k9____K9 ; __k9____L9__first = __k9____K9 [0]; __k9____L9__noptr =( ptr ) __k9____L9__noptr ; 
 __k9____L9____m__contents = __k9____L9__contents ;
 __k9__combined__contents = __k9____L9____m__contents ;
 __k9__combined__length = __k9____L9__length ;
 __k9__combined__first = __k9____L9__first ;
 __k9__combined__memory = __k9____L9__noptr ;
 __k9____O9 = 1024 ;
 __k9____P9__size = __k9____O9 ;
 __k9____P9____GW____OI = 0 ;
 __k9____P9____GW____QI____lF = 0 ;
 __k9____P9____GW____QI____mF__z =( __k9____P9__size == __k9____P9____GW____QI____lF ); 
 __k9____P9____GW____QI____mF____end :
 if(! __k9____P9____GW____QI____mF__z )goto __k9____P9____GW____QI____kF__fi ;
 __k9____P9____GW____QI____nF = "Cannot allocate zero size" ;
 goto __k9____P9____GW____QI____oF____oD ;
 __builtin_unreachable();
 __k9____P9____GW____QI____kF__fi :
 __k9____P9____GW____QI__mem = alloca ( __k9____P9__size * sizeof ( __k9____P9____GW____QI____pF )); 
 __k9____P9____GW____QI____rF = __k9____P9____GW____QI__mem ;
 __k9____P9____GW____QI____sF__z =(! __k9____P9____GW____QI____rF ); 
 __k9____P9____GW____QI____sF____end :
 if(! __k9____P9____GW____QI____sF__z )goto __k9____P9____GW____QI____qF__fi ;
 __k9____P9____GW____QI____tF = "Failed a Stack allocation" ;
 goto __k9____P9____GW____QI____uF____oD ;
 __builtin_unreachable();
 __k9____P9____GW____QI____qF__fi :
 __k9____P9____GW____QI____zF = 0 ;
 __k9____P9____GW____QI____1F__bytesize = sizeof ( __k9____P9____GW____QI____1F____8E )* __k9____P9__size ; 
 __k9____P9____GW____QI____1F____end :
 __k9____P9____HW____fO = 0 ;
 __k9____P9____HW____hO = 0 ;
 __k9____P9____HW____iO = 0 ;
 __k9____P9__contents__size = __k9____P9__size ;
 __k9____P9__contents____7E = __k9____P9____GW____QI____zF ;
 __k9____P9__contents__mem = __k9____P9____GW____QI__mem ;
 __k9____P9__contents__underlying = __k9____P9____GW____QI__mem ;
 __k9____P9__contents__bytesize = __k9____P9____GW____QI____1F__bytesize ;
 __k9____P9__length = __k9____P9____HW____fO ;
 __k9____buffer_size = segments__dynamic ? ((u64*) segments__dynamic )[1]:0 ;
 __k9____R9____wD = 0 ;
 __k9____R9____xD = 1 ;
 __k9____R9__pos = __k9____R9____wD ;
 __k9____S9__loop :
 __k9____T9__self__pos = __k9____R9__pos ;
 __k9____T9__value = __k9__i ;
 __k9____T9__value = __k9____T9__self__pos ;
 __k9____T9____zD = 1 ;
 __k9____T9____0D__z = __k9____T9__self__pos + __k9____T9____zD ; 
 __k9____T9____0D____end :
 __k9____T9__self__pos = __k9____T9____0D__z ;
 __k9____T9____1D__z = __k9____T9__self__pos <= __k9____buffer_size ; 
 __k9____T9____1D____end :
 __k9____R9__pos = __k9____T9__self__pos ;
 if(! __k9____T9____1D__z )goto __k9____S9__while ;
 if(! segments__dynamic )goto __result__buffer_error ;
 __k9__segments__dynamic____buffer_alignment = 4 ;
 __k9__segments__dynamic____buffer_size = ((u64*) segments__dynamic )[1] ;
 if( __k9____T9__value >= __k9__segments__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(& __k9____X9 , &((u64*)((void**) segments__dynamic )[0])[ __k9____T9__value * __k9__segments__dynamic____buffer_alignment +0], sizeof( ptr )) ;
 memcpy(& __k9____Y9 , &((u64*)((void**) segments__dynamic )[0])[ __k9____T9__value * __k9__segments__dynamic____buffer_alignment +1], sizeof( u64 )) ;
 memcpy(& __k9____Z9 , &((u64*)((void**) segments__dynamic )[0])[ __k9____T9__value * __k9__segments__dynamic____buffer_alignment +2], sizeof( char )) ;
 memcpy(& __k9____a9 , &((u64*)((void**) segments__dynamic )[0])[ __k9____T9__value * __k9__segments__dynamic____buffer_alignment +3], sizeof( ptr )) ;
 __k9____b9 = " " ;
 __k9____c9____eb__length = strlen ( __k9____b9 ); __k9____c9____eb__contents =( ptr ) __k9____b9 ; __k9____c9____eb__first = __k9____b9 [0]; __k9____c9____eb__noptr =( ptr ) __k9____c9____eb__noptr ; 
 __k9____c9____eb____m__contents = __k9____c9____eb__contents ;
 __k9____c9__len_x = __k9____Y9 ; __k9____c9__len_y = __k9____c9____eb__length ; __k9____c9__total_len = __k9____c9__len_x + __k9____c9__len_y ; __k9____c9__first = __k9____Y9 ? __k9____Z9 : __k9____c9____eb__first ; 
 __k9____c9____fb = 1 ;
 __k9____c9____gb__z = __k9____c9__total_len + __k9____c9____fb ; 
 __k9____c9____gb____end :
 __k9____c9____hb = 0 ;
 __k9____c9____jb__size = __k9____c9____gb__z * sizeof ( __k9____c9____jb____IS ); 
 __k9____c9____jb____KS__x = __k9____P9__length ;
 __k9____c9____jb____KS__z = __k9____c9____jb____KS__x + __k9____c9____jb__size ; 
 __k9____c9____jb____KS____end :
 __k9____c9____jb____LS__z = __k9____c9____jb____KS__z > __k9____P9__contents__size ; 
 __k9____c9____jb____LS____end :
 if(! __k9____c9____jb____LS__z )goto __k9____c9____jb____JS__fi ;
 __k9____c9____jb____MS = "Failed an Arena allocation" ;
 goto __k9____c9____jb____NS____oD ;
 __builtin_unreachable();
 __k9____c9____jb____JS__fi :
 __k9____c9____jb___contents =( ptr )(( char *) __k9____P9__contents__mem + __k9____P9__length * sizeof ( char )); 
 __k9____P9__length = __k9____P9__length + __k9____c9____jb__size ; 
 __k9____c9____jb____RS = 0 ;
 __k9____c9____jb____TS__bytesize = sizeof ( __k9____c9____jb____TS____8E )* __k9____c9____jb__size ; 
 __k9____c9____jb____TS____end :
 memcpy (( char *) __k9____c9____jb___contents ,( char *) __k9____X9 , __k9____c9__len_x ); memcpy (( char *) __k9____c9____jb___contents + __k9____c9__len_x ,( char *) __k9____c9____eb____m__contents , __k9____c9__len_y );(( char *) __k9____c9____jb___contents )[ __k9____c9__total_len ]=0; 
 __k9____c9____mb__contents = __k9____c9____jb___contents ;
 __k9____P9__type = __k9____c9____jb__self__type ;
 __k9____P9__contents____5E = __k9____c9____jb__self__contents____5E ;
 __k9____P9__contents____6E____0E = __k9____c9____jb__self__contents____6E____0E ;
 __k9____d9__len_x = __k9__combined__length ; __k9____d9__len_y = __k9____c9__total_len ; __k9____d9__total_len = __k9____d9__len_x + __k9____d9__len_y ; __k9____d9__first = __k9__combined__length ? __k9__combined__first : __k9____c9__first ; 
 __k9____d9____Ri = 1 ;
 __k9____d9____Si__z = __k9____d9__total_len + __k9____d9____Ri ; 
 __k9____d9____Si____end :
 __k9____d9____Ti = 0 ;
 __k9____d9____Vi__size = __k9____d9____Si__z * sizeof ( __k9____d9____Vi____IS ); 
 __k9____d9____Vi____KS__x = __k9____P9__length ;
 __k9____d9____Vi____KS__z = __k9____d9____Vi____KS__x + __k9____d9____Vi__size ; 
 __k9____d9____Vi____KS____end :
 __k9____d9____Vi____LS__z = __k9____d9____Vi____KS__z > __k9____P9__contents__size ; 
 __k9____d9____Vi____LS____end :
 if(! __k9____d9____Vi____LS__z )goto __k9____d9____Vi____JS__fi ;
 __k9____d9____Vi____MS = "Failed an Arena allocation" ;
 goto __k9____d9____Vi____NS____oD ;
 __builtin_unreachable();
 __k9____d9____Vi____JS__fi :
 __k9____d9____Vi___contents =( ptr )(( char *) __k9____P9__contents__mem + __k9____P9__length * sizeof ( char )); 
 __k9____P9__length = __k9____P9__length + __k9____d9____Vi__size ; 
 __k9____d9____Vi____RS = 0 ;
 __k9____d9____Vi____TS__bytesize = sizeof ( __k9____d9____Vi____TS____8E )* __k9____d9____Vi__size ; 
 __k9____d9____Vi____TS____end :
 memcpy (( char *) __k9____d9____Vi___contents ,( char *) __k9__combined__contents , __k9____d9__len_x ); memcpy (( char *) __k9____d9____Vi___contents + __k9____d9__len_x ,( char *) __k9____c9____mb__contents , __k9____d9__len_y );(( char *) __k9____d9____Vi___contents )[ __k9____d9__total_len ]=0; 
 __k9____d9____Yi__contents = __k9____d9____Vi___contents ;
 __k9____P9__type = __k9____d9____Vi__self__type ;
 __k9____P9__contents____5E = __k9____d9____Vi__self__contents____5E ;
 __k9____P9__contents____6E____0E = __k9____d9____Vi__self__contents____6E____0E ;
 __k9__combined__contents = __k9____d9____Yi__contents ;
 __k9__combined__length = __k9____d9__total_len ;
 __k9__combined__first = __k9____d9__first ;
 __k9__combined__memory = __k9____P9__contents__underlying ;
 goto __k9____S9__loop ;
 __k9____S9__while :
 __TRANSIENT( __k9____P9__contents__mem )
 __l9__message__contents = __k9__combined__contents ;
 printf ( "%.*s\n" ,( int ) __k9__combined__length ,( char *) __l9__message__contents ); 
 __l9____end :
 __end :
goto __return;

// ERROR HANDLING
__k9____d9____Vi____NS____oD :
 printf ( "%s\n" , __k9____d9____Vi____MS ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__k9____c9____jb____NS____oD :
 printf ( "%s\n" , __k9____c9____jb____MS ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__k9____P9____GW____QI____uF____oD :
 printf ( "%s\n" , __k9____P9____GW____QI____tF ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__k9____P9____GW____QI____oF____oD :
 printf ( "%s\n" , __k9____P9____GW____QI____nF ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__result__buffer_error :
printf("Buffer error\n");
__result__errocode=__BUFFER__ERROR;
goto __failsafe;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
if( __f9__dynamic ){if((u64*)((u64*) __f9__dynamic )[2]) __runtime_free((u64*)((u64*) __f9__dynamic )[0]) ;
 __runtime_free( __f9__dynamic ) ;
 __f9__dynamic = 0 ;
 }__state->err =  __result__errocode;
}



int main() {
struct main__787__state __main_args={0};
__smolambda_initialize_service_tasks(main__787, &__main_args);
return __main_args.err;
}

