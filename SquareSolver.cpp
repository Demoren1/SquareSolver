#include <stdio.h>
#include <math.h>
#include <cmath>   // for isfinite
#include <float.h>
#include <assert.h>

const char END_INPUT = 'q';

char get_number(double* x);
void solve_linnar_equation(double b, double c, struct Result*);
void solve_square_equation(struct Param*, struct Result*);
void clear_of_buff (void);
char input_parameters (struct Param*);
void invite_to_input (void);
void output(struct Result);
int is_zero(double u);

enum quantity_of_roots
{
    ZERO_ROOT,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS
};

struct Param
{   double a;
    double b;
    double c;
};

struct Result
{
    double root1;
    double root2;
    int n_roots;
};

int main()
{
    struct Result solution  = {0, 0, -1};
    struct Param parameters = {0, 0,  0};
    int is_ran_solver_eq    = 1;

    while ( is_ran_solver_eq  )
    {
            invite_to_input();            //SOLUTION->root1
            if ( input_parameters(&parameters) == END_INPUT)
            {
                is_ran_solver_eq = 0;
                break;
            }
            solve_square_equation(&parameters ,&solution);
            output(solution);
            clear_of_buff();
    }

    return 0;
}

char get_number(double* x)
{
    char current_sym = 0;

    while (scanf("%lf", x) != 1)
    {
        current_sym = getchar();

        if (current_sym == 'q')      // magic
            return END_INPUT;

        while ( current_sym != '\n')
            current_sym = getchar();

        printf("is not number, please input  number: ");
    }
}

void solve_linnar_equation(double b, double c, struct Result* sol)
{
    assert (sol != NULL);
    assert (std::isfinite(b));
    assert (std::isfinite(c));

    if (is_zero(b))
        sol->n_roots = (is_zero(c)) ? INF_ROOTS : ZERO_ROOT;
    else
    {
        sol->root1 = (-c) / b;
        sol->n_roots = 2;
    }
}

void solve_square_equation(struct Param* par, struct Result* sol)
{
    assert (par != NULL);
    assert (sol != NULL);
    assert (std::isfinite(par->a));
    assert (std::isfinite(par->b));
    assert (std::isfinite(par->c));

    double a = par->a, b = par->b, c = par->c;
    double D = 0, sqrt_D = 0;
    double double_a = 2*a;

    if (is_zero(a))
        solve_linnar_equation(b, c, sol);
    else
    {
        D = b * b - 4 * a * c;

        if (D > 0)
        {
            sqrt_D = sqrt(D);
            sol->root1 = (-b - sqrt_D) / double_a;
            sol->root2 = (-b + sqrt_D) / double_a;
            sol->n_roots = 2;
        }
        else if (is_zero(D))
        {
            sol->root1 = (-b) / double_a;
            sol->n_roots = 1;
        }
        else
            sol->n_roots = 0;
    }
}

void clear_of_buff(void)
{
    while (getchar() != '\n')
        continue;
}

char input_parameters(struct Param* par)
{
    assert(par != NULL);

    printf("a=");
    if ( get_number(&par->a) == 'q')
        return END_INPUT;
    printf("b=");
    if ( get_number(&par->b) == 'q')
        return END_INPUT;
    printf("c=");
    if ( get_number(&par->c) == 'q')
        return END_INPUT;

    return 0;
}

void invite_to_input(void)
{
    printf("\n\nInput coefficients for equation a*x^2+b*x+c=0 \n");
    printf("Input q if want to exit.\n");
}

void output(struct Result sol)
{
    switch(sol.n_roots)
    {
    case ZERO_ROOT:
        printf("x belong to empty set");
        break;
    case ONE_ROOT:
        printf("The root of equation is %.3f\n", sol.root1);
        break;
    case TWO_ROOTS:
        printf ("The roots of equation are %.3f and %.3f\n", sol.root1, sol.root2);
        break;
    case INF_ROOTS:
        printf("x belong to R\n");
        break;
    default:
        printf("ERROR, invalid quantity of roots");
        break;
    }
}

int is_zero(double u)
{
    return (fabs(u - FLT_EPSILON) <= FLT_EPSILON);
}

