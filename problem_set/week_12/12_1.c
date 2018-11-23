#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define accur_parameter 1.0e-10
double bisection(double (*f)(double),double x1,double x2){
   double mid;
   mid=(x1+x2)/2;
   while (f(mid)!=0){
      if (f(x1)*f(mid)<0){
         x2=mid;
      }
      else{
         x1=mid;
      }
      mid=(x1+x2)/2;
      if (x2-x1<accur_parameter){
         return mid;
      }
   }
   return mid;
   
}
double f_a(double x){
   return pow(x,3)-7*x-6;
}
double f_c(double x){
   return sin(5*x)+cos(10*x)+x*x/10;
}
void main(void){
   printf("root of fa(x): %.10f\n",bisection(f_a,0.0,10.0));
   printf("root of fb(x): %.10f\n",bisection(sin,2.0,4.0));
   printf("root of fc(x): %.10f\t%.10f\n",bisection(f_c,0.0,1.0),bisection(f_c,1.0,2.0));
}
