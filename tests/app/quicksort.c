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
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__374__state *__state=(struct main__374__state*)__void__state;
bool __0A8B=0;
bool __097B=0;
u64 __087B=0;
bool __027B=0;
u64 __017B=0;
u64 __007B=0;
u64 __0z7B=0;
u64 __0y7B=0;
bool __0x7B=0;
f64 __0w7B=0;
ptr __0v7B=0;
f64 __0u7B=0;
f64 __0t7B=0;
u64 __0s7B=0;
u64 __0p7B=0;
u64 __0o7B=0;
u64 __0m7B=0;
u64 __0l7B=0;
f64 __0k7B=0;
ptr __0j7B=0;
f64 __0i7B=0;
f64 __0h7B=0;
u64 __0f7B=0;
bool __0c7B=0;
f64 __0b7B=0;
bool __0Y7B=0;
u64 __0W7B=0;
u64 __0V7B=0;
f64 __0U7B=0;
u64 __0T7B=0;
bool __0Q7B=0;
bool __0N7B=0;
u64 __0M7B=0;
u64 __0L7B=0;
ptr __0K7B=0;
u64 __0J7B=0;
u64 __0I7B=0;
u64 __0H7B=0;
ptr __0G7B=0;
ptr __0F7B=0;
bool __0D7B=0;
bool __0B7B=0;
u64 __0A7B=0;
ptr __096B=0;
u64 __086B=0;
u64 __076B=0;
u64 __066B=0;
u64 __046B=0;
bool __006B=0;
ptr __0y6B=0;
f64 __0w6B=0;
u64 __0r7B=0;
u64 arr__dynamic____buffer_alignment=0;
u64 __0r6B=0;
u64 __0q6B=0;
u64 __0p6B=0;
u64 __0o6B=0;
u64 __0n6B=0;
u64 __0v6B=0;
f64 noopt=0;
u64 __0m6B=0;
bool __0k6B=0;
u64 __0h6B=0;
u64 __0g6B=0;
u64 arr__dynamic____buffer_size=0;
ptr __09xB__dynamic=0;
u64 __0e6B=0;
u64 __0d6B=0;
u64 __0c6B=0;
u64 __0b6B=0;
u64 __0a6B=0;
u64 r=0;
u64 __0Z6B=0;
ptr __0Y6B=0;
bool __0V6B=0;
u64 __0T6B=0;
u64 __0S6B=0;
u64 __0R6B=0;
u64 __0Q6B=0;
u64 __0O6B=0;
u64 __0N6B=0;
f64 __0g7B=0;
u64 rand__s2=0;
u64 __0S7B=0;
u64 rand__s1=0;
ptr __025B=0;
u64 __015B=0;
bool __0q5B=0;
bool __0k5B=0;
u64 rand__s0=0;
u64 __0j5B=0;
ptr arr__dynamic____buffer_contents=0;
u64 __0wxB__s1=0;
u64 __0Y5B=0;
f64 __0X5B=0;
u64 __0wxB__s2=0;
u64 __0U5B=0;
f64 __0M5B=0;
ptr arr__dynamic=0;
ptr stack__surface=0;
u64 __0z6B=0;
u64 __034B=0;
u64 __0wxB__s0=0;
ptr stack__dynamic=0;
u64 __0q4B=0;
f64 __0l4B=0;
u64 __0i4B=0;
u64 arr__dynamic____buffer_capacity=0;
u64 __0e4B=0;
u64 __0i6B=0;
ptr arr__surface=0;
u64 __0d4B=0;
ptr __02xB__dynamic=0;
u64 rand__s3=0;
u64 __0c4B=0;
f64 accum=0;
u64 __0Z4B=0;
f64 __0t6B=0;
u64 repetitions=0;
u64 __0W4B=0;
u64 __0V4B=0;
u64 __0U4B=0;
u64 __0R4B=0;
u64 __0Q4B=0;
u64 __0P4B=0;
u64 __0O4B=0;
bool __0N4B=0;
u64 __0K4B=0;
u64 __0J4B=0;
bool __0H4B=0;
u64 __0F4B=0;
u64 __0E4B=0;
bool __0C4B=0;
u64 __083B=0;
u64 __063B=0;
u64 __043B=0;
u64 __033B=0;
u64 __013B=0;
u64 __003B=0;
bool __0y3B=0;
u64 __0u3B=0;
u64 __0s3B=0;
u64 __0q3B=0;
u64 __0p3B=0;
bool __0o3B=0;
u64 __0k3B=0;
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
__0M5B = 0.0 ;
 noopt = __0M5B ;
 __0X5B = 0.0 ;
 accum = __0X5B ;
 __025B =( struct timespec *) alloca ( sizeof ( struct timespec )); clock_gettime ( CLOCK_REALTIME ,( struct timespec *) __025B ); __0Z4B =( u64 )(( struct timespec *) __025B )-> tv_sec *( u64 ) 1000000000 +(( struct timespec *) __025B )-> tv_nsec ; 
 __0Y4B :
 __0c4B =( __0Z4B += 0x9E3779B97F4A7C15ULL ); __0c4B =( __0c4B ^( __0c4B >> 30 ))* 0xBF58476D1CE4E5B9ULL ; __0c4B =( __0c4B ^( __0c4B >> 27 ))* 0x94D049BB133111EBULL ; __0c4B = __0c4B ^( __0c4B >> 31 ); 
 __0a4B :
 __0W4B =( __0Z4B += 0x9E3779B97F4A7C15ULL ); __0W4B =( __0W4B ^( __0W4B >> 30 ))* 0xBF58476D1CE4E5B9ULL ; __0W4B =( __0W4B ^( __0W4B >> 27 ))* 0x94D049BB133111EBULL ; __0W4B = __0W4B ^( __0W4B >> 31 ); 
 __0B6B :
 __0U4B =( __0Z4B += 0x9E3779B97F4A7C15ULL ); __0U4B =( __0U4B ^( __0U4B >> 30 ))* 0xBF58476D1CE4E5B9ULL ; __0U4B =( __0U4B ^( __0U4B >> 27 ))* 0x94D049BB133111EBULL ; __0U4B = __0U4B ^( __0U4B >> 31 ); 
 __0T4B :
 __0d4B =( __0Z4B += 0x9E3779B97F4A7C15ULL ); __0d4B =( __0d4B ^( __0d4B >> 30 ))* 0xBF58476D1CE4E5B9ULL ; __0d4B =( __0d4B ^( __0d4B >> 27 ))* 0x94D049BB133111EBULL ; __0d4B = __0d4B ^( __0d4B >> 31 ); 
 __0S4B :
 __0wxB__s0 = __0c4B ;
 __0wxB__s1 = __0W4B ;
 __0wxB__s2 = __0U4B ;
 __0wxB__s3 = __0d4B ;
 
 rand__s0 = __0wxB__s0 ;
 rand__s1 = __0wxB__s1 ;
 rand__s2 = __0wxB__s2 ;
 rand__s3 = __0wxB__s3 ;
 __0U5B = 100 ;
 __0j5B = 100000 ;
 __0i4B = __0U5B ;
 __0q4B = 0 ;
 __0R4B = 1 ;
 __0Q4B = __0q4B ;
 __0N6B = __0R4B ;
 __0O6B = __0q4B ;
 __0P6B :
 __0Q6B = __0O6B ;
 __0R6B = repetitions ;
 __0R6B = __0Q6B ;
 __0S6B = 1 ;
 __0T6B = __0Q6B + __0S6B ; 
 __0U6B :
 __0Q6B = __0T6B ;
 __0V6B = __0Q6B <= __0i4B ; 
 __0W6B :
 __0O6B = __0Q6B ;
 if(! __0V6B )goto __0X6B ;
 __02xB__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 __0Y6B = 0 ;
 arr__dynamic = __02xB__dynamic ;
 arr__surface = __0Y6B ;
 __0Z6B = __0j5B ;
 __0a6B = 0 ;
 __0b6B = 1 ;
 __0c6B = __0a6B ;
 __0d6B = __0b6B ;
 __0e6B = __0a6B ;
 __0f6B :
 __0g6B = __0e6B ;
 __0n6B = r ;
 __0n6B = __0g6B ;
 __0h6B = 1 ;
 __0i6B = __0g6B + __0h6B ; 
 __0j6B :
 __0g6B = __0i6B ;
 __0k6B = __0g6B <= __0Z6B ; 
 __0l6B :
 __0e6B = __0g6B ;
 if(! __0k6B )goto __024B ;
 __0m6B = rand__s3 ;
 __0o6B = rand__s0 + __0m6B ; __0p6B = rand__s1 << 17 ; rand__s2 ^= rand__s0 ; __0m6B ^= rand__s1 ; rand__s1 ^= rand__s2 ; rand__s0 ^= __0m6B ; rand__s2 ^= __0p6B ; 
 __0q6B = 45 ;
 __0r6B =( __0m6B << __0q6B )|( __0m6B >>( 64 - __0q6B )); 
 __0s6B :
 __0m6B = __0r6B ;
 __0t6B =(( f64 )( __0o6B >> 11 ))/(( f64 )(( unsigned long long )(1)<< 53 )); 
 __0u6B :
 rand__s3 = __0m6B ;
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
 memcpy(&((char*) arr__dynamic____buffer_contents )[ arr__dynamic____buffer_size * arr__dynamic____buffer_alignment ], & __0t6B , 8 ) ;
 goto __0f6B ;
 __024B :
 __0w6B = __smo_time_eta (); 
 __0x6B :
 __09xB__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 __0y6B = 0 ;
 __0e4B = 0 ;
 __015B = arr__dynamic ? ((u64*) arr__dynamic )[1]:0 ;
 __0z6B = 1 ;
 __006B = __0z6B > __015B ; 
 __016B :
 if(! __006B )goto __026B ;
 [[unlikely]] goto __036B ;
 __builtin_unreachable();
 __026B :
 __046B = __015B - __0z6B ; 
 __056B :
 if(! __09xB__dynamic )goto __result__buffer_error ;
 __066B = 16 ;
 __076B = ((u64*) __09xB__dynamic )[1] ;
 __086B = ((u64*) __09xB__dynamic )[2] & ~(1ULL << 63) ;
 if( __076B >= __086B ){ if( ((u64*) __09xB__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __086B = __086B +( __086B >>2)+1; if( __076B ) ((void**) __09xB__dynamic )[0] = __runtime_realloc((u64*)((void**) __09xB__dynamic )[0],  __086B * __066B , __086B * __066B ) ;
 else ((void**) __09xB__dynamic )[0] = __runtime_alloc( __086B * __066B ) ;
 ((u64*) __09xB__dynamic )[2] = __086B ;
 __096B = (ptr)((void**) __09xB__dynamic )[0] ;
 if(! __096B )goto __result__buffer_error ;
 } else  __096B = (ptr)(((u64*) __09xB__dynamic )[0]) ;
 ((u64*) __09xB__dynamic )[1] = __076B +1 ;
 memcpy( &((char*) __096B )[ __076B * __066B + 0 ] , & __0e4B , 8 ) ;
 memcpy( &((char*) __096B )[ __076B * __066B + 8 ] , & __046B , 8 ) ;
 stack__dynamic = __09xB__dynamic ;
 stack__surface = __0y6B ;
 __0C7B :
 __015B = stack__dynamic ? ((u64*) stack__dynamic )[1]:0 ;
 __0D7B = __015B ;
 if(! __0D7B )goto __0E7B ;
 __0F7B = arr__dynamic ;
 __0G7B = arr__surface ;
 if(! stack__dynamic )goto __result__buffer_pop_error ;
 __0H7B = 16 ;
 __0I7B = ((u64*) stack__dynamic )[1] ;
 __0J7B = ((u64*) stack__dynamic )[2] & ~(1ULL << 63) ;
 if(! __0I7B )goto __result__buffer_pop_error ;
 __0K7B = (ptr)((void**) stack__dynamic )[0] ;
 if(! __0K7B )goto __result__buffer_pop_error ;
 __0L7B = __0I7B -1 ;
 memcpy( & __0M7B , &((char*) __0K7B )[ __0L7B * __0H7B + 0 ] , 8 ) ;
 memcpy( & __034B , &((char*) __0K7B )[ __0L7B * __0H7B + 8 ] , 8 ) ;
 ((u64*) stack__dynamic )[1] = __0L7B ;
 __0N7B = __0M7B >= __034B ; 
 __0O7B :
 if(! __0N7B )goto __0P7B ;
 __0Q7B = false ;
 goto __0R7B ;
 __0P7B :
 if(! __0F7B )goto __result__buffer_error ;
 __0S7B = 8 ;
 __0T7B = ((u64*) __0F7B )[1] ;
 if( __034B >= __0T7B )goto __result__buffer_error ;
 memcpy(& __0U7B , &((char*)((void**) __0F7B )[0])[ __034B * __0S7B ], sizeof( f64 )) ;
 __0V7B = __0M7B ;
 __0W7B = __0M7B ;
 __0X7B :
 __0Y7B = __0W7B < __034B ; 
 __0Z7B :
 if(! __0Y7B )goto __0a7B ;
 if(! __0F7B )goto __result__buffer_error ;
 __0S7B = 8 ;
 __0T7B = ((u64*) __0F7B )[1] ;
 if( __0W7B >= __0T7B )goto __result__buffer_error ;
 memcpy(& __0b7B , &((char*)((void**) __0F7B )[0])[ __0W7B * __0S7B ], sizeof( f64 )) ;
 __0c7B = __0b7B < __0U7B ; 
 __0d7B :
 if(! __0c7B )goto __0e7B ;
 if(! __0F7B )goto __result__buffer_error ;
 __0v6B = 8 ;
 __0f7B = ((u64*) __0F7B )[1] ;
 if( __0V7B >= __0f7B )goto __result__buffer_error ;
 memcpy(& __0g7B , &((char*)((void**) __0F7B )[0])[ __0V7B * __0v6B ], sizeof( f64 )) ;
 if(! __0F7B )goto __result__buffer_error ;
 __0v6B = 8 ;
 __0f7B = ((u64*) __0F7B )[1] ;
 if( __0V7B >= __0f7B )goto __result__buffer_error ;
 memcpy(& __0h7B , &((char*)((void**) __0F7B )[0])[ __0V7B * __0v6B ], sizeof( f64 )) ;
 if(! __0F7B )goto __result__buffer_error ;
 __0v6B = 8 ;
 __0f7B = ((u64*) __0F7B )[1] ;
 if( __0W7B >= __0f7B )goto __result__buffer_error ;
 memcpy(& __0i7B , &((char*)((void**) __0F7B )[0])[ __0W7B * __0v6B ], sizeof( f64 )) ;
 if(! __0F7B )goto __result__buffer_error ;
 __0f7B = ((u64*) __0F7B )[1] ;
 __0v6B = 8 ;
 __0j7B = (ptr)(((u64*) __0F7B )[0]) ;
 if( __0V7B >= __0f7B )goto __result__buffer_error ;
 memcpy(&((char*) __0j7B )[ __0V7B * __0v6B ], & __0i7B , sizeof( f64 )) ;
 if(! __0F7B )goto __result__buffer_error ;
 __0v6B = 8 ;
 __0f7B = ((u64*) __0F7B )[1] ;
 if( __0W7B >= __0f7B )goto __result__buffer_error ;
 memcpy(& __0k7B , &((char*)((void**) __0F7B )[0])[ __0W7B * __0v6B ], sizeof( f64 )) ;
 if(! __0F7B )goto __result__buffer_error ;
 __0f7B = ((u64*) __0F7B )[1] ;
 __0v6B = 8 ;
 __0j7B = (ptr)(((u64*) __0F7B )[0]) ;
 if( __0W7B >= __0f7B )goto __result__buffer_error ;
 memcpy(&((char*) __0j7B )[ __0W7B * __0v6B ], & __0g7B , sizeof( f64 )) ;
 __0l7B = 1 ;
 __0m7B = __0V7B + __0l7B ; 
 __0n7B :
 __0V7B = __0m7B ;
 __0e7B :
 __0o7B = 1 ;
 __0p7B = __0W7B + __0o7B ; 
 __0q7B :
 __0W7B = __0p7B ;
 goto __0X7B ;
 __0a7B :
 if(! __0F7B )goto __result__buffer_error ;
 __0r7B = 8 ;
 __0s7B = ((u64*) __0F7B )[1] ;
 if( __0V7B >= __0s7B )goto __result__buffer_error ;
 memcpy(& __0t7B , &((char*)((void**) __0F7B )[0])[ __0V7B * __0r7B ], sizeof( f64 )) ;
 if(! __0F7B )goto __result__buffer_error ;
 __0r7B = 8 ;
 __0s7B = ((u64*) __0F7B )[1] ;
 if( __0V7B >= __0s7B )goto __result__buffer_error ;
 memcpy(& __0u7B , &((char*)((void**) __0F7B )[0])[ __0V7B * __0r7B ], sizeof( f64 )) ;
 if(! __0F7B )goto __result__buffer_error ;
 __0r7B = 8 ;
 __0s7B = ((u64*) __0F7B )[1] ;
 if( __034B >= __0s7B )goto __result__buffer_error ;
 memcpy(& __0l4B , &((char*)((void**) __0F7B )[0])[ __034B * __0r7B ], sizeof( f64 )) ;
 if(! __0F7B )goto __result__buffer_error ;
 __0s7B = ((u64*) __0F7B )[1] ;
 __0r7B = 8 ;
 __0v7B = (ptr)(((u64*) __0F7B )[0]) ;
 if( __0V7B >= __0s7B )goto __result__buffer_error ;
 memcpy(&((char*) __0v7B )[ __0V7B * __0r7B ], & __0l4B , sizeof( f64 )) ;
 if(! __0F7B )goto __result__buffer_error ;
 __0r7B = 8 ;
 __0s7B = ((u64*) __0F7B )[1] ;
 if( __034B >= __0s7B )goto __result__buffer_error ;
 memcpy(& __0w7B , &((char*)((void**) __0F7B )[0])[ __034B * __0r7B ], sizeof( f64 )) ;
 if(! __0F7B )goto __result__buffer_error ;
 __0s7B = ((u64*) __0F7B )[1] ;
 __0r7B = 8 ;
 __0v7B = (ptr)(((u64*) __0F7B )[0]) ;
 if( __034B >= __0s7B )goto __result__buffer_error ;
 memcpy(&((char*) __0v7B )[ __034B * __0r7B ], & __0t7B , sizeof( f64 )) ;
 __0B7B = false ;
 __0x7B = __0B7B ;
 __0y7B = 0 ;
 __0z7B = __0y7B ;
 __007B = 0 ;
 __017B = __007B ;
 __027B = __0V7B > __0M7B ; 
 __037B :
 if(! __027B )goto __047B ;
 __0z7B = __0M7B ;
 __0Y5B = 1 ;
 __0q5B = __0Y5B > __0V7B ; 
 __057B :
 if(! __0q5B )goto __067B ;
 [[unlikely]] goto __077B ;
 __builtin_unreachable();
 __067B :
 __087B = __0V7B - __0Y5B ; 
 __0n4B :
 __017B = __087B ;
 __0k5B = true ;
 __0x7B = __0k5B ;
 __047B :
 __097B = false ;
 __0A8B = __097B ;
 __0A7B = 0 ;
 __0V4B = __0A7B ;
 __0P4B = 0 ;
 __0O4B = __0P4B ;
 __0N4B = __0V7B < __034B ; 
 __0M4B :
 if(! __0N4B )goto __0L4B ;
 __0K4B = 1 ;
 __0J4B = __0V7B + __0K4B ; 
 __0I4B :
 __0V4B = __0J4B ;
 __0O4B = __034B ;
 __0H4B = true ;
 __0A8B = __0H4B ;
 __0L4B :
 if(! __0x7B )goto __0G4B ;
 __0F4B = 1 ;
 __0E4B = __017B + __0F4B ; 
 __0D4B :
 __0C4B = __0z7B > __0E4B ; 
 __0B4B :
 if(! __0C4B )goto __0A4B ;
 [[unlikely]] goto __093B ;
 __builtin_unreachable();
 __0A4B :
 __083B = __0E4B - __0z7B ; 
 __073B :
 __063B = __083B ;
 goto __053B ;
 __0G4B :
 __043B = 0 ;
 __063B = __043B ;
 __053B :
 __033B = 0 ;
 if(! __0A8B )goto __023B ;
 __013B = 1 ;
 __003B = __0O4B + __013B ; 
 __0z3B :
 __0y3B = __0V4B > __003B ; 
 __0x3B :
 if(! __0y3B )goto __0w3B ;
 [[unlikely]] goto __0v3B ;
 __builtin_unreachable();
 __0w3B :
 __0u3B = __003B - __0V4B ; 
 __0t3B :
 __0s3B = __0u3B ;
 goto __0r3B ;
 __023B :
 __0q3B = 0 ;
 __0s3B = __0q3B ;
 __0r3B :
 __0p3B = 0 ;
 __0o3B = __063B < __0s3B ; 
 __0n3B :
 if(! __0o3B )goto __0m3B ;
 if(! __0A8B )goto __0l3B ;
 if(! stack__dynamic )goto __result__buffer_error ;
 __0H7B = 16 ;
 __0I7B = ((u64*) stack__dynamic )[1] ;
 __0J7B = ((u64*) stack__dynamic )[2] & ~(1ULL << 63) ;
 if( __0I7B >= __0J7B ){ if( ((u64*) stack__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __0k3B = __0J7B ;
 __0J7B = __0J7B +( __0J7B >>2)+1; if( __0I7B ) ((void**) stack__dynamic )[0] = __runtime_realloc((u64*)((void**) stack__dynamic )[0],  __0J7B * __0H7B , __0k3B * __0H7B ) ;
 else ((void**) stack__dynamic )[0] = __runtime_alloc( __0J7B * __0H7B ) ;
 ((u64*) stack__dynamic )[2] = __0J7B ;
 __0K7B = (ptr)((void**) stack__dynamic )[0] ;
 if(! __0K7B )goto __result__buffer_error ;
 } else  __0K7B = (ptr)(((u64*) stack__dynamic )[0]) ;
 ((u64*) stack__dynamic )[1] = __0I7B +1 ;
 memcpy( &((char*) __0K7B )[ __0I7B * __0H7B + 0 ] , & __0V4B , 8 ) ;
 memcpy( &((char*) __0K7B )[ __0I7B * __0H7B + 8 ] , & __0O4B , 8 ) ;
 __0l3B :
 if(! __0x7B )goto __0j3B ;
 if(! stack__dynamic )goto __result__buffer_error ;
 __0H7B = 16 ;
 __0I7B = ((u64*) stack__dynamic )[1] ;
 __0J7B = ((u64*) stack__dynamic )[2] & ~(1ULL << 63) ;
 if( __0I7B >= __0J7B ){ if( ((u64*) stack__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __0k3B = __0J7B ;
 __0J7B = __0J7B +( __0J7B >>2)+1; if( __0I7B ) ((void**) stack__dynamic )[0] = __runtime_realloc((u64*)((void**) stack__dynamic )[0],  __0J7B * __0H7B , __0k3B * __0H7B ) ;
 else ((void**) stack__dynamic )[0] = __runtime_alloc( __0J7B * __0H7B ) ;
 ((u64*) stack__dynamic )[2] = __0J7B ;
 __0K7B = (ptr)((void**) stack__dynamic )[0] ;
 if(! __0K7B )goto __result__buffer_error ;
 } else  __0K7B = (ptr)(((u64*) stack__dynamic )[0]) ;
 ((u64*) stack__dynamic )[1] = __0I7B +1 ;
 memcpy( &((char*) __0K7B )[ __0I7B * __0H7B + 0 ] , & __0z7B , 8 ) ;
 memcpy( &((char*) __0K7B )[ __0I7B * __0H7B + 8 ] , & __017B , 8 ) ;
 goto __0i3B ;
 __0j3B :
 if(! __0x7B )goto __0X4B ;
 if(! stack__dynamic )goto __result__buffer_error ;
 __0H7B = 16 ;
 __0I7B = ((u64*) stack__dynamic )[1] ;
 __0J7B = ((u64*) stack__dynamic )[2] & ~(1ULL << 63) ;
 if( __0I7B >= __0J7B ){ if( ((u64*) stack__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __0k3B = __0J7B ;
 __0J7B = __0J7B +( __0J7B >>2)+1; if( __0I7B ) ((void**) stack__dynamic )[0] = __runtime_realloc((u64*)((void**) stack__dynamic )[0],  __0J7B * __0H7B , __0k3B * __0H7B ) ;
 else ((void**) stack__dynamic )[0] = __runtime_alloc( __0J7B * __0H7B ) ;
 ((u64*) stack__dynamic )[2] = __0J7B ;
 __0K7B = (ptr)((void**) stack__dynamic )[0] ;
 if(! __0K7B )goto __result__buffer_error ;
 } else  __0K7B = (ptr)(((u64*) stack__dynamic )[0]) ;
 ((u64*) stack__dynamic )[1] = __0I7B +1 ;
 memcpy( &((char*) __0K7B )[ __0I7B * __0H7B + 0 ] , & __0z7B , 8 ) ;
 memcpy( &((char*) __0K7B )[ __0I7B * __0H7B + 8 ] , & __017B , 8 ) ;
 __0X4B :
 if(! __0A8B )goto __0h3B ;
 if(! stack__dynamic )goto __result__buffer_error ;
 __0H7B = 16 ;
 __0I7B = ((u64*) stack__dynamic )[1] ;
 __0J7B = ((u64*) stack__dynamic )[2] & ~(1ULL << 63) ;
 if( __0I7B >= __0J7B ){ if( ((u64*) stack__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __0k3B = __0J7B ;
 __0J7B = __0J7B +( __0J7B >>2)+1; if( __0I7B ) ((void**) stack__dynamic )[0] = __runtime_realloc((u64*)((void**) stack__dynamic )[0],  __0J7B * __0H7B , __0k3B * __0H7B ) ;
 else ((void**) stack__dynamic )[0] = __runtime_alloc( __0J7B * __0H7B ) ;
 ((u64*) stack__dynamic )[2] = __0J7B ;
 __0K7B = (ptr)((void**) stack__dynamic )[0] ;
 if(! __0K7B )goto __result__buffer_error ;
 } else  __0K7B = (ptr)(((u64*) stack__dynamic )[0]) ;
 ((u64*) stack__dynamic )[1] = __0I7B +1 ;
 memcpy( &((char*) __0K7B )[ __0I7B * __0H7B + 0 ] , & __0V4B , 8 ) ;
 memcpy( &((char*) __0K7B )[ __0I7B * __0H7B + 8 ] , & __0O4B , 8 ) ;
 __0h3B :
 __0g3B = true ;
 goto __0R7B ;
 __0i3B :
 __0m3B :
 __0R7B :
 arr__dynamic = __0F7B ;
 arr__surface = __0G7B ;
 goto __0C7B ;
 __0E7B :
 __0f3B = __smo_time_eta (); 
 __0e3B :
 __0d3B = __0f3B - __0w6B ; 
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
 if( arr__dynamic ){if((u64*)((u64*) arr__dynamic )[2]) __runtime_free((u64*)((u64*) arr__dynamic )[0]) ;
 __runtime_free( arr__dynamic ) ;
 arr__dynamic = 0 ;
 } goto __0P6B ;
 __0X6B :
 __0V3B = 1000.0 ;
 __0U3B = __0U5B ;
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
__0v3B :
 printf ( "Error: unsigned subtraction yielded a negative\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__093B :
 printf ( "Error: unsigned subtraction yielded a negative\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__077B :
 printf ( "Error: unsigned subtraction yielded a negative\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__result__buffer_pop_error :
printf("Buffer error\n");
__result__error_code=__BUFFER__ERROR;
goto __failsafe;
__036B :
 printf ( "Error: unsigned subtraction yielded a negative\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__result__buffer_error :
printf("Buffer error\n");
__result__error_code=__BUFFER__ERROR;
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
if( __09xB__dynamic ){if((u64*)((u64*) __09xB__dynamic )[2]) __runtime_free((u64*)((u64*) __09xB__dynamic )[0]) ;
 __runtime_free( __09xB__dynamic ) ;
 __09xB__dynamic = 0 ;
 }
 

 

 

 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__error_code;
}



int main() {
struct main__374__state __main_args={0};
__smolambda_initialize_service_tasks(main__374, &__main_args);
return __main_args.err;
}

