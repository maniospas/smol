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
#define __DYokMIC__ERROR 5
#define __TRANSIENT(message)
#define __builtin_assume(cond) do { if(!(cond)) __builtin_unreachable(); } while(0)
#ifdef __cplusplus
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <stdbool.h>
#else
#ifndef bool
typedef char bool;
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

struct main__379__state{errcode err;};
__externc void main__379(void *__void__state);

void main__379(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1684;
struct main__379__state *__state=(struct main__379__state*)__void__state;
ptr __sxB__mem=0;
u64 __n2B=0;
ptr memory_characters__dynamic____buffer_contents=0;
ptr __l2B=0;
ptr __k2B=0;
char __j2B=0;
u64 __i2B=0;
cstr __h2B=0;
u64 __72B=0;
bool __g2B=0;
u64 __f2B=0;
u64 __d2B=0;
ptr __c2B=0;
u64 __b2B=0;
u64 __a2B=0;
u64 __Z2B=0;
bool __z2B=0;
u64 __Y2B=0;
bool __A3B=0;
cstr __W2B=0;
char __82B=0;
u64 __62B=0;
i64 __92B=0;
bool __S2B=0;
bool __42B=0;
bool __R2B=0;
i64 __r2B=0;
u64 __22B=0;
cstr __P2B=0;
i64 __32B=0;
bool __M2B=0;
i64 __y2B=0;
u64 __L2B=0;
u64 __K2B=0;
u64 __J2B=0;
u64 __I2B=0;
u64 __H2B=0;
u64 __x2B=0;
bool __s2B=0;
bool __v2B=0;
i64 __q2B=0;
ptr __91B=0;
i64 __y1B=0;
ptr __txB__surface=0;
u64 size=0;
ptr __txB__dynamic=0;
u64 memory_characters__dynamic____buffer_size=0;
ptr input__contents=0;
u64 memory_characters__dynamic____buffer_alignment=0;
char input__first=0;
u64 input__length=0;
ptr input__memory=0;
i64 __M1B=0;
bool __L1B=0;
bool running=0;
u64 __H1B=0;
u64 __G1B=0;
i64 __D1B=0;
bool __C1B=0;
ptr memory__underlying=0;
u64 __A1B=0;
bool __90B=0;
u64 __60B=0;
bool __50B=0;
bool __00B=0;
cstr __x0B=0;
char __v0B=0;
ptr __u0B=0;
cstr __t0B=0;

// IMPLEMENTATION
__I2B = 4 ;
 __J2B = 1024 ;
 __K2B = __J2B * __I2B ; 
 __h1B :
 __L2B = 0 ;
 __M2B =( __K2B == __L2B ); 
 __N2B :
 if(! __M2B )goto __O2B ;
 __P2B = "Cannot allocate zero size" ;
 [[unlikely]] goto __Q2B ;
 __builtin_unreachable();
 __O2B :
 __sxB__mem = __runtime_alloc ( __K2B ); 
 __R2B = __sxB__mem ;
 __S2B =(! __R2B ); 
 __T2B :
 if(! __S2B )goto __V2B ;
 __W2B = "Failed a Heap allocation" ;
 [[unlikely]] goto __X2B ;
 __builtin_unreachable();
 __V2B :
 memory__underlying = __sxB__mem ;
 __txB__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 ((u64*) __txB__dynamic )[0] = (u64)(u64*) __sxB__mem ;
 ((u64*) __txB__dynamic )[2] = ( __K2B /(sizeof(u64)*1)) | (1ULL <<63) ;
 __txB__surface = memory__underlying ;
 __Y2B = 128 ;
 if(! __txB__dynamic )goto __result__buffer_error ;
 __Z2B = 1 ;
 __a2B = ((u64*) __txB__dynamic )[1] ;
 __b2B = ((u64*) __txB__dynamic )[2] & ~(1ULL << 63) ;
 if( __Y2B && __a2B + __Y2B > __b2B ){ if( ((u64*) __txB__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __b2B = __a2B + __Y2B +1 ;
 if( __a2B ) { ((u64*) __txB__dynamic )[0]=(u64)(u64*)__runtime_realloc((u64*)((u64*) __txB__dynamic )[0],  __b2B * __Z2B , __b2B * __Z2B ) ;
 memset((char*)((u64*)((u64*) __txB__dynamic )[0]) + ( __b2B * __Z2B ), 0, (( __b2B  -  __b2B ) *  __Z2B )); } else ((u64*) __txB__dynamic )[0]=(u64)(u64*)__runtime_calloc( __b2B * __Z2B ) , 0 ;
 ((u64*) __txB__dynamic )[2] = __b2B ;
 __c2B = (ptr)(((u64*) __txB__dynamic )[0]) ;
 if(! __c2B )goto __result__buffer_error ;
 } else  __c2B = (ptr)(((u64*) __txB__dynamic )[0]) ;
 ((u64*) __txB__dynamic )[1] = __a2B + __Y2B ;
 __d2B = 0 ;
 size = __d2B ;
 __g2B = true ;
 running = __g2B ;
 __h2B = "" ;
 __i2B = strlen ( __h2B ); __91B =( ptr ) __h2B ; __j2B = __h2B [0]; __k2B =0; 
 __l2B = __91B ;
 input__contents = __l2B ;
 input__length = __i2B ;
 input__first = __j2B ;
 input__memory = __k2B ;
 __o2B :
 if(! running )goto __p2B ;
 __q2B = __smo_next_key_press (); 
 __r2B = __q2B ;
 __n2B = 10 ;
 __y1B = __n2B ;
 __s2B =( __r2B == __y1B ); 
 __t2B :
 if(! __s2B )goto __u2B ;
 __v2B = false ;
 running = __v2B ;
 goto __w2B ;
 __u2B :
 __x2B = 32 ;
 __y2B = __x2B ;
 __z2B = __r2B >= __y2B ; 
 __02B :
 if(! __z2B )goto __12B ;
 __22B = 126 ;
 __32B = __22B ;
 __42B = __r2B <= __32B ; 
 __52B :
 __12B :
 if(! __42B )goto __m2B ;
 if(! __txB__dynamic )goto __result__buffer_error ;
 memory_characters__dynamic____buffer_alignment = 1 ;
 memory_characters__dynamic____buffer_size = ((u64*) __txB__dynamic )[1] ;
 if( size >= memory_characters__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(& __82B , &((char*)((void**) __txB__dynamic )[0])[ size * memory_characters__dynamic____buffer_alignment ], sizeof( char )) ;
 __f2B = 0 ;
 __92B = __f2B ;
 __A3B = __r2B < __92B ; 
 __B3B :
 if( __A3B )goto __C3B ;
 __72B = 255 ;
 __M1B = __72B ;
 __L1B = __r2B >= __M1B ; 
 __K1B :
 __C3B :
 if(! __L1B )goto __J1B ;
 [[unlikely]] goto __I1B ;
 __builtin_unreachable();
 __J1B :
 if(! __txB__dynamic )goto __result__buffer_error ;
 memory_characters__dynamic____buffer_size = ((u64*) __txB__dynamic )[1] ;
 memory_characters__dynamic____buffer_alignment = 1 ;
 memory_characters__dynamic____buffer_contents = (ptr)(((u64*) __txB__dynamic )[0]) ;
 if( size >= memory_characters__dynamic____buffer_size )goto __result__buffer_error ;
 __H1B = 1 ;
 __G1B = size + __H1B ; 
 __F1B :
 size = __G1B ;
 goto __E1B ;
 __m2B :
 __62B = 127 ;
 __D1B = __62B ;
 __C1B =( __r2B == __D1B ); 
 __e2B :
 if(! __C1B )goto __B1B ;
 __A1B = 0 ;
 __90B = size > __A1B ; 
 __80B :
 __B1B :
 if(! __90B )goto __70B ;
 __60B = 1 ;
 __50B = __60B > size ; 
 __40B :
 if(! __50B )goto __30B ;
 [[unlikely]] goto __20B ;
 __builtin_unreachable();
 __30B :
 __H2B = size - __60B ; 
 __10B :
 size = __H2B ;
 __70B :
 __E1B :
 __w2B :
 __00B = size >= __K2B ; 
 __z0B :
 if(! __00B )goto __y0B ;
 __x0B = "Cannot allocate more than the available memory" ;
 [[unlikely]] goto __w0B ;
 __builtin_unreachable();
 __y0B :
 __v0B = __K2B ?(( char *) __sxB__mem )[0]:0; 
 __u0B = __sxB__mem ;
 input__contents = __u0B ;
 input__length = size ;
 input__first = __v0B ;
 input__memory = memory__underlying ;
 __t0B = "\r" ;
 printf ( "%s" , __t0B ); 
 __s0B :
 printf ( "%.*s" ,( int ) input__length ,( char *) input__contents ); 
 __r0B :
 fflush ( stdout ); 
 __q0B :
 goto __o2B ;
 __p2B :
 __p0B :
goto __return;

// ERROR HANDLING
__w0B :
 printf ( "%s\n" , __x0B ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__result__buffer_error :
printf("Buffer error\n");
__result__error_code=__BUFFER__ERROR;
goto __failsafe;
__20B :
 printf ( "Error: unsigned subtraction yielded a negative\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__I1B :
 printf ( "Cannot convert a non-character key input to a characters\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__Q2B :
 printf ( "%s\n" , __P2B ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__X2B :
 printf ( "%s\n" , __W2B ); 
__result__error_code=__USER__ERROR;
goto __failsafe;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
if ( __txB__dynamic ) __runtime_free ( __txB__dynamic ); __txB__dynamic =0; 
 if( __txB__dynamic ) __runtime_free( __txB__dynamic ) ;
 __txB__dynamic = 0 ;
__state->err =  __result__error_code;
}



int main() {
struct main__379__state __main_args={0};
__smolambda_initialize_service_tasks(main__379, &__main_args);
return __main_args.err;
}

