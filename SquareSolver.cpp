#include "square_functions_and_constants.h"

//!@file
//!  main() -- square solver
int main()
{
    int choice = 1;
    while (choice != EXIT)
    {
        menu (&choice);

        switch (choice)
        {
            case SOLVE_SQUARE_EQUATION:
                solver_of_square_eq();
                break;

            case TEST_SQUARE_EQUATION:
                test_square_equation();
                break;

            case TEST_LINEAR_EQUATION:
                test_linear_equation();
                break;

            case TEST_IS_ZERO:
                test_is_zero();
                break;

            case EXIT:
                break;

            default:
                printf ("Something went wrong\n");
                INF_ABOUT_ERROR();
                break;
        }
    }

    return 0;
}

