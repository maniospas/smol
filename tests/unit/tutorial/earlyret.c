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
typedef uint64_t __new;
typedef double f64;

#include<string.h>

#include<stdio.h>

struct main__208__state{errcode err;};
__externc void main__208(void *__void__state);

void main__208(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1816;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__208__state *__state=(struct main__208__state*)__void__state;
char __06G____0pG__x=0;
ptr __06G____0iG__noptr=0;
char __06G____0oG__z=0;
u64 __06G____0oG__pos=0;
char __06G____0nG__x__first=0;
ptr __06G____0oG__x__memory=0;
ptr __06G____0nG__x__contents=0;
u64 __06G____0oG__x__length=0;
__new __06G____0oG__x____0r=0;
u64 __06G____0nG____0jC__y=0;
char __06G____0yG__x=0;
u64 __06G____0nG____0jC__x=0;
ptr __06G____0nG__x__memory=0;
char __06G____0oG__x__first=0;
u64 __06G____0nG__x__length=0;
bool __06G____0uG__message=0;
u64 __06G____0mG____0WF__z=0;
char __06G____0jG__x__first=0;
u64 __06G____0xG____0jC__x=0;
char __06G____0pG__y=0;
u64 __06G____0mG____0WF__y=0;
bool __06G____0nG____0jC__z=0;
u64 __06G____0kG__step=0;
u64 __06G____0iG__length=0;
ptr __06G____0xG__x__memory=0;
bool __07G__message=0;
bool __06G____02G=0;
u64 __06G____0iG____02__length=0;
char __06G____0tG__message=0;
u64 __06G____0rG__message=0;
u64 __06G____0oG____0jC__y=0;
__new __06G____0jG__x____0r=0;
u64 __06G____0mG____0WF__x=0;
ptr __06G____0xG__x__contents=0;
u64 __06G____0mG__self__step=0;
char __06G____0yG__y=0;
bool __06G____0mG____0XF__z=0;
ptr __04G__noptr=0;
__new __04G____01=0;
ptr __04G__memory=0;
ptr __06G____0iG____02__contents=0;
bool __06G__ret=0;
char __04G____02__first=0;
char __04G__first=0;
ptr __04G____02__memory=0;
char __06G____0nG__z=0;
cstr __05G=0;
bool __06G____0zG=0;
u64 __04G____02__length=0;
u64 __06G____0xG____0jC__y=0;
u64 __06G____0kG__sup=0;
char __06G____0iG____02__first=0;
__new __06G____0iG____01=0;
char __06G____0xG__z=0;
cstr __04G__raw=0;
__new __04G____00=0;
u64 __06G____0mG__self__sup=0;
u64 __06G____0mG__self__pos=0;
bool __06G____0xG____0jC__z=0;
__new __04G____02____0r=0;
ptr __04G____02__contents=0;
bool __06G____0pG__z=0;
ptr __06G____0iG__contents=0;
cstr __06G___line=0;
u64 __06G____0oG____0jC__x=0;
bool __06G____0yG__z=0;
u64 __06G____0nG__pos=0;
u64 __06G____0mG__value=0;
cstr __03G=0;
bool __06G____00G=0;
u64 __06G____0xG__x__length=0;
cstr __06G____0iG__raw=0;
bool __06G____0oG____0jC__z=0;
u64 __06G____0kG____0SF=0;
__new __04G____0r=0;
u64 __06G____0kG____0TF=0;
u64 __06G____0mG____0XF__x=0;
char __06G__c=0;
__new __06G____0iG____00=0;
char __06G____0xG__x__first=0;
ptr __04G__contents=0;
cstr __06G____0vG__message=0;
u64 __06G____0kG__start=0;
u64 __06G____0kG__pos=0;
u64 __06G____0xG__pos=0;
u64 __06G____0kG____0UF__step=0;
ptr __06G____0iG__memory=0;
u64 __06G____0mG____0XF__y=0;
u64 __06G__pos=0;
ptr __06G____0jG__x__memory=0;
u64 __06G____0mG__self__start=0;
u64 __06G____0kG____0UF__sup=0;
ptr __06G__line__memory=0;
u64 __06G____0jG__x__length=0;
__new __06G____0nG__x____0r=0;
char __06G____0sG__message=0;
char __06G__line__first=0;
char __06G____0iG__first=0;
ptr __06G____0jG__x__contents=0;
u64 __04G__length=0;
__new __06G____0iG____02____0r=0;
u64 __06G____0mG____0VF=0;
ptr __06G__line__contents=0;
u64 __06G__line__length=0;
ptr __06G____0oG__x__contents=0;
__new __06G____0xG__x____0r=0;
__new __06G____0iG____0r=0;
__new __06G__line____0r=0;
u64 __06G____0kG____0UF__start=0;
ptr __06G____0iG____02__memory=0;
cstr __06G____0qG=0;
u64 __06G____0kG____0UF__pos=0;

// IMPLEMENTATION
__03G = "a" ;
 __04G__raw = __03G ;
 __04G__length = strlen ( __04G__raw ); __04G__contents =( ptr ) __04G__raw ; __04G__first = __04G__raw [0]; __04G__noptr =0; 
 __04G____02__contents = __04G__contents ;
 __04G____02__length = __04G__length ;
 __04G____02__first = __04G__first ;
 __04G____02__memory = __04G__noptr ;
 goto __04G____02____end ;
 __04G____02____end :
 __04G__contents = __04G____02__contents ;
 __04G__length = __04G____02__length ;
 __04G__first = __04G____02__first ;
 __04G__memory = __04G____02__memory ;
 goto __04G____end ;
 __04G____end :
 __05G = "abc" ;
 __06G__c = __04G__first ;
 __06G___line = __05G ;
 __06G____0iG__raw = __06G___line ;
 __06G____0iG__length = strlen ( __06G____0iG__raw ); __06G____0iG__contents =( ptr ) __06G____0iG__raw ; __06G____0iG__first = __06G____0iG__raw [0]; __06G____0iG__noptr =0; 
 __06G____0iG____02__contents = __06G____0iG__contents ;
 __06G____0iG____02__length = __06G____0iG__length ;
 __06G____0iG____02__first = __06G____0iG__first ;
 __06G____0iG____02__memory = __06G____0iG__noptr ;
 goto __06G____0iG____02____end ;
 __06G____0iG____02____end :
 __06G____0iG__contents = __06G____0iG____02__contents ;
 __06G____0iG__length = __06G____0iG____02__length ;
 __06G____0iG__first = __06G____0iG____02__first ;
 __06G____0iG__memory = __06G____0iG____02__memory ;
 goto __06G____0iG____end ;
 __06G____0iG____end :
 __06G__line__contents = __06G____0iG__contents ;
 __06G__line__length = __06G____0iG__length ;
 __06G__line__first = __06G____0iG__first ;
 __06G__line__memory = __06G____0iG__memory ;
 __06G____0jG__x__contents = __06G__line__contents ;
 __06G____0jG__x__length = __06G__line__length ;
 __06G____0jG__x__first = __06G__line__first ;
 __06G____0jG__x__memory = __06G__line__memory ;
 goto __06G____0jG____end ;
 __06G____0jG____end :
 __06G____0kG__sup = __06G____0jG__x__length ;
 __06G____0kG____0SF = 0 ;
 __06G____0kG____0TF = 1 ;
 __06G____0kG____0UF__start = __06G____0kG____0SF ;
 __06G____0kG____0UF__sup = __06G____0kG__sup ;
 __06G____0kG____0UF__step = __06G____0kG____0TF ;
 __06G____0kG____0UF__pos = __06G____0kG____0UF__start ;
 goto __06G____0kG____0UF____end ;
 __06G____0kG____0UF____end :
 __06G____0kG__start = __06G____0kG____0UF__start ;
 __06G____0kG__sup = __06G____0kG____0UF__sup ;
 __06G____0kG__step = __06G____0kG____0UF__step ;
 __06G____0kG__pos = __06G____0kG____0UF__pos ;
 goto __06G____0kG____end ;
 __06G____0kG____end :
 __06G____0lG__loop :
 __06G____0mG__self__start = __06G____0kG__start ;
 __06G____0mG__self__sup = __06G____0kG__sup ;
 __06G____0mG__self__step = __06G____0kG__step ;
 __06G____0mG__self__pos = __06G____0kG__pos ;
 __06G____0mG__value = __06G__pos ;
 __06G____0mG__value = __06G____0mG__self__pos ;
 __06G____0mG____0VF = 1 ;
 __06G____0mG____0WF__x = __06G____0mG__self__pos ;
 __06G____0mG____0WF__y = __06G____0mG____0VF ;
 __06G____0mG____0WF__z = __06G____0mG____0WF__x + __06G____0mG____0WF__y ; 
 goto __06G____0mG____0WF____end ;
 __06G____0mG____0WF____end :
 __06G____0mG__self__pos = __06G____0mG____0WF__z ;
 __06G____0mG____0XF__x = __06G____0mG__self__pos ;
 __06G____0mG____0XF__y = __06G____0mG__self__sup ;
 __06G____0mG____0XF__z = __06G____0mG____0XF__x <= __06G____0mG____0XF__y ; 
 goto __06G____0mG____0XF____end ;
 __06G____0mG____0XF____end :
 goto __06G____0mG____end ;
 __06G____0mG____end :
 __06G____0kG__start = __06G____0mG__self__start ;
 __06G____0kG__sup = __06G____0mG__self__sup ;
 __06G____0kG__step = __06G____0mG__self__step ;
 __06G____0kG__pos = __06G____0mG__self__pos ;
 __06G__pos = __06G____0mG__value ;
 if(! __06G____0mG____0XF__z )goto __06G____0lG__while ;
 __06G____0nG__x__contents = __06G__line__contents ;
 __06G____0nG__x__length = __06G__line__length ;
 __06G____0nG__x__first = __06G__line__first ;
 __06G____0nG__x__memory = __06G__line__memory ;
 __06G____0nG__pos = __06G__pos ;
 __06G____0nG____0jC__x = __06G____0nG__x__length ;
 __06G____0nG____0jC__y = __06G____0nG__pos ;
 __06G____0nG____0jC__z = __06G____0nG____0jC__x <= __06G____0nG____0jC__y ; 
 goto __06G____0nG____0jC____end ;
 __06G____0nG____0jC____end :
 if(! __06G____0nG____0jC__z )goto __06G____0nG____0iC__fi ;
 [[unlikely]] goto __06G____0nG____0kC ;
 __builtin_unreachable();
 __06G____0nG____0iC__if :
 __06G____0nG____0iC__fi :
 __06G____0nG__z =( __builtin_constant_p ( __06G____0nG__pos )&& __06G____0nG__pos ==0)? __06G____0nG__x__first :(( char *) __06G____0nG__x__contents )[ __06G____0nG__pos ]; 
 goto __06G____0nG____end ;
 __06G____0nG____end :
 __06G____0oG__x__contents = __06G__line__contents ;
 __06G____0oG__x__length = __06G__line__length ;
 __06G____0oG__x__first = __06G__line__first ;
 __06G____0oG__x__memory = __06G__line__memory ;
 __06G____0oG__pos = __06G__pos ;
 __06G____0oG____0jC__x = __06G____0oG__x__length ;
 __06G____0oG____0jC__y = __06G____0oG__pos ;
 __06G____0oG____0jC__z = __06G____0oG____0jC__x <= __06G____0oG____0jC__y ; 
 goto __06G____0oG____0jC____end ;
 __06G____0oG____0jC____end :
 if(! __06G____0oG____0jC__z )goto __06G____0oG____0iC__fi ;
 [[unlikely]] goto __06G____0oG____0kC ;
 __builtin_unreachable();
 __06G____0oG____0iC__if :
 __06G____0oG____0iC__fi :
 __06G____0oG__z =( __builtin_constant_p ( __06G____0oG__pos )&& __06G____0oG__pos ==0)? __06G____0oG__x__first :(( char *) __06G____0oG__x__contents )[ __06G____0oG__pos ]; 
 goto __06G____0oG____end ;
 __06G____0oG____end :
 __06G____0pG__x = __06G____0oG__z ;
 __06G____0pG__y = __06G__c ;
 __06G____0pG__z =( __06G____0pG__x == __06G____0pG__y ); 
 goto __06G____0pG____end ;
 __06G____0pG____end :
 __06G____0qG = "\n" ;
 __06G____0rG__message = __06G__pos ;
 printf ( "%lu" , __06G____0rG__message ); 
 __06G____0rG____end :
 __06G____0sG__message = __06G____0nG__z ;
 printf ( "%c" , __06G____0sG__message ); 
 __06G____0sG____end :
 __06G____0tG__message = __06G__c ;
 printf ( "%c" , __06G____0tG__message ); 
 __06G____0tG____end :
 __06G____0uG__message = __06G____0pG__z ;
 __06G____0uG__message ? printf ( "true" ): printf ( "false" ); 
 __06G____0uG____end :
 __06G____0vG__message = __06G____0qG ;
 printf ( "%s" , __06G____0vG__message ); 
 __06G____0vG____end :
 __06G____0xG__x__contents = __06G__line__contents ;
 __06G____0xG__x__length = __06G__line__length ;
 __06G____0xG__x__first = __06G__line__first ;
 __06G____0xG__x__memory = __06G__line__memory ;
 __06G____0xG__pos = __06G__pos ;
 __06G____0xG____0jC__x = __06G____0xG__x__length ;
 __06G____0xG____0jC__y = __06G____0xG__pos ;
 __06G____0xG____0jC__z = __06G____0xG____0jC__x <= __06G____0xG____0jC__y ; 
 goto __06G____0xG____0jC____end ;
 __06G____0xG____0jC____end :
 if(! __06G____0xG____0jC__z )goto __06G____0xG____0iC__fi ;
 [[unlikely]] goto __06G____0xG____0kC ;
 __builtin_unreachable();
 __06G____0xG____0iC__if :
 __06G____0xG____0iC__fi :
 __06G____0xG__z =( __builtin_constant_p ( __06G____0xG__pos )&& __06G____0xG__pos ==0)? __06G____0xG__x__first :(( char *) __06G____0xG__x__contents )[ __06G____0xG__pos ]; 
 goto __06G____0xG____end ;
 __06G____0xG____end :
 __06G____0yG__x = __06G____0xG__z ;
 __06G____0yG__y = __06G__c ;
 __06G____0yG__z =( __06G____0yG__x == __06G____0yG__y ); 
 goto __06G____0yG____end ;
 __06G____0yG____end :
 if(! __06G____0yG__z )goto __06G____0wG__fi ;
 __06G____0zG = true ;
 __06G__ret = __06G____0zG ;
 __06G____00G = true ;
 goto __06G____end ;
 __06G____0wG__if :
 __06G____0wG__fi :
 goto __06G____0lG__loop ;
 __06G____0lG__while :
 __06G____02G = false ;
 __06G____00G = __06G____02G ;
 goto __06G____end ;
 __06G____end :
 __07G__message = __06G____00G ;
 __07G__message ? printf ( "true\n" ): printf ( "false\n" ); 
 __07G____end :
 __end :
goto __return;

// ERROR HANDLING
__06G____0nG____0kC :
 printf ( "String index out of bounds\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__06G____0oG____0kC :
 printf ( "String index out of bounds\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__06G____0xG____0kC :
 printf ( "String index out of bounds\n" ); 
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
struct main__208__state __main_args={0};
__smolambda_initialize_service_tasks(main__208, &__main_args);
return __main_args.err;
}

