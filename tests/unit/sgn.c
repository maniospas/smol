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

#include<stdio.h>

struct main__184__state{errcode err;};
__externc void main__184(void *__void__state);

void main__184(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 1076;
struct main__184__state *__state=(struct main__184__state*)__void__state;
cstr __8E=0;
cstr __7E=0;
bool __6E__z=0;
f64 __5E=0;
cstr __3E__r=0;
f64 __2E=0;

// IMPLEMENTATION
__2E = 1.0 ;
 __5E = 0.0 ;
 __6E__z = __2E > __5E ; 
 __6E____end :
 if(! __6E__z )goto __4E__fi ;
 __7E = "positive" ;
 __3E__r = __7E ;
 goto __3E ;
 __4E__fi :
 __8E = "negative" ;
 __3E__r = __8E ;
 __3E :
 printf ( "%s\n" , __3E__r ); 
 __9E____end :
 __end :
goto __return;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
__state->err =  __result__error_code;
}



int main() {
struct main__184__state __main_args={0};
__smolambda_initialize_service_tasks(main__184, &__main_args);
return __main_args.err;
}

