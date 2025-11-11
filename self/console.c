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
#define __DYNAMIC__ERROR 5
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

#include<stdlib.h>

#include "std/oscommon.h"

#include<stdio.h>

struct main__380__state{errcode err;};
__externc void main__380(void *__void__state);
struct read_str__379__state{errcode err;nominal *__0jC____ret;ptr *contents____ret;u64 *length____ret;char *first____ret;ptr *memory____ret;};
__externc void read_str__379(void *__void__state);

void read_str__379(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1756;
struct read_str__379__state *__state=(struct read_str__379__state*)__void__state;
ptr contents = 0;
u64 length = 0;
char first = 0;
ptr memory = 0;
bool __0k4B=0;
i64 __0j4B=0;
u64 __0i4B=0;
errcode err=0;
ptr __0OyB__memory=0;
bool __0b4B=0;
ptr __0txB__dynamic=0;
i64 __0e4B=0;
u64 __0Z4B=0;
u64 memory_characters__dynamic____buffer_alignment=0;
i64 __0a4B=0;
u64 memory_characters__dynamic____buffer_size=0;
i64 __0T4B=0;
cstr __0m3B=0;
bool __0W4B=0;
u64 __0U4B=0;
bool __0f4B=0;
u64 __0d4B=0;
u64 __0L4B=0;
ptr __0O4B=0;
cstr __0J4B=0;
i64 __0c3B=0;
u64 __0M4B=0;
i64 __0V4B=0;
bool __0G4B=0;
u64 __0P4B=0;
bool __0C4B=0;
u64 __0R3B=0;
u64 __0N4B=0;
bool __0Q4B=0;
u64 __083B=0;
u64 size=0;
bool __033B=0;
char __063B=0;
bool __0F4B=0;
u64 __093B=0;
u64 __073B=0;
u64 __0A4B=0;
ptr __0sxB__mem=0;
bool running=0;
u64 __0v2B=0;
i64 __0u2B=0;
bool __0t2B=0;
char __0p2B=0;
ptr memory_characters__dynamic____buffer_contents=0;
ptr __0OyB__contents=0;
u64 __0o2B=0;
u64 __0n2B=0;
u64 __0k2B=0;
i64 __0j2B=0;
bool __0i2B=0;
ptr mem__underlying=0;
u64 __0h2B=0;
bool __0g2B=0;
u64 __0d2B=0;
bool __0c2B=0;
u64 __0Y2B=0;
cstr __0W2B=0;
bool __0U2B=0;
cstr __0R2B=0;
char __0Q2B=0;
ptr __0P2B=0;
cstr __0N2B=0;
bool __0L2B=0;
cstr __0I2B=0;
char __0G2B=0;
ptr __0F2B=0;
ptr __0txB__surface=0;

// IMPLEMENTATION
__083B = 4 ;
 __093B = 1024 ;
 __0A4B = __093B * __083B ; 
 __0B4B :
 __073B = 0 ;
 __0C4B =( __0A4B == __073B ); 
 __0D4B :
 if(! __0C4B )goto __043B ;
 __0m3B = "Cannot allocate zero size" ;
 [[unlikely]] goto __0E4B ;
 __builtin_unreachable();
 __043B :
 __0sxB__mem = __runtime_alloc ( __0A4B ); 
 __0F4B = __0sxB__mem ;
 __0G4B =(! __0F4B ); 
 __0H4B :
 if(! __0G4B )goto __0I4B ;
 __0J4B = "Failed a Heap allocation" ;
 [[unlikely]] goto __0K4B ;
 __builtin_unreachable();
 __0I4B :
 mem__underlying = __0sxB__mem ;
 __0txB__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 ((u64*) __0txB__dynamic )[0] = (u64)(u64*) __0sxB__mem ;
 ((u64*) __0txB__dynamic )[2] = ( __0A4B /(sizeof(u64)*1)) | (1ULL <<63) ;
 __0txB__surface = mem__underlying ;
 __0L4B = 128 ;
 if(! __0txB__dynamic )goto __result__buffer_error ;
 __0M4B = 1 ;
 __0R3B = ((u64*) __0txB__dynamic )[1] ;
 __0N4B = ((u64*) __0txB__dynamic )[2] & ~(1ULL << 63) ;
 if( __0L4B && __0R3B + __0L4B > __0N4B ){ if( ((u64*) __0txB__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __0N4B = __0R3B + __0L4B +1 ;
 if( __0R3B ) { ((u64*) __0txB__dynamic )[0]=(u64)(u64*)__runtime_realloc((u64*)((u64*) __0txB__dynamic )[0],  __0N4B * __0M4B , __0N4B * __0M4B ) ;
 memset((char*)((u64*)((u64*) __0txB__dynamic )[0]) + ( __0N4B * __0M4B ), 0, (( __0N4B  -  __0N4B ) *  __0M4B )); } else ((u64*) __0txB__dynamic )[0]=(u64)(u64*)__runtime_calloc( __0N4B * __0M4B ) , 0 ;
 ((u64*) __0txB__dynamic )[2] = __0N4B ;
 __0O4B = (ptr)(((u64*) __0txB__dynamic )[0]) ;
 if(! __0O4B )goto __result__buffer_error ;
 } else  __0O4B = (ptr)(((u64*) __0txB__dynamic )[0]) ;
 ((u64*) __0txB__dynamic )[1] = __0R3B + __0L4B ;
 __0P4B = 0 ;
 size = __0P4B ;
 __0Q4B = true ;
 running = __0Q4B ;
 __0R4B :
 if(! running )goto __0S4B ;
 __0c3B = __smo_next_key_press (); 
 __0T4B = __0c3B ;
 __0U4B = 10 ;
 __0V4B = __0U4B ;
 __0W4B =( __0T4B == __0V4B ); 
 __0J3B :
 if(! __0W4B )goto __0X4B ;
 __033B = false ;
 running = __033B ;
 goto __0Y4B ;
 __0X4B :
 __0Z4B = 32 ;
 __0a4B = __0Z4B ;
 __0b4B = __0T4B >= __0a4B ; 
 __0c4B :
 if(! __0b4B )goto __0o3B ;
 __0d4B = 126 ;
 __0e4B = __0d4B ;
 __0f4B = __0T4B <= __0e4B ; 
 __0g4B :
 __0o3B :
 if(! __0f4B )goto __0h4B ;
 if(! __0txB__dynamic )goto __result__buffer_error ;
 memory_characters__dynamic____buffer_alignment = 1 ;
 memory_characters__dynamic____buffer_size = ((u64*) __0txB__dynamic )[1] ;
 if( size >= memory_characters__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(& __063B , &((char*)((void**) __0txB__dynamic )[0])[ size * memory_characters__dynamic____buffer_alignment ], sizeof( char )) ;
 __0i4B = 0 ;
 __0j4B = __0i4B ;
 __0k4B = __0T4B < __0j4B ; 
 __0x2B :
 if( __0k4B )goto __0w2B ;
 __0v2B = 255 ;
 __0u2B = __0v2B ;
 __0t2B = __0T4B >= __0u2B ; 
 __0s2B :
 __0w2B :
 if(! __0t2B )goto __0r2B ;
 [[unlikely]] goto __0q2B ;
 __builtin_unreachable();
 __0r2B :
 __0p2B = __0T4B ;
 if(! __0txB__dynamic )goto __result__buffer_error ;
 memory_characters__dynamic____buffer_size = ((u64*) __0txB__dynamic )[1] ;
 memory_characters__dynamic____buffer_alignment = 1 ;
 memory_characters__dynamic____buffer_contents = (ptr)(((u64*) __0txB__dynamic )[0]) ;
 if( size >= memory_characters__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(&((char*) memory_characters__dynamic____buffer_contents )[ size * memory_characters__dynamic____buffer_alignment ], & __0p2B , sizeof( char )) ;
 __0o2B = 1 ;
 __0n2B = size + __0o2B ; 
 __0m2B :
 size = __0n2B ;
 goto __0l2B ;
 __0h4B :
 __0k2B = 127 ;
 __0j2B = __0k2B ;
 __0i2B =( __0T4B == __0j2B ); 
 __053B :
 if(! __0i2B )goto __0y2B ;
 __0h2B = 0 ;
 __0g2B = size > __0h2B ; 
 __0f2B :
 __0y2B :
 if(! __0g2B )goto __0e2B ;
 __0d2B = 1 ;
 __0c2B = __0d2B > size ; 
 __0b2B :
 if(! __0c2B )goto __0a2B ;
 [[unlikely]] goto __0Z2B ;
 __builtin_unreachable();
 __0a2B :
 __0Y2B = size - __0d2B ; 
 __0X2B :
 size = __0Y2B ;
 __0e2B :
 __0l2B :
 __0Y4B :
 __0W2B = "\r" ;
 printf ( "%s" , __0W2B ); 
 __0V2B :
 __0U2B = size > __0A4B ; 
 __0T2B :
 if(! __0U2B )goto __0S2B ;
 __0R2B = "Cannot allocate more than the available memory" ;
 [[unlikely]] goto __062B ;
 __builtin_unreachable();
 __0S2B :
 __0Q2B = __0A4B ?(( char *) __0sxB__mem )[0]:0; 
 __0P2B = __0sxB__mem ;
 printf ( "%.*s" ,( int ) size ,( char *) __0P2B ); 
 __0O2B :
 goto __0R4B ;
 __0S4B :
 __0N2B = "" ;
 printf ( "%s\n" , __0N2B ); 
 __0M2B :
 __0L2B = size > __0A4B ; 
 __0K2B :
 if(! __0L2B )goto __0J2B ;
 __0I2B = "Cannot allocate more than the available memory" ;
 [[unlikely]] goto __0H2B ;
 __builtin_unreachable();
 __0J2B :
 __0G2B = __0A4B ?(( char *) __0sxB__mem )[0]:0; 
 __0F2B = __0sxB__mem ;
 __0OyB__contents = __0F2B ;
 __0OyB__memory = mem__underlying ;
 contents = __0OyB__contents ;
 length = size ;
 first = __0G2B ;
 memory = __0OyB__memory ;
 __0E2B :
goto __return;

// ERROR HANDLING
__062B :
 printf ( "%s\n" , __0R2B ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0E4B :
 printf ( "%s\n" , __0m3B ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0Z2B :
 printf ( "Error: unsigned subtraction yielded a negative\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__result__buffer_error :
printf("Buffer error\n");
__result__error_code=__BUFFER__ERROR;
goto __failsafe;
__0H2B :
 printf ( "%s\n" , __0I2B ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0q2B :
 printf ( "Cannot convert a non-character key input to a characters\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0K4B :
 printf ( "%s\n" , __0J4B ); 
__result__error_code=__USER__ERROR;
goto __failsafe;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:
if ( contents ) __runtime_free ( contents ); contents =0; 
contents=0;

// HOTPATH SKIPS TO HERE
__return:
if( __0txB__dynamic ) __runtime_free( __0txB__dynamic ) ;
 __0txB__dynamic = 0 ;
*__state->contents____ret=contents;
*__state->length____ret=length;
*__state->first____ret=first;
*__state->memory____ret=memory;
__state->err =  __result__error_code;
}


void main__380(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1328;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__380__state *__state=(struct main__380__state*)__void__state;
struct read_str__379__state* __0z0B____state = 0 ;
ptr __0z0B__contents=0;
u64 __0s4B=0;
char __0r4B=0;
ptr __0q4B=0;
nominal __0p4B=0;
ptr __0o4B=0;
errcode __0n4B=0;

// IMPLEMENTATION
__0z0B__contents = 0 ;
 __0s4B = 0 ;
 __0r4B = 0 ;
 __0q4B = 0 ;
 {char mark;if(__service_stack_floor+ 1768 >=(char*)&mark) goto __service_stack_floor_handler;} __0z0B____state = (struct read_str__379__state*)__runtime_calloc(sizeof(struct read_str__379__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0z0B____state ) ;
 __0z0B____state -> __0jC____ret = & __0p4B ;
 __0z0B____state -> contents____ret = & __0z0B__contents ;
 __0z0B____state -> length____ret = & __0s4B ;
 __0z0B____state -> first____ret = & __0r4B ;
 __0z0B____state -> memory____ret = & __0q4B ;
 __0o4B = __smolambda_add_task ( read_str__379 , __0z0B____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __0o4B ) ;
 if( __0n4B ) goto  __result_unhandled_error ;
 printf ( "%.*s\n" ,( int ) __0s4B ,( char *) __0z0B__contents ); 
 __0m4B :
 __0l4B :
goto __return;

// ERROR HANDLING
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__error_code =__UNHANDLED__ERROR;
goto __failsafe ;
__service_stack_floor_handler:
printf("Insufficient stack for safe service call (too much recursion or stack allocation)\n");
__result__error_code=__STACK__ERROR;
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
if ( __0z0B__contents ) __runtime_free ( __0z0B__contents ); __0z0B__contents =0; 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__error_code;
}



int main() {
struct main__380__state __main_args={0};
__smolambda_initialize_service_tasks(main__380, &__main_args);
return __main_args.err;
}

