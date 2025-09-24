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

#include<string.h>

#include<stdlib.h>

#include<stdio.h>

struct main__869__state{errcode err;};
void main__869(void *__void__state);

void main__869(void *__void__state){
errcode __result__errocode=0;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__869__state *__state=(struct main__869__state*)__void__state;
bool __wDB____EB____G__z=0;
u64 __wDB____EB__x=0;
char __wDB__first=0;
bool __wDB____AB__z=0;
char __qDB__z=0;
bool __pDB____G__z=0;
u64 __oDB=0;
char __iDB____xBB__first=0;
u64 __iDB____xBB__bytes_read=0;
ptr __iDB____xBB__ret=0;
bool __wDB____7__z=0;
bool __gDB____F9__z=0;
bool __gDB____E9__z=0;
ptr __gDB____E9__x=0;
ptr __gDB__contents=0;
ptr __gDB____C9____m__contents=0;
char __gDB____C9__first=0;
ptr __gDB____C9__contents=0;
ptr __wDB__contents=0;
ptr __gDB____C9__noptr=0;
ptr __iDB____xBB____1AB__contents=0;
ptr __UDB____m__contents=0;
cstr __aDB____jW____RI____uF=0;
char __aDB____jW____RI____qF=0;
u64 __uDB=0;
u64 __aDB____jW____RI____mF=0;
ptr __UDB__noptr=0;
u64 __vDB__z=0;
bool __rDB__z=0;
char __WDB__z=0;
u64 __pDB__z=0;
ptr __UDB__contents=0;
bool __vDB____G__z=0;
u64 __sDB=0;
u64 __ZDB=0;
bool __WDB____EC__z=0;
cstr __TDB=0;
char __UDB__first=0;
cstr __aDB____jW____RI____oF=0;
u64 __UDB__length=0;
u64 __VDB=0;
bool __aDB____jW____RI____nF__z=0;
bool __aDB____jW____RI____tF__z=0;
bool __aDB____jW____RI____sF=0;
ptr __aDB____jW____RI__mem=0;
bool __qDB____EC__z=0;
u64 __aDB____kW____SP=0;
cstr __fDB=0;
u64 __gDB____C9__length=0;

// IMPLEMENTATION
__TDB = "\n" ;
 __UDB__length = strlen ( __TDB ); __UDB__contents =( ptr ) __TDB ; __UDB__first = __TDB [0]; __UDB__noptr =( ptr ) __UDB__noptr ; 
 __UDB____m__contents = __UDB__contents ;
 goto __UDB____m____end ;
 __UDB____m____end :
 goto __UDB____end ;
 __UDB____end :
 __VDB = 0 ;
 __WDB____EC__z = __UDB__length <= __VDB ; 
 goto __WDB____EC____end ;
 __WDB____EC____end :
 if(! __WDB____EC__z )goto __WDB____DC__fi ;
 goto __WDB____FC ;
 __builtin_unreachable();
 __WDB____DC__if :
 __WDB____DC__fi :
 __WDB__z =( __builtin_constant_p ( __VDB )&& __VDB ==0)? __UDB__first :(( char *) __UDB____m__contents )[ __VDB ]; 
 goto __WDB____end ;
 __WDB____end :
 goto __YDB____end ;
 __YDB____end :
 __ZDB = 1024 ;
 goto __aDB____jW____OI____end ;
 __aDB____jW____OI____end :
 __aDB____jW____RI____mF = 0 ;
 __aDB____jW____RI____nF__z =( __ZDB == __aDB____jW____RI____mF ); 
 goto __aDB____jW____RI____nF____end ;
 __aDB____jW____RI____nF____end :
 if(! __aDB____jW____RI____nF__z )goto __aDB____jW____RI____lF__fi ;
 __aDB____jW____RI____oF = "Cannot allocate zero size" ;
 goto __aDB____jW____RI____pF____pD ;
 __builtin_unreachable();
 __aDB____jW____RI____pF____end :
 goto __aDB____jW____RI____lF__if ;
 __aDB____jW____RI____lF__if :
 __aDB____jW____RI____lF__fi :
 __aDB____jW____RI__mem = alloca ( __ZDB * sizeof ( __aDB____jW____RI____qF )); 
 __aDB____jW____RI____sF = __aDB____jW____RI__mem ;
 __aDB____jW____RI____tF__z =(! __aDB____jW____RI____sF ); 
 goto __aDB____jW____RI____tF____end ;
 __aDB____jW____RI____tF____end :
 if(! __aDB____jW____RI____tF__z )goto __aDB____jW____RI____rF__fi ;
 __aDB____jW____RI____uF = "Failed a Stack allocation" ;
 goto __aDB____jW____RI____vF____pD ;
 __builtin_unreachable();
 __aDB____jW____RI____vF____end :
 goto __aDB____jW____RI____rF__if ;
 __aDB____jW____RI____rF__if :
 __aDB____jW____RI____rF__fi :
 goto __aDB____jW____RI____zF____end ;
 __aDB____jW____RI____zF____end :
 __aDB____jW____RI____2F____end :
 goto __aDB____jW____RI____end ;
 __aDB____jW____RI____end :
 goto __aDB____jW____end ;
 __aDB____jW____end :
 __aDB____kW____SP = 0 ;
 goto __aDB____kW____YP____end ;
 __aDB____kW____YP____end :
 goto __aDB____kW____UP__with ;
 __aDB____kW____UP__with :
 goto __aDB____kW____end ;
 __aDB____kW____end :
 goto __aDB____end ;
 __aDB____end :
 goto __eDB____end ;
 __eDB____end :
 __fDB = "README.md" ;
 __gDB____C9__length = strlen ( __fDB ); __gDB____C9__contents =( ptr ) __fDB ; __gDB____C9__first = __fDB [0]; __gDB____C9__noptr =( ptr ) __gDB____C9__noptr ; 
 __gDB____C9____m__contents = __gDB____C9__contents ;
 goto __gDB____C9____m____end ;
 __gDB____C9____m____end :
 goto __gDB____C9____end ;
 __gDB____C9____end :
 __gDB__contents = fopen (( char *) __gDB____C9____m__contents , "r" ); 
 __gDB____E9__x = __gDB__contents ;
 __gDB____E9__z =( __gDB____E9__x ); 
 goto __gDB____E9____end ;
 __gDB____E9____end :
 __gDB____F9__z =(! __gDB____E9__z ); 
 goto __gDB____F9____end ;
 __gDB____F9____end :
 if(! __gDB____F9__z )goto __gDB____D9__fi ;
 goto __gDB____G9 ;
 __builtin_unreachable();
 __gDB____D9__if :
 __gDB____D9__fi :
 goto __gDB____J9____end ;
 __gDB____J9____end :
 goto __gDB____end ;
 __gDB____end :
 __hDB__loop :
 __iDB____xBB__ret = __gDB__contents ?( ptr ) fgets (( char *) __aDB____jW____RI__mem , __ZDB ,( FILE *) __gDB__contents ): __gDB__contents ; __iDB____xBB__bytes_read = __iDB____xBB__ret ? strlen (( char *) __iDB____xBB__ret ):0; __iDB____xBB__first =(( char *) __aDB____jW____RI__mem )[0]; if( __iDB____xBB__bytes_read &&(( char *) __aDB____jW____RI__mem )[ __iDB____xBB__bytes_read -1]== 10 ) { __iDB____xBB__bytes_read --; if( __iDB____xBB__bytes_read &&(( char *) __aDB____jW____RI__mem )[ __iDB____xBB__bytes_read -1]== 13 ) __iDB____xBB__bytes_read --;(( char *) __aDB____jW____RI__mem )[ __iDB____xBB__bytes_read ]=0; } __aDB____kW____SP = __aDB____kW____SP + __iDB____xBB__bytes_read ; 
 __iDB____xBB____1AB__contents = __iDB____xBB__ret ;
 goto __iDB____xBB____1AB____end ;
 __iDB____xBB____1AB____end :
 goto __iDB____xBB____end ;
 __iDB____xBB____end :
 goto __iDB____yBB____j____end ;
 __iDB____yBB____j____end :
 goto __iDB____yBB____end ;
 __iDB____yBB____end :
 goto __iDB____end ;
 __iDB____end :
 if(! __iDB____xBB__ret )goto __hDB__while ;
 goto __kDB____end ;
 __kDB____end :
 if(! __iDB____xBB__bytes_read )goto __mDB ;
 goto __nDB____end ;
 __nDB____end :
 __oDB = 1 ;
 __pDB____G__z = __oDB > __iDB____xBB__bytes_read ; 
 goto __pDB____G____end ;
 __pDB____G____end :
 if(! __pDB____G__z )goto __pDB____F__fi ;
 goto __pDB____H ;
 __builtin_unreachable();
 __pDB____F__if :
 __pDB____F__fi :
 __pDB__z = __iDB____xBB__bytes_read - __oDB ; 
 goto __pDB____end ;
 __pDB____end :
 __qDB____EC__z = __iDB____xBB__bytes_read <= __pDB__z ; 
 goto __qDB____EC____end ;
 __qDB____EC____end :
 if(! __qDB____EC__z )goto __qDB____DC__fi ;
 goto __qDB____FC ;
 __builtin_unreachable();
 __qDB____DC__if :
 __qDB____DC__fi :
 __qDB__z =( __builtin_constant_p ( __pDB__z )&& __pDB__z ==0)? __iDB____xBB__first :(( char *) __iDB____xBB____1AB__contents )[ __pDB__z ]; 
 goto __qDB____end ;
 __qDB____end :
 __rDB__z =( __qDB__z == __WDB__z ); 
 goto __rDB____end ;
 __rDB____end :
 __mDB :
 if(! __iDB____xBB__bytes_read )goto __jDB__fi ;
 __sDB = 0 ;
 goto __tDB____end ;
 __tDB____end :
 __uDB = 1 ;
 __vDB____G__z = __uDB > __iDB____xBB__bytes_read ; 
 goto __vDB____G____end ;
 __vDB____G____end :
 if(! __vDB____G__z )goto __vDB____F__fi ;
 goto __vDB____H ;
 __builtin_unreachable();
 __vDB____F__if :
 __vDB____F__fi :
 __vDB__z = __iDB____xBB__bytes_read - __uDB ; 
 goto __vDB____end ;
 __vDB____end :
 goto __wDB____5____end ;
 __wDB____5____end :
 __wDB____7__z = __vDB__z < __sDB ; 
 goto __wDB____7____end ;
 __wDB____7____end :
 if(! __wDB____7__z )goto __wDB____6__fi ;
 goto __wDB____8 ;
 __builtin_unreachable();
 __wDB____6__if :
 __wDB____6__fi :
 __wDB____AB__z = __vDB__z > __iDB____xBB__bytes_read ; 
 goto __wDB____AB____end ;
 __wDB____AB____end :
 if(! __wDB____AB__z )goto __wDB____9__fi ;
 goto __wDB____BB ;
 __builtin_unreachable();
 __wDB____9__if :
 __wDB____9__fi :
 __wDB__contents =( ptr )(( char *) __iDB____xBB____1AB__contents + __sDB * sizeof ( char )); __wDB__first = __sDB == __vDB__z ?0:(( __builtin_constant_p ( __sDB )&& __sDB ==0)? __iDB____xBB__first :(( char *) __iDB____xBB____1AB__contents )[ __sDB ]); 
 __wDB____EB__x = __vDB__z ;
 __wDB____EB____G__z = __sDB > __wDB____EB__x ; 
 goto __wDB____EB____G____end ;
 __wDB____EB____G____end :
 if(! __wDB____EB____G__z )goto __wDB____EB____F__fi ;
 goto __wDB____EB____H ;
 __builtin_unreachable();
 __wDB____EB____F__if :
 __wDB____EB____F__fi :
 __wDB____EB____end :
 goto __wDB____FB____end ;
 __wDB____FB____end :
 goto __wDB____end ;
 __wDB____end :
 __jDB__if :
 __jDB__fi :
 printf ( "%.*s\n" ,( int ) __iDB____xBB__bytes_read ,( char *) __iDB____xBB____1AB__contents ); 
 __xDB____end :
 goto __hDB__loop ;
 __hDB__while :
 __bDB__on :
 __end :
goto __return;

// ERROR HANDLING
__WDB____FC :
 printf ( "String index out of bounds\n" ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __aDB____jW____RI____pF____pD :
 printf ( "%s\n" , __aDB____jW____RI____oF ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __aDB____jW____RI____vF____pD :
 printf ( "%s\n" , __aDB____jW____RI____uF ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __gDB____G9 :
 printf ( "Failed to open file: %.*s\n" ,( int ) __gDB____C9__length ,( char *) __gDB____C9____m__contents ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __pDB____H :
 printf ( "Error: unsigned substraction yielded a negative\n" ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __qDB____FC :
 printf ( "String index out of bounds\n" ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __vDB____H :
 printf ( "Error: unsigned substraction yielded a negative\n" ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __wDB____8 :
 printf ( "String slice cannot end before it starts\n" ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __wDB____BB :
 printf ( "String slice must end at most at the length of the base string\n" ); 
__result__errocode=__USER__ERROR;
goto __failsafe;
 __wDB____EB____H :
 printf ( "Error: unsigned substraction yielded a negative\n" ); 
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
struct main__869__state __main_args={0};
__smolambda_initialize_service_tasks(main__869, &__main_args);
return __main_args.err;
}

