#include <stdio.h>
#include <math.h>
#include <cmath>   // for isfinite
#include <float.h>
#include <assert.h>
#include "square_functions_and_constants.hpp"

void invite_to_input(void)
{
    printf("\n\nInput coefficients for equation a*x^2+b*x+c=0 \n");
    printf("Input q if want to exit.\n");
}


char input_parameters(struct Param* par)
{
    assert(par != NULL);

    printf("a=");
    if ( get_number(&par->a) == 'q')
    {
        return END_INPUT;
    }
    printf("b=");
    if ( get_number(&par->b) == 'q')
    {
        return END_INPUT;
    }
    printf("c=");
    if ( get_number(&par->c) == 'q')
    {
        return END_INPUT;
    }

    return 0;
}

char get_number(double* x)
{
    char current_sym = 0;

    while (scanf("%lf", x) != 1)
    {
        current_sym = getchar();

        if (current_sym == 'q')
        {
            return END_INPUT;
        }

        while ( current_sym != '\n')
        {
            current_sym = getchar();
        }

        printf("is not number, please input  number: ");
    }
}

void clear_of_buff(void)
{
    while (getchar() != '\n')
    {
        continue;
    }
}

void output(struct Result sol)
{
    switch(sol.n_roots)
    {
    case ZERO_ROOT:
        printf("x belong to empty set");
        break;
    case ONE_ROOT:
        printf("The root of equation is %lg\n", sol.root1);
        break;
    case TWO_ROOTS:
        printf ("The roots of equation are %lg and %lg\n", sol.root1, sol.root2);
        break;
    case INF_ROOTS:
        printf("x belong to R\n");
        break;
    default:
        printf("ERROR, invalid quantity of roots");
        break;
    }
}

void  menu(double* choice)
{
    printf("\n********************************************************************************\n\n");
    printf("Select function\n");
    printf("1. Solving a square equation          2. Testing a solution of square solver\n");
    printf("3. Exit\n");
    printf("********************************************************************************\n\n");

    get_number(choice);
}

