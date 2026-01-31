#include<stdio.h>
int main(){
int __error_code = 0;
double __cnst4=2.0;
double __cnst3=1.0;
double __tmp16__message=0;
double __tmp15__x=0;
double __tmp15__y=0;
double __tmp15__z=0;
double p1__y=0;
double p1__x=0;
double __tmp12__x=0;
double __tmp12__y=0;
double f__b__x=0;
double f__a__x=0;
double __tmp13__x=0;
double f__b__y=0;
double __tmp13__y=0;
double p2__x=0;
double p2__y=0;
double __tmp14__b__y=0;
double __tmp14__b__x=0;
double __tmp14__a__y=0;
double __tmp14__a__x=0;
double f__a__y=0;
__tmp12__x=__cnst3;
__tmp12__y=__cnst4;
goto __tmp12____return;
__tmp12____return:
p1__x=__tmp12__x;
p1__y=__tmp12__y;
__tmp13__x=__cnst3;
__tmp13__y=__cnst4;
goto __tmp13____return;
__tmp13____return:
p2__x=__tmp13__x;
p2__y=__tmp13__y;
__tmp14__a__x=p1__x;
__tmp14__a__y=p1__y;
__tmp14__b__x=p2__x;
__tmp14__b__y=p2__y;
goto __tmp14____return;
__tmp14____return:
f__a__x=__tmp14__a__x;
f__a__y=__tmp14__a__y;
f__b__x=__tmp14__b__x;
f__b__y=__tmp14__b__y;
__tmp15__x=f__a__x;
__tmp15__y=f__a__y;
__tmp15__z=__tmp15__x+__tmp15__y;
goto __tmp15____return;
__tmp15____return:
__tmp16__message=__tmp15__z;
printf("%.6f\n",__tmp16__message);
__failsafe:
__return:
return __error_code;
}