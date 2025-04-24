#include <cstring>
#define ptr void*
#define u64 unsigned long
#define i64 long
#define f64 double

#include<stdio.h>
#include<stdio.h>
#include<cstdlib>
#include <stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
int main() {
bool __v12 = false;
bool i;
bool __v13__message;
bool __v13____v3 = true;
i64 __v14 = 1;
i64 __v15 = 2;
i64 __v16 = 3;
i64 __v17 = 4;
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
i64 __v19__message;
bool __v19____v2 = true;
i64 __v21 = 0;
i64 __v20;
i64 __v22__message;
bool __v22____v2 = true;
i64 __v23 = 1;
i64 __v24 = 0;
i64 res__x;
i64 res__y;
i64 res____v4 = 0;
i64 res__comp__x;
i64 res__comp__y;
bool res__comp__z;
bool res____v5__condition;
bool res____v5____v7 = true;
i64 res__z;
i64 __v25__message;
bool __v25____v2 = true;
i = __v12;
__v13__message = i;
__v13__message?printf("true\n"):printf("false\n");
__v13____end:
buf__size = 4;
buf__offset = 0;
buf__contents = malloc(sizeof(i64)*buf__size);
std::memcpy((unsigned char*)buf__contents + sizeof(i64) * 0, &__v14, sizeof(i64));
std::memcpy((unsigned char*)buf__contents + sizeof(i64) * 1, &__v15, sizeof(i64));
std::memcpy((unsigned char*)buf__contents + sizeof(i64) * 2, &__v16, sizeof(i64));
std::memcpy((unsigned char*)buf__contents + sizeof(i64) * 3, &__v17, sizeof(i64));
if(buf__size-buf__offset<4) goto __v18;
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
__v19__message = f__start__x;
printf("%ld\n",__v19__message);
__v19____end:
__v20 = __v21;
f__start__x = __v20;
__v22__message = f__start__x;
printf("%ld\n",__v22__message);
__v22____end:
res__x = __v23;
res__y = __v24;
res____start:
res__comp__x = res__y;
res__comp__y = res____v4;
res__comp__z=(res__comp__x==res__comp__y);
res__comp____end:
res____v5__condition = res__comp__z;
if(!res____v5__condition)goto res____finally;
res____v5____end:
goto __v6;
res____finally:
res__z=res__x/res__y;
res____end:
__v25__message = res__z;
printf("%ld\n",__v25__message);
__v25____end:
__end:
goto __return;
buf__size = 0;
free(buf__contents);
__error:
__v18:
printf("Runtime error: `buf` does not have enough remaining elements\n");
goto __return;
__v6:
printf("Division by zero\n");
goto __return;
__return:
buf__size = 0;
free(buf__contents);
return 0;
}
