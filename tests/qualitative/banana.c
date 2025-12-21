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
#define __IS_new 9
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
typedef uint64_t new;
typedef double f64;

#include<string.h>

#include<stdio.h>

struct main__185__state{errcode err;};
__externc void main__185(void *__void__state);

void main__185(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1808;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__185__state *__state=(struct main__185__state*)__void__state;
cstr __0E=0;
bool __zE____PD=0;
u64 __zE____OD____PB__x=0;
char __zE____OD__first=0;
ptr __zE____OD__contents=0;
bool __zE____MD=0;
u64 __zE____LD____PB__z=0;
char __zE____LD__first=0;
ptr __zE____LD__contents=0;
bool __zE____LD____LB__z=0;
bool __zE____LD____IB__z=0;
u64 __zE____KD__z=0;
bool __zE____ID__z=0;
u64 __zE____HD__z=0;
u64 __zE____GD=0;
bool __zE____FD__z=0;
u64 __zE____ED____PB__x=0;
char __zE____ED__first=0;
bool __zE____ED____LB__z=0;
u64 word__length=0;
u64 __zE____DD__z=0;
u64 __zE__value__length=0;
u64 __zE____LD____PB__x=0;
ptr __zE____ED__contents=0;
u64 __zE____ED____PB__z=0;
ptr __xE____MC__noptr=0;
u64 __zE____OD____PB__z=0;
bool __zE____OD____IB__z=0;
bool __zE____OD____PB____G__z=0;
u64 __zE__self__pos=0;
ptr __xE____MC____m__contents=0;
bool __zE____OD____LB__z=0;
ptr s__query__memory=0;
ptr __xE____LC__contents=0;
ptr __zE__value__contents=0;
bool __zE____ED____IB__z=0;
ptr __zE__value__memory=0;
bool __zE____LD____PB____G__z=0;
char s__query__first=0;
errcode err=0;
u64 __zE__prev=0;
cstr __vE=0;
cstr __wE=0;
u64 __xE____LC__length=0;
ptr __xE____LC__noptr=0;
ptr __xE____LC____m__contents=0;
ptr s__query__contents=0;
u64 __xE____MC__length=0;
bool __zE____ED____PB____G__z=0;
ptr __xE____MC__contents=0;
char __xE____MC__first=0;
u64 s__query__length=0;
ptr s__sep__contents=0;
char s__sep__first=0;
ptr s__sep__memory=0;
u64 s__pos=0;
u64 __xE__pos=0;
ptr word__contents=0;
char __zE__value__first=0;
char __xE____LC__first=0;
char word__first=0;
ptr word__memory=0;
bool __zE____4C__z=0;
u64 s__sep__length=0;
bool __zE____5C=0;
bool __zE____9C____G__z=0;
u64 __zE____9C__z=0;
bool __zE____AD__z=0;

// IMPLEMENTATION
__vE = "Me? I like bananas!" ;
 __wE = " " ;
 __xE____LC__length = strlen ( __vE ); __xE____LC__contents =( ptr ) __vE ; __xE____LC__first = __vE [0]; __xE____LC__noptr =( ptr ) __xE____LC__noptr ; 
 __xE____LC____m__contents = __xE____LC__contents ;
 __xE____MC__length = strlen ( __wE ); __xE____MC__contents =( ptr ) __wE ; __xE____MC__first = __wE [0]; __xE____MC__noptr =( ptr ) __xE____MC__noptr ; 
 __xE____MC____m__contents = __xE____MC__contents ;
 s__query__contents = __xE____LC____m__contents ;
 s__query__length = __xE____LC__length ;
 s__query__first = __xE____LC__first ;
 s__query__memory = __xE____LC__noptr ;
 s__sep__contents = __xE____MC____m__contents ;
 s__sep__length = __xE____MC__length ;
 s__sep__first = __xE____MC__first ;
 s__sep__memory = __xE____MC__noptr ;
 s__pos = __xE__pos ;
 __yE__loop :
 __zE__self__pos = s__pos ;
 __zE__value__contents = word__contents ;
 __zE__value__length = word__length ;
 __zE__value__first = word__first ;
 __zE__value__memory = word__memory ;
 __zE____4C__z = __zE__self__pos >= s__query__length ; 
 __zE____4C____end :
 if(! __zE____4C__z )goto __zE____2C__fi ;
 __zE____5C = false ;
 goto __zE____end ;
 __zE____2C__fi :
 __zE__prev = __zE__self__pos ;
 __zE____6C__loop :
 __zE____9C____G__z = s__sep__length > s__query__length ; 
 __zE____9C____G____end :
 if(! __zE____9C____G__z )goto __zE____9C____F__fi ;
 goto __zE____9C____H ;
 __builtin_unreachable();
 __zE____9C____F__fi :
 __zE____9C__z = s__query__length - s__sep__length ; 
 __zE____9C____end :
 __zE____AD__z = __zE__self__pos < __zE____9C__z ; 
 __zE____AD____end :
 if(! __zE____AD__z )goto __zE____6C__while ;
 __zE____DD__z = __zE__self__pos + s__sep__length ; 
 __zE____DD____end :
 __zE____ED____IB__z = __zE____DD__z < __zE__self__pos ; 
 __zE____ED____IB____end :
 if(! __zE____ED____IB__z )goto __zE____ED____HB__fi ;
 goto __zE____ED____JB ;
 __builtin_unreachable();
 __zE____ED____HB__fi :
 __zE____ED____LB__z = __zE____DD__z > s__query__length ; 
 __zE____ED____LB____end :
 if(! __zE____ED____LB__z )goto __zE____ED____KB__fi ;
 goto __zE____ED____MB ;
 __builtin_unreachable();
 __zE____ED____KB__fi :
 __zE____ED__contents =( ptr )(( char *) s__query__contents + __zE__self__pos * sizeof ( char )); __zE____ED__first = __zE__self__pos == __zE____DD__z ?0:(( __builtin_constant_p ( __zE__self__pos )&& __zE__self__pos ==0)? s__query__first :(( char *) s__query__contents )[ __zE__self__pos ]); 
 __zE____ED____PB__x = __zE____DD__z ;
 __zE____ED____PB____G__z = __zE__self__pos > __zE____ED____PB__x ; 
 __zE____ED____PB____G____end :
 if(! __zE____ED____PB____G__z )goto __zE____ED____PB____F__fi ;
 goto __zE____ED____PB____H ;
 __builtin_unreachable();
 __zE____ED____PB____F__fi :
 __zE____ED____PB__z = __zE____ED____PB__x - __zE__self__pos ; 
 __zE____ED____PB____end :
 __zE____FD__z =( s__sep__first != __zE____ED__first )||( s__sep__length != __zE____ED____PB__z )||( memcmp (( char *) s__sep__contents +1,( char *) __zE____ED__contents +1, s__sep__length -1)!=0); 
 __zE____FD____end :
 if(! __zE____FD__z )goto __zE____BD__fi ;
 __zE____GD = 1 ;
 __zE____HD__z = __zE__self__pos + __zE____GD ; 
 __zE____HD____end :
 __zE__self__pos = __zE____HD__z ;
 goto __zE____BD__if ;
 __zE____ID__z = __zE__self__pos <= __zE__prev ; 
 __zE____ID____end :
 if(! __zE____ID__z )goto __zE____BD__fi ;
 __zE____BD__if :
 goto __zE____BD__el ;
 __zE____BD__fi :
 __zE____KD__z = __zE__self__pos + s__sep__length ; 
 __zE____KD____end :
 __zE__self__pos = __zE____KD__z ;
 __zE__prev = __zE__self__pos ;
 __zE____BD__le :
 __zE____BD__if :
 goto __zE____BD__el ;
 __zE____BD__fi :
 __zE____LD____IB__z = __zE__self__pos < __zE__prev ; 
 __zE____LD____IB____end :
 if(! __zE____LD____IB__z )goto __zE____LD____HB__fi ;
 goto __zE____LD____JB ;
 __builtin_unreachable();
 __zE____LD____HB__fi :
 __zE____LD____LB__z = __zE__self__pos > s__query__length ; 
 __zE____LD____LB____end :
 if(! __zE____LD____LB__z )goto __zE____LD____KB__fi ;
 goto __zE____LD____MB ;
 __builtin_unreachable();
 __zE____LD____KB__fi :
 __zE____LD__contents =( ptr )(( char *) s__query__contents + __zE__prev * sizeof ( char )); __zE____LD__first = __zE__prev == __zE__self__pos ?0:(( __builtin_constant_p ( __zE__prev )&& __zE__prev ==0)? s__query__first :(( char *) s__query__contents )[ __zE__prev ]); 
 __zE____LD____PB__x = __zE__self__pos ;
 __zE____LD____PB____G__z = __zE__prev > __zE____LD____PB__x ; 
 __zE____LD____PB____G____end :
 if(! __zE____LD____PB____G__z )goto __zE____LD____PB____F__fi ;
 goto __zE____LD____PB____H ;
 __builtin_unreachable();
 __zE____LD____PB____F__fi :
 __zE____LD____PB__z = __zE____LD____PB__x - __zE__prev ; 
 __zE____LD____PB____end :
 __zE__value__contents = __zE____LD__contents ;
 __zE__value__length = __zE____LD____PB__z ;
 __zE__value__first = __zE____LD__first ;
 __zE__value__memory = s__query__contents ;
 __zE____MD = true ;
 __zE____5C = __zE____MD ;
 goto __zE____end ;
 __zE____BD__le :
 __zE____BD__el :
 goto __zE____6C__loop ;
 __zE____6C__while :
 __zE__self__pos = s__query__length ;
 __zE____OD____IB__z = __zE__self__pos < __zE__prev ; 
 __zE____OD____IB____end :
 if(! __zE____OD____IB__z )goto __zE____OD____HB__fi ;
 goto __zE____OD____JB ;
 __builtin_unreachable();
 __zE____OD____HB__fi :
 __zE____OD____LB__z = __zE__self__pos > s__query__length ; 
 __zE____OD____LB____end :
 if(! __zE____OD____LB__z )goto __zE____OD____KB__fi ;
 goto __zE____OD____MB ;
 __builtin_unreachable();
 __zE____OD____KB__fi :
 __zE____OD__contents =( ptr )(( char *) s__query__contents + __zE__prev * sizeof ( char )); __zE____OD__first = __zE__prev == __zE__self__pos ?0:(( __builtin_constant_p ( __zE__prev )&& __zE__prev ==0)? s__query__first :(( char *) s__query__contents )[ __zE__prev ]); 
 __zE____OD____PB__x = __zE__self__pos ;
 __zE____OD____PB____G__z = __zE__prev > __zE____OD____PB__x ; 
 __zE____OD____PB____G____end :
 if(! __zE____OD____PB____G__z )goto __zE____OD____PB____F__fi ;
 goto __zE____OD____PB____H ;
 __builtin_unreachable();
 __zE____OD____PB____F__fi :
 __zE____OD____PB__z = __zE____OD____PB__x - __zE__prev ; 
 __zE____OD____PB____end :
 __zE__value__contents = __zE____OD__contents ;
 __zE__value__length = __zE____OD____PB__z ;
 __zE__value__first = __zE____OD__first ;
 __zE__value__memory = s__query__contents ;
 __zE____PD = true ;
 __zE____5C = __zE____PD ;
 __zE____end :
 s__pos = __zE__self__pos ;
 if(! __zE____5C )goto __yE__while ;
 __0E = "word: " ;
 printf ( "%s" , __0E ); 
 __1E____end :
 printf ( "%.*s\n" ,( int ) __zE__value__length ,( char *) __zE__value__contents ); 
 __2E____end :
 goto __yE__loop ;
 __yE__while :
 __end :
goto __return;

// ERROR HANDLING
__zE____OD____PB____H :
 printf ( "Error: unsigned substraction yielded a negative\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__zE____OD____JB :
 printf ( "String slice cannot end before it starts\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__zE____LD____PB____H :
 printf ( "Error: unsigned substraction yielded a negative\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__zE____OD____MB :
 printf ( "String slice must end at most at the length of the base string\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__zE____LD____JB :
 printf ( "String slice cannot end before it starts\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__zE____LD____MB :
 printf ( "String slice must end at most at the length of the base string\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__zE____ED____JB :
 printf ( "String slice cannot end before it starts\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__zE____ED____PB____H :
 printf ( "Error: unsigned substraction yielded a negative\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__zE____ED____MB :
 printf ( "String slice must end at most at the length of the base string\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__zE____9C____H :
 printf ( "Error: unsigned substraction yielded a negative\n" ); 
__result__error_code=__USER__ERROR;
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
__state->err =  __result__error_code;
}



int main() {
struct main__185__state __main_args={0};
__smolambda_initialize_service_tasks(main__185, &__main_args);
return __main_args.err;
}

