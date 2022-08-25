#include <stdio.h>
#include <math.h>
#include <cmath>   // for isfinite
#include <float.h>
#include <assert.h>
#include "square_functions_and_constants.hpp"

//!@file
//!  main() -- square solver
int main()
{
    //!@param [in] paramaters coefficients of equations
    struct Result solution  = {0, 0, -1};
    struct Param parameters = {0, 0,  0};
    double choice           = 1;

    while (choice != EXIT)
    {
        menu(&choice);

        if (choice == SOLVE_SQUARE_EQUATION)
        {
            int is_ran_solver_eq    = 1;
            while (is_ran_solver_eq)
            {
                    invite_to_input();            //SOLUTION->root1
                    if (input_parameters(&parameters) == END_INPUT)
                    {
                        is_ran_solver_eq = 0;
                        break;
                    }
                    solve_square_equation(&parameters ,&solution);
                    output(solution);
                    clear_of_buff();
            }
        }
        else if (choice == TEST_SQUARE_EQUATION)
        {
            test_square_equation();
        }
        else if (choice == EXIT)
        {
            break;
        }
        else
        {
            printf("Something go wrong\n");
            INF_ABOUT_ERROR;
        }
    }

    return 0;
}
