#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>

int Compare_c_(double c);
int Compare_a(double a);
int Compare_b(double b);
int Compare_c(double c);
int Compare_Discriminant(double Discriminant);

double Input(double* a, double* b, double* c, int* n_scanf);

int Clear_Buffer();
int Would_User_Continue(int* Iteration_Variable);

double Square_Equation_Solution(double a, double b, double c,
                                double* x_1, double* x_2, int* N_Roots);
double Linear_Equation_Solution(double b, double c,
                                double* x_1, int* N_Roots);

int Output_Square_Solution(double x_1, double x_2, int N_Roots);
int Output_Linear_Solution(double x_1, int N_Roots);

int main()
{
 printf("квадратное уравнение в общем виде: a*x^2+b*x+c=0\n");

 double a = NAN, b = NAN, c = NAN, x_1 = NAN, x_2 = NAN;    // TODO  NAN ++
 int Iteration_Variable = 0, N_Roots = 0;
                                    // TODO naming  ++
 for(; Iteration_Variable < 1; ++Iteration_Variable)
 {
    printf("введите коэффициенты a,b,c:\n");   // TODO format ++
    int n_scanf = 0;
// TODO input function ++
    Input( &a, &b, &c, &n_scanf);

    if(n_scanf == 3)
    {
        if(Compare_a(a))    // TODO compare function ++, why do you substract from zero? ++
        {
            Square_Equation_Solution(a, b, c, &x_1, &x_2, &N_Roots);
            Output_Square_Solution(x_1, x_2, N_Roots);

            Clear_Buffer();

            Would_User_Continue(&Iteration_Variable); // Naming ++
            Clear_Buffer();    // Naming ++
        }
        else
        {
            Linear_Equation_Solution( b, c, &x_1, &N_Roots);
            Output_Linear_Solution(x_1, N_Roots);

            Clear_Buffer();

            Would_User_Continue(&Iteration_Variable);
            Clear_Buffer();
        }
    }
    else
    {
        Clear_Buffer();
        printf("данные введены некорректно\n");

        Would_User_Continue(&Iteration_Variable);
        Clear_Buffer();
    }
 }
return 0;
}

double Square_Equation_Solution(double a, double b, double c,
                                double* x_1, double* x_2, int* N_Roots)   // TOOD do not use short names ++
{
    /*assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    assert(x_1 != NULL);
    assert(x_2 != NULL);
    assert(x_1 != x_2);*/

    double Discriminant = NAN;
    Discriminant = b * b - 4 * a * c;

    if(Compare_Discriminant(Discriminant))
    {
        *x_1 = - b / (2 * a);
        *N_Roots = 1;

        return *N_Roots;
    }
    else if(Discriminant > 0.0)
    {
        double Square_Root_Discriminant = NAN;

        Square_Root_Discriminant = sqrt(Discriminant);
        *x_1 = (- b + Square_Root_Discriminant) / (2 * a);
        *x_2 = (- b - Square_Root_Discriminant) / (2 * a);
        *N_Roots = 2;

        return *N_Roots;
    }
    else
    {   *x_1 = *x_2 = NAN;  //потом поменяю
        *N_Roots = 0;

        return *N_Roots;
    }
}



double Linear_Equation_Solution(double b, double c,
                                double* x_1, int* N_Roots)  // TODO do not use short names  ++
{
    if(Compare_b(b) && Compare_c(c))
    {
        *x_1 = 1;
        *N_Roots = 2;

        return *N_Roots;
    }
    else if(Compare_b(b) && Compare_c_(c))
    {
        *x_1 = -1;
        *N_Roots = 0;

        return *N_Roots;
    }
    else
    {
        *x_1 = - c / b;
        *N_Roots = 1;

        return *N_Roots;
    }
}


int Would_User_Continue(int* Iteration_Variable)
{
    printf("желаете продолжить ?\n"
           "(введите 'y',чтобы продолжить)\n");

    if(getchar() == 'y')
       *Iteration_Variable = -1; // TODO use enum
    else
       *Iteration_Variable = 0;

    Clear_Buffer();
    return *Iteration_Variable;
}


int Clear_Buffer()
{
    while(getchar() != '\n')
        getchar();
    return 0;
}


double Input(double* a, double* b, double* c, int* n_scanf)
{
    *n_scanf = scanf("%lf %lf %lf", &*a, &*b, &*c);
    return *n_scanf;
}


int Compare_a(double a)
{
    int Is_a_Zero = 1;

    if(fabs(a) > 0.000001)
        Is_a_Zero = 1;
    else
        Is_a_Zero = 0;

    return Is_a_Zero;
}


int Compare_b(double b)
{
    int Is_b_Zero = 1;

    if(fabs(b) < 0.000001)
        Is_b_Zero = 1;
    else
        Is_b_Zero = 0;

    return Is_b_Zero;
}


int Compare_c(double c)
{
    int Is_c_Zero = 1;

    if(fabs(c) < 0.000001)
        Is_c_Zero = 1;
    else
        Is_c_Zero = 0;

    return Is_c_Zero;
}


int Compare_c_(double c)
{
    int Is_c_Zero = 1;

    if(fabs(c) > 0.000001)
        Is_c_Zero = 1;
    else
        Is_c_Zero = 0;

    return Is_c_Zero;
}


int Compare_Discriminant(double Discriminant)
{
    int Is_D_Zero = 1;

    if(fabs(Discriminant) < 0.000001)
        Is_D_Zero = 1;
    else
        Is_D_Zero = 0;

    return Is_D_Zero;
}


int Output_Square_Solution(double x_1, double x_2, int N_Roots)
{
    switch(N_Roots)
    {
        case 0 : printf("действительных  корней уравнения нет\n");
                 break;
        case 1 : printf("уравнение имеет 1 корень : x_1 = %lf\n", x_1);
                 break;
        case 2 : printf("уравнение имеет 2 корня : x_1 = %lf, x_2 = %lf \n", x_1, x_2);
                 break;
                 default :
                    printf("что-то пошло не так...");
    }
    return 0;
}


int Output_Linear_Solution(double x_1, int N_Roots)
{
    switch(N_Roots)
    {
        case 0 : printf("корней нет \n");
                 break;
        case 1 : printf("уравнение сводится к линейному и имеет 1 корень : x_1 = %lf\n", x_1);
                 break;
        case 2 : printf("уравнение имеет бесконечное колличество корней \n");
                 break;
                 default :
                    printf("что-то пошло не так...");
    }
    return 0;
}
