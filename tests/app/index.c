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

struct main__364__state{errcode err;};
__externc void main__364(void *__void__state);

void main__364(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1852;
struct main__364__state *__state=(struct main__364__state*)__void__state;
ptr __ErB=0;
u64 __6qB=0;
u64 __4qB=0;
ptr __3qB=0;
ptr segments__dynamic=0;
ptr __2qB=0;
char __1qB=0;
ptr __0qB=0;
u64 __zqB=0;
cstr __yqB=0;
ptr __xqB=0;
char __rqB=0;
char __hqB=0;
u64 __fqB=0;
ptr __YkB__dynamic=0;
ptr __cqB=0;
ptr __YqB=0;
u64 __WqB=0;
u64 __KqB=0;
cstr __PrB=0;
char __NrB=0;
ptr __OrB=0;
u64 __HrB=0;
ptr __KrB=0;
ptr __FrB=0;
bool __IrB=0;
cstr __GrB=0;
ptr __9qB=0;
u64 __CrB=0;
u64 __7qB=0;
bool __upB=0;
cstr __ArB=0;
u64 __LrB=0;
u64 __8qB=0;
ptr __JrB=0;
ptr __MrB=0;
u64 __PpB=0;
ptr __OpB=0;
ptr __NpB=0;
u64 __MpB=0;
u64 __KpB=0;
u64 __JpB=0;
u64 __IpB=0;
u64 __GpB=0;
u64 __FpB=0;
u64 __EpB=0;
u64 __DpB=0;
u64 __CpB=0;
bool __ApB=0;
u64 __7oB=0;
u64 __6oB=0;
ptr __5oB=0;
u64 __4oB=0;
char __3oB=0;
ptr __2oB=0;
ptr __0oB=0;
u64 __zoB=0;
char __yoB=0;
ptr __xoB=0;
cstr __woB=0;
u64 __voB=0;
ptr __uoB=0;
char __toB=0;
ptr __soB=0;
ptr __roB=0;
u64 __qoB=0;
u64 __poB=0;
u64 __ooB=0;
char __noB=0;
u64 __moB=0;
u64 __loB=0;
u64 __joB=0;
u64 __ioB=0;
bool __goB=0;
cstr __doB=0;
ptr __boB=0;
u64 __aoB=0;
ptr __ZoB=0;
nominal __YoB=0;
nominal __XoB=0;
nominal __WoB=0;
nominal __VoB=0;
u64 __UoB=0;
u64 __ToB=0;
u64 __SoB=0;
char __RoB=0;
u64 __QoB=0;
u64 __PoB=0;
u64 __NoB=0;
u64 __MoB=0;
bool __KoB=0;
cstr __HoB=0;
ptr __TpB=0;
ptr __FoB=0;
u64 __EoB=0;
ptr __DoB=0;
nominal __CoB=0;
nominal __BoB=0;
ptr __AoB=0;
u64 __LpB=0;

// IMPLEMENTATION
__YkB__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 __xqB = 0 ;
 __yqB = "I think." ;
 __zqB = strlen ( __yqB ); __0qB =( ptr ) __yqB ; __1qB = __yqB [0]; __2qB =( ptr ) __2qB ; 
 __3qB = __0qB ;
 if(! __YkB__dynamic )goto __result__buffer_error ;
 __4qB = 13 ;
 __6qB = ((u64*) __YkB__dynamic )[1] ;
 __7qB = ((u64*) __YkB__dynamic )[2] & ~(1ULL << 63) ;
 if( __6qB >= __7qB ){ if( ((u64*) __YkB__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __8qB = __7qB ;
 __7qB = __7qB +( __7qB >>2)+1; if( __6qB ) ((void**) __YkB__dynamic )[0] = __runtime_realloc((u64*)((void**) __YkB__dynamic )[0],  __7qB * __4qB , __8qB * __4qB ) ;
 else ((void**) __YkB__dynamic )[0] = __runtime_alloc( __7qB * __4qB ) ;
 ((u64*) __YkB__dynamic )[2] = __7qB ;
 __9qB = (ptr)((void**) __YkB__dynamic )[0] ;
 if(! __9qB )goto __result__buffer_error ;
 } else  __9qB = (ptr)(((u64*) __YkB__dynamic )[0]) ;
 ((u64*) __YkB__dynamic )[1] = __6qB +1 ;
 memcpy(&((char*) __9qB )[ __6qB * __4qB +0], & __3qB , sizeof(ptr)); 
 memcpy(&((char*) __9qB )[ __6qB * __4qB +4], & __zqB , sizeof(u64)); 
 memcpy(&((char*) __9qB )[ __6qB * __4qB +8], & __1qB , sizeof(char)); 
 memcpy(&((char*) __9qB )[ __6qB * __4qB +9], & __2qB , sizeof(ptr)); 
 

 __ArB = "Therefore I am." ;
 __CrB = strlen ( __ArB ); __YqB =( ptr ) __ArB ; __rqB = __ArB [0]; __ErB =( ptr ) __ErB ; 
 __FrB = __YqB ;
 if(! __YkB__dynamic )goto __result__buffer_error ;
 __4qB = 13 ;
 __6qB = ((u64*) __YkB__dynamic )[1] ;
 __7qB = ((u64*) __YkB__dynamic )[2] & ~(1ULL << 63) ;
 if( __6qB >= __7qB ){ if( ((u64*) __YkB__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 __8qB = __7qB ;
 __7qB = __7qB +( __7qB >>2)+1; if( __6qB ) ((void**) __YkB__dynamic )[0] = __runtime_realloc((u64*)((void**) __YkB__dynamic )[0],  __7qB * __4qB , __8qB * __4qB ) ;
 else ((void**) __YkB__dynamic )[0] = __runtime_alloc( __7qB * __4qB ) ;
 ((u64*) __YkB__dynamic )[2] = __7qB ;
 __9qB = (ptr)((void**) __YkB__dynamic )[0] ;
 if(! __9qB )goto __result__buffer_error ;
 } else  __9qB = (ptr)(((u64*) __YkB__dynamic )[0]) ;
 ((u64*) __YkB__dynamic )[1] = __6qB +1 ;
 memcpy(&((char*) __9qB )[ __6qB * __4qB +0], & __FrB , sizeof(ptr)); memcpy(&((char*) __9qB )[ __6qB * __4qB +4], & __CrB , sizeof(u64)); memcpy(&((char*) __9qB )[ __6qB * __4qB +8], & __rqB , sizeof(char)); memcpy(&((char*) __9qB )[ __6qB * __4qB +9], & __ErB , sizeof(ptr)); segments__dynamic = __YkB__dynamic ;
 __GrB = "" ;
 __HrB = strlen ( __GrB ); __JrB =( ptr ) __GrB ; __hqB = __GrB [0]; __KrB =( ptr ) __KrB ; 
 __TpB = __JrB ;
 __cqB = __TpB ;
 __LrB = __HrB ;
 __NrB = __hqB ;
 __OrB = __KrB ;
 __fqB = 1024 ;
 __WqB = __fqB ; __MrB =( __WqB + __service_stack_floor >=( char *)& __WqB )?0: alloca ( __WqB ); 
 __IrB = __MrB ;
 __upB =(! __IrB ); 
 __DrB :
 if(! __upB )goto __5qB ;
 __PrB = "Insufficient stack for allocation (too much recursion or stack allocation, or zero size requested)" ;
 goto __BrB ;
 __builtin_unreachable();
 __5qB :
 __KqB = 0 ;
 __PpB = __fqB ;
 __OpB = __MrB ;
 __NpB = __MrB ;
 __MpB = __KqB ;
 __LpB = segments__dynamic ? ((u64*) segments__dynamic )[1]:0 ;
 __KpB = 0 ;
 __JpB = 1 ;
 __IpB = __KpB ;
 __HpB :
 __GpB = __IpB ;
 __FpB = __EpB ;
 __FpB = __GpB ;
 __DpB = 1 ;
 __CpB = __GpB + __DpB ; 
 __BpB :
 __GpB = __CpB ;
 __ApB = __GpB <= __LpB ; 
 __9oB :
 __IpB = __GpB ;
 if(! __ApB )goto __8oB ;
 if(! segments__dynamic )goto __result__buffer_error ;
 __7oB = 13 ;
 __6oB = ((u64*) segments__dynamic )[1] ;
 if( __FpB >= __6oB )goto __result__buffer_error ;
 memcpy(& __5oB , &((char*)((void**) segments__dynamic )[0])[ __FpB * __7oB +0], sizeof( ptr )) ;
 memcpy(& __4oB , &((char*)((void**) segments__dynamic )[0])[ __FpB * __7oB +4], sizeof( u64 )) ;
 memcpy(& __3oB , &((char*)((void**) segments__dynamic )[0])[ __FpB * __7oB +8], sizeof( char )) ;
 memcpy(& __2oB , &((char*)((void**) segments__dynamic )[0])[ __FpB * __7oB +9], sizeof( ptr )) ;
 printf ( "%lu\n" , __4oB ); 
 __1oB :
 if(! segments__dynamic )goto __result__buffer_error ;
 __7oB = 13 ;
 __6oB = ((u64*) segments__dynamic )[1] ;
 if( __FpB >= __6oB )goto __result__buffer_error ;
 memcpy(& __0oB , &((char*)((void**) segments__dynamic )[0])[ __FpB * __7oB +0], sizeof( ptr )) ;
 memcpy(& __zoB , &((char*)((void**) segments__dynamic )[0])[ __FpB * __7oB +4], sizeof( u64 )) ;
 memcpy(& __yoB , &((char*)((void**) segments__dynamic )[0])[ __FpB * __7oB +8], sizeof( char )) ;
 memcpy(& __xoB , &((char*)((void**) segments__dynamic )[0])[ __FpB * __7oB +9], sizeof( ptr )) ;
 __woB = " " ;
 __voB = strlen ( __woB ); __uoB =( ptr ) __woB ; __toB = __woB [0]; __soB =( ptr ) __soB ; 
 __roB = __uoB ;
 __qoB = __zoB ; __poB = __voB ; __ooB = __qoB + __poB ; __noB = __zoB ? __yoB : __toB ; 
 __moB = 1 ;
 __loB = __ooB + __moB ; 
 __koB :
 __joB = __loB ;
 __ioB = __MpB + __joB ; 
 __hoB :
 __goB = __ioB > __PpB ; 
 __foB :
 if(! __goB )goto __eoB ;
 __doB = "Failed an Arena allocation" ;
 goto __coB ;
 __builtin_unreachable();
 __eoB :
 __boB =( ptr )(( char *) __OpB + __MpB * sizeof ( char )); 
 __MpB = __MpB + __joB ; 
 __aoB = __joB ;
 __joB = __aoB ;
 memcpy (( char *) __boB ,( char *) __0oB , __qoB ); memcpy (( char *) __boB + __qoB ,( char *) __roB , __poB );(( char *) __boB )[ __ooB ]=0; 
 __ZoB = __boB ;
 __YoB = __XoB ;
 __WoB = __VoB ;
 __UoB = __LrB ; __ToB = __ooB ; __SoB = __UoB + __ToB ; __RoB = __LrB ? __NrB : __noB ; 
 __QoB = 1 ;
 __PoB = __SoB + __QoB ; 
 __OoB :
 __NoB = __PoB ;
 __MoB = __MpB + __NoB ; 
 __LoB :
 __KoB = __MoB > __PpB ; 
 __JoB :
 if(! __KoB )goto __IoB ;
 __HoB = "Failed an Arena allocation" ;
 goto __GoB ;
 __builtin_unreachable();
 __IoB :
 __FoB =( ptr )(( char *) __OpB + __MpB * sizeof ( char )); 
 __MpB = __MpB + __NoB ; 
 __EoB = __NoB ;
 __NoB = __EoB ;
 memcpy (( char *) __FoB ,( char *) __cqB , __UoB ); memcpy (( char *) __FoB + __UoB ,( char *) __ZoB , __ToB );(( char *) __FoB )[ __SoB ]=0; 
 __DoB = __FoB ;
 __YoB = __CoB ;
 __WoB = __BoB ;
 __cqB = __DoB ;
 __LrB = __SoB ;
 __NrB = __RoB ;
 __OrB = __NpB ;
 goto __HpB ;
 __8oB :
 __TRANSIENT( __OpB )
 __AoB = __cqB ;
 printf ( "%.*s\n" ,( int ) __LrB ,( char *) __AoB ); 
 __9nB :
 __8nB :
goto __return;

// ERROR HANDLING
__coB :
 printf ( "%s\n" , __doB ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__BrB :
 printf ( "%s\n" , __PrB ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__result__buffer_error :
printf("Buffer error\n");
__result__error_code=__BUFFER__ERROR;
goto __failsafe;
__GoB :
 printf ( "%s\n" , __HoB ); 
__result__error_code=__USER__ERROR;
goto __failsafe;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
if( __YkB__dynamic ){if((u64*)((u64*) __YkB__dynamic )[2]) __runtime_free((u64*)((u64*) __YkB__dynamic )[0]) ;
 __runtime_free( __YkB__dynamic ) ;
 __YkB__dynamic = 0 ;
 }__state->err =  __result__error_code;
}



int main() {
struct main__364__state __main_args={0};
__smolambda_initialize_service_tasks(main__364, &__main_args);
return __main_args.err;
}

