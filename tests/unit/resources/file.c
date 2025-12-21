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
typedef uint64_t new;
typedef double f64;

#include<string.h>

#include<stdlib.h>

#include<stdio.h>

struct main__435__state{errcode err;};
__externc void main__435(void *__void__state);

void main__435(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1784;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__435__state *__state=(struct main__435__state*)__void__state;
u64 line__length=0;
char line__first=0;
ptr __0mEC=0;
char __0nEC=0;
bool __0iEC=0;
ptr __0hDC=0;
ptr __0hEC=0;
u64 __0cEC=0;
ptr __0dDC=0;
ptr __0fEC=0;
u64 __0aEC=0;
u64 __0dEC=0;
ptr __0oEC=0;
ptr __0bEC=0;
cstr __0WEC=0;
u64 __0ZEC=0;
ptr __0UEC=0;
bool __0SEC=0;
u64 __0TDC=0;
char __0gEC=0;
u64 __0OEC=0;
u64 __0REC=0;
bool __0ODC=0;
u64 __0MEC=0;
ptr line__contents=0;
ptr __0KEC=0;
u64 __0NEC=0;
ptr __0YEC=0;
ptr __0LEC=0;
cstr __0IDC=0;
cstr __0GEC=0;
char __0JEC=0;
bool __0FDC=0;
u64 __0HEC=0;
ptr __0S8B__mem=0;
ptr __0QEC=0;
ptr __07CC=0;
ptr line__memory=0;
bool __05CC=0;
ptr __0IEC=0;
u64 __0wCC=0;
u64 __0qCC=0;
char __0pCC=0;
char __0oCC=0;
ptr __0nCC=0;
ptr __0mCC=0;
bool __0lCC=0;
bool __0kCC=0;
cstr __0hCC=0;
ptr __0fCC=0;
u64 __0eCC=0;
char __0dCC=0;
ptr __0cCC=0;
bool __0aCC=0;
bool __0YCC=0;
u64 __0WCC=0;
bool __0VCC=0;
u64 __0RCC=0;
bool __0PCC=0;
char __0LCC=0;
bool __0JCC=0;
u64 __0GCC=0;
u64 __0FCC=0;
bool __0ECC=0;
u64 __0ACC=0;
ptr __0W8B__contents=0;
bool __08BC=0;
ptr __02BC=0;
char __01BC=0;
u64 __00BC=0;
bool __0zBC=0;
u64 __0vBC=0;

// IMPLEMENTATION
__0GEC = "\n" ;
 __0HEC = strlen ( __0GEC ); __0IEC =( ptr ) __0GEC ; __0JEC = __0GEC [0]; __0KEC =0; 
 __0LEC = __0IEC ;
 __0MEC = 1 ;
 __0NEC = 1024 ;
 __0OEC = __0NEC * __0MEC ; 
 __0PEC :
 __0REC = __0OEC ; __0S8B__mem =( __0REC + __service_stack_floor >=( char *)& __0REC )?0: alloca ( __0REC ); 
 __0ODC = __0S8B__mem ;
 __0SEC =(! __0ODC ); 
 __0TEC :
 if(! __0SEC )goto __0VEC ;
 __0WEC = "Insufficient stack for allocation (too much recursion or stack allocation, or zero size requested)" ;
 [[unlikely]] goto __0XEC ;
 __builtin_unreachable();
 __0VEC :
 __0wCC = __0OEC ;
 __07CC = __0S8B__mem ;
 __0YEC = __0S8B__mem ;
 __0ZEC = 0 ;
 __0aEC = __0ZEC ;
 __0bEC = 0 ;
 __0IDC = "README.md" ;
 __0cEC = strlen ( __0IDC ); __0fEC =( ptr ) __0IDC ; __0gEC = __0IDC [0]; __0hEC =0; 
 __0dDC = __0fEC ;
 __0W8B__contents = fopen (( char *) __0dDC , "r" ); 
 __0hDC = __0W8B__contents ;
 __0iEC =( __0hDC ); 
 __0jEC :
 __0FDC =(! __0iEC ); 
 __0ZDC :
 if(! __0FDC )goto __0MDC ;
 [[unlikely]] goto __0kEC ;
 __builtin_unreachable();
 __0MDC :
 __0lEC :
 __0mEC = line__contents ;
 __0dEC = line__length ;
 __0nEC = line__first ;
 __0UEC = line__memory ;
 __0oEC = __0QEC ;
 __0TDC = __0qCC ;
 __0pCC = __0oCC ;
 __0nCC = __0mCC ;
 __0lCC = __07CC ;
 __0kCC =(! __0lCC ); 
 __0jCC :
 if(! __0kCC )goto __0iCC ;
 __0hCC = "No reader contents" ;
 [[unlikely]] goto __0gCC ;
 __builtin_unreachable();
 __0iCC :
 __0fCC = __0W8B__contents ?( ptr ) fgets (( char *) __07CC , __0wCC ,( FILE *) __0W8B__contents ): __0W8B__contents ; __0eCC = __0fCC ? strlen (( char *) __0fCC ):0; __0dCC =(( char *) __07CC )[0]; if ( __0eCC &&(( char *) __07CC )[ __0eCC -1]== 10 ) { __0eCC --; if ( __0eCC &&(( char *) __07CC )[ __0eCC -1]== 13 ) __0eCC --;(( char *) __07CC )[ __0eCC ]=0; } __0aEC = __0aEC + __0eCC ; 
 __0cCC = __0fCC ;
 if ( __0YEC )((( char *) __0cCC )[ __0eCC ])=0; 
 __0bCC :
 __0oEC = __0cCC ;
 __0TDC = __0eCC ;
 __0pCC = __0dCC ;
 __0nCC = __0YEC ;
 __0aCC = __0fCC ;
 __0mEC = __0oEC ;
 __0dEC = __0TDC ;
 __0nEC = __0pCC ;
 __0UEC = __0nCC ;
 __0wCC = __0wCC ;
 __07CC = __07CC ;
 __0YEC = __0YEC ;
 __0aEC = __0aEC ;
 __0W8B__contents = __0W8B__contents ;
 line__contents = __0mEC ;
 line__length = __0dEC ;
 line__first = __0nEC ;
 line__memory = __0UEC ;
 if(! __0aCC )goto __0ZCC ;
 __0YCC = line__length ;
 if(! __0YCC )goto __0XCC ;
 __0WCC = 1 ;
 __0VCC = __0WCC > line__length ; 
 __0UCC :
 if(! __0VCC )goto __0TCC ;
 [[unlikely]] goto __0SCC ;
 __builtin_unreachable();
 __0TCC :
 __0RCC = line__length - __0WCC ; 
 __0QCC :
 __0PCC = line__length <= __0RCC ; 
 __0OCC :
 if(! __0PCC )goto __0NCC ;
 [[unlikely]] goto __0MCC ;
 __builtin_unreachable();
 __0NCC :
 __0LCC =( __builtin_constant_p ( __0RCC )&& __0RCC ==0)? line__first :(( char *) line__contents )[ __0RCC ]; 
 __0KCC :
 __0JCC =( __0LCC == __0JEC ); 
 __0ICC :
 __0YCC = __0JCC ;
 __0XCC :
 if(! __0YCC )goto __0HCC ;
 __0GCC = 0 ;
 __0FCC = 1 ;
 __0ECC = __0FCC > line__length ; 
 __0DCC :
 if(! __0ECC )goto __0CCC ;
 [[unlikely]] goto __0BCC ;
 __builtin_unreachable();
 __0CCC :
 __0ACC = line__length - __0FCC ; 
 __09BC :
 __08BC = __0ACC < __0GCC ; 
 __07BC :
 if(! __08BC )goto __06BC ;
 [[unlikely]] goto __05BC ;
 __builtin_unreachable();
 __06BC :
 __05CC = __0ACC > line__length ; 
 __04BC :
 if(! __05CC )goto __0eEC ;
 [[unlikely]] goto __03BC ;
 __builtin_unreachable();
 __0eEC :
 __02BC =( ptr )(( char *) line__contents + __0GCC * sizeof ( char )); __01BC = __0GCC == __0ACC ?0:(( __builtin_constant_p ( __0GCC )&& __0GCC ==0)? line__first :(( char *) line__contents )[ __0GCC ]); 
 __00BC = __0ACC ;
 __0zBC = __0GCC > __00BC ; 
 __0yBC :
 if(! __0zBC )goto __0xBC ;
 [[unlikely]] goto __0wBC ;
 __builtin_unreachable();
 __0xBC :
 __0vBC = __00BC - __0GCC ; 
 __0uBC :
 line__contents = __02BC ;
 line__length = __0vBC ;
 line__first = __01BC ;
 line__memory = line__contents ;
 __0HCC :
 printf ( "%.*s\n" ,( int ) line__length ,( char *) line__contents ); 
 __0tBC :
 goto __0lEC ;
 __0ZCC :
 __0sBC :
goto __return;

// ERROR HANDLING
__03BC :
 printf ( "String slice must end at most at the length of the base string\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0wBC :
 printf ( "Error: unsigned subtraction yielded a negative\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0BCC :
 printf ( "Error: unsigned subtraction yielded a negative\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__05BC :
 printf ( "String slice cannot end before it starts\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0kEC :
 printf ( "Failed to open file: %.*s\n" ,( int ) __0cEC ,( char *) __0dDC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0XEC :
 printf ( "%s\n" , __0WEC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0SCC :
 printf ( "Error: unsigned subtraction yielded a negative\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0gCC :
 printf ( "%s\n" , __0hCC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0MCC :
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
if ( __0W8B__contents ) fclose (( FILE *) __0W8B__contents ); __0W8B__contents =0; 
__TRANSIENT( __0S8B__mem )
__runtime_apply_linked(__smolambda_all_task_results, __runtime_free, 1);
__state->err =  __result__error_code;
}



int main() {
struct main__435__state __main_args={0};
__smolambda_initialize_service_tasks(main__435, &__main_args);
return __main_args.err;
}

