#define ptr void*
#define u64 unsigned long
#define i64 long
#define f64 double

#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<cstdlib>
int main() {
i64 p1__x = 1;
i64 p1__y = 2;
i64 p2__x = 3;
i64 p2__y = 4;
i64 f__start__x = 1;
i64 f__start__y = p1__x;
i64 f__end__x = p1__y;
i64 f__end__y = 3;
i64 __temp1__x = f__start__x;
printf("%ld\n",__temp1__x);
i64 __temp2__x = f__end__y;
printf("%ld\n",__temp2__x);
i64 i__x = f__start__x;
i64 i__y = f__start__y;
i64 i__z=i__x+i__y;
i64 __temp3__x = i__z;
printf("%ld\n",__temp3__x);
u64 mem__size = 4;
ptr mem__contents = malloc(sizeof(i64)*mem__size);
((i64*)mem__contents)[0] = p1__x;
((i64*)mem__contents)[1] = p1__y;
((i64*)mem__contents)[2] = p2__x;
((i64*)mem__contents)[3] = p2__y;
return 0;
}
