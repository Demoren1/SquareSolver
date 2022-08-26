<<<<<<< HEAD
#include "square_functions_and_constants.h"
=======
#include "square_functions_and_constants.hpp"
>>>>>>> b8080c2fcdfd336f9aa1de950307ef42ef947de9

//!@file
//!  main() -- square solver
int main()
{
<<<<<<< HEAD
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
=======
    struct Result solution  = {0, 0, -1};
    struct Param parameters = {0, 0,  0};
    int    choice           = 1;

    while (choice != EXIT)
    {
        menu(&choice);

        switch(choice)
        {
            case(SOLVE_SQUARE_EQUATION):
                solver_of_square_eq();
                break;

            case(TEST_SQUARE_EQUATION):
                test_square_equation();
                break;

            case(TEST_LINEAR_EQUATION):
                test_linear_equation();
                break;

            case(TEST_IS_ZERO):
                test_is_zero();
                break;

            case(EXIT):
                break;

            default:
                printf("Something go wrong\n");
>>>>>>> b8080c2fcdfd336f9aa1de950307ef42ef947de9
                INF_ABOUT_ERROR();
                break;
        }
    }

    return 0;
}

