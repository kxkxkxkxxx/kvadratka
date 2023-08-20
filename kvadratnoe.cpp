#include <stdio.h>
#include <TXLib.h>
#include <math.h>
int main(void)
{
  double a,b,c,D;
  double x_1,x_2;
  printf("квадратное уравнение в общем виде: a*x^2+b*x+c=0, а!=0;\n"
  "введите коэффициенты a,b,c:\n");
      if(scanf("%lf",&a)==1 && scanf("%lf",&b)==1 && scanf("%lf",&c)==1 && a!=0.0)
        {
          D=b*b-4.0*a*c;
          if(D<0)
             {
               printf("действительных корней уравнения нет(((\n");
             }
          else
             {
               x_1=(-b+sqrt(D))/(2*a);
               x_2=(-b-sqrt(D))/(2*a);
               if(x_1==x_2)
                 printf("уравнение %.3lf*x^2+%.3lf*x+%.3lf=0 имеет 1 корень: x_1=%.5lf\n",a,b,c,x_1);
               else
                 printf("уравнение %.3lf*x^2+%.3lf*x+%.3lf=0 имеет 2 корня:"
                 " x_1=%.5lf ; x_2=%.5lf\n",a,b,c,x_1,x_2);
             }
        }
      else
          printf("данные введены некорректно...\n");
  return 0;
}

