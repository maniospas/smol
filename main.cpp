#include <cstring>
#define ptr void*
#define u64 unsigned long
#define i64 long
#define f64 double

#include<cstdlib>
#include <stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include <stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
int main() {
i64 __v5 = 1;
i64 __v6 = 2;
i64 __v7 = 3;
i64 __v8 = 4;
u64 buf__size;
u64 buf__offset;
ptr buf__contents;
i64 __buf__0;
i64 __buf__1;
i64 __buf__2;
i64 __buf__3;
i64 f__start__x;
i64 f__start__y;
i64 f__end__x;
i64 f__end__y;
i64 __v10__x;
bool __v10____v1 = true;
i64 __v11;
i64 __v12__x;
bool __v12____v1 = true;
i64 f2__start__x;
i64 f2__start__y;
i64 f2__end__x;
i64 f2__end__y;
i64 __v14__x;
bool __v14____v1 = true;
i64 res__x;
i64 res__y;
i64 res__zero;
i64 res__comp__x;
i64 res__comp__y;
bool res__comp__z;
bool res____v2__condition;
bool res____v2____v4 = true;
i64 res__z;
i64 __v15__x;
bool __v15____v1 = true;
buf__size = 4;
buf__offset = 0;
buf__contents = malloc(sizeof(i64)*buf__size);
std::memcpy((unsigned char*)buf__contents + sizeof(i64) * 0, &__v5, sizeof(i64));
std::memcpy((unsigned char*)buf__contents + sizeof(i64) * 1, &__v6, sizeof(i64));
std::memcpy((unsigned char*)buf__contents + sizeof(i64) * 2, &__v7, sizeof(i64));
std::memcpy((unsigned char*)buf__contents + sizeof(i64) * 3, &__v8, sizeof(i64));
if(buf__size-buf__offset<4) goto __v9;
std::memcpy(&__buf__0, (unsigned char*)buf__contents+sizeof(u64)*(0+buf__offset), sizeof(__buf__0));
std::memcpy(&__buf__1, (unsigned char*)buf__contents+sizeof(u64)*(1+buf__offset), sizeof(__buf__1));
std::memcpy(&__buf__2, (unsigned char*)buf__contents+sizeof(u64)*(2+buf__offset), sizeof(__buf__2));
std::memcpy(&__buf__3, (unsigned char*)buf__contents+sizeof(u64)*(3+buf__offset), sizeof(__buf__3));
buf__offset += 4;
f__start__x = __buf__0;
f__start__y = __buf__1;
f__end__x = __buf__2;
f__end__y = __buf__3;
f____end:
__v10__x = f__start__x;
printf("%ld\n",__v10__x);
__v10____end:
__v11 = 0;
f__start__x = __v11;
__v12__x = f__start__x;
printf("%ld\n",__v12__x);
__v12____end:
if(buf__size-buf__offset<4) goto __v13;
std::memcpy(&__buf__0, (unsigned char*)buf__contents+sizeof(u64)*(0+buf__offset), sizeof(__buf__0));
std::memcpy(&__buf__1, (unsigned char*)buf__contents+sizeof(u64)*(1+buf__offset), sizeof(__buf__1));
std::memcpy(&__buf__2, (unsigned char*)buf__contents+sizeof(u64)*(2+buf__offset), sizeof(__buf__2));
std::memcpy(&__buf__3, (unsigned char*)buf__contents+sizeof(u64)*(3+buf__offset), sizeof(__buf__3));
buf__offset += 4;
f2__start__x = __buf__0;
f2__start__y = __buf__1;
f2__end__x = __buf__2;
f2__end__y = __buf__3;
f2____end:
__v14__x = f2__start__x;
printf("%ld\n",__v14__x);
__v14____end:
res__x = 1;
res__y = 0;
res____start:
res__zero = 0;
res__comp__x = res__y;
res__comp__y = res__zero;
res__comp__z=(res__comp__x==res__comp__y);
res__comp____end:
res____v2__condition = res__comp__z;
if(!res____v2__condition)goto res____finally;
res____v2____end:
goto __v3;
res____finally:
res__z=res__x/res__y;
res____end:
__v15__x = res__z;
printf("%ld\n",__v15__x);
__v15____end:
__end:
goto __return;
buf__size = 0;
free(buf__contents);
__error:
__v9:
printf("Runtime error: `buf` does not have enough remaining elements\n");
goto __return;
__v13:
printf("Runtime error: `buf` does not have enough remaining elements\n");
goto __return;
__v3:
printf("Division by zero\n");
goto __return;
__return:
buf__size = 0;
free(buf__contents);
return 0;
}
