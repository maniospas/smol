#define SMOLAMBDA_SERVICES 2
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

#include<stdio.h>

#include "std/oscommon.h"

#include "raylib.h"

struct main__948__state{errcode err;};
void main__948(void *__void__state);
struct test__947__state{errcode err;};
void test__947(void *__void__state);

void test__947(void *__void__state){
errcode __result__errocode=0;
struct test__947__state *__state=(struct test__947__state*)__void__state;
f64 __OHB__z=0;
f64 __NHB__z=0;
f64 __MHB=0;
f64 __JHB=0;
f64 __IHB__z=0;
f64 __HHB=0;
f64 __GHB__z=0;
f64 __FHB__elapsed=0;
cstr __DHB__title=0;
cstr __CHB____IFB____AFB=0;
bool __CHB____IFB____9EB__z=0;
u64 __CHB____IFB____8EB=0;
cstr __CHB____IFB____0EB=0;
bool __CHB____IFB____zEB__z=0;
bool __fGB____mW____WI____6G__z=0;
char __fGB____mW____UI=0;
f64 accum_fps=0;
f64 __bGB=0;
f64 __aGB__elapsed=0;
f64 __kGB____9FB__y=0;
f64 prev_t=0;
u64 __rGB____wD=0;
char __4GB__first=0;
cstr __YGB=0;
f64 __XGB=0;
f64 __WGB=0;
f64 __TGB=0;
ptr spheres__dynamic=0;
f64 __RGB=0;
nominal window____CFB=0;
f64 dt=0;
f64 __OGB=0;
ptr __GGB__dynamic____buffer_contents=0;
u64 __4GB____Dc____fU__bytesize=0;
ptr __GGB__dynamic=0;
f64 __kGB____FGB____ZFB__z=0;
f64 __wGB=0;
u64 __2GB____Eo____Wm____fU__bytesize=0;
u64 __AHB=0;
f64 __kGB____AGB=0;
f64 __kGB____FGB____yFB__z=0;
char __2GB____Eo____Um=0;
u64 __kGB____6FB____xD=0;
ptr spheres__surface=0;
f64 __kGB____FGB____sFB____Z=0;
cstr __0GB____4FB____IFB____5EB=0;
cstr __fGB____mW____WI____7G=0;
bool __CHB____IFB____4EB__z=0;
f64 __kGB____FGB____eFB=0;
u64 __GGB__dynamic____buffer_size=0;
f64 __kGB____FGB__s__dy=0;
nominal __iGB____DFB____CFB=0;
char __fGB____mW____WI____LH____CF=0;
f64 __lGB__size__w=0;
u64 __2GB__allocator__cycles=0;
f64 __QGB=0;
cstr __3GB=0;
f64 __JGB=0;
f64 __NGB=0;
u64 __4GB__total_len=0;
nominal __fGB____nW__contents____9E=0;
f64 __jGB__elapsed=0;
f64 __KHB__z=0;
f64 __lGB__size__h=0;
u64 __kGB__i=0;
ptr __GGB__surface=0;
u64 __fGB____nW__cycles=0;
f64 __kGB____FGB____dFB__z=0;
bool __0GB____4FB____IFB____uEB__z=0;
u64 __CHB____IFB____yEB=0;
f64 __yGB=0;
u64 __2GB____Eo____Tm=0;
f64 __KGB=0;
f64 __kGB____9FB__dx=0;
bool __kGB____8FB____1D__z=0;
u64 __GGB__dynamic____buffer_capacity=0;
u64 __2GB__allocator__contents__bytesize=0;
f64 __6GB=0;
u64 __4GB__len_y=0;
u64 __buffer_size=0;
char __2GB____Eo____Wm____VU=0;
u64 __eGB=0;
u64 __kGB____8FB__value=0;
nominal __2GB____Eo____Wm__self__contents____9E=0;
u64 __GGB__dynamic____buffer_alignment=0;
bool __iGB__ret=0;
ptr __fGB____mW____WI__mem=0;
u64 __tGB____0D__z=0;
f64 __HGB=0;
char __4GB____Bc=0;
u64 __CHB____IFB____3EB=0;
f64 window__size__w=0;
u64 __4GB____Ac__z=0;
cstr __4GB____Dc____YU=0;
nominal __4GB____Dc__self__contents____AF____1E=0;
f64 __LGB=0;
ptr __2GB____Eo____Ym__x=0;
char __4GB____Dc____fU____CF=0;
char __2GB____Eo____Wm____dU=0;
f64 __kGB____FGB____qFB=0;
u64 __4GB____9b=0;
ptr __fGB____nW__contents__mem=0;
bool __kGB____FGB____rFB__z=0;
f64 __DHB__size__h=0;
u64 __BHB=0;
u64 __4GB__len_x=0;
char __fGB____mW____WI____JH=0;
u64 __kGB____6FB____wD=0;
f64 __kGB____9FB__x=0;
bool __CHB____IFB____uEB__z=0;
f64 window__size__h=0;
f64 __kGB____FGB____gFB____a__z=0;
u64 __0GB____4FB____IFB____tEB=0;
cstr __fGB____mW____WI____DH=0;
u64 __rGB__end=0;
ptr __2GB____Eo__contents=0;
u64 __tGB____zD=0;
u64 __fGB____nW__length=0;
bool __2GB____Eo____Ym__z=0;
bool __pGB____IFB____9EB__z=0;
f64 __kGB____FGB____sFB____a__z=0;
bool __pGB____IFB____uEB__z=0;
f64 __kGB____EGB=0;
u64 __pGB____IFB____tEB=0;
f64 __IGB=0;
f64 __kGB____FGB__s__x=0;
char __fGB____mW____WI____9G=0;
u64 __kGB__spheres__dynamic____buffer_alignment=0;
bool __fGB____mW____WI____BH=0;
u64 __kGB__spheres__dynamic____buffer_size=0;
bool __fGB____mW____WI____CH__z=0;
f64 __qGB__size__w=0;
nominal __fGB____nW__type=0;
u64 __fGB____nW__contents__size=0;
bool __PHB____XFB__z=0;
u64 i=0;
char __fGB____nW__contents____BF=0;
ptr __fGB____nW__contents__underlying=0;
u64 __rGB__step=0;
u64 __fGB____nW__contents__bytesize=0;
u64 __fGB____nW____YP=0;
u64 __fGB____nW____ZP=0;
bool __iGB____EFB__x=0;
bool __iGB____EFB__z=0;
f64 __PGB=0;
ptr __4GB____8b__contents=0;
f64 __kGB____FGB__s__dx=0;
u64 __GGB__dynamic____buffer_prev_capacity=0;
u64 __kGB____8FB__self__pos=0;
u64 __kGB____6FB__pos=0;
u64 __kGB____8FB____zD=0;
u64 __fGB____mW____WI____5G=0;
cstr __lGB__title=0;
f64 __kGB____BGB=0;
f64 __kGB____9FB__r=0;
f64 __kGB____9FB__dy=0;
f64 __kGB____FGB__s__y=0;
char __4GB____Dc____dU=0;
f64 __kGB____FGB____YFB__z=0;
f64 __kGB____FGB__nx=0;
f64 __kGB____FGB____aFB__z=0;
f64 __vGB=0;
f64 __kGB____FGB____bFB__z=0;
f64 __kGB____FGB__ny=0;
f64 __kGB____FGB__ndy=0;
ptr __2GB__allocator__contents__mem=0;
bool __kGB____FGB____fFB__z=0;
nominal __DHB__window____CFB=0;
f64 __kGB____FGB____gFB____Z=0;
f64 __kGB____FGB____iFB__z=0;
u64 __rGB__pos=0;
f64 __kGB____FGB____jFB=0;
bool __kGB____FGB____kFB__z=0;
f64 __kGB____FGB____lFB=0;
u64 __9GB=0;
u64 __kGB____8FB____0D__z=0;
f64 __kGB____FGB____mFB__z=0;
u64 __kGB____buffer_size=0;
f64 __kGB____FGB____nFB____Z=0;
f64 __kGB____FGB____nFB____a__z=0;
f64 __kGB____FGB____pFB__z=0;
u64 __pGB____IFB____3EB=0;
bool __0GB____4FB____IFB____zEB__z=0;
u64 __oGB=0;
f64 __kGB____FGB____vFB=0;
bool __kGB____FGB____wFB__z=0;
f64 __kGB____FGB____xFB=0;
f64 __kGB____FGB__ndx=0;
f64 __kGB____FGB____zFB____Z=0;
f64 __kGB____FGB____zFB____a__z=0;
nominal __lGB__window____CFB=0;
ptr __4GB____8b____m__contents=0;
cstr __pGB____IFB____AFB=0;
u64 __nGB=0;
u64 __pGB____HFB=0;
f64 __EHB__size__w=0;
u64 __0GB____4FB____IFB____8EB=0;
bool __pGB____IFB____zEB__z=0;
f64 __PHB____WFB=0;
cstr __pGB____IFB____0EB=0;
cstr window__title=0;
u64 __fGB____mW____WI____LH__bytesize=0;
bool __pGB____IFB____4EB__z=0;
u64 __tGB__value=0;
bool __0GB____4FB____IFB____9EB__z=0;
f64 __LHB__z=0;
cstr __pGB____IFB____5EB=0;
cstr __CHB____IFB____vEB=0;
u64 __mGB=0;
u64 __pGB____IFB____8EB=0;
f64 __8GB=0;
u64 __rGB____xD=0;
u64 __rGB__start=0;
u64 __tGB__self__pos=0;
bool __tGB____1D__z=0;
f64 __kGB____DGB=0;
u64 spheres__dynamic____buffer_size=0;
f64 __xGB=0;
f64 __DHB__size__w=0;
f64 __0GB____5FB__size__w=0;
cstr __2GB____Eo____Wm____YU=0;
u64 __0GB____1FB=0;
u64 __0GB____2FB=0;
u64 __0GB____3FB=0;
f64 __kGB____FGB____uFB__z=0;
u64 __0GB____4FB____HFB=0;
cstr __0GB____4FB____IFB____vEB=0;
u64 __0GB____4FB____IFB____yEB=0;
nominal __4GB____Dc__self__contents____9E=0;
cstr __0GB____4FB____IFB____0EB=0;
u64 __0GB____4FB____IFB____3EB=0;
bool __0GB____4FB____IFB____4EB__z=0;
cstr __0GB____4FB____IFB____AFB=0;
nominal __0GB____5FB__window____CFB=0;
cstr __pGB____IFB____vEB=0;
u64 __1GB=0;
u64 __2GB__allocator__contents__size=0;
char __2GB__allocator__contents____BF=0;
ptr __2GB__allocator__contents__underlying=0;
u64 __2GB__allocator__length=0;
u64 __2GB____Eo____Wm__size=0;
u64 __2GB____Eo____Wm____XU__x=0;
char __fGB____nW____cP=0;
bool __2GB____Eo____Wm____XU__z=0;
char __fGB____nW____bP=0;
ptr __2GB____Eo____Wm___contents=0;
char __2GB____Eo____Wm____fU____CF=0;
u64 __2GB____Eo__length=0;
char __2GB____Eo__first=0;
char __4GB____Dc____VU=0;
u64 spheres__dynamic____buffer_alignment=0;
f64 __kGB____CGB=0;
bool __2GB____Eo____Zm__z=0;
nominal __2GB____Eo____Wm__self__type=0;
nominal __fGB____nW__contents____AF____1E=0;
cstr __CHB____IFB____5EB=0;
nominal __2GB____Eo____Wm__self__contents____AF____1E=0;
u64 __4GB____8b__length=0;
char __4GB____8b__first=0;
ptr __4GB____8b__noptr=0;
u64 __4GB____Dc__size=0;
u64 __4GB____Dc____XU__x=0;
bool __4GB____Dc____XU__z=0;
ptr __4GB____Dc___contents=0;
ptr __4GB____Gc__contents=0;
nominal __4GB____Dc__self__type=0;
u64 __pGB____IFB____yEB=0;
f64 __5GB=0;
u64 __CHB____HFB=0;
f64 __zGB=0;
u64 __CHB____IFB____tEB=0;

// IMPLEMENTATION
__GGB__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 __GGB__surface = 0 ;
 __HGB = 100.0 ;
 __IGB = 100.0 ;
 __JGB = 30.0 ;
 __KGB = 1000.0 ;
 __LGB = 650.0 ;
 if(! __GGB__dynamic )goto __result__buffer_error ;
 __GGB__dynamic____buffer_alignment = 5 ;
 __GGB__dynamic____buffer_size = ((u64*) __GGB__dynamic )[1] ;
 __GGB__dynamic____buffer_capacity = ((u64*) __GGB__dynamic )[2] & ~(1ULL << 63) ;
 if( __GGB__dynamic____buffer_size >= __GGB__dynamic____buffer_capacity ){ if( ((u64*) __GGB__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __GGB__dynamic____buffer_prev_capacity = __GGB__dynamic____buffer_capacity ;
 __GGB__dynamic____buffer_capacity = __GGB__dynamic____buffer_capacity +( __GGB__dynamic____buffer_capacity >>2)+1; if( __GGB__dynamic____buffer_size ) ((void**) __GGB__dynamic )[0] = __runtime_realloc((u64*)((void**) __GGB__dynamic )[0],  __GGB__dynamic____buffer_capacity * __GGB__dynamic____buffer_alignment *sizeof(u64),  __GGB__dynamic____buffer_prev_capacity * __GGB__dynamic____buffer_alignment *sizeof(u64)); else ((void**) __GGB__dynamic )[0] = __runtime_alloc( __GGB__dynamic____buffer_capacity * __GGB__dynamic____buffer_alignment *sizeof(u64)); ((u64*) __GGB__dynamic )[2] = __GGB__dynamic____buffer_capacity ;
 __GGB__dynamic____buffer_contents = (ptr)((void**) __GGB__dynamic )[0] ;
 if( ! __GGB__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  __GGB__dynamic____buffer_contents = (ptr)(((u64*) __GGB__dynamic )[0]) ;
 ((u64*) __GGB__dynamic )[1] = __GGB__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __GGB__dynamic____buffer_contents )[ __GGB__dynamic____buffer_size * __GGB__dynamic____buffer_alignment +0], & __HGB , sizeof(f64)); memcpy(&((u64*) __GGB__dynamic____buffer_contents )[ __GGB__dynamic____buffer_size * __GGB__dynamic____buffer_alignment +1], & __IGB , sizeof(f64)); memcpy(&((u64*) __GGB__dynamic____buffer_contents )[ __GGB__dynamic____buffer_size * __GGB__dynamic____buffer_alignment +2], & __JGB , sizeof(f64)); memcpy(&((u64*) __GGB__dynamic____buffer_contents )[ __GGB__dynamic____buffer_size * __GGB__dynamic____buffer_alignment +3], & __KGB , sizeof(f64)); memcpy(&((u64*) __GGB__dynamic____buffer_contents )[ __GGB__dynamic____buffer_size * __GGB__dynamic____buffer_alignment +4], & __LGB , sizeof(f64)); __NGB = 100.0 ;
 __OGB = 100.0 ;
 __PGB = 30.0 ;
 __QGB = 450.0 ;
 __RGB = 600.0 ;
 if(! __GGB__dynamic )goto __result__buffer_error ;
 __GGB__dynamic____buffer_alignment = 5 ;
 __GGB__dynamic____buffer_size = ((u64*) __GGB__dynamic )[1] ;
 __GGB__dynamic____buffer_capacity = ((u64*) __GGB__dynamic )[2] & ~(1ULL << 63) ;
 if( __GGB__dynamic____buffer_size >= __GGB__dynamic____buffer_capacity ){ if( ((u64*) __GGB__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __GGB__dynamic____buffer_prev_capacity = __GGB__dynamic____buffer_capacity ;
 __GGB__dynamic____buffer_capacity = __GGB__dynamic____buffer_capacity +( __GGB__dynamic____buffer_capacity >>2)+1; if( __GGB__dynamic____buffer_size ) ((void**) __GGB__dynamic )[0] = __runtime_realloc((u64*)((void**) __GGB__dynamic )[0],  __GGB__dynamic____buffer_capacity * __GGB__dynamic____buffer_alignment *sizeof(u64),  __GGB__dynamic____buffer_prev_capacity * __GGB__dynamic____buffer_alignment *sizeof(u64)); else ((void**) __GGB__dynamic )[0] = __runtime_alloc( __GGB__dynamic____buffer_capacity * __GGB__dynamic____buffer_alignment *sizeof(u64)); ((u64*) __GGB__dynamic )[2] = __GGB__dynamic____buffer_capacity ;
 __GGB__dynamic____buffer_contents = (ptr)((void**) __GGB__dynamic )[0] ;
 if( ! __GGB__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  __GGB__dynamic____buffer_contents = (ptr)(((u64*) __GGB__dynamic )[0]) ;
 ((u64*) __GGB__dynamic )[1] = __GGB__dynamic____buffer_size +1 ;
 memcpy(&((u64*) __GGB__dynamic____buffer_contents )[ __GGB__dynamic____buffer_size * __GGB__dynamic____buffer_alignment +0], & __NGB , sizeof(f64)); memcpy(&((u64*) __GGB__dynamic____buffer_contents )[ __GGB__dynamic____buffer_size * __GGB__dynamic____buffer_alignment +1], & __OGB , sizeof(f64)); memcpy(&((u64*) __GGB__dynamic____buffer_contents )[ __GGB__dynamic____buffer_size * __GGB__dynamic____buffer_alignment +2], & __PGB , sizeof(f64)); memcpy(&((u64*) __GGB__dynamic____buffer_contents )[ __GGB__dynamic____buffer_size * __GGB__dynamic____buffer_alignment +3], & __QGB , sizeof(f64)); memcpy(&((u64*) __GGB__dynamic____buffer_contents )[ __GGB__dynamic____buffer_size * __GGB__dynamic____buffer_alignment +4], & __RGB , sizeof(f64)); spheres__dynamic = __GGB__dynamic ;
 spheres__surface = __GGB__surface ;
 __TGB = 0.0 ;
 dt = __TGB ;
 __WGB = 800.0 ;
 __XGB = 450.0 ;
 __YGB = "Hello from smoλ+raylib" ;
 SetTraceLogLevel ( LOG_WARNING ); InitWindow ( __WGB , __XGB ,( char *) __YGB ); 
 __ZGB____end :
 window__size__w = __WGB ;
 window__size__h = __XGB ;
 window__title = __YGB ;
 __aGB__elapsed = __smo_time_eta (); 
 __aGB____end :
 prev_t = __aGB__elapsed ;
 __bGB = 60.0 ;
 accum_fps = __bGB ;
 __eGB = 1024 ;
 __fGB____mW____UI = 0 ;
 __fGB____mW____WI____5G = 0 ;
 __fGB____mW____WI____6G__z =( __eGB == __fGB____mW____WI____5G ); 
 __fGB____mW____WI____6G____end :
 if(! __fGB____mW____WI____6G__z )goto __fGB____mW____WI____4G__fi ;
 __fGB____mW____WI____7G = "Cannot allocate zero size" ;
 goto __fGB____mW____WI____8G____oD ;
 __builtin_unreachable();
 __fGB____mW____WI____4G__fi :
 __fGB____mW____WI__mem = __runtime_alloc ( __eGB * sizeof ( __fGB____mW____WI____9G )); 
 __fGB____mW____WI____BH = __fGB____mW____WI__mem ;
 __fGB____mW____WI____CH__z =(! __fGB____mW____WI____BH ); 
 __fGB____mW____WI____CH____end :
 if(! __fGB____mW____WI____CH__z )goto __fGB____mW____WI____AH__fi ;
 __fGB____mW____WI____DH = "Failed a Heap allocation" ;
 goto __fGB____mW____WI____EH____oD ;
 __builtin_unreachable();
 __fGB____mW____WI____AH__fi :
 __fGB____mW____WI____JH = 0 ;
 __fGB____mW____WI____LH__bytesize = sizeof ( __fGB____mW____WI____LH____CF )* __eGB ; 
 __fGB____mW____WI____LH____end :
 __fGB____nW__contents__size = __eGB ;
 __fGB____nW__contents____BF = __fGB____mW____WI____JH ;
 __fGB____nW__contents__mem = __fGB____mW____WI__mem ;
 __fGB____nW__contents__underlying = __fGB____mW____WI__mem ;
 __fGB____nW__contents__bytesize = __fGB____mW____WI____LH__bytesize ;
 __fGB____nW____YP = 0 ;
 __fGB____nW__length = __fGB____nW____YP ;
 __fGB____nW____ZP = 0 ;
 __fGB____nW__cycles = __fGB____nW____ZP ;
 __fGB____nW____bP = 0 ;
 __fGB____nW____cP = 0 ;
 __hGB__loop :
 __iGB__ret = WindowShouldClose (); 
 __iGB____EFB__x = __iGB__ret ;
 __iGB____EFB__z =(! __iGB____EFB__x ); 
 __iGB____EFB____end :
 window____CFB = __iGB____DFB____CFB ;
 if(! __iGB____EFB__z )goto __hGB__while ;
 __jGB__elapsed = __smo_time_eta (); 
 __jGB____end :
 __kGB____buffer_size = spheres__dynamic ? ((u64*) spheres__dynamic )[1]:0 ;
 __kGB____6FB____wD = 0 ;
 __kGB____6FB____xD = 1 ;
 __kGB____6FB__pos = __kGB____6FB____wD ;
 __kGB____7FB__loop :
 __kGB____8FB__self__pos = __kGB____6FB__pos ;
 __kGB____8FB__value = __kGB__i ;
 __kGB____8FB__value = __kGB____8FB__self__pos ;
 __kGB____8FB____zD = 1 ;
 __kGB____8FB____0D__z = __kGB____8FB__self__pos + __kGB____8FB____zD ; 
 __kGB____8FB____0D____end :
 __kGB____8FB__self__pos = __kGB____8FB____0D__z ;
 __kGB____8FB____1D__z = __kGB____8FB__self__pos <= __kGB____buffer_size ; 
 __kGB____8FB____1D____end :
 __kGB____6FB__pos = __kGB____8FB__self__pos ;
 if(! __kGB____8FB____1D__z )goto __kGB____7FB__while ;
 if(! spheres__dynamic )goto __result__buffer_error ;
 __kGB__spheres__dynamic____buffer_alignment = 5 ;
 __kGB__spheres__dynamic____buffer_size = ((u64*) spheres__dynamic )[1] ;
 if( __kGB____8FB__value >= __kGB__spheres__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(& __kGB____AGB , &((u64*)((void**) spheres__dynamic )[0])[ __kGB____8FB__value * __kGB__spheres__dynamic____buffer_alignment +0], sizeof( f64 )) ;
 __kGB____9FB__x = __kGB____AGB ;
 memcpy(& __kGB____BGB , &((u64*)((void**) spheres__dynamic )[0])[ __kGB____8FB__value * __kGB__spheres__dynamic____buffer_alignment +1], sizeof( f64 )) ;
 __kGB____9FB__y = __kGB____BGB ;
 memcpy(& __kGB____CGB , &((u64*)((void**) spheres__dynamic )[0])[ __kGB____8FB__value * __kGB__spheres__dynamic____buffer_alignment +2], sizeof( f64 )) ;
 __kGB____9FB__r = __kGB____CGB ;
 memcpy(& __kGB____DGB , &((u64*)((void**) spheres__dynamic )[0])[ __kGB____8FB__value * __kGB__spheres__dynamic____buffer_alignment +3], sizeof( f64 )) ;
 __kGB____9FB__dx = __kGB____DGB ;
 memcpy(& __kGB____EGB , &((u64*)((void**) spheres__dynamic )[0])[ __kGB____8FB__value * __kGB__spheres__dynamic____buffer_alignment +4], sizeof( f64 )) ;
 __kGB____9FB__dy = __kGB____EGB ;
 __kGB____FGB__s__x = __kGB____9FB__x ;
 __kGB____FGB__s__y = __kGB____9FB__y ;
 __kGB____FGB__s__dx = __kGB____9FB__dx ;
 __kGB____FGB__s__dy = __kGB____9FB__dy ;
 __kGB____FGB____YFB__z = __kGB____FGB__s__dx * dt ; 
 __kGB____FGB____YFB____end :
 __kGB____FGB____ZFB__z = __kGB____FGB__s__x + __kGB____FGB____YFB__z ; 
 __kGB____FGB____ZFB____end :
 __kGB____FGB__nx = __kGB____FGB____ZFB__z ;
 __kGB____FGB____aFB__z = __kGB____FGB__s__dy * dt ; 
 __kGB____FGB____aFB____end :
 __kGB____FGB____bFB__z = __kGB____FGB__s__y + __kGB____FGB____aFB__z ; 
 __kGB____FGB____bFB____end :
 __kGB____FGB__ny = __kGB____FGB____bFB__z ;
 __kGB____FGB__ndx = __kGB____FGB__s__dx ;
 __kGB____FGB__ndy = __kGB____FGB__s__dy ;
 __kGB____FGB____dFB__z = __kGB____FGB__nx - __kGB____9FB__r ; 
 __kGB____FGB____dFB____end :
 __kGB____FGB____eFB = 0.0 ;
 __kGB____FGB____fFB__z = __kGB____FGB____dFB__z < __kGB____FGB____eFB ; 
 __kGB____FGB____fFB____end :
 if(! __kGB____FGB____fFB__z )goto __kGB____FGB____cFB__fi ;
 __kGB____FGB__nx = __kGB____9FB__r ;
 __kGB____FGB____gFB____Z = 0.0 ;
 __kGB____FGB____gFB____a__z = __kGB____FGB____gFB____Z - __kGB____FGB__ndx ; 
 __kGB____FGB____gFB____a____end :
 __kGB____FGB__ndx = __kGB____FGB____gFB____a__z ;
 goto __kGB____FGB____cFB__el ;
 __kGB____FGB____cFB__fi :
 __kGB____FGB____iFB__z = __kGB____FGB__nx + __kGB____9FB__r ; 
 __kGB____FGB____iFB____end :
 __kGB____FGB____jFB = 800.0 ;
 __kGB____FGB____kFB__z = __kGB____FGB____iFB__z > __kGB____FGB____jFB ; 
 __kGB____FGB____kFB____end :
 if(! __kGB____FGB____kFB__z )goto __kGB____FGB____hFB__fi ;
 __kGB____FGB____lFB = 800.0 ;
 __kGB____FGB____mFB__z = __kGB____FGB____lFB - __kGB____9FB__r ; 
 __kGB____FGB____mFB____end :
 __kGB____FGB__nx = __kGB____FGB____mFB__z ;
 __kGB____FGB____nFB____Z = 0.0 ;
 __kGB____FGB____nFB____a__z = __kGB____FGB____nFB____Z - __kGB____FGB__ndx ; 
 __kGB____FGB____nFB____a____end :
 __kGB____FGB__ndx = __kGB____FGB____nFB____a__z ;
 __kGB____FGB____hFB__fi :
 __kGB____FGB____cFB__el :
 __kGB____FGB____pFB__z = __kGB____FGB__ny - __kGB____9FB__r ; 
 __kGB____FGB____pFB____end :
 __kGB____FGB____qFB = 0.0 ;
 __kGB____FGB____rFB__z = __kGB____FGB____pFB__z < __kGB____FGB____qFB ; 
 __kGB____FGB____rFB____end :
 if(! __kGB____FGB____rFB__z )goto __kGB____FGB____oFB__fi ;
 __kGB____FGB__ny = __kGB____9FB__r ;
 __kGB____FGB____sFB____Z = 0.0 ;
 __kGB____FGB____sFB____a__z = __kGB____FGB____sFB____Z - __kGB____FGB__ndy ; 
 __kGB____FGB____sFB____a____end :
 __kGB____FGB__ndy = __kGB____FGB____sFB____a__z ;
 goto __kGB____FGB____oFB__el ;
 __kGB____FGB____oFB__fi :
 __kGB____FGB____uFB__z = __kGB____FGB__ny + __kGB____9FB__r ; 
 __kGB____FGB____uFB____end :
 __kGB____FGB____vFB = 450.0 ;
 __kGB____FGB____wFB__z = __kGB____FGB____uFB__z > __kGB____FGB____vFB ; 
 __kGB____FGB____wFB____end :
 if(! __kGB____FGB____wFB__z )goto __kGB____FGB____tFB__fi ;
 __kGB____FGB____xFB = 450.0 ;
 __kGB____FGB____yFB__z = __kGB____FGB____xFB - __kGB____9FB__r ; 
 __kGB____FGB____yFB____end :
 __kGB____FGB__ny = __kGB____FGB____yFB__z ;
 __kGB____FGB____zFB____Z = 0.0 ;
 __kGB____FGB____zFB____a__z = __kGB____FGB____zFB____Z - __kGB____FGB__ndy ; 
 __kGB____FGB____zFB____a____end :
 __kGB____FGB__ndy = __kGB____FGB____zFB____a__z ;
 __kGB____FGB____tFB__fi :
 __kGB____FGB____oFB__el :
 __kGB____FGB__s__x = __kGB____FGB__nx ;
 __kGB____FGB__s__y = __kGB____FGB__ny ;
 __kGB____FGB__s__dx = __kGB____FGB__ndx ;
 __kGB____FGB__s__dy = __kGB____FGB__ndy ;
 __kGB____9FB__x = __kGB____FGB__s__x ;
 __kGB____9FB__y = __kGB____FGB__s__y ;
 __kGB____9FB__dx = __kGB____FGB__s__dx ;
 __kGB____9FB__dy = __kGB____FGB__s__dy ;
 memcpy(&((u64*)((u64*) spheres__dynamic )[0])[ __kGB____8FB__value * __kGB__spheres__dynamic____buffer_alignment +0], & __kGB____9FB__x , sizeof( __kGB____9FB__x )) ;
 memcpy(&((u64*)((u64*) spheres__dynamic )[0])[ __kGB____8FB__value * __kGB__spheres__dynamic____buffer_alignment +1], & __kGB____9FB__y , sizeof( __kGB____9FB__y )) ;
 memcpy(&((u64*)((u64*) spheres__dynamic )[0])[ __kGB____8FB__value * __kGB__spheres__dynamic____buffer_alignment +2], & __kGB____9FB__r , sizeof( __kGB____9FB__r )) ;
 memcpy(&((u64*)((u64*) spheres__dynamic )[0])[ __kGB____8FB__value * __kGB__spheres__dynamic____buffer_alignment +3], & __kGB____9FB__dx , sizeof( __kGB____9FB__dx )) ;
 memcpy(&((u64*)((u64*) spheres__dynamic )[0])[ __kGB____8FB__value * __kGB__spheres__dynamic____buffer_alignment +4], & __kGB____9FB__dy , sizeof( __kGB____9FB__dy )) ;
 goto __kGB____7FB__loop ;
 __kGB____7FB__while :
 BeginDrawing (); 
 __lGB__size__w = window__size__w ;
 __lGB__size__h = window__size__h ;
 __lGB__title = window__title ;
 window____CFB = __lGB__window____CFB ;
 __mGB = 50 ;
 __nGB = 50 ;
 __oGB = 80 ;
 __pGB____HFB = 255 ;
 __pGB____IFB____tEB = 255 ;
 __pGB____IFB____uEB__z = __mGB > __pGB____IFB____tEB ; 
 __pGB____IFB____uEB____end :
 if(! __pGB____IFB____uEB__z )goto __pGB____IFB____sEB__fi ;
 __pGB____IFB____vEB = "Color r greater than 255" ;
 goto __pGB____IFB____wEB____oD ;
 __builtin_unreachable();
 __pGB____IFB____sEB__fi :
 __pGB____IFB____yEB = 255 ;
 __pGB____IFB____zEB__z = __nGB > __pGB____IFB____yEB ; 
 __pGB____IFB____zEB____end :
 if(! __pGB____IFB____zEB__z )goto __pGB____IFB____xEB__fi ;
 __pGB____IFB____0EB = "Color g greater than 255" ;
 goto __pGB____IFB____1EB____oD ;
 __builtin_unreachable();
 __pGB____IFB____xEB__fi :
 __pGB____IFB____3EB = 255 ;
 __pGB____IFB____4EB__z = __oGB > __pGB____IFB____3EB ; 
 __pGB____IFB____4EB____end :
 if(! __pGB____IFB____4EB__z )goto __pGB____IFB____2EB__fi ;
 __pGB____IFB____5EB = "Color b greater than 255" ;
 goto __pGB____IFB____6EB____oD ;
 __builtin_unreachable();
 __pGB____IFB____2EB__fi :
 __pGB____IFB____8EB = 255 ;
 __pGB____IFB____9EB__z = __pGB____HFB > __pGB____IFB____8EB ; 
 __pGB____IFB____9EB____end :
 if(! __pGB____IFB____9EB__z )goto __pGB____IFB____7EB__fi ;
 __pGB____IFB____AFB = "Color a greater than 255" ;
 goto __pGB____IFB____BFB____oD ;
 __builtin_unreachable();
 __pGB____IFB____7EB__fi :
 ClearBackground (( Color ) {( unsigned char ) __mGB ,( unsigned char ) __nGB ,( unsigned char ) __oGB ,( unsigned char ) __pGB____HFB }); 
 __qGB__size__w = __lGB__size__w ;
 __buffer_size = spheres__dynamic ? ((u64*) spheres__dynamic )[1]:0 ;
 __rGB__end = __buffer_size ;
 __rGB____wD = 0 ;
 __rGB____xD = 1 ;
 __rGB__start = __rGB____wD ;
 __rGB__step = __rGB____xD ;
 __rGB__pos = __rGB____wD ;
 __sGB__loop :
 __tGB__self__pos = __rGB__pos ;
 __tGB__value = i ;
 __tGB__value = __tGB__self__pos ;
 __tGB____zD = 1 ;
 __tGB____0D__z = __tGB__self__pos + __tGB____zD ; 
 __tGB____0D____end :
 __tGB__self__pos = __tGB____0D__z ;
 __tGB____1D__z = __tGB__self__pos <= __rGB__end ; 
 __tGB____1D____end :
 __rGB__pos = __tGB__self__pos ;
 if(! __tGB____1D__z )goto __sGB__while ;
 if(! spheres__dynamic )goto __result__buffer_error ;
 spheres__dynamic____buffer_alignment = 5 ;
 spheres__dynamic____buffer_size = ((u64*) spheres__dynamic )[1] ;
 if( __tGB__value >= spheres__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(& __vGB , &((u64*)((void**) spheres__dynamic )[0])[ __tGB__value * spheres__dynamic____buffer_alignment +0], sizeof( f64 )) ;
 memcpy(& __wGB , &((u64*)((void**) spheres__dynamic )[0])[ __tGB__value * spheres__dynamic____buffer_alignment +1], sizeof( f64 )) ;
 memcpy(& __xGB , &((u64*)((void**) spheres__dynamic )[0])[ __tGB__value * spheres__dynamic____buffer_alignment +2], sizeof( f64 )) ;
 memcpy(& __yGB , &((u64*)((void**) spheres__dynamic )[0])[ __tGB__value * spheres__dynamic____buffer_alignment +3], sizeof( f64 )) ;
 memcpy(& __zGB , &((u64*)((void**) spheres__dynamic )[0])[ __tGB__value * spheres__dynamic____buffer_alignment +4], sizeof( f64 )) ;
 __0GB____1FB = 200 ;
 __0GB____2FB = 50 ;
 __0GB____3FB = 50 ;
 __0GB____4FB____HFB = 255 ;
 __0GB____4FB____IFB____tEB = 255 ;
 __0GB____4FB____IFB____uEB__z = __0GB____1FB > __0GB____4FB____IFB____tEB ; 
 __0GB____4FB____IFB____uEB____end :
 if(! __0GB____4FB____IFB____uEB__z )goto __0GB____4FB____IFB____sEB__fi ;
 __0GB____4FB____IFB____vEB = "Color r greater than 255" ;
 goto __0GB____4FB____IFB____wEB____oD ;
 __builtin_unreachable();
 __0GB____4FB____IFB____sEB__fi :
 __0GB____4FB____IFB____yEB = 255 ;
 __0GB____4FB____IFB____zEB__z = __0GB____2FB > __0GB____4FB____IFB____yEB ; 
 __0GB____4FB____IFB____zEB____end :
 if(! __0GB____4FB____IFB____zEB__z )goto __0GB____4FB____IFB____xEB__fi ;
 __0GB____4FB____IFB____0EB = "Color g greater than 255" ;
 goto __0GB____4FB____IFB____1EB____oD ;
 __builtin_unreachable();
 __0GB____4FB____IFB____xEB__fi :
 __0GB____4FB____IFB____3EB = 255 ;
 __0GB____4FB____IFB____4EB__z = __0GB____3FB > __0GB____4FB____IFB____3EB ; 
 __0GB____4FB____IFB____4EB____end :
 if(! __0GB____4FB____IFB____4EB__z )goto __0GB____4FB____IFB____2EB__fi ;
 __0GB____4FB____IFB____5EB = "Color b greater than 255" ;
 goto __0GB____4FB____IFB____6EB____oD ;
 __builtin_unreachable();
 __0GB____4FB____IFB____2EB__fi :
 __0GB____4FB____IFB____8EB = 255 ;
 __0GB____4FB____IFB____9EB__z = __0GB____4FB____HFB > __0GB____4FB____IFB____8EB ; 
 __0GB____4FB____IFB____9EB____end :
 if(! __0GB____4FB____IFB____9EB__z )goto __0GB____4FB____IFB____7EB__fi ;
 __0GB____4FB____IFB____AFB = "Color a greater than 255" ;
 goto __0GB____4FB____IFB____BFB____oD ;
 __builtin_unreachable();
 __0GB____4FB____IFB____7EB__fi :
 DrawCircleV (( Vector2 ) {( float ) __vGB ,( float ) __wGB },( float ) __xGB ,( Color ) {( unsigned char ) __0GB____1FB ,( unsigned char ) __0GB____2FB ,( unsigned char ) __0GB____3FB ,( unsigned char ) __0GB____4FB____HFB }); 
 __0GB____5FB__size__w = window__size__w ;
 window____CFB = __0GB____5FB__window____CFB ;
 window__size__w = window__size__w ;
 window__size__h = window__size__h ;
 window__title = window__title ;
 goto __sGB__loop ;
 __sGB__while :
 __1GB = accum_fps ;
 __2GB__allocator__contents__size = __fGB____nW__contents__size ;
 __2GB__allocator__contents____BF = __fGB____nW__contents____BF ;
 __2GB__allocator__contents__mem = __fGB____nW__contents__mem ;
 __2GB__allocator__contents__underlying = __fGB____nW__contents__underlying ;
 __2GB__allocator__contents__bytesize = __fGB____nW__contents__bytesize ;
 __2GB__allocator__length = __fGB____nW__length ;
 __2GB__allocator__cycles = __fGB____nW__cycles ;
 __2GB____Eo____Tm = 21 ;
 __2GB____Eo____Um = 0 ;
 __2GB____Eo____Wm__size = __2GB____Eo____Tm * sizeof ( __2GB____Eo____Wm____VU ); 
 __2GB____Eo____Wm____XU__x = __2GB____Eo____Wm__size ;
 __2GB____Eo____Wm____XU__z = __2GB____Eo____Wm____XU__x > __2GB__allocator__contents__size ; 
 __2GB____Eo____Wm____XU____end :
 if(! __2GB____Eo____Wm____XU__z )goto __2GB____Eo____Wm____WU__fi ;
 __2GB____Eo____Wm____YU = "Failed a Volatile allocation" ;
 goto __2GB____Eo____Wm____ZU____oD ;
 __builtin_unreachable();
 __2GB____Eo____Wm____WU__fi :
 if( __2GB__allocator__length + __2GB____Eo____Wm__size > __2GB__allocator__contents__size ) { __2GB__allocator__length =0; __2GB__allocator__cycles = __2GB__allocator__cycles +1; } 
 __2GB____Eo____Wm___contents =( ptr )(( char *) __2GB__allocator__contents__mem + __2GB__allocator__length ); 
 __2GB__allocator__length = __2GB__allocator__length + __2GB____Eo____Wm__size ; 
 __2GB____Eo____Wm____dU = 0 ;
 __2GB____Eo____Wm____fU__bytesize = sizeof ( __2GB____Eo____Wm____fU____CF )* __2GB____Eo____Wm__size ; 
 __2GB____Eo____Wm____fU____end :
 if( __2GB____Eo____Wm___contents ) { __2GB____Eo__length =( u64 ) snprintf (( char *) __2GB____Eo____Wm___contents , sizeof ( char )* 21 , "%lu" , __1GB ); if( __2GB____Eo__length < 32 ) { __2GB____Eo__contents = malloc ( __2GB____Eo__length +1); if( __2GB____Eo__contents ) { memcpy ( __2GB____Eo__contents ,( char *) __2GB____Eo____Wm___contents , __2GB____Eo__length );(( char *) __2GB____Eo__contents )[ __2GB____Eo__length ]=0; __2GB____Eo__first =(( char *) __2GB____Eo__contents )[0]; } } } 
 __2GB____Eo____Ym__x = __2GB____Eo__contents ;
 __2GB____Eo____Ym__z =( __2GB____Eo____Ym__x ); 
 __2GB____Eo____Ym____end :
 __2GB____Eo____Zm__z =(! __2GB____Eo____Ym__z ); 
 __2GB____Eo____Zm____end :
 if(! __2GB____Eo____Zm__z )goto __2GB____Eo____Xm__fi ;
 goto __2GB____Eo____am ;
 __builtin_unreachable();
 __2GB____Eo____Xm__fi :
 __fGB____nW__type = __2GB____Eo____Wm__self__type ;
 __fGB____nW__contents____9E = __2GB____Eo____Wm__self__contents____9E ;
 __fGB____nW__contents____AF____1E = __2GB____Eo____Wm__self__contents____AF____1E ;
 __fGB____nW__contents__size = __2GB__allocator__contents__size ;
 __fGB____nW__contents____BF = __2GB__allocator__contents____BF ;
 __fGB____nW__contents__mem = __2GB__allocator__contents__mem ;
 __fGB____nW__contents__underlying = __2GB__allocator__contents__underlying ;
 __fGB____nW__contents__bytesize = __2GB__allocator__contents__bytesize ;
 __fGB____nW__length = __2GB__allocator__length ;
 __fGB____nW__cycles = __2GB__allocator__cycles ;
 __3GB = " fps" ;
 __4GB____8b__length = strlen ( __3GB ); __4GB____8b__contents =( ptr ) __3GB ; __4GB____8b__first = __3GB [0]; __4GB____8b__noptr =( ptr ) __4GB____8b__noptr ; 
 __4GB____8b____m__contents = __4GB____8b__contents ;
 __4GB__len_x = __2GB____Eo__length ; __4GB__len_y = __4GB____8b__length ; __4GB__total_len = __4GB__len_x + __4GB__len_y ; __4GB__first = __2GB____Eo__length ? __2GB____Eo__first : __4GB____8b__first ; 
 __4GB____9b = 1 ;
 __4GB____Ac__z = __4GB__total_len + __4GB____9b ; 
 __4GB____Ac____end :
 __4GB____Bc = 0 ;
 __4GB____Dc__size = __4GB____Ac__z * sizeof ( __4GB____Dc____VU ); 
 __4GB____Dc____XU__x = __4GB____Dc__size ;
 __4GB____Dc____XU__z = __4GB____Dc____XU__x > __fGB____nW__contents__size ; 
 __4GB____Dc____XU____end :
 if(! __4GB____Dc____XU__z )goto __4GB____Dc____WU__fi ;
 __4GB____Dc____YU = "Failed a Volatile allocation" ;
 goto __4GB____Dc____ZU____oD ;
 __builtin_unreachable();
 __4GB____Dc____WU__fi :
 if( __fGB____nW__length + __4GB____Dc__size > __fGB____nW__contents__size ) { __fGB____nW__length =0; __fGB____nW__cycles = __fGB____nW__cycles +1; } 
 __4GB____Dc___contents =( ptr )(( char *) __fGB____nW__contents__mem + __fGB____nW__length ); 
 __fGB____nW__length = __fGB____nW__length + __4GB____Dc__size ; 
 __4GB____Dc____dU = 0 ;
 __4GB____Dc____fU__bytesize = sizeof ( __4GB____Dc____fU____CF )* __4GB____Dc__size ; 
 __4GB____Dc____fU____end :
 memcpy (( char *) __4GB____Dc___contents ,( char *) __2GB____Eo__contents , __4GB__len_x ); memcpy (( char *) __4GB____Dc___contents + __4GB__len_x ,( char *) __4GB____8b____m__contents , __4GB__len_y );(( char *) __4GB____Dc___contents )[ __4GB__total_len ]=0; 
 __4GB____Gc__contents = __4GB____Dc___contents ;
 __fGB____nW__type = __4GB____Dc__self__type ;
 __fGB____nW__contents____9E = __4GB____Dc__self__contents____9E ;
 __fGB____nW__contents____AF____1E = __4GB____Dc__self__contents____AF____1E ;
 __fGB____nW__contents__size = __fGB____nW__contents__size ;
 __fGB____nW__contents____BF = __fGB____nW__contents____BF ;
 __fGB____nW__contents__mem = __fGB____nW__contents__mem ;
 __fGB____nW__contents__underlying = __fGB____nW__contents__underlying ;
 __fGB____nW__contents__bytesize = __fGB____nW__contents__bytesize ;
 __fGB____nW__length = __fGB____nW__length ;
 __fGB____nW__cycles = __fGB____nW__cycles ;
 __5GB = 10.0 ;
 __6GB = 10.0 ;
 __8GB = 20.0 ;
 __9GB = 255 ;
 __AHB = 255 ;
 __BHB = 255 ;
 __CHB____HFB = 255 ;
 __CHB____IFB____tEB = 255 ;
 __CHB____IFB____uEB__z = __9GB > __CHB____IFB____tEB ; 
 __CHB____IFB____uEB____end :
 if(! __CHB____IFB____uEB__z )goto __CHB____IFB____sEB__fi ;
 __CHB____IFB____vEB = "Color r greater than 255" ;
 goto __CHB____IFB____wEB____oD ;
 __builtin_unreachable();
 __CHB____IFB____sEB__fi :
 __CHB____IFB____yEB = 255 ;
 __CHB____IFB____zEB__z = __AHB > __CHB____IFB____yEB ; 
 __CHB____IFB____zEB____end :
 if(! __CHB____IFB____zEB__z )goto __CHB____IFB____xEB__fi ;
 __CHB____IFB____0EB = "Color g greater than 255" ;
 goto __CHB____IFB____1EB____oD ;
 __builtin_unreachable();
 __CHB____IFB____xEB__fi :
 __CHB____IFB____3EB = 255 ;
 __CHB____IFB____4EB__z = __BHB > __CHB____IFB____3EB ; 
 __CHB____IFB____4EB____end :
 if(! __CHB____IFB____4EB__z )goto __CHB____IFB____2EB__fi ;
 __CHB____IFB____5EB = "Color b greater than 255" ;
 goto __CHB____IFB____6EB____oD ;
 __builtin_unreachable();
 __CHB____IFB____2EB__fi :
 __CHB____IFB____8EB = 255 ;
 __CHB____IFB____9EB__z = __CHB____HFB > __CHB____IFB____8EB ; 
 __CHB____IFB____9EB____end :
 if(! __CHB____IFB____9EB__z )goto __CHB____IFB____7EB__fi ;
 __CHB____IFB____AFB = "Color a greater than 255" ;
 goto __CHB____IFB____BFB____oD ;
 __builtin_unreachable();
 __CHB____IFB____7EB__fi :
 DrawText (( char *) __4GB____Gc__contents , __5GB , __6GB , __8GB ,( Color ) {( unsigned char ) __9GB ,( unsigned char ) __AHB ,( unsigned char ) __BHB ,( unsigned char ) __CHB____HFB }); 
 __DHB__size__w = window__size__w ;
 __DHB__size__h = window__size__h ;
 __DHB__title = window__title ;
 window____CFB = __DHB__window____CFB ;
 EndDrawing (); 
 __EHB__size__w = __DHB__size__w ;
 __FHB__elapsed = __smo_time_eta (); 
 __FHB____end :
 __GHB__z = __FHB__elapsed - prev_t ; 
 __GHB____end :
 dt = __GHB__z ;
 prev_t = __FHB__elapsed ;
 __HHB = 0.99 ;
 __IHB__z = accum_fps * __HHB ; 
 __IHB____end :
 __JHB = 0.01 ;
 __KHB__z = __JHB / dt ; 
 __KHB____end :
 __LHB__z = __IHB__z + __KHB__z ; 
 __LHB____end :
 accum_fps = __LHB__z ;
 __MHB = 0.015 ;
 __NHB__z = __FHB__elapsed - __jGB__elapsed ; 
 __NHB____end :
 __OHB__z = __MHB - __NHB__z ; 
 __OHB____end :
 __PHB____WFB = 0.0 ;
 __PHB____XFB__z = __OHB__z <= __PHB____WFB ; 
 __PHB____XFB____end :
 if(! __PHB____XFB__z )goto __PHB____VFB__fi ;
 goto __PHB____end ;
 __PHB____VFB__fi :
 __smo_exact_sleep ( __OHB__z ); 
 __PHB____end :
 goto __hGB__loop ;
 __hGB__while :
 __end :
goto __return;

// ERROR HANDLING
__0GB____4FB____IFB____6EB____oD :
 printf ( "%s\n" , __0GB____4FB____IFB____5EB ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__CHB____IFB____wEB____oD :
 printf ( "%s\n" , __CHB____IFB____vEB ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__result__buffer_error :
printf("Buffer error\n");
__result__errocode=__BUFFER__ERROR;
goto __failsafe;
__2GB____Eo____am :
 printf ( "Failed to allocate str from number\n" ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__2GB____Eo____Wm____ZU____oD :
 printf ( "%s\n" , __2GB____Eo____Wm____YU ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__0GB____4FB____IFB____1EB____oD :
 printf ( "%s\n" , __0GB____4FB____IFB____0EB ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__pGB____IFB____1EB____oD :
 printf ( "%s\n" , __pGB____IFB____0EB ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__0GB____4FB____IFB____BFB____oD :
 printf ( "%s\n" , __0GB____4FB____IFB____AFB ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__pGB____IFB____BFB____oD :
 printf ( "%s\n" , __pGB____IFB____AFB ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__CHB____IFB____BFB____oD :
 printf ( "%s\n" , __CHB____IFB____AFB ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__CHB____IFB____6EB____oD :
 printf ( "%s\n" , __CHB____IFB____5EB ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__pGB____IFB____wEB____oD :
 printf ( "%s\n" , __pGB____IFB____vEB ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__fGB____mW____WI____8G____oD :
 printf ( "%s\n" , __fGB____mW____WI____7G ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__4GB____Dc____ZU____oD :
 printf ( "%s\n" , __4GB____Dc____YU ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__fGB____mW____WI____EH____oD :
 printf ( "%s\n" , __fGB____mW____WI____DH ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__pGB____IFB____6EB____oD :
 printf ( "%s\n" , __pGB____IFB____5EB ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__CHB____IFB____1EB____oD :
 printf ( "%s\n" , __CHB____IFB____0EB ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__0GB____4FB____IFB____wEB____oD :
 printf ( "%s\n" , __0GB____4FB____IFB____vEB ); 
__result__errocode=__USER__ERROR;
goto __failsafe;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
if( __fGB____nW__contents__mem ) __runtime_free ( __fGB____nW__contents__mem ); __fGB____nW__contents__mem =0; 
if( __GGB__dynamic ){if((u64*)((u64*) __GGB__dynamic )[2]) __runtime_free((u64*)((u64*) __GGB__dynamic )[0]) ;
 __runtime_free( __GGB__dynamic ) ;
 __GGB__dynamic = 0 ;
 }__state->err =  __result__errocode;
}


void main__948(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__948__state *__state=(struct main__948__state*)__void__state;
struct test__947__state* __QHB____state = 0 ;
errcode __QHB__err=0;
ptr __QHB____task=0;

// IMPLEMENTATION
__QHB____state = (struct test__947__state*)__runtime_calloc(sizeof(struct test__947__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __QHB____state ) ;
 __QHB____task = __smolambda_add_task ( test__947 , __QHB____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __QHB____task ) ;
 if( __QHB__err ) goto  __result_unhandled_error ;
 if( __QHB__err ) goto  __result_unhandled_error ;
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



int main() {
struct main__948__state __main_args={0};
__smolambda_initialize_service_tasks(main__948, &__main_args);
return __main_args.err;
}

