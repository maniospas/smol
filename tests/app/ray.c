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
u64 __service_stack_size = 3424;
struct test__1204__state *__state=(struct test__1204__state*)__void__state;
nominal __8hI=0;
nominal __7hI=0;
cstr __5hI=0;
bool __4hI=0;
u64 __3hI=0;
u64 __2hI=0;
char __1hI=0;
char __0hI=0;
u64 __yhI=0;
char __xhI=0;
u64 __whI=0;
u64 __vhI=0;
ptr __uhI=0;
u64 __thI=0;
cstr __shI=0;
nominal __rhI=0;
nominal __qhI=0;
nominal __phI=0;
bool __mhI=0;
bool __khI=0;
ptr __jhI=0;
char __ihI=0;
ptr __hhI=0;
u64 __ghI=0;
u64 __ehI=0;
char __dhI=0;
ptr __chI=0;
cstr __ahI=0;
bool __YhI=0;
u64 __XhI=0;
char __WhI=0;
u64 __VhI=0;
u64 __UhI=0;
u64 __ThI=0;
nominal __ShI=0;
f64 __RhI=0;
cstr __QhI=0;
bool __NhI=0;
u64 __MhI=0;
cstr __KhI=0;
cstr __FhI=0;
bool __DhI=0;
u64 __ChI=0;
cstr __AhI=0;
bool __7gI=0;
u64 __6gI=0;
u64 __5gI=0;
u64 __3gI=0;
u64 __2gI=0;
f64 __1gI=0;
f64 __0gI=0;
f64 __zgI=0;
f64 __ygI=0;
f64 __xgI=0;
bool __tgI=0;
char __qgI=0;
u64 __pgI=0;
u64 __ogI=0;
u64 __ngI=0;
u64 __lgI=0;
u64 __kgI=0;
u64 __jgI=0;
u64 __igI=0;
u64 __hgI=0;
u64 __fgI=0;
u64 __egI=0;
f64 __dgI=0;
u64 i=0;
bool __agI=0;
u64 __ZgI=0;
ptr __YgI=0;
cstr __WgI=0;
cstr __QgI=0;
bool __OgI=0;
u64 __NgI=0;
cstr __LgI=0;
bool __IgI=0;
u64 __HgI=0;
u64 __GgI=0;
u64 __FgI=0;
u64 __EgI=0;
u64 __DgI=0;
u64 __CgI=0;
nominal __BgI=0;
cstr __AgI=0;
f64 __9fI=0;
f64 __8fI=0;
f64 __6fI=0;
f64 __5fI=0;
f64 __3fI=0;
f64 __2fI=0;
bool __zfI=0;
f64 __yfI=0;
f64 __wfI=0;
f64 __tfI=0;
bool __qfI=0;
f64 __pfI=0;
f64 __nfI=0;
u64 __mfI=0;
f64 __jfI=0;
bool __efI=0;
f64 __cfI=0;
f64 __ZfI=0;
bool __WfI=0;
f64 __VfI=0;
f64 __TfI=0;
f64 __RfI=0;
f64 __QfI=0;
f64 __OfI=0;
f64 __MfI=0;
f64 __LfI=0;
f64 __KfI=0;
f64 __IfI=0;
f64 __HfI=0;
f64 __GfI=0;
f64 __FfI=0;
f64 __EfI=0;
f64 __DfI=0;
f64 __CfI=0;
f64 __BfI=0;
f64 __AfI=0;
f64 __9eI=0;
nominal __8eI=0;
f64 __7eI=0;
f64 __6eI=0;
f64 __5eI=0;
f64 __4eI=0;
u64 __3eI=0;
u64 __2eI=0;
bool __zeI=0;
u64 __xeI=0;
u64 __weI=0;
u64 __veI=0;
u64 __ueI=0;
u64 __teI=0;
u64 __reI=0;
u64 __qeI=0;
u64 __peI=0;
u64 __oeI=0;
ptr __neI=0;
f64 __leI=0;
nominal __jeI=0;
bool __heI=0;
bool __geI=0;
ptr __feI=0;
bool __eeI=0;
u64 __ceI=0;
u64 __beI=0;
ptr __aeI=0;
char __ZeI=0;
u64 __YeI=0;
u64 __XeI=0;
u64 __VeI=0;
char __UeI=0;
cstr __SeI=0;
bool __PeI=0;
bool __OeI=0;
ptr __NeI=0;
cstr __LeI=0;
bool __IeI=0;
u64 __HeI=0;
u64 __GeI=0;
char __FeI=0;
char __EeI=0;
u64 __DeI=0;
f64 __CeI=0;
f64 __AeI=0;
f64 __9dI=0;
f64 __2dI=0;
cstr __DdI=0;
u64 __6cI=0;
ptr __3cI=0;
f64 __kfI=0;
f64 window__size__w=0;
u64 __HhI=0;
ptr spheres__dynamic____buffer_contents=0;
nominal __hcI=0;
char __dcI=0;
f64 __YcI=0;
f64 __VcI=0;
char __ScI=0;
f64 __PcI=0;
f64 __4bI=0;
f64 __zbI=0;
f64 __ubI=0;
f64 __sbI=0;
nominal __pbI=0;
f64 __obI=0;
cstr window__title=0;
f64 __ibI=0;
u64 __gbI=0;
f64 __SfI=0;
nominal window____EDI=0;
f64 __ZbI=0;
u64 __YbI=0;
ptr __VbI=0;
bool __TbI=0;
bool __SgI=0;
ptr __mKI__contents__mem=0;
u64 __ddI=0;
u64 __odI=0;
u64 __LbI=0;
u64 __ndI=0;
ptr __HbI=0;
char __gdI=0;
u64 __jdI=0;
u64 spheres__dynamic____buffer_alignment=0;
u64 __zaI=0;
u64 __rgI=0;
ptr spheres__dynamic=0;
f64 __hfI=0;
u64 spheres__dynamic____buffer_size=0;
f64 __dfI=0;
f64 window__size__h=0;
f64 accum_fps=0;
f64 prev_t=0;
f64 __RaI=0;
u64 __OaI=0;
ptr __8JI__dynamic=0;
char __IaI=0;
nominal __GaI=0;
f64 __4ZI=0;
ptr __3ZI=0;
u64 __2ZI=0;
u64 __1ZI=0;
u64 __4gI=0;
ptr spheres__surface=0;
u64 __0ZI=0;
ptr __yZI=0;
f64 __xZI=0;
f64 __wZI=0;
f64 __vZI=0;
char __uZI=0;
f64 __tZI=0;
f64 __sZI=0;
f64 __rZI=0;
f64 __qZI=0;
f64 __oZI=0;
f64 __nZI=0;
f64 dt=0;
f64 __mZI=0;
f64 __kZI=0;
f64 __jZI=0;
f64 __iZI=0;
f64 __hZI=0;
cstr __gZI=0;
f64 __fZI=0;
f64 __eZI=0;
u64 __dZI=0;
u64 __cZI=0;
u64 __bZI=0;
u64 __aZI=0;
u64 __ZZI=0;
bool __YZI=0;
cstr __VZI=0;
u64 __UZI=0;
bool __TZI=0;
cstr __QZI=0;
u64 __OZI=0;
bool __NZI=0;
cstr __KZI=0;
u64 __IZI=0;
bool __HZI=0;
cstr __EZI=0;
f64 __CZI=0;
f64 __BZI=0;
cstr __AZI=0;
nominal __9YI=0;
f64 __8YI=0;
f64 __7YI=0;
f64 __5YI=0;
f64 __3YI=0;
f64 __2YI=0;
f64 __0YI=0;
f64 __zYI=0;
f64 __xYI=0;
f64 __vYI=0;
f64 __uYI=0;
f64 __sYI=0;
f64 __qYI=0;
bool __pYI=0;

// IMPLEMENTATION
__8JI__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 __3ZI = 0 ;
 __odI = 2 ;
 if(! __8JI__dynamic )goto __result__buffer_error ;
 __6cI = 5 ;
 __YbI = ((u64*) __8JI__dynamic )[1] ;
 __2ZI = ((u64*) __8JI__dynamic )[2] & ~(1ULL << 63) ;
 if( __odI && __YbI + __odI > __2ZI ){ if( ((u64*) __8JI__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __2ZI = __YbI + __odI +1 ;
 if( __YbI ) { ((u64*) __8JI__dynamic )[0]=(u64)(u64*)__runtime_realloc((u64*)((u64*) __8JI__dynamic )[0],  __2ZI * __6cI *sizeof(u64),  __2ZI * __6cI *sizeof(u64)); memset((u64*)((u64*)((u64*) __8JI__dynamic )[0]) + ( __2ZI * __6cI ), 0, (( __2ZI  -  __2ZI ) *  __6cI  * sizeof(u64))); } else ((u64*) __8JI__dynamic )[0]=(u64)(u64*)__runtime_calloc( __2ZI * __6cI *sizeof(u64)) , 0 ;
 ((u64*) __8JI__dynamic )[2] = __2ZI ;
 __HbI = (ptr)(((u64*) __8JI__dynamic )[0]) ;
 if(! __HbI )goto __result__buffer_error ;
 } else  __HbI = (ptr)(((u64*) __8JI__dynamic )[0]) ;
 ((u64*) __8JI__dynamic )[1] = __YbI + __odI ;
 spheres__dynamic = __8JI__dynamic ;
 spheres__surface = __3ZI ;
 __0ZI = 0 ;
 if(! spheres__dynamic )goto __result__buffer_error ;
 spheres__dynamic____buffer_alignment = 5 ;
 spheres__dynamic____buffer_size = ((u64*) spheres__dynamic )[1] ;
 if( __0ZI >= spheres__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(& __xZI , &((u64*)((void**) spheres__dynamic )[0])[ __0ZI * spheres__dynamic____buffer_alignment +0], sizeof( f64 )) ;
 memcpy(& __ubI , &((u64*)((void**) spheres__dynamic )[0])[ __0ZI * spheres__dynamic____buffer_alignment +1], sizeof( f64 )) ;
 memcpy(& __wZI , &((u64*)((void**) spheres__dynamic )[0])[ __0ZI * spheres__dynamic____buffer_alignment +2], sizeof( f64 )) ;
 memcpy(& __ibI , &((u64*)((void**) spheres__dynamic )[0])[ __0ZI * spheres__dynamic____buffer_alignment +3], sizeof( f64 )) ;
 memcpy(& __2dI , &((u64*)((void**) spheres__dynamic )[0])[ __0ZI * spheres__dynamic____buffer_alignment +4], sizeof( f64 )) ;
 __tZI = 100.0 ;
 __sZI = 100.0 ;
 __4bI = 30.0 ;
 __VcI = 1000.0 ;
 __rZI = 650.0 ;
 if(! spheres__dynamic )goto __result__buffer_error ;
 spheres__dynamic____buffer_size = ((u64*) spheres__dynamic )[1] ;
 spheres__dynamic____buffer_alignment = 5 ;
 spheres__dynamic____buffer_contents = (ptr)(((u64*) spheres__dynamic )[0]) ;
 if( __0ZI >= spheres__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(&((u64*) spheres__dynamic____buffer_contents )[ __0ZI * spheres__dynamic____buffer_alignment +0], & __tZI , sizeof(f64)); memcpy(&((u64*) spheres__dynamic____buffer_contents )[ __0ZI * spheres__dynamic____buffer_alignment +1], & __sZI , sizeof(f64)); memcpy(&((u64*) spheres__dynamic____buffer_contents )[ __0ZI * spheres__dynamic____buffer_alignment +2], & __4bI , sizeof(f64)); memcpy(&((u64*) spheres__dynamic____buffer_contents )[ __0ZI * spheres__dynamic____buffer_alignment +3], & __VcI , sizeof(f64)); memcpy(&((u64*) spheres__dynamic____buffer_contents )[ __0ZI * spheres__dynamic____buffer_alignment +4], & __rZI , sizeof(f64)); __LbI = 1 ;
 if(! spheres__dynamic )goto __result__buffer_error ;
 spheres__dynamic____buffer_alignment = 5 ;
 spheres__dynamic____buffer_size = ((u64*) spheres__dynamic )[1] ;
 if( __LbI >= spheres__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(& __sbI , &((u64*)((void**) spheres__dynamic )[0])[ __LbI * spheres__dynamic____buffer_alignment +0], sizeof( f64 )) ;
 memcpy(& __oZI , &((u64*)((void**) spheres__dynamic )[0])[ __LbI * spheres__dynamic____buffer_alignment +1], sizeof( f64 )) ;
 memcpy(& __vZI , &((u64*)((void**) spheres__dynamic )[0])[ __LbI * spheres__dynamic____buffer_alignment +2], sizeof( f64 )) ;
 memcpy(& __nZI , &((u64*)((void**) spheres__dynamic )[0])[ __LbI * spheres__dynamic____buffer_alignment +3], sizeof( f64 )) ;
 memcpy(& __mZI , &((u64*)((void**) spheres__dynamic )[0])[ __LbI * spheres__dynamic____buffer_alignment +4], sizeof( f64 )) ;
 __PcI = 100.0 ;
 __kZI = 100.0 ;
 __YcI = 30.0 ;
 __jZI = 450.0 ;
 __iZI = 600.0 ;
 if(! spheres__dynamic )goto __result__buffer_error ;
 spheres__dynamic____buffer_size = ((u64*) spheres__dynamic )[1] ;
 spheres__dynamic____buffer_alignment = 5 ;
 spheres__dynamic____buffer_contents = (ptr)(((u64*) spheres__dynamic )[0]) ;
 if( __LbI >= spheres__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(&((u64*) spheres__dynamic____buffer_contents )[ __LbI * spheres__dynamic____buffer_alignment +0], & __PcI , sizeof(f64)); memcpy(&((u64*) spheres__dynamic____buffer_contents )[ __LbI * spheres__dynamic____buffer_alignment +1], & __kZI , sizeof(f64)); memcpy(&((u64*) spheres__dynamic____buffer_contents )[ __LbI * spheres__dynamic____buffer_alignment +2], & __YcI , sizeof(f64)); memcpy(&((u64*) spheres__dynamic____buffer_contents )[ __LbI * spheres__dynamic____buffer_alignment +3], & __jZI , sizeof(f64)); memcpy(&((u64*) spheres__dynamic____buffer_contents )[ __LbI * spheres__dynamic____buffer_alignment +4], & __iZI , sizeof(f64)); __obI = 0.0 ;
 dt = __obI ;
 __hZI = 800.0 ;
 __4ZI = 450.0 ;
 __gZI = "Hello from smoλ+raylib" ;
 SetTraceLogLevel ( LOG_WARNING ); InitWindow ( __hZI , __4ZI ,( char *) __gZI ); 
 __pZI :
 window__size__w = __hZI ;
 window__size__h = __4ZI ;
 window__title = __gZI ;
 __AeI = __smo_time_eta (); 
 __BeI :
 prev_t = __AeI ;
 __CeI = 60.0 ;
 accum_fps = __CeI ;
 __DeI = 1024 ;
 __EeI = 0 ;
 __FeI = __EeI ;
 __HeI = 0 ;
 __IeI =( __DeI == __HeI ); 
 __JeI :
 if(! __IeI )goto __KeI ;
 __LeI = "Cannot allocate zero size" ;
 goto __MeI ;
 __builtin_unreachable();
 __KeI :
 __NeI = __runtime_alloc ( __DeI * sizeof ( __FeI )); 
 __OeI = __NeI ;
 __PeI =(! __OeI ); 
 __QeI :
 if(! __PeI )goto __ReI ;
 __SeI = "Failed a Heap allocation" ;
 goto __TeI ;
 __builtin_unreachable();
 __ReI :
 __UeI = 0 ;
 __VeI = sizeof ( __UeI )* __DeI ; 
 __WeI :
 __FeI = __UeI ;
 __XeI = 0 ;
 __YeI = 0 ;
 __1ZI = __DeI ;
 __ZeI = __FeI ;
 __mKI__contents__mem = __NeI ;
 __aeI = __NeI ;
 __beI = __VeI ;
 __zaI = __XeI ;
 __ceI = __YeI ;
 __deI :
 __eeI = WindowShouldClose (); 
 __geI = __eeI ;
 __heI =(! __geI ); 
 __ieI :
 window____EDI = __jeI ;
 if(! __heI )goto __keI ;
 __leI = __smo_time_eta (); 
 __meI :
 __oeI = spheres__dynamic ? ((u64*) spheres__dynamic )[1]:0 ;
 __peI = 0 ;
 __qeI = 1 ;
 __reI = __peI ;
 __seI :
 __teI = __reI ;
 __ueI = __veI ;
 __ueI = __teI ;
 __ddI = 1 ;
 __xeI = __teI + __ddI ; 
 __yeI :
 __teI = __xeI ;
 __zeI = __teI <= __oeI ; 
 __0eI :
 __reI = __teI ;
 if(! __zeI )goto __1eI ;
 if(! spheres__dynamic )goto __result__buffer_error ;
 __2eI = 5 ;
 __3eI = ((u64*) spheres__dynamic )[1] ;
 if( __ueI >= __3eI )goto __result__buffer_error ;
 memcpy(& __4eI , &((u64*)((void**) spheres__dynamic )[0])[ __ueI * __2eI +0], sizeof( f64 )) ;
 __5eI = __4eI ;
 memcpy(& __6eI , &((u64*)((void**) spheres__dynamic )[0])[ __ueI * __2eI +1], sizeof( f64 )) ;
 __zbI = __6eI ;
 memcpy(& __7eI , &((u64*)((void**) spheres__dynamic )[0])[ __ueI * __2eI +2], sizeof( f64 )) ;
 __9eI = __7eI ;
 memcpy(& __AfI , &((u64*)((void**) spheres__dynamic )[0])[ __ueI * __2eI +3], sizeof( f64 )) ;
 __BfI = __AfI ;
 memcpy(& __CfI , &((u64*)((void**) spheres__dynamic )[0])[ __ueI * __2eI +4], sizeof( f64 )) ;
 __DfI = __CfI ;
 __EfI = __5eI ;
 __FfI = __zbI ;
 __GfI = __BfI ;
 __HfI = __DfI ;
 __IfI = __GfI * dt ; 
 __JfI :
 __KfI = __EfI + __IfI ; 
 __zZI :
 __LfI = __KfI ;
 __MfI = __HfI * dt ; 
 __NfI :
 __OfI = __FfI + __MfI ; 
 __PfI :
 __QfI = __OfI ;
 __RfI = __GfI ;
 __SfI = __HfI ;
 __TfI = __LfI - __9eI ; 
 __UfI :
 __VfI = 0.0 ;
 __WfI = __TfI < __VfI ; 
 __XfI :
 if(! __WfI )goto __YfI ;
 __LfI = __9eI ;
 __ZfI = 0.0 ;
 __qZI = __ZfI - __RfI ; 
 __afI :
 __RfI = __qZI ;
 goto __bfI ;
 __YfI :
 __cfI = __LfI + __9eI ; 
 __ldI :
 __dfI = 800.0 ;
 __efI = __cfI > __dfI ; 
 __ffI :
 if(! __efI )goto __gfI ;
 __9dI = 800.0 ;
 __hfI = __9dI - __9eI ; 
 __ifI :
 __LfI = __hfI ;
 __jfI = 0.0 ;
 __kfI = __jfI - __RfI ; 
 __lfI :
 __RfI = __kfI ;
 __nfI = __QfI - __9eI ; 
 __ofI :
 __pfI = 0.0 ;
 __qfI = __nfI < __pfI ; 
 __rfI :
 if(! __qfI )goto __sfI ;
 __QfI = __9eI ;
 __ZbI = 0.0 ;
 __tfI = __ZbI - __SfI ; 
 __ufI :
 __SfI = __tfI ;
 goto __vfI ;
 __sfI :
 __wfI = __QfI + __9eI ; 
 __xfI :
 __yfI = 450.0 ;
 __zfI = __wfI > __yfI ; 
 __0fI :
 if(! __zfI )goto __1fI ;
 __2fI = 450.0 ;
 __3fI = __2fI - __9eI ; 
 __4fI :
 __QfI = __3fI ;
 __5fI = 0.0 ;
 __6fI = __5fI - __SfI ; 
 __7fI :
 __SfI = __6fI ;
 __1fI :
 __vfI :
 __EfI = __LfI ;
 __FfI = __QfI ;
 __GfI = __RfI ;
 __HfI = __SfI ;
 __gfI :
 __bfI :
 __5eI = __EfI ;
 __zbI = __FfI ;
 __BfI = __GfI ;
 __DfI = __HfI ;
 memcpy(&((u64*)((u64*) spheres__dynamic )[0])[ __ueI * __2eI +0], & __5eI , sizeof( __5eI )) ;
 memcpy(&((u64*)((u64*) spheres__dynamic )[0])[ __ueI * __2eI +1], & __zbI , sizeof( __zbI )) ;
 memcpy(&((u64*)((u64*) spheres__dynamic )[0])[ __ueI * __2eI +2], & __9eI , sizeof( __9eI )) ;
 memcpy(&((u64*)((u64*) spheres__dynamic )[0])[ __ueI * __2eI +3], & __BfI , sizeof( __BfI )) ;
 memcpy(&((u64*)((u64*) spheres__dynamic )[0])[ __ueI * __2eI +4], & __DfI , sizeof( __DfI )) ;
 goto __seI ;
 __1eI :
 BeginDrawing (); 
 __8fI = window__size__w ;
 __9fI = window__size__h ;
 __AgI = window__title ;
 window____EDI = __BgI ;
 __CgI = 50 ;
 __EgI = 50 ;
 __FgI = 80 ;
 __GgI = 255 ;
 __HgI = 255 ;
 __IgI = __CgI > __HgI ; 
 __JgI :
 if(! __IgI )goto __KgI ;
 __LgI = "Color r greater than 255" ;
 goto __MgI ;
 __builtin_unreachable();
 __KgI :
 __NgI = 255 ;
 __OgI = __EgI > __NgI ; 
 __xaI :
 if(! __OgI )goto __PgI ;
 __QgI = "Color g greater than 255" ;
 goto __RgI ;
 __builtin_unreachable();
 __PgI :
 __OaI = 255 ;
 __SgI = __FgI > __OaI ; 
 __TgI :
 if(! __SgI )goto __VgI ;
 __WgI = "Color b greater than 255" ;
 goto __XgI ;
 __builtin_unreachable();
 __VgI :
 __ZgI = 255 ;
 __agI = __GgI > __ZgI ; 
 __bgI :
 if(! __agI )goto __cgI ;
 __DdI = "Color a greater than 255" ;
 goto __lZI ;
 __builtin_unreachable();
 __cgI :
 ClearBackground (( Color ) {( unsigned char ) __CgI ,( unsigned char ) __EgI ,( unsigned char ) __FgI ,( unsigned char ) __GgI }); 
 __dgI = __8fI ;
 __egI = spheres__dynamic ? ((u64*) spheres__dynamic )[1]:0 ;
 __fgI = __egI ;
 __hgI = 0 ;
 __igI = 1 ;
 __jgI = __hgI ;
 __kgI = __igI ;
 __lgI = __hgI ;
 __mgI :
 __ngI = __lgI ;
 __ogI = i ;
 __ogI = __ngI ;
 __pgI = 1 ;
 __rgI = __ngI + __pgI ; 
 __sgI :
 __ngI = __rgI ;
 __tgI = __ngI <= __fgI ; 
 __ugI :
 __lgI = __ngI ;
 if(! __tgI )goto __wgI ;
 if(! spheres__dynamic )goto __result__buffer_error ;
 spheres__dynamic____buffer_alignment = 5 ;
 spheres__dynamic____buffer_size = ((u64*) spheres__dynamic )[1] ;
 if( __ogI >= spheres__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(& __xgI , &((u64*)((void**) spheres__dynamic )[0])[ __ogI * spheres__dynamic____buffer_alignment +0], sizeof( f64 )) ;
 memcpy(& __ygI , &((u64*)((void**) spheres__dynamic )[0])[ __ogI * spheres__dynamic____buffer_alignment +1], sizeof( f64 )) ;
 memcpy(& __zgI , &((u64*)((void**) spheres__dynamic )[0])[ __ogI * spheres__dynamic____buffer_alignment +2], sizeof( f64 )) ;
 memcpy(& __0gI , &((u64*)((void**) spheres__dynamic )[0])[ __ogI * spheres__dynamic____buffer_alignment +3], sizeof( f64 )) ;
 memcpy(& __1gI , &((u64*)((void**) spheres__dynamic )[0])[ __ogI * spheres__dynamic____buffer_alignment +4], sizeof( f64 )) ;
 __2gI = 200 ;
 __3gI = 50 ;
 __4gI = 50 ;
 __5gI = 255 ;
 __6gI = 255 ;
 __7gI = __2gI > __6gI ; 
 __8gI :
 if(! __7gI )goto __9gI ;
 __AhI = "Color r greater than 255" ;
 goto __BhI ;
 __builtin_unreachable();
 __9gI :
 __ChI = 255 ;
 __DhI = __3gI > __ChI ; 
 __EhI :
 if(! __DhI )goto __UgI ;
 __FhI = "Color g greater than 255" ;
 goto __GhI ;
 __builtin_unreachable();
 __UgI :
 __HhI = 255 ;
 __TbI = __4gI > __HhI ; 
 __IhI :
 if(! __TbI )goto __JhI ;
 __KhI = "Color b greater than 255" ;
 goto __LhI ;
 __builtin_unreachable();
 __JhI :
 __MhI = 255 ;
 __NhI = __5gI > __MhI ; 
 __OhI :
 if(! __NhI )goto __PhI ;
 __QhI = "Color a greater than 255" ;
 goto __jbI ;
 __builtin_unreachable();
 __PhI :
 DrawCircleV (( Vector2 ) {( float ) __xgI ,( float ) __ygI },( float ) __zgI ,( Color ) {( unsigned char ) __2gI ,( unsigned char ) __3gI ,( unsigned char ) __4gI ,( unsigned char ) __5gI }); 
 __RhI = window__size__w ;
 window____EDI = __ShI ;
 window__size__w = window__size__w ;
 window__size__h = window__size__h ;
 window__title = window__title ;
 __ThI = accum_fps ;
 __DgI = __1ZI ;
 __uZI = __ZeI ;
 __yZI = __mKI__contents__mem ;
 __VbI = __aeI ;
 __mfI = __beI ;
 __UhI = __zaI ;
 __VhI = __ceI ;
 __GeI = 21 ;
 __WhI = 0 ;
 __IaI = __dcI ;
 __XhI = __GeI * sizeof ( __IaI ); 
 __gbI = __XhI ;
 __YhI = __gbI > __DgI ; 
 __ZhI :
 if(! __YhI )goto __FcI ;
 __ahI = "Failed a Volatile allocation" ;
 goto __MaI ;
 __builtin_unreachable();
 __FcI :
 if ( __UhI + __XhI > __DgI ) { __UhI =0; __VhI = __VhI +1; } 
 __chI =( ptr )(( char *) __yZI + __UhI ); 
 __UhI = __UhI + __XhI ; 
 __dhI = 0 ;
 __ehI = sizeof ( __dhI )* __XhI ; 
 __fhI :
 __IaI = __dhI ;
 if ( __chI ) { __ghI =( u64 ) snprintf (( char *) __chI , sizeof ( char )* 21 , "%lu" , __ThI ); if ( __ghI < 32 ) { __hhI = malloc ( __ghI +1); if ( __hhI ) { memcpy ( __hhI ,( char *) __chI , __ghI );(( char *) __hhI )[ __ghI ]=0; __ihI =(( char *) __hhI )[0]; } } } 
 __jhI = __hhI ;
 __khI =( __jhI ); 
 __lhI :
 __mhI =(! __khI ); 
 __nhI :
 if(! __mhI )goto __bhI ;
 goto __ohI ;
 __builtin_unreachable();
 __bhI :
 __GaI = __phI ;
 __qhI = __hcI ;
 __pbI = __rhI ;
 __1ZI = __DgI ;
 __ZeI = __uZI ;
 __mKI__contents__mem = __yZI ;
 __aeI = __VbI ;
 __beI = __mfI ;
 __zaI = __UhI ;
 __ceI = __VhI ;
 __shI = " fps" ;
 __thI = strlen ( __shI ); __neI =( ptr ) __shI ; __ScI = __shI [0]; __uhI =( ptr ) __uhI ; 
 __3cI = __neI ;
 __whI = __ghI ; __jdI = __thI ; __ndI = __whI + __jdI ; __xhI = __ghI ? __ihI : __ScI ; 
 __weI = 1 ;
 __yhI = __ndI + __weI ; 
 __zhI :
 __gdI = 0 ;
 __0hI = __1hI ;
 __2hI = __yhI * sizeof ( __0hI ); 
 __3hI = __2hI ;
 __4hI = __3hI > __1ZI ; 
 __WdI :
 if(! __4hI )goto __vgI ;
 __5hI = "Failed a Volatile allocation" ;
 goto __ggI ;
 __builtin_unreachable();
 __vgI :
 if ( __zaI + __2hI > __1ZI ) { __zaI =0; __ceI = __ceI +1; } 
 __feI =( ptr )(( char *) __mKI__contents__mem + __zaI ); 
 __zaI = __zaI + __2hI ; 
 __qgI = 0 ;
 __vhI = sizeof ( __qgI )* __2hI ; 
 __6hI :
 __0hI = __qgI ;
 memcpy (( char *) __feI ,( char *) __hhI , __whI ); memcpy (( char *) __feI + __whI ,( char *) __3cI , __jdI );(( char *) __feI )[ __ndI ]=0; 
 __YgI = __feI ;
 __GaI = __7hI ;
 __qhI = __8eI ;
 __pbI = __8hI ;
 __1ZI = __1ZI ;
 __ZeI = __ZeI ;
 __mKI__contents__mem = __mKI__contents__mem ;
 __aeI = __aeI ;
 __beI = __beI ;
 __zaI = __zaI ;
 __ceI = __ceI ;
 __fZI = 10.0 ;
 __RaI = 10.0 ;
 __eZI = 20.0 ;
 __dZI = 255 ;
 __cZI = 255 ;
 __bZI = 255 ;
 __aZI = 255 ;
 __ZZI = 255 ;
 __YZI = __dZI > __ZZI ; 
 __XZI :
 if(! __YZI )goto __WZI ;
 __VZI = "Color r greater than 255" ;
 goto __fbI ;
 __builtin_unreachable();
 __WZI :
 __UZI = 255 ;
 __TZI = __cZI > __UZI ; 
 __SZI :
 if(! __TZI )goto __RZI ;
 __QZI = "Color g greater than 255" ;
 goto __PZI ;
 __builtin_unreachable();
 __RZI :
 __OZI = 255 ;
 __NZI = __bZI > __OZI ; 
 __MZI :
 if(! __NZI )goto __LZI ;
 __KZI = "Color b greater than 255" ;
 goto __JZI ;
 __builtin_unreachable();
 __LZI :
 __IZI = 255 ;
 __HZI = __aZI > __IZI ; 
 __GZI :
 if(! __HZI )goto __FZI ;
 __EZI = "Color a greater than 255" ;
 goto __DZI ;
 __builtin_unreachable();
 __FZI :
 DrawText (( char *) __YgI , __fZI , __RaI , __eZI ,( Color ) {( unsigned char ) __dZI ,( unsigned char ) __cZI ,( unsigned char ) __bZI ,( unsigned char ) __aZI }); 
 __CZI = window__size__w ;
 __BZI = window__size__h ;
 __AZI = window__title ;
 window____EDI = __9YI ;
 EndDrawing (); 
 __8YI = __CZI ;
 __7YI = __smo_time_eta (); 
 __6YI :
 __5YI = __7YI - prev_t ; 
 __4YI :
 dt = __5YI ;
 prev_t = __7YI ;
 __3YI = 0.99 ;
 __2YI = accum_fps * __3YI ; 
 __1YI :
 __0YI = 0.01 ;
 __zYI = __0YI / dt ; 
 __yYI :
 __xYI = __2YI + __zYI ; 
 __wYI :
 accum_fps = __xYI ;
 __vYI = 0.015 ;
 __uYI = __7YI - __leI ; 
 __tYI :
 __sYI = __vYI - __uYI ; 
 __rYI :
 __qYI = 0.0 ;
 __pYI = __sYI <= __qYI ; 
 __oYI :
 if(! __pYI )goto __nYI ;
 goto __mYI ;
 __nYI :
 __smo_exact_sleep ( __sYI ); 
 __mYI :
 goto __mgI ;
 __wgI :
 goto __deI ;
 __keI :
 __lYI :
goto __return;

// ERROR HANDLING
__GhI :
 printf ( "%s\n" , __FhI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__DZI :
 printf ( "%s\n" , __EZI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__MgI :
 printf ( "%s\n" , __LgI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__JZI :
 printf ( "%s\n" , __KZI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__result__buffer_error :
printf("Buffer error\n");
__result__errocode=__BUFFER__ERROR;
goto __failsafe;
__PZI :
 printf ( "%s\n" , __QZI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__TeI :
 printf ( "%s\n" , __SeI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__MeI :
 printf ( "%s\n" , __LeI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__XgI :
 printf ( "%s\n" , __WgI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__BhI :
 printf ( "%s\n" , __AhI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__RgI :
 printf ( "%s\n" , __QgI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__jbI :
 printf ( "%s\n" , __QhI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__MaI :
 printf ( "%s\n" , __ahI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__fbI :
 printf ( "%s\n" , __VZI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__lZI :
 printf ( "%s\n" , __DdI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__ggI :
 printf ( "%s\n" , __5hI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__LhI :
 printf ( "%s\n" , __KhI ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__ohI :
 printf ( "Failed to allocate str from number\n" ); 
__result__errocode=__USER__ERROR;
goto __failsafe;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
if ( __mKI__contents__mem ) __runtime_free ( __mKI__contents__mem ); __mKI__contents__mem =0; 
if( __8JI__dynamic ){if((u64*)((u64*) __8JI__dynamic )[2]) __runtime_free((u64*)((u64*) __8JI__dynamic )[0]) ;
 __runtime_free( __8JI__dynamic ) ;
 __8JI__dynamic = 0 ;
 }__state->err =  __result__errocode;
}


void main__1205(void *__void__state){
errcode __result__errocode=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1896;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__1205__state *__state=(struct main__1205__state*)__void__state;
struct test__1204__state* __EVI____state = 0 ;
ptr __BiI=0;
errcode __AiI=0;

// IMPLEMENTATION
{char mark;if(__service_stack_floor+ 3504 >=(char*)&mark) goto __service_stack_floor_handler;} __EVI____state = (struct test__1204__state*)__runtime_calloc(sizeof(struct test__1204__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __EVI____state ) ;
 __BiI = __smolambda_add_task ( test__1204 , __EVI____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __BiI ) ;
 if( __AiI ) goto  __result_unhandled_error ;
 __9hI :
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

