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

#include<stdio.h>

struct main__882__state{errcode err;};
__externc void main__882(void *__void__state);

void main__882(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 2360;
struct main__882__state *__state=(struct main__882__state*)__void__state;
cstr __x0G=0;
ptr __v0G=0;
u64 __u0G=0;
u64 __t0G=0;
u64 __s0G=0;
ptr __r0G=0;
u64 __q0G=0;
u64 __p0G=0;
f64 __n0G=0;
ptr __m0G=0;
u64 __l0G=0;
u64 __k0G=0;
u64 __j0G=0;
u64 __i0G=0;
f64 __h0G=0;
nominal __g0G=0;
nominal shapes____anG=0;
ptr __e0G=0;
u64 __d0G=0;
u64 __c0G=0;
u64 __b0G=0;
ptr shapes__squares__surface=0;
u64 __Z0G=0;
u64 __Y0G=0;
u64 __X0G=0;
tag __W0G=0;
f64 __V0G=0;
ptr __U0G=0;
u64 __T0G=0;
u64 __S0G=0;
u64 __R0G=0;
f64 __Q0G=0;
nominal __P0G=0;
u64 __O0G=0;
u64 __N0G=0;
u64 __M0G=0;
ptr __L0G=0;
u64 __K0G=0;
u64 __J0G=0;
tag __I0G=0;
ptr __a0G=0;
ptr shapes__squares__dynamic=0;
f64 __H0G=0;
ptr __G0G=0;
u64 __F0G=0;
u64 __E0G=0;
u64 __D0G=0;
u64 __C0G=0;
u64 __B0G=0;
f64 __A0G=0;
nominal __9zG=0;
u64 __8zG=0;
ptr __6zG=0;
u64 __5zG=0;
u64 __4zG=0;
u64 __2zG=0;
u64 __1zG=0;
u64 __0zG=0;
tag __zzG=0;
ptr __yzG=0;
u64 __xzG=0;
u64 __wzG=0;
u64 __vzG=0;
ptr __uzG=0;
nominal __szG=0;
ptr __pzG=0;
u64 __rzG=0;
ptr __8pG__types__dynamic=0;
u64 __YzG=0;
f64 __ayG=0;
u64 __PyG=0;
ptr shapes__types__surface=0;
ptr shapes__types__dynamic=0;
ptr shapes__circles__dynamic=0;
ptr shapes__circles__surface=0;
ptr __qzG=0;
ptr shapes__lookups__surface=0;
ptr __3zG=0;
ptr shapes__lookups__dynamic=0;
ptr __8pG__circles__dynamic=0;
u64 i=0;
tag __o0G=0;
ptr __8pG__squares__dynamic=0;
f64 __CxG=0;
u64 __AxG=0;
u64 __9wG=0;
u64 __8wG=0;
u64 __7wG=0;
u64 __6wG=0;
u64 __5wG=0;
u64 __3wG=0;
u64 __2wG=0;
u64 __1wG=0;
u64 __0wG=0;
bool __ywG=0;
f64 __vwG=0;
u64 __uwG=0;
u64 __twG=0;
tag __swG=0;
f64 __rwG=0;
tag __qwG=0;
bool __pwG=0;
cstr __mwG=0;
f64 __kwG=0;
u64 __jwG=0;
u64 __iwG=0;
tag __hwG=0;
f64 __gwG=0;
tag __fwG=0;
cstr __cwG=0;
u64 __awG=0;
u64 __ZwG=0;
u64 __YwG=0;
u64 __XwG=0;
u64 __WwG=0;
f64 __VwG=0;
f64 __UwG=0;
f64 __TwG=0;
f64 __RwG=0;
ptr __8pG__lookups__dynamic=0;
cstr __NwG=0;
f64 __LwG=0;
bool __izG=0;
u64 __KwG=0;
u64 __hzG=0;
u64 __JwG=0;
tag __IwG=0;
f64 __HwG=0;
tag __GwG=0;
bool __FwG=0;
cstr __CwG=0;
ptr __ozG=0;
u64 __AwG=0;
ptr __nzG=0;
u64 __9vG=0;
ptr __mzG=0;
u64 __8vG=0;
ptr __lzG=0;
u64 __7vG=0;
ptr __kzG=0;
u64 __6vG=0;
ptr __jzG=0;
f64 __5vG=0;
f64 __4vG=0;
f64 __3vG=0;
f64 __1vG=0;

// IMPLEMENTATION
__jzG = __runtime_calloc(3*sizeof(u64)) ;
 __kzG = 0 ;
 __8pG__squares__dynamic = __jzG ;
 __lzG = __runtime_calloc(3*sizeof(u64)) ;
 __mzG = 0 ;
 __8pG__circles__dynamic = __lzG ;
 __nzG = __runtime_calloc(3*sizeof(u64)) ;
 __ozG = 0 ;
 __8pG__types__dynamic = __nzG ;
 __pzG = __runtime_calloc(3*sizeof(u64)) ;
 __qzG = 0 ;
 __8pG__lookups__dynamic = __pzG ;
 shapes__squares__dynamic = __8pG__squares__dynamic ;
 shapes__squares__surface = __kzG ;
 shapes__circles__dynamic = __8pG__circles__dynamic ;
 shapes__circles__surface = __mzG ;
 shapes__types__dynamic = __8pG__types__dynamic ;
 shapes__types__surface = __ozG ;
 shapes__lookups__dynamic = __8pG__lookups__dynamic ;
 shapes__lookups__surface = __qzG ;
 __CxG = 1.0 ;
 __vzG = shapes__squares__dynamic ? ((u64*) shapes__squares__dynamic )[1]:0 ;
 if(! shapes__lookups__dynamic )goto __result__buffer_error ;
 __wzG = 1 ;
 __xzG = ((u64*) shapes__lookups__dynamic )[1] ;
 __YzG = ((u64*) shapes__lookups__dynamic )[2] & ~(1ULL << 63) ;
 if( __xzG >= __YzG ){ if( ((u64*) shapes__lookups__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __YzG = __YzG +( __YzG >>2)+1; if( __xzG ) ((void**) shapes__lookups__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__lookups__dynamic )[0],  __YzG * __wzG *sizeof(u64),  __YzG * __wzG *sizeof(u64)); else ((void**) shapes__lookups__dynamic )[0] = __runtime_alloc( __YzG * __wzG *sizeof(u64)); ((u64*) shapes__lookups__dynamic )[2] = __YzG ;
 __yzG = (ptr)((void**) shapes__lookups__dynamic )[0] ;
 if(! __yzG )goto __result__buffer_error ;
 } else  __yzG = (ptr)(((u64*) shapes__lookups__dynamic )[0]) ;
 ((u64*) shapes__lookups__dynamic )[1] = __xzG +1 ;
 memcpy(&((u64*) __yzG )[ __xzG * __wzG ], & __vzG , sizeof(u64)); __ayG = __CxG ;
 __zzG = 2 ;
 if(! shapes__types__dynamic )goto __result__buffer_error ;
 __0zG = 1 ;
 __1zG = ((u64*) shapes__types__dynamic )[1] ;
 __2zG = ((u64*) shapes__types__dynamic )[2] & ~(1ULL << 63) ;
 if( __1zG >= __2zG ){ if( ((u64*) shapes__types__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __2zG = __2zG +( __2zG >>2)+1; if( __1zG ) ((void**) shapes__types__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__types__dynamic )[0],  __2zG * __0zG *sizeof(u64),  __2zG * __0zG *sizeof(u64)); else ((void**) shapes__types__dynamic )[0] = __runtime_alloc( __2zG * __0zG *sizeof(u64)); ((u64*) shapes__types__dynamic )[2] = __2zG ;
 __3zG = (ptr)((void**) shapes__types__dynamic )[0] ;
 if(! __3zG )goto __result__buffer_error ;
 } else  __3zG = (ptr)(((u64*) shapes__types__dynamic )[0]) ;
 ((u64*) shapes__types__dynamic )[1] = __1zG +1 ;
 memcpy(&((u64*) __3zG )[ __1zG * __0zG ], & __zzG , sizeof(u64)); if(! shapes__squares__dynamic )goto __result__buffer_error ;
 __4zG = 1 ;
 __5zG = ((u64*) shapes__squares__dynamic )[1] ;
 __rzG = ((u64*) shapes__squares__dynamic )[2] & ~(1ULL << 63) ;
 if( __5zG >= __rzG ){ if( ((u64*) shapes__squares__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __rzG = __rzG +( __rzG >>2)+1; if( __5zG ) ((void**) shapes__squares__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__squares__dynamic )[0],  __rzG * __4zG *sizeof(u64),  __rzG * __4zG *sizeof(u64)); else ((void**) shapes__squares__dynamic )[0] = __runtime_alloc( __rzG * __4zG *sizeof(u64)); ((u64*) shapes__squares__dynamic )[2] = __rzG ;
 __6zG = (ptr)((void**) shapes__squares__dynamic )[0] ;
 if(! __6zG )goto __result__buffer_error ;
 } else  __6zG = (ptr)(((u64*) shapes__squares__dynamic )[0]) ;
 ((u64*) shapes__squares__dynamic )[1] = __5zG +1 ;
 memcpy(&((u64*) __6zG )[ __5zG * __4zG +0], & __CxG , sizeof(f64)); __7zG :
 shapes____anG = __9zG ;
 __A0G = 1.0 ;
 __B0G = shapes__squares__dynamic ? ((u64*) shapes__squares__dynamic )[1]:0 ;
 if(! shapes__lookups__dynamic )goto __result__buffer_error ;
 __C0G = 1 ;
 __E0G = ((u64*) shapes__lookups__dynamic )[1] ;
 __F0G = ((u64*) shapes__lookups__dynamic )[2] & ~(1ULL << 63) ;
 if( __E0G >= __F0G ){ if( ((u64*) shapes__lookups__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __F0G = __F0G +( __F0G >>2)+1; if( __E0G ) ((void**) shapes__lookups__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__lookups__dynamic )[0],  __F0G * __C0G *sizeof(u64),  __F0G * __C0G *sizeof(u64)); else ((void**) shapes__lookups__dynamic )[0] = __runtime_alloc( __F0G * __C0G *sizeof(u64)); ((u64*) shapes__lookups__dynamic )[2] = __F0G ;
 __G0G = (ptr)((void**) shapes__lookups__dynamic )[0] ;
 if(! __G0G )goto __result__buffer_error ;
 } else  __G0G = (ptr)(((u64*) shapes__lookups__dynamic )[0]) ;
 ((u64*) shapes__lookups__dynamic )[1] = __E0G +1 ;
 memcpy(&((u64*) __G0G )[ __E0G * __C0G ], & __B0G , sizeof(u64)); __H0G = __A0G ;
 __I0G = 1 ;
 if(! shapes__types__dynamic )goto __result__buffer_error ;
 __hzG = 1 ;
 __J0G = ((u64*) shapes__types__dynamic )[1] ;
 __K0G = ((u64*) shapes__types__dynamic )[2] & ~(1ULL << 63) ;
 if( __J0G >= __K0G ){ if( ((u64*) shapes__types__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __K0G = __K0G +( __K0G >>2)+1; if( __J0G ) ((void**) shapes__types__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__types__dynamic )[0],  __K0G * __hzG *sizeof(u64),  __K0G * __hzG *sizeof(u64)); else ((void**) shapes__types__dynamic )[0] = __runtime_alloc( __K0G * __hzG *sizeof(u64)); ((u64*) shapes__types__dynamic )[2] = __K0G ;
 __L0G = (ptr)((void**) shapes__types__dynamic )[0] ;
 if(! __L0G )goto __result__buffer_error ;
 } else  __L0G = (ptr)(((u64*) shapes__types__dynamic )[0]) ;
 ((u64*) shapes__types__dynamic )[1] = __J0G +1 ;
 memcpy(&((u64*) __L0G )[ __J0G * __hzG ], & __I0G , sizeof(u64)); if(! shapes__circles__dynamic )goto __result__buffer_error ;
 __M0G = 1 ;
 __N0G = ((u64*) shapes__circles__dynamic )[1] ;
 __O0G = ((u64*) shapes__circles__dynamic )[2] & ~(1ULL << 63) ;
 if( __N0G >= __O0G ){ if( ((u64*) shapes__circles__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __O0G = __O0G +( __O0G >>2)+1; if( __N0G ) ((void**) shapes__circles__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__circles__dynamic )[0],  __O0G * __M0G *sizeof(u64),  __O0G * __M0G *sizeof(u64)); else ((void**) shapes__circles__dynamic )[0] = __runtime_alloc( __O0G * __M0G *sizeof(u64)); ((u64*) shapes__circles__dynamic )[2] = __O0G ;
 __uzG = (ptr)((void**) shapes__circles__dynamic )[0] ;
 if(! __uzG )goto __result__buffer_error ;
 } else  __uzG = (ptr)(((u64*) shapes__circles__dynamic )[0]) ;
 ((u64*) shapes__circles__dynamic )[1] = __N0G +1 ;
 memcpy(&((u64*) __uzG )[ __N0G * __M0G +0], & __A0G , sizeof(f64)); __tzG :
 shapes____anG = __P0G ;
 __Q0G = 2.0 ;
 __PyG = shapes__squares__dynamic ? ((u64*) shapes__squares__dynamic )[1]:0 ;
 if(! shapes__lookups__dynamic )goto __result__buffer_error ;
 __R0G = 1 ;
 __S0G = ((u64*) shapes__lookups__dynamic )[1] ;
 __T0G = ((u64*) shapes__lookups__dynamic )[2] & ~(1ULL << 63) ;
 if( __S0G >= __T0G ){ if( ((u64*) shapes__lookups__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __T0G = __T0G +( __T0G >>2)+1; if( __S0G ) ((void**) shapes__lookups__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__lookups__dynamic )[0],  __T0G * __R0G *sizeof(u64),  __T0G * __R0G *sizeof(u64)); else ((void**) shapes__lookups__dynamic )[0] = __runtime_alloc( __T0G * __R0G *sizeof(u64)); ((u64*) shapes__lookups__dynamic )[2] = __T0G ;
 __U0G = (ptr)((void**) shapes__lookups__dynamic )[0] ;
 if(! __U0G )goto __result__buffer_error ;
 } else  __U0G = (ptr)(((u64*) shapes__lookups__dynamic )[0]) ;
 ((u64*) shapes__lookups__dynamic )[1] = __S0G +1 ;
 memcpy(&((u64*) __U0G )[ __S0G * __R0G ], & __PyG , sizeof(u64)); __V0G = __Q0G ;
 __W0G = 1 ;
 if(! shapes__types__dynamic )goto __result__buffer_error ;
 __X0G = 1 ;
 __Y0G = ((u64*) shapes__types__dynamic )[1] ;
 __Z0G = ((u64*) shapes__types__dynamic )[2] & ~(1ULL << 63) ;
 if( __Y0G >= __Z0G ){ if( ((u64*) shapes__types__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __Z0G = __Z0G +( __Z0G >>2)+1; if( __Y0G ) ((void**) shapes__types__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__types__dynamic )[0],  __Z0G * __X0G *sizeof(u64),  __Z0G * __X0G *sizeof(u64)); else ((void**) shapes__types__dynamic )[0] = __runtime_alloc( __Z0G * __X0G *sizeof(u64)); ((u64*) shapes__types__dynamic )[2] = __Z0G ;
 __a0G = (ptr)((void**) shapes__types__dynamic )[0] ;
 if(! __a0G )goto __result__buffer_error ;
 } else  __a0G = (ptr)(((u64*) shapes__types__dynamic )[0]) ;
 ((u64*) shapes__types__dynamic )[1] = __Y0G +1 ;
 memcpy(&((u64*) __a0G )[ __Y0G * __X0G ], & __W0G , sizeof(u64)); if(! shapes__circles__dynamic )goto __result__buffer_error ;
 __b0G = 1 ;
 __c0G = ((u64*) shapes__circles__dynamic )[1] ;
 __d0G = ((u64*) shapes__circles__dynamic )[2] & ~(1ULL << 63) ;
 if( __c0G >= __d0G ){ if( ((u64*) shapes__circles__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __d0G = __d0G +( __d0G >>2)+1; if( __c0G ) ((void**) shapes__circles__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__circles__dynamic )[0],  __d0G * __b0G *sizeof(u64),  __d0G * __b0G *sizeof(u64)); else ((void**) shapes__circles__dynamic )[0] = __runtime_alloc( __d0G * __b0G *sizeof(u64)); ((u64*) shapes__circles__dynamic )[2] = __d0G ;
 __e0G = (ptr)((void**) shapes__circles__dynamic )[0] ;
 if(! __e0G )goto __result__buffer_error ;
 } else  __e0G = (ptr)(((u64*) shapes__circles__dynamic )[0]) ;
 ((u64*) shapes__circles__dynamic )[1] = __c0G +1 ;
 memcpy(&((u64*) __e0G )[ __c0G * __b0G +0], & __Q0G , sizeof(f64)); __f0G :
 shapes____anG = __g0G ;
 __h0G = 5.0 ;
 __i0G = shapes__squares__dynamic ? ((u64*) shapes__squares__dynamic )[1]:0 ;
 if(! shapes__lookups__dynamic )goto __result__buffer_error ;
 __j0G = 1 ;
 __k0G = ((u64*) shapes__lookups__dynamic )[1] ;
 __l0G = ((u64*) shapes__lookups__dynamic )[2] & ~(1ULL << 63) ;
 if( __k0G >= __l0G ){ if( ((u64*) shapes__lookups__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __l0G = __l0G +( __l0G >>2)+1; if( __k0G ) ((void**) shapes__lookups__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__lookups__dynamic )[0],  __l0G * __j0G *sizeof(u64),  __l0G * __j0G *sizeof(u64)); else ((void**) shapes__lookups__dynamic )[0] = __runtime_alloc( __l0G * __j0G *sizeof(u64)); ((u64*) shapes__lookups__dynamic )[2] = __l0G ;
 __m0G = (ptr)((void**) shapes__lookups__dynamic )[0] ;
 if(! __m0G )goto __result__buffer_error ;
 } else  __m0G = (ptr)(((u64*) shapes__lookups__dynamic )[0]) ;
 ((u64*) shapes__lookups__dynamic )[1] = __k0G +1 ;
 memcpy(&((u64*) __m0G )[ __k0G * __j0G ], & __i0G , sizeof(u64)); __n0G = __h0G ;
 __o0G = 2 ;
 if(! shapes__types__dynamic )goto __result__buffer_error ;
 __8zG = 1 ;
 __p0G = ((u64*) shapes__types__dynamic )[1] ;
 __q0G = ((u64*) shapes__types__dynamic )[2] & ~(1ULL << 63) ;
 if( __p0G >= __q0G ){ if( ((u64*) shapes__types__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __q0G = __q0G +( __q0G >>2)+1; if( __p0G ) ((void**) shapes__types__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__types__dynamic )[0],  __q0G * __8zG *sizeof(u64),  __q0G * __8zG *sizeof(u64)); else ((void**) shapes__types__dynamic )[0] = __runtime_alloc( __q0G * __8zG *sizeof(u64)); ((u64*) shapes__types__dynamic )[2] = __q0G ;
 __r0G = (ptr)((void**) shapes__types__dynamic )[0] ;
 if(! __r0G )goto __result__buffer_error ;
 } else  __r0G = (ptr)(((u64*) shapes__types__dynamic )[0]) ;
 ((u64*) shapes__types__dynamic )[1] = __p0G +1 ;
 memcpy(&((u64*) __r0G )[ __p0G * __8zG ], & __o0G , sizeof(u64)); if(! shapes__squares__dynamic )goto __result__buffer_error ;
 __s0G = 1 ;
 __t0G = ((u64*) shapes__squares__dynamic )[1] ;
 __u0G = ((u64*) shapes__squares__dynamic )[2] & ~(1ULL << 63) ;
 if( __t0G >= __u0G ){ if( ((u64*) shapes__squares__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __u0G = __u0G +( __u0G >>2)+1; if( __t0G ) ((void**) shapes__squares__dynamic )[0] = __runtime_realloc((u64*)((void**) shapes__squares__dynamic )[0],  __u0G * __s0G *sizeof(u64),  __u0G * __s0G *sizeof(u64)); else ((void**) shapes__squares__dynamic )[0] = __runtime_alloc( __u0G * __s0G *sizeof(u64)); ((u64*) shapes__squares__dynamic )[2] = __u0G ;
 __v0G = (ptr)((void**) shapes__squares__dynamic )[0] ;
 if(! __v0G )goto __result__buffer_error ;
 } else  __v0G = (ptr)(((u64*) shapes__squares__dynamic )[0]) ;
 ((u64*) shapes__squares__dynamic )[1] = __t0G +1 ;
 memcpy(&((u64*) __v0G )[ __t0G * __s0G +0], & __h0G , sizeof(f64)); __w0G :
 shapes____anG = __szG ;
 __x0G = "=== Volumes ===" ;
 printf ( "%s\n" , __x0G ); 
 __y0G :
 __D0G = shapes__types__dynamic ? ((u64*) shapes__types__dynamic )[1]:0 ;
 __AxG = __D0G ;
 __9wG = 0 ;
 __8wG = 1 ;
 __7wG = __9wG ;
 __6wG = __8wG ;
 __5wG = __9wG ;
 __4wG :
 __3wG = __5wG ;
 __2wG = i ;
 __2wG = __3wG ;
 __1wG = 1 ;
 __0wG = __3wG + __1wG ; 
 __zwG :
 __3wG = __0wG ;
 __ywG = __3wG <= __AxG ; 
 __xwG :
 __5wG = __3wG ;
 if(! __ywG )goto __wwG ;
 __vwG = 0 ;
 if(! shapes__types__dynamic )goto __result__buffer_error ;
 __uwG = 1 ;
 __twG = ((u64*) shapes__types__dynamic )[1] ;
 if( __2wG >= __twG )goto __result__buffer_error ;
 memcpy(& __swG , &((u64*)((u64*) shapes__types__dynamic )[0])[ __2wG * __uwG +0], sizeof( tag )) ;
 __rwG = 0 ;
 __qwG = 2 ;
 __pwG =( __swG == __qwG ); 
 __owG :
 if(! __pwG )goto __nwG ;
 __mwG = "Square: " ;
 printf ( "%s" , __mwG ); 
 __lwG :
 __kwG = 0 ;
 if(! shapes__types__dynamic )goto __result__buffer_error ;
 __jwG = 1 ;
 __iwG = ((u64*) shapes__types__dynamic )[1] ;
 if( __2wG >= __iwG )goto __result__buffer_error ;
 memcpy(& __hwG , &((u64*)((u64*) shapes__types__dynamic )[0])[ __2wG * __jwG +0], sizeof( tag )) ;
 __gwG = 0 ;
 __fwG = 2 ;
 __izG =( __hwG != __fwG ); 
 __ewG :
 if(! __izG )goto __dwG ;
 __cwG = "Trying to access a different shape" ;
 goto __bwG ;
 __builtin_unreachable();
 __dwG :
 if(! shapes__lookups__dynamic )goto __result__buffer_error ;
 __awG = 1 ;
 __ZwG = ((u64*) shapes__lookups__dynamic )[1] ;
 if( __2wG >= __ZwG )goto __result__buffer_error ;
 memcpy(& __YwG , &((u64*)((u64*) shapes__lookups__dynamic )[0])[ __2wG * __awG +0], sizeof( u64 )) ;
 if(! shapes__squares__dynamic )goto __result__buffer_error ;
 __XwG = 1 ;
 __WwG = ((u64*) shapes__squares__dynamic )[1] ;
 if( __YwG >= __WwG )goto __result__buffer_error ;
 memcpy(& __VwG , &((u64*)((void**) shapes__squares__dynamic )[0])[ __YwG * __XwG +0], sizeof( f64 )) ;
 __UwG = 1.0 ;
 __TwG = __VwG * __VwG ; 
 __SwG :
 __RwG = __TwG * __UwG ; 
 __QwG :
 printf ( "%.6f\n" , __RwG ); 
 __PwG :
 goto __OwG ;
 __nwG :
 __NwG = "Circle: " ;
 printf ( "%s" , __NwG ); 
 __MwG :
 __LwG = 0 ;
 if(! shapes__types__dynamic )goto __result__buffer_error ;
 __KwG = 1 ;
 __JwG = ((u64*) shapes__types__dynamic )[1] ;
 if( __2wG >= __JwG )goto __result__buffer_error ;
 memcpy(& __IwG , &((u64*)((u64*) shapes__types__dynamic )[0])[ __2wG * __KwG +0], sizeof( tag )) ;
 __HwG = 0 ;
 __GwG = 1 ;
 __FwG =( __IwG != __GwG ); 
 __EwG :
 if(! __FwG )goto __DwG ;
 __CwG = "Trying to access a different shape" ;
 goto __BwG ;
 __builtin_unreachable();
 __DwG :
 if(! shapes__lookups__dynamic )goto __result__buffer_error ;
 __AwG = 1 ;
 __9vG = ((u64*) shapes__lookups__dynamic )[1] ;
 if( __2wG >= __9vG )goto __result__buffer_error ;
 memcpy(& __8vG , &((u64*)((u64*) shapes__lookups__dynamic )[0])[ __2wG * __AwG +0], sizeof( u64 )) ;
 if(! shapes__squares__dynamic )goto __result__buffer_error ;
 __7vG = 1 ;
 __6vG = ((u64*) shapes__squares__dynamic )[1] ;
 if( __8vG >= __6vG )goto __result__buffer_error ;
 memcpy(& __5vG , &((u64*)((void**) shapes__squares__dynamic )[0])[ __8vG * __7vG +0], sizeof( f64 )) ;
 __4vG = 1.0 ;
 __3vG = __5vG * __5vG ; 
 __2vG :
 __1vG = __3vG * __4vG ; 
 __0vG :
 printf ( "%.6f\n" , __1vG ); 
 __zvG :
 __OwG :
 goto __4wG ;
 __wwG :
 __yvG :
goto __return;

// ERROR HANDLING
__BwG :
 printf ( "%s\n" , __CwG ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__bwG :
 printf ( "%s\n" , __cwG ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__result__buffer_error :
printf("Buffer error\n");
__result__error_code=__BUFFER__ERROR;
goto __failsafe;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
if( __8pG__lookups__dynamic ){if((u64*)((u64*) __8pG__lookups__dynamic )[2]) __runtime_free((u64*)((u64*) __8pG__lookups__dynamic )[0]) ;
 __runtime_free( __8pG__lookups__dynamic ) ;
 __8pG__lookups__dynamic = 0 ;
 }if( __8pG__types__dynamic ){if((u64*)((u64*) __8pG__types__dynamic )[2]) __runtime_free((u64*)((u64*) __8pG__types__dynamic )[0]) ;
 __runtime_free( __8pG__types__dynamic ) ;
 __8pG__types__dynamic = 0 ;
 }if( __8pG__circles__dynamic ){if((u64*)((u64*) __8pG__circles__dynamic )[2]) __runtime_free((u64*)((u64*) __8pG__circles__dynamic )[0]) ;
 __runtime_free( __8pG__circles__dynamic ) ;
 __8pG__circles__dynamic = 0 ;
 }if( __8pG__squares__dynamic ){if((u64*)((u64*) __8pG__squares__dynamic )[2]) __runtime_free((u64*)((u64*) __8pG__squares__dynamic )[0]) ;
 __runtime_free( __8pG__squares__dynamic ) ;
 __8pG__squares__dynamic = 0 ;
 }__state->err =  __result__error_code;
}



int main() {
struct main__882__state __main_args={0};
__smolambda_initialize_service_tasks(main__882, &__main_args);
return __main_args.err;
}

