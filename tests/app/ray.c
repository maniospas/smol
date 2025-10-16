#define SMOLAMBDA_SERVICES 2
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
#define __DYokMIC__ERROR 5
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

#include<string.h>

#include<stdlib.h>

#include<stdio.h>

#include "std/oscommon.h"

#include "raylib.h"

struct main__1205__state{errcode err;};
__externc void main__1205(void *__void__state);
struct test__1204__state{errcode err;};
__externc void test__1204(void *__void__state);

void test__1204(void *__void__state){
errcode __result__errocode=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 3412;
struct test__1204__state *__state=(struct test__1204__state*)__void__state;
f64 __2hI=0;
f64 __1hI=0;
f64 __zhI=0;
f64 __xhI=0;
f64 __whI=0;
f64 __vhI=0;
f64 __uhI=0;
f64 __thI=0;
f64 __shI=0;
f64 __rhI=0;
f64 __qhI=0;
f64 __phI=0;
f64 __ohI=0;
f64 __nhI=0;
bool __mhI=0;
u64 __lhI=0;
u64 __khI=0;
u64 __jhI=0;
u64 __ihI=0;
u64 __ghI=0;
u64 __ehI=0;
f64 __dhI=0;
f64 __chI=0;
f64 __bhI=0;
f64 __ahI=0;
f64 __ZhI=0;
f64 __XhI=0;
f64 __WhI=0;
bool __VhI=0;
bool __ShI=0;
nominal __RhI=0;
f64 __QhI=0;
bool __PhI=0;
cstr __OhI=0;
f64 __NhI=0;
u64 __MhI=0;
cstr __LhI=0;
u64 __KhI=0;
cstr __IhI=0;
bool __FhI=0;
u64 __EhI=0;
cstr __ChI=0;
bool __9gI=0;
u64 __8gI=0;
cstr __6gI=0;
u64 __3gI=0;
bool __2gI=0;
u64 __1gI=0;
u64 __0gI=0;
u64 __zgI=0;
u64 __ygI=0;
f64 __xgI=0;
f64 __wgI=0;
f64 __vgI=0;
nominal __ugI=0;
nominal __tgI=0;
ptr __rgI=0;
u64 __pgI=0;
char __ogI=0;
ptr __ngI=0;
cstr __lgI=0;
bool __igI=0;
u64 __hgI=0;
char __ggI=0;
char __fgI=0;
u64 __dgI=0;
u64 __cgI=0;
char __bgI=0;
u64 __agI=0;
u64 __ZgI=0;
u64 __XgI=0;
ptr __WgI=0;
ptr __UgI=0;
char __TgI=0;
ptr __SgI=0;
f64 __RgI=0;
u64 __QgI=0;
cstr __PgI=0;
nominal __OgI=0;
nominal __NgI=0;
nominal __MgI=0;
nominal __LgI=0;
nominal __KgI=0;
nominal __JgI=0;
bool __FgI=0;
bool __DgI=0;
ptr __CgI=0;
char __BgI=0;
ptr __AgI=0;
u64 __9fI=0;
char __7fI=0;
cstr __5fI=0;
bool __3fI=0;
u64 __2fI=0;
f64 __1fI=0;
u64 __0fI=0;
char __zfI=0;
char __yfI=0;
u64 __xfI=0;
u64 __wfI=0;
u64 __ufI=0;
u64 __tfI=0;
ptr __sfI=0;
ptr __rfI=0;
char __qfI=0;
u64 __pfI=0;
nominal __ofI=0;
f64 __nfI=0;
cstr __lfI=0;
bool __ifI=0;
u64 __hfI=0;
cstr __ffI=0;
bool __cfI=0;
u64 __bfI=0;
cstr __ZfI=0;
bool __XfI=0;
u64 __WfI=0;
cstr __UfI=0;
bool __RfI=0;
u64 __QfI=0;
u64 __PfI=0;
u64 __OfI=0;
f64 __NfI=0;
f64 __MfI=0;
f64 __LfI=0;
f64 __KfI=0;
f64 __JfI=0;
bool __GfI=0;
u64 __EfI=0;
u64 __DfI=0;
u64 i=0;
u64 __CfI=0;
u64 __BfI=0;
u64 __9eI=0;
u64 __8eI=0;
u64 __7eI=0;
u64 __6eI=0;
u64 __5eI=0;
u64 __4eI=0;
u64 __3eI=0;
f64 __2eI=0;
cstr __0eI=0;
bool __yeI=0;
u64 __xeI=0;
cstr __veI=0;
u64 __ueI=0;
u64 __reI=0;
cstr __qeI=0;
bool __neI=0;
cstr __leI=0;
bool __ieI=0;
u64 __heI=0;
u64 __geI=0;
u64 __feI=0;
u64 __eeI=0;
u64 __deI=0;
nominal __ceI=0;
bool __beI=0;
cstr __aeI=0;
f64 __ZeI=0;
f64 __YeI=0;
bool __XeI=0;
bool __TeI=0;
nominal __ReI=0;
nominal window____EDI=0;
bool __NeI=0;
bool __MeI=0;
u64 __KeI=0;
u64 __JeI=0;
u64 __IeI=0;
ptr __HeI=0;
char __GeI=0;
u64 __FeI=0;
u64 __EeI=0;
u64 __DeI=0;
u64 __BeI=0;
char __AeI=0;
cstr __8dI=0;
bool __5dI=0;
bool __pdI=0;
f64 __VgI=0;
f64 __CdI=0;
f64 __AdI=0;
u64 __3cI=0;
f64 __1cI=0;
u64 __xcI=0;
u64 __lcI=0;
u64 __fcI=0;
u64 __bcI=0;
cstr __VeI=0;
f64 window__size__w=0;
ptr __UKI__dynamic=0;
u64 __YcI=0;
f64 __UcI=0;
f64 __RcI=0;
f64 __IcI=0;
u64 __5bI=0;
bool __2bI=0;
f64 __ubI=0;
f64 __ibI=0;
bool __4dI=0;
cstr window__title=0;
char __UbI=0;
bool __OeI=0;
f64 window__size__h=0;
u64 spheres__dynamic____buffer_alignment=0;
f64 __kdI=0;
u64 __gdI=0;
u64 spheres__dynamic____buffer_size=0;
f64 __DbI=0;
ptr __7aI=0;
f64 prev_t=0;
bool __faI=0;
u64 __eaI=0;
cstr __YaI=0;
f64 __UaI=0;
bool window__ready=0;
char __GaI=0;
ptr spheres__dynamic____buffer_contents=0;
u64 spheres__dynamic____buffer_capacity=0;
u64 spheres__dynamic____buffer_prev_capacity=0;
bool __8ZI=0;
cstr __6ZI=0;
ptr __2ZI=0;
nominal __sgI=0;
f64 __1ZI=0;
f64 __0ZI=0;
ptr __zZI=0;
f64 __wZI=0;
f64 __vZI=0;
f64 __uZI=0;
f64 __sZI=0;
bool __qZI=0;
f64 __rZI=0;
f64 dt=0;
f64 __pZI=0;
cstr __oZI=0;
u64 __lZI=0;
f64 accum_fps=0;
f64 __kZI=0;
u64 __jZI=0;
f64 __iZI=0;
char __hZI=0;
char __fZI=0;
f64 __dZI=0;
f64 __cZI=0;
f64 __aZI=0;
bool __ZZI=0;
f64 __WZI=0;
f64 __VZI=0;
f64 __SZI=0;
ptr __tKI__contents__mem=0;
f64 __QZI=0;
bool __PZI=0;
f64 __MZI=0;
f64 __LZI=0;
f64 __JZI=0;
f64 __IZI=0;
ptr spheres__dynamic=0;
ptr spheres__surface=0;
f64 __GZI=0;
f64 __EZI=0;
bool __DZI=0;
f64 __AZI=0;
f64 __9YI=0;
f64 __6YI=0;
f64 __4YI=0;
bool __3YI=0;
f64 __0YI=0;
f64 __zYI=0;
f64 __xYI=0;
f64 __wYI=0;
f64 __uYI=0;
f64 __tYI=0;
f64 __rYI=0;
bool __pYI=0;

// IMPLEMENTATION
__UKI__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 __zZI = 0 ;
 spheres__dynamic = __UKI__dynamic ;
 spheres__surface = __zZI ;
 __wZI = 100.0 ;
 __CdI = 100.0 ;
 __vZI = 30.0 ;
 __ibI = 1000.0 ;
 __uZI = 650.0 ;
 if(! spheres__dynamic )goto __result__buffer_error ;
 spheres__dynamic____buffer_alignment = 5 ;
 spheres__dynamic____buffer_size = ((u64*) spheres__dynamic )[1] ;
 spheres__dynamic____buffer_capacity = ((u64*) spheres__dynamic )[2] & ~(1ULL << 63) ;
 if( spheres__dynamic____buffer_size >= spheres__dynamic____buffer_capacity ){ if( ((u64*) spheres__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 spheres__dynamic____buffer_prev_capacity = spheres__dynamic____buffer_capacity ;
 spheres__dynamic____buffer_capacity = spheres__dynamic____buffer_capacity +( spheres__dynamic____buffer_capacity >>2)+1; if( spheres__dynamic____buffer_size ) ((void**) spheres__dynamic )[0] = __runtime_realloc((u64*)((void**) spheres__dynamic )[0],  spheres__dynamic____buffer_capacity * spheres__dynamic____buffer_alignment *sizeof(u64),  spheres__dynamic____buffer_prev_capacity * spheres__dynamic____buffer_alignment *sizeof(u64)); else ((void**) spheres__dynamic )[0] = __runtime_alloc( spheres__dynamic____buffer_capacity * spheres__dynamic____buffer_alignment *sizeof(u64)); ((u64*) spheres__dynamic )[2] = spheres__dynamic____buffer_capacity ;
 spheres__dynamic____buffer_contents = (ptr)((void**) spheres__dynamic )[0] ;
 if(! spheres__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  spheres__dynamic____buffer_contents = (ptr)(((u64*) spheres__dynamic )[0]) ;
 ((u64*) spheres__dynamic )[1] = spheres__dynamic____buffer_size +1 ;
 memcpy(&((u64*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment +0], & __wZI , sizeof(f64)); memcpy(&((u64*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment +1], & __CdI , sizeof(f64)); memcpy(&((u64*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment +2], & __vZI , sizeof(f64)); memcpy(&((u64*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment +3], & __ibI , sizeof(f64)); memcpy(&((u64*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment +4], & __uZI , sizeof(f64)); __sZI = 100.0 ;
 __IcI = 100.0 ;
 __ubI = 30.0 ;
 __UaI = 450.0 ;
 __rZI = 600.0 ;
 if(! spheres__dynamic )goto __result__buffer_error ;
 spheres__dynamic____buffer_alignment = 5 ;
 spheres__dynamic____buffer_size = ((u64*) spheres__dynamic )[1] ;
 spheres__dynamic____buffer_capacity = ((u64*) spheres__dynamic )[2] & ~(1ULL << 63) ;
 if( spheres__dynamic____buffer_size >= spheres__dynamic____buffer_capacity ){ if( ((u64*) spheres__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 spheres__dynamic____buffer_prev_capacity = spheres__dynamic____buffer_capacity ;
 spheres__dynamic____buffer_capacity = spheres__dynamic____buffer_capacity +( spheres__dynamic____buffer_capacity >>2)+1; if( spheres__dynamic____buffer_size ) ((void**) spheres__dynamic )[0] = __runtime_realloc((u64*)((void**) spheres__dynamic )[0],  spheres__dynamic____buffer_capacity * spheres__dynamic____buffer_alignment *sizeof(u64),  spheres__dynamic____buffer_prev_capacity * spheres__dynamic____buffer_alignment *sizeof(u64)); else ((void**) spheres__dynamic )[0] = __runtime_alloc( spheres__dynamic____buffer_capacity * spheres__dynamic____buffer_alignment *sizeof(u64)); ((u64*) spheres__dynamic )[2] = spheres__dynamic____buffer_capacity ;
 spheres__dynamic____buffer_contents = (ptr)((void**) spheres__dynamic )[0] ;
 if(! spheres__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  spheres__dynamic____buffer_contents = (ptr)(((u64*) spheres__dynamic )[0]) ;
 ((u64*) spheres__dynamic )[1] = spheres__dynamic____buffer_size +1 ;
 memcpy(&((u64*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment +0], & __sZI , sizeof(f64)); memcpy(&((u64*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment +1], & __IcI , sizeof(f64)); memcpy(&((u64*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment +2], & __ubI , sizeof(f64)); memcpy(&((u64*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment +3], & __UaI , sizeof(f64)); memcpy(&((u64*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment +4], & __rZI , sizeof(f64)); __DbI = 0.0 ;
 dt = __DbI ;
 __pZI = 800.0 ;
 __RcI = 450.0 ;
 __oZI = "Hello from smoλ+raylib" ;
 SetTraceLogLevel ( LOG_WARNING ); InitWindow ( __pZI , __RcI ,( char *) __oZI ); 
 __pdI = false ;
 window__size__w = __pZI ;
 window__size__h = __RcI ;
 window__title = __oZI ;
 window__ready = __pdI ;
 __kZI = __smo_time_eta (); 
 __ZbI :
 prev_t = __kZI ;
 __iZI = 60.0 ;
 accum_fps = __iZI ;
 __eaI = 1024 ;
 __hZI = 0 ;
 __fZI = __hZI ;
 __5bI = 0 ;
 __8ZI =( __eaI == __5bI ); 
 __yZI :
 if(! __8ZI )goto __eZI ;
 __6ZI = "Cannot allocate zero size" ;
 goto __caI ;
 __builtin_unreachable();
 __eZI :
 __2ZI = __runtime_alloc ( __eaI * sizeof ( __fZI )); 
 __4dI = __2ZI ;
 __5dI =(! __4dI ); 
 __6dI :
 if(! __5dI )goto __7dI ;
 __8dI = "Failed a Heap allocation" ;
 goto __9dI ;
 __builtin_unreachable();
 __7dI :
 __AeI = 0 ;
 __BeI = sizeof ( __AeI )* __eaI ; 
 __CeI :
 __fZI = __AeI ;
 __DeI = 0 ;
 __EeI = 0 ;
 __FeI = __eaI ;
 __GeI = __fZI ;
 __tKI__contents__mem = __2ZI ;
 __HeI = __2ZI ;
 __IeI = __BeI ;
 __JeI = __DeI ;
 __KeI = __EeI ;
 __LeI :
 __MeI = WindowShouldClose (); 
 __NeI = __MeI ;
 __OeI =(! __NeI ); 
 __PeI :
 window____EDI = __ReI ;
 if(! __OeI )goto __SeI ;
 __TeI = window__ready ;
 if(! __TeI )goto __UeI ;
 __VeI = "Window.begin() already called without closing it with Window.end()" ;
 goto __WeI ;
 __builtin_unreachable();
 __UeI :
 __XeI = true ;
 __TeI = __XeI ;
 BeginDrawing (); 
 __YeI = window__size__w ;
 __ZeI = window__size__h ;
 __aeI = window__title ;
 __beI = __TeI ;
 window____EDI = __ceI ;
 window__ready = __TeI ;
 __deI = 50 ;
 __eeI = 50 ;
 __feI = 80 ;
 __geI = 255 ;
 __heI = 255 ;
 __ieI = __deI > __heI ; 
 __jeI :
 if(! __ieI )goto __keI ;
 __leI = "Color r greater than 255" ;
 goto __meI ;
 __builtin_unreachable();
 __keI :
 __xcI = 255 ;
 __neI = __eeI > __xcI ; 
 __oeI :
 if(! __neI )goto __peI ;
 __qeI = "Color g greater than 255" ;
 goto __RdI ;
 __builtin_unreachable();
 __peI :
 __reI = 255 ;
 __faI = __feI > __reI ; 
 __seI :
 if(! __faI )goto __teI ;
 __veI = "Color b greater than 255" ;
 goto __weI ;
 __builtin_unreachable();
 __teI :
 __xeI = 255 ;
 __yeI = __geI > __xeI ; 
 __zeI :
 if(! __yeI )goto __bdI ;
 __0eI = "Color a greater than 255" ;
 goto __1eI ;
 __builtin_unreachable();
 __bdI :
 ClearBackground (( Color ) {( unsigned char ) __deI ,( unsigned char ) __eeI ,( unsigned char ) __feI ,( unsigned char ) __geI }); 
 __2eI = __YeI ;
 __3eI = spheres__dynamic ? ((u64*) spheres__dynamic )[1]:0 ;
 __4eI = __3eI ;
 __5eI = 0 ;
 __6eI = 1 ;
 __7eI = __5eI ;
 __8eI = __6eI ;
 __9eI = __5eI ;
 __AfI :
 __BfI = __9eI ;
 __CfI = i ;
 __CfI = __BfI ;
 __DfI = 1 ;
 __EfI = __BfI + __DfI ; 
 __FfI :
 __BfI = __EfI ;
 __GfI = __BfI <= __4eI ; 
 __HfI :
 __9eI = __BfI ;
 if(! __GfI )goto __IfI ;
 if(! spheres__dynamic )goto __result__buffer_error ;
 spheres__dynamic____buffer_alignment = 5 ;
 spheres__dynamic____buffer_size = ((u64*) spheres__dynamic )[1] ;
 if( __CfI >= spheres__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(& __JfI , &((u64*)((void**) spheres__dynamic )[0])[ __CfI * spheres__dynamic____buffer_alignment +0], sizeof( f64 )) ;
 memcpy(& __KfI , &((u64*)((void**) spheres__dynamic )[0])[ __CfI * spheres__dynamic____buffer_alignment +1], sizeof( f64 )) ;
 memcpy(& __LfI , &((u64*)((void**) spheres__dynamic )[0])[ __CfI * spheres__dynamic____buffer_alignment +2], sizeof( f64 )) ;
 memcpy(& __MfI , &((u64*)((void**) spheres__dynamic )[0])[ __CfI * spheres__dynamic____buffer_alignment +3], sizeof( f64 )) ;
 memcpy(& __NfI , &((u64*)((void**) spheres__dynamic )[0])[ __CfI * spheres__dynamic____buffer_alignment +4], sizeof( f64 )) ;
 __fcI = 200 ;
 __bcI = 50 ;
 __OfI = 50 ;
 __PfI = 255 ;
 __QfI = 255 ;
 __RfI = __fcI > __QfI ; 
 __SfI :
 if(! __RfI )goto __TfI ;
 __UfI = "Color r greater than 255" ;
 goto __VfI ;
 __builtin_unreachable();
 __TfI :
 __WfI = 255 ;
 __XfI = __bcI > __WfI ; 
 __QeI :
 if(! __XfI )goto __YfI ;
 __ZfI = "Color g greater than 255" ;
 goto __afI ;
 __builtin_unreachable();
 __YfI :
 __bfI = 255 ;
 __cfI = __OfI > __bfI ; 
 __dfI :
 if(! __cfI )goto __efI ;
 __ffI = "Color b greater than 255" ;
 goto __gfI ;
 __builtin_unreachable();
 __efI :
 __hfI = 255 ;
 __ifI = __PfI > __hfI ; 
 __jfI :
 if(! __ifI )goto __kfI ;
 __lfI = "Color a greater than 255" ;
 goto __mfI ;
 __builtin_unreachable();
 __kfI :
 DrawCircleV (( Vector2 ) {( float ) __JfI ,( float ) __KfI },( float ) __LfI ,( Color ) {( unsigned char ) __fcI ,( unsigned char ) __bcI ,( unsigned char ) __OfI ,( unsigned char ) __PfI }); 
 __nfI = window__size__w ;
 window____EDI = __ofI ;
 window__size__w = window__size__w ;
 window__size__h = window__size__h ;
 window__title = window__title ;
 window__ready = window__ready ;
 goto __AfI ;
 __IfI :
 __gdI = accum_fps ;
 __pfI = __FeI ;
 __qfI = __GeI ;
 __rfI = __tKI__contents__mem ;
 __sfI = __HeI ;
 __tfI = __IeI ;
 __ufI = __JeI ;
 __wfI = __KeI ;
 __xfI = 21 ;
 __yfI = 0 ;
 __GaI = __zfI ;
 __0fI = __xfI * sizeof ( __GaI ); 
 __2fI = __0fI ;
 __3fI = __2fI > __pfI ; 
 __9ZI :
 if(! __3fI )goto __4fI ;
 __5fI = "Failed a Volatile allocation" ;
 goto __6fI ;
 __builtin_unreachable();
 __4fI :
 if ( __ufI + __0fI > __pfI ) { __ufI =0; __wfI = __wfI +1; } 
 __7aI =( ptr )(( char *) __rfI + __ufI ); 
 __ufI = __ufI + __0fI ; 
 __7fI = 0 ;
 __ueI = sizeof ( __7fI )* __0fI ; 
 __8fI :
 __GaI = __7fI ;
 if ( __7aI ) { __9fI =( u64 ) snprintf (( char *) __7aI , sizeof ( char )* 21 , "%lu" , __gdI ); if ( __9fI < 32 ) { __AgI = malloc ( __9fI +1); if ( __AgI ) { memcpy ( __AgI ,( char *) __7aI , __9fI );(( char *) __AgI )[ __9fI ]=0; __BgI =(( char *) __AgI )[0]; } } } 
 __CgI = __AgI ;
 __DgI =( __CgI ); 
 __EgI :
 __FgI =(! __DgI ); 
 __GgI :
 if(! __FgI )goto __HgI ;
 goto __IgI ;
 __builtin_unreachable();
 __HgI :
 __JgI = __KgI ;
 __LgI = __MgI ;
 __NgI = __OgI ;
 __FeI = __pfI ;
 __GeI = __qfI ;
 __tKI__contents__mem = __rfI ;
 __HeI = __sfI ;
 __IeI = __tfI ;
 __JeI = __ufI ;
 __KeI = __wfI ;
 __PgI = " fps" ;
 __QgI = strlen ( __PgI ); __SgI =( ptr ) __PgI ; __TgI = __PgI [0]; __UgI =( ptr ) __UgI ; 
 __WgI = __SgI ;
 __XgI = __9fI ; __ZgI = __QgI ; __agI = __XgI + __ZgI ; __bgI = __9fI ? __BgI : __TgI ; 
 __cgI = 1 ;
 __dgI = __agI + __cgI ; 
 __egI :
 __fgI = 0 ;
 __UbI = __ggI ;
 __lZI = __dgI * sizeof ( __UbI ); 
 __hgI = __lZI ;
 __igI = __hgI > __FeI ; 
 __jgI :
 if(! __igI )goto __kgI ;
 __lgI = "Failed a Volatile allocation" ;
 goto __mgI ;
 __builtin_unreachable();
 __kgI :
 if ( __JeI + __lZI > __FeI ) { __JeI =0; __KeI = __KeI +1; } 
 __ngI =( ptr )(( char *) __tKI__contents__mem + __JeI ); 
 __JeI = __JeI + __lZI ; 
 __ogI = 0 ;
 __pgI = sizeof ( __ogI )* __lZI ; 
 __qgI :
 __UbI = __ogI ;
 memcpy (( char *) __ngI ,( char *) __AgI , __XgI ); memcpy (( char *) __ngI + __XgI ,( char *) __WgI , __ZgI );(( char *) __ngI )[ __agI ]=0; 
 __rgI = __ngI ;
 __JgI = __sgI ;
 __LgI = __tgI ;
 __NgI = __ugI ;
 __FeI = __FeI ;
 __GeI = __GeI ;
 __tKI__contents__mem = __tKI__contents__mem ;
 __HeI = __HeI ;
 __IeI = __IeI ;
 __JeI = __JeI ;
 __KeI = __KeI ;
 __vgI = 10.0 ;
 __wgI = 10.0 ;
 __xgI = 20.0 ;
 __ygI = 255 ;
 __3cI = 255 ;
 __zgI = 255 ;
 __0gI = 255 ;
 __1gI = 255 ;
 __2gI = __ygI > __1gI ; 
 __4gI :
 if(! __2gI )goto __5gI ;
 __6gI = "Color r greater than 255" ;
 goto __7gI ;
 __builtin_unreachable();
 __5gI :
 __8gI = 255 ;
 __9gI = __3cI > __8gI ; 
 __AhI :
 if(! __9gI )goto __BhI ;
 __ChI = "Color g greater than 255" ;
 goto __DhI ;
 __builtin_unreachable();
 __BhI :
 __EhI = 255 ;
 __FhI = __zgI > __EhI ; 
 __GhI :
 if(! __FhI )goto __HhI ;
 __IhI = "Color b greater than 255" ;
 goto __JhI ;
 __builtin_unreachable();
 __HhI :
 __KhI = 255 ;
 __2bI = __0gI > __KhI ; 
 __SaI :
 if(! __2bI )goto __DdI ;
 __LhI = "Color a greater than 255" ;
 goto __vfI ;
 __builtin_unreachable();
 __DdI :
 DrawText (( char *) __rgI , __vgI , __wgI , __xgI ,( Color ) {( unsigned char ) __ygI ,( unsigned char ) __3cI ,( unsigned char ) __zgI ,( unsigned char ) __0gI }); 
 __NhI = window__size__w ;
 __kdI = window__size__h ;
 __OhI = window__title ;
 __PhI = window__ready ;
 window____EDI = __RhI ;
 __ShI = __PhI ;
 __qZI =(! __ShI ); 
 __ThI :
 if(! __qZI )goto __ScI ;
 __YaI = "Window.begin() must be called before a matching Window.end()" ;
 goto __UhI ;
 __builtin_unreachable();
 __ScI :
 __VhI = false ;
 __ShI = __VhI ;
 EndDrawing (); 
 __WhI = __NhI ;
 __PhI = __ShI ;
 __XhI = __smo_time_eta (); 
 __YhI :
 __ZhI = __XhI - prev_t ; 
 __WaI :
 dt = __ZhI ;
 prev_t = __XhI ;
 __ahI = 0.99 ;
 __bhI = accum_fps * __ahI ; 
 __gZI :
 __chI = 0.01 ;
 __1fI = __chI / dt ; 
 __nbI :
 __dhI = __bhI + __1fI ; 
 __fhI :
 accum_fps = __dhI ;
 __MhI = spheres__dynamic ? ((u64*) spheres__dynamic )[1]:0 ;
 __ghI = 0 ;
 __YcI = 1 ;
 __lcI = __ghI ;
 __hhI :
 __ihI = __lcI ;
 __ehI = __jhI ;
 __ehI = __ihI ;
 __khI = 1 ;
 __lhI = __ihI + __khI ; 
 __iaI :
 __ihI = __lhI ;
 __mhI = __ihI <= __MhI ; 
 __kaI :
 __lcI = __ihI ;
 if(! __mhI )goto __gaI ;
 if(! spheres__dynamic )goto __result__buffer_error ;
 __jZI = 5 ;
 __3gI = ((u64*) spheres__dynamic )[1] ;
 if( __ehI >= __3gI )goto __result__buffer_error ;
 memcpy(& __nhI , &((u64*)((void**) spheres__dynamic )[0])[ __ehI * __jZI +0], sizeof( f64 )) ;
 __UcI = __nhI ;
 memcpy(& __ohI , &((u64*)((void**) spheres__dynamic )[0])[ __ehI * __jZI +1], sizeof( f64 )) ;
 __QhI = __ohI ;
 memcpy(& __phI , &((u64*)((void**) spheres__dynamic )[0])[ __ehI * __jZI +2], sizeof( f64 )) ;
 __1ZI = __phI ;
 memcpy(& __qhI , &((u64*)((void**) spheres__dynamic )[0])[ __ehI * __jZI +3], sizeof( f64 )) ;
 __1cI = __qhI ;
 memcpy(& __rhI , &((u64*)((void**) spheres__dynamic )[0])[ __ehI * __jZI +4], sizeof( f64 )) ;
 __shI = __rhI ;
 __thI = __UcI ;
 __uhI = __QhI ;
 __vhI = __1cI ;
 __whI = __shI ;
 __xhI = __vhI * dt ; 
 __yhI :
 __zhI = __thI + __xhI ; 
 __0hI :
 __1hI = __zhI ;
 __VgI = __whI * dt ; 
 __YgI :
 __RgI = __uhI + __VgI ; 
 __8cI :
 __AdI = __RgI ;
 __2hI = __vhI ;
 __dZI = __whI ;
 __cZI = __1hI - __1ZI ; 
 __bZI :
 __aZI = 0.0 ;
 __ZZI = __cZI < __aZI ; 
 __YZI :
 if(! __ZZI )goto __XZI ;
 __1hI = __1ZI ;
 __WZI = 0.0 ;
 __VZI = __WZI - __2hI ; 
 __UZI :
 __2hI = __VZI ;
 goto __TZI ;
 __XZI :
 __SZI = __1hI + __1ZI ; 
 __RZI :
 __QZI = 800.0 ;
 __PZI = __SZI > __QZI ; 
 __OZI :
 if(! __PZI )goto __NZI ;
 __MZI = 800.0 ;
 __LZI = __MZI - __1ZI ; 
 __KZI :
 __1hI = __LZI ;
 __JZI = 0.0 ;
 __IZI = __JZI - __2hI ; 
 __HZI :
 __2hI = __IZI ;
 __NZI :
 __TZI :
 __GZI = __AdI - __1ZI ; 
 __FZI :
 __EZI = 0.0 ;
 __DZI = __GZI < __EZI ; 
 __CZI :
 if(! __DZI )goto __BZI ;
 __AdI = __1ZI ;
 __AZI = 0.0 ;
 __9YI = __AZI - __dZI ; 
 __8YI :
 __dZI = __9YI ;
 goto __7YI ;
 __BZI :
 __6YI = __AdI + __1ZI ; 
 __5YI :
 __4YI = 450.0 ;
 __3YI = __6YI > __4YI ; 
 __2YI :
 if(! __3YI )goto __1YI ;
 __0YI = 450.0 ;
 __zYI = __0YI - __1ZI ; 
 __yYI :
 __AdI = __zYI ;
 __xYI = 0.0 ;
 __wYI = __xYI - __dZI ; 
 __vYI :
 __dZI = __wYI ;
 __1YI :
 __7YI :
 __thI = __1hI ;
 __uhI = __AdI ;
 __vhI = __2hI ;
 __whI = __dZI ;
 __UcI = __thI ;
 __QhI = __uhI ;
 __1cI = __vhI ;
 __shI = __whI ;
 memcpy(&((u64*)((u64*) spheres__dynamic )[0])[ __ehI * __jZI +0], & __UcI , sizeof( __UcI )) ;
 memcpy(&((u64*)((u64*) spheres__dynamic )[0])[ __ehI * __jZI +1], & __QhI , sizeof( __QhI )) ;
 memcpy(&((u64*)((u64*) spheres__dynamic )[0])[ __ehI * __jZI +2], & __1ZI , sizeof( __1ZI )) ;
 memcpy(&((u64*)((u64*) spheres__dynamic )[0])[ __ehI * __jZI +3], & __1cI , sizeof( __1cI )) ;
 memcpy(&((u64*)((u64*) spheres__dynamic )[0])[ __ehI * __jZI +4], & __shI , sizeof( __shI )) ;
 goto __hhI ;
 __gaI :
 __uYI = 0.015 ;
 __tYI = __XhI - prev_t ; 
 __sYI :
 __rYI = __uYI - __tYI ; 
 __qYI :
 __0ZI = 0.0 ;
 __pYI = __rYI <= __0ZI ; 
 __oYI :
 if(! __pYI )goto __nYI ;
 goto __mYI ;
 __nYI :
 __smo_exact_sleep ( __rYI ); 
 __mYI :
 goto __LeI ;
 __SeI :
 __lYI :
goto __return;

// ERROR HANDLING
__UhI :
 printf ( "%s\n" , __YaI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__RdI :
 printf ( "%s\n" , __qeI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__weI :
 printf ( "%s\n" , __veI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__7gI :
 printf ( "%s\n" , __6gI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__meI :
 printf ( "%s\n" , __leI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__DhI :
 printf ( "%s\n" , __ChI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__result__buffer_error :
printf("Buffer error\n");
__result__errocode=__BUFFER__ERROR;
goto __failsafe;
__afI :
 printf ( "%s\n" , __ZfI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__JhI :
 printf ( "%s\n" , __IhI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__WeI :
 printf ( "%s\n" , __VeI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__gfI :
 printf ( "%s\n" , __ffI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__IgI :
 printf ( "Failed to allocate str from number\n" ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__9dI :
 printf ( "%s\n" , __8dI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__mfI :
 printf ( "%s\n" , __lfI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__vfI :
 printf ( "%s\n" , __LhI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__caI :
 printf ( "%s\n" , __6ZI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__mgI :
 printf ( "%s\n" , __lgI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__1eI :
 printf ( "%s\n" , __0eI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__VfI :
 printf ( "%s\n" , __UfI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__6fI :
 printf ( "%s\n" , __5fI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
if ( __tKI__contents__mem ) __runtime_free ( __tKI__contents__mem ); __tKI__contents__mem =0; 
if( __UKI__dynamic ){if((u64*)((u64*) __UKI__dynamic )[2]) __runtime_free((u64*)((u64*) __UKI__dynamic )[0]) ;
 __runtime_free( __UKI__dynamic ) ;
 __UKI__dynamic = 0 ;
 }__state->err =  __result__errocode;
}


void main__1205(void *__void__state){
errcode __result__errocode=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1892;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__1205__state *__state=(struct main__1205__state*)__void__state;
struct test__1204__state* __FVI____state = 0 ;
ptr __5hI=0;
errcode __4hI=0;

// IMPLEMENTATION
{char mark;if(__service_stack_floor+ 3496 >=(char*)&mark) goto __service_stack_floor_handler;} __FVI____state = (struct test__1204__state*)__runtime_calloc(sizeof(struct test__1204__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __FVI____state ) ;
 __5hI = __smolambda_add_task ( test__1204 , __FVI____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __5hI ) ;
 if( __4hI ) goto  __result_unhandled_error ;
 __3hI :
goto __return;

// ERROR HANDLING
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__service_stack_floor_handler:
printf("Insufficient stack for safe service call (too much recursion or stack allocation)\n");
__result__errocode=__STACK__ERROR;
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
struct main__1205__state __main_args={0};
__smolambda_initialize_service_tasks(main__1205, &__main_args);
return __main_args.err;
}

