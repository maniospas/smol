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

#include<time.h>

#include<stdlib.h>

#include<stdio.h>

#include "std/oscommon.h"

struct main__374__state{errcode err;};
__externc void main__374(void *__void__state);

void main__374(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 2320;
struct main__374__state *__state=(struct main__374__state*)__void__state;
u64 __0A8B=0;
bool __097B=0;
bool __087B=0;
u64 __077B=0;
u64 __037B=0;
bool __007B=0;
u64 __0z7B=0;
u64 __0y7B=0;
u64 __0x7B=0;
u64 __0w7B=0;
bool __0v7B=0;
bool __0u7B=0;
f64 __0t7B=0;
ptr __0s7B=0;
f64 __0q7B=0;
f64 __0p7B=0;
u64 __0o7B=0;
u64 __0m7B=0;
u64 __0l7B=0;
u64 __0j7B=0;
u64 __0i7B=0;
f64 __0h7B=0;
f64 __0f7B=0;
f64 __0e7B=0;
f64 __0d7B=0;
u64 __0c7B=0;
u64 __0b7B=0;
bool __0Y7B=0;
bool __0X7B=0;
f64 __0W7B=0;
bool __0T7B=0;
u64 __0R7B=0;
u64 __0Q7B=0;
u64 __0P7B=0;
bool __0M7B=0;
bool __0J7B=0;
u64 __0I7B=0;
u64 __0H7B=0;
u64 __0G7B=0;
ptr __0F7B=0;
u64 __0E7B=0;
u64 __0D7B=0;
u64 __0C7B=0;
ptr __0B7B=0;
ptr __0A7B=0;
bool __086B=0;
ptr __066B=0;
u64 __056B=0;
u64 __046B=0;
u64 __036B=0;
u64 __016B=0;
u64 __0w6B=0;
f64 __0r7B=0;
u64 arr__dynamic____buffer_alignment=0;
f64 __0r6B=0;
u64 __0p6B=0;
u64 __0o6B=0;
u64 __0n6B=0;
u64 __0m6B=0;
ptr __0v6B=0;
f64 noopt=0;
u64 __0k6B=0;
bool __0h6B=0;
u64 __0e6B=0;
ptr __09xB__dynamic=0;
u64 __0d6B=0;
u64 __0c6B=0;
u64 arr__dynamic____buffer_size=0;
u64 __0a6B=0;
u64 r=0;
u64 __0Z6B=0;
u64 __0Y6B=0;
u64 __0X6B=0;
u64 __0W6B=0;
u64 __0V6B=0;
ptr arr__surface=0;
ptr __0U6B=0;
bool __0R6B=0;
u64 __0P6B=0;
u64 __0O6B=0;
f64 __0N6B=0;
bool __0x6B=0;
f64 accum=0;
f64 __0t6B=0;
u64 repetitions=0;
u64 __0L6B=0;
u64 __0K6B=0;
u64 __065B=0;
ptr __0z5B=0;
u64 __0y5B=0;
f64 __0p5B=0;
u64 __0f6B=0;
bool __0o5B=0;
u64 rand__s0=0;
ptr arr__dynamic____buffer_contents=0;
u64 __0a5B=0;
u64 __0wxB__s1=0;
u64 __0wxB__s2=0;
u64 rand__s3=0;
u64 __0O7B=0;
ptr __02xB__dynamic=0;
u64 __0K5B=0;
ptr arr__dynamic=0;
ptr stack__surface=0;
u64 rand__s1=0;
u64 __0wxB__s0=0;
ptr stack__dynamic=0;
u64 __0m4B=0;
u64 arr__dynamic____buffer_capacity=0;
u64 __0g4B=0;
f64 __0f4B=0;
u64 __0e4B=0;
u64 __0d4B=0;
u64 __0c4B=0;
u64 __0b4B=0;
ptr __0g7B=0;
u64 rand__s2=0;
u64 __0Z4B=0;
u64 __0X4B=0;
u64 __0V4B=0;
u64 __0U4B=0;
u64 __0T4B=0;
u64 __0S4B=0;
u64 __0R4B=0;
u64 __0Q4B=0;
u64 __0P4B=0;
bool __0O4B=0;
u64 __0L4B=0;
u64 __0K4B=0;
bool __0I4B=0;
u64 __0G4B=0;
u64 __0F4B=0;
bool __0D4B=0;
u64 __093B=0;
u64 __073B=0;
u64 __053B=0;
u64 __043B=0;
u64 __023B=0;
u64 __013B=0;
bool __0z3B=0;
u64 __0v3B=0;
u64 __0t3B=0;
u64 __0r3B=0;
u64 __0q3B=0;
bool __0p3B=0;
u64 __0l3B=0;
u64 __0wxB__s3=0;
bool __0g3B=0;
f64 __0f3B=0;
f64 __0d3B=0;
f64 __0b3B=0;
u64 __0Z3B=0;
f64 __0Y3B=0;
f64 __0X3B=0;
f64 __0V3B=0;
f64 __0U3B=0;
f64 __0T3B=0;
f64 __0R3B=0;
cstr __0O3B=0;

// IMPLEMENTATION
__0p5B = 0.0 ;
 noopt = __0p5B ;
 __0f4B = 0.0 ;
 accum = __0f4B ;
 __0z5B =( struct timespec *) alloca ( sizeof ( struct timespec )); clock_gettime ( CLOCK_REALTIME ,( struct timespec *) __0z5B ); __0d4B =( u64 )(( struct timespec *) __0z5B )-> tv_sec *( u64 ) 1000000000 +(( struct timespec *) __0z5B )-> tv_nsec ; 
 __0h4B :
 __0c4B =( __0d4B += 0x9E3779B97F4A7C15ULL ); __0c4B =( __0c4B ^( __0c4B >> 30 ))* 0xBF58476D1CE4E5B9ULL ; __0c4B =( __0c4B ^( __0c4B >> 27 ))* 0x94D049BB133111EBULL ; __0c4B = __0c4B ^( __0c4B >> 31 ); 
 __0a4B :
 __0Z4B =( __0d4B += 0x9E3779B97F4A7C15ULL ); __0Z4B =( __0Z4B ^( __0Z4B >> 30 ))* 0xBF58476D1CE4E5B9ULL ; __0Z4B =( __0Z4B ^( __0Z4B >> 27 ))* 0x94D049BB133111EBULL ; __0Z4B = __0Z4B ^( __0Z4B >> 31 ); 
 __0Y4B :
 __0K5B =( __0d4B += 0x9E3779B97F4A7C15ULL ); __0K5B =( __0K5B ^( __0K5B >> 30 ))* 0xBF58476D1CE4E5B9ULL ; __0K5B =( __0K5B ^( __0K5B >> 27 ))* 0x94D049BB133111EBULL ; __0K5B = __0K5B ^( __0K5B >> 31 ); 
 __0u4B :
 __0X4B =( __0d4B += 0x9E3779B97F4A7C15ULL ); __0X4B =( __0X4B ^( __0X4B >> 30 ))* 0xBF58476D1CE4E5B9ULL ; __0X4B =( __0X4B ^( __0X4B >> 27 ))* 0x94D049BB133111EBULL ; __0X4B = __0X4B ^( __0X4B >> 31 ); 
 __0W4B :
 __0wxB__s0 = __0c4B ;
 __0wxB__s1 = __0Z4B ;
 __0wxB__s2 = __0K5B ;
 __0wxB__s3 = __0X4B ;
 
 rand__s0 = __0wxB__s0 ;
 rand__s1 = __0wxB__s1 ;
 rand__s2 = __0wxB__s2 ;
 rand__s3 = __0wxB__s3 ;
 __0V4B = 100 ;
 __0m4B = 100000 ;
 __0b4B = __0V4B ;
 __0U4B = 0 ;
 __0T4B = 1 ;
 __0S4B = __0U4B ;
 __0a5B = __0T4B ;
 __0R4B = __0U4B ;
 __0J6B :
 __0K6B = __0R4B ;
 __0L6B = repetitions ;
 __0L6B = __0K6B ;
 __0O6B = 1 ;
 __0P6B = __0K6B + __0O6B ; 
 __0Q6B :
 __0K6B = __0P6B ;
 __0R6B = __0K6B <= __0b4B ; 
 __0S6B :
 __0R4B = __0K6B ;
 if(! __0R6B )goto __0T6B ;
 __02xB__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 __0U6B = 0 ;
 arr__dynamic = __02xB__dynamic ;
 arr__surface = __0U6B ;
 __0V6B = __0m4B ;
 __0W6B = 0 ;
 __0X6B = 1 ;
 __0Y6B = __0W6B ;
 __0Z6B = __0X6B ;
 __0a6B = __0W6B ;
 __0b6B :
 __0c6B = __0a6B ;
 __0d6B = r ;
 __0d6B = __0c6B ;
 __0e6B = 1 ;
 __0f6B = __0c6B + __0e6B ; 
 __0g6B :
 __0c6B = __0f6B ;
 __0h6B = __0c6B <= __0V6B ; 
 __0i6B :
 __0a6B = __0c6B ;
 if(! __0h6B )goto __0j6B ;
 __0k6B = rand__s3 ;
 __0m6B = rand__s0 + __0k6B ; __0n6B = rand__s1 << 17 ; rand__s2 ^= rand__s0 ; __0k6B ^= rand__s1 ; rand__s1 ^= rand__s2 ; rand__s0 ^= __0k6B ; rand__s2 ^= __0n6B ; 
 __0o6B = 45 ;
 __0p6B =( __0k6B << __0o6B )|( __0k6B >>( 64 - __0o6B )); 
 __0q6B :
 __0k6B = __0p6B ;
 __0r6B =(( f64 )( __0m6B >> 11 ))/(( f64 )(( unsigned long long )(1)<< 53 )); 
 __0s6B :
 rand__s3 = __0k6B ;
 if(! arr__dynamic )goto __result__buffer_error ;
 arr__dynamic____buffer_alignment = 8 ;
 arr__dynamic____buffer_size = ((u64*) arr__dynamic )[1] ;
 arr__dynamic____buffer_capacity = ((u64*) arr__dynamic )[2] & ~(1ULL << 63) ;
 if( arr__dynamic____buffer_size >= arr__dynamic____buffer_capacity ){ if( ((u64*) arr__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 arr__dynamic____buffer_capacity = arr__dynamic____buffer_capacity +( arr__dynamic____buffer_capacity >>2)+1; if( arr__dynamic____buffer_size ) ((void**) arr__dynamic )[0] = __runtime_realloc((u64*)((void**) arr__dynamic )[0],  arr__dynamic____buffer_capacity * arr__dynamic____buffer_alignment , arr__dynamic____buffer_capacity * arr__dynamic____buffer_alignment ) ;
 else ((void**) arr__dynamic )[0] = __runtime_alloc( arr__dynamic____buffer_capacity * arr__dynamic____buffer_alignment ) ;
 ((u64*) arr__dynamic )[2] = arr__dynamic____buffer_capacity ;
 arr__dynamic____buffer_contents = (ptr)((void**) arr__dynamic )[0] ;
 if(! arr__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  arr__dynamic____buffer_contents = (ptr)(((u64*) arr__dynamic )[0]) ;
 ((u64*) arr__dynamic )[1] = arr__dynamic____buffer_size +1 ;
 memcpy(&((char*) arr__dynamic____buffer_contents )[ arr__dynamic____buffer_size * arr__dynamic____buffer_alignment ], & __0r6B , 8 ) ;
 goto __0b6B ;
 __0j6B :
 __0t6B = __smo_time_eta (); 
 __0u6B :
 __09xB__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 __0v6B = 0 ;
 __065B = 0 ;
 __0y5B = arr__dynamic ? ((u64*) arr__dynamic )[1]:0 ;
 __0w6B = 1 ;
 __0x6B = __0w6B > __0y5B ; 
 __0y6B :
 if(! __0x6B )goto __0z6B ;
 [[unlikely]] goto __006B ;
 __builtin_unreachable();
 __0z6B :
 __016B = __0y5B - __0w6B ; 
 __026B :
 if(! __09xB__dynamic )goto __result__buffer_error ;
 __036B = 16 ;
 __046B = ((u64*) __09xB__dynamic )[1] ;
 __056B = ((u64*) __09xB__dynamic )[2] & ~(1ULL << 63) ;
 if( __046B >= __056B ){ if( ((u64*) __09xB__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __056B = __056B +( __056B >>2)+1; if( __046B ) ((void**) __09xB__dynamic )[0] = __runtime_realloc((u64*)((void**) __09xB__dynamic )[0],  __056B * __036B , __056B * __036B ) ;
 else ((void**) __09xB__dynamic )[0] = __runtime_alloc( __056B * __036B ) ;
 ((u64*) __09xB__dynamic )[2] = __056B ;
 __066B = (ptr)((void**) __09xB__dynamic )[0] ;
 if(! __066B )goto __result__buffer_error ;
 } else  __066B = (ptr)(((u64*) __09xB__dynamic )[0]) ;
 ((u64*) __09xB__dynamic )[1] = __046B +1 ;
 memcpy( &((char*) __066B )[ __046B * __036B + 0 ] , & __065B , 8 ) ;
 memcpy( &((char*) __066B )[ __046B * __036B + 8 ] , & __016B , 8 ) ;
 stack__dynamic = __09xB__dynamic ;
 stack__surface = __0v6B ;
 __076B :
 __0y5B = stack__dynamic ? ((u64*) stack__dynamic )[1]:0 ;
 __086B = __0y5B ;
 if(! __086B )goto __096B ;
 __0A7B = arr__dynamic ;
 __0B7B = arr__surface ;
 if(! stack__dynamic )goto __result__buffer_pop_error ;
 __0C7B = 16 ;
 __0D7B = ((u64*) stack__dynamic )[1] ;
 __0E7B = ((u64*) stack__dynamic )[2] & ~(1ULL << 63) ;
 if(! __0D7B )goto __result__buffer_pop_error ;
 __0F7B = (ptr)((void**) stack__dynamic )[0] ;
 if(! __0F7B )goto __result__buffer_pop_error ;
 __0G7B = __0D7B -1 ;
 memcpy( & __0H7B , &((char*) __0F7B )[ __0G7B * __0C7B + 0 ] , 8 ) ;
 memcpy( & __0I7B , &((char*) __0F7B )[ __0G7B * __0C7B + 8 ] , 8 ) ;
 ((u64*) stack__dynamic )[1] = __0G7B ;
 __0J7B = __0H7B >= __0I7B ; 
 __0K7B :
 if(! __0J7B )goto __0L7B ;
 __0M7B = false ;
 goto __0N7B ;
 __0L7B :
 if(! __0A7B )goto __result__buffer_error ;
 __0O7B = 8 ;
 __0P7B = ((u64*) __0A7B )[1] ;
 if( __0I7B >= __0P7B )goto __result__buffer_error ;
 memcpy(& __0N6B , &((char*)((void**) __0A7B )[0])[ __0I7B * __0O7B ], sizeof( f64 )) ;
 __0Q7B = __0H7B ;
 __0R7B = __0H7B ;
 __0S7B :
 __0T7B = __0R7B < __0I7B ; 
 __0U7B :
 if(! __0T7B )goto __0V7B ;
 if(! __0A7B )goto __result__buffer_error ;
 __0O7B = 8 ;
 __0P7B = ((u64*) __0A7B )[1] ;
 if( __0R7B >= __0P7B )goto __result__buffer_error ;
 memcpy(& __0W7B , &((char*)((void**) __0A7B )[0])[ __0R7B * __0O7B ], sizeof( f64 )) ;
 __0Y7B = __0W7B < __0N6B ; 
 __0Z7B :
 if(! __0Y7B )goto __0a7B ;
 if(! __0A7B )goto __result__buffer_error ;
 __0b7B = 8 ;
 __0c7B = ((u64*) __0A7B )[1] ;
 if( __0Q7B >= __0c7B )goto __result__buffer_error ;
 memcpy(& __0d7B , &((char*)((void**) __0A7B )[0])[ __0Q7B * __0b7B ], sizeof( f64 )) ;
 if(! __0A7B )goto __result__buffer_error ;
 __0b7B = 8 ;
 __0c7B = ((u64*) __0A7B )[1] ;
 if( __0Q7B >= __0c7B )goto __result__buffer_error ;
 memcpy(& __0e7B , &((char*)((void**) __0A7B )[0])[ __0Q7B * __0b7B ], sizeof( f64 )) ;
 if(! __0A7B )goto __result__buffer_error ;
 __0b7B = 8 ;
 __0c7B = ((u64*) __0A7B )[1] ;
 if( __0R7B >= __0c7B )goto __result__buffer_error ;
 memcpy(& __0f7B , &((char*)((void**) __0A7B )[0])[ __0R7B * __0b7B ], sizeof( f64 )) ;
 if(! __0A7B )goto __result__buffer_error ;
 __0c7B = ((u64*) __0A7B )[1] ;
 __0b7B = 8 ;
 __0g7B = (ptr)(((u64*) __0A7B )[0]) ;
 if( __0Q7B >= __0c7B )goto __result__buffer_error ;
 memcpy(&((char*) __0g7B )[ __0Q7B * __0b7B ], & __0f7B , sizeof( f64 )) ;
 if(! __0A7B )goto __result__buffer_error ;
 __0b7B = 8 ;
 __0c7B = ((u64*) __0A7B )[1] ;
 if( __0R7B >= __0c7B )goto __result__buffer_error ;
 memcpy(& __0h7B , &((char*)((void**) __0A7B )[0])[ __0R7B * __0b7B ], sizeof( f64 )) ;
 if(! __0A7B )goto __result__buffer_error ;
 __0c7B = ((u64*) __0A7B )[1] ;
 __0b7B = 8 ;
 __0g7B = (ptr)(((u64*) __0A7B )[0]) ;
 if( __0R7B >= __0c7B )goto __result__buffer_error ;
 memcpy(&((char*) __0g7B )[ __0R7B * __0b7B ], & __0d7B , sizeof( f64 )) ;
 __0i7B = 1 ;
 __0j7B = __0Q7B + __0i7B ; 
 __0k7B :
 __0Q7B = __0j7B ;
 __0a7B :
 __0l7B = 1 ;
 __0m7B = __0R7B + __0l7B ; 
 __0n7B :
 __0R7B = __0m7B ;
 goto __0S7B ;
 __0V7B :
 if(! __0A7B )goto __result__buffer_error ;
 __0e4B = 8 ;
 __0o7B = ((u64*) __0A7B )[1] ;
 if( __0Q7B >= __0o7B )goto __result__buffer_error ;
 memcpy(& __0p7B , &((char*)((void**) __0A7B )[0])[ __0Q7B * __0e4B ], sizeof( f64 )) ;
 if(! __0A7B )goto __result__buffer_error ;
 __0e4B = 8 ;
 __0o7B = ((u64*) __0A7B )[1] ;
 if( __0Q7B >= __0o7B )goto __result__buffer_error ;
 memcpy(& __0q7B , &((char*)((void**) __0A7B )[0])[ __0Q7B * __0e4B ], sizeof( f64 )) ;
 if(! __0A7B )goto __result__buffer_error ;
 __0e4B = 8 ;
 __0o7B = ((u64*) __0A7B )[1] ;
 if( __0I7B >= __0o7B )goto __result__buffer_error ;
 memcpy(& __0r7B , &((char*)((void**) __0A7B )[0])[ __0I7B * __0e4B ], sizeof( f64 )) ;
 if(! __0A7B )goto __result__buffer_error ;
 __0o7B = ((u64*) __0A7B )[1] ;
 __0e4B = 8 ;
 __0s7B = (ptr)(((u64*) __0A7B )[0]) ;
 if( __0Q7B >= __0o7B )goto __result__buffer_error ;
 memcpy(&((char*) __0s7B )[ __0Q7B * __0e4B ], & __0r7B , sizeof( f64 )) ;
 if(! __0A7B )goto __result__buffer_error ;
 __0e4B = 8 ;
 __0o7B = ((u64*) __0A7B )[1] ;
 if( __0I7B >= __0o7B )goto __result__buffer_error ;
 memcpy(& __0t7B , &((char*)((void**) __0A7B )[0])[ __0I7B * __0e4B ], sizeof( f64 )) ;
 if(! __0A7B )goto __result__buffer_error ;
 __0o7B = ((u64*) __0A7B )[1] ;
 __0e4B = 8 ;
 __0s7B = (ptr)(((u64*) __0A7B )[0]) ;
 if( __0I7B >= __0o7B )goto __result__buffer_error ;
 memcpy(&((char*) __0s7B )[ __0I7B * __0e4B ], & __0p7B , sizeof( f64 )) ;
 __0u7B = false ;
 __0v7B = __0u7B ;
 __0w7B = 0 ;
 __0x7B = __0w7B ;
 __0y7B = 0 ;
 __0z7B = __0y7B ;
 __007B = __0Q7B > __0H7B ; 
 __017B :
 if(! __007B )goto __027B ;
 __0x7B = __0H7B ;
 __037B = 1 ;
 __0o5B = __037B > __0Q7B ; 
 __047B :
 if(! __0o5B )goto __057B ;
 [[unlikely]] goto __067B ;
 __builtin_unreachable();
 __057B :
 __077B = __0Q7B - __037B ; 
 __0p4B :
 __0z7B = __077B ;
 __0X7B = true ;
 __0v7B = __0X7B ;
 __027B :
 __087B = false ;
 __097B = __087B ;
 __0g4B = 0 ;
 __0A8B = __0g4B ;
 __0Q4B = 0 ;
 __0P4B = __0Q4B ;
 __0O4B = __0Q7B < __0I7B ; 
 __0N4B :
 if(! __0O4B )goto __0M4B ;
 __0L4B = 1 ;
 __0K4B = __0Q7B + __0L4B ; 
 __0J4B :
 __0A8B = __0K4B ;
 __0P4B = __0I7B ;
 __0I4B = true ;
 __097B = __0I4B ;
 __0M4B :
 if(! __0v7B )goto __0H4B ;
 __0G4B = 1 ;
 __0F4B = __0z7B + __0G4B ; 
 __0E4B :
 __0D4B = __0x7B > __0F4B ; 
 __0C4B :
 if(! __0D4B )goto __0B4B ;
 [[unlikely]] goto __0A4B ;
 __builtin_unreachable();
 __0B4B :
 __093B = __0F4B - __0x7B ; 
 __083B :
 __073B = __093B ;
 goto __063B ;
 __0H4B :
 __053B = 0 ;
 __073B = __053B ;
 __063B :
 __043B = 0 ;
 if(! __097B )goto __033B ;
 __023B = 1 ;
 __013B = __0P4B + __023B ; 
 __003B :
 __0z3B = __0A8B > __013B ; 
 __0y3B :
 if(! __0z3B )goto __0x3B ;
 [[unlikely]] goto __0w3B ;
 __builtin_unreachable();
 __0x3B :
 __0v3B = __013B - __0A8B ; 
 __0u3B :
 __0t3B = __0v3B ;
 goto __0s3B ;
 __033B :
 __0r3B = 0 ;
 __0t3B = __0r3B ;
 __0s3B :
 __0q3B = 0 ;
 __0p3B = __073B < __0t3B ; 
 __0o3B :
 if(! __0p3B )goto __0n3B ;
 if(! __097B )goto __0m3B ;
 if(! stack__dynamic )goto __result__buffer_error ;
 __0C7B = 16 ;
 __0D7B = ((u64*) stack__dynamic )[1] ;
 __0E7B = ((u64*) stack__dynamic )[2] & ~(1ULL << 63) ;
 if( __0D7B >= __0E7B ){ if( ((u64*) stack__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __0l3B = __0E7B ;
 __0E7B = __0E7B +( __0E7B >>2)+1; if( __0D7B ) ((void**) stack__dynamic )[0] = __runtime_realloc((u64*)((void**) stack__dynamic )[0],  __0E7B * __0C7B , __0l3B * __0C7B ) ;
 else ((void**) stack__dynamic )[0] = __runtime_alloc( __0E7B * __0C7B ) ;
 ((u64*) stack__dynamic )[2] = __0E7B ;
 __0F7B = (ptr)((void**) stack__dynamic )[0] ;
 if(! __0F7B )goto __result__buffer_error ;
 } else  __0F7B = (ptr)(((u64*) stack__dynamic )[0]) ;
 ((u64*) stack__dynamic )[1] = __0D7B +1 ;
 memcpy( &((char*) __0F7B )[ __0D7B * __0C7B + 0 ] , & __0A8B , 8 ) ;
 memcpy( &((char*) __0F7B )[ __0D7B * __0C7B + 8 ] , & __0P4B , 8 ) ;
 __0m3B :
 if(! __0v7B )goto __0k3B ;
 if(! stack__dynamic )goto __result__buffer_error ;
 __0C7B = 16 ;
 __0D7B = ((u64*) stack__dynamic )[1] ;
 __0E7B = ((u64*) stack__dynamic )[2] & ~(1ULL << 63) ;
 if( __0D7B >= __0E7B ){ if( ((u64*) stack__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __0l3B = __0E7B ;
 __0E7B = __0E7B +( __0E7B >>2)+1; if( __0D7B ) ((void**) stack__dynamic )[0] = __runtime_realloc((u64*)((void**) stack__dynamic )[0],  __0E7B * __0C7B , __0l3B * __0C7B ) ;
 else ((void**) stack__dynamic )[0] = __runtime_alloc( __0E7B * __0C7B ) ;
 ((u64*) stack__dynamic )[2] = __0E7B ;
 __0F7B = (ptr)((void**) stack__dynamic )[0] ;
 if(! __0F7B )goto __result__buffer_error ;
 } else  __0F7B = (ptr)(((u64*) stack__dynamic )[0]) ;
 ((u64*) stack__dynamic )[1] = __0D7B +1 ;
 memcpy( &((char*) __0F7B )[ __0D7B * __0C7B + 0 ] , & __0x7B , 8 ) ;
 memcpy( &((char*) __0F7B )[ __0D7B * __0C7B + 8 ] , & __0z7B , 8 ) ;
 goto __0j3B ;
 __0k3B :
 if(! __0v7B )goto __0i3B ;
 if(! stack__dynamic )goto __result__buffer_error ;
 __0C7B = 16 ;
 __0D7B = ((u64*) stack__dynamic )[1] ;
 __0E7B = ((u64*) stack__dynamic )[2] & ~(1ULL << 63) ;
 if( __0D7B >= __0E7B ){ if( ((u64*) stack__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __0l3B = __0E7B ;
 __0E7B = __0E7B +( __0E7B >>2)+1; if( __0D7B ) ((void**) stack__dynamic )[0] = __runtime_realloc((u64*)((void**) stack__dynamic )[0],  __0E7B * __0C7B , __0l3B * __0C7B ) ;
 else ((void**) stack__dynamic )[0] = __runtime_alloc( __0E7B * __0C7B ) ;
 ((u64*) stack__dynamic )[2] = __0E7B ;
 __0F7B = (ptr)((void**) stack__dynamic )[0] ;
 if(! __0F7B )goto __result__buffer_error ;
 } else  __0F7B = (ptr)(((u64*) stack__dynamic )[0]) ;
 ((u64*) stack__dynamic )[1] = __0D7B +1 ;
 memcpy( &((char*) __0F7B )[ __0D7B * __0C7B + 0 ] , & __0x7B , 8 ) ;
 memcpy( &((char*) __0F7B )[ __0D7B * __0C7B + 8 ] , & __0z7B , 8 ) ;
 __0i3B :
 if(! __097B )goto __0h3B ;
 if(! stack__dynamic )goto __result__buffer_error ;
 __0C7B = 16 ;
 __0D7B = ((u64*) stack__dynamic )[1] ;
 __0E7B = ((u64*) stack__dynamic )[2] & ~(1ULL << 63) ;
 if( __0D7B >= __0E7B ){ if( ((u64*) stack__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __0l3B = __0E7B ;
 __0E7B = __0E7B +( __0E7B >>2)+1; if( __0D7B ) ((void**) stack__dynamic )[0] = __runtime_realloc((u64*)((void**) stack__dynamic )[0],  __0E7B * __0C7B , __0l3B * __0C7B ) ;
 else ((void**) stack__dynamic )[0] = __runtime_alloc( __0E7B * __0C7B ) ;
 ((u64*) stack__dynamic )[2] = __0E7B ;
 __0F7B = (ptr)((void**) stack__dynamic )[0] ;
 if(! __0F7B )goto __result__buffer_error ;
 } else  __0F7B = (ptr)(((u64*) stack__dynamic )[0]) ;
 ((u64*) stack__dynamic )[1] = __0D7B +1 ;
 memcpy( &((char*) __0F7B )[ __0D7B * __0C7B + 0 ] , & __0A8B , 8 ) ;
 memcpy( &((char*) __0F7B )[ __0D7B * __0C7B + 8 ] , & __0P4B , 8 ) ;
 __0h3B :
 __0g3B = true ;
 goto __0N7B ;
 __0j3B :
 __0n3B :
 __0N7B :
 arr__dynamic = __0A7B ;
 arr__surface = __0B7B ;
 goto __076B ;
 __096B :
 __0f3B = __smo_time_eta (); 
 __0e3B :
 __0d3B = __0f3B - __0t6B ; 
 __0c3B :
 __0b3B = accum + __0d3B ; 
 __0a3B :
 accum = __0b3B ;
 __0Z3B = 0 ;
 if(! arr__dynamic )goto __result__buffer_error ;
 arr__dynamic____buffer_alignment = 8 ;
 arr__dynamic____buffer_size = ((u64*) arr__dynamic )[1] ;
 if( __0Z3B >= arr__dynamic____buffer_size )goto __result__buffer_error ;
 memcpy(& __0Y3B , &((char*)((void**) arr__dynamic )[0])[ __0Z3B * arr__dynamic____buffer_alignment ], sizeof( f64 )) ;
 __0X3B = noopt + __0Y3B ; 
 __0W3B :
 noopt = __0X3B ;
 goto __0J6B ;
 __0T6B :
 __0V3B = 1000.0 ;
 __0U3B = __0V4B ;
 __0T3B = __0V3B / __0U3B ; 
 __0S3B :
 __0R3B = accum * __0T3B ; 
 __0Q3B :
 printf ( "%.6f" , __0R3B ); 
 __0P3B :
 __0O3B = " ms" ;
 printf ( "%s\n" , __0O3B ); 
 __0N3B :
 __0M3B :
goto __return;

// ERROR HANDLING
__067B :
 printf ( "Error: unsigned subtraction yielded a negative\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__result__buffer_pop_error :
printf("Buffer error\n");
__result__error_code=__BUFFER__ERROR;
goto __failsafe;
__006B :
 printf ( "Error: unsigned subtraction yielded a negative\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0A4B :
 printf ( "Error: unsigned subtraction yielded a negative\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0w3B :
 printf ( "Error: unsigned subtraction yielded a negative\n" ); 
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
if( __09xB__dynamic ){if((u64*)((u64*) __09xB__dynamic )[2]) __runtime_free((u64*)((u64*) __09xB__dynamic )[0]) ;
 __runtime_free( __09xB__dynamic ) ;
 __09xB__dynamic = 0 ;
 }if( __02xB__dynamic ){if((u64*)((u64*) __02xB__dynamic )[2]) __runtime_free((u64*)((u64*) __02xB__dynamic )[0]) ;
 __runtime_free( __02xB__dynamic ) ;
 __02xB__dynamic = 0 ;
 }
 

 

 

 
__state->err =  __result__error_code;
}



int main() {
struct main__374__state __main_args={0};
__smolambda_initialize_service_tasks(main__374, &__main_args);
return __main_args.err;
}

