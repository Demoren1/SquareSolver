#include <stdio.h>
#include <math.h>

double test_num(void);                       //check is input are number, if number - return
void linnar_equation(double b, double c, double* root1, int* flag);
void square_equation(double a, double b, double c, double* root1, double* root2, int* flag);
void not_equation (double c, int* flag);
void input_reset(void);
int  test_exit(void);
void input (double* a, double* b, double* c);                         //boolean function
void solver(double a, double b, double c, double* root1, double* root2, int* flag);                             //choose right version of solution
void invite_to_input (void);
void output(double root1, double root2, int flag);
enum output_ways {inf_roots, null_roots, linnar_root, square_roots, square_root, roots_in_C};


int main(void)
{
    double a = 0, b = 0, c = 0, root1 = 0, root2 = 0;
    int flag = -1;

    while ( 1 )
    {
            invite_to_input();
            if (test_exit() )
                break;
            input(&a, &b, &c);
            solver (a, b, c, &root1, &root2, &flag);
            output(root1, root2, flag);
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

void not_equation(double c, int* flag)
{
    *flag = (c == 0) ? 0 : 1;
}

void linnar_equation(double b, double c, double* root1, int* flag)
{
    *root1 = (-c) / b;
    *flag = 2;
}

void square_equation(double a, double b, double c, double* root1, double* root2, int* flag)
{
    double D = 0;

    D = b * b - 4 * a * c;

    if (D > 0)
    {                                                               //if discriminate > 0
        D = sqrt(D);
        *root1 = (-b - D) / (2 * a);
        *root2 = (-b + D) / (2 * a);
        *flag = 3;
    }
    else if (D == 0)
    {                                                               //if discriminate == 0
        *root1 = (-b) / (2 * a);
        *flag = 4;
    }
    else
        *flag = 5;                                                  //if discriminate < 0
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

void input(double* a, double* b, double* c)
{
    printf("a=");
    *a = test_num();
    printf("b=");
    *b = test_num();
    printf("c=");
    *c = test_num();
}

void solver(double a, double b, double c, double* root1, double* root2, int* flag)
{
    if (a == 0 && b == 0)
        not_equation(c, flag);
    else if (a == 0)
        linnar_equation(b, c, root1, flag);
    else square_equation(a, b, c, root1, root2, flag);
}

void invite_to_input(void)
{
    printf("\n\nInput coefficients for equation a*x^2+b*x+c=0 \n");
    printf("Input q if want to exit, else press enter\n");
}

void output(double root1, double root2, int flag)
{
    switch(flag)
    {
    case inf_roots:
        printf("x belong to R");
        break;
    case null_roots:
        printf("x belong to empty set");
        break;
    case linnar_root:
        printf("This is not square equation, the root is %.3f\n", root1);
        break;
    case square_roots:
        printf ("The roots of equation are %.3f and %.3f\n", root1, root2);
        break;
    case square_root:
        printf("The root of equation is %.3f\n", root1);
        break;
    case roots_in_C:
        printf("The equation haven't roots in R\n");
        break;
    }
}


