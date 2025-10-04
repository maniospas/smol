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

#include<stdlib.h>

#include<stdio.h>

struct main__871__state{errcode err;};
__externc void main__871(void *__void__state);

void main__871(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__871__state *__state=(struct main__871__state*)__void__state;
cstr __gIB____0HB=0;
bool __gIB____wHB__z=0;
cstr __gIB____sHB____ECB=0;
bool __gIB____sHB____DCB__z=0;
cstr __gIB____pHB=0;
bool __gIB____oHB=0;
bool __gIB____mHB____1D__z=0;
u64 __gIB____mHB____0D__z=0;
u64 __gIB__pos=0;
u64 __gIB____mHB__value=0;
u64 __gIB____kHB____wD=0;
u64 __gIB____eHB__if__r=0;
u64 __gIB____hHB=0;
bool __gIB____gHB__z=0;
nominal __fIB____IFB__self__contents____EF____8E=0;
nominal __fIB____IFB__self__contents____DF=0;
u64 __fIB__i=0;
cstr __fIB____IFB____MT=0;
f64 __fIB____IFB____RT=0;
bool __fIB____IFB____LT__z=0;
u64 __fIB____IFB____KT__z=0;
u64 __fIB____IFB____KT__x=0;
f64 __fIB____IFB____IT=0;
u64 __fIB____IFB__size=0;
f64 __fIB____GFB=0;
u64 __fIB__size=0;
cstr __fIB____EFB=0;
bool __fIB____DFB__z=0;
nominal __eIB____AIB____49__self__contents____EF____8E=0;
cstr __gIB____iHB=0;
nominal __eIB____AIB____49__self__type=0;
ptr __eIB____DIB__contents=0;
u64 __gIB____fHB=0;
f64 __eIB____CIB=0;
bool __XIB____QW____YI____zF=0;
u64 __eIB____AIB____79____zD=0;
ptr memory__contents__underlying=0;
cstr __eIB____DIB____ICB=0;
u64 __gIB____kHB__pos=0;
u64 __bIB____AIB____49____KT__x=0;
u64 __bIB____AIB____59____xD=0;
f64 __fIB____IFB____TT____WF=0;
u64 memory__contents__size=0;
u64 __dIB=0;
f64 __bIB____CIB=0;
char __XIB____QW____YI____xF=0;
nominal __fIB____IFB__self__type=0;
u64 __bIB__memory__size=0;
u64 __aIB=0;
bool __bIB____AIB____49____LT__z=0;
ptr memory__contents__mem=0;
bool __bIB____AIB____79____1D__z=0;
bool __eIB____DIB____HCB__z=0;
u64 __WIB=0;
u64 __cIB=0;
u64 __bIB____AIB____79__value=0;
u64 __fIB____IFB____TT__bytesize=0;
u64 __gIB____mHB__self__pos=0;
ptr __fIB____IFB___contents=0;
f64 __bIB____AIB____49____TT____WF=0;
u64 __gIB____kHB____xD=0;
nominal __bIB____AIB____49__self__type=0;
bool __eIB____AIB____49____LT__z=0;
u64 __eIB____AIB____59____xD=0;
cstr __gIB____xHB=0;
bool __eIB____AIB____79____1D__z=0;
f64 __eIB____AIB____49____RT=0;
u64 __bIB____AIB____79____zD=0;
u64 __XIB__size=0;
u64 __bIB____AIB____49__size=0;
nominal __eIB____AIB____49__self__contents____DF=0;
u64 __eIB__size=0;
cstr __eIB____AIB____49____MT=0;
u64 __bIB____AIB____49____KT__z=0;
ptr __fIB____LFB__contents=0;
u64 __bIB____AIB____79__self__pos=0;
u64 __bIB____AIB____59____wD=0;
f64 __eIB____AIB____49____TT____WF=0;
cstr __XIB____QW____YI____1F=0;
ptr __XIB__contents__mem=0;
char __XIB____QW____WI=0;
bool __XIB____QW____YI____uF__z=0;
char __XIB____RW____pO=0;
u64 __bIB____AIB____59__pos=0;
cstr __XIB____QW____YI____vF=0;
char __XIB____QW____YI____7F=0;
u64 __bIB____AIB__i=0;
u64 __XIB____QW____YI____9F__bytesize=0;
char __XIB____QW____YI____9F____GF=0;
u64 __XIB____RW____nO=0;
char __XIB____RW____qO=0;
char memory__contents____FF=0;
u64 memory__contents__bytesize=0;
f64 __gIB____sHB__value=0;
u64 __bIB____AIB____49____TT__bytesize=0;
ptr __bIB____DIB__contents=0;
u64 memory__length=0;
u64 memory__size=0;
u64 __ZIB=0;
u64 __bIB__memory__contents__size=0;
char __bIB__memory__contents____FF=0;
ptr __bIB__memory__contents__mem=0;
ptr __bIB__memory__contents__underlying=0;
u64 __bIB__memory__contents__bytesize=0;
u64 __bIB__memory__length=0;
u64 __bIB__size=0;
f64 __bIB____AIB____29=0;
u64 __eIB____AIB____79____0D__z=0;
u64 __eIB__memory__contents__size=0;
u64 __eIB____AIB____79__self__pos=0;
cstr __bIB____AIB____49____MT=0;
ptr __bIB____AIB____49___contents=0;
f64 __bIB____AIB____49____RT=0;
u64 __bIB____AIB____79____0D__z=0;
bool __bIB____DIB____HCB__z=0;
u64 __gIB____mHB____zD=0;
cstr __bIB____DIB____ICB=0;
u64 __eIB____AIB____59____wD=0;
bool __XIB____QW____YI____0F__z=0;
nominal memory__type=0;
u64 __eIB__memory__contents__bytesize=0;
nominal memory__contents____DF=0;
nominal __bIB____AIB____49__self__contents____DF=0;
nominal memory__contents____EF____8E=0;
nominal __bIB____AIB____49__self__contents____EF____8E=0;
char __eIB__memory__contents____FF=0;
ptr __eIB__memory__contents__mem=0;
ptr __eIB__memory__contents__underlying=0;
u64 __eIB__memory__length=0;
u64 __eIB__memory__size=0;
ptr __XIB____QW____YI__mem=0;
u64 __XIB____QW____YI____tF=0;
f64 __eIB____AIB____29=0;
u64 __eIB____AIB____49__size=0;
f64 __eIB____AIB____49____IT=0;
f64 __bIB____AIB____49____IT=0;
u64 __eIB____AIB____49____KT__x=0;
u64 __eIB____AIB____49____KT__z=0;
ptr __eIB____AIB____49___contents=0;
u64 __eIB____AIB____49____TT__bytesize=0;
u64 __eIB____AIB____59__pos=0;
u64 __eIB____AIB____79__value=0;
u64 __eIB____AIB__i=0;

// IMPLEMENTATION
__WIB = 1024 ;
 __XIB__size = __WIB ;
 __XIB____QW____WI = 0 ;
 __XIB____QW____YI____tF = 0 ;
 __XIB____QW____YI____uF__z =( __XIB__size == __XIB____QW____YI____tF ); 
 __XIB____QW____YI____uF____end :
 if(! __XIB____QW____YI____uF__z )goto __XIB____QW____YI____sF__fi ;
 __XIB____QW____YI____vF = "Cannot allocate zero size" ;
 goto __XIB____QW____YI____wF____oD ;
 __builtin_unreachable();
 __XIB____QW____YI____sF__fi :
 __XIB____QW____YI__mem = alloca ( __XIB__size * sizeof ( __XIB____QW____YI____xF )); 
 __XIB____QW____YI____zF = __XIB____QW____YI__mem ;
 __XIB____QW____YI____0F__z =(! __XIB____QW____YI____zF ); 
 __XIB____QW____YI____0F____end :
 if(! __XIB____QW____YI____0F__z )goto __XIB____QW____YI____yF__fi ;
 __XIB____QW____YI____1F = "Failed a Stack allocation" ;
 goto __XIB____QW____YI____2F____oD ;
 __builtin_unreachable();
 __XIB____QW____YI____yF__fi :
 __XIB____QW____YI____7F = 0 ;
 __XIB____QW____YI____9F__bytesize = sizeof ( __XIB____QW____YI____9F____GF )* __XIB__size ; 
 __XIB____QW____YI____9F____end :
 __XIB____RW____nO = 0 ;
 __XIB____RW____pO = 0 ;
 __XIB____RW____qO = 0 ;
 __XIB__contents__mem = __XIB____QW____YI__mem ;
 __XIB__size = __XIB__size ;
 memory__contents__size = __XIB__size ;
 memory__contents____FF = __XIB____QW____YI____7F ;
 memory__contents__mem = __XIB__contents__mem ;
 memory__contents__underlying = __XIB____QW____YI__mem ;
 memory__contents__bytesize = __XIB____QW____YI____9F__bytesize ;
 memory__length = __XIB____RW____nO ;
 memory__size = __XIB__size ;
 __ZIB = 1 ;
 __aIB = 10 ;
 __bIB__memory__contents__size = memory__contents__size ;
 __bIB__memory__contents____FF = memory__contents____FF ;
 __bIB__memory__contents__mem = memory__contents__mem ;
 __bIB__memory__contents__underlying = memory__contents__underlying ;
 __bIB__memory__contents__bytesize = memory__contents__bytesize ;
 __bIB__memory__length = memory__length ;
 __bIB__memory__size = memory__size ;
 __bIB__size = __aIB ;
 __bIB____AIB____29 = 0 ;
 __bIB____AIB____49__size = __bIB__size * sizeof ( __bIB____AIB____49____IT ); 
 __bIB____AIB____49____KT__x = __bIB__memory__length ;
 __bIB____AIB____49____KT__z = __bIB____AIB____49____KT__x + __bIB____AIB____49__size ; 
 __bIB____AIB____49____KT____end :
 __bIB____AIB____49____LT__z = __bIB____AIB____49____KT__z > __bIB__memory__contents__size ; 
 __bIB____AIB____49____LT____end :
 if(! __bIB____AIB____49____LT__z )goto __bIB____AIB____49____JT__fi ;
 __bIB____AIB____49____MT = "Failed an Arena allocation" ;
 goto __bIB____AIB____49____NT____oD ;
 __builtin_unreachable();
 __bIB____AIB____49____JT__fi :
 __bIB____AIB____49___contents =( ptr )(( char *) __bIB__memory__contents__mem + __bIB__memory__length * sizeof ( char )); 
 __bIB__memory__length = __bIB__memory__length + __bIB____AIB____49__size ; 
 __bIB____AIB____49____RT = 0 ;
 __bIB____AIB____49____TT__bytesize = sizeof ( __bIB____AIB____49____TT____WF )* __bIB____AIB____49__size ; 
 __bIB____AIB____49____TT____end :
 __bIB____AIB____59____wD = 0 ;
 __bIB____AIB____59____xD = 1 ;
 __bIB____AIB____59__pos = __bIB____AIB____59____wD ;
 __bIB____AIB____69__loop :
 __bIB____AIB____79__self__pos = __bIB____AIB____59__pos ;
 __bIB____AIB____79__value = __bIB____AIB__i ;
 __bIB____AIB____79__value = __bIB____AIB____79__self__pos ;
 __bIB____AIB____79____zD = 1 ;
 __bIB____AIB____79____0D__z = __bIB____AIB____79__self__pos + __bIB____AIB____79____zD ; 
 __bIB____AIB____79____0D____end :
 __bIB____AIB____79__self__pos = __bIB____AIB____79____0D__z ;
 __bIB____AIB____79____1D__z = __bIB____AIB____79__self__pos <= __bIB__size ; 
 __bIB____AIB____79____1D____end :
 __bIB____AIB____59__pos = __bIB____AIB____79__self__pos ;
 if(! __bIB____AIB____79____1D__z )goto __bIB____AIB____69__while ;
 (( f64 *) __bIB____AIB____49___contents )[ __bIB____AIB____79__value ]=0; 
 goto __bIB____AIB____69__loop ;
 __bIB____AIB____69__while :
 __bIB____CIB = 1.0 ;
 __bIB____DIB____HCB__z = __ZIB >= __bIB__size ; 
 __bIB____DIB____HCB____end :
 if(! __bIB____DIB____HCB__z )goto __bIB____DIB____GCB__fi ;
 __bIB____DIB____ICB = "Vec out of bounds" ;
 goto __bIB____DIB____JCB____oD ;
 __builtin_unreachable();
 __bIB____DIB____GCB__fi :
 (( f64 *) __bIB____AIB____49___contents )[ __ZIB ]= __bIB____CIB ; 
 __bIB____DIB__contents = __bIB____AIB____49___contents ;
 __bIB__size = __bIB__size ;
 memory__type = __bIB____AIB____49__self__type ;
 memory__contents____DF = __bIB____AIB____49__self__contents____DF ;
 memory__contents____EF____8E = __bIB____AIB____49__self__contents____EF____8E ;
 memory__contents__size = __bIB__memory__contents__size ;
 memory__contents____FF = __bIB__memory__contents____FF ;
 memory__contents__mem = __bIB__memory__contents__mem ;
 memory__contents__underlying = __bIB__memory__contents__underlying ;
 memory__contents__bytesize = __bIB__memory__contents__bytesize ;
 memory__length = __bIB__memory__length ;
 memory__size = __bIB__memory__size ;
 __cIB = 1 ;
 __dIB = 10 ;
 __eIB__memory__contents__size = memory__contents__size ;
 __eIB__memory__contents____FF = memory__contents____FF ;
 __eIB__memory__contents__mem = memory__contents__mem ;
 __eIB__memory__contents__underlying = memory__contents__underlying ;
 __eIB__memory__contents__bytesize = memory__contents__bytesize ;
 __eIB__memory__length = memory__length ;
 __eIB__memory__size = memory__size ;
 __eIB__size = __dIB ;
 __eIB____AIB____29 = 0 ;
 __eIB____AIB____49__size = __eIB__size * sizeof ( __eIB____AIB____49____IT ); 
 __eIB____AIB____49____KT__x = __eIB__memory__length ;
 __eIB____AIB____49____KT__z = __eIB____AIB____49____KT__x + __eIB____AIB____49__size ; 
 __eIB____AIB____49____KT____end :
 __eIB____AIB____49____LT__z = __eIB____AIB____49____KT__z > __eIB__memory__contents__size ; 
 __eIB____AIB____49____LT____end :
 if(! __eIB____AIB____49____LT__z )goto __eIB____AIB____49____JT__fi ;
 __eIB____AIB____49____MT = "Failed an Arena allocation" ;
 goto __eIB____AIB____49____NT____oD ;
 __builtin_unreachable();
 __eIB____AIB____49____JT__fi :
 __eIB____AIB____49___contents =( ptr )(( char *) __eIB__memory__contents__mem + __eIB__memory__length * sizeof ( char )); 
 __eIB__memory__length = __eIB__memory__length + __eIB____AIB____49__size ; 
 __eIB____AIB____49____RT = 0 ;
 __eIB____AIB____49____TT__bytesize = sizeof ( __eIB____AIB____49____TT____WF )* __eIB____AIB____49__size ; 
 __eIB____AIB____49____TT____end :
 __eIB____AIB____59____wD = 0 ;
 __eIB____AIB____59____xD = 1 ;
 __eIB____AIB____59__pos = __eIB____AIB____59____wD ;
 __eIB____AIB____69__loop :
 __eIB____AIB____79__self__pos = __eIB____AIB____59__pos ;
 __eIB____AIB____79__value = __eIB____AIB__i ;
 __eIB____AIB____79__value = __eIB____AIB____79__self__pos ;
 __eIB____AIB____79____zD = 1 ;
 __eIB____AIB____79____0D__z = __eIB____AIB____79__self__pos + __eIB____AIB____79____zD ; 
 __eIB____AIB____79____0D____end :
 __eIB____AIB____79__self__pos = __eIB____AIB____79____0D__z ;
 __eIB____AIB____79____1D__z = __eIB____AIB____79__self__pos <= __eIB__size ; 
 __eIB____AIB____79____1D____end :
 __eIB____AIB____59__pos = __eIB____AIB____79__self__pos ;
 if(! __eIB____AIB____79____1D__z )goto __eIB____AIB____69__while ;
 (( f64 *) __eIB____AIB____49___contents )[ __eIB____AIB____79__value ]=0; 
 goto __eIB____AIB____69__loop ;
 __eIB____AIB____69__while :
 __eIB____CIB = 1.0 ;
 __eIB____DIB____HCB__z = __cIB >= __eIB__size ; 
 __eIB____DIB____HCB____end :
 if(! __eIB____DIB____HCB__z )goto __eIB____DIB____GCB__fi ;
 __eIB____DIB____ICB = "Vec out of bounds" ;
 goto __eIB____DIB____JCB____oD ;
 __builtin_unreachable();
 __eIB____DIB____GCB__fi :
 (( f64 *) __eIB____AIB____49___contents )[ __cIB ]= __eIB____CIB ; 
 __eIB____DIB__contents = __eIB____AIB____49___contents ;
 __eIB__size = __eIB__size ;
 memory__type = __eIB____AIB____49__self__type ;
 memory__contents____DF = __eIB____AIB____49__self__contents____DF ;
 memory__contents____EF____8E = __eIB____AIB____49__self__contents____EF____8E ;
 memory__contents__size = __eIB__memory__contents__size ;
 memory__contents____FF = __eIB__memory__contents____FF ;
 memory__contents__mem = __eIB__memory__contents__mem ;
 memory__contents__underlying = __eIB__memory__contents__underlying ;
 memory__contents__bytesize = __eIB__memory__contents__bytesize ;
 memory__length = __eIB__memory__length ;
 memory__size = __eIB__memory__size ;
 __fIB____DFB__z =( __bIB__size != __eIB__size ); 
 __fIB____DFB____end :
 if(! __fIB____DFB__z )goto __fIB____CFB__fi ;
 __fIB____EFB = "Incompatible Vec sizes" ;
 goto __fIB____FFB____oD ;
 __builtin_unreachable();
 __fIB____CFB__fi :
 __builtin_assume ( __bIB__size == __eIB__size ); 
 __fIB__size = __bIB__size ;
 __fIB____GFB = 0 ;
 __fIB____IFB__size = __fIB__size * sizeof ( __fIB____IFB____IT ); 
 __fIB____IFB____KT__x = memory__length ;
 __fIB____IFB____KT__z = __fIB____IFB____KT__x + __fIB____IFB__size ; 
 __fIB____IFB____KT____end :
 __fIB____IFB____LT__z = __fIB____IFB____KT__z > memory__contents__size ; 
 __fIB____IFB____LT____end :
 if(! __fIB____IFB____LT__z )goto __fIB____IFB____JT__fi ;
 __fIB____IFB____MT = "Failed an Arena allocation" ;
 goto __fIB____IFB____NT____oD ;
 __builtin_unreachable();
 __fIB____IFB____JT__fi :
 __fIB____IFB___contents =( ptr )(( char *) memory__contents__mem + memory__length * sizeof ( char )); 
 memory__length = memory__length + __fIB____IFB__size ; 
 __fIB____IFB____RT = 0 ;
 __fIB____IFB____TT__bytesize = sizeof ( __fIB____IFB____TT____WF )* __fIB____IFB__size ; 
 __fIB____IFB____TT____end :
 for( __fIB__i =0; __fIB__i < __fIB__size ;++ __fIB__i )(( f64 *) __fIB____IFB___contents )[ __fIB__i ]=(( f64 *) __bIB____DIB__contents )[ __fIB__i ]*(( f64 *) __eIB____DIB__contents )[ __fIB__i ]; 
 __fIB____LFB__contents = __fIB____IFB___contents ;
 memory__type = __fIB____IFB__self__type ;
 memory__contents____DF = __fIB____IFB__self__contents____DF ;
 memory__contents____EF____8E = __fIB____IFB__self__contents____EF____8E ;
 memory__contents__size = memory__contents__size ;
 memory__contents____FF = memory__contents____FF ;
 memory__contents__mem = memory__contents__mem ;
 memory__contents__underlying = memory__contents__underlying ;
 memory__contents__bytesize = memory__contents__bytesize ;
 memory__length = memory__length ;
 memory__size = memory__size ;
 __gIB____fHB = 10 ;
 __gIB____gHB__z = __fIB__size > __gIB____fHB ; 
 __gIB____gHB____end :
 if(! __gIB____gHB__z )goto __gIB____eHB__fi ;
 __gIB____hHB = 10 ;
 __gIB____eHB__if__r = __gIB____hHB ;
 goto __gIB____eHB__el ;
 __gIB____eHB__fi :
 __gIB____eHB__if__r = __fIB__size ;
 __gIB____eHB__el :
 __gIB____iHB = "[" ;
 printf ( "%s" , __gIB____iHB ); 
 __gIB____jHB____end :
 __gIB____kHB____wD = 0 ;
 __gIB____kHB____xD = 1 ;
 __gIB____kHB__pos = __gIB____kHB____wD ;
 __gIB____lHB__loop :
 __gIB____mHB__self__pos = __gIB____kHB__pos ;
 __gIB____mHB__value = __gIB__pos ;
 __gIB____mHB__value = __gIB____mHB__self__pos ;
 __gIB____mHB____zD = 1 ;
 __gIB____mHB____0D__z = __gIB____mHB__self__pos + __gIB____mHB____zD ; 
 __gIB____mHB____0D____end :
 __gIB____mHB__self__pos = __gIB____mHB____0D__z ;
 __gIB____mHB____1D__z = __gIB____mHB__self__pos <= __gIB____eHB__if__r ; 
 __gIB____mHB____1D____end :
 __gIB____kHB__pos = __gIB____mHB__self__pos ;
 if(! __gIB____mHB____1D__z )goto __gIB____lHB__while ;
 __gIB____oHB = __gIB____mHB__value ;
 if(! __gIB____oHB )goto __gIB____nHB__fi ;
 __gIB____pHB = " " ;
 printf ( "%s" , __gIB____pHB ); 
 __gIB____qHB____end :
 __gIB____nHB__fi :
 __gIB____sHB____DCB__z = __gIB____mHB__value >= __fIB__size ; 
 __gIB____sHB____DCB____end :
 if(! __gIB____sHB____DCB__z )goto __gIB____sHB____CCB__fi ;
 __gIB____sHB____ECB = "Vec out of bounds" ;
 goto __gIB____sHB____FCB____oD ;
 __builtin_unreachable();
 __gIB____sHB____CCB__fi :
 __gIB____sHB__value =(( f64 *) __fIB____LFB__contents )[ __gIB____mHB__value ]; 
 __gIB____sHB____end :
 printf ( "%.6f" , __gIB____sHB__value ); 
 __gIB____tHB____end :
 goto __gIB____lHB__loop ;
 __gIB____lHB__while :
 __gIB____wHB__z =( __gIB____eHB__if__r != __fIB__size ); 
 __gIB____wHB____end :
 if(! __gIB____wHB__z )goto __gIB____vHB__fi ;
 __gIB____xHB = " ..." ;
 printf ( "%s" , __gIB____xHB ); 
 __gIB____yHB____end :
 __gIB____vHB__fi :
 __gIB____0HB = "]" ;
 printf ( "%s\n" , __gIB____0HB ); 
 __gIB____1HB____end :
 __end :
goto __return;

// ERROR HANDLING
__gIB____sHB____FCB____oD :
 printf ( "%s\n" , __gIB____sHB____ECB ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__fIB____IFB____NT____oD :
 printf ( "%s\n" , __fIB____IFB____MT ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__fIB____FFB____oD :
 printf ( "%s\n" , __fIB____EFB ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__eIB____DIB____JCB____oD :
 printf ( "%s\n" , __eIB____DIB____ICB ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__bIB____DIB____JCB____oD :
 printf ( "%s\n" , __bIB____DIB____ICB ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__eIB____AIB____49____NT____oD :
 printf ( "%s\n" , __eIB____AIB____49____MT ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__bIB____AIB____49____NT____oD :
 printf ( "%s\n" , __bIB____AIB____49____MT ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__XIB____QW____YI____2F____oD :
 printf ( "%s\n" , __XIB____QW____YI____1F ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__XIB____QW____YI____wF____oD :
 printf ( "%s\n" , __XIB____QW____YI____vF ); 
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
__TRANSIENT( __XIB__contents__mem )
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}



int main() {
struct main__871__state __main_args={0};
__smolambda_initialize_service_tasks(main__871, &__main_args);
return __main_args.err;
}

