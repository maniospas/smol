#define SMOLAMBDA_SERVICES 2
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

#include<stdlib.h>

#include<stdio.h>

#include "std/oscommon.h"

#include "raylib.h"

struct test__496__state{errcode err;};
__externc void test__496(void *__void__state);
struct main__497__state{errcode err;};
__externc void main__497(void *__void__state);

void main__497(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 2116;
__SmolambdaLinkedMemory* __smolambda_all_tasks = 0;
__SmolambdaLinkedMemory* __smolambda_all_task_results = 0;
struct main__497__state *__state=(struct main__497__state*)__void__state;
struct test__496__state* __0bbC____state = 0 ;
ptr __03fC=0;
errcode __02fC=0;

// IMPLEMENTATION
{char mark;if(__service_stack_floor+ 3564 >=(char*)&mark) goto __service_stack_floor_handler;} __0bbC____state = (struct test__496__state*)__runtime_calloc(sizeof(struct test__496__state)) ;
 __smolambda_all_task_results = __runtime_prepend_linked(__smolambda_all_task_results, __0bbC____state ) ;
 __03fC = __smolambda_add_task ( test__496 , __0bbC____state ) ;
 __smolambda_all_tasks = __runtime_prepend_linked(__smolambda_all_tasks, __03fC ) ;
 if( __02fC ) goto  __result_unhandled_error ;
 __01fC :
goto __return;

// ERROR HANDLING
__result_unhandled_error :
 printf("Unhandled error\n") ;
 __result__error_code =__UNHANDLED__ERROR;
goto __failsafe ;
__service_stack_floor_handler:
printf("Insufficient stack for safe service call (too much recursion or stack allocation)\n");
__result__error_code=__STACK__ERROR;
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


void test__496(void *__void__state){
errcode __result__error_code=0;
char* __service_stack_floor = (char*)__runtime_stack_bottom();
u64 __service_stack_size = 3524;
struct test__496__state *__state=(struct test__496__state*)__void__state;
bool __0KsC=0;
u64 __0JsC=0;
ptr __0IsC=0;
cstr __0GsC=0;
bool __0DsC=0;
u64 __0CsC=0;
u64 __0AsC=0;
u64 __09rC=0;
char __08rC=0;
u64 __07rC=0;
u64 __06rC=0;
u64 __05rC=0;
ptr __04rC=0;
ptr __03rC=0;
char __02rC=0;
ptr __01rC=0;
u64 __00rC=0;
cstr __0zrC=0;
__new __0yrC=0;
__new __0xrC=0;
__new __0wrC=0;
__new __0vrC=0;
bool __0rrC=0;
bool __0prC=0;
ptr __0orC=0;
char __0nrC=0;
ptr __0mrC=0;
u64 __0lrC=0;
cstr __0krC=0;
u64 __0grC=0;
u64 __0frC=0;
ptr __0erC=0;
ptr __0drC=0;
u64 __0crC=0;
u64 __0brC=0;
bool __0arC=0;
u64 __0ZrC=0;
u64 __0YrC=0;
ptr __0XrC=0;
u64 __0WrC=0;
ptr __0VrC=0;
cstr __0UrC=0;
bool __0SrC=0;
bool __0RrC=0;
cstr __0PrC=0;
bool __0MrC=0;
u64 __0LrC=0;
u64 __0KrC=0;
u64 __0JrC=0;
f64 __0IrC=0;
f64 __0FrC=0;
cstr window__title=0;
bool __0DrC=0;
bool __0CrC=0;
cstr __0BrC=0;
__new __0ArC=0;
f64 __09qC=0;
f64 __08qC=0;
f64 __07qC=0;
f64 __06qC=0;
f64 __05qC=0;
f64 __04qC=0;
bool __03qC=0;
f64 __0GrC=0;
ptr spheres__dynamic____buffer_contents=0;
u64 __02qC=0;
u64 spheres__dynamic____buffer_prev_capacity=0;
f64 __01qC=0;
cstr __00qC=0;
f64 __0zqC=0;
f64 __0yqC=0;
f64 __0xqC=0;
f64 __0wqC=0;
f64 __0vqC=0;
ptr __0uqC=0;
u64 __0tqC=0;
ptr __0uQC__dynamic=0;
cstr __0sqC=0;
ptr __0JRC__mem=0;
cstr __0KqC=0;
f64 __05pC=0;
f64 __01pC=0;
u64 spheres__dynamic____buffer_capacity=0;
f64 __0xpC=0;
ptr spheres__surface=0;
__new __0hpC=0;
u64 __0JtC=0;
cstr __0MtC=0;
u64 __0HtC=0;
u64 __0cpC=0;
u64 __0ItC=0;
f64 __0EtC=0;
bool __09sC=0;
u64 __0CtC=0;
ptr __0QpC=0;
u64 __0OtC=0;
u64 __06sC=0;
cstr __01sC=0;
f64 __04sC=0;
f64 __0FtC=0;
u64 __0KpC=0;
f64 __02sC=0;
f64 __0DtC=0;
u64 __0GtC=0;
bool window__ready=0;
u64 __0voC=0;
bool __0loC=0;
u64 __0RoC=0;
ptr __0RqC=0;
f64 accum_fps=0;
bool __0xtC=0;
u64 __0EoC=0;
u64 __09tC=0;
u64 __0wtC=0;
u64 __07tC=0;
u64 __0AuC=0;
u64 __0ptC=0;
f64 __06nC=0;
cstr __0ntC=0;
bool __0qtC=0;
bool __01tC=0;
f64 __0ztC=0;
f64 __0htC=0;
u64 __0ktC=0;
f64 __0ftC=0;
u64 __0wnC=0;
u64 __0itC=0;
cstr __0ttC=0;
f64 __0gtC=0;
u64 __0ZtC=0;
cstr __0XtC=0;
bool __0atC=0;
u64 __0ltC=0;
u64 __0jtC=0;
bool __0mtC=0;
bool __0UtC=0;
bool __0PtC=0;
cstr __0StC=0;
__new __0etC=0;
f64 dt=0;
ptr spheres__dynamic=0;
f64 window__size__h=0;
f64 window__size__w=0;
cstr __0vsC=0;
u64 __07sC=0;
u64 __05sC=0;
u64 __0nsC=0;
f64 __03mC=0;
cstr __0lsC=0;
bool __0osC=0;
bool __0zsC=0;
bool __0xsC=0;
cstr __0ymC=0;
u64 __0fsC=0;
u64 __0isC=0;
u64 __0dsC=0;
u64 __0gsC=0;
f64 __0tmC=0;
u64 __0esC=0;
u64 __0psC=0;
cstr __0ssC=0;
f64 prev_t=0;
__new __0asC=0;
__new __0YsC=0;
bool __0kmC=0;
bool __0WsC=0;
bool __0hsC=0;
u64 __0hmC=0;
__new __0PsC=0;
f64 __0SsC=0;
ptr __0NsC=0;
__new __0QsC=0;
u64 __0ZsC=0;
u64 __0csC=0;
f64 __0XmC=0;
bool __0TsC=0;
u64 __0TmC=0;
f64 __0RsC=0;
cstr __0UsC=0;
bool __0RmC=0;
u64 __0MmC=0;
u64 __05tC=0;
f64 __0ImC=0;
__new window____0V9B=0;
u64 __06tC=0;
u64 __0FmC=0;
f64 __04tC=0;
f64 __06lC=0;
u64 __0wlC=0;
u64 spheres__dynamic____buffer_alignment=0;
u64 __0slC=0;
u64 __0qlC=0;
__new __0ulC=0;
u64 spheres__dynamic____buffer_size=0;
bool __0olC=0;
u64 __0mlC=0;
u64 __0ilC=0;
u64 __0hlC=0;
f64 __0glC=0;
f64 __0flC=0;
f64 __0elC=0;
f64 __0dlC=0;
f64 __0clC=0;
f64 __0blC=0;
f64 __0alC=0;
f64 __0ZlC=0;
f64 __0YlC=0;
f64 __0XlC=0;
f64 __0WlC=0;
f64 __0VlC=0;
f64 __0UlC=0;
f64 __0TlC=0;
f64 __0RlC=0;
f64 __0PlC=0;
f64 __0OlC=0;
f64 __0MlC=0;
f64 __0KlC=0;
f64 __0JlC=0;
f64 __0IlC=0;
f64 __0HlC=0;
f64 __0FlC=0;
bool __0ElC=0;
f64 __0BlC=0;
f64 __0AlC=0;
f64 __07kC=0;
f64 __05kC=0;
bool __04kC=0;
f64 __01kC=0;
f64 __00kC=0;
f64 __0ykC=0;
f64 __0xkC=0;
f64 __0vkC=0;
f64 __0tkC=0;
bool __0skC=0;
f64 __0pkC=0;
f64 __0okC=0;
f64 __0lkC=0;
f64 __0jkC=0;
bool __0ikC=0;
f64 __0fkC=0;
f64 __0ekC=0;
f64 __0ckC=0;
f64 __0bkC=0;
f64 __0ZkC=0;
f64 __0YkC=0;
f64 __0WkC=0;
f64 __0UkC=0;
bool __0TkC=0;

// IMPLEMENTATION
__0uQC__dynamic = __runtime_calloc(3*sizeof(u64)) ;
 __0uqC = 0 ;
 spheres__dynamic = __0uQC__dynamic ;
 spheres__surface = __0uqC ;
 __0vqC = 100.0 ;
 __0wqC = 100.0 ;
 __0xqC = 30.0 ;
 __0yqC = 1000.0 ;
 __0zqC = 650.0 ;
 if(! spheres__dynamic )goto __result__buffer_error ;
 spheres__dynamic____buffer_alignment = 40 ;
 spheres__dynamic____buffer_size = ((u64*) spheres__dynamic )[1] ;
 spheres__dynamic____buffer_capacity = ((u64*) spheres__dynamic )[2] & ~(1ULL << 63) ;
 if( spheres__dynamic____buffer_size >= spheres__dynamic____buffer_capacity ){ if( ((u64*) spheres__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 spheres__dynamic____buffer_prev_capacity = spheres__dynamic____buffer_capacity ;
 spheres__dynamic____buffer_capacity = spheres__dynamic____buffer_capacity +( spheres__dynamic____buffer_capacity >>2)+1; if( spheres__dynamic____buffer_size ) ((void**) spheres__dynamic )[0] = __runtime_realloc((u64*)((void**) spheres__dynamic )[0],  spheres__dynamic____buffer_capacity * spheres__dynamic____buffer_alignment , spheres__dynamic____buffer_prev_capacity * spheres__dynamic____buffer_alignment ) ;
 else ((void**) spheres__dynamic )[0] = __runtime_alloc( spheres__dynamic____buffer_capacity * spheres__dynamic____buffer_alignment ) ;
 ((u64*) spheres__dynamic )[2] = spheres__dynamic____buffer_capacity ;
 spheres__dynamic____buffer_contents = (ptr)((void**) spheres__dynamic )[0] ;
 if(! spheres__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  spheres__dynamic____buffer_contents = (ptr)(((u64*) spheres__dynamic )[0]) ;
 ((u64*) spheres__dynamic )[1] = spheres__dynamic____buffer_size +1 ;
 memcpy( &((char*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment + 0 ] , & __0vqC , 8 ) ;
 memcpy( &((char*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment + 8 ] , & __0wqC , 8 ) ;
 memcpy( &((char*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment + 16 ] , & __0xqC , 8 ) ;
 memcpy( &((char*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment + 24 ] , & __0yqC , 8 ) ;
 memcpy( &((char*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment + 32 ] , & __0zqC , 8 ) ;
 __04qC = 100.0 ;
 __05qC = 100.0 ;
 __06qC = 30.0 ;
 __07qC = 450.0 ;
 __06nC = 600.0 ;
 if(! spheres__dynamic )goto __result__buffer_error ;
 spheres__dynamic____buffer_alignment = 40 ;
 spheres__dynamic____buffer_size = ((u64*) spheres__dynamic )[1] ;
 spheres__dynamic____buffer_capacity = ((u64*) spheres__dynamic )[2] & ~(1ULL << 63) ;
 if( spheres__dynamic____buffer_size >= spheres__dynamic____buffer_capacity ){ if( ((u64*) spheres__dynamic )[2] & (1ULL << 63) )goto __result__buffer_error ;
 spheres__dynamic____buffer_prev_capacity = spheres__dynamic____buffer_capacity ;
 spheres__dynamic____buffer_capacity = spheres__dynamic____buffer_capacity +( spheres__dynamic____buffer_capacity >>2)+1; if( spheres__dynamic____buffer_size ) ((void**) spheres__dynamic )[0] = __runtime_realloc((u64*)((void**) spheres__dynamic )[0],  spheres__dynamic____buffer_capacity * spheres__dynamic____buffer_alignment , spheres__dynamic____buffer_prev_capacity * spheres__dynamic____buffer_alignment ) ;
 else ((void**) spheres__dynamic )[0] = __runtime_alloc( spheres__dynamic____buffer_capacity * spheres__dynamic____buffer_alignment ) ;
 ((u64*) spheres__dynamic )[2] = spheres__dynamic____buffer_capacity ;
 spheres__dynamic____buffer_contents = (ptr)((void**) spheres__dynamic )[0] ;
 if(! spheres__dynamic____buffer_contents )goto __result__buffer_error ;
 } else  spheres__dynamic____buffer_contents = (ptr)(((u64*) spheres__dynamic )[0]) ;
 ((u64*) spheres__dynamic )[1] = spheres__dynamic____buffer_size +1 ;
 memcpy( &((char*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment + 0 ] , & __04qC , 8 ) ;
 memcpy( &((char*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment + 8 ] , & __05qC , 8 ) ;
 memcpy( &((char*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment + 16 ] , & __06qC , 8 ) ;
 memcpy( &((char*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment + 24 ] , & __07qC , 8 ) ;
 memcpy( &((char*) spheres__dynamic____buffer_contents )[ spheres__dynamic____buffer_size * spheres__dynamic____buffer_alignment + 32 ] , & __06nC , 8 ) ;
 __08qC = 0.0 ;
 dt = __08qC ;
 __0ImC = 800.0 ;
 __09qC = 450.0 ;
 __0BrC = "Hello from smoλ+raylib" ;
 SetTraceLogLevel ( LOG_WARNING ); InitWindow ( __0ImC , __09qC ,( char *) __0BrC ); 
 __0CrC = __0DrC ;
 window__size__w = __0ImC ;
 window__size__h = __09qC ;
 window__title = __0BrC ;
 window__ready = __0CrC ;
 __0FrC = __smo_time_eta (); 
 __0HrC :
 prev_t = __0FrC ;
 __0IrC = 60.0 ;
 accum_fps = __0IrC ;
 __0JrC = 128 ;
 __0KrC = __0JrC ;
 __0LrC = 0 ;
 __0MrC =( __0KrC == __0LrC ); 
 __0NrC :
 if(! __0MrC )goto __0OrC ;
 __0PrC = "Cannot allocate zero size" ;
 [[unlikely]] goto __0QrC ;
 __builtin_unreachable();
 __0OrC :
 __0JRC__mem = __runtime_alloc ( __0KrC ); 
 __0RrC = __0JRC__mem ;
 __0SrC =(! __0RrC ); 
 __0TrC :
 if(! __0SrC )goto __04lC ;
 __0UrC = "Failed a Heap allocation" ;
 [[unlikely]] goto __0UqC ;
 __builtin_unreachable();
 __04lC :
 __0VrC = __0JRC__mem ;
 __0WrC = __0KrC ;
 __0RqC = __0JRC__mem ;
 __0XrC = __0VrC ;
 __0YrC = 0 ;
 __0ZrC = __0YrC ;
 __0TpC :
 __0arC = WindowShouldClose (); 
 __0RmC = __0arC ;
 __0loC =(! __0RmC ); 
 __0emC :
 window____0V9B = __0hpC ;
 if(! __0loC )goto __0cmC ;
 __0brC = accum_fps ;
 __0crC = __0WrC ;
 __0drC = __0RqC ;
 __0erC = __0XrC ;
 __0frC = __0ZrC ;
 __0grC = 21 ;
 __0cpC = __0grC ;
 __03qC = __0cpC > __0crC ; 
 __0irC :
 if(! __03qC )goto __0jrC ;
 __0krC = "Failed an Circular allocation" ;
 [[unlikely]] goto __05oC ;
 __builtin_unreachable();
 __0jrC :
 if ( __0frC + __0cpC > __0crC ) { __0frC =0; } 
 __0QpC =( ptr )(( char *) __0drC + __0frC * sizeof ( char )); 
 __0frC = __0frC + __0cpC ; 
 __0RoC = __0cpC ;
 __0cpC = __0RoC ;
 if ( __0QpC ) { __0lrC =( u64 ) snprintf (( char *) __0QpC , sizeof ( char )* 21 , "%lu" , __0brC ); if ( __0lrC < 32 ) { __0mrC = malloc ( __0lrC +1); if ( __0mrC ) { memcpy ( __0mrC ,( char *) __0QpC , __0lrC );(( char *) __0mrC )[ __0lrC ]=0; __0nrC =(( char *) __0mrC )[0]; } } } 
 __0orC = __0mrC ;
 __0prC =( __0orC ); 
 __0qrC :
 __0rrC =(! __0prC ); 
 __0srC :
 if(! __0rrC )goto __0ApC ;
 [[unlikely]] goto __0trC ;
 __builtin_unreachable();
 __0ApC :
 if ( __0erC && __0mrC )((( char *) __0mrC )[ __0lrC ])=0; 
 __0urC :
 __0vrC = __0wrC ;
 __0xrC = __0yrC ;
 __0WrC = __0crC ;
 __0RqC = __0drC ;
 __0XrC = __0erC ;
 __0ZrC = __0frC ;
 __0zrC = " fps" ;
 __00rC = strlen ( __0zrC ); __01rC =( ptr ) __0zrC ; __02rC = __0zrC [0]; __03rC =0; 
 __04rC = __01rC ;
 __05rC = __0lrC ; __06rC = __00rC ; __07rC = __05rC + __06rC ; __08rC = __0lrC ? __0nrC : __02rC ; 
 __09rC = 1 ;
 __0AsC = __07rC + __09rC ; 
 __0BsC :
 __0CsC = __0AsC ;
 __0DsC = __0CsC > __0WrC ; 
 __0EsC :
 if(! __0DsC )goto __0FsC ;
 __0GsC = "Failed an Circular allocation" ;
 [[unlikely]] goto __0HsC ;
 __builtin_unreachable();
 __0FsC :
 if ( __0ZrC + __0CsC > __0WrC ) { __0ZrC =0; } 
 __0IsC =( ptr )(( char *) __0RqC + __0ZrC * sizeof ( char )); 
 __0ZrC = __0ZrC + __0CsC ; 
 __0JsC = __0CsC ;
 __0CsC = __0JsC ;
 __0KsC =(( char *) __0erC >=(( char *) __0IsC )&&( char *) __0erC <=(( char *) __0IsC )+ __05rC )||((( char *) __03rC )+ __05rC >=(( char *) __0IsC )&&( char *) __03rC <=(( char *) __0IsC )+ __07rC ); 
 if(! __0KsC )goto __0LsC ;
 [[unlikely]] goto __0MsC ;
 __builtin_unreachable();
 __0LsC :
 memcpy (( char *) __0IsC ,( char *) __0mrC , __05rC ); memcpy (( char *) __0IsC + __05rC ,( char *) __04rC , __06rC );(( char *) __0IsC )[ __07rC ]=0; 
 __0NsC = __0IsC ;
 if ( __0XrC && __0NsC )((( char *) __0NsC )[ __07rC ])=0; 
 __0OsC :
 __0vrC = __0PsC ;
 __0xrC = __0QsC ;
 __0WrC = __0WrC ;
 __0RqC = __0RqC ;
 __0XrC = __0XrC ;
 __0ZrC = __0ZrC ;
 __0RsC = window__size__w ;
 __0SsC = window__size__h ;
 __00qC = window__title ;
 __0TsC = window__ready ;
 if(! __0TsC )goto __06pC ;
 __0UsC = "Window.begin() already called without closing it with Window.end()" ;
 [[unlikely]] goto __0VsC ;
 __builtin_unreachable();
 __06pC :
 __0WsC = true ;
 BeginDrawing (); 
 __0XsC :
 __0YsC = __0asC ;
 __0csC = 50 ;
 __0dsC = 50 ;
 __0esC = 80 ;
 __0fsC = 255 ;
 __0gsC = 255 ;
 __0hsC = __0csC > __0gsC ; 
 __0PmC :
 if(! __0hsC )goto __0jsC ;
 __0lsC = "Color r greater than 255" ;
 [[unlikely]] goto __0msC ;
 __builtin_unreachable();
 __0jsC :
 __0nsC = 255 ;
 __0osC = __0dsC > __0nsC ; 
 __0qsC :
 if(! __0osC )goto __0rsC ;
 __0ssC = "Color g greater than 255" ;
 [[unlikely]] goto __0tsC ;
 __builtin_unreachable();
 __0rsC :
 __0EoC = 255 ;
 __0olC = __0esC > __0EoC ; 
 __0rnC :
 if(! __0olC )goto __0usC ;
 __0vsC = "Color b greater than 255" ;
 [[unlikely]] goto __0wsC ;
 __builtin_unreachable();
 __0usC :
 __0wnC = 255 ;
 __0xsC = __0fsC > __0wnC ; 
 __0ysC :
 if(! __0xsC )goto __00sC ;
 __01sC = "Color a greater than 255" ;
 [[unlikely]] goto __00lC ;
 __builtin_unreachable();
 __00sC :
 ClearBackground (( Color ) {( unsigned char ) __0csC ,( unsigned char ) __0dsC ,( unsigned char ) __0esC ,( unsigned char ) __0fsC }); 
 __06lC = __0RsC ;
 __0YsC = __0ulC ;
 __0voC = spheres__dynamic ? ((u64*) spheres__dynamic )[1]:0 ;
 __0wlC = 0 ;
 __0mlC = 1 ;
 __0TmC = __0wlC ;
 __03sC :
 __0slC = __0TmC ;
 __0qlC = __05sC ;
 __0qlC = __0slC ;
 __06sC = 1 ;
 __07sC = __0slC + __06sC ; 
 __08sC :
 __0slC = __07sC ;
 __09sC = __0slC <= __0voC ; 
 __0AtC :
 __0TmC = __0slC ;
 if(! __09sC )goto __0BtC ;
 if(! spheres__dynamic )goto __result__buffer_error ;
 __0CtC = 40 ;
 __0FmC = ((u64*) spheres__dynamic )[1] ;
 if( __0qlC >= __0FmC )goto __result__buffer_error ;
 memcpy(& __01pC , &((char*)((void**) spheres__dynamic )[0])[ __0qlC * __0CtC +0], sizeof( f64 )) ;
 memcpy(& __05pC , &((char*)((void**) spheres__dynamic )[0])[ __0qlC * __0CtC +8], sizeof( f64 )) ;
 memcpy(& __0DtC , &((char*)((void**) spheres__dynamic )[0])[ __0qlC * __0CtC +16], sizeof( f64 )) ;
 memcpy(& __0EtC , &((char*)((void**) spheres__dynamic )[0])[ __0qlC * __0CtC +24], sizeof( f64 )) ;
 memcpy(& __0FtC , &((char*)((void**) spheres__dynamic )[0])[ __0qlC * __0CtC +32], sizeof( f64 )) ;
 __0GtC = 200 ;
 __0HtC = 50 ;
 __0ItC = 50 ;
 __0KpC = 255 ;
 __0JtC = 255 ;
 __0kmC = __0GtC > __0JtC ; 
 __0KtC :
 if(! __0kmC )goto __0LtC ;
 __0MtC = "Color r greater than 255" ;
 [[unlikely]] goto __0NtC ;
 __builtin_unreachable();
 __0LtC :
 __0OtC = 255 ;
 __0PtC = __0HtC > __0OtC ; 
 __0QtC :
 if(! __0PtC )goto __0RtC ;
 __0StC = "Color g greater than 255" ;
 [[unlikely]] goto __0TtC ;
 __builtin_unreachable();
 __0RtC :
 __02qC = 255 ;
 __0UtC = __0ItC > __02qC ; 
 __0VtC :
 if(! __0UtC )goto __0WtC ;
 __0XtC = "Color b greater than 255" ;
 [[unlikely]] goto __0YtC ;
 __builtin_unreachable();
 __0WtC :
 __0ZtC = 255 ;
 __0atC = __0KpC > __0ZtC ; 
 __0btC :
 if(! __0atC )goto __0ctC ;
 __0KqC = "Color a greater than 255" ;
 [[unlikely]] goto __0dtC ;
 __builtin_unreachable();
 __0ctC :
 DrawCircleV (( Vector2 ) {( float ) __01pC ,( float ) __05pC },( float ) __0DtC ,( Color ) {( unsigned char ) __0GtC ,( unsigned char ) __0HtC ,( unsigned char ) __0ItC ,( unsigned char ) __0KpC }); 
 __0XmC = __0RsC ;
 __0YsC = __0etC ;
 goto __03sC ;
 __0BtC :
 __0ftC = 10.0 ;
 __0gtC = 10.0 ;
 __0htC = 20.0 ;
 __0itC = 255 ;
 __0jtC = 255 ;
 __0ktC = 255 ;
 __0ltC = 255 ;
 __0tqC = 255 ;
 __0mtC = __0itC > __0tqC ; 
 __0pmC :
 if(! __0mtC )goto __0BoC ;
 __0ntC = "Color r greater than 255" ;
 [[unlikely]] goto __0otC ;
 __builtin_unreachable();
 __0BoC :
 __0ptC = 255 ;
 __0qtC = __0jtC > __0ptC ; 
 __0rtC :
 if(! __0qtC )goto __0stC ;
 __0ttC = "Color g greater than 255" ;
 [[unlikely]] goto __0utC ;
 __builtin_unreachable();
 __0stC :
 __0wtC = 255 ;
 __0xtC = __0ktC > __0wtC ; 
 __0ytC :
 if(! __0xtC )goto __0rmC ;
 __0sqC = "Color b greater than 255" ;
 [[unlikely]] goto __00tC ;
 __builtin_unreachable();
 __0rmC :
 __0hmC = 255 ;
 __01tC = __0ltC > __0hmC ; 
 __00mC :
 if(! __01tC )goto __0hrC ;
 __0ymC = "Color a greater than 255" ;
 [[unlikely]] goto __02tC ;
 __builtin_unreachable();
 __0hrC :
 if ( __0XrC && __0NsC )((( char *) __0NsC )[ __07rC ])=0; 
 __0mmC :
 DrawText (( char *) __0NsC , __0ftC , __0gtC , __0htC ,( Color ) {( unsigned char ) __0itC ,( unsigned char ) __0jtC ,( unsigned char ) __0ktC ,( unsigned char ) __0ltC }); 
 __03mC = __0RsC ;
 __0YsC = __0ArC ;
 window____0V9B = __0YsC ;
 window__size__w = __0RsC ;
 window__size__h = __0SsC ;
 window__title = __00qC ;
 window__ready = __0TsC ;
 EndDrawing (); 
 __0ztC = __smo_time_eta (); 
 __03tC :
 __01qC = __0ztC - prev_t ; 
 __0CmC :
 dt = __01qC ;
 prev_t = __0ztC ;
 __04tC = 0.99 ;
 __0GrC = accum_fps * __04tC ; 
 __01nC :
 __04sC = 0.01 ;
 __0tmC = __04sC / dt ; 
 __0ZoC :
 __02sC = __0GrC + __0tmC ; 
 __0vtC :
 accum_fps = __02sC ;
 __0MmC = spheres__dynamic ? ((u64*) spheres__dynamic )[1]:0 ;
 __05tC = 0 ;
 __06tC = 1 ;
 __07tC = __05tC ;
 __08tC :
 __09tC = __07tC ;
 __0AuC = __0isC ;
 __0AuC = __09tC ;
 __0psC = 1 ;
 __0ZsC = __09tC + __0psC ; 
 __0ksC :
 __09tC = __0ZsC ;
 __0zsC = __09tC <= __0MmC ; 
 __0bsC :
 __07tC = __09tC ;
 if(! __0zsC )goto __0jlC ;
 if(! spheres__dynamic )goto __result__buffer_error ;
 __0ilC = 40 ;
 __0hlC = ((u64*) spheres__dynamic )[1] ;
 if( __0AuC >= __0hlC )goto __result__buffer_error ;
 memcpy(& __0glC , &((char*)((void**) spheres__dynamic )[0])[ __0AuC * __0ilC +0], sizeof( f64 )) ;
 __0flC = __0glC ;
 memcpy(& __0elC , &((char*)((void**) spheres__dynamic )[0])[ __0AuC * __0ilC +8], sizeof( f64 )) ;
 __0xpC = __0elC ;
 memcpy(& __0dlC , &((char*)((void**) spheres__dynamic )[0])[ __0AuC * __0ilC +16], sizeof( f64 )) ;
 __0clC = __0dlC ;
 memcpy(& __0blC , &((char*)((void**) spheres__dynamic )[0])[ __0AuC * __0ilC +24], sizeof( f64 )) ;
 __0alC = __0blC ;
 memcpy(& __0ZlC , &((char*)((void**) spheres__dynamic )[0])[ __0AuC * __0ilC +32], sizeof( f64 )) ;
 __0YlC = __0ZlC ;
 __0XlC = __0flC ;
 __0WlC = __0xpC ;
 __0VlC = __0alC ;
 __0UlC = __0YlC ;
 __0TlC = __0VlC * dt ; 
 __0SlC :
 __0RlC = __0XlC + __0TlC ; 
 __0QlC :
 __0PlC = __0RlC ;
 __0OlC = __0UlC * dt ; 
 __0NlC :
 __0MlC = __0WlC + __0OlC ; 
 __0LlC :
 __0KlC = __0MlC ;
 __0JlC = __0VlC ;
 __0IlC = __0UlC ;
 __0HlC = __0PlC - __0clC ; 
 __0GlC :
 __0FlC = 0.0 ;
 __0ElC = __0HlC < __0FlC ; 
 __0DlC :
 if(! __0ElC )goto __0ClC ;
 __0PlC = __0clC ;
 __0BlC = 0.0 ;
 __0AlC = __0BlC - __0JlC ; 
 __09kC :
 __0JlC = __0AlC ;
 goto __08kC ;
 __0ClC :
 __07kC = __0PlC + __0clC ; 
 __06kC :
 __05kC = 800.0 ;
 __04kC = __07kC > __05kC ; 
 __03kC :
 if(! __04kC )goto __02kC ;
 __01kC = 800.0 ;
 __00kC = __01kC - __0clC ; 
 __0zkC :
 __0PlC = __00kC ;
 __0ykC = 0.0 ;
 __0xkC = __0ykC - __0JlC ; 
 __0wkC :
 __0JlC = __0xkC ;
 __02kC :
 __08kC :
 __0vkC = __0KlC - __0clC ; 
 __0ukC :
 __0tkC = 0.0 ;
 __0skC = __0vkC < __0tkC ; 
 __0rkC :
 if(! __0skC )goto __0qkC ;
 __0KlC = __0clC ;
 __0pkC = 0.0 ;
 __0okC = __0pkC - __0IlC ; 
 __0nkC :
 __0IlC = __0okC ;
 goto __0mkC ;
 __0qkC :
 __0lkC = __0KlC + __0clC ; 
 __0kkC :
 __0jkC = 450.0 ;
 __0ikC = __0lkC > __0jkC ; 
 __0hkC :
 if(! __0ikC )goto __0gkC ;
 __0fkC = 450.0 ;
 __0ekC = __0fkC - __0clC ; 
 __0dkC :
 __0KlC = __0ekC ;
 __0ckC = 0.0 ;
 __0bkC = __0ckC - __0IlC ; 
 __0akC :
 __0IlC = __0bkC ;
 __0gkC :
 __0mkC :
 __0XlC = __0PlC ;
 __0WlC = __0KlC ;
 __0VlC = __0JlC ;
 __0UlC = __0IlC ;
 __0flC = __0XlC ;
 __0xpC = __0WlC ;
 __0alC = __0VlC ;
 __0YlC = __0UlC ;
 memcpy( &((char*) spheres__dynamic____buffer_contents )[ __0AuC * __0ilC + 0 ] , & __0XlC , 8 ) ;
 memcpy( &((char*) spheres__dynamic____buffer_contents )[ __0AuC * __0ilC + 8 ] , & __0WlC , 8 ) ;
 memcpy( &((char*) spheres__dynamic____buffer_contents )[ __0AuC * __0ilC + 16 ] , & __0clC , 8 ) ;
 memcpy( &((char*) spheres__dynamic____buffer_contents )[ __0AuC * __0ilC + 24 ] , & __0VlC , 8 ) ;
 memcpy( &((char*) spheres__dynamic____buffer_contents )[ __0AuC * __0ilC + 32 ] , & __0UlC , 8 ) ;
 goto __08tC ;
 __0jlC :
 __0ZkC = 0.015 ;
 __0YkC = __0ztC - prev_t ; 
 __0XkC :
 __0WkC = __0ZkC - __0YkC ; 
 __0VkC :
 __0UkC = 0.0 ;
 __0TkC = __0WkC <= __0UkC ; 
 __0SkC :
 if(! __0TkC )goto __0RkC ;
 goto __0XqC ;
 __0RkC :
 __smo_exact_sleep ( __0WkC ); 
 __0XqC :
 goto __0TpC ;
 __0cmC :
 __0QkC :
goto __return;

// ERROR HANDLING
__0TtC :
 printf ( "%s\n" , __0StC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0HsC :
 printf ( "%s\n" , __0GsC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0trC :
 printf ( "Failed to allocate str from number\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0utC :
 printf ( "%s\n" , __0ttC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0YtC :
 printf ( "%s\n" , __0XtC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__02tC :
 printf ( "%s\n" , __0ymC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0NtC :
 printf ( "%s\n" , __0MtC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__00lC :
 printf ( "%s\n" , __01sC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__05oC :
 printf ( "%s\n" , __0krC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__result__buffer_error :
printf("Buffer error\n");
__result__error_code=__BUFFER__ERROR;
goto __failsafe;
__0UqC :
 printf ( "%s\n" , __0UrC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0otC :
 printf ( "%s\n" , __0ntC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__00tC :
 printf ( "%s\n" , __0sqC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0wsC :
 printf ( "%s\n" , __0vsC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0tsC :
 printf ( "%s\n" , __0ssC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0QrC :
 printf ( "%s\n" , __0PrC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0msC :
 printf ( "%s\n" , __0lsC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0dtC :
 printf ( "%s\n" , __0KqC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0MsC :
 printf ( "String concatenation would corrupt one of the operands due to writing on its memory region - consider larger or non-overlapping circular buffers or arenas.\n" ); 
__result__error_code=__USER__ERROR;
goto __failsafe;
__0VsC :
 printf ( "%s\n" , __0UsC ); 
__result__error_code=__USER__ERROR;
goto __failsafe;

// DEALLOCATE RESOURCES BY ERRORS
__failsafe:

// HOTPATH SKIPS TO HERE
__return:
if ( __0JRC__mem ) __runtime_free ( __0JRC__mem ); __0JRC__mem =0; 
if( __0uQC__dynamic ){if((u64*)((u64*) __0uQC__dynamic )[2]) __runtime_free((u64*)((u64*) __0uQC__dynamic )[0]) ;
 __runtime_free( __0uQC__dynamic ) ;
 __0uQC__dynamic = 0 ;
 }__state->err =  __result__error_code;
}



int main() {
struct main__497__state __main_args={0};
__smolambda_initialize_service_tasks(main__497, &__main_args);
return __main_args.err;
}

