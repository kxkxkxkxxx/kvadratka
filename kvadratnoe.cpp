#include <stdio.h>
#include <TXLib.h>
#include <math.h>
int main(void)
{
  double a,b,c,D;
  double x_1,x_2;
  printf("���������� ��������� � ����� ����: a*x^2+b*x+c=0, �!=0;\n"
  "������� ������������ a,b,c:\n");
      if(scanf("%lf",&a)==1 && scanf("%lf",&b)==1 && scanf("%lf",&c)==1 && a!=0.0)
        {
          D=b*b-4.0*a*c;
          if(D<0)
             {
               printf("�������������� ������ ��������� ���(((\n");
             }
          else
             {
               x_1=(-b+sqrt(D))/(2*a);
               x_2=(-b-sqrt(D))/(2*a);
               if(x_1==x_2)
                 printf("��������� %.3lf*x^2+%.3lf*x+%.3lf=0 ����� 1 ������: x_1=%.5lf\n",a,b,c,x_1);
               else
                 printf("��������� %.3lf*x^2+%.3lf*x+%.3lf=0 ����� 2 �����:"
                 " x_1=%.5lf ; x_2=%.5lf\n",a,b,c,x_1,x_2);
             }
        }
      else
          printf("������ ������� �����������...\n");
  return 0;
}

