#include <stdio.h>
#include <math.h>

double test_num(void);                       //check is input are number, if number - return
void linnar_equation(double b, double c);
void square_equation(double a, double b, double c, double D);
void not_equation (double c);
void input_reset(void);
int  test_exit(void);
void input (double &a, double &b, double &c);                         //boolean function
void solver(double a, double b, double c);                             //choose right version of solution
void invite_to_input (void);

int main(void)
{
    double a = 0, b = 0, c = 0;

    while ( 1 )
    {
            invite_to_input();
            if (test_exit() )
                break;
            input(a, b, c);
            solver (a, b, c);
            input_reset();
    }

    return 0;
}

double test_num(void)
{
    char ch = 'A';
    double x = 0;

    while(scanf("%lf", &x) != 1)
    {
        while ( (ch = getchar() ) != '\n')
            putchar(ch);

        printf(" is not number, please input  number: ");
    }

    return x;
}

void not_equation(double c)
{
    printf("%s", (c == 0) ? "x belong R" : "x belong empty set");
}

void linnar_equation(double b, double c)
{
    double x = 0;
    x = (-c) / b;
    printf("This is not square equation, the root is %.3f\n", x);
}

void square_equation(double a, double b, double c)
{
    double x1 = 0, x2 = 0, D = 0;

    D = b * b - 4 * a * c;

    if (D > 0)
    {                                                               //if discriminate > 0
        D = pow(D, 0.5);
        x1 = (-b -D) / (2 * a);
        x2 = (-b + D)/(2 * a);

        printf ("The roots of equation are %.3f and %.3f\n", x1, x2);
    }
    else if (D == 0)
    {                                                               //if discriminate == 0
        x1 = x2 =  (-b) / (2 * a);

        printf("The root of equation is %.3f\n", x1);
    }
    else                                                            //if discriminate < 0
        printf("The equation haven't roots in R\n");
}

void input_reset(void)
{
    while (getchar() != '\n')
        continue;
}

int test_exit(void)
{
    char test = 'A';

    test = getchar();

    if (test == 'q')
        return 1;
    else if (test == '\n')
        {}
    else
        input_reset();

    return 0;
}

void input(double &a, double &b, double &c)
{
    printf("a=");
    a = test_num();
    printf("b=");
    b = test_num();
    printf("c=");
    c = test_num();
}

void solver(double a, double b, double c)
{
    double roots[2];
    if (a == 0 && b == 0)
        not_equation(c);
    else if (a == 0)
        linnar_equation(b, c);
    else square_equation(a, b, c);
}

void invite_to_input(void)
{
    printf("\n\nInput coefficients for equation a*x^2+b*x+c=0 \n");
    printf("Input q if want to exit, else press enter\n");
}





