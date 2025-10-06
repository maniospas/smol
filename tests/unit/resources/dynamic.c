#define SMOLAMBDA_SERVICES 1
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

#include<stdlib.h>

#include<stdio.h>

#include<math.h>

struct main__590__state{errcode err;};
__externc void main__590(void *__void__state);

void main__590(void *__void__state){
errcode __result__errocode=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 4756;
struct main__590__state *__state=(struct main__590__state*)__void__state;
f64 __Sv____On__z=0;
f64 __Sv____Nn____Kn__z=0;
f64 __Sv____Nn____Jn=0;
f64 __Sv____Nn____Hn__z=0;
f64 __Rv=0;
u64 __Qv__self__circles__dynamic____buffer_size=0;
u64 __Qv__self__lookups__dynamic____buffer_size=0;
u64 __Qv__self__lookups__dynamic____buffer_alignment=0;
bool __Qv____Ls__z=0;
tag __Qv____Ks=0;
f64 __Ov__radius=0;
f64 __Kv=0;
u64 __Jv__shapes__squares__dynamic____buffer_size=0;
u64 __Jv__shapes__squares__dynamic____buffer_alignment=0;
u64 __Jv__shapes__types__dynamic____buffer_alignment=0;
tag __Fv____kq=0;
u64 __Fv__self__types__dynamic____buffer_size=0;
u64 __Fv__self__types__dynamic____buffer_alignment=0;
f64 __Dv__side=0;
bool __Av____1D__z=0;
u64 __Av____zD=0;
u64 __Av__value=0;
u64 __Av__self__pos=0;
u64 __Qv__self__circles__dynamic____buffer_alignment=0;
u64 __8u__pos=0;
u64 __8u__step=0;
u64 __8u__start=0;
u64 __8u__sup=0;
nominal __6u__shapes__memory____zO=0;
nominal __6u__shapes____Bp=0;
u64 __6u__shapes__types__dynamic____buffer_capacity=0;
u64 __6u__shapes__types__dynamic____buffer_size=0;
ptr __6u__shapes__lookups__dynamic____buffer_contents=0;
u64 __6u__shapes__lookups__dynamic____buffer_alignment=0;
f64 __4u=0;
nominal __1u__shapes____Bp=0;
u64 __1u__shapes__circles__dynamic____buffer_size=0;
u64 __1u__shapes__circles__dynamic____buffer_alignment=0;
u64 __1u__shapes__types__dynamic____buffer_capacity=0;
u64 __1u__shapes__types__dynamic____buffer_alignment=0;
ptr __1u__shapes__lookups__dynamic____buffer_contents=0;
u64 __1u__shapes__lookups__dynamic____buffer_capacity=0;
u64 __1u__shapes__lookups__dynamic____buffer_alignment=0;
nominal __wu__shapes____Bp=0;
u64 __wu__shapes__circles__dynamic____buffer_size=0;
u64 __wu__shapes__circles__dynamic____buffer_alignment=0;
ptr __wu__shapes__types__dynamic____buffer_contents=0;
bool __Fv____lq__z=0;
u64 __wu__shapes__types__dynamic____buffer_alignment=0;
ptr __wu__shapes__lookups__dynamic____buffer_contents=0;
u64 __6u__shapes__squares__dynamic____buffer_size=0;
u64 __wu____buffer_size=0;
f64 __uu=0;
ptr __1u__shapes__types__dynamic____buffer_contents=0;
nominal shapes__memory____zO=0;
nominal __ru__shapes____Bp=0;
nominal shapes____Bp=0;
ptr __ru__shapes__squares__dynamic____buffer_contents=0;
u64 __ru__shapes__squares__dynamic____buffer_alignment=0;
u64 __ru__shapes__types__dynamic____buffer_size=0;
u64 __ru__shapes__types__dynamic____buffer_alignment=0;
tag __ru____Ou=0;
ptr __ru__shapes__lookups__dynamic____buffer_contents=0;
f64 __Sv____Nn____In__z=0;
u64 __ru__shapes__lookups__dynamic____buffer_capacity=0;
u64 __ru__shapes__lookups__dynamic____buffer_alignment=0;
u64 __ru____buffer_size=0;
f64 __pu=0;
ptr shapes__lookups__dynamic=0;
ptr shapes__types__surface=0;
ptr shapes__types__dynamic=0;
ptr shapes__squares__dynamic=0;
u64 shapes__size=0;
u64 shapes__memory__allocated=0;
u64 shapes__memory__size=0;
ptr __mu____Rp__dynamic=0;
nominal __mu____Qp____NQ__self____zO=0;
char __mu____Qp____NQ____SP____OF=0;
u64 __mu____Qp____NQ____SP__bytesize=0;
cstr __mu____Qp____NQ____KP=0;
ptr __mu____Qp____NQ__mem=0;
u64 __1u__shapes__circles__dynamic____buffer_capacity=0;
ptr __mu____Qp____NQ__next_acquired=0;
u64 __mu____Qp____NQ__self__allocated__prev=0;
bool __mu____Qp____NQ__success=0;
u64 __mu____Qp____NQ__next_size=0;
bool __mu____Qp____NQ____EP=0;
char __mu____Qp____LQ=0;
ptr __mu____Np__dynamic=0;
u64 __mu____Mp____NQ____SP__bytesize=0;
bool __mu____Mp____NQ____JP__x=0;
char __mu____Mp____NQ____CP=0;
ptr __mu____Mp____NQ__next_acquired=0;
u64 __mu____Mp____NQ__self__allocated__prev=0;
bool __mu____Mp____NQ__success=0;
u64 __mu____Mp____NQ__next_size=0;
nominal __1u__shapes__memory____zO=0;
char __mu____Mp____LQ=0;
u64 __wu__shapes__types__dynamic____buffer_capacity=0;
nominal __mu____Ip____NQ__self____zO=0;
char __mu____Ip____NQ____SP____OF=0;
u64 __mu____Ip____NQ____SP__bytesize=0;
char __mu____Ip____NQ____QP=0;
cstr __mu____Ip____NQ____KP=0;
bool __mu____Ip____NQ____JP__z=0;
u64 __mu____Ip____NQ__self__allocated__prev=0;
u64 __mu____Hp__z=0;
u64 __mu____Gp=0;
ptr __mu____Fp__dynamic=0;
tag __Qv____Is=0;
u64 __6u__shapes__types__dynamic____buffer_alignment=0;
nominal __mu____Ep____NQ__self____zO=0;
char __mu____Ep____NQ____SP____OF=0;
u64 __mu____Ep____NQ____SP__bytesize=0;
char __mu____Ep____NQ____QP=0;
cstr __mu____Ep____NQ____KP=0;
bool __mu____Ep____NQ____JP__x=0;
char __mu____Ep____NQ____CP=0;
cstr __mu____Qp____NQ____GP=0;
ptr __mu____Ep____NQ__next_acquired=0;
u64 __mu____Ep____NQ__self__allocated__prev=0;
cstr __mu____Ep____NQ____GP=0;
bool __mu____Ep____NQ____EP=0;
u64 __ru__shapes__squares__dynamic____buffer_capacity=0;
u64 __mu____Cp=0;
u64 __mu__memory____dynamic_entry=0;
u64 __mu__memory__allocated=0;
ptr __mu__memory__acquired=0;
u64 __lu=0;
u64 __ku____5O____dynamic_entry=0;
u64 __ku__allocated=0;
ptr __mu__circles__dynamic=0;
tag __1u____eu=0;
nominal __wu__shapes__memory____zO=0;
u64 __Qv__self__types__dynamic____buffer_size=0;
u64 __1u____buffer_size=0;
u64 i=0;
u64 __6u__shapes__squares__dynamic____buffer_capacity=0;
u64 __mu__memory__size=0;
u64 __ku____5O____1O=0;
u64 __wu__shapes__lookups__dynamic____buffer_size=0;
u64 __ku__size=0;
cstr __Jv____3t=0;
ptr shapes__circles__surface=0;
bool __mu____Mp____NQ____FP__z=0;
bool __mu____Mp____NQ____EP=0;
u64 __7u____buffer_size=0;
tag __wu____eu=0;
u64 __mu____Pp__z=0;
u64 __1u__shapes__types__dynamic____buffer_size=0;
f64 __Qv____Ss=0;
bool __mu____Ip____NQ____EP=0;
ptr __mu__lookups__dynamic=0;
u64 __ru__shapes__types__dynamic____buffer_capacity=0;
cstr __Qv____Ms=0;
tag __6u____Ou=0;
ptr shapes__circles__dynamic=0;
f64 __Jv____9t=0;
char __mu____Mp____NQ____QP=0;
bool __mu____Qp____NQ____JP__x=0;
u64 __mu____Kp=0;
u64 __ru__shapes__lookups__dynamic____buffer_size=0;
f64 __Lv____Qn__z=0;
ptr __mu__types__dynamic=0;
u64 __1u__shapes__lookups__dynamic____buffer_size=0;
bool __mu____Mp____NQ____JP__z=0;
bool __mu____Ip____NQ__success=0;
bool __Jv____2t__z=0;
f64 __Hv__side=0;
ptr __mu____Ep____NQ__mem=0;
u64 __mu____Op=0;
ptr __mu____Ip____NQ__next_acquired=0;
ptr __wu__shapes__circles__dynamic____buffer_contents=0;
bool __mu____Qp____NQ____JP__z=0;
u64 __6u__shapes__squares__dynamic____buffer_alignment=0;
u64 __Jv__shapes__types__dynamic____buffer_size=0;
u64 __Qv__self__types__dynamic____buffer_alignment=0;
bool __mu____Ep____NQ__success=0;
u64 __6u__shapes__lookups__dynamic____buffer_size=0;
cstr __mu____Mp____NQ____KP=0;
ptr __mu__squares__dynamic=0;
u64 __Jv____6t=0;
u64 __mu____Lp__z=0;
nominal __mu__memory____zO=0;
bool __mu____Qp____NQ____FP__z=0;
u64 __6u__shapes__lookups__dynamic____buffer_capacity=0;
bool __mu____Ep____NQ____FP__z=0;
ptr __mu____Ip____NQ__mem=0;
u64 __mu____Dp__z=0;
u64 __wu__shapes__circles__dynamic____buffer_capacity=0;
ptr __1u__shapes__circles__dynamic____buffer_contents=0;
cstr __mu____Mp____NQ____GP=0;
bool __mu____Ep____NQ____JP__z=0;
char __mu____Qp____NQ____CP=0;
char __mu____Mp____NQ____SP____OF=0;
bool __mu____Ip____NQ____JP__x=0;
tag __Jv____zt=0;
char __mu____Ip____NQ____CP=0;
nominal __mu____Mp____NQ__self____zO=0;
f64 __zu=0;
ptr __mu____Jp__dynamic=0;
u64 __ku____dynamic_entry=0;
f64 __Lv____Pn____Mn__z=0;
char __mu____Ep____LQ=0;
u64 __ru__shapes__squares__dynamic____buffer_size=0;
u64 __mu____Ep____NQ__next_size=0;
nominal __ru__shapes__memory____zO=0;
ptr __ru__shapes__types__dynamic____buffer_contents=0;
bool __mu____Ip____NQ____FP__z=0;
char __mu____Ip____LQ=0;
ptr __ku____5O__acquired=0;
u64 __Jv__shapes__lookups__dynamic____buffer_alignment=0;
ptr __ku__acquired=0;
u64 __8u____wD=0;
char __mu____Qp____NQ____QP=0;
ptr __6u__shapes__types__dynamic____buffer_contents=0;
tag __Fv____jq=0;
ptr shapes__squares__surface=0;
u64 __mu____Ip____NQ__next_size=0;
u64 __wu__shapes__lookups__dynamic____buffer_capacity=0;
ptr shapes__lookups__surface=0;
ptr __6u__shapes__squares__dynamic____buffer_contents=0;
u64 __6u____buffer_size=0;
u64 __ku____5O____0O=0;
tag __Jv____1t=0;
u64 __Av____0D__z=0;
ptr shapes__memory__acquired=0;
u64 __8u____xD=0;
u64 shapes__memory____dynamic_entry=0;
ptr __mu____Mp____NQ__mem=0;
u64 __Jv__shapes__lookups__dynamic____buffer_size=0;
u64 __Qv____Ps=0;
cstr __mu____Ip____NQ____GP=0;
u64 __wu__shapes__lookups__dynamic____buffer_alignment=0;
u64 __wu__shapes__types__dynamic____buffer_size=0;

// IMPLEMENTATION
__ku____5O__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __ku____5O__acquired )(( ptr **) __ku____5O__acquired )[0]=0; 
 __ku____5O____0O = 0 ;
 __ku____5O____1O = 0 ;
 __ku__acquired = __ku____5O__acquired ;
 __ku__size = __ku____5O____0O ;
 __ku__allocated = __ku____5O____1O ;
 __ku____dynamic_entry = __ku____5O____dynamic_entry ;
 __lu = 1024 ;
 __mu__memory__acquired = __ku__acquired ;
 __mu__memory__size = __ku__size ;
 __mu__memory__allocated = __ku__allocated ;
 __mu__memory____dynamic_entry = __ku____dynamic_entry ;
 __mu____Cp = 4 ;
 __mu____Dp__z = __lu * __mu____Cp ; 
 __mu____Dp____end :
 __mu____Ep____LQ = 0 ;
 __mu____Ep____NQ____EP = __mu__memory__acquired ;
 __mu____Ep____NQ____FP__z =(! __mu____Ep____NQ____EP ); 
 __mu____Ep____NQ____FP____end :
 if(! __mu____Ep____NQ____FP__z )goto __mu____Ep____NQ____DP__fi ;
 __mu____Ep____NQ____GP = "Did not initialize Dynamic" ;
 goto __mu____Ep____NQ____HP____oD ;
 __builtin_unreachable();
 __mu____Ep____NQ____DP__fi :
 __mu____Ep____NQ__next_size = __mu__memory__size +1; __mu____Ep____NQ__success = true ; __mu____Ep____NQ__self__allocated__prev = __mu__memory__allocated ; if ( __mu____Ep____NQ__next_size >= __mu__memory__allocated ) { __mu__memory__allocated = __mu__memory__allocated + __mu__memory__allocated /2+1; __mu____Ep____NQ__next_acquired =( ptr )((( ptr **) __mu__memory__acquired )[0]? __runtime_realloc ((( ptr **) __mu__memory__acquired )[0], __mu__memory__allocated * sizeof ( ptr ), __mu____Ep____NQ__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __mu__memory__allocated * sizeof ( ptr ))); if ( __mu____Ep____NQ__success = __mu____Ep____NQ__next_acquired )(( ptr **) __mu__memory__acquired )[0]=( ptr *) __mu____Ep____NQ__next_acquired ; } if ( __mu____Ep____NQ__success ) { __mu____Ep____NQ__mem =( ptr ) __runtime_alloc ( __mu____Dp__z * sizeof ( __mu____Ep____NQ____CP )); if ( __mu____Ep____NQ__success = __mu____Ep____NQ__mem ) {(( ptr **) __mu__memory__acquired )[0][ __mu__memory__size ]= __mu____Ep____NQ__mem ; __mu__memory__size = __mu____Ep____NQ__next_size ; } } 
 __mu____Ep____NQ____JP__x = __mu____Ep____NQ__success ;
 __mu____Ep____NQ____JP__z =(! __mu____Ep____NQ____JP__x ); 
 __mu____Ep____NQ____JP____end :
 if(! __mu____Ep____NQ____JP__z )goto __mu____Ep____NQ____IP__fi ;
 __mu____Ep____NQ____KP = "Failed a Dynamic allocation" ;
 goto __mu____Ep____NQ____LP____oD ;
 __builtin_unreachable();
 __mu____Ep____NQ____IP__fi :
 __mu____Ep____NQ____QP = 0 ;
 __mu____Ep____NQ____SP__bytesize = sizeof ( __mu____Ep____NQ____SP____OF )* __mu____Dp__z ; 
 __mu____Ep____NQ____SP____end :
 __mu__memory____zO = __mu____Ep____NQ__self____zO ;
 __mu____Fp__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 ((u64*) __mu____Fp__dynamic )[0] = (u64)(u64*) __mu____Ep____NQ__mem ;
 ((u64*) __mu____Fp__dynamic )[2] = ( __mu____Ep____NQ____SP__bytesize /(sizeof(u64)*1)) | (1ULL <<63) ;
 __mu__squares__dynamic = __mu____Fp__dynamic ;
 __mu____Gp = 4 ;
 __mu____Hp__z = __lu * __mu____Gp ; 
 __mu____Hp____end :
 __mu____Ip____LQ = 0 ;
 __mu____Ip____NQ____EP = __mu__memory__acquired ;
 __mu____Ip____NQ____FP__z =(! __mu____Ip____NQ____EP ); 
 __mu____Ip____NQ____FP____end :
 if(! __mu____Ip____NQ____FP__z )goto __mu____Ip____NQ____DP__fi ;
 __mu____Ip____NQ____GP = "Did not initialize Dynamic" ;
 goto __mu____Ip____NQ____HP____oD ;
 __builtin_unreachable();
 __mu____Ip____NQ____DP__fi :
 __mu____Ip____NQ__next_size = __mu__memory__size +1; __mu____Ip____NQ__success = true ; __mu____Ip____NQ__self__allocated__prev = __mu__memory__allocated ; if ( __mu____Ip____NQ__next_size >= __mu__memory__allocated ) { __mu__memory__allocated = __mu__memory__allocated + __mu__memory__allocated /2+1; __mu____Ip____NQ__next_acquired =( ptr )((( ptr **) __mu__memory__acquired )[0]? __runtime_realloc ((( ptr **) __mu__memory__acquired )[0], __mu__memory__allocated * sizeof ( ptr ), __mu____Ip____NQ__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __mu__memory__allocated * sizeof ( ptr ))); if ( __mu____Ip____NQ__success = __mu____Ip____NQ__next_acquired )(( ptr **) __mu__memory__acquired )[0]=( ptr *) __mu____Ip____NQ__next_acquired ; } if ( __mu____Ip____NQ__success ) { __mu____Ip____NQ__mem =( ptr ) __runtime_alloc ( __mu____Hp__z * sizeof ( __mu____Ip____NQ____CP )); if ( __mu____Ip____NQ__success = __mu____Ip____NQ__mem ) {(( ptr **) __mu__memory__acquired )[0][ __mu__memory__size ]= __mu____Ip____NQ__mem ; __mu__memory__size = __mu____Ip____NQ__next_size ; } } 
 __mu____Ip____NQ____JP__x = __mu____Ip____NQ__success ;
 __mu____Ip____NQ____JP__z =(! __mu____Ip____NQ____JP__x ); 
 __mu____Ip____NQ____JP____end :
 if(! __mu____Ip____NQ____JP__z )goto __mu____Ip____NQ____IP__fi ;
 __mu____Ip____NQ____KP = "Failed a Dynamic allocation" ;
 goto __mu____Ip____NQ____LP____oD ;
 __builtin_unreachable();
 __mu____Ip____NQ____IP__fi :
 __mu____Ip____NQ____QP = 0 ;
 __mu____Ip____NQ____SP__bytesize = sizeof ( __mu____Ip____NQ____SP____OF )* __mu____Hp__z ; 
 __mu____Ip____NQ____SP____end :
 __mu__memory____zO = __mu____Ip____NQ__self____zO ;
 __mu____Jp__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 ((u64*) __mu____Jp__dynamic )[0] = (u64)(u64*) __mu____Ip____NQ__mem ;
 ((u64*) __mu____Jp__dynamic )[2] = ( __mu____Ip____NQ____SP__bytesize /(sizeof(u64)*1)) | (1ULL <<63) ;
 __mu__circles__dynamic = __mu____Jp__dynamic ;
 __mu____Kp = 8 ;
 __mu____Lp__z = __lu * __mu____Kp ; 
 __mu____Lp____end :
 __mu____Mp____LQ = 0 ;
 __mu____Mp____NQ____EP = __mu__memory__acquired ;
 __mu____Mp____NQ____FP__z =(! __mu____Mp____NQ____EP ); 
 __mu____Mp____NQ____FP____end :
 if(! __mu____Mp____NQ____FP__z )goto __mu____Mp____NQ____DP__fi ;
 __mu____Mp____NQ____GP = "Did not initialize Dynamic" ;
 goto __mu____Mp____NQ____HP____oD ;
 __builtin_unreachable();
 __mu____Mp____NQ____DP__fi :
 __mu____Mp____NQ__next_size = __mu__memory__size +1; __mu____Mp____NQ__success = true ; __mu____Mp____NQ__self__allocated__prev = __mu__memory__allocated ; if ( __mu____Mp____NQ__next_size >= __mu__memory__allocated ) { __mu__memory__allocated = __mu__memory__allocated + __mu__memory__allocated /2+1; __mu____Mp____NQ__next_acquired =( ptr )((( ptr **) __mu__memory__acquired )[0]? __runtime_realloc ((( ptr **) __mu__memory__acquired )[0], __mu__memory__allocated * sizeof ( ptr ), __mu____Mp____NQ__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __mu__memory__allocated * sizeof ( ptr ))); if ( __mu____Mp____NQ__success = __mu____Mp____NQ__next_acquired )(( ptr **) __mu__memory__acquired )[0]=( ptr *) __mu____Mp____NQ__next_acquired ; } if ( __mu____Mp____NQ__success ) { __mu____Mp____NQ__mem =( ptr ) __runtime_alloc ( __mu____Lp__z * sizeof ( __mu____Mp____NQ____CP )); if ( __mu____Mp____NQ__success = __mu____Mp____NQ__mem ) {(( ptr **) __mu__memory__acquired )[0][ __mu__memory__size ]= __mu____Mp____NQ__mem ; __mu__memory__size = __mu____Mp____NQ__next_size ; } } 
 __mu____Mp____NQ____JP__x = __mu____Mp____NQ__success ;
 __mu____Mp____NQ____JP__z =(! __mu____Mp____NQ____JP__x ); 
 __mu____Mp____NQ____JP____end :
 if(! __mu____Mp____NQ____JP__z )goto __mu____Mp____NQ____IP__fi ;
 __mu____Mp____NQ____KP = "Failed a Dynamic allocation" ;
 goto __mu____Mp____NQ____LP____oD ;
 __builtin_unreachable();
 __mu____Mp____NQ____IP__fi :
 __mu____Mp____NQ____QP = 0 ;
 __mu____Mp____NQ____SP__bytesize = sizeof ( __mu____Mp____NQ____SP____OF )* __mu____Lp__z ; 
 __mu____Mp____NQ____SP____end :
 __mu__memory____zO = __mu____Mp____NQ__self____zO ;
 __mu____Np__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 ((u64*) __mu____Np__dynamic )[0] = (u64)(u64*) __mu____Mp____NQ__mem ;
 ((u64*) __mu____Np__dynamic )[2] = ( __mu____Mp____NQ____SP__bytesize /(sizeof(u64)*1)) | (1ULL <<63) ;
 __mu__types__dynamic = __mu____Np__dynamic ;
 __mu____Op = 8 ;
 __mu____Pp__z = __lu * __mu____Op ; 
 __mu____Pp____end :
 __mu____Qp____LQ = 0 ;
 __mu____Qp____NQ____EP = __mu__memory__acquired ;
 __mu____Qp____NQ____FP__z =(! __mu____Qp____NQ____EP ); 
 __mu____Qp____NQ____FP____end :
 if(! __mu____Qp____NQ____FP__z )goto __mu____Qp____NQ____DP__fi ;
 __mu____Qp____NQ____GP = "Did not initialize Dynamic" ;
 goto __mu____Qp____NQ____HP____oD ;
 __builtin_unreachable();
 __mu____Qp____NQ____DP__fi :
 __mu____Qp____NQ__next_size = __mu__memory__size +1; __mu____Qp____NQ__success = true ; __mu____Qp____NQ__self__allocated__prev = __mu__memory__allocated ; if ( __mu____Qp____NQ__next_size >= __mu__memory__allocated ) { __mu__memory__allocated = __mu__memory__allocated + __mu__memory__allocated /2+1; __mu____Qp____NQ__next_acquired =( ptr )((( ptr **) __mu__memory__acquired )[0]? __runtime_realloc ((( ptr **) __mu__memory__acquired )[0], __mu__memory__allocated * sizeof ( ptr ), __mu____Qp____NQ__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __mu__memory__allocated * sizeof ( ptr ))); if ( __mu____Qp____NQ__success = __mu____Qp____NQ__next_acquired )(( ptr **) __mu__memory__acquired )[0]=( ptr *) __mu____Qp____NQ__next_acquired ; } if ( __mu____Qp____NQ__success ) { __mu____Qp____NQ__mem =( ptr ) __runtime_alloc ( __mu____Pp__z * sizeof ( __mu____Qp____NQ____CP )); if ( __mu____Qp____NQ__success = __mu____Qp____NQ__mem ) {(( ptr **) __mu__memory__acquired )[0][ __mu__memory__size ]= __mu____Qp____NQ__mem ; __mu__memory__size = __mu____Qp____NQ__next_size ; } } 
 __mu____Qp____NQ____JP__x = __mu____Qp____NQ__success ;
 __mu____Qp____NQ____JP__z =(! __mu____Qp____NQ____JP__x ); 
 __mu____Qp____NQ____JP____end :
 if(! __mu____Qp____NQ____JP__z )goto __mu____Qp____NQ____IP__fi ;
 __mu____Qp____NQ____KP = "Failed a Dynamic allocation" ;
 goto __mu____Qp____NQ____LP____oD ;
 __builtin_unreachable();
 __mu____Qp____NQ____IP__fi :
 __mu____Qp____NQ____QP = 0 ;
 __mu____Qp____NQ____SP__bytesize = sizeof ( __mu____Qp____NQ____SP____OF )* __mu____Pp__z ; 
 __mu____Qp____NQ____SP____end :
 __mu__memory____zO = __mu____Qp____NQ__self____zO ;
 __mu____Rp__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 ((u64*) __mu____Rp__dynamic )[0] = (u64)(u64*) __mu____Qp____NQ__mem ;
 ((u64*) __mu____Rp__dynamic )[2] = ( __mu____Qp____NQ____SP__bytesize /(sizeof(u64)*1)) | (1ULL <<63) ;
 __mu__lookups__dynamic = __mu____Rp__dynamic ;
 __ku__acquired = __mu__memory__acquired ;
 __ku__size = __mu__memory__size ;
 __ku__allocated = __mu__memory__allocated ;
 __ku____dynamic_entry = __mu__memory____dynamic_entry ;
 shapes__memory__acquired = __mu__memory__acquired ;
 shapes__memory__size = __mu__memory__size ;
 shapes__memory__allocated = __mu__memory__allocated ;
 shapes__memory____dynamic_entry = __mu__memory____dynamic_entry ;
 shapes__size = __lu ;
 shapes__squares__dynamic = __mu__squares__dynamic ;
 shapes__squares__surface = __mu__memory__acquired ;
 shapes__circles__dynamic = __mu__circles__dynamic ;
 shapes__circles__surface = __mu__memory__acquired ;
 shapes__types__dynamic = __mu__types__dynamic ;
 shapes__types__surface = __mu__memory__acquired ;
 shapes__lookups__dynamic = __mu__lookups__dynamic ;
 shapes__lookups__surface = __mu__memory__acquired ;
 __pu = 1.0 ;
 __ru____buffer_size = shapes__squares__dynamic ? ((u64*) shapes__squares__dynamic )[1]:0 ;
 if(! shapes__lookups__dynamic )goto __result__buffer_error ;
 __ru__shapes__lookups__dynamic____buffer_alignment = 1 ;
 __ru__shapes__lookups__dynamic____buffer_size = ((u64*) shapes__lookups__dynamic )[1] ;
 __ru__shapes__lookups__dynamic____buffer_capacity = ((u64*) shapes__lookups__dynamic )[2] & ~(1ULL << 63) ;
 if( __ru__shapes__lookups__dynamic____buffer_size >= __ru__shapes__lookups__dynamic____buffer_capacity ){ if( ((u64*) shapes__lookups__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __ru__shapes__lookups__dynamic____buffer_capacity = __ru__shapes__lookups__dynamic____buffer_capacity +( __ru__shapes__lookups__dynamic____buffer_capacity >>2)+1; if( __ru__shapes__lookups__dynamic____buffer_size ) ((void**) shapes__lookups__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__lookups__dynamic )[0],  __ru__shapes__lookups__dynamic____buffer_capacity * __ru__shapes__lookups__dynamic____buffer_alignment *sizeof(u64),  __ru__shapes__lookups__dynamic____buffer_capacity * __ru__shapes__lookups__dynamic____buffer_alignment *sizeof(u64)); else ((void**) shapes__lookups__dynamic )[0] = __runtime_alloc( __ru__shapes__lookups__dynamic____buffer_capacity * __ru__shapes__lookups__dynamic____buffer_alignment *sizeof(u64)); ((u64*) shapes__lookups__dynamic )[2] = __ru__shapes__lookups__dynamic____buffer_capacity ;
 __ru__shapes__lookups__dynamic____buffer_contents = (ptr)((void**) shapes__lookups__dynamic )[0] ;
 if( ! __ru__shapes__lookups__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  __ru__shapes__lookups__dynamic____buffer_contents = (ptr)(((u64*) shapes__lookups__dynamic )[0]) ;
 ((u64*) shapes__lookups__dynamic )[1] = __ru__shapes__lookups__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __ru__shapes__lookups__dynamic____buffer_contents )[ __ru__shapes__lookups__dynamic____buffer_size * __ru__shapes__lookups__dynamic____buffer_alignment ], & __ru____buffer_size , sizeof(u64)); __ru____Ou = 3 ;
 if(! shapes__types__dynamic )goto __result__buffer_error ;
 __ru__shapes__types__dynamic____buffer_alignment = 1 ;
 __ru__shapes__types__dynamic____buffer_size = ((u64*) shapes__types__dynamic )[1] ;
 __ru__shapes__types__dynamic____buffer_capacity = ((u64*) shapes__types__dynamic )[2] & ~(1ULL << 63) ;
 if( __ru__shapes__types__dynamic____buffer_size >= __ru__shapes__types__dynamic____buffer_capacity ){ if( ((u64*) shapes__types__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __ru__shapes__types__dynamic____buffer_capacity = __ru__shapes__types__dynamic____buffer_capacity +( __ru__shapes__types__dynamic____buffer_capacity >>2)+1; if( __ru__shapes__types__dynamic____buffer_size ) ((void**) shapes__types__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__types__dynamic )[0],  __ru__shapes__types__dynamic____buffer_capacity * __ru__shapes__types__dynamic____buffer_alignment *sizeof(u64),  __ru__shapes__types__dynamic____buffer_capacity * __ru__shapes__types__dynamic____buffer_alignment *sizeof(u64)); else ((void**) shapes__types__dynamic )[0] = __runtime_alloc( __ru__shapes__types__dynamic____buffer_capacity * __ru__shapes__types__dynamic____buffer_alignment *sizeof(u64)); ((u64*) shapes__types__dynamic )[2] = __ru__shapes__types__dynamic____buffer_capacity ;
 __ru__shapes__types__dynamic____buffer_contents = (ptr)((void**) shapes__types__dynamic )[0] ;
 if( ! __ru__shapes__types__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  __ru__shapes__types__dynamic____buffer_contents = (ptr)(((u64*) shapes__types__dynamic )[0]) ;
 ((u64*) shapes__types__dynamic )[1] = __ru__shapes__types__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __ru__shapes__types__dynamic____buffer_contents )[ __ru__shapes__types__dynamic____buffer_size * __ru__shapes__types__dynamic____buffer_alignment ], & __ru____Ou , sizeof(u64)); if(! shapes__squares__dynamic )goto __result__buffer_error ;
 __ru__shapes__squares__dynamic____buffer_alignment = 1 ;
 __ru__shapes__squares__dynamic____buffer_size = ((u64*) shapes__squares__dynamic )[1] ;
 __ru__shapes__squares__dynamic____buffer_capacity = ((u64*) shapes__squares__dynamic )[2] & ~(1ULL << 63) ;
 if( __ru__shapes__squares__dynamic____buffer_size >= __ru__shapes__squares__dynamic____buffer_capacity ){ if( ((u64*) shapes__squares__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __ru__shapes__squares__dynamic____buffer_capacity = __ru__shapes__squares__dynamic____buffer_capacity +( __ru__shapes__squares__dynamic____buffer_capacity >>2)+1; if( __ru__shapes__squares__dynamic____buffer_size ) ((void**) shapes__squares__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__squares__dynamic )[0],  __ru__shapes__squares__dynamic____buffer_capacity * __ru__shapes__squares__dynamic____buffer_alignment *sizeof(u64),  __ru__shapes__squares__dynamic____buffer_capacity * __ru__shapes__squares__dynamic____buffer_alignment *sizeof(u64)); else ((void**) shapes__squares__dynamic )[0] = __runtime_alloc( __ru__shapes__squares__dynamic____buffer_capacity * __ru__shapes__squares__dynamic____buffer_alignment *sizeof(u64)); ((u64*) shapes__squares__dynamic )[2] = __ru__shapes__squares__dynamic____buffer_capacity ;
 __ru__shapes__squares__dynamic____buffer_contents = (ptr)((void**) shapes__squares__dynamic )[0] ;
 if( ! __ru__shapes__squares__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  __ru__shapes__squares__dynamic____buffer_contents = (ptr)(((u64*) shapes__squares__dynamic )[0]) ;
 ((u64*) shapes__squares__dynamic )[1] = __ru__shapes__squares__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __ru__shapes__squares__dynamic____buffer_contents )[ __ru__shapes__squares__dynamic____buffer_size * __ru__shapes__squares__dynamic____buffer_alignment +0], & __pu , sizeof(f64)); __ru____end :
 shapes____Bp = __ru__shapes____Bp ;
 shapes__memory____zO = __ru__shapes__memory____zO ;
 __uu = 1.0 ;
 __wu____buffer_size = shapes__circles__dynamic ? ((u64*) shapes__circles__dynamic )[1]:0 ;
 if(! shapes__lookups__dynamic )goto __result__buffer_error ;
 __wu__shapes__lookups__dynamic____buffer_alignment = 1 ;
 __wu__shapes__lookups__dynamic____buffer_size = ((u64*) shapes__lookups__dynamic )[1] ;
 __wu__shapes__lookups__dynamic____buffer_capacity = ((u64*) shapes__lookups__dynamic )[2] & ~(1ULL << 63) ;
 if( __wu__shapes__lookups__dynamic____buffer_size >= __wu__shapes__lookups__dynamic____buffer_capacity ){ if( ((u64*) shapes__lookups__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __wu__shapes__lookups__dynamic____buffer_capacity = __wu__shapes__lookups__dynamic____buffer_capacity +( __wu__shapes__lookups__dynamic____buffer_capacity >>2)+1; if( __wu__shapes__lookups__dynamic____buffer_size ) ((void**) shapes__lookups__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__lookups__dynamic )[0],  __wu__shapes__lookups__dynamic____buffer_capacity * __wu__shapes__lookups__dynamic____buffer_alignment *sizeof(u64),  __wu__shapes__lookups__dynamic____buffer_capacity * __wu__shapes__lookups__dynamic____buffer_alignment *sizeof(u64)); else ((void**) shapes__lookups__dynamic )[0] = __runtime_alloc( __wu__shapes__lookups__dynamic____buffer_capacity * __wu__shapes__lookups__dynamic____buffer_alignment *sizeof(u64)); ((u64*) shapes__lookups__dynamic )[2] = __wu__shapes__lookups__dynamic____buffer_capacity ;
 __wu__shapes__lookups__dynamic____buffer_contents = (ptr)((void**) shapes__lookups__dynamic )[0] ;
 if( ! __wu__shapes__lookups__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  __wu__shapes__lookups__dynamic____buffer_contents = (ptr)(((u64*) shapes__lookups__dynamic )[0]) ;
 ((u64*) shapes__lookups__dynamic )[1] = __wu__shapes__lookups__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __wu__shapes__lookups__dynamic____buffer_contents )[ __wu__shapes__lookups__dynamic____buffer_size * __wu__shapes__lookups__dynamic____buffer_alignment ], & __wu____buffer_size , sizeof(u64)); __wu____eu = 2 ;
 if(! shapes__types__dynamic )goto __result__buffer_error ;
 __wu__shapes__types__dynamic____buffer_alignment = 1 ;
 __wu__shapes__types__dynamic____buffer_size = ((u64*) shapes__types__dynamic )[1] ;
 __wu__shapes__types__dynamic____buffer_capacity = ((u64*) shapes__types__dynamic )[2] & ~(1ULL << 63) ;
 if( __wu__shapes__types__dynamic____buffer_size >= __wu__shapes__types__dynamic____buffer_capacity ){ if( ((u64*) shapes__types__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __wu__shapes__types__dynamic____buffer_capacity = __wu__shapes__types__dynamic____buffer_capacity +( __wu__shapes__types__dynamic____buffer_capacity >>2)+1; if( __wu__shapes__types__dynamic____buffer_size ) ((void**) shapes__types__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__types__dynamic )[0],  __wu__shapes__types__dynamic____buffer_capacity * __wu__shapes__types__dynamic____buffer_alignment *sizeof(u64),  __wu__shapes__types__dynamic____buffer_capacity * __wu__shapes__types__dynamic____buffer_alignment *sizeof(u64)); else ((void**) shapes__types__dynamic )[0] = __runtime_alloc( __wu__shapes__types__dynamic____buffer_capacity * __wu__shapes__types__dynamic____buffer_alignment *sizeof(u64)); ((u64*) shapes__types__dynamic )[2] = __wu__shapes__types__dynamic____buffer_capacity ;
 __wu__shapes__types__dynamic____buffer_contents = (ptr)((void**) shapes__types__dynamic )[0] ;
 if( ! __wu__shapes__types__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  __wu__shapes__types__dynamic____buffer_contents = (ptr)(((u64*) shapes__types__dynamic )[0]) ;
 ((u64*) shapes__types__dynamic )[1] = __wu__shapes__types__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __wu__shapes__types__dynamic____buffer_contents )[ __wu__shapes__types__dynamic____buffer_size * __wu__shapes__types__dynamic____buffer_alignment ], & __wu____eu , sizeof(u64)); if(! shapes__circles__dynamic )goto __result__buffer_error ;
 __wu__shapes__circles__dynamic____buffer_alignment = 1 ;
 __wu__shapes__circles__dynamic____buffer_size = ((u64*) shapes__circles__dynamic )[1] ;
 __wu__shapes__circles__dynamic____buffer_capacity = ((u64*) shapes__circles__dynamic )[2] & ~(1ULL << 63) ;
 if( __wu__shapes__circles__dynamic____buffer_size >= __wu__shapes__circles__dynamic____buffer_capacity ){ if( ((u64*) shapes__circles__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __wu__shapes__circles__dynamic____buffer_capacity = __wu__shapes__circles__dynamic____buffer_capacity +( __wu__shapes__circles__dynamic____buffer_capacity >>2)+1; if( __wu__shapes__circles__dynamic____buffer_size ) ((void**) shapes__circles__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__circles__dynamic )[0],  __wu__shapes__circles__dynamic____buffer_capacity * __wu__shapes__circles__dynamic____buffer_alignment *sizeof(u64),  __wu__shapes__circles__dynamic____buffer_capacity * __wu__shapes__circles__dynamic____buffer_alignment *sizeof(u64)); else ((void**) shapes__circles__dynamic )[0] = __runtime_alloc( __wu__shapes__circles__dynamic____buffer_capacity * __wu__shapes__circles__dynamic____buffer_alignment *sizeof(u64)); ((u64*) shapes__circles__dynamic )[2] = __wu__shapes__circles__dynamic____buffer_capacity ;
 __wu__shapes__circles__dynamic____buffer_contents = (ptr)((void**) shapes__circles__dynamic )[0] ;
 if( ! __wu__shapes__circles__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  __wu__shapes__circles__dynamic____buffer_contents = (ptr)(((u64*) shapes__circles__dynamic )[0]) ;
 ((u64*) shapes__circles__dynamic )[1] = __wu__shapes__circles__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __wu__shapes__circles__dynamic____buffer_contents )[ __wu__shapes__circles__dynamic____buffer_size * __wu__shapes__circles__dynamic____buffer_alignment +0], & __uu , sizeof(f64)); __wu____end :
 shapes____Bp = __wu__shapes____Bp ;
 shapes__memory____zO = __wu__shapes__memory____zO ;
 __zu = 2.0 ;
 __1u____buffer_size = shapes__circles__dynamic ? ((u64*) shapes__circles__dynamic )[1]:0 ;
 if(! shapes__lookups__dynamic )goto __result__buffer_error ;
 __1u__shapes__lookups__dynamic____buffer_alignment = 1 ;
 __1u__shapes__lookups__dynamic____buffer_size = ((u64*) shapes__lookups__dynamic )[1] ;
 __1u__shapes__lookups__dynamic____buffer_capacity = ((u64*) shapes__lookups__dynamic )[2] & ~(1ULL << 63) ;
 if( __1u__shapes__lookups__dynamic____buffer_size >= __1u__shapes__lookups__dynamic____buffer_capacity ){ if( ((u64*) shapes__lookups__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __1u__shapes__lookups__dynamic____buffer_capacity = __1u__shapes__lookups__dynamic____buffer_capacity +( __1u__shapes__lookups__dynamic____buffer_capacity >>2)+1; if( __1u__shapes__lookups__dynamic____buffer_size ) ((void**) shapes__lookups__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__lookups__dynamic )[0],  __1u__shapes__lookups__dynamic____buffer_capacity * __1u__shapes__lookups__dynamic____buffer_alignment *sizeof(u64),  __1u__shapes__lookups__dynamic____buffer_capacity * __1u__shapes__lookups__dynamic____buffer_alignment *sizeof(u64)); else ((void**) shapes__lookups__dynamic )[0] = __runtime_alloc( __1u__shapes__lookups__dynamic____buffer_capacity * __1u__shapes__lookups__dynamic____buffer_alignment *sizeof(u64)); ((u64*) shapes__lookups__dynamic )[2] = __1u__shapes__lookups__dynamic____buffer_capacity ;
 __1u__shapes__lookups__dynamic____buffer_contents = (ptr)((void**) shapes__lookups__dynamic )[0] ;
 if( ! __1u__shapes__lookups__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  __1u__shapes__lookups__dynamic____buffer_contents = (ptr)(((u64*) shapes__lookups__dynamic )[0]) ;
 ((u64*) shapes__lookups__dynamic )[1] = __1u__shapes__lookups__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __1u__shapes__lookups__dynamic____buffer_contents )[ __1u__shapes__lookups__dynamic____buffer_size * __1u__shapes__lookups__dynamic____buffer_alignment ], & __1u____buffer_size , sizeof(u64)); __1u____eu = 2 ;
 if(! shapes__types__dynamic )goto __result__buffer_error ;
 __1u__shapes__types__dynamic____buffer_alignment = 1 ;
 __1u__shapes__types__dynamic____buffer_size = ((u64*) shapes__types__dynamic )[1] ;
 __1u__shapes__types__dynamic____buffer_capacity = ((u64*) shapes__types__dynamic )[2] & ~(1ULL << 63) ;
 if( __1u__shapes__types__dynamic____buffer_size >= __1u__shapes__types__dynamic____buffer_capacity ){ if( ((u64*) shapes__types__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __1u__shapes__types__dynamic____buffer_capacity = __1u__shapes__types__dynamic____buffer_capacity +( __1u__shapes__types__dynamic____buffer_capacity >>2)+1; if( __1u__shapes__types__dynamic____buffer_size ) ((void**) shapes__types__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__types__dynamic )[0],  __1u__shapes__types__dynamic____buffer_capacity * __1u__shapes__types__dynamic____buffer_alignment *sizeof(u64),  __1u__shapes__types__dynamic____buffer_capacity * __1u__shapes__types__dynamic____buffer_alignment *sizeof(u64)); else ((void**) shapes__types__dynamic )[0] = __runtime_alloc( __1u__shapes__types__dynamic____buffer_capacity * __1u__shapes__types__dynamic____buffer_alignment *sizeof(u64)); ((u64*) shapes__types__dynamic )[2] = __1u__shapes__types__dynamic____buffer_capacity ;
 __1u__shapes__types__dynamic____buffer_contents = (ptr)((void**) shapes__types__dynamic )[0] ;
 if( ! __1u__shapes__types__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  __1u__shapes__types__dynamic____buffer_contents = (ptr)(((u64*) shapes__types__dynamic )[0]) ;
 ((u64*) shapes__types__dynamic )[1] = __1u__shapes__types__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __1u__shapes__types__dynamic____buffer_contents )[ __1u__shapes__types__dynamic____buffer_size * __1u__shapes__types__dynamic____buffer_alignment ], & __1u____eu , sizeof(u64)); if(! shapes__circles__dynamic )goto __result__buffer_error ;
 __1u__shapes__circles__dynamic____buffer_alignment = 1 ;
 __1u__shapes__circles__dynamic____buffer_size = ((u64*) shapes__circles__dynamic )[1] ;
 __1u__shapes__circles__dynamic____buffer_capacity = ((u64*) shapes__circles__dynamic )[2] & ~(1ULL << 63) ;
 if( __1u__shapes__circles__dynamic____buffer_size >= __1u__shapes__circles__dynamic____buffer_capacity ){ if( ((u64*) shapes__circles__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __1u__shapes__circles__dynamic____buffer_capacity = __1u__shapes__circles__dynamic____buffer_capacity +( __1u__shapes__circles__dynamic____buffer_capacity >>2)+1; if( __1u__shapes__circles__dynamic____buffer_size ) ((void**) shapes__circles__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__circles__dynamic )[0],  __1u__shapes__circles__dynamic____buffer_capacity * __1u__shapes__circles__dynamic____buffer_alignment *sizeof(u64),  __1u__shapes__circles__dynamic____buffer_capacity * __1u__shapes__circles__dynamic____buffer_alignment *sizeof(u64)); else ((void**) shapes__circles__dynamic )[0] = __runtime_alloc( __1u__shapes__circles__dynamic____buffer_capacity * __1u__shapes__circles__dynamic____buffer_alignment *sizeof(u64)); ((u64*) shapes__circles__dynamic )[2] = __1u__shapes__circles__dynamic____buffer_capacity ;
 __1u__shapes__circles__dynamic____buffer_contents = (ptr)((void**) shapes__circles__dynamic )[0] ;
 if( ! __1u__shapes__circles__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  __1u__shapes__circles__dynamic____buffer_contents = (ptr)(((u64*) shapes__circles__dynamic )[0]) ;
 ((u64*) shapes__circles__dynamic )[1] = __1u__shapes__circles__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __1u__shapes__circles__dynamic____buffer_contents )[ __1u__shapes__circles__dynamic____buffer_size * __1u__shapes__circles__dynamic____buffer_alignment +0], & __zu , sizeof(f64)); __1u____end :
 shapes____Bp = __1u__shapes____Bp ;
 shapes__memory____zO = __1u__shapes__memory____zO ;
 __4u = 5.0 ;
 __6u____buffer_size = shapes__squares__dynamic ? ((u64*) shapes__squares__dynamic )[1]:0 ;
 if(! shapes__lookups__dynamic )goto __result__buffer_error ;
 __6u__shapes__lookups__dynamic____buffer_alignment = 1 ;
 __6u__shapes__lookups__dynamic____buffer_size = ((u64*) shapes__lookups__dynamic )[1] ;
 __6u__shapes__lookups__dynamic____buffer_capacity = ((u64*) shapes__lookups__dynamic )[2] & ~(1ULL << 63) ;
 if( __6u__shapes__lookups__dynamic____buffer_size >= __6u__shapes__lookups__dynamic____buffer_capacity ){ if( ((u64*) shapes__lookups__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __6u__shapes__lookups__dynamic____buffer_capacity = __6u__shapes__lookups__dynamic____buffer_capacity +( __6u__shapes__lookups__dynamic____buffer_capacity >>2)+1; if( __6u__shapes__lookups__dynamic____buffer_size ) ((void**) shapes__lookups__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__lookups__dynamic )[0],  __6u__shapes__lookups__dynamic____buffer_capacity * __6u__shapes__lookups__dynamic____buffer_alignment *sizeof(u64),  __6u__shapes__lookups__dynamic____buffer_capacity * __6u__shapes__lookups__dynamic____buffer_alignment *sizeof(u64)); else ((void**) shapes__lookups__dynamic )[0] = __runtime_alloc( __6u__shapes__lookups__dynamic____buffer_capacity * __6u__shapes__lookups__dynamic____buffer_alignment *sizeof(u64)); ((u64*) shapes__lookups__dynamic )[2] = __6u__shapes__lookups__dynamic____buffer_capacity ;
 __6u__shapes__lookups__dynamic____buffer_contents = (ptr)((void**) shapes__lookups__dynamic )[0] ;
 if( ! __6u__shapes__lookups__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  __6u__shapes__lookups__dynamic____buffer_contents = (ptr)(((u64*) shapes__lookups__dynamic )[0]) ;
 ((u64*) shapes__lookups__dynamic )[1] = __6u__shapes__lookups__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __6u__shapes__lookups__dynamic____buffer_contents )[ __6u__shapes__lookups__dynamic____buffer_size * __6u__shapes__lookups__dynamic____buffer_alignment ], & __6u____buffer_size , sizeof(u64)); __6u____Ou = 3 ;
 if(! shapes__types__dynamic )goto __result__buffer_error ;
 __6u__shapes__types__dynamic____buffer_alignment = 1 ;
 __6u__shapes__types__dynamic____buffer_size = ((u64*) shapes__types__dynamic )[1] ;
 __6u__shapes__types__dynamic____buffer_capacity = ((u64*) shapes__types__dynamic )[2] & ~(1ULL << 63) ;
 if( __6u__shapes__types__dynamic____buffer_size >= __6u__shapes__types__dynamic____buffer_capacity ){ if( ((u64*) shapes__types__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __6u__shapes__types__dynamic____buffer_capacity = __6u__shapes__types__dynamic____buffer_capacity +( __6u__shapes__types__dynamic____buffer_capacity >>2)+1; if( __6u__shapes__types__dynamic____buffer_size ) ((void**) shapes__types__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__types__dynamic )[0],  __6u__shapes__types__dynamic____buffer_capacity * __6u__shapes__types__dynamic____buffer_alignment *sizeof(u64),  __6u__shapes__types__dynamic____buffer_capacity * __6u__shapes__types__dynamic____buffer_alignment *sizeof(u64)); else ((void**) shapes__types__dynamic )[0] = __runtime_alloc( __6u__shapes__types__dynamic____buffer_capacity * __6u__shapes__types__dynamic____buffer_alignment *sizeof(u64)); ((u64*) shapes__types__dynamic )[2] = __6u__shapes__types__dynamic____buffer_capacity ;
 __6u__shapes__types__dynamic____buffer_contents = (ptr)((void**) shapes__types__dynamic )[0] ;
 if( ! __6u__shapes__types__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  __6u__shapes__types__dynamic____buffer_contents = (ptr)(((u64*) shapes__types__dynamic )[0]) ;
 ((u64*) shapes__types__dynamic )[1] = __6u__shapes__types__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __6u__shapes__types__dynamic____buffer_contents )[ __6u__shapes__types__dynamic____buffer_size * __6u__shapes__types__dynamic____buffer_alignment ], & __6u____Ou , sizeof(u64)); if(! shapes__squares__dynamic )goto __result__buffer_error ;
 __6u__shapes__squares__dynamic____buffer_alignment = 1 ;
 __6u__shapes__squares__dynamic____buffer_size = ((u64*) shapes__squares__dynamic )[1] ;
 __6u__shapes__squares__dynamic____buffer_capacity = ((u64*) shapes__squares__dynamic )[2] & ~(1ULL << 63) ;
 if( __6u__shapes__squares__dynamic____buffer_size >= __6u__shapes__squares__dynamic____buffer_capacity ){ if( ((u64*) shapes__squares__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __6u__shapes__squares__dynamic____buffer_capacity = __6u__shapes__squares__dynamic____buffer_capacity +( __6u__shapes__squares__dynamic____buffer_capacity >>2)+1; if( __6u__shapes__squares__dynamic____buffer_size ) ((void**) shapes__squares__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__squares__dynamic )[0],  __6u__shapes__squares__dynamic____buffer_capacity * __6u__shapes__squares__dynamic____buffer_alignment *sizeof(u64),  __6u__shapes__squares__dynamic____buffer_capacity * __6u__shapes__squares__dynamic____buffer_alignment *sizeof(u64)); else ((void**) shapes__squares__dynamic )[0] = __runtime_alloc( __6u__shapes__squares__dynamic____buffer_capacity * __6u__shapes__squares__dynamic____buffer_alignment *sizeof(u64)); ((u64*) shapes__squares__dynamic )[2] = __6u__shapes__squares__dynamic____buffer_capacity ;
 __6u__shapes__squares__dynamic____buffer_contents = (ptr)((void**) shapes__squares__dynamic )[0] ;
 if( ! __6u__shapes__squares__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  __6u__shapes__squares__dynamic____buffer_contents = (ptr)(((u64*) shapes__squares__dynamic )[0]) ;
 ((u64*) shapes__squares__dynamic )[1] = __6u__shapes__squares__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __6u__shapes__squares__dynamic____buffer_contents )[ __6u__shapes__squares__dynamic____buffer_size * __6u__shapes__squares__dynamic____buffer_alignment +0], & __4u , sizeof(f64)); __6u____end :
 shapes____Bp = __6u__shapes____Bp ;
 shapes__memory____zO = __6u__shapes__memory____zO ;
 __7u____buffer_size = shapes__types__dynamic ? ((u64*) shapes__types__dynamic )[1]:0 ;
 __8u__sup = __7u____buffer_size ;
 __8u____wD = 0 ;
 __8u____xD = 1 ;
 __8u__start = __8u____wD ;
 __8u__step = __8u____xD ;
 __8u__pos = __8u____wD ;
 __9u__loop :
 __Av__self__pos = __8u__pos ;
 __Av__value = i ;
 __Av__value = __Av__self__pos ;
 __Av____zD = 1 ;
 __Av____0D__z = __Av__self__pos + __Av____zD ; 
 __Av____0D____end :
 __Av__self__pos = __Av____0D__z ;
 __Av____1D__z = __Av__self__pos <= __8u__sup ; 
 __Av____1D____end :
 __8u__pos = __Av__self__pos ;
 if(! __Av____1D__z )goto __9u__while ;
 __Dv__side = 0 ;
 if(! shapes__types__dynamic )goto __result__buffer_error ;
 __Fv__self__types__dynamic____buffer_alignment = 1 ;
 __Fv__self__types__dynamic____buffer_size = ((u64*) shapes__types__dynamic )[1] ;
 if( __Av__value >= __Fv__self__types__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(& __Fv____jq , &((u64*)((u64*) shapes__types__dynamic )[0])[ __Av__value * __Fv__self__types__dynamic____buffer_alignment +0], sizeof( tag )) ;
 __Fv____kq = 3 ;
 __Fv____lq__z =( __Fv____jq == __Fv____kq ); 
 __Fv____lq____end :
 if(! __Fv____lq__z )goto __Bv__fi ;
 __Hv__side = 0 ;
 if(! shapes__types__dynamic )goto __result__buffer_error ;
 __Jv__shapes__types__dynamic____buffer_alignment = 1 ;
 __Jv__shapes__types__dynamic____buffer_size = ((u64*) shapes__types__dynamic )[1] ;
 if( __Av__value >= __Jv__shapes__types__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(& __Jv____zt , &((u64*)((u64*) shapes__types__dynamic )[0])[ __Av__value * __Jv__shapes__types__dynamic____buffer_alignment +0], sizeof( tag )) ;
 __Jv____1t = 3 ;
 __Jv____2t__z =( __Jv____zt != __Jv____1t ); 
 __Jv____2t____end :
 if(! __Jv____2t__z )goto __Jv____0t__fi ;
 __Jv____3t = "Trying to access a non-square" ;
 goto __Jv____4t____oD ;
 __builtin_unreachable();
 __Jv____0t__fi :
 if(! shapes__lookups__dynamic )goto __result__buffer_error ;
 __Jv__shapes__lookups__dynamic____buffer_alignment = 1 ;
 __Jv__shapes__lookups__dynamic____buffer_size = ((u64*) shapes__lookups__dynamic )[1] ;
 if( __Av__value >= __Jv__shapes__lookups__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(& __Jv____6t , &((u64*)((u64*) shapes__lookups__dynamic )[0])[ __Av__value * __Jv__shapes__lookups__dynamic____buffer_alignment +0], sizeof( u64 )) ;
 if(! shapes__squares__dynamic )goto __result__buffer_error ;
 __Jv__shapes__squares__dynamic____buffer_alignment = 1 ;
 __Jv__shapes__squares__dynamic____buffer_size = ((u64*) shapes__squares__dynamic )[1] ;
 if( __Jv____6t >= __Jv__shapes__squares__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(& __Jv____9t , &((u64*)((void**) shapes__squares__dynamic )[0])[ __Jv____6t * __Jv__shapes__squares__dynamic____buffer_alignment +0], sizeof( f64 )) ;
 __Kv = 1.0 ;
 __Lv____Pn____Mn__z = __Jv____9t * __Jv____9t ; 
 __Lv____Pn____Mn____end :
 __Lv____Qn__z = __Lv____Pn____Mn__z * __Kv ; 
 __Lv____Qn____end :
 printf ( "%.6f\n" , __Lv____Qn__z ); 
 __Mv____end :
 goto __Bv__el ;
 __Bv__fi :
 __Ov__radius = 0 ;
 if(! shapes__types__dynamic )goto __result__buffer_error ;
 __Qv__self__types__dynamic____buffer_alignment = 1 ;
 __Qv__self__types__dynamic____buffer_size = ((u64*) shapes__types__dynamic )[1] ;
 if( __Av__value >= __Qv__self__types__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(& __Qv____Is , &((u64*)((u64*) shapes__types__dynamic )[0])[ __Av__value * __Qv__self__types__dynamic____buffer_alignment +0], sizeof( tag )) ;
 __Qv____Ks = 2 ;
 __Qv____Ls__z =( __Qv____Is != __Qv____Ks ); 
 __Qv____Ls____end :
 if(! __Qv____Ls__z )goto __Qv____Js__fi ;
 __Qv____Ms = "Trying to access a non-circle" ;
 goto __Qv____Ns____oD ;
 __builtin_unreachable();
 __Qv____Js__fi :
 if(! shapes__lookups__dynamic )goto __result__buffer_error ;
 __Qv__self__lookups__dynamic____buffer_alignment = 1 ;
 __Qv__self__lookups__dynamic____buffer_size = ((u64*) shapes__lookups__dynamic )[1] ;
 if( __Av__value >= __Qv__self__lookups__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(& __Qv____Ps , &((u64*)((u64*) shapes__lookups__dynamic )[0])[ __Av__value * __Qv__self__lookups__dynamic____buffer_alignment +0], sizeof( u64 )) ;
 if(! shapes__circles__dynamic )goto __result__buffer_error ;
 __Qv__self__circles__dynamic____buffer_alignment = 1 ;
 __Qv__self__circles__dynamic____buffer_size = ((u64*) shapes__circles__dynamic )[1] ;
 if( __Qv____Ps >= __Qv__self__circles__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(& __Qv____Ss , &((u64*)((void**) shapes__circles__dynamic )[0])[ __Qv____Ps * __Qv__self__circles__dynamic____buffer_alignment +0], sizeof( f64 )) ;
 __Rv = 1.0 ;
 __Sv____Nn____Hn__z = __Qv____Ss * __Qv____Ss ; 
 __Sv____Nn____Hn____end :
 __Sv____Nn____In__z = __Sv____Nn____Hn__z * M_PI ; 
 __Sv____Nn____In____end :
 __Sv____Nn____Jn = 2.0 ;
 __Sv____Nn____Kn__z = __Sv____Nn____In__z / __Sv____Nn____Jn ; 
 __Sv____Nn____Kn____end :
 __Sv____On__z = __Sv____Nn____Kn__z * __Rv ; 
 __Sv____On____end :
 printf ( "%.6f\n" , __Sv____On__z ); 
 __Tv____end :
 __Bv__el :
 goto __9u__loop ;
 __9u__while :
 __end :
goto __return;

// ERROR HANDLING
__Qv____Ns____oD :
 printf ( "%s\n" , __Qv____Ms ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__Jv____4t____oD :
 printf ( "%s\n" , __Jv____3t ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__result__buffer_error :
printf("Buffer error\n");
__result__errocode=__BUFFER__ERROR;
goto __failsafe;
__mu____Qp____NQ____HP____oD :
 printf ( "%s\n" , __mu____Qp____NQ____GP ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__mu____Mp____NQ____LP____oD :
 printf ( "%s\n" , __mu____Mp____NQ____KP ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__mu____Ip____NQ____LP____oD :
 printf ( "%s\n" , __mu____Ip____NQ____KP ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__mu____Ip____NQ____HP____oD :
 printf ( "%s\n" , __mu____Ip____NQ____GP ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__mu____Qp____NQ____LP____oD :
 printf ( "%s\n" , __mu____Qp____NQ____KP ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__mu____Mp____NQ____HP____oD :
 printf ( "%s\n" , __mu____Mp____NQ____GP ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__mu____Ep____NQ____LP____oD :
 printf ( "%s\n" , __mu____Ep____NQ____KP ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__mu____Ep____NQ____HP____oD :
 printf ( "%s\n" , __mu____Ep____NQ____GP ); 
__result__errocode=__USER__ERROR;
goto __failsafe;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
if( __mu__lookups__dynamic ) __runtime_free( __mu__lookups__dynamic ) ;
 __mu__lookups__dynamic = 0 ;
if( __mu__circles__dynamic ) __runtime_free( __mu__circles__dynamic ) ;
 __mu__circles__dynamic = 0 ;
if( __mu__types__dynamic ) __runtime_free( __mu__types__dynamic ) ;
 __mu__types__dynamic = 0 ;
if( __mu__squares__dynamic ) __runtime_free( __mu__squares__dynamic ) ;
 __mu__squares__dynamic = 0 ;
if ( __ku__acquired ) { for ( __ku____dynamic_entry =0; __ku____dynamic_entry < __ku__size ;++ __ku____dynamic_entry ) { __runtime_free ((( ptr **) __ku__acquired )[0][ __ku____dynamic_entry ]); } __runtime_free ( __ku__acquired ); __ku__acquired =0; __ku__size =0; __ku__allocated =0; } 
 if ( __ku__acquired ) { for ( __ku____5O____dynamic_entry =0; __ku____5O____dynamic_entry < __ku____5O____0O ;++ __ku____5O____dynamic_entry ) { __runtime_free ((( ptr **) __ku__acquired )[0][ __ku____5O____dynamic_entry ]); } __runtime_free ( __ku__acquired ); __ku__acquired =0; __ku____5O____0O =0; __ku____5O____1O =0; } 
__state->err =  __result__errocode;
}



int main() {
struct main__590__state __main_args={0};
__smolambda_initialize_service_tasks(main__590, &__main_args);
return __main_args.err;
}

