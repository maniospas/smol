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

#include<stdlib.h>

#include<stdio.h>

#include "std/oscommon.h"

struct main__380__state{errcode err;};
__externc void main__380(void *__void__state);

void main__380(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1716;
struct main__380__state *__state=(struct main__380__state*)__void__state;
u64 __0L6B=0;
bool __0J6B=0;
i64 __0I6B=0;
u64 __0H6B=0;
bool __0E6B=0;
i64 __0D6B=0;
bool __0B6B=0;
bool __085B=0;
i64 __075B=0;
u64 __065B=0;
i64 __055B=0;
bool __025B=0;
bool __015B=0;
u64 __005B=0;
u64 __0z5B=0;
ptr __0y5B=0;
u64 __0x5B=0;
u64 __0w5B=0;
u64 __0v5B=0;
u64 __0u5B=0;
ptr __0t5B=0;
cstr __0r5B=0;
i64 __0q5B=0;
i64 __0U6B=0;
bool __0n5B=0;
bool __0m5B=0;
cstr __0k5B=0;
u64 __0O6B=0;
bool __0h5B=0;
u64 __0g5B=0;
u64 __0M6B=0;
i64 __0P6B=0;
u64 __0e5B=0;
u64 __0d5B=0;
char __0N6B=0;
u64 __0c5B=0;
ptr __0Z5B=0;
bool __0Q6B=0;
u64 __0T6B=0;
bool __0T4B=0;
char __0P4B=0;
ptr __0O4B=0;
u64 __0N4B=0;
u64 __0M4B=0;
ptr __0x0B__contents=0;
u64 __0J4B=0;
i64 __0I4B=0;
bool __0H4B=0;
u64 __0E4B=0;
bool __0D4B=0;
u64 __0A4B=0;
bool __093B=0;
u64 __053B=0;
cstr __033B=0;
bool __013B=0;
cstr __0y3B=0;
char __0w3B=0;
ptr __0v3B=0;
bool __0s3B=0;
u64 __0b4B=0;
cstr __0p3B=0;
char __0n3B=0;
ptr __0m3B=0;

// IMPLEMENTATION
__0c5B = 4 ;
 __0d5B = 1024 ;
 __0e5B = __0d5B * __0c5B ; 
 __0f5B :
 __0g5B = 0 ;
 __0h5B =( __0e5B == __0g5B ); 
 __0i5B :
 if(! __0h5B )goto __0j5B ;
 __0k5B = "Cannot allocate zero size" ;
 [[unlikely]] goto __0l5B ;
 __builtin_unreachable();
 __0j5B :
 __0Z5B = __runtime_alloc ( __0e5B ); 
 __0m5B = __0Z5B ;
 __0n5B =(! __0m5B ); 
 __0o5B :
 if(! __0n5B )goto __0p5B ;
 __0r5B = "Failed a Heap allocation" ;
 [[unlikely]] goto __0s5B ;
 __builtin_unreachable();
 __0p5B :
 __0t5B = __runtime_calloc(3*sizeof(u64)) ;
 ((u64*) __0t5B )[0] = (u64)(u64*) __0Z5B ;
 ((u64*) __0t5B )[2] = ( __0e5B /(sizeof(u64)*1)) | (1ULL <<63) ;
 __0u5B = 128 ;
 if(! __0t5B )goto __result__buffer_error ;
 __0v5B = 1 ;
 __0w5B = ((u64*) __0t5B )[1] ;
 __0x5B = ((u64*) __0t5B )[2] & ~(1ULL << 63) ;
 if( __0u5B && __0w5B + __0u5B > __0x5B ){ if( ((u64*) __0t5B )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __0x5B = __0w5B + __0u5B +1 ;
 if( __0w5B ) { ((u64*) __0t5B )[0]=(u64)(u64*)__runtime_realloc((u64*)((u64*) __0t5B )[0],  __0x5B * __0v5B , __0x5B * __0v5B ) ;
 memset((char*)((u64*)((u64*) __0t5B )[0]) + ( __0x5B * __0v5B ), 0, (( __0x5B  -  __0x5B ) *  __0v5B )); } else ((u64*) __0t5B )[0]=(u64)(u64*)__runtime_calloc( __0x5B * __0v5B ) , 0 ;
 ((u64*) __0t5B )[2] = __0x5B ;
 __0y5B = (ptr)(((u64*) __0t5B )[0]) ;
 if(! __0y5B )goto __result__buffer_error ;
 } else  __0y5B = (ptr)(((u64*) __0t5B )[0]) ;
 ((u64*) __0t5B )[1] = __0w5B + __0u5B ;
 __0z5B = 0 ;
 __005B = __0z5B ;
 __015B = true ;
 __025B = __015B ;
 __035B :
 if(! __025B )goto __045B ;
 __055B = __smo_next_key_press (); 
 __0q5B = __055B ;
 __065B = 10 ;
 __075B = __065B ;
 __085B =( __0q5B == __075B ); 
 __095B :
 if(! __085B )goto __0A6B ;
 __0B6B = false ;
 __025B = __0B6B ;
 goto __0C6B ;
 __0A6B :
 __0b4B = 32 ;
 __0D6B = __0b4B ;
 __0E6B = __0q5B >= __0D6B ; 
 __0F6B :
 if(! __0E6B )goto __0G6B ;
 __0H6B = 126 ;
 __0I6B = __0H6B ;
 __0J6B = __0q5B <= __0I6B ; 
 __0K6B :
 __0G6B :
 if(! __0J6B )goto __0m4B ;
 if(! __0t5B )goto __result__buffer_error ;
 __0L6B = 1 ;
 __0M6B = ((u64*) __0t5B )[1] ;
 if( __005B >= __0M6B )goto __result__buffer_error ;
 memcpy(& __0N6B , &((char*)((void**) __0t5B )[0])[ __005B * __0L6B ], sizeof( char )) ;
 __0O6B = 0 ;
 __0P6B = __0O6B ;
 __0Q6B = __0q5B < __0P6B ; 
 __0R6B :
 if( __0Q6B )goto __0S6B ;
 __0T6B = 255 ;
 __0U6B = __0T6B ;
 __0T4B = __0q5B >= __0U6B ; 
 __0S4B :
 __0S6B :
 if(! __0T4B )goto __0R4B ;
 [[unlikely]] goto __0Q4B ;
 __builtin_unreachable();
 __0R4B :
 __0P4B = __0q5B ;
 if(! __0t5B )goto __result__buffer_error ;
 __0M6B = ((u64*)__memory_characters__dynamic__)[1] ;
 __0L6B = 1 ;
 __0O4B = (ptr)(((u64*)__memory_characters__dynamic__)[0]) ;
 if( __005B >= __0M6B )goto __result__buffer_error ;
 memcpy(&((char*) __0O4B )[ __005B * __0L6B ], & __0P4B , sizeof( char )); ;
 __0N4B = 1 ;
 __0M4B = __005B + __0N4B ; 
 __0L4B :
 __005B = __0M4B ;
 goto __0K4B ;
 __0m4B :
 __0J4B = 127 ;
 __0I4B = __0J4B ;
 __0H4B =( __0q5B == __0I4B ); 
 __0G4B :
 if(! __0H4B )goto __0F4B ;
 __0E4B = 0 ;
 __0D4B = __005B > __0E4B ; 
 __0C4B :
 __0F4B :
 if(! __0D4B )goto __0B4B ;
 __0A4B = 1 ;
 __093B = __0A4B > __005B ; 
 __083B :
 if(! __093B )goto __073B ;
 [[unlikely]] goto __063B ;
 __builtin_unreachable();
 __073B :
 __053B = __005B - __0A4B ; 
 __043B :
 __005B = __053B ;
 __0B4B :
 __0K4B :
 __0C6B :
 __033B = "\r" ;
 printf ( "%s" , __033B ); 
 __023B :
 __013B = __005B > __0e5B ; 
 __003B :
 if(! __013B )goto __0z3B ;
 __0y3B = "Cannot allocate more than the available memory" ;
 [[unlikely]] goto __0x3B ;
 __builtin_unreachable();
 __0z3B :
 __0w3B = __0e5B ?(( char *) __0Z5B )[0]:0; 
 __0v3B = __0Z5B ;
 printf ( "%.*s" ,( int ) __005B ,( char *) __0v3B ); 
 __0u3B :
 goto __035B ;
 __045B :
 fflush ( stdout ); 
 __0t3B :
 __0s3B = __005B > __0e5B ; 
 __0r3B :
 if(! __0s3B )goto __0q3B ;
 __0p3B = "Cannot allocate more than the available memory" ;
 [[unlikely]] goto __0o3B ;
 __builtin_unreachable();
 __0q3B :
 __0n3B = __0e5B ?(( char *) __0Z5B )[0]:0; 
 __0m3B = __0Z5B ;
 __0x0B__contents = __0m3B ;
 if( __0t5B ) __runtime_free( __0t5B ) ;
 __0t5B = 0 ;
 printf ( "%.*s\n" ,( int ) __005B ,( char *) __0x0B__contents ); 
 __0l3B :
 __0k3B :
goto __return;

// ERROR HANDLING
__0s5B :
 printf ( "%s\n" , __0r5B ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0l5B :
 printf ( "%s\n" , __0k5B ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__063B :
 printf ( "Error: unsigned subtraction yielded a negative\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0Q4B :
 printf ( "Cannot convert a non-character key input to a characters\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__result__buffer_error :
printf("Buffer error\n");
__result__error_code=__BUFFER__ERROR;
goto __failsafe;
__0o3B :
 printf ( "%s\n" , __0p3B ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0x3B :
 printf ( "%s\n" , __0y3B ); 
__result__error_code=__USER__ERROR;
goto __failsafe;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
if ( __0x0B__contents ) __runtime_free ( __0x0B__contents ); __0x0B__contents =0; 
__state->err =  __result__error_code;
}



int main() {
struct main__380__state __main_args={0};
__smolambda_initialize_service_tasks(main__380, &__main_args);
return __main_args.err;
}

