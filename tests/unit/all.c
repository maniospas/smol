#define SMOLAMBDA_SERVICES 8
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
typedef uint64_t u64;
typedef long i64;
typedef uint64_t nominal;
typedef double f64;

#include "std/oscommon.h"

#include<sys/wait.h>

#if defined(_WIN32)||defined(_WIN64)
#define popen _popen
#define pclose _pclose
#endif

#include<string.h>

#include<stdlib.h>

#include<stdio.h>

#include <stdio.h>
struct std_test__818__state{errcode err;cstr name;};
__externc void std_test__818(void *__void__state);
struct std_test__819__state{errcode err;nominal name____b;ptr name__contents;u64 name__length;char name__first;ptr name__memory;};
__externc void std_test__819(void *__void__state);
struct std_test__820__state{errcode err;nominal name____c;ptr name__contents;u64 name__length;char name__first;ptr name__memory;};
__externc void std_test__820(void *__void__state);
struct run__814__state{errcode err;cstr command;};
__externc void run__814(void *__void__state);
struct run__815__state{errcode err;nominal command____b;ptr command__contents;u64 command__length;char command__first;ptr command__memory;};
__externc void run__815(void *__void__state);
struct run__816__state{errcode err;nominal command____c;ptr command__contents;u64 command__length;char command__first;ptr command__memory;};
__externc void run__816(void *__void__state);
struct main__822__state{errcode err;};
__externc void main__822(void *__void__state);
struct all__821__state{errcode err;};
__externc void all__821(void *__void__state);

void all__821(void *__void__state){
errcode __result__errocode=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 14844;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct all__821__state *__state=(struct all__821__state*)__void__state;
struct std_test__818__state* __E8____state = 0 ;
 struct std_test__818__state* __G8____state = 0 ;
 struct std_test__818__state* __I8____state = 0 ;
 struct std_test__818__state* __K8____state = 0 ;
 struct std_test__818__state* __M8____state = 0 ;
 struct std_test__818__state* __O8____state = 0 ;
 struct std_test__818__state* __Q8____state = 0 ;
 struct std_test__818__state* __S8____state = 0 ;
 struct std_test__818__state* __U8____state = 0 ;
 struct std_test__818__state* __W8____state = 0 ;
 struct std_test__818__state* __Y8____state = 0 ;
 struct std_test__818__state* __a8____state = 0 ;
 struct std_test__818__state* __c8____state = 0 ;
 struct std_test__818__state* __e8____state = 0 ;
 struct std_test__818__state* __g8____state = 0 ;
 struct std_test__818__state* __i8____state = 0 ;
 struct std_test__818__state* __k8____state = 0 ;
 struct std_test__818__state* __m8____state = 0 ;
 struct std_test__818__state* __o8____state = 0 ;
 struct std_test__818__state* __q8____state = 0 ;
 struct std_test__818__state* __s8____state = 0 ;
 struct std_test__818__state* __u8____state = 0 ;
ptr __u8____task=0;
errcode __s8__err=0;
cstr __r8=0;
ptr __q8____task=0;
cstr __p8=0;
ptr __o8____task=0;
errcode __m8__err=0;
cstr __h8=0;
errcode __g8__err=0;
ptr __g8____task=0;
cstr __f8=0;
errcode __e8__err=0;
cstr __d8=0;
ptr __c8____task=0;
cstr __b8=0;
errcode __Y8__err=0;
errcode __q8__err=0;
ptr __Y8____task=0;
cstr __X8=0;
ptr __W8____task=0;
ptr __S8____task=0;
cstr __R8=0;
ptr __Q8____task=0;
cstr __P8=0;
ptr __O8____task=0;
cstr __N8=0;
errcode __M8__err=0;
cstr __L8=0;
errcode __K8__err=0;
cstr __J8=0;
cstr __H8=0;
ptr __G8____task=0;
cstr __F8=0;
errcode __E8__err=0;
cstr __D8=0;
ptr __U8____task=0;
errcode __i8__err=0;
cstr __j8=0;
errcode __Q8__err=0;
ptr __k8____task=0;
errcode __O8__err=0;
errcode __k8__err=0;
ptr __e8____task=0;
cstr __T8=0;
ptr __E8____task=0;
ptr __a8____task=0;
errcode __u8__err=0;
errcode __I8__err=0;
errcode __o8__err=0;
cstr __l8=0;
ptr __M8____task=0;
ptr __I8____task=0;
errcode __W8__err=0;
errcode __a8__err=0;
errcode __c8__err=0;
cstr __Z8=0;
errcode __G8__err=0;
cstr __n8=0;
ptr __m8____task=0;
errcode __U8__err=0;
cstr __t8=0;
ptr __i8____task=0;
errcode __S8__err=0;
ptr __s8____task=0;
ptr __K8____task=0;
cstr __V8=0;

// IMPLEMENTATION
__D8 = "buffer" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __E8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __E8____state ) ;
 __E8____state -> name = __D8 ;
 __E8____task = __smolambda_add_task ( std_test__818 , __E8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __E8____task ) ;
 if( __E8__err ) goto  __result_unhandled_error ;
 __F8 = "bbuffer" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __G8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __G8____state ) ;
 __G8____state -> name = __F8 ;
 __G8____task = __smolambda_add_task ( std_test__818 , __G8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __G8____task ) ;
 if( __G8__err ) goto  __result_unhandled_error ;
 __H8 = "bufferconst" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __I8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __I8____state ) ;
 __I8____state -> name = __H8 ;
 __I8____task = __smolambda_add_task ( std_test__818 , __I8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __I8____task ) ;
 if( __I8__err ) goto  __result_unhandled_error ;
 __J8 = "buffergrow" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __K8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __K8____state ) ;
 __K8____state -> name = __J8 ;
 __K8____task = __smolambda_add_task ( std_test__818 , __K8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __K8____task ) ;
 if( __K8__err ) goto  __result_unhandled_error ;
 __L8 = "effvec" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __M8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __M8____state ) ;
 __M8____state -> name = __L8 ;
 __M8____task = __smolambda_add_task ( std_test__818 , __M8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __M8____task ) ;
 if( __M8__err ) goto  __result_unhandled_error ;
 __N8 = "fail" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __O8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __O8____state ) ;
 __O8____state -> name = __N8 ;
 __O8____task = __smolambda_add_task ( std_test__818 , __O8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __O8____task ) ;
 if( __O8__err ) goto  __result_unhandled_error ;
 __P8 = "file" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __Q8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __Q8____state ) ;
 __Q8____state -> name = __P8 ;
 __Q8____task = __smolambda_add_task ( std_test__818 , __Q8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __Q8____task ) ;
 if( __Q8__err ) goto  __result_unhandled_error ;
 __R8 = "filesize" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __S8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __S8____state ) ;
 __S8____state -> name = __R8 ;
 __S8____task = __smolambda_add_task ( std_test__818 , __S8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __S8____task ) ;
 if( __S8__err ) goto  __result_unhandled_error ;
 __T8 = "finally" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __U8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __U8____state ) ;
 __U8____state -> name = __T8 ;
 __U8____task = __smolambda_add_task ( std_test__818 , __U8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __U8____task ) ;
 if( __U8__err ) goto  __result_unhandled_error ;
 __V8 = "nom" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __W8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __W8____state ) ;
 __W8____state -> name = __V8 ;
 __W8____task = __smolambda_add_task ( std_test__818 , __W8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __W8____task ) ;
 if( __W8__err ) goto  __result_unhandled_error ;
 __X8 = "mem" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __Y8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __Y8____state ) ;
 __Y8____state -> name = __X8 ;
 __Y8____task = __smolambda_add_task ( std_test__818 , __Y8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __Y8____task ) ;
 if( __Y8__err ) goto  __result_unhandled_error ;
 __Z8 = "infinite" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __a8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __a8____state ) ;
 __a8____state -> name = __Z8 ;
 __a8____task = __smolambda_add_task ( std_test__818 , __a8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __a8____task ) ;
 if( __a8__err ) goto  __result_unhandled_error ;
 __b8 = "union" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __c8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __c8____state ) ;
 __c8____state -> name = __b8 ;
 __c8____task = __smolambda_add_task ( std_test__818 , __c8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __c8____task ) ;
 if( __c8__err ) goto  __result_unhandled_error ;
 __d8 = "memtest" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __e8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __e8____state ) ;
 __e8____state -> name = __d8 ;
 __e8____task = __smolambda_add_task ( std_test__818 , __e8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __e8____task ) ;
 if( __e8__err ) goto  __result_unhandled_error ;
 __f8 = "mutpoint" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __g8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __g8____state ) ;
 __g8____state -> name = __f8 ;
 __g8____task = __smolambda_add_task ( std_test__818 , __g8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __g8____task ) ;
 if( __g8__err ) goto  __result_unhandled_error ;
 __h8 = "range_test" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __i8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __i8____state ) ;
 __i8____state -> name = __h8 ;
 __i8____task = __smolambda_add_task ( std_test__818 , __i8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __i8____task ) ;
 if( __i8__err ) goto  __result_unhandled_error ;
 __j8 = "ref" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __k8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __k8____state ) ;
 __k8____state -> name = __j8 ;
 __k8____task = __smolambda_add_task ( std_test__818 , __k8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __k8____task ) ;
 if( __k8__err ) goto  __result_unhandled_error ;
 __l8 = "strcat" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __m8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __m8____state ) ;
 __m8____state -> name = __l8 ;
 __m8____task = __smolambda_add_task ( std_test__818 , __m8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __m8____task ) ;
 if( __m8__err ) goto  __result_unhandled_error ;
 __n8 = "vec" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __o8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __o8____state ) ;
 __o8____state -> name = __n8 ;
 __o8____task = __smolambda_add_task ( std_test__818 , __o8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __o8____task ) ;
 if( __o8__err ) goto  __result_unhandled_error ;
 __p8 = "virtfile" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __q8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __q8____state ) ;
 __q8____state -> name = __p8 ;
 __q8____task = __smolambda_add_task ( std_test__818 , __q8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __q8____task ) ;
 if( __q8__err ) goto  __result_unhandled_error ;
 __r8 = "accessvar" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __s8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __s8____state ) ;
 __s8____state -> name = __r8 ;
 __s8____task = __smolambda_add_task ( std_test__818 , __s8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __s8____task ) ;
 if( __s8__err ) goto  __result_unhandled_error ;
 __t8 = "release" ;
 {char mark;if(__service_stack_floor+ 2844 >=(char*)&mark) goto __service_stack_floor_handler;} __u8____state = (struct std_test__818__state*)__runtime_calloc(sizeof(struct std_test__818__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __u8____state ) ;
 __u8____state -> name = __t8 ;
 __u8____task = __smolambda_add_task ( std_test__818 , __u8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __u8____task ) ;
 if( __u8__err ) goto  __result_unhandled_error ;
 __end :
goto __return;

// ERROR HANDLING
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__service_stack_floor_handler:
printf("Insufficient stack for safe service call (too much recursion or stack allocation)\n");
__result__errocode=__STACK__ERROR;
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


void main__822(void *__void__state){
errcode __result__errocode=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 14664;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__822__state *__state=(struct main__822__state*)__void__state;
struct all__821__state* __w8____state = 0 ;
cstr __38=0;
f64 __18__z=0;
cstr __y8=0;
errcode __w8__err=0;
f64 __v8__elapsed=0;
ptr __w8____task=0;
f64 __08__elapsed=0;

// IMPLEMENTATION
__v8__elapsed = __smo_time_eta (); 
 __v8____end :
 {char mark;if(__service_stack_floor+ 14844 >=(char*)&mark) goto __service_stack_floor_handler;} __w8____state = (struct all__821__state*)__runtime_calloc(sizeof(struct all__821__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __w8____state ) ;
 __w8____task = __smolambda_add_task ( all__821 , __w8____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __w8____task ) ;
 if( __w8__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __w8____task ) ;
 __w8__err = __w8____state -> err ;
 __y8 = "Completed in " ;
 printf ( "%s" , __y8 ); 
 __z8____end :
 __08__elapsed = __smo_time_eta (); 
 __08____end :
 __18__z = __08__elapsed - __v8__elapsed ; 
 __18____end :
 printf ( "%.6f" , __18__z ); 
 __28____end :
 __38 = " sec" ;
 printf ( "%s\n" , __38 ); 
 __48____end :
 __end :
goto __return;

// ERROR HANDLING
__x8 :
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__service_stack_floor_handler:
printf("Insufficient stack for safe service call (too much recursion or stack allocation)\n");
__result__errocode=__STACK__ERROR;
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


void run__816(void *__void__state){
errcode __result__errocode=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1180;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__816__state *__state=(struct run__816__state*)__void__state;
ptr command__contents= __state->command__contents;
u64 command__length= __state->command__length;
char command__first= __state->command__first;
ptr command__memory= __state->command__memory;
nominal __w6__p____D5=0;
ptr process__contents=0;
ptr __v6__contents=0;
bool __v6____S5__z=0;
ptr __t6__contents=0;
nominal command____c=0;
i64 __v6__status=0;
nominal process____D5=0;
ptr __u6__contents=0;
ptr __v6____R5__x=0;
bool __v6____R5__z=0;

// IMPLEMENTATION
__t6__contents = 0 ;
 __u6__contents = __t6__contents ;
 __v6__contents =( ptr ) popen (( cstr ) command__contents , "r" ); 
 __v6____R5__x = __v6__contents ;
 __v6____R5__z =( __v6____R5__x ); 
 __v6____R5____end :
 __v6____S5__z =(! __v6____R5__z ); 
 __v6____S5____end :
 if(! __v6____S5__z )goto __v6____Q5__fi ;
 goto __v6____T5 ;
 __builtin_unreachable();
 __v6____Q5__fi :
 process__contents = __v6__contents ;
 if ( process__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process__contents )) { } } 
 __w6____end :
 process____D5 = __w6__p____D5 ;
 __v6__status =0; if ( process__contents ) __v6__status = pclose (( FILE *) process__contents ); process__contents =0; if ( __v6__status ) { if ( __v6__status !=-1&& WIFEXITED ( __v6__status )) __v6__status = WEXITSTATUS ( __v6__status ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __v6__status ); __result__errocode = __USER__ERROR ; goto __failsafe ; } 
 __end :
goto __return;

// ERROR HANDLING
__v6____T5 :
 printf ( "Error: Failed to start process\n" ); 
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


void run__815(void *__void__state){
errcode __result__errocode=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1576;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__815__state *__state=(struct run__815__state*)__void__state;
ptr command__contents= __state->command__contents;
u64 command__length= __state->command__length;
char command__first= __state->command__first;
ptr command__memory= __state->command__memory;
i64 __q6____e6__status=0;
ptr __q6____e6__contents=0;
bool process____e6____I5__z=0;
cstr process____a6____qF=0;
ptr process__command__contents=0;
char __q6____a6____yF____AF=0;
bool process____e6____J5__z=0;
ptr __q6____e6____I5__x=0;
nominal process____e6____D5=0;
bool process____a6____pF__z=0;
ptr process____e6____G5__noptr=0;
nominal process____T6____D5=0;
char process__command__first=0;
ptr process____c6__contents=0;
u64 process____a6____yF__bytesize=0;
ptr __q6____a6__mem=0;
u64 process__command__length=0;
bool __q6____a6____oF=0;
ptr process__command__memory=0;
u64 process____a6__size_bytes=0;
ptr process____e6____G5____p__contents=0;
bool __q6____e6____J5__z=0;
ptr process____e6__contents=0;
char process____a6____mF=0;
char __q6____a6____wF=0;
cstr __q6__mem=0;
ptr process____e6____I5__x=0;
char __q6____Y6=0;
char __q6____a6____mF=0;
bool __q6____a6____pF__z=0;
bool process____a6____oF=0;
i64 process____e6__status=0;
char process____a6____wF=0;
ptr process____a6__mem=0;
nominal process__command____b=0;
cstr process__mem=0;
char process____e6____G5__first=0;
u64 process____W6=0;
cstr __q6____a6____qF=0;
ptr process____d6__contents=0;
u64 process____X6__z=0;
ptr __q6____e6____G5__noptr=0;
ptr __o6__contents=0;
u64 process____a6__size=0;
char process____Y6=0;
char process____a6____yF____AF=0;
u64 process____e6____G5__length=0;
ptr process____T6__contents=0;
char process__first=0;
nominal command____b=0;
ptr __p6__contents=0;
u64 __q6____W6=0;
ptr process____e6____G5__contents=0;
u64 __q6____a6__size_bytes=0;
nominal __r6__p____D5=0;
u64 __q6____a6____yF__bytesize=0;
char __q6__first=0;
ptr __q6____c6__contents=0;
u64 __q6____e6____G5__length=0;
ptr __q6____e6____G5____p__contents=0;
ptr __q6____e6____G5__contents=0;
char __q6____e6____G5__first=0;
bool __q6____e6____I5__z=0;
u64 __q6____X6__z=0;

// IMPLEMENTATION
__o6__contents = 0 ;
 __p6__contents = __o6__contents ;
 __q6____W6 = 1 ;
 __q6____X6__z = command__length + __q6____W6 ; 
 __q6____X6____end :
 __q6____Y6 = 0 ;
 __q6____a6__size_bytes = __q6____X6__z * sizeof ( __q6____a6____mF ); __q6____a6__mem =( __q6____a6__size_bytes + __service_stack_floor >=( char *)& __q6____a6__size_bytes )?0: alloca ( __q6____a6__size_bytes ); 
 __q6____a6____oF = __q6____a6__mem ;
 __q6____a6____pF__z =(! __q6____a6____oF ); 
 __q6____a6____pF____end :
 if(! __q6____a6____pF__z )goto __q6____a6____nF__fi ;
 __q6____a6____qF = "Insufficient stack for allocation (too much recursion or stack allocatio, or zero size requested)" ;
 goto __q6____a6____rF____qD ;
 __builtin_unreachable();
 __q6____a6____nF__fi :
 __q6____a6____wF = 0 ;
 __q6____a6____yF__bytesize = sizeof ( __q6____a6____yF____AF )* __q6____X6__z ; 
 __q6____a6____yF____end :
 __q6__first =0; if ( __q6____a6__mem ) { memcpy (( char *) __q6____a6__mem , command__contents , command__length );(( char *) __q6____a6__mem )[ command__length ]=0; } __q6__mem =( const char *) __q6____a6__mem ; 
 __q6____c6__contents = 0 ;
 __q6____e6____G5__length = strlen ( __q6__mem ); __q6____e6____G5__contents =( ptr ) __q6__mem ; __q6____e6____G5__first = __q6__mem [0]; __q6____e6____G5__noptr =( ptr ) __q6____e6____G5__noptr ; 
 __q6____e6____G5____p__contents = __q6____e6____G5__contents ;
 __q6____e6__contents =( ptr ) popen (( cstr ) __q6____e6____G5____p__contents , "r" ); 
 __q6____e6____I5__x = __q6____e6__contents ;
 __q6____e6____I5__z =( __q6____e6____I5__x ); 
 __q6____e6____I5____end :
 __q6____e6____J5__z =(! __q6____e6____I5__z ); 
 __q6____e6____J5____end :
 if(! __q6____e6____J5__z )goto __q6____e6____H5__fi ;
 goto __q6____e6____K5 ;
 __builtin_unreachable();
 __q6____e6____H5__fi :
 __TRANSIENT( __q6____a6__mem )
 process____e6__contents = __q6____e6__contents ;
 if ( process____e6__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process____e6__contents )) { } } 
 __r6____end :
 process____e6____D5 = __r6__p____D5 ;
 __q6____e6__status =0; if ( process____e6__contents ) __q6____e6__status = pclose (( FILE *) process____e6__contents ); process____e6__contents =0; if ( __q6____e6__status ) { if ( __q6____e6__status !=-1&& WIFEXITED ( __q6____e6__status )) __q6____e6__status = WEXITSTATUS ( __q6____e6__status ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __q6____e6__status ); __result__errocode = __USER__ERROR ; goto __failsafe ; } 
 __end :
goto __return;

// ERROR HANDLING
__q6____e6____K5 :
 printf ( "Error: Failed to start process\n" ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__q6____a6____rF____qD :
 printf ( "%s\n" , __q6____a6____qF ); 
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


void run__814(void *__void__state){
errcode __result__errocode=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1164;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct run__814__state *__state=(struct run__814__state*)__void__state;
cstr command= __state->command;
i64 __l6__status=0;
nominal __m6__p____D5=0;
bool __l6____I5__z=0;
u64 __l6____G5__length=0;
nominal process____D5=0;
ptr __l6__contents=0;
ptr process__contents=0;
ptr __j6__contents=0;
ptr __k6__contents=0;
bool __l6____J5__z=0;
char __l6____G5__first=0;
ptr __l6____G5__contents=0;
ptr __l6____G5__noptr=0;
ptr __l6____G5____p__contents=0;
ptr __l6____I5__x=0;

// IMPLEMENTATION
__j6__contents = 0 ;
 __k6__contents = __j6__contents ;
 __l6____G5__length = strlen ( command ); __l6____G5__contents =( ptr ) command ; __l6____G5__first = command [0]; __l6____G5__noptr =( ptr ) __l6____G5__noptr ; 
 __l6____G5____p__contents = __l6____G5__contents ;
 __l6__contents =( ptr ) popen (( cstr ) __l6____G5____p__contents , "r" ); 
 __l6____I5__x = __l6__contents ;
 __l6____I5__z =( __l6____I5__x ); 
 __l6____I5____end :
 __l6____J5__z =(! __l6____I5__z ); 
 __l6____J5____end :
 if(! __l6____J5__z )goto __l6____H5__fi ;
 goto __l6____K5 ;
 __builtin_unreachable();
 __l6____H5__fi :
 process__contents = __l6__contents ;
 if ( process__contents ) { char buf [ 1024 ]; while ( fread ( buf ,1, sizeof ( buf ),( FILE *) process__contents )) { } } 
 __m6____end :
 process____D5 = __m6__p____D5 ;
 __l6__status =0; if ( process__contents ) __l6__status = pclose (( FILE *) process__contents ); process__contents =0; if ( __l6__status ) { if ( __l6__status !=-1&& WIFEXITED ( __l6__status )) __l6__status = WEXITSTATUS ( __l6__status ); printf ( "Error: Process not finished or exited with non-zero exit code %ld\n" , __l6__status ); __result__errocode = __USER__ERROR ; goto __failsafe ; } 
 __end :
goto __return;

// ERROR HANDLING
__l6____K5 :
 printf ( "Error: Failed to start process\n" ); 
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


void std_test__820(void *__void__state){
errcode __result__errocode=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 2744;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__820__state *__state=(struct std_test__820__state*)__void__state;
struct run__816__state* __07____state = 0 ;
ptr name__contents= __state->name__contents;
u64 name__length= __state->name__length;
char name__first= __state->name__first;
ptr name__memory= __state->name__memory;
nominal __B8____jh__self____BQ=0;
ptr __B8____mh__contents=0;
char __B8____jh____eQ____EF=0;
u64 __B8____jh____eQ__bytesize=0;
cstr __B8____jh____WQ=0;
bool __B8____jh__success=0;
ptr __B8____jh__next_acquired=0;
bool __B8____jh____QQ=0;
char __B8____hh=0;
u64 __B8____gh__z=0;
u64 __B8__total_len=0;
u64 __B8__len_y=0;
ptr __B8____dh__noptr=0;
char __A8____Dd____eQ____EF=0;
u64 __A8____Dd____eQ__bytesize=0;
bool __B8____jh____RQ__z=0;
bool __A8____Dd____VQ__x=0;
char __A8____Dd____OQ=0;
ptr __A8____Dd__mem=0;
ptr __A8____Dd__next_acquired=0;
u64 __A8____Dd__self__allocated__prev=0;
u64 __A8____Dd__next_size=0;
cstr __A8____Dd____SQ=0;
bool __A8____Dd____QQ=0;
u64 __A8____9c=0;
u64 __A8__len_y=0;
u64 __A8__len_x=0;
ptr __A8____8c____m__contents=0;
ptr __A8____8c__noptr=0;
cstr __87=0;
ptr __67____mh__contents=0;
char __67____jh____eQ____EF=0;
char __67____jh____cQ=0;
bool __67____jh____VQ__x=0;
ptr __B8____jh__mem=0;
char __67____jh____OQ=0;
ptr __67____jh__next_acquired=0;
u64 __67____jh__next_size=0;
bool __67____jh__success=0;
cstr __67____jh____SQ=0;
bool __67____jh____RQ__z=0;
bool __67____jh____QQ=0;
char __67____hh=0;
u64 __67____gh__z=0;
u64 __67____fh=0;
char __67__first=0;
u64 __67__len_x=0;
u64 __67____dh__length=0;
nominal __57____Dd__self____BQ=0;
bool __B8____jh____VQ__x=0;
ptr __67____dh__contents=0;
cstr __57____Dd____WQ=0;
bool __57____Dd____VQ__x=0;
char __57____Dd____OQ=0;
u64 __57____Dd__self__allocated__prev=0;
ptr __67____jh__mem=0;
u64 __57____Dd__next_size=0;
bool __57____Dd__success=0;
bool __57____Dd____QQ=0;
u64 __57____Ad__z=0;
u64 __57____9c=0;
char __57__first=0;
u64 __57__total_len=0;
ptr __B8____dh__contents=0;
u64 __57__len_x=0;
char __57____8c__first=0;
cstr __47=0;
cstr __37=0;
bool __27=0;
char __B8____dh__first=0;
errcode __07__err=0;
u64 __A8____Ad__z=0;
ptr command__memory=0;
u64 command__length=0;
ptr command__contents=0;
nominal command____c=0;
u64 __x7____HQ____dynamic_entry=0;
cstr __A8____Dd____WQ=0;
cstr __67____jh____WQ=0;
bool __u7____jh__success=0;
char __A8____Bd=0;
u64 __p7____dynamic_entry=0;
char __u7____jh____eQ____EF=0;
nominal __A8____Dd__self____BQ=0;
cstr __u7____jh____WQ=0;
ptr __A8____8c__contents=0;
u64 __B8____dh__length=0;
nominal __x7____BQ=0;
char __A8__first=0;
cstr __s7=0;
u64 __A8____8c__length=0;
u64 __67____jh____eQ__bytesize=0;
char __B8____jh____cQ=0;
char __B8__first=0;
u64 __t7__total_len=0;
bool __A8____Dd__success=0;
ptr __67____dh____m__contents=0;
char __B8____jh____OQ=0;
u64 __x7____HQ____DQ=0;
u64 __t7____9c=0;
u64 __t7____Ad__z=0;
char __u7____dh__first=0;
char __u7____jh____OQ=0;
u64 __B8____jh__self__allocated__prev=0;
ptr __u7____dh__noptr=0;
u64 __p7__size=0;
bool __t7____Dd____VQ__z=0;
u64 __67__len_y=0;
u64 __57____Dd____eQ__bytesize=0;
bool __B8____jh____VQ__z=0;
char __57____Dd____cQ=0;
char __A8____Dd____cQ=0;
char __57____Dd____eQ____EF=0;
ptr __u7____dh__contents=0;
ptr __57____8c____m__contents=0;
u64 __u7____jh__next_size=0;
u64 __57__len_y=0;
ptr __A8____Gd__contents=0;
char __67____dh__first=0;
char command__first=0;
u64 __p7____HQ____dynamic_entry=0;
char __A8____8c__first=0;
u64 __67__total_len=0;
u64 __x7____dynamic_entry=0;
ptr __57____8c__contents=0;
char __t7____Bd=0;
bool __A8____Dd____VQ__z=0;
nominal __67____jh__self____BQ=0;
ptr __67____dh__noptr=0;
u64 __t7__len_x=0;
ptr __t7____Dd__mem=0;
u64 __u7____dh__length=0;
bool __A8____Dd____RQ__z=0;
char __u7__first=0;
ptr __t7____Gd__contents=0;
u64 __57____8c__length=0;
bool __57____Dd____RQ__z=0;
cstr __57____Dd____SQ=0;
cstr __u7____jh____SQ=0;
ptr __07____task=0;
cstr __B8____jh____SQ=0;
bool __u7____jh____RQ__z=0;
u64 __A8__total_len=0;
ptr __t7____8c____m__contents=0;
u64 __u7____gh__z=0;
u64 __x7__size=0;
ptr __57____Dd__next_acquired=0;
char __t7____Dd____eQ____EF=0;
ptr __57____Dd__mem=0;
bool __57____Dd____VQ__z=0;
ptr __x7__acquired=0;
ptr __p7__acquired=0;
nominal name____c=0;
char __u7____hh=0;
ptr __p7____HQ__acquired=0;
ptr __u7____jh__next_acquired=0;
u64 __p7____HQ____CQ=0;
u64 __B8____jh__next_size=0;
u64 __p7____HQ____DQ=0;
u64 __p7__allocated=0;
cstr __r7=0;
ptr __u7____dh____m__contents=0;
u64 __t7____8c__length=0;
ptr __57____Gd__contents=0;
ptr __t7____8c__contents=0;
char __57____Bd=0;
char __t7____8c__first=0;
u64 __t7__len_y=0;
bool __u7____jh____VQ__z=0;
char __t7__first=0;
bool __t7____Dd____QQ=0;
bool __t7____Dd____RQ__z=0;
cstr __t7____Dd____SQ=0;
u64 __t7____Dd__next_size=0;
u64 __u7__len_x=0;
bool __t7____Dd__success=0;
ptr __t7____Dd__next_acquired=0;
char __t7____Dd____OQ=0;
ptr __57____8c__noptr=0;
u64 __u7____jh__self__allocated__prev=0;
u64 __B8__len_x=0;
cstr __t7____Dd____WQ=0;
char __t7____Dd____cQ=0;
u64 __t7____Dd____eQ__bytesize=0;
cstr __97=0;
nominal __p7____BQ=0;
nominal __t7____Dd__self____BQ=0;
u64 __u7__len_y=0;
u64 __67____jh__self__allocated__prev=0;
u64 __u7__total_len=0;
u64 __u7____fh=0;
bool __u7____jh____QQ=0;
ptr __u7____jh__mem=0;
ptr __u7____mh__contents=0;
u64 __t7____Dd__self__allocated__prev=0;
bool __t7____Dd____VQ__x=0;
bool __u7____jh____VQ__x=0;
u64 __B8____fh=0;
char __u7____jh____cQ=0;
ptr __B8____dh____m__contents=0;
u64 __u7____jh____eQ__bytesize=0;
nominal __u7____jh__self____BQ=0;
ptr __x7____HQ__acquired=0;
ptr __t7____8c__noptr=0;
u64 __x7____HQ____CQ=0;
bool __67____jh____VQ__z=0;
u64 __x7__allocated=0;

// IMPLEMENTATION
__p7____HQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __p7____HQ__acquired )(( ptr **) __p7____HQ__acquired )[0]=0; 
 __p7____HQ____CQ = 0 ;
 __p7____HQ____DQ = 0 ;
 __p7__acquired = __p7____HQ__acquired ;
 __p7__size = __p7____HQ____CQ ;
 __p7__allocated = __p7____HQ____DQ ;
 __p7____dynamic_entry = __p7____HQ____dynamic_entry ;
 __r7 = "./smol tests/unit/" ;
 __s7 = ".s --workers 1 --runtime eager 2>&1" ;
 __t7____8c__length = strlen ( __s7 ); __t7____8c__contents =( ptr ) __s7 ; __t7____8c__first = __s7 [0]; __t7____8c__noptr =( ptr ) __t7____8c__noptr ; 
 __t7____8c____m__contents = __t7____8c__contents ;
 __t7__len_x = name__length ; __t7__len_y = __t7____8c__length ; __t7__total_len = __t7__len_x + __t7__len_y ; __t7__first = name__length ? name__first : __t7____8c__first ; 
 __t7____9c = 1 ;
 __t7____Ad__z = __t7__total_len + __t7____9c ; 
 __t7____Ad____end :
 __t7____Bd = 0 ;
 __t7____Dd____QQ = __p7__acquired ;
 __t7____Dd____RQ__z =(! __t7____Dd____QQ ); 
 __t7____Dd____RQ____end :
 if(! __t7____Dd____RQ__z )goto __t7____Dd____PQ__fi ;
 __t7____Dd____SQ = "Did not initialize Dynamic" ;
 goto __t7____Dd____TQ____qD ;
 __builtin_unreachable();
 __t7____Dd____PQ__fi :
 __t7____Dd__next_size = __p7__size +1; __t7____Dd__success = true ; __t7____Dd__self__allocated__prev = __p7__allocated ; if ( __t7____Dd__next_size >= __p7__allocated ) { __p7__allocated = __p7__allocated + __p7__allocated /2+1; __t7____Dd__next_acquired =( ptr )((( ptr **) __p7__acquired )[0]? __runtime_realloc ((( ptr **) __p7__acquired )[0], __p7__allocated * sizeof ( ptr ), __t7____Dd__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __p7__allocated * sizeof ( ptr ))); if ( __t7____Dd__success = __t7____Dd__next_acquired )(( ptr **) __p7__acquired )[0]=( ptr *) __t7____Dd__next_acquired ; } if ( __t7____Dd__success ) { __t7____Dd__mem =( ptr ) __runtime_alloc ( __t7____Ad__z * sizeof ( __t7____Dd____OQ )); if ( __t7____Dd__success = __t7____Dd__mem ) {(( ptr **) __p7__acquired )[0][ __p7__size ]= __t7____Dd__mem ; __p7__size = __t7____Dd__next_size ; } } 
 __t7____Dd____VQ__x = __t7____Dd__success ;
 __t7____Dd____VQ__z =(! __t7____Dd____VQ__x ); 
 __t7____Dd____VQ____end :
 if(! __t7____Dd____VQ__z )goto __t7____Dd____UQ__fi ;
 __t7____Dd____WQ = "Failed a Dynamic allocation" ;
 goto __t7____Dd____XQ____qD ;
 __builtin_unreachable();
 __t7____Dd____UQ__fi :
 __t7____Dd____cQ = 0 ;
 __t7____Dd____eQ__bytesize = sizeof ( __t7____Dd____eQ____EF )* __t7____Ad__z ; 
 __t7____Dd____eQ____end :
 memcpy (( char *) __t7____Dd__mem ,( char *) name__contents , __t7__len_x ); memcpy (( char *) __t7____Dd__mem + __t7__len_x ,( char *) __t7____8c____m__contents , __t7__len_y );(( char *) __t7____Dd__mem )[ __t7__total_len ]=0; 
 __t7____Gd__contents = __t7____Dd__mem ;
 __p7____BQ = __t7____Dd__self____BQ ;
 __p7__acquired = __p7__acquired ;
 __p7__size = __p7__size ;
 __p7__allocated = __p7__allocated ;
 __p7____dynamic_entry = __p7____dynamic_entry ;
 __u7____dh__length = strlen ( __r7 ); __u7____dh__contents =( ptr ) __r7 ; __u7____dh__first = __r7 [0]; __u7____dh__noptr =( ptr ) __u7____dh__noptr ; 
 __u7____dh____m__contents = __u7____dh__contents ;
 __u7__len_x = __u7____dh__length ; __u7__len_y = __t7__total_len ; __u7__total_len = __u7__len_x + __u7__len_y ; __u7__first = __u7____dh__length ? __u7____dh__first : __t7__first ; 
 __u7____fh = 1 ;
 __u7____gh__z = __u7__total_len + __u7____fh ; 
 __u7____gh____end :
 __u7____hh = 0 ;
 __u7____jh____QQ = __p7__acquired ;
 __u7____jh____RQ__z =(! __u7____jh____QQ ); 
 __u7____jh____RQ____end :
 if(! __u7____jh____RQ__z )goto __u7____jh____PQ__fi ;
 __u7____jh____SQ = "Did not initialize Dynamic" ;
 goto __u7____jh____TQ____qD ;
 __builtin_unreachable();
 __u7____jh____PQ__fi :
 __u7____jh__next_size = __p7__size +1; __u7____jh__success = true ; __u7____jh__self__allocated__prev = __p7__allocated ; if ( __u7____jh__next_size >= __p7__allocated ) { __p7__allocated = __p7__allocated + __p7__allocated /2+1; __u7____jh__next_acquired =( ptr )((( ptr **) __p7__acquired )[0]? __runtime_realloc ((( ptr **) __p7__acquired )[0], __p7__allocated * sizeof ( ptr ), __u7____jh__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __p7__allocated * sizeof ( ptr ))); if ( __u7____jh__success = __u7____jh__next_acquired )(( ptr **) __p7__acquired )[0]=( ptr *) __u7____jh__next_acquired ; } if ( __u7____jh__success ) { __u7____jh__mem =( ptr ) __runtime_alloc ( __u7____gh__z * sizeof ( __u7____jh____OQ )); if ( __u7____jh__success = __u7____jh__mem ) {(( ptr **) __p7__acquired )[0][ __p7__size ]= __u7____jh__mem ; __p7__size = __u7____jh__next_size ; } } 
 __u7____jh____VQ__x = __u7____jh__success ;
 __u7____jh____VQ__z =(! __u7____jh____VQ__x ); 
 __u7____jh____VQ____end :
 if(! __u7____jh____VQ__z )goto __u7____jh____UQ__fi ;
 __u7____jh____WQ = "Failed a Dynamic allocation" ;
 goto __u7____jh____XQ____qD ;
 __builtin_unreachable();
 __u7____jh____UQ__fi :
 __u7____jh____cQ = 0 ;
 __u7____jh____eQ__bytesize = sizeof ( __u7____jh____eQ____EF )* __u7____gh__z ; 
 __u7____jh____eQ____end :
 memcpy (( char *) __u7____jh__mem ,( char *) __u7____dh____m__contents , __u7__len_x ); memcpy (( char *) __u7____jh__mem + __u7__len_x ,( char *) __t7____Gd__contents , __u7__len_y );(( char *) __u7____jh__mem )[ __u7__total_len ]=0; 
 __u7____mh__contents = __u7____jh__mem ;
 __p7____BQ = __u7____jh__self____BQ ;
 __p7__acquired = __p7__acquired ;
 __p7__size = __p7__size ;
 __p7__allocated = __p7__allocated ;
 __p7____dynamic_entry = __p7____dynamic_entry ;
 __x7____HQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __x7____HQ__acquired )(( ptr **) __x7____HQ__acquired )[0]=0; 
 __x7____HQ____CQ = 0 ;
 __x7____HQ____DQ = 0 ;
 __x7__acquired = __x7____HQ__acquired ;
 __x7__size = __x7____HQ____CQ ;
 __x7__allocated = __x7____HQ____DQ ;
 __x7____dynamic_entry = __x7____HQ____dynamic_entry ;
 {char mark;if(__service_stack_floor+ 1180 >=(char*)&mark) goto __service_stack_floor_handler;} __07____state = (struct run__816__state*)__runtime_calloc(sizeof(struct run__816__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __07____state ) ;
 __07____state -> command____c = command____c ;
 __07____state -> command__contents = __u7____mh__contents ;
 __07____state -> command__length = __u7__total_len ;
 __07____state -> command__first = __u7__first ;
 __07____state -> command__memory = __p7__acquired ;
 __07____task = __smolambda_add_task ( run__816 , __07____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __07____task ) ;
 if( __07__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __07____task ) ;
 __07__err = __07____state -> err ;
 __27 = __07__err ;
 if(! __27 )goto __z7__fi ;
 __37 = "[ \033[31mERROR\033[0m ] " ;
 __47 = ".s" ;
 __57____8c__length = strlen ( __47 ); __57____8c__contents =( ptr ) __47 ; __57____8c__first = __47 [0]; __57____8c__noptr =( ptr ) __57____8c__noptr ; 
 __57____8c____m__contents = __57____8c__contents ;
 __57__len_x = name__length ; __57__len_y = __57____8c__length ; __57__total_len = __57__len_x + __57__len_y ; __57__first = name__length ? name__first : __57____8c__first ; 
 __57____9c = 1 ;
 __57____Ad__z = __57__total_len + __57____9c ; 
 __57____Ad____end :
 __57____Bd = 0 ;
 __57____Dd____QQ = __x7__acquired ;
 __57____Dd____RQ__z =(! __57____Dd____QQ ); 
 __57____Dd____RQ____end :
 if(! __57____Dd____RQ__z )goto __57____Dd____PQ__fi ;
 __57____Dd____SQ = "Did not initialize Dynamic" ;
 goto __57____Dd____TQ____qD ;
 __builtin_unreachable();
 __57____Dd____PQ__fi :
 __57____Dd__next_size = __x7__size +1; __57____Dd__success = true ; __57____Dd__self__allocated__prev = __x7__allocated ; if ( __57____Dd__next_size >= __x7__allocated ) { __x7__allocated = __x7__allocated + __x7__allocated /2+1; __57____Dd__next_acquired =( ptr )((( ptr **) __x7__acquired )[0]? __runtime_realloc ((( ptr **) __x7__acquired )[0], __x7__allocated * sizeof ( ptr ), __57____Dd__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __x7__allocated * sizeof ( ptr ))); if ( __57____Dd__success = __57____Dd__next_acquired )(( ptr **) __x7__acquired )[0]=( ptr *) __57____Dd__next_acquired ; } if ( __57____Dd__success ) { __57____Dd__mem =( ptr ) __runtime_alloc ( __57____Ad__z * sizeof ( __57____Dd____OQ )); if ( __57____Dd__success = __57____Dd__mem ) {(( ptr **) __x7__acquired )[0][ __x7__size ]= __57____Dd__mem ; __x7__size = __57____Dd__next_size ; } } 
 __57____Dd____VQ__x = __57____Dd__success ;
 __57____Dd____VQ__z =(! __57____Dd____VQ__x ); 
 __57____Dd____VQ____end :
 if(! __57____Dd____VQ__z )goto __57____Dd____UQ__fi ;
 __57____Dd____WQ = "Failed a Dynamic allocation" ;
 goto __57____Dd____XQ____qD ;
 __builtin_unreachable();
 __57____Dd____UQ__fi :
 __57____Dd____cQ = 0 ;
 __57____Dd____eQ__bytesize = sizeof ( __57____Dd____eQ____EF )* __57____Ad__z ; 
 __57____Dd____eQ____end :
 memcpy (( char *) __57____Dd__mem ,( char *) name__contents , __57__len_x ); memcpy (( char *) __57____Dd__mem + __57__len_x ,( char *) __57____8c____m__contents , __57__len_y );(( char *) __57____Dd__mem )[ __57__total_len ]=0; 
 __57____Gd__contents = __57____Dd__mem ;
 __x7____BQ = __57____Dd__self____BQ ;
 __x7__acquired = __x7__acquired ;
 __x7__size = __x7__size ;
 __x7__allocated = __x7__allocated ;
 __x7____dynamic_entry = __x7____dynamic_entry ;
 __67____dh__length = strlen ( __37 ); __67____dh__contents =( ptr ) __37 ; __67____dh__first = __37 [0]; __67____dh__noptr =( ptr ) __67____dh__noptr ; 
 __67____dh____m__contents = __67____dh__contents ;
 __67__len_x = __67____dh__length ; __67__len_y = __57__total_len ; __67__total_len = __67__len_x + __67__len_y ; __67__first = __67____dh__length ? __67____dh__first : __57__first ; 
 __67____fh = 1 ;
 __67____gh__z = __67__total_len + __67____fh ; 
 __67____gh____end :
 __67____hh = 0 ;
 __67____jh____QQ = __x7__acquired ;
 __67____jh____RQ__z =(! __67____jh____QQ ); 
 __67____jh____RQ____end :
 if(! __67____jh____RQ__z )goto __67____jh____PQ__fi ;
 __67____jh____SQ = "Did not initialize Dynamic" ;
 goto __67____jh____TQ____qD ;
 __builtin_unreachable();
 __67____jh____PQ__fi :
 __67____jh__next_size = __x7__size +1; __67____jh__success = true ; __67____jh__self__allocated__prev = __x7__allocated ; if ( __67____jh__next_size >= __x7__allocated ) { __x7__allocated = __x7__allocated + __x7__allocated /2+1; __67____jh__next_acquired =( ptr )((( ptr **) __x7__acquired )[0]? __runtime_realloc ((( ptr **) __x7__acquired )[0], __x7__allocated * sizeof ( ptr ), __67____jh__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __x7__allocated * sizeof ( ptr ))); if ( __67____jh__success = __67____jh__next_acquired )(( ptr **) __x7__acquired )[0]=( ptr *) __67____jh__next_acquired ; } if ( __67____jh__success ) { __67____jh__mem =( ptr ) __runtime_alloc ( __67____gh__z * sizeof ( __67____jh____OQ )); if ( __67____jh__success = __67____jh__mem ) {(( ptr **) __x7__acquired )[0][ __x7__size ]= __67____jh__mem ; __x7__size = __67____jh__next_size ; } } 
 __67____jh____VQ__x = __67____jh__success ;
 __67____jh____VQ__z =(! __67____jh____VQ__x ); 
 __67____jh____VQ____end :
 if(! __67____jh____VQ__z )goto __67____jh____UQ__fi ;
 __67____jh____WQ = "Failed a Dynamic allocation" ;
 goto __67____jh____XQ____qD ;
 __builtin_unreachable();
 __67____jh____UQ__fi :
 __67____jh____cQ = 0 ;
 __67____jh____eQ__bytesize = sizeof ( __67____jh____eQ____EF )* __67____gh__z ; 
 __67____jh____eQ____end :
 memcpy (( char *) __67____jh__mem ,( char *) __67____dh____m__contents , __67__len_x ); memcpy (( char *) __67____jh__mem + __67__len_x ,( char *) __57____Gd__contents , __67__len_y );(( char *) __67____jh__mem )[ __67__total_len ]=0; 
 __67____mh__contents = __67____jh__mem ;
 __x7____BQ = __67____jh__self____BQ ;
 __x7__acquired = __x7__acquired ;
 __x7__size = __x7__size ;
 __x7__allocated = __x7__allocated ;
 __x7____dynamic_entry = __x7____dynamic_entry ;
 printf ( "%s\n" ,( char *) __67____mh__contents ); 
 __77____end :
 goto __z7__el ;
 __z7__fi :
 __87 = "[ \033[32mOK\033[0m ] " ;
 __97 = ".s" ;
 __A8____8c__length = strlen ( __97 ); __A8____8c__contents =( ptr ) __97 ; __A8____8c__first = __97 [0]; __A8____8c__noptr =( ptr ) __A8____8c__noptr ; 
 __A8____8c____m__contents = __A8____8c__contents ;
 __A8__len_x = name__length ; __A8__len_y = __A8____8c__length ; __A8__total_len = __A8__len_x + __A8__len_y ; __A8__first = name__length ? name__first : __A8____8c__first ; 
 __A8____9c = 1 ;
 __A8____Ad__z = __A8__total_len + __A8____9c ; 
 __A8____Ad____end :
 __A8____Bd = 0 ;
 __A8____Dd____QQ = __x7__acquired ;
 __A8____Dd____RQ__z =(! __A8____Dd____QQ ); 
 __A8____Dd____RQ____end :
 if(! __A8____Dd____RQ__z )goto __A8____Dd____PQ__fi ;
 __A8____Dd____SQ = "Did not initialize Dynamic" ;
 goto __A8____Dd____TQ____qD ;
 __builtin_unreachable();
 __A8____Dd____PQ__fi :
 __A8____Dd__next_size = __x7__size +1; __A8____Dd__success = true ; __A8____Dd__self__allocated__prev = __x7__allocated ; if ( __A8____Dd__next_size >= __x7__allocated ) { __x7__allocated = __x7__allocated + __x7__allocated /2+1; __A8____Dd__next_acquired =( ptr )((( ptr **) __x7__acquired )[0]? __runtime_realloc ((( ptr **) __x7__acquired )[0], __x7__allocated * sizeof ( ptr ), __A8____Dd__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __x7__allocated * sizeof ( ptr ))); if ( __A8____Dd__success = __A8____Dd__next_acquired )(( ptr **) __x7__acquired )[0]=( ptr *) __A8____Dd__next_acquired ; } if ( __A8____Dd__success ) { __A8____Dd__mem =( ptr ) __runtime_alloc ( __A8____Ad__z * sizeof ( __A8____Dd____OQ )); if ( __A8____Dd__success = __A8____Dd__mem ) {(( ptr **) __x7__acquired )[0][ __x7__size ]= __A8____Dd__mem ; __x7__size = __A8____Dd__next_size ; } } 
 __A8____Dd____VQ__x = __A8____Dd__success ;
 __A8____Dd____VQ__z =(! __A8____Dd____VQ__x ); 
 __A8____Dd____VQ____end :
 if(! __A8____Dd____VQ__z )goto __A8____Dd____UQ__fi ;
 __A8____Dd____WQ = "Failed a Dynamic allocation" ;
 goto __A8____Dd____XQ____qD ;
 __builtin_unreachable();
 __A8____Dd____UQ__fi :
 __A8____Dd____cQ = 0 ;
 __A8____Dd____eQ__bytesize = sizeof ( __A8____Dd____eQ____EF )* __A8____Ad__z ; 
 __A8____Dd____eQ____end :
 memcpy (( char *) __A8____Dd__mem ,( char *) name__contents , __A8__len_x ); memcpy (( char *) __A8____Dd__mem + __A8__len_x ,( char *) __A8____8c____m__contents , __A8__len_y );(( char *) __A8____Dd__mem )[ __A8__total_len ]=0; 
 __A8____Gd__contents = __A8____Dd__mem ;
 __x7____BQ = __A8____Dd__self____BQ ;
 __x7__acquired = __x7__acquired ;
 __x7__size = __x7__size ;
 __x7__allocated = __x7__allocated ;
 __x7____dynamic_entry = __x7____dynamic_entry ;
 __B8____dh__length = strlen ( __87 ); __B8____dh__contents =( ptr ) __87 ; __B8____dh__first = __87 [0]; __B8____dh__noptr =( ptr ) __B8____dh__noptr ; 
 __B8____dh____m__contents = __B8____dh__contents ;
 __B8__len_x = __B8____dh__length ; __B8__len_y = __A8__total_len ; __B8__total_len = __B8__len_x + __B8__len_y ; __B8__first = __B8____dh__length ? __B8____dh__first : __A8__first ; 
 __B8____fh = 1 ;
 __B8____gh__z = __B8__total_len + __B8____fh ; 
 __B8____gh____end :
 __B8____hh = 0 ;
 __B8____jh____QQ = __x7__acquired ;
 __B8____jh____RQ__z =(! __B8____jh____QQ ); 
 __B8____jh____RQ____end :
 if(! __B8____jh____RQ__z )goto __B8____jh____PQ__fi ;
 __B8____jh____SQ = "Did not initialize Dynamic" ;
 goto __B8____jh____TQ____qD ;
 __builtin_unreachable();
 __B8____jh____PQ__fi :
 __B8____jh__next_size = __x7__size +1; __B8____jh__success = true ; __B8____jh__self__allocated__prev = __x7__allocated ; if ( __B8____jh__next_size >= __x7__allocated ) { __x7__allocated = __x7__allocated + __x7__allocated /2+1; __B8____jh__next_acquired =( ptr )((( ptr **) __x7__acquired )[0]? __runtime_realloc ((( ptr **) __x7__acquired )[0], __x7__allocated * sizeof ( ptr ), __B8____jh__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __x7__allocated * sizeof ( ptr ))); if ( __B8____jh__success = __B8____jh__next_acquired )(( ptr **) __x7__acquired )[0]=( ptr *) __B8____jh__next_acquired ; } if ( __B8____jh__success ) { __B8____jh__mem =( ptr ) __runtime_alloc ( __B8____gh__z * sizeof ( __B8____jh____OQ )); if ( __B8____jh__success = __B8____jh__mem ) {(( ptr **) __x7__acquired )[0][ __x7__size ]= __B8____jh__mem ; __x7__size = __B8____jh__next_size ; } } 
 __B8____jh____VQ__x = __B8____jh__success ;
 __B8____jh____VQ__z =(! __B8____jh____VQ__x ); 
 __B8____jh____VQ____end :
 if(! __B8____jh____VQ__z )goto __B8____jh____UQ__fi ;
 __B8____jh____WQ = "Failed a Dynamic allocation" ;
 goto __B8____jh____XQ____qD ;
 __builtin_unreachable();
 __B8____jh____UQ__fi :
 __B8____jh____cQ = 0 ;
 __B8____jh____eQ__bytesize = sizeof ( __B8____jh____eQ____EF )* __B8____gh__z ; 
 __B8____jh____eQ____end :
 memcpy (( char *) __B8____jh__mem ,( char *) __B8____dh____m__contents , __B8__len_x ); memcpy (( char *) __B8____jh__mem + __B8__len_x ,( char *) __A8____Gd__contents , __B8__len_y );(( char *) __B8____jh__mem )[ __B8__total_len ]=0; 
 __B8____mh__contents = __B8____jh__mem ;
 __x7____BQ = __B8____jh__self____BQ ;
 __x7__acquired = __x7__acquired ;
 __x7__size = __x7__size ;
 __x7__allocated = __x7__allocated ;
 __x7____dynamic_entry = __x7____dynamic_entry ;
 printf ( "%s\n" ,( char *) __B8____mh__contents ); 
 __C8____end :
 __z7__el :
 __end :
goto __return;

// ERROR HANDLING
__17 :
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
__57____Dd____XQ____qD :
 printf ( "%s\n" , __57____Dd____WQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__67____jh____TQ____qD :
 printf ( "%s\n" , __67____jh____SQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__67____jh____XQ____qD :
 printf ( "%s\n" , __67____jh____WQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__B8____jh____TQ____qD :
 printf ( "%s\n" , __B8____jh____SQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__A8____Dd____XQ____qD :
 printf ( "%s\n" , __A8____Dd____WQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__t7____Dd____TQ____qD :
 printf ( "%s\n" , __t7____Dd____SQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__u7____jh____XQ____qD :
 printf ( "%s\n" , __u7____jh____WQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__B8____jh____XQ____qD :
 printf ( "%s\n" , __B8____jh____WQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__t7____Dd____XQ____qD :
 printf ( "%s\n" , __t7____Dd____WQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__u7____jh____TQ____qD :
 printf ( "%s\n" , __u7____jh____SQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__A8____Dd____TQ____qD :
 printf ( "%s\n" , __A8____Dd____SQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__service_stack_floor_handler:
printf("Insufficient stack for safe service call (too much recursion or stack allocation)\n");
__result__errocode=__STACK__ERROR;
goto __failsafe;
__57____Dd____TQ____qD :
 printf ( "%s\n" , __57____Dd____SQ ); 
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
if ( __x7__acquired ) { for ( __x7____dynamic_entry =0; __x7____dynamic_entry < __x7__size ;++ __x7____dynamic_entry ) { __runtime_free ((( ptr **) __x7__acquired )[0][ __x7____dynamic_entry ]); } __runtime_free ( __x7__acquired ); __x7__acquired =0; __x7__size =0; __x7__allocated =0; } 
 if ( __x7__acquired ) { for ( __x7____HQ____dynamic_entry =0; __x7____HQ____dynamic_entry < __x7____HQ____CQ ;++ __x7____HQ____dynamic_entry ) { __runtime_free ((( ptr **) __x7__acquired )[0][ __x7____HQ____dynamic_entry ]); } __runtime_free ( __x7__acquired ); __x7__acquired =0; __x7____HQ____CQ =0; __x7____HQ____DQ =0; } 
if ( __p7__acquired ) { for ( __p7____dynamic_entry =0; __p7____dynamic_entry < __p7__size ;++ __p7____dynamic_entry ) { __runtime_free ((( ptr **) __p7__acquired )[0][ __p7____dynamic_entry ]); } __runtime_free ( __p7__acquired ); __p7__acquired =0; __p7__size =0; __p7__allocated =0; } 
 if ( __p7__acquired ) { for ( __p7____HQ____dynamic_entry =0; __p7____HQ____dynamic_entry < __p7____HQ____CQ ;++ __p7____HQ____dynamic_entry ) { __runtime_free ((( ptr **) __p7__acquired )[0][ __p7____HQ____dynamic_entry ]); } __runtime_free ( __p7__acquired ); __p7__acquired =0; __p7____HQ____CQ =0; __p7____HQ____DQ =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}


void std_test__819(void *__void__state){
errcode __result__errocode=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 2720;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__819__state *__state=(struct std_test__819__state*)__void__state;
struct run__816__state* __a7____state = 0 ;
ptr name__contents= __state->name__contents;
u64 name__length= __state->name__length;
char name__first= __state->name__first;
ptr name__memory= __state->name__memory;
nominal __l7____jh__self____BQ=0;
ptr __l7____mh__contents=0;
u64 __l7____jh____eQ__bytesize=0;
char __l7____jh____cQ=0;
bool __l7____jh____VQ__z=0;
char __l7____jh____OQ=0;
ptr __l7____jh__mem=0;
ptr __l7____jh__next_acquired=0;
u64 __l7____jh__self__allocated__prev=0;
bool __l7____jh__success=0;
cstr __l7____jh____SQ=0;
bool __l7____jh____RQ__z=0;
char __l7____hh=0;
u64 __l7____gh__z=0;
u64 __l7____fh=0;
u64 __l7__len_y=0;
ptr __l7____dh____m__contents=0;
char __l7____dh__first=0;
char __k7____5b____cQ=0;
u64 __l7__total_len=0;
bool __k7____5b____VQ__x=0;
char __k7____5b____OQ=0;
bool __k7____5b__success=0;
cstr __k7____5b____SQ=0;
bool __k7____5b____QQ=0;
u64 __k7____2b__z=0;
char __k7____5b____eQ____EF=0;
u64 __k7____1b=0;
char __k7__first=0;
ptr __k7____0b____m__contents=0;
char __k7____0b__first=0;
ptr __k7____0b__contents=0;
cstr __i7=0;
nominal __g7____jh__self____BQ=0;
ptr __g7____mh__contents=0;
char __g7____jh____cQ=0;
bool __g7____jh____VQ__z=0;
bool __g7____jh____VQ__x=0;
ptr __g7____jh__mem=0;
ptr __g7____jh__next_acquired=0;
u64 __l7____dh__length=0;
u64 __g7____jh__self__allocated__prev=0;
cstr __j7=0;
bool __g7____jh____RQ__z=0;
char __g7____hh=0;
char __g7__first=0;
ptr __g7____dh__noptr=0;
u64 __l7__len_x=0;
bool __k7____5b____VQ__z=0;
char __g7____dh__first=0;
char __g7____jh____eQ____EF=0;
ptr __g7____dh__contents=0;
nominal __f7____5b__self____BQ=0;
nominal __X7____BQ=0;
ptr __f7____8b__contents=0;
char __f7____5b____eQ____EF=0;
char __f7____5b____cQ=0;
cstr __f7____5b____WQ=0;
char __f7____5b____OQ=0;
bool __f7____5b__success=0;
bool __f7____5b____RQ__z=0;
bool __f7____5b____QQ=0;
u64 __f7____2b__z=0;
char __f7__first=0;
nominal __k7____5b__self____BQ=0;
u64 __f7__total_len=0;
u64 __f7__len_y=0;
u64 __f7__len_x=0;
ptr __f7____0b____m__contents=0;
char __f7____0b__first=0;
ptr __f7____0b__contents=0;
u64 __f7____0b__length=0;
cstr __g7____jh____SQ=0;
cstr __e7=0;
bool __c7=0;
errcode __a7__err=0;
char __T7____5b____cQ=0;
ptr __k7____5b__mem=0;
u64 __g7____dh__length=0;
ptr __U7____jh__next_acquired=0;
cstr __f7____5b____SQ=0;
cstr __U7____jh____SQ=0;
ptr __f7____5b__mem=0;
char __T7____0b__first=0;
bool __g7____jh__success=0;
u64 __k7____5b__next_size=0;
u64 __T7____0b__length=0;
u64 __U7__len_x=0;
u64 __f7____5b__next_size=0;
u64 __f7____5b____eQ__bytesize=0;
char __T7__first=0;
cstr __k7____5b____WQ=0;
ptr __T7____8b__contents=0;
char __f7____3b=0;
char __U7____hh=0;
ptr __g7____dh____m__contents=0;
ptr __f7____5b__next_acquired=0;
ptr __X7__acquired=0;
bool __f7____5b____VQ__x=0;
u64 __f7____1b=0;
u64 __U7__total_len=0;
u64 __l7____jh__next_size=0;
bool __f7____5b____VQ__z=0;
char __U7__first=0;
cstr __U7____jh____WQ=0;
u64 __g7____gh__z=0;
u64 __g7__len_y=0;
char __U7____jh____eQ____EF=0;
cstr __S7=0;
u64 __k7____5b____eQ__bytesize=0;
u64 __k7____0b__length=0;
u64 __X7____HQ____CQ=0;
u64 __T7__total_len=0;
bool __g7____jh____QQ=0;
u64 __k7__len_y=0;
u64 __k7____5b__self__allocated__prev=0;
u64 __P7____HQ____DQ=0;
u64 __T7__len_x=0;
ptr __f7____0b__noptr=0;
char __U7____jh____OQ=0;
ptr __k7____0b__noptr=0;
bool __U7____jh____VQ__z=0;
ptr __k7____5b__next_acquired=0;
cstr __l7____jh____WQ=0;
char __k7____3b=0;
nominal __U7____jh__self____BQ=0;
ptr __U7____dh____m__contents=0;
bool __U7____jh__success=0;
ptr __T7____0b__contents=0;
cstr __g7____jh____WQ=0;
u64 __U7____gh__z=0;
u64 __P7__allocated=0;
u64 __T7____2b__z=0;
u64 command__length=0;
u64 __k7__len_x=0;
u64 __T7__len_y=0;
u64 __T7____5b__self__allocated__prev=0;
ptr __P7__acquired=0;
nominal name____b=0;
ptr __U7____dh__contents=0;
ptr __l7____dh__noptr=0;
u64 __P7____HQ____CQ=0;
u64 __P7__size=0;
ptr __T7____0b____m__contents=0;
u64 __P7____HQ____dynamic_entry=0;
char __g7____jh____OQ=0;
cstr __R7=0;
ptr __P7____HQ__acquired=0;
ptr __T7____0b__noptr=0;
u64 __g7____jh__next_size=0;
char __U7____dh__first=0;
u64 __g7____fh=0;
char __T7____3b=0;
bool __T7____5b____QQ=0;
bool __T7____5b____RQ__z=0;
u64 __g7__len_x=0;
bool __T7____5b__success=0;
u64 __P7____dynamic_entry=0;
ptr __U7____jh__mem=0;
u64 __T7____5b__next_size=0;
ptr __T7____5b__next_acquired=0;
ptr __T7____5b__mem=0;
bool __l7____jh____QQ=0;
ptr __k7____8b__contents=0;
char __T7____5b____OQ=0;
bool __T7____5b____VQ__z=0;
u64 __f7____5b__self__allocated__prev=0;
u64 __k7__total_len=0;
u64 __T7____5b____eQ__bytesize=0;
char __T7____5b____eQ____EF=0;
char __l7____jh____eQ____EF=0;
u64 __g7____jh____eQ__bytesize=0;
nominal __P7____BQ=0;
bool __l7____jh____VQ__x=0;
u64 __X7__allocated=0;
nominal __T7____5b__self____BQ=0;
u64 __U7____dh__length=0;
cstr __d7=0;
ptr __U7____dh__noptr=0;
u64 __U7__len_y=0;
u64 __U7____fh=0;
char __l7__first=0;
bool __k7____5b____RQ__z=0;
u64 __T7____1b=0;
bool __U7____jh____QQ=0;
u64 __g7__total_len=0;
bool __U7____jh____RQ__z=0;
bool __T7____5b____VQ__x=0;
u64 __U7____jh__next_size=0;
u64 __U7____jh__self__allocated__prev=0;
ptr __l7____dh__contents=0;
bool __U7____jh____VQ__x=0;
char __U7____jh____cQ=0;
u64 __U7____jh____eQ__bytesize=0;
ptr __U7____mh__contents=0;
ptr __X7____HQ__acquired=0;
ptr __a7____task=0;
cstr __T7____5b____WQ=0;
u64 __X7____HQ____DQ=0;
u64 __X7__size=0;
u64 __X7____dynamic_entry=0;
u64 __X7____HQ____dynamic_entry=0;
cstr __T7____5b____SQ=0;
nominal command____c=0;
ptr command__contents=0;
char command__first=0;
ptr command__memory=0;

// IMPLEMENTATION
__P7____HQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __P7____HQ__acquired )(( ptr **) __P7____HQ__acquired )[0]=0; 
 __P7____HQ____CQ = 0 ;
 __P7____HQ____DQ = 0 ;
 __P7__acquired = __P7____HQ__acquired ;
 __P7__size = __P7____HQ____CQ ;
 __P7__allocated = __P7____HQ____DQ ;
 __P7____dynamic_entry = __P7____HQ____dynamic_entry ;
 __R7 = "./smol tests/unit/" ;
 __S7 = ".s --workers 1 --runtime eager 2>&1" ;
 __T7____0b__length = strlen ( __S7 ); __T7____0b__contents =( ptr ) __S7 ; __T7____0b__first = __S7 [0]; __T7____0b__noptr =( ptr ) __T7____0b__noptr ; 
 __T7____0b____m__contents = __T7____0b__contents ;
 __T7__len_x = name__length ; __T7__len_y = __T7____0b__length ; __T7__total_len = __T7__len_x + __T7__len_y ; __T7__first = name__length ? name__first : __T7____0b__first ; 
 __T7____1b = 1 ;
 __T7____2b__z = __T7__total_len + __T7____1b ; 
 __T7____2b____end :
 __T7____3b = 0 ;
 __T7____5b____QQ = __P7__acquired ;
 __T7____5b____RQ__z =(! __T7____5b____QQ ); 
 __T7____5b____RQ____end :
 if(! __T7____5b____RQ__z )goto __T7____5b____PQ__fi ;
 __T7____5b____SQ = "Did not initialize Dynamic" ;
 goto __T7____5b____TQ____qD ;
 __builtin_unreachable();
 __T7____5b____PQ__fi :
 __T7____5b__next_size = __P7__size +1; __T7____5b__success = true ; __T7____5b__self__allocated__prev = __P7__allocated ; if ( __T7____5b__next_size >= __P7__allocated ) { __P7__allocated = __P7__allocated + __P7__allocated /2+1; __T7____5b__next_acquired =( ptr )((( ptr **) __P7__acquired )[0]? __runtime_realloc ((( ptr **) __P7__acquired )[0], __P7__allocated * sizeof ( ptr ), __T7____5b__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __P7__allocated * sizeof ( ptr ))); if ( __T7____5b__success = __T7____5b__next_acquired )(( ptr **) __P7__acquired )[0]=( ptr *) __T7____5b__next_acquired ; } if ( __T7____5b__success ) { __T7____5b__mem =( ptr ) __runtime_alloc ( __T7____2b__z * sizeof ( __T7____5b____OQ )); if ( __T7____5b__success = __T7____5b__mem ) {(( ptr **) __P7__acquired )[0][ __P7__size ]= __T7____5b__mem ; __P7__size = __T7____5b__next_size ; } } 
 __T7____5b____VQ__x = __T7____5b__success ;
 __T7____5b____VQ__z =(! __T7____5b____VQ__x ); 
 __T7____5b____VQ____end :
 if(! __T7____5b____VQ__z )goto __T7____5b____UQ__fi ;
 __T7____5b____WQ = "Failed a Dynamic allocation" ;
 goto __T7____5b____XQ____qD ;
 __builtin_unreachable();
 __T7____5b____UQ__fi :
 __T7____5b____cQ = 0 ;
 __T7____5b____eQ__bytesize = sizeof ( __T7____5b____eQ____EF )* __T7____2b__z ; 
 __T7____5b____eQ____end :
 memcpy (( char *) __T7____5b__mem ,( char *) name__contents , __T7__len_x ); memcpy (( char *) __T7____5b__mem + __T7__len_x ,( char *) __T7____0b____m__contents , __T7__len_y );(( char *) __T7____5b__mem )[ __T7__total_len ]=0; 
 __T7____8b__contents = __T7____5b__mem ;
 __P7____BQ = __T7____5b__self____BQ ;
 __P7__acquired = __P7__acquired ;
 __P7__size = __P7__size ;
 __P7__allocated = __P7__allocated ;
 __P7____dynamic_entry = __P7____dynamic_entry ;
 __U7____dh__length = strlen ( __R7 ); __U7____dh__contents =( ptr ) __R7 ; __U7____dh__first = __R7 [0]; __U7____dh__noptr =( ptr ) __U7____dh__noptr ; 
 __U7____dh____m__contents = __U7____dh__contents ;
 __U7__len_x = __U7____dh__length ; __U7__len_y = __T7__total_len ; __U7__total_len = __U7__len_x + __U7__len_y ; __U7__first = __U7____dh__length ? __U7____dh__first : __T7__first ; 
 __U7____fh = 1 ;
 __U7____gh__z = __U7__total_len + __U7____fh ; 
 __U7____gh____end :
 __U7____hh = 0 ;
 __U7____jh____QQ = __P7__acquired ;
 __U7____jh____RQ__z =(! __U7____jh____QQ ); 
 __U7____jh____RQ____end :
 if(! __U7____jh____RQ__z )goto __U7____jh____PQ__fi ;
 __U7____jh____SQ = "Did not initialize Dynamic" ;
 goto __U7____jh____TQ____qD ;
 __builtin_unreachable();
 __U7____jh____PQ__fi :
 __U7____jh__next_size = __P7__size +1; __U7____jh__success = true ; __U7____jh__self__allocated__prev = __P7__allocated ; if ( __U7____jh__next_size >= __P7__allocated ) { __P7__allocated = __P7__allocated + __P7__allocated /2+1; __U7____jh__next_acquired =( ptr )((( ptr **) __P7__acquired )[0]? __runtime_realloc ((( ptr **) __P7__acquired )[0], __P7__allocated * sizeof ( ptr ), __U7____jh__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __P7__allocated * sizeof ( ptr ))); if ( __U7____jh__success = __U7____jh__next_acquired )(( ptr **) __P7__acquired )[0]=( ptr *) __U7____jh__next_acquired ; } if ( __U7____jh__success ) { __U7____jh__mem =( ptr ) __runtime_alloc ( __U7____gh__z * sizeof ( __U7____jh____OQ )); if ( __U7____jh__success = __U7____jh__mem ) {(( ptr **) __P7__acquired )[0][ __P7__size ]= __U7____jh__mem ; __P7__size = __U7____jh__next_size ; } } 
 __U7____jh____VQ__x = __U7____jh__success ;
 __U7____jh____VQ__z =(! __U7____jh____VQ__x ); 
 __U7____jh____VQ____end :
 if(! __U7____jh____VQ__z )goto __U7____jh____UQ__fi ;
 __U7____jh____WQ = "Failed a Dynamic allocation" ;
 goto __U7____jh____XQ____qD ;
 __builtin_unreachable();
 __U7____jh____UQ__fi :
 __U7____jh____cQ = 0 ;
 __U7____jh____eQ__bytesize = sizeof ( __U7____jh____eQ____EF )* __U7____gh__z ; 
 __U7____jh____eQ____end :
 memcpy (( char *) __U7____jh__mem ,( char *) __U7____dh____m__contents , __U7__len_x ); memcpy (( char *) __U7____jh__mem + __U7__len_x ,( char *) __T7____8b__contents , __U7__len_y );(( char *) __U7____jh__mem )[ __U7__total_len ]=0; 
 __U7____mh__contents = __U7____jh__mem ;
 __P7____BQ = __U7____jh__self____BQ ;
 __P7__acquired = __P7__acquired ;
 __P7__size = __P7__size ;
 __P7__allocated = __P7__allocated ;
 __P7____dynamic_entry = __P7____dynamic_entry ;
 __X7____HQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __X7____HQ__acquired )(( ptr **) __X7____HQ__acquired )[0]=0; 
 __X7____HQ____CQ = 0 ;
 __X7____HQ____DQ = 0 ;
 __X7__acquired = __X7____HQ__acquired ;
 __X7__size = __X7____HQ____CQ ;
 __X7__allocated = __X7____HQ____DQ ;
 __X7____dynamic_entry = __X7____HQ____dynamic_entry ;
 {char mark;if(__service_stack_floor+ 1180 >=(char*)&mark) goto __service_stack_floor_handler;} __a7____state = (struct run__816__state*)__runtime_calloc(sizeof(struct run__816__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __a7____state ) ;
 __a7____state -> command____c = command____c ;
 __a7____state -> command__contents = __U7____mh__contents ;
 __a7____state -> command__length = __U7__total_len ;
 __a7____state -> command__first = __U7__first ;
 __a7____state -> command__memory = __P7__acquired ;
 __a7____task = __smolambda_add_task ( run__816 , __a7____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __a7____task ) ;
 if( __a7__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __a7____task ) ;
 __a7__err = __a7____state -> err ;
 __c7 = __a7__err ;
 if(! __c7 )goto __Z7__fi ;
 __d7 = "[ \033[31mERROR\033[0m ] " ;
 __e7 = ".s" ;
 __f7____0b__length = strlen ( __e7 ); __f7____0b__contents =( ptr ) __e7 ; __f7____0b__first = __e7 [0]; __f7____0b__noptr =( ptr ) __f7____0b__noptr ; 
 __f7____0b____m__contents = __f7____0b__contents ;
 __f7__len_x = name__length ; __f7__len_y = __f7____0b__length ; __f7__total_len = __f7__len_x + __f7__len_y ; __f7__first = name__length ? name__first : __f7____0b__first ; 
 __f7____1b = 1 ;
 __f7____2b__z = __f7__total_len + __f7____1b ; 
 __f7____2b____end :
 __f7____3b = 0 ;
 __f7____5b____QQ = __X7__acquired ;
 __f7____5b____RQ__z =(! __f7____5b____QQ ); 
 __f7____5b____RQ____end :
 if(! __f7____5b____RQ__z )goto __f7____5b____PQ__fi ;
 __f7____5b____SQ = "Did not initialize Dynamic" ;
 goto __f7____5b____TQ____qD ;
 __builtin_unreachable();
 __f7____5b____PQ__fi :
 __f7____5b__next_size = __X7__size +1; __f7____5b__success = true ; __f7____5b__self__allocated__prev = __X7__allocated ; if ( __f7____5b__next_size >= __X7__allocated ) { __X7__allocated = __X7__allocated + __X7__allocated /2+1; __f7____5b__next_acquired =( ptr )((( ptr **) __X7__acquired )[0]? __runtime_realloc ((( ptr **) __X7__acquired )[0], __X7__allocated * sizeof ( ptr ), __f7____5b__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __X7__allocated * sizeof ( ptr ))); if ( __f7____5b__success = __f7____5b__next_acquired )(( ptr **) __X7__acquired )[0]=( ptr *) __f7____5b__next_acquired ; } if ( __f7____5b__success ) { __f7____5b__mem =( ptr ) __runtime_alloc ( __f7____2b__z * sizeof ( __f7____5b____OQ )); if ( __f7____5b__success = __f7____5b__mem ) {(( ptr **) __X7__acquired )[0][ __X7__size ]= __f7____5b__mem ; __X7__size = __f7____5b__next_size ; } } 
 __f7____5b____VQ__x = __f7____5b__success ;
 __f7____5b____VQ__z =(! __f7____5b____VQ__x ); 
 __f7____5b____VQ____end :
 if(! __f7____5b____VQ__z )goto __f7____5b____UQ__fi ;
 __f7____5b____WQ = "Failed a Dynamic allocation" ;
 goto __f7____5b____XQ____qD ;
 __builtin_unreachable();
 __f7____5b____UQ__fi :
 __f7____5b____cQ = 0 ;
 __f7____5b____eQ__bytesize = sizeof ( __f7____5b____eQ____EF )* __f7____2b__z ; 
 __f7____5b____eQ____end :
 memcpy (( char *) __f7____5b__mem ,( char *) name__contents , __f7__len_x ); memcpy (( char *) __f7____5b__mem + __f7__len_x ,( char *) __f7____0b____m__contents , __f7__len_y );(( char *) __f7____5b__mem )[ __f7__total_len ]=0; 
 __f7____8b__contents = __f7____5b__mem ;
 __X7____BQ = __f7____5b__self____BQ ;
 __X7__acquired = __X7__acquired ;
 __X7__size = __X7__size ;
 __X7__allocated = __X7__allocated ;
 __X7____dynamic_entry = __X7____dynamic_entry ;
 __g7____dh__length = strlen ( __d7 ); __g7____dh__contents =( ptr ) __d7 ; __g7____dh__first = __d7 [0]; __g7____dh__noptr =( ptr ) __g7____dh__noptr ; 
 __g7____dh____m__contents = __g7____dh__contents ;
 __g7__len_x = __g7____dh__length ; __g7__len_y = __f7__total_len ; __g7__total_len = __g7__len_x + __g7__len_y ; __g7__first = __g7____dh__length ? __g7____dh__first : __f7__first ; 
 __g7____fh = 1 ;
 __g7____gh__z = __g7__total_len + __g7____fh ; 
 __g7____gh____end :
 __g7____hh = 0 ;
 __g7____jh____QQ = __X7__acquired ;
 __g7____jh____RQ__z =(! __g7____jh____QQ ); 
 __g7____jh____RQ____end :
 if(! __g7____jh____RQ__z )goto __g7____jh____PQ__fi ;
 __g7____jh____SQ = "Did not initialize Dynamic" ;
 goto __g7____jh____TQ____qD ;
 __builtin_unreachable();
 __g7____jh____PQ__fi :
 __g7____jh__next_size = __X7__size +1; __g7____jh__success = true ; __g7____jh__self__allocated__prev = __X7__allocated ; if ( __g7____jh__next_size >= __X7__allocated ) { __X7__allocated = __X7__allocated + __X7__allocated /2+1; __g7____jh__next_acquired =( ptr )((( ptr **) __X7__acquired )[0]? __runtime_realloc ((( ptr **) __X7__acquired )[0], __X7__allocated * sizeof ( ptr ), __g7____jh__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __X7__allocated * sizeof ( ptr ))); if ( __g7____jh__success = __g7____jh__next_acquired )(( ptr **) __X7__acquired )[0]=( ptr *) __g7____jh__next_acquired ; } if ( __g7____jh__success ) { __g7____jh__mem =( ptr ) __runtime_alloc ( __g7____gh__z * sizeof ( __g7____jh____OQ )); if ( __g7____jh__success = __g7____jh__mem ) {(( ptr **) __X7__acquired )[0][ __X7__size ]= __g7____jh__mem ; __X7__size = __g7____jh__next_size ; } } 
 __g7____jh____VQ__x = __g7____jh__success ;
 __g7____jh____VQ__z =(! __g7____jh____VQ__x ); 
 __g7____jh____VQ____end :
 if(! __g7____jh____VQ__z )goto __g7____jh____UQ__fi ;
 __g7____jh____WQ = "Failed a Dynamic allocation" ;
 goto __g7____jh____XQ____qD ;
 __builtin_unreachable();
 __g7____jh____UQ__fi :
 __g7____jh____cQ = 0 ;
 __g7____jh____eQ__bytesize = sizeof ( __g7____jh____eQ____EF )* __g7____gh__z ; 
 __g7____jh____eQ____end :
 memcpy (( char *) __g7____jh__mem ,( char *) __g7____dh____m__contents , __g7__len_x ); memcpy (( char *) __g7____jh__mem + __g7__len_x ,( char *) __f7____8b__contents , __g7__len_y );(( char *) __g7____jh__mem )[ __g7__total_len ]=0; 
 __g7____mh__contents = __g7____jh__mem ;
 __X7____BQ = __g7____jh__self____BQ ;
 __X7__acquired = __X7__acquired ;
 __X7__size = __X7__size ;
 __X7__allocated = __X7__allocated ;
 __X7____dynamic_entry = __X7____dynamic_entry ;
 printf ( "%s\n" ,( char *) __g7____mh__contents ); 
 __h7____end :
 goto __Z7__el ;
 __Z7__fi :
 __i7 = "[ \033[32mOK\033[0m ] " ;
 __j7 = ".s" ;
 __k7____0b__length = strlen ( __j7 ); __k7____0b__contents =( ptr ) __j7 ; __k7____0b__first = __j7 [0]; __k7____0b__noptr =( ptr ) __k7____0b__noptr ; 
 __k7____0b____m__contents = __k7____0b__contents ;
 __k7__len_x = name__length ; __k7__len_y = __k7____0b__length ; __k7__total_len = __k7__len_x + __k7__len_y ; __k7__first = name__length ? name__first : __k7____0b__first ; 
 __k7____1b = 1 ;
 __k7____2b__z = __k7__total_len + __k7____1b ; 
 __k7____2b____end :
 __k7____3b = 0 ;
 __k7____5b____QQ = __X7__acquired ;
 __k7____5b____RQ__z =(! __k7____5b____QQ ); 
 __k7____5b____RQ____end :
 if(! __k7____5b____RQ__z )goto __k7____5b____PQ__fi ;
 __k7____5b____SQ = "Did not initialize Dynamic" ;
 goto __k7____5b____TQ____qD ;
 __builtin_unreachable();
 __k7____5b____PQ__fi :
 __k7____5b__next_size = __X7__size +1; __k7____5b__success = true ; __k7____5b__self__allocated__prev = __X7__allocated ; if ( __k7____5b__next_size >= __X7__allocated ) { __X7__allocated = __X7__allocated + __X7__allocated /2+1; __k7____5b__next_acquired =( ptr )((( ptr **) __X7__acquired )[0]? __runtime_realloc ((( ptr **) __X7__acquired )[0], __X7__allocated * sizeof ( ptr ), __k7____5b__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __X7__allocated * sizeof ( ptr ))); if ( __k7____5b__success = __k7____5b__next_acquired )(( ptr **) __X7__acquired )[0]=( ptr *) __k7____5b__next_acquired ; } if ( __k7____5b__success ) { __k7____5b__mem =( ptr ) __runtime_alloc ( __k7____2b__z * sizeof ( __k7____5b____OQ )); if ( __k7____5b__success = __k7____5b__mem ) {(( ptr **) __X7__acquired )[0][ __X7__size ]= __k7____5b__mem ; __X7__size = __k7____5b__next_size ; } } 
 __k7____5b____VQ__x = __k7____5b__success ;
 __k7____5b____VQ__z =(! __k7____5b____VQ__x ); 
 __k7____5b____VQ____end :
 if(! __k7____5b____VQ__z )goto __k7____5b____UQ__fi ;
 __k7____5b____WQ = "Failed a Dynamic allocation" ;
 goto __k7____5b____XQ____qD ;
 __builtin_unreachable();
 __k7____5b____UQ__fi :
 __k7____5b____cQ = 0 ;
 __k7____5b____eQ__bytesize = sizeof ( __k7____5b____eQ____EF )* __k7____2b__z ; 
 __k7____5b____eQ____end :
 memcpy (( char *) __k7____5b__mem ,( char *) name__contents , __k7__len_x ); memcpy (( char *) __k7____5b__mem + __k7__len_x ,( char *) __k7____0b____m__contents , __k7__len_y );(( char *) __k7____5b__mem )[ __k7__total_len ]=0; 
 __k7____8b__contents = __k7____5b__mem ;
 __X7____BQ = __k7____5b__self____BQ ;
 __X7__acquired = __X7__acquired ;
 __X7__size = __X7__size ;
 __X7__allocated = __X7__allocated ;
 __X7____dynamic_entry = __X7____dynamic_entry ;
 __l7____dh__length = strlen ( __i7 ); __l7____dh__contents =( ptr ) __i7 ; __l7____dh__first = __i7 [0]; __l7____dh__noptr =( ptr ) __l7____dh__noptr ; 
 __l7____dh____m__contents = __l7____dh__contents ;
 __l7__len_x = __l7____dh__length ; __l7__len_y = __k7__total_len ; __l7__total_len = __l7__len_x + __l7__len_y ; __l7__first = __l7____dh__length ? __l7____dh__first : __k7__first ; 
 __l7____fh = 1 ;
 __l7____gh__z = __l7__total_len + __l7____fh ; 
 __l7____gh____end :
 __l7____hh = 0 ;
 __l7____jh____QQ = __X7__acquired ;
 __l7____jh____RQ__z =(! __l7____jh____QQ ); 
 __l7____jh____RQ____end :
 if(! __l7____jh____RQ__z )goto __l7____jh____PQ__fi ;
 __l7____jh____SQ = "Did not initialize Dynamic" ;
 goto __l7____jh____TQ____qD ;
 __builtin_unreachable();
 __l7____jh____PQ__fi :
 __l7____jh__next_size = __X7__size +1; __l7____jh__success = true ; __l7____jh__self__allocated__prev = __X7__allocated ; if ( __l7____jh__next_size >= __X7__allocated ) { __X7__allocated = __X7__allocated + __X7__allocated /2+1; __l7____jh__next_acquired =( ptr )((( ptr **) __X7__acquired )[0]? __runtime_realloc ((( ptr **) __X7__acquired )[0], __X7__allocated * sizeof ( ptr ), __l7____jh__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __X7__allocated * sizeof ( ptr ))); if ( __l7____jh__success = __l7____jh__next_acquired )(( ptr **) __X7__acquired )[0]=( ptr *) __l7____jh__next_acquired ; } if ( __l7____jh__success ) { __l7____jh__mem =( ptr ) __runtime_alloc ( __l7____gh__z * sizeof ( __l7____jh____OQ )); if ( __l7____jh__success = __l7____jh__mem ) {(( ptr **) __X7__acquired )[0][ __X7__size ]= __l7____jh__mem ; __X7__size = __l7____jh__next_size ; } } 
 __l7____jh____VQ__x = __l7____jh__success ;
 __l7____jh____VQ__z =(! __l7____jh____VQ__x ); 
 __l7____jh____VQ____end :
 if(! __l7____jh____VQ__z )goto __l7____jh____UQ__fi ;
 __l7____jh____WQ = "Failed a Dynamic allocation" ;
 goto __l7____jh____XQ____qD ;
 __builtin_unreachable();
 __l7____jh____UQ__fi :
 __l7____jh____cQ = 0 ;
 __l7____jh____eQ__bytesize = sizeof ( __l7____jh____eQ____EF )* __l7____gh__z ; 
 __l7____jh____eQ____end :
 memcpy (( char *) __l7____jh__mem ,( char *) __l7____dh____m__contents , __l7__len_x ); memcpy (( char *) __l7____jh__mem + __l7__len_x ,( char *) __k7____8b__contents , __l7__len_y );(( char *) __l7____jh__mem )[ __l7__total_len ]=0; 
 __l7____mh__contents = __l7____jh__mem ;
 __X7____BQ = __l7____jh__self____BQ ;
 __X7__acquired = __X7__acquired ;
 __X7__size = __X7__size ;
 __X7__allocated = __X7__allocated ;
 __X7____dynamic_entry = __X7____dynamic_entry ;
 printf ( "%s\n" ,( char *) __l7____mh__contents ); 
 __m7____end :
 __Z7__el :
 __end :
goto __return;

// ERROR HANDLING
__k7____5b____XQ____qD :
 printf ( "%s\n" , __k7____5b____WQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__b7 :
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
__g7____jh____XQ____qD :
 printf ( "%s\n" , __g7____jh____WQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__f7____5b____TQ____qD :
 printf ( "%s\n" , __f7____5b____SQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__l7____jh____XQ____qD :
 printf ( "%s\n" , __l7____jh____WQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__l7____jh____TQ____qD :
 printf ( "%s\n" , __l7____jh____SQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__T7____5b____TQ____qD :
 printf ( "%s\n" , __T7____5b____SQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__g7____jh____TQ____qD :
 printf ( "%s\n" , __g7____jh____SQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__T7____5b____XQ____qD :
 printf ( "%s\n" , __T7____5b____WQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__U7____jh____TQ____qD :
 printf ( "%s\n" , __U7____jh____SQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__service_stack_floor_handler:
printf("Insufficient stack for safe service call (too much recursion or stack allocation)\n");
__result__errocode=__STACK__ERROR;
goto __failsafe;
__k7____5b____TQ____qD :
 printf ( "%s\n" , __k7____5b____SQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__U7____jh____XQ____qD :
 printf ( "%s\n" , __U7____jh____WQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__f7____5b____XQ____qD :
 printf ( "%s\n" , __f7____5b____WQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:
__runtime_apply_linked(__smolambda_all_tasks, __smolambda_task_wait, 0);
__runtime_apply_linked(__smolambda_all_tasks, __smolambda_task_destroy, 1);
__smolambda_all_tasks = 0;

// HOTPATH SKIPS TO HERE
__return:
__runtime_apply_linked(__smolambda_all_tasks, __smolambda_task_wait, 0);
__runtime_apply_linked(__smolambda_all_tasks, __smolambda_task_destroy, 1);
if ( __X7__acquired ) { for ( __X7____dynamic_entry =0; __X7____dynamic_entry < __X7__size ;++ __X7____dynamic_entry ) { __runtime_free ((( ptr **) __X7__acquired )[0][ __X7____dynamic_entry ]); } __runtime_free ( __X7__acquired ); __X7__acquired =0; __X7__size =0; __X7__allocated =0; } 
 if ( __X7__acquired ) { for ( __X7____HQ____dynamic_entry =0; __X7____HQ____dynamic_entry < __X7____HQ____CQ ;++ __X7____HQ____dynamic_entry ) { __runtime_free ((( ptr **) __X7__acquired )[0][ __X7____HQ____dynamic_entry ]); } __runtime_free ( __X7__acquired ); __X7__acquired =0; __X7____HQ____CQ =0; __X7____HQ____DQ =0; } 
if ( __P7__acquired ) { for ( __P7____dynamic_entry =0; __P7____dynamic_entry < __P7__size ;++ __P7____dynamic_entry ) { __runtime_free ((( ptr **) __P7__acquired )[0][ __P7____dynamic_entry ]); } __runtime_free ( __P7__acquired ); __P7__acquired =0; __P7__size =0; __P7__allocated =0; } 
 if ( __P7__acquired ) { for ( __P7____HQ____dynamic_entry =0; __P7____HQ____dynamic_entry < __P7____HQ____CQ ;++ __P7____HQ____dynamic_entry ) { __runtime_free ((( ptr **) __P7__acquired )[0][ __P7____HQ____dynamic_entry ]); } __runtime_free ( __P7__acquired ); __P7__acquired =0; __P7____HQ____CQ =0; __P7____HQ____DQ =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}


void std_test__818(void *__void__state){
errcode __result__errocode=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 2744;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct std_test__818__state *__state=(struct std_test__818__state*)__void__state;
struct run__816__state* __A7____state = 0 ;
cstr name= __state->name;
char __L7____jh____eQ____EF=0;
cstr __L7____jh____WQ=0;
bool __L7____jh____VQ__z=0;
ptr __L7____jh__mem=0;
ptr __L7____jh__next_acquired=0;
bool __L7____jh__success=0;
char __L7____hh=0;
u64 __L7__total_len=0;
u64 __L7__len_y=0;
u64 __L7____jh____eQ__bytesize=0;
u64 __L7__len_x=0;
ptr __L7____dh__noptr=0;
char __L7____dh__first=0;
nominal __K7____xa__self____BQ=0;
u64 __L7____gh__z=0;
ptr __K7____0a__contents=0;
bool __L7____jh____QQ=0;
char __K7____xa____cQ=0;
bool __K7____xa____VQ__x=0;
ptr __K7____xa__mem=0;
ptr __K7____xa__next_acquired=0;
u64 __K7____xa__self__allocated__prev=0;
bool __K7____xa__success=0;
cstr __K7____xa____SQ=0;
u64 __K7____ua__z=0;
u64 __K7__total_len=0;
u64 __K7__len_y=0;
u64 __L7____dh__length=0;
u64 __K7__len_x=0;
ptr __K7____sa__noptr=0;
u64 __K7____sa__length=0;
ptr __K7____ra____m__contents=0;
u64 __G7____jh____eQ__bytesize=0;
char __G7____jh____cQ=0;
bool __G7____jh____VQ__z=0;
bool __G7____jh____VQ__x=0;
ptr __G7____jh__mem=0;
u64 __G7____jh__self__allocated__prev=0;
bool __G7____jh____RQ__z=0;
bool __G7____jh____QQ=0;
char __G7____hh=0;
u64 __G7____gh__z=0;
char __G7__first=0;
u64 __G7__total_len=0;
u64 __G7__len_y=0;
u64 __G7__len_x=0;
ptr __G7____dh__noptr=0;
ptr __G7____dh__contents=0;
nominal __F7____xa__self____BQ=0;
nominal __76____BQ=0;
u64 __F7____xa____eQ__bytesize=0;
char __F7____xa____cQ=0;
u64 __G7____fh=0;
bool __F7____xa____VQ__x=0;
char __F7____xa____OQ=0;
u64 __F7____xa__self__allocated__prev=0;
bool __F7____xa__success=0;
u64 __F7____xa__next_size=0;
char __L7____jh____OQ=0;
bool __F7____xa____RQ__z=0;
bool __F7____xa____QQ=0;
char __F7__first=0;
u64 __F7__total_len=0;
u64 __G7____dh__length=0;
u64 __F7__len_y=0;
char __G7____dh__first=0;
u64 __F7__len_x=0;
ptr __F7____sa____m__contents=0;
ptr __F7____sa__noptr=0;
cstr __J7=0;
ptr __F7____ra__noptr=0;
char __K7____sa__first=0;
char __F7____ra__first=0;
ptr __F7____ra__contents=0;
bool __C7=0;
char __46____jh____cQ=0;
ptr __F7____ra____m__contents=0;
u64 __K7____ta=0;
bool __G7____jh__success=0;
nominal __G7____jh__self____BQ=0;
cstr __36____xa____WQ=0;
cstr __L7____jh____SQ=0;
char __36____ra__first=0;
nominal __36____xa__self____BQ=0;
u64 __46____jh__self__allocated__prev=0;
u64 __36____xa__next_size=0;
cstr __E7=0;
cstr __16=0;
char __L7____jh____cQ=0;
u64 __K7____xa____eQ__bytesize=0;
u64 __36__len_x=0;
u64 __76____HQ____DQ=0;
u64 __L7____fh=0;
cstr __K7____xa____WQ=0;
u64 __L7____jh__next_size=0;
ptr __F7____0a__contents=0;
ptr __F7____xa__next_acquired=0;
ptr __46____dh__contents=0;
cstr __F7____xa____SQ=0;
ptr __46____dh__noptr=0;
ptr __K7____ra__noptr=0;
bool __L7____jh____RQ__z=0;
char __K7__first=0;
char __K7____xa____OQ=0;
u64 __46____jh____eQ__bytesize=0;
ptr __K7____ra__contents=0;
ptr __76__acquired=0;
ptr __z6__acquired=0;
ptr __L7____dh____m__contents=0;
char __K7____va=0;
char __F7____xa____eQ____EF=0;
char __F7____sa__first=0;
u64 __F7____ua__z=0;
ptr __36____0a__contents=0;
ptr __46____dh____m__contents=0;
char __L7__first=0;
nominal __z6____BQ=0;
bool __K7____xa____VQ__z=0;
bool __K7____xa____QQ=0;
nominal __L7____jh__self____BQ=0;
u64 __46____dh__length=0;
bool __F7____xa____VQ__z=0;
u64 __K7____xa__next_size=0;
char __36____xa____cQ=0;
u64 __46__total_len=0;
char __F7____va=0;
bool __46____jh____VQ__x=0;
ptr __G7____dh____m__contents=0;
u64 __46__len_x=0;
bool __K7____xa____RQ__z=0;
cstr __G7____jh____SQ=0;
ptr __46____mh__contents=0;
char __K7____ra__first=0;
ptr __F7____sa__contents=0;
u64 __F7____sa__length=0;
ptr __L7____dh__contents=0;
bool __46____jh____QQ=0;
errcode __A7__err=0;
ptr __G7____jh__next_acquired=0;
ptr __z6____HQ__acquired=0;
char __36____xa____OQ=0;
cstr __36____xa____SQ=0;
bool __36____xa____RQ__z=0;
cstr __D7=0;
ptr __G7____mh__contents=0;
ptr __36____xa__next_acquired=0;
ptr __F7____xa__mem=0;
u64 __36____ta=0;
u64 __36____xa____eQ__bytesize=0;
cstr __46____jh____SQ=0;
u64 __L7____jh__self__allocated__prev=0;
u64 __76____dynamic_entry=0;
u64 __z6____HQ____DQ=0;
u64 __z6____HQ____CQ=0;
cstr __F7____xa____WQ=0;
u64 __z6__size=0;
bool __36____xa____QQ=0;
ptr __K7____sa__contents=0;
u64 __z6__allocated=0;
u64 __z6____dynamic_entry=0;
ptr __76____HQ__acquired=0;
ptr __36____sa__contents=0;
u64 __z6____HQ____dynamic_entry=0;
ptr __K7____sa____m__contents=0;
cstr __26=0;
u64 __36____ua__z=0;
ptr __36____ra__contents=0;
ptr __36____ra__noptr=0;
ptr __36____ra____m__contents=0;
u64 __36____sa__length=0;
cstr __G7____jh____WQ=0;
u64 __46__len_y=0;
u64 __46____gh__z=0;
char __36____sa__first=0;
ptr __L7____mh__contents=0;
char __K7____xa____eQ____EF=0;
ptr __36____sa____m__contents=0;
ptr __36____sa__noptr=0;
u64 __36__total_len=0;
char __36__first=0;
bool __36____xa__success=0;
u64 __36____xa__self__allocated__prev=0;
ptr __36____xa__mem=0;
bool __36____xa____VQ__x=0;
u64 __36____ra__length=0;
char __36____xa____eQ____EF=0;
char __G7____jh____OQ=0;
char __46____dh__first=0;
u64 __46____fh=0;
bool __L7____jh____VQ__x=0;
char __46____hh=0;
bool __46____jh____RQ__z=0;
u64 __F7____ra__length=0;
ptr __A7____task=0;
u64 __46____jh__next_size=0;
bool __46____jh__success=0;
ptr __46____jh__next_acquired=0;
ptr __46____jh__mem=0;
char __46____jh____OQ=0;
char __G7____jh____eQ____EF=0;
cstr __46____jh____WQ=0;
char __46____jh____eQ____EF=0;
u64 __G7____jh__next_size=0;
nominal __46____jh__self____BQ=0;
u64 __76____HQ____CQ=0;
u64 __76__size=0;
bool __46____jh____VQ__z=0;
u64 __76__allocated=0;
char __46__first=0;
u64 __36__len_y=0;
u64 __76____HQ____dynamic_entry=0;
nominal command____c=0;
ptr command__contents=0;
cstr __I7=0;
bool __36____xa____VQ__z=0;
u64 command__length=0;
u64 __K7____ra__length=0;
char command__first=0;
u64 __F7____ta=0;
char __36____va=0;
ptr command__memory=0;

// IMPLEMENTATION
__z6____HQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __z6____HQ__acquired )(( ptr **) __z6____HQ__acquired )[0]=0; 
 __z6____HQ____CQ = 0 ;
 __z6____HQ____DQ = 0 ;
 __z6__acquired = __z6____HQ__acquired ;
 __z6__size = __z6____HQ____CQ ;
 __z6__allocated = __z6____HQ____DQ ;
 __z6____dynamic_entry = __z6____HQ____dynamic_entry ;
 __16 = "./smol tests/unit/" ;
 __26 = ".s --workers 1 --runtime eager 2>&1" ;
 __36____ra__length = strlen ( name ); __36____ra__contents =( ptr ) name ; __36____ra__first = name [0]; __36____ra__noptr =( ptr ) __36____ra__noptr ; 
 __36____ra____m__contents = __36____ra__contents ;
 __36____sa__length = strlen ( __26 ); __36____sa__contents =( ptr ) __26 ; __36____sa__first = __26 [0]; __36____sa__noptr =( ptr ) __36____sa__noptr ; 
 __36____sa____m__contents = __36____sa__contents ;
 __36__len_x = __36____ra__length ; __36__len_y = __36____sa__length ; __36__total_len = __36__len_x + __36__len_y ; __36__first = __36____ra__length ? __36____ra__first : __36____sa__first ; 
 __36____ta = 1 ;
 __36____ua__z = __36__total_len + __36____ta ; 
 __36____ua____end :
 __36____va = 0 ;
 __36____xa____QQ = __z6__acquired ;
 __36____xa____RQ__z =(! __36____xa____QQ ); 
 __36____xa____RQ____end :
 if(! __36____xa____RQ__z )goto __36____xa____PQ__fi ;
 __36____xa____SQ = "Did not initialize Dynamic" ;
 goto __36____xa____TQ____qD ;
 __builtin_unreachable();
 __36____xa____PQ__fi :
 __36____xa__next_size = __z6__size +1; __36____xa__success = true ; __36____xa__self__allocated__prev = __z6__allocated ; if ( __36____xa__next_size >= __z6__allocated ) { __z6__allocated = __z6__allocated + __z6__allocated /2+1; __36____xa__next_acquired =( ptr )((( ptr **) __z6__acquired )[0]? __runtime_realloc ((( ptr **) __z6__acquired )[0], __z6__allocated * sizeof ( ptr ), __36____xa__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __z6__allocated * sizeof ( ptr ))); if ( __36____xa__success = __36____xa__next_acquired )(( ptr **) __z6__acquired )[0]=( ptr *) __36____xa__next_acquired ; } if ( __36____xa__success ) { __36____xa__mem =( ptr ) __runtime_alloc ( __36____ua__z * sizeof ( __36____xa____OQ )); if ( __36____xa__success = __36____xa__mem ) {(( ptr **) __z6__acquired )[0][ __z6__size ]= __36____xa__mem ; __z6__size = __36____xa__next_size ; } } 
 __36____xa____VQ__x = __36____xa__success ;
 __36____xa____VQ__z =(! __36____xa____VQ__x ); 
 __36____xa____VQ____end :
 if(! __36____xa____VQ__z )goto __36____xa____UQ__fi ;
 __36____xa____WQ = "Failed a Dynamic allocation" ;
 goto __36____xa____XQ____qD ;
 __builtin_unreachable();
 __36____xa____UQ__fi :
 __36____xa____cQ = 0 ;
 __36____xa____eQ__bytesize = sizeof ( __36____xa____eQ____EF )* __36____ua__z ; 
 __36____xa____eQ____end :
 memcpy (( char *) __36____xa__mem ,( char *) __36____ra____m__contents , __36__len_x ); memcpy (( char *) __36____xa__mem + __36__len_x ,( char *) __36____sa____m__contents , __36__len_y );(( char *) __36____xa__mem )[ __36__total_len ]=0; 
 __36____0a__contents = __36____xa__mem ;
 __z6____BQ = __36____xa__self____BQ ;
 __z6__acquired = __z6__acquired ;
 __z6__size = __z6__size ;
 __z6__allocated = __z6__allocated ;
 __z6____dynamic_entry = __z6____dynamic_entry ;
 __46____dh__length = strlen ( __16 ); __46____dh__contents =( ptr ) __16 ; __46____dh__first = __16 [0]; __46____dh__noptr =( ptr ) __46____dh__noptr ; 
 __46____dh____m__contents = __46____dh__contents ;
 __46__len_x = __46____dh__length ; __46__len_y = __36__total_len ; __46__total_len = __46__len_x + __46__len_y ; __46__first = __46____dh__length ? __46____dh__first : __36__first ; 
 __46____fh = 1 ;
 __46____gh__z = __46__total_len + __46____fh ; 
 __46____gh____end :
 __46____hh = 0 ;
 __46____jh____QQ = __z6__acquired ;
 __46____jh____RQ__z =(! __46____jh____QQ ); 
 __46____jh____RQ____end :
 if(! __46____jh____RQ__z )goto __46____jh____PQ__fi ;
 __46____jh____SQ = "Did not initialize Dynamic" ;
 goto __46____jh____TQ____qD ;
 __builtin_unreachable();
 __46____jh____PQ__fi :
 __46____jh__next_size = __z6__size +1; __46____jh__success = true ; __46____jh__self__allocated__prev = __z6__allocated ; if ( __46____jh__next_size >= __z6__allocated ) { __z6__allocated = __z6__allocated + __z6__allocated /2+1; __46____jh__next_acquired =( ptr )((( ptr **) __z6__acquired )[0]? __runtime_realloc ((( ptr **) __z6__acquired )[0], __z6__allocated * sizeof ( ptr ), __46____jh__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __z6__allocated * sizeof ( ptr ))); if ( __46____jh__success = __46____jh__next_acquired )(( ptr **) __z6__acquired )[0]=( ptr *) __46____jh__next_acquired ; } if ( __46____jh__success ) { __46____jh__mem =( ptr ) __runtime_alloc ( __46____gh__z * sizeof ( __46____jh____OQ )); if ( __46____jh__success = __46____jh__mem ) {(( ptr **) __z6__acquired )[0][ __z6__size ]= __46____jh__mem ; __z6__size = __46____jh__next_size ; } } 
 __46____jh____VQ__x = __46____jh__success ;
 __46____jh____VQ__z =(! __46____jh____VQ__x ); 
 __46____jh____VQ____end :
 if(! __46____jh____VQ__z )goto __46____jh____UQ__fi ;
 __46____jh____WQ = "Failed a Dynamic allocation" ;
 goto __46____jh____XQ____qD ;
 __builtin_unreachable();
 __46____jh____UQ__fi :
 __46____jh____cQ = 0 ;
 __46____jh____eQ__bytesize = sizeof ( __46____jh____eQ____EF )* __46____gh__z ; 
 __46____jh____eQ____end :
 memcpy (( char *) __46____jh__mem ,( char *) __46____dh____m__contents , __46__len_x ); memcpy (( char *) __46____jh__mem + __46__len_x ,( char *) __36____0a__contents , __46__len_y );(( char *) __46____jh__mem )[ __46__total_len ]=0; 
 __46____mh__contents = __46____jh__mem ;
 __z6____BQ = __46____jh__self____BQ ;
 __z6__acquired = __z6__acquired ;
 __z6__size = __z6__size ;
 __z6__allocated = __z6__allocated ;
 __z6____dynamic_entry = __z6____dynamic_entry ;
 __76____HQ__acquired = __runtime_alloc ( sizeof ( ptr **)); if ( __76____HQ__acquired )(( ptr **) __76____HQ__acquired )[0]=0; 
 __76____HQ____CQ = 0 ;
 __76____HQ____DQ = 0 ;
 __76__acquired = __76____HQ__acquired ;
 __76__size = __76____HQ____CQ ;
 __76__allocated = __76____HQ____DQ ;
 __76____dynamic_entry = __76____HQ____dynamic_entry ;
 {char mark;if(__service_stack_floor+ 1180 >=(char*)&mark) goto __service_stack_floor_handler;} __A7____state = (struct run__816__state*)__runtime_calloc(sizeof(struct run__816__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __A7____state ) ;
 __A7____state -> command____c = command____c ;
 __A7____state -> command__contents = __46____mh__contents ;
 __A7____state -> command__length = __46__total_len ;
 __A7____state -> command__first = __46__first ;
 __A7____state -> command__memory = __z6__acquired ;
 __A7____task = __smolambda_add_task ( run__816 , __A7____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __A7____task ) ;
 if( __A7__err ) goto  __result_unhandled_error ;
 __smolambda_task_wait ( __A7____task ) ;
 __A7__err = __A7____state -> err ;
 __C7 = __A7__err ;
 if(! __C7 )goto __96__fi ;
 __D7 = "[ \033[31mERROR\033[0m ] " ;
 __E7 = ".s" ;
 __F7____ra__length = strlen ( name ); __F7____ra__contents =( ptr ) name ; __F7____ra__first = name [0]; __F7____ra__noptr =( ptr ) __F7____ra__noptr ; 
 __F7____ra____m__contents = __F7____ra__contents ;
 __F7____sa__length = strlen ( __E7 ); __F7____sa__contents =( ptr ) __E7 ; __F7____sa__first = __E7 [0]; __F7____sa__noptr =( ptr ) __F7____sa__noptr ; 
 __F7____sa____m__contents = __F7____sa__contents ;
 __F7__len_x = __F7____ra__length ; __F7__len_y = __F7____sa__length ; __F7__total_len = __F7__len_x + __F7__len_y ; __F7__first = __F7____ra__length ? __F7____ra__first : __F7____sa__first ; 
 __F7____ta = 1 ;
 __F7____ua__z = __F7__total_len + __F7____ta ; 
 __F7____ua____end :
 __F7____va = 0 ;
 __F7____xa____QQ = __76__acquired ;
 __F7____xa____RQ__z =(! __F7____xa____QQ ); 
 __F7____xa____RQ____end :
 if(! __F7____xa____RQ__z )goto __F7____xa____PQ__fi ;
 __F7____xa____SQ = "Did not initialize Dynamic" ;
 goto __F7____xa____TQ____qD ;
 __builtin_unreachable();
 __F7____xa____PQ__fi :
 __F7____xa__next_size = __76__size +1; __F7____xa__success = true ; __F7____xa__self__allocated__prev = __76__allocated ; if ( __F7____xa__next_size >= __76__allocated ) { __76__allocated = __76__allocated + __76__allocated /2+1; __F7____xa__next_acquired =( ptr )((( ptr **) __76__acquired )[0]? __runtime_realloc ((( ptr **) __76__acquired )[0], __76__allocated * sizeof ( ptr ), __F7____xa__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __76__allocated * sizeof ( ptr ))); if ( __F7____xa__success = __F7____xa__next_acquired )(( ptr **) __76__acquired )[0]=( ptr *) __F7____xa__next_acquired ; } if ( __F7____xa__success ) { __F7____xa__mem =( ptr ) __runtime_alloc ( __F7____ua__z * sizeof ( __F7____xa____OQ )); if ( __F7____xa__success = __F7____xa__mem ) {(( ptr **) __76__acquired )[0][ __76__size ]= __F7____xa__mem ; __76__size = __F7____xa__next_size ; } } 
 __F7____xa____VQ__x = __F7____xa__success ;
 __F7____xa____VQ__z =(! __F7____xa____VQ__x ); 
 __F7____xa____VQ____end :
 if(! __F7____xa____VQ__z )goto __F7____xa____UQ__fi ;
 __F7____xa____WQ = "Failed a Dynamic allocation" ;
 goto __F7____xa____XQ____qD ;
 __builtin_unreachable();
 __F7____xa____UQ__fi :
 __F7____xa____cQ = 0 ;
 __F7____xa____eQ__bytesize = sizeof ( __F7____xa____eQ____EF )* __F7____ua__z ; 
 __F7____xa____eQ____end :
 memcpy (( char *) __F7____xa__mem ,( char *) __F7____ra____m__contents , __F7__len_x ); memcpy (( char *) __F7____xa__mem + __F7__len_x ,( char *) __F7____sa____m__contents , __F7__len_y );(( char *) __F7____xa__mem )[ __F7__total_len ]=0; 
 __F7____0a__contents = __F7____xa__mem ;
 __76____BQ = __F7____xa__self____BQ ;
 __76__acquired = __76__acquired ;
 __76__size = __76__size ;
 __76__allocated = __76__allocated ;
 __76____dynamic_entry = __76____dynamic_entry ;
 __G7____dh__length = strlen ( __D7 ); __G7____dh__contents =( ptr ) __D7 ; __G7____dh__first = __D7 [0]; __G7____dh__noptr =( ptr ) __G7____dh__noptr ; 
 __G7____dh____m__contents = __G7____dh__contents ;
 __G7__len_x = __G7____dh__length ; __G7__len_y = __F7__total_len ; __G7__total_len = __G7__len_x + __G7__len_y ; __G7__first = __G7____dh__length ? __G7____dh__first : __F7__first ; 
 __G7____fh = 1 ;
 __G7____gh__z = __G7__total_len + __G7____fh ; 
 __G7____gh____end :
 __G7____hh = 0 ;
 __G7____jh____QQ = __76__acquired ;
 __G7____jh____RQ__z =(! __G7____jh____QQ ); 
 __G7____jh____RQ____end :
 if(! __G7____jh____RQ__z )goto __G7____jh____PQ__fi ;
 __G7____jh____SQ = "Did not initialize Dynamic" ;
 goto __G7____jh____TQ____qD ;
 __builtin_unreachable();
 __G7____jh____PQ__fi :
 __G7____jh__next_size = __76__size +1; __G7____jh__success = true ; __G7____jh__self__allocated__prev = __76__allocated ; if ( __G7____jh__next_size >= __76__allocated ) { __76__allocated = __76__allocated + __76__allocated /2+1; __G7____jh__next_acquired =( ptr )((( ptr **) __76__acquired )[0]? __runtime_realloc ((( ptr **) __76__acquired )[0], __76__allocated * sizeof ( ptr ), __G7____jh__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __76__allocated * sizeof ( ptr ))); if ( __G7____jh__success = __G7____jh__next_acquired )(( ptr **) __76__acquired )[0]=( ptr *) __G7____jh__next_acquired ; } if ( __G7____jh__success ) { __G7____jh__mem =( ptr ) __runtime_alloc ( __G7____gh__z * sizeof ( __G7____jh____OQ )); if ( __G7____jh__success = __G7____jh__mem ) {(( ptr **) __76__acquired )[0][ __76__size ]= __G7____jh__mem ; __76__size = __G7____jh__next_size ; } } 
 __G7____jh____VQ__x = __G7____jh__success ;
 __G7____jh____VQ__z =(! __G7____jh____VQ__x ); 
 __G7____jh____VQ____end :
 if(! __G7____jh____VQ__z )goto __G7____jh____UQ__fi ;
 __G7____jh____WQ = "Failed a Dynamic allocation" ;
 goto __G7____jh____XQ____qD ;
 __builtin_unreachable();
 __G7____jh____UQ__fi :
 __G7____jh____cQ = 0 ;
 __G7____jh____eQ__bytesize = sizeof ( __G7____jh____eQ____EF )* __G7____gh__z ; 
 __G7____jh____eQ____end :
 memcpy (( char *) __G7____jh__mem ,( char *) __G7____dh____m__contents , __G7__len_x ); memcpy (( char *) __G7____jh__mem + __G7__len_x ,( char *) __F7____0a__contents , __G7__len_y );(( char *) __G7____jh__mem )[ __G7__total_len ]=0; 
 __G7____mh__contents = __G7____jh__mem ;
 __76____BQ = __G7____jh__self____BQ ;
 __76__acquired = __76__acquired ;
 __76__size = __76__size ;
 __76__allocated = __76__allocated ;
 __76____dynamic_entry = __76____dynamic_entry ;
 printf ( "%s\n" ,( char *) __G7____mh__contents ); 
 __H7____end :
 goto __96__el ;
 __96__fi :
 __I7 = "[ \033[32mOK\033[0m ] " ;
 __J7 = ".s" ;
 __K7____ra__length = strlen ( name ); __K7____ra__contents =( ptr ) name ; __K7____ra__first = name [0]; __K7____ra__noptr =( ptr ) __K7____ra__noptr ; 
 __K7____ra____m__contents = __K7____ra__contents ;
 __K7____sa__length = strlen ( __J7 ); __K7____sa__contents =( ptr ) __J7 ; __K7____sa__first = __J7 [0]; __K7____sa__noptr =( ptr ) __K7____sa__noptr ; 
 __K7____sa____m__contents = __K7____sa__contents ;
 __K7__len_x = __K7____ra__length ; __K7__len_y = __K7____sa__length ; __K7__total_len = __K7__len_x + __K7__len_y ; __K7__first = __K7____ra__length ? __K7____ra__first : __K7____sa__first ; 
 __K7____ta = 1 ;
 __K7____ua__z = __K7__total_len + __K7____ta ; 
 __K7____ua____end :
 __K7____va = 0 ;
 __K7____xa____QQ = __76__acquired ;
 __K7____xa____RQ__z =(! __K7____xa____QQ ); 
 __K7____xa____RQ____end :
 if(! __K7____xa____RQ__z )goto __K7____xa____PQ__fi ;
 __K7____xa____SQ = "Did not initialize Dynamic" ;
 goto __K7____xa____TQ____qD ;
 __builtin_unreachable();
 __K7____xa____PQ__fi :
 __K7____xa__next_size = __76__size +1; __K7____xa__success = true ; __K7____xa__self__allocated__prev = __76__allocated ; if ( __K7____xa__next_size >= __76__allocated ) { __76__allocated = __76__allocated + __76__allocated /2+1; __K7____xa__next_acquired =( ptr )((( ptr **) __76__acquired )[0]? __runtime_realloc ((( ptr **) __76__acquired )[0], __76__allocated * sizeof ( ptr ), __K7____xa__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __76__allocated * sizeof ( ptr ))); if ( __K7____xa__success = __K7____xa__next_acquired )(( ptr **) __76__acquired )[0]=( ptr *) __K7____xa__next_acquired ; } if ( __K7____xa__success ) { __K7____xa__mem =( ptr ) __runtime_alloc ( __K7____ua__z * sizeof ( __K7____xa____OQ )); if ( __K7____xa__success = __K7____xa__mem ) {(( ptr **) __76__acquired )[0][ __76__size ]= __K7____xa__mem ; __76__size = __K7____xa__next_size ; } } 
 __K7____xa____VQ__x = __K7____xa__success ;
 __K7____xa____VQ__z =(! __K7____xa____VQ__x ); 
 __K7____xa____VQ____end :
 if(! __K7____xa____VQ__z )goto __K7____xa____UQ__fi ;
 __K7____xa____WQ = "Failed a Dynamic allocation" ;
 goto __K7____xa____XQ____qD ;
 __builtin_unreachable();
 __K7____xa____UQ__fi :
 __K7____xa____cQ = 0 ;
 __K7____xa____eQ__bytesize = sizeof ( __K7____xa____eQ____EF )* __K7____ua__z ; 
 __K7____xa____eQ____end :
 memcpy (( char *) __K7____xa__mem ,( char *) __K7____ra____m__contents , __K7__len_x ); memcpy (( char *) __K7____xa__mem + __K7__len_x ,( char *) __K7____sa____m__contents , __K7__len_y );(( char *) __K7____xa__mem )[ __K7__total_len ]=0; 
 __K7____0a__contents = __K7____xa__mem ;
 __76____BQ = __K7____xa__self____BQ ;
 __76__acquired = __76__acquired ;
 __76__size = __76__size ;
 __76__allocated = __76__allocated ;
 __76____dynamic_entry = __76____dynamic_entry ;
 __L7____dh__length = strlen ( __I7 ); __L7____dh__contents =( ptr ) __I7 ; __L7____dh__first = __I7 [0]; __L7____dh__noptr =( ptr ) __L7____dh__noptr ; 
 __L7____dh____m__contents = __L7____dh__contents ;
 __L7__len_x = __L7____dh__length ; __L7__len_y = __K7__total_len ; __L7__total_len = __L7__len_x + __L7__len_y ; __L7__first = __L7____dh__length ? __L7____dh__first : __K7__first ; 
 __L7____fh = 1 ;
 __L7____gh__z = __L7__total_len + __L7____fh ; 
 __L7____gh____end :
 __L7____hh = 0 ;
 __L7____jh____QQ = __76__acquired ;
 __L7____jh____RQ__z =(! __L7____jh____QQ ); 
 __L7____jh____RQ____end :
 if(! __L7____jh____RQ__z )goto __L7____jh____PQ__fi ;
 __L7____jh____SQ = "Did not initialize Dynamic" ;
 goto __L7____jh____TQ____qD ;
 __builtin_unreachable();
 __L7____jh____PQ__fi :
 __L7____jh__next_size = __76__size +1; __L7____jh__success = true ; __L7____jh__self__allocated__prev = __76__allocated ; if ( __L7____jh__next_size >= __76__allocated ) { __76__allocated = __76__allocated + __76__allocated /2+1; __L7____jh__next_acquired =( ptr )((( ptr **) __76__acquired )[0]? __runtime_realloc ((( ptr **) __76__acquired )[0], __76__allocated * sizeof ( ptr ), __L7____jh__self__allocated__prev * sizeof ( ptr )): __runtime_alloc ( __76__allocated * sizeof ( ptr ))); if ( __L7____jh__success = __L7____jh__next_acquired )(( ptr **) __76__acquired )[0]=( ptr *) __L7____jh__next_acquired ; } if ( __L7____jh__success ) { __L7____jh__mem =( ptr ) __runtime_alloc ( __L7____gh__z * sizeof ( __L7____jh____OQ )); if ( __L7____jh__success = __L7____jh__mem ) {(( ptr **) __76__acquired )[0][ __76__size ]= __L7____jh__mem ; __76__size = __L7____jh__next_size ; } } 
 __L7____jh____VQ__x = __L7____jh__success ;
 __L7____jh____VQ__z =(! __L7____jh____VQ__x ); 
 __L7____jh____VQ____end :
 if(! __L7____jh____VQ__z )goto __L7____jh____UQ__fi ;
 __L7____jh____WQ = "Failed a Dynamic allocation" ;
 goto __L7____jh____XQ____qD ;
 __builtin_unreachable();
 __L7____jh____UQ__fi :
 __L7____jh____cQ = 0 ;
 __L7____jh____eQ__bytesize = sizeof ( __L7____jh____eQ____EF )* __L7____gh__z ; 
 __L7____jh____eQ____end :
 memcpy (( char *) __L7____jh__mem ,( char *) __L7____dh____m__contents , __L7__len_x ); memcpy (( char *) __L7____jh__mem + __L7__len_x ,( char *) __K7____0a__contents , __L7__len_y );(( char *) __L7____jh__mem )[ __L7__total_len ]=0; 
 __L7____mh__contents = __L7____jh__mem ;
 __76____BQ = __L7____jh__self____BQ ;
 __76__acquired = __76__acquired ;
 __76__size = __76__size ;
 __76__allocated = __76__allocated ;
 __76____dynamic_entry = __76____dynamic_entry ;
 printf ( "%s\n" ,( char *) __L7____mh__contents ); 
 __M7____end :
 __96__el :
 __end :
goto __return;

// ERROR HANDLING
__K7____xa____XQ____qD :
 printf ( "%s\n" , __K7____xa____WQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__G7____jh____TQ____qD :
 printf ( "%s\n" , __G7____jh____SQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__K7____xa____TQ____qD :
 printf ( "%s\n" , __K7____xa____SQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__36____xa____XQ____qD :
 printf ( "%s\n" , __36____xa____WQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__F7____xa____XQ____qD :
 printf ( "%s\n" , __F7____xa____WQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__L7____jh____XQ____qD :
 printf ( "%s\n" , __L7____jh____WQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__46____jh____TQ____qD :
 printf ( "%s\n" , __46____jh____SQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__errocode =__UNHANDLED__ERROR;
goto __failsafe ;
__G7____jh____XQ____qD :
 printf ( "%s\n" , __G7____jh____WQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__L7____jh____TQ____qD :
 printf ( "%s\n" , __L7____jh____SQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__36____xa____TQ____qD :
 printf ( "%s\n" , __36____xa____SQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__F7____xa____TQ____qD :
 printf ( "%s\n" , __F7____xa____SQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__B7 :
__result__errocode=__UNHANDLED__ERROR;
goto __failsafe;
__46____jh____XQ____qD :
 printf ( "%s\n" , __46____jh____WQ ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
__service_stack_floor_handler:
printf("Insufficient stack for safe service call (too much recursion or stack allocation)\n");
__result__errocode=__STACK__ERROR;
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
if ( __76__acquired ) { for ( __76____dynamic_entry =0; __76____dynamic_entry < __76__size ;++ __76____dynamic_entry ) { __runtime_free ((( ptr **) __76__acquired )[0][ __76____dynamic_entry ]); } __runtime_free ( __76__acquired ); __76__acquired =0; __76__size =0; __76__allocated =0; } 
 if ( __76__acquired ) { for ( __76____HQ____dynamic_entry =0; __76____HQ____dynamic_entry < __76____HQ____CQ ;++ __76____HQ____dynamic_entry ) { __runtime_free ((( ptr **) __76__acquired )[0][ __76____HQ____dynamic_entry ]); } __runtime_free ( __76__acquired ); __76__acquired =0; __76____HQ____CQ =0; __76____HQ____DQ =0; } 
if ( __z6__acquired ) { for ( __z6____dynamic_entry =0; __z6____dynamic_entry < __z6__size ;++ __z6____dynamic_entry ) { __runtime_free ((( ptr **) __z6__acquired )[0][ __z6____dynamic_entry ]); } __runtime_free ( __z6__acquired ); __z6__acquired =0; __z6__size =0; __z6__allocated =0; } 
 if ( __z6__acquired ) { for ( __z6____HQ____dynamic_entry =0; __z6____HQ____dynamic_entry < __z6____HQ____CQ ;++ __z6____HQ____dynamic_entry ) { __runtime_free ((( ptr **) __z6__acquired )[0][ __z6____HQ____dynamic_entry ]); } __runtime_free ( __z6__acquired ); __z6__acquired =0; __z6____HQ____CQ =0; __z6____HQ____DQ =0; } 
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__errocode;
}



int main() {
struct main__822__state __main_args={0};
__smolambda_initialize_service_tasks(main__822, &__main_args);
return __main_args.err;
}

