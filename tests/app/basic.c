#include<stdio.h>
int main(){
int __error_code = 0;
double __cnst2=0.0;
double __cnst3=1.0;
double __tmp12__message=0;
double __tmp11__x=0;
double __tmp11____cnst2=0;
double __tmp11__sign____cnst2=0;
double __tmp11____cnst3=0;
int __tmp11____tmp10__z=0;
double __tmp11____tmp10__x=0;
double __tmp11____tmp10__y=0;
__tmp11__x=__cnst3;
__tmp11____cnst3=__cnst3;
__tmp11____cnst2=__cnst2;
__tmp11__sign____cnst2=__tmp11____cnst2;
__tmp11____tmp10__x=__tmp11__x;
__tmp11____tmp10__y=__tmp11____cnst3;
__tmp11____tmp10__z=__tmp11____tmp10__x<=__tmp11____tmp10__y;
goto __tmp11____tmp10____return;
__tmp11____tmp10____return:
if(__tmp11____tmp10__z){
goto __tmp11____return;
}
__tmp11____cnst3=__tmp11__sign____cnst2;
goto __tmp11____return;
__tmp11____return:
__tmp12__message=__tmp11____cnst3;
printf("%.6f\n",__tmp12__message);
__failsafe:
__return:
return __error_code;
}