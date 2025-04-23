#define ptr void*
#define u64 unsigned long
#define i64 long
#define f64 double

#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
int main() {
i64 res__x;
i64 res__y;
i64 res__zero;
i64 res__comp__x;
i64 res__comp__y;
bool res__comp__z;
bool res____v1__condition;
i64 res__z;
i64 __v3__x;
res__x = 1;
res__y = 0;
res__zero = 0;
res__comp__x = res__y;
res__comp__y = res__zero;
res__comp__z=(res__comp__x==res__comp__y);
res__comp____end:
res____v1__condition = res__comp__z;
if(!res____v1__condition)goto res____finally;
res____v1____end:
goto __v2;
res____finally:
res__z=res__x/res__y;
res____end:
__v3__x = res__z;
printf("%ld\n",__v3__x);
__v3____end:
__end:
goto __return;
__error:
__v2:
printf("Division by zero\n");
goto __return;
__return:
return 0;
}
