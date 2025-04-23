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
i64 __v7 = 1;
i64 __v8 = 2;
i64 __v9 = 3;
i64 __v10 = 4;
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
i64 __v12__x;
bool __v12____v1 = true;
i64 __v14 = 0;
i64 __v13;
i64 __v15__x;
bool __v15____v1 = true;
i64 f2__start__x;
i64 f2__start__y;
i64 f2__end__x;
i64 f2__end__y;
i64 __v17__x;
bool __v17____v1 = true;
i64 __v18 = 1;
i64 __v19 = 0;
i64 res__x;
i64 res__y;
i64 res____v2 = 0;
i64 res__comp__x;
i64 res__comp__y;
bool res__comp__z;
bool res____v3__condition;
bool res____v3____v5 = true;
i64 res__z;
i64 __v20__x;
bool __v20____v1 = true;
buf__size = 4;
buf__offset = 0;
buf__contents = malloc(sizeof(i64)*buf__size);
std::memcpy((unsigned char*)buf__contents + sizeof(i64) * 0, &__v7, sizeof(i64));
std::memcpy((unsigned char*)buf__contents + sizeof(i64) * 1, &__v8, sizeof(i64));
std::memcpy((unsigned char*)buf__contents + sizeof(i64) * 2, &__v9, sizeof(i64));
std::memcpy((unsigned char*)buf__contents + sizeof(i64) * 3, &__v10, sizeof(i64));
if(buf__size-buf__offset<4) goto __v11;
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
__v12__x = f__start__x;
printf("%ld\n",__v12__x);
__v12____end:
__v13 = __v14;
f__start__x = __v13;
__v15__x = f__start__x;
printf("%ld\n",__v15__x);
__v15____end:
if(buf__size-buf__offset<4) goto __v16;
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
__v17__x = f2__start__x;
printf("%ld\n",__v17__x);
__v17____end:
res__x = __v18;
res__y = __v19;
res____start:
res__comp__x = res__y;
res__comp__y = res____v2;
res__comp__z=(res__comp__x==res__comp__y);
res__comp____end:
res____v3__condition = res__comp__z;
if(!res____v3__condition)goto res____finally;
res____v3____end:
goto __v4;
res____finally:
res__z=res__x/res__y;
res____end:
__v20__x = res__z;
printf("%ld\n",__v20__x);
__v20____end:
__end:
goto __return;
buf__size = 0;
free(buf__contents);
__error:
__v11:
printf("Runtime error: `buf` does not have enough remaining elements\n");
goto __return;
__v16:
printf("Runtime error: `buf` does not have enough remaining elements\n");
goto __return;
__v4:
printf("Division by zero\n");
goto __return;
__return:
buf__size = 0;
free(buf__contents);
return 0;
}
