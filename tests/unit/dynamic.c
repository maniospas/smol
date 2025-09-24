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

#include<stdio.h>

struct main__215__state{errcode err;};
void main__215(void *__void__state);

void main__215(void *__void__state){
errcode __result__errocode=0;
struct main__215__state *__state=(struct main__215__state*)__void__state;
f64 __fG____LF____IF__z=0;
nominal __fG____LF__self____HF=0;
f64 __fG____MF__x=0;
f64 __fG__height=0;
f64 __fG__base__side=0;
nominal __fG__base____HF=0;
u64 __dG__shapes__squares__dynamic____buffer_size=0;
u64 __dG____5F=0;
u64 __dG__shapes__types__dynamic____buffer_size=0;
cstr __dG____2F__error=0;
cstr __dG____1F=0;
u64 __dG____zF=0;
ptr __dG__shapes____OF__dynamic=0;
f64 __dG____9F=0;
u64 __dG__shapes__lookups__dynamic____buffer_size=0;
u64 __dG__type=0;
u64 __dG____xF=0;
u64 __dG__shapes__types__dynamic____buffer_alignment=0;
nominal __dG____HF=0;
ptr __dG__shapes____QF__dynamic=0;
u64 __dG____0F__y=0;
ptr __dG__shapes____RF__surface=0;
ptr __dG__shapes____RF__dynamic=0;
ptr __dG__shapes____OF__surface=0;
f64 __dG__side=0;
u64 __dG__pos=0;
u64 __dG__shapes__lookups__dynamic____buffer_alignment=0;
ptr __dG__shapes__lookups__surface=0;
ptr __dG__shapes__lookups__dynamic=0;
ptr __dG__shapes__types__surface=0;
ptr __dG__shapes__types__dynamic=0;
nominal __dG__shapes____NF=0;
f64 __cG__side=0;
nominal __cG____HF=0;
f64 __bG__side=0;
nominal __aG____HF=0;
ptr __ZG__self____PF__surface=0;
u64 __ZG__self__types__dynamic____buffer_size=0;
ptr __ZG__self____PF__dynamic=0;
ptr __dG__shapes__circles__dynamic=0;
ptr __ZG__self____OF__surface=0;
f64 __fG____LF____IF__y=0;
u64 __ZG____cF=0;
u64 __ZG__self__types__dynamic____buffer_alignment=0;
u64 __ZG____aF=0;
u64 __ZG____dF__x=0;
nominal __PG____CF=0;
ptr __ZG__self____QF__surface=0;
nominal __NG=0;
nominal __WG____HF=0;
ptr __ZG__self____QF__dynamic=0;
nominal __MG=0;
u64 __SG____yD__pos=0;
u64 __LG____AG=0;
ptr __LG__shapes____RF__dynamic=0;
ptr __LG__shapes____QF__surface=0;
nominal __FG=0;
nominal __LG____NF=0;
ptr __dG__shapes____QF__surface=0;
ptr __LG__shapes____PF__dynamic=0;
f64 __ZG____YF__side=0;
ptr __LG__squares__surface=0;
u64 __dG____4F=0;
u64 __SG____yD__end=0;
ptr __LG__shapes__squares__dynamic____buffer_contents=0;
u64 __ZG____dF__y=0;
u64 __LG__shapes__squares__dynamic____buffer_capacity=0;
ptr __dG__shapes____PF__dynamic=0;
u64 __RG____buffer_size=0;
ptr __LG__types__surface=0;
u64 __QG__shapes__circles__dynamic____buffer_capacity=0;
bool __ZG____dF__z=0;
f64 __LG__square__side=0;
f64 __OG=0;
ptr __LG__shapes__circles__dynamic=0;
ptr __QG__shapes__types__dynamic=0;
nominal __dG____8F=0;
ptr __LG__shapes____PF__surface=0;
nominal __LG__shapes____NF=0;
ptr __LG__shapes__lookups__surface=0;
ptr __LG__circles__surface=0;
ptr __GG____QF__dynamic=0;
f64 __YG__side=0;
u64 __LG__types__dynamic=0;
ptr __GG____RF__dynamic=0;
nominal __dG____uF____HF=0;
nominal __KG____HF=0;
ptr __GG__squares__surface=0;
ptr shapes____QF__dynamic=0;
ptr shapes__circles__surface=0;
u64 __UG____0D__z=0;
ptr __dG__shapes____PF__surface=0;
f64 __JG=0;
ptr __ZG__self__lookups__surface=0;
ptr __GG____OF__surface=0;
ptr __ZG__self__circles__surface=0;
u64 __QG____buffer_size=0;
ptr __RG__shapes__circles__dynamic=0;
ptr __LG__shapes__circles__surface=0;
ptr __QG__shapes__types__surface=0;
u64 __dG____wF=0;
ptr __QG__shapes__circles__dynamic=0;
ptr __GG__types__dynamic=0;
f64 __fG____LF__self__side=0;
u64 __SG__start=0;
u64 __dG__lookup=0;
ptr __QG__shapes__squares__surface=0;
ptr __GG____PF__surface=0;
nominal __EG=0;
ptr __GG__lookups__dynamic=0;
ptr __GG__lookups__surface=0;
ptr __LG__shapes____QF__dynamic=0;
ptr shapes____PF__dynamic=0;
ptr __GG__squares__dynamic=0;
nominal shapes____NF=0;
ptr __QG__shapes__lookups__dynamic=0;
ptr __GG____PF__dynamic=0;
ptr __GG____RF__surface=0;
ptr __LG__shapes__types__surface=0;
ptr __QG__shapes__circles__surface=0;
ptr __GG____QF__surface=0;
f64 __dG____7F__side=0;
ptr __GG__types__surface=0;
nominal __ZG____YF____HF=0;
ptr __QG__shapes__lookups__surface=0;
u64 __LG__shapes__squares__dynamic____buffer_prev_capacity=0;
ptr shapes__types__surface=0;
ptr shapes____OF__dynamic=0;
f64 __dG____uF__side=0;
ptr __ZG__self__lookups__dynamic=0;
ptr shapes____PF__surface=0;
ptr shapes____RF__surface=0;
u64 __LG____buffer_size=0;
ptr __QG__shapes____RF__surface=0;
ptr shapes____QF__surface=0;
u64 i=0;
bool __dG____0F__z=0;
ptr __LG__shapes__types__dynamic=0;
nominal __ZG__self____NF=0;
ptr shapes__squares__surface=0;
ptr __QG__lookups__surface=0;
ptr __QG__squares__surface=0;
ptr __QG__circles__surface=0;
u64 __SG____yD__step=0;
ptr __RG__shapes__lookups__surface=0;
nominal __HG=0;
u64 __UG____0D__y=0;
ptr shapes__circles__dynamic=0;
u64 __dG____0F__x=0;
ptr __LG__shapes____OF__surface=0;
u64 __LG__shapes__squares__dynamic____buffer_size=0;
nominal __GG____NF=0;
ptr __GG__circles__surface=0;
ptr shapes__lookups__surface=0;
f64 __fG____LF____IF__x=0;
u64 __ZG____bF=0;
ptr __LG__shapes__lookups__dynamic=0;
ptr shapes__squares__dynamic=0;
ptr shapes__lookups__dynamic=0;
ptr __GG__circles__dynamic=0;
ptr shapes____RF__dynamic=0;
ptr __QG__shapes____RF__dynamic=0;
nominal __QG__shapes____NF=0;
ptr __LG__shapes____OF__dynamic=0;
ptr shapes____OF__surface=0;
ptr __QG__shapes__squares__dynamic=0;
u64 __ZG__type=0;
nominal __IG=0;
nominal __QG__circle____CF=0;
u64 __LG__shapes__squares__dynamic____buffer_alignment=0;
f64 __QG__circle__radius=0;
ptr __QG__shapes____PF__surface=0;
u64 __QG__lookups__dynamic=0;
nominal __LG__square____HF=0;
ptr __RG__shapes__squares__dynamic=0;
ptr __QG__types__surface=0;
u64 __QG__types__dynamic=0;
ptr shapes__types__dynamic=0;
ptr __QG__shapes__circles__dynamic____buffer_contents=0;
u64 __QG__shapes__circles__dynamic____buffer_size=0;
ptr __ZG__self__types__dynamic=0;
ptr __LG__shapes__squares__surface=0;
f64 __XG__side=0;
ptr __ZG__self____RF__surface=0;
ptr __QG__shapes____OF__dynamic=0;
ptr __RG__shapes____RF__dynamic=0;
u64 __QG__shapes__circles__dynamic____buffer_alignment=0;
ptr __QG__shapes____QF__dynamic=0;
nominal __RG__shapes____NF=0;
ptr __RG__shapes__squares__surface=0;
nominal __QG____NF=0;
ptr __RG__shapes__circles__surface=0;
ptr __GG____OF__dynamic=0;
u64 __UG____zD=0;
ptr __LG__shapes____RF__surface=0;
ptr __RG__shapes__types__dynamic=0;
f64 __gG__message=0;
ptr __QG__shapes____QF__surface=0;
ptr __RG__shapes__lookups__dynamic=0;
f64 __PG__radius=0;
ptr __RG__shapes____OF__surface=0;
ptr __RG__shapes____PF__surface=0;
f64 __fG____MF__z=0;
ptr __RG__shapes____PF__dynamic=0;
ptr __RG__shapes____OF__dynamic=0;
ptr __RG__shapes____QF__surface=0;
ptr __LG__shapes__squares__dynamic=0;
ptr __RG__shapes____RF__surface=0;
ptr __dG__shapes__squares__dynamic=0;
u64 __QG__shapes__circles__dynamic____buffer_prev_capacity=0;
u64 __SG__end=0;
ptr __RG__shapes____QF__dynamic=0;
u64 __LG__lookups__dynamic=0;
u64 __SG__pos=0;
f64 __eG=0;
u64 __SG__step=0;
u64 __SG____yD__start=0;
u64 __SG____xD=0;
u64 __SG____wD=0;
ptr __dG__shapes__squares__surface=0;
ptr __LG__lookups__surface=0;
u64 __UG__self__start=0;
f64 __fG____MF__y=0;
nominal __dG____7F____HF=0;
u64 __UG__self__end=0;
u64 __UG__self__step=0;
ptr __dG__shapes__circles__surface=0;
ptr __ZG__self____OF__dynamic=0;
u64 __UG__self__pos=0;
u64 __UG__value=0;
ptr __RG__shapes__types__surface=0;
u64 __UG____1D__y=0;
u64 __dG__shapes__squares__dynamic____buffer_alignment=0;
ptr __ZG__self__squares__dynamic=0;
f64 __KG__side=0;
bool __UG____1D__z=0;
u64 __UG____0D__x=0;
u64 __UG____1D__x=0;
nominal __YG____HF=0;
u64 __QG____CG=0;
ptr __ZG__self__squares__surface=0;
ptr __ZG__self__circles__dynamic=0;
ptr __QG__shapes____PF__dynamic=0;
ptr __ZG__self__types__surface=0;
ptr __ZG__self____RF__dynamic=0;
ptr __QG__shapes____OF__surface=0;
u64 __ZG__pos=0;

// IMPLEMENTATION
__GG____OF__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 __GG____OF__surface = 0 ;
 __GG__squares__dynamic = __GG____OF__dynamic ;
 __GG__squares__surface = __GG____OF__surface ;
 __GG____PF__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 __GG____PF__surface = 0 ;
 __GG__circles__dynamic = __GG____PF__dynamic ;
 __GG__circles__surface = __GG____PF__surface ;
 __GG____QF__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 __GG____QF__surface = 0 ;
 __GG__types__dynamic = __GG____QF__dynamic ;
 __GG__types__surface = __GG____QF__surface ;
 __GG____RF__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 __GG____RF__surface = 0 ;
 __GG__lookups__dynamic = __GG____RF__dynamic ;
 __GG__lookups__surface = __GG____RF__surface ;
 goto __GG____end ;
 __GG____end :
 shapes__squares__dynamic = __GG__squares__dynamic ;
 shapes__squares__surface = __GG__squares__surface ;
 shapes__circles__dynamic = __GG__circles__dynamic ;
 shapes__circles__surface = __GG__circles__surface ;
 shapes__types__dynamic = __GG__types__dynamic ;
 shapes__types__surface = __GG__types__surface ;
 shapes__lookups__dynamic = __GG__lookups__dynamic ;
 shapes__lookups__surface = __GG__lookups__surface ;
 __JG = 1.0 ;
 __KG__side = __JG ;
 goto __KG____end ;
 __KG____end :
 __LG__shapes__squares__dynamic = shapes__squares__dynamic ;
 __LG__shapes__squares__surface = shapes__squares__surface ;
 __LG__shapes__circles__dynamic = shapes__circles__dynamic ;
 __LG__shapes__circles__surface = shapes__circles__surface ;
 __LG__shapes__types__dynamic = shapes__types__dynamic ;
 __LG__shapes__types__surface = shapes__types__surface ;
 __LG__shapes__lookups__dynamic = shapes__lookups__dynamic ;
 __LG__shapes__lookups__surface = shapes__lookups__surface ;
 __LG__square__side = __KG__side ;
 __LG____buffer_size = __LG__shapes__squares__dynamic ? ((u64*) __LG__shapes__squares__dynamic )[1]:0 ;
 __LG____AG = 0 ;
 if(! __LG__shapes__squares__dynamic )goto __LG____BG ;
 __LG__shapes__squares__dynamic____buffer_alignment = 1 ;
 __LG__shapes__squares__dynamic____buffer_size = ((u64*) __LG__shapes__squares__dynamic )[1] ;
 __LG__shapes__squares__dynamic____buffer_capacity = ((u64*) __LG__shapes__squares__dynamic )[2] & ~(1ULL << 63) ;
 if( __LG__shapes__squares__dynamic____buffer_size >= __LG__shapes__squares__dynamic____buffer_capacity ){ if( ((u64*) __LG__shapes__squares__dynamic )[2] & (1ULL << 63) )goto __LG____BG ;
 __LG__shapes__squares__dynamic____buffer_prev_capacity = __LG__shapes__squares__dynamic____buffer_capacity ;
 __LG__shapes__squares__dynamic____buffer_capacity = __LG__shapes__squares__dynamic____buffer_capacity +( __LG__shapes__squares__dynamic____buffer_capacity >>2)+1; if( __LG__shapes__squares__dynamic____buffer_size ) ((void**) __LG__shapes__squares__dynamic )[0] = __runtime_realloc((u64*)((void**) __LG__shapes__squares__dynamic )[0],  __LG__shapes__squares__dynamic____buffer_capacity * __LG__shapes__squares__dynamic____buffer_alignment *sizeof(u64),  __LG__shapes__squares__dynamic____buffer_prev_capacity * __LG__shapes__squares__dynamic____buffer_alignment *sizeof(u64)); else ((void**) __LG__shapes__squares__dynamic )[0] = __runtime_alloc( __LG__shapes__squares__dynamic____buffer_capacity * __LG__shapes__squares__dynamic____buffer_alignment *sizeof(u64)); ((u64*) __LG__shapes__squares__dynamic )[2] = __LG__shapes__squares__dynamic____buffer_capacity ;
 __LG__shapes__squares__dynamic____buffer_contents = (ptr)((void**) __LG__shapes__squares__dynamic )[0] ;
 if( ! __LG__shapes__squares__dynamic____buffer_contents )goto __LG____BG ;
 } else  __LG__shapes__squares__dynamic____buffer_contents = (ptr)(((u64*) __LG__shapes__squares__dynamic )[0]) ;
 ((u64*) __LG__shapes__squares__dynamic )[1] = __LG__shapes__squares__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __LG__shapes__squares__dynamic____buffer_contents )[ __LG__shapes__squares__dynamic____buffer_size * __LG__shapes__squares__dynamic____buffer_alignment +0], & __LG__square__side , sizeof(f64)); __LG__squares__dynamic = __LG__shapes__squares__dynamic ;
 __LG__squares__surface = __LG__shapes__squares__surface ;
 __LG__circles__dynamic = __LG__shapes__circles__dynamic ;
 __LG__circles__surface = __LG__shapes__circles__surface ;
 __LG__types__dynamic = __LG__shapes__types__dynamic ;
 __LG__types__surface = __LG__shapes__types__surface ;
 __LG__lookups__dynamic = __LG__shapes__lookups__dynamic ;
 __LG__lookups__surface = __LG__shapes__lookups__surface ;
 goto __LG____end ;
 __LG____end :
 shapes____NF = __LG__shapes____NF ;
 shapes__squares__dynamic = __LG__shapes__squares__dynamic ;
 shapes__squares__surface = __LG__shapes__squares__surface ;
 shapes__circles__dynamic = __LG__shapes__circles__dynamic ;
 shapes__circles__surface = __LG__shapes__circles__surface ;
 shapes__types__dynamic = __LG__shapes__types__dynamic ;
 shapes__types__surface = __LG__shapes__types__surface ;
 shapes__lookups__dynamic = __LG__shapes__lookups__dynamic ;
 shapes__lookups__surface = __LG__shapes__lookups__surface ;
 if( __OF__dynamic ){if((u64*)((u64*) __OF__dynamic )[2]) __runtime_free((u64*)((u64*) __OF__dynamic )[0]) ;
 __runtime_free( __OF__dynamic ) ;
 __OF__dynamic = 0 ;
 } if( __PF__dynamic ){if((u64*)((u64*) __PF__dynamic )[2]) __runtime_free((u64*)((u64*) __PF__dynamic )[0]) ;
 __runtime_free( __PF__dynamic ) ;
 __PF__dynamic = 0 ;
 } if( __QF__dynamic ){if((u64*)((u64*) __QF__dynamic )[2]) __runtime_free((u64*)((u64*) __QF__dynamic )[0]) ;
 __runtime_free( __QF__dynamic ) ;
 __QF__dynamic = 0 ;
 } if( __RF__dynamic ){if((u64*)((u64*) __RF__dynamic )[2]) __runtime_free((u64*)((u64*) __RF__dynamic )[0]) ;
 __runtime_free( __RF__dynamic ) ;
 __RF__dynamic = 0 ;
 } __OG = 1.0 ;
 __PG__radius = __OG ;
 goto __PG____end ;
 __PG____end :
 __QG__shapes__squares__dynamic = shapes__squares__dynamic ;
 __QG__shapes__squares__surface = shapes__squares__surface ;
 __QG__shapes__circles__dynamic = shapes__circles__dynamic ;
 __QG__shapes__circles__surface = shapes__circles__surface ;
 __QG__shapes__types__dynamic = shapes__types__dynamic ;
 __QG__shapes__types__surface = shapes__types__surface ;
 __QG__shapes__lookups__dynamic = shapes__lookups__dynamic ;
 __QG__shapes__lookups__surface = shapes__lookups__surface ;
 __QG__circle__radius = __PG__radius ;
 __QG____buffer_size = __QG__shapes__circles__dynamic ? ((u64*) __QG__shapes__circles__dynamic )[1]:0 ;
 __QG____CG = 1 ;
 if(! __QG__shapes__circles__dynamic )goto __QG____DG ;
 __QG__shapes__circles__dynamic____buffer_alignment = 1 ;
 __QG__shapes__circles__dynamic____buffer_size = ((u64*) __QG__shapes__circles__dynamic )[1] ;
 __QG__shapes__circles__dynamic____buffer_capacity = ((u64*) __QG__shapes__circles__dynamic )[2] & ~(1ULL << 63) ;
 if( __QG__shapes__circles__dynamic____buffer_size >= __QG__shapes__circles__dynamic____buffer_capacity ){ if( ((u64*) __QG__shapes__circles__dynamic )[2] & (1ULL << 63) )goto __QG____DG ;
 __QG__shapes__circles__dynamic____buffer_prev_capacity = __QG__shapes__circles__dynamic____buffer_capacity ;
 __QG__shapes__circles__dynamic____buffer_capacity = __QG__shapes__circles__dynamic____buffer_capacity +( __QG__shapes__circles__dynamic____buffer_capacity >>2)+1; if( __QG__shapes__circles__dynamic____buffer_size ) ((void**) __QG__shapes__circles__dynamic )[0] = __runtime_realloc((u64*)((void**) __QG__shapes__circles__dynamic )[0],  __QG__shapes__circles__dynamic____buffer_capacity * __QG__shapes__circles__dynamic____buffer_alignment *sizeof(u64),  __QG__shapes__circles__dynamic____buffer_prev_capacity * __QG__shapes__circles__dynamic____buffer_alignment *sizeof(u64)); else ((void**) __QG__shapes__circles__dynamic )[0] = __runtime_alloc( __QG__shapes__circles__dynamic____buffer_capacity * __QG__shapes__circles__dynamic____buffer_alignment *sizeof(u64)); ((u64*) __QG__shapes__circles__dynamic )[2] = __QG__shapes__circles__dynamic____buffer_capacity ;
 __QG__shapes__circles__dynamic____buffer_contents = (ptr)((void**) __QG__shapes__circles__dynamic )[0] ;
 if( ! __QG__shapes__circles__dynamic____buffer_contents )goto __QG____DG ;
 } else  __QG__shapes__circles__dynamic____buffer_contents = (ptr)(((u64*) __QG__shapes__circles__dynamic )[0]) ;
 ((u64*) __QG__shapes__circles__dynamic )[1] = __QG__shapes__circles__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __QG__shapes__circles__dynamic____buffer_contents )[ __QG__shapes__circles__dynamic____buffer_size * __QG__shapes__circles__dynamic____buffer_alignment +0], & __QG__circle__radius , sizeof(f64)); __QG__squares__dynamic = __QG__shapes__squares__dynamic ;
 __QG__squares__surface = __QG__shapes__squares__surface ;
 __QG__circles__dynamic = __QG__shapes__circles__dynamic ;
 __QG__circles__surface = __QG__shapes__circles__surface ;
 __QG__types__dynamic = __QG__shapes__types__dynamic ;
 __QG__types__surface = __QG__shapes__types__surface ;
 __QG__lookups__dynamic = __QG__shapes__lookups__dynamic ;
 __QG__lookups__surface = __QG__shapes__lookups__surface ;
 goto __QG____end ;
 __QG____end :
 shapes____NF = __QG__shapes____NF ;
 shapes__squares__dynamic = __QG__shapes__squares__dynamic ;
 shapes__squares__surface = __QG__shapes__squares__surface ;
 shapes__circles__dynamic = __QG__shapes__circles__dynamic ;
 shapes__circles__surface = __QG__shapes__circles__surface ;
 shapes__types__dynamic = __QG__shapes__types__dynamic ;
 shapes__types__surface = __QG__shapes__types__surface ;
 shapes__lookups__dynamic = __QG__shapes__lookups__dynamic ;
 shapes__lookups__surface = __QG__shapes__lookups__surface ;
 if( __OF__dynamic ){if((u64*)((u64*) __OF__dynamic )[2]) __runtime_free((u64*)((u64*) __OF__dynamic )[0]) ;
 __runtime_free( __OF__dynamic ) ;
 __OF__dynamic = 0 ;
 } if( __PF__dynamic ){if((u64*)((u64*) __PF__dynamic )[2]) __runtime_free((u64*)((u64*) __PF__dynamic )[0]) ;
 __runtime_free( __PF__dynamic ) ;
 __PF__dynamic = 0 ;
 } if( __QF__dynamic ){if((u64*)((u64*) __QF__dynamic )[2]) __runtime_free((u64*)((u64*) __QF__dynamic )[0]) ;
 __runtime_free( __QF__dynamic ) ;
 __QF__dynamic = 0 ;
 } if( __RF__dynamic ){if((u64*)((u64*) __RF__dynamic )[2]) __runtime_free((u64*)((u64*) __RF__dynamic )[0]) ;
 __runtime_free( __RF__dynamic ) ;
 __RF__dynamic = 0 ;
 } __RG__shapes__squares__dynamic = shapes__squares__dynamic ;
 __RG__shapes__squares__surface = shapes__squares__surface ;
 __RG__shapes__circles__dynamic = shapes__circles__dynamic ;
 __RG__shapes__circles__surface = shapes__circles__surface ;
 __RG__shapes__types__dynamic = shapes__types__dynamic ;
 __RG__shapes__types__surface = shapes__types__surface ;
 __RG__shapes__lookups__dynamic = shapes__lookups__dynamic ;
 __RG__shapes__lookups__surface = shapes__lookups__surface ;
 __RG____buffer_size = __RG__shapes__types__dynamic ? ((u64*) __RG__shapes__types__dynamic )[1]:0 ;
 goto __RG____end ;
 __RG____end :
 __SG__end = __RG____buffer_size ;
 __SG____wD = 0 ;
 __SG____xD = 1 ;
 __SG____yD__start = __SG____wD ;
 __SG____yD__end = __SG__end ;
 __SG____yD__step = __SG____xD ;
 __SG____yD__pos = __SG____yD__start ;
 goto __SG____yD____end ;
 __SG____yD____end :
 __SG__start = __SG____yD__start ;
 __SG__end = __SG____yD__end ;
 __SG__step = __SG____yD__step ;
 __SG__pos = __SG____yD__pos ;
 goto __SG____end ;
 __SG____end :
 __TG__loop :
 __UG__self__start = __SG__start ;
 __UG__self__end = __SG__end ;
 __UG__self__step = __SG__step ;
 __UG__self__pos = __SG__pos ;
 __UG__value = i ;
 __UG__value = __UG__self__pos ;
 __UG____zD = 1 ;
 __UG____0D__x = __UG__self__pos ;
 __UG____0D__y = __UG____zD ;
 __UG____0D__z = __UG____0D__x + __UG____0D__y ; 
 goto __UG____0D____end ;
 __UG____0D____end :
 __UG__self__pos = __UG____0D__z ;
 __UG____1D__x = __UG__self__pos ;
 __UG____1D__y = __UG__self__end ;
 __UG____1D__z = __UG____1D__x <= __UG____1D__y ; 
 goto __UG____1D____end ;
 __UG____1D____end :
 goto __UG____end ;
 __UG____end :
 __SG__start = __UG__self__start ;
 __SG__end = __UG__self__end ;
 __SG__step = __UG__self__step ;
 __SG__pos = __UG__self__pos ;
 i = __UG__value ;
 if(! __UG____1D__z )goto __TG__while ;
 __XG__side = 0 ;
 __YG__side = __XG__side ;
 goto __YG____end ;
 __YG____end :
 __ZG__self__squares__dynamic = shapes__squares__dynamic ;
 __ZG__self__squares__surface = shapes__squares__surface ;
 __ZG__self__circles__dynamic = shapes__circles__dynamic ;
 __ZG__self__circles__surface = shapes__circles__surface ;
 __ZG__self__types__dynamic = shapes__types__dynamic ;
 __ZG__self__types__surface = shapes__types__surface ;
 __ZG__self__lookups__dynamic = shapes__lookups__dynamic ;
 __ZG__self__lookups__surface = shapes__lookups__surface ;
 __ZG__pos = i ;
 __ZG____YF__side = __YG__side ;
 if(! __ZG__self__types__dynamic )goto __ZG____ZF ;
 __ZG__self__types__dynamic____buffer_alignment = 1 ;
 __ZG__self__types__dynamic____buffer_size = ((u64*) __ZG__self__types__dynamic )[1] ;
 if( __ZG__pos >= __ZG__self__types__dynamic____buffer_size )goto __ZG____ZF ;
 memcpy(& __ZG____bF , &((u64*)((u64*) __ZG__self__types__dynamic )[0])[ __ZG__pos * __ZG__self__types__dynamic____buffer_alignment +0], sizeof( u64 )) ;
 __ZG____aF = __ZG____bF ;
 __ZG__type = __ZG____aF ;
 __ZG____cF = 1 ;
 __ZG____dF__x = __ZG__type ;
 __ZG____dF__y = __ZG____cF ;
 __ZG____dF__z =( __ZG____dF__x == __ZG____dF__y ); 
 goto __ZG____dF____end ;
 __ZG____dF____end :
 goto __ZG____end ;
 __ZG____end :
 if(! __ZG____dF__z )goto __VG__fi ;
 __bG__side = 0 ;
 __cG__side = __bG__side ;
 goto __cG____end ;
 __cG____end :
 __dG__shapes__squares__dynamic = shapes__squares__dynamic ;
 __dG__shapes__squares__surface = shapes__squares__surface ;
 __dG__shapes__circles__dynamic = shapes__circles__dynamic ;
 __dG__shapes__circles__surface = shapes__circles__surface ;
 __dG__shapes__types__dynamic = shapes__types__dynamic ;
 __dG__shapes__types__surface = shapes__types__surface ;
 __dG__shapes__lookups__dynamic = shapes__lookups__dynamic ;
 __dG__shapes__lookups__surface = shapes__lookups__surface ;
 __dG__pos = i ;
 __dG____uF__side = __cG__side ;
 if(! __dG__shapes__types__dynamic )goto __dG____vF ;
 __dG__shapes__types__dynamic____buffer_alignment = 1 ;
 __dG__shapes__types__dynamic____buffer_size = ((u64*) __dG__shapes__types__dynamic )[1] ;
 if( __dG__pos >= __dG__shapes__types__dynamic____buffer_size )goto __dG____vF ;
 memcpy(& __dG____xF , &((u64*)((u64*) __dG__shapes__types__dynamic )[0])[ __dG__pos * __dG__shapes__types__dynamic____buffer_alignment +0], sizeof( u64 )) ;
 __dG____wF = __dG____xF ;
 __dG__type = __dG____wF ;
 __dG____zF = 1 ;
 __dG____0F__x = __dG__type ;
 __dG____0F__y = __dG____zF ;
 __dG____0F__z =( __dG____0F__x != __dG____0F__y ); 
 goto __dG____0F____end ;
 __dG____0F____end :
 if(! __dG____0F__z )goto __dG____yF__fi ;
 __dG____1F = "Trying to access a non-square" ;
 __dG____2F__error = __dG____1F ;
 goto __dG____2F____pD ;
 __builtin_unreachable();
 __dG____2F____end :
 goto __dG____yF__if ;
 __dG____yF__if :
 __dG____yF__fi :
 if(! __dG__shapes__lookups__dynamic )goto __dG____3F ;
 __dG__shapes__lookups__dynamic____buffer_alignment = 1 ;
 __dG__shapes__lookups__dynamic____buffer_size = ((u64*) __dG__shapes__lookups__dynamic )[1] ;
 if( __dG__pos >= __dG__shapes__lookups__dynamic____buffer_size )goto __dG____3F ;
 memcpy(& __dG____5F , &((u64*)((u64*) __dG__shapes__lookups__dynamic )[0])[ __dG__pos * __dG__shapes__lookups__dynamic____buffer_alignment +0], sizeof( u64 )) ;
 __dG____4F = __dG____5F ;
 __dG__lookup = __dG____4F ;
 if(! __dG__shapes__squares__dynamic )goto __dG____6F ;
 __dG__shapes__squares__dynamic____buffer_alignment = 1 ;
 __dG__shapes__squares__dynamic____buffer_size = ((u64*) __dG__shapes__squares__dynamic )[1] ;
 if( __dG__lookup >= __dG__shapes__squares__dynamic____buffer_size )goto __dG____6F ;
 memcpy(& __dG____9F , &((u64*)((void**) __dG__shapes__squares__dynamic )[0])[ __dG__lookup * __dG__shapes__squares__dynamic____buffer_alignment +0], sizeof( f64 )) ;
 __dG____7F__side = __dG____9F ;
 __dG__side = __dG____7F__side ;
 goto __dG____end ;
 __dG____end :
 __eG = 1.0 ;
 __fG__base__side = __dG__side ;
 __fG__height = __eG ;
 __fG____LF__self__side = __fG__base__side ;
 __fG____LF____IF__x = __fG____LF__self__side ;
 __fG____LF____IF__y = __fG____LF__self__side ;
 __fG____LF____IF__z = __fG____LF____IF__x * __fG____LF____IF__y ; 
 goto __fG____LF____IF____end ;
 __fG____LF____IF____end :
 goto __fG____LF____end ;
 __fG____LF____end :
 __fG____MF__x = __fG____LF____IF__z ;
 __fG____MF__y = __fG__height ;
 __fG____MF__z = __fG____MF__x * __fG____MF__y ; 
 goto __fG____MF____end ;
 __fG____MF____end :
 goto __fG____end ;
 __fG____end :
 __gG__message = __fG____MF__z ;
 printf ( "%.6f\n" , __gG__message ); 
 __gG____end :
 __VG__if :
 __VG__fi :
 goto __TG__loop ;
 __TG__while :
 __end :
goto __return;

// ERROR HANDLING
__LG____BG :
printf("Buffer error \n");
__result__errocode=__BUFFER__ERROR;
goto __failsafe;
 __QG____DG :
printf("Buffer error \n");
__result__errocode=__BUFFER__ERROR;
goto __failsafe;
 __ZG____ZF :
printf("Buffer index out of range\n");
__result__errocode=__BUFFER__ERROR;
goto __failsafe;
 __dG____vF :
printf("Buffer index out of range\n");
__result__errocode=__BUFFER__ERROR;
goto __failsafe;
 __dG____2F____pD :
 printf ( "%s\n" , __dG____2F__error ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __dG____3F :
printf("Buffer index out of range\n");
__result__errocode=__BUFFER__ERROR;
goto __failsafe;
 __dG____6F :
printf("Buffer index out of range\n");
__result__errocode=__BUFFER__ERROR;
goto __failsafe;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
if( __GG__circles__dynamic ){if((u64*)((u64*) __GG__circles__dynamic )[2]) __runtime_free((u64*)((u64*) __GG__circles__dynamic )[0]) ;
 __runtime_free( __GG__circles__dynamic ) ;
 __GG__circles__dynamic = 0 ;
 }if( __GG__lookups__dynamic ){if((u64*)((u64*) __GG__lookups__dynamic )[2]) __runtime_free((u64*)((u64*) __GG__lookups__dynamic )[0]) ;
 __runtime_free( __GG__lookups__dynamic ) ;
 __GG__lookups__dynamic = 0 ;
 }if( __GG__types__dynamic ){if((u64*)((u64*) __GG__types__dynamic )[2]) __runtime_free((u64*)((u64*) __GG__types__dynamic )[0]) ;
 __runtime_free( __GG__types__dynamic ) ;
 __GG__types__dynamic = 0 ;
 }if( __GG__squares__dynamic ){if((u64*)((u64*) __GG__squares__dynamic )[2]) __runtime_free((u64*)((u64*) __GG__squares__dynamic )[0]) ;
 __runtime_free( __GG__squares__dynamic ) ;
 __GG__squares__dynamic = 0 ;
 }__state->err =  __result__errocode;
}



int main() {
struct main__215__state __main_args={0};
__smolambda_initialize_service_tasks(main__215, &__main_args);
return __main_args.err;
}

