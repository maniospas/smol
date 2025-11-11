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

#include<string.h>

#include<stdlib.h>

#include<stdio.h>

struct main__354__state{errcode err;};
__externc void main__354(void *__void__state);

void main__354(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1636;
struct main__354__state *__state=(struct main__354__state*)__void__state;
ptr __CrB=0;
u64 __7qB=0;
char __6qB=0;
u64 __5qB=0;
u64 __4qB=0;
u64 __3qB=0;
ptr __2qB=0;
ptr __1qB=0;
char __0qB=0;
ptr __zqB=0;
cstr __xqB=0;
ptr __DrB=0;
ptr __wqB=0;
ptr __vqB=0;
char __uqB=0;
ptr __tqB=0;
u64 __sqB=0;
cstr __rqB=0;
cstr __qqB=0;
bool __pqB=0;
nominal __oqB=0;
u64 __nqB=0;
u64 __mqB=0;
ptr mem__mem=0;
cstr __kqB=0;
nominal __FrB=0;
bool __hqB=0;
u64 __yqB=0;
ptr mem__underlying=0;
cstr __fqB=0;
bool __cqB=0;
u64 __bqB=0;
u64 __aqB=0;
bool __ZqB=0;
u64 arn____6i__length=0;
cstr __QqB=0;
nominal arn____6i__type=0;
ptr __ZmB__mem=0;
u64 __8qB=0;
u64 mem__size=0;
ptr arn____6i__contents__mem=0;
u64 arn____6i__contents__size=0;
u64 __TpB=0;
char __RpB=0;
u64 __OpB=0;
u64 __NpB=0;
nominal arn____6i__contents__type=0;
u64 __MpB=0;
char __LpB=0;
u64 __KpB=0;
u64 __JpB=0;
ptr arn____6i__contents__underlying=0;
u64 __HpB=0;
bool __GpB=0;
cstr __DpB=0;
ptr __BpB=0;
u64 __ApB=0;
ptr __9oB=0;
ptr __PpB=0;
nominal __8oB=0;
ptr __SpB=0;
nominal __7oB=0;
u64 __dpB=0;
ptr __QpB=0;

// IMPLEMENTATION
__aqB = 50 ;
 __bqB = 0 ;
 __cqB =( __aqB == __bqB ); 
 __dqB :
 if(! __cqB )goto __eqB ;
 __fqB = "Cannot allocate zero size" ;
 goto __gqB ;
 __builtin_unreachable();
 __eqB :
 __ZmB__mem = __runtime_alloc ( __aqB ); 
 __hqB = __ZmB__mem ;
 __ZqB =(! __hqB ); 
 __iqB :
 if(! __ZqB )goto __jqB ;
 __kqB = "Failed a Heap allocation" ;
 goto __lqB ;
 __builtin_unreachable();
 __jqB :
 mem__size = __aqB ;
 mem__mem = __ZmB__mem ;
 mem__underlying = __ZmB__mem ;
 __mqB = 0 ;
 arn____6i__contents__size = mem__size ;
 arn____6i__contents__mem = mem__mem ;
 arn____6i__contents__underlying = mem__underlying ;
 arn____6i__length = __mqB ;
 __qqB = "1234" ;
 __rqB = "567" ;
 __sqB = strlen ( __qqB ); __tqB =( ptr ) __qqB ; __uqB = __qqB [0]; __vqB =0; 
 __wqB = __tqB ;
 __yqB = strlen ( __rqB ); __zqB =( ptr ) __rqB ; __0qB = __rqB [0]; __1qB =0; 
 __2qB = __zqB ;
 __3qB = __sqB ; __4qB = __yqB ; __5qB = __3qB + __4qB ; __6qB = __sqB ? __uqB : __0qB ; 
 __7qB = 1 ;
 __8qB = __5qB + __7qB ; 
 __9qB :
 __nqB = __8qB ;
 __pqB = __nqB > arn____6i__contents__size ; 
 __PqB :
 if(! __pqB )goto __ArB ;
 __QqB = "Failed an Circular allocation" ;
 goto __BrB ;
 __builtin_unreachable();
 __ArB :
 if ( arn____6i__length + __nqB > arn____6i__contents__size ) { arn____6i__length =0; } 
 __CrB =( ptr )(( char *) arn____6i__contents__mem + arn____6i__length * sizeof ( char )); 
 arn____6i__length = arn____6i__length + __nqB ; 
 __dpB = __nqB ;
 __nqB = __dpB ;
 memcpy (( char *) __CrB ,( char *) __wqB , __3qB ); memcpy (( char *) __CrB + __3qB ,( char *) __2qB , __4qB );(( char *) __CrB )[ __5qB ]=0; 
 __DrB = __CrB ;
 arn____6i__type = __FrB ;
 arn____6i__contents__type = __oqB ;
 arn____6i__contents__size = arn____6i__contents__size ;
 arn____6i__contents__mem = arn____6i__contents__mem ;
 arn____6i__contents__underlying = arn____6i__contents__underlying ;
 arn____6i__length = arn____6i__length ;
 __xqB = "aa" ;
 __TpB = strlen ( __xqB ); __SpB =( ptr ) __xqB ; __RpB = __xqB [0]; __QpB =0; 
 __PpB = __SpB ;
 __OpB = __TpB ; __NpB = __5qB ; __MpB = __OpB + __NpB ; __LpB = __TpB ? __RpB : __6qB ; 
 __KpB = 1 ;
 __JpB = __MpB + __KpB ; 
 __IpB :
 __HpB = __JpB ;
 __GpB = __HpB > arn____6i__contents__size ; 
 __FpB :
 if(! __GpB )goto __EpB ;
 __DpB = "Failed an Circular allocation" ;
 goto __CpB ;
 __builtin_unreachable();
 __EpB :
 if ( arn____6i__length + __HpB > arn____6i__contents__size ) { arn____6i__length =0; } 
 __BpB =( ptr )(( char *) arn____6i__contents__mem + arn____6i__length * sizeof ( char )); 
 arn____6i__length = arn____6i__length + __HpB ; 
 __ApB = __HpB ;
 __HpB = __ApB ;
 memcpy (( char *) __BpB ,( char *) __PpB , __OpB ); memcpy (( char *) __BpB + __OpB ,( char *) __DrB , __NpB );(( char *) __BpB )[ __MpB ]=0; 
 __9oB = __BpB ;
 arn____6i__type = __8oB ;
 arn____6i__contents__type = __7oB ;
 arn____6i__contents__size = arn____6i__contents__size ;
 arn____6i__contents__mem = arn____6i__contents__mem ;
 arn____6i__contents__underlying = arn____6i__contents__underlying ;
 arn____6i__length = arn____6i__length ;
 printf ( "%llu\n" ,( unsigned long long ) __MpB ); 
 __6oB :
 printf ( "%.*s\n" ,( int ) __MpB ,( char *) __9oB ); 
 __5oB :
 __4oB :
goto __return;

// ERROR HANDLING
__BrB :
 printf ( "%s\n" , __QqB ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__CpB :
 printf ( "%s\n" , __DpB ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__gqB :
 printf ( "%s\n" , __fqB ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__lqB :
 printf ( "%s\n" , __kqB ); 
__result__error_code=__USER__ERROR;
goto __failsafe;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
if ( __ZmB__mem ) __runtime_free ( __ZmB__mem ); __ZmB__mem =0; 
__state->err =  __result__error_code;
}



int main() {
struct main__354__state __main_args={0};
__smolambda_initialize_service_tasks(main__354, &__main_args);
return __main_args.err;
}

