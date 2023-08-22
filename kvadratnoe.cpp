#include <stdio.h>
#include <TXLib.h>
#include <locale.h>
#include <math.h>

double sqr_solution(double a, double b, double c);
int message(int flag);
double lin_solution(double b, double c);

int main(void)
{
 setlocale(LC_ALL, "Russian");

 double a = 0.0, b = 0.0, c = 0.0;

 printf("квадратное уравнение в общем виде: a*x^2+b*x+c=0\n");
 printf("введите коэффициенты a,b,c:\n");

 int n = 0;
 n=scanf("%lf %lf %lf", &a, &b, &c);

 {
 if(n == 3)
  {
  if(a != 0)
   {
   sqr_solution(a, b, c);
   }
  else
   {
   if(fabs(0.0 - b) < 0.000001 && fabs(0.0 - c) < 0.000001)
    {
    printf("уравнение имеет бесконечное колличество решений\n");
    }
   else
    {
    lin_solution(b, c);
    }
   }
  }
 else
  {
  getchar();
  printf("данные введены некорректно\n");
  }
 }

return 0;
}

double sqr_solution(double a, double b, double c)
{
 double D = 0.0;
 double sqr_root_D = 0.0;
 double x_1 = 0.0, x_2 = 0.0;

 D = b * b - 4.0 * a * c ;

 if ( D <= 0)
   printf("корней нет\n");

 if (fabs(0.0 - D) < 0.000001)
   {
   sqr_root_D = sqrt( D );
   x_1 = ( - b - sqr_root_D )/(2.0 * a);

   printf("уравнение имеет 1 корень : x = %lf\n",x_1);
   }
 if (D >= 0)
   {
   sqr_root_D = sqrt( D );
   x_1 = ( - b - sqr_root_D )/(2 * a);
   x_2 = ( - b + sqr_root_D )/(2 * a);

   printf("уравнение имеет 2 корня : x_1 = %lf\nx_2 = %lf\n",x_1, x_2);
   }
 return x_1;
}

/*int message(int flag)
{
 printf("желаете продолжить?\n");

 printf("введите <y>, чтобы обновить коэффициенты\n"
        "введите <n>, чтобы завершить выполнение программы\n");

 char ch = 'a';
 ch = getchar();

 for(;ch != 'y' && ch !='n';)
   {
   printf("введите <y>, чтобы обновить коэффициенты\n"
          "введите <n>, чтобы завершить выполнение программы\n");
   ch=getchar();
   }

 if(ch == 'y')
   flag = 1;
 else if(ch == 'n')
   flag = 2;
 else
  {

  }
 return flag;
}      */

double lin_solution(double b, double c)
{
 double x_1 = 0.0 ;

 x_1 = - c / b;
 printf("уравнение cводится к линейному и имеет 1 корень : x = %lf\n", x_1);
 return x_1;
}


