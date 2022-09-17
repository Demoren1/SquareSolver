#include "square_functions_and_constants.h"

void invite_to_input()
{
    printf("\n\nInput coefficients for equation a*x^2+b*x+c=0 \n");
    printf("Input q if want to exit.\n");
}


char input_parameters (struct Param* const parameters)
{
    #define input_letter(letter) \
        printf("%s = ", #letter); \
        if ( get_number(&parameters->letter) == 'q') \
    {                                   \
        return END_INPUT;              \
    }

    assert (parameters != NULL);

    input_letter (a);
    input_letter (b);
    input_letter (c);
    #undef input_letter

    return 0;
}

char get_number (double* const x)
{
    assert (x != 0);

    bool getting_num        = true;
    bool is_number_in_buff  = false;
    char current_sym        = 0;

    while (getting_num)
    {
        is_number_in_buff = scanf("%lf", x);
        current_sym = getchar();

        if (want_to_exit(current_sym) && !(is_number_in_buff))
        {
            return END_INPUT;
        }
        else if (current_sym =='\n')
            break;
        else
        {
            while ( current_sym != '\n')
            {
                current_sym = getchar();
            }
        }

        printf("is not number, please input  number: ");
    }
}

void clear_of_buff()
{
    while (getchar() != '\n')
    {
        continue;
    }
}

void output (struct Result* const solution)
{
    switch (solution->n_roots)
    {
        case ZERO_ROOT:
            printf("x belongs to empty set");
            break;
        case ONE_ROOT:
            printf("The root of equation is %lg\n", solution->root1);
            break;
        case TWO_ROOTS:
            printf ("The roots of equation are %lg and %lg\n", solution->root1, solution->root2);
            break;
        case INF_ROOTS:
            printf("x belongs to R\n");
            break;
        default:
            printf("ERROR, invalid quantity of roots");
            break;
    }
}

void  menu (int* const choice)
{
    assert(choice != 0);
    printf("******************************************************************************\n"
           "Select function\n"
           "1. Solving a square equation              2. Testing a solution of square solver\n"
           "3. Testing a solution of linear equation  4. Testing comparing with zero \n"
           "5. Exit\n"
           "********************************************************************************\n");

    scanf("%d", choice);
}

int want_to_exit(char exit_test)
{
    return (exit_test == 'q') ? 1 : 0;
}
