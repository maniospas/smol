#define SMOLAMBDA_SERVICES 1
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
#define __builtin_assume(cond) do { if (!(cond)) __builtin_unreachable(); } while (0)
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

struct main__870__state{errcode err;};
void main__870(void *__void__state);

void main__870(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__870__state *__state=(struct main__870__state*)__void__state;
f64 __AIB____OHB__value=0;
cstr __AIB____OHB____lBB=0;
bool __AIB____JHB____2D__z=0;
u64 __AIB____HHB____xD=0;
cstr __AIB____FHB=0;
bool __AIB____DHB__z=0;
u64 __AIB____CHB=0;
u64 __9HB__i=0;
f64 __9HB____pEB____QT=0;
ptr __9HB____pEB___contents=0;
cstr __9HB____pEB____LT=0;
bool __8HB____hHB____oBB__z=0;
cstr __AIB____MHB=0;
bool __8HB____eHB____e9____2D__z=0;
u64 __1HB____QW____oO=0;
cstr __AIB____UHB=0;
f64 __9HB____pEB____HT=0;
u64 __AIB____EHB=0;
u64 __7HB=0;
bool __AIB____RHB__z=0;
bool __1HB____PW____ZI____0F=0;
u64 __1HB____PW____ZI____uF=0;
u64 __4HB=0;
char __1HB____PW____ZI____yF=0;
u64 __8HB____eHB____b9____JT__x=0;
u64 __8HB____eHB____b9____JT__z=0;
u64 __8HB____eHB____c9____xD=0;
cstr __1HB____PW____ZI____2F=0;
u64 __5HB____eHB____c9____xD=0;
cstr __9HB____lEB=0;
u64 __0HB=0;
bool __1HB____PW____ZI____vF__z=0;
cstr __1HB____PW____ZI____wF=0;
ptr __1HB____PW____ZI__mem=0;
bool __1HB____PW____ZI____1F__z=0;
u64 __3HB=0;
bool __5HB____eHB____e9____2D__z=0;
u64 __5HB____eHB____b9__size=0;
f64 __5HB____eHB____b9____HT=0;
u64 __5HB____eHB____b9____JT__x=0;
ptr __9HB____sEB__contents=0;
u64 __5HB____eHB____b9____JT__z=0;
bool __5HB____eHB____b9____KT__z=0;
cstr __5HB____eHB____b9____LT=0;
f64 __5HB____gHB=0;
ptr __5HB____eHB____b9___contents=0;
f64 __5HB____eHB____b9____QT=0;
cstr __8HB____hHB____pBB=0;
cstr __AIB____SHB=0;
bool __5HB____hHB____oBB__z=0;
cstr __5HB____hHB____pBB=0;
u64 __9HB____pEB__size=0;
ptr __5HB____hHB__contents=0;
u64 __6HB=0;
u64 __8HB____eHB____b9__size=0;
f64 __8HB____eHB____b9____HT=0;
bool __8HB____eHB____b9____KT__z=0;
bool __AIB____OHB____kBB__z=0;
cstr __8HB____eHB____b9____LT=0;
ptr __8HB____eHB____b9___contents=0;
f64 __8HB____eHB____b9____QT=0;
f64 __8HB____gHB=0;
ptr __8HB____hHB__contents=0;
bool __9HB____kEB__z=0;
u64 __9HB__size=0;
u64 __9HB____pEB____JT__x=0;
u64 __9HB____pEB____JT__z=0;
bool __9HB____pEB____KT__z=0;

// IMPLEMENTATION
goto __zHB____end ;
 __zHB____end :
 __0HB = 1024 ;
 goto __1HB____PW____WI____end ;
 __1HB____PW____WI____end :
 __1HB____PW____ZI____uF = 0 ;
 __1HB____PW____ZI____vF__z =( __0HB == __1HB____PW____ZI____uF ); 
 goto __1HB____PW____ZI____vF____end ;
 __1HB____PW____ZI____vF____end :
 if(! __1HB____PW____ZI____vF__z )goto __1HB____PW____ZI____tF__fi ;
 __1HB____PW____ZI____wF = "Cannot allocate zero size" ;
 goto __1HB____PW____ZI____xF____pD ;
 __builtin_unreachable();
 __1HB____PW____ZI____xF____end :
 goto __1HB____PW____ZI____tF__if ;
 __1HB____PW____ZI____tF__if :
 __1HB____PW____ZI____tF__fi :
 __1HB____PW____ZI__mem = alloca ( __0HB * sizeof ( __1HB____PW____ZI____yF )); 
 __1HB____PW____ZI____0F = __1HB____PW____ZI__mem ;
 __1HB____PW____ZI____1F__z =(! __1HB____PW____ZI____0F ); 
 goto __1HB____PW____ZI____1F____end ;
 __1HB____PW____ZI____1F____end :
 if(! __1HB____PW____ZI____1F__z )goto __1HB____PW____ZI____zF__fi ;
 __1HB____PW____ZI____2F = "Failed a Stack allocation" ;
 goto __1HB____PW____ZI____3F____pD ;
 __builtin_unreachable();
 __1HB____PW____ZI____3F____end :
 goto __1HB____PW____ZI____zF__if ;
 __1HB____PW____ZI____zF__if :
 __1HB____PW____ZI____zF__fi :
 goto __1HB____PW____ZI____7F____end ;
 __1HB____PW____ZI____7F____end :
 __1HB____PW____ZI____AG____end :
 goto __1HB____PW____ZI____end ;
 __1HB____PW____ZI____end :
 goto __1HB____PW____end ;
 __1HB____PW____end :
 __1HB____QW____oO = 0 ;
 goto __1HB____QW____tO____end ;
 __1HB____QW____tO____end :
 goto __1HB____QW____pO__with ;
 __1HB____QW____pO__with :
 goto __1HB____QW____end ;
 __1HB____QW____end :
 goto __1HB____end ;
 __1HB____end :
 __3HB = 1 ;
 __4HB = 10 ;
 __5HB____eHB____b9__size = __4HB * sizeof ( __5HB____eHB____b9____HT ); 
 __5HB____eHB____b9____JT__x = __1HB____QW____oO ;
 __5HB____eHB____b9____JT__z = __5HB____eHB____b9____JT__x + __5HB____eHB____b9__size ; 
 goto __5HB____eHB____b9____JT____end ;
 __5HB____eHB____b9____JT____end :
 __5HB____eHB____b9____KT__z = __5HB____eHB____b9____JT__z > __0HB ; 
 goto __5HB____eHB____b9____KT____end ;
 __5HB____eHB____b9____KT____end :
 if(! __5HB____eHB____b9____KT__z )goto __5HB____eHB____b9____IT__fi ;
 __5HB____eHB____b9____LT = "Failed an Arena allocation" ;
 goto __5HB____eHB____b9____MT____pD ;
 __builtin_unreachable();
 __5HB____eHB____b9____MT____end :
 goto __5HB____eHB____b9____IT__if ;
 __5HB____eHB____b9____IT__if :
 __5HB____eHB____b9____IT__fi :
 __5HB____eHB____b9___contents =( ptr )(( char *) __1HB____PW____ZI__mem + __1HB____QW____oO * sizeof ( char )); 
 __1HB____QW____oO = __1HB____QW____oO + __5HB____eHB____b9__size ; 
 __5HB____eHB____b9____QT = 0 ;
 __5HB____eHB____b9____ST____end :
 goto __5HB____eHB____b9____end ;
 __5HB____eHB____b9____end :
 __5HB____eHB____c9____xD = 0 ;
 goto __5HB____eHB____c9____zD____end ;
 __5HB____eHB____c9____zD____end :
 goto __5HB____eHB____c9____end ;
 __5HB____eHB____c9____end :
 __5HB____eHB____d9__loop :
 __5HB____eHB____e9____1D____end :
 __5HB____eHB____e9____2D__z = __5HB____eHB____c9____xD <= __4HB ; 
 goto __5HB____eHB____e9____2D____end ;
 __5HB____eHB____e9____2D____end :
 goto __5HB____eHB____e9____end ;
 __5HB____eHB____e9____end :
 if(! __5HB____eHB____e9____2D__z )goto __5HB____eHB____d9__while ;
 (( f64 *) __5HB____eHB____b9___contents )[ __5HB____eHB____c9____xD ]=0; 
 goto __5HB____eHB____d9__loop ;
 __5HB____eHB____d9__while :
 goto __5HB____eHB____h9____end ;
 __5HB____eHB____h9____end :
 goto __5HB____eHB____end ;
 __5HB____eHB____end :
 __5HB____gHB = 1.0 ;
 __5HB____hHB____oBB__z = __3HB >= __4HB ; 
 goto __5HB____hHB____oBB____end ;
 __5HB____hHB____oBB____end :
 if(! __5HB____hHB____oBB__z )goto __5HB____hHB____nBB__fi ;
 __5HB____hHB____pBB = "Vec out of bounds" ;
 goto __5HB____hHB____qBB____pD ;
 __builtin_unreachable();
 __5HB____hHB____qBB____end :
 goto __5HB____hHB____nBB__if ;
 __5HB____hHB____nBB__if :
 __5HB____hHB____nBB__fi :
 (( f64 *) __5HB____eHB____b9___contents )[ __3HB ]= __5HB____gHB ; 
 __5HB____hHB__contents = __5HB____eHB____b9___contents ;
 goto __5HB____hHB____end ;
 __5HB____hHB____end :
 goto __5HB____fHB__on ;
 __5HB____fHB__on :
 goto __5HB____end ;
 __5HB____end :
 __6HB = 1 ;
 __7HB = 10 ;
 __8HB____eHB____b9__size = __7HB * sizeof ( __8HB____eHB____b9____HT ); 
 __8HB____eHB____b9____JT__x = __1HB____QW____oO ;
 __8HB____eHB____b9____JT__z = __8HB____eHB____b9____JT__x + __8HB____eHB____b9__size ; 
 goto __8HB____eHB____b9____JT____end ;
 __8HB____eHB____b9____JT____end :
 __8HB____eHB____b9____KT__z = __8HB____eHB____b9____JT__z > __0HB ; 
 goto __8HB____eHB____b9____KT____end ;
 __8HB____eHB____b9____KT____end :
 if(! __8HB____eHB____b9____KT__z )goto __8HB____eHB____b9____IT__fi ;
 __8HB____eHB____b9____LT = "Failed an Arena allocation" ;
 goto __8HB____eHB____b9____MT____pD ;
 __builtin_unreachable();
 __8HB____eHB____b9____MT____end :
 goto __8HB____eHB____b9____IT__if ;
 __8HB____eHB____b9____IT__if :
 __8HB____eHB____b9____IT__fi :
 __8HB____eHB____b9___contents =( ptr )(( char *) __1HB____PW____ZI__mem + __1HB____QW____oO * sizeof ( char )); 
 __1HB____QW____oO = __1HB____QW____oO + __8HB____eHB____b9__size ; 
 __8HB____eHB____b9____QT = 0 ;
 __8HB____eHB____b9____ST____end :
 goto __8HB____eHB____b9____end ;
 __8HB____eHB____b9____end :
 __8HB____eHB____c9____xD = 0 ;
 goto __8HB____eHB____c9____zD____end ;
 __8HB____eHB____c9____zD____end :
 goto __8HB____eHB____c9____end ;
 __8HB____eHB____c9____end :
 __8HB____eHB____d9__loop :
 __8HB____eHB____e9____1D____end :
 __8HB____eHB____e9____2D__z = __8HB____eHB____c9____xD <= __7HB ; 
 goto __8HB____eHB____e9____2D____end ;
 __8HB____eHB____e9____2D____end :
 goto __8HB____eHB____e9____end ;
 __8HB____eHB____e9____end :
 if(! __8HB____eHB____e9____2D__z )goto __8HB____eHB____d9__while ;
 (( f64 *) __8HB____eHB____b9___contents )[ __8HB____eHB____c9____xD ]=0; 
 goto __8HB____eHB____d9__loop ;
 __8HB____eHB____d9__while :
 goto __8HB____eHB____h9____end ;
 __8HB____eHB____h9____end :
 goto __8HB____eHB____end ;
 __8HB____eHB____end :
 __8HB____gHB = 1.0 ;
 __8HB____hHB____oBB__z = __6HB >= __7HB ; 
 goto __8HB____hHB____oBB____end ;
 __8HB____hHB____oBB____end :
 if(! __8HB____hHB____oBB__z )goto __8HB____hHB____nBB__fi ;
 __8HB____hHB____pBB = "Vec out of bounds" ;
 goto __8HB____hHB____qBB____pD ;
 __builtin_unreachable();
 __8HB____hHB____qBB____end :
 goto __8HB____hHB____nBB__if ;
 __8HB____hHB____nBB__if :
 __8HB____hHB____nBB__fi :
 (( f64 *) __8HB____eHB____b9___contents )[ __6HB ]= __8HB____gHB ; 
 __8HB____hHB__contents = __8HB____eHB____b9___contents ;
 goto __8HB____hHB____end ;
 __8HB____hHB____end :
 goto __8HB____fHB__on ;
 __8HB____fHB__on :
 goto __8HB____end ;
 __8HB____end :
 __9HB____kEB__z =( __4HB != __7HB ); 
 goto __9HB____kEB____end ;
 __9HB____kEB____end :
 if(! __9HB____kEB__z )goto __9HB____jEB__fi ;
 __9HB____lEB = "Incompatible Vec sizes" ;
 goto __9HB____mEB____pD ;
 __builtin_unreachable();
 __9HB____mEB____end :
 goto __9HB____jEB__if ;
 __9HB____jEB__if :
 __9HB____jEB__fi :
 __builtin_assume ( __4HB == __7HB ); 
 __9HB__size = __4HB ;
 __9HB____pEB__size = __9HB__size * sizeof ( __9HB____pEB____HT ); 
 __9HB____pEB____JT__x = __1HB____QW____oO ;
 __9HB____pEB____JT__z = __9HB____pEB____JT__x + __9HB____pEB__size ; 
 goto __9HB____pEB____JT____end ;
 __9HB____pEB____JT____end :
 __9HB____pEB____KT__z = __9HB____pEB____JT__z > __0HB ; 
 goto __9HB____pEB____KT____end ;
 __9HB____pEB____KT____end :
 if(! __9HB____pEB____KT__z )goto __9HB____pEB____IT__fi ;
 __9HB____pEB____LT = "Failed an Arena allocation" ;
 goto __9HB____pEB____MT____pD ;
 __builtin_unreachable();
 __9HB____pEB____MT____end :
 goto __9HB____pEB____IT__if ;
 __9HB____pEB____IT__if :
 __9HB____pEB____IT__fi :
 __9HB____pEB___contents =( ptr )(( char *) __1HB____PW____ZI__mem + __1HB____QW____oO * sizeof ( char )); 
 __1HB____QW____oO = __1HB____QW____oO + __9HB____pEB__size ; 
 __9HB____pEB____QT = 0 ;
 __9HB____pEB____ST____end :
 goto __9HB____pEB____end ;
 __9HB____pEB____end :
 for ( __9HB__i =0; __9HB__i < __9HB__size ;++ __9HB__i )(( f64 *) __9HB____pEB___contents )[ __9HB__i ]=(( f64 *) __5HB____hHB__contents )[ __9HB__i ]*(( f64 *) __8HB____hHB__contents )[ __9HB__i ]; 
 __9HB____sEB__contents = __9HB____pEB___contents ;
 goto __9HB____sEB____end ;
 __9HB____sEB____end :
 goto __9HB____end ;
 __9HB____end :
 __AIB____CHB = 10 ;
 __AIB____DHB__z = __9HB__size > __AIB____CHB ; 
 goto __AIB____DHB____end ;
 __AIB____DHB____end :
 if(! __AIB____DHB__z )goto __AIB____BHB__fi ;
 __AIB____EHB = 10 ;
 goto __AIB____BHB__if ;
 __AIB____BHB__if :
 goto __AIB____BHB__el ;
 __AIB____BHB__fi :
 goto __AIB____BHB__le ;
 __AIB____BHB__le :
 __AIB____BHB__el :
 __AIB____FHB = "[" ;
 printf ( "%s" , __AIB____FHB ); 
 __AIB____GHB____end :
 __AIB____HHB____xD = 0 ;
 goto __AIB____HHB____zD____end ;
 __AIB____HHB____zD____end :
 goto __AIB____HHB____end ;
 __AIB____HHB____end :
 __AIB____IHB__loop :
 __AIB____JHB____1D____end :
 __AIB____JHB____2D__z = __AIB____HHB____xD <= __AIB____EHB ; 
 goto __AIB____JHB____2D____end ;
 __AIB____JHB____2D____end :
 goto __AIB____JHB____end ;
 __AIB____JHB____end :
 if(! __AIB____JHB____2D__z )goto __AIB____IHB__while ;
 if(! __AIB____HHB____xD )goto __AIB____KHB__fi ;
 __AIB____MHB = " " ;
 printf ( "%s" , __AIB____MHB ); 
 __AIB____NHB____end :
 goto __AIB____KHB__if ;
 __AIB____KHB__if :
 __AIB____KHB__fi :
 __AIB____OHB____kBB__z = __AIB____HHB____xD >= __9HB__size ; 
 goto __AIB____OHB____kBB____end ;
 __AIB____OHB____kBB____end :
 if(! __AIB____OHB____kBB__z )goto __AIB____OHB____jBB__fi ;
 __AIB____OHB____lBB = "Vec out of bounds" ;
 goto __AIB____OHB____mBB____pD ;
 __builtin_unreachable();
 __AIB____OHB____mBB____end :
 goto __AIB____OHB____jBB__if ;
 __AIB____OHB____jBB__if :
 __AIB____OHB____jBB__fi :
 __AIB____OHB__value =(( f64 *) __9HB____sEB__contents )[ __AIB____HHB____xD ]; 
 goto __AIB____OHB____end ;
 __AIB____OHB____end :
 printf ( "%.6f" , __AIB____OHB__value ); 
 __AIB____PHB____end :
 goto __AIB____IHB__loop ;
 __AIB____IHB__while :
 __AIB____RHB__z =( __AIB____EHB != __9HB__size ); 
 goto __AIB____RHB____end ;
 __AIB____RHB____end :
 if(! __AIB____RHB__z )goto __AIB____QHB__fi ;
 __AIB____SHB = " ..." ;
 printf ( "%s" , __AIB____SHB ); 
 __AIB____THB____end :
 goto __AIB____QHB__if ;
 __AIB____QHB__if :
 __AIB____QHB__fi :
 __AIB____UHB = "]" ;
 printf ( "%s\n" , __AIB____UHB ); 
 __AIB____VHB____end :
 __AIB____end :
 __2HB__on :
 __end :
goto __return;

// ERROR HANDLING
__1HB____PW____ZI____xF____pD :
 printf ( "%s\n" , __1HB____PW____ZI____wF ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __1HB____PW____ZI____3F____pD :
 printf ( "%s\n" , __1HB____PW____ZI____2F ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __5HB____eHB____b9____MT____pD :
 printf ( "%s\n" , __5HB____eHB____b9____LT ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __5HB____hHB____qBB____pD :
 printf ( "%s\n" , __5HB____hHB____pBB ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __8HB____eHB____b9____MT____pD :
 printf ( "%s\n" , __8HB____eHB____b9____LT ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __8HB____hHB____qBB____pD :
 printf ( "%s\n" , __8HB____hHB____pBB ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __9HB____mEB____pD :
 printf ( "%s\n" , __9HB____lEB ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __9HB____pEB____MT____pD :
 printf ( "%s\n" , __9HB____pEB____LT ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __AIB____OHB____mBB____pD :
 printf ( "%s\n" , __AIB____OHB____lBB ); 
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
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}



int main() {
struct main__870__state __main_args={0};
__smolambda_initialize_service_tasks(main__870, &__main_args);
return __main_args.err;
}

